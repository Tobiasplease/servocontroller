#!/usr/bin/env python3
"""
Simple 8-Servo Hand Control (5 Fingers + 3 Arm)
================================================

Minimal version focused on:
- 5-finger cursor wave control
- 3 arm servo individual control
- Arduino export functionality
- No complex Markov chains or datasets

Author: Simplified 8-Servo System
"""
import tkinter as tk
from tkinter import ttk
import tkinter.messagebox
import tkinter.simpledialog
import time
import math
import os
import json
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
        self.root = tk.Tk()
        self.root.title("Simple 8-Servo Hand Control")
        self.root.geometry("1380x940")
        self.root.minsize(1200, 820)
        
        # Color scheme
        self.colors = {
            'bg_main': '#FEF7F7',
            'bg_frame': '#F8E8E8',
            'bg_dark': '#E0D0E0',
            'text_main': '#5D4E75',
            'text_dim': '#9B8BA8',
            'button_bg': '#E8C5E8',
            'canvas_bg': '#FFFEF8'
        }
        
        self.root.configure(bg=self.colors['bg_main'])
        
        # Servo configuration
        self.num_fingers = 5
        self.num_arm_servos = 3
        self.finger_names = ['Thumb', 'Index', 'Middle', 'Ring', 'Pinky']
        self.arm_names = ['Shoulder', 'Elbow', 'Wrist']
        self.all_servo_names = self.finger_names + self.arm_names
        
        # Hardware configuration (can be saved/loaded as presets)
        self.hardware_config = {
            'name': 'Default',
            'description': 'Standard 8-servo hand controller',
            'serial_port': 'COM4',
            'baud_rate': 9600,
            'global_min_angle': 0,
            'global_max_angle': 45,
            'pin_mapping': [12, 11, 10, 9, 8, 7, 6, 5],
            'servo_names': ['Thumb', 'Index', 'Middle', 'Ring', 'Pinky', 'Shoulder', 'Elbow', 'Wrist'],
            'reversed_servos': [2, 3],  # Servo indices that are reversed (Middle, Ring)
            'per_servo_limits': [
                [0, 180], [0, 180], [0, 180], [0, 180],  # Fingers
                [0, 180], [0, 180], [0, 180], [0, 180]   # Arm
            ]
        }
        self.hardware_config_file = 'hardware_config.json'
        self.load_hardware_config()  # Load saved config if exists
        
        # Derive legacy variables from config for backward compatibility
        self.servo_limits = [tuple(lim) for lim in self.hardware_config['per_servo_limits']]
        self.servo_reversed = [i in self.hardware_config['reversed_servos'] for i in range(8)]
        self.default_port = self.hardware_config['serial_port']
        
        # Initialize positions
        self.finger_positions = [90.0] * self.num_fingers
        self.arm_positions = [90.0] * self.num_arm_servos
        
        # Control parameters
        self.cursor_sensitivity = tk.DoubleVar(value=2.0)
        self.servo_range = tk.DoubleVar(value=180.0)
        self.wave_gravity = tk.DoubleVar(value=0.5)  # How much Y position affects all fingers
        self.wave_offset = tk.DoubleVar(value=0.0)   # Base offset for all fingers
        self.global_clamp_min = tk.IntVar(value=0)
        self.global_clamp_max = tk.IntVar(value=180)
        
        # Per-finger wave enable (allows excluding fingers from cursor control)
        self.finger_wave_enabled = [tk.BooleanVar(value=True) for _ in range(self.num_fingers)]
        
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
        self.markov_mode = False  # True when organic variations are active
        self.position_wobble = tk.DoubleVar(value=1.5)  # ± degrees random offset (subtle)
        self.timing_jitter = tk.DoubleVar(value=8.0)  # ± % timing variation (gentle)
        self.pause_chance = tk.DoubleVar(value=2.0)  # % chance to pause at keyframes (rare)
        self.is_paused_at_keyframe = False
        self.pause_until = 0  # timestamp when pause ends
        self.wobble_offsets = [0.0] * 8  # current wobble offset per servo
        self.wobble_targets = [0.0] * 8  # target wobble offset (for smooth transitions)
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
        self.pir_transition_time = tk.DoubleVar(value=2.0)  # Seconds to blend between states
        
        # Recording assignments for each state (filename from pir_recordings/ folder)
        self.pir_idle_recording = tk.StringVar(value="")
        self.pir_active_recording = tk.StringVar(value="")
        self.pir_sleep_recording = tk.StringVar(value="")
        
        # Cache for loaded PIR recordings {filename: layers_data}
        self.pir_cached_recordings = {}
        self.pir_recordings_dir = os.path.join(os.path.dirname(os.path.abspath(__file__)), "pir_recordings")
        
        # State-specific playback speeds
        self.pir_idle_speed = tk.DoubleVar(value=0.5)  # Slow for idle
        self.pir_active_speed = tk.DoubleVar(value=1.5)  # Fast for active
        self.pir_sleep_speed = tk.DoubleVar(value=0.2)  # Very slow for sleep
        
        # State transition tracking
        self.pir_blend_factor = 0.0  # 0.0-1.0 for smooth state transitions
        self.pir_previous_state = None
        self.pir_transition_start = 0
        self.pir_transition_positions = None  # Store positions at transition start for blending

        # Control mode
        self.control_mode = tk.StringVar(value="cursor")
        self.hover_mode = tk.BooleanVar(value=False)  # Toggle for hover control
        
        # Hardware controller
        self.hand_controller = None
        if HAND_CONTROLLER_AVAILABLE:
            try:
                self.hand_controller = HandExpressionController(port=self.default_port, clean_output=True)
            except Exception as e:
                print(f"[WARNING] Could not initialize hand controller: {e}")
        
        # Create GUI
        self.create_interface()
        
        # Populate PIR recording dropdowns from library
        self.update_pir_recording_combos()
        
        # Start control loop
        self.last_send_time = 0
        self.send_interval = 0.05  # 20Hz
        self.control_loop()
        
        print("✅ Simple 8-servo hand control initialized")
        print(f"🖱️ Cursor wave control for {self.num_fingers} fingers")
        print(f"🎛️ Individual control for {self.num_arm_servos} arm servos")
    
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
        top_bar.pack(fill=tk.X, pady=(10, 10), padx=10)
        
        title = tk.Label(top_bar, text="🤖 8-Servo Hand Control", 
                        bg=self.colors['bg_main'], fg=self.colors['text_main'],
                        font=('Arial', 14, 'bold'))
        title.pack(side=tk.LEFT)
        
        # Recording controls on top right
        record_controls = tk.Frame(top_bar, bg=self.colors['bg_main'])
        record_controls.pack(side=tk.RIGHT)
        
        self.record_btn = tk.Button(record_controls, text="🔴 Record", 
                                   command=self.toggle_recording,
                                   bg=self.colors['button_bg'], font=('Arial', 9, 'bold'))
        self.record_btn.pack(side=tk.LEFT, padx=2)
        
        self.playback_btn = tk.Button(record_controls, text="▶️ Play", 
                                     command=self.toggle_playback,
                                     bg=self.colors['button_bg'], font=('Arial', 9, 'bold'))
        self.playback_btn.pack(side=tk.LEFT, padx=2)
        
        self.markov_btn = tk.Button(record_controls, text="🎲 Organic", 
                                    command=self.toggle_markov_playback,
                                    bg=self.colors['button_bg'], font=('Arial', 9, 'bold'))
        self.markov_btn.pack(side=tk.LEFT, padx=2)
        
        tk.Button(record_controls, text="📸 Capture", 
                 command=self.capture_keyframe,
                 bg=self.colors['button_bg'], font=('Arial', 9)).pack(side=tk.LEFT, padx=2)
        
        tk.Button(record_controls, text="💾 Save", 
                 command=self.save_recording,
                 bg=self.colors['button_bg'], font=('Arial', 9)).pack(side=tk.LEFT, padx=2)
        
        tk.Button(record_controls, text="📂 Load", 
                 command=self.load_recording,
                 bg=self.colors['button_bg'], font=('Arial', 9)).pack(side=tk.LEFT, padx=2)
        
        tk.Button(record_controls, text="📤 Export", 
                 command=self.export_arduino_code,
                 bg=self.colors['button_bg'], font=('Arial', 9)).pack(side=tk.LEFT, padx=2)
        
        tk.Button(record_controls, text="🎲 Markov Export", 
                 command=self.export_markov_arduino,
                 bg=self.colors['button_bg'], font=('Arial', 9)).pack(side=tk.LEFT, padx=2)
        
        tk.Button(record_controls, text="🔌 Connect", 
                 command=self.reconnect_arduino,
                 bg=self.colors['button_bg'], font=('Arial', 9)).pack(side=tk.LEFT, padx=2)
        
        tk.Button(record_controls, text="🗑️", 
                 command=self.clear_layers,
                 bg=self.colors['button_bg'], font=('Arial', 9)).pack(side=tk.LEFT, padx=2)
        
        # Status bar
        status_bar = tk.Frame(main_frame, bg=self.colors['bg_dark'], relief=tk.SUNKEN, bd=1)
        status_bar.pack(fill=tk.X, pady=(0, 10))
        
        self.record_status_label = tk.Label(status_bar, text="⚪ Ready to record (Press SPACE)", 
                                           bg=self.colors['bg_dark'], fg=self.colors['text_main'],
                                           font=('Arial', 9), anchor=tk.W)
        self.record_status_label.pack(side=tk.LEFT, padx=5, pady=3, fill=tk.X, expand=True)
        
        # Timeline
        self.timeline_canvas = tk.Canvas(main_frame, height=25, bg=self.colors['bg_dark'], 
                                        highlightthickness=1, highlightbackground=self.colors['text_dim'])
        self.timeline_canvas.pack(fill=tk.X, pady=(0, 5))
        
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
        
        self.variation_expanded = True
        self.variation_btn = tk.Button(self.variation_container, 
                                       text="▼ Organic Variations", 
                                       command=self.toggle_variation_panel,
                                       bg=self.colors['button_bg'], fg=self.colors['text_main'],
                                       font=('Arial', 9, 'bold'), anchor='w', 
                                       relief=tk.FLAT, cursor="hand2")
        self.variation_btn.pack(fill=tk.X, pady=(0, 2))
        
        self.variation_content = tk.Frame(self.variation_container, bg=self.colors['bg_frame'],
                                          relief=tk.GROOVE, bd=1)
        self.variation_content.pack(fill=tk.X, pady=(0, 5))  # Start expanded
        
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
        mode_frame = tk.LabelFrame(main_frame, text="Control Mode", 
                                  bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        mode_frame.pack(fill=tk.X, pady=(0, 10))
        
        tk.Radiobutton(mode_frame, text="🖱️ Cursor Wave Control (5 Fingers)", 
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
        self.hw_config_btn = tk.Button(self.hw_config_container, 
                                       text="▶ Hardware Config", 
                                       command=self.toggle_hw_config_panel,
                                       bg=self.colors['button_bg'], fg=self.colors['text_main'],
                                       font=('Arial', 9, 'bold'), anchor='w', 
                                       relief=tk.FLAT, cursor="hand2")
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
        tk.Button(name_row, text="📥 Import", command=self.import_hardware_preset,
                 bg=self.colors['button_bg'], font=('Arial', 7)).pack(side=tk.LEFT, padx=2)
        tk.Button(name_row, text="📤 Export", command=self.export_hardware_preset,
                 bg=self.colors['button_bg'], font=('Arial', 7)).pack(side=tk.LEFT, padx=2)
        
        # Serial port
        port_row = tk.Frame(self.hw_config_content, bg=self.colors['bg_frame'])
        port_row.pack(fill=tk.X, padx=5, pady=2)
        tk.Label(port_row, text="Serial Port:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8), width=12, anchor='w').pack(side=tk.LEFT)
        self.config_port_var = tk.StringVar(value=self.hardware_config['serial_port'])
        tk.Entry(port_row, textvariable=self.config_port_var, width=10, font=('Arial', 8)).pack(side=tk.LEFT, padx=5)
        
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
        tk.Label(range_row, text="° (for export)", bg=self.colors['bg_frame'], 
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
        tk.Button(btn_row, text="✅ Apply & Save", command=self.apply_and_save_config,
                 bg=self.colors['button_bg'], font=('Arial', 8, 'bold')).pack(side=tk.LEFT, padx=5)
        tk.Label(btn_row, text="(Affects .ino exports)", bg=self.colors['bg_frame'], 
                fg=self.colors['text_dim'], font=('Arial', 7)).pack(side=tk.LEFT)
        
        # ==================== PIR STATE MACHINE PANEL ====================
        pir_main_frame = tk.LabelFrame(main_frame, text="🔴 PIR State Machine (Test & Export)", 
                                       bg='#FFE8E8', fg=self.colors['text_main'],
                                       font=('Arial', 10, 'bold'))
        pir_main_frame.pack(fill=tk.X, pady=(5, 10), padx=5)
        
        # Top row: Enable toggle, state indicator, simulate button
        pir_top_row = tk.Frame(pir_main_frame, bg='#FFE8E8')
        pir_top_row.pack(fill=tk.X, padx=10, pady=5)
        
        self.pir_enable_cb = tk.Checkbutton(pir_top_row, text="Enable PIR Mode", 
                                           variable=self.pir_enabled,
                                           bg='#FFE8E8', fg=self.colors['text_main'],
                                           font=('Arial', 9, 'bold'),
                                           command=self.on_pir_toggle)
        self.pir_enable_cb.pack(side=tk.LEFT)
        
        # State indicator
        tk.Label(pir_top_row, text="  State:", bg='#FFE8E8', 
                fg=self.colors['text_main'], font=('Arial', 9)).pack(side=tk.LEFT, padx=(20, 5))
        self.pir_state_label = tk.Label(pir_top_row, text="OFF", 
                                        bg='#888888', fg='white',
                                        font=('Arial', 9, 'bold'), width=8, relief=tk.RAISED)
        self.pir_state_label.pack(side=tk.LEFT)
        
        # Simulate motion button
        self.pir_simulate_btn = tk.Button(pir_top_row, text="👋 Simulate Motion", 
                                         command=self.simulate_pir_motion,
                                         bg='#FFB366', font=('Arial', 9, 'bold'),
                                         state=tk.DISABLED)
        self.pir_simulate_btn.pack(side=tk.LEFT, padx=(20, 5))
        
        # Timer display
        self.pir_timer_label = tk.Label(pir_top_row, text="", 
                                        bg='#FFE8E8', fg=self.colors['text_dim'],
                                        font=('Arial', 8))
        self.pir_timer_label.pack(side=tk.LEFT, padx=10)
        
        # Save to Library button (saves current recording for PIR states)
        self.pir_save_btn = tk.Button(pir_top_row, text="📚 Save to Library", 
                                      command=self.save_to_pir_library,
                                      bg='#99CCFF', font=('Arial', 9, 'bold'))
        self.pir_save_btn.pack(side=tk.RIGHT, padx=5)
        
        # State assignment cards - three columns
        pir_states_frame = tk.Frame(pir_main_frame, bg='#FFE8E8')
        pir_states_frame.pack(fill=tk.X, padx=10, pady=5)
        
        # IDLE state card
        idle_card = tk.LabelFrame(pir_states_frame, text="😴 IDLE", 
                                  bg='#E8E8FF', fg='#333366',
                                  font=('Arial', 9, 'bold'))
        idle_card.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=(0, 5))
        
        tk.Label(idle_card, text="Recording:", bg='#E8E8FF', 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(anchor=tk.W, padx=5)
        self.pir_idle_combo = ttk.Combobox(idle_card, width=15, state='readonly')
        self.pir_idle_combo.pack(padx=5, pady=2)
        self.pir_idle_combo.bind('<<ComboboxSelected>>', 
            lambda e: self.pir_idle_recording.set(self.pir_idle_combo.get() if self.pir_idle_combo.current() > 0 else ""))
        
        speed_frame = tk.Frame(idle_card, bg='#E8E8FF')
        speed_frame.pack(fill=tk.X, padx=5, pady=2)
        tk.Label(speed_frame, text="Speed:", bg='#E8E8FF', 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Scale(speed_frame, from_=0.1, to=2.0, resolution=0.1, orient=tk.HORIZONTAL,
                variable=self.pir_idle_speed, length=80, font=('Arial', 7),
                bg='#E8E8FF', highlightthickness=0).pack(side=tk.LEFT)
        
        # ACTIVE state card
        active_card = tk.LabelFrame(pir_states_frame, text="⚡ ACTIVE", 
                                    bg='#E8FFE8', fg='#336633',
                                    font=('Arial', 9, 'bold'))
        active_card.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=5)
        
        tk.Label(active_card, text="Recording:", bg='#E8FFE8', 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(anchor=tk.W, padx=5)
        self.pir_active_combo = ttk.Combobox(active_card, width=15, state='readonly')
        self.pir_active_combo.pack(padx=5, pady=2)
        self.pir_active_combo.bind('<<ComboboxSelected>>', 
            lambda e: self.pir_active_recording.set(self.pir_active_combo.get() if self.pir_active_combo.current() > 0 else ""))
        
        speed_frame2 = tk.Frame(active_card, bg='#E8FFE8')
        speed_frame2.pack(fill=tk.X, padx=5, pady=2)
        tk.Label(speed_frame2, text="Speed:", bg='#E8FFE8', 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Scale(speed_frame2, from_=0.1, to=3.0, resolution=0.1, orient=tk.HORIZONTAL,
                variable=self.pir_active_speed, length=80, font=('Arial', 7),
                bg='#E8FFE8', highlightthickness=0).pack(side=tk.LEFT)
        
        # SLEEP state card
        sleep_card = tk.LabelFrame(pir_states_frame, text="💤 SLEEP", 
                                   bg='#F0E8FF', fg='#663366',
                                   font=('Arial', 9, 'bold'))
        sleep_card.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=(5, 0))
        
        tk.Label(sleep_card, text="Recording:", bg='#F0E8FF', 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(anchor=tk.W, padx=5)
        self.pir_sleep_combo = ttk.Combobox(sleep_card, width=15, state='readonly')
        self.pir_sleep_combo.pack(padx=5, pady=2)
        self.pir_sleep_combo.bind('<<ComboboxSelected>>', 
            lambda e: self.pir_sleep_recording.set(self.pir_sleep_combo.get() if self.pir_sleep_combo.current() > 0 else ""))
        
        speed_frame3 = tk.Frame(sleep_card, bg='#F0E8FF')
        speed_frame3.pack(fill=tk.X, padx=5, pady=2)
        tk.Label(speed_frame3, text="Speed:", bg='#F0E8FF', 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Scale(speed_frame3, from_=0.1, to=1.0, resolution=0.1, orient=tk.HORIZONTAL,
                variable=self.pir_sleep_speed, length=80, font=('Arial', 7),
                bg='#F0E8FF', highlightthickness=0).pack(side=tk.LEFT)
        
        # Timing row
        pir_timing_frame = tk.Frame(pir_main_frame, bg='#FFE8E8')
        pir_timing_frame.pack(fill=tk.X, padx=10, pady=(5, 10))
        
        tk.Label(pir_timing_frame, text="Active duration:", bg='#FFE8E8', 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Spinbox(pir_timing_frame, from_=5, to=120, width=4, 
                  textvariable=self.pir_active_duration, font=('Arial', 8)).pack(side=tk.LEFT, padx=2)
        tk.Label(pir_timing_frame, text="sec", bg='#FFE8E8', 
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
        
        tk.Label(pir_timing_frame, text="    Sleep after:", bg='#FFE8E8', 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(15, 0))
        tk.Spinbox(pir_timing_frame, from_=1, to=60, width=4, 
                  textvariable=self.pir_sleep_timeout, font=('Arial', 8)).pack(side=tk.LEFT, padx=2)
        tk.Label(pir_timing_frame, text="min", bg='#FFE8E8', 
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
        
        tk.Label(pir_timing_frame, text="    Blend time:", bg='#FFE8E8', 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(15, 0))
        tk.Spinbox(pir_timing_frame, from_=0.5, to=5.0, increment=0.5, width=4, 
                  textvariable=self.pir_transition_time, font=('Arial', 8)).pack(side=tk.LEFT, padx=2)
        tk.Label(pir_timing_frame, text="sec", bg='#FFE8E8', 
                fg=self.colors['text_dim'], font=('Arial', 8)).pack(side=tk.LEFT)
        
        # ==================== END PIR PANEL ====================
        
        # Create two main areas side by side
        content_frame = tk.Frame(main_frame, bg=self.colors['bg_main'])
        content_frame.pack(fill=tk.BOTH, expand=True)
        
        # Left side - Cursor control
        self.cursor_frame = tk.LabelFrame(content_frame, text="Cursor Wave Control", 
                                         bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        self.cursor_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=(0, 5))
        
        # Canvas for cursor control with visual feedback - larger area for finer control
        self.canvas = tk.Canvas(self.cursor_frame, width=550, height=380,
                               bg=self.colors['canvas_bg'])
        self.canvas.pack(pady=10, fill=tk.BOTH, expand=True)
        self.canvas.bind("<Motion>", self.on_mouse_move)
        self.canvas.bind("<Configure>", lambda e: self.on_canvas_resize(e))
        
        # Per-finger wave enable checkboxes
        finger_enable_frame = tk.Frame(self.cursor_frame, bg=self.colors['bg_frame'])
        finger_enable_frame.pack(fill=tk.X, padx=10, pady=(0, 5))
        tk.Label(finger_enable_frame, text="Wave On:", bg=self.colors['bg_frame'], 
                fg=self.colors['text_main'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(0, 5))
        for i, name in enumerate(self.finger_names):
            cb = tk.Checkbutton(finger_enable_frame, text=name[:3], 
                               variable=self.finger_wave_enabled[i],
                               bg=self.colors['bg_frame'], fg=self.colors['text_main'],
                               font=('Arial', 8), selectcolor=self.colors['bg_dark'])
            cb.pack(side=tk.LEFT, padx=3)
        
        # Bind spacebar for recording toggle
        self.root.bind("<space>", lambda e: self.toggle_recording())
        
        # Initialize visual elements
        self.finger_bars = []
        self.arm_indicators = []
        self.create_visual_feedback()
        
        # Cursor control parameters - Row 1
        param_frame1 = tk.Frame(self.cursor_frame, bg=self.colors['bg_frame'])
        param_frame1.pack(fill=tk.X, padx=10, pady=(5, 2))
        
        tk.Label(param_frame1, text="Wave:", bg=self.colors['bg_frame'], 
                font=('Arial', 8)).pack(side=tk.LEFT)
        tk.Scale(param_frame1, from_=0.1, to=10.0, resolution=0.1, orient=tk.HORIZONTAL,
                variable=self.cursor_sensitivity, length=100, 
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

        tk.Button(param_frame1, text="Apply Clamp to All", command=self.apply_global_clamp_to_all,
             bg=self.colors['button_bg'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(5, 0))
        
        # Cursor control parameters - Row 2
        param_frame2 = tk.Frame(self.cursor_frame, bg=self.colors['bg_frame'])
        param_frame2.pack(fill=tk.X, padx=10, pady=(2, 5))
        
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
        layer_frame = tk.LabelFrame(main_frame, text="Recorded Layers", 
                                    bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        layer_frame.pack(fill=tk.X, pady=(10, 0))
        
        list_container = tk.Frame(layer_frame, bg=self.colors['bg_frame'])
        list_container.pack(fill=tk.X, padx=5, pady=5)
        
        scrollbar = tk.Scrollbar(list_container)
        scrollbar.pack(side=tk.RIGHT, fill=tk.Y)
        
        self.layer_listbox = tk.Listbox(list_container, bg=self.colors['bg_dark'], 
                                        fg=self.colors['text_main'],
                                        selectmode=tk.SINGLE, height=6,
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
        tk.Button(layer_bottom, text="📸→📦 Keyframes to Layer", 
                 command=self.convert_keyframes_to_layer,
                 bg=self.colors['button_bg'], font=('Arial', 8)).pack(side=tk.RIGHT, padx=2)
        
        tk.Button(layer_bottom, text="Clear Keyframes", 
                 command=self.clear_keyframes,
                 bg=self.colors['button_bg'], font=('Arial', 8)).pack(side=tk.RIGHT, padx=2)
        
        tk.Button(layer_bottom, text="Delete Selected", 
                 command=self.delete_selected_layer,
                 bg=self.colors['button_bg'], font=('Arial', 8)).pack(side=tk.RIGHT)
    
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
        tk.Button(preset_row, text="💾 Save Preset", command=self.save_servo_preset,
                 bg=self.colors['button_bg'], font=('Arial', 8)).pack(side=tk.LEFT, padx=(0, 5))
        tk.Button(preset_row, text="📂 Load Preset", command=self.load_servo_preset,
                 bg=self.colors['button_bg'], font=('Arial', 8)).pack(side=tk.LEFT)
        
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

        for i in range(8):
            self.servo_limits[i] = (min_lim, max_lim)
            if hasattr(self, 'servo_min_vars') and i < len(self.servo_min_vars):
                self.servo_min_vars[i].set(min_lim)
                self.servo_max_vars[i].set(max_lim)

        self.apply_servo_limits_to_state()
        self.update_large_bar()
        self.update_small_servo_bars()
        self.update_visual_feedback()

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

        self.apply_servo_limits_to_state()
        self.update_large_bar()
        self.update_small_servo_bars()
        self.update_visual_feedback()

    def on_bar_reverse_changed(self, servo_idx):
        """Apply reverse toggle from visualizer row controls."""
        self.servo_reversed[servo_idx] = bool(self.servo_rev_vars[servo_idx].get())
        self.update_large_bar()
        self.update_small_servo_bars()
        self.update_visual_feedback()

    def clamp_servo_angle(self, servo_idx, angle):
        """Clamp a servo angle to its configured range."""
        min_lim, max_lim = self.servo_limits[servo_idx]
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
            min_lim, max_lim = self.servo_limits[servo_idx]
            return max_lim - (logical_angle - min_lim)
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

            loaded_limits = preset.get('servo_limits', [])
            if len(loaded_limits) == 8:
                new_limits = []
                for item in loaded_limits:
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
                self.servo_limits = new_limits

            loaded_reversed = preset.get('servo_reversed', [])
            if isinstance(loaded_reversed, list) and len(loaded_reversed) == 8:
                self.servo_reversed = [bool(flag) for flag in loaded_reversed]

            cursor_settings = preset.get('cursor_settings', {})
            if isinstance(cursor_settings, dict):
                self.cursor_sensitivity.set(float(cursor_settings.get('wave', self.cursor_sensitivity.get())))
                self.servo_range.set(float(cursor_settings.get('range', self.servo_range.get())))
                self.wave_gravity.set(float(cursor_settings.get('gravity', self.wave_gravity.get())))
                self.wave_offset.set(float(cursor_settings.get('offset', self.wave_offset.get())))

            self.apply_servo_limits_to_state()
            if hasattr(self, 'servo_min_vars'):
                for i in range(min(8, len(self.servo_min_vars))):
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
        min_lim, max_lim = self.servo_limits[servo_idx]
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
            self.large_bar_canvas.itemconfig(self.large_bar_range_label, text=f"Clamp: {min_lim}° - {max_lim}° | Rev:{reverse_text}")
    
    def update_small_servo_bars(self):
        """Update all small servo bars."""
        all_positions = list(self.finger_positions) + list(self.arm_positions)
        
        for i, bar_info in enumerate(self.small_bars):
            if i >= len(all_positions):
                continue
                
            pos = all_positions[i]
            min_lim, max_lim = self.servo_limits[i]
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
        
        tk.Button(test_frame, text="▶️ Test Movement", command=self.test_scratch_movement,
                 bg=self.colors['button_bg'], fg=self.colors['text_main']).pack(side=tk.LEFT, padx=5)
        tk.Button(test_frame, text="⏹️ Stop Test", command=self.stop_test_movement,
                 bg=self.colors['button_bg'], fg=self.colors['text_main']).pack(side=tk.LEFT, padx=5)
        tk.Button(test_frame, text="🏠 Center Arms", command=self.center_arms,
                 bg=self.colors['button_bg'], fg=self.colors['text_main']).pack(side=tk.LEFT, padx=5)
        
        # Export dedicated scratch movement
        export_frame = tk.Frame(coord_frame, bg=self.colors['bg_frame'])
        export_frame.pack(fill=tk.X, padx=5, pady=10)
        
        tk.Button(export_frame, text="📤 Export Scratch Movement", command=self.export_scratch_arduino,
                 bg=self.colors['button_bg'], fg=self.colors['text_main']).pack(side=tk.LEFT, padx=5)
    
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
        sensitivity = self.cursor_sensitivity.get()
        servo_range = self.servo_range.get()
        gravity = self.wave_gravity.get()
        offset = self.wave_offset.get()
        
        for i in range(self.num_fingers):
            # Skip if this finger is disabled from wave control
            if not self.finger_wave_enabled[i].get():
                continue
                
            # Create wave pattern across fingers
            finger_offset = (i / max(self.num_fingers - 1, 1)) - 0.5  # -0.5 to 0.5
            
            # Wave influence from X position
            wave_influence = math.sin((x_norm + finger_offset) * math.pi * sensitivity)
            
            # Gravity pull from Y position (0=top pulls up, 1=bottom pulls down)
            gravity_pull = (y_norm - 0.5) * 2  # -1 (top) to 1 (bottom)
            
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
            
            self.finger_positions[i] = angle
        
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
        wrist_contrib = self.arm_contributions["Wrist Tilt"].get()
        elbow_contrib = self.arm_contributions["Elbow"].get()
        
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
        rotate_contrib = self.arm_contributions["Wrist Rotate"].get()
        
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
        
        rotate_contrib = self.arm_contributions["Wrist Rotate"].get()
        tilt_contrib = self.arm_contributions["Wrist Tilt"].get()
        
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
            wrist_contrib = self.arm_contributions["Wrist Tilt"].get()
            elbow_contrib = self.arm_contributions["Elbow"].get()
            
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
            rotate_contrib = self.arm_contributions["Wrist Rotate"].get()
            
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
            rotate_contrib = self.arm_contributions["Wrist Rotate"].get()
            tilt_contrib = self.arm_contributions["Wrist Tilt"].get()
            
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
        
        # Update visual feedback
        self.update_visual_feedback()
        self.update_large_bar()
        self.update_small_servo_bars()
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
            if self.control_mode.get() == "cursor" and i < self.num_fingers:
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
            self.playback_btn.config(text="⏹️ Stop", bg='#ffcccc')
            print(f"▶️ Auto-playing {len(self.recorded_layers)} existing layers")
        
        self.record_btn.config(text="⏹️ Stop", bg='#ffcccc')
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
        
        self.record_btn.config(text="🔴 Record", bg=self.colors['button_bg'])
        self.update_layer_list()
    
    def toggle_playback(self):
        """Toggle playback of ALL recorded layers simultaneously."""
        if not self.recorded_layers:
            print("❌ No layers to play back")
            return
        
        self.is_playing = not self.is_playing
        self.markov_mode = False  # Regular play disables organic mode
        
        if self.is_playing:
            # Start playing ALL recorded layers simultaneously
            self.playback_start_time = time.time()
            self.playback_index = 0
            self.playback_btn.config(text="⏹️ Stop", bg='#ffcccc')
            self.markov_btn.config(bg=self.colors['button_bg'])
            print(f"▶️ Playing {len(self.recorded_layers)} layers simultaneously")
        else:
            # Stop playback
            self.is_playing = False
            self.playback_layer = None
            self.playback_btn.config(text="▶️ Play", bg=self.colors['button_bg'])
            print("⏹️ Playback stopped")
        
        self.update_timeline()
    
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
            self.markov_btn.config(text="🎲 Organic", bg=self.colors['button_bg'])
            self.playback_btn.config(text="▶️ Play", bg=self.colors['button_bg'])
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
            self.wobble_offsets = [0.0] * 8
            self.wobble_targets = [0.0] * 8
            self.last_wobble_update = time.time()
            # Reset organic sine wave phases for fresh start
            self._organic_phases = [random.uniform(0, 2 * math.pi) for _ in range(8)]
            self._organic_start_time = time.time()
            # Initialize timing jitter
            self.jitter_speed_multiplier = 1.0
            self.jitter_speed_target = 1.0
            self.last_jitter_update = time.time()
            
            self.markov_btn.config(text="⏹️ Stop", bg='#ccffcc')
            self.playback_btn.config(text="▶️ Play", bg=self.colors['button_bg'])
            print(f"🎲 Organic playback: wobble=±{self.position_wobble.get()}°, jitter=±{self.timing_jitter.get()}%, pause={self.pause_chance.get()}%")
        
        self.update_timeline()
    
    def toggle_variation_panel(self, event=None):
        """Toggle the organic variations control panel."""
        self.variation_expanded = not self.variation_expanded
        if self.variation_expanded:
            self.variation_content.pack(fill=tk.X, pady=(0, 5))
            self.variation_btn.config(text="▼ Organic Variations")
        else:
            self.variation_content.pack_forget()
            self.variation_btn.config(text="▶ Organic Variations")
    
    def toggle_hw_config_panel(self, event=None):
        """Toggle the hardware configuration panel."""
        self.hw_config_expanded = not self.hw_config_expanded
        if self.hw_config_expanded:
            self.hw_config_content.pack(fill=tk.X, pady=(0, 5))
            self.hw_config_btn.config(text="▼ Hardware Config")
        else:
            self.hw_config_content.pack_forget()
            self.hw_config_btn.config(text="▶ Hardware Config")
    
    def apply_and_save_config(self):
        """Apply hardware config from UI and save to file."""
        self.update_config_from_ui()
        self.save_hardware_config()
        tkinter.messagebox.showinfo("Config Saved", 
            f"Hardware config '{self.hardware_config['name']}' saved.\n\n"
            f"These settings will be used in exported .ino sketches:\n"
            f"• Angle range: {self.hardware_config['global_min_angle']}° - {self.hardware_config['global_max_angle']}°\n"
            f"• Reversed servos: {self.hardware_config['reversed_servos']}\n"
            f"• Serial port: {self.hardware_config['serial_port']}")

    # ==================== PIR STATE MACHINE METHODS ====================
    
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
    
    def update_pir_recording_combos(self):
        """Update the PIR state recording dropdowns with library recordings."""
        # Build options: None, Current Recording (if loaded), then library files
        recordings = ['(None)']
        
        # Add current recording option if layers are loaded
        if self.recorded_layers:
            recordings.append('[Current Recording]')
        
        # Add saved library recordings
        recordings.extend(self.scan_pir_recordings_library())
        
        # Update all three combos
        for combo, var in [(self.pir_idle_combo, self.pir_idle_recording),
                          (self.pir_active_combo, self.pir_active_recording),
                          (self.pir_sleep_combo, self.pir_sleep_recording)]:
            current = var.get()
            combo['values'] = recordings
            
            # Restore selection if still valid
            if current and current in recordings:
                combo.set(current)
            else:
                combo.current(0)
                var.set("")
    
    def on_pir_toggle(self):
        """Toggle PIR testing mode."""
        if self.pir_enabled.get():
            # Enable PIR mode
            self.pir_state = 'idle'
            self.pir_state_start_time = time.time()
            self.pir_last_motion_time = time.time()  # Start fresh
            self.pir_simulate_btn.config(state=tk.NORMAL)
            self.update_pir_state_display()
            
            # Start PIR playback if we have recordings assigned
            if not self.is_playing:
                self.is_playing = True
                self.playback_start_time = time.time()
            
            print(f"🔴 PIR Mode enabled - starting in IDLE state")
        else:
            # Disable PIR mode
            self.pir_state = 'idle'
            self.pir_simulate_btn.config(state=tk.DISABLED)
            self.pir_state_label.config(text="OFF", bg='#888888')
            self.pir_timer_label.config(text="")
            print("⚪ PIR Mode disabled")
    
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
                if line and not line.startswith("8-Servo"):  # Skip startup messages
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
            self.pir_simulate_btn.config(bg='#FF6600')
            self.root.after(200, lambda: self.pir_simulate_btn.config(bg='#FFB366'))
        
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
            self.update_pir_state_display()
        
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
    
    def get_pir_playback_speed(self):
        """Get the playback speed for the current PIR state."""
        speeds = {
            'idle': self.pir_idle_speed.get(),
            'active': self.pir_active_speed.get(),
            'sleep': self.pir_sleep_speed.get()
        }
        
        # Blend between previous and current state speed during transitions
        if self.pir_blend_factor < 1.0 and self.pir_previous_state:
            prev_speed = speeds.get(self.pir_previous_state, 1.0)
            curr_speed = speeds.get(self.pir_state, 1.0)
            return prev_speed + (curr_speed - prev_speed) * self.pir_blend_factor
        
        return speeds.get(self.pir_state, 1.0)
    
    def get_pir_active_recording_name(self):
        """Get the recording filename for the current PIR state."""
        recordings = {
            'idle': self.pir_idle_recording.get(),
            'active': self.pir_active_recording.get(),
            'sleep': self.pir_sleep_recording.get()
        }
        return recordings.get(self.pir_state, "")
    
    def get_pir_active_layers(self):
        """Get the loaded layers for the current PIR state. Returns list or None."""
        recording_name = self.get_pir_active_recording_name()
        if not recording_name or recording_name == '(None)':
            return None
        return self.load_pir_recording(recording_name)
    
    # ==================== END PIR METHODS ====================

    def update_playback(self):
        """Update servo positions based on ALL layers playing simultaneously.
        
        Layer priority: Later layers completely override earlier layers for the
        servos they recorded. This allows single-servo overdubs to mask wave recordings.
        
        PIR Mode: When enabled, uses state-specific recording and speed.
        """
        if not self.is_playing:
            return
        
        # Determine which layers to play and at what speed
        if self.pir_enabled.get():
            # PIR Mode: Use state-specific recording from library
            pir_layers = self.get_pir_active_layers()
            if not pir_layers:
                return  # No recording assigned for this state
            
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
        
        # Apply positions ONLY from the owning layer for each servo
        for layer_idx, layer in enumerate(layers_to_play):
            duration = layer['duration']
            data = layer['data']
            
            if not data:
                continue
            
            # Map current time to this layer's timeline proportionally
            # All layers loop at the same rate for perfect sync
            normalized_time = (elapsed / max_duration) * duration if max_duration > 0 else 0
            
            # Find current and start positions for blending
            current_point = None
            start_point = data[0]  # First frame
            
            # Find the closest data point for current time in this layer
            for point in data:
                if point['time'] >= normalized_time:
                    current_point = point
                    break
            
            # If we didn't find a point, use the last one
            if current_point is None:
                current_point = data[-1]
            
            # Apply finger positions ONLY if this layer owns the servo
            for finger_idx in range(self.num_fingers):
                if finger_owner[finger_idx] == layer_idx:
                    current_pos = current_point['finger_positions'][finger_idx]
                    if current_pos is not None:
                        if is_blending:
                            start_pos = start_point['finger_positions'][finger_idx]
                            if start_pos is not None:
                                blended_pos = current_pos * (1 - blend_factor) + start_pos * blend_factor
                                self.finger_positions[finger_idx] = blended_pos
                            else:
                                self.finger_positions[finger_idx] = current_pos
                        else:
                            self.finger_positions[finger_idx] = current_pos
            
            # Apply arm positions ONLY if this layer owns the servo
            for arm_idx in range(self.num_arm_servos):
                if arm_owner[arm_idx] == layer_idx:
                    current_pos = current_point['arm_positions'][arm_idx]
                    if current_pos is not None:
                        if is_blending:
                            start_pos = start_point['arm_positions'][arm_idx]
                            if start_pos is not None:
                                blended_pos = current_pos * (1 - blend_factor) + start_pos * blend_factor
                                self.arm_positions[arm_idx] = blended_pos
                            else:
                                self.arm_positions[arm_idx] = current_pos
                        else:
                            self.arm_positions[arm_idx] = current_pos
        
        # Apply PIR state transition blending (smooth fade between recordings)
        if self.pir_enabled.get() and self.pir_blend_factor < 1.0 and self.pir_transition_positions:
            # Blend from stored transition positions to current computed positions
            bf = self.pir_blend_factor  # 0.0 = old positions, 1.0 = new positions
            
            # Use eased blend for smoother feel (smooth step)
            bf = bf * bf * (3 - 2 * bf)  # Hermite interpolation
            
            for i in range(self.num_fingers):
                old_pos = self.pir_transition_positions['fingers'][i]
                new_pos = self.finger_positions[i]
                self.finger_positions[i] = old_pos + (new_pos - old_pos) * bf
            
            for i in range(self.num_arm_servos):
                old_pos = self.pir_transition_positions['arm'][i]
                new_pos = self.arm_positions[i]
                self.arm_positions[i] = old_pos + (new_pos - old_pos) * bf
        
        # Apply organic variations if in Markov mode
        if self.markov_mode:
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
            self._organic_phases = [random.uniform(0, 2 * math.pi) for _ in range(8)]
            self._organic_start_time = current_time
        
        # Time since organic mode started
        t = current_time - self._organic_start_time
        
        # Calculate smooth wobble for each servo using layered sine waves
        # Different frequencies create more organic, less mechanical movement
        for i in range(8):
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
        
        # Determine which servos to record based on control mode
        if self.control_mode.get() == 'cursor':
            # Cursor mode: only record ENABLED finger positions
            finger_positions = [None] * self.num_fingers
            arm_positions = [None] * self.num_arm_servos
            # Only record fingers that have wave control enabled
            for i in range(self.num_fingers):
                if self.finger_wave_enabled[i].get():
                    finger_positions[i] = self.finger_positions[i]
                    self.recorded_servos['fingers'].add(i)
        else:
            # Manual mode: only record the selected servo
            selected = self.selected_servo.get()
            if selected < self.num_fingers:
                # Selected finger
                finger_positions = [None] * self.num_fingers
                finger_positions[selected] = self.finger_positions[selected]
                arm_positions = [None] * self.num_arm_servos
                self.recorded_servos['fingers'].add(selected)
            else:
                # Selected arm servo
                finger_positions = [None] * self.num_fingers
                arm_positions = [None] * self.num_arm_servos
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
        """Clear all recorded layers."""
        self.recorded_layers = []
        self.captured_keyframes = []  # Also clear keyframes
        self.keyframe_capture_start = None
        self.loop_duration.set(0.0)  # Reset loop duration constraint
        self.update_layer_list()
        print("🗑️ All layers and keyframes cleared - loop duration reset")
    
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
        # Update derived variables
        self.servo_limits = [tuple(lim) for lim in self.hardware_config['per_servo_limits']]
        self.servo_reversed = [i in self.hardware_config['reversed_servos'] for i in range(8)]
        self.default_port = self.hardware_config['serial_port']
        
        # Update UI elements if they exist
        if hasattr(self, 'config_name_var'):
            self.config_name_var.set(self.hardware_config['name'])
        if hasattr(self, 'config_min_var'):
            self.config_min_var.set(self.hardware_config['global_min_angle'])
        if hasattr(self, 'config_max_var'):
            self.config_max_var.set(self.hardware_config['global_max_angle'])
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
        if hasattr(self, 'config_port_var'):
            self.hardware_config['serial_port'] = self.config_port_var.get()
        if hasattr(self, 'config_reversed_vars'):
            self.hardware_config['reversed_servos'] = [
                i for i, var in enumerate(self.config_reversed_vars) if var.get()
            ]
        
        # Apply the changes
        self.apply_hardware_config()
    
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
                self.hand_controller.serial_connection.close()
                print("🔌 Closed existing connection")
            except:
                pass
        
        # Try to reconnect
        try:
            self.hand_controller = HandExpressionController(port=self.default_port, clean_output=True)
            # Test the connection by sending a center command
            self.hand_controller.set_hand_positions([90]*8)
            print(f"✅ Arduino reconnected on {self.default_port}")
            tkinter.messagebox.showinfo("Connected", f"Arduino reconnected successfully on {self.default_port}!")
        except Exception as e:
            self.hand_controller = None
            print(f"❌ Reconnect failed: {e}")
            tkinter.messagebox.showerror("Connection Failed", f"Failed to reconnect Arduino:\n{e}\n\nMake sure Arduino is plugged in and on {self.default_port}!")
    
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
    
    def update_timeline(self):
        """Update the timeline visualization."""
        self.timeline_canvas.delete("all")
        
        width = self.timeline_canvas.winfo_width()
        height = 30
        
        if width <= 1:
            return
        
        if not self.recorded_layers or not self.is_playing:
            # Draw empty timeline
            self.timeline_canvas.create_rectangle(0, 0, width, height, 
                                                  fill=self.colors['bg_dark'], outline='')
            self.timeline_canvas.create_text(width//2, height//2, 
                                            text="⏸️ Not playing" if self.recorded_layers else "No layers",
                                            fill=self.colors['text_dim'])
            return
        
        # Calculate longest layer duration
        max_duration = max(layer['duration'] for layer in self.recorded_layers)
        elapsed = time.time() - self.playback_start_time
        
        # Normalize to 0.0-1.0
        progress = (elapsed % max_duration) / max_duration if max_duration > 0 else 0
        self.playback_position = progress
        
        # Draw background
        self.timeline_canvas.create_rectangle(0, 0, width, height, 
                                              fill=self.colors['bg_dark'], outline='')
        
        # Draw layers as bars
        layer_height = height // max(len(self.recorded_layers), 1)
        for i, layer in enumerate(self.recorded_layers):
            y = i * layer_height
            layer_width = (layer['duration'] / max_duration) * width
            
            # Layer bar
            self.timeline_canvas.create_rectangle(0, y, layer_width, y + layer_height - 1,
                                                  fill='#4CAF50', outline='#2E7D32')
            
            # Layer label
            self.timeline_canvas.create_text(5, y + layer_height//2,
                                            text=layer['name'], anchor=tk.W,
                                            fill='white', font=('Arial', 7))
        
        # Draw playhead
        playhead_x = progress * width
        self.timeline_canvas.create_line(playhead_x, 0, playhead_x, height,
                                        fill='#FF5722', width=2)
        
        # Time label
        current_time = elapsed % max_duration
        self.timeline_canvas.create_text(width - 5, height - 5,
                                        text=f"{current_time:.1f}s / {max_duration:.1f}s",
                                        anchor=tk.SE, fill=self.colors['text_main'],
                                        font=('Arial', 8))
    
    def update_recording_status(self):
        """Update recording status label."""
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
        
        # Save to file
        filename = f"hand_movements_{datetime.datetime.now().strftime('%Y%m%d_%H%M%S')}.ino"
        filepath = os.path.join(os.getcwd(), filename)
        
        try:
            with open(filepath, 'w') as f:
                f.write(code)
            
            tkinter.messagebox.showinfo("Export Successful", 
                                      f"Arduino code exported to:\\n{filepath}\\n\\n" +
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
        servo_owner = [-1] * 8  # layer index that owns each servo (-1 = none)
        for layer_idx, layer in enumerate(self.recorded_layers):
            recorded_servos = layer.get('recorded_servos', {'fingers': set(), 'arm': set()})
            for finger_idx in recorded_servos.get('fingers', []):
                if finger_idx < 5:
                    servo_owner[finger_idx] = layer_idx
            for arm_idx in recorded_servos.get('arm', []):
                if arm_idx < 3:
                    servo_owner[5 + arm_idx] = layer_idx
        
        # Extract keyframes for all layers WITH TIME NORMALIZATION
        all_layer_keyframes = []
        for layer in self.recorded_layers:
            movements = sorted(layer['data'], key=lambda x: x['time'])
            keyframes = self._extract_keyframes(movements)
            
            # TIME NORMALIZE: Scale layer duration to match global loop duration
            # This ensures layers recorded at different durations sync properly
            layer_duration = layer['duration']
            if layer_duration > 0 and max_duration > 0:
                time_scale = max_duration / layer_duration
                # Scale all keyframe timestamps
                for kf in keyframes:
                    kf['time'] = kf['time'] * time_scale
            
            all_layer_keyframes.append({
                'name': layer['name'],
                'mode': layer['control_mode'],
                'duration': layer['duration'],
                'keyframes': keyframes
            })
        
        # Adjust duration by playback speed (faster speed = shorter duration)
        adjusted_duration = max_duration / playback_speed
        
        # Build ownership comment
        ownership_info = []
        servo_names = self.finger_names + self.arm_names
        for servo_idx in range(8):
            owner = servo_owner[servo_idx]
            if owner >= 0:
                ownership_info.append(f" * Servo {servo_idx} ({servo_names[servo_idx]}): Layer {owner + 1}")
        
        # Get config values for export
        min_angle = self.hardware_config['global_min_angle']
        max_angle = self.hardware_config['global_max_angle']
        reversed_servos = self.hardware_config['reversed_servos']
        pin_mapping = self.hardware_config['pin_mapping']
        
        # Build reversed servo condition for C code
        if reversed_servos:
            reversed_check = ' || '.join([f'index == {i}' for i in reversed_servos])
            reversed_names = ', '.join([self.all_servo_names[i] for i in reversed_servos if i < 8])
        else:
            reversed_check = '0'  # Never true
            reversed_names = 'none'
        
        # Build pin mapping string
        pin_str = ', '.join([str(p) for p in pin_mapping])
        
        code = f'''/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
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
 * Hardware: 5 Finger Servos + 3 Arm Servos
 * Fingers: {', '.join(self.finger_names)}
 * Arm: {', '.join(self.arm_names)}
 * 
 * Pin Mapping:
 * Pin {pin_mapping[0]} -> Thumb (servo 0)
 * Pin {pin_mapping[1]} -> Index (servo 1)
 * Pin {pin_mapping[2]} -> Middle (servo 2)
 * Pin {pin_mapping[3]} -> Ring (servo 3)
 * Pin {pin_mapping[4]} -> Pinky (servo 4)
 * Pin {pin_mapping[5]} -> Shoulder (servo 5)
 * Pin {pin_mapping[6]} -> Elbow (servo 6)
 * Pin {pin_mapping[7]} -> Wrist (servo 7)
 * 
 * Range: {min_angle}-{max_angle} degrees. Reversed servos: {reversed_names}
 */

#include <Servo.h>

// Servo objects
Servo servo[8];
int servoPins[8] = {{{pin_str}}};

// Range configuration (from hardware preset: {self.hardware_config['name']})
const int MIN_ANGLE = {min_angle};
const int MAX_ANGLE = {max_angle};

// Helper: Map 0-180 to MIN-MAX, reverse specified servos
void writeServo(int index, int pos) {{
  pos = map(pos, 0, 180, MIN_ANGLE, MAX_ANGLE);
  pos = constrain(pos, MIN_ANGLE, MAX_ANGLE);
  if({reversed_check}) pos = MAX_ANGLE - pos;  // Reverse {reversed_names}
  servo[index].write(pos);
}}

// Timing
unsigned long loopStartTime;
unsigned long loopDuration = {int(adjusted_duration * 1000)}; // milliseconds (adjusted for {playback_speed:.1f}x speed)

// Layer data structures
'''
        
        # Generate data arrays for each layer (using PROGMEM to save RAM)
        for i, layer_data in enumerate(all_layer_keyframes):
            keyframes = layer_data['keyframes']
            
            # Find which servos this layer OWNS
            layer_owned_servos = [s for s in range(8) if servo_owner[s] == i]
            
            # Skip layers that don't own any servos (no need to generate data)
            if not layer_owned_servos:
                code += f"\n// Layer {i+1}: {layer_data['name']} - MASKED by later layer(s)\n"
                continue
            
            code += f"\n// Layer {i+1}: {layer_data['name']} ({layer_data['mode']} mode) - {len(keyframes)} keyframes\n"
            code += f"const int layer{i+1}_count = {len(keyframes)};\n"
            code += f"const unsigned long layer{i+1}_times[] PROGMEM = {{"
            # Adjust keyframe times by playback speed
            code += ', '.join([str(int((kf['time'] / playback_speed) * 1000)) for kf in keyframes])
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
        code += '''
void setup() {
  Serial.begin(9600);
  
  // Attach servos
  for(int i = 0; i < 8; i++) {
    servo[i].attach(servoPins[i]);
    writeServo(i, 90);  // Center position
  }
  
  delay(1000);
  Serial.println("8-Servo Hand Control Ready - Simultaneous Playback");
  loopStartTime = millis();
}

void loop() {
  unsigned long elapsed = millis() - loopStartTime;
  
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
    elapsed = 0;
'''
        
        # Reset layer indices - ONLY for layers that OWN servos (others don't have index vars)
        for i in range(len(all_layer_keyframes)):
            # Check if this layer owns any servos
            layer_owned_servos = [s for s in range(8) if servo_owner[s] == i]
            if layer_owned_servos:
                code += f"    layer{i+1}_index = 0;\n"
        
        code += "  }\n\n"
        
        # Update each layer - ONLY for servos this layer OWNS
        for i in range(len(all_layer_keyframes)):
            layer_keyframes = all_layer_keyframes[i]['keyframes']
            
            # Only include servos that this layer OWNS (last layer to record wins)
            owned_servos = []
            for servo_idx in range(8):
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
  if(layer{i+1}_index < layer{i+1}_count - 1) {{
    unsigned long currentTime = pgm_read_dword(&layer{i+1}_times[layer{i+1}_index]);
    unsigned long nextTime = pgm_read_dword(&layer{i+1}_times[layer{i+1}_index + 1]);
    
    // Move to next keyframe if we've passed it
    if(elapsed >= nextTime) {{
      layer{i+1}_index++;
    }}
    
    // Interpolate between current and next keyframe
    if(layer{i+1}_index < layer{i+1}_count - 1 && elapsed >= currentTime) {{
      currentTime = pgm_read_dword(&layer{i+1}_times[layer{i+1}_index]);
      nextTime = pgm_read_dword(&layer{i+1}_times[layer{i+1}_index + 1]);
      
      // Calculate interpolation factor (0.0 to 1.0)
      float factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
      factor = constrain(factor, 0.0, 1.0);
      
'''
            for servo_idx in owned_servos:
                servo_name = self.finger_names[servo_idx] if servo_idx < 5 else self.arm_names[servo_idx - 5]
                code += f"      // Interpolate {servo_name}\n"
                code += f"      int curr{servo_idx} = pgm_read_word(&layer{i+1}_servo{servo_idx}[layer{i+1}_index]);\n"
                code += f"      int next{servo_idx} = pgm_read_word(&layer{i+1}_servo{servo_idx}[layer{i+1}_index + 1]);\n"
                code += f"      int start{servo_idx} = pgm_read_word(&layer{i+1}_servo{servo_idx}[0]);\n"
                code += f"      \n"
                code += f"      if(curr{servo_idx} != -1 && next{servo_idx} != -1) {{\n"
                code += f"        int interpolated = curr{servo_idx} + (int)((next{servo_idx} - curr{servo_idx}) * factor);\n"
                code += f"        \n"
                code += f"        // Apply blend zone for smooth looping\n"
                code += f"        if(isBlending && start{servo_idx} != -1) {{\n"
                code += f"          interpolated = interpolated * (1.0 - blendFactor) + start{servo_idx} * blendFactor;\n"
                code += f"        }}\n"
                code += f"        \n"
                code += f"        writeServo({servo_idx}, interpolated);\n"
                code += f"      }} else if(curr{servo_idx} != -1) {{\n"
                code += f"        int pos = curr{servo_idx};\n"
                code += f"        \n"
                code += f"        // Apply blend zone for smooth looping\n"
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
        dialog.title("Markov Chain Export Configuration")
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
        pir_pin = tk.IntVar(value=3)
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
        
        tk.Button(phrase_frame, text="➕ Add Phrase from File", command=add_phrase,
                 bg=self.colors['button_bg']).pack(pady=5)
        
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
                
                tkinter.messagebox.showinfo("Markov Export Successful", 
                                          f"Arduino code with Markov chain exported to:\n{filepath}\n\n" +
                                          f"Phrases: {len(phrase_files) + 1}\n" +
                                          f"PIR Sensor: {'Enabled' if pir_enable.get() else 'Disabled'}")
                print(f"🎲 Markov Arduino code exported to {filepath}")
                
            except Exception as e:
                tkinter.messagebox.showerror("Export Failed", f"Failed to export Arduino code:\n{e}")
        
        button_frame = tk.Frame(dialog, bg=self.colors['bg_main'])
        button_frame.pack(fill=tk.X, padx=10, pady=10)
        
        tk.Button(button_frame, text="✅ Export", command=do_export,
                 bg=self.colors['button_bg'], font=('Arial', 10, 'bold')).pack(side=tk.LEFT, padx=5)
        tk.Button(button_frame, text="❌ Cancel", command=dialog.destroy,
                 bg=self.colors['button_bg']).pack(side=tk.LEFT, padx=5)
    
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
        
        # Build simple uniform transition matrix (each phrase can transition to any other with equal probability)
        # In the future, this could analyze temporal patterns to build smarter transitions
        
        # Get config values for export
        min_angle = self.hardware_config['global_min_angle']
        max_angle = self.hardware_config['global_max_angle']
        reversed_servos = self.hardware_config['reversed_servos']
        pin_mapping = self.hardware_config['pin_mapping']
        
        # Build reversed servo condition for C code
        if reversed_servos:
            reversed_check = ' || '.join([f'index == {i}' for i in reversed_servos])
            reversed_names = ', '.join([self.all_servo_names[i] for i in reversed_servos if i < 8])
        else:
            reversed_check = '0'
            reversed_names = 'none'
        
        # Build pin mapping string
        pin_str = ', '.join([str(p) for p in pin_mapping])
        
        code = f'''/*
 * 8-Servo Hand Control - Markov Chain Phrase System
 * Generated: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}
 * Hardware Config: {self.hardware_config['name']}
 * Phrases: {num_phrases}
 * PIR Sensor: {"Enabled on pin " + str(pir_pin) if pir_enabled else "Disabled"}
 * 
 * This sketch uses Markov chains to randomly transition between
 * recorded movement phrases, creating organic, non-repetitive behavior.
 * 
 * Hardware: 5 Finger Servos + 3 Arm Servos
 * Pin Mapping:
 * Pin {pin_mapping[0]} -> Thumb (servo 0)
 * Pin {pin_mapping[1]} -> Index (servo 1)
 * Pin {pin_mapping[2]} -> Middle (servo 2)
 * Pin {pin_mapping[3]} -> Ring (servo 3)
 * Pin {pin_mapping[4]} -> Pinky (servo 4)
 * Pin {pin_mapping[5]} -> Shoulder (servo 5)
 * Pin {pin_mapping[6]} -> Elbow (servo 6)
 * Pin {pin_mapping[7]} -> Wrist (servo 7)
 * 
 * Range: {min_angle}-{max_angle} degrees. Reversed servos: {reversed_names}
 */

#include <Servo.h>

// Servo objects
Servo servo[8];
int servoPins[8] = {{{pin_str}}};

// Range configuration (from hardware preset: {self.hardware_config['name']})
const int MIN_ANGLE = {min_angle};
const int MAX_ANGLE = {max_angle};

// Helper: Map 0-180 to MIN-MAX, reverse specified servos
void writeServo(int index, int pos) {{
  pos = map(pos, 0, 180, MIN_ANGLE, MAX_ANGLE);
  pos = constrain(pos, MIN_ANGLE, MAX_ANGLE);
  if({reversed_check}) pos = MAX_ANGLE - pos;  // Reverse {reversed_names}
  servo[index].write(pos);
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
            phrase_servo_owner = [-1] * 8
            for layer_idx, layer in enumerate(phrase['layers']):
                recorded_servos = layer.get('recorded_servos', {'fingers': set(), 'arm': set()})
                for finger_idx in recorded_servos.get('fingers', []):
                    if finger_idx < 5:
                        phrase_servo_owner[finger_idx] = layer_idx
                for arm_idx in recorded_servos.get('arm', []):
                    if arm_idx < 3:
                        phrase_servo_owner[5 + arm_idx] = layer_idx
            
            # Extract keyframes for all layers WITH TIME NORMALIZATION
            all_layer_keyframes = []
            for layer in phrase['layers']:
                movements = sorted(layer['data'], key=lambda x: x['time'])
                keyframes = self._extract_keyframes(movements)
                
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
                owned_servos = [s for s in range(8) if phrase_servo_owner[s] == layer_idx]
                
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
        code += '''void setup() {
  Serial.begin(9600);
  
  // Attach servos
  for(int i = 0; i < 8; i++) {
    servo[i].attach(servoPins[i]);
    writeServo(i, 90);  // Center position
  }
  
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
            code += '''  // Check PIR sensor
  if(digitalRead(PIR_PIN) == HIGH) {
    motionDetected = true;
    lastMotionTime = millis();
  }
  
  // Check motion timeout
  if(motionDetected && (millis() - lastMotionTime > MOTION_TIMEOUT)) {
    motionDetected = false;
    Serial.println("No motion detected - pausing");
    // Return to center position
    for(int i = 0; i < 8; i++) {
      writeServo(i, 90);
    }
    delay(100);
    return;
  }
  
  // Only play phrases if motion detected
  if(!motionDetected) {
    delay(100);
    return;
  }
  
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
            servo_owner = phrase.get('servo_owner', [-1] * 8)
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
                owned_servos = [s for s in range(8) if servo_owner[s] == layer_idx]
                
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
        
        # Create finger position bars
        self.finger_bars = []
        self.finger_clamp_markers = []
        self.finger_label_ids = []
        bar_width = 40  # Slightly wider bars
        bar_spacing = 62  # More spacing
        start_x = 35
        
        for i in range(self.num_fingers):
            x = start_x + (i * bar_spacing)
            
            # Background bar (full range) - taller bars
            bg_bar = self.canvas.create_rectangle(
                x, top_y, x + bar_width, bottom_y,
                fill='#E0E0E0', outline='#CCCCCC', width=1
            )
            
            # Position indicator bar
            pos_bar = self.canvas.create_rectangle(
                x, bottom_y - usable_h // 2, x + bar_width, bottom_y - usable_h // 2,
                fill='#4CAF50', outline='#45A049', width=1
            )

            # Clamp markers (min=max full range by default; updated live)
            min_marker = self.canvas.create_line(
                x, bottom_y, x + bar_width, bottom_y,
                fill='#0D47A1', width=2, dash=(3, 2)
            )
            max_marker = self.canvas.create_line(
                x, top_y, x + bar_width, top_y,
                fill='#B71C1C', width=2, dash=(3, 2)
            )
            
            # Label
            label_id = self.canvas.create_text(
                x + bar_width//2, bottom_y + 22,
                text=self.finger_names[i][:3],  # Short name
                font=('Arial', 8), fill='#333333'
            )
            
            self.finger_bars.append((bg_bar, pos_bar))
            self.finger_clamp_markers.append((min_marker, max_marker))
            self.finger_label_ids.append(label_id)
        
        # Create arm servo indicators (smaller, on the right)
        self.arm_indicators = []
        self.arm_label_ids = []
        self.arm_range_text_ids = []
        arm_start_x = start_x + (self.num_fingers * bar_spacing) + 12
        
        for i in range(self.num_arm_servos):
            y = top_y + (i * 58)
            
            # Small circular indicator
            indicator = self.canvas.create_oval(
                arm_start_x, y, arm_start_x + 15, y + 15,
                fill='#FF9800', outline='#F57C00', width=1
            )
            
            # Label
            label_id = self.canvas.create_text(
                arm_start_x - 5, y + 7,
                text=self.arm_names[i][:2],  # Very short name
                font=('Arial', 7), fill='#333333', anchor='e'
            )

            range_text_id = self.canvas.create_text(
                arm_start_x + 20, y + 7,
                text="0-180",
                font=('Arial', 7), fill='#666666', anchor='w'
            )
            
            self.arm_indicators.append(indicator)
            self.arm_label_ids.append(label_id)
            self.arm_range_text_ids.append(range_text_id)
        
        # Add instructions
        self.canvas.create_text(
            min(canvas_w // 2, 190), 14,
            text="Move mouse here for finger control",
            font=('Arial', 10), fill='#666666'
        )
        
        # Add current mode indicator
        self.mode_text = self.canvas.create_text(
            min(canvas_w // 2, 190), canvas_h - 18,
            text="Mode: Cursor Wave Control",
            font=('Arial', 9, 'bold'), fill='#2196F3'
        )
    
    def update_visual_feedback(self):
        """Update the visual feedback based on current servo positions."""
        # Update finger bars
        for i, (bg_bar, pos_bar) in enumerate(self.finger_bars):
            if i < len(self.finger_positions):
                # Convert angle (0-180) to bar position (30-200)
                angle = self.finger_positions[i]
                coords = self.canvas.coords(bg_bar)
                x_left, y_top, x_right, y_bottom = coords
                total_h = max(1, int(y_bottom - y_top))
                bar_height = int((angle / 180.0) * total_h)
                
                bar_top = y_bottom - bar_height  # Invert so 0° is at bottom
                bar_bottom = y_bottom
                x = x_left
                bar_width = x_right - x_left
                
                # Update position bar
                self.canvas.coords(pos_bar, x, bar_top, x + bar_width, bar_bottom)

                # Update clamp markers on full-scale bar (always 0-180 visual)
                min_lim, max_lim = self.servo_limits[i]
                min_y = y_bottom - int((min_lim / 180.0) * total_h)
                max_y = y_bottom - int((max_lim / 180.0) * total_h)
                min_marker, max_marker = self.finger_clamp_markers[i]
                self.canvas.coords(min_marker, x, min_y, x + bar_width, min_y)
                self.canvas.coords(max_marker, x, max_y, x + bar_width, max_y)

                # Show reverse state and disabled state directly on finger label
                label = self.finger_names[i][:3]
                if self.servo_reversed[i]:
                    label += "↺"
                if not self.finger_wave_enabled[i].get():
                    label += "○"  # Circle indicates disabled from wave
                self.canvas.itemconfig(self.finger_label_ids[i], text=label)
                
                # Color based on angle (muted if disabled from wave)
                wave_enabled = self.finger_wave_enabled[i].get()
                if not wave_enabled:
                    color = '#888888'  # Gray for disabled fingers
                elif 70 <= angle <= 110:  # Near center
                    color = '#4CAF50'  # Green
                elif angle < 70:
                    color = '#2196F3'  # Blue
                else:
                    color = '#FF5722'  # Red
                
                self.canvas.itemconfig(pos_bar, fill=color)
        
        # Update arm indicators (change size based on position)
        for i, indicator in enumerate(self.arm_indicators):
            if i < len(self.arm_positions):
                angle = self.arm_positions[i]
                # Size based on angle (10-20 pixels)
                size = 10 + int((angle / 180.0) * 10)
                
                coords = self.canvas.coords(indicator)
                arm_start_x = coords[0]
                y = coords[1]
                
                self.canvas.coords(indicator, 
                                 arm_start_x, y, 
                                 arm_start_x + size, y + size)
                
                # Color based on angle
                if 70 <= angle <= 110:
                    color = '#FF9800'  # Orange
                elif angle < 70:
                    color = '#3F51B5'  # Indigo
                else:
                    color = '#E91E63'  # Pink
                
                self.canvas.itemconfig(indicator, fill=color)

                # Update arm label and clamp text
                servo_idx = self.num_fingers + i
                arm_label = self.arm_names[i][:2]
                if self.servo_reversed[servo_idx]:
                    arm_label += "↺"
                self.canvas.itemconfig(self.arm_label_ids[i], text=arm_label)

                min_lim, max_lim = self.servo_limits[servo_idx]
                self.canvas.itemconfig(self.arm_range_text_ids[i], text=f"{min_lim}-{max_lim}")
        
        # Update mode indicator
        mode = self.control_mode.get()
        mode_text = "Mode: Cursor Wave Control" if mode == "cursor" else "Mode: Individual Servo Control"
        self.canvas.itemconfig(self.mode_text, text=mode_text)


def main():
    """Main function to start the simple hand control interface."""
    print("[START] Starting Simple 8-Servo Hand Control...")
    
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