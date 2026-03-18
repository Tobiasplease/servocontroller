/*
 * 8-Servo Hand Control - Generated Movement Code
 * Generated: 2025-12-04 18:32:00
 * Layers: 1
 * Total Movements: 1046
 * 
 * Hardware: 5 Finger Servos + 3 Arm Servos
 * Fingers: Thumb, Index, Middle, Ring, Pinky
 * Arm: Shoulder, Elbow, Wrist
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

// Servo objects for 8 servos (5 fingers + 3 arm)
Servo servo[8];

// Servo pins - REVERSED ORDER to match hardware (12-5)
int servoPins[8] = {12, 11, 10, 9, 8, 7, 6, 5};

// Forward declarations
void smoothMove(int servoIndex, int targetAngle, int steps = 10);
void centerAllServos();
void setFingers(int thumb, int index, int middle, int ring, int pinky);
void setArm(int wristRotate, int wristTilt, int elbow);

void setup() {
  Serial.begin(9600);
  
  // Attach servos
  for(int i = 0; i < 8; i++) {
    servo[i].attach(servoPins[i]);
    servo[i].write(90); // Center position
  }
  
  delay(1000);
  Serial.println("8-Servo Hand Control Ready");
}

void loop() {
  Serial.println("Playing recorded sequence...");
  
  playLayer1(); // Layer_1 (cursor mode)
  delay(2000); // Pause between layers

}

// Layer 1: Layer_1 - cursor mode
// Duration: 9.7s, Keyframes: 35 (reduced from 1046 frames)
void playLayer1() {
  // Keyframe 1 @ 0.00s: Fingers [139, 115, 56, 80, 139] Arm [-, -, -]
  delay(4);
  servo[0].write(139); // Thumb
  servo[1].write(115); // Index
  servo[2].write(56); // Middle
  servo[3].write(80); // Ring
  servo[4].write(139); // Pinky

  // Keyframe 2 @ 0.21s: Fingers [124, 78, 34, 80, 124] Arm [-, -, -]
  smoothMove(0, 124, 10); // Thumb
  smoothMove(1, 78, 10); // Index
  smoothMove(2, 34, 10); // Middle
  smoothMove(3, 80, 10); // Ring
  smoothMove(4, 124, 10); // Pinky

  // Keyframe 3 @ 0.42s: Fingers [100, 74, 16, 41, 100] Arm [-, -, -]
  smoothMove(0, 100, 10); // Thumb
  smoothMove(1, 74, 10); // Index
  smoothMove(2, 16, 10); // Middle
  smoothMove(3, 41, 10); // Ring
  smoothMove(4, 100, 10); // Pinky

  // Keyframe 4 @ 0.62s: Fingers [63, 91, 34, 6, 63] Arm [-, -, -]
  smoothMove(0, 63, 10); // Thumb
  smoothMove(1, 91, 10); // Index
  smoothMove(2, 34, 10); // Middle
  smoothMove(3, 6, 10); // Ring
  smoothMove(4, 63, 10); // Pinky

  // Keyframe 5 @ 0.82s: Fingers [14, 78, 83, 19, 14] Arm [-, -, -]
  smoothMove(0, 14, 10); // Thumb
  smoothMove(1, 78, 10); // Index
  smoothMove(2, 83, 10); // Middle
  smoothMove(3, 19, 10); // Ring
  smoothMove(4, 14, 10); // Pinky

  // Keyframe 6 @ 1.03s: Fingers [11, 53, 101, 59, 11] Arm [-, -, -]
  smoothMove(0, 11, 10); // Thumb
  smoothMove(1, 53, 10); // Index
  smoothMove(2, 101, 10); // Middle
  smoothMove(3, 59, 10); // Ring
  smoothMove(4, 11, 10); // Pinky

  // Keyframe 7 @ 1.24s: Fingers [32, 50, 111, 94, 32] Arm [-, -, -]
  smoothMove(0, 32, 10); // Thumb
  smoothMove(1, 50, 10); // Index
  smoothMove(2, 111, 10); // Middle
  smoothMove(3, 94, 10); // Ring
  smoothMove(4, 32, 10); // Pinky

  // Keyframe 8 @ 1.44s: Fingers [49, 77, 134, 106, 49] Arm [-, -, -]
  smoothMove(0, 49, 10); // Thumb
  smoothMove(1, 77, 10); // Index
  smoothMove(2, 134, 10); // Middle
  smoothMove(3, 106, 10); // Ring
  smoothMove(4, 49, 10); // Pinky

  // Keyframe 9 @ 1.65s: Fingers [64, 121, 149, 92, 64] Arm [-, -, -]
  smoothMove(0, 64, 10); // Thumb
  smoothMove(1, 121, 10); // Index
  smoothMove(2, 149, 10); // Middle
  smoothMove(3, 92, 10); // Ring
  smoothMove(4, 64, 10); // Pinky

  // Keyframe 10 @ 1.85s: Fingers [110, 162, 124, 73, 110] Arm [-, -, -]
  smoothMove(0, 110, 10); // Thumb
  smoothMove(1, 162, 10); // Index
  smoothMove(2, 124, 10); // Middle
  smoothMove(3, 73, 10); // Ring
  smoothMove(4, 110, 10); // Pinky

  // Keyframe 11 @ 2.05s: Fingers [139, 158, 97, 78, 139] Arm [-, -, -]
  smoothMove(0, 139, 10); // Thumb
  smoothMove(1, 158, 10); // Index
  smoothMove(2, 97, 10); // Middle
  smoothMove(3, 78, 10); // Ring
  smoothMove(4, 139, 10); // Pinky

  // Keyframe 12 @ 2.25s: Fingers [154, 124, 68, 97, 154] Arm [-, -, -]
  smoothMove(0, 154, 10); // Thumb
  smoothMove(1, 124, 10); // Index
  smoothMove(2, 68, 10); // Middle
  smoothMove(3, 97, 10); // Ring
  smoothMove(4, 154, 10); // Pinky

  // Keyframe 13 @ 2.46s: Fingers [142, 92, 53, 104, 142] Arm [-, -, -]
  smoothMove(0, 142, 10); // Thumb
  smoothMove(1, 92, 10); // Index
  smoothMove(2, 53, 10); // Middle
  smoothMove(3, 104, 10); // Ring
  smoothMove(4, 142, 10); // Pinky

  // Keyframe 14 @ 2.66s: Fingers [128, 72, 42, 99, 128] Arm [-, -, -]
  smoothMove(0, 128, 10); // Thumb
  smoothMove(1, 72, 10); // Index
  smoothMove(2, 42, 10); // Middle
  smoothMove(3, 99, 10); // Ring
  smoothMove(4, 128, 10); // Pinky

  // Keyframe 15 @ 2.87s: Fingers [117, 62, 30, 85, 117] Arm [-, -, -]
  smoothMove(0, 117, 10); // Thumb
  smoothMove(1, 62, 10); // Index
  smoothMove(2, 30, 10); // Middle
  smoothMove(3, 85, 10); // Ring
  smoothMove(4, 117, 10); // Pinky

  // Keyframe 16 @ 3.07s: Fingers [107, 61, 17, 63, 107] Arm [-, -, -]
  smoothMove(0, 107, 10); // Thumb
  smoothMove(1, 61, 10); // Index
  smoothMove(2, 17, 10); // Middle
  smoothMove(3, 63, 10); // Ring
  smoothMove(4, 107, 10); // Pinky

  // Keyframe 17 @ 3.27s: Fingers [95, 68, 10, 37, 95] Arm [-, -, -]
  smoothMove(0, 95, 10); // Thumb
  smoothMove(1, 68, 10); // Index
  smoothMove(2, 10, 10); // Middle
  smoothMove(3, 37, 10); // Ring
  smoothMove(4, 95, 10); // Pinky

  // Keyframe 18 @ 3.48s: Fingers [77, 75, 12, 14, 77] Arm [-, -, -]
  smoothMove(0, 77, 10); // Thumb
  smoothMove(1, 75, 10); // Index
  smoothMove(2, 12, 10); // Middle
  smoothMove(3, 14, 10); // Ring
  smoothMove(4, 77, 10); // Pinky

  // Keyframe 19 @ 4.45s: Fingers [5, 66, 85, 24, 5] Arm [-, -, -]
  smoothMove(0, 5, 20); // Thumb
  smoothMove(1, 66, 20); // Index
  smoothMove(2, 85, 20); // Middle
  smoothMove(3, 24, 20); // Ring
  smoothMove(4, 5, 20); // Pinky

  // Keyframe 20 @ 4.67s: Fingers [2, 58, 89, 34, 2] Arm [-, -, -]
  smoothMove(0, 2, 11); // Thumb
  smoothMove(1, 58, 11); // Index
  smoothMove(2, 89, 11); // Middle
  smoothMove(3, 34, 11); // Ring
  smoothMove(4, 2, 11); // Pinky

  // Keyframe 21 @ 4.88s: Fingers [4, 40, 93, 56, 4] Arm [-, -, -]
  smoothMove(0, 4, 10); // Thumb
  smoothMove(1, 40, 10); // Index
  smoothMove(2, 93, 10); // Middle
  smoothMove(3, 56, 10); // Ring
  smoothMove(4, 4, 10); // Pinky

  // Keyframe 22 @ 5.08s: Fingers [21, 38, 99, 82, 21] Arm [-, -, -]
  smoothMove(0, 21, 10); // Thumb
  smoothMove(1, 38, 10); // Index
  smoothMove(2, 99, 10); // Middle
  smoothMove(3, 82, 10); // Ring
  smoothMove(4, 21, 10); // Pinky

  // Keyframe 23 @ 5.28s: Fingers [62, 126, 127, 63, 62] Arm [-, -, -]
  smoothMove(0, 62, 10); // Thumb
  smoothMove(1, 126, 10); // Index
  smoothMove(2, 127, 10); // Middle
  smoothMove(3, 63, 10); // Ring
  smoothMove(4, 62, 10); // Pinky

  // Keyframe 24 @ 5.49s: Fingers [146, 153, 89, 83, 146] Arm [-, -, -]
  smoothMove(0, 146, 10); // Thumb
  smoothMove(1, 153, 10); // Index
  smoothMove(2, 89, 10); // Middle
  smoothMove(3, 83, 10); // Ring
  smoothMove(4, 146, 10); // Pinky

  // Keyframe 25 @ 5.70s: Fingers [146, 109, 57, 95, 146] Arm [-, -, -]
  smoothMove(0, 146, 10); // Thumb
  smoothMove(1, 109, 10); // Index
  smoothMove(2, 57, 10); // Middle
  smoothMove(3, 95, 10); // Ring
  smoothMove(4, 146, 10); // Pinky

  // Keyframe 26 @ 5.90s: Fingers [126, 93, 39, 72, 126] Arm [-, -, -]
  smoothMove(0, 126, 10); // Thumb
  smoothMove(1, 93, 10); // Index
  smoothMove(2, 39, 10); // Middle
  smoothMove(3, 72, 10); // Ring
  smoothMove(4, 126, 10); // Pinky

  // Keyframe 27 @ 6.10s: Fingers [84, 103, 42, 23, 84] Arm [-, -, -]
  smoothMove(0, 84, 10); // Thumb
  smoothMove(1, 103, 10); // Index
  smoothMove(2, 42, 10); // Middle
  smoothMove(3, 23, 10); // Ring
  smoothMove(4, 84, 10); // Pinky

  // Keyframe 28 @ 6.31s: Fingers [28, 92, 84, 21, 28] Arm [-, -, -]
  smoothMove(0, 28, 10); // Thumb
  smoothMove(1, 92, 10); // Index
  smoothMove(2, 84, 10); // Middle
  smoothMove(3, 21, 10); // Ring
  smoothMove(4, 28, 10); // Pinky

  // Keyframe 29 @ 6.51s: Fingers [22, 78, 108, 52, 22] Arm [-, -, -]
  smoothMove(0, 22, 10); // Thumb
  smoothMove(1, 78, 10); // Index
  smoothMove(2, 108, 10); // Middle
  smoothMove(3, 52, 10); // Ring
  smoothMove(4, 22, 10); // Pinky

  // Keyframe 30 @ 6.71s: Fingers [44, 106, 122, 60, 44] Arm [-, -, -]
  smoothMove(0, 44, 10); // Thumb
  smoothMove(1, 106, 10); // Index
  smoothMove(2, 122, 10); // Middle
  smoothMove(3, 60, 10); // Ring
  smoothMove(4, 44, 10); // Pinky

  // Keyframe 31 @ 6.92s: Fingers [70, 133, 124, 61, 70] Arm [-, -, -]
  smoothMove(0, 70, 10); // Thumb
  smoothMove(1, 133, 10); // Index
  smoothMove(2, 124, 10); // Middle
  smoothMove(3, 61, 10); // Ring
  smoothMove(4, 70, 10); // Pinky

  // Keyframe 32 @ 7.13s: Fingers [96, 148, 110, 59, 96] Arm [-, -, -]
  smoothMove(0, 96, 10); // Thumb
  smoothMove(1, 148, 10); // Index
  smoothMove(2, 110, 10); // Middle
  smoothMove(3, 59, 10); // Ring
  smoothMove(4, 96, 10); // Pinky

  // Keyframe 33 @ 7.67s: Fingers [108, 150, 102, 60, 108] Arm [-, -, -]
  smoothMove(0, 108, 20); // Thumb
  smoothMove(1, 150, 20); // Index
  smoothMove(2, 102, 20); // Middle
  smoothMove(3, 60, 20); // Ring
  smoothMove(4, 108, 20); // Pinky

  // Keyframe 34 @ 7.88s: Fingers [137, 75, 90, 152, 137] Arm [-, -, -]
  smoothMove(0, 137, 10); // Thumb
  smoothMove(1, 75, 10); // Index
  smoothMove(2, 90, 10); // Middle
  smoothMove(3, 152, 10); // Ring
  smoothMove(4, 137, 10); // Pinky

  // Keyframe 35 @ 9.64s: Fingers [137, 75, 90, 152, 137] Arm [-, -, -]
  smoothMove(0, 137, 20); // Thumb
  smoothMove(1, 75, 20); // Index
  smoothMove(2, 90, 20); // Middle
  smoothMove(3, 152, 20); // Ring
  smoothMove(4, 137, 20); // Pinky

}

// Utility Functions
void centerAllServos() {
  Serial.println("Centering all servos...");
  for(int i = 0; i < 8; i++) {
    servo[i].write(90);
    delay(100);
  }
}

void smoothMove(int servoIndex, int targetAngle, int steps = 10) {
  int currentAngle = servo[servoIndex].read();
  float stepSize = (float)(targetAngle - currentAngle) / (float)steps;
  
  for(int i = 1; i <= steps; i++) {
    int newAngle = currentAngle + (int)(stepSize * i);
    servo[servoIndex].write(newAngle);
    delay(20);  // 20ms per step for smooth motion
  }
  servo[servoIndex].write(targetAngle);  // Ensure exact target reached
}

// Individual servo control functions
void setFingers(int thumb, int index, int middle, int ring, int pinky) {
  servo[0].write(thumb);
  servo[1].write(index);
  servo[2].write(middle); 
  servo[3].write(ring);
  servo[4].write(pinky);
}

void setArm(int wristRotate, int wristTilt, int elbow) {
  servo[5].write(wristRotate);
  servo[6].write(wristTilt);
  servo[7].write(elbow);
}
