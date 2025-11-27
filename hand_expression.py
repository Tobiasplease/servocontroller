"""
Standalone Hand Expression Controller
====================================
Extracted from the main servo_control system for standalone operation.
Provides the exact same API as the original HandExpressionController.
"""

import time
import serial
from typing import Optional


class HandExpressionController:
    """Standalone hand expression controller with exact same API as original."""
    
    def __init__(self, port: str = "COM3", baudrate: int = 9600, clean_output: bool = True):
        self.port = port
        self.baudrate = baudrate
        self.clean_output = clean_output
        self.serial_connection = None
        self.manual_override = False
        
        # Command throttling system (matches original)
        self.last_command_time = 0.0
        self.min_command_interval = 0.05  # 20Hz max
        self.last_sent_positions = {}
        self.position_change_threshold = 3.0
        
        self._init_serial()
        
    def _init_serial(self):
        """Initialize serial connection to Arduino hand controller."""
        try:
            self.serial_connection = serial.Serial(self.port, self.baudrate, timeout=1)
            time.sleep(2)  # Arduino boot time
            if not self.clean_output:
                print(f"✅ Connected to hand controller on {self.port} at {self.baudrate} baud")
            # Send test command to verify connection (8 servos)
            test_command = "HAND8,90,90,90,90,90,90,90,90\n"
            self.serial_connection.write(test_command.encode())
            if not self.clean_output:
                print(f"📤 Test command sent: {test_command.strip()}")
        except Exception as e:
            if not self.clean_output:
                print(f"❌ Failed to connect to {self.port}: {e}")
            self.serial_connection = None
    
    def set_hand_positions(self, positions: list):
        """
        Set hand positions with proper throttling.
        positions: list of 8 angles [thumb, index, middle, ring, pinky, wrist_rotate, wrist_tilt, elbow] (0-180 degrees)
        """
        if len(positions) != 8:
            raise ValueError("Must provide exactly 8 positions for 5 fingers + 3 arm servos")
        
        if not self.serial_connection:
            return
            
        current_time = time.time()
        
        # Rate limiting: Don't send more than 20 commands per second
        if current_time - self.last_command_time < self.min_command_interval:
            return
        
        # Convert to servo dictionary for position change detection (8 servos: 5 fingers + 3 arm)
        finger_positions = {}
        for i, angle in enumerate(positions):
            # Wrist servo (index 7) gets full range, others get limited range
            if i == 7:  # Wrist servo
                # Use full servo range (0-180°) for wrist
                arduino_position = max(0, min(180, int(angle)))
            else:
                # Clamp other servos to safe range (40-130°)
                arduino_min = 40
                arduino_max = 130
                arduino_center = 85
                arduino_range = 90
                
                # Convert from 0-180° system to Arduino's 40-130° system
                offset_from_center = angle - 90.0
                arduino_offset = (offset_from_center / 90.0) * (arduino_range / 2.0)
                arduino_position = arduino_center + arduino_offset
                arduino_position = max(arduino_min, min(arduino_max, arduino_position))
                arduino_position = int(arduino_position)
            
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
            # Send command in format expected by Arduino: "HAND8,f0,f1,f2,f3,f4,arm0,arm1,arm2\n"
            pos_list = [finger_positions.get(f"finger{i}", 85) for i in range(8)]
            command = f"HAND8,{','.join(map(str, pos_list))}\n"
            self.serial_connection.write(command.encode())
            
            # Update tracking variables
            self.last_command_time = current_time
            self.last_sent_positions = finger_positions.copy()
            
            # Debug output occasionally
            if not hasattr(self, '_debug_count'):
                self._debug_count = 0
            self._debug_count += 1
            if self._debug_count % 20 == 0:  # Every 20 commands
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
