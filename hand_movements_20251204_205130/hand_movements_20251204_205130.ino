/*
 * 8-Servo Hand Control - Generated Movement Code
 * Generated: 2025-12-04 20:51:29
 * Layers: 4
 * Total Movements: 3186
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
  
  playLayer1(); // Layer_1 (manual mode)
  delay(2000); // Pause between layers

  playLayer2(); // Layer_2 (manual mode)
  delay(2000); // Pause between layers

  playLayer3(); // Layer_3 (manual mode)
  delay(2000); // Pause between layers

  playLayer4(); // Layer_4 (cursor mode)
  delay(2000); // Pause between layers

}

// Layer 1: Layer_1 - manual mode
// Duration: 6.6s, Keyframes: 25 (reduced from 419 frames)
void playLayer1() {
  // Keyframe 1 @ 0.01s: Fingers [-, -, -, -, -] Arm [131, -, -]
  delay(12);
  servo[5].write(131); // Shoulder

  // Keyframe 2 @ 0.51s: Fingers [-, -, -, -, -] Arm [135, -, -]
  smoothMove(5, 135, 20); // Shoulder

  // Keyframe 3 @ 0.61s: Fingers [-, -, -, -, -] Arm [139, -, -]
  smoothMove(5, 139, 5); // Shoulder

  // Keyframe 4 @ 0.73s: Fingers [-, -, -, -, -] Arm [143, -, -]
  smoothMove(5, 143, 6); // Shoulder

  // Keyframe 5 @ 0.92s: Fingers [-, -, -, -, -] Arm [147, -, -]
  smoothMove(5, 147, 9); // Shoulder

  // Keyframe 6 @ 1.13s: Fingers [-, -, -, -, -] Arm [151, -, -]
  smoothMove(5, 151, 10); // Shoulder

  // Keyframe 7 @ 1.30s: Fingers [-, -, -, -, -] Arm [155, -, -]
  smoothMove(5, 155, 8); // Shoulder

  // Keyframe 8 @ 1.47s: Fingers [-, -, -, -, -] Arm [159, -, -]
  smoothMove(5, 159, 8); // Shoulder

  // Keyframe 9 @ 1.65s: Fingers [-, -, -, -, -] Arm [164, -, -]
  smoothMove(5, 164, 9); // Shoulder

  // Keyframe 10 @ 1.82s: Fingers [-, -, -, -, -] Arm [168, -, -]
  smoothMove(5, 168, 8); // Shoulder

  // Keyframe 11 @ 2.11s: Fingers [-, -, -, -, -] Arm [172, -, -]
  smoothMove(5, 172, 14); // Shoulder

  // Keyframe 12 @ 2.44s: Fingers [-, -, -, -, -] Arm [176, -, -]
  smoothMove(5, 176, 16); // Shoulder

  // Keyframe 13 @ 3.43s: Fingers [-, -, -, -, -] Arm [172, -, -]
  smoothMove(5, 172, 20); // Shoulder

  // Keyframe 14 @ 3.52s: Fingers [-, -, -, -, -] Arm [168, -, -]
  smoothMove(5, 168, 4); // Shoulder

  // Keyframe 15 @ 3.70s: Fingers [-, -, -, -, -] Arm [164, -, -]
  smoothMove(5, 164, 8); // Shoulder

  // Keyframe 16 @ 3.94s: Fingers [-, -, -, -, -] Arm [160, -, -]
  smoothMove(5, 160, 12); // Shoulder

  // Keyframe 17 @ 4.14s: Fingers [-, -, -, -, -] Arm [156, -, -]
  smoothMove(5, 156, 9); // Shoulder

  // Keyframe 18 @ 4.29s: Fingers [-, -, -, -, -] Arm [152, -, -]
  smoothMove(5, 152, 7); // Shoulder

  // Keyframe 19 @ 4.45s: Fingers [-, -, -, -, -] Arm [148, -, -]
  smoothMove(5, 148, 8); // Shoulder

  // Keyframe 20 @ 4.64s: Fingers [-, -, -, -, -] Arm [144, -, -]
  smoothMove(5, 144, 9); // Shoulder

  // Keyframe 21 @ 4.77s: Fingers [-, -, -, -, -] Arm [139, -, -]
  smoothMove(5, 139, 6); // Shoulder

  // Keyframe 22 @ 4.99s: Fingers [-, -, -, -, -] Arm [135, -, -]
  smoothMove(5, 135, 11); // Shoulder

  // Keyframe 23 @ 5.29s: Fingers [-, -, -, -, -] Arm [131, -, -]
  smoothMove(5, 131, 14); // Shoulder

  // Keyframe 24 @ 5.66s: Fingers [-, -, -, -, -] Arm [127, -, -]
  smoothMove(5, 127, 18); // Shoulder

  // Keyframe 25 @ 6.61s: Fingers [-, -, -, -, -] Arm [126, -, -]
  smoothMove(5, 126, 20); // Shoulder

}

// Layer 2: Layer_2 - manual mode
// Duration: 11.0s, Keyframes: 25 (reduced from 592 frames)
void playLayer2() {
  // Keyframe 1 @ 0.01s: Fingers [-, -, -, -, -] Arm [-, 63, -]
  delay(5);
  servo[6].write(63); // Elbow

  // Keyframe 2 @ 1.08s: Fingers [-, -, -, -, -] Arm [-, 59, -]
  smoothMove(6, 59, 20); // Elbow

  // Keyframe 3 @ 1.34s: Fingers [-, -, -, -, -] Arm [-, 55, -]
  smoothMove(6, 55, 12); // Elbow

  // Keyframe 4 @ 1.48s: Fingers [-, -, -, -, -] Arm [-, 51, -]
  smoothMove(6, 51, 6); // Elbow

  // Keyframe 5 @ 1.68s: Fingers [-, -, -, -, -] Arm [-, 47, -]
  smoothMove(6, 47, 10); // Elbow

  // Keyframe 6 @ 2.17s: Fingers [-, -, -, -, -] Arm [-, 43, -]
  smoothMove(6, 43, 20); // Elbow

  // Keyframe 7 @ 2.61s: Fingers [-, -, -, -, -] Arm [-, 39, -]
  smoothMove(6, 39, 20); // Elbow

  // Keyframe 8 @ 3.00s: Fingers [-, -, -, -, -] Arm [-, 34, -]
  smoothMove(6, 34, 19); // Elbow

  // Keyframe 9 @ 3.51s: Fingers [-, -, -, -, -] Arm [-, 30, -]
  smoothMove(6, 30, 20); // Elbow

  // Keyframe 10 @ 4.01s: Fingers [-, -, -, -, -] Arm [-, 34, -]
  smoothMove(6, 34, 20); // Elbow

  // Keyframe 11 @ 4.17s: Fingers [-, -, -, -, -] Arm [-, 39, -]
  smoothMove(6, 39, 7); // Elbow

  // Keyframe 12 @ 4.30s: Fingers [-, -, -, -, -] Arm [-, 43, -]
  smoothMove(6, 43, 6); // Elbow

  // Keyframe 13 @ 5.77s: Fingers [-, -, -, -, -] Arm [-, 39, -]
  smoothMove(6, 39, 20); // Elbow

  // Keyframe 14 @ 6.46s: Fingers [-, -, -, -, -] Arm [-, 43, -]
  smoothMove(6, 43, 20); // Elbow

  // Keyframe 15 @ 6.54s: Fingers [-, -, -, -, -] Arm [-, 47, -]
  smoothMove(6, 47, 3); // Elbow

  // Keyframe 16 @ 6.62s: Fingers [-, -, -, -, -] Arm [-, 51, -]
  smoothMove(6, 51, 3); // Elbow

  // Keyframe 17 @ 6.71s: Fingers [-, -, -, -, -] Arm [-, 55, -]
  smoothMove(6, 55, 4); // Elbow

  // Keyframe 18 @ 6.97s: Fingers [-, -, -, -, -] Arm [-, 59, -]
  smoothMove(6, 59, 13); // Elbow

  // Keyframe 19 @ 7.49s: Fingers [-, -, -, -, -] Arm [-, 63, -]
  smoothMove(6, 63, 20); // Elbow

  // Keyframe 20 @ 7.97s: Fingers [-, -, -, -, -] Arm [-, 67, -]
  smoothMove(6, 67, 20); // Elbow

  // Keyframe 21 @ 8.34s: Fingers [-, -, -, -, -] Arm [-, 72, -]
  smoothMove(6, 72, 18); // Elbow

  // Keyframe 22 @ 9.00s: Fingers [-, -, -, -, -] Arm [-, 67, -]
  smoothMove(6, 67, 20); // Elbow

  // Keyframe 23 @ 9.28s: Fingers [-, -, -, -, -] Arm [-, 63, -]
  smoothMove(6, 63, 14); // Elbow

  // Keyframe 24 @ 9.57s: Fingers [-, -, -, -, -] Arm [-, 59, -]
  smoothMove(6, 59, 14); // Elbow

  // Keyframe 25 @ 11.01s: Fingers [-, -, -, -, -] Arm [-, 56, -]
  smoothMove(6, 56, 20); // Elbow

}

// Layer 3: Layer_3 - manual mode
// Duration: 11.0s, Keyframes: 70 (reduced from 911 frames)
void playLayer3() {
  // Keyframe 1 @ 0.00s: Fingers [-, -, -, -, -] Arm [-, -, 116]
  delay(4);
  servo[7].write(116); // Wrist

  // Keyframe 2 @ 0.30s: Fingers [-, -, -, -, -] Arm [-, -, 112]
  smoothMove(7, 112, 14); // Wrist

  // Keyframe 3 @ 0.36s: Fingers [-, -, -, -, -] Arm [-, -, 108]
  smoothMove(7, 108, 2); // Wrist

  // Keyframe 4 @ 0.46s: Fingers [-, -, -, -, -] Arm [-, -, 103]
  smoothMove(7, 103, 4); // Wrist

  // Keyframe 5 @ 0.51s: Fingers [-, -, -, -, -] Arm [-, -, 99]
  smoothMove(7, 99, 2); // Wrist

  // Keyframe 6 @ 0.56s: Fingers [-, -, -, -, -] Arm [-, -, 93]
  smoothMove(7, 93, 2); // Wrist

  // Keyframe 7 @ 0.62s: Fingers [-, -, -, -, -] Arm [-, -, 88]
  smoothMove(7, 88, 2); // Wrist

  // Keyframe 8 @ 0.67s: Fingers [-, -, -, -, -] Arm [-, -, 83]
  smoothMove(7, 83, 2); // Wrist

  // Keyframe 9 @ 0.72s: Fingers [-, -, -, -, -] Arm [-, -, 79]
  smoothMove(7, 79, 2); // Wrist

  // Keyframe 10 @ 0.82s: Fingers [-, -, -, -, -] Arm [-, -, 75]
  smoothMove(7, 75, 5); // Wrist

  // Keyframe 11 @ 1.02s: Fingers [-, -, -, -, -] Arm [-, -, 71]
  smoothMove(7, 71, 9); // Wrist

  // Keyframe 12 @ 1.26s: Fingers [-, -, -, -, -] Arm [-, -, 78]
  smoothMove(7, 78, 12); // Wrist

  // Keyframe 13 @ 1.31s: Fingers [-, -, -, -, -] Arm [-, -, 82]
  delay(50);
  servo[7].write(82); // Wrist

  // Keyframe 14 @ 1.38s: Fingers [-, -, -, -, -] Arm [-, -, 87]
  smoothMove(7, 87, 3); // Wrist

  // Keyframe 15 @ 1.45s: Fingers [-, -, -, -, -] Arm [-, -, 91]
  smoothMove(7, 91, 3); // Wrist

  // Keyframe 16 @ 1.52s: Fingers [-, -, -, -, -] Arm [-, -, 95]
  smoothMove(7, 95, 3); // Wrist

  // Keyframe 17 @ 1.65s: Fingers [-, -, -, -, -] Arm [-, -, 100]
  smoothMove(7, 100, 6); // Wrist

  // Keyframe 18 @ 1.73s: Fingers [-, -, -, -, -] Arm [-, -, 104]
  smoothMove(7, 104, 4); // Wrist

  // Keyframe 19 @ 1.79s: Fingers [-, -, -, -, -] Arm [-, -, 108]
  smoothMove(7, 108, 3); // Wrist

  // Keyframe 20 @ 1.85s: Fingers [-, -, -, -, -] Arm [-, -, 112]
  smoothMove(7, 112, 2); // Wrist

  // Keyframe 21 @ 1.94s: Fingers [-, -, -, -, -] Arm [-, -, 116]
  smoothMove(7, 116, 4); // Wrist

  // Keyframe 22 @ 2.04s: Fingers [-, -, -, -, -] Arm [-, -, 120]
  smoothMove(7, 120, 5); // Wrist

  // Keyframe 23 @ 2.14s: Fingers [-, -, -, -, -] Arm [-, -, 124]
  smoothMove(7, 124, 4); // Wrist

  // Keyframe 24 @ 2.22s: Fingers [-, -, -, -, -] Arm [-, -, 129]
  smoothMove(7, 129, 3); // Wrist

  // Keyframe 25 @ 2.36s: Fingers [-, -, -, -, -] Arm [-, -, 133]
  smoothMove(7, 133, 7); // Wrist

  // Keyframe 26 @ 2.82s: Fingers [-, -, -, -, -] Arm [-, -, 129]
  smoothMove(7, 129, 20); // Wrist

  // Keyframe 27 @ 2.87s: Fingers [-, -, -, -, -] Arm [-, -, 121]
  smoothMove(7, 121, 2); // Wrist

  // Keyframe 28 @ 2.93s: Fingers [-, -, -, -, -] Arm [-, -, 116]
  smoothMove(7, 116, 2); // Wrist

  // Keyframe 29 @ 3.10s: Fingers [-, -, -, -, -] Arm [-, -, 112]
  smoothMove(7, 112, 8); // Wrist

  // Keyframe 30 @ 3.26s: Fingers [-, -, -, -, -] Arm [-, -, 108]
  smoothMove(7, 108, 7); // Wrist

  // Keyframe 31 @ 3.41s: Fingers [-, -, -, -, -] Arm [-, -, 104]
  smoothMove(7, 104, 7); // Wrist

  // Keyframe 32 @ 3.50s: Fingers [-, -, -, -, -] Arm [-, -, 100]
  smoothMove(7, 100, 4); // Wrist

  // Keyframe 33 @ 3.65s: Fingers [-, -, -, -, -] Arm [-, -, 96]
  smoothMove(7, 96, 7); // Wrist

  // Keyframe 34 @ 3.79s: Fingers [-, -, -, -, -] Arm [-, -, 92]
  smoothMove(7, 92, 6); // Wrist

  // Keyframe 35 @ 3.89s: Fingers [-, -, -, -, -] Arm [-, -, 87]
  smoothMove(7, 87, 4); // Wrist

  // Keyframe 36 @ 4.02s: Fingers [-, -, -, -, -] Arm [-, -, 83]
  smoothMove(7, 83, 6); // Wrist

  // Keyframe 37 @ 4.14s: Fingers [-, -, -, -, -] Arm [-, -, 79]
  smoothMove(7, 79, 6); // Wrist

  // Keyframe 38 @ 4.34s: Fingers [-, -, -, -, -] Arm [-, -, 75]
  smoothMove(7, 75, 9); // Wrist

  // Keyframe 39 @ 4.64s: Fingers [-, -, -, -, -] Arm [-, -, 80]
  smoothMove(7, 80, 15); // Wrist

  // Keyframe 40 @ 4.71s: Fingers [-, -, -, -, -] Arm [-, -, 84]
  smoothMove(7, 84, 3); // Wrist

  // Keyframe 41 @ 5.03s: Fingers [-, -, -, -, -] Arm [-, -, 88]
  smoothMove(7, 88, 16); // Wrist

  // Keyframe 42 @ 5.11s: Fingers [-, -, -, -, -] Arm [-, -, 92]
  smoothMove(7, 92, 4); // Wrist

  // Keyframe 43 @ 5.22s: Fingers [-, -, -, -, -] Arm [-, -, 96]
  smoothMove(7, 96, 5); // Wrist

  // Keyframe 44 @ 5.38s: Fingers [-, -, -, -, -] Arm [-, -, 100]
  smoothMove(7, 100, 8); // Wrist

  // Keyframe 45 @ 5.49s: Fingers [-, -, -, -, -] Arm [-, -, 104]
  smoothMove(7, 104, 5); // Wrist

  // Keyframe 46 @ 5.60s: Fingers [-, -, -, -, -] Arm [-, -, 109]
  smoothMove(7, 109, 5); // Wrist

  // Keyframe 47 @ 5.92s: Fingers [-, -, -, -, -] Arm [-, -, 113]
  smoothMove(7, 113, 15); // Wrist

  // Keyframe 48 @ 6.20s: Fingers [-, -, -, -, -] Arm [-, -, 117]
  smoothMove(7, 117, 14); // Wrist

  // Keyframe 49 @ 6.38s: Fingers [-, -, -, -, -] Arm [-, -, 121]
  smoothMove(7, 121, 9); // Wrist

  // Keyframe 50 @ 6.63s: Fingers [-, -, -, -, -] Arm [-, -, 125]
  smoothMove(7, 125, 12); // Wrist

  // Keyframe 51 @ 6.88s: Fingers [-, -, -, -, -] Arm [-, -, 129]
  smoothMove(7, 129, 12); // Wrist

  // Keyframe 52 @ 7.16s: Fingers [-, -, -, -, -] Arm [-, -, 133]
  smoothMove(7, 133, 14); // Wrist

  // Keyframe 53 @ 7.41s: Fingers [-, -, -, -, -] Arm [-, -, 137]
  smoothMove(7, 137, 12); // Wrist

  // Keyframe 54 @ 7.68s: Fingers [-, -, -, -, -] Arm [-, -, 141]
  smoothMove(7, 141, 13); // Wrist

  // Keyframe 55 @ 8.17s: Fingers [-, -, -, -, -] Arm [-, -, 146]
  smoothMove(7, 146, 20); // Wrist

  // Keyframe 56 @ 8.34s: Fingers [-, -, -, -, -] Arm [-, -, 150]
  smoothMove(7, 150, 8); // Wrist

  // Keyframe 57 @ 9.18s: Fingers [-, -, -, -, -] Arm [-, -, 145]
  smoothMove(7, 145, 20); // Wrist

  // Keyframe 58 @ 9.26s: Fingers [-, -, -, -, -] Arm [-, -, 141]
  smoothMove(7, 141, 4); // Wrist

  // Keyframe 59 @ 9.34s: Fingers [-, -, -, -, -] Arm [-, -, 137]
  smoothMove(7, 137, 3); // Wrist

  // Keyframe 60 @ 9.42s: Fingers [-, -, -, -, -] Arm [-, -, 133]
  smoothMove(7, 133, 4); // Wrist

  // Keyframe 61 @ 9.48s: Fingers [-, -, -, -, -] Arm [-, -, 128]
  smoothMove(7, 128, 2); // Wrist

  // Keyframe 62 @ 9.54s: Fingers [-, -, -, -, -] Arm [-, -, 123]
  smoothMove(7, 123, 2); // Wrist

  // Keyframe 63 @ 9.59s: Fingers [-, -, -, -, -] Arm [-, -, 118]
  smoothMove(7, 118, 2); // Wrist

  // Keyframe 64 @ 9.65s: Fingers [-, -, -, -, -] Arm [-, -, 113]
  smoothMove(7, 113, 2); // Wrist

  // Keyframe 65 @ 9.70s: Fingers [-, -, -, -, -] Arm [-, -, 108]
  smoothMove(7, 108, 2); // Wrist

  // Keyframe 66 @ 9.76s: Fingers [-, -, -, -, -] Arm [-, -, 103]
  smoothMove(7, 103, 2); // Wrist

  // Keyframe 67 @ 9.81s: Fingers [-, -, -, -, -] Arm [-, -, 96]
  smoothMove(7, 96, 2); // Wrist

  // Keyframe 68 @ 9.86s: Fingers [-, -, -, -, -] Arm [-, -, 91]
  smoothMove(7, 91, 2); // Wrist

  // Keyframe 69 @ 9.95s: Fingers [-, -, -, -, -] Arm [-, -, 87]
  smoothMove(7, 87, 4); // Wrist

  // Keyframe 70 @ 11.00s: Fingers [-, -, -, -, -] Arm [-, -, 85]
  smoothMove(7, 85, 20); // Wrist

}

// Layer 4: Layer_4 - cursor mode
// Duration: 11.0s, Keyframes: 50 (reduced from 1264 frames)
void playLayer4() {
  // Keyframe 1 @ 0.00s: Fingers [50, 56, 59, 58, 53] Arm [-, -, -]
  delay(4);
  servo[0].write(50); // Thumb
  servo[1].write(56); // Index
  servo[2].write(59); // Middle
  servo[3].write(58); // Ring
  servo[4].write(53); // Pinky

  // Keyframe 2 @ 0.32s: Fingers [58, 65, 68, 68, 64] Arm [-, -, -]
  smoothMove(0, 58, 15); // Thumb
  smoothMove(1, 65, 15); // Index
  smoothMove(2, 68, 15); // Middle
  smoothMove(3, 68, 15); // Ring
  smoothMove(4, 64, 15); // Pinky

  // Keyframe 3 @ 0.52s: Fingers [75, 81, 85, 84, 80] Arm [-, -, -]
  smoothMove(0, 75, 10); // Thumb
  smoothMove(1, 81, 10); // Index
  smoothMove(2, 85, 10); // Middle
  smoothMove(3, 84, 10); // Ring
  smoothMove(4, 80, 10); // Pinky

  // Keyframe 4 @ 0.72s: Fingers [87, 94, 98, 98, 95] Arm [-, -, -]
  smoothMove(0, 87, 10); // Thumb
  smoothMove(1, 94, 10); // Index
  smoothMove(2, 98, 10); // Middle
  smoothMove(3, 98, 10); // Ring
  smoothMove(4, 95, 10); // Pinky

  // Keyframe 5 @ 0.93s: Fingers [95, 103, 109, 111, 110] Arm [-, -, -]
  smoothMove(0, 95, 10); // Thumb
  smoothMove(1, 103, 10); // Index
  smoothMove(2, 109, 10); // Middle
  smoothMove(3, 111, 10); // Ring
  smoothMove(4, 110, 10); // Pinky

  // Keyframe 6 @ 1.13s: Fingers [105, 113, 119, 121, 120] Arm [-, -, -]
  smoothMove(0, 105, 10); // Thumb
  smoothMove(1, 113, 10); // Index
  smoothMove(2, 119, 10); // Middle
  smoothMove(3, 121, 10); // Ring
  smoothMove(4, 120, 10); // Pinky

  // Keyframe 7 @ 1.35s: Fingers [127, 131, 132, 129, 123] Arm [-, -, -]
  smoothMove(0, 127, 10); // Thumb
  smoothMove(1, 131, 10); // Index
  smoothMove(2, 132, 10); // Middle
  smoothMove(3, 129, 10); // Ring
  smoothMove(4, 123, 10); // Pinky

  // Keyframe 8 @ 1.65s: Fingers [130, 130, 125, 118, 110] Arm [-, -, -]
  smoothMove(0, 130, 15); // Thumb
  smoothMove(1, 130, 15); // Index
  smoothMove(2, 125, 15); // Middle
  smoothMove(3, 118, 15); // Ring
  smoothMove(4, 110, 15); // Pinky

  // Keyframe 9 @ 1.85s: Fingers [119, 116, 110, 102, 94] Arm [-, -, -]
  smoothMove(0, 119, 10); // Thumb
  smoothMove(1, 116, 10); // Index
  smoothMove(2, 110, 10); // Middle
  smoothMove(3, 102, 10); // Ring
  smoothMove(4, 94, 10); // Pinky

  // Keyframe 10 @ 2.06s: Fingers [95, 93, 88, 81, 72] Arm [-, -, -]
  smoothMove(0, 95, 10); // Thumb
  smoothMove(1, 93, 10); // Index
  smoothMove(2, 88, 10); // Middle
  smoothMove(3, 81, 10); // Ring
  smoothMove(4, 72, 10); // Pinky

  // Keyframe 11 @ 2.26s: Fingers [71, 74, 73, 68, 60] Arm [-, -, -]
  smoothMove(0, 71, 10); // Thumb
  smoothMove(1, 74, 10); // Index
  smoothMove(2, 73, 10); // Middle
  smoothMove(3, 68, 10); // Ring
  smoothMove(4, 60, 10); // Pinky

  // Keyframe 12 @ 2.47s: Fingers [52, 50, 45, 38, 29] Arm [-, -, -]
  smoothMove(0, 52, 10); // Thumb
  smoothMove(1, 50, 10); // Index
  smoothMove(2, 45, 10); // Middle
  smoothMove(3, 38, 10); // Ring
  smoothMove(4, 29, 10); // Pinky

  // Keyframe 13 @ 2.67s: Fingers [24, 17, 13, 12, 15] Arm [-, -, -]
  smoothMove(0, 24, 10); // Thumb
  smoothMove(1, 17, 10); // Index
  smoothMove(2, 13, 10); // Middle
  smoothMove(3, 12, 10); // Ring
  smoothMove(4, 15, 10); // Pinky

  // Keyframe 14 @ 2.88s: Fingers [19, 22, 28, 36, 44] Arm [-, -, -]
  smoothMove(0, 19, 10); // Thumb
  smoothMove(1, 22, 10); // Index
  smoothMove(2, 28, 10); // Middle
  smoothMove(3, 36, 10); // Ring
  smoothMove(4, 44, 10); // Pinky

  // Keyframe 15 @ 3.08s: Fingers [48, 56, 64, 71, 75] Arm [-, -, -]
  smoothMove(0, 48, 10); // Thumb
  smoothMove(1, 56, 10); // Index
  smoothMove(2, 64, 10); // Middle
  smoothMove(3, 71, 10); // Ring
  smoothMove(4, 75, 10); // Pinky

  // Keyframe 16 @ 3.29s: Fingers [73, 81, 89, 96, 100] Arm [-, -, -]
  smoothMove(0, 73, 10); // Thumb
  smoothMove(1, 81, 10); // Index
  smoothMove(2, 89, 10); // Middle
  smoothMove(3, 96, 10); // Ring
  smoothMove(4, 100, 10); // Pinky

  // Keyframe 17 @ 3.49s: Fingers [86, 82, 81, 85, 91] Arm [-, -, -]
  smoothMove(0, 86, 10); // Thumb
  smoothMove(1, 82, 10); // Index
  smoothMove(2, 81, 10); // Middle
  smoothMove(3, 85, 10); // Ring
  smoothMove(4, 91, 10); // Pinky

  // Keyframe 18 @ 3.71s: Fingers [123, 122, 117, 109, 101] Arm [-, -, -]
  smoothMove(0, 123, 11); // Thumb
  smoothMove(1, 122, 11); // Index
  smoothMove(2, 117, 11); // Middle
  smoothMove(3, 109, 11); // Ring
  smoothMove(4, 101, 11); // Pinky

  // Keyframe 19 @ 3.93s: Fingers [94, 102, 110, 117, 122] Arm [-, -, -]
  smoothMove(0, 94, 10); // Thumb
  smoothMove(1, 102, 10); // Index
  smoothMove(2, 110, 10); // Middle
  smoothMove(3, 117, 10); // Ring
  smoothMove(4, 122, 10); // Pinky

  // Keyframe 20 @ 4.13s: Fingers [82, 83, 88, 95, 104] Arm [-, -, -]
  smoothMove(0, 82, 10); // Thumb
  smoothMove(1, 83, 10); // Index
  smoothMove(2, 88, 10); // Middle
  smoothMove(3, 95, 10); // Ring
  smoothMove(4, 104, 10); // Pinky

  // Keyframe 21 @ 4.44s: Fingers [82, 90, 99, 105, 109] Arm [-, -, -]
  smoothMove(0, 82, 15); // Thumb
  smoothMove(1, 90, 15); // Index
  smoothMove(2, 99, 15); // Middle
  smoothMove(3, 105, 15); // Ring
  smoothMove(4, 109, 15); // Pinky

  // Keyframe 22 @ 4.65s: Fingers [118, 122, 122, 118, 112] Arm [-, -, -]
  smoothMove(0, 118, 10); // Thumb
  smoothMove(1, 122, 10); // Index
  smoothMove(2, 122, 10); // Middle
  smoothMove(3, 118, 10); // Ring
  smoothMove(4, 112, 10); // Pinky

  // Keyframe 23 @ 4.85s: Fingers [137, 140, 140, 136, 128] Arm [-, -, -]
  smoothMove(0, 137, 10); // Thumb
  smoothMove(1, 140, 10); // Index
  smoothMove(2, 140, 10); // Middle
  smoothMove(3, 136, 10); // Ring
  smoothMove(4, 128, 10); // Pinky

  // Keyframe 24 @ 5.05s: Fingers [147, 152, 154, 151, 146] Arm [-, -, -]
  smoothMove(0, 147, 10); // Thumb
  smoothMove(1, 152, 10); // Index
  smoothMove(2, 154, 10); // Middle
  smoothMove(3, 151, 10); // Ring
  smoothMove(4, 146, 10); // Pinky

  // Keyframe 25 @ 5.44s: Fingers [159, 160, 157, 150, 142] Arm [-, -, -]
  smoothMove(0, 159, 19); // Thumb
  smoothMove(1, 160, 19); // Index
  smoothMove(2, 157, 19); // Middle
  smoothMove(3, 150, 19); // Ring
  smoothMove(4, 142, 19); // Pinky

  // Keyframe 26 @ 5.65s: Fingers [171, 169, 164, 157, 148] Arm [-, -, -]
  smoothMove(0, 171, 10); // Thumb
  smoothMove(1, 169, 10); // Index
  smoothMove(2, 164, 10); // Middle
  smoothMove(3, 157, 10); // Ring
  smoothMove(4, 148, 10); // Pinky

  // Keyframe 27 @ 5.94s: Fingers [165, 161, 154, 146, 138] Arm [-, -, -]
  smoothMove(0, 165, 14); // Thumb
  smoothMove(1, 161, 14); // Index
  smoothMove(2, 154, 14); // Middle
  smoothMove(3, 146, 14); // Ring
  smoothMove(4, 138, 14); // Pinky

  // Keyframe 28 @ 6.15s: Fingers [154, 149, 142, 133, 126] Arm [-, -, -]
  smoothMove(0, 154, 10); // Thumb
  smoothMove(1, 149, 10); // Index
  smoothMove(2, 142, 10); // Middle
  smoothMove(3, 133, 10); // Ring
  smoothMove(4, 126, 10); // Pinky

  // Keyframe 29 @ 6.62s: Fingers [144, 141, 135, 126, 118] Arm [-, -, -]
  smoothMove(0, 144, 20); // Thumb
  smoothMove(1, 141, 20); // Index
  smoothMove(2, 135, 20); // Middle
  smoothMove(3, 126, 20); // Ring
  smoothMove(4, 118, 20); // Pinky

  // Keyframe 30 @ 6.87s: Fingers [134, 131, 124, 116, 108] Arm [-, -, -]
  smoothMove(0, 134, 12); // Thumb
  smoothMove(1, 131, 12); // Index
  smoothMove(2, 124, 12); // Middle
  smoothMove(3, 116, 12); // Ring
  smoothMove(4, 108, 12); // Pinky

  // Keyframe 31 @ 7.07s: Fingers [114, 113, 108, 100, 92] Arm [-, -, -]
  smoothMove(0, 114, 10); // Thumb
  smoothMove(1, 113, 10); // Index
  smoothMove(2, 108, 10); // Middle
  smoothMove(3, 100, 10); // Ring
  smoothMove(4, 92, 10); // Pinky

  // Keyframe 32 @ 7.27s: Fingers [95, 97, 95, 90, 82] Arm [-, -, -]
  smoothMove(0, 95, 10); // Thumb
  smoothMove(1, 97, 10); // Index
  smoothMove(2, 95, 10); // Middle
  smoothMove(3, 90, 10); // Ring
  smoothMove(4, 82, 10); // Pinky

  // Keyframe 33 @ 7.49s: Fingers [85, 88, 88, 83, 76] Arm [-, -, -]
  smoothMove(0, 85, 10); // Thumb
  smoothMove(1, 88, 10); // Index
  smoothMove(2, 88, 10); // Middle
  smoothMove(3, 83, 10); // Ring
  smoothMove(4, 76, 10); // Pinky

  // Keyframe 34 @ 7.70s: Fingers [70, 76, 78, 76, 71] Arm [-, -, -]
  smoothMove(0, 70, 10); // Thumb
  smoothMove(1, 76, 10); // Index
  smoothMove(2, 78, 10); // Middle
  smoothMove(3, 76, 10); // Ring
  smoothMove(4, 71, 10); // Pinky

  // Keyframe 35 @ 7.90s: Fingers [54, 61, 65, 65, 61] Arm [-, -, -]
  smoothMove(0, 54, 10); // Thumb
  smoothMove(1, 61, 10); // Index
  smoothMove(2, 65, 10); // Middle
  smoothMove(3, 65, 10); // Ring
  smoothMove(4, 61, 10); // Pinky

  // Keyframe 36 @ 8.15s: Fingers [48, 54, 57, 56, 51] Arm [-, -, -]
  smoothMove(0, 48, 12); // Thumb
  smoothMove(1, 54, 12); // Index
  smoothMove(2, 57, 12); // Middle
  smoothMove(3, 56, 12); // Ring
  smoothMove(4, 51, 12); // Pinky

  // Keyframe 37 @ 8.37s: Fingers [54, 54, 50, 43, 35] Arm [-, -, -]
  smoothMove(0, 54, 11); // Thumb
  smoothMove(1, 54, 11); // Index
  smoothMove(2, 50, 11); // Middle
  smoothMove(3, 43, 11); // Ring
  smoothMove(4, 35, 11); // Pinky

  // Keyframe 38 @ 8.58s: Fingers [45, 43, 38, 30, 22] Arm [-, -, -]
  smoothMove(0, 45, 10); // Thumb
  smoothMove(1, 43, 10); // Index
  smoothMove(2, 38, 10); // Middle
  smoothMove(3, 30, 10); // Ring
  smoothMove(4, 22, 10); // Pinky

  // Keyframe 39 @ 8.78s: Fingers [41, 46, 48, 45, 39] Arm [-, -, -]
  smoothMove(0, 41, 10); // Thumb
  smoothMove(1, 46, 10); // Index
  smoothMove(2, 48, 10); // Middle
  smoothMove(3, 45, 10); // Ring
  smoothMove(4, 39, 10); // Pinky

  // Keyframe 40 @ 8.99s: Fingers [34, 38, 45, 53, 61] Arm [-, -, -]
  smoothMove(0, 34, 10); // Thumb
  smoothMove(1, 38, 10); // Index
  smoothMove(2, 45, 10); // Middle
  smoothMove(3, 53, 10); // Ring
  smoothMove(4, 61, 10); // Pinky

  // Keyframe 41 @ 9.19s: Fingers [61, 61, 64, 71, 79] Arm [-, -, -]
  smoothMove(0, 61, 10); // Thumb
  smoothMove(1, 61, 10); // Index
  smoothMove(2, 64, 10); // Middle
  smoothMove(3, 71, 10); // Ring
  smoothMove(4, 79, 10); // Pinky

  // Keyframe 42 @ 9.39s: Fingers [94, 101, 109, 117, 124] Arm [-, -, -]
  smoothMove(0, 94, 10); // Thumb
  smoothMove(1, 101, 10); // Index
  smoothMove(2, 109, 10); // Middle
  smoothMove(3, 117, 10); // Ring
  smoothMove(4, 124, 10); // Pinky

  // Keyframe 43 @ 9.60s: Fingers [150, 154, 154, 150, 143] Arm [-, -, -]
  smoothMove(0, 150, 10); // Thumb
  smoothMove(1, 154, 10); // Index
  smoothMove(2, 154, 10); // Middle
  smoothMove(3, 150, 10); // Ring
  smoothMove(4, 143, 10); // Pinky

  // Keyframe 44 @ 9.81s: Fingers [153, 145, 138, 133, 133] Arm [-, -, -]
  smoothMove(0, 153, 10); // Thumb
  smoothMove(1, 145, 10); // Index
  smoothMove(2, 138, 10); // Middle
  smoothMove(3, 133, 10); // Ring
  smoothMove(4, 133, 10); // Pinky

  // Keyframe 45 @ 10.02s: Fingers [128, 137, 144, 149, 150] Arm [-, -, -]
  smoothMove(0, 128, 10); // Thumb
  smoothMove(1, 137, 10); // Index
  smoothMove(2, 144, 10); // Middle
  smoothMove(3, 149, 10); // Ring
  smoothMove(4, 150, 10); // Pinky

  // Keyframe 46 @ 10.22s: Fingers [103, 111, 118, 123, 123] Arm [-, -, -]
  smoothMove(0, 103, 10); // Thumb
  smoothMove(1, 111, 10); // Index
  smoothMove(2, 118, 10); // Middle
  smoothMove(3, 123, 10); // Ring
  smoothMove(4, 123, 10); // Pinky

  // Keyframe 47 @ 10.43s: Fingers [78, 72, 71, 73, 79] Arm [-, -, -]
  smoothMove(0, 78, 10); // Thumb
  smoothMove(1, 72, 10); // Index
  smoothMove(2, 71, 10); // Middle
  smoothMove(3, 73, 10); // Ring
  smoothMove(4, 79, 10); // Pinky

  // Keyframe 48 @ 10.64s: Fingers [88, 96, 102, 104, 103] Arm [-, -, -]
  smoothMove(0, 88, 10); // Thumb
  smoothMove(1, 96, 10); // Index
  smoothMove(2, 102, 10); // Middle
  smoothMove(3, 104, 10); // Ring
  smoothMove(4, 103, 10); // Pinky

  // Keyframe 49 @ 10.85s: Fingers [78, 80, 85, 92, 101] Arm [-, -, -]
  smoothMove(0, 78, 10); // Thumb
  smoothMove(1, 80, 10); // Index
  smoothMove(2, 85, 10); // Middle
  smoothMove(3, 92, 10); // Ring
  smoothMove(4, 101, 10); // Pinky

  // Keyframe 50 @ 11.01s: Fingers [78, 80, 85, 92, 101] Arm [-, -, -]
  smoothMove(0, 78, 7); // Thumb
  smoothMove(1, 80, 7); // Index
  smoothMove(2, 85, 7); // Middle
  smoothMove(3, 92, 7); // Ring
  smoothMove(4, 101, 7); // Pinky

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
