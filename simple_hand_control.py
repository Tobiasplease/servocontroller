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
import time
import math
import os
import json
import datetime
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
        self.root.geometry("1000x900")
        
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
        
        # Per-servo range calibration (min, max) - allows different physical ranges
        # Wrist servo needs wider electronic range to get same physical movement
        self.servo_limits = [
            (0, 180),   # Thumb
            (0, 180),   # Index
            (0, 180),   # Middle
            (0, 180),   # Ring
            (0, 180),   # Pinky
            (0, 180),   # Shoulder
            (0, 180),   # Elbow
            (0, 180),   # Wrist - full range for smaller servo
        ]
        
        # Initialize positions
        self.finger_positions = [90.0] * self.num_fingers
        self.arm_positions = [90.0] * self.num_arm_servos
        
        # Control parameters
        self.cursor_sensitivity = tk.DoubleVar(value=2.0)
        self.servo_range = tk.DoubleVar(value=80.0)
        self.wave_gravity = tk.DoubleVar(value=0.5)  # How much Y position affects all fingers
        self.wave_offset = tk.DoubleVar(value=0.0)   # Base offset for all fingers
        
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
        
        # Keyframe capture system
        self.captured_keyframes = []
        self.keyframe_capture_start = None
        
        # Control mode
        self.control_mode = tk.StringVar(value="cursor")
        self.hover_mode = tk.BooleanVar(value=False)  # Toggle for hover control
        
        # Hardware controller
        self.hand_controller = None
        if HAND_CONTROLLER_AVAILABLE:
            try:
                self.hand_controller = HandExpressionController(port='COM9', clean_output=True)
            except Exception as e:
                print(f"[WARNING] Could not initialize hand controller: {e}")
        
        # Create GUI
        self.create_interface()
        
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
        
        # Create two main areas side by side
        content_frame = tk.Frame(main_frame, bg=self.colors['bg_main'])
        content_frame.pack(fill=tk.BOTH, expand=True)
        
        # Left side - Cursor control
        self.cursor_frame = tk.LabelFrame(content_frame, text="Cursor Wave Control", 
                                         bg=self.colors['bg_frame'], fg=self.colors['text_main'])
        self.cursor_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True, padx=(0, 5))
        
        # Canvas for cursor control with visual feedback
        self.canvas = tk.Canvas(self.cursor_frame, width=280, height=250, 
                               bg=self.colors['canvas_bg'])
        self.canvas.pack(pady=10)
        self.canvas.bind("<Motion>", self.on_mouse_move)
        
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
        
        tk.Label(param_frame1, text="Range:", bg=self.colors['bg_frame'],
                font=('Arial', 8)).pack(side=tk.LEFT, padx=(10,0))
        tk.Scale(param_frame1, from_=10.0, to=180.0, resolution=5.0, orient=tk.HORIZONTAL,
                variable=self.servo_range, length=100,
                font=('Arial', 8)).pack(side=tk.LEFT, padx=5)
        
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
        all_names = self.finger_names + self.arm_names
        
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
        viz_frame = tk.LabelFrame(control_frame, text="All Servos (Read-Only)",
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
        """Create small read-only bars for all servos."""
        self.small_bars = []
        all_names = self.finger_names + self.arm_names
        
        for i, name in enumerate(all_names):
            frame = tk.Frame(self.viz_frame_inner, bg=self.colors['bg_main'])
            frame.pack(fill=tk.X, pady=3)
            
            # Label
            tk.Label(frame, text=f"{name}:", width=10, anchor='w',
                    bg=self.colors['bg_main'], font=('Arial', 9)).pack(side=tk.LEFT, padx=5)
            
            # Small bar canvas
            bar_canvas = tk.Canvas(frame, width=150, height=20, 
                                  bg='#e0e0e0', highlightthickness=1)
            bar_canvas.pack(side=tk.LEFT, padx=5)
            
            # Fill bar
            fill = bar_canvas.create_rectangle(0, 0, 0, 20, fill='#4CAF50', outline='')
            
            # Value label
            value_label = tk.Label(frame, text="90°", width=5, anchor='w',
                                  bg=self.colors['bg_main'], font=('Arial', 9, 'bold'))
            value_label.pack(side=tk.LEFT, padx=5)
            
            self.small_bars.append({
                'canvas': bar_canvas,
                'fill': fill,
                'label': value_label
            })
    
    def on_servo_select(self, event=None):
        """Handle servo selection change."""
        self.selected_servo.set(self.servo_selector.current())
        all_names = self.finger_names + self.arm_names
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
        bar_height = 350
        
        coords = self.large_bar_canvas.coords(self.large_bar_rect)
        if len(coords) == 4:
            x1, y1, x2, y2 = coords
            fill_height = (pos / 180.0) * bar_height
            
            self.large_bar_canvas.coords(self.large_bar_fill,
                x1, y2 - fill_height, x2, y2)
            
            # Color coding
            if pos < 60:
                color = '#2196F3'
            elif pos > 120:
                color = '#f44336'
            else:
                color = '#4CAF50'
                
            self.large_bar_canvas.itemconfig(self.large_bar_fill, fill=color)
            self.large_bar_canvas.itemconfig(self.large_bar_value, text=f"{int(pos)}°")
    
    def update_small_servo_bars(self):
        """Update all small servo bars."""
        all_positions = list(self.finger_positions) + list(self.arm_positions)
        
        for i, bar_info in enumerate(self.small_bars):
            if i >= len(all_positions):
                continue
                
            pos = all_positions[i]
            bar_width = (pos / 180.0) * 150
            
            bar_info['canvas'].coords(bar_info['fill'], 0, 0, bar_width, 20)
            
            if pos < 60:
                color = '#2196F3'
            elif pos > 120:
                color = '#f44336'
            else:
                color = '#4CAF50'
                
            bar_info['canvas'].itemconfig(bar_info['fill'], fill=color)
            bar_info['label'].config(text=f"{int(pos)}°")
    
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
            angle = 180 - (normalized * 180)
            angle = max(0, min(180, angle))
            
            servo_idx = self.selected_servo.get()
            
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
            # Create wave pattern across fingers
            finger_offset = (i / max(self.num_fingers - 1, 1)) - 0.5  # -0.5 to 0.5
            
            # Wave influence from X position
            wave_influence = math.sin((x_norm + finger_offset) * math.pi * sensitivity)
            
            # Gravity pull from Y position (0=top pulls up, 1=bottom pulls down)
            gravity_pull = (y_norm - 0.5) * 2  # -1 (top) to 1 (bottom)
            
            # Combine: wave creates the pattern, gravity pulls everything up/down
            total_influence = wave_influence * (1.0 - gravity) + gravity_pull * gravity
            
            # Convert to servo angle with base offset
            angle = 90 + offset + (total_influence * servo_range / 2)
            angle = max(0, min(180, angle))
            
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
            self.finger_positions[servo_index] = angle
            print(f"🎛️ {self.finger_names[servo_index]}: {angle}°")
        else:
            arm_index = servo_index - self.num_fingers
            self.arm_positions[arm_index] = angle
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
        
        try:
            self.hand_controller.set_hand_positions(all_positions)
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
        
        if self.is_playing:
            # Start playing ALL recorded layers simultaneously
            self.playback_start_time = time.time()
            self.playback_index = 0
            self.playback_btn.config(text="⏹️ Stop", bg='#ffcccc')
            print(f"▶️ Playing {len(self.recorded_layers)} layers simultaneously")
        else:
            # Stop playback
            self.is_playing = False
            self.playback_layer = None
            self.playback_btn.config(text="▶️ Play", bg=self.colors['button_bg'])
            print("⏹️ Playback stopped")
        
        self.update_timeline()
    
    def update_playback(self):
        """Update servo positions based on ALL layers playing simultaneously."""
        if not self.is_playing or not self.recorded_layers:
            return
        
        # Apply playback speed multiplier
        elapsed = (time.time() - self.playback_start_time) * self.playback_speed.get()
        
        # Get loop duration (fixed or auto)
        fixed_duration = self.loop_duration.get()
        if fixed_duration > 0:
            max_duration = fixed_duration
        else:
            # Auto mode: use longest layer
            max_duration = max(layer['duration'] for layer in self.recorded_layers)
        
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
        
        # Apply positions from ALL layers simultaneously
        for layer in self.recorded_layers:
            duration = layer['duration']
            data = layer['data']
            recorded_servos = layer.get('recorded_servos', {'fingers': set(), 'arm': set()})
            
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
            
            # Apply positions with optional blending
            for finger_idx in recorded_servos.get('fingers', []):
                if finger_idx < len(self.finger_positions):
                    current_pos = current_point['finger_positions'][finger_idx]
                    if current_pos is not None:
                        if is_blending:
                            # Blend between current position and start position
                            start_pos = start_point['finger_positions'][finger_idx]
                            if start_pos is not None:
                                blended_pos = current_pos * (1 - blend_factor) + start_pos * blend_factor
                                self.finger_positions[finger_idx] = blended_pos
                            else:
                                self.finger_positions[finger_idx] = current_pos
                        else:
                            self.finger_positions[finger_idx] = current_pos
            
            for arm_idx in recorded_servos.get('arm', []):
                if arm_idx < len(self.arm_positions):
                    current_pos = current_point['arm_positions'][arm_idx]
                    if current_pos is not None:
                        if is_blending:
                            # Blend between current position and start position
                            start_pos = start_point['arm_positions'][arm_idx]
                            if start_pos is not None:
                                blended_pos = current_pos * (1 - blend_factor) + start_pos * blend_factor
                                self.arm_positions[arm_idx] = blended_pos
                            else:
                                self.arm_positions[arm_idx] = current_pos
                        else:
                            self.arm_positions[arm_idx] = current_pos
    
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
            # Cursor mode: only record finger positions
            finger_positions = self.finger_positions.copy()
            arm_positions = [None] * self.num_arm_servos
            # Mark all fingers as recorded
            for i in range(self.num_fingers):
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
                self.hand_controller.serial.close()
                print("🔌 Closed existing connection")
            except:
                pass
        
        # Try to reconnect
        try:
            self.hand_controller = HandExpressionController(port='COM9', clean_output=True)
            # Test the connection by sending a center command
            self.hand_controller.set_hand_positions([90]*8)
            print("✅ Arduino reconnected on COM9")
            tkinter.messagebox.showinfo("Connected", "Arduino reconnected successfully on COM9!")
        except Exception as e:
            self.hand_controller = None
            print(f"❌ Reconnect failed: {e}")
            tkinter.messagebox.showerror("Connection Failed", f"Failed to reconnect Arduino:\n{e}\n\nMake sure Arduino is plugged in and on COM9!")
    
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
        """Generate complete Arduino code from recorded layers with SIMULTANEOUS playback."""
        # Calculate keyframe counts
        total_frames = sum(len(layer['data']) for layer in self.recorded_layers)
        
        # Get current playback speed setting
        playback_speed = self.playback_speed.get()
        
        # Determine global loop duration (use loop_duration if set, otherwise max of all layers)
        if self.loop_duration.get() > 0:
            max_duration = self.loop_duration.get()
        else:
            max_duration = max(layer['duration'] for layer in self.recorded_layers) if self.recorded_layers else 0
        
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
        
        code = f'''/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}
 * Layers: {len(self.recorded_layers)}
 * Original Frames Recorded: {total_frames}
 * Loop Duration: {max_duration:.2f}s (recorded) / {adjusted_duration:.2f}s (at {playback_speed:.1f}x speed)
 * Playback Speed: {playback_speed:.1f}x
 * 
 * Hardware: 5 Finger Servos + 3 Arm Servos
 * Fingers: {', '.join(self.finger_names)}
 * Arm: {', '.join(self.arm_names)}
 * 
 * Pin Mapping (reversed order):
 * Pin 12 -> Thumb (servo 0)
 * Pin 11 -> Index (servo 1)
 * Pin 10 -> Middle (servo 2)
 * Pin 9  -> Ring (servo 3)
 * Pin 8  -> Pinky (servo 4)
 * Pin 7  -> Shoulder (servo 5)
 * Pin 6  -> Elbow (servo 6)
 * Pin 5  -> Wrist (servo 7)
 */

#include <Servo.h>

// Servo objects
Servo servo[8];
int servoPins[8] = {{12, 11, 10, 9, 8, 7, 6, 5}};

// Timing
unsigned long loopStartTime;
unsigned long loopDuration = {int(adjusted_duration * 1000)}; // milliseconds (adjusted for {playback_speed:.1f}x speed)

// Layer data structures
'''
        
        # Generate data arrays for each layer (using PROGMEM to save RAM)
        for i, layer_data in enumerate(all_layer_keyframes):
            keyframes = layer_data['keyframes']
            code += f"\n// Layer {i+1}: {layer_data['name']} ({layer_data['mode']} mode) - {len(keyframes)} keyframes\n"
            code += f"const int layer{i+1}_count = {len(keyframes)};\n"
            code += f"const unsigned long layer{i+1}_times[] PROGMEM = {{"
            # Adjust keyframe times by playback speed
            code += ', '.join([str(int((kf['time'] / playback_speed) * 1000)) for kf in keyframes])
            code += "};\n"
            
            # Generate position arrays for each servo (8 servos) - only if servo is actually used
            for servo_idx in range(8):
                # Check if this servo is used in this layer
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
                    code += f"const int layer{i+1}_servo{servo_idx}[] PROGMEM = {{"
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
    servo[i].write(90);
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
        
        # Reset all layer indices
        for i in range(len(all_layer_keyframes)):
            code += f"    layer{i+1}_index = 0;\n"
        
        code += "  }\n\n"
        
        # Update each layer
        for i in range(len(all_layer_keyframes)):
            layer_keyframes = all_layer_keyframes[i]['keyframes']
            
            # Check which servos are used in this layer
            used_servos = []
            for servo_idx in range(8):
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
                    used_servos.append(servo_idx)
            
            code += f'''  // Update layer {i+1} with interpolation
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
            for servo_idx in used_servos:
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
                code += f"        servo[{servo_idx}].write(interpolated);\n"
                code += f"      }} else if(curr{servo_idx} != -1) {{\n"
                code += f"        int pos = curr{servo_idx};\n"
                code += f"        \n"
                code += f"        // Apply blend zone for smooth looping\n"
                code += f"        if(isBlending && start{servo_idx} != -1) {{\n"
                code += f"          pos = pos * (1.0 - blendFactor) + start{servo_idx} * blendFactor;\n"
                code += f"        }}\n"
                code += f"        \n"
                code += f"        servo[{servo_idx}].write(pos);\n"
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
        pir_pin = tk.IntVar(value=2)
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
        
        code = f'''/*
 * 8-Servo Hand Control - Markov Chain Phrase System
 * Generated: {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}
 * Phrases: {num_phrases}
 * PIR Sensor: {"Enabled on pin " + str(pir_pin) if pir_enabled else "Disabled"}
 * 
 * This sketch uses Markov chains to randomly transition between
 * recorded movement phrases, creating organic, non-repetitive behavior.
 * 
 * Hardware: 5 Finger Servos + 3 Arm Servos
 * Pin Mapping (reversed order):
 * Pin 12 -> Thumb (servo 0)
 * Pin 11 -> Index (servo 1)
 * Pin 10 -> Middle (servo 2)
 * Pin 9  -> Ring (servo 3)
 * Pin 8  -> Pinky (servo 4)
 * Pin 7  -> Shoulder (servo 5)
 * Pin 6  -> Elbow (servo 6)
 * Pin 5  -> Wrist (servo 7)
 */

#include <Servo.h>

// Servo objects
Servo servo[8];
int servoPins[8] = {{12, 11, 10, 9, 8, 7, 6, 5}};

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
            
            # Generate layer data structures
            for layer_idx, layer_data in enumerate(all_layer_keyframes):
                keyframes = layer_data['keyframes']
                code += f"const int phrase{phrase_idx}_layer{layer_idx}_count = {len(keyframes)};\n"
                code += f"const unsigned long phrase{phrase_idx}_layer{layer_idx}_times[] PROGMEM = {{"
                code += ', '.join([str(int(kf['time'] * 1000)) for kf in keyframes])
                code += "};\n"
                
                # Generate position arrays for each servo (only if used)
                for servo_idx in range(8):
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
            
            code += f"int phrase{phrase_idx}_layer_indices[{len(all_layer_keyframes)}];\n\n"
        
        # Setup function
        code += '''void setup() {
  Serial.begin(9600);
  
  // Attach servos
  for(int i = 0; i < 8; i++) {
    servo[i].attach(servoPins[i]);
    servo[i].write(90);
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
      servo[i].write(90);
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
            num_layers = len(phrases[phrase_idx]['layers'])
            code += f"    if(currentPhrase == {phrase_idx}) {{ for(int i = 0; i < {num_layers}; i++) phrase{phrase_idx}_layer_indices[i] = 0; }}\n"
        
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
            all_layer_keyframes = []
            for layer in phrase['layers']:
                movements = sorted(layer['data'], key=lambda x: x['time'])
                keyframes = self._extract_keyframes(movements)
                
                layer_duration = layer['duration']
                max_duration = phrase['loop_duration']
                if layer_duration > 0 and max_duration > 0:
                    time_scale = max_duration / layer_duration
                    for kf in keyframes:
                        kf['time'] = kf['time'] * time_scale
                
                all_layer_keyframes.append(keyframes)
            
            code += f"    case {phrase_idx}:\n"
            code += f"      playPhrase{phrase_idx}(elapsed);\n"
            code += f"      break;\n"
        
        code += '''  }
}

'''
        
        # Generate individual phrase playback functions
        for phrase_idx, phrase in enumerate(phrases):
            all_layer_keyframes = []
            for layer in phrase['layers']:
                movements = sorted(layer['data'], key=lambda x: x['time'])
                keyframes = self._extract_keyframes(movements)
                
                layer_duration = layer['duration']
                max_duration = phrase['loop_duration']
                if layer_duration > 0 and max_duration > 0:
                    time_scale = max_duration / layer_duration
                    for kf in keyframes:
                        kf['time'] = kf['time'] * time_scale
                
                all_layer_keyframes.append({
                    'keyframes': keyframes
                })
            
            code += f"void playPhrase{phrase_idx}(unsigned long elapsed) {{\n"
            code += f"  unsigned long blendZone = phrase{phrase_idx}_duration / 10;\n"
            code += f"  bool isBlending = elapsed >= (phrase{phrase_idx}_duration - blendZone);\n"
            code += f"  float blendFactor = isBlending ? (float)(elapsed - (phrase{phrase_idx}_duration - blendZone)) / blendZone : 0;\n\n"
            
            # Generate layer playback code
            for layer_idx, layer_data in enumerate(all_layer_keyframes):
                keyframes = layer_data['keyframes']
                code += f"  // Layer {layer_idx}\n"
                code += f"  if(phrase{phrase_idx}_layer_indices[{layer_idx}] < phrase{phrase_idx}_layer{layer_idx}_count - 1) {{\n"
                code += f"    unsigned long currentTime = pgm_read_dword(&phrase{phrase_idx}_layer{layer_idx}_times[phrase{phrase_idx}_layer_indices[{layer_idx}]]);\n"
                code += f"    unsigned long nextTime = pgm_read_dword(&phrase{phrase_idx}_layer{layer_idx}_times[phrase{phrase_idx}_layer_indices[{layer_idx}] + 1]);\n"
                code += f"    \n"
                code += f"    if(elapsed >= nextTime) {{\n"
                code += f"      phrase{phrase_idx}_layer_indices[{layer_idx}]++;\n"
                code += f"    }}\n"
                code += f"    \n"
                code += f"    float factor = (elapsed >= currentTime && nextTime > currentTime) ? (float)(elapsed - currentTime) / (nextTime - currentTime) : 0;\n"
                code += f"    if(factor > 1.0) factor = 1.0;\n\n"
                
                # Check which servos are used in this layer
                used_servos = set()
                for kf in keyframes:
                    for servo_idx in range(8):
                        if servo_idx < 5:
                            pos = kf['finger_positions'][servo_idx]
                        else:
                            pos = kf['arm_positions'][servo_idx - 5]
                        if pos is not None:
                            used_servos.add(servo_idx)
                
                # Generate interpolation code for each used servo
                for servo_idx in sorted(used_servos):
                    code += f"    // Servo {servo_idx}\n"
                    code += f"    int curr{servo_idx} = pgm_read_word(&phrase{phrase_idx}_layer{layer_idx}_servo{servo_idx}[phrase{phrase_idx}_layer_indices[{layer_idx}]]);\n"
                    code += f"    int next{servo_idx} = pgm_read_word(&phrase{phrase_idx}_layer{layer_idx}_servo{servo_idx}[phrase{phrase_idx}_layer_indices[{layer_idx}] + 1]);\n"
                    code += f"    int start{servo_idx} = pgm_read_word(&phrase{phrase_idx}_layer{layer_idx}_servo{servo_idx}[0]);\n"
                    code += f"    if(curr{servo_idx} != -1 && next{servo_idx} != -1) {{\n"
                    code += f"      int interpolated = curr{servo_idx} + (int)((next{servo_idx} - curr{servo_idx}) * factor);\n"
                    code += f"      if(isBlending && start{servo_idx} != -1) {{\n"
                    code += f"        interpolated = interpolated * (1.0 - blendFactor) + start{servo_idx} * blendFactor;\n"
                    code += f"      }}\n"
                    code += f"      servo[{servo_idx}].write(interpolated);\n"
                    code += f"    }}\n\n"
                
                code += f"  }}\n\n"
            
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
        
        # Create finger position bars
        self.finger_bars = []
        bar_width = 30
        bar_spacing = 50
        start_x = 25
        
        for i in range(self.num_fingers):
            x = start_x + (i * bar_spacing)
            
            # Background bar (full range) - taller bars
            bg_bar = self.canvas.create_rectangle(
                x, 30, x + bar_width, 200,
                fill='#E0E0E0', outline='#CCCCCC', width=1
            )
            
            # Position indicator bar
            pos_bar = self.canvas.create_rectangle(
                x, 115, x + bar_width, 115,
                fill='#4CAF50', outline='#45A049', width=1
            )
            
            # Label
            self.canvas.create_text(
                x + bar_width//2, 215,
                text=self.finger_names[i][:3],  # Short name
                font=('Arial', 8), fill='#333333'
            )
            
            self.finger_bars.append((bg_bar, pos_bar))
        
        # Create arm servo indicators (smaller, on the right)
        self.arm_indicators = []
        arm_start_x = 280
        
        for i in range(self.num_arm_servos):
            y = 30 + (i * 50)
            
            # Small circular indicator
            indicator = self.canvas.create_oval(
                arm_start_x, y, arm_start_x + 15, y + 15,
                fill='#FF9800', outline='#F57C00', width=1
            )
            
            # Label
            self.canvas.create_text(
                arm_start_x - 5, y + 7,
                text=self.arm_names[i][:2],  # Very short name
                font=('Arial', 7), fill='#333333', anchor='e'
            )
            
            self.arm_indicators.append(indicator)
        
        # Add instructions
        self.canvas.create_text(
            150, 10,
            text="Move mouse here for finger control",
            font=('Arial', 10), fill='#666666'
        )
        
        # Add current mode indicator
        self.mode_text = self.canvas.create_text(
            150, 235,
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
                bar_height = int((angle / 180.0) * 170)  # 0-170 pixel height
                
                bar_top = 200 - bar_height  # Invert so 0° is at bottom
                bar_bottom = 200
                
                x = 25 + (i * 50)
                
                # Update position bar
                self.canvas.coords(pos_bar, x, bar_top, x + 30, bar_bottom)
                
                # Color based on angle
                if 70 <= angle <= 110:  # Near center
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
                
                arm_start_x = 280
                y = 50 + (i * 40)
                
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