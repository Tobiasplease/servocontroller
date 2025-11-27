#!/usr/bin/env python3
"""
Autonomous Hand Control System
=============================

Integrates the hand control interface with external emotional analysis systems.
Automatically selects datasets and controls hand movements based on real-time
emotional state detection from machine.py or other emotion detection systems.

Features:
- Real-time emotion detection integration
- Automatic dataset selection and switching
- Autonomous operation with configurable parameters
- Fallback behaviors for missing datasets or connection issues
- Logging and monitoring capabilities

Author: Autonomous Integration System
"""

import time
import threading
import json
import os
import sys
import traceback
import subprocess
from typing import Optional, Dict, Any, Callable
from dataclasses import dataclass
from enum import Enum
import queue

# Import the hand control interface
try:
    from hand_control_interface import CleanCursorInterface
    HAND_CONTROL_AVAILABLE = True
except ImportError as e:
    print(f"❌ Hand control interface not available: {e}")
    HAND_CONTROL_AVAILABLE = False


class EmotionSource(Enum):
    """Supported emotion detection sources."""
    MACHINE_PY = "machine_py"
    JSON_FILE = "json_file"
    TCP_SOCKET = "tcp_socket"
    HTTP_API = "http_api"
    SIMULATION = "simulation"


@dataclass
class EmotionState:
    """Represents an emotional state with confidence and metadata."""
    emotion: str
    confidence: float
    timestamp: float
    metadata: Dict[str, Any] = None

    def __post_init__(self):
        if self.metadata is None:
            self.metadata = {}


class EmotionDetector:
    """Base class for emotion detection systems."""
    
    def __init__(self, source_type: EmotionSource):
        self.source_type = source_type
        self.running = False
        self.last_emotion = None
        self.emotion_queue = queue.Queue(maxsize=10)
        
    def start(self):
        """Start emotion detection."""
        self.running = True
        
    def stop(self):
        """Stop emotion detection."""
        self.running = False
        
    def get_latest_emotion(self) -> Optional[EmotionState]:
        """Get the most recent emotion reading."""
        try:
            return self.emotion_queue.get_nowait()
        except queue.Empty:
            return self.last_emotion
    
    def _emit_emotion(self, emotion_state: EmotionState):
        """Emit a new emotion state."""
        self.last_emotion = emotion_state
        try:
            self.emotion_queue.put_nowait(emotion_state)
        except queue.Full:
            # Remove oldest and add newest
            try:
                self.emotion_queue.get_nowait()
                self.emotion_queue.put_nowait(emotion_state)
            except queue.Empty:
                pass


class MachineDetector(EmotionDetector):
    """Emotion detector that interfaces with machine.py."""
    
    def __init__(self, machine_path: str = "machine.py", update_interval: float = 1.0):
        super().__init__(EmotionSource.MACHINE_PY)
        self.machine_path = machine_path
        self.update_interval = update_interval
        self.process = None
        self.thread = None
        
    def start(self):
        """Start machine.py and begin monitoring."""
        super().start()
        self.thread = threading.Thread(target=self._monitor_machine, daemon=True)
        self.thread.start()
        print(f"🤖 Started machine.py emotion detection (interval: {self.update_interval}s)")
        
    def stop(self):
        """Stop machine.py monitoring."""
        super().stop()
        if self.process:
            self.process.terminate()
            self.process = None
        print("🛑 Stopped machine.py emotion detection")
        
    def _monitor_machine(self):
        """Monitor machine.py output for emotion data."""
        while self.running:
            try:
                # Launch machine.py and capture output
                result = subprocess.run(
                    [sys.executable, self.machine_path, "--emotion-only"],
                    capture_output=True,
                    text=True,
                    timeout=10.0
                )
                
                if result.returncode == 0 and result.stdout.strip():
                    emotion_data = self._parse_machine_output(result.stdout.strip())
                    if emotion_data:
                        emotion_state = EmotionState(
                            emotion=emotion_data['emotion'],
                            confidence=emotion_data.get('confidence', 1.0),
                            timestamp=time.time(),
                            metadata=emotion_data
                        )
                        self._emit_emotion(emotion_state)
                        
            except subprocess.TimeoutExpired:
                print("⚠️ machine.py timeout - continuing...")
            except Exception as e:
                print(f"❌ Error running machine.py: {e}")
                
            time.sleep(self.update_interval)
    
    def _parse_machine_output(self, output: str) -> Optional[Dict[str, Any]]:
        """Parse machine.py output to extract emotion data."""
        try:
            # Try JSON format first
            return json.loads(output)
        except json.JSONDecodeError:
            # Try simple text format
            lines = output.strip().split('\n')
            for line in lines:
                if ':' in line:
                    emotion, confidence_str = line.split(':', 1)
                    try:
                        confidence = float(confidence_str.strip())
                        return {
                            'emotion': emotion.strip().lower(),
                            'confidence': confidence
                        }
                    except ValueError:
                        continue
            
            # Fallback - assume the output is just the emotion name
            emotion = output.strip().lower()
            if emotion:
                return {'emotion': emotion, 'confidence': 1.0}
                
        return None


class FileDetector(EmotionDetector):
    """Emotion detector that reads from a JSON file."""
    
    def __init__(self, file_path: str = "current_emotion.json", update_interval: float = 0.5):
        super().__init__(EmotionSource.JSON_FILE)
        self.file_path = file_path
        self.update_interval = update_interval
        self.last_modified = 0
        self.thread = None
        
    def start(self):
        """Start monitoring the emotion file."""
        super().start()
        self.thread = threading.Thread(target=self._monitor_file, daemon=True)
        self.thread.start()
        print(f"📁 Started file emotion detection: {self.file_path}")
        
    def _monitor_file(self):
        """Monitor file for emotion updates."""
        while self.running:
            try:
                if os.path.exists(self.file_path):
                    current_modified = os.path.getmtime(self.file_path)
                    if current_modified > self.last_modified:
                        self.last_modified = current_modified
                        with open(self.file_path, 'r') as f:
                            data = json.load(f)
                        
                        emotion_state = EmotionState(
                            emotion=data.get('emotion', 'calm_observant'),
                            confidence=data.get('confidence', 1.0),
                            timestamp=data.get('timestamp', time.time()),
                            metadata=data
                        )
                        self._emit_emotion(emotion_state)
                        
            except Exception as e:
                print(f"❌ Error reading emotion file: {e}")
                
            time.sleep(self.update_interval)


class SimulationDetector(EmotionDetector):
    """Emotion detector that cycles through emotions for testing."""
    
    def __init__(self, emotions: list = None, cycle_time: float = 30.0):
        super().__init__(EmotionSource.SIMULATION)
        self.emotions = emotions or [
            'energized_engaged', 'alert_curious', 'calm_observant', 
            'quiet_detached', 'withdrawn_distant'
        ]
        self.cycle_time = cycle_time
        self.current_index = 0
        self.thread = None
        
    def start(self):
        """Start emotion simulation."""
        super().start()
        self.thread = threading.Thread(target=self._simulate_emotions, daemon=True)
        self.thread.start()
        print(f"🎭 Started emotion simulation (cycle: {self.cycle_time}s)")
        
    def _simulate_emotions(self):
        """Simulate cycling through emotions."""
        while self.running:
            emotion = self.emotions[self.current_index]
            emotion_state = EmotionState(
                emotion=emotion,
                confidence=0.9,
                timestamp=time.time(),
                metadata={'source': 'simulation', 'cycle_position': self.current_index}
            )
            self._emit_emotion(emotion_state)
            
            self.current_index = (self.current_index + 1) % len(self.emotions)
            time.sleep(self.cycle_time)


class AutonomousController:
    """Main autonomous controller that integrates emotion detection with hand control."""
    
    def __init__(self, 
                 emotion_detector: EmotionDetector,
                 hand_interface: Optional[CleanCursorInterface] = None,
                 config: Dict[str, Any] = None):
        
        self.emotion_detector = emotion_detector
        self.hand_interface = hand_interface
        self.config = config or self._default_config()
        
        self.running = False
        self.current_emotion = None
        self.last_dataset_switch = 0
        self.generation_active = False
        
        # Emotion mapping - map detected emotions to available dataset emotions
        self.emotion_mapping = self._build_emotion_mapping()
        
        print("🤖 Autonomous controller initialized")
        
    def _default_config(self) -> Dict[str, Any]:
        """Default configuration for autonomous operation."""
        return {
            'min_confidence': 0.6,  # Minimum confidence to act on emotion
            'switch_delay': 2.0,    # Minimum seconds between dataset switches
            'auto_generation': True, # Automatically start Markov generation
            'fallback_emotion': 'calm_observant',  # Fallback if detection fails
            'generation_duration': 60.0,  # How long to generate before checking for changes
            'verbose_logging': True
        }
    
    def _build_emotion_mapping(self) -> Dict[str, str]:
        """Build mapping between detected emotions and available dataset emotions."""
        # Standard emotions available in the hand control system
        available_emotions = [
            'energized_engaged', 'alert_curious', 'calm_observant',
            'quiet_detached', 'withdrawn_distant'
        ]
        
        # Map various emotion names to standard ones
        mapping = {}
        
        # Direct mappings
        for emotion in available_emotions:
            mapping[emotion] = emotion
            mapping[emotion.replace('_', ' ')] = emotion
            mapping[emotion.replace('_', '-')] = emotion
        
        # Common emotion synonyms
        mapping.update({
            'happy': 'energized_engaged',
            'excited': 'energized_engaged',
            'enthusiastic': 'energized_engaged',
            'energetic': 'energized_engaged',
            'engaged': 'energized_engaged',
            
            'curious': 'alert_curious',
            'interested': 'alert_curious',
            'attentive': 'alert_curious',
            'focused': 'alert_curious',
            'alert': 'alert_curious',
            
            'calm': 'calm_observant',
            'peaceful': 'calm_observant',
            'relaxed': 'calm_observant',
            'neutral': 'calm_observant',
            'observant': 'calm_observant',
            'balanced': 'calm_observant',
            
            'tired': 'quiet_detached',
            'bored': 'quiet_detached',
            'disinterested': 'quiet_detached',
            'detached': 'quiet_detached',
            'quiet': 'quiet_detached',
            
            'sad': 'withdrawn_distant',
            'depressed': 'withdrawn_distant',
            'withdrawn': 'withdrawn_distant',
            'distant': 'withdrawn_distant',
            'melancholy': 'withdrawn_distant'
        })
        
        return mapping
    
    def start(self):
        """Start autonomous operation."""
        if not HAND_CONTROL_AVAILABLE:
            print("❌ Cannot start - hand control interface not available")
            return False
            
        self.running = True
        
        # Start emotion detection
        self.emotion_detector.start()
        
        # Start main control loop
        control_thread = threading.Thread(target=self._control_loop, daemon=True)
        control_thread.start()
        
        print("🚀 Autonomous controller started")
        return True
    
    def stop(self):
        """Stop autonomous operation."""
        self.running = False
        self.emotion_detector.stop()
        
        if self.hand_interface and self.generation_active:
            try:
                self.hand_interface.stop_markov_generation()
            except:
                pass
                
        print("🛑 Autonomous controller stopped")
    
    def _control_loop(self):
        """Main control loop for autonomous operation."""
        while self.running:
            try:
                # Get latest emotion
                emotion_state = self.emotion_detector.get_latest_emotion()
                
                if emotion_state and self._should_process_emotion(emotion_state):
                    self._process_emotion_change(emotion_state)
                
                # Monitor generation status
                if self.hand_interface:
                    self._monitor_generation_status()
                
                time.sleep(0.5)  # Check twice per second
                
            except Exception as e:
                print(f"❌ Error in control loop: {e}")
                if self.config['verbose_logging']:
                    traceback.print_exc()
                time.sleep(1.0)
    
    def _should_process_emotion(self, emotion_state: EmotionState) -> bool:
        """Determine if we should act on this emotion detection."""
        # Check confidence threshold
        if emotion_state.confidence < self.config['min_confidence']:
            return False
            
        # Check if emotion actually changed
        if self.current_emotion == emotion_state.emotion:
            return False
            
        # Check switch delay
        if time.time() - self.last_dataset_switch < self.config['switch_delay']:
            return False
            
        return True
    
    def _process_emotion_change(self, emotion_state: EmotionState):
        """Process a change in emotional state."""
        # Map the detected emotion to available dataset emotion
        target_emotion = self._map_emotion(emotion_state.emotion)
        
        if not target_emotion:
            if self.config['verbose_logging']:
                print(f"⚠️ Unknown emotion '{emotion_state.emotion}', using fallback")
            target_emotion = self.config['fallback_emotion']
        
        if self.config['verbose_logging']:
            print(f"🎭 Emotion change: {emotion_state.emotion} -> {target_emotion} "
                  f"(confidence: {emotion_state.confidence:.2f})")
        
        # Switch to the new emotion in hand interface
        if self.hand_interface:
            self._switch_hand_emotion(target_emotion)
        
        self.current_emotion = target_emotion
        self.last_dataset_switch = time.time()
    
    def _map_emotion(self, detected_emotion: str) -> Optional[str]:
        """Map a detected emotion to an available dataset emotion."""
        detected_emotion = detected_emotion.lower().strip()
        return self.emotion_mapping.get(detected_emotion)
    
    def _switch_hand_emotion(self, emotion: str):
        """Switch the hand interface to a new emotion and start generation."""
        try:
            # Stop current generation if active
            if self.generation_active:
                self.hand_interface.stop_markov_generation()
                self.generation_active = False
                time.sleep(0.5)  # Brief pause
            
            # Switch emotional state
            self.hand_interface.switch_emotional_state(emotion)
            time.sleep(0.5)  # Allow UI to update
            
            # Start Markov generation if configured
            if self.config['auto_generation']:
                # Check if datasets are available for this emotion
                if emotion in self.hand_interface.available_datasets:
                    datasets = self.hand_interface.available_datasets[emotion]
                    if datasets:
                        self.hand_interface.start_markov_generation()
                        self.generation_active = True
                        print(f"✅ Started generation for {emotion} with {len(datasets)} datasets")
                    else:
                        print(f"⚠️ No datasets available for {emotion}")
                else:
                    print(f"⚠️ Emotion {emotion} not found in available datasets")
                    
        except Exception as e:
            print(f"❌ Error switching to {emotion}: {e}")
            if self.config['verbose_logging']:
                traceback.print_exc()
    
    def _monitor_generation_status(self):
        """Monitor the status of Markov generation."""
        if not self.hand_interface:
            return
            
        # Check if generation is still active when it should be
        if self.config['auto_generation'] and self.current_emotion:
            is_generating = getattr(self.hand_interface, 'generating', False)
            
            if self.generation_active != is_generating:
                self.generation_active = is_generating
                if self.config['verbose_logging']:
                    status = "started" if is_generating else "stopped"
                    print(f"🎨 Generation {status} for {self.current_emotion}")


def create_autonomous_system(emotion_source: str = "simulation", **kwargs) -> AutonomousController:
    """Factory function to create an autonomous system with specified emotion source."""
    
    # Create emotion detector based on source
    if emotion_source == "machine_py":
        machine_path = kwargs.get('machine_path', 'machine.py')
        update_interval = kwargs.get('update_interval', 1.0)
        detector = MachineDetector(machine_path, update_interval)
        
    elif emotion_source == "file":
        file_path = kwargs.get('file_path', 'current_emotion.json')
        update_interval = kwargs.get('update_interval', 0.5)
        detector = FileDetector(file_path, update_interval)
        
    elif emotion_source == "simulation":
        emotions = kwargs.get('emotions', None)
        cycle_time = kwargs.get('cycle_time', 30.0)
        detector = SimulationDetector(emotions, cycle_time)
        
    else:
        raise ValueError(f"Unknown emotion source: {emotion_source}")
    
    # Create hand interface if available
    hand_interface = None
    if HAND_CONTROL_AVAILABLE:
        hand_interface = CleanCursorInterface()
        # Don't start the UI mainloop - we'll run headless
    
    # Create controller
    config = kwargs.get('config', {})
    controller = AutonomousController(detector, hand_interface, config)
    
    return controller


def main():
    """Main function for testing autonomous operation."""
    import argparse
    
    parser = argparse.ArgumentParser(description="Autonomous Hand Control System")
    parser.add_argument("--source", choices=["machine_py", "file", "simulation"], 
                       default="simulation", help="Emotion detection source")
    parser.add_argument("--machine-path", default="machine.py", 
                       help="Path to machine.py")
    parser.add_argument("--emotion-file", default="current_emotion.json",
                       help="Path to emotion JSON file")
    parser.add_argument("--cycle-time", type=float, default=30.0,
                       help="Simulation cycle time in seconds")
    parser.add_argument("--headless", action="store_true",
                       help="Run without GUI (autonomous only)")
    parser.add_argument("--verbose", action="store_true",
                       help="Verbose logging")
    
    args = parser.parse_args()
    
    # Create configuration
    config = {
        'verbose_logging': args.verbose,
        'auto_generation': True,
        'min_confidence': 0.6,
        'switch_delay': 2.0
    }
    
    # Create autonomous system
    kwargs = {
        'config': config,
        'machine_path': args.machine_path,
        'file_path': args.emotion_file,
        'cycle_time': args.cycle_time
    }
    
    try:
        controller = create_autonomous_system(args.source, **kwargs)
        
        if controller.start():
            print("🤖 Autonomous system running...")
            print("Press Ctrl+C to stop")
            
            if not args.headless and controller.hand_interface:
                # Run with GUI
                print("🖥️ Starting GUI interface...")
                controller.hand_interface.root.mainloop()
            else:
                # Run headless
                print("🔧 Running in headless mode...")
                try:
                    while True:
                        time.sleep(1)
                except KeyboardInterrupt:
                    pass
        else:
            print("❌ Failed to start autonomous system")
            
    except KeyboardInterrupt:
        print("\n🛑 Shutting down...")
    except Exception as e:
        print(f"❌ Error: {e}")
        traceback.print_exc()
    finally:
        if 'controller' in locals():
            controller.stop()
        print("✅ Shutdown complete")


if __name__ == "__main__":
    main()
