#!/usr/bin/env python3
"""
Simple 10-Servo Hand Control (channels S0-S9)
================================================

Minimal version focused on:
- 5-finger cursor wave control
- 3 arm servo individual control
- Arduino export functionality
- No complex Markov chains or datasets

Author: Simplified 10-Servo System
"""
import tkinter as tk
from tkinter import ttk
import tkinter.messagebox
import tkinter.simpledialog
import customtkinter as ctk
import time
import math
import os
import json
import shutil
import datetime
import random
from typing import Optional

# Import hand controller from local module
try:
    from hand_expression import HandExpressionController
    HAND_CONTROLLER_AVAILABLE = True
    print("[OK] Hand controller available")
except ImportError as e:
    print(f"[WARNING] Hand controller not available - simulation mode: {e}")
    HAND_CONTROLLER_AVAILABLE = False


class SimpleHandControl:
    """Simple 8-servo hand control with cursor wave control and Arduino export."""
    
    def __init__(self):
        # Set CustomTkinter appearance - Windows 98 classic style
        ctk.set_appearance_mode("light")
        ctk.set_default_color_theme("blue")
        
        self.root = ctk.CTk()
        self.root.title("Servo Control Interface")
        # Size to the screen, don't assume it. The old fixed 1380x940 with a
        # 1200x820 minimum was larger than the work area on a 1280x720 display,
        # so the lower panels sat permanently off-screen and could not be
        # reached by resizing -- only by scrolling, which is easy to miss.
        screen_w = self.root.winfo_screenwidth()
        screen_h = self.root.winfo_screenheight()
        win_w = min(1380, screen_w - 40)
        win_h = min(940, screen_h - 80)
        self.root.geometry(f"{win_w}x{win_h}+{max(0, (screen_w - win_w) // 2)}+10")
        self.root.minsize(min(900, win_w), min(600, win_h))
        
        # Windows 98 classic color scheme - clean and readable
        self.colors = {
            'bg_main': '#d4d0c8',      # Classic Win98 gray
            'bg_frame': '#d4d0c8',     # Same gray for frames
            'bg_dark': '#808080',      # Darker gray for inset areas
            'text_main': '#000000',    # Black text - maximum readability
            'text_dim': '#404040',     # Dark gray for secondary text
            'text_cyan': '#000080',    # Navy blue accent
            'button_bg': '#d4d0c8',    # Button face
            'button_hover': '#e4e0d8', # Lighter on hover
            'button_active': '#000080', # Navy blue when active
            'canvas_bg': '#ffffff',    # White canvas/input areas
            'accent_red': '#ff0000',   # Pure red for recording
            'accent_cyan': '#000080',  # Navy blue highlights
            'border': '#808080'        # Gray border
        }
        # Default CTkButton color - match Win98 look
        self.default_button_color = '#d4d0c8'
        
        # Servo configuration.
        #
        # Channels are numbered, not named after anatomy -- this rig gets
        # rewired per project, so "Shoulder"/"Elbow" went stale. Labels are
        # built from the pin map as "S<index> (D<pin>)": the index is stable
        # and matches the wire protocol order, the pin follows the mapping.
        #
        # The finger/arm split survives ONLY as a storage detail: every
        # recording on disk carries separate 'finger_positions' and
        # 'arm_positions' arrays, so collapsing them into one list would
        # orphan every take. Group B simply grew from 3 to 5.
        self.num_fingers = 5        # group A -> channels 0-4
        self.num_arm_servos = 5     # group B -> channels 5-9
        self.num_servos = self.num_fingers + self.num_arm_servos

        # Hardware configuration (can be saved/loaded as presets)
        self.hardware_config = {
            'name': 'Default',
            'description': 'Standard 10-servo controller',
            'serial_port': 'COM4',
            # 115200: a HAND10 frame is ~46 bytes, which is 48ms on the wire
            # at 9600 baud -- past the send interval. At 115200 it is ~4ms.
            'baud_rate': 115200,
            # Expressive range: host-side, applied before the frame goes out.
            # Change it freely -- it takes effect on the next frame, no reflash.
            'global_min_angle': 0,
            'global_max_angle': 45,
            # Hardware backstop: compiled into the sketch, so changing it means
            # regenerating and reflashing. Its job is to survive a corrupt frame,
            # NOT to shape the motion -- keep it at whatever the mechanism can
            # physically reach and do the shaping above, per channel.
            'firmware_safe_min': 0,
            'firmware_safe_max': 180,
            'pin_mapping': [12, 11, 10, 9, 8, 7, 6, 5, 4, 3],
            'servo_names': [f'S{i}' for i in range(10)],
            'reversed_servos': [2, 3],  # Servo indices that are reversed
            'per_servo_limits': [[0, 180] for _ in range(10)],
            'pir_pin': 2,  # moved off 3 so that pin can drive servo S9
        }
        self.hardware_config_file = 'hardware_config.json'
        self.load_hardware_config()  # Load saved config if exists
        self.migrate_hardware_config()  # grow 8-servo presets to 10

        # Labels are derived, never stored -- rebuilt whenever the pin map changes
        self.refresh_servo_labels()

        # Derive legacy variables from config for backward compatibility
        self.servo_limits = [tuple(lim) for lim in self.hardware_config['per_servo_limits']]
        self.servo_reversed = [i in self.hardware_config['reversed_servos']
                               for i in range(self.num_servos)]
        self.default_port = self.hardware_config['serial_port']
        
        # Initialize positions at the configured rest pose -- the same pose the
        # listener bakes into its startupPositions[]. These used to be a flat
        # 90.0, so the first frame the host sent yanked every channel to 90 the
        # instant the UI opened, throwing away the sketch's startup pose. That
        # was invisible only while the old double-scaling happened to squash 90
        # down to 17 degrees; with the scaling gone, 90 means 90.
        rest = self.get_startup_pose()
        self.finger_positions = [float(v) for v in rest[:self.num_fingers]]
        self.arm_positions = [float(v) for v in rest[self.num_fingers:]]
        
        # Control parameters
        # Cursor sensitivity is split per axis: X sets how tightly the wave
        # wraps across the fingers, Y how hard the vertical drag pulls. One
        # shared value meant a twitchy wave forced a twitchy gravity too.
        self.cursor_sensitivity = tk.DoubleVar(value=2.0)      # X / wave spread
        self.cursor_sensitivity_y = tk.DoubleVar(value=1.0)    # Y / gravity gain
        self.servo_range = tk.DoubleVar(value=180.0)
        self.wave_gravity = tk.DoubleVar(value=0.5)  # How much Y position affects all fingers
        self.wave_offset = tk.DoubleVar(value=0.0)   # Base offset for all fingers
        self.global_clamp_min = tk.IntVar(value=0)
        self.global_clamp_max = tk.IntVar(value=180)
        
        # Per-finger wave enable (allows excluding fingers from cursor control)
        # Wave control now reaches every channel, not just the first five --
        # this rig is not always a hand. S5..S9 start disabled so existing
        # setups behave exactly as before until you switch them on.
        self.wave_enabled = [tk.BooleanVar(value=(i < 5)) for i in range(self.num_servos)]
        # alias: the finger-bar canvas code indexes 0..4 of the same list
        self.finger_wave_enabled = self.wave_enabled
        
        # Recording system
        self.recorded_layers = []
        self.layer_recording = False
        self.layer_record_start_time = 0
        self.current_layer_data = []
        
        # Playback system
        self.is_playing = False
        self.playback_layer = None
        self.playback_start_time = 0
        self.playback_index = 0
        self.playback_position = 0.0  # 0.0 to 1.0 for timeline visualization
        self.loop_duration = tk.DoubleVar(value=0.0)  # 0 = auto (longest layer), >0 = fixed duration
        self.playback_speed = tk.DoubleVar(value=1.0)  # Playback speed multiplier (0.1x to 3.0x)
        
        # Markov/organic playback settings
        self.markov_mode = False  # True while organic is actually driving a pass
        # Organic is a property of playback, toggled here and honoured by both
        # ▶ Play and the exporter, so preview and sketch cannot disagree.
        self.organic_enabled = tk.BooleanVar(value=False)
        # name typed into the export dialog; blank falls back to a timestamp
        self.pending_export_name = ''
        # Per-channel record-enable. Separate from wave_enabled on purpose:
        # which bars are on the pad and which channels a take OWNS are two
        # different questions, and conflating them is what let an overdub
        # silently seize channels it was not performing.
        self.rec_armed = [tk.BooleanVar(value=True) for _ in range(self.num_servos)]
        self.position_wobble = tk.DoubleVar(value=1.5)  # ± degrees random offset (subtle)
        self.timing_jitter = tk.DoubleVar(value=8.0)  # ± % timing variation (gentle)
        self.pause_chance = tk.DoubleVar(value=2.0)  # % chance to pause at keyframes (rare)
        self.is_paused_at_keyframe = False
        self.pause_until = 0  # timestamp when pause ends
        self.wobble_offsets = [0.0] * self.num_servos  # current wobble offset per servo
        self.wobble_targets = [0.0] * self.num_servos  # target wobble offset (for smooth transitions)
        self.last_wobble_update = 0
        self.jitter_speed_multiplier = 1.0  # current speed jitter (smoothly varies)
        self.jitter_speed_target = 1.0  # target speed for smooth transitions
        self.last_jitter_update = 0
        
        # Keyframe capture system
        self.captured_keyframes = []
        self.keyframe_capture_start = None
        
        # PIR State Machine System
        self.pir_enabled = tk.BooleanVar(value=False)  # PIR testing mode enabled
        self.pir_simulated_motion = False  # Simulated motion detection (for testing)
        self.pir_last_motion_time = 0  # Last time motion was detected
        self.pir_state = 'idle'  # Current state: 'idle', 'active', 'sleep'
        self.pir_state_start_time = 0  # When current state started
        
        # PIR timing configuration
        self.pir_active_duration = tk.IntVar(value=30)  # Seconds to stay active after motion
        self.pir_sleep_timeout = tk.IntVar(value=30)  # Minutes of no motion before sleep (30 min default)
        self.pir_transition_time = tk.DoubleVar(value=5.0)  # Seconds to blend between states
        
        # Crossfade settings (organic blending between recordings within a state)
        self.pir_crossfade_enabled = tk.BooleanVar(value=True)
        self.pir_crossfade_interval_min = tk.IntVar(value=10)   # Min seconds between crossfades
        self.pir_crossfade_interval_max = tk.IntVar(value=25)  # Max seconds between crossfades
        self.pir_crossfade_duration_min = tk.IntVar(value=8)   # Min crossfade length (seconds)
        self.pir_crossfade_duration_max = tk.IntVar(value=15)   # Max crossfade length (seconds)
        
        # Boot lockout: hold IDLE and ignore the sensor for this long after
        # power-up. A PIR needs 30-60s to settle its ambient reference and
        # false-triggers while it does, so a piece that wakes into ACTIVE the
        # instant it is switched on is usually reacting to nothing.
        self.pir_startup_lockout = tk.IntVar(value=10)

        # Recording assignments for each state (list of filenames from pir_recordings/ folder)
        self.pir_idle_recordings = []  # List of recording names for IDLE state
        self.pir_active_recordings = []  # List of recording names for ACTIVE state
        self.pir_sleep_recordings = []  # List of recording names for SLEEP state
        
        # Current recording index for each state (for cycling through multiple recordings)
        self.pir_recording_index = {'idle': 0, 'active': 0, 'sleep': 0}
        self.pir_recording_progress = 0.0  # Progress through current recording (0.0-1.0)
        self.pir_crossfade_to_next = False  # Flag to trigger crossfade to next recording
        
        # Cache for loaded PIR recordings {filename: layers_data}
        self.pir_cached_recordings = {}
        self.pir_recordings_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), "pir_recordings")
        
        # State transition tracking
        self.pir_blend_factor = 0.0  # 0.0-1.0 for smooth state transitions
        self.pir_previous_state = None
        self.pir_transition_start = 0
        self.pir_transition_positions = None  # Store positions at transition start for blending
        
        # Recording crossfade tracking (within same state)
        self.pir_rec_blend_factor = 0.0
        self.pir_prev_rec_positions = None
        self.pir_next_crossfade_time = 0  # When to start next crossfade
        self.pir_is_crossfading = False    # Currently crossfading between recordings
        self.pir_crossfade_start_time = 0  # When current crossfade started
        self.pir_crossfade_duration = 3.0  # Duration of current crossfade (seconds)
        self.pir_crossfade_target_idx = 0  # Target recording index during crossfade

        # Markov segment system (alternative to crossfade)
        self.pir_markov_enabled = tk.BooleanVar(value=False)  # Use Markov instead of crossfade
        self.pir_markov_segment_length = tk.DoubleVar(value=1.0)  # Segment length in seconds
        self.pir_markov_chaos = tk.IntVar(value=30)  # 0=smooth, 100=creative/random
        self.pir_markov_blend_time = tk.DoubleVar(value=0.1)  # Blend time between segments (keep short for momentum)
        self.pir_markov_hardware_preview = tk.BooleanVar(value=True)  # Show what Arduino will actually do
        
        # Hardware preview constants (must match Arduino export)
        self.HARDWARE_SAMPLES_PER_SEG = 12
        self.HARDWARE_TOP_K_TRANSITIONS = 6
        
        # Markov runtime state
        self.pir_markov_segments = {}  # {state: [segment_data, ...]}
        self.pir_markov_transitions = {}  # {state: [[prob array], ...]}
        self.pir_markov_hw_segments = {}  # {state: [hw_segment_data, ...]} - subsampled for hardware preview
        self.pir_markov_hw_transitions = {}  # {state: [[sparse top-k], ...]} - sparse for hardware preview
        self.pir_current_segment_idx = 0
        self.pir_segment_start_time = 0
        self.pir_prev_segment_end_positions = None
        self.pir_needs_blend = False
        self.pir_markov_initialized = False

        # Control mode
        self.control_mode = tk.StringVar(value="cursor")
        self.hover_mode = tk.BooleanVar(value=False)  # Toggle for hover control
        
        # Hardware controller
        self.hand_controller = None
        if HAND_CONTROLLER_AVAILABLE:
            try:
                self.hand_controller = HandExpressionController(
                    port=self.default_port, 
                    baudrate=self.hardware_config.get('baud_rate', 115200),
                    clean_output=True,
                    min_angle=self.hardware_config['global_min_angle'],
                    max_angle=self.hardware_config['global_max_angle']
                )
                # Start from where the hand actually is, not where we assumed
                self.sync_pose_from_board()
            except Exception as e:
                print(f"[WARNING] Could not initialize hand controller: {e}")
        
        # Create GUI
        self.create_interface()
        self.update_connection_status()
        
        # Populate PIR recording dropdowns from library
        self.update_pir_recording_combos()
        
        # Start control loop
        self.last_send_time = 0
        self.send_interval = 0.05  # 20Hz
        self.control_loop()
        
        print(f"✅ Simple {self.num_servos}-servo hand control initialized "
              f"(S0-S{self.num_servos - 1}, PIR on D{self.hardware_config.get('pir_pin', 2)})")
        enabled = sum(1 for v in self.wave_enabled if v.get())
        print(f"🖱️ Wave control: {enabled}/{self.num_servos} channels enabled")
        print(f"🎛️ Individual control for all {self.num_servos} channels")
    
    def create_interface(self):
        """Create the user interface."""
        # Create main canvas with scrollbar
        canvas_container = tk.Frame(self.root, bg=self.colors['bg_main'])
        canvas_container.pack(fill=tk.BOTH, expand=True)
        
        scrollbar = tk.Scrollbar(canvas_container, orient=tk.VERTICAL)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        
        main_canvas = tk.Canvas(canvas_container, bg=self.colors['bg_main'], 
                               yscrollcommand=scrollbar.set, highlightthickness=0)
        main_canvas.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        
        scrollbar.config(command=main_canvas.yview)
        
        # Main scrollable frame
        main_frame = tk.Frame(main_canvas, bg=self.colors['bg_main'])
        canvas_window = main_canvas.create_window((0, 0), window=main_frame, anchor=tk.NW)
        
        # Configure scroll region when frame changes size
        def configure_scroll_region(event=None):
            main_canvas.configure(scrollregion=main_canvas.bbox("all"))
        
        main_frame.bind("<Configure>", configure_scroll_region)
        
        # Bind mousewheel for scrolling
        def on_mousewheel(event):
            main_canvas.yview_scroll(int(-1*(event.delta/120)), "units")
        
        main_canvas.bind_all("<MouseWheel>", on_mousewheel)
        
        # Make canvas expand with window
        def configure_canvas_width(event):
            main_canvas.itemconfig(canvas_window, width=event.width)
        
        main_canvas.bind("<Configure>", configure_canvas_width)
        
        # Title and recording controls at top
        top_bar = tk.Frame(main_frame, bg=self.colors['bg_main'])
        top_bar.pack(fill=tk.X, pady=(10, 5), padx=10)
        
        title = tk.Label(top_bar, text="Servo Control", 
                        bg=self.colors['bg_main'], fg=self.colors['text_main'],
                        font=('Arial', 14, 'bold'))
        title.pack(side=tk.LEFT)
        
        # Connection status on far right
        self.connection_label = tk.Label(top_bar, text="● Disconnected", 
                                         bg=self.colors['bg_main'], fg='#808080',
                                         font=('Arial', 9))
        self.connection_label.pack(side=tk.RIGHT, padx=10)
        
        # Toolbar with grouped buttons
        toolbar = tk.Frame(main_frame, bg=self.colors['bg_main'], relief=tk.GROOVE, bd=1)
        toolbar.pack(fill=tk.X, pady=(0, 10), padx=10)
        
        # Helper to create separator
        def add_separator():
            sep = tk.Frame(toolbar, width=2, bg='#808080')
            sep.pack(side=tk.LEFT, fill=tk.Y, padx=8, pady=4)
        
        # === TRANSPORT GROUP ===
        transport_frame = tk.Frame(toolbar, bg=self.colors['bg_main'])
        transport_frame.pack(side=tk.LEFT, padx=5, pady=5)
        
        self.record_btn = ctk.CTkButton(transport_frame, text="● REC", 
                                   command=self.toggle_recording,
                                   font=('Arial', 11, 'bold'), width=70,
                                   fg_color='#c0c0c0', text_color='black',
                                   hover_color='#e0e0e0',
                                   corner_radius=0, border_width=2, border_color='#808080')
        self.record_btn.pack(side=tk.LEFT, padx=2)
        
        self.playback_btn = ctk.CTkButton(transport_frame, text="▶ Play", 
                                     command=self.toggle_playback,
                                     font=('Arial', 11, 'bold'), width=70,
                                     fg_color='#c0c0c0', text_color='black',
                                     hover_color='#e0e0e0',
                                     corner_radius=0, border_width=2, border_color='#808080')
        self.playback_btn.pack(side=tk.LEFT, padx=2)
        
        # The "~ Organic" transport is gone: organic is now a checkbox in the
        # Organic Variations panel that modifies ▶ Play. Two play buttons meant
        # you could be in a mode you did not choose, and Play silently cleared it.
        # toggle_markov_playback() is kept for any handler that still calls it.
        
        add_separator()
        
        # === FILE GROUP ===
        file_frame = tk.Frame(toolbar, bg=self.colors['bg_main'])
        file_frame.pack(side=tk.LEFT, padx=5, pady=5)
        
        ctk.CTkButton(file_frame, text="Save", 
                 command=self.save_recording,
                 font=('Arial', 10), width=60,
                 fg_color='#c0c0c0', text_color='black',
                 hover_color='#e0e0e0',
                 corner_radius=0, border_width=2, border_color='#808080').pack(side=tk.LEFT, padx=2)
        
        ctk.CTkButton(file_frame, text="Load", 
                 command=self.load_recording,
                 font=('Arial', 10), width=60,
                 fg_color='#c0c0c0', text_color='black',
                 hover_color='#e0e0e0',
                 corner_radius=0, border_width=2, border_color='#808080').pack(side=tk.LEFT, padx=2)
        
        add_separator()
        
        # === EXPORT GROUP ===
        export_frame = tk.Frame(toolbar, bg=self.colors['bg_main'])
        export_frame.pack(side=tk.LEFT, padx=5, pady=5)

        export_button_row = tk.Frame(export_frame, bg=self.colors['bg_main'])
        export_button_row.pack(fill=tk.X)
        
        # One door to every sketch. The old toolbar had "Export .ino (Full)"
        # and "Multi-Phrase" here, a third in the PIR panel and a fourth in the
        # scratch section -- with a caption elsewhere explaining the difference,
        # which is what a UI does when the buttons do not carry their own meaning.
        ctk.CTkButton(export_button_row, text="⬇ Export .ino...",
                 command=self.open_export_dialog,
                 font=('Arial', 11, 'bold'), width=150,
                 fg_color='#c0c0c0', text_color='black',
                 hover_color='#e0e0e0',
                 corner_radius=0, border_width=2, border_color='#808080').pack(side=tk.LEFT, padx=2)

        self.export_hint_label = tk.Label(export_frame,
             text="reflects current UI",
             bg=self.colors['bg_main'],
             fg=self.colors['text_dim'],
             font=('Arial', 7))
        self.export_hint_label.pack(anchor='w', padx=3, pady=(1, 0))
        
        add_separator()
        
        # === TOOLS GROUP ===
        tools_frame = tk.Frame(toolbar, bg=self.colors['bg_main'])
        tools_frame.pack(side=tk.LEFT, padx=5, pady=5)
        
        ctk.CTkButton(tools_frame, text="Capture", 
                 command=self.capture_keyframe,
                 font=('Arial', 10), width=70,
                 fg_color='#c0c0c0', text_color='black',
                 hover_color='#e0e0e0',
                 corner_radius=0, border_width=2, border_color='#808080').pack(side=tk.LEFT, padx=2)
        
        ctk.CTkButton(tools_frame, text="Connect", 
                 command=self.reconnect_arduino,
                 font=('Arial', 10), width=70,
                 fg_color='#c0c0c0', text_color='black',
                 hover_color='#e0e0e0',
                 corner_radius=0, border_width=2, border_color='#808080').pack(side=tk.LEFT, padx=2)

        ctk.CTkButton(tools_frame, text="Disconnect", 
             command=self.disconnect_arduino,
             font=('Arial', 10), width=85,
             fg_color='#c0c0c0', text_color='black',
             hover_color='#e0e0e0',
             corner_radius=0, border_width=2, border_color='#808080').pack(side=tk.LEFT, padx=2)
        
        ctk.CTkButton(tools_frame, text="Clear All", 
                 command=self.clear_layers,
                 font=('Arial', 10), width=70,
                 fg_color='#c0c0c0', text_color='black',
                 hover_color='#e0e0e0',
                 corner_radius=0, border_width=2, border_color='#808080').pack(side=tk.LEFT, padx=2)
        
        # Status bar
        status_bar = self.status_bar = tk.Frame(main_frame, bg=self.colors['bg_dark'], relief=tk.SUNKEN, bd=1)
        status_bar.pack(fill=tk.X, pady=(0, 10))
        
        self.record_status_label = tk.Label(status_bar, text="⚪ Ready to record (Press SPACE)", 
                                           bg=self.colors['bg_dark'], fg=self.colors['text_main'],
                                           font=('Arial', 9), anchor=tk.W)
        self.record_status_label.pack(side=tk.LEFT, padx=5, pady=3, fill=tk.X, expand=True)
        
        # Timeline
        # Layers live directly under the workspace (see arrange_main_layout) so
        # the takes stay in view while you are actually performing into them.
        self.timeline_container = tk.LabelFrame(main_frame, text="Layers",
                                                bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                                                font=('Arial', 9, 'bold'))
        self.timeline_container.pack(fill=tk.X, pady=(0, 5))

        # Transport right here, where the takes are. The toolbar copies are
        # still there, but during a pass your eyes are on the lanes, not the
        # top of the window.
        lane_transport = tk.Frame(self.timeline_container, bg=self.colors['bg_frame'])
        lane_transport.pack(fill=tk.X, padx=4, pady=(2, 0))
        self.record_btn2 = ctk.CTkButton(lane_transport, text="● REC",
                 command=self.toggle_recording,
                 font=('Arial', 10, 'bold'), width=70,
                 fg_color='#c0c0c0', text_color='black', hover_color='#e0e0e0',
                 corner_radius=0, border_width=2, border_color='#808080')
        self.record_btn2.pack(side=tk.LEFT, padx=2)
        self.playback_btn2 = ctk.CTkButton(lane_transport, text="▶ Play",
                 command=self.toggle_playback,
                 font=('Arial', 10, 'bold'), width=70,
                 fg_color='#c0c0c0', text_color='black', hover_color='#e0e0e0',
                 corner_radius=0, border_width=2, border_color='#808080')
        self.playback_btn2.pack(side=tk.LEFT, padx=2)
        self.lane_status_label = tk.Label(lane_transport, text="",
                 bg=self.colors['bg_frame'], fg=self.colors['text_dim'],
                 font=('Arial', 8), anchor='w')
        self.lane_status_label.pack(side=tk.LEFT, padx=10)

        # Record-enable per channel, DAW style. A take owns exactly the armed
        # channels it can actually drive -- so overdubbing S1 no longer drags
        # S0 along just because S0's bar happens to be on the pad.
        arm_row = tk.Frame(self.timeline_container, bg=self.colors['bg_frame'])
        arm_row.pack(fill=tk.X, padx=4, pady=(0, 2))
        tk.Label(arm_row, text="REC arm:", bg=self.colors['bg_frame'],
                 fg=self.colors['text_main'], font=('Arial', 8, 'bold')).pack(side=tk.LEFT)
        for i in range(self.num_servos):
            tk.Checkbutton(arm_row, text=f"S{i}", variable=self.rec_armed[i],
                           command=self.on_rec_arm_changed,
                           bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                           font=('Arial', 8), selectcolor=self.colors['bg_dark']
                           ).pack(side=tk.LEFT, padx=1)
        ctk.CTkButton(arm_row, text="all", width=34, height=20, font=('Arial', 8),
                      command=lambda: self.set_all_rec_armed(True),
                      fg_color='#c0c0c0', text_color='black', hover_color='#e0e0e0',
                      corner_radius=0).pack(side=tk.LEFT, padx=(8, 2))
        ctk.CTkButton(arm_row, text="none", width=40, height=20, font=('Arial', 8),
                      command=lambda: self.set_all_rec_armed(False),
                      fg_color='#c0c0c0', text_color='black', hover_color='#e0e0e0',
                      corner_radius=0).pack(side=tk.LEFT, padx=2)
        self.arm_hint_label = tk.Label(arm_row, text="", bg=self.colors['bg_frame'],
                 fg=self.colors['text_dim'], font=('Arial', 8))
        self.arm_hint_label.pack(side=tk.LEFT, padx=8)

        # Height is re-set as layers arrive -- one lane per layer, each with
        # the waveform of its take (see redraw_timeline_waves)
        self.timeline_canvas = tk.Canvas(self.timeline_container, height=self.LANE_HEIGHT,
                                        bg=self.colors['bg_dark'],
                                        highlightthickness=1, highlightbackground=self.colors['text_dim'])
        self.timeline_canvas.pack(fill=tk.X, padx=4, pady=(2, 4))
        self._timeline_sig = None
        self._timeline_tick = 0
        
        # Playback speed control
        speed_frame = tk.Frame(main_frame, bg=self.colors['bg_main'])
        speed_frame.pack(fill=tk.X, pady=(0, 10))
        
        tk.Label(speed_frame, text="⏩ Playback Speed:", bg=self.colors['bg_main'], 
                fg=self.colors['text_main'], font=('Arial', 9)).pack(side=tk.LEFT, padx=(0, 5))
        
        speed_slider = tk.Scale(speed_frame, from_=0.1, to=3.0, resolution=0.1, orient=tk.HORIZONTAL,
                               variable=self.playback_speed, length=200, font=('Arial', 8),
                               bg=self.colors['bg_main'], fg=self.colors['text_main'],
                               highlightthickness=0, troughcolor=self.colors['bg_dark'])
        speed_slider.pack(side=tk.LEFT, padx=5)
        
        self.speed_label = tk.Label(speed_frame, text="1.0x", bg=self.colors['bg_main'], 
                                    fg=self.colors['text_main'], font=('Arial', 9, 'bold'), width=6)
        self.speed_label.pack(side=tk.LEFT, padx=5)
        
        # Update speed label when slider changes
        self.playback_speed.trace('w', lambda *args: self.speed_label.config(text=f"{self.playback_speed.get():.1f}x"))
        
        # Organic variation controls (collapsible, starts expanded)
        self.variation_container = tk.Frame(main_frame, bg=self.colors['bg_main'])
        self.variation_container.pack(fill=tk.X, pady=(0, 5))
        
        self.variation_expanded = False
        self.variation_btn = ctk.CTkButton(self.variation_container, 
                                       text="▶ Organic Variations", 
                                       command=self.toggle_variation_panel,
                                       fg_color="transparent", text_color=self.colors['text_main'],
                                       font=('Arial', 11, 'bold'), anchor='w',
                                       hover_color='#E0E0E0')
        self.variation_btn.pack(fill=tk.X, pady=(0, 2))
        
        self.variation_content = tk.Frame(self.variation_container, bg=self.colors['bg_frame'],
                                          relief=tk.GROOVE, bd=1)
        # starts collapsed -- keep the default view lean; the workspace is the point
        self.organic_btn = self.variation_btn  # header repaints to show [ON]

        # The toggle: organic applies to ▶ Play, so what you preview is what
        # gets baked into the export.
        organic_row = tk.Frame(self.variation_content, bg=self.colors['bg_frame'])
        organic_row.pack(fill=tk.X, padx=5, pady=(4, 2))
        tk.Checkbutton(organic_row, text="Apply organic to playback and export",
                       variable=self.organic_enabled, command=self.on_organic_toggled,
                       bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                       font=('Arial', 9, 'bold'),
                       selectcolor=self.colors['bg_dark']).pack(side=tk.LEFT)
        tk.Label(organic_row, text="(off = exact replay of the recorded take)",
                 bg=self.colors['bg_frame'], fg=self.colors['text_dim'],
                 font=('Arial', 7)).pack(side=tk.LEFT, padx=6)

        # Wobble control
        wobble_row = tk.Frame(self.variation_content, bg=self.colors['bg_frame'])
        wobble_row.pack(fill=tk.X, padx=5, pady=2)
        tk.Label(wobble_row, text="Position Wobble:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8), width=14, anchor='w').pack(side=tk.LEFT)
        tk.Scale(wobble_row, from_=0, to=10, resolution=0.5, orient=tk.HORIZONTAL,
                variable=self.position_wobble, length=120, font=('Arial', 7),
                bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                highlightthickness=0, troughcolor=self.colors['bg_dark']).pack(side=tk.LEFT, padx=5)
        tk.Label(wobble_row, text="±°", bg=self.colors['bg_frame'], 
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
        
        # Timing jitter control
        jitter_row = tk.Frame(self.variation_content, bg=self.colors['bg_frame'])
        jitter_row.pack(fill=tk.X, padx=5, pady=2)
        tk.Label(jitter_row, text="Timing Jitter:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8), width=14, anchor='w').pack(side=tk.LEFT)
        tk.Scale(jitter_row, from_=0, to=30, resolution=1, orient=tk.HORIZONTAL,
                variable=self.timing_jitter, length=120, font=('Arial', 7),
                bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                highlightthickness=0, troughcolor=self.colors['bg_dark']).pack(side=tk.LEFT, padx=5)
        tk.Label(jitter_row, text="±%", bg=self.colors['bg_frame'], 
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
        
        # Pause chance control
        pause_row = tk.Frame(self.variation_content, bg=self.colors['bg_frame'])
        pause_row.pack(fill=tk.X, padx=5, pady=2)
        tk.Label(pause_row, text="Pause Chance:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8), width=14, anchor='w').pack(side=tk.LEFT)
        tk.Scale(pause_row, from_=0, to=20, resolution=1, orient=tk.HORIZONTAL,
                variable=self.pause_chance, length=120, font=('Arial', 7),
                bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                highlightthickness=0, troughcolor=self.colors['bg_dark']).pack(side=tk.LEFT, padx=5)
        tk.Label(pause_row, text="%", bg=self.colors['bg_frame'], 
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
        
        # Control mode selection
        mode_frame = self.mode_frame = tk.LabelFrame(main_frame, text="Control Mode", 
                                  bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        mode_frame.pack(fill=tk.X, pady=(0, 10))
        
        tk.Radiobutton(mode_frame, text="🖱️ Cursor Wave Control (enabled channels)", 
                      variable=self.control_mode, value="cursor",
                      bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                      command=self.on_mode_change).pack(anchor=tk.W, padx=10, pady=3)
        
        tk.Radiobutton(mode_frame, text="🎛️ Individual Servo Control", 
                      variable=self.control_mode, value="manual",
                      bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                      command=self.on_mode_change).pack(anchor=tk.W, padx=10, pady=3)
        
        # Hardware Configuration Panel (collapsible)
        self.hw_config_container = tk.Frame(main_frame, bg=self.colors['bg_main'])
        self.hw_config_container.pack(fill=tk.X, pady=(0, 5))
        
        # Clickable header button
        self.hw_config_expanded = False
        self.hw_config_btn = ctk.CTkButton(self.hw_config_container, 
                                       text="▶ Hardware Config", 
                                       command=self.toggle_hw_config_panel,
                                       fg_color="transparent", text_color=self.colors['text_main'],
                                       font=('Arial', 11, 'bold'), anchor='w',
                                       hover_color='#E0E0E0')
        self.hw_config_btn.pack(fill=tk.X, pady=(0, 2))
        
        # Content frame (starts hidden)
        self.hw_config_content = tk.Frame(self.hw_config_container, bg=self.colors['bg_frame'],
                                          relief=tk.GROOVE, bd=1)
        # Don't pack yet - starts collapsed
        
        # Config name and preset controls
        name_row = tk.Frame(self.hw_config_content, bg=self.colors['bg_frame'])
        name_row.pack(fill=tk.X, padx=5, pady=2)
        tk.Label(name_row, text="Preset Name:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8), width=12, anchor='w').pack(side=tk.LEFT)
        self.config_name_var = tk.StringVar(value=self.hardware_config['name'])
        tk.Entry(name_row, textvariable=self.config_name_var, width=20, font=('Arial', 8)).pack(side=tk.LEFT, padx=5)
        ctk.CTkButton(name_row, text="📥 Import", command=self.import_hardware_preset,
                 font=('Arial', 10), width=70).pack(side=tk.LEFT, padx=2)
        ctk.CTkButton(name_row, text="📤 Export", command=self.export_hardware_preset,
                 font=('Arial', 10), width=70).pack(side=tk.LEFT, padx=2)
        
        # Serial port
        port_row = tk.Frame(self.hw_config_content, bg=self.colors['bg_frame'])
        port_row.pack(fill=tk.X, padx=5, pady=2)
        tk.Label(port_row, text="Serial Port:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8), width=12, anchor='w').pack(side=tk.LEFT)
        self.config_port_var = tk.StringVar(value=self.hardware_config['serial_port'])
        tk.Entry(port_row, textvariable=self.config_port_var, width=10, font=('Arial', 8)).pack(side=tk.LEFT, padx=5)

        tk.Label(port_row, text="Baud:", bg=self.colors['bg_frame'],
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(12, 0))
        self.config_baud_var = tk.IntVar(value=self.hardware_config.get('baud_rate', 115200))
        ttk.Combobox(port_row, textvariable=self.config_baud_var, width=8, font=('Arial', 8),
                     values=[9600, 19200, 38400, 57600, 115200, 250000],
                     state='normal').pack(side=tk.LEFT, padx=5)

        tk.Label(port_row, text="PIR pin D:", bg=self.colors['bg_frame'],
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(12, 0))
        self.config_pir_pin_var = tk.IntVar(value=self.hardware_config.get('pir_pin', 2))
        tk.Spinbox(port_row, from_=0, to=19, textvariable=self.config_pir_pin_var,
                   width=4, font=('Arial', 8)).pack(side=tk.LEFT, padx=5)

        # Pin mapping -- editable, because the whole point of numbered channels
        # is that this rig gets rewired between projects
        pins_row = tk.Frame(self.hw_config_content, bg=self.colors['bg_frame'])
        pins_row.pack(fill=tk.X, padx=5, pady=2)
        tk.Label(pins_row, text="Pins S0..S%d:" % (self.num_servos - 1), bg=self.colors['bg_frame'],
                fg=self.colors['text_main'], font=('Arial', 8), width=12, anchor='w').pack(side=tk.LEFT)
        self.config_pins_var = tk.StringVar(
            value=', '.join(str(p) for p in self.hardware_config['pin_mapping']))
        tk.Entry(pins_row, textvariable=self.config_pins_var, width=40,
                 font=('Arial', 8)).pack(side=tk.LEFT, padx=5)
        tk.Label(pins_row, text="(comma separated, in channel order)", bg=self.colors['bg_frame'],
                fg=self.colors['text_dim'], font=('Arial', 7)).pack(side=tk.LEFT)

        # Global angle range
        range_row = tk.Frame(self.hw_config_content, bg=self.colors['bg_frame'])
        range_row.pack(fill=tk.X, padx=5, pady=2)
        tk.Label(range_row, text="Angle Range:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8), width=12, anchor='w').pack(side=tk.LEFT)
        self.config_min_var = tk.IntVar(value=self.hardware_config['global_min_angle'])
        self.config_max_var = tk.IntVar(value=self.hardware_config['global_max_angle'])
        tk.Entry(range_row, textvariable=self.config_min_var, width=5, font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Label(range_row, text=" - ", bg=self.colors['bg_frame'], fg=self.colors['text_main']).pack(side=tk.LEFT)
        tk.Entry(range_row, textvariable=self.config_max_var, width=5, font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Label(range_row, text="° (live clamp — no reflash; per-channel limits below)",
                bg=self.colors['bg_frame'],
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT, padx=5)

        # Hardware backstop. Separate from the range above on purpose: this one
        # is compiled into the sketch, so it is the only range that costs a
        # reflash to change. Leave it at what the mechanism can physically reach.
        safe_row = tk.Frame(self.hw_config_content, bg=self.colors['bg_frame'])
        safe_row.pack(fill=tk.X, padx=5, pady=2)
        tk.Label(safe_row, text="Safe Limit:", bg=self.colors['bg_frame'],
                fg=self.colors['text_main'], font=('Arial', 8), width=12, anchor='w').pack(side=tk.LEFT)
        self.config_safe_min_var = tk.IntVar(value=self.hardware_config.get('firmware_safe_min', 0))
        self.config_safe_max_var = tk.IntVar(value=self.hardware_config.get('firmware_safe_max', 180))
        tk.Entry(safe_row, textvariable=self.config_safe_min_var, width=5, font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Label(safe_row, text=" - ", bg=self.colors['bg_frame'], fg=self.colors['text_main']).pack(side=tk.LEFT)
        tk.Entry(safe_row, textvariable=self.config_safe_max_var, width=5, font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Label(safe_row, text="° (baked into the sketch — needs a reflash)",
                bg=self.colors['bg_frame'],
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT, padx=5)
        
        # Reversed servos
        rev_row = tk.Frame(self.hw_config_content, bg=self.colors['bg_frame'])
        rev_row.pack(fill=tk.X, padx=5, pady=2)
        tk.Label(rev_row, text="Reversed:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8), width=12, anchor='w').pack(side=tk.LEFT)
        self.config_reversed_vars = []
        for i, name in enumerate(self.all_servo_names):
            var = tk.BooleanVar(value=i in self.hardware_config['reversed_servos'])
            self.config_reversed_vars.append(var)
            cb = tk.Checkbutton(rev_row, text=name[:3], variable=var,
                               bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                               font=('Arial', 7), command=self.update_config_from_ui)
            cb.pack(side=tk.LEFT)
        
        # Apply and Save buttons
        btn_row = tk.Frame(self.hw_config_content, bg=self.colors['bg_frame'])
        btn_row.pack(fill=tk.X, padx=5, pady=5)
        ctk.CTkButton(btn_row, text="✅ Apply & Save", command=self.apply_and_save_config,
                 font=('Arial', 11, 'bold'), width=120).pack(side=tk.LEFT, padx=5)
        ctk.CTkButton(btn_row, text="⚙ Generate Listener .ino", command=self.export_listener_sketch,
                 font=('Arial', 11), width=170).pack(side=tk.LEFT, padx=5)
        tk.Label(btn_row, text="(listener matches the config above -- reflash after changing pins/baud)",
                bg=self.colors['bg_frame'],
                fg=self.colors['text_dim'], font=('Arial', 7)).pack(side=tk.LEFT)
        
        # ==================== PIR STATE MACHINE PANEL ====================
        # Collapsible, same pattern as Hardware Config -- PIR is only relevant
        # to some of the rigs this drives, and expanded it pushed the actual
        # workspace off the bottom of the window.
        self.pir_container = tk.Frame(main_frame, bg=self.colors['bg_main'])
        self.pir_container.pack(fill=tk.X, pady=(0, 5))

        self.pir_expanded = False
        self.pir_panel_btn = ctk.CTkButton(self.pir_container,
                                       text="▶ PIR State Machine",
                                       command=self.toggle_pir_panel,
                                       fg_color="transparent", text_color=self.colors['text_main'],
                                       font=('Arial', 11, 'bold'), anchor='w',
                                       hover_color='#E0E0E0')
        self.pir_panel_btn.pack(fill=tk.X, pady=(0, 2))

        self.pir_content = tk.Frame(self.pir_container, bg=self.colors['bg_main'])
        # not packed -- starts collapsed

        pir_main_frame = tk.LabelFrame(self.pir_content, text="PIR State Machine (Test & Export)",
                                       bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                                       font=('Arial', 10, 'bold'))
        pir_main_frame.pack(fill=tk.X, pady=(5, 10), padx=5)
        
        # Top row: Enable toggle, state indicator, simulate button
        pir_top_row = tk.Frame(pir_main_frame, bg=self.colors['bg_frame'])
        pir_top_row.pack(fill=tk.X, padx=10, pady=5)
        
        self.pir_enable_cb = tk.Checkbutton(pir_top_row, text="Enable PIR Mode", 
                                           variable=self.pir_enabled,
                                           bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                                           font=('Arial', 9, 'bold'),
                                           command=self.on_pir_toggle)
        self.pir_enable_cb.pack(side=tk.LEFT)
        
        # State indicator
        tk.Label(pir_top_row, text="  State:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 9)).pack(side=tk.LEFT, padx=(20, 5))
        self.pir_state_label = tk.Label(pir_top_row, text="OFF", 
                                        bg='#888888', fg='white',
                                        font=('Arial', 9, 'bold'), width=8, relief=tk.RAISED)
        self.pir_state_label.pack(side=tk.LEFT)
        
        # Recording indicator (shows which recording is playing)
        self.pir_rec_label = tk.Label(pir_top_row, text="", 
                                      bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                                      font=('Arial', 8))
        self.pir_rec_label.pack(side=tk.LEFT, padx=(3, 0))
        
        # Simulate motion button
        self.pir_simulate_btn = ctk.CTkButton(pir_top_row, text="Simulate Motion", 
                                         command=self.simulate_pir_motion,
                                         fg_color='#c0c0c0', text_color='black',
                                         hover_color='#a0a0a0',
                                         corner_radius=0, border_width=2, border_color='#808080',
                                         state='disabled', width=130)
        self.pir_simulate_btn.pack(side=tk.LEFT, padx=(20, 5))
        
        # Timer display
        self.pir_timer_label = tk.Label(pir_top_row, text="", 
                                        bg=self.colors['bg_frame'], fg=self.colors['text_dim'],
                                        font=('Arial', 8))
        self.pir_timer_label.pack(side=tk.LEFT, padx=10)
        
        # Save to Library button (saves current recording for PIR states)
        self.pir_save_btn = ctk.CTkButton(pir_top_row, text="Save to Library", 
                                      command=self.save_to_pir_library,
                                      fg_color='#c0c0c0', text_color='black',
                                      hover_color='#e0e0e0',
                                      corner_radius=0, border_width=2, border_color='#808080',
                                      width=120)
        self.pir_save_btn.pack(side=tk.RIGHT, padx=5)

        # Clear Library: empties the folder AND the three state lists, so a
        # fresh start does not leave the cards pointing at names that are gone.
        self.pir_clear_btn = ctk.CTkButton(pir_top_row, text="Clear Library",
                                      command=self.clear_recording_library,
                                      fg_color='#c0c0c0', text_color='black',
                                      hover_color='#e0a0a0',
                                      corner_radius=0, border_width=2, border_color='#808080',
                                      width=110)
        self.pir_clear_btn.pack(side=tk.RIGHT, padx=5)

        # PIR export moved into the single Export .ino dialog, which preselects
        # the PIR generator whenever PIR mode is on.

        tk.Label(pir_main_frame,
             text="With PIR enabled, Export .ino defaults to the compressed state machine.",
             bg=self.colors['bg_frame'],
             fg=self.colors['text_dim'],
             font=('Arial', 8),
             anchor='w',
             justify='left').pack(fill=tk.X, padx=10, pady=(0, 5))
        
        # State assignment cards - three columns with multi-recording support
        pir_states_frame = tk.Frame(pir_main_frame, bg=self.colors['bg_frame'])
        pir_states_frame.pack(fill=tk.X, padx=10, pady=5)
        
        # Helper to create a state card with listbox and add/remove buttons
        def create_state_card(parent, title, recordings_list, state_key):
            card = tk.LabelFrame(parent, text=title, 
                                bg='#e0e0e0', fg='#000000',
                                font=('Arial', 9, 'bold'))
            
            # Listbox for multiple recordings
            listbox = tk.Listbox(card, width=18, height=3, font=('Arial', 8),
                                selectmode=tk.SINGLE, bg='white')
            listbox.pack(padx=5, pady=2, fill=tk.X)
            
            # Button row
            btn_frame = tk.Frame(card, bg='#e0e0e0')
            btn_frame.pack(fill=tk.X, padx=5, pady=2)
            
            # Add button with dropdown
            add_btn = tk.Button(btn_frame, text="+", width=3, font=('Arial', 8),
                              command=lambda: self.add_pir_recording(state_key, listbox))
            add_btn.pack(side=tk.LEFT, padx=1)
            
            # Remove button
            remove_btn = tk.Button(btn_frame, text="-", width=3, font=('Arial', 8),
                                  command=lambda: self.remove_pir_recording(state_key, listbox))
            remove_btn.pack(side=tk.LEFT, padx=1)
            
            return card, listbox
        
        # Create the three state cards
        idle_card, self.pir_idle_listbox = create_state_card(
            pir_states_frame, "IDLE", self.pir_idle_recordings, 'idle')
        idle_card.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=(0, 5))
        
        active_card, self.pir_active_listbox = create_state_card(
            pir_states_frame, "ACTIVE", self.pir_active_recordings, 'active')
        active_card.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=5)
        
        sleep_card, self.pir_sleep_listbox = create_state_card(
            pir_states_frame, "SLEEP", self.pir_sleep_recordings, 'sleep')
        sleep_card.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=(5, 0))
        
        # Timing row
        pir_timing_frame = tk.Frame(pir_main_frame, bg=self.colors['bg_frame'])
        pir_timing_frame.pack(fill=tk.X, padx=10, pady=(5, 10))
        
        tk.Label(pir_timing_frame, text="Active duration:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Spinbox(pir_timing_frame, from_=5, to=120, width=4, 
                  textvariable=self.pir_active_duration, font=('Arial', 8)).pack(side=tk.LEFT, padx=2)
        tk.Label(pir_timing_frame, text="sec", bg=self.colors['bg_frame'], 
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
        
        tk.Label(pir_timing_frame, text="    Startup idle:", bg=self.colors['bg_frame'],
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(15, 0))
        tk.Spinbox(pir_timing_frame, from_=0, to=300, width=4,
                  textvariable=self.pir_startup_lockout, font=('Arial', 8)).pack(side=tk.LEFT, padx=2)
        tk.Label(pir_timing_frame, text="sec", bg=self.colors['bg_frame'],
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)

        tk.Label(pir_timing_frame, text="    Sleep after:", bg=self.colors['bg_frame'],
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(15, 0))
        tk.Spinbox(pir_timing_frame, from_=1, to=60, width=4, 
                  textvariable=self.pir_sleep_timeout, font=('Arial', 8)).pack(side=tk.LEFT, padx=2)
        tk.Label(pir_timing_frame, text="min", bg=self.colors['bg_frame'], 
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
        
        tk.Label(pir_timing_frame, text="    Blend time:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(15, 0))
        tk.Spinbox(pir_timing_frame, from_=0.5, to=5.0, increment=0.5, width=4, 
                  textvariable=self.pir_transition_time, font=('Arial', 8)).pack(side=tk.LEFT, padx=2)
        tk.Label(pir_timing_frame, text="sec", bg=self.colors['bg_frame'], 
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
        
        # Crossfade row (organic blending between recordings)
        pir_crossfade_frame = tk.Frame(pir_main_frame, bg=self.colors['bg_frame'])
        pir_crossfade_frame.pack(fill=tk.X, padx=10, pady=(0, 8))
        
        self.pir_crossfade_cb = tk.Checkbutton(pir_crossfade_frame, text="Crossfade recordings", 
                                               variable=self.pir_crossfade_enabled,
                                               bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                                               font=('Arial', 8, 'bold'))
        self.pir_crossfade_cb.pack(side=tk.LEFT)
        
        tk.Label(pir_crossfade_frame, text="  Interval:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(10, 0))
        tk.Spinbox(pir_crossfade_frame, from_=1, to=30, width=3, 
                  textvariable=self.pir_crossfade_interval_min, font=('Arial', 8)).pack(side=tk.LEFT, padx=1)
        tk.Label(pir_crossfade_frame, text="-", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Spinbox(pir_crossfade_frame, from_=1, to=60, width=3, 
                  textvariable=self.pir_crossfade_interval_max, font=('Arial', 8)).pack(side=tk.LEFT, padx=1)
        tk.Label(pir_crossfade_frame, text="sec", bg=self.colors['bg_frame'], 
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
        
        tk.Label(pir_crossfade_frame, text="  Duration:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(10, 0))
        tk.Spinbox(pir_crossfade_frame, from_=1, to=15, width=3, 
                  textvariable=self.pir_crossfade_duration_min, font=('Arial', 8)).pack(side=tk.LEFT, padx=1)
        tk.Label(pir_crossfade_frame, text="-", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Spinbox(pir_crossfade_frame, from_=1, to=30, width=3, 
                  textvariable=self.pir_crossfade_duration_max, font=('Arial', 8)).pack(side=tk.LEFT, padx=1)
        tk.Label(pir_crossfade_frame, text="sec", bg=self.colors['bg_frame'], 
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
        
        # Markov segment row (alternative to crossfade)
        pir_markov_frame = tk.Frame(pir_main_frame, bg=self.colors['bg_frame'])
        pir_markov_frame.pack(fill=tk.X, padx=10, pady=(0, 8))
        
        self.pir_markov_cb = tk.Checkbutton(pir_markov_frame, text="Markov segments", 
                                            variable=self.pir_markov_enabled,
                                            command=self._on_markov_toggle,
                                            bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                                            font=('Arial', 8, 'bold'))
        self.pir_markov_cb.pack(side=tk.LEFT)
        
        tk.Label(pir_markov_frame, text="  Seg:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(10, 0))
        tk.Spinbox(pir_markov_frame, from_=0.3, to=3.0, increment=0.1, width=4, 
                  textvariable=self.pir_markov_segment_length, font=('Arial', 8)).pack(side=tk.LEFT, padx=1)
        tk.Label(pir_markov_frame, text="s", bg=self.colors['bg_frame'], 
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
        
        tk.Label(pir_markov_frame, text="  Chaos:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(10, 0))
        tk.Scale(pir_markov_frame, from_=0, to=100, orient=tk.HORIZONTAL, length=80,
                variable=self.pir_markov_chaos, showvalue=False,
                bg=self.colors['bg_frame'], highlightthickness=0).pack(side=tk.LEFT, padx=1)
        tk.Label(pir_markov_frame, text="  Seg Blend:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(5, 0))
        tk.Spinbox(pir_markov_frame, from_=0.0, to=1.0, increment=0.05, width=4, 
                  textvariable=self.pir_markov_blend_time, font=('Arial', 8)).pack(side=tk.LEFT, padx=1)
        tk.Label(pir_markov_frame, text="s", bg=self.colors['bg_frame'], 
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
        
        # Hardware preview toggle
        tk.Checkbutton(pir_markov_frame, text="HW Preview", variable=self.pir_markov_hardware_preview,
                      command=self._on_markov_hw_preview_toggle,
                      bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                      selectcolor=self.colors['bg_dark'], font=('Arial', 8),
                      activebackground=self.colors['bg_frame']).pack(side=tk.LEFT, padx=(15, 0))
        
        # Markov info row (shows segment details and size estimation)
        pir_markov_info_frame = tk.Frame(pir_main_frame, bg=self.colors['bg_frame'])
        pir_markov_info_frame.pack(fill=tk.X, padx=10, pady=(0, 8))
        
        self.pir_markov_info_label = tk.Label(pir_markov_info_frame, text="",
                                              bg=self.colors['bg_frame'], 
                                              fg=self.colors['text_dim'],
                                              font=('Consolas', 8), anchor='w', justify='left')
        self.pir_markov_info_label.pack(side=tk.LEFT, fill=tk.X, expand=True)
        
        # ==================== END PIR PANEL ====================
        
        # Create two main areas side by side
        content_frame = self.content_frame = tk.Frame(main_frame, bg=self.colors['bg_main'])
        content_frame.pack(fill=tk.BOTH, expand=True)
        
        # Left side - Cursor control
        self.cursor_frame = tk.LabelFrame(content_frame, text="Cursor Wave Control", 
                                         bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        self.cursor_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=(0, 5))
        
        # Canvas for cursor control with visual feedback - larger area for finer control
        # 380 tall pushed the Layers panel off the bottom on a 720p-logical
        # screen. It still fills whatever height is going (expand=True), this
        # is only the floor -- the pad stays usable, the lanes stay visible.
        self.canvas = tk.Canvas(self.cursor_frame, width=550, height=260,
                               bg=self.colors['canvas_bg'])
        self.canvas.pack(pady=6, fill=tk.BOTH, expand=True)
        self.canvas.bind("<Motion>", self.on_mouse_move)
        self.canvas.bind("<Configure>", lambda e: self.on_canvas_resize(e))
        
        # Per-finger wave enable checkboxes
        finger_enable_frame = tk.Frame(self.cursor_frame, bg=self.colors['bg_frame'])
        finger_enable_frame.pack(fill=tk.X, padx=10, pady=(0, 5))
        tk.Label(finger_enable_frame, text="Wave On:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(0, 5))
        for i, name in enumerate(self.all_servo_names):
            cb = tk.Checkbutton(finger_enable_frame, text=f"S{i}",
                               variable=self.wave_enabled[i],
                               command=self.on_wave_channel_toggled,
                               bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                               font=('Arial', 8), selectcolor=self.colors['bg_dark'])
            cb.pack(side=tk.LEFT, padx=2)
        
        # Bind spacebar for recording toggle
        self.root.bind("<space>", lambda e: self.toggle_recording())
        
        # Initialize visual elements
        self.finger_bars = []
        self.arm_indicators = []
        self.create_visual_feedback()
        
        # Cursor control parameters - Row 1
        # Wave tuning collapses like Hardware Config -- these get set once per
        # rig and then just take up room above the lanes. The Wave On row stays
        # visible, since that is what puts bars on the pad.
        self.wave_cfg_container = tk.Frame(self.cursor_frame, bg=self.colors['bg_frame'])
        self.wave_cfg_container.pack(fill=tk.X, padx=6, pady=(2, 4))
        self.wave_cfg_expanded = False
        self.wave_cfg_btn = ctk.CTkButton(self.wave_cfg_container,
                                      text="▶ Wave Config",
                                      command=self.toggle_wave_config_panel,
                                      fg_color="transparent", text_color=self.colors['text_main'],
                                      font=('Arial', 10, 'bold'), anchor='w',
                                      hover_color='#E0E0E0', height=22)
        self.wave_cfg_btn.pack(fill=tk.X)
        self.wave_cfg_content = tk.Frame(self.wave_cfg_container, bg=self.colors['bg_frame'])
        # not packed -- starts collapsed

        param_frame1 = tk.Frame(self.wave_cfg_content, bg=self.colors['bg_frame'])
        param_frame1.pack(fill=tk.X, padx=4, pady=(4, 2))
        
        tk.Label(param_frame1, text="Sens X:", bg=self.colors['bg_frame'],
                font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Scale(param_frame1, from_=0.1, to=10.0, resolution=0.1, orient=tk.HORIZONTAL,
                variable=self.cursor_sensitivity, length=90,
                font=('Arial', 8)).pack(side=tk.LEFT, padx=5)

        tk.Label(param_frame1, text="Sens Y:", bg=self.colors['bg_frame'],
                font=('Arial', 8)).pack(side=tk.LEFT, padx=(5, 0))
        tk.Scale(param_frame1, from_=0.1, to=4.0, resolution=0.1, orient=tk.HORIZONTAL,
                variable=self.cursor_sensitivity_y, length=90,
                font=('Arial', 8)).pack(side=tk.LEFT, padx=5)

        tk.Label(param_frame1, text="Clamp Min:", bg=self.colors['bg_frame'],
            font=('Arial', 8)).pack(side=tk.LEFT, padx=(10,0))
        tk.Scale(param_frame1, from_=0, to=180, resolution=1, orient=tk.HORIZONTAL,
            variable=self.global_clamp_min, length=80,
            font=('Arial', 8)).pack(side=tk.LEFT, padx=5)

        tk.Label(param_frame1, text="Clamp Max:", bg=self.colors['bg_frame'],
            font=('Arial', 8)).pack(side=tk.LEFT, padx=(5,0))
        tk.Scale(param_frame1, from_=0, to=180, resolution=1, orient=tk.HORIZONTAL,
            variable=self.global_clamp_max, length=80,
            font=('Arial', 8)).pack(side=tk.LEFT, padx=5)

        ctk.CTkButton(param_frame1, text="Apply Clamp to All", command=self.apply_global_clamp_to_all,
             font=('Arial', 10), width=130).pack(side=tk.LEFT, padx=(5, 0))
        
        # Cursor control parameters - Row 2
        param_frame2 = tk.Frame(self.wave_cfg_content, bg=self.colors['bg_frame'])
        param_frame2.pack(fill=tk.X, padx=4, pady=(2, 4))
        
        tk.Label(param_frame2, text="Gravity:", bg=self.colors['bg_frame'], 
                font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Scale(param_frame2, from_=0.0, to=1.0, resolution=0.1, orient=tk.HORIZONTAL,
                variable=self.wave_gravity, length=100, 
                font=('Arial', 8)).pack(side=tk.LEFT, padx=5)
        
        tk.Label(param_frame2, text="Offset:", bg=self.colors['bg_frame'],
                font=('Arial', 8)).pack(side=tk.LEFT, padx=(10,0))
        tk.Scale(param_frame2, from_=-45.0, to=45.0, resolution=5.0, orient=tk.HORIZONTAL,
                variable=self.wave_offset, length=100,
                font=('Arial', 8)).pack(side=tk.LEFT, padx=5)
        
        # Right side - Individual servo control
        self.servo_frame = tk.LabelFrame(content_frame, text="Individual Servo Control", 
                                        bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        self.servo_frame.pack(side=tk.RIGHT, fill=tk.BOTH, expand=True, padx=(5, 0))
        
        self.create_servo_sliders()
        
        # Layer list at bottom
        layer_frame = self.layer_frame = tk.LabelFrame(main_frame, text="Recorded Layers", 
                                    bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        layer_frame.pack(fill=tk.X, pady=(10, 0))
        
        list_container = tk.Frame(layer_frame, bg=self.colors['bg_frame'])
        list_container.pack(fill=tk.X, padx=5, pady=5)
        
        scrollbar = tk.Scrollbar(list_container)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        
        self.layer_listbox = tk.Listbox(list_container, bg=self.colors['bg_dark'], 
                                        fg=self.colors['text_main'],
                                        selectmode=tk.SINGLE, height=3,
                                        yscrollcommand=scrollbar.set, font=('Arial', 8))
        self.layer_listbox.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)
        self.layer_listbox.bind('<Double-Button-1>', lambda e: self.delete_selected_layer())
        scrollbar.config(command=self.layer_listbox.yview)
        
        # Layer info and delete button
        layer_bottom = tk.Frame(layer_frame, bg=self.colors['bg_frame'])
        layer_bottom.pack(fill=tk.X, padx=5, pady=(0, 5))
        
        self.layer_info_label = tk.Label(layer_bottom, text="No layers recorded", 
                                        bg=self.colors['bg_frame'], fg=self.colors['text_dim'],
                                        font=('Arial', 8), anchor=tk.W)
        self.layer_info_label.pack(side=tk.LEFT, fill=tk.X, expand=True)
        
        # Keyframe control buttons
        ctk.CTkButton(layer_bottom, text="Keyframes to Layer", 
                 command=self.convert_keyframes_to_layer,
                 font=('Arial', 10), width=130,
                 fg_color='#c0c0c0', text_color='black',
                 hover_color='#e0e0e0',
                 corner_radius=0, border_width=2, border_color='#808080').pack(side=tk.RIGHT, padx=2)
        
        ctk.CTkButton(layer_bottom, text="Clear Keyframes", 
                 command=self.clear_keyframes,
                 font=('Arial', 10), width=110,
                 fg_color='#c0c0c0', text_color='black',
                 hover_color='#e0e0e0',
                 corner_radius=0, border_width=2, border_color='#808080').pack(side=tk.RIGHT, padx=2)
        
        ctk.CTkButton(layer_bottom, text="Delete Selected",
                 command=self.delete_selected_layer,
                 font=('Arial', 10), width=110,
                 fg_color='#c0c0c0', text_color='black',
                 hover_color='#e0e0e0',
                 corner_radius=0, border_width=2, border_color='#808080').pack(side=tk.RIGHT)

        self.arrange_main_layout()

    def arrange_main_layout(self):
        """Put the workspace first and the layers directly beneath it.

        Widgets are created in whatever order the panels were written, which
        left the workspace at the very bottom -- below a full-height PIR block
        -- while the timeline sat up by the toolbar. Rather than move hundreds
        of lines, repack the four frames that matter; pack(after=...) rewrites
        the order without touching how any panel is built.

        Resulting order:
            toolbar / status / control mode
            WORKSPACE  (cursor pad + per-channel sliders)
            LAYERS     (waveform lanes + playhead)
            recorded-layer list
            playback speed, organic variations
            hardware config, PIR          (both collapsed by default)
        """
        self.mode_frame.pack(fill=tk.X, pady=(0, 6), after=self.status_bar)
        self.content_frame.pack(fill=tk.BOTH, expand=True, after=self.mode_frame)
        self.timeline_container.pack(fill=tk.X, pady=(6, 0), after=self.content_frame)
        self.layer_frame.pack(fill=tk.X, pady=(4, 0), after=self.timeline_container)

    def create_servo_sliders(self):
        """Create single-servo control interface."""
        # Servo selector
        selector_frame = tk.Frame(self.servo_frame, bg=self.colors['bg_frame'])
        selector_frame.pack(fill=tk.X, padx=10, pady=10)
        
        tk.Label(selector_frame, text="Select Servo:", font=('Arial', 10, 'bold'),
                bg=self.colors['bg_frame'], fg=self.colors['text_main']).pack(side=tk.LEFT, padx=5)
        
        self.selected_servo = tk.IntVar(value=0)
        all_names = self.all_servo_names
        
        servo_selector = ttk.Combobox(selector_frame, values=all_names, 
                                     state='readonly', width=15)
        servo_selector.current(0)
        servo_selector.bind('<<ComboboxSelected>>', self.on_servo_select)
        servo_selector.pack(side=tk.LEFT, padx=5)
        self.servo_selector = servo_selector
        
        # Hover mode toggle
        self.hover_check = tk.Checkbutton(selector_frame, text="Hover Mode", 
                                         variable=self.hover_mode,
                                         bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                                         font=('Arial', 9))
        self.hover_check.pack(side=tk.LEFT, padx=10)

        # Preset controls (global)
        preset_row = tk.Frame(self.servo_frame, bg=self.colors['bg_frame'])
        preset_row.pack(fill=tk.X, padx=10, pady=(0, 10))
        ctk.CTkButton(preset_row, text="Save Preset", command=self.save_servo_preset,
                 font=('Arial', 10), width=100,
                 fg_color='#c0c0c0', text_color='black',
                 hover_color='#e0e0e0',
                 corner_radius=0, border_width=2, border_color='#808080').pack(side=tk.LEFT, padx=(0, 5))
        ctk.CTkButton(preset_row, text="Load Preset", command=self.load_servo_preset,
                 font=('Arial', 10), width=100,
                 fg_color='#c0c0c0', text_color='black',
                 hover_color='#e0e0e0',
                 corner_radius=0, border_width=2, border_color='#808080').pack(side=tk.LEFT)
        
        # Large control bar
        control_frame = tk.Frame(self.servo_frame, bg=self.colors['bg_frame'])
        control_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)
        
        # Canvas for large interactive bar
        self.large_bar_canvas = tk.Canvas(control_frame, bg=self.colors['bg_main'],
                                         width=150, height=400, highlightthickness=0)
        self.large_bar_canvas.pack(side=tk.LEFT, padx=20)
        
        # Bind mouse events - both click/drag and motion for hover mode
        self.large_bar_canvas.bind("<Button-1>", self.on_large_bar_click)
        self.large_bar_canvas.bind("<B1-Motion>", self.on_large_bar_drag)
        self.large_bar_canvas.bind("<Motion>", self.on_large_bar_hover)
        
        self.create_large_bar()
        
        # Scrollable visualization of all servos
        viz_frame = tk.LabelFrame(control_frame, text="All Servos (Clamp + Reverse)",
                                 bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        viz_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=10)
        
        # Canvas with scrollbar
        canvas = tk.Canvas(viz_frame, bg=self.colors['bg_main'], width=300, height=400)
        scrollbar = ttk.Scrollbar(viz_frame, orient="vertical", command=canvas.yview)
        self.viz_frame_inner = tk.Frame(canvas, bg=self.colors['bg_main'])
        
        self.viz_frame_inner.bind(
            "<Configure>",
            lambda e: canvas.configure(scrollregion=canvas.bbox("all"))
        )
        
        canvas.create_window((0, 0), window=self.viz_frame_inner, anchor="nw")
        canvas.configure(yscrollcommand=scrollbar.set)
        
        canvas.pack(side="left", fill="both", expand=True)
        scrollbar.pack(side="right", fill="y")
        
        self.create_small_servo_bars()
    
    def create_large_bar(self):
        """Create the large control bar."""
        bar_width = 80
        bar_height = 350
        x = 35
        y = 30
        
        # Background
        self.large_bar_rect = self.large_bar_canvas.create_rectangle(
            x, y, x + bar_width, y + bar_height,
            fill='#e0e0e0', outline='#666666', width=3
        )
        
        # Fill
        self.large_bar_fill = self.large_bar_canvas.create_rectangle(
            x, y + bar_height, x + bar_width, y + bar_height,
            fill='#4CAF50', outline=''
        )
        
        # Servo name label
        self.large_bar_name = self.large_bar_canvas.create_text(
            x + bar_width/2, y - 15,
            text=self.finger_names[0], font=('Arial', 12, 'bold')
        )
        
        # Value label
        self.large_bar_value = self.large_bar_canvas.create_text(
            x + bar_width/2, y + bar_height + 20,
            text="90°", font=('Arial', 16, 'bold'), fill='#0066cc'
        )

        self.large_bar_min_line = self.large_bar_canvas.create_line(
            x, y + bar_height, x + bar_width, y + bar_height,
            fill='#0D47A1', width=2, dash=(4, 2)
        )
        self.large_bar_max_line = self.large_bar_canvas.create_line(
            x, y, x + bar_width, y,
            fill='#B71C1C', width=2, dash=(4, 2)
        )
        self.large_bar_range_label = self.large_bar_canvas.create_text(
            x + bar_width/2, y + bar_height + 38,
            text="Range: 0° - 180°", font=('Arial', 9), fill='#555555'
        )
        
        # Degree markers
        for deg in [0, 45, 90, 135, 180]:
            marker_y = y + bar_height - (deg / 180.0 * bar_height)
            self.large_bar_canvas.create_line(
                x - 5, marker_y, x, marker_y, width=2
            )
            self.large_bar_canvas.create_text(
                x - 15, marker_y, text=f"{deg}°", font=('Arial', 8)
            )
    
    def create_small_servo_bars(self):
        """Create small bars with per-servo clamp/reverse controls."""
        self.small_bars = []
        all_names = self.all_servo_names

        self.servo_min_vars = []
        self.servo_max_vars = []
        self.servo_rev_vars = []
        
        for i, name in enumerate(all_names):
            frame = tk.Frame(self.viz_frame_inner, bg=self.colors['bg_main'])
            frame.pack(fill=tk.X, pady=3)

            min_lim, max_lim = self.servo_limits[i]
            min_var = tk.IntVar(value=min_lim)
            max_var = tk.IntVar(value=max_lim)
            rev_var = tk.BooleanVar(value=self.servo_reversed[i])
            self.servo_min_vars.append(min_var)
            self.servo_max_vars.append(max_var)
            self.servo_rev_vars.append(rev_var)
            
            # Label
            name_label = tk.Label(frame, text=f"{name}:", width=12, anchor='w',
                                  bg=self.colors['bg_main'], font=('Arial', 9))
            name_label.pack(side=tk.LEFT, padx=5)
            
            # Small bar canvas
            bar_canvas = tk.Canvas(frame, width=150, height=20, 
                                  bg='#e0e0e0', highlightthickness=1)
            bar_canvas.pack(side=tk.LEFT, padx=5)
            
            # Fill bar
            fill = bar_canvas.create_rectangle(0, 0, 0, 20, fill='#4CAF50', outline='')
            clamp_min_marker = bar_canvas.create_line(0, 0, 0, 20, fill='#0D47A1', width=2, dash=(2, 2))
            clamp_max_marker = bar_canvas.create_line(150, 0, 150, 20, fill='#B71C1C', width=2, dash=(2, 2))
            
            # Value label
            value_label = tk.Label(frame, text="90° [0-180]", width=14, anchor='w',
                                  bg=self.colors['bg_main'], font=('Arial', 9, 'bold'))
            value_label.pack(side=tk.LEFT, padx=5)

            tk.Label(frame, text="Min", bg=self.colors['bg_main'], font=('Arial', 8)).pack(side=tk.LEFT)
            min_spin = tk.Spinbox(frame, from_=0, to=180, width=4, textvariable=min_var,
                                  command=lambda idx=i: self.on_bar_limits_changed(idx))
            min_spin.pack(side=tk.LEFT, padx=(2, 4))
            min_spin.bind("<Return>", lambda _e, idx=i: self.on_bar_limits_changed(idx))
            min_spin.bind("<FocusOut>", lambda _e, idx=i: self.on_bar_limits_changed(idx))

            tk.Label(frame, text="Max", bg=self.colors['bg_main'], font=('Arial', 8)).pack(side=tk.LEFT)
            max_spin = tk.Spinbox(frame, from_=0, to=180, width=4, textvariable=max_var,
                                  command=lambda idx=i: self.on_bar_limits_changed(idx))
            max_spin.pack(side=tk.LEFT, padx=(2, 4))
            max_spin.bind("<Return>", lambda _e, idx=i: self.on_bar_limits_changed(idx))
            max_spin.bind("<FocusOut>", lambda _e, idx=i: self.on_bar_limits_changed(idx))

            rev_chk = tk.Checkbutton(frame, text="Rev", variable=rev_var,
                                     command=lambda idx=i: self.on_bar_reverse_changed(idx),
                                     bg=self.colors['bg_main'], font=('Arial', 8))
            rev_chk.pack(side=tk.LEFT, padx=(4, 0))

            # Click any row element to select that servo
            frame.bind("<Button-1>", lambda _e, idx=i: self.select_servo_from_row(idx))
            name_label.bind("<Button-1>", lambda _e, idx=i: self.select_servo_from_row(idx))
            bar_canvas.bind("<Button-1>", lambda _e, idx=i: self.select_servo_from_row(idx))
            
            self.small_bars.append({
                'frame': frame,
                'canvas': bar_canvas,
                'fill': fill,
                'clamp_min_marker': clamp_min_marker,
                'clamp_max_marker': clamp_max_marker,
                'name_label': name_label,
                'label': value_label,
                'min_spin': min_spin,
                'max_spin': max_spin,
                'rev_chk': rev_chk
            })

    def select_servo_from_row(self, servo_idx):
        """Select servo from visualizer row click."""
        self.selected_servo.set(servo_idx)
        if hasattr(self, 'servo_selector'):
            self.servo_selector.current(servo_idx)
        self.on_servo_select()

    def apply_global_clamp_to_all(self):
        """Apply global clamp sliders to all servos."""
        min_lim = int(self.global_clamp_min.get())
        max_lim = int(self.global_clamp_max.get())
        if min_lim > max_lim:
            min_lim, max_lim = max_lim, min_lim
            self.global_clamp_min.set(min_lim)
            self.global_clamp_max.set(max_lim)

        for i in range(self.num_servos):
            self.servo_limits[i] = (min_lim, max_lim)
            if hasattr(self, 'servo_min_vars') and i < len(self.servo_min_vars):
                self.servo_min_vars[i].set(min_lim)
                self.servo_max_vars[i].set(max_lim)

        self.apply_servo_limits_to_state()
        self.update_large_bar()
        self.update_small_servo_bars()
        self.update_visual_feedback()

    def effective_servo_limits(self):
        """The clamp a STANDALONE sketch has to enforce for itself.

        The listener can bake a wide backstop because the host clamps every
        frame on the way out. An exported movement/Markov/PIR sketch has no
        host: it is the whole system, so whatever the UI was applying has to
        be compiled into it or the piece plays back with a different range
        than it was performed with.

        That is the per-channel limit intersected with the expressive range.
        Where they do not overlap the expressive range wins, since it is the
        outer authority, and the channel is pinned rather than left free."""
        lo_global = int(self.hardware_config.get('global_min_angle', 0))
        hi_global = int(self.hardware_config.get('global_max_angle', 180))
        return [self.effective_limits_for(i) for i in range(self.num_servos)]

    def effective_limits_for(self, servo_idx):
        """Effective range for one channel. Same rule as the exported arrays,
        so the live path and any generated sketch clamp and mirror identically."""
        lo_global = int(self.hardware_config.get('global_min_angle', 0))
        hi_global = int(self.hardware_config.get('global_max_angle', 180))
        try:
            lo, hi = self.servo_limits[servo_idx]
        except (IndexError, TypeError, ValueError):
            lo, hi = 0, 180
        lo = max(int(lo), lo_global)
        hi = min(int(hi), hi_global)
        if lo > hi:
            lo = hi
        return lo, hi

    def effective_limits_c_arrays(self):
        """The same limits rendered as two C initialiser lists."""
        limits = self.effective_servo_limits()
        return (', '.join(str(lo) for lo, _ in limits),
                ', '.join(str(hi) for _, hi in limits))

    def push_servo_state_to_config(self):
        """Write the live per-channel limits and reversal back into the config.

        servo_limits/servo_reversed are derived FROM hardware_config at load,
        but the visualizer's row controls and the preset loader only ever wrote
        the derived copies. Everything that generates a sketch reads the
        config, so edits made on the bars drove correctly live and then came
        out wrong in every export -- and were reverted whenever the config was
        re-applied, since that re-derives from the config. One direction of
        truth was missing; this is it."""
        self.hardware_config['per_servo_limits'] = [
            [int(lo), int(hi)] for lo, hi in self.servo_limits[:self.num_servos]]
        self.hardware_config['reversed_servos'] = sorted(
            i for i in range(self.num_servos) if self.servo_reversed[i])

    def on_bar_limits_changed(self, servo_idx):
        """Apply min/max clamp edits from visualizer row controls."""
        min_lim = int(self.servo_min_vars[servo_idx].get())
        max_lim = int(self.servo_max_vars[servo_idx].get())

        min_lim = max(0, min(180, min_lim))
        max_lim = max(0, min(180, max_lim))
        if min_lim > max_lim:
            min_lim, max_lim = max_lim, min_lim

        self.servo_min_vars[servo_idx].set(min_lim)
        self.servo_max_vars[servo_idx].set(max_lim)
        self.servo_limits[servo_idx] = (min_lim, max_lim)
        self.push_servo_state_to_config()

        self.apply_servo_limits_to_state()
        self.update_large_bar()
        self.update_small_servo_bars()
        self.update_visual_feedback()

    def on_bar_reverse_changed(self, servo_idx):
        """Apply reverse toggle from visualizer row controls.

        Writes through to hardware_config, which is the copy every exporter
        reads. This used to set only self.servo_reversed, so a channel flipped
        on its bar drove correctly live and then came out unreversed in every
        generated sketch -- and was silently reverted the next time the config
        was applied, since that re-derives servo_reversed from the config."""
        self.servo_reversed[servo_idx] = bool(self.servo_rev_vars[servo_idx].get())

        self.push_servo_state_to_config()
        # Keep the Hardware Config checkboxes showing the same truth
        if hasattr(self, 'config_reversed_vars'):
            flagged = self.hardware_config['reversed_servos']
            for i, var in enumerate(self.config_reversed_vars):
                if i < self.num_servos:
                    var.set(i in flagged)

        self.update_large_bar()
        self.update_small_servo_bars()
        self.update_visual_feedback()

    def sync_pose_from_board(self):
        """Adopt the pose the board reported at boot, if it reported one.

        The board is the authority on where the hand physically is -- the
        config only records what was baked the last time a listener was
        generated here, which says nothing about a sketch flashed from another
        machine or edited by hand. Adopting on connect means the host's first
        frame asks for the pose the hand is already holding, so connecting
        moves nothing.

        Reported values are hardware degrees (post-reversal, as the wire
        carries them). get_hardware_position mirrors within the channel's
        limits, and a mirror is its own inverse, so passing them back through
        it recovers the logical angle the sliders should show."""
        if not self.hand_controller:
            return False
        reported = getattr(self.hand_controller, 'reported_pose', None)
        if not reported or len(reported) < self.num_servos:
            return False

        logical = [self.get_hardware_position(i, reported[i]) for i in range(self.num_servos)]
        self.finger_positions = [float(v) for v in logical[:self.num_fingers]]
        self.arm_positions = [float(v) for v in logical[self.num_fingers:]]
        self.hardware_config['startup_pose'] = [int(round(v)) for v in reported]

        # The bars may not exist yet when this runs during construction
        for refresh in ('update_large_bar', 'update_small_servo_bars', 'update_visual_feedback'):
            if hasattr(self, refresh):
                try:
                    getattr(self, refresh)()
                except Exception:
                    pass
        # Plain ASCII on purpose: this runs before the first frame goes out, and
        # a cp1252 console raises UnicodeEncodeError on the emoji the rest of
        # this file logs with. Losing the sync to a failed log line would put
        # the lurch straight back.
        print(f"[POSE] Adopted board startup pose: {[int(round(v)) for v in reported]}")
        return True

    def get_startup_pose(self):
        """The rig's rest pose, in degrees, one entry per channel.

        Single source of truth for three things that must agree or the hand
        jumps: the sketch's baked startupPositions[], the UI's opening slider
        state, and the pose sent on reconnect. Stored by the listener generator
        so whatever gets flashed is what the UI comes up holding.

        Missing or short config falls back to the middle of the expressive
        range rather than a fixed 90 -- on a rig configured 0-80, 90 is past
        the end of everything."""
        cfg = self.hardware_config
        lo = cfg.get('global_min_angle', 0)
        hi = cfg.get('global_max_angle', 180)
        midpoint = (lo + hi) / 2.0

        pose = list(cfg.get('startup_pose') or [])
        while len(pose) < self.num_servos:
            pose.append(midpoint)
        pose = pose[:self.num_servos]

        return [self.clamp_servo_angle(i, pose[i]) for i in range(self.num_servos)]

    def clamp_servo_angle(self, servo_idx, angle):
        """Clamp a servo angle to its EFFECTIVE range.

        Effective = the channel's own limits intersected with the expressive
        range, so setting the expressive range once covers every channel and
        the per-channel limits are only needed where a channel wants something
        tighter.

        This used to consult only the per-channel limits, which let the sliders
        and the stored state travel past the expressive range: the hardware got
        the clamped value but the UI showed, and RECORDED, the unclamped one.
        Takes then contained motion that never happened, and replayed
        differently through a sketch that clamps correctly."""
        min_lim, max_lim = self.effective_limits_for(servo_idx)
        angle = float(angle)
        return max(min_lim, min(max_lim, angle))

    def apply_servo_limits_to_state(self):
        """Clamp all current logical positions to configured servo limits."""
        for i in range(self.num_fingers):
            self.finger_positions[i] = self.clamp_servo_angle(i, self.finger_positions[i])
        for i in range(self.num_arm_servos):
            servo_idx = self.num_fingers + i
            self.arm_positions[i] = self.clamp_servo_angle(servo_idx, self.arm_positions[i])

    def get_hardware_position(self, servo_idx, logical_angle):
        """Map logical angle to hardware angle with optional per-servo reversal."""
        logical_angle = self.clamp_servo_angle(servo_idx, logical_angle)
        if self.servo_reversed[servo_idx]:
            # Mirror within the EFFECTIVE range, not the raw per-servo limits.
            # Mirroring around limits wider than the expressive range threw the
            # result past that range, where the clamp downstream flattened it:
            # with limits 0-180 and an expressive range of 0-80, every logical
            # angle from 0 to 100 came out as 80. The channel did not read as
            # reversed, it read as dead -- and no export could match it either,
            # since a sketch mirrors within the range it was given.
            min_lim, max_lim = self.effective_limits_for(servo_idx)
            logical_angle = max(min_lim, min(max_lim, logical_angle))
            return min_lim + max_lim - logical_angle
        return logical_angle

    def save_servo_preset(self):
        """Save current servo limits/reversal and cursor tuning as a preset JSON."""
        from tkinter import filedialog

        timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        filename = filedialog.asksaveasfilename(
            title="Save Servo Preset",
            defaultextension=".json",
            filetypes=[("JSON files", "*.json"), ("All files", "*.*")],
            initialdir=os.getcwd(),
            initialfile=f"servo_preset_{timestamp}.json"
        )

        if not filename:
            return

        preset = {
            'version': '1.0',
            'preset_type': 'servo_calibration',
            'timestamp': timestamp,
            'default_port': self.default_port,
            'servo_limits': [[int(min_lim), int(max_lim)] for min_lim, max_lim in self.servo_limits],
            'servo_reversed': [bool(flag) for flag in self.servo_reversed],
            'cursor_settings': {
                'wave': self.cursor_sensitivity.get(),
                'wave_y': self.cursor_sensitivity_y.get(),
                'range': self.servo_range.get(),
                'gravity': self.wave_gravity.get(),
                'offset': self.wave_offset.get()
            }
        }

        try:
            with open(filename, 'w') as f:
                json.dump(preset, f, indent=2)
            tkinter.messagebox.showinfo("Preset Saved", f"Servo preset saved to:\n{filename}")
            print(f"💾 Servo preset saved: {filename}")
        except Exception as e:
            tkinter.messagebox.showerror("Save Failed", f"Failed to save preset:\n{e}")

    def load_servo_preset(self):
        """Load servo limits/reversal and cursor tuning preset from JSON."""
        from tkinter import filedialog

        filename = filedialog.askopenfilename(
            title="Load Servo Preset",
            filetypes=[("JSON files", "*.json"), ("All files", "*.*")],
            initialdir=os.getcwd()
        )

        if not filename:
            return

        try:
            with open(filename, 'r') as f:
                preset = json.load(f)

            # Presets written by the 8-servo build come back short. Accept any
            # length up to the current channel count and pad the rest with
            # defaults, rather than silently ignoring the whole preset.
            loaded_limits = preset.get('servo_limits', [])
            if loaded_limits:
                new_limits = []
                for item in loaded_limits[:self.num_servos]:
                    if isinstance(item, dict):
                        min_lim = int(item.get('min', 0))
                        max_lim = int(item.get('max', 180))
                    else:
                        min_lim = int(item[0])
                        max_lim = int(item[1])
                    min_lim = max(0, min(180, min_lim))
                    max_lim = max(0, min(180, max_lim))
                    if min_lim > max_lim:
                        min_lim, max_lim = max_lim, min_lim
                    new_limits.append((min_lim, max_lim))
                while len(new_limits) < self.num_servos:
                    new_limits.append((0, 180))
                self.servo_limits = new_limits

            loaded_reversed = preset.get('servo_reversed', [])
            if isinstance(loaded_reversed, list) and loaded_reversed:
                flags = [bool(flag) for flag in loaded_reversed[:self.num_servos]]
                while len(flags) < self.num_servos:
                    flags.append(False)
                self.servo_reversed = flags

            cursor_settings = preset.get('cursor_settings', {})
            if isinstance(cursor_settings, dict):
                self.cursor_sensitivity.set(float(cursor_settings.get('wave', self.cursor_sensitivity.get())))
                # presets saved before the X/Y split carry no 'wave_y'
                self.cursor_sensitivity_y.set(float(cursor_settings.get('wave_y', self.cursor_sensitivity_y.get())))
                self.servo_range.set(float(cursor_settings.get('range', self.servo_range.get())))
                self.wave_gravity.set(float(cursor_settings.get('gravity', self.wave_gravity.get())))
                self.wave_offset.set(float(cursor_settings.get('offset', self.wave_offset.get())))

            # A preset that only touched the derived copies left every exporter
            # reading the pre-load config -- push it through before anything
            # redraws or generates.
            self.push_servo_state_to_config()
            if hasattr(self, 'config_reversed_vars'):
                flagged = self.hardware_config['reversed_servos']
                for i, var in enumerate(self.config_reversed_vars):
                    if i < self.num_servos:
                        var.set(i in flagged)

            self.apply_servo_limits_to_state()
            if hasattr(self, 'servo_min_vars'):
                # was min(8, ...): S8 and S9 kept displaying the previous
                # preset's limits after a load
                for i in range(min(self.num_servos, len(self.servo_min_vars))):
                    min_lim, max_lim = self.servo_limits[i]
                    self.servo_min_vars[i].set(min_lim)
                    self.servo_max_vars[i].set(max_lim)
                    self.servo_rev_vars[i].set(self.servo_reversed[i])
            self.update_large_bar()
            self.update_small_servo_bars()
            self.update_visual_feedback()

            tkinter.messagebox.showinfo("Preset Loaded", f"Servo preset loaded from:\n{os.path.basename(filename)}")
            print(f"📂 Servo preset loaded: {filename}")
        except Exception as e:
            tkinter.messagebox.showerror("Load Failed", f"Failed to load preset:\n{e}")
    
    def on_servo_select(self, event=None):
        """Handle servo selection change."""
        self.selected_servo.set(self.servo_selector.current())
        all_names = self.all_servo_names
        servo_idx = self.selected_servo.get()
        self.large_bar_canvas.itemconfig(self.large_bar_name, text=all_names[servo_idx])
        self.update_large_bar()
    
    def update_large_bar(self):
        """Update the large control bar."""
        servo_idx = self.selected_servo.get()
        all_positions = list(self.finger_positions) + list(self.arm_positions)
        
        if servo_idx >= len(all_positions):
            return
            
        pos = all_positions[servo_idx]
        # Effective, not raw: the markers have to sit where the channel really
        # stops, or the bar shows travel the hardware will never make.
        min_lim, max_lim = self.effective_limits_for(servo_idx)
        pos = self.clamp_servo_angle(servo_idx, pos)
        bar_height = 350
        
        coords = self.large_bar_canvas.coords(self.large_bar_rect)
        if len(coords) == 4:
            x1, y1, x2, y2 = coords
            fill_height = (pos / 180.0) * bar_height
            min_marker_y = y2 - ((min_lim / 180.0) * bar_height)
            max_marker_y = y2 - ((max_lim / 180.0) * bar_height)
            
            self.large_bar_canvas.coords(self.large_bar_fill,
                x1, y2 - fill_height, x2, y2)
            self.large_bar_canvas.coords(self.large_bar_min_line, x1, min_marker_y, x2, min_marker_y)
            self.large_bar_canvas.coords(self.large_bar_max_line, x1, max_marker_y, x2, max_marker_y)
            
            # Color coding
            if pos < 60:
                color = '#2196F3'
            elif pos > 120:
                color = '#f44336'
            else:
                color = '#4CAF50'
                
            self.large_bar_canvas.itemconfig(self.large_bar_fill, fill=color)
            self.large_bar_canvas.itemconfig(self.large_bar_value, text=f"{int(pos)}°")
            reverse_text = " ON" if self.servo_reversed[servo_idx] else " OFF"
            # Name the binding constraint. "Clamp: 0-60" against a bar set to
            # 0-180 otherwise looks like the bar is being ignored.
            raw_lo, raw_hi = self.servo_limits[servo_idx]
            source = "" if (min_lim, max_lim) == (raw_lo, raw_hi) else " (global)"
            self.large_bar_canvas.itemconfig(
                self.large_bar_range_label,
                text=f"Clamp: {min_lim}° - {max_lim}°{source} | Rev:{reverse_text}")
    
    def update_small_servo_bars(self):
        """Update all small servo bars."""
        all_positions = list(self.finger_positions) + list(self.arm_positions)
        
        for i, bar_info in enumerate(self.small_bars):
            if i >= len(all_positions):
                continue
                
            pos = all_positions[i]
            min_lim, max_lim = self.effective_limits_for(i)
            pos = self.clamp_servo_angle(i, pos)
            bar_width = (pos / 180.0) * 150
            clamp_min_x = (min_lim / 180.0) * 150
            clamp_max_x = (max_lim / 180.0) * 150
            
            bar_info['canvas'].coords(bar_info['fill'], 0, 0, bar_width, 20)
            bar_info['canvas'].coords(bar_info['clamp_min_marker'], clamp_min_x, 0, clamp_min_x, 20)
            bar_info['canvas'].coords(bar_info['clamp_max_marker'], clamp_max_x, 0, clamp_max_x, 20)
            name = self.all_servo_names[i]
            reversed_suffix = " ↺" if self.servo_reversed[i] else ""
            bar_info['name_label'].config(text=f"{name}{reversed_suffix}:")

            if i == self.selected_servo.get():
                bar_info['canvas'].config(highlightthickness=2, highlightbackground='#0066cc')
            else:
                bar_info['canvas'].config(highlightthickness=1, highlightbackground='#777777')
            
            if pos < 60:
                color = '#2196F3'
            elif pos > 120:
                color = '#f44336'
            else:
                color = '#4CAF50'
                
            bar_info['canvas'].itemconfig(bar_info['fill'], fill=color)
            bar_info['label'].config(text=f"{int(pos)}° [{min_lim}-{max_lim}]")
    
    def on_large_bar_click(self, event):
        """Handle click on large bar."""
        self.on_large_bar_drag(event)
    
    def on_large_bar_hover(self, event):
        """Handle hovering on large bar (if hover mode enabled)."""
        if not self.hover_mode.get():
            return
        # Use the same logic as drag
        self.on_large_bar_drag(event)
    
    def on_large_bar_drag(self, event):
        """Handle dragging on large bar."""
        if self.control_mode.get() != "manual":
            return
            
        coords = self.large_bar_canvas.coords(self.large_bar_rect)
        if len(coords) != 4:
            return
            
        x1, y1, x2, y2 = coords
        bar_height = y2 - y1
        
        if y1 <= event.y <= y2:
            normalized = (event.y - y1) / bar_height
            servo_idx = self.selected_servo.get()
            angle = 180 - (normalized * 180)
            angle = self.clamp_servo_angle(servo_idx, angle)
            
            if servo_idx < self.num_fingers:
                self.finger_positions[servo_idx] = angle
            else:
                arm_idx = servo_idx - self.num_fingers
                self.arm_positions[arm_idx] = angle
            
            if self.layer_recording:
                self.record_current_state()
            
            self.update_large_bar()
            self.update_small_servo_bars()
    
    def create_arm_calibration_controls(self):
        """Create dedicated controls for coordinated arm movement calibration."""
        # Movement pattern selection
        pattern_frame = tk.LabelFrame(self.arm_cal_frame, text="Scratch Movement Pattern", 
                                     bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        pattern_frame.pack(fill=tk.X, padx=5, pady=5)
        
        self.scratch_pattern = tk.StringVar(value="vertical")
        patterns = [
            ("↕️ Vertical Scratch", "vertical"),
            ("↔️ Horizontal Scratch", "horizontal"), 
            ("🌀 Circular Scratch", "circular"),
            ("🎯 Custom Pattern", "custom")
        ]
        
        for text, value in patterns:
            tk.Radiobutton(pattern_frame, text=text, variable=self.scratch_pattern, value=value,
                          bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                          command=self.update_scratch_pattern).pack(anchor=tk.W, padx=10, pady=2)
        
        # Coordinated arm controls
        coord_frame = tk.LabelFrame(self.arm_cal_frame, text="Coordinated Arm Movement", 
                                   bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        coord_frame.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        
        # Movement amplitude control
        tk.Label(coord_frame, text="Movement Range:", bg=self.colors['bg_frame'], fg=self.colors['text_main']).pack()
        self.movement_range = tk.DoubleVar(value=30.0)
        range_scale = tk.Scale(coord_frame, from_=10.0, to=60.0, variable=self.movement_range, 
                              orient=tk.HORIZONTAL, bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        range_scale.pack(fill=tk.X, padx=10, pady=5)
        
        # Speed control
        tk.Label(coord_frame, text="Movement Speed:", bg=self.colors['bg_frame'], fg=self.colors['text_main']).pack()
        self.movement_speed = tk.DoubleVar(value=1.0)
        speed_scale = tk.Scale(coord_frame, from_=0.1, to=3.0, resolution=0.1, variable=self.movement_speed,
                              orient=tk.HORIZONTAL, bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        speed_scale.pack(fill=tk.X, padx=10, pady=5)
        
        # Individual arm servo contribution
        contrib_frame = tk.LabelFrame(coord_frame, text="Servo Contributions to Movement", 
                                     bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        contrib_frame.pack(fill=tk.X, padx=5, pady=5)
        
        # Keyed by the CURRENT channel labels. The scratch helpers below ask
        # for anatomy keys ("Wrist Tilt", "Wrist Rotate") that have never
        # existed in this dict, so they go through arm_contrib() and fall
        # back to 1.0 instead of raising KeyError.
        self.arm_contributions = {}
        for i, name in enumerate(self.arm_names):
            tk.Label(contrib_frame, text=f"{name} Contribution:", 
                    bg=self.colors['bg_frame'], fg=self.colors['text_main']).pack()
            var = tk.DoubleVar(value=1.0)
            self.arm_contributions[name] = var
            contrib_scale = tk.Scale(contrib_frame, from_=0.0, to=2.0, resolution=0.1, variable=var,
                                   orient=tk.HORIZONTAL, bg=self.colors['bg_frame'], fg=self.colors['text_main'])
            contrib_scale.pack(fill=tk.X, padx=10, pady=2)
        
        # Movement test buttons
        test_frame = tk.Frame(coord_frame, bg=self.colors['bg_frame'])
        test_frame.pack(fill=tk.X, padx=5, pady=10)
        
        ctk.CTkButton(test_frame, text="▶️ Test Movement", command=self.test_scratch_movement,
                 font=('Arial', 11), width=120).pack(side=tk.LEFT, padx=5)
        ctk.CTkButton(test_frame, text="⏹️ Stop Test", command=self.stop_test_movement,
                 font=('Arial', 11), width=90).pack(side=tk.LEFT, padx=5)
        ctk.CTkButton(test_frame, text="🏠 Center Arms", command=self.center_arms,
                 font=('Arial', 11), width=100).pack(side=tk.LEFT, padx=5)
        
        # Export dedicated scratch movement
        export_frame = tk.Frame(coord_frame, bg=self.colors['bg_frame'])
        export_frame.pack(fill=tk.X, padx=5, pady=10)
        
        ctk.CTkButton(export_frame, text="📤 Export Scratch Movement", command=self.export_scratch_arduino,
                 font=('Arial', 11), width=180).pack(side=tk.LEFT, padx=5)
    
    def on_mode_change(self):
        """Handle control mode change."""
        mode = self.control_mode.get()
        if mode == "cursor":
            print("🖱️ Switched to cursor wave control")
        else:
            print("🎛️ Switched to individual servo control")
        
        # Update visual feedback immediately
        self.update_visual_feedback()
    
    def on_canvas_resize(self, event):
        """Redraw visual feedback when canvas is resized."""
        # Avoid recursive calls and only resize if size actually changed
        if hasattr(self, '_last_canvas_size'):
            if self._last_canvas_size == (event.width, event.height):
                return
        self._last_canvas_size = (event.width, event.height)
        
        # Recreate visual elements for new size
        self.root.after(50, self.create_visual_feedback)
    
    def on_mouse_move(self, event):
        """Handle mouse movement for cursor wave control."""
        if self.control_mode.get() != "cursor":
            return
            
        # Convert mouse position to normalized values
        x_norm = event.x / max(self.canvas.winfo_width(), 1)
        y_norm = event.y / max(self.canvas.winfo_height(), 1)
        
        # Get control parameters
        sensitivity_x = self.cursor_sensitivity.get()
        sensitivity_y = self.cursor_sensitivity_y.get()
        servo_range = self.servo_range.get()
        gravity = self.wave_gravity.get()
        offset = self.wave_offset.get()
        
        # Spread the wave across the channels that are actually ENABLED, not
        # across all ten. Otherwise switching S5..S9 on would squash the five
        # you already had into one corner of the waveform and change how every
        # existing setup feels.
        active = [i for i in range(self.num_servos) if self.wave_enabled[i].get()]

        for slot, i in enumerate(active):
            # Position within the wave, 0..1 across the enabled channels
            finger_offset = (slot / max(len(active) - 1, 1)) - 0.5  # -0.5 to 0.5

            # Wave influence from X position
            wave_influence = math.sin((x_norm + finger_offset) * math.pi * sensitivity_x)

            # Gravity pull from Y position (0=top pulls up, 1=bottom pulls down)
            # Y sensitivity scales how much of the pad's height you need to
            # travel for full deflection; clamped so >1.0 saturates early
            # rather than wrapping past the ends of the range.
            gravity_pull = (y_norm - 0.5) * 2 * sensitivity_y  # -1 (top) to 1 (bottom)
            gravity_pull = max(-1.0, min(1.0, gravity_pull))
            
            # Combine: wave creates the pattern, gravity pulls everything up/down
            total_influence = wave_influence * (1.0 - gravity) + gravity_pull * gravity

            # Convert influence (-1..1) to selected servo's full clamp span (min..max)
            # so reduced physical ranges still use the entire mouse expressive space.
            min_lim, max_lim = self.servo_limits[i]
            span = max(max_lim - min_lim, 1)

            # Apply offset/range shaping before normalization
            shaped = total_influence + (offset / 90.0)
            shaped = max(-1.0, min(1.0, shaped))

            norm_01 = (shaped + 1.0) / 2.0
            angle = min_lim + (norm_01 * span)

            # Optional per-servo reverse in wave controller
            if self.servo_reversed[i]:
                angle = max_lim - (angle - min_lim)

            angle = self.clamp_servo_angle(i, angle)

            # Channels 0-4 live in finger_positions, 5-9 in arm_positions --
            # storage split only, the wave treats them identically
            if i < self.num_fingers:
                self.finger_positions[i] = angle
            else:
                self.arm_positions[i - self.num_fingers] = angle

        # Record if we're recording
        if self.layer_recording:
            self.record_current_state()
    
    def on_servo_change(self, servo_index, value):
        """Handle individual servo slider changes."""
        if self.control_mode.get() != "manual":
            return
            
        angle = float(value)
        
        if servo_index < self.num_fingers:
            self.finger_positions[servo_index] = self.clamp_servo_angle(servo_index, angle)
            print(f"🎛️ {self.finger_names[servo_index]}: {angle}°")
        else:
            arm_index = servo_index - self.num_fingers
            self.arm_positions[arm_index] = self.clamp_servo_angle(servo_index, angle)
            print(f"🎛️ {self.arm_names[arm_index]}: {angle}°")
        
        # Record if we're recording
        if self.layer_recording:
            self.record_current_state()
    
    def update_scratch_pattern(self):
        """Update the scratch movement pattern."""
        pattern = self.scratch_pattern.get()
        print(f"🤖 Scratch pattern changed to: {pattern}")
    
    def test_scratch_movement(self):
        """Test the coordinated scratch movement."""
        print("🤖 Testing scratch movement...")
        pattern = self.scratch_pattern.get()
        range_val = self.movement_range.get()
        speed = self.movement_speed.get()
        
        # Simple test movement - just move the servos in a coordinated pattern
        if pattern == "vertical":
            self.perform_vertical_scratch(range_val, speed)
        elif pattern == "horizontal":
            self.perform_horizontal_scratch(range_val, speed)
        elif pattern == "circular":
            self.perform_circular_scratch(range_val, speed)
    
    def perform_vertical_scratch(self, range_val, speed):
        """Perform vertical scratching movement."""
        # Move wrist tilt and elbow in coordination for vertical scratch
        wrist_contrib = self.arm_contrib("Wrist Tilt")
        elbow_contrib = self.arm_contrib("Elbow")
        
        # Simple up-down movement
        for i in range(5):
            # Up position
            self.arm_positions[1] = 90 + (range_val * wrist_contrib)  # Wrist Tilt
            self.arm_positions[2] = 90 - (range_val * 0.5 * elbow_contrib)  # Elbow
            self.send_to_hardware()
            time.sleep(0.5/speed)
            
            # Down position  
            self.arm_positions[1] = 90 - (range_val * wrist_contrib)  # Wrist Tilt
            self.arm_positions[2] = 90 + (range_val * 0.3 * elbow_contrib)  # Elbow
            self.send_to_hardware()
            time.sleep(0.5/speed)
    
    def perform_horizontal_scratch(self, range_val, speed):
        """Perform horizontal scratching movement."""
        rotate_contrib = self.arm_contrib("Wrist Rotate")
        
        # Simple left-right movement
        for i in range(5):
            # Left position
            self.arm_positions[0] = 90 - (range_val * rotate_contrib)  # Wrist Rotate
            self.send_to_hardware()
            time.sleep(0.3/speed)
            
            # Right position
            self.arm_positions[0] = 90 + (range_val * rotate_contrib)  # Wrist Rotate  
            self.send_to_hardware()
            time.sleep(0.3/speed)
    
    def perform_circular_scratch(self, range_val, speed):
        """Perform circular scratching movement."""
        import math
        
        rotate_contrib = self.arm_contrib("Wrist Rotate")
        tilt_contrib = self.arm_contrib("Wrist Tilt")
        
        # Circular movement using both wrist rotate and tilt
        for i in range(20):
            angle = (i / 20.0) * 2 * math.pi
            
            self.arm_positions[0] = 90 + (range_val * rotate_contrib * math.cos(angle))  # Wrist Rotate
            self.arm_positions[1] = 90 + (range_val * tilt_contrib * math.sin(angle))   # Wrist Tilt
            
            self.send_to_hardware()
            time.sleep(0.1/speed)
    
    def stop_test_movement(self):
        """Stop any ongoing test movement."""
        print("🛑 Stopping test movement...")
        # Return to center positions
        self.center_arms()
    
    def center_arms(self):
        """Center all arm servos to 90 degrees."""
        print("🏠 Centering arm servos...")
        for i in range(len(self.arm_positions)):
            self.arm_positions[i] = 90.0
        self.send_to_hardware()
        self.update_visual_feedback()
    
    def export_scratch_arduino(self):
        """Export the current scratch movement pattern as optimized Arduino code."""
        pattern = self.scratch_pattern.get()
        range_val = self.movement_range.get()
        speed = self.movement_speed.get()
        
        # Generate optimized Arduino code for scratch movement
        code = f'''/*
 * ARM SCRATCH MOVEMENT - Optimized Code
 * Generated: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}
 * Pattern: {pattern.upper()}
 * Range: {range_val}°, Speed: {speed}x
 * 
 * Servos: Wrist Rotate (5), Wrist Tilt (6), Elbow (7)
 */

#include <Servo.h>

// Arm servos only (fingers can stay at rest position)
Servo wristRotate;  // Servo 5
Servo wristTilt;    // Servo 6  
Servo elbow;        // Servo 7

// Movement parameters
float range = {range_val};
float speed = {speed};
int baseDelay = (int)(500 / speed);

void setup() {{
  Serial.begin(9600);
  
  // Attach arm servos (adjust pins as needed)
  wristRotate.attach(13);  // Pin for wrist rotate
  wristTilt.attach(14);    // Pin for wrist tilt
  elbow.attach(15);        // Pin for elbow
  
  // Center all servos
  centerArms();
  delay(1000);
  
  Serial.println("ARM SCRATCH MOVEMENT Ready");
}}

void loop() {{
  Serial.println("Performing {pattern} scratch...");
  
'''
        
        # Add the specific movement pattern
        if pattern == "vertical":
            wrist_contrib = self.arm_contrib("Wrist Tilt")
            elbow_contrib = self.arm_contrib("Elbow")
            
            code += f'''  // Vertical scratch movement
  for(int cycle = 0; cycle < 5; cycle++) {{
    // Up position
    wristTilt.write(90 + (range * {wrist_contrib}));
    elbow.write(90 - (range * 0.5 * {elbow_contrib}));
    delay(baseDelay);
    
    // Down position
    wristTilt.write(90 - (range * {wrist_contrib}));
    elbow.write(90 + (range * 0.3 * {elbow_contrib}));
    delay(baseDelay);
  }}
'''
        elif pattern == "horizontal":
            rotate_contrib = self.arm_contrib("Wrist Rotate")
            
            code += f'''  // Horizontal scratch movement
  for(int cycle = 0; cycle < 5; cycle++) {{
    // Left position
    wristRotate.write(90 - (range * {rotate_contrib}));
    delay(baseDelay * 0.6);
    
    // Right position
    wristRotate.write(90 + (range * {rotate_contrib}));
    delay(baseDelay * 0.6);
  }}
'''
        elif pattern == "circular":
            rotate_contrib = self.arm_contrib("Wrist Rotate")
            tilt_contrib = self.arm_contrib("Wrist Tilt")
            
            code += f'''  // Circular scratch movement
  for(int i = 0; i < 20; i++) {{
    float angle = (i / 20.0) * 2 * PI;
    
    int rotatePos = 90 + (range * {rotate_contrib} * cos(angle));
    int tiltPos = 90 + (range * {tilt_contrib} * sin(angle));
    
    wristRotate.write(rotatePos);
    wristTilt.write(tiltPos);
    delay(baseDelay * 0.2);
  }}
'''
        
        code += '''  
  centerArms(); // Return to center
  delay(2000);  // Wait 2 seconds before next cycle
}

// Utility functions
void centerArms() {
  Serial.println("Centering arms...");
  wristRotate.write(90);
  wristTilt.write(90);
  elbow.write(90);
  delay(500);
}

// Manual control functions for calibration
void setScratchPosition(int rotate, int tilt, int elbowPos) {
  wristRotate.write(rotate);
  wristTilt.write(tilt);  
  elbow.write(elbowPos);
}
'''
        
        # Save to file
        filename = f"arm_scratch_{pattern}_{datetime.datetime.now().strftime('%Y%m%d_%H%M%S')}.ino"
        filepath = os.path.join(os.getcwd(), filename)
        
        try:
            with open(filepath, 'w') as f:
                f.write(code)
            
            tkinter.messagebox.showinfo("ARM SCRATCH Export Successful", 
                                      f"Optimized Arduino code exported to:\\n{filepath}\\n\\n" +
                                      f"Pattern: {pattern.upper()}\\n" +
                                      f"Range: {range_val}°, Speed: {speed}x\\n\\n" +
                                      "🎯 This code focuses ONLY on arm movement for scratching!")
            print(f"🤖 ARM SCRATCH Arduino code exported to {filepath}")
            
        except Exception as e:
            tkinter.messagebox.showerror("Export Failed", f"Failed to export Arduino code:\\n{e}")
    
    def control_loop(self):
        """Main control loop to send positions to hardware."""
        current_time = time.time()

        # Check for PIR events from Arduino
        self.check_pir_from_arduino()

        # Always keep logical positions inside configured servo limits
        self.apply_servo_limits_to_state()
        
        # Update PIR state machine if enabled
        if self.pir_enabled.get():
            self.update_pir_state_machine()
        
        # Update playback if active
        self.update_playback()
        
        # Record if active
        if self.layer_recording:
            self.record_current_state()
        
        if current_time - self.last_send_time >= self.send_interval:
            self.send_to_hardware()
            self.last_send_time = current_time
        
        # Update visual feedback. The timeline now draws real waveforms, so
        # it runs at ~13Hz instead of every tick -- a full re-trace on the
        # same thread as playback is exactly the kind of stall that shows up
        # as chop at the servo.
        self.update_visual_feedback()
        self.update_large_bar()
        self.update_small_servo_bars()
        self._timeline_tick = (self._timeline_tick + 1) % 3
        if self._timeline_tick == 0:
            self.update_timeline()
        self.update_recording_status()
        
        # Schedule next iteration
        self.root.after(25, self.control_loop)  # ~40Hz
    
    def send_to_hardware(self):
        """Send current positions to the hand controller."""
        if not self.hand_controller:
            return
            
        # Combine finger and arm positions for 8-servo command
        all_positions = self.finger_positions + self.arm_positions
        hardware_positions = []
        for i, angle in enumerate(all_positions):
            # In cursor wave mode, finger reversal is already applied in on_mouse_move.
            # Avoid double-reversing fingers on output.
            if self.control_mode.get() == "cursor" and self.wave_enabled[i].get():
                hardware_positions.append(self.clamp_servo_angle(i, angle))
            else:
                hardware_positions.append(self.get_hardware_position(i, angle))
        
        try:
            self.hand_controller.set_hand_positions(hardware_positions)
        except Exception as e:
            print(f"❌ Hardware communication error: {e}")
    
    def toggle_recording(self):
        """Start or stop layer recording."""
        print(f"[DEBUG] Toggle recording called. Current state: {self.layer_recording}")
        if self.layer_recording:
            self.stop_recording()
        else:
            self.start_recording()
    
    def start_recording(self):
        """Start recording a new layer."""
        self.layer_recording = True
        self.layer_record_start_time = time.time()
        self.current_layer_data = []
        
        # Track which servos are being recorded (changed during recording)
        self.recorded_servos = {'fingers': set(), 'arm': set()}
        
        # Auto-start playback if there are existing layers
        if self.recorded_layers and not self.is_playing:
            self.is_playing = True
            self.playback_start_time = time.time()
            self.playback_index = 0
            self.playback_btn.configure(text="⏹️ Stop", fg_color=self.colors['accent_red'])
            print(f"▶️ Auto-playing {len(self.recorded_layers)} existing layers")
        
        self.record_btn.configure(text="⏹️ Stop", fg_color=self.colors['accent_red'])
        
        # Show recording indicator on canvas
        if hasattr(self, 'rec_indicator_bg'):
            self.canvas.itemconfig(self.rec_indicator_bg, state='normal')
            self.canvas.itemconfig(self.rec_indicator_dot, state='normal')
            self.canvas.itemconfig(self.rec_indicator_text, state='normal')
            self.blink_recording_indicator()
        
        print("🔴 Started layer recording...")
    
    def stop_recording(self):
        """Stop recording the current layer."""
        self.layer_recording = False
        
        if self.current_layer_data:
            layer = {
                'name': f"Layer_{len(self.recorded_layers)+1}",
                'duration': time.time() - self.layer_record_start_time,
                'data': self.current_layer_data.copy(),
                'timestamp': datetime.datetime.now().isoformat(),
                'control_mode': self.control_mode.get(),
                'recorded_servos': self.recorded_servos  # Track which servos were recorded
            }
            
            self.recorded_layers.append(layer)
            print(f"✅ Layer recorded: {len(self.current_layer_data)} points over {layer['duration']:.1f}s")
            
            # If this is the FIRST layer, set it as the loop duration constraint
            if len(self.recorded_layers) == 1:
                self.loop_duration.set(round(layer['duration'], 2))
                print(f"⏱️ First layer sets loop duration: {layer['duration']:.2f}s (all future layers constrained to this time)")
        
        self.record_btn.configure(text="🔴 Record", fg_color=self.default_button_color)
        
        # Hide recording indicator
        if hasattr(self, 'rec_indicator_bg'):
            self.canvas.itemconfig(self.rec_indicator_bg, state='hidden')
            self.canvas.itemconfig(self.rec_indicator_dot, state='hidden')
            self.canvas.itemconfig(self.rec_indicator_text, state='hidden')
        
        self.update_layer_list()
    
    def blink_recording_indicator(self):
        """Blink the recording indicator while recording."""
        if not self.layer_recording or not hasattr(self, 'rec_indicator_dot'):
            return
        
        # Toggle visibility of the dot for blink effect
        current_state = self.canvas.itemcget(self.rec_indicator_dot, 'state')
        new_state = 'hidden' if current_state == 'normal' else 'normal'
        self.canvas.itemconfig(self.rec_indicator_dot, state=new_state)
        
        # Schedule next blink
        self.root.after(500, self.blink_recording_indicator)
    
    def toggle_playback(self):
        """Toggle playback of ALL recorded layers simultaneously."""
        if not self.recorded_layers:
            print("❌ No layers to play back")
            return
        
        self.is_playing = not self.is_playing
        # Organic is a PROPERTY of playback now, not a rival transport. It used
        # to be reachable only through a second play button, and pressing Play
        # silently cleared it -- so the sliders sat there doing nothing and what
        # you previewed was never what you exported.
        self.markov_mode = bool(self.organic_enabled.get())

        if self.is_playing:
            # Start playing ALL recorded layers simultaneously
            self.playback_start_time = time.time()
            self.playback_index = 0
            if self.markov_mode:
                self.init_organic_state()
            self.playback_btn.configure(text="⏹️ Stop", fg_color=self.colors['accent_red'])
            organic_note = (f" + organic (±{self.position_wobble.get()}°, "
                            f"±{self.timing_jitter.get()}% jitter)") if self.markov_mode else ""
            print(f"▶️ Playing {len(self.recorded_layers)} layers simultaneously{organic_note}")
        else:
            # Stop playback
            self.is_playing = False
            self.playback_layer = None
            self.playback_btn.configure(text="▶️ Play", fg_color=self.default_button_color)
            print("⏹️ Playback stopped")
        
        self.update_timeline()
    
    # --- consolidated .ino export ------------------------------------------
    EXPORT_MODES = [
        ('basic',   'Basic loop',            'All layers, full detail, loops forever'),
        ('pir',     'PIR state machine',     'Compressed idle/active/sleep states'),
        ('markov',  'PIR Markov phrases',    'Segment shuffling between phrases'),
        ('scratch', 'Scratch movement only', 'Arm scratch pattern, ignores layers'),
    ]

    def detect_export_mode(self):
        """Pick the sketch that matches how the UI is currently set up.

        The mode was previously implied by WHICH button you found, which is
        why there were four of them. Here it is derived from the same state
        that drives playback."""
        if self.pir_enabled.get():
            if self.pir_markov_enabled.get():
                return 'markov'
            return 'pir'
        return 'basic'

    def export_mode_available(self, mode):
        """(ok, reason) for a mode given current state."""
        if mode in ('basic', 'markov', 'pir') and not self.recorded_layers:
            return False, "no layers recorded"
        if mode == 'pir' and not self.pir_enabled.get():
            return True, "PIR mode is off - will export current layers as states"
        if mode == 'markov' and not self.pir_markov_enabled.get():
            return True, "Markov is off in the PIR panel"
        return True, ""

    def open_export_dialog(self):
        """One export door. Shows what will be written, from live UI state."""
        if not self.recorded_layers and self.detect_export_mode() != 'scratch':
            tkinter.messagebox.showwarning(
                "Nothing to export",
                "No layers recorded yet.\n\nRecord a pass first, or pick "
                "\"Scratch movement only\" which does not use layers.")

        dlg = tk.Toplevel(self.root)
        dlg.title("Export .ino")
        dlg.configure(bg=self.colors['bg_main'])
        dlg.transient(self.root)
        dlg.grab_set()
        dlg.resizable(False, False)

        detected = self.detect_export_mode()
        mode_var = tk.StringVar(value=detected)

        # --- sketch type ---
        type_box = tk.LabelFrame(dlg, text="Sketch type", bg=self.colors['bg_frame'],
                                 fg=self.colors['text_main'], font=('Arial', 9, 'bold'))
        type_box.pack(fill=tk.X, padx=10, pady=(10, 6))
        for key, label, blurb in self.EXPORT_MODES:
            row = tk.Frame(type_box, bg=self.colors['bg_frame'])
            row.pack(fill=tk.X, padx=6, pady=1)
            suffix = "   ← matches current setup" if key == detected else ""
            tk.Radiobutton(row, text=label + suffix, variable=mode_var, value=key,
                           bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                           font=('Arial', 9, 'bold' if key == detected else 'normal'),
                           selectcolor=self.colors['bg_dark'],
                           anchor='w').pack(side=tk.LEFT)
            tk.Label(row, text=blurb, bg=self.colors['bg_frame'],
                     fg=self.colors['text_dim'], font=('Arial', 7)).pack(side=tk.LEFT, padx=8)

        # --- what the sketch will actually contain, read from live state ---
        info_box = tk.LabelFrame(dlg, text="Reflects current UI", bg=self.colors['bg_frame'],
                                 fg=self.colors['text_main'], font=('Arial', 9, 'bold'))
        info_box.pack(fill=tk.X, padx=10, pady=6)

        cfg = self.hardware_config
        speed = self.playback_speed.get()
        loop_s = self.get_timeline_loop_duration()
        rows = [
            ("Layers", f"{len(self.recorded_layers)}"
                       + (f"   loop {loop_s:.1f}s" if loop_s else "")),
            ("Speed", f"{speed:.1f}x" + (f"   → {loop_s / speed:.1f}s exported"
                                         if loop_s and speed else "")),
            ("Channels", f"{self.num_servos}   S0-S{self.num_servos - 1}"),
            ("Pins", ", ".join(str(p) for p in cfg['pin_mapping'])),
            ("Baud", f"{cfg.get('baud_rate', 115200)}"),
            ("PIR pin", f"D{cfg.get('pir_pin', 2)}"),
        ]
        for k, v in rows:
            r = tk.Frame(info_box, bg=self.colors['bg_frame'])
            r.pack(fill=tk.X, padx=6, pady=1)
            tk.Label(r, text=k, width=10, anchor='w', bg=self.colors['bg_frame'],
                     fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
            tk.Label(r, text=v, anchor='w', bg=self.colors['bg_frame'],
                     fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT)

        # --- organic, mirroring the live sliders ---
        org_box = tk.LabelFrame(dlg, text="Organic", bg=self.colors['bg_frame'],
                                fg=self.colors['text_main'], font=('Arial', 9, 'bold'))
        org_box.pack(fill=tk.X, padx=10, pady=6)
        bake_var = tk.BooleanVar(value=bool(self.organic_enabled.get()))
        tk.Checkbutton(org_box, text="Bake organic variation into the sketch",
                       variable=bake_var, bg=self.colors['bg_frame'],
                       fg=self.colors['text_main'], font=('Arial', 9),
                       selectcolor=self.colors['bg_dark']).pack(anchor='w', padx=6, pady=(4, 0))
        tk.Label(org_box,
                 text=f"wobble ±{self.position_wobble.get():.1f}°    "
                      f"jitter ±{self.timing_jitter.get():.0f}%    "
                      f"pause {self.pause_chance.get():.0f}%"
                      + ("" if self.organic_enabled.get()
                         else "     (organic is currently OFF for playback)"),
                 bg=self.colors['bg_frame'], fg=self.colors['text_dim'],
                 font=('Arial', 8)).pack(anchor='w', padx=26, pady=(0, 5))

        # --- name it, here, before anything is written ---
        name_box = tk.LabelFrame(dlg, text="Save as", bg=self.colors['bg_frame'],
                                 fg=self.colors['text_main'], font=('Arial', 9, 'bold'))
        name_box.pack(fill=tk.X, padx=10, pady=6)
        name_row = tk.Frame(name_box, bg=self.colors['bg_frame'])
        name_row.pack(fill=tk.X, padx=6, pady=5)
        name_var = tk.StringVar(value=getattr(self, 'pending_export_name', '') or '')
        name_entry = tk.Entry(name_row, textvariable=name_var, width=34, font=('Arial', 9))
        name_entry.pack(side=tk.LEFT)
        tk.Label(name_row, text=".ino", bg=self.colors['bg_frame'],
                 fg=self.colors['text_dim'], font=('Arial', 9)).pack(side=tk.LEFT, padx=(2, 8))
        tk.Label(name_box, text="blank = timestamped name",
                 bg=self.colors['bg_frame'], fg=self.colors['text_dim'],
                 font=('Arial', 7)).pack(anchor='w', padx=8, pady=(0, 4))

        status = tk.Label(dlg, text="", bg=self.colors['bg_main'],
                          fg=self.colors['text_dim'], font=('Arial', 8), anchor='w')
        status.pack(fill=tk.X, padx=12)

        def refresh_status(*_):
            ok, reason = self.export_mode_available(mode_var.get())
            status.config(text=("⚠ " + reason) if reason else "")

        mode_var.trace('w', refresh_status)
        refresh_status()

        btn_row = tk.Frame(dlg, bg=self.colors['bg_main'])
        btn_row.pack(fill=tk.X, padx=10, pady=(4, 10))

        def do_generate():
            mode = mode_var.get()
            ok, reason = self.export_mode_available(mode)
            if not ok:
                tkinter.messagebox.showwarning("Cannot export", reason)
                return
            # the exporters read organic off these vars, so make the choice
            # in this dialog the one that actually takes effect
            self.pending_export_name = name_var.get()
            previous = self.organic_enabled.get()
            self.organic_enabled.set(bake_var.get())
            try:
                dlg.destroy()
                if mode == 'basic':
                    self.export_arduino_code()
                elif mode == 'pir':
                    self.export_pir_state_machine()
                elif mode == 'markov':
                    self.export_markov_arduino()
                elif mode == 'scratch':
                    self.export_scratch_arduino()
            finally:
                self.organic_enabled.set(previous)

        ctk.CTkButton(btn_row, text="Generate .ino", command=do_generate,
                      font=('Arial', 11, 'bold'), width=140).pack(side=tk.RIGHT, padx=4)
        ctk.CTkButton(btn_row, text="Cancel", command=dlg.destroy,
                      font=('Arial', 11), width=90,
                      fg_color='#c0c0c0', text_color='black',
                      hover_color='#e0e0e0').pack(side=tk.RIGHT, padx=4)

        dlg.update_idletasks()
        x = self.root.winfo_rootx() + max(0, (self.root.winfo_width() - dlg.winfo_width()) // 2)
        y = self.root.winfo_rooty() + 60
        dlg.geometry(f"+{x}+{y}")
        return dlg

    def init_organic_state(self):
        """Reset the organic oscillators so a pass starts from a clean phase."""
        self.wobble_offsets = [0.0] * self.num_servos
        self.wobble_targets = [0.0] * self.num_servos
        self.last_wobble_update = time.time()
        self._organic_phases = [random.uniform(0, 2 * math.pi) for _ in range(self.num_servos)]
        self._organic_start_time = time.time()
        self.jitter_speed_multiplier = 1.0
        self.jitter_speed_target = 1.0
        self.last_jitter_update = time.time()
        self.is_paused_at_keyframe = False
        self.pause_until = 0

    def on_organic_toggled(self):
        """Organic switched while the transport may already be running."""
        on = bool(self.organic_enabled.get())
        if self.is_playing:
            # take effect immediately -- the whole point is to hear the change
            self.markov_mode = on
            if on:
                self.init_organic_state()
        self.organic_btn.configure(
            text=("▼ Organic Variations  [ON]" if on else "▼ Organic Variations")
            if self.variation_expanded else
            ("▶ Organic Variations  [ON]" if on else "▶ Organic Variations"))
        print(f"🎲 Organic {'enabled' if on else 'disabled'} "
              f"(wobble ±{self.position_wobble.get()}°, jitter ±{self.timing_jitter.get()}%, "
              f"pause {self.pause_chance.get()}%)")

    def toggle_markov_playback(self):
        """Toggle organic/Markov playback mode with random variations."""
        if not self.recorded_layers:
            print("❌ No layers to play back")
            return
        
        if self.is_playing and self.markov_mode:
            # Stop playback
            self.is_playing = False
            self.markov_mode = False
            self.playback_layer = None
            self.markov_btn.configure(text="🎲 Organic", fg_color=self.default_button_color)
            self.playback_btn.configure(text="▶️ Play", fg_color=self.default_button_color)
            print("⏹️ Organic playback stopped")
        else:
            # Start organic playback
            self.is_playing = True
            self.markov_mode = True
            self.playback_start_time = time.time()
            self.playback_index = 0
            self.is_paused_at_keyframe = False
            self.pause_until = 0
            # Initialize wobble offsets
            self.wobble_offsets = [0.0] * self.num_servos
            self.wobble_targets = [0.0] * self.num_servos
            self.last_wobble_update = time.time()
            # Reset organic sine wave phases for fresh start
            self._organic_phases = [random.uniform(0, 2 * math.pi) for _ in range(self.num_servos)]
            self._organic_start_time = time.time()
            # Initialize timing jitter
            self.jitter_speed_multiplier = 1.0
            self.jitter_speed_target = 1.0
            self.last_jitter_update = time.time()
            
            self.markov_btn.configure(text="⏹️ Stop", fg_color=self.colors['text_main'])
            self.playback_btn.configure(text="▶️ Play", fg_color=self.default_button_color)
            print(f"🎲 Organic playback: wobble=±{self.position_wobble.get()}°, jitter=±{self.timing_jitter.get()}%, pause={self.pause_chance.get()}%")
        
        self.update_timeline()
    
    def toggle_variation_panel(self, event=None):
        """Toggle the organic variations control panel."""
        self.variation_expanded = not self.variation_expanded
        if self.variation_expanded:
            self.variation_content.pack(fill=tk.X, pady=(0, 5))
            self.variation_btn.configure(text="▼ Organic Variations")
        else:
            self.variation_content.pack_forget()
            self.variation_btn.configure(text="▶ Organic Variations")
    
    def toggle_hw_config_panel(self, event=None):
        """Toggle the hardware configuration panel."""
        self.hw_config_expanded = not self.hw_config_expanded
        if self.hw_config_expanded:
            self.hw_config_content.pack(fill=tk.X, pady=(0, 5))
            self.hw_config_btn.configure(text="▼ Hardware Config")
        else:
            self.hw_config_content.pack_forget()
            self.hw_config_btn.configure(text="▶ Hardware Config")

    def generate_listener_sketch(self):
        """Build the listener sketch from the CURRENT hardware config.

        Hand-editing a listener every time the rig is rewired is how the pin
        map and the config drift apart, so this is generated from the same
        dict the host sends against: same channel order, same pins, same baud,
        same reversal set."""
        cfg = self.hardware_config
        pins = list(cfg['pin_mapping'])
        n = self.num_servos
        baud = int(cfg.get('baud_rate', 115200))
        pir = int(cfg.get('pir_pin', 2))
        reversed_ch = sorted(i for i in cfg.get('reversed_servos', []) if i < n)
        # The BACKSTOP, not the expressive range. Baking the expressive range in
        # meant every narrowing of it needed a reflash, and every widening of it
        # was silently cut off by the sketch still holding the old value.
        lo = int(cfg.get('firmware_safe_min', 0))
        hi = int(cfg.get('firmware_safe_max', 180))
        cmd = f"HAND{n}"

        # Startup pose, baked from wherever the sliders sit right now. The old
        # sketch attached every channel at the midpoint of the global range,
        # which is a pose nothing was ever posed in -- on a 0-80 range that is
        # 40 degrees on all ten, and the rig lurches there on power-up before
        # the host has said anything. Run it through get_hardware_position so
        # the baked value is byte-for-byte what a live frame would carry for
        # that slider, reversal included.
        live = list(self.finger_positions) + list(self.arm_positions)
        startup = []
        for i in range(n):
            angle = live[i] if i < len(live) else 90.0
            startup.append(int(round(self.get_hardware_position(i, angle))))
        startup_str = ", ".join(str(v) for v in startup)

        # Record what we baked. The UI opens holding this pose and reconnect
        # resends it, so the board and the host agree on where "rest" is
        # instead of the host overwriting the sketch's pose on first frame.
        cfg['startup_pose'] = list(startup)

        mapping = "\n".join(
            f" * S{i} -> D{pins[i]}   startup {startup[i]}" for i in range(n))
        frame_bytes = len(cmd) + 1 + n * 4
        ms_at_baud = frame_bytes * 10 / baud * 1000

        return f'''/*
 * {n}-Servo Listener -- GENERATED from hardware config "{cfg.get('name', 'Default')}"
 * Generated: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}
 *
 * Receives: "{cmd},pos0,...,pos{n - 1}"
 * Sends:    "PIR,1" on motion
 *
 * Channels are numbered, not named after anatomy -- this rig gets rewired
 * per project. The channel index is what the protocol and the UI agree on;
 * the pin is just where that channel is wired right now.
 *
{mapping}
 *
 * Startup pose is baked from the host UI sliders as they stood at generation
 * time -- NOT the midpoint of the range. Re-pose the hand and regenerate to
 * change where it wakes up.
 *
 * Positions are DEGREES, end to end: what the slider reads is what the servo
 * is told. MIN_ANGLE/MAX_ANGLE below are a hardware backstop that clamps a bad
 * frame, not the expressive range -- set the expressive range in the UI, where
 * it is applied once. Nothing here rescales.
 *
 * PIR sensor on D{pir}.
 * Baud {baud}: a {cmd} frame is ~{frame_bytes} bytes = ~{ms_at_baud:.1f}ms of wire time.
 *
 * Regenerate this from Hardware Config whenever pins, baud or reversal
 * change, and reflash -- the host will not warn you if they drift apart.
 */

#include <Servo.h>

const int NUM_SERVOS = {n};
const int pins[NUM_SERVOS] = {{{', '.join(str(p) for p in pins)}}};

const int PIR_PIN = {pir};
bool lastPirState = false;
unsigned long lastPirSendTime = 0;
const unsigned long PIR_DEBOUNCE_MS = 200;

const int MIN_ANGLE = {lo};
const int MAX_ANGLE = {hi};

// Where each channel wakes up, in degrees. Captured from the host sliders when
// this file was generated -- see the header.
const int startupPositions[NUM_SERVOS] = {{{startup_str}}};

// Reversal ({', '.join(f'S{i}' for i in reversed_ch) if reversed_ch else 'none set'}) is applied by the HOST, in
// get_hardware_position, before the frame goes out -- it is listed here for
// reference only. Re-applying it in firmware would invert an already-inverted
// value and cancel it out, which is what this sketch used to do.

Servo servos[NUM_SERVOS];
String inputBuffer = "";

// One path for every write, so the startup pose and a live frame land in the
// same place. Two copies of this arithmetic is how a rig ends up waking
// somewhere it never gets sent.
//
// Degrees in, degrees out. This used to map 0-180 onto MIN..MAX, but the host
// had ALREADY scaled the frame into that range, so the second scaling shrank
// every move to roughly 44% of what was asked for. The range is a clamp -- a
// hardware backstop against a bad frame -- not the expressive range. The
// expressive range is the UI's, and it is applied there, once.
void writeChannel(int channel, int deg) {{
  servos[channel].write(constrain(deg, MIN_ANGLE, MAX_ANGLE));
}}

void setup() {{
  Serial.begin({baud});
  pinMode(PIR_PIN, INPUT);

  for (int i = 0; i < NUM_SERVOS; i++) {{
    servos[i].attach(pins[i]);
    writeChannel(i, startupPositions[i]);
  }}

  delay(1000);
  Serial.println("{n}-Servo Listener Ready - awaiting {cmd} commands");
  Serial.print("PIR on D"); Serial.println(PIR_PIN);
  Serial.print("Range "); Serial.print(MIN_ANGLE);
  Serial.print("-"); Serial.println(MAX_ANGLE);
  Serial.println("Reversed (host-side): {', '.join(f'S{i}' for i in reversed_ch) if reversed_ch else 'none'}");
  for (int i = 0; i < NUM_SERVOS; i++) {{
    Serial.print("S"); Serial.print(i);
    Serial.print(" -> D"); Serial.print(pins[i]);
    Serial.print(" start "); Serial.println(startupPositions[i]);
  }}
}}

void loop() {{
  bool pirState = digitalRead(PIR_PIN) == HIGH;
  unsigned long now = millis();

  if (pirState && !lastPirState && (now - lastPirSendTime > PIR_DEBOUNCE_MS)) {{
    Serial.println("PIR,1");
    lastPirSendTime = now;
  }}
  lastPirState = pirState;

  while (Serial.available()) {{
    char c = Serial.read();
    if (c == '\\n') {{
      processCommand(inputBuffer);
      inputBuffer = "";
    }} else if (c != '\\r') {{
      inputBuffer += c;
    }}
  }}
}}

void processCommand(String command) {{
  if (!command.startsWith("{cmd},")) return;

  String data = command.substring({len(cmd) + 1});

  int positions[NUM_SERVOS];
  int parsed = 0;
  int lastComma = -1;

  for (int i = 0; i < NUM_SERVOS; i++) {{
    int nextComma = data.indexOf(',', lastComma + 1);

    if (nextComma == -1) {{
      // Last field. A short or truncated frame must leave the remaining
      // channels untouched, not slam them to whatever the tail happened
      // to be -- so stop here rather than reusing it.
      String tail = data.substring(lastComma + 1);
      if (tail.length() == 0) break;
      positions[i] = tail.toInt();
      parsed = i + 1;
      break;
    }}

    positions[i] = data.substring(lastComma + 1, nextComma).toInt();
    parsed = i + 1;
    lastComma = nextComma;
  }}

  for (int i = 0; i < parsed; i++) {{
    writeChannel(i, positions[i]);
  }}
}}
'''

    def export_listener_sketch(self):
        """Write the generated listener sketch next to the project."""
        from tkinter import filedialog
        # take whatever is currently typed in the config fields first, so the
        # sketch matches what the user is looking at rather than the last save
        try:
            self.update_config_from_ui()
        except Exception:
            pass

        default = f"listener_{self.num_servos}servo_{datetime.datetime.now().strftime('%Y%m%d_%H%M%S')}.ino"
        path = filedialog.asksaveasfilename(
            defaultextension=".ino",
            initialfile=default,
            filetypes=[("Arduino sketch", "*.ino"), ("All files", "*.*")],
            title="Save generated listener sketch",
        )
        if not path:
            return
        try:
            with open(path, 'w', encoding='utf-8') as f:
                f.write(self.generate_listener_sketch())
            # generate_listener_sketch just recorded the pose it baked; persist
            # it so the next UI launch opens holding what the board booted into
            self.save_hardware_config()
            cfg = self.hardware_config
            tkinter.messagebox.showinfo(
                "Listener Generated",
                f"Saved: {os.path.basename(path)}\n\n"
                f"Channels: {self.num_servos} (S0-S{self.num_servos - 1})\n"
                f"Pins: {', '.join(str(p) for p in cfg['pin_mapping'])}\n"
                f"Baud: {cfg.get('baud_rate', 115200)}\n"
                f"PIR: D{cfg.get('pir_pin', 2)}\n"
                f"Startup pose: baked from the current sliders\n"
                f"Safe limit: {cfg.get('firmware_safe_min', 0)}-{cfg.get('firmware_safe_max', 180)}° "
                f"(expressive range {cfg['global_min_angle']}-{cfg['global_max_angle']}° "
                f"stays in the UI)\n\n"
                "Flash this before connecting -- the host talks "
                f"HAND{self.num_servos} at this baud.")
            print(f"⚙ Listener sketch written to {path}")
        except Exception as e:
            tkinter.messagebox.showerror("Generate Failed", f"Could not write sketch:\n{e}")

    def toggle_wave_config_panel(self, event=None):
        """Toggle the wave tuning sliders."""
        self.wave_cfg_expanded = not self.wave_cfg_expanded
        if self.wave_cfg_expanded:
            self.wave_cfg_content.pack(fill=tk.X)
            self.wave_cfg_btn.configure(text="▼ Wave Config")
        else:
            self.wave_cfg_content.pack_forget()
            self.wave_cfg_btn.configure(text="▶ Wave Config")

    def toggle_pir_panel(self, event=None):
        """Toggle the PIR state machine panel."""
        self.pir_expanded = not self.pir_expanded
        if self.pir_expanded:
            self.pir_content.pack(fill=tk.X, pady=(0, 5))
            self.pir_panel_btn.configure(text="▼ PIR State Machine")
        else:
            self.pir_content.pack_forget()
            self.pir_panel_btn.configure(text="▶ PIR State Machine")
    
    def apply_and_save_config(self):
        """Apply hardware config from UI and save to file."""
        self.update_config_from_ui()
        self.save_hardware_config()
        
        # Reinitialize hand controller with new settings
        if HAND_CONTROLLER_AVAILABLE and self.hand_controller:
            try:
                old_port = self.hand_controller.serial_connection.port if self.hand_controller.serial_connection else self.default_port
                self.hand_controller.serial_connection.close()
                self.hand_controller = HandExpressionController(
                    port=old_port,
                    baudrate=self.hardware_config.get('baud_rate', 115200),
                    clean_output=True,
                    min_angle=self.hardware_config['global_min_angle'],
                    max_angle=self.hardware_config['global_max_angle']
                )
                self.sync_pose_from_board()
                print(f"✅ Controller reinitialized with range {self.hardware_config['global_min_angle']}-{self.hardware_config['global_max_angle']}°")
            except Exception as e:
                print(f"⚠️ Could not reinitialize controller: {e}")
        
        tkinter.messagebox.showinfo("Config Saved", 
            f"Hardware config '{self.hardware_config['name']}' saved and applied.\n\n"
            f"Settings now active:\n"
            f"• Angle range: {self.hardware_config['global_min_angle']}° - {self.hardware_config['global_max_angle']}°\n"
            f"• Reversed servos: {self.hardware_config['reversed_servos']}\n"
            f"• Serial port: {self.hardware_config['serial_port']}")

    # ==================== PIR STATE MACHINE METHODS ====================
    
    def clear_recording_library(self):
        """Wipe the recording library and every reference to it, for a fresh start.

        clear_layers() handles what is loaded in memory; this handles what is on
        disk plus the three state assignment lists, the library cache and the
        listboxes. Clearing only the folder would leave the state cards pointing
        at names that no longer resolve, which fails later at export rather than
        here where it can be explained.

        Archiving is the default rather than deleting: takes are the one thing in
        this project that cannot be regenerated -- a config or a sketch can be
        rebuilt from the UI in seconds, a performance cannot be re-performed.
        """
        from tkinter import filedialog  # noqa: F401  (kept local, as elsewhere here)

        files = []
        if os.path.isdir(self.pir_recordings_dir):
            files = sorted(f for f in os.listdir(self.pir_recordings_dir)
                           if f.lower().endswith('.json'))

        assigned = (len(self.pir_idle_recordings) + len(self.pir_active_recordings)
                    + len(self.pir_sleep_recordings))
        if not files and not assigned:
            tkinter.messagebox.showinfo("Nothing to Clear", "The recording library is already empty.")
            return

        total_mb = sum(
            os.path.getsize(os.path.join(self.pir_recordings_dir, f))
            for f in files) / (1024 * 1024) if files else 0.0

        keep = tkinter.messagebox.askyesnocancel(
            "Clear Recording Library",
            f"{len(files)} recording(s), {total_mb:.1f} MB\n"
            f"{assigned} state assignment(s) across IDLE / ACTIVE / SLEEP\n\n"
            "YES  - move the files to a timestamped archive folder (recommended)\n"
            "NO   - delete the files permanently\n"
            "CANCEL - do nothing\n\n"
            "Either way the state assignments and the library cache are cleared.")
        if keep is None:
            return

        archived_to = None
        try:
            if keep and files:
                stamp = datetime.datetime.now().strftime('%Y%m%d_%H%M%S')
                archived_to = os.path.join(
                    os.path.dirname(self.pir_recordings_dir), f'pir_recordings_archive_{stamp}')
                os.makedirs(archived_to, exist_ok=True)
                for name in files:
                    shutil.move(os.path.join(self.pir_recordings_dir, name),
                                os.path.join(archived_to, name))
            elif files:
                for name in files:
                    os.remove(os.path.join(self.pir_recordings_dir, name))
        except Exception as e:
            tkinter.messagebox.showerror(
                "Clear Failed",
                f"Stopped partway through:\n{e}\n\n"
                "The state assignments have NOT been cleared, so what is left on "
                "disk still matches what the UI is showing.")
            return

        # Only now drop the references -- if the file move had failed above, the
        # assignments still describe what is actually there.
        self.pir_idle_recordings.clear()
        self.pir_active_recordings.clear()
        self.pir_sleep_recordings.clear()
        self.pir_cached_recordings.clear()
        self.pir_recording_index = {'idle': 0, 'active': 0, 'sleep': 0}
        self.pir_recording_progress = 0.0
        self.pir_crossfade_to_next = False

        for state in ('idle', 'active', 'sleep'):
            listbox = self.get_pir_state_listbox(state)
            if listbox is not None:
                listbox.delete(0, tk.END)
        if hasattr(self, 'update_pir_recording_combos'):
            self.update_pir_recording_combos()

        where = f"Archived to:\n{os.path.basename(archived_to)}" if archived_to else "Files deleted permanently."
        tkinter.messagebox.showinfo(
            "Library Cleared",
            f"{len(files)} recording(s) cleared.\n{where}\n\n"
            "In-memory layers are untouched -- use Clear All for those.")
        print(f"[LIBRARY] Cleared {len(files)} recording(s); "
              f"{'archived to ' + archived_to if archived_to else 'deleted permanently'}")

    def scan_pir_recordings_library(self):
        """Scan pir_recordings and movement_recordings folders for available recordings."""
        recordings = []
        
        # Create pir_recordings folder if it doesn't exist
        if not os.path.exists(self.pir_recordings_dir):
            os.makedirs(self.pir_recordings_dir)
        
        # Scan pir_recordings folder (saved recordings)
        for filename in os.listdir(self.pir_recordings_dir):
            if filename.endswith('.json'):
                name = filename[:-5]  # Remove .json extension
                recordings.append(name)
        
        return sorted(recordings)
    
    def save_to_pir_library(self):
        """Save current layers as a named recording to the PIR library."""
        if not self.recorded_layers:
            tkinter.messagebox.showwarning("Nothing to Save", "No recorded layers to save!")
            return
        
        # Ask for a name
        name = tkinter.simpledialog.askstring(
            "Save to PIR Library",
            "Enter a name for this recording:\n(e.g., 'idle_breathing', 'active_wave')",
            initialvalue="")
        
        if not name:
            return
        
        # Clean the name (remove invalid characters)
        name = "".join(c for c in name if c.isalnum() or c in ('_', '-', ' ')).strip()
        name = name.replace(' ', '_')
        
        if not name:
            tkinter.messagebox.showerror("Invalid Name", "Please enter a valid name.")
            return
        
        # Create folder if needed
        if not os.path.exists(self.pir_recordings_dir):
            os.makedirs(self.pir_recordings_dir)
        
        filepath = os.path.join(self.pir_recordings_dir, f"{name}.json")
        
        # Check if file exists
        if os.path.exists(filepath):
            if not tkinter.messagebox.askyesno("Overwrite?", 
                    f"'{name}' already exists. Overwrite?"):
                return
        
        try:
            # Prepare data for saving
            layers_to_save = []
            for layer in self.recorded_layers:
                layer_copy = {
                    'name': layer['name'],
                    'duration': layer['duration'],
                    'control_mode': layer['control_mode'],
                    'data': layer['data'],
                    'timestamp': layer.get('timestamp', '')
                }
                if 'recorded_servos' in layer:
                    layer_copy['recorded_servos'] = {
                        'fingers': list(layer['recorded_servos'].get('fingers', set())),
                        'arm': list(layer['recorded_servos'].get('arm', set()))
                    }
                layers_to_save.append(layer_copy)
            
            save_data = {
                'version': '1.0',
                'timestamp': datetime.datetime.now().strftime("%Y%m%d_%H%M%S"),
                'loop_duration': self.loop_duration.get(),
                'layers': layers_to_save
            }
            
            with open(filepath, 'w') as f:
                json.dump(save_data, f, indent=2)
            
            print(f"📚 Saved to PIR library: {name}")
            
            # Refresh the dropdowns
            self.update_pir_recording_combos()
            
            tkinter.messagebox.showinfo("Saved to Library", 
                f"Recording saved as '{name}'\nAvailable in PIR state dropdowns.")
                
        except Exception as e:
            print(f"❌ Save to library failed: {e}")
            tkinter.messagebox.showerror("Save Failed", f"Failed to save:\n{e}")
    
    def load_pir_recording(self, name):
        """Load a recording from the PIR library into cache. Returns layers list or None."""
        if not name:
            return None
        
        # Special case: use currently loaded recording
        if name == '[Current Recording]':
            return self.recorded_layers if self.recorded_layers else None
        
        # Check cache first
        if name in self.pir_cached_recordings:
            return self.pir_cached_recordings[name]
        
        # Load from pir_recordings/ folder
        filepath = os.path.join(self.pir_recordings_dir, f"{name}.json")
        
        if not os.path.exists(filepath):
            print(f"⚠️ PIR recording not found: {name}")
            return None
        
        try:
            with open(filepath, 'r') as f:
                save_data = json.load(f)
            
            layers = save_data.get('layers', [])
            
            # Convert recorded_servos lists back to sets
            for layer in layers:
                if 'recorded_servos' in layer:
                    layer['recorded_servos'] = {
                        'fingers': set(layer['recorded_servos'].get('fingers', [])),
                        'arm': set(layer['recorded_servos'].get('arm', []))
                    }
                else:
                    layer['recorded_servos'] = {'fingers': set(), 'arm': set()}
            
            # Cache it
            self.pir_cached_recordings[name] = layers
            print(f"📂 Loaded PIR recording: {name} ({len(layers)} layers)")
            return layers
            
        except Exception as e:
            print(f"❌ Failed to load PIR recording {name}: {e}")
            return None
    
    def get_pir_state_recordings_list(self, state):
        """Get the recordings list for a given PIR state."""
        lists = {
            'idle': self.pir_idle_recordings,
            'active': self.pir_active_recordings,
            'sleep': self.pir_sleep_recordings
        }
        return lists.get(state, [])
    
    def get_pir_state_listbox(self, state):
        """Get the listbox widget for a given PIR state."""
        listboxes = {
            'idle': self.pir_idle_listbox,
            'active': self.pir_active_listbox,
            'sleep': self.pir_sleep_listbox
        }
        return listboxes.get(state)
    
    def add_pir_recording(self, state, listbox):
        """Show popup menu to add a recording to a PIR state."""
        # Build options list
        recordings = []
        
        # Add current recording option if layers are loaded
        if self.recorded_layers:
            recordings.append('[Current Recording]')
        
        # Add saved library recordings
        recordings.extend(self.scan_pir_recordings_library())
        
        if not recordings:
            tkinter.messagebox.showinfo("No Recordings", 
                "No recordings available. Record a movement or save to the PIR library first.")
            return
        
        # Create popup menu
        menu = tk.Menu(self.root, tearoff=0)
        for rec in recordings:
            menu.add_command(label=rec, 
                command=lambda r=rec, s=state, lb=listbox: self._do_add_pir_recording(s, lb, r))
        
        # Show menu at button position
        try:
            menu.tk_popup(self.root.winfo_pointerx(), self.root.winfo_pointery())
        finally:
            menu.grab_release()
    
    def _do_add_pir_recording(self, state, listbox, recording_name):
        """Actually add the recording to the state's list."""
        # Get the right list
        if state == 'idle':
            rec_list = self.pir_idle_recordings
        elif state == 'active':
            rec_list = self.pir_active_recordings
        else:
            rec_list = self.pir_sleep_recordings
        
        # Avoid duplicates
        if recording_name not in rec_list:
            rec_list.append(recording_name)
            listbox.insert(tk.END, recording_name)
            print(f"➕ Added '{recording_name}' to {state.upper()} state")
            
            # Rebuild Markov segments if Markov mode is enabled
            if self.pir_markov_enabled.get():
                self._rebuild_markov_segments()
    
    def remove_pir_recording(self, state, listbox):
        """Remove selected recording from a PIR state."""
        selection = listbox.curselection()
        if not selection:
            return
        
        idx = selection[0]
        recording_name = listbox.get(idx)
        
        # Get the right list
        if state == 'idle':
            rec_list = self.pir_idle_recordings
        elif state == 'active':
            rec_list = self.pir_active_recordings
        else:
            rec_list = self.pir_sleep_recordings
        
        if recording_name in rec_list:
            rec_list.remove(recording_name)
            listbox.delete(idx)
            print(f"➖ Removed '{recording_name}' from {state.upper()} state")
            
            # Rebuild Markov segments if Markov mode is enabled
            if self.pir_markov_enabled.get():
                self._rebuild_markov_segments()
    
    def update_pir_recording_combos(self):
        """Legacy compatibility - now a no-op since we use listboxes."""
        pass  # Listboxes are updated directly via add/remove
    
    def on_pir_toggle(self):
        """Toggle PIR testing mode."""
        if self.pir_enabled.get():
            # Enable PIR mode
            self.pir_state = 'idle'
            self.pir_state_start_time = time.time()
            self.pir_last_motion_time = time.time()  # Start fresh
            self.pir_simulate_btn.configure(state='normal')
            self.update_pir_state_display()

            # Randomize starting recording per state so we don't bias index 0.
            for state_name in ['idle', 'active', 'sleep']:
                self._randomize_pir_state_recording(state_name)
            self.pir_crossfade_target_idx = self.pir_recording_index.get(self.pir_state, 0)
            
            # Initialize crossfade system
            self._schedule_next_crossfade()
            
            # Initialize Markov if enabled
            if self.pir_markov_enabled.get():
                self._rebuild_markov_segments()
            
            # Start PIR playback if we have recordings assigned
            if not self.is_playing:
                self.is_playing = True
                self.playback_start_time = time.time()
            
            print(f"🔴 PIR Mode enabled - starting in IDLE state")
        else:
            # Disable PIR mode
            self.pir_state = 'idle'
            self.pir_simulate_btn.configure(state='disabled')
            self.pir_state_label.config(text="OFF", bg='#888888')
            self.pir_rec_label.config(text="")
            self.pir_timer_label.config(text="")
            print("⚪ PIR Mode disabled")

    def _randomize_pir_state_recording(self, state):
        """Pick a random current recording index for the given PIR state."""
        import random
        rec_lists = {
            'idle': self.pir_idle_recordings,
            'active': self.pir_active_recordings,
            'sleep': self.pir_sleep_recordings
        }
        rec_list = rec_lists.get(state, [])
        if not rec_list:
            self.pir_recording_index[state] = 0
            return
        self.pir_recording_index[state] = random.randrange(len(rec_list))
    
    def check_pir_from_arduino(self):
        """Check for PIR motion events from Arduino over serial."""
        if not self.hand_controller or not self.pir_enabled.get():
            return
        
        try:
            # Check if there's data waiting (serial_connection is the attribute name in HandExpressionController)
            ser = self.hand_controller.serial_connection
            if ser and ser.in_waiting > 0:
                line = ser.readline().decode('utf-8', errors='ignore').strip()
                
                # Debug: show any incoming serial data
                if line and not line.startswith("8-Servo") and not line.startswith("10-Servo"):  # Skip startup messages
                    print(f"📥 Arduino: {line}")
                
                # Check for PIR event
                if line == "PIR,1":
                    print("📡 PIR motion detected from Arduino!")
                    self.trigger_pir_motion()
        except Exception as e:
            # Silently ignore serial read errors
            pass
    
    def trigger_pir_motion(self):
        """Trigger a PIR motion event (called from Arduino or simulate button)."""
        if not self.pir_enabled.get():
            return
        
        self.pir_last_motion_time = time.time()
        
        # Transition to active if not already
        if self.pir_state != 'active':
            self.pir_previous_state = self.pir_state
            self.pir_state = 'active'
            self.pir_state_start_time = time.time()
            self.pir_transition_start = time.time()
            self.pir_blend_factor = 0.0
            # Capture current positions for blending
            self.pir_transition_positions = {
                'fingers': self.finger_positions[:],
                'arm': self.arm_positions[:]
            }
            print(f"👋 Motion! {self.pir_previous_state} → ACTIVE")
            
            # Flash the simulate button briefly to show activity
            self.pir_simulate_btn.configure(fg_color='#808080')
            self.root.after(200, lambda: self.pir_simulate_btn.configure(fg_color='#c0c0c0'))
        
        self.update_pir_state_display()
    
    def simulate_pir_motion(self):
        """Simulate a PIR motion detection event for testing (button click)."""
        if not self.pir_enabled.get():
            return
        
        print("🖱️ Simulated motion (button click)")
        self.trigger_pir_motion()
    
    def update_pir_state_machine(self):
        """Update PIR state machine - called from control_loop."""
        if not self.pir_enabled.get():
            return
        
        current_time = time.time()
        time_since_motion = current_time - self.pir_last_motion_time
        time_in_state = current_time - self.pir_state_start_time
        
        old_state = self.pir_state
        
        # State transition logic
        if self.pir_state == 'active':
            # Check if we should return to idle
            if time_since_motion >= self.pir_active_duration.get():
                self.pir_previous_state = 'active'
                self.pir_state = 'idle'
                self.pir_state_start_time = current_time
                self.pir_transition_start = current_time
                self.pir_blend_factor = 0.0
                # Capture current positions for blending
                self.pir_transition_positions = {
                    'fingers': self.finger_positions[:],
                    'arm': self.arm_positions[:]
                }
                print(f"⏱️ Active timeout - transitioning to IDLE")
        
        elif self.pir_state == 'idle':
            # Check if we should go to sleep
            sleep_timeout_sec = self.pir_sleep_timeout.get() * 60  # Convert minutes to seconds
            if time_since_motion >= sleep_timeout_sec:
                self.pir_previous_state = 'idle'
                self.pir_state = 'sleep'
                self.pir_state_start_time = current_time
                self.pir_transition_start = current_time
                self.pir_blend_factor = 0.0
                # Capture current positions for blending
                self.pir_transition_positions = {
                    'fingers': self.finger_positions[:],
                    'arm': self.arm_positions[:]
                }
                print(f"😴 Sleep timeout ({self.pir_sleep_timeout.get()} min) - transitioning to SLEEP")
        
        elif self.pir_state == 'sleep':
            # Wake up on motion (handled in simulate_pir_motion)
            pass
        
        # Update blend factor for smooth transitions
        transition_time = self.pir_transition_time.get()
        if current_time - self.pir_transition_start < transition_time:
            self.pir_blend_factor = (current_time - self.pir_transition_start) / transition_time
        else:
            self.pir_blend_factor = 1.0
        
        # Update display if state changed
        if old_state != self.pir_state:
            # Randomize starting recording for the new state immediately.
            self._randomize_pir_state_recording(self.pir_state)
            self.pir_crossfade_target_idx = self.pir_recording_index.get(self.pir_state, 0)
            self.update_pir_state_display()
            # Reset crossfade timing for new state
            self._schedule_next_crossfade()
        
        # Handle recording crossfade within state (if enabled and multiple recordings)
        if self.pir_crossfade_enabled.get():
            self._update_recording_crossfade(current_time)
        
        # Update timer display
        self.update_pir_timer_display(time_since_motion, time_in_state)
    
    def update_pir_state_display(self):
        """Update the PIR state indicator in the UI."""
        state_colors = {
            'idle': ('#6666FF', 'IDLE'),
            'active': ('#00CC00', 'ACTIVE'),
            'sleep': ('#9966CC', 'SLEEP')
        }
        color, text = state_colors.get(self.pir_state, ('#888888', 'OFF'))
        self.pir_state_label.config(text=text, bg=color)
        
        # Check if Markov mode is active
        if self.pir_markov_enabled.get() and self.pir_markov_initialized:
            segments = self.pir_markov_segments.get(self.pir_state, [])
            if segments:
                seg_idx = self.pir_current_segment_idx
                total = len(segments)
                # Get source recording name for current segment
                if seg_idx < len(segments):
                    seg = segments[seg_idx]
                    rec_name = seg.get('recording_name', f"rec{seg['recording']}")
                    seg_num = seg.get('segment_idx', 0) + 1  # 1-based for display
                    self.pir_rec_label.config(text=f"[Seg {seg_idx+1}/{total} from '{rec_name}' #{seg_num}]")
                else:
                    self.pir_rec_label.config(text=f"[Markov seg {seg_idx+1}/{total}]")
            else:
                self.pir_rec_label.config(text="[Markov: no segments]")
            return
        
        # Update recording indicator with actual recording name
        rec_idx = self.pir_recording_index.get(self.pir_state, 0)
        rec_lists = {
            'idle': self.pir_idle_recordings,
            'active': self.pir_active_recordings,
            'sleep': self.pir_sleep_recordings
        }
        rec_list = rec_lists.get(self.pir_state, [])
        if rec_list and len(rec_list) > 0 and rec_idx < len(rec_list):
            # Show the actual recording name
            rec_name = rec_list[rec_idx]
            # Remove .json extension if present for cleaner display
            if rec_name.endswith('.json'):
                rec_name = rec_name[:-5]
            
            # Show crossfade indicator if actively crossfading
            if self.pir_is_crossfading and hasattr(self, 'pir_crossfade_target_idx'):
                target_idx = self.pir_crossfade_target_idx
                if target_idx < len(rec_list):
                    target_name = rec_list[target_idx]
                    if target_name.endswith('.json'):
                        target_name = target_name[:-5]
                    self.pir_rec_label.config(text=f"({rec_name} → {target_name})")
                else:
                    self.pir_rec_label.config(text=f"({rec_name})")
            else:
                self.pir_rec_label.config(text=f"({rec_name})")
        else:
            self.pir_rec_label.config(text="")
    
    def update_pir_timer_display(self, time_since_motion, time_in_state):
        """Update the timer display in PIR panel."""
        if self.pir_state == 'active':
            remaining = max(0, self.pir_active_duration.get() - time_since_motion)
            self.pir_timer_label.config(text=f"Active: {remaining:.0f}s remaining")
        elif self.pir_state == 'idle':
            remaining_min = max(0, self.pir_sleep_timeout.get() - (time_since_motion / 60))
            self.pir_timer_label.config(text=f"Sleep in: {remaining_min:.1f} min")
        elif self.pir_state == 'sleep':
            self.pir_timer_label.config(text="💤 Sleeping...")
    
    def _schedule_next_crossfade(self):
        """Schedule the next crossfade at a random interval."""
        import random
        interval_min = self.pir_crossfade_interval_min.get()
        interval_max = self.pir_crossfade_interval_max.get()
        interval = random.uniform(interval_min, interval_max)
        self.pir_next_crossfade_time = time.time() + interval
        self.pir_is_crossfading = False
        self.pir_rec_blend_factor = 0.0
    
    def _update_recording_crossfade(self, current_time):
        """Update the recording crossfade system (mirrors Arduino behavior).
        
        This keeps two recording indices (A=current, B=target) and crossfades between them.
        When crossfade completes, A becomes B and a new B is picked.
        """
        import random
        
        # Get recording list for current state
        rec_lists = {
            'idle': self.pir_idle_recordings,
            'active': self.pir_active_recordings,
            'sleep': self.pir_sleep_recordings
        }
        rec_list = rec_lists.get(self.pir_state, [])
        
        # Need at least 2 recordings to crossfade
        if len(rec_list) < 2:
            return
        
        # Check if we should start a new crossfade
        if not self.pir_is_crossfading and current_time >= self.pir_next_crossfade_time:
            # Start crossfade
            self.pir_is_crossfading = True
            self.pir_crossfade_start_time = current_time
            
            # Random duration within configured range
            dur_min = self.pir_crossfade_duration_min.get()
            dur_max = self.pir_crossfade_duration_max.get()
            self.pir_crossfade_duration = random.uniform(dur_min, dur_max)
            
            # Pick a new target recording different from current
            current_idx = self.pir_recording_index.get(self.pir_state, 0)
            available = [i for i in range(len(rec_list)) if i != current_idx]
            if available:
                self.pir_crossfade_target_idx = random.choice(available)
            else:
                self.pir_crossfade_target_idx = current_idx
            
            # Store current positions for blending
            self.pir_prev_rec_positions = {
                'fingers': self.finger_positions[:],
                'arm': self.arm_positions[:]
            }
            
            target_name = rec_list[self.pir_crossfade_target_idx]
            if target_name.endswith('.json'):
                target_name = target_name[:-5]
            print(f"🔀 Starting crossfade to: {target_name} (over {self.pir_crossfade_duration:.1f}s)")
            
            # Update display to show crossfade in progress
            self.update_pir_state_display()
        
        # Update crossfade progress
        if self.pir_is_crossfading:
            elapsed = current_time - self.pir_crossfade_start_time
            if elapsed >= self.pir_crossfade_duration:
                # Crossfade complete - switch to target recording
                self.pir_recording_index[self.pir_state] = self.pir_crossfade_target_idx
                self.pir_rec_blend_factor = 0.0
                self.pir_is_crossfading = False
                self.update_pir_state_display()
                
                # Schedule next crossfade
                self._schedule_next_crossfade()
                
                rec_name = rec_list[self.pir_crossfade_target_idx]
                if rec_name.endswith('.json'):
                    rec_name = rec_name[:-5]
                print(f"✅ Crossfade complete, now playing: {rec_name}")
            else:
                # Very smooth ease-in-out crossfade factor (smootherstep - barely noticeable)
                t = elapsed / self.pir_crossfade_duration
                # Smootherstep (Ken Perlin) - much gentler than smoothstep
                self.pir_rec_blend_factor = t * t * t * (t * (t * 6.0 - 15.0) + 10.0)
    
    def _on_markov_toggle(self):
        """Handle toggling Markov mode on/off."""
        print(f"[MARKOV] toggle: enabled={self.pir_markov_enabled.get()}")
        if self.pir_markov_enabled.get():
            # Disable crossfade when Markov is enabled
            self.pir_crossfade_enabled.set(False)
            # Build Markov segments for current state
            print(f"  IDLE recordings: {self.pir_idle_recordings}")
            print(f"  ACTIVE recordings: {self.pir_active_recordings}")
            print(f"  SLEEP recordings: {self.pir_sleep_recordings}")
            self._rebuild_markov_segments()
            print("[MARKOV] Segment mode enabled")
        else:
            print("[MARKOV] Disabled, crossfade available")
            # Clear info display
            if hasattr(self, 'pir_markov_info_label'):
                self.pir_markov_info_label.config(text="")

    def _on_markov_hw_preview_toggle(self):
        """Handle HW Preview toggle and make mode changes immediately visible."""
        use_hw = self.pir_markov_hardware_preview.get()
        mode_name = "HW preview" if use_hw else "full preview"
        print(f"[MARKOV] {mode_name} enabled")

        # If Markov is running, ensure data/state matches new preview mode immediately.
        if self.pir_markov_enabled.get():
            if not self.pir_markov_initialized:
                self._rebuild_markov_segments()
            elif use_hw:
                # Rebuild hardware preview tables if missing/stale.
                has_hw = any(self.pir_markov_hw_segments.get(s, []) for s in ['idle', 'active', 'sleep'])
                if not has_hw:
                    self._build_hardware_preview_data()

            # Restart segment playback to avoid carrying stale interpolation state.
            self.pir_current_segment_idx = 0
            self.pir_segment_start_time = time.time()
            self.pir_prev_segment_end_positions = None
            self.pir_needs_blend = False

        self._update_markov_info_display()
    
    def _rebuild_markov_segments(self):
        """Build segment pool and transition matrix from all PIR recordings."""
        import random
        
        self.pir_markov_segments = {'idle': [], 'active': [], 'sleep': []}
        self.pir_markov_transitions = {'idle': [], 'active': [], 'sleep': []}
        
        rec_map = {
            'idle': self.pir_idle_recordings,
            'active': self.pir_active_recordings,
            'sleep': self.pir_sleep_recordings
        }
        
        segment_length = self.pir_markov_segment_length.get()
        print(f"[MARKOV] Building segments (segment_length={segment_length}s)...")
        
        for state_name, rec_list in rec_map.items():
            all_segments = []
            print(f"  {state_name.upper()}: {len(rec_list)} recordings to process")
            
            for rec_idx, rec_name in enumerate(rec_list):
                layers = self.load_pir_recording(rec_name)
                if not layers:
                    print(f"    [WARN] Failed to load '{rec_name}'")
                    continue
                
                print(f"    Loaded '{rec_name}': {len(layers)} layers")
                
                # Get the merged timeline from all layers
                merged = self._merge_layers_to_samples(layers, sample_rate=50)  # 50Hz
                if not merged:
                    print(f"    [WARN] '{rec_name}' produced no samples")
                    continue
                
                print(f"    Merged to {len(merged)} samples ({len(merged)/50:.1f}s)")
                
                # Chop into segments
                samples_per_segment = int(segment_length * 50)
                num_segments = len(merged) // samples_per_segment
                
                for seg_idx in range(num_segments):
                    start_idx = seg_idx * samples_per_segment
                    end_idx = start_idx + samples_per_segment
                    segment_data = merged[start_idx:end_idx]
                    
                    if len(segment_data) < samples_per_segment:
                        continue
                    
                    # Randomize duration with bias toward longer (1.2-3.0s, biased toward 1.8-2.5s)
                    # Using triangular distribution: min=1.2, mode=2.0, max=3.0
                    import random
                    random_duration = random.triangular(1.2, 3.0, 2.0)
                    
                    all_segments.append({
                        'recording': rec_idx,
                        'recording_name': rec_name,  # Store actual name for display
                        'segment_idx': seg_idx,
                        'data': segment_data,
                        'start_positions': segment_data[0],
                        'end_positions': segment_data[-1],
                        'duration': random_duration  # Variable duration per segment
                    })
            
            self.pir_markov_segments[state_name] = all_segments
            
            # Build transition matrix based on position similarity
            if len(all_segments) > 1:
                self.pir_markov_transitions[state_name] = self._build_transition_matrix(all_segments)
            else:
                self.pir_markov_transitions[state_name] = []
        
        # Build hardware-equivalent segments and sparse transitions for preview
        self._build_hardware_preview_data()
        
        total = sum(len(segs) for segs in self.pir_markov_segments.values())
        print(f"[MARKOV] Built {total} segments (idle:{len(self.pir_markov_segments['idle'])}, "
              f"active:{len(self.pir_markov_segments['active'])}, sleep:{len(self.pir_markov_segments['sleep'])})")
        
        self.pir_markov_initialized = True
        self.pir_current_segment_idx = 0
        self.pir_segment_start_time = time.time()
        self.pir_prev_segment_end_positions = None
        self.pir_needs_blend = False
        
        # Update info display
        self._update_markov_info_display()
    
    def _update_markov_info_display(self):
        """Update the Markov info label with segment counts and size estimation."""
        if not hasattr(self, 'pir_markov_info_label'):
            return
        
        total_segs = sum(len(segs) for segs in self.pir_markov_segments.values())
        if total_segs == 0:
            self.pir_markov_info_label.config(text="No segments built")
            return
        
        # Count segments per recording
        rec_counts = {}  # {rec_name: count}
        for state_name, segments in self.pir_markov_segments.items():
            for seg in segments:
                rec_name = seg.get('recording_name', f"rec{seg['recording']}")
                if rec_name not in rec_counts:
                    rec_counts[rec_name] = {'idle': 0, 'active': 0, 'sleep': 0}
                rec_counts[rec_name][state_name] += 1
        
        # Calculate Arduino memory size (matches export settings).
        samples_per_seg = self.HARDWARE_SAMPLES_PER_SEG
        top_k = self.HARDWARE_TOP_K_TRANSITIONS
        bytes_per_segment = samples_per_seg * self.num_servos + (top_k * 2)  # data + sparse transitions
        total_bytes = total_segs * bytes_per_segment
        total_kb = total_bytes / 1024
        
        # Format info text
        segment_length = self.pir_markov_segment_length.get()
        lines = []
        mode_label = "HW" if self.pir_markov_hardware_preview.get() else "FULL"
        lines.append(f"Mode: {mode_label} preview")
        lines.append(f"Segments: {total_segs} ({segment_length}s each, {samples_per_seg} samples)")
        
        # Per-recording breakdown
        for rec_name, counts in rec_counts.items():
            parts = []
            if counts['idle'] > 0:
                parts.append(f"I:{counts['idle']}")
            if counts['active'] > 0:
                parts.append(f"A:{counts['active']}")
            if counts['sleep'] > 0:
                parts.append(f"S:{counts['sleep']}")
            lines.append(f"  {rec_name}: {' '.join(parts)}")
        
        # Size estimation (more accurate now)
        if total_kb > 25:
            lines.append(f"Arduino: ~{total_kb:.1f}KB [!] Near 30KB limit")
        else:
            lines.append(f"Arduino: ~{total_kb:.1f}KB (limit ~30KB)")
        
        self.pir_markov_info_label.config(text="\n".join(lines))
    
    def _merge_layers_to_samples(self, layers, sample_rate=50):
        """Merge multiple layers into a single sample array at fixed rate."""
        if not layers:
            print("    [MERGE] no layers provided")
            return []
        
        # Find max duration
        durations = [layer.get('duration', 0) for layer in layers]
        max_duration = max(durations) if durations else 0
        
        if max_duration <= 0:
            print(f"    [MERGE] max_duration is {max_duration}")
            return []
        
        num_samples = int(max_duration * sample_rate)
        print(f"    [MERGE] max_duration={max_duration:.2f}s, num_samples={num_samples}")
        
        if num_samples <= 0:
            return []
        
        # Initialize with None
        samples = []
        rest_pose = [float(v) for v in self.get_startup_pose()]

        for sample_idx in range(num_samples):
            t = sample_idx / sample_rate
            # Rest pose, not a hardcoded 90: 90 sits outside any range narrower
            # than it, so unrecorded channels saturated at the top of their
            # travel instead of staying put.
            positions = list(rest_pose)
            
            for layer in layers:
                data = layer.get('data', [])
                if not data:
                    continue
                
                duration = layer.get('duration', 1.0)
                layer_t = t * (duration / max_duration) if max_duration > 0 else 0
                
                # Find surrounding keyframes
                prev_point = data[0]
                next_point = data[-1]
                for i, point in enumerate(data):
                    if point['time'] >= layer_t:
                        next_point = point
                        prev_point = data[max(0, i - 1)]
                        break
                
                # Interpolate
                time_diff = next_point['time'] - prev_point['time']
                if time_diff > 0:
                    factor = (layer_t - prev_point['time']) / time_diff
                    factor = max(0, min(1, factor))
                else:
                    factor = 0
                
                # Apply finger positions
                for finger_idx in range(5):
                    prev_fingers = prev_point.get('finger_positions', [])
                    next_fingers = next_point.get('finger_positions', [])
                    if finger_idx < len(prev_fingers) and finger_idx < len(next_fingers):
                        pv = prev_fingers[finger_idx]
                        nv = next_fingers[finger_idx]
                        if pv is not None and nv is not None:
                            positions[finger_idx] = pv + (nv - pv) * factor
                
                # Apply arm positions
                for arm_idx in range(self.num_arm_servos):
                    prev_arm = prev_point.get('arm_positions', [])
                    next_arm = next_point.get('arm_positions', [])
                    if arm_idx < len(prev_arm) and arm_idx < len(next_arm):
                        pv = prev_arm[arm_idx]
                        nv = next_arm[arm_idx]
                        if pv is not None and nv is not None:
                            positions[5 + arm_idx] = pv + (nv - pv) * factor
            
            samples.append(positions)
        
        return samples
    
    def _build_transition_matrix(self, segments):
        """Build probability matrix based on position similarity between segment ends and starts."""
        import math
        
        num_segments = len(segments)
        chaos = self.pir_markov_chaos.get() / 100.0  # 0.0 to 1.0
        
        # Calculate similarity scores between all pairs
        # similarity = how similar segment[i].end is to segment[j].start
        matrix = []
        
        for i in range(num_segments):
            end_pos = segments[i]['end_positions']
            probs = []
            
            for j in range(num_segments):
                if i == j:
                    # Small chance to repeat same segment
                    probs.append(0.05)
                    continue
                
                start_pos = segments[j]['start_positions']
                
                # Calculate distance (sum of squared differences)
                dist = 0
                for k in range(self.num_servos):
                    diff = end_pos[k] - start_pos[k]
                    dist += diff * diff
                dist = math.sqrt(dist)
                
                # Convert distance to similarity (closer = higher)
                # Max distance ~ 180*sqrt(8) ~ 509
                similarity = max(0, 1 - (dist / 200))
                
                # Mix similarity with uniform random based on chaos setting
                # chaos=0: pure similarity, chaos=1: pure random
                uniform = 1.0 / (num_segments - 1)
                prob = (1 - chaos) * similarity + chaos * uniform
                probs.append(prob)
            
            # Normalize to sum to 1
            total = sum(probs)
            if total > 0:
                probs = [p / total for p in probs]
            else:
                probs = [1.0 / num_segments] * num_segments
            
            matrix.append(probs)
        
        return matrix
    
    def _build_hardware_preview_data(self):
        """Build hardware-equivalent segments and sparse transitions for accurate preview.
        
        This creates the exact same data that gets exported to Arduino:
        - Segments subsampled to HARDWARE_SAMPLES_PER_SEG (12) points
        - Transitions limited to top HARDWARE_TOP_K_TRANSITIONS (6) with byte probabilities
        """
        self.pir_markov_hw_segments = {'idle': [], 'active': [], 'sleep': []}
        self.pir_markov_hw_transitions = {'idle': [], 'active': [], 'sleep': []}
        
        for state_name in ['idle', 'active', 'sleep']:
            full_segments = self.pir_markov_segments.get(state_name, [])
            full_transitions = self.pir_markov_transitions.get(state_name, [])
            
            if not full_segments:
                continue
            
            # Subsample each segment to hardware resolution
            hw_segs = []
            for seg in full_segments:
                full_data = seg['data']
                num_samples = len(full_data)
                
                # Subsample to HARDWARE_SAMPLES_PER_SEG points
                hw_data = []
                for i in range(self.HARDWARE_SAMPLES_PER_SEG):
                    # Calculate source index (same logic as Arduino export)
                    src_idx = int(i * (num_samples - 1) / (self.HARDWARE_SAMPLES_PER_SEG - 1))
                    src_idx = min(src_idx, num_samples - 1)
                    hw_data.append(full_data[src_idx][:])  # Copy the positions
                
                hw_segs.append({
                    'data': hw_data,
                    'duration': seg['duration'],
                    'recording_name': seg.get('recording_name', ''),
                    'start_positions': hw_data[0],
                    'end_positions': hw_data[-1]
                })
            
            self.pir_markov_hw_segments[state_name] = hw_segs
            
            # Build sparse top-K transitions (same as Arduino export)
            if full_transitions:
                sparse_trans = []
                for i, probs in enumerate(full_transitions):
                    # Get indices sorted by probability
                    indexed_probs = [(idx, p) for idx, p in enumerate(probs)]
                    indexed_probs.sort(key=lambda x: x[1], reverse=True)
                    
                    # Take top K
                    top_k = indexed_probs[:self.HARDWARE_TOP_K_TRANSITIONS]
                    
                    # Normalize probabilities to sum to 1.0
                    total = sum(p for _, p in top_k)
                    if total > 0:
                        normalized = [(idx, p / total) for idx, p in top_k]
                    else:
                        # Fallback: uniform among top K
                        normalized = [(idx, 1.0 / len(top_k)) for idx, _ in top_k]
                    
                    sparse_trans.append(normalized)  # List of (index, probability) tuples
                
                self.pir_markov_hw_transitions[state_name] = sparse_trans
        
        print(f"[MARKOV] Hardware preview data built (samples/seg={self.HARDWARE_SAMPLES_PER_SEG}, top-K={self.HARDWARE_TOP_K_TRANSITIONS})")

    def _markov_pick_next_segment(self, state):
        """Pick the next segment using Markov transition probabilities."""
        import random
        
        segments = self.pir_markov_segments.get(state, [])
        if not segments or self.pir_current_segment_idx >= len(segments):
            return 0
        
        # Use sparse transitions when hardware preview is enabled
        if self.pir_markov_hardware_preview.get():
            sparse_transitions = self.pir_markov_hw_transitions.get(state, [])
            if sparse_transitions and self.pir_current_segment_idx < len(sparse_transitions):
                # Sparse format: list of (index, probability) tuples
                trans = sparse_transitions[self.pir_current_segment_idx]
                r = random.random()
                cumulative = 0
                for idx, prob in trans:
                    cumulative += prob
                    if r <= cumulative:
                        return idx
                # Fallback to first option
                return trans[0][0] if trans else 0
            return random.randint(0, len(segments) - 1)
        
        # Full transition matrix for non-hardware preview
        transitions = self.pir_markov_transitions.get(state, [])
        if not transitions:
            return 0
        
        probs = transitions[self.pir_current_segment_idx]
        
        # Weighted random choice
        r = random.random()
        cumulative = 0
        for idx, prob in enumerate(probs):
            cumulative += prob
            if r <= cumulative:
                return idx
        
        return len(probs) - 1  # Fallback to last
    
    def _update_markov_playback(self, current_time):
        """Update Markov segment playback (matches Arduino export exactly)."""
        import random
        
        # Use hardware segments when hardware preview is enabled
        use_hw = self.pir_markov_hardware_preview.get()
        if use_hw:
            segments = self.pir_markov_hw_segments.get(self.pir_state, [])
        else:
            segments = self.pir_markov_segments.get(self.pir_state, [])
        
        if not segments:
            return None, None
        
        # Initialize if needed
        if self.pir_current_segment_idx >= len(segments):
            self.pir_current_segment_idx = 0
            self.pir_segment_start_time = current_time
        
        current_seg = segments[self.pir_current_segment_idx]
        segment_duration = current_seg['duration']
        segment_elapsed = current_time - self.pir_segment_start_time
        
        # Check if segment is done
        if segment_elapsed >= segment_duration:
            # Store end positions for blending
            self.pir_prev_segment_end_positions = current_seg['data'][-1][:]
            
            # Pick next segment
            next_idx = self._markov_pick_next_segment(self.pir_state)
            self.pir_current_segment_idx = next_idx
            self.pir_segment_start_time = current_time
            self.pir_needs_blend = True
            segment_elapsed = 0
            current_seg = segments[next_idx]
            segment_duration = current_seg['duration']
            # Update display
            self.update_pir_state_display()
        
        # Calculate position within segment
        progress = segment_elapsed / segment_duration if segment_duration > 0 else 1.0
        num_samples = len(current_seg['data'])
        
        if use_hw:
            # Hardware mode: interpolate between sparse samples
            sample_float = progress * (num_samples - 1)
            sample_idx = min(int(sample_float), num_samples - 2)
            interp_factor = sample_float - sample_idx
            
            pos_a = current_seg['data'][sample_idx]
            pos_b = current_seg['data'][sample_idx + 1]
            positions = [pos_a[i] + (pos_b[i] - pos_a[i]) * interp_factor for i in range(self.num_servos)]
        else:
            # Full-fidelity mode: direct sample lookup
            sample_idx = min(int(progress * num_samples), num_samples - 1)
            positions = current_seg['data'][sample_idx][:]
        
        # Blend from previous segment if needed
        blend_time = self.pir_markov_blend_time.get()
        if self.pir_needs_blend and segment_elapsed < blend_time and self.pir_prev_segment_end_positions:
            blend_factor = segment_elapsed / blend_time if blend_time > 0 else 1.0
            # Smootherstep
            bf = blend_factor
            blend_factor = bf * bf * bf * (bf * (bf * 6.0 - 15.0) + 10.0)
            
            for i in range(self.num_servos):
                old_pos = self.pir_prev_segment_end_positions[i]
                new_pos = positions[i]
                positions[i] = old_pos + (new_pos - old_pos) * blend_factor
        elif segment_elapsed >= blend_time:
            self.pir_needs_blend = False
        
        return positions, current_seg
    
    def get_pir_playback_speed(self):
        """Get the playback speed for the current PIR state. Now always 1.0 (speed embedded in recording)."""
        return 1.0
    
    def get_pir_active_recording_name(self):
        """Get the current recording filename for the current PIR state."""
        rec_lists = {
            'idle': self.pir_idle_recordings,
            'active': self.pir_active_recordings,
            'sleep': self.pir_sleep_recordings
        }
        rec_list = rec_lists.get(self.pir_state, [])
        if not rec_list:
            return ""
        
        # Get current index for this state
        idx = self.pir_recording_index.get(self.pir_state, 0) % len(rec_list)
        return rec_list[idx]
    
    def advance_pir_recording(self):
        """Move to next recording in the current state's list (random or sequential)."""
        rec_lists = {
            'idle': self.pir_idle_recordings,
            'active': self.pir_active_recordings,
            'sleep': self.pir_sleep_recordings
        }
        rec_list = rec_lists.get(self.pir_state, [])
        
        if len(rec_list) <= 1:
            return  # No other recordings to switch to
        
        import random
        # Pick a different recording randomly
        current_idx = self.pir_recording_index.get(self.pir_state, 0)
        available = [i for i in range(len(rec_list)) if i != current_idx]
        if available:
            new_idx = random.choice(available)
            self.pir_recording_index[self.pir_state] = new_idx
            
            # Store current positions for crossfade
            self.pir_prev_rec_positions = {
                'fingers': self.finger_positions[:],
                'arm': self.arm_positions[:]
            }
            self.pir_rec_blend_factor = 0.0
            print(f"🔄 Switching to recording: {rec_list[new_idx]}")
            
            # Update the display to show new recording
            self.update_pir_state_display()
    
    def get_pir_active_layers(self):
        """Get the loaded layers for the current PIR state. Returns list or None."""
        recording_name = self.get_pir_active_recording_name()
        if not recording_name or recording_name == '(None)':
            return None
        return self.load_pir_recording(recording_name)
    
    def _get_pir_crossfade_target_layers(self):
        """Get the layers for the crossfade target recording. Returns list or None."""
        rec_lists = {
            'idle': self.pir_idle_recordings,
            'active': self.pir_active_recordings,
            'sleep': self.pir_sleep_recordings
        }
        rec_list = rec_lists.get(self.pir_state, [])
        if not rec_list or self.pir_crossfade_target_idx >= len(rec_list):
            return None
        
        target_name = rec_list[self.pir_crossfade_target_idx]
        if not target_name or target_name == '(None)':
            return None
        return self.load_pir_recording(target_name)
    
    def export_pir_state_machine(self):
        """Export the complete PIR State Machine to Arduino .ino file."""
        # Validate that we have recordings assigned
        idle_recs = self.pir_idle_recordings
        active_recs = self.pir_active_recordings
        sleep_recs = self.pir_sleep_recordings
        
        if not any([idle_recs, active_recs, sleep_recs]):
            tkinter.messagebox.showwarning("No Recordings", 
                "Please assign at least one recording to a PIR state before exporting.")
            return
        
        # Load all the recordings for each state
        # Structure: {state: [layers_list1, layers_list2, ...]}
        recordings = {'idle': [], 'active': [], 'sleep': []}
        
        for state, rec_list in [('idle', idle_recs), ('active', active_recs), ('sleep', sleep_recs)]:
            for rec_name in rec_list:
                if rec_name and rec_name != '(None)':
                    layers = self.load_pir_recording(rec_name)
                    if layers:
                        recordings[state].append({'name': rec_name, 'layers': layers})
                        print(f"📂 Loaded {state}: {rec_name} ({len(layers)} layers)")
                    else:
                        print(f"⚠️ Could not load recording for {state}: {rec_name}")
        
        total_recordings = sum(len(r) for r in recordings.values())
        if total_recordings == 0:
            tkinter.messagebox.showerror("Load Failed", "Could not load any of the assigned recordings.")
            return
        
        # Generate the Arduino code - use Markov if enabled
        if self.pir_markov_enabled.get():
            code = self.generate_markov_pir_code(recordings)
            mode_str = "Markov"
        else:
            code = self.generate_pir_state_machine_code(recordings)
            mode_str = "Crossfade"
        
        # Save to file
        filename = f"pir_{mode_str.lower()}_{datetime.datetime.now().strftime('%Y%m%d_%H%M%S')}.ino"
        filepath = os.path.join(os.getcwd(), filename)
        
        try:
            with open(filepath, 'w', encoding='utf-8') as f:
                f.write(code)
            
            # Show success with details
            states_info = []
            for state, rec_list in [('idle', self.pir_idle_recordings), 
                                    ('active', self.pir_active_recordings), 
                                    ('sleep', self.pir_sleep_recordings)]:
                if rec_list:
                    rec_names = ', '.join(rec_list[:3])  # Show up to 3
                    if len(rec_list) > 3:
                        rec_names += f" (+{len(rec_list)-3} more)"
                    states_info.append(f"  {state.upper()}: {len(rec_list)} recording(s)\n    {rec_names}")
                else:
                    states_info.append(f"  {state.upper()}: (none)")
            
            extra_info = ""
            if mode_str == "Markov":
                extra_info = f"\nMarkov Settings:\n  Segment length: {self.pir_markov_segment_length.get()}s\n  Chaos: {self.pir_markov_chaos.get()}%\n  Blend time: {self.pir_markov_blend_time.get()}s\n"
            
            tkinter.messagebox.showinfo(f"PIR Export ({mode_str})", 
                f"Arduino code exported to:\n{filepath}\n\n" +
                f"Mode: {mode_str} (compressed PIR export)\n\n" +
                f"State Recordings:\n" + "\n".join(states_info) + "\n\n" +
                f"Timing:\n" +
                f"  Active duration: {self.pir_active_duration.get()}s\n" +
                f"  Sleep timeout: {self.pir_sleep_timeout.get()} min\n" +
                f"  Blend time: {self.pir_transition_time.get()}s" + extra_info)
            
            print(f"📤 PIR State Machine ({mode_str}) exported to {filepath}")
            
        except Exception as e:
            tkinter.messagebox.showerror("Export Failed", f"Failed to export:\n{e}")
    
    def generate_pir_state_machine_code(self, recordings):
        """Generate Arduino code for the PIR state machine.
        recordings format: {state: [{name, layers}, ...]}
        """
        
        # Hardware config
        hw = self.hardware_config
        pins = hw['pin_mapping']
        reversed_servos = hw['reversed_servos']
        # Use hardware config limits (matches listener behavior: 0-45 for the physical servos)
        # Backstop only. The clamp the piece was performed with is per
        # channel, and a standalone sketch has no host to apply it.
        eff_min_str, eff_max_str = self.effective_limits_c_arrays()
        min_angle = hw.get('firmware_safe_min', 0)
        max_angle = hw.get('firmware_safe_max', 180)
        
        # Timing config
        active_duration_ms = int(self.pir_active_duration.get() * 1000)
        sleep_timeout_ms = int(self.pir_sleep_timeout.get() * 60 * 1000)
        blend_time_ms = int(self.pir_transition_time.get() * 1000)
        startup_lockout_ms = int(self.pir_startup_lockout.get() * 1000)

        # Crossfade config
        crossfade_enabled = 'true' if self.pir_crossfade_enabled.get() else 'false'
        crossfade_interval_min = int(self.pir_crossfade_interval_min.get() * 1000)
        crossfade_interval_max = int(self.pir_crossfade_interval_max.get() * 1000)
        crossfade_duration_min = int(self.pir_crossfade_duration_min.get() * 1000)
        crossfade_duration_max = int(self.pir_crossfade_duration_max.get() * 1000)
        
        # Decide the channel set and per-take sample counts before any array is
        # emitted -- both the declarations and the lookup code depend on them.
        (self._pir_active_channels, self._pir_sample_plan,
         self._pir_sample_rate) = self.plan_pir_data(recordings)

        # Organic wobble config. The toggle is the single source of truth, the
        # same way the movement exporter treats it: off means a literal 0.0 in
        # the sketch. This used to read the slider unconditionally, so with
        # Organic Variations switched OFF the preview replayed the take clean
        # while the exported sketch layered a continuous sine drift over every
        # channel -- small, always moving, and present in the sketch only.
        wobble_amount = float(self.position_wobble.get()) if self.organic_enabled.get() else 0.0

        # Count total recordings per state for comments
        rec_counts = {s: len(recs) for s, recs in recordings.items()}

        # Startup pose: use first sample from first available recording (prefer IDLE).
        startup_positions = [90] * self.num_servos
        startup_layers = None
        for state_name in ['idle', 'active', 'sleep']:
            state_recs = recordings.get(state_name, [])
            if state_recs:
                startup_layers = state_recs[0].get('layers', [])
                if startup_layers:
                    break
        if startup_layers:
            merged_startup = self._merge_layers_to_samples(startup_layers, sample_rate=50)
            if merged_startup:
                startup_positions = [int(round(v)) for v in merged_startup[0]]
        startup_positions_str = ', '.join(str(v) for v in startup_positions)
        
        code = f'''// PIR State Machine - Auto-generated by Hand Control Interface
// Generated: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}
// 
// State Machine:
//   MOTION DETECTED -> ACTIVE state (plays active recordings)
//   After {self.pir_active_duration.get()}s no motion -> IDLE state  
//   After {self.pir_sleep_timeout.get()} min idle -> SLEEP state
//   Any motion -> back to ACTIVE
//
// Recordings per state:
//   IDLE: {rec_counts.get('idle', 0)} recordings
//   ACTIVE: {rec_counts.get('active', 0)} recordings  
//   SLEEP: {rec_counts.get('sleep', 0)} recordings
//
// Smooth blending between states over {self.pir_transition_time.get()}s

#include <Servo.h>

// ==================== CONFIGURATION ====================
#define PIR_PIN {self.hardware_config.get('pir_pin', 2)}  // PIR sensor input pin
#define NUM_SERVOS {self.num_servos}
#define UPDATE_INTERVAL 5  // ms between servo updates (200Hz)

// Timing (milliseconds)
const unsigned long ACTIVE_DURATION = {active_duration_ms}UL;
const unsigned long SLEEP_TIMEOUT = {sleep_timeout_ms}UL;
const unsigned long BLEND_TIME = {blend_time_ms}UL;
// Hold IDLE and ignore the sensor for this long after power-up (0 = disabled).
const unsigned long STARTUP_LOCKOUT = {startup_lockout_ms}UL;

// Servo pin mapping
const int servoPins[NUM_SERVOS] = {{{', '.join(map(str, pins))}}};

// Startup pose (logical 0-180, before hardware mapping)
const int startupPositions[NUM_SERVOS] = {{{startup_positions_str}}};

// Reversed servo flags
const bool servoReversed[NUM_SERVOS] = {{{', '.join(['true' if i in reversed_servos else 'false' for i in range(self.num_servos)])}}};

// Angle limits. MIN/MAX are the hardware backstop; the per-channel arrays are
// the range the piece was actually performed with (per-servo limit intersected
// with the UI's expressive range) and are what playback clamps to. There is no
// host in this sketch to apply them, so they are compiled in.
const int MIN_ANGLE = {min_angle};
const int MAX_ANGLE = {max_angle};
const int servoMin[NUM_SERVOS] = {{{eff_min_str}}};
const int servoMax[NUM_SERVOS] = {{{eff_max_str}}};

// ==================== STATE MACHINE ====================
enum State {{ STATE_IDLE, STATE_ACTIVE, STATE_SLEEP }};
State currentState = STATE_IDLE;
State previousState = STATE_IDLE;

unsigned long lastMotionTime = 0;
unsigned long stateStartTime = 0;
unsigned long transitionStartTime = 0;
float stateBlendFactor = 1.0;  // For state-to-state transitions

// Recording crossfade system (for organic blending within a state)
// Each state has two "active" recordings that crossfade into each other
int idleRecA = 0, idleRecB = 0;
int activeRecA = 0, activeRecB = 0;
int sleepRecA = 0, sleepRecB = 0;
float crossfadeFactor = 0.0;           // 0.0 = 100% recA, 1.0 = 100% recB
unsigned long crossfadeStartTime = 0;
unsigned long crossfadeDuration = 3000; // How long each crossfade takes (ms)
unsigned long nextCrossfadeTime = 0;    // When to start the next crossfade
bool isCrossfading = false;

// Crossfade timing range (randomized for organic feel)
const unsigned long MIN_CROSSFADE_INTERVAL = {crossfade_interval_min}UL;  // Min time between crossfades
const unsigned long MAX_CROSSFADE_INTERVAL = {crossfade_interval_max}UL; // Max time between crossfades
const unsigned long MIN_CROSSFADE_DURATION = {crossfade_duration_min}UL;  // Min crossfade length
const unsigned long MAX_CROSSFADE_DURATION = {crossfade_duration_max}UL;  // Max crossfade length
const bool CROSSFADE_ENABLED = {crossfade_enabled};  // Enable organic crossfading between recordings
const int MAX_STEP_PER_UPDATE = 2;  // Slew-rate limit to reduce twitchy jumps

// Only the channels that were actually recorded are stored in the movement
// tables; the rest hold REST_POSE. A constant column costs the same flash as a
// moving one, and that flash is what limits the sample rate.
#define NUM_STORED_CH {len(self._pir_active_channels)}
const uint8_t STORED_CH[NUM_STORED_CH] PROGMEM = {{{', '.join(str(c) for c in self._pir_active_channels)}}};
const int REST_POSE[NUM_SERVOS] = {{{', '.join(str(int(round(v))) for v in self.get_startup_pose())}}};

// Organic sine wave wobble (adds life-like micro-movements)
const float WOBBLE_AMOUNT = {wobble_amount};  // Max degrees of wobble (0 = disabled)
float phaseOffsets[NUM_SERVOS];  // Random phase offset per servo for variety

// Current servo positions (for blending)
int currentPositions[NUM_SERVOS] = {{{startup_positions_str}}};
int transitionFromPositions[NUM_SERVOS];

// ==================== SERVO OBJECTS ====================
Servo servos[NUM_SERVOS];

'''
        
        # Generate the movement data arrays for each state
        # For multi-recording states, we generate arrays for each recording
        for state_name, rec_list in recordings.items():
            if not rec_list:
                code += f"\n// No recordings for {state_name} state\n"
                continue
            
            for rec_idx, rec_data in enumerate(rec_list):
                rec_name = rec_data['name']
                layers = rec_data['layers']
                array_suffix = f"_{rec_idx}" if len(rec_list) > 1 else ""
                code += f"\n// {state_name.upper()} recording {rec_idx}: {rec_name}\n"
                code += self._generate_state_movement_data(f"{state_name}{array_suffix}", layers, min_angle, max_angle)
            
            # Add count constant for this state (use #define so #ifdef works)
            code += f"#define NUM_{state_name.upper()}_RECORDINGS {len(rec_list)}\n"
        
        code += '''
// ==================== HELPER FUNCTIONS ====================

int applyServoLimits(int angle, int servoIdx) {
  // Degrees in, degrees out. Recorded values are already the degrees the UI
  // was showing, so rescaling them onto MIN..MAX (as this used to) shrank
  // every playback against the take it was recorded from. The range clamps.
  int lo = servoMin[servoIdx];
  int hi = servoMax[servoIdx];
  int pos = constrain(angle, lo, hi);

  // Mirror within THIS channel's range. A shared MAX_ANGLE - pos only lands
  // correctly when every channel starts at 0; on a 20-160 channel it threw
  // the servo 20 degrees off, which read as "the reversal didn't take".
  if (servoReversed[servoIdx]) {
    pos = lo + hi - pos;
  }
  return constrain(pos, MIN_ANGLE, MAX_ANGLE);
}

int blendPositions(int from, int to, float factor) {
  // Smootherstep for very smooth state transitions (barely noticeable)
  float t = factor;
  float easedFactor = t * t * t * (t * (t * 6.0 - 15.0) + 10.0);  // Ken Perlin smootherstep
  return from + (int)((to - from) * easedFactor);
}

'''
        
        # Generate the position lookup function for each state
        code += self._generate_position_lookup_functions(recordings)
        
        code += '''
// ==================== CROSSFADE SYSTEM ====================

void updateCrossfade() {
  // Skip if crossfade is disabled
  if (!CROSSFADE_ENABLED) return;
  
  unsigned long now = millis();
  
  // Check if we should start a new crossfade
  if (!isCrossfading && now >= nextCrossfadeTime) {
    startNewCrossfade();
  }
  
  // Update crossfade progress
  if (isCrossfading) {
    unsigned long elapsed = now - crossfadeStartTime;
    if (elapsed >= crossfadeDuration) {
      // Crossfade complete - A becomes B, pick new B
      finishCrossfade();
    } else {
      // Very smooth crossfade using smootherstep (barely noticeable)
      float t = (float)elapsed / crossfadeDuration;
      // Smootherstep (Ken Perlin) - much gentler than smoothstep
      crossfadeFactor = t * t * t * (t * (t * 6.0 - 15.0) + 10.0);
    }
  }
}

void startNewCrossfade() {
  isCrossfading = true;
  crossfadeStartTime = millis();
  crossfadeDuration = random(MIN_CROSSFADE_DURATION, MAX_CROSSFADE_DURATION);
  crossfadeFactor = 0.0;
  
  // Pick a new target recording (recB) different from current (recA)
  switch (currentState) {
    case STATE_IDLE:
      #if NUM_IDLE_RECORDINGS > 1
      do { idleRecB = random(NUM_IDLE_RECORDINGS); } while (idleRecB == idleRecA);
      #endif
      break;
    case STATE_ACTIVE:
      #if NUM_ACTIVE_RECORDINGS > 1
      do { activeRecB = random(NUM_ACTIVE_RECORDINGS); } while (activeRecB == activeRecA);
      #endif
      break;
    case STATE_SLEEP:
      #if NUM_SLEEP_RECORDINGS > 1
      do { sleepRecB = random(NUM_SLEEP_RECORDINGS); } while (sleepRecB == sleepRecA);
      #endif
      break;
  }
}

void finishCrossfade() {
  isCrossfading = false;
  crossfadeFactor = 0.0;
  
  // A becomes B (we've fully transitioned to B)
  idleRecA = idleRecB;
  activeRecA = activeRecB;
  sleepRecA = sleepRecB;
  
  // Schedule next crossfade at random interval
  nextCrossfadeTime = millis() + random(MIN_CROSSFADE_INTERVAL, MAX_CROSSFADE_INTERVAL);
}

// ==================== STATE MACHINE LOGIC ====================

void checkStateTransitions() {
  unsigned long now = millis();
  unsigned long timeSinceMotion = now - lastMotionTime;
  
  State newState = currentState;
  
  switch (currentState) {
    case STATE_ACTIVE:
      // After active duration with no motion, go to idle
      if (timeSinceMotion >= ACTIVE_DURATION) {
        newState = STATE_IDLE;
      }
      break;
      
    case STATE_IDLE:
      // After sleep timeout, go to sleep
      if (timeSinceMotion >= SLEEP_TIMEOUT) {
        newState = STATE_SLEEP;
      }
      break;
      
    case STATE_SLEEP:
      // Only wake up on motion (handled in triggerMotion)
      break;
  }
  
  if (newState != currentState) {
    startTransition(newState);
  }
  
  // Update state blend factor
  if (now - transitionStartTime < BLEND_TIME) {
    stateBlendFactor = (float)(now - transitionStartTime) / BLEND_TIME;
  } else {
    stateBlendFactor = 1.0;
  }
}

void startTransition(State newState) {
  Serial.print("State: ");
  Serial.print(currentState);
  Serial.print(" -> ");
  Serial.println(newState);
  
  // Save current positions for blending
  for (int i = 0; i < NUM_SERVOS; i++) {
    transitionFromPositions[i] = currentPositions[i];
  }
  
  // Initialize crossfade for the new state with random recordings
  switch (newState) {
    case STATE_IDLE:
      #ifdef NUM_IDLE_RECORDINGS
      idleRecA = random(NUM_IDLE_RECORDINGS);
      idleRecB = random(NUM_IDLE_RECORDINGS);
      #endif
      break;
    case STATE_ACTIVE:
      #ifdef NUM_ACTIVE_RECORDINGS
      activeRecA = random(NUM_ACTIVE_RECORDINGS);
      activeRecB = random(NUM_ACTIVE_RECORDINGS);
      #endif
      break;
    case STATE_SLEEP:
      #ifdef NUM_SLEEP_RECORDINGS
      sleepRecA = random(NUM_SLEEP_RECORDINGS);
      sleepRecB = random(NUM_SLEEP_RECORDINGS);
      #endif
      break;
  }
  
  // Reset crossfade state
  isCrossfading = false;
  crossfadeFactor = 0.0;
  nextCrossfadeTime = millis() + random(MIN_CROSSFADE_INTERVAL, MAX_CROSSFADE_INTERVAL);
  
  previousState = currentState;
  currentState = newState;
  stateStartTime = millis();
  transitionStartTime = millis();
  stateBlendFactor = 0.0;
}

void triggerMotion() {
  unsigned long now = millis();
  lastMotionTime = now;
  
  if (currentState != STATE_ACTIVE) {
    startTransition(STATE_ACTIVE);
    Serial.println("PIR: Motion detected!");
  }
}

// ==================== MAIN PLAYBACK ====================

void updateServos() {
  static unsigned long playbackTime = 0;
  static unsigned long lastUpdate = 0;
  
  unsigned long now = millis();
  unsigned long elapsed = now - lastUpdate;
  lastUpdate = now;
  
  // Advance playback time
  playbackTime += elapsed;
  
  // Update crossfade between recordings
  updateCrossfade();
  
  // Get blended positions from current state's recordings
  int positionsA[NUM_SERVOS];
  int positionsB[NUM_SERVOS];
  int targetPositions[NUM_SERVOS];
  
  // Get positions from both active recordings
  getPositionsForRecording(currentState, 0, playbackTime, positionsA);  // Recording A
  getPositionsForRecording(currentState, 1, playbackTime, positionsB);  // Recording B
  
  // Blend between the two recordings
  for (int i = 0; i < NUM_SERVOS; i++) {
    targetPositions[i] = positionsA[i] + (int)((positionsB[i] - positionsA[i]) * crossfadeFactor);
  }
  
    // If transitioning between states, blend from old positions
    int desiredPositions[NUM_SERVOS];
  if (stateBlendFactor < 1.0) {
    for (int i = 0; i < NUM_SERVOS; i++) {
            desiredPositions[i] = blendPositions(transitionFromPositions[i], targetPositions[i], stateBlendFactor);
    }
  } else {
    for (int i = 0; i < NUM_SERVOS; i++) {
            desiredPositions[i] = targetPositions[i];
        }
    }

    // Apply slew-rate limiting to avoid abrupt per-frame jumps.
    for (int i = 0; i < NUM_SERVOS; i++) {
        int delta = desiredPositions[i] - currentPositions[i];
        if (delta > MAX_STEP_PER_UPDATE) delta = MAX_STEP_PER_UPDATE;
        if (delta < -MAX_STEP_PER_UPDATE) delta = -MAX_STEP_PER_UPDATE;
        currentPositions[i] += delta;
        if (currentPositions[i] < 0) currentPositions[i] = 0;
        if (currentPositions[i] > 180) currentPositions[i] = 180;
    }

    // If still in state transition, update blend source so we don't get re-jumps.
    if (stateBlendFactor < 1.0) {
        for (int i = 0; i < NUM_SERVOS; i++) {
            transitionFromPositions[i] = currentPositions[i];
    }
  }
  
  // Write to servos with organic wobble
  float t = millis() / 1000.0;  // Time in seconds
  for (int i = 0; i < NUM_SERVOS; i++) {
    int finalPos = currentPositions[i];
    
    // Apply organic sine-wave wobble if enabled
    if (WOBBLE_AMOUNT > 0) {
      float phase = phaseOffsets[i];
      // Layer 1: Slow breathing rhythm (~7 second cycle)
      float breath = sin(t * 0.9 + phase) * 0.5;
      // Layer 2: Medium drift (~2.5 second cycle)
      float drift = sin(t * 2.5 + phase * 1.3) * 0.3;
      // Layer 3: Subtle micro-tremor (faster, smaller)
      float tremor = sin(t * 7.5 + phase * 2.1) * 0.2;
      
      float wobble = (breath + drift + tremor) * WOBBLE_AMOUNT;
      finalPos += (int)wobble;
    }
    
    int angle = applyServoLimits(finalPos, i);
    servos[i].write(angle);
  }
}

'''
        
        # Setup and loop
        code += '''
// ==================== SETUP & LOOP ====================

void setup() {
  Serial.begin(9600);
  Serial.println("PIR State Machine Starting...");
  
  // Seed random number generator for recording selection
  randomSeed(analogRead(0));
  
  // Initialize PIR pin
  pinMode(PIR_PIN, INPUT);
  
  // Initialize random phase offsets for organic wobble
  for (int i = 0; i < NUM_SERVOS; i++) {
    phaseOffsets[i] = random(0, 628) / 100.0;  // 0 to 2*PI
  }
  
  // Attach servos
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(servoPins[i]);
        servos[i].write(applyServoLimits(startupPositions[i], i));
        currentPositions[i] = startupPositions[i];
        transitionFromPositions[i] = startupPositions[i];
  }

    // Randomize initial recording selection per state (avoid bias to recording 0)
    #ifdef NUM_IDLE_RECORDINGS
    if (NUM_IDLE_RECORDINGS > 0) {
        idleRecA = random(NUM_IDLE_RECORDINGS);
        idleRecB = idleRecA;
        if (NUM_IDLE_RECORDINGS > 1) {
            do { idleRecB = random(NUM_IDLE_RECORDINGS); } while (idleRecB == idleRecA);
        }
    }
    #endif

    #ifdef NUM_ACTIVE_RECORDINGS
    if (NUM_ACTIVE_RECORDINGS > 0) {
        activeRecA = random(NUM_ACTIVE_RECORDINGS);
        activeRecB = activeRecA;
        if (NUM_ACTIVE_RECORDINGS > 1) {
            do { activeRecB = random(NUM_ACTIVE_RECORDINGS); } while (activeRecB == activeRecA);
        }
    }
    #endif

    #ifdef NUM_SLEEP_RECORDINGS
    if (NUM_SLEEP_RECORDINGS > 0) {
        sleepRecA = random(NUM_SLEEP_RECORDINGS);
        sleepRecB = sleepRecA;
        if (NUM_SLEEP_RECORDINGS > 1) {
            do { sleepRecB = random(NUM_SLEEP_RECORDINGS); } while (sleepRecB == sleepRecA);
        }
    }
    #endif

    // Schedule first crossfade at a random interval.
    nextCrossfadeTime = millis() + random(MIN_CROSSFADE_INTERVAL, MAX_CROSSFADE_INTERVAL);
    isCrossfading = false;
    crossfadeFactor = 0.0;
  
  // Initialize timing
  lastMotionTime = millis();
  stateStartTime = millis();
  transitionStartTime = millis();
  
  Serial.println("Ready - starting in IDLE state");
}

void loop() {
  // Check PIR sensor
  // Startup lockout: hold IDLE and ignore the sensor entirely until the
  // lockout expires. The read is skipped rather than the result discarded --
  // triggerMotion() stamps lastMotionTime, so merely ignoring the state change
  // would still reset the sleep timer from a settling sensor. millis() cannot
  // wrap inside the lockout, so a plain comparison is safe here.
  if (millis() < STARTUP_LOCKOUT) {
    currentState = STATE_IDLE;
    previousState = STATE_IDLE;
    stateBlendFactor = 1.0;
    lastMotionTime = 0;
    updateServos();
    delay(UPDATE_INTERVAL);
    return;
  }

  if (digitalRead(PIR_PIN) == HIGH) {
    triggerMotion();
  }

  // Update state machine
  checkStateTransitions();
  
  // Update servo positions
  updateServos();
  
  delay(UPDATE_INTERVAL);
}
'''
        
        return code
    
    def generate_markov_pir_code(self, recordings):
        """Generate Arduino code for PIR state machine with Markov segment transitions.
        recordings format: {state: [{name, layers}, ...]}
        
        MEMORY OPTIMIZATIONS:
        - Sparse transitions: Only store top-4 likely next segments per segment (8 bytes vs N bytes)
        - Reduced samples: 12 samples per segment (vs 25) - still smooth with interpolation
        - This means: segments = N * 12 * 8 = 96 bytes/segment + 8 bytes transition
        """
        import math
        
        # Memory-efficient settings
        SAMPLES_PER_SEG = 12  # Reduced from 25 - interpolation fills gaps
        TOP_K_TRANSITIONS = 6  # Store 6 most likely next segments for variety
        
        # Hardware config
        hw = self.hardware_config
        pins = hw['pin_mapping']
        reversed_servos = hw['reversed_servos']
        # Backstop only. The clamp the piece was performed with is per
        # channel, and a standalone sketch has no host to apply it.
        eff_min_str, eff_max_str = self.effective_limits_c_arrays()
        min_angle = hw.get('firmware_safe_min', 0)
        max_angle = hw.get('firmware_safe_max', 180)
        
        # Timing config
        active_duration_ms = int(self.pir_active_duration.get() * 1000)
        sleep_timeout_ms = int(self.pir_sleep_timeout.get() * 60 * 1000)
        blend_time_ms = int(self.pir_transition_time.get() * 1000)
        startup_lockout_ms = int(self.pir_startup_lockout.get() * 1000)

        # Markov config
        segment_length = self.pir_markov_segment_length.get()
        segment_length_ms = int(segment_length * 1000)
        chaos = self.pir_markov_chaos.get() / 100.0
        markov_blend_ms = int(self.pir_markov_blend_time.get() * 1000)
        # Gated on the toggle, as in the other exporters -- see the note there.
        wobble_amount = float(self.position_wobble.get()) if self.organic_enabled.get() else 0.0
        
        # Build segments for each state
        all_segments = {'idle': [], 'active': [], 'sleep': []}
        all_transitions = {'idle': [], 'active': [], 'sleep': []}  # Now sparse: [(idx, prob), ...]
        
        for state_name, rec_list in recordings.items():
            segments = []
            for rec_data in rec_list:
                layers = rec_data['layers']
                merged = self._merge_layers_to_samples(layers, sample_rate=50)
                if not merged:
                    continue
                
                samples_per_segment = int(segment_length * 50)
                num_segments = len(merged) // samples_per_segment
                
                for seg_idx in range(num_segments):
                    start_idx = seg_idx * samples_per_segment
                    end_idx = start_idx + samples_per_segment
                    segment_data = merged[start_idx:end_idx]
                    
                    if len(segment_data) >= samples_per_segment:
                        # Subsample to SAMPLES_PER_SEG samples
                        subsampled = []
                        step = max(1, len(segment_data) // SAMPLES_PER_SEG)
                        for i in range(0, len(segment_data), step):
                            if len(subsampled) < SAMPLES_PER_SEG:
                                subsampled.append(segment_data[i])
                        while len(subsampled) < SAMPLES_PER_SEG:
                            subsampled.append(segment_data[-1])
                        
                        # Randomize duration with bias toward longer (1.2-3.0s, biased toward 1.8-2.5s)
                        import random
                        random_duration = random.triangular(1.2, 3.0, 2.0)
                        
                        segments.append({
                            'data': subsampled,
                            'start': subsampled[0],
                            'end': subsampled[-1],
                            'duration': random_duration
                        })
            
            all_segments[state_name] = segments
            
            # Build SPARSE transition data (only top-K most likely transitions)
            if len(segments) > 1:
                sparse_trans = []
                for i, seg_i in enumerate(segments):
                    # Calculate probability to each other segment
                    probs = []
                    for j, seg_j in enumerate(segments):
                        if i == j:
                            prob = 5  # Small self-loop chance
                        else:
                            # Calculate similarity (smaller distance = higher prob)
                            dist = 0
                            for k in range(self.num_servos):
                                diff = seg_i['end'][k] - seg_j['start'][k]
                                dist += diff * diff
                            dist = math.sqrt(dist)
                            similarity = max(1, int(100 * (1 - dist / 200)))
                            # Mix with uniform based on chaos
                            uniform = 100 // (len(segments) - 1) if len(segments) > 1 else 100
                            prob = int((1 - chaos) * similarity + chaos * uniform)
                        probs.append((j, max(1, prob)))
                    
                    # Sort by probability and take top K
                    probs.sort(key=lambda x: x[1], reverse=True)
                    top_k = probs[:TOP_K_TRANSITIONS]
                    
                    # Normalize probabilities to sum to 255 (fit in byte)
                    total = sum(p[1] for p in top_k)
                    if total > 0:
                        top_k = [(idx, min(255, int(p * 255 / total))) for idx, p in top_k]
                    
                    sparse_trans.append(top_k)
                
                all_transitions[state_name] = sparse_trans
        
        # Calculate and display actual memory usage
        total_segs = sum(len(segs) for segs in all_segments.values())
        seg_bytes = total_segs * SAMPLES_PER_SEG * self.num_servos
        trans_bytes = total_segs * TOP_K_TRANSITIONS * 2  # idx + prob per transition
        total_data_kb = (seg_bytes + trans_bytes) / 1024
        print(f"[MARKOV EXPORT] {total_segs} segments, ~{total_data_kb:.1f}KB data")

        # Startup pose from first available segment start (prefer IDLE).
        startup_positions = [90] * self.num_servos
        for state_name in ['idle', 'active', 'sleep']:
            segs = all_segments.get(state_name, [])
            if segs:
                startup_positions = [int(round(v)) for v in segs[0]['start']]
                break
        startup_positions_str = ', '.join(str(v) for v in startup_positions)
        
        # Generate code
        code = f'''// PIR Markov State Machine - Auto-generated
// Generated: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}
// Mode: Markov Segments (learned transitions between movement chunks)
//
// Segment length: {segment_length}s, Chaos: {int(chaos*100)}%, Blend: {markov_blend_ms}ms
// idle: {len(all_segments['idle'])} segments, active: {len(all_segments['active'])} segments, sleep: {len(all_segments['sleep'])} segments
//

#include <Servo.h>

// ==================== CONFIGURATION ====================
#define PIR_PIN {self.hardware_config.get('pir_pin', 2)}
#define NUM_SERVOS {self.num_servos}
#define UPDATE_INTERVAL 20
#define SAMPLES_PER_SEGMENT {SAMPLES_PER_SEG}
#define TOP_K_TRANS {TOP_K_TRANSITIONS}

const int servoPins[NUM_SERVOS] = {{{', '.join(map(str, pins))}}};
const bool servoReversed[NUM_SERVOS] = {{{', '.join('true' if i in reversed_servos else 'false' for i in range(self.num_servos))}}};
const int startupPositions[NUM_SERVOS] = {{{startup_positions_str}}};
// SERVO_MIN/MAX are the hardware backstop; the per-channel arrays are the
// range the piece was performed with and are what playback clamps to.
const int SERVO_MIN = {min_angle};
const int SERVO_MAX = {max_angle};
const int servoMin[NUM_SERVOS] = {{{eff_min_str}}};
const int servoMax[NUM_SERVOS] = {{{eff_max_str}}};

// Timing
const unsigned long ACTIVE_DURATION = {active_duration_ms}UL;
const unsigned long SLEEP_TIMEOUT = {sleep_timeout_ms}UL;
const unsigned long STATE_BLEND_TIME = {blend_time_ms}UL;
// const unsigned long SEGMENT_DURATION = {segment_length_ms}UL;  // Now variable per segment
const unsigned long SEGMENT_BLEND_TIME = {markov_blend_ms}UL;
// Hold IDLE and ignore the sensor for this long after power-up (0 = disabled).
const unsigned long STARTUP_LOCKOUT = {startup_lockout_ms}UL;
const int MAX_STEP_PER_UPDATE = 2;  // Slew-rate limit for smoother transitions

// Organic wobble
const float WOBBLE_AMOUNT = {wobble_amount};
float phaseOffsets[NUM_SERVOS];

// ==================== SEGMENT DATA ====================
'''
        
        # Generate segment data for each state
        for state_name in ['idle', 'active', 'sleep']:
            segments = all_segments[state_name]
            state_upper = state_name.upper()
            
            if not segments:
                code += f"\n// No segments for {state_upper}\n"
                code += f"#define NUM_{state_upper}_SEGMENTS 0\n"
                continue
            
            code += f"\n// {state_upper} state: {len(segments)} segments\n"
            code += f"#define NUM_{state_upper}_SEGMENTS {len(segments)}\n"
            
            # Generate segment durations (in milliseconds)
            code += f"const PROGMEM unsigned int {state_name}Durations[NUM_{state_upper}_SEGMENTS] = {{\n  "
            # Fallback to segment_length if 'duration' key doesn't exist (old segments)
            default_duration = self.pir_markov_segment_length.get()
            duration_strs = [str(int(seg.get('duration', default_duration) * 1000)) for seg in segments]
            code += ', '.join(duration_strs)
            code += "\n};\n"
            
            # Generate segment position data (compact format)
            code += f"const PROGMEM uint8_t {state_name}Seg[NUM_{state_upper}_SEGMENTS][SAMPLES_PER_SEGMENT][NUM_SERVOS] = {{\n"
            for seg_idx, seg in enumerate(segments):
                # Compact: one segment per line
                code += "  {"
                for sample_idx, sample in enumerate(seg['data']):
                    vals = [str(int(max(0, min(180, sample[i])))) for i in range(self.num_servos)]
                    code += "{" + ','.join(vals) + "}"
                    if sample_idx < len(seg['data']) - 1:
                        code += ","
                code += "}"
                if seg_idx < len(segments) - 1:
                    code += ","
                code += "\n"
            code += "};\n"
            
            # Generate SPARSE transition data (top-4 per segment)
            transitions = all_transitions.get(state_name, [])
            if transitions:
                # Format: [seg_idx][4] = {idx0, prob0, idx1, prob1, idx2, prob2, idx3, prob3}
                code += f"const PROGMEM uint8_t {state_name}Trans[NUM_{state_upper}_SEGMENTS][{TOP_K_TRANSITIONS * 2}] = {{\n"
                for seg_trans in transitions:
                    entries = []
                    for idx, prob in seg_trans:
                        entries.extend([str(idx), str(prob)])
                    # Pad if needed
                    while len(entries) < TOP_K_TRANSITIONS * 2:
                        entries.extend(['0', '0'])
                    code += "  {" + ','.join(entries) + "},\n"
                code += "};\n"
        
        # State machine and servo code
        code += '''
// ==================== STATE MACHINE ====================
enum State { STATE_IDLE, STATE_ACTIVE, STATE_SLEEP };
const char* stateNames[] = {"IDLE", "ACTIVE", "SLEEP"};

State currentState = STATE_IDLE;
State previousState = STATE_IDLE;

unsigned long lastMotionTime = 0;
unsigned long stateStartTime = 0;
unsigned long transitionStartTime = 0;
float stateBlendFactor = 1.0;

// Markov segment tracking
int currentSegment = 0;
unsigned long segmentStartTime = 0;
int prevSegmentEndPos[NUM_SERVOS];  // End positions from previous segment
bool needsBlend = false;

// Servo positions
int currentPositions[NUM_SERVOS];
int transitionFromPositions[NUM_SERVOS];
Servo servos[NUM_SERVOS];

// ==================== HELPER FUNCTIONS ====================
int applyServoLimits(int position, int servoIdx) {
  // Degrees in, degrees out -- recorded values are already the degrees the UI
  // was showing. Clamp to THIS channel's performed range, and mirror within
  // that same range: a shared SERVO_MAX - pos only lands correctly when every
  // channel starts at 0, and otherwise reads as the reversal not taking.
  int lo = servoMin[servoIdx];
  int hi = servoMax[servoIdx];
  int pos = constrain(position, lo, hi);

  if (servoReversed[servoIdx]) {
    pos = lo + hi - pos;
  }
  return constrain(pos, SERVO_MIN, SERVO_MAX);
}

float smootherstep(float t) {
  return t * t * t * (t * (t * 6.0 - 15.0) + 10.0);
}

int getNumSegments(State state) {
  switch (state) {
    case STATE_IDLE: return NUM_IDLE_SEGMENTS;
    case STATE_ACTIVE: return NUM_ACTIVE_SEGMENTS;
    case STATE_SLEEP: return NUM_SLEEP_SEGMENTS;
    default: return 0;
  }
}

unsigned int getSegmentDuration(State state, int segmentIdx) {
  switch (state) {
    case STATE_IDLE: 
      if (segmentIdx < NUM_IDLE_SEGMENTS)
        return pgm_read_word(&idleDurations[segmentIdx]);
      break;
    case STATE_ACTIVE: 
      if (segmentIdx < NUM_ACTIVE_SEGMENTS)
        return pgm_read_word(&activeDurations[segmentIdx]);
      break;
    case STATE_SLEEP: 
      if (segmentIdx < NUM_SLEEP_SEGMENTS)
        return pgm_read_word(&sleepDurations[segmentIdx]);
      break;
  }
  return 1000; // Fallback to 1 second
}

// Pick next segment using sparse transition table (top-K most likely transitions)
int pickNextSegment(State state, int currentSeg) {
  int numSegs = getNumSegments(state);
  if (numSegs <= 1) return 0;
  
  // Get sparse transitions for this segment
  uint8_t transData[TOP_K_TRANS * 2];
  switch (state) {
'''
        
        # Add sparse transition lookup for each state
        for state_name in ['idle', 'active', 'sleep']:
            if all_segments[state_name] and all_transitions.get(state_name):
                code += f"    case STATE_{state_name.upper()}: for(int i=0;i<TOP_K_TRANS*2;i++) transData[i]=pgm_read_byte(&{state_name}Trans[currentSeg][i]); break;\n"
        
        code += '''    default: return random(numSegs);
  }
  
  // Calculate total probability and pick
  int total = 0;
  for (int i = 0; i < TOP_K_TRANS; i++) {
    total += transData[i*2 + 1];
  }
  if (total == 0) return random(numSegs);
  
  int target = random(total);
  int cumulative = 0;
  for (int i = 0; i < TOP_K_TRANS; i++) {
    cumulative += transData[i*2 + 1];
    if (target < cumulative) {
      return transData[i*2];  // Return the segment index
    }
  }
  return transData[0];  // Fallback to first option
}

void getSegmentPosition(State state, int segIdx, int sampleIdx, int* positions) {
  for (int i = 0; i < NUM_SERVOS; i++) {
    uint8_t pos;
    switch (state) {
'''
        
        for state_name in ['idle', 'active', 'sleep']:
            if all_segments[state_name]:
                code += f"      case STATE_{state_name.upper()}: pos = pgm_read_byte(&{state_name}Seg[segIdx][sampleIdx][i]); break;\n"
        
        code += '''      default: pos = 90; break;
    }
    positions[i] = pos;
  }
}

// ==================== MAIN FUNCTIONS ====================
void triggerMotion() {
  Serial.println("!!! PIR MOTION DETECTED !!!");
  lastMotionTime = millis();
  if (currentState == STATE_SLEEP) {
    startStateTransition(STATE_ACTIVE);
  } else if (currentState == STATE_IDLE) {
    startStateTransition(STATE_ACTIVE);
  }
}

void startStateTransition(State newState) {
  Serial.print(">>> STATE CHANGE: ");
  Serial.print(stateNames[currentState]);
  Serial.print(" -> ");
  Serial.println(stateNames[newState]);
  
  for (int i = 0; i < NUM_SERVOS; i++) {
    transitionFromPositions[i] = currentPositions[i];
  }
  previousState = currentState;
  currentState = newState;
  transitionStartTime = millis();
  stateBlendFactor = 0;
  
  // Reset segment to random start
  currentSegment = random(getNumSegments(newState));
  segmentStartTime = millis();
  needsBlend = false;
}

void checkStateTransitions() {
  unsigned long now = millis();
  unsigned long timeSinceMotion = now - lastMotionTime;
  
  switch (currentState) {
    case STATE_ACTIVE:
      if (timeSinceMotion >= ACTIVE_DURATION) {
        startStateTransition(STATE_IDLE);
      }
      break;
    case STATE_IDLE:
      if (timeSinceMotion >= SLEEP_TIMEOUT) {
        startStateTransition(STATE_SLEEP);
      }
      break;
    case STATE_SLEEP:
      break;
  }
  
  // Update state blend factor
  if (millis() - transitionStartTime < STATE_BLEND_TIME) {
    stateBlendFactor = smootherstep((float)(millis() - transitionStartTime) / STATE_BLEND_TIME);
  } else {
    stateBlendFactor = 1.0;
  }
}

void updateServos() {
  unsigned long now = millis();
  int numSegs = getNumSegments(currentState);
  if (numSegs == 0) return;
  
  // Time within current segment
  unsigned long segmentElapsed = now - segmentStartTime;
  unsigned int currentSegmentDuration = getSegmentDuration(currentState, currentSegment);
  
  // Check if segment is done
  if (segmentElapsed >= currentSegmentDuration) {
    // Store last sample position for blending
    int lastIdx = SAMPLES_PER_SEGMENT - 1;
    getSegmentPosition(currentState, currentSegment, lastIdx, prevSegmentEndPos);
    
    // Pick next segment
    currentSegment = pickNextSegment(currentState, currentSegment);
    segmentStartTime = now;
    needsBlend = true;
    segmentElapsed = 0;
    currentSegmentDuration = getSegmentDuration(currentState, currentSegment);
  }
  
  // Calculate position within segment WITH INTERPOLATION
  float progress = (float)segmentElapsed / currentSegmentDuration;
  float sampleFloat = progress * (SAMPLES_PER_SEGMENT - 1);
  int sampleIdx = constrain((int)sampleFloat, 0, SAMPLES_PER_SEGMENT - 2);
  float interpFactor = sampleFloat - sampleIdx;
  
  int posA[NUM_SERVOS], posB[NUM_SERVOS];
  getSegmentPosition(currentState, currentSegment, sampleIdx, posA);
  getSegmentPosition(currentState, currentSegment, sampleIdx + 1, posB);
  
  int targetPositions[NUM_SERVOS];
  for (int i = 0; i < NUM_SERVOS; i++) {
    targetPositions[i] = posA[i] + (int)((posB[i] - posA[i]) * interpFactor);
  }
  
  // Blend from previous segment if needed
  if (needsBlend && segmentElapsed < SEGMENT_BLEND_TIME) {
    float blendFactor = smootherstep((float)segmentElapsed / SEGMENT_BLEND_TIME);
    for (int i = 0; i < NUM_SERVOS; i++) {
      targetPositions[i] = prevSegmentEndPos[i] + (int)((targetPositions[i] - prevSegmentEndPos[i]) * blendFactor);
    }
  } else {
    needsBlend = false;
  }
  
    // Apply state transition blend
    int desiredPositions[NUM_SERVOS];
  if (stateBlendFactor < 1.0) {
    for (int i = 0; i < NUM_SERVOS; i++) {
            desiredPositions[i] = transitionFromPositions[i] + (int)((targetPositions[i] - transitionFromPositions[i]) * stateBlendFactor);
    }
  } else {
    for (int i = 0; i < NUM_SERVOS; i++) {
            desiredPositions[i] = targetPositions[i];
    }
  }

    // Apply slew-rate limiting to reduce twitchiness at segment/state boundaries.
    for (int i = 0; i < NUM_SERVOS; i++) {
        int delta = desiredPositions[i] - currentPositions[i];
        if (delta > MAX_STEP_PER_UPDATE) delta = MAX_STEP_PER_UPDATE;
        if (delta < -MAX_STEP_PER_UPDATE) delta = -MAX_STEP_PER_UPDATE;
        currentPositions[i] += delta;
        if (currentPositions[i] < 0) currentPositions[i] = 0;
        if (currentPositions[i] > 180) currentPositions[i] = 180;
    }

    // Keep transition source in sync while blending to avoid discontinuities.
    if (stateBlendFactor < 1.0) {
        for (int i = 0; i < NUM_SERVOS; i++) {
            transitionFromPositions[i] = currentPositions[i];
        }
    }
  
  // Apply organic wobble and write to servos
  float t = millis() / 1000.0;
  for (int i = 0; i < NUM_SERVOS; i++) {
    int finalPos = currentPositions[i];
    
    if (WOBBLE_AMOUNT > 0) {
      float phase = phaseOffsets[i];
      float breath = sin(t * 0.9 + phase) * 0.5;
      float drift = sin(t * 2.5 + phase * 1.3) * 0.3;
      float tremor = sin(t * 7.5 + phase * 2.1) * 0.2;
      finalPos += (int)((breath + drift + tremor) * WOBBLE_AMOUNT);
    }
    
    servos[i].write(applyServoLimits(finalPos, i));
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("PIR Markov State Machine Starting...");
  
  randomSeed(analogRead(0));
  pinMode(PIR_PIN, INPUT);
  
  for (int i = 0; i < NUM_SERVOS; i++) {
    phaseOffsets[i] = random(0, 628) / 100.0;
    servos[i].attach(servoPins[i]);
        servos[i].write(applyServoLimits(startupPositions[i], i));
        currentPositions[i] = startupPositions[i];
        transitionFromPositions[i] = startupPositions[i];
  }
  
  lastMotionTime = millis();
  stateStartTime = millis();
  transitionStartTime = millis();
  segmentStartTime = millis();
    int idleSegs = getNumSegments(STATE_IDLE);
    currentSegment = (idleSegs > 0) ? 0 : 0;
  needsBlend = false;
  
  Serial.println("Ready - Markov segment mode (variable durations)");
  Serial.print("Blend time: "); Serial.print(SEGMENT_BLEND_TIME); Serial.println("ms");
}

unsigned long lastDebugTime = 0;

void loop() {
  // Startup lockout: hold IDLE and do not read the sensor at all until it
  // expires, so a settling PIR cannot trigger or reset the sleep timer.
  if (millis() < STARTUP_LOCKOUT) {
    currentState = STATE_IDLE;
    lastMotionTime = 0;
    updateServos();
    return;
  }

  bool pirHigh = digitalRead(PIR_PIN) == HIGH;
  if (pirHigh) {
    triggerMotion();
  }

  checkStateTransitions();
  updateServos();

  // Debug output every 2 seconds
  if (millis() - lastDebugTime > 2000) {
    Serial.print("State:"); Serial.print(stateNames[currentState]);
    Serial.print(" Seg:"); Serial.print(currentSegment);
    Serial.print("/"); Serial.print(getNumSegments(currentState));
    Serial.print(" PIR:"); Serial.println(pirHigh  ? "HIGH" : "LOW");
    lastDebugTime = millis();
  }
  
  delay(UPDATE_INTERVAL);
}
'''
        
        return code

    # Bytes of PROGMEM the movement tables may occupy. An ATmega328 (Uno/Nano)
    # has 32256 usable after the bootloader, and the state machine, servo
    # library and serial code need their share. 18000 leaves roughly 12KB.
    PIR_DATA_BUDGET_BYTES = 18000
    PIR_MIN_SAMPLES = 24          # below this even a short take stutters
    PIR_RECORD_RATE_HZ = 50.0     # what the UI captured at; never exceed it

    def plan_pir_data(self, recordings):
        """Decide which channels to store and how many samples each take gets.

        Two things were wasting the budget. Every sample stored all ten
        channels even when only six were ever recorded, so 40% of the table
        was a constant. And every take got a flat 500 samples regardless of
        length, so a 47s idle loop was sampled at 10.7Hz while a 23s take got
        21.8Hz -- the longest take, the one running most of the time, came out
        the coarsest.

        Storing only recorded channels and then dividing the budget by
        duration fixes both: every take lands at the SAME sample rate, and
        that rate is as high as the remaining flash allows.

        Returns (channels, {key: samples}, rate_hz).
        """
        used = set()
        takes = []   # (key, duration)
        for state_name, rec_list in (recordings or {}).items():
            if not rec_list:
                continue
            for rec_idx, rec_data in enumerate(rec_list):
                layers = rec_data.get('layers', []) or []
                suffix = f"_{rec_idx}" if len(rec_list) > 1 else ""
                duration = max((l.get('duration', 0) for l in layers), default=0)
                takes.append((f"{state_name}{suffix}", max(float(duration), 0.001)))
                for layer in layers:
                    recorded = layer.get('recorded_servos') or {}
                    for finger_idx in recorded.get('fingers', []):
                        if 0 <= finger_idx < self.num_fingers:
                            used.add(int(finger_idx))
                    for arm_idx in recorded.get('arm', []):
                        ch = self.num_fingers + int(arm_idx)
                        if ch < self.num_servos:
                            used.add(ch)

        # No ownership metadata (older saves) means we cannot prove a channel
        # is unused -- store all of them rather than silently dropping motion.
        channels = sorted(used) if used else list(range(self.num_servos))

        if not takes:
            return channels, {}, 0.0

        total_duration = sum(d for _, d in takes)
        budget_samples = max(1, self.PIR_DATA_BUDGET_BYTES // max(1, len(channels)))
        rate = budget_samples / total_duration
        rate = min(rate, self.PIR_RECORD_RATE_HZ)   # no point inventing detail

        allocation = {}
        for key, duration in takes:
            n = int(round(duration * rate))
            n = max(self.PIR_MIN_SAMPLES, min(n, int(duration * self.PIR_RECORD_RATE_HZ) or 1))
            allocation[key] = n
        return channels, allocation, rate

    def _generate_state_movement_data(self, state_name, layers, min_angle, max_angle):
        """Generate the PROGMEM movement data arrays for a state."""
        
        # Merge all layers into a single timeline
        # For simplicity, we'll sample at fixed intervals and merge
        if not layers:
            return f"\n// No data for {state_name} state\n"
        
        # Sample count comes from plan_pir_data, which divides the flash budget
        # by total duration so every take lands at the same rate. The old rule
        # was a flat 500 per take regardless of length, which sampled a 47s
        # loop at 10.7Hz and a 23s one at 21.8Hz -- the longest take, running
        # most of the time, came out the coarsest.
        max_duration = max(layer['duration'] for layer in layers)
        planned = getattr(self, '_pir_sample_plan', {}) or {}
        num_samples = planned.get(state_name)
        if not num_samples:
            num_samples = min(500, int(max_duration / 0.02) + 1)
        sample_interval = max_duration / num_samples if num_samples else 0.02

        # Channels this state's layers never recorded hold the REST POSE, not a
        # hardcoded 90. 90 is outside any range narrower than it, so on a 0-60
        # rig every unrecorded channel baked as 90 and then saturated at 60 --
        # the sketch drove them hard to the top of their travel while the UI,
        # which simply never touches an unrecorded channel, left them at rest.
        # Four channels sitting 20 degrees off is exactly the kind of "different
        # somehow" that is hard to point at.
        rest = [int(round(v)) for v in self.get_startup_pose()]
        positions = [list(rest) for _ in range(num_samples)]
        
        # Debug: track if we found any actual data
        found_any_data = False
        
        # Process each layer
        for layer in layers:
            data = layer.get('data', [])
            if not data:
                print(f"  ⚠️ Layer '{layer.get('name', 'unknown')}' has no data")
                continue
            
            print(f"  📊 Processing layer '{layer.get('name', 'unknown')}' with {len(data)} frames")
            
            # Debug: check first frame structure
            if data:
                first_frame = data[0]
                print(f"     First frame keys: {list(first_frame.keys())}")
                print(f"     finger_positions: {first_frame.get('finger_positions', 'MISSING')}")
                print(f"     arm_positions: {first_frame.get('arm_positions', 'MISSING')}")
            
            for sample_idx in range(num_samples):
                t = sample_idx * sample_interval
                
                # Find the keyframes around this time
                debug_this = (sample_idx == 0)  # Debug first sample only
                pos = self._interpolate_layer_at_time(layer, t, debug_sample=debug_this)
                if debug_this and pos:
                    print(f"     Interpolated pos for t=0: {pos}")
                if pos:
                    # Merge into positions (later layers override)
                    for servo_idx, val in enumerate(pos):
                        if val is not None:
                            positions[sample_idx][servo_idx] = int(val)
                            found_any_data = True
        
        # Debug output
        if found_any_data:
            # Check a sample position
            sample_pos = positions[len(positions)//2]
            print(f"  ✅ Found data! Middle sample: {sample_pos}")
        else:
            print(f"  ❌ No actual movement data was extracted!")
        
        # Generate the PROGMEM arrays. Only the channels that were actually
        # recorded are stored -- a constant column costs the same flash as a
        # moving one, and on a Nano that flash is the thing limiting how finely
        # the takes can be sampled.
        channels = getattr(self, '_pir_active_channels', None) or list(range(self.num_servos))
        duration_ms = int(max_duration * 1000)
        rate = num_samples / max_duration if max_duration > 0 else 0.0

        code = (f"\n// {state_name.upper()} movement data: {num_samples} samples over "
                f"{max_duration:.1f}s = {rate:.1f}Hz, {len(channels)} channel(s) stored\n")
        code += f"const unsigned long {state_name}Duration = {duration_ms}UL;\n"
        code += f"const int {state_name}NumSamples = {num_samples};\n"
        code += f"const uint8_t {state_name}Data[{num_samples}][NUM_STORED_CH] PROGMEM = {{\n"

        for i, sample in enumerate(positions):
            # uint8_t storage, so clamp to 0-180 as before
            row = [max(0, min(180, int(sample[ch]))) for ch in channels]
            code += f"  {{{', '.join(map(str, row))}}}"
            if i < num_samples - 1:
                code += ","
            if i % 10 == 9:
                code += "\n"

        code += "\n};\n"

        return code
    
    def _interpolate_layer_at_time(self, layer, t, debug_sample=False):
        """Get interpolated position from a layer at time t."""
        data = layer.get('data', [])
        duration = layer.get('duration', 1.0)
        
        if not data:
            if debug_sample:
                print(f"     _interpolate: No data in layer!")
            return None
        
        # Handle looping
        if duration > 0:
            t = t % duration
        
        # Find surrounding keyframes
        prev_frame = None
        next_frame = None
        
        for frame in data:
            frame_time = frame.get('time', 0)
            if frame_time <= t:
                prev_frame = frame
            if frame_time >= t and next_frame is None:
                next_frame = frame
                break
        
        if prev_frame is None:
            prev_frame = data[0]
        if next_frame is None:
            next_frame = data[-1] if data else prev_frame
        
        if debug_sample:
            print(f"     _interpolate: t={t:.3f}, prev_time={prev_frame.get('time', 0):.3f}")
            print(f"     prev_fingers: {prev_frame.get('finger_positions', 'NONE')}")
            print(f"     prev_arm: {prev_frame.get('arm_positions', 'NONE')}")
        
        # Interpolate
        prev_time = prev_frame.get('time', 0)
        next_time = next_frame.get('time', 0)
        
        if next_time == prev_time:
            factor = 0
        else:
            factor = (t - prev_time) / (next_time - prev_time)
        
        # Get positions
        result = [None] * self.num_servos
        
        # Handle fingers (recording format uses 'finger_positions')
        prev_fingers = prev_frame.get('finger_positions', prev_frame.get('fingers', []))
        next_fingers = next_frame.get('finger_positions', next_frame.get('fingers', []))
        if prev_fingers and next_fingers:
            for i in range(min(5, len(prev_fingers), len(next_fingers))):
                prev_val = prev_fingers[i]
                next_val = next_fingers[i]
                if prev_val is not None and next_val is not None:
                    result[i] = prev_val + (next_val - prev_val) * factor
                elif prev_val is not None:
                    result[i] = prev_val
                elif next_val is not None:
                    result[i] = next_val
        
        # Handle arm (recording format uses 'arm_positions')
        prev_arm = prev_frame.get('arm_positions', prev_frame.get('arm', []))
        next_arm = next_frame.get('arm_positions', next_frame.get('arm', []))
        if prev_arm and next_arm:
            # was min(3, ...) from the 8-channel era, which silently dropped
            # arm indices 3 and 4 -- channels S8 and S9 -- during export
            for i in range(min(self.num_arm_servos, len(prev_arm), len(next_arm))):
                prev_val = prev_arm[i]
                next_val = next_arm[i]
                if prev_val is not None and next_val is not None:
                    result[5 + i] = prev_val + (next_val - prev_val) * factor
                elif prev_val is not None:
                    result[5 + i] = prev_val
                elif next_val is not None:
                    result[5 + i] = next_val
        
        return result
    
    def _generate_position_lookup_functions(self, recordings):
        """Generate the function that looks up positions for a specific recording slot.
        
        The crossfade system uses two slots (A=0, B=1) that hold indices into the
        recording arrays. This function reads positions from the recording at the
        specified slot.
        """
        
        # Generate getPositionsForRecording(state, slot, playbackTime, positions)
        # slot 0 = recA, slot 1 = recB
        code = "void getPositionsForRecording(State state, int slot, unsigned long playbackTime, int* positions) {\n"
        code += "  unsigned long duration;\n"
        code += "  int numSamples;\n"
        code += "  int sampleIdx, nextIdx;\n"
        code += "  unsigned long samplePos;\n"
        code += "  int fraction;\n"
        code += "  int recIdx;\n"
        code += "  \n"
        # Only stored channels get written below. positionsA/B are plain locals
        # in updateServos, so anything left unwritten would be stack garbage
        # blended straight into the servo output.
        code += "  for (int i = 0; i < NUM_SERVOS; i++) positions[i] = REST_POSE[i];\n"
        code += "  \n"
        code += "  // Get the recording index for this slot\n"
        code += "  switch (state) {\n"
        code += "    case STATE_IDLE:   recIdx = (slot == 0) ? idleRecA : idleRecB; break;\n"
        code += "    case STATE_ACTIVE: recIdx = (slot == 0) ? activeRecA : activeRecB; break;\n"
        code += "    case STATE_SLEEP:  recIdx = (slot == 0) ? sleepRecA : sleepRecB; break;\n"
        code += "    default: recIdx = 0; break;\n"
        code += "  }\n"
        code += "  \n"
        code += "  // Now get positions from the selected recording\n"
        code += "  switch (state) {\n"
        
        for state_name in ['idle', 'active', 'sleep']:
            if state_name not in recordings or not recordings[state_name]:
                continue
                
            rec_list = recordings[state_name]
            num_recordings = len(rec_list)
            
            code += f"    case STATE_{state_name.upper()}:\n"
            
            if num_recordings == 1:
                # Single recording - no switch needed
                code += f"      duration = {state_name}Duration;\n"
                code += f"      numSamples = {state_name}NumSamples;\n"
                code += f"      if (duration > 0) playbackTime = playbackTime % duration;\n"
                code += f"      samplePos = ((unsigned long)playbackTime * numSamples * 1000UL) / duration;\n"
                code += f"      sampleIdx = samplePos / 1000;\n"
                code += f"      if (sampleIdx >= numSamples) sampleIdx = numSamples - 1;\n"
                code += f"      nextIdx = (sampleIdx + 1) % numSamples;\n"
                code += f"      fraction = samplePos % 1000;\n"
                # Column k of the table is channel STORED_CH[k], not channel k
                code += f"      for (int k = 0; k < NUM_STORED_CH; k++) {{\n"
                code += f"        int ch = pgm_read_byte(&STORED_CH[k]);\n"
                code += f"        int curr = pgm_read_byte(&{state_name}Data[sampleIdx][k]);\n"
                code += f"        int next = pgm_read_byte(&{state_name}Data[nextIdx][k]);\n"
                code += f"        positions[ch] = curr + ((next - curr) * fraction) / 1000;\n"
                code += f"      }}\n"
            else:
                # Multiple recordings - switch on recIdx
                code += f"      switch (recIdx) {{\n"
                for rec_idx in range(num_recordings):
                    suffix = f"_{rec_idx}"
                    code += f"        case {rec_idx}:\n"
                    code += f"          duration = {state_name}{suffix}Duration;\n"
                    code += f"          numSamples = {state_name}{suffix}NumSamples;\n"
                    code += f"          if (duration > 0) playbackTime = playbackTime % duration;\n"
                    code += f"          samplePos = ((unsigned long)playbackTime * numSamples * 1000UL) / duration;\n"
                    code += f"          sampleIdx = samplePos / 1000;\n"
                    code += f"          if (sampleIdx >= numSamples) sampleIdx = numSamples - 1;\n"
                    code += f"          nextIdx = (sampleIdx + 1) % numSamples;\n"
                    code += f"          fraction = samplePos % 1000;\n"
                    code += f"          for (int k = 0; k < NUM_STORED_CH; k++) {{\n"
                    code += f"            int ch = pgm_read_byte(&STORED_CH[k]);\n"
                    code += f"            int curr = pgm_read_byte(&{state_name}{suffix}Data[sampleIdx][k]);\n"
                    code += f"            int next = pgm_read_byte(&{state_name}{suffix}Data[nextIdx][k]);\n"
                    code += f"            positions[ch] = curr + ((next - curr) * fraction) / 1000;\n"
                    code += f"          }}\n"
                    code += f"          break;\n"
                # Default to first recording
                code += f"        default:\n"
                code += f"          duration = {state_name}_0Duration;\n"
                code += f"          numSamples = {state_name}_0NumSamples;\n"
                code += f"          if (duration > 0) playbackTime = playbackTime % duration;\n"
                code += f"          samplePos = ((unsigned long)playbackTime * numSamples * 1000UL) / duration;\n"
                code += f"          sampleIdx = samplePos / 1000;\n"
                code += f"          if (sampleIdx >= numSamples) sampleIdx = numSamples - 1;\n"
                code += f"          nextIdx = (sampleIdx + 1) % numSamples;\n"
                code += f"          fraction = samplePos % 1000;\n"
                code += f"          for (int k = 0; k < NUM_STORED_CH; k++) {{\n"
                code += f"            int ch = pgm_read_byte(&STORED_CH[k]);\n"
                code += f"            int curr = pgm_read_byte(&{state_name}_0Data[sampleIdx][k]);\n"
                code += f"            int next = pgm_read_byte(&{state_name}_0Data[nextIdx][k]);\n"
                code += f"            positions[ch] = curr + ((next - curr) * fraction) / 1000;\n"
                code += f"          }}\n"
                code += f"          break;\n"
                code += f"      }}\n"
            
            code += f"      break;\n"
        
        # No data for this state: hold the rest pose. This used to write a flat
        # 90, which is outside any range narrower than it and so slammed every
        # channel to its upper stop. positions[] is already seeded above.
        code += "    default:\n"
        code += "      break;\n"
        code += "  }\n"
        code += "}\n\n"
        
        return code
    
    # ==================== END PIR METHODS ====================

    def update_playback(self):
        """Update servo positions based on ALL layers playing simultaneously.
        
        Layer priority: Later layers completely override earlier layers for the
        servos they recorded. This allows single-servo overdubs to mask wave recordings.
        
        PIR Mode: When enabled, uses state-specific recording and speed.
        """
        if not self.is_playing:
            return
        
        # Initialize crossfade layers (only used in PIR mode)
        crossfade_layers = None
        
        # Determine which layers to play and at what speed
        if self.pir_enabled.get():
            # Check if Markov mode is active
            if self.pir_markov_enabled.get() and self.pir_markov_initialized:
                # Markov segment playback
                current_time = time.time()
                positions, current_seg = self._update_markov_playback(current_time)
                
                if positions:
                    # Apply positions directly from Markov
                    for i in range(self.num_fingers):
                        self.finger_positions[i] = positions[i]
                    for i in range(self.num_arm_servos):
                        self.arm_positions[i] = positions[5 + i]
                    
                    # Apply state transition blending if needed
                    if self.pir_blend_factor < 1.0 and self.pir_transition_positions:
                        bf = self.pir_blend_factor
                        bf = bf * bf * bf * (bf * (bf * 6.0 - 15.0) + 10.0)  # Smootherstep
                        
                        for i in range(self.num_fingers):
                            old_pos = self.pir_transition_positions['fingers'][i]
                            new_pos = self.finger_positions[i]
                            self.finger_positions[i] = old_pos + (new_pos - old_pos) * bf
                        
                        for i in range(self.num_arm_servos):
                            old_pos = self.pir_transition_positions['arm'][i]
                            new_pos = self.arm_positions[i]
                            self.arm_positions[i] = old_pos + (new_pos - old_pos) * bf
                    
                    # Apply organic sine wobble if enabled
                    if self.position_wobble.get() > 0:
                        self.apply_organic_variations()
                    
                    self.update_timeline()
                    return  # Skip normal playback
            
            # Normal PIR Mode: Use state-specific recording from library
            pir_layers = self.get_pir_active_layers()
            if not pir_layers:
                return  # No recording assigned for this state
            
            # Handle crossfade between recordings (if enabled and active)
            if self.pir_is_crossfading and self.pir_crossfade_enabled.get():
                crossfade_layers = self._get_pir_crossfade_target_layers()
            
            # Use PIR state speed and loaded layers
            speed_mult = self.get_pir_playback_speed()
            layers_to_play = pir_layers
        else:
            # Normal playback: Use all layers
            if not self.recorded_layers:
                return
            
            speed_mult = self.playback_speed.get()
            layers_to_play = self.recorded_layers
        
        # Apply organic variations if in Markov mode
        if self.markov_mode:
            # Update jitter target periodically (slow changes for natural feel)
            current_time = time.time()
            if current_time - self.last_jitter_update > random.uniform(1.0, 3.0):
                jitter_pct = self.timing_jitter.get() / 100.0
                self.jitter_speed_target = 1.0 + random.uniform(-jitter_pct, jitter_pct)
                self.last_jitter_update = current_time
            # Very smoothly approach target (gradual speed changes)
            self.jitter_speed_multiplier += (self.jitter_speed_target - self.jitter_speed_multiplier) * 0.02
            speed_mult *= self.jitter_speed_multiplier
        
        elapsed = (time.time() - self.playback_start_time) * speed_mult
        
        # Get loop duration (fixed or auto)
        fixed_duration = self.loop_duration.get()
        if fixed_duration > 0:
            max_duration = fixed_duration
        else:
            # Auto mode: use longest layer
            max_duration = max(layer['duration'] for layer in layers_to_play)
        
        # Smooth loop transition - use last 10% of loop for blending
        blend_zone = max_duration * 0.1  # 10% of loop duration for smooth transition
        is_blending = elapsed >= (max_duration - blend_zone)
        
        # Loop back to start when loop duration reached
        if elapsed >= max_duration:
            self.playback_start_time = time.time()
            elapsed = 0
            is_blending = False
        
        # Calculate blend factor if we're in the transition zone
        if is_blending:
            blend_factor = (elapsed - (max_duration - blend_zone)) / blend_zone  # 0.0 to 1.0
        else:
            blend_factor = 0.0
        
        # LAYER PRIORITY: Determine which layer "owns" each servo (LAST layer wins)
        # This ensures later layers completely mask earlier ones for the same servo
        finger_owner = [None] * self.num_fingers  # layer index that owns each finger
        arm_owner = [None] * self.num_arm_servos   # layer index that owns each arm servo
        
        for layer_idx, layer in enumerate(layers_to_play):
            recorded_servos = layer.get('recorded_servos', {'fingers': set(), 'arm': set()})
            for finger_idx in recorded_servos.get('fingers', []):
                if finger_idx < self.num_fingers:
                    finger_owner[finger_idx] = layer_idx  # Later layers overwrite
            for arm_idx in recorded_servos.get('arm', []):
                if arm_idx < self.num_arm_servos:
                    arm_owner[arm_idx] = layer_idx
        
        # Channels the in-progress take is claiming are LEFT ALONE by playback.
        #
        # This is where overdubs turned to mush. Recording auto-starts playback
        # of the existing layers, and record_current_state captures whatever is
        # in finger_positions/arm_positions at that instant. So without this,
        # the old layer was writing a channel at 40Hz from update_playback while
        # the performer wrote the same channel from on_mouse_move at mouse-event
        # rate -- and the new take recorded the interleaving of the two. The
        # result read as jitter, but it was two sources fighting over one
        # channel, not noise.
        #
        # Recency wins: whatever you are performing now owns the channel, both
        # while recording it and afterwards (the owner map above is last-wins).
        claimed = self.currently_claimed_channels() if self.layer_recording else set()

        # Apply positions ONLY from the owning layer for each servo
        for layer_idx, layer in enumerate(layers_to_play):
            duration = layer['duration']
            data = layer['data']
            
            if not data or len(data) < 2:
                continue
            
            # Map current time to this layer's timeline proportionally
            # All layers loop at the same rate for perfect sync
            normalized_time = (elapsed / max_duration) * duration if max_duration > 0 else 0
            
            # Find surrounding keyframes for interpolation (smooth playback)
            start_point = data[0]  # First frame for loop blending
            prev_point = data[0]
            next_point = data[-1]
            for i, point in enumerate(data):
                if point['time'] >= normalized_time:
                    next_point = point
                    prev_point = data[max(0, i - 1)]
                    break
            
            # Calculate interpolation factor between keyframes
            time_diff = next_point['time'] - prev_point['time']
            if time_diff > 0:
                interp_factor = (normalized_time - prev_point['time']) / time_diff
                interp_factor = max(0, min(1, interp_factor))  # Clamp to 0-1
            else:
                interp_factor = 0
            
            # Apply finger positions ONLY if this layer owns the servo
            for finger_idx in range(self.num_fingers):
                if finger_idx in claimed:
                    continue  # the take being recorded owns this channel now
                if finger_owner[finger_idx] == layer_idx:
                    prev_fingers = prev_point.get('finger_positions', [])
                    next_fingers = next_point.get('finger_positions', [])
                    if finger_idx < len(prev_fingers) and finger_idx < len(next_fingers):
                        prev_val = prev_fingers[finger_idx]
                        next_val = next_fingers[finger_idx]
                        if prev_val is not None and next_val is not None:
                            # Interpolate between keyframes
                            current_pos = prev_val + (next_val - prev_val) * interp_factor
                            if is_blending:
                                start_fingers = start_point.get('finger_positions', [])
                                if finger_idx < len(start_fingers) and start_fingers[finger_idx] is not None:
                                    start_pos = start_fingers[finger_idx]
                                    current_pos = current_pos * (1 - blend_factor) + start_pos * blend_factor
                            self.finger_positions[finger_idx] = current_pos
            
            # Apply arm positions ONLY if this layer owns the servo
            for arm_idx in range(self.num_arm_servos):
                if (self.num_fingers + arm_idx) in claimed:
                    continue  # the take being recorded owns this channel now
                if arm_owner[arm_idx] == layer_idx:
                    prev_arm = prev_point.get('arm_positions', [])
                    next_arm = next_point.get('arm_positions', [])
                    if arm_idx < len(prev_arm) and arm_idx < len(next_arm):
                        prev_val = prev_arm[arm_idx]
                        next_val = next_arm[arm_idx]
                        if prev_val is not None and next_val is not None:
                            # Interpolate between keyframes
                            current_pos = prev_val + (next_val - prev_val) * interp_factor
                            if is_blending:
                                start_arm = start_point.get('arm_positions', [])
                                if arm_idx < len(start_arm) and start_arm[arm_idx] is not None:
                                    start_pos = start_arm[arm_idx]
                                    current_pos = current_pos * (1 - blend_factor) + start_pos * blend_factor
                            self.arm_positions[arm_idx] = current_pos
        
        # Apply PIR recording crossfade (smooth blend between two recordings within same state)
        if self.pir_enabled.get() and self.pir_is_crossfading and crossfade_layers:
            # Store positions from recording A (already computed above)
            positions_a_fingers = self.finger_positions[:]
            positions_a_arm = self.arm_positions[:]
            
            # Compute interpolated positions from recording B (crossfade target)
            for layer in crossfade_layers:
                duration = layer['duration']
                data = layer['data']
                if not data or len(data) < 2:
                    continue
                
                normalized_time = (elapsed / max_duration) * duration if max_duration > 0 else 0
                
                # Find surrounding keyframes for interpolation
                prev_point = data[0]
                next_point = data[-1]
                for i, point in enumerate(data):
                    if point['time'] >= normalized_time:
                        next_point = point
                        prev_point = data[max(0, i - 1)]
                        break
                
                # Calculate interpolation factor between keyframes
                time_diff = next_point['time'] - prev_point['time']
                if time_diff > 0:
                    interp_factor = (normalized_time - prev_point['time']) / time_diff
                    interp_factor = max(0, min(1, interp_factor))  # Clamp to 0-1
                else:
                    interp_factor = 0
                
                # Interpolate positions within recording B
                for finger_idx in range(self.num_fingers):
                    prev_fingers = prev_point.get('finger_positions', [])
                    next_fingers = next_point.get('finger_positions', [])
                    if finger_idx < len(prev_fingers) and finger_idx < len(next_fingers):
                        prev_val = prev_fingers[finger_idx]
                        next_val = next_fingers[finger_idx]
                        if prev_val is not None and next_val is not None:
                            # Interpolate within recording B
                            pos_b = prev_val + (next_val - prev_val) * interp_factor
                            pos_a = positions_a_fingers[finger_idx]
                            # Blend between recordings A and B
                            self.finger_positions[finger_idx] = pos_a + (pos_b - pos_a) * self.pir_rec_blend_factor
                
                for arm_idx in range(self.num_arm_servos):
                    prev_arm = prev_point.get('arm_positions', [])
                    next_arm = next_point.get('arm_positions', [])
                    if arm_idx < len(prev_arm) and arm_idx < len(next_arm):
                        prev_val = prev_arm[arm_idx]
                        next_val = next_arm[arm_idx]
                        if prev_val is not None and next_val is not None:
                            # Interpolate within recording B
                            pos_b = prev_val + (next_val - prev_val) * interp_factor
                            pos_a = positions_a_arm[arm_idx]
                            # Blend between recordings A and B
                            self.arm_positions[arm_idx] = pos_a + (pos_b - pos_a) * self.pir_rec_blend_factor
        
        # Apply PIR state transition blending (smooth fade between recordings)
        if self.pir_enabled.get() and self.pir_blend_factor < 1.0 and self.pir_transition_positions:
            # Blend from stored transition positions to current computed positions
            bf = self.pir_blend_factor  # 0.0 = old positions, 1.0 = new positions
            
            # Use smootherstep for very smooth state transitions (barely noticeable)
            bf = bf * bf * bf * (bf * (bf * 6.0 - 15.0) + 10.0)  # Ken Perlin's smootherstep
            
            for i in range(self.num_fingers):
                old_pos = self.pir_transition_positions['fingers'][i]
                new_pos = self.finger_positions[i]
                self.finger_positions[i] = old_pos + (new_pos - old_pos) * bf
            
            for i in range(self.num_arm_servos):
                old_pos = self.pir_transition_positions['arm'][i]
                new_pos = self.arm_positions[i]
                self.arm_positions[i] = old_pos + (new_pos - old_pos) * bf
        
        # Apply organic variations if in Markov mode OR PIR mode (for organic feel)
        if self.markov_mode or (self.pir_enabled.get() and self.position_wobble.get() > 0):
            self.apply_organic_variations()
    
    def apply_organic_variations(self):
        """Apply organic variations using smooth sine-based oscillation for natural movement.
        
        Uses layered sine waves at different frequencies to create organic, breathing-like motion
        instead of random jumps which cause twitchiness.
        """
        current_time = time.time()
        
        # Check for pause state (ease out of pause smoothly)
        if self.is_paused_at_keyframe:
            if current_time < self.pause_until:
                return  # Still paused
            else:
                self.is_paused_at_keyframe = False
        
        # Random chance to pause (rare, feels like hesitation)
        if current_time - getattr(self, '_last_pause_check', 0) > 2.5:  # Check less often
            self._last_pause_check = current_time
            if random.random() * 100 < self.pause_chance.get():
                pause_duration = random.uniform(0.2, 0.6)
                self.is_paused_at_keyframe = True
                self.pause_until = current_time + pause_duration
                return
        
        # Get wobble amount from UI
        wobble_amount = self.position_wobble.get()
        if wobble_amount <= 0:
            return  # No wobble requested
        
        # Initialize phase offsets once (randomized per servo for variety)
        if not hasattr(self, '_organic_phases'):
            self._organic_phases = [random.uniform(0, 2 * math.pi) for _ in range(self.num_servos)]
            self._organic_start_time = current_time
        
        # Time since organic mode started
        t = current_time - self._organic_start_time
        
        # Calculate smooth wobble for each servo using layered sine waves
        # Different frequencies create more organic, less mechanical movement
        for i in range(self.num_servos):
            phase = self._organic_phases[i]
            
            # Layer 1: Slow breathing rhythm (0.15 Hz - ~7 second cycle)
            breath = math.sin(t * 0.15 * 2 * math.pi + phase) * 0.5
            
            # Layer 2: Medium drift (0.4 Hz - ~2.5 second cycle)  
            drift = math.sin(t * 0.4 * 2 * math.pi + phase * 1.3) * 0.3
            
            # Layer 3: Subtle micro-tremor (1.2 Hz - faster, smaller)
            tremor = math.sin(t * 1.2 * 2 * math.pi + phase * 2.1) * 0.2
            
            # Combine layers and scale by wobble amount
            combined = (breath + drift + tremor) * wobble_amount
            self.wobble_offsets[i] = combined
        
        # Apply wobble offsets to positions (positions were set by update_playback first)
        for i in range(self.num_fingers):
            self.finger_positions[i] = max(0, min(180, 
                self.finger_positions[i] + self.wobble_offsets[i]))
        
        for i in range(self.num_arm_servos):
            self.arm_positions[i] = max(0, min(180, 
                self.arm_positions[i] + self.wobble_offsets[5 + i]))
    
    def set_loop_to_longest(self):
        """Set loop duration to the longest recorded layer."""
        if not self.recorded_layers:
            return
        longest = max(layer['duration'] for layer in self.recorded_layers)
        self.loop_duration.set(round(longest, 2))
        print(f"⏱️ Loop duration set to {longest:.2f}s (longest layer)")
    
    def record_current_state(self):
        """Record the current servo state."""
        if not self.layer_recording:
            return
        
        # Check if we've exceeded the loop duration constraint (if set)
        # Adjust for playback speed - if playing at 2x speed, recording should be 2x longer
        elapsed_time = time.time() - self.layer_record_start_time
        if self.loop_duration.get() > 0:
            # Divide loop duration by playback speed to get effective recording time limit
            effective_limit = self.loop_duration.get() / self.playback_speed.get()
            if elapsed_time >= effective_limit:
                print(f"⏱️ Reached time limit ({effective_limit:.2f}s at {self.playback_speed.get():.1f}x speed) - auto-stopping recording")
                self.stop_recording()
                return
        
        # Only channels this take actually claims get written. Everything
        # else stays None so the layer that performed it keeps ownership.
        claimed = self.claimable_channels()
        if self.control_mode.get() == 'cursor':
            # Cursor mode: record every channel the wave is driving, across
            # both storage groups -- a wave-driven S7 must land in the take
            # the same way a wave-driven S2 does.
            finger_positions = [None] * self.num_fingers
            arm_positions = [None] * self.num_arm_servos
            for i in range(self.num_servos):
                if i not in claimed:
                    continue
                if i < self.num_fingers:
                    finger_positions[i] = self.finger_positions[i]
                    self.recorded_servos['fingers'].add(i)
                else:
                    arm_idx = i - self.num_fingers
                    arm_positions[arm_idx] = self.arm_positions[arm_idx]
                    self.recorded_servos['arm'].add(arm_idx)
        else:
            # Manual mode: the selected servo, and only if it is armed
            finger_positions = [None] * self.num_fingers
            arm_positions = [None] * self.num_arm_servos
            selected = self.selected_servo.get()
            if selected in claimed:
                if selected < self.num_fingers:
                    finger_positions[selected] = self.finger_positions[selected]
                    self.recorded_servos['fingers'].add(selected)
                else:
                    arm_idx = selected - self.num_fingers
                    arm_positions[arm_idx] = self.arm_positions[arm_idx]
                    self.recorded_servos['arm'].add(arm_idx)
        
        point = {
            'time': time.time() - self.layer_record_start_time,
            'finger_positions': finger_positions,
            'arm_positions': arm_positions,
            'control_mode': self.control_mode.get()
        }
        
        self.current_layer_data.append(point)
    
    def clear_layers(self):
        """Clear everything that can put movement on the servos.

        This used to empty recorded_layers and nothing else, which is why old
        movement kept coming back after a Clear All. Four other stores were
        left live:

          * current_layer_data -- an in-progress capture survived the clear, so
            the next Stop committed a layer built from samples taken BEFORE it
          * layer_recording / is_playing -- the transport kept running, and
            recording carried on into the "cleared" session
          * pir_cached_recordings -- with PIR enabled, update_playback reads the
            library cache and never touches recorded_layers at all, so Clear All
            did not even interrupt it
          * recorded_servos -- a stale ownership set leaked into the next take

        Anything that survives here is movement the user cannot see the source
        of, so clear the lot."""
        n_layers = len(self.recorded_layers)
        n_cached = len(getattr(self, 'pir_cached_recordings', {}) or {})
        was_busy = self.layer_recording or self.is_playing

        if n_layers or n_cached or was_busy:
            detail = [f"{n_layers} layer(s)"]
            if n_cached:
                detail.append(f"{n_cached} cached PIR recording(s)")
            if self.layer_recording:
                detail.append("the take being recorded right now")
            if not tkinter.messagebox.askyesno(
                    "Clear all?",
                    "This discards:\n  - " + "\n  - ".join(detail)
                    + "\n\nSaved files on disk are untouched.\n\nContinue?"):
                return

        # 1. stop the transport before touching what it is reading
        self.layer_recording = False
        self.is_playing = False
        self.markov_mode = False
        self.playback_layer = None
        self.playback_index = 0
        self.playback_position = 0.0

        # 2. drop the in-progress capture
        self.current_layer_data = []
        self.recorded_servos = {'fingers': set(), 'arm': set()}

        # 3. drop committed layers and keyframes
        self.recorded_layers = []
        self.captured_keyframes = []
        self.keyframe_capture_start = None
        self.loop_duration.set(0.0)

        # 4. drop the PIR library cache -- the other thing that drives servos
        if hasattr(self, 'pir_cached_recordings'):
            self.pir_cached_recordings = {}
        self.pir_transition_positions = None
        self.pir_is_crossfading = False

        # 5. force the timeline to re-trace rather than trust its cache
        self._timeline_sig = None

        # 6. put the buttons back
        self.record_btn.configure(text="🔴 Record", fg_color=self.default_button_color)
        self.playback_btn.configure(text="▶️ Play", fg_color=self.default_button_color)
        if hasattr(self, 'rec_indicator_bg'):
            self.canvas.itemconfig(self.rec_indicator_bg, state='hidden')
            self.canvas.itemconfig(self.rec_indicator_dot, state='hidden')
            self.canvas.itemconfig(self.rec_indicator_text, state='hidden')

        self.update_layer_list()
        self.update_timeline()
        self.sync_lane_transport()
        self.on_rec_arm_changed()
        print(f"🗑️ Cleared {n_layers} layer(s), {n_cached} cached PIR recording(s), "
              f"in-progress capture, and stopped the transport")
    
    # ==================== Hardware Config Management ====================
    
    def load_hardware_config(self, filepath=None):
        """Load hardware configuration from JSON file."""
        if filepath is None:
            filepath = self.hardware_config_file
        
        try:
            if os.path.exists(filepath):
                with open(filepath, 'r') as f:
                    loaded = json.load(f)
                    # Merge with defaults (to handle missing keys in old configs)
                    for key in loaded:
                        self.hardware_config[key] = loaded[key]
                print(f"✅ Loaded hardware config: {self.hardware_config['name']}")
                return True
        except Exception as e:
            print(f"⚠️ Could not load hardware config: {e}")
        return False
    
    # Pins the two channels added in the 8 -> 10 expansion default to.
    # 3 was the old PIR input; PIR moved to 2 to free it.
    DEFAULT_NEW_PINS = [4, 3]
    LEGACY_PIR_PIN = 3

    def migrate_hardware_config(self):
        """Grow a saved 8-servo preset to 10 channels in place.

        Presets on disk predate the extra two servos, so every per-channel
        list comes back short. Pad rather than reject: a config written by
        the old build must still open, just with two more channels parked at
        safe defaults."""
        config = self.hardware_config
        total = self.num_servos

        pins = list(config.get('pin_mapping') or [])
        while len(pins) < total:
            idx = len(pins)
            # Only the two channels added by this expansion have a known
            # default pin. Anything missing below that came from a malformed
            # config; park it on 0 rather than indexing off the end.
            new_slot = idx - 8
            if 0 <= new_slot < len(self.DEFAULT_NEW_PINS):
                pins.append(self.DEFAULT_NEW_PINS[new_slot])
            else:
                pins.append(0)
        config['pin_mapping'] = pins[:total]

        limits = [list(lim) for lim in (config.get('per_servo_limits') or [])]
        while len(limits) < total:
            limits.append([0, 180])
        config['per_servo_limits'] = limits[:total]

        names = list(config.get('servo_names') or [])
        while len(names) < total:
            names.append(f'S{len(names)}')
        config['servo_names'] = names[:total]

        # PIR must not sit on a pin a servo now drives. Falling back to a fixed
        # D2 was only right while D2 happened to be free -- on a rig that moved
        # a servo onto it, the "fix" landed the sensor on another taken pin. Go
        # to the lowest genuinely free digital pin instead, and record the move
        # so the caller can tell the user rather than only the console: the
        # spinbox still reading D3 while the config says D2 is worse than the
        # collision it was avoiding.
        pir = config.get('pir_pin', 2)
        self.pir_pin_moved = None
        if pir in config['pin_mapping']:
            free = next((p for p in range(2, 20) if p not in config['pin_mapping']), None)
            if free is None:
                print(f"⚠️ PIR pin D{pir} is driven by a servo and no digital pin is free")
            else:
                print(f"⚠️ PIR pin D{pir} is driven by a servo - moving PIR to D{free}")
                self.pir_pin_moved = (pir, free)
                pir = free
        config['pir_pin'] = pir

        config.setdefault('reversed_servos', [])
        config['reversed_servos'] = [i for i in config['reversed_servos'] if i < total]

        # Presets written before the expressive range and the hardware backstop
        # were separated only have the one pair. Open the backstop to full scale
        # rather than inheriting the old value: that value was the expressive
        # range, and baking it in is exactly the coupling this split undoes.
        config.setdefault('firmware_safe_min', 0)
        config.setdefault('firmware_safe_max', 180)

        # The backstop has to contain the expressive range or it silently
        # truncates the top of every move -- and only a reflash would fix it,
        # which is the confusing kind of failure. Widen to fit and say so.
        self.safe_range_widened = None
        lo_safe, hi_safe = config['firmware_safe_min'], config['firmware_safe_max']
        lo_exp, hi_exp = config['global_min_angle'], config['global_max_angle']
        if lo_exp < lo_safe or hi_exp > hi_safe:
            new_lo, new_hi = min(lo_safe, lo_exp), max(hi_safe, hi_exp)
            print(f"⚠️ Firmware backstop {lo_safe}-{hi_safe} is narrower than the "
                  f"expressive range {lo_exp}-{hi_exp} - widening to {new_lo}-{new_hi}")
            self.safe_range_widened = (lo_safe, hi_safe, new_lo, new_hi)
            config['firmware_safe_min'], config['firmware_safe_max'] = new_lo, new_hi

    def arm_contrib(self, name, default=1.0):
        """Contribution weight for an arm channel, by label.

        The scratch-pattern helpers were written against anatomy names that
        no longer exist (and in the case of "Wrist Tilt"/"Wrist Rotate",
        never did -- the dict was always keyed by arm_names). Missing keys
        return a neutral 1.0 so those code paths degrade instead of raising."""
        var = self.arm_contributions.get(name)
        return var.get() if var is not None else default

    def refresh_servo_labels(self):
        """Rebuild the displayed channel labels from the pin map.

        Derived on every call so a rewire (changing pin_mapping) renames the
        channels immediately, instead of leaving a stale name saved in the
        preset the way the old anatomy labels did."""
        pins = self.hardware_config.get('pin_mapping') or []
        labels = []
        for i in range(self.num_servos):
            pin = pins[i] if i < len(pins) else None
            labels.append(f"S{i} (D{pin})" if pin is not None else f"S{i}")
        self.all_servo_names = labels
        self.finger_names = labels[:self.num_fingers]
        self.arm_names = labels[self.num_fingers:]
        return labels

    def save_hardware_config(self, filepath=None):
        """Save hardware configuration to JSON file."""
        if filepath is None:
            filepath = self.hardware_config_file
        
        try:
            with open(filepath, 'w') as f:
                json.dump(self.hardware_config, f, indent=2)
            print(f"💾 Saved hardware config: {self.hardware_config['name']}")
            return True
        except Exception as e:
            print(f"❌ Could not save hardware config: {e}")
            tkinter.messagebox.showerror("Save Failed", f"Could not save hardware config:\n{e}")
        return False
    
    def apply_hardware_config(self):
        """Apply current hardware config to internal variables and reconnect if needed."""
        # A config arriving from disk or the editor may still be 8 channels
        # wide, and its pin map may have moved -- grow it and re-derive the
        # labels before anything indexes by channel.
        self.migrate_hardware_config()
        self.refresh_servo_labels()

        # Update derived variables
        self.servo_limits = [tuple(lim) for lim in self.hardware_config['per_servo_limits']]
        self.servo_reversed = [i in self.hardware_config['reversed_servos'] for i in range(self.num_servos)]
        self.default_port = self.hardware_config['serial_port']
        
        # Update UI elements if they exist
        if hasattr(self, 'config_name_var'):
            self.config_name_var.set(self.hardware_config['name'])
        if hasattr(self, 'config_min_var'):
            self.config_min_var.set(self.hardware_config['global_min_angle'])
        if hasattr(self, 'config_max_var'):
            self.config_max_var.set(self.hardware_config['global_max_angle'])
        # migrate_hardware_config may have widened these to contain the
        # expressive range, so push the result back rather than the input
        if hasattr(self, 'config_safe_min_var'):
            self.config_safe_min_var.set(self.hardware_config.get('firmware_safe_min', 0))
        if hasattr(self, 'config_safe_max_var'):
            self.config_safe_max_var.set(self.hardware_config.get('firmware_safe_max', 180))
        if hasattr(self, 'config_port_var'):
            self.config_port_var.set(self.hardware_config['serial_port'])
        if hasattr(self, 'config_reversed_vars'):
            for i, var in enumerate(self.config_reversed_vars):
                var.set(i in self.hardware_config['reversed_servos'])
        
        # Update canvas display
        if hasattr(self, 'update_servo_display'):
            self.update_servo_display()
        
        print(f"🔧 Applied hardware config: {self.hardware_config['name']}")
    
    def update_config_from_ui(self):
        """Update hardware config from UI controls."""
        if hasattr(self, 'config_name_var'):
            self.hardware_config['name'] = self.config_name_var.get()
        if hasattr(self, 'config_min_var'):
            self.hardware_config['global_min_angle'] = self.config_min_var.get()
        if hasattr(self, 'config_max_var'):
            self.hardware_config['global_max_angle'] = self.config_max_var.get()
        if hasattr(self, 'config_safe_min_var'):
            try:
                self.hardware_config['firmware_safe_min'] = int(self.config_safe_min_var.get())
            except (ValueError, tk.TclError):
                pass
        if hasattr(self, 'config_safe_max_var'):
            try:
                self.hardware_config['firmware_safe_max'] = int(self.config_safe_max_var.get())
            except (ValueError, tk.TclError):
                pass
        if hasattr(self, 'config_port_var'):
            self.hardware_config['serial_port'] = self.config_port_var.get()
        if hasattr(self, 'config_reversed_vars'):
            self.hardware_config['reversed_servos'] = [
                i for i, var in enumerate(self.config_reversed_vars) if var.get()
            ]
        if hasattr(self, 'config_baud_var'):
            try:
                self.hardware_config['baud_rate'] = int(self.config_baud_var.get())
            except (ValueError, tk.TclError):
                pass  # mid-typing in the combobox; keep the last good value
        if hasattr(self, 'config_pir_pin_var'):
            try:
                self.hardware_config['pir_pin'] = int(self.config_pir_pin_var.get())
            except (ValueError, tk.TclError):
                pass
        if hasattr(self, 'config_pins_var'):
            # Only accept a COMPLETE, well-formed map. A half-typed field
            # would otherwise reshuffle every channel's pin mid-keystroke.
            try:
                parsed = [int(p) for p in self.config_pins_var.get().replace(' ', '').split(',') if p != '']
                if len(parsed) == self.num_servos:
                    self.hardware_config['pin_mapping'] = parsed
            except ValueError:
                pass

        # Apply the changes (also re-derives labels and re-checks the PIR pin)
        self.apply_hardware_config()

        # If the PIR pin collided with a servo pin it has just been moved. Push
        # the corrected value back into the spinbox and say so -- otherwise the
        # field goes on displaying a pin the sketch will never use.
        widened = getattr(self, 'safe_range_widened', None)
        if widened:
            old_lo, old_hi, new_lo, new_hi = widened
            self.safe_range_widened = None
            tkinter.messagebox.showwarning(
                "Safe Limit Widened",
                f"The expressive range does not fit inside the firmware safe "
                f"limit of {old_lo}-{old_hi}°, so the limit has been widened to "
                f"{new_lo}-{new_hi}°.\n\n"
                "The safe limit is compiled into the sketch, so regenerate the "
                "listener and reflash for this to take effect. Until you do, "
                f"the board still clamps at {old_lo}-{old_hi}°.")

        moved = getattr(self, 'pir_pin_moved', None)
        if moved and hasattr(self, 'config_pir_pin_var'):
            old, new = moved
            self.config_pir_pin_var.set(new)
            self.pir_pin_moved = None
            tkinter.messagebox.showwarning(
                "PIR Pin Moved",
                f"D{old} is driven by a servo in the current pin map, so the PIR "
                f"sensor has been moved to D{new}.\n\n"
                f"To keep the PIR on D{old}, first move that servo channel to a "
                f"different pin, then set the PIR pin again.")
    
    def export_hardware_preset(self):
        """Export current hardware config to a named preset file."""
        from tkinter import filedialog
        filepath = filedialog.asksaveasfilename(
            title="Export Hardware Preset",
            defaultextension=".json",
            filetypes=[("JSON files", "*.json"), ("All files", "*.*")],
            initialfile=f"hardware_{self.hardware_config['name'].lower().replace(' ', '_')}.json"
        )
        if filepath:
            self.update_config_from_ui()
            self.save_hardware_config(filepath)
            tkinter.messagebox.showinfo("Export Successful", 
                f"Hardware preset exported to:\n{filepath}")
    
    def import_hardware_preset(self):
        """Import hardware config from a preset file."""
        from tkinter import filedialog
        filepath = filedialog.askopenfilename(
            title="Import Hardware Preset",
            filetypes=[("JSON files", "*.json"), ("All files", "*.*")]
        )
        if filepath:
            if self.load_hardware_config(filepath):
                self.apply_hardware_config()
                tkinter.messagebox.showinfo("Import Successful", 
                    f"Loaded preset: {self.hardware_config['name']}")
    
    # ==================== Recording Save/Load ====================

    def save_recording(self):
        """Save all recorded layers to a JSON file."""
        if not self.recorded_layers:
            tkinter.messagebox.showwarning("Nothing to Save", "No recorded layers to save!")
            return
        
        timestamp = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        filename = f"hand_recording_{timestamp}.json"
        
        try:
            # Prepare data for saving (exclude non-serializable objects)
            layers_to_save = []
            for layer in self.recorded_layers:
                layer_copy = {
                    'name': layer['name'],
                    'duration': layer['duration'],
                    'control_mode': layer['control_mode'],
                    'data': layer['data'],
                    'timestamp': layer.get('timestamp', '')
                }
                # Convert recorded_servos set to list if it exists
                if 'recorded_servos' in layer:
                    layer_copy['recorded_servos'] = {
                        'fingers': list(layer['recorded_servos'].get('fingers', set())),
                        'arm': list(layer['recorded_servos'].get('arm', set()))
                    }
                layers_to_save.append(layer_copy)
            
            save_data = {
                'version': '1.0',
                'timestamp': timestamp,
                'loop_duration': self.loop_duration.get(),
                'layers': layers_to_save,
                'captured_keyframes': self.captured_keyframes
            }
            
            with open(filename, 'w') as f:
                json.dump(save_data, f, indent=2)
            
            print(f"💾 Saved {len(self.recorded_layers)} layers to {filename}")
            tkinter.messagebox.showinfo("Saved Successfully", f"Recording saved to:\n{filename}")
        except Exception as e:
            print(f"❌ Save failed: {e}")
            tkinter.messagebox.showerror("Save Failed", f"Failed to save recording:\n{e}")
    
    def load_recording(self):
        """Load recorded layers from a JSON file."""
        from tkinter import filedialog
        
        filename = filedialog.askopenfilename(
            title="Load Recording",
            filetypes=[("JSON files", "*.json"), ("All files", "*.*")],
            initialdir=os.getcwd()
        )
        
        if not filename:
            return
        
        try:
            with open(filename, 'r') as f:
                save_data = json.load(f)
            
            # Load layers and convert recorded_servos lists back to sets
            loaded_layers = save_data.get('layers', [])
            for layer in loaded_layers:
                if 'recorded_servos' in layer:
                    # Convert lists back to sets
                    layer['recorded_servos'] = {
                        'fingers': set(layer['recorded_servos'].get('fingers', [])),
                        'arm': set(layer['recorded_servos'].get('arm', []))
                    }
                else:
                    # Create default recorded_servos if missing
                    layer['recorded_servos'] = {'fingers': set(), 'arm': set()}
            
            self.recorded_layers = loaded_layers
            self.captured_keyframes = save_data.get('captured_keyframes', [])
            self.loop_duration.set(save_data.get('loop_duration', 0.0))
            
            # Update UI
            self.update_layer_list()
            
            print(f"📂 Loaded {len(self.recorded_layers)} layers from {os.path.basename(filename)}")
            tkinter.messagebox.showinfo("Loaded Successfully", 
                                       f"Loaded {len(self.recorded_layers)} layers from:\n{os.path.basename(filename)}")
        except Exception as e:
            print(f"❌ Load failed: {e}")
            tkinter.messagebox.showerror("Load Failed", f"Failed to load recording:\n{e}")
    
    def reconnect_arduino(self):
        """Reconnect to Arduino without losing recordings."""
        if not HAND_CONTROLLER_AVAILABLE:
            tkinter.messagebox.showerror("Not Available", "Hand controller module not available!")
            return
        
        # Close existing connection if any
        if self.hand_controller:
            try:
                ser = getattr(self.hand_controller, 'serial_connection', None)
                if ser and getattr(ser, 'is_open', False):
                    ser.close()
                    print("🔌 Closed existing connection")
            except Exception:
                pass
            self.hand_controller = None
            self.update_connection_status()
        
        # Try to reconnect
        try:
            self.hand_controller = HandExpressionController(
                port=self.default_port, 
                baudrate=self.hardware_config.get('baud_rate', 115200),
                clean_output=True,
                min_angle=self.hardware_config['global_min_angle'],
                max_angle=self.hardware_config['global_max_angle']
            )
            # Adopt whatever the board came up holding, then echo it back. A
            # reconnect is not a reason to move: [90]*n threw every channel to
            # 90 degrees on a rig that may not reach anywhere near that.
            self.sync_pose_from_board()
            self.hand_controller.set_hand_positions(
                list(self.finger_positions) + list(self.arm_positions))
            print(f"✅ Arduino reconnected on {self.default_port}")
            self.update_connection_status()
            tkinter.messagebox.showinfo("Connected", f"Arduino reconnected successfully on {self.default_port}!")
        except Exception as e:
            self.hand_controller = None
            self.update_connection_status()
            print(f"❌ Reconnect failed: {e}")
            tkinter.messagebox.showerror("Connection Failed", f"Failed to reconnect Arduino:\n{e}\n\nMake sure Arduino is plugged in and on {self.default_port}!")

    def disconnect_arduino(self):
        """Disconnect from Arduino and release the COM port."""
        if not self.hand_controller:
            self.update_connection_status()
            tkinter.messagebox.showinfo("Disconnected", "No active Arduino connection.")
            return

        try:
            ser = getattr(self.hand_controller, 'serial_connection', None)
            if ser and getattr(ser, 'is_open', False):
                ser.close()
                print("🔌 Arduino disconnected (COM port released)")
            self.hand_controller = None
            self.update_connection_status()
            tkinter.messagebox.showinfo("Disconnected", "Arduino disconnected. COM port released.")
        except Exception as e:
            self.hand_controller = None
            self.update_connection_status()
            print(f"❌ Disconnect failed: {e}")
            tkinter.messagebox.showerror("Disconnect Failed", f"Failed to disconnect Arduino:\n{e}")

    def update_connection_status(self):
        """Update top-right connection indicator."""
        if not hasattr(self, 'connection_label'):
            return

        ser = getattr(self.hand_controller, 'serial_connection', None) if self.hand_controller else None
        is_connected = bool(ser and getattr(ser, 'is_open', False))

        if is_connected:
            port = getattr(ser, 'port', self.default_port)
            self.connection_label.config(text=f"● Connected ({port})", fg='#00aa00')
        else:
            self.connection_label.config(text="● Disconnected", fg='#aa0000')
    
    def capture_keyframe(self):
        """Capture current servo positions as a keyframe."""
        # Start timing on first capture
        if self.keyframe_capture_start is None:
            self.keyframe_capture_start = time.time()
            timestamp = 0.0
        else:
            timestamp = time.time() - self.keyframe_capture_start
        
        # Capture current positions
        keyframe = {
            'time': timestamp,
            'finger_positions': self.finger_positions.copy(),
            'arm_positions': self.arm_positions.copy()
        }
        
        self.captured_keyframes.append(keyframe)
        
        # Print to console
        print(f"📸 Keyframe {len(self.captured_keyframes)} captured at {timestamp:.2f}s:")
        print(f"   Fingers: {[int(p) for p in self.finger_positions]}")
        print(f"   Arm: {[int(p) for p in self.arm_positions]}")
        
        # Update status
        self.record_status_label.config(
            text=f"📸 Captured {len(self.captured_keyframes)} keyframes (last at {timestamp:.2f}s)"
        )
    
    def clear_keyframes(self):
        """Clear captured keyframes without affecting layers."""
        if not self.captured_keyframes:
            print("ℹ️ No keyframes to clear")
            return
        
        count = len(self.captured_keyframes)
        self.captured_keyframes = []
        self.keyframe_capture_start = None
        print(f"🗑️ Cleared {count} keyframes")
        self.record_status_label.config(text="⚪ Ready to record (Press SPACE)")
    
    def convert_keyframes_to_layer(self):
        """Convert captured keyframes into a recorded layer."""
        if not self.captured_keyframes:
            tkinter.messagebox.showwarning("No Keyframes", "No keyframes captured yet. Use 📸 Capture to save positions.")
            return
        
        # Calculate duration from first to last keyframe
        duration = self.captured_keyframes[-1]['time']
        
        # Create layer from keyframes
        layer = {
            'name': f"Keyframe_Layer_{len(self.recorded_layers)+1}",
            'duration': duration,
            'data': self.captured_keyframes.copy(),
            'timestamp': datetime.datetime.now().isoformat(),
            'control_mode': 'keyframe',
            'recorded_servos': {
                'fingers': set(range(self.num_fingers)),
                'arm': set(range(self.num_arm_servos))
            }
        }
        
        self.recorded_layers.append(layer)
        self.update_layer_list()
        
        # Set loop duration if this is the first layer
        if len(self.recorded_layers) == 1:
            self.loop_duration.set(round(duration, 2))
            print(f"⏱️ First layer sets loop duration: {duration:.2f}s")
        
        print(f"✅ Converted {len(self.captured_keyframes)} keyframes to layer (duration: {duration:.2f}s)")
        
        # Clear keyframes after conversion
        self.captured_keyframes = []
        self.keyframe_capture_start = None
        self.record_status_label.config(text=f"✅ Keyframes converted to layer")
    
    def delete_selected_layer(self):
        """Delete the selected layer from the listbox."""
        selection = self.layer_listbox.curselection()
        if not selection:
            return  # Silent if nothing selected during double-click
        
        idx = selection[0]
        if 0 <= idx < len(self.recorded_layers):
            layer_name = self.recorded_layers[idx]['name']
            
            # Ask for confirmation
            if tkinter.messagebox.askyesno("Delete Layer", 
                                          f"Delete {layer_name}?"):
                self.recorded_layers.pop(idx)
                
                # If all layers are now deleted, reset loop duration
                if len(self.recorded_layers) == 0:
                    self.loop_duration.set(0.0)
                    print(f"🗑️ Deleted {layer_name} - loop duration reset")
                else:
                    print(f"🗑️ Deleted {layer_name}")
                
                self.update_layer_list()
    
    def update_layer_list(self):
        """Update the layer listbox display."""
        self.layer_listbox.delete(0, tk.END)
        
        if not self.recorded_layers:
            self.layer_info_label.config(text="No layers recorded")
            # Also update PIR combos
            self.update_pir_recording_combos()
            return
        
        for i, layer in enumerate(self.recorded_layers):
            duration = layer['duration']
            points = len(layer['data'])
            mode = layer['control_mode']
            
            # Show which servos were recorded
            recorded_servos = layer.get('recorded_servos', {'fingers': set(), 'arm': set()})
            servo_count = len(recorded_servos.get('fingers', [])) + len(recorded_servos.get('arm', []))
            
            display_text = f"{i+1}. {layer['name']} ({duration:.1f}s, {points} pts, {servo_count} servos, {mode})"
            self.layer_listbox.insert(tk.END, display_text)
        
        # Update info label
        total_duration = sum(layer['duration'] for layer in self.recorded_layers)
        total_points = sum(len(layer['data']) for layer in self.recorded_layers)
        self.layer_info_label.config(
            text=f"Total: {len(self.recorded_layers)} layers, {total_duration:.1f}s, {total_points} points"
        )
        
        # Update PIR state recording dropdowns
        self.update_pir_recording_combos()
    
    # Per-servo trace colours for the timeline waveforms, indexed by the
    # global servo index (0-4 fingers, 5-7 arm). Chosen to stay legible
    # against the white inset lanes of the Win98 palette.
    WAVE_COLORS = ['#000080', '#008080', '#800080', '#808000',
                   '#c05000', '#006000', '#a00040', '#405060']
    # Tall enough that several autoscaled traces in one lane stay legible;
    # at 26px they collapsed into a hairball.
    LANE_HEIGHT = 46

    def get_timeline_loop_duration(self):
        """The loop length the timeline must measure against -- the same one
        update_playback uses. These used to disagree whenever a fixed loop
        duration was set, which slid the playhead off the samples it was
        supposed to be pointing at."""
        if not self.recorded_layers:
            return 0.0
        fixed = self.loop_duration.get()
        if fixed > 0:
            return float(fixed)
        return max((layer.get('duration') or 0.0) for layer in self.recorded_layers)

    def _timeline_signature(self):
        """Cheap fingerprint of everything the CACHED traces are drawn FROM.
        While this is unchanged the tick only moves the playhead, instead of
        re-tracing every polyline at loop rate.

        The in-progress take is deliberately NOT in here -- its length changes
        every frame, so including it would invalidate the cache continuously.
        It gets its own lane, redrawn on its own each tick."""
        return (
            self.timeline_canvas.winfo_width(),
            round(self.get_timeline_loop_duration(), 3),
            bool(self.layer_recording),
            tuple(
                (layer.get('name', ''),
                 round(layer.get('duration') or 0.0, 3),
                 len(layer.get('data') or []))
                for layer in self.recorded_layers
            ),
        )

    def draw_recording_lane(self):
        """Trace the take being recorded RIGHT NOW, live.

        Drawn separately from the cached lanes and re-traced every tick, since
        it grows continuously. Decimated to one point per pixel, so the cost
        stays flat however long the pass runs."""
        canvas = self.timeline_canvas
        canvas.delete('reclane')
        if not self.layer_recording:
            return

        width = canvas.winfo_width()
        if width <= 1:
            return

        top = len(self.recorded_layers) * self.LANE_HEIGHT
        bottom = top + self.LANE_HEIGHT - 2
        canvas.create_rectangle(0, top, width, bottom, fill='#2a1520',
                                outline=self.colors['accent_red'], tags='reclane')

        data = self.current_layer_data
        elapsed = max(0.001, time.time() - self.layer_record_start_time)
        # scale to the loop if one is set, else to what has been captured
        loop = self.loop_duration.get() or 0.0
        span = loop if loop > 0 else elapsed

        for ch in range(self.num_servos):
            key, idx = (('finger_positions', ch) if ch < self.num_fingers
                        else ('arm_positions', ch - self.num_fingers))
            vals = [(p.get('time', 0.0), (p.get(key) or [None] * 5)[idx])
                    for p in data
                    if idx < len(p.get(key) or []) and (p.get(key) or [])[idx] is not None]
            if len(vals) < 2:
                continue
            lo = min(v for _, v in vals)
            hi = max(v for _, v in vals)
            rng = hi - lo
            step = max(1, len(vals) // max(1, width))
            pts = []
            for t, v in vals[::step]:
                x = min(width - 1, max(0, (t / span) * width if span else 0))
                y = ((top + bottom) / 2 if rng < 1e-6
                     else bottom - 2 - ((v - lo) / rng) * (bottom - top - 4))
                pts.extend((x, y))
            if len(pts) >= 4:
                canvas.create_line(*pts,
                                   fill=self.WAVE_COLORS[ch % len(self.WAVE_COLORS)],
                                   tags='reclane')

        # write head, so you can see where in the loop you are
        head_x = min(width - 1, (elapsed / span) * width if span else 0)
        canvas.create_line(head_x, top, head_x, bottom,
                           fill=self.colors['accent_red'], width=2, tags='reclane')
        canvas.create_text(4, top + self.LANE_HEIGHT // 2,
                           text=f"● REC  {elapsed:.1f}s / {len(data)} pts", anchor=tk.W,
                           fill='#ff8080', font=('Arial', 7, 'bold'), tags='reclane')

    def _layer_servo_indices(self, layer):
        """Global servo indices this layer actually recorded, in order."""
        recorded = layer.get('recorded_servos') or {}
        indices = [i for i in sorted(recorded.get('fingers', []) or []) if i < self.num_fingers]
        indices += [self.num_fingers + i
                    for i in sorted(recorded.get('arm', []) or [])
                    if i < self.num_arm_servos]
        return indices

    def _servo_samples(self, layer, servo_index):
        """(time, angle) pairs for one servo, skipping frames where it wasn't
        captured. Cursor mode writes None for disabled fingers, so a lane can
        legitimately be sparse."""
        if servo_index < self.num_fingers:
            key, idx = 'finger_positions', servo_index
        else:
            key, idx = 'arm_positions', servo_index - self.num_fingers

        out = []
        for point in layer.get('data') or []:
            values = point.get(key) or []
            if idx < len(values) and values[idx] is not None:
                out.append((point.get('time', 0.0), values[idx]))
        return out

    def redraw_timeline_waves(self):
        """Trace each layer as its own lane: one polyline per servo the layer
        actually recorded, each autoscaled to its own range. A layer that only
        overdubbed the elbow draws one line, not eight -- the lane never
        implies more was captured than was."""
        canvas = self.timeline_canvas
        canvas.delete('wave')

        width = canvas.winfo_width()
        if width <= 1:
            return

        if not self.recorded_layers:
            canvas.create_rectangle(0, 0, width, self.LANE_HEIGHT,
                                    fill=self.colors['bg_dark'], outline='', tags='wave')
            canvas.create_text(width // 2, self.LANE_HEIGHT // 2,
                               text='No layers recorded', fill=self.colors['canvas_bg'],
                               font=('Arial', 8), tags='wave')
            return

        loop_duration = self.get_timeline_loop_duration() or 1.0

        for i, layer in enumerate(self.recorded_layers):
            top = i * self.LANE_HEIGHT
            bottom = top + self.LANE_HEIGHT - 2

            # Inset lane, Win98 style: white field, dark top/left shadow
            canvas.create_rectangle(0, top, width, bottom,
                                    fill=self.colors['canvas_bg'],
                                    outline=self.colors['border'], tags='wave')

            duration = layer.get('duration') or 0.0
            for servo_index in self._layer_servo_indices(layer):
                samples = self._servo_samples(layer, servo_index)
                if len(samples) < 2:
                    continue

                values = [v for _, v in samples]
                low, high = min(values), max(values)
                span = high - low

                # One sample per pixel at most -- takes run to thousands of
                # frames and Tk chokes long before it draws them all
                step = max(1, len(samples) // max(1, width))
                points = []
                for sample_time, value in samples[::step]:
                    # Playback maps each layer proportionally across the whole
                    # loop (see update_playback), so the trace must stretch the
                    # same way or it won't sit under the playhead
                    fraction = (sample_time / duration) if duration > 0 else 0.0
                    x = min(width - 1, max(0, fraction * width))
                    if span < 1e-6:
                        y = (top + bottom) / 2
                    else:
                        y = bottom - 2 - ((value - low) / span) * (bottom - top - 4)
                    points.extend((x, y))

                if len(points) >= 4:
                    canvas.create_line(*points,
                                       fill=self.WAVE_COLORS[servo_index % len(self.WAVE_COLORS)],
                                       tags='wave')

            label = f"{layer.get('name', 'layer')}  ({duration:.1f}s)"
            canvas.create_text(4, top + self.LANE_HEIGHT // 2, text=label, anchor=tk.W,
                               fill=self.colors['text_dim'], font=('Arial', 7), tags='wave')

    def update_timeline(self):
        """Move the playhead, and re-trace the waveforms only when the takes
        themselves changed."""
        canvas = self.timeline_canvas
        width = canvas.winfo_width()
        if width <= 1:
            return

        signature = self._timeline_signature()
        if signature != getattr(self, '_timeline_sig', None):
            self._timeline_sig = signature
            lanes = len(self.recorded_layers) + (1 if self.layer_recording else 0)
            wanted_height = max(self.LANE_HEIGHT, lanes * self.LANE_HEIGHT)
            if int(canvas['height']) != wanted_height:
                canvas.config(height=wanted_height)
            self.redraw_timeline_waves()

        # live take: its own lane, re-traced every tick because it is growing
        self.draw_recording_lane()

        canvas.delete('playhead')
        height = int(canvas['height'])
        loop_duration = self.get_timeline_loop_duration()

        if not self.recorded_layers or not self.is_playing or loop_duration <= 0:
            return

        elapsed = (time.time() - self.playback_start_time) % loop_duration
        progress = elapsed / loop_duration
        self.playback_position = progress

        playhead_x = progress * width
        canvas.create_line(playhead_x, 0, playhead_x, height,
                           fill=self.colors['accent_red'], width=1, tags='playhead')
        canvas.create_text(width - 4, height - 2,
                           text=f"{elapsed:.1f}s / {loop_duration:.1f}s", anchor=tk.SE,
                           fill=self.colors['text_main'], font=('Arial', 7), tags='playhead')

    def set_all_rec_armed(self, on):
        for v in self.rec_armed:
            v.set(bool(on))
        self.on_rec_arm_changed()

    def on_rec_arm_changed(self):
        """Show what the next take will actually take ownership of."""
        claim = sorted(self.claimable_channels())
        if not claim:
            self.arm_hint_label.config(text="⚠ nothing armed - REC would capture nothing")
            return
        # channels an earlier layer already owns, which this take would take over
        owned = {}
        for idx, layer in enumerate(self.recorded_layers):
            for ch in self._layer_servo_indices(layer):
                owned[ch] = idx
        stealing = [c for c in claim if c in owned]
        text = "will own: " + ",".join(f"S{c}" for c in claim)
        if stealing:
            text += "   (overwrites " + ",".join(f"S{c}" for c in stealing) + ")"
        self.arm_hint_label.config(text=text)

    def sync_lane_transport(self):
        """Keep the by-the-lanes transport in step with the toolbar pair.

        Mirrored from live state rather than from the other buttons' text, so
        the two can never disagree about what the transport is doing."""
        if not hasattr(self, 'record_btn2'):
            return
        rec_on = bool(self.layer_recording)
        play_on = bool(self.is_playing)
        self.record_btn2.configure(
            text="■ Stop" if rec_on else "● REC",
            fg_color=self.colors['accent_red'] if rec_on else '#c0c0c0',
            text_color='white' if rec_on else 'black')
        self.playback_btn2.configure(
            text="■ Stop" if play_on else "▶ Play",
            fg_color=self.colors['accent_red'] if play_on else '#c0c0c0',
            text_color='white' if play_on else 'black')

        if rec_on:
            claim = sorted(self.currently_claimed_channels())
            msg = (f"recording lane {len(self.recorded_layers) + 1} -> "
                   + (",".join(f"S{c}" for c in claim) if claim else "nothing armed!"))
        elif play_on:
            msg = f"playing {len(self.recorded_layers)} layer(s)"
            if self.organic_enabled.get():
                msg += "  + organic"
        elif self.recorded_layers:
            msg = f"{len(self.recorded_layers)} layer(s)"
        else:
            msg = "no layers yet - hit REC"
        self.lane_status_label.config(text=msg)

    def update_recording_status(self):
        """Update recording status label."""
        self.sync_lane_transport()
        if self.layer_recording:
            elapsed = time.time() - self.layer_record_start_time
            points = len(self.current_layer_data)
            servos = len(self.recorded_servos.get('fingers', [])) + len(self.recorded_servos.get('arm', []))
            self.record_status_label.config(
                text=f"🔴 Recording: {elapsed:.1f}s, {points} points, {servos} servos changed",
                fg='#f44336'
            )
        elif self.is_playing:
            self.record_status_label.config(
                text=f"▶️ Playing {len(self.recorded_layers)} layers",
                fg='#4CAF50'
            )
        elif self.recorded_layers:
            self.record_status_label.config(
                text=f"⏸️ Ready - {len(self.recorded_layers)} layers recorded",
                fg=self.colors['text_main']
            )
        else:
            self.record_status_label.config(
                text="⚪ Ready to record",
                fg=self.colors['text_dim']
            )
    
    def export_arduino_code(self):
        """Export recorded layers as Arduino code."""
        if not self.recorded_layers:
            tkinter.messagebox.showwarning("No Layers", "No layers recorded yet. Record some movements first!")
            return
        
        code = self.generate_arduino_code()

        # Name it. This used to write hand_movements_<timestamp>.ino straight
        # into the working directory without asking, which is how you end up
        # with a folder full of sketches you cannot tell apart.
        filename = self.resolve_export_filename("hand_movements")
        if not filename:
            return
        filepath = os.path.join(os.getcwd(), filename)
        
        try:
            with open(filepath, 'w') as f:
                f.write(code)
            
            tkinter.messagebox.showinfo("Full-Detail Export Successful", 
                                      f"Arduino code exported to:\\n{filepath}\\n\\n" +
                                      "Mode: Full-detail simultaneous layer export (highest fidelity).\\n\\n" +
                                      f"Exported {len(self.recorded_layers)} layers with " +
                                      f"{sum(len(layer['data']) for layer in self.recorded_layers)} total movements.")
            print(f"📤 Arduino code exported to {filepath}")
            
        except Exception as e:
            tkinter.messagebox.showerror("Export Failed", f"Failed to export Arduino code:\\n{e}")
    
    def generate_arduino_code(self):
        """Generate complete Arduino code from recorded layers with SIMULTANEOUS playback.
        
        Layer priority: Later layers completely override earlier layers for the
        servos they recorded. This matches the UI playback behavior.
        """
        # Calculate keyframe counts
        total_frames = sum(len(layer['data']) for layer in self.recorded_layers)
        
        # Get current playback speed setting
        playback_speed = self.playback_speed.get()
        
        # Determine global loop duration (use loop_duration if set, otherwise max of all layers)
        if self.loop_duration.get() > 0:
            max_duration = self.loop_duration.get()
        else:
            max_duration = max(layer['duration'] for layer in self.recorded_layers) if self.recorded_layers else 0
        
        # LAYER PRIORITY: Determine which layer "owns" each servo (LAST layer wins)
        servo_owner = [-1] * self.num_servos  # layer index that owns each servo (-1 = none)
        for layer_idx, layer in enumerate(self.recorded_layers):
            recorded_servos = layer.get('recorded_servos', {'fingers': set(), 'arm': set()})
            for finger_idx in recorded_servos.get('fingers', []):
                if finger_idx < 5:
                    servo_owner[finger_idx] = layer_idx
            for arm_idx in recorded_servos.get('arm', []):
                if arm_idx < self.num_arm_servos:
                    servo_owner[5 + arm_idx] = layer_idx
        
        # Build startup pose from first recorded value for each servo owner.
        # This avoids the awkward hardcoded 90deg boot pose.
        startup_positions = [90] * self.num_servos

        # Sort each layer timeline once.
        sorted_layer_movements = []
        for layer in self.recorded_layers:
            sorted_layer_movements.append(sorted(layer['data'], key=lambda x: x['time']))

        # Nano flash guard:
        # Full-frame export can exceed 30KB quickly. We try full fidelity first,
        # then fall back to keyframes/decimation when data is too large.
        # This keeps short recordings high fidelity while making long recordings compile.
        NANO_SAFE_TOTAL_FRAMES = 900
        full_total_frames = sum(len(movements) for movements in sorted_layer_movements)
        use_compressed_export = full_total_frames > NANO_SAFE_TOTAL_FRAMES

        if use_compressed_export:
            # First compression pass: semantic keyframe extraction.
            working_layer_frames = [self._extract_keyframes(movements) for movements in sorted_layer_movements]
            compressed_total = sum(len(frames) for frames in working_layer_frames)

            # Second compression pass if still too large: uniform decimation per layer.
            if compressed_total > NANO_SAFE_TOTAL_FRAMES and compressed_total > 0:
                ratio = NANO_SAFE_TOTAL_FRAMES / compressed_total
                decimated = []
                for frames in working_layer_frames:
                    if len(frames) <= 2:
                        decimated.append(frames)
                        continue

                    keep = max(2, int(len(frames) * ratio))
                    if keep >= len(frames):
                        decimated.append(frames)
                        continue

                    step = max(1, int(math.ceil((len(frames) - 1) / (keep - 1))))
                    reduced = frames[::step]
                    if reduced[-1] != frames[-1]:
                        reduced.append(frames[-1])
                    decimated.append(reduced)
                working_layer_frames = decimated
        else:
            # Preserve full timing for shorter recordings.
            working_layer_frames = [[dict(m) for m in movements] for movements in sorted_layer_movements]

        # Extract frames for all layers WITH TIME NORMALIZATION
        all_layer_keyframes = []
        for layer, keyframes in zip(self.recorded_layers, working_layer_frames):
            
            # TIME NORMALIZE: Scale layer duration to match global loop duration
            # This ensures layers recorded at different durations sync properly.
            #
            # Playback speed MUST be divided out here as well. The generated
            # sketch compares raw millis() against these timestamps, so if the
            # speed only shrank loopDuration (as it used to) the keyframes were
            # left on the unscaled timebase and every loop reset partway
            # through -- at 1.3x, the last 23% of every layer was amputated
            # mid-gesture. Both must land on the same adjusted timebase.
            #
            # Copy first: on the compressed path _extract_keyframes appends
            # the ORIGINAL frame dicts, not copies, so scaling in place
            # rewrote the live recording. Exporting twice compounded the
            # scale factor, and everything downstream -- UI playback, the
            # timeline waveforms -- read the mangled timestamps afterwards.
            keyframes = [dict(kf) for kf in keyframes]

            # Stretch onto the loop using the span the keyframes ACTUALLY
            # cover, not the nominal recorded duration. On clean data the two
            # agree to within 0.1% so this changes nothing -- but they drift
            # apart whenever a layer's timestamps have been rescaled without
            # its duration following (which the in-place-scaling bug above
            # used to do on every export). Normalizing by a stale duration
            # left such layers ending early, and the sketch then froze them,
            # unblended, until the loop reset: a pause, then a snap.
            # The span is authoritative; the duration is not.
            if keyframes and max_duration > 0 and playback_speed > 0:
                first_time = keyframes[0]['time']
                span = keyframes[-1]['time'] - first_time
                target = max_duration / playback_speed
                if span > 0:
                    for kf in keyframes:
                        kf['time'] = (kf['time'] - first_time) / span * target
                else:
                    # single keyframe, or all stamped identically
                    for kf in keyframes:
                        kf['time'] = 0.0
            
            all_layer_keyframes.append({
                'name': layer['name'],
                'mode': layer['control_mode'],
                'duration': layer['duration'],
                'keyframes': keyframes
            })

        if use_compressed_export:
            final_total = sum(len(layer_data['keyframes']) for layer_data in all_layer_keyframes)
            print(f"[EXPORT] Nano-safe compression enabled: {full_total_frames} -> {final_total} frames")

        # Resolve startup position from the first keyframe of each owning layer.
        for servo_idx in range(self.num_servos):
            owner = servo_owner[servo_idx]
            if owner < 0 or owner >= len(all_layer_keyframes):
                continue

            owner_keyframes = all_layer_keyframes[owner]['keyframes']
            for kf in owner_keyframes:
                if servo_idx < 5:
                    pos = kf['finger_positions'][servo_idx]
                else:
                    pos = kf['arm_positions'][servo_idx - 5]
                if pos is not None:
                    startup_positions[servo_idx] = int(pos)
                    break
        
        # Adjust duration by playback speed (faster speed = shorter duration)
        adjusted_duration = max_duration / playback_speed
        
        # Build ownership comment
        ownership_info = []
        servo_names = self.finger_names + self.arm_names
        for servo_idx in range(self.num_servos):
            owner = servo_owner[servo_idx]
            if owner >= 0:
                ownership_info.append(f" * Servo {servo_idx} ({servo_names[servo_idx]}): Layer {owner + 1}")
        
        # Organic values for the sketch. The toggle is the single source of
        # truth: off means a literal 0.0 in the generated constants, so the
        # exported sketch replays exactly what the preview replayed.
        organic_on = bool(self.organic_enabled.get())
        organic_wobble = f"{float(self.position_wobble.get()):.2f}" if organic_on else "0.0"
        organic_jitter = f"{float(self.timing_jitter.get()) / 100.0:.3f}" if organic_on else "0.0"

        # Get config values for export
        # Backstop only. The clamp the piece was performed with is per
        # channel, and a standalone sketch has no host to apply it.
        eff_min_str, eff_max_str = self.effective_limits_c_arrays()
        min_angle = self.hardware_config.get('firmware_safe_min', 0)
        max_angle = self.hardware_config.get('firmware_safe_max', 180)
        reversed_servos = self.hardware_config['reversed_servos']
        pin_mapping = self.hardware_config['pin_mapping']
        
        # Build reversed servo condition for C code
        if reversed_servos:
            reversed_check = ' || '.join([f'index == {i}' for i in reversed_servos])
            reversed_names = ', '.join([self.all_servo_names[i] for i in reversed_servos if i < self.num_servos])
        else:
            reversed_check = '0'  # Never true
            reversed_names = 'none'
        
        # Build pin mapping string
        pin_str = ', '.join([str(p) for p in pin_mapping])
        startup_positions_str = ', '.join(str(p) for p in startup_positions)
        # Channel -> pin comment, derived from the config rather than the old
        # hardcoded 8-line anatomy list, which silently dropped S8/S9.
        pin_map_comment = '\n'.join(
            f" * S{i} -> D{pin_mapping[i]}" for i in range(min(self.num_servos, len(pin_mapping))))

        code = f'''/*
 * {self.num_servos}-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}
 * Hardware Config: {self.hardware_config['name']}
 * Layers: {len(self.recorded_layers)}
 * Original Frames Recorded: {total_frames}
 * Loop Duration: {max_duration:.2f}s (recorded) / {adjusted_duration:.2f}s (at {playback_speed:.1f}x speed)
 * Playback Speed: {playback_speed:.1f}x
 * 
 * Layer Priority (later layers override earlier for same servo):
{chr(10).join(ownership_info)}
 * 
 * Hardware: {self.num_fingers} group-A channels + {self.num_arm_servos} group-B channels
 * Group A: {', '.join(self.finger_names)}
 * Group B: {', '.join(self.arm_names)}
 *
 * Channel -> pin mapping:
{pin_map_comment}
 *
 * Stored positions already constrained during recording
 */

#include <Servo.h>

// Servo objects
Servo servo[{self.num_servos}];
int servoPins[{self.num_servos}] = {{{pin_str}}};

// Range configuration (from hardware preset: {self.hardware_config['name']})
const int MIN_ANGLE = {min_angle};
const int MAX_ANGLE = {max_angle};
// Per-channel performed range (per-servo limit ∩ expressive range). No host
// here to apply it, so it is compiled in.
const int servoMin[{self.num_servos}] = {{{eff_min_str}}};
const int servoMax[{self.num_servos}] = {{{eff_max_str}}};

// ---- Organic variation ----------------------------------------------------
// Mirrors the Organic panel in the UI, so the sketch breathes the same way the
// preview did. 0 values = exact replay of the recorded take.
// (Pause Chance is a live-preview control only and is not exported.)
const float WOBBLE_AMOUNT = {organic_wobble};   // degrees of drift per channel
const float TIMING_JITTER = {organic_jitter};   // fraction, e.g. 0.08 = +/-8% tempo
float phaseOffset[{self.num_servos}];
float jitterMul = 1.0;
float jitterTarget = 1.0;
unsigned long lastJitterUpdate = 0;
unsigned long organicClock = 0;   // jitter-warped playback clock
unsigned long lastTickMs = 0;

// Layered slow sines rather than random jumps -- random per-frame offsets read
// as twitch on a servo, not as life.
int applyWobble(int index, int pos) {{
  if (WOBBLE_AMOUNT <= 0.0) return pos;
  float t = millis() / 1000.0;
  float breath = sin(t * 0.7 + phaseOffset[index]);
  float drift  = sin(t * 0.23 + phaseOffset[index] * 1.7) * 0.6;
  float tremor = sin(t * 2.9 + phaseOffset[index] * 0.4) * 0.15;
  return pos + (int)((breath + drift + tremor) * WOBBLE_AMOUNT * 0.5);
}}

// Helper: clamp to the rig's range and reverse the specified channels.
// Recorded positions are already degrees, so nothing is rescaled here -- doing
// so replayed every take smaller than it was performed.
void writeServo(int index, int pos) {{
  pos = applyWobble(index, pos);
  pos = constrain(pos, servoMin[index], servoMax[index]);
  // Mirror within THIS channel's range -- a shared MAX_ANGLE - pos only lands
  // correctly when every channel starts at 0.
  if({reversed_check}) pos = servoMin[index] + servoMax[index] - pos;  // Reverse {reversed_names}
  servo[index].write(constrain(pos, MIN_ANGLE, MAX_ANGLE));
}}

// Timing
unsigned long loopStartTime;
unsigned long loopDuration = {int(adjusted_duration * 1000)}; // milliseconds (adjusted for {playback_speed:.1f}x speed)

// Startup pose (matches first recorded frame per owned servo)
const int startupPositions[{self.num_servos}] = {{{startup_positions_str}}};

// Layer data structures
'''
        
        # Generate data arrays for each layer (using PROGMEM to save RAM)
        for i, layer_data in enumerate(all_layer_keyframes):
            keyframes = layer_data['keyframes']
            
            # Find which servos this layer OWNS
            layer_owned_servos = [s for s in range(self.num_servos) if servo_owner[s] == i]
            
            # Skip layers that don't own any servos (no need to generate data)
            if not layer_owned_servos:
                code += f"\n// Layer {i+1}: {layer_data['name']} - MASKED by later layer(s)\n"
                continue
            
            code += f"\n// Layer {i+1}: {layer_data['name']} ({layer_data['mode']} mode) - {len(keyframes)} keyframes\n"
            code += f"const int layer{i+1}_count = {len(keyframes)};\n"
            code += f"const unsigned long layer{i+1}_times[] PROGMEM = {{"
            # Seconds -> ms only. Playback speed is ALREADY folded into these
            # timestamps by the normalization above, which stretches every
            # layer onto max_duration/playback_speed. Dividing again here (as
            # this line used to) applied the speed twice and left the whole
            # sequence finishing at loopDuration/speed -- the dead air and
            # snap at the end of every loop.
            code += ', '.join([str(int(kf['time'] * 1000)) for kf in keyframes])
            code += "};\n"
            
            # Generate position arrays ONLY for servos this layer OWNS
            for servo_idx in layer_owned_servos:
                # Verify the layer has data for this servo
                has_data = False
                for kf in keyframes:
                    if servo_idx < 5:  # Finger servo
                        pos = kf['finger_positions'][servo_idx]
                    else:  # Arm servo
                        pos = kf['arm_positions'][servo_idx - 5]
                    if pos is not None:
                        has_data = True
                        break
                
                if has_data:
                    servo_name = self.finger_names[servo_idx] if servo_idx < 5 else self.arm_names[servo_idx - 5]
                    code += f"const int layer{i+1}_servo{servo_idx}[] PROGMEM = {{  // {servo_name} (OWNED)\n  "
                    positions = []
                    for kf in keyframes:
                        if servo_idx < 5:  # Finger servo
                            pos = kf['finger_positions'][servo_idx]
                        else:  # Arm servo
                            pos = kf['arm_positions'][servo_idx - 5]
                        positions.append(str(int(pos)) if pos is not None else "-1")
                    code += ', '.join(positions)
                    code += "};\n"
            
            code += f"int layer{i+1}_index = 0;\n"
        
        # Setup function
        code += f'''
void setup() {{
  Serial.begin({self.hardware_config.get('baud_rate', 115200)});

  // Attach servos
  for(int i = 0; i < {self.num_servos}; i++) {{
    servo[i].attach(servoPins[i]);
        writeServo(i, startupPositions[i]);
  }}

  // Spread the wobble phases so channels never breathe in lockstep
  randomSeed(analogRead(A0));
  for (int i = 0; i < {self.num_servos}; i++) {{
    phaseOffset[i] = random(0, 628) / 100.0;   // 0..2pi
  }}

  delay(1000);
  Serial.println("{self.num_servos}-Servo Hand Control Ready - Simultaneous Playback");
  loopStartTime = millis();
  lastTickMs = millis();
}}
'''

        # plain literal from here: this block has no interpolation, so the C
        # braces stay single rather than being doubled for an f-string
        code += '''
void loop() {
  // Timing jitter: drift the playback clock slowly around 1.0x instead of
  // stepping it, so the tempo breathes rather than stutters. With
  // TIMING_JITTER = 0 this is exactly millis() - loopStartTime.
  unsigned long nowMs = millis();
  unsigned long deltaMs = nowMs - lastTickMs;
  lastTickMs = nowMs;

  if (TIMING_JITTER > 0.0) {
    if (nowMs - lastJitterUpdate > 1500) {
      jitterTarget = 1.0 + (random(-1000, 1000) / 1000.0) * TIMING_JITTER;
      lastJitterUpdate = nowMs;
    }
    jitterMul += (jitterTarget - jitterMul) * 0.02;   // ease, never jump
  } else {
    jitterMul = 1.0;
  }

  organicClock += (unsigned long)(deltaMs * jitterMul);
  unsigned long elapsed = organicClock;

  // Smooth loop blending - last 10% of loop blends back to start
  unsigned long blendZone = loopDuration / 10;  // 10% blend zone
  bool isBlending = elapsed >= (loopDuration - blendZone);
  float blendFactor = 0.0;
  
  if(isBlending) {
    blendFactor = (float)(elapsed - (loopDuration - blendZone)) / (float)blendZone;
    blendFactor = constrain(blendFactor, 0.0, 1.0);
  }
  
  // Loop the sequence
  if(elapsed >= loopDuration) {
    loopStartTime = millis();
    organicClock = 0;   // the jitter-warped clock is the one being compared
    elapsed = 0;
'''
        
        # Reset layer indices - ONLY for layers that OWN servos (others don't have index vars)
        for i in range(len(all_layer_keyframes)):
            # Check if this layer owns any servos
            layer_owned_servos = [s for s in range(self.num_servos) if servo_owner[s] == i]
            if layer_owned_servos:
                code += f"    layer{i+1}_index = 0;\n"
        
        code += "  }\n\n"
        
        # Update each layer - ONLY for servos this layer OWNS
        for i in range(len(all_layer_keyframes)):
            layer_keyframes = all_layer_keyframes[i]['keyframes']
            
            # Only include servos that this layer OWNS (last layer to record wins)
            owned_servos = []
            for servo_idx in range(self.num_servos):
                # Check if this layer owns this servo
                if servo_owner[servo_idx] != i:
                    continue
                # Also verify the layer has data for it
                has_data = False
                for kf in layer_keyframes:
                    if servo_idx < 5:
                        pos = kf['finger_positions'][servo_idx]
                    else:
                        pos = kf['arm_positions'][servo_idx - 5]
                    if pos is not None:
                        has_data = True
                        break
                if has_data:
                    owned_servos.append(servo_idx)
            
            # Skip layer entirely if it doesn't own any servos
            if not owned_servos:
                continue
            
            code += f'''  // Update layer {i+1} with interpolation (OWNS: {', '.join([self.finger_names[s] if s < 5 else self.arm_names[s-5] for s in owned_servos])})
  {{
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer{i+1}_index < layer{i+1}_count - 1 &&
          elapsed >= pgm_read_dword(&layer{i+1}_times[layer{i+1}_index + 1])) {{
      layer{i+1}_index++;
    }}

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer{i+1}_index >= layer{i+1}_count - 1);
    float factor = 0.0;
    if(!atEnd) {{
      unsigned long currentTime = pgm_read_dword(&layer{i+1}_times[layer{i+1}_index]);
      unsigned long nextTime = pgm_read_dword(&layer{i+1}_times[layer{i+1}_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {{
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }}
    }}
    {{
'''
            for servo_idx in owned_servos:
                servo_name = self.finger_names[servo_idx] if servo_idx < 5 else self.arm_names[servo_idx - 5]
                code += f"      // Interpolate {servo_name}\n"
                code += f"      int curr{servo_idx} = pgm_read_word(&layer{i+1}_servo{servo_idx}[layer{i+1}_index]);\n"
                code += f"      // reading [index + 1] past the end would run off the array\n"
                code += f"      int next{servo_idx} = atEnd ? curr{servo_idx}\n"
                code += f"                  : (int)pgm_read_word(&layer{i+1}_servo{servo_idx}[layer{i+1}_index + 1]);\n"
                code += f"      int start{servo_idx} = pgm_read_word(&layer{i+1}_servo{servo_idx}[0]);\n"
                code += f"      \n"
                code += f"      if(curr{servo_idx} != -1) {{\n"
                code += f"        int pos = (next{servo_idx} != -1)\n"
                code += f"                ? curr{servo_idx} + (int)((next{servo_idx} - curr{servo_idx}) * factor)\n"
                code += f"                : curr{servo_idx};\n"
                code += f"        \n"
                code += f"        // Apply blend zone for smooth looping -- runs even once this\n"
                code += f"        // layer is out of keyframes, so it eases home instead of snapping\n"
                code += f"        if(isBlending && start{servo_idx} != -1) {{\n"
                code += f"          pos = pos * (1.0 - blendFactor) + start{servo_idx} * blendFactor;\n"
                code += f"        }}\n"
                code += f"        \n"
                code += f"        writeServo({servo_idx}, pos);\n"
                code += f"      }}\n"
            
            code += "    }\n  }\n\n"
        
        code += "  delay(5); // 200Hz update rate for smooth interpolation\n}\n"
        
        return code
    
    def export_markov_arduino(self):
        """Export Arduino code with Markov chain phrase transitions and PIR sensor support."""
        if not self.recorded_layers:
            tkinter.messagebox.showwarning("No Layers", "No layers recorded yet. Record some movements first!")
            return
        
        # Create configuration dialog
        dialog = tk.Toplevel(self.root)
        dialog.title("Multi-Phrase Export Configuration")
        dialog.geometry("500x400")
        dialog.configure(bg=self.colors['bg_main'])
        dialog.transient(self.root)
        dialog.grab_set()
        
        # PIR Sensor settings
        pir_frame = tk.LabelFrame(dialog, text="PIR Motion Sensor", 
                                 bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        pir_frame.pack(fill=tk.X, padx=10, pady=10)
        
        tk.Label(pir_frame, text="Enable PIR Sensor:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main']).grid(row=0, column=0, sticky=tk.W, padx=5, pady=5)
        pir_enable = tk.BooleanVar(value=True)
        tk.Checkbutton(pir_frame, variable=pir_enable, bg=self.colors['bg_frame']).grid(row=0, column=1, sticky=tk.W, padx=5, pady=5)
        
        tk.Label(pir_frame, text="PIR Pin:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main']).grid(row=1, column=0, sticky=tk.W, padx=5, pady=5)
        # default from the saved config, not a literal -- 3 now drives S9
        pir_pin = tk.IntVar(value=self.hardware_config.get('pir_pin', 2))
        tk.Spinbox(pir_frame, from_=2, to=13, textvariable=pir_pin, width=10).grid(row=1, column=1, sticky=tk.W, padx=5, pady=5)
        
        tk.Label(pir_frame, text="Motion Timeout (seconds):", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main']).grid(row=2, column=0, sticky=tk.W, padx=5, pady=5)
        motion_timeout = tk.IntVar(value=5)
        tk.Spinbox(pir_frame, from_=1, to=60, textvariable=motion_timeout, width=10).grid(row=2, column=1, sticky=tk.W, padx=5, pady=5)
        
        # Phrase library settings
        phrase_frame = tk.LabelFrame(dialog, text="Phrase Library", 
                                     bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        phrase_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)
        
        tk.Label(phrase_frame, text="Current recording will be exported as 1 phrase.\nLoad more .json recordings to add phrases:", 
                bg=self.colors['bg_frame'], fg=self.colors['text_main'], justify=tk.LEFT).pack(pady=5)
        
        phrase_listbox = tk.Listbox(phrase_frame, height=6, bg=self.colors['bg_dark'], fg=self.colors['text_main'])
        phrase_listbox.pack(fill=tk.BOTH, expand=True, padx=5, pady=5)
        phrase_listbox.insert(tk.END, "Phrase 1: Current Recording")
        
        phrase_files = []
        
        def add_phrase():
            filename = tkinter.filedialog.askopenfilename(
                title="Load Additional Phrase",
                filetypes=[("JSON files", "*.json"), ("All files", "*.*")]
            )
            if filename:
                phrase_files.append(filename)
                phrase_listbox.insert(tk.END, f"Phrase {len(phrase_files) + 1}: {os.path.basename(filename)}")
        
        ctk.CTkButton(phrase_frame, text="➕ Add Phrase from File", command=add_phrase,
                 font=('Arial', 11), width=160).pack(pady=5)
        
        # Export button
        def do_export():
            dialog.destroy()
            code = self.generate_markov_arduino_code(
                pir_enabled=pir_enable.get(),
                pir_pin=pir_pin.get(),
                motion_timeout=motion_timeout.get(),
                additional_phrase_files=phrase_files
            )
            
            # Save to file
            filename = f"hand_markov_{datetime.datetime.now().strftime('%Y%m%d_%H%M%S')}.ino"
            filepath = os.path.join(os.getcwd(), filename)
            
            try:
                with open(filepath, 'w') as f:
                    f.write(code)
                
                tkinter.messagebox.showinfo("Multi-Phrase Export Successful", 
                                          f"Arduino code with multi-phrase transitions exported to:\n{filepath}\n\n" +
                                          f"Phrases: {len(phrase_files) + 1}\n" +
                                          f"PIR Sensor: {'Enabled' if pir_enable.get() else 'Disabled'}")
                print(f"📦 Multi-phrase Arduino code exported to {filepath}")
                
            except Exception as e:
                tkinter.messagebox.showerror("Export Failed", f"Failed to export Arduino code:\n{e}")
        
        button_frame = tk.Frame(dialog, bg=self.colors['bg_main'])
        button_frame.pack(fill=tk.X, padx=10, pady=10)
        
        ctk.CTkButton(button_frame, text="✅ Export", command=do_export,
                 font=('Arial', 12, 'bold'), width=100).pack(side=tk.LEFT, padx=5)
        ctk.CTkButton(button_frame, text="❌ Cancel", command=dialog.destroy,
                 font=('Arial', 11), width=80).pack(side=tk.LEFT, padx=5)
    
    def generate_markov_arduino_code(self, pir_enabled=True, pir_pin=2, motion_timeout=5, additional_phrase_files=None):
        """Generate Arduino code with Markov chain transitions between phrases."""
        if additional_phrase_files is None:
            additional_phrase_files = []
        
        # Collect all phrases (current recording + loaded files)
        phrases = []
        
        # Add current recording as first phrase
        phrases.append({
            'name': 'Current Recording',
            'layers': self.recorded_layers,
            'loop_duration': self.loop_duration.get() if self.loop_duration.get() > 0 else max(layer['duration'] for layer in self.recorded_layers)
        })
        
        # Load additional phrases from files
        for filepath in additional_phrase_files:
            try:
                with open(filepath, 'r') as f:
                    save_data = json.load(f)
                    loaded_layers = save_data.get('layers', [])
                    # Convert recorded_servos lists back to sets
                    for layer in loaded_layers:
                        if 'recorded_servos' in layer:
                            layer['recorded_servos'] = {
                                'fingers': set(layer['recorded_servos'].get('fingers', [])),
                                'arm': set(layer['recorded_servos'].get('arm', []))
                            }
                    phrases.append({
                        'name': os.path.basename(filepath),
                        'layers': loaded_layers,
                        'loop_duration': save_data.get('loop_duration', max(layer['duration'] for layer in loaded_layers) if loaded_layers else 1.0)
                    })
            except Exception as e:
                print(f"❌ Failed to load phrase from {filepath}: {e}")
        
        num_phrases = len(phrases)

        # Startup pose for Markov export: match first phrase's first recorded pose
        # (per servo ownership, last layer wins) instead of forcing center 90deg.
        startup_positions = [90] * self.num_servos
        if phrases:
            first_phrase_layers = phrases[0].get('layers', [])
            startup_owner = [-1] * self.num_servos
            for layer_idx, layer in enumerate(first_phrase_layers):
                recorded_servos = layer.get('recorded_servos', {'fingers': set(), 'arm': set()})
                for finger_idx in recorded_servos.get('fingers', []):
                    if finger_idx < 5:
                        startup_owner[finger_idx] = layer_idx
                for arm_idx in recorded_servos.get('arm', []):
                    if arm_idx < self.num_arm_servos:
                        startup_owner[5 + arm_idx] = layer_idx

            for servo_idx in range(self.num_servos):
                owner = startup_owner[servo_idx]
                if owner < 0 or owner >= len(first_phrase_layers):
                    continue
                layer_data = sorted(first_phrase_layers[owner].get('data', []), key=lambda x: x['time'])
                for movement in layer_data:
                    if servo_idx < 5:
                        pos = movement['finger_positions'][servo_idx]
                    else:
                        pos = movement['arm_positions'][servo_idx - 5]
                    if pos is not None:
                        startup_positions[servo_idx] = int(pos)
                        break
        
        # Build simple uniform transition matrix (each phrase can transition to any other with equal probability)
        # In the future, this could analyze temporal patterns to build smarter transitions
        
        # Get config values for export
        # Backstop only. The clamp the piece was performed with is per
        # channel, and a standalone sketch has no host to apply it.
        eff_min_str, eff_max_str = self.effective_limits_c_arrays()
        min_angle = self.hardware_config.get('firmware_safe_min', 0)
        max_angle = self.hardware_config.get('firmware_safe_max', 180)
        reversed_servos = self.hardware_config['reversed_servos']
        pin_mapping = self.hardware_config['pin_mapping']
        
        # Build reversed servo condition for C code
        if reversed_servos:
            reversed_check = ' || '.join([f'index == {i}' for i in reversed_servos])
            reversed_names = ', '.join([self.all_servo_names[i] for i in reversed_servos if i < self.num_servos])
        else:
            reversed_check = '0'
            reversed_names = 'none'
        
        # Build pin mapping string
        pin_str = ', '.join([str(p) for p in pin_mapping])
        startup_positions_str = ', '.join(str(p) for p in startup_positions)
        pin_map_comment = '\n'.join(
            f" * S{i} -> D{pin_mapping[i]}" for i in range(min(self.num_servos, len(pin_mapping))))

        code = f'''/*
 * {self.num_servos}-Servo Hand Control - Markov Chain Phrase System
 * Generated: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}
 * Hardware Config: {self.hardware_config['name']}
 * Phrases: {num_phrases}
 * PIR Sensor: {"Enabled on pin " + str(pir_pin) if pir_enabled else "Disabled"}
 * 
 * This sketch uses Markov chains to randomly transition between
 * recorded movement phrases, creating organic, non-repetitive behavior.
 * 
 * Hardware: {self.num_fingers} group-A channels + {self.num_arm_servos} group-B channels
 *
 * Channel -> pin mapping:
{pin_map_comment}
 *
 * Stored positions already constrained during recording
 */

#include <Servo.h>

// Servo objects
Servo servo[{self.num_servos}];
int servoPins[{self.num_servos}] = {{{pin_str}}};

// Startup pose (matches first phrase's first recorded frame)
const int startupPositions[{self.num_servos}] = {{{startup_positions_str}}};

// Range configuration (from hardware preset: {self.hardware_config['name']})
const int MIN_ANGLE = {min_angle};
const int MAX_ANGLE = {max_angle};
// Per-channel performed range (per-servo limit ∩ expressive range). No host
// here to apply it, so it is compiled in.
const int servoMin[{self.num_servos}] = {{{eff_min_str}}};
const int servoMax[{self.num_servos}] = {{{eff_max_str}}};

// Helper: clamp to the rig's range and reverse the specified channels.
// Recorded positions are already degrees -- the range clamps, it does not scale.
void writeServo(int index, int pos) {{
  pos = constrain(pos, servoMin[index], servoMax[index]);
  // Mirror within THIS channel's range, not a shared one.
  if({reversed_check}) pos = servoMin[index] + servoMax[index] - pos;  // Reverse {reversed_names}
  servo[index].write(constrain(pos, MIN_ANGLE, MAX_ANGLE));
}}

// PIR Motion Sensor
'''
        
        if pir_enabled:
            code += f'''const int PIR_PIN = {pir_pin};
const unsigned long MOTION_TIMEOUT = {motion_timeout * 1000}; // milliseconds
bool motionDetected = false;
unsigned long lastMotionTime = 0;
'''
        
        code += f'''
// Phrase system
const int NUM_PHRASES = {num_phrases};
int currentPhrase = 0;
unsigned long phraseStartTime = 0;

// Transition probability matrix (stored as percentages 0-100)
// Each row represents probabilities of transitioning FROM that phrase TO others
const uint8_t transitionMatrix[NUM_PHRASES][NUM_PHRASES] PROGMEM = {{
'''
        
        # Generate uniform transition matrix (equal probability to all other phrases)
        for i in range(num_phrases):
            code += "  {"
            probs = []
            for j in range(num_phrases):
                if i == j:
                    probs.append("10")  # 10% chance to repeat same phrase
                else:
                    # Equal probability for other phrases
                    prob = int(90 / (num_phrases - 1)) if num_phrases > 1 else 0
                    probs.append(str(prob))
            code += ", ".join(probs)
            code += "}," if i < num_phrases - 1 else "}"
            code += f" // From Phrase {i}\n"
        
        code += "};\n\n"
        
        # Generate keyframe data for each phrase
        for phrase_idx, phrase in enumerate(phrases):
            code += f"// ===== PHRASE {phrase_idx}: {phrase['name']} =====\n"
            
            max_duration = phrase['loop_duration']
            
            # LAYER PRIORITY for this phrase: Determine servo ownership (last layer wins)
            phrase_servo_owner = [-1] * self.num_servos
            for layer_idx, layer in enumerate(phrase['layers']):
                recorded_servos = layer.get('recorded_servos', {'fingers': set(), 'arm': set()})
                for finger_idx in recorded_servos.get('fingers', []):
                    if finger_idx < 5:
                        phrase_servo_owner[finger_idx] = layer_idx
                for arm_idx in recorded_servos.get('arm', []):
                    if arm_idx < self.num_arm_servos:
                        phrase_servo_owner[5 + arm_idx] = layer_idx
            
            # Extract keyframes for all layers WITH TIME NORMALIZATION
            all_layer_keyframes = []
            for layer in phrase['layers']:
                movements = sorted(layer['data'], key=lambda x: x['time'])
                # copy: _extract_keyframes hands back the original frame dicts,
                # and the normalize below rewrites 'time' in place
                keyframes = [dict(kf) for kf in self._extract_keyframes(movements)]

                # TIME NORMALIZE
                layer_duration = layer['duration']
                if layer_duration > 0 and max_duration > 0:
                    time_scale = max_duration / layer_duration
                    for kf in keyframes:
                        kf['time'] = kf['time'] * time_scale
                
                all_layer_keyframes.append({
                    'name': layer['name'],
                    'keyframes': keyframes
                })
            
            code += f"const unsigned long phrase{phrase_idx}_duration = {int(max_duration * 1000)};\n"
            
            # Store ownership info for playback code generation
            phrase['servo_owner'] = phrase_servo_owner
            phrase['layer_keyframes'] = all_layer_keyframes
            
            # Generate layer data structures - ONLY for layers that OWN servos
            active_layers = []
            for layer_idx, layer_data in enumerate(all_layer_keyframes):
                keyframes = layer_data['keyframes']
                
                # Find which servos this layer OWNS
                owned_servos = [s for s in range(self.num_servos) if phrase_servo_owner[s] == layer_idx]
                
                if not owned_servos:
                    code += f"// Layer {layer_idx}: {layer_data['name']} - MASKED by later layer(s)\n"
                    continue
                
                active_layers.append(layer_idx)
                
                code += f"const int phrase{phrase_idx}_layer{layer_idx}_count = {len(keyframes)};\n"
                code += f"const unsigned long phrase{phrase_idx}_layer{layer_idx}_times[] PROGMEM = {{"
                code += ', '.join([str(int(kf['time'] * 1000)) for kf in keyframes])
                code += "};\n"
                
                # Generate position arrays ONLY for servos this layer OWNS
                for servo_idx in owned_servos:
                    has_data = False
                    for kf in keyframes:
                        if servo_idx < 5:
                            pos = kf['finger_positions'][servo_idx]
                        else:
                            pos = kf['arm_positions'][servo_idx - 5]
                        if pos is not None:
                            has_data = True
                            break
                    
                    if has_data:
                        code += f"const int phrase{phrase_idx}_layer{layer_idx}_servo{servo_idx}[] PROGMEM = {{"
                        positions = []
                        for kf in keyframes:
                            if servo_idx < 5:
                                pos = kf['finger_positions'][servo_idx]
                            else:
                                pos = kf['arm_positions'][servo_idx - 5]
                            positions.append(str(int(pos)) if pos is not None else "-1")
                        code += ', '.join(positions)
                        code += "};\n"
            
            phrase['active_layers'] = active_layers
            num_active = len(active_layers) if active_layers else 1
            code += f"int phrase{phrase_idx}_layer_indices[{num_active}];\n\n"
        
        # Setup function
        code += f'''void setup() {{
  Serial.begin({self.hardware_config.get('baud_rate', 115200)});

  // Attach servos
  for(int i = 0; i < {self.num_servos}; i++) {{
    servo[i].attach(servoPins[i]);
        writeServo(i, startupPositions[i]);
  }}

'''
        
        if pir_enabled:
            code += f'''  // Setup PIR sensor
  pinMode(PIR_PIN, INPUT);
  Serial.println("PIR Motion Sensor enabled on pin {pir_pin}");
  
'''
        
        code += '''  delay(1000);
  randomSeed(analogRead(A0)); // Seed random from floating analog pin
  Serial.println("Markov Chain Hand Control Ready");
  Serial.print("Phrases loaded: ");
  Serial.println(NUM_PHRASES);
  
  phraseStartTime = millis();
}

'''
        
        # Helper function to select next phrase based on Markov probabilities
        code += '''int selectNextPhrase(int currentPhrase) {
  // Read transition probabilities for current phrase from PROGMEM
  int randVal = random(100); // 0-99
  int cumulative = 0;
  
  for(int i = 0; i < NUM_PHRASES; i++) {
    cumulative += pgm_read_byte(&transitionMatrix[currentPhrase][i]);
    if(randVal < cumulative) {
      return i;
    }
  }
  
  return 0; // Fallback
}

'''
        
        # Main loop with phrase playback and transitions
        code += '''void loop() {
'''
        
        if pir_enabled:
            code += f'''  // Check PIR sensor
  if(digitalRead(PIR_PIN) == HIGH) {{
    motionDetected = true;
    lastMotionTime = millis();
  }}

  // Check motion timeout
  if(motionDetected && (millis() - lastMotionTime > MOTION_TIMEOUT)) {{
    motionDetected = false;
    Serial.println("No motion detected - pausing");
    // Return to center position
    for(int i = 0; i < {self.num_servos}; i++) {{
      writeServo(i, 90);
    }}
    delay(100);
    return;
  }}
  
  // Only play phrases if motion detected
  if(!motionDetected) {{
    delay(100);
    return;
  }}

'''
        
        code += '''  unsigned long elapsed = millis() - phraseStartTime;
  unsigned long phraseDuration = 0;
  
  // Get current phrase duration
  switch(currentPhrase) {
'''
        
        for phrase_idx in range(num_phrases):
            code += f"    case {phrase_idx}: phraseDuration = phrase{phrase_idx}_duration; break;\n"
        
        code += '''  }
  
  // Check if phrase is complete
  if(elapsed >= phraseDuration) {
    // Transition to next phrase using Markov chain
    int nextPhrase = selectNextPhrase(currentPhrase);
    
    Serial.print("Phrase ");
    Serial.print(currentPhrase);
    Serial.print(" complete. Transitioning to phrase ");
    Serial.println(nextPhrase);
    
    currentPhrase = nextPhrase;
    phraseStartTime = millis();
    elapsed = 0;
    
    // Reset all layer indices for new phrase
'''
        
        for phrase_idx in range(num_phrases):
            active_layers = phrases[phrase_idx].get('active_layers', list(range(len(phrases[phrase_idx]['layers']))))
            num_active = len(active_layers) if active_layers else 1
            code += f"    if(currentPhrase == {phrase_idx}) {{ for(int i = 0; i < {num_active}; i++) phrase{phrase_idx}_layer_indices[i] = 0; }}\n"
        
        code += '''  }
  
  // Play current phrase
  playPhrase(currentPhrase, elapsed);
  
  delay(5); // 200Hz update rate
}

void playPhrase(int phraseNum, unsigned long elapsed) {
  switch(phraseNum) {
'''
        
        # Generate playback code for each phrase
        for phrase_idx, phrase in enumerate(phrases):
            code += f"    case {phrase_idx}:\n"
            code += f"      playPhrase{phrase_idx}(elapsed);\n"
            code += f"      break;\n"
        
        code += '''  }
}

'''
        
        # Generate individual phrase playback functions using ownership info
        for phrase_idx, phrase in enumerate(phrases):
            servo_owner = phrase.get('servo_owner', [-1] * self.num_servos)
            active_layers = phrase.get('active_layers', list(range(len(phrase['layers']))))
            layer_keyframes = phrase.get('layer_keyframes', [])
            
            code += f"void playPhrase{phrase_idx}(unsigned long elapsed) {{\n"
            code += f"  unsigned long blendZone = phrase{phrase_idx}_duration / 10;\n"
            code += f"  bool isBlending = elapsed >= (phrase{phrase_idx}_duration - blendZone);\n"
            code += f"  float blendFactor = isBlending ? (float)(elapsed - (phrase{phrase_idx}_duration - blendZone)) / blendZone : 0;\n\n"
            
            # Generate layer playback code - ONLY for active layers that OWN servos
            active_idx = 0
            for layer_idx in active_layers:
                if layer_idx >= len(layer_keyframes):
                    continue
                    
                layer_data = layer_keyframes[layer_idx]
                keyframes = layer_data['keyframes']
                
                # Find servos this layer OWNS
                owned_servos = [s for s in range(self.num_servos) if servo_owner[s] == layer_idx]
                
                if not owned_servos:
                    continue
                
                code += f"  // Layer {layer_idx} (OWNS: servos {owned_servos})\n"
                code += f"  if(phrase{phrase_idx}_layer_indices[{active_idx}] < phrase{phrase_idx}_layer{layer_idx}_count - 1) {{\n"
                code += f"    unsigned long currentTime = pgm_read_dword(&phrase{phrase_idx}_layer{layer_idx}_times[phrase{phrase_idx}_layer_indices[{active_idx}]]);\n"
                code += f"    unsigned long nextTime = pgm_read_dword(&phrase{phrase_idx}_layer{layer_idx}_times[phrase{phrase_idx}_layer_indices[{active_idx}] + 1]);\n"
                code += f"    \n"
                code += f"    if(elapsed >= nextTime) {{\n"
                code += f"      phrase{phrase_idx}_layer_indices[{active_idx}]++;\n"
                code += f"    }}\n"
                code += f"    \n"
                code += f"    float factor = (elapsed >= currentTime && nextTime > currentTime) ? (float)(elapsed - currentTime) / (nextTime - currentTime) : 0;\n"
                code += f"    if(factor > 1.0) factor = 1.0;\n\n"
                
                # Generate interpolation code ONLY for OWNED servos
                for servo_idx in owned_servos:
                    # Verify data exists for this servo
                    has_data = False
                    for kf in keyframes:
                        if servo_idx < 5:
                            pos = kf['finger_positions'][servo_idx]
                        else:
                            pos = kf['arm_positions'][servo_idx - 5]
                        if pos is not None:
                            has_data = True
                            break
                    
                    if not has_data:
                        continue
                    
                    code += f"    // Servo {servo_idx} (OWNED by this layer)\n"
                    code += f"    int curr{servo_idx} = pgm_read_word(&phrase{phrase_idx}_layer{layer_idx}_servo{servo_idx}[phrase{phrase_idx}_layer_indices[{active_idx}]]);\n"
                    code += f"    int next{servo_idx} = pgm_read_word(&phrase{phrase_idx}_layer{layer_idx}_servo{servo_idx}[phrase{phrase_idx}_layer_indices[{active_idx}] + 1]);\n"
                    code += f"    int start{servo_idx} = pgm_read_word(&phrase{phrase_idx}_layer{layer_idx}_servo{servo_idx}[0]);\n"
                    code += f"    if(curr{servo_idx} != -1 && next{servo_idx} != -1) {{\n"
                    code += f"      int interpolated = curr{servo_idx} + (int)((next{servo_idx} - curr{servo_idx}) * factor);\n"
                    code += f"      if(isBlending && start{servo_idx} != -1) {{\n"
                    code += f"        interpolated = interpolated * (1.0 - blendFactor) + start{servo_idx} * blendFactor;\n"
                    code += f"      }}\n"
                    code += f"      writeServo({servo_idx}, interpolated);\n"
                    code += f"    }}\n\n"
                
                code += f"  }}\n\n"
                active_idx += 1
            
            code += "}\n\n"
        
        return code

    def _extract_keyframes(self, movements, threshold=5.0):
        """Extract keyframes from movement data based on significant position changes.
        
        Uses adaptive threshold and time decimation to aggressively compress cursor movements
        while preserving manual positioning precision.
        
        Args:
            movements: List of movement dictionaries with time and positions
            threshold: Minimum angle change (degrees) to create a keyframe
            
        Returns:
            List of keyframe movements with significant changes
        """
        if not movements:
            return []
        
        # Adaptive threshold and time decimation based on control mode
        control_mode = movements[0].get('control_mode', 'cursor')
        if control_mode == 'cursor':
            threshold = 5.0  # Reduced from 10° for smoother cursor movements
            min_time_delta = 0.1  # Reduced from 200ms to 100ms for higher resolution
        else:
            threshold = 3.0  # Reduced from 4° for smoother manual positioning
            min_time_delta = 0.05  # Keep at 50ms for manual
        
        keyframes = [movements[0]]  # Always include first frame
        last_keyframe = movements[0]
        last_keyframe_time = movements[0]['time']
        
        for movement in movements[1:]:
            # Time-based decimation: enforce minimum time between keyframes
            time_delta = movement['time'] - last_keyframe_time
            if time_delta < min_time_delta:
                continue  # Skip - too soon after last keyframe
            
            # Check if any servo has changed significantly
            is_keyframe = False
            max_change = 0.0
            
            # Check finger positions
            for i in range(len(movement['finger_positions'])):
                curr_pos = movement['finger_positions'][i]
                last_pos = last_keyframe['finger_positions'][i]
                
                # Only compare if both are not None
                if curr_pos is not None and last_pos is not None:
                    change = abs(curr_pos - last_pos)
                    max_change = max(max_change, change)
                    if change >= threshold:
                        is_keyframe = True
                        break
                elif curr_pos is not None or last_pos is not None:
                    # One changed from/to None - that's a keyframe
                    is_keyframe = True
                    break
            
            # Check arm positions if not already a keyframe
            if not is_keyframe:
                for i in range(len(movement['arm_positions'])):
                    curr_pos = movement['arm_positions'][i]
                    last_pos = last_keyframe['arm_positions'][i]
                    
                    if curr_pos is not None and last_pos is not None:
                        change = abs(curr_pos - last_pos)
                        max_change = max(max_change, change)
                        if change >= threshold:
                            is_keyframe = True
                            break
                    elif curr_pos is not None or last_pos is not None:
                        is_keyframe = True
                        break
            
            if is_keyframe:
                keyframes.append(movement)
                last_keyframe = movement
                last_keyframe_time = movement['time']
        
        # Always include last frame to complete the motion
        if movements[-1] != keyframes[-1]:
            keyframes.append(movements[-1])
        
        reduction = 100*(1-len(keyframes)/len(movements)) if len(movements) > 0 else 0
        print(f"  🔍 Keyframe extraction ({control_mode} mode, {threshold}° threshold, {min_time_delta*1000:.0f}ms min): {len(movements)} frames → {len(keyframes)} keyframes ({reduction:.1f}% reduction)")
        
        return keyframes
    
    def resolve_export_filename(self, prefix):
        """Filename for an export, from the name typed in the export dialog.

        Falls back to a timestamp only when nothing was typed, so an unnamed
        sketch is a deliberate choice rather than the default."""
        raw = (getattr(self, 'pending_export_name', '') or '').strip()
        if not raw:
            return f"{prefix}_{datetime.datetime.now().strftime('%Y%m%d_%H%M%S')}.ino"

        # keep it a filename, not a path -- the dialog is a free text field
        safe = ''.join(c for c in raw if c.isalnum() or c in ' _-').strip().replace(' ', '_')
        if not safe:
            return f"{prefix}_{datetime.datetime.now().strftime('%Y%m%d_%H%M%S')}.ino"
        if not safe.lower().endswith('.ino'):
            safe += '.ino'

        if os.path.exists(os.path.join(os.getcwd(), safe)):
            if not tkinter.messagebox.askyesno(
                    "Overwrite?", f"{safe} already exists.\n\nOverwrite it?"):
                return None
        return safe

    def drivable_channels(self):
        """Channels the CURRENT control mode can actually move."""
        if self.control_mode.get() == 'cursor':
            return {i for i in range(self.num_servos) if self.wave_enabled[i].get()}
        return {self.selected_servo.get()}

    def claimable_channels(self):
        """Channels the next take would own: armed AND actually drivable.

        Claiming a channel you are not driving is the whole bug. In cursor
        mode the wave moves every enabled channel, so a take used to seize
        all of them -- tick S1 to overdub it and S0 came along silently,
        taking ownership away from the layer that actually performed it. Now
        arming is explicit and separate from which bars are on the pad."""
        return {i for i in self.drivable_channels() if self.rec_armed[i].get()}

    def currently_claimed_channels(self):
        """Global channel indices the in-progress take is performing.

        Mirrors exactly what record_current_state will write, so playback and
        recording can never disagree about who owns a channel. Empty when not
        recording."""
        if not self.layer_recording:
            return set()
        return self.claimable_channels()

    def channel_angle(self, ch):
        """Current angle for a global channel index, across both storage groups."""
        if ch < self.num_fingers:
            return self.finger_positions[ch]
        return self.arm_positions[ch - self.num_fingers]

    def on_wave_channel_toggled(self):
        """A Wave On checkbox changed -- rebuild the pad to match."""
        self.create_visual_feedback()

    def create_visual_feedback(self):
        """Create visual feedback elements on the canvas."""
        self.canvas.delete("all")

        # Use actual displayed size if available, fallback to configured size
        canvas_w = self.canvas.winfo_width()
        canvas_h = self.canvas.winfo_height()
        if canvas_w < 10:  # Not yet displayed, use configured size
            canvas_w = int(self.canvas.cget('width'))
        if canvas_h < 10:
            canvas_h = int(self.canvas.cget('height'))
        
        top_y = 36
        bottom_y = canvas_h - 50  # More space for taller bars
        usable_h = max(1, bottom_y - top_y)
        
        # One bar per ENABLED channel. The canvas used to hardcode five finger
        # bars plus three little arm dots, so channels 5-9 had no real presence
        # on the pad you actually perform into. Now the "Wave On" checkboxes
        # below the canvas ARE the canvas: tick a channel and its bar appears.
        self.bar_channels = [i for i in range(self.num_servos)
                             if self.wave_enabled[i].get()]

        self.channel_bars = {}
        self.channel_clamps = {}
        self.channel_labels = {}
        # legacy aliases -- some older code paths still index these
        self.finger_bars = []
        self.finger_clamp_markers = []
        self.finger_label_ids = []
        self.arm_indicators = []
        self.arm_label_ids = []
        self.arm_range_text_ids = []

        n_bars = len(self.bar_channels)
        if n_bars:
            start_x = 35
            # Fit however many are enabled into the pad rather than running off
            # the right edge once you pass five.
            avail = max(120, canvas_w - start_x - 20)
            slot = min(62, avail / n_bars)
            bar_width = max(12, int(slot * 0.62))

            for slot_idx, ch in enumerate(self.bar_channels):
                x = start_x + int(slot_idx * slot)

                bg_bar = self.canvas.create_rectangle(
                    x, top_y, x + bar_width, bottom_y,
                    fill='#E0E0E0', outline='#CCCCCC', width=1
                )
                pos_bar = self.canvas.create_rectangle(
                    x, bottom_y - usable_h // 2, x + bar_width, bottom_y - usable_h // 2,
                    fill='#4CAF50', outline='#45A049', width=1
                )
                min_marker = self.canvas.create_line(
                    x, bottom_y, x + bar_width, bottom_y,
                    fill='#0D47A1', width=2, dash=(3, 2)
                )
                max_marker = self.canvas.create_line(
                    x, top_y, x + bar_width, top_y,
                    fill='#B71C1C', width=2, dash=(3, 2)
                )
                label_id = self.canvas.create_text(
                    x + bar_width // 2, bottom_y + 22,
                    text=f"S{ch}",
                    font=('Arial', 8), fill='#333333'
                )

                self.channel_bars[ch] = (bg_bar, pos_bar)
                self.channel_clamps[ch] = (min_marker, max_marker)
                self.channel_labels[ch] = label_id

        # Add instructions
        hint = ("Move mouse here - no channels enabled" if not n_bars
                else f"Move mouse here - driving {n_bars} channel"
                     f"{'s' if n_bars != 1 else ''}")
        self.canvas.create_text(
            min(canvas_w // 2, 190), 14,
            text=hint,
            font=('Arial', 10), fill='#666666'
        )
        
        # Add current mode indicator
        self.mode_text = self.canvas.create_text(
            min(canvas_w // 2, 190), canvas_h - 18,
            text="Mode: Cursor Wave Control",
            font=('Arial', 9, 'bold'), fill='#2196F3'
        )
        
        # Recording indicator (hidden by default)
        self.rec_indicator_bg = self.canvas.create_rectangle(
            canvas_w - 110, 8, canvas_w - 10, 32,
            fill='#ff0000', outline='#cc0000', width=2, state='hidden'
        )
        self.rec_indicator_dot = self.canvas.create_oval(
            canvas_w - 105, 13, canvas_w - 93, 25,
            fill='#ffffff', outline='#ffffff', state='hidden'
        )
        self.rec_indicator_text = self.canvas.create_text(
            canvas_w - 55, 20,
            text="REC", font=('Arial', 11, 'bold'), fill='#ffffff', state='hidden'
        )
    
    def update_visual_feedback(self):
        """Update the visual feedback based on current servo positions."""
        # Update finger bars
        # If the enabled set changed under us, rebuild before drawing
        current = [i for i in range(self.num_servos) if self.wave_enabled[i].get()]
        if current != getattr(self, 'bar_channels', None):
            self.create_visual_feedback()
            return

        for ch, (bg_bar, pos_bar) in self.channel_bars.items():
            angle = self.channel_angle(ch)
            x_left, y_top, x_right, y_bottom = self.canvas.coords(bg_bar)
            total_h = max(1, int(y_bottom - y_top))
            bar_height = int((angle / 180.0) * total_h)

            bar_top = y_bottom - bar_height  # Invert so 0 deg sits at the bottom
            x = x_left
            bar_width = x_right - x_left

            self.canvas.coords(pos_bar, x, bar_top, x + bar_width, y_bottom)

            # Clamp markers on the full-scale bar (always 0-180 visual)
            min_lim, max_lim = self.servo_limits[ch]
            min_y = y_bottom - int((min_lim / 180.0) * total_h)
            max_y = y_bottom - int((max_lim / 180.0) * total_h)
            min_marker, max_marker = self.channel_clamps[ch]
            self.canvas.coords(min_marker, x, min_y, x + bar_width, min_y)
            self.canvas.coords(max_marker, x, max_y, x + bar_width, max_y)

            label = f"S{ch}"
            if self.servo_reversed[ch]:
                label += "↺"
            self.canvas.itemconfig(self.channel_labels[ch], text=label)

            if 70 <= angle <= 110:      # near centre
                color = '#4CAF50'
            elif angle < 70:
                color = '#2196F3'
            else:
                color = '#FF5722'
            self.canvas.itemconfig(pos_bar, fill=color)

        # Update mode indicator
        mode = self.control_mode.get()
        mode_text = "Mode: Cursor Wave Control" if mode == "cursor" else "Mode: Individual Servo Control"
        self.canvas.itemconfig(self.mode_text, text=mode_text)


def main():
    """Main function to start the simple hand control interface."""
    print("[START] Starting Simple 10-Servo Hand Control...")
    
    try:
        interface = SimpleHandControl()
        interface.root.mainloop()
    except KeyboardInterrupt:
        print("\\n[INFO] Interrupted by user")
    except Exception as e:
        print(f"[ERROR] Error: {e}")
        import traceback
        traceback.print_exc()
    finally:
        print("[INFO] Shutdown complete")


if __name__ == "__main__":
    main()