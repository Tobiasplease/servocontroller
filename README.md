# Hand Control Standalone - 8-Servo Hand Controller

Complete standalone interface for controlling an 8-servo robotic hand (5 fingers + 3 arm servos) with Arduino.

## Features

### Core Control
- **8-Servo Control**: 5 finger servos (Thumb, Index, Middle, Ring, Pinky) + 3 arm servos (Shoulder, Elbow, Wrist)
- **Cursor Wave Control**: Move mouse over canvas to control finger movements with wave physics
- **Individual Servo Control**: Direct control via sliders or keyboard shortcuts
- **Real-time Hardware Communication**: Serial connection to Arduino at configurable baud rate

### Recording & Playback
- **Multi-layer Recording**: Record complex movements across multiple layers
- **Keyframe-based Animation**: Precise control with keyframe capture and editing
- **Layer Management**: Independent control of finger and arm servo layers
- **Playback System**: Variable speed playback with blending and crossfading

### Movement Chain System
- **Continuous Loop Mode**: Non-stop movement sequences for installations
- **Sensor-Reactive Mode**: PIR motion sensor triggered state machine (IDLE/ACTIVE/SLEEP)
- **Movement Library**: Save and organize movement recordings
- **State-based Playback**: Different behaviors for different states

### Advanced Features
- **Markov Chain Generation**: AI-driven organic movement transitions
- **Crossfade Engine**: Smooth blending between movement sequences
- **Hardware Preview**: See exactly what will run on Arduino before export
- **Organic Wobble**: Natural micro-movements for lifelike behavior

### Arduino Export
- **Full .ino Export**: Complete Arduino sketches with all movements embedded
- **Multi-Phrase Export**: Markov chain based phrase system
- **PIR State Machine Export**: Sensor-reactive autonomous behavior
- **Continuous Loop Export**: Non-stop movement sequences
- **Optimized Code**: Memory-efficient sparse data structures for Arduino

### Hardware Configuration
- **Configurable Hardware Presets**: Save/load different hardware setups
- **Pin Mapping**: Customize Arduino pin assignments
- **Servo Reversal**: Per-servo direction reversal
- **Angle Limits**: Global and per-servo angle constraints
- **PIR Pin Configuration**: Configurable PIR sensor pin
- **Import/Export Presets**: Share hardware configurations

## Files

### Main Application
- `simple_hand_control.py` - Main GUI application with all features
- `hand_expression.py` - Hand controller serial communication module
- `launcher.py` - Simple launcher script
- `autonomous_controller.py` - Autonomous playback controller

### Configuration
- `hardware_config.json` - Hardware configuration (pins, reversals, limits)
- `requirements.txt` - Python dependencies

### Data Directories
- `pir_recordings/` - Movement recordings for PIR state machine
- `movement_recordings/` - General movement recordings (if present)

## Setup

### 1. Install Python Dependencies
```bash
pip install -r requirements.txt
```

Required packages:
- `pyserial>=3.5` - Serial communication with Arduino
- `customtkinter>=5.2.0` - Modern UI components

### 2. Arduino Setup
Upload the appropriate Arduino sketch to your board:
- For listener mode: Use `hand_control_8servo_listener.ino` or similar
- For autonomous mode: Export a sketch from the application

Default Arduino configuration:
- **Servo Pins**: D12, D11, D10, D9, D8, D7, D6, D5 (for servos 0-7)
- **PIR Sensor Pin**: D2 (configurable in hardware settings)
- **Baud Rate**: 9600
- **Command Format**: `HAND8,pos0,pos1,pos2,pos3,pos4,pos5,pos6,pos7\n`

### 3. Hardware Configuration
Open the Hardware Config panel in the application to configure:
- Serial port (e.g., COM4, COM9)
- PIR sensor pin (default: 2)
- Angle range (e.g., 0-45° for limited servos, 0-180° for full range)
- Reversed servos (check boxes for servos that need direction reversed)

**Note**: For your older sculpture Arduino with pin 3 for PIR, change "PIR Pin" to 3 in the Hardware Config panel.

### 4. Run the Application
```bash
python simple_hand_control.py
```

Or use the launcher:
```bash
python launcher.py
```

## Usage Guide

### Basic Operation
1. **Connect Hardware**: Click "Connect to Hand" button and select your serial port
2. **Test Servos**: Use sliders or cursor wave to verify all servos respond correctly
3. **Configure Hardware**: Expand "Hardware Config" to set reversed servos and angle limits

### Recording Movements
1. Click "Start Recording" or press Space
2. Move cursor or adjust sliders to create movement
3. Recording automatically stops after configured duration
4. Recordings are saved to `pir_recordings/` folder

### Creating Movement Chains

#### Continuous Loop Mode
1. Select "Continuous Loop" in Movement Chain System panel
2. Add recordings to Movement Library using "+" button
3. Configure Markov settings (segment length, chaos, blend time)
4. Click "Export .ino (Continuous)" to generate Arduino code

#### Sensor-Reactive Mode (PIR)
1. Select "Sensor-Reactive (PIR)" mode
2. Assign recordings to IDLE, ACTIVE, and SLEEP states
3. Configure PIR settings (active duration, sleep timeout, transition time)
4. Click "Export .ino (PIR)" to generate Arduino code

### Exporting to Arduino
- **Export .ino (Full)**: Complete movement sequence with all keyframes
- **Multi-Phrase**: Markov-based phrase system with multiple recordings
- **Export from Movement Chain panel**: Generates continuous or PIR-reactive code

## Hardware Configuration Presets

You can save and load different hardware configurations for different sculptures:

```json
{
  "name": "Default",
  "description": "Standard 8-servo hand controller",
  "serial_port": "COM9",
  "baud_rate": 9600,
  "pir_pin": 2,
  "global_min_angle": 0,
  "global_max_angle": 180,
  "pin_mapping": [12, 11, 10, 9, 8, 7, 6, 5],
  "servo_names": ["Thumb", "Index", "Middle", "Ring", "Pinky", "Shoulder", "Elbow", "Wrist"],
  "reversed_servos": [],
  "per_servo_limits": [[0, 180], [0, 180], ...]
}
```

### For Older Sculpture (from your code snippet):
- PIR Pin: 3 (instead of 2)
- Reversed Servos: Pins 9 and 10 (Middle and Ring fingers)
- Angle Range: 0-70°

Create a preset using the Import/Export buttons in Hardware Config panel.

## Troubleshooting

### Connection Issues
- Verify correct COM port in Hardware Config
- Check Arduino is programmed with listener sketch
- Ensure baud rate matches (9600 default)

### Servo Direction Issues
- Check "Reversed" checkboxes in Hardware Config for servos moving wrong direction
- According to your old code: pins 9 and 10 should be reversed

### PIR Sensor Not Working
- Verify PIR pin setting matches your Arduino wiring (pin 2 or 3)
- Check PIR sensor wiring and power
- Test with "Simulate Motion" button in PIR panel

### Memory Issues on Arduino Export
- Use Markov mode (more memory efficient)
- Reduce number of recordings
- Shorten segment length
- The application shows estimated memory usage during export

## Architecture

The application is built with:
- **GUI**: CustomTkinter for modern UI with classic Windows 98 aesthetic
- **Serial Communication**: PySerial for Arduino communication
- **State Machine**: Three-state PIR reactive system (IDLE/ACTIVE/SLEEP)
- **Movement Engine**: Layer-based recording with keyframe interpolation
- **Export System**: Generates optimized Arduino C++ code with embedded movement data

## Development Notes

- Current branch: `ui-modernize`
- All changes are tracked in git
- PIR recordings stored as JSON with layer data
- Hardware config persists between sessions
- Export generates timestamped .ino files

## License & Credits

Auto-generated Arduino code includes attribution:
```
🤖 Generated with [Claude Code](https://claude.com/claude-code)
Co-Authored-By: Claude <noreply@anthropic.com>
```

---

For questions or issues, refer to the git history or regenerate Arduino code from the application.
