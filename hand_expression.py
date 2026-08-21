"""
Standalone Hand Expression Controller
====================================
Extracted from the main servo_control system for standalone operation.
Provides the exact same API as the original HandExpressionController.
"""

import re
import time
import serial
from typing import Optional


class HandExpressionController:
    """Standalone hand expression controller with exact same API as original."""
    
    NUM_SERVOS = 10

    def __init__(self, port: str = "COM3", baudrate: int = 115200, clean_output: bool = True,
                 min_angle: int = 0, max_angle: int = 180):
        self.port = port
        self.baudrate = baudrate
        self.clean_output = clean_output
        self.serial_connection = None
        self.manual_override = False
        # Filled from the board's boot banner if it publishes one. None means
        # an older sketch that does not report -- caller falls back to config.
        self.reported_pose = None
        self.min_angle = min_angle
        self.max_angle = max_angle
        
        # Command throttling system.
        # The caller's control loop is the real governor (see control_loop's
        # send_interval); this is only a floor so a stray tight-loop caller
        # can't flood the port. Two independent 20Hz throttles used to beat
        # against each other and drop frames unevenly, which read as chop.
        self.last_command_time = 0.0
        self.min_command_interval = 0.015
        self.last_sent_positions = {}
        # Positions go out as whole degrees, so anything below 1.0 means
        # "send whenever the integer actually changed". This was 3.0, which
        # discarded every sub-3-degree move and then released the backlog as
        # a jump -- a staircase generator on slow, smooth motion.
        self.position_change_threshold = 0.5
        
        self._init_serial()
        
    def _init_serial(self):
        """Initialize serial connection to Arduino hand controller."""
        try:
            self.serial_connection = serial.Serial(self.port, self.baudrate, timeout=1)
            time.sleep(2)  # Arduino boot time
            if not self.clean_output:
                print(f"✅ Connected to hand controller on {self.port} at {self.baudrate} baud")
            # Deliberately send NOTHING here. This used to fire a "HAND10,90,90,
            # ..." frame as a connection test, which drove all ten channels to
            # 90 degrees the moment the port opened -- discarding the startup
            # pose the sketch had just booted into. It went unnoticed only
            # because the old double-scaling turned that 90 into 17 degrees.
            #
            # It never verified anything either: the write is buffered and
            # nothing reads a reply, so it succeeded whether or not a board was
            # listening. Opening the port is the connection test. The caller's
            # first real frame carries the actual pose.
            #
            # Instead, LISTEN. The board has just finished booting and printed
            # where it put every channel, which is the one authoritative answer
            # to "where is the hand right now" -- better than any value the host
            # has stored, because it survives a sketch flashed from elsewhere or
            # edited by hand.
            self.reported_pose = self._read_startup_pose()
            if self.reported_pose and not self.clean_output:
                print(f"📥 Board reports startup pose: {self.reported_pose}")
        except Exception as e:
            if not self.clean_output:
                print(f"❌ Failed to connect to {self.port}: {e}")
            self.serial_connection = None
    
    # "S0 -> D12 start 40", one per channel, printed by the listener at boot
    _BANNER_POSE = re.compile(r'^S(\d+)\s*->\s*D\d+\s+start\s+(-?\d+)\s*$')

    def _read_startup_pose(self):
        """Read the board's boot banner and return its pose, or None.

        Bounded by a wall-clock deadline rather than a line count: a board
        running an older sketch prints a banner with no pose lines in it at
        all, and waiting for ten of them would hang the UI on connect.
        Returns None unless every channel reported -- a partial pose is worse
        than no pose, since the caller would fill the gaps with guesses.
        """
        deadline = time.time() + 1.5
        pose = {}
        try:
            while time.time() < deadline and len(pose) < self.NUM_SERVOS:
                raw = self.serial_connection.readline()
                if not raw:
                    continue  # readline timeout; the deadline ends this
                match = self._BANNER_POSE.match(raw.decode('utf-8', errors='replace').strip())
                if match:
                    channel, degrees = int(match.group(1)), int(match.group(2))
                    if 0 <= channel < self.NUM_SERVOS:
                        pose[channel] = degrees
        except Exception as e:
            if not self.clean_output:
                print(f"⚠️ Could not read startup pose: {e}")
            return None

        if len(pose) == self.NUM_SERVOS:
            return [pose[i] for i in range(self.NUM_SERVOS)]
        return None

    def set_hand_positions(self, positions: list):
        """
        Set channel positions with proper throttling.
        positions: list of NUM_SERVOS angles, channel S0..S9 in wire order (0-180 degrees)
        """
        if len(positions) != self.NUM_SERVOS:
            raise ValueError(f"Must provide exactly {self.NUM_SERVOS} positions (channels S0-S{self.NUM_SERVOS - 1})")
        
        if not self.serial_connection:
            return
            
        current_time = time.time()
        
        # Rate limiting: Don't send more than 20 commands per second
        if current_time - self.last_command_time < self.min_command_interval:
            return
        
        # Convert to a per-channel dict for position change detection
        finger_positions = {}
        for i, angle in enumerate(positions):
            # Degrees in, degrees out. This used to RESCALE 0-180 onto
            # min_angle..max_angle, and the sketch then rescaled the result a
            # second time -- on a 0-80 rig, a full-scale 180 arrived as 80 here
            # and was written to the servo as 35. Every channel moved at 44% of
            # the commanded throw, and the baked startup pose (which never went
            # through either scaling) did not match the live frames that
            # followed it.
            #
            # The range is now a CLAMP, not a scale, and it is applied once,
            # here, from the UI's configured range. What the slider reads is
            # what the servo is told. round, not int: truncation biased every
            # angle downward by up to a full degree, which showed up as a
            # slight ratchet on ramps.
            arduino_position = int(round(angle))
            arduino_position = max(self.min_angle, min(self.max_angle, arduino_position))
            finger_positions[f"finger{i}"] = arduino_position
        
        # Position change detection: Only send if positions changed significantly
        if self.last_sent_positions:
            position_changed = False
            for finger_name, new_pos in finger_positions.items():
                old_pos = self.last_sent_positions.get(finger_name, 0)
                if abs(new_pos - old_pos) > self.position_change_threshold:
                    position_changed = True
                    break
            
            if not position_changed:
                return  # Skip sending - positions haven't changed enough
        
        try:
            # A HAND10 frame is ~46 bytes. At 9600 baud that was 48ms of wire
            # time against a 50ms send interval -- unusable, which is why this
            # link runs at 115200, where the same frame costs ~4ms. Still check
            # the port isn't backed up: dropping a frame is free (the next one
            # carries the newer position anyway), whereas a blocking write
            # would stall the whole control loop, and a timed-out write would
            # tear a frame mid-line and hand the Arduino garbage angles.
            if getattr(self.serial_connection, "out_waiting", 0) > 2 * (5 * self.NUM_SERVOS):
                return

            # Wire format: "HAND10,s0,s1,...,s9\n" -- channel order matches
            # the UI's S0..S9 and the sketch's servoPins[] order.
            pos_list = [finger_positions.get(f"finger{i}", 85) for i in range(self.NUM_SERVOS)]
            command = f"HAND10,{','.join(map(str, pos_list))}\n"
            self.serial_connection.write(command.encode())
            
            # Update tracking variables
            self.last_command_time = current_time
            self.last_sent_positions = finger_positions.copy()
            
            # Debug output occasionally
            if not hasattr(self, '_debug_count'):
                self._debug_count = 0
            self._debug_count += 1
            if self._debug_count % 200 == 0:  # ~every 10s at 20Hz; console writes stall the send path
                print(f"📤 SERIAL: {command.strip()}")
                
        except Exception as e:
            if not self.clean_output:
                print(f"❌ Serial write error: {e}")
    
    def enable_manual_override(self):
        """Enable manual override mode."""
        self.manual_override = True
        if not self.clean_output:
            print("🎮 Manual override ENABLED")
    
    def disable_manual_override(self):
        """Disable manual override mode."""
        self.manual_override = False
        if not self.clean_output:
            print("🤖 Manual override DISABLED")
    
    def cleanup(self):
        """Clean shutdown of hand controller."""
        if self.serial_connection:
            try:
                self.serial_connection.close()
                if not self.clean_output:
                    print("🔌 Serial connection closed")
            except Exception as e:
                if not self.clean_output:
                    print(f"❌ Error closing serial: {e}")
