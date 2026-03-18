/*
 * 8-Servo Hand Control - Generated Movement Code
 * Generated: 2025-12-04 18:25:35
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
// Duration: 6.6s, Keyframes: 33 (reduced from 419 frames)
void playLayer1() {
  // Keyframe 1 @ 0.01s: Fingers [-, -, -, -, -] Arm [131, -, -]
  delay(12);
  servo[5].write(131); // Shoulder

  // Keyframe 2 @ 0.48s: Fingers [-, -, -, -, -] Arm [134, -, -]
  smoothMove(5, 134, 20); // Shoulder

  // Keyframe 3 @ 0.56s: Fingers [-, -, -, -, -] Arm [137, -, -]
  smoothMove(5, 137, 3); // Shoulder

  // Keyframe 4 @ 0.63s: Fingers [-, -, -, -, -] Arm [140, -, -]
  smoothMove(5, 140, 3); // Shoulder

  // Keyframe 5 @ 0.73s: Fingers [-, -, -, -, -] Arm [143, -, -]
  smoothMove(5, 143, 4); // Shoulder

  // Keyframe 6 @ 0.88s: Fingers [-, -, -, -, -] Arm [146, -, -]
  smoothMove(5, 146, 7); // Shoulder

  // Keyframe 7 @ 1.03s: Fingers [-, -, -, -, -] Arm [149, -, -]
  smoothMove(5, 149, 7); // Shoulder

  // Keyframe 8 @ 1.19s: Fingers [-, -, -, -, -] Arm [152, -, -]
  smoothMove(5, 152, 7); // Shoulder

  // Keyframe 9 @ 1.30s: Fingers [-, -, -, -, -] Arm [155, -, -]
  smoothMove(5, 155, 5); // Shoulder

  // Keyframe 10 @ 1.43s: Fingers [-, -, -, -, -] Arm [158, -, -]
  smoothMove(5, 158, 6); // Shoulder

  // Keyframe 11 @ 1.58s: Fingers [-, -, -, -, -] Arm [162, -, -]
  smoothMove(5, 162, 7); // Shoulder

  // Keyframe 12 @ 1.68s: Fingers [-, -, -, -, -] Arm [165, -, -]
  smoothMove(5, 165, 4); // Shoulder

  // Keyframe 13 @ 1.82s: Fingers [-, -, -, -, -] Arm [168, -, -]
  smoothMove(5, 168, 7); // Shoulder

  // Keyframe 14 @ 2.03s: Fingers [-, -, -, -, -] Arm [171, -, -]
  smoothMove(5, 171, 10); // Shoulder

  // Keyframe 15 @ 2.23s: Fingers [-, -, -, -, -] Arm [174, -, -]
  smoothMove(5, 174, 9); // Shoulder

  // Keyframe 16 @ 2.68s: Fingers [-, -, -, -, -] Arm [177, -, -]
  smoothMove(5, 177, 20); // Shoulder

  // Keyframe 17 @ 3.38s: Fingers [-, -, -, -, -] Arm [174, -, -]
  smoothMove(5, 174, 20); // Shoulder

  // Keyframe 18 @ 3.46s: Fingers [-, -, -, -, -] Arm [171, -, -]
  smoothMove(5, 171, 3); // Shoulder

  // Keyframe 19 @ 3.54s: Fingers [-, -, -, -, -] Arm [168, -, -]
  smoothMove(5, 168, 4); // Shoulder

  // Keyframe 20 @ 3.67s: Fingers [-, -, -, -, -] Arm [165, -, -]
  smoothMove(5, 165, 6); // Shoulder

  // Keyframe 21 @ 3.82s: Fingers [-, -, -, -, -] Arm [162, -, -]
  smoothMove(5, 162, 7); // Shoulder

  // Keyframe 22 @ 4.01s: Fingers [-, -, -, -, -] Arm [158, -, -]
  smoothMove(5, 158, 9); // Shoulder

  // Keyframe 23 @ 4.15s: Fingers [-, -, -, -, -] Arm [155, -, -]
  smoothMove(5, 155, 7); // Shoulder

  // Keyframe 24 @ 4.27s: Fingers [-, -, -, -, -] Arm [152, -, -]
  smoothMove(5, 152, 6); // Shoulder

  // Keyframe 25 @ 4.38s: Fingers [-, -, -, -, -] Arm [149, -, -]
  smoothMove(5, 149, 5); // Shoulder

  // Keyframe 26 @ 4.52s: Fingers [-, -, -, -, -] Arm [146, -, -]
  smoothMove(5, 146, 7); // Shoulder

  // Keyframe 27 @ 4.65s: Fingers [-, -, -, -, -] Arm [143, -, -]
  smoothMove(5, 143, 6); // Shoulder

  // Keyframe 28 @ 4.76s: Fingers [-, -, -, -, -] Arm [140, -, -]
  smoothMove(5, 140, 5); // Shoulder

  // Keyframe 29 @ 4.89s: Fingers [-, -, -, -, -] Arm [137, -, -]
  smoothMove(5, 137, 6); // Shoulder

  // Keyframe 30 @ 5.06s: Fingers [-, -, -, -, -] Arm [134, -, -]
  smoothMove(5, 134, 8); // Shoulder

  // Keyframe 31 @ 5.31s: Fingers [-, -, -, -, -] Arm [131, -, -]
  smoothMove(5, 131, 12); // Shoulder

  // Keyframe 32 @ 5.59s: Fingers [-, -, -, -, -] Arm [128, -, -]
  smoothMove(5, 128, 14); // Shoulder

  // Keyframe 33 @ 6.61s: Fingers [-, -, -, -, -] Arm [126, -, -]
  smoothMove(5, 126, 20); // Shoulder

}

// Layer 2: Layer_2 - manual mode
// Duration: 11.0s, Keyframes: 32 (reduced from 592 frames)
void playLayer2() {
  // Keyframe 1 @ 0.01s: Fingers [-, -, -, -, -] Arm [-, 63, -]
  delay(5);
  servo[6].write(63); // Elbow

  // Keyframe 2 @ 0.76s: Fingers [-, -, -, -, -] Arm [-, 60, -]
  smoothMove(6, 60, 20); // Elbow

  // Keyframe 3 @ 1.25s: Fingers [-, -, -, -, -] Arm [-, 57, -]
  smoothMove(6, 57, 20); // Elbow

  // Keyframe 4 @ 1.36s: Fingers [-, -, -, -, -] Arm [-, 54, -]
  smoothMove(6, 54, 5); // Elbow

  // Keyframe 5 @ 1.48s: Fingers [-, -, -, -, -] Arm [-, 51, -]
  smoothMove(6, 51, 5); // Elbow

  // Keyframe 6 @ 1.61s: Fingers [-, -, -, -, -] Arm [-, 48, -]
  smoothMove(6, 48, 6); // Elbow

  // Keyframe 7 @ 2.02s: Fingers [-, -, -, -, -] Arm [-, 45, -]
  smoothMove(6, 45, 20); // Elbow

  // Keyframe 8 @ 2.26s: Fingers [-, -, -, -, -] Arm [-, 42, -]
  smoothMove(6, 42, 12); // Elbow

  // Keyframe 9 @ 2.61s: Fingers [-, -, -, -, -] Arm [-, 39, -]
  smoothMove(6, 39, 17); // Elbow

  // Keyframe 10 @ 2.90s: Fingers [-, -, -, -, -] Arm [-, 36, -]
  smoothMove(6, 36, 14); // Elbow

  // Keyframe 11 @ 3.13s: Fingers [-, -, -, -, -] Arm [-, 32, -]
  smoothMove(6, 32, 11); // Elbow

  // Keyframe 12 @ 3.54s: Fingers [-, -, -, -, -] Arm [-, 29, -]
  smoothMove(6, 29, 20); // Elbow

  // Keyframe 13 @ 3.88s: Fingers [-, -, -, -, -] Arm [-, 32, -]
  smoothMove(6, 32, 17); // Elbow

  // Keyframe 14 @ 4.08s: Fingers [-, -, -, -, -] Arm [-, 36, -]
  smoothMove(6, 36, 9); // Elbow

  // Keyframe 15 @ 4.17s: Fingers [-, -, -, -, -] Arm [-, 39, -]
  smoothMove(6, 39, 4); // Elbow

  // Keyframe 16 @ 4.26s: Fingers [-, -, -, -, -] Arm [-, 42, -]
  smoothMove(6, 42, 4); // Elbow

  // Keyframe 17 @ 5.77s: Fingers [-, -, -, -, -] Arm [-, 39, -]
  smoothMove(6, 39, 20); // Elbow

  // Keyframe 18 @ 6.40s: Fingers [-, -, -, -, -] Arm [-, 42, -]
  smoothMove(6, 42, 20); // Elbow

  // Keyframe 19 @ 6.51s: Fingers [-, -, -, -, -] Arm [-, 45, -]
  smoothMove(6, 45, 5); // Elbow

  // Keyframe 20 @ 6.55s: Fingers [-, -, -, -, -] Arm [-, 48, -]
  delay(38);
  servo[6].write(48); // Elbow

  // Keyframe 21 @ 6.62s: Fingers [-, -, -, -, -] Arm [-, 51, -]
  smoothMove(6, 51, 3); // Elbow

  // Keyframe 22 @ 6.69s: Fingers [-, -, -, -, -] Arm [-, 54, -]
  smoothMove(6, 54, 3); // Elbow

  // Keyframe 23 @ 6.93s: Fingers [-, -, -, -, -] Arm [-, 57, -]
  smoothMove(6, 57, 11); // Elbow

  // Keyframe 24 @ 7.01s: Fingers [-, -, -, -, -] Arm [-, 60, -]
  smoothMove(6, 60, 4); // Elbow

  // Keyframe 25 @ 7.49s: Fingers [-, -, -, -, -] Arm [-, 63, -]
  smoothMove(6, 63, 20); // Elbow

  // Keyframe 26 @ 7.94s: Fingers [-, -, -, -, -] Arm [-, 66, -]
  smoothMove(6, 66, 20); // Elbow

  // Keyframe 27 @ 8.11s: Fingers [-, -, -, -, -] Arm [-, 69, -]
  smoothMove(6, 69, 8); // Elbow

  // Keyframe 28 @ 9.04s: Fingers [-, -, -, -, -] Arm [-, 66, -]
  smoothMove(6, 66, 20); // Elbow

  // Keyframe 29 @ 9.28s: Fingers [-, -, -, -, -] Arm [-, 63, -]
  smoothMove(6, 63, 11); // Elbow

  // Keyframe 30 @ 9.53s: Fingers [-, -, -, -, -] Arm [-, 60, -]
  smoothMove(6, 60, 12); // Elbow

  // Keyframe 31 @ 9.85s: Fingers [-, -, -, -, -] Arm [-, 57, -]
  smoothMove(6, 57, 16); // Elbow

  // Keyframe 32 @ 11.01s: Fingers [-, -, -, -, -] Arm [-, 56, -]
  smoothMove(6, 56, 20); // Elbow

}

// Layer 3: Layer_3 - manual mode
// Duration: 11.0s, Keyframes: 99 (reduced from 911 frames)
void playLayer3() {
  // Keyframe 1 @ 0.00s: Fingers [-, -, -, -, -] Arm [-, -, 116]
  delay(4);
  servo[7].write(116); // Wrist

  // Keyframe 2 @ 0.24s: Fingers [-, -, -, -, -] Arm [-, -, 113]
  smoothMove(7, 113, 11); // Wrist

  // Keyframe 3 @ 0.33s: Fingers [-, -, -, -, -] Arm [-, -, 110]
  smoothMove(7, 110, 4); // Wrist

  // Keyframe 4 @ 0.38s: Fingers [-, -, -, -, -] Arm [-, -, 106]
  smoothMove(7, 106, 2); // Wrist

  // Keyframe 5 @ 0.46s: Fingers [-, -, -, -, -] Arm [-, -, 103]
  smoothMove(7, 103, 3); // Wrist

  // Keyframe 6 @ 0.50s: Fingers [-, -, -, -, -] Arm [-, -, 100]
  delay(46);
  servo[7].write(100); // Wrist

  // Keyframe 7 @ 0.52s: Fingers [-, -, -, -, -] Arm [-, -, 96]
  delay(17);
  servo[7].write(96); // Wrist

  // Keyframe 8 @ 0.56s: Fingers [-, -, -, -, -] Arm [-, -, 93]
  delay(39);
  servo[7].write(93); // Wrist

  // Keyframe 9 @ 0.59s: Fingers [-, -, -, -, -] Arm [-, -, 90]
  delay(31);
  servo[7].write(90); // Wrist

  // Keyframe 10 @ 0.63s: Fingers [-, -, -, -, -] Arm [-, -, 86]
  delay(40);
  servo[7].write(86); // Wrist

  // Keyframe 11 @ 0.67s: Fingers [-, -, -, -, -] Arm [-, -, 83]
  delay(36);
  servo[7].write(83); // Wrist

  // Keyframe 12 @ 0.70s: Fingers [-, -, -, -, -] Arm [-, -, 80]
  delay(35);
  servo[7].write(80); // Wrist

  // Keyframe 13 @ 0.76s: Fingers [-, -, -, -, -] Arm [-, -, 77]
  smoothMove(7, 77, 2); // Wrist

  // Keyframe 14 @ 0.90s: Fingers [-, -, -, -, -] Arm [-, -, 74]
  smoothMove(7, 74, 7); // Wrist

  // Keyframe 15 @ 1.02s: Fingers [-, -, -, -, -] Arm [-, -, 71]
  smoothMove(7, 71, 5); // Wrist

  // Keyframe 16 @ 1.26s: Fingers [-, -, -, -, -] Arm [-, -, 78]
  smoothMove(7, 78, 12); // Wrist

  // Keyframe 17 @ 1.29s: Fingers [-, -, -, -, -] Arm [-, -, 81]
  delay(30);
  servo[7].write(81); // Wrist

  // Keyframe 18 @ 1.34s: Fingers [-, -, -, -, -] Arm [-, -, 84]
  delay(46);
  servo[7].write(84); // Wrist

  // Keyframe 19 @ 1.39s: Fingers [-, -, -, -, -] Arm [-, -, 87]
  smoothMove(7, 87, 2); // Wrist

  // Keyframe 20 @ 1.44s: Fingers [-, -, -, -, -] Arm [-, -, 91]
  delay(49);
  servo[7].write(91); // Wrist

  // Keyframe 21 @ 1.50s: Fingers [-, -, -, -, -] Arm [-, -, 94]
  smoothMove(7, 94, 2); // Wrist

  // Keyframe 22 @ 1.58s: Fingers [-, -, -, -, -] Arm [-, -, 97]
  smoothMove(7, 97, 4); // Wrist

  // Keyframe 23 @ 1.65s: Fingers [-, -, -, -, -] Arm [-, -, 100]
  smoothMove(7, 100, 3); // Wrist

  // Keyframe 24 @ 1.70s: Fingers [-, -, -, -, -] Arm [-, -, 103]
  smoothMove(7, 103, 2); // Wrist

  // Keyframe 25 @ 1.76s: Fingers [-, -, -, -, -] Arm [-, -, 106]
  smoothMove(7, 106, 2); // Wrist

  // Keyframe 26 @ 1.81s: Fingers [-, -, -, -, -] Arm [-, -, 109]
  smoothMove(7, 109, 2); // Wrist

  // Keyframe 27 @ 1.85s: Fingers [-, -, -, -, -] Arm [-, -, 112]
  delay(33);
  servo[7].write(112); // Wrist

  // Keyframe 28 @ 1.91s: Fingers [-, -, -, -, -] Arm [-, -, 115]
  smoothMove(7, 115, 3); // Wrist

  // Keyframe 29 @ 1.99s: Fingers [-, -, -, -, -] Arm [-, -, 118]
  smoothMove(7, 118, 3); // Wrist

  // Keyframe 30 @ 2.07s: Fingers [-, -, -, -, -] Arm [-, -, 121]
  smoothMove(7, 121, 4); // Wrist

  // Keyframe 31 @ 2.14s: Fingers [-, -, -, -, -] Arm [-, -, 124]
  smoothMove(7, 124, 3); // Wrist

  // Keyframe 32 @ 2.20s: Fingers [-, -, -, -, -] Arm [-, -, 128]
  smoothMove(7, 128, 3); // Wrist

  // Keyframe 33 @ 2.33s: Fingers [-, -, -, -, -] Arm [-, -, 131]
  smoothMove(7, 131, 6); // Wrist

  // Keyframe 34 @ 2.37s: Fingers [-, -, -, -, -] Arm [-, -, 134]
  delay(43);
  servo[7].write(134); // Wrist

  // Keyframe 35 @ 2.78s: Fingers [-, -, -, -, -] Arm [-, -, 131]
  smoothMove(7, 131, 20); // Wrist

  // Keyframe 36 @ 2.83s: Fingers [-, -, -, -, -] Arm [-, -, 127]
  smoothMove(7, 127, 2); // Wrist

  // Keyframe 37 @ 2.85s: Fingers [-, -, -, -, -] Arm [-, -, 123]
  delay(20);
  servo[7].write(123); // Wrist

  // Keyframe 38 @ 2.88s: Fingers [-, -, -, -, -] Arm [-, -, 120]
  delay(27);
  servo[7].write(120); // Wrist

  // Keyframe 39 @ 2.90s: Fingers [-, -, -, -, -] Arm [-, -, 117]
  delay(28);
  servo[7].write(117); // Wrist

  // Keyframe 40 @ 3.05s: Fingers [-, -, -, -, -] Arm [-, -, 114]
  smoothMove(7, 114, 7); // Wrist

  // Keyframe 41 @ 3.14s: Fingers [-, -, -, -, -] Arm [-, -, 111]
  smoothMove(7, 111, 4); // Wrist

  // Keyframe 42 @ 3.28s: Fingers [-, -, -, -, -] Arm [-, -, 108]
  smoothMove(7, 108, 6); // Wrist

  // Keyframe 43 @ 3.40s: Fingers [-, -, -, -, -] Arm [-, -, 104]
  smoothMove(7, 104, 6); // Wrist

  // Keyframe 44 @ 3.46s: Fingers [-, -, -, -, -] Arm [-, -, 101]
  smoothMove(7, 101, 3); // Wrist

  // Keyframe 45 @ 3.59s: Fingers [-, -, -, -, -] Arm [-, -, 98]
  smoothMove(7, 98, 6); // Wrist

  // Keyframe 46 @ 3.67s: Fingers [-, -, -, -, -] Arm [-, -, 95]
  smoothMove(7, 95, 4); // Wrist

  // Keyframe 47 @ 3.79s: Fingers [-, -, -, -, -] Arm [-, -, 92]
  smoothMove(7, 92, 5); // Wrist

  // Keyframe 48 @ 3.86s: Fingers [-, -, -, -, -] Arm [-, -, 88]
  smoothMove(7, 88, 3); // Wrist

  // Keyframe 49 @ 3.97s: Fingers [-, -, -, -, -] Arm [-, -, 85]
  smoothMove(7, 85, 5); // Wrist

  // Keyframe 50 @ 4.03s: Fingers [-, -, -, -, -] Arm [-, -, 82]
  smoothMove(7, 82, 3); // Wrist

  // Keyframe 51 @ 4.10s: Fingers [-, -, -, -, -] Arm [-, -, 79]
  smoothMove(7, 79, 3); // Wrist

  // Keyframe 52 @ 4.30s: Fingers [-, -, -, -, -] Arm [-, -, 76]
  smoothMove(7, 76, 9); // Wrist

  // Keyframe 53 @ 4.40s: Fingers [-, -, -, -, -] Arm [-, -, 73]
  smoothMove(7, 73, 5); // Wrist

  // Keyframe 54 @ 4.62s: Fingers [-, -, -, -, -] Arm [-, -, 77]
  smoothMove(7, 77, 10); // Wrist

  // Keyframe 55 @ 4.64s: Fingers [-, -, -, -, -] Arm [-, -, 80]
  delay(24);
  servo[7].write(80); // Wrist

  // Keyframe 56 @ 4.68s: Fingers [-, -, -, -, -] Arm [-, -, 83]
  delay(38);
  servo[7].write(83); // Wrist

  // Keyframe 57 @ 5.00s: Fingers [-, -, -, -, -] Arm [-, -, 86]
  smoothMove(7, 86, 15); // Wrist

  // Keyframe 58 @ 5.06s: Fingers [-, -, -, -, -] Arm [-, -, 90]
  smoothMove(7, 90, 3); // Wrist

  // Keyframe 59 @ 5.12s: Fingers [-, -, -, -, -] Arm [-, -, 93]
  smoothMove(7, 93, 3); // Wrist

  // Keyframe 60 @ 5.19s: Fingers [-, -, -, -, -] Arm [-, -, 96]
  smoothMove(7, 96, 3); // Wrist

  // Keyframe 61 @ 5.32s: Fingers [-, -, -, -, -] Arm [-, -, 99]
  smoothMove(7, 99, 6); // Wrist

  // Keyframe 62 @ 5.42s: Fingers [-, -, -, -, -] Arm [-, -, 102]
  smoothMove(7, 102, 5); // Wrist

  // Keyframe 63 @ 5.50s: Fingers [-, -, -, -, -] Arm [-, -, 105]
  smoothMove(7, 105, 3); // Wrist

  // Keyframe 64 @ 5.58s: Fingers [-, -, -, -, -] Arm [-, -, 108]
  smoothMove(7, 108, 4); // Wrist

  // Keyframe 65 @ 5.75s: Fingers [-, -, -, -, -] Arm [-, -, 111]
  smoothMove(7, 111, 8); // Wrist

  // Keyframe 66 @ 5.98s: Fingers [-, -, -, -, -] Arm [-, -, 114]
  smoothMove(7, 114, 11); // Wrist

  // Keyframe 67 @ 6.23s: Fingers [-, -, -, -, -] Arm [-, -, 117]
  smoothMove(7, 117, 12); // Wrist

  // Keyframe 68 @ 6.38s: Fingers [-, -, -, -, -] Arm [-, -, 120]
  smoothMove(7, 120, 7); // Wrist

  // Keyframe 69 @ 6.58s: Fingers [-, -, -, -, -] Arm [-, -, 123]
  smoothMove(7, 123, 10); // Wrist

  // Keyframe 70 @ 6.72s: Fingers [-, -, -, -, -] Arm [-, -, 127]
  smoothMove(7, 127, 7); // Wrist

  // Keyframe 71 @ 6.96s: Fingers [-, -, -, -, -] Arm [-, -, 130]
  smoothMove(7, 130, 11); // Wrist

  // Keyframe 72 @ 7.16s: Fingers [-, -, -, -, -] Arm [-, -, 133]
  smoothMove(7, 133, 9); // Wrist

  // Keyframe 73 @ 7.27s: Fingers [-, -, -, -, -] Arm [-, -, 136]
  smoothMove(7, 136, 5); // Wrist

  // Keyframe 74 @ 7.51s: Fingers [-, -, -, -, -] Arm [-, -, 139]
  smoothMove(7, 139, 12); // Wrist

  // Keyframe 75 @ 7.77s: Fingers [-, -, -, -, -] Arm [-, -, 142]
  smoothMove(7, 142, 12); // Wrist

  // Keyframe 76 @ 8.14s: Fingers [-, -, -, -, -] Arm [-, -, 145]
  smoothMove(7, 145, 18); // Wrist

  // Keyframe 77 @ 8.28s: Fingers [-, -, -, -, -] Arm [-, -, 148]
  smoothMove(7, 148, 6); // Wrist

  // Keyframe 78 @ 8.42s: Fingers [-, -, -, -, -] Arm [-, -, 151]
  smoothMove(7, 151, 7); // Wrist

  // Keyframe 79 @ 9.09s: Fingers [-, -, -, -, -] Arm [-, -, 148]
  smoothMove(7, 148, 20); // Wrist

  // Keyframe 80 @ 9.18s: Fingers [-, -, -, -, -] Arm [-, -, 145]
  smoothMove(7, 145, 4); // Wrist

  // Keyframe 81 @ 9.23s: Fingers [-, -, -, -, -] Arm [-, -, 142]
  smoothMove(7, 142, 2); // Wrist

  // Keyframe 82 @ 9.31s: Fingers [-, -, -, -, -] Arm [-, -, 138]
  smoothMove(7, 138, 4); // Wrist

  // Keyframe 83 @ 9.37s: Fingers [-, -, -, -, -] Arm [-, -, 135]
  smoothMove(7, 135, 2); // Wrist

  // Keyframe 84 @ 9.43s: Fingers [-, -, -, -, -] Arm [-, -, 132]
  smoothMove(7, 132, 3); // Wrist

  // Keyframe 85 @ 9.47s: Fingers [-, -, -, -, -] Arm [-, -, 129]
  delay(39);
  servo[7].write(129); // Wrist

  // Keyframe 86 @ 9.50s: Fingers [-, -, -, -, -] Arm [-, -, 126]
  delay(26);
  servo[7].write(126); // Wrist

  // Keyframe 87 @ 9.54s: Fingers [-, -, -, -, -] Arm [-, -, 123]
  delay(35);
  servo[7].write(123); // Wrist

  // Keyframe 88 @ 9.57s: Fingers [-, -, -, -, -] Arm [-, -, 120]
  delay(36);
  servo[7].write(120); // Wrist

  // Keyframe 89 @ 9.61s: Fingers [-, -, -, -, -] Arm [-, -, 117]
  delay(33);
  servo[7].write(117); // Wrist

  // Keyframe 90 @ 9.63s: Fingers [-, -, -, -, -] Arm [-, -, 114]
  delay(26);
  servo[7].write(114); // Wrist

  // Keyframe 91 @ 9.67s: Fingers [-, -, -, -, -] Arm [-, -, 110]
  delay(41);
  servo[7].write(110); // Wrist

  // Keyframe 92 @ 9.71s: Fingers [-, -, -, -, -] Arm [-, -, 106]
  delay(40);
  servo[7].write(106); // Wrist

  // Keyframe 93 @ 9.75s: Fingers [-, -, -, -, -] Arm [-, -, 103]
  delay(31);
  servo[7].write(103); // Wrist

  // Keyframe 94 @ 9.79s: Fingers [-, -, -, -, -] Arm [-, -, 100]
  delay(41);
  servo[7].write(100); // Wrist

  // Keyframe 95 @ 9.81s: Fingers [-, -, -, -, -] Arm [-, -, 96]
  delay(24);
  servo[7].write(96); // Wrist

  // Keyframe 96 @ 9.85s: Fingers [-, -, -, -, -] Arm [-, -, 92]
  delay(33);
  servo[7].write(92); // Wrist

  // Keyframe 97 @ 9.89s: Fingers [-, -, -, -, -] Arm [-, -, 89]
  delay(44);
  servo[7].write(89); // Wrist

  // Keyframe 98 @ 9.98s: Fingers [-, -, -, -, -] Arm [-, -, 86]
  smoothMove(7, 86, 4); // Wrist

  // Keyframe 99 @ 11.00s: Fingers [-, -, -, -, -] Arm [-, -, 85]
  smoothMove(7, 85, 20); // Wrist

}

// Layer 4: Layer_4 - cursor mode
// Duration: 11.0s, Keyframes: 201 (reduced from 1264 frames)
void playLayer4() {
  // Keyframe 1 @ 0.00s: Fingers [50, 56, 59, 58, 53] Arm [-, -, -]
  delay(4);
  servo[0].write(50); // Thumb
  servo[1].write(56); // Index
  servo[2].write(59); // Middle
  servo[3].write(58); // Ring
  servo[4].write(53); // Pinky

  // Keyframe 2 @ 0.26s: Fingers [55, 61, 64, 63, 58] Arm [-, -, -]
  smoothMove(0, 55, 12); // Thumb
  smoothMove(1, 61, 12); // Index
  smoothMove(2, 64, 12); // Middle
  smoothMove(3, 63, 12); // Ring
  smoothMove(4, 58, 12); // Pinky

  // Keyframe 3 @ 0.32s: Fingers [58, 65, 68, 68, 64] Arm [-, -, -]
  smoothMove(0, 58, 3); // Thumb
  smoothMove(1, 65, 3); // Index
  smoothMove(2, 68, 3); // Middle
  smoothMove(3, 68, 3); // Ring
  smoothMove(4, 64, 3); // Pinky

  // Keyframe 4 @ 0.37s: Fingers [62, 69, 73, 73, 69] Arm [-, -, -]
  smoothMove(0, 62, 2); // Thumb
  smoothMove(1, 69, 2); // Index
  smoothMove(2, 73, 2); // Middle
  smoothMove(3, 73, 2); // Ring
  smoothMove(4, 69, 2); // Pinky

  // Keyframe 5 @ 0.42s: Fingers [67, 73, 77, 77, 72] Arm [-, -, -]
  delay(42);
  servo[0].write(67); // Thumb
  servo[1].write(73); // Index
  servo[2].write(77); // Middle
  servo[3].write(77); // Ring
  servo[4].write(72); // Pinky

  // Keyframe 6 @ 0.49s: Fingers [72, 79, 82, 82, 77] Arm [-, -, -]
  smoothMove(0, 72, 3); // Thumb
  smoothMove(1, 79, 3); // Index
  smoothMove(2, 82, 3); // Middle
  smoothMove(3, 82, 3); // Ring
  smoothMove(4, 77, 3); // Pinky

  // Keyframe 7 @ 0.56s: Fingers [77, 84, 87, 87, 83] Arm [-, -, -]
  smoothMove(0, 77, 3); // Thumb
  smoothMove(1, 84, 3); // Index
  smoothMove(2, 87, 3); // Middle
  smoothMove(3, 87, 3); // Ring
  smoothMove(4, 83, 3); // Pinky

  // Keyframe 8 @ 0.63s: Fingers [81, 88, 92, 92, 89] Arm [-, -, -]
  smoothMove(0, 81, 3); // Thumb
  smoothMove(1, 88, 3); // Index
  smoothMove(2, 92, 3); // Middle
  smoothMove(3, 92, 3); // Ring
  smoothMove(4, 89, 3); // Pinky

  // Keyframe 9 @ 0.71s: Fingers [86, 93, 97, 97, 94] Arm [-, -, -]
  smoothMove(0, 86, 3); // Thumb
  smoothMove(1, 93, 3); // Index
  smoothMove(2, 97, 3); // Middle
  smoothMove(3, 97, 3); // Ring
  smoothMove(4, 94, 3); // Pinky

  // Keyframe 10 @ 0.76s: Fingers [89, 96, 101, 102, 99] Arm [-, -, -]
  delay(48);
  servo[0].write(89); // Thumb
  servo[1].write(96); // Index
  servo[2].write(101); // Middle
  servo[3].write(102); // Ring
  servo[4].write(99); // Pinky

  // Keyframe 11 @ 0.84s: Fingers [92, 100, 105, 107, 104] Arm [-, -, -]
  smoothMove(0, 92, 4); // Thumb
  smoothMove(1, 100, 4); // Index
  smoothMove(2, 105, 4); // Middle
  smoothMove(3, 107, 4); // Ring
  smoothMove(4, 104, 4); // Pinky

  // Keyframe 12 @ 0.93s: Fingers [95, 103, 109, 111, 110] Arm [-, -, -]
  smoothMove(0, 95, 4); // Thumb
  smoothMove(1, 103, 4); // Index
  smoothMove(2, 109, 4); // Middle
  smoothMove(3, 111, 4); // Ring
  smoothMove(4, 110, 4); // Pinky

  // Keyframe 13 @ 1.03s: Fingers [100, 108, 114, 116, 115] Arm [-, -, -]
  smoothMove(0, 100, 5); // Thumb
  smoothMove(1, 108, 5); // Index
  smoothMove(2, 114, 5); // Middle
  smoothMove(3, 116, 5); // Ring
  smoothMove(4, 115, 5); // Pinky

  // Keyframe 14 @ 1.13s: Fingers [105, 113, 119, 121, 120] Arm [-, -, -]
  smoothMove(0, 105, 4); // Thumb
  smoothMove(1, 113, 4); // Index
  smoothMove(2, 119, 4); // Middle
  smoothMove(3, 121, 4); // Ring
  smoothMove(4, 120, 4); // Pinky

  // Keyframe 15 @ 1.19s: Fingers [111, 119, 123, 124, 121] Arm [-, -, -]
  smoothMove(0, 111, 3); // Thumb
  smoothMove(1, 119, 3); // Index
  smoothMove(2, 123, 3); // Middle
  smoothMove(3, 124, 3); // Ring
  smoothMove(4, 121, 3); // Pinky

  // Keyframe 16 @ 1.25s: Fingers [118, 124, 127, 126, 121] Arm [-, -, -]
  smoothMove(0, 118, 2); // Thumb
  smoothMove(1, 124, 2); // Index
  smoothMove(2, 127, 2); // Middle
  smoothMove(3, 126, 2); // Ring
  smoothMove(4, 121, 2); // Pinky

  // Keyframe 17 @ 1.28s: Fingers [123, 128, 130, 128, 122] Arm [-, -, -]
  delay(31);
  servo[0].write(123); // Thumb
  servo[1].write(128); // Index
  servo[2].write(130); // Middle
  servo[3].write(128); // Ring
  servo[4].write(122); // Pinky

  // Keyframe 18 @ 1.46s: Fingers [128, 133, 134, 131, 124] Arm [-, -, -]
  smoothMove(0, 128, 8); // Thumb
  smoothMove(1, 133, 8); // Index
  smoothMove(2, 134, 8); // Middle
  smoothMove(3, 131, 8); // Ring
  smoothMove(4, 124, 8); // Pinky

  // Keyframe 19 @ 1.62s: Fingers [134, 137, 137, 132, 125] Arm [-, -, -]
  smoothMove(0, 134, 7); // Thumb
  smoothMove(1, 137, 7); // Index
  smoothMove(2, 137, 7); // Middle
  smoothMove(3, 132, 7); // Ring
  smoothMove(4, 125, 7); // Pinky

  // Keyframe 20 @ 1.64s: Fingers [133, 134, 132, 126, 118] Arm [-, -, -]
  delay(28);
  servo[0].write(133); // Thumb
  servo[1].write(134); // Index
  servo[2].write(132); // Middle
  servo[3].write(126); // Ring
  servo[4].write(118); // Pinky

  // Keyframe 21 @ 1.65s: Fingers [130, 130, 125, 118, 110] Arm [-, -, -]
  delay(6);
  servo[0].write(130); // Thumb
  servo[1].write(130); // Index
  servo[2].write(125); // Middle
  servo[3].write(118); // Ring
  servo[4].write(110); // Pinky

  // Keyframe 22 @ 1.68s: Fingers [127, 125, 119, 112, 103] Arm [-, -, -]
  delay(31);
  servo[0].write(127); // Thumb
  servo[1].write(125); // Index
  servo[2].write(119); // Middle
  servo[3].write(112); // Ring
  servo[4].write(103); // Pinky

  // Keyframe 23 @ 1.80s: Fingers [123, 120, 114, 106, 97] Arm [-, -, -]
  smoothMove(0, 123, 5); // Thumb
  smoothMove(1, 120, 5); // Index
  smoothMove(2, 114, 5); // Middle
  smoothMove(3, 106, 5); // Ring
  smoothMove(4, 97, 5); // Pinky

  // Keyframe 24 @ 1.87s: Fingers [117, 115, 109, 101, 92] Arm [-, -, -]
  smoothMove(0, 117, 3); // Thumb
  smoothMove(1, 115, 3); // Index
  smoothMove(2, 109, 3); // Middle
  smoothMove(3, 101, 3); // Ring
  smoothMove(4, 92, 3); // Pinky

  // Keyframe 25 @ 1.91s: Fingers [112, 109, 103, 95, 87] Arm [-, -, -]
  delay(42);
  servo[0].write(112); // Thumb
  servo[1].write(109); // Index
  servo[2].write(103); // Middle
  servo[3].write(95); // Ring
  servo[4].write(87); // Pinky

  // Keyframe 26 @ 1.96s: Fingers [107, 104, 98, 90, 82] Arm [-, -, -]
  smoothMove(0, 107, 2); // Thumb
  smoothMove(1, 104, 2); // Index
  smoothMove(2, 98, 2); // Middle
  smoothMove(3, 90, 2); // Ring
  smoothMove(4, 82, 2); // Pinky

  // Keyframe 27 @ 2.01s: Fingers [102, 99, 93, 85, 76] Arm [-, -, -]
  delay(48);
  servo[0].write(102); // Thumb
  servo[1].write(99); // Index
  servo[2].write(93); // Middle
  servo[3].write(85); // Ring
  servo[4].write(76); // Pinky

  // Keyframe 28 @ 2.05s: Fingers [96, 95, 89, 82, 74] Arm [-, -, -]
  delay(39);
  servo[0].write(96); // Thumb
  servo[1].write(95); // Index
  servo[2].write(89); // Middle
  servo[3].write(82); // Ring
  servo[4].write(74); // Pinky

  // Keyframe 29 @ 2.10s: Fingers [91, 90, 85, 78, 70] Arm [-, -, -]
  smoothMove(0, 91, 2); // Thumb
  smoothMove(1, 90, 2); // Index
  smoothMove(2, 85, 2); // Middle
  smoothMove(3, 78, 2); // Ring
  smoothMove(4, 70, 2); // Pinky

  // Keyframe 30 @ 2.15s: Fingers [85, 86, 83, 76, 68] Arm [-, -, -]
  delay(41);
  servo[0].write(85); // Thumb
  servo[1].write(86); // Index
  servo[2].write(83); // Middle
  servo[3].write(76); // Ring
  servo[4].write(68); // Pinky

  // Keyframe 31 @ 2.20s: Fingers [79, 81, 79, 74, 66] Arm [-, -, -]
  smoothMove(0, 79, 2); // Thumb
  smoothMove(1, 81, 2); // Index
  smoothMove(2, 79, 2); // Middle
  smoothMove(3, 74, 2); // Ring
  smoothMove(4, 66, 2); // Pinky

  // Keyframe 32 @ 2.24s: Fingers [73, 76, 75, 70, 62] Arm [-, -, -]
  delay(39);
  servo[0].write(73); // Thumb
  servo[1].write(76); // Index
  servo[2].write(75); // Middle
  servo[3].write(70); // Ring
  servo[4].write(62); // Pinky

  // Keyframe 33 @ 2.27s: Fingers [68, 71, 70, 65, 57] Arm [-, -, -]
  delay(31);
  servo[0].write(68); // Thumb
  servo[1].write(71); // Index
  servo[2].write(70); // Middle
  servo[3].write(65); // Ring
  servo[4].write(57); // Pinky

  // Keyframe 34 @ 2.31s: Fingers [63, 66, 65, 60, 52] Arm [-, -, -]
  delay(32);
  servo[0].write(63); // Thumb
  servo[1].write(66); // Index
  servo[2].write(65); // Middle
  servo[3].write(60); // Ring
  servo[4].write(52); // Pinky

  // Keyframe 35 @ 2.34s: Fingers [59, 61, 59, 54, 46] Arm [-, -, -]
  delay(31);
  servo[0].write(59); // Thumb
  servo[1].write(61); // Index
  servo[2].write(59); // Middle
  servo[3].write(54); // Ring
  servo[4].write(46); // Pinky

  // Keyframe 36 @ 2.36s: Fingers [55, 57, 54, 48, 40] Arm [-, -, -]
  delay(24);
  servo[0].write(55); // Thumb
  servo[1].write(57); // Index
  servo[2].write(54); // Middle
  servo[3].write(48); // Ring
  servo[4].write(40); // Pinky

  // Keyframe 37 @ 2.39s: Fingers [55, 54, 50, 43, 34] Arm [-, -, -]
  delay(23);
  servo[0].write(55); // Thumb
  servo[1].write(54); // Index
  servo[2].write(50); // Middle
  servo[3].write(43); // Ring
  servo[4].write(34); // Pinky

  // Keyframe 38 @ 2.48s: Fingers [51, 50, 45, 37, 29] Arm [-, -, -]
  smoothMove(0, 51, 4); // Thumb
  smoothMove(1, 50, 4); // Index
  smoothMove(2, 45, 4); // Middle
  smoothMove(3, 37, 4); // Ring
  smoothMove(4, 29, 4); // Pinky

  // Keyframe 39 @ 2.55s: Fingers [50, 46, 40, 32, 24] Arm [-, -, -]
  smoothMove(0, 50, 3); // Thumb
  smoothMove(1, 46, 3); // Index
  smoothMove(2, 40, 3); // Middle
  smoothMove(3, 32, 3); // Ring
  smoothMove(4, 24, 3); // Pinky

  // Keyframe 40 @ 2.59s: Fingers [47, 42, 35, 26, 19] Arm [-, -, -]
  delay(32);
  servo[0].write(47); // Thumb
  servo[1].write(42); // Index
  servo[2].write(35); // Middle
  servo[3].write(26); // Ring
  servo[4].write(19); // Pinky

  // Keyframe 41 @ 2.62s: Fingers [42, 35, 27, 19, 14] Arm [-, -, -]
  delay(33);
  servo[0].write(42); // Thumb
  servo[1].write(35); // Index
  servo[2].write(27); // Middle
  servo[3].write(19); // Ring
  servo[4].write(14); // Pinky

  // Keyframe 42 @ 2.63s: Fingers [37, 29, 21, 15, 12] Arm [-, -, -]
  delay(14);
  servo[0].write(37); // Thumb
  servo[1].write(29); // Index
  servo[2].write(21); // Middle
  servo[3].write(15); // Ring
  servo[4].write(12); // Pinky

  // Keyframe 43 @ 2.65s: Fingers [31, 23, 16, 12, 12] Arm [-, -, -]
  delay(16);
  servo[0].write(31); // Thumb
  servo[1].write(23); // Index
  servo[2].write(16); // Middle
  servo[3].write(12); // Ring
  servo[4].write(12); // Pinky

  // Keyframe 44 @ 2.67s: Fingers [25, 18, 13, 12, 15] Arm [-, -, -]
  delay(16);
  servo[0].write(25); // Thumb
  servo[1].write(18); // Index
  servo[2].write(13); // Middle
  servo[3].write(12); // Ring
  servo[4].write(15); // Pinky

  // Keyframe 45 @ 2.71s: Fingers [19, 14, 12, 15, 20] Arm [-, -, -]
  delay(47);
  servo[0].write(19); // Thumb
  servo[1].write(14); // Index
  servo[2].write(12); // Middle
  servo[3].write(15); // Ring
  servo[4].write(20); // Pinky

  // Keyframe 46 @ 2.77s: Fingers [17, 14, 14, 18, 25] Arm [-, -, -]
  smoothMove(0, 17, 2); // Thumb
  smoothMove(1, 14, 2); // Index
  smoothMove(2, 14, 2); // Middle
  smoothMove(3, 18, 2); // Ring
  smoothMove(4, 25, 2); // Pinky

  // Keyframe 47 @ 2.79s: Fingers [16, 15, 17, 23, 31] Arm [-, -, -]
  delay(22);
  servo[0].write(16); // Thumb
  servo[1].write(15); // Index
  servo[2].write(17); // Middle
  servo[3].write(23); // Ring
  servo[4].write(31); // Pinky

  // Keyframe 48 @ 2.82s: Fingers [16, 16, 21, 28, 36] Arm [-, -, -]
  delay(26);
  servo[0].write(16); // Thumb
  servo[1].write(16); // Index
  servo[2].write(21); // Middle
  servo[3].write(28); // Ring
  servo[4].write(36); // Pinky

  // Keyframe 49 @ 2.86s: Fingers [18, 21, 26, 34, 43] Arm [-, -, -]
  delay(38);
  servo[0].write(18); // Thumb
  servo[1].write(21); // Index
  servo[2].write(26); // Middle
  servo[3].write(34); // Ring
  servo[4].write(43); // Pinky

  // Keyframe 50 @ 2.90s: Fingers [21, 25, 32, 40, 48] Arm [-, -, -]
  delay(39);
  servo[0].write(21); // Thumb
  servo[1].write(25); // Index
  servo[2].write(32); // Middle
  servo[3].write(40); // Ring
  servo[4].write(48); // Pinky

  // Keyframe 51 @ 2.93s: Fingers [25, 30, 37, 46, 53] Arm [-, -, -]
  delay(31);
  servo[0].write(25); // Thumb
  servo[1].write(30); // Index
  servo[2].write(37); // Middle
  servo[3].write(46); // Ring
  servo[4].write(53); // Pinky

  // Keyframe 52 @ 2.97s: Fingers [29, 35, 43, 51, 58] Arm [-, -, -]
  delay(45);
  servo[0].write(29); // Thumb
  servo[1].write(35); // Index
  servo[2].write(43); // Middle
  servo[3].write(51); // Ring
  servo[4].write(58); // Pinky

  // Keyframe 53 @ 3.02s: Fingers [34, 41, 50, 58, 63] Arm [-, -, -]
  delay(42);
  servo[0].write(34); // Thumb
  servo[1].write(41); // Index
  servo[2].write(50); // Middle
  servo[3].write(58); // Ring
  servo[4].write(63); // Pinky

  // Keyframe 54 @ 3.05s: Fingers [40, 47, 56, 63, 69] Arm [-, -, -]
  delay(32);
  servo[0].write(40); // Thumb
  servo[1].write(47); // Index
  servo[2].write(56); // Middle
  servo[3].write(63); // Ring
  servo[4].write(69); // Pinky

  // Keyframe 55 @ 3.08s: Fingers [48, 56, 64, 71, 75] Arm [-, -, -]
  delay(32);
  servo[0].write(48); // Thumb
  servo[1].write(56); // Index
  servo[2].write(64); // Middle
  servo[3].write(71); // Ring
  servo[4].write(75); // Pinky

  // Keyframe 56 @ 3.11s: Fingers [54, 62, 70, 76, 79] Arm [-, -, -]
  delay(30);
  servo[0].write(54); // Thumb
  servo[1].write(62); // Index
  servo[2].write(70); // Middle
  servo[3].write(76); // Ring
  servo[4].write(79); // Pinky

  // Keyframe 57 @ 3.16s: Fingers [60, 68, 76, 82, 84] Arm [-, -, -]
  delay(49);
  servo[0].write(60); // Thumb
  servo[1].write(68); // Index
  servo[2].write(76); // Middle
  servo[3].write(82); // Ring
  servo[4].write(84); // Pinky

  // Keyframe 58 @ 3.20s: Fingers [65, 73, 81, 87, 89] Arm [-, -, -]
  delay(33);
  servo[0].write(65); // Thumb
  servo[1].write(73); // Index
  servo[2].write(81); // Middle
  servo[3].write(87); // Ring
  servo[4].write(89); // Pinky

  // Keyframe 59 @ 3.23s: Fingers [70, 78, 86, 92, 94] Arm [-, -, -]
  delay(31);
  servo[0].write(70); // Thumb
  servo[1].write(78); // Index
  servo[2].write(86); // Middle
  servo[3].write(92); // Ring
  servo[4].write(94); // Pinky

  // Keyframe 60 @ 3.29s: Fingers [73, 81, 89, 96, 100] Arm [-, -, -]
  smoothMove(0, 73, 3); // Thumb
  smoothMove(1, 81, 3); // Index
  smoothMove(2, 89, 3); // Middle
  smoothMove(3, 96, 3); // Ring
  smoothMove(4, 100, 3); // Pinky

  // Keyframe 61 @ 3.44s: Fingers [77, 79, 84, 92, 100] Arm [-, -, -]
  smoothMove(0, 77, 7); // Thumb
  smoothMove(1, 79, 7); // Index
  smoothMove(2, 84, 7); // Middle
  smoothMove(3, 92, 7); // Ring
  smoothMove(4, 100, 7); // Pinky

  // Keyframe 62 @ 3.47s: Fingers [81, 79, 82, 87, 95] Arm [-, -, -]
  delay(33);
  servo[0].write(81); // Thumb
  servo[1].write(79); // Index
  servo[2].write(82); // Middle
  servo[3].write(87); // Ring
  servo[4].write(95); // Pinky

  // Keyframe 63 @ 3.51s: Fingers [87, 83, 82, 84, 91] Arm [-, -, -]
  delay(32);
  servo[0].write(87); // Thumb
  servo[1].write(83); // Index
  servo[2].write(82); // Middle
  servo[3].write(84); // Ring
  servo[4].write(91); // Pinky

  // Keyframe 64 @ 3.51s: Fingers [94, 87, 84, 84, 88] Arm [-, -, -]
  delay(6);
  servo[0].write(94); // Thumb
  servo[1].write(87); // Index
  servo[2].write(84); // Middle
  servo[3].write(84); // Ring
  servo[4].write(88); // Pinky

  // Keyframe 65 @ 3.54s: Fingers [100, 92, 86, 84, 85] Arm [-, -, -]
  delay(24);
  servo[0].write(100); // Thumb
  servo[1].write(92); // Index
  servo[2].write(86); // Middle
  servo[3].write(84); // Ring
  servo[4].write(85); // Pinky

  // Keyframe 66 @ 3.59s: Fingers [109, 100, 93, 87, 85] Arm [-, -, -]
  delay(48);
  servo[0].write(109); // Thumb
  servo[1].write(100); // Index
  servo[2].write(93); // Middle
  servo[3].write(87); // Ring
  servo[4].write(85); // Pinky

  // Keyframe 67 @ 3.61s: Fingers [116, 109, 100, 93, 88] Arm [-, -, -]
  delay(24);
  servo[0].write(116); // Thumb
  servo[1].write(109); // Index
  servo[2].write(100); // Middle
  servo[3].write(93); // Ring
  servo[4].write(88); // Pinky

  // Keyframe 68 @ 3.63s: Fingers [121, 116, 108, 100, 92] Arm [-, -, -]
  delay(15);
  servo[0].write(121); // Thumb
  servo[1].write(116); // Index
  servo[2].write(108); // Middle
  servo[3].write(100); // Ring
  servo[4].write(92); // Pinky

  // Keyframe 69 @ 3.66s: Fingers [123, 121, 116, 108, 99] Arm [-, -, -]
  delay(33);
  servo[0].write(123); // Thumb
  servo[1].write(121); // Index
  servo[2].write(116); // Middle
  servo[3].write(108); // Ring
  servo[4].write(99); // Pinky

  // Keyframe 70 @ 3.74s: Fingers [122, 124, 121, 115, 107] Arm [-, -, -]
  smoothMove(0, 122, 3); // Thumb
  smoothMove(1, 124, 3); // Index
  smoothMove(2, 121, 3); // Middle
  smoothMove(3, 115, 3); // Ring
  smoothMove(4, 107, 3); // Pinky

  // Keyframe 71 @ 3.75s: Fingers [120, 124, 124, 120, 113] Arm [-, -, -]
  delay(16);
  servo[0].write(120); // Thumb
  servo[1].write(124); // Index
  servo[2].write(124); // Middle
  servo[3].write(120); // Ring
  servo[4].write(113); // Pinky

  // Keyframe 72 @ 3.83s: Fingers [113, 120, 124, 124, 120] Arm [-, -, -]
  smoothMove(0, 113, 4); // Thumb
  smoothMove(1, 120, 4); // Index
  smoothMove(2, 124, 4); // Middle
  smoothMove(3, 124, 4); // Ring
  smoothMove(4, 120, 4); // Pinky

  // Keyframe 73 @ 3.86s: Fingers [105, 114, 120, 124, 124] Arm [-, -, -]
  delay(31);
  servo[0].write(105); // Thumb
  servo[1].write(114); // Index
  servo[2].write(120); // Middle
  servo[3].write(124); // Ring
  servo[4].write(124); // Pinky

  // Keyframe 74 @ 3.89s: Fingers [100, 108, 116, 122, 124] Arm [-, -, -]
  delay(24);
  servo[0].write(100); // Thumb
  servo[1].write(108); // Index
  servo[2].write(116); // Middle
  servo[3].write(122); // Ring
  servo[4].write(124); // Pinky

  // Keyframe 75 @ 3.91s: Fingers [94, 102, 110, 117, 122] Arm [-, -, -]
  delay(23);
  servo[0].write(94); // Thumb
  servo[1].write(102); // Index
  servo[2].write(110); // Middle
  servo[3].write(117); // Ring
  servo[4].write(122); // Pinky

  // Keyframe 76 @ 3.97s: Fingers [90, 96, 104, 113, 119] Arm [-, -, -]
  smoothMove(0, 90, 2); // Thumb
  smoothMove(1, 96, 2); // Index
  smoothMove(2, 104, 2); // Middle
  smoothMove(3, 113, 2); // Ring
  smoothMove(4, 119, 2); // Pinky

  // Keyframe 77 @ 4.01s: Fingers [86, 90, 98, 106, 114] Arm [-, -, -]
  delay(41);
  servo[0].write(86); // Thumb
  servo[1].write(90); // Index
  servo[2].write(98); // Middle
  servo[3].write(106); // Ring
  servo[4].write(114); // Pinky

  // Keyframe 78 @ 4.06s: Fingers [84, 87, 92, 100, 109] Arm [-, -, -]
  smoothMove(0, 84, 2); // Thumb
  smoothMove(1, 87, 2); // Index
  smoothMove(2, 92, 2); // Middle
  smoothMove(3, 100, 2); // Ring
  smoothMove(4, 109, 2); // Pinky

  // Keyframe 79 @ 4.13s: Fingers [82, 83, 88, 95, 104] Arm [-, -, -]
  smoothMove(0, 82, 3); // Thumb
  smoothMove(1, 83, 3); // Index
  smoothMove(2, 88, 3); // Middle
  smoothMove(3, 95, 3); // Ring
  smoothMove(4, 104, 3); // Pinky

  // Keyframe 80 @ 4.27s: Fingers [77, 79, 84, 92, 100] Arm [-, -, -]
  smoothMove(0, 77, 6); // Thumb
  smoothMove(1, 79, 6); // Index
  smoothMove(2, 84, 6); // Middle
  smoothMove(3, 92, 6); // Ring
  smoothMove(4, 100, 6); // Pinky

  // Keyframe 81 @ 4.35s: Fingers [75, 81, 88, 97, 104] Arm [-, -, -]
  smoothMove(0, 75, 4); // Thumb
  smoothMove(1, 81, 4); // Index
  smoothMove(2, 88, 4); // Middle
  smoothMove(3, 97, 4); // Ring
  smoothMove(4, 104, 4); // Pinky

  // Keyframe 82 @ 4.41s: Fingers [79, 86, 94, 102, 108] Arm [-, -, -]
  smoothMove(0, 79, 3); // Thumb
  smoothMove(1, 86, 3); // Index
  smoothMove(2, 94, 3); // Middle
  smoothMove(3, 102, 3); // Ring
  smoothMove(4, 108, 3); // Pinky

  // Keyframe 83 @ 4.44s: Fingers [84, 92, 100, 107, 110] Arm [-, -, -]
  delay(31);
  servo[0].write(84); // Thumb
  servo[1].write(92); // Index
  servo[2].write(100); // Middle
  servo[3].write(107); // Ring
  servo[4].write(110); // Pinky

  // Keyframe 84 @ 4.46s: Fingers [91, 99, 106, 111, 111] Arm [-, -, -]
  delay(15);
  servo[0].write(91); // Thumb
  servo[1].write(99); // Index
  servo[2].write(106); // Middle
  servo[3].write(111); // Ring
  servo[4].write(111); // Pinky

  // Keyframe 85 @ 4.47s: Fingers [98, 106, 111, 112, 110] Arm [-, -, -]
  delay(15);
  servo[0].write(98); // Thumb
  servo[1].write(106); // Index
  servo[2].write(111); // Middle
  servo[3].write(112); // Ring
  servo[4].write(110); // Pinky

  // Keyframe 86 @ 4.50s: Fingers [106, 112, 115, 113, 109] Arm [-, -, -]
  delay(28);
  servo[0].write(106); // Thumb
  servo[1].write(112); // Index
  servo[2].write(115); // Middle
  servo[3].write(113); // Ring
  servo[4].write(109); // Pinky

  // Keyframe 87 @ 4.58s: Fingers [113, 117, 118, 115, 109] Arm [-, -, -]
  smoothMove(0, 113, 3); // Thumb
  smoothMove(1, 117, 3); // Index
  smoothMove(2, 118, 3); // Middle
  smoothMove(3, 115, 3); // Ring
  smoothMove(4, 109, 3); // Pinky

  // Keyframe 88 @ 4.63s: Fingers [118, 122, 122, 118, 112] Arm [-, -, -]
  smoothMove(0, 118, 2); // Thumb
  smoothMove(1, 122, 2); // Index
  smoothMove(2, 122, 2); // Middle
  smoothMove(3, 118, 2); // Ring
  smoothMove(4, 112, 2); // Pinky

  // Keyframe 89 @ 4.70s: Fingers [124, 127, 127, 123, 115] Arm [-, -, -]
  smoothMove(0, 124, 3); // Thumb
  smoothMove(1, 127, 3); // Index
  smoothMove(2, 127, 3); // Middle
  smoothMove(3, 123, 3); // Ring
  smoothMove(4, 115, 3); // Pinky

  // Keyframe 90 @ 4.75s: Fingers [129, 133, 132, 128, 121] Arm [-, -, -]
  smoothMove(0, 129, 2); // Thumb
  smoothMove(1, 133, 2); // Index
  smoothMove(2, 132, 2); // Middle
  smoothMove(3, 128, 2); // Ring
  smoothMove(4, 121, 2); // Pinky

  // Keyframe 91 @ 4.83s: Fingers [135, 138, 138, 133, 126] Arm [-, -, -]
  smoothMove(0, 135, 3); // Thumb
  smoothMove(1, 138, 3); // Index
  smoothMove(2, 138, 3); // Middle
  smoothMove(3, 133, 3); // Ring
  smoothMove(4, 126, 3); // Pinky

  // Keyframe 92 @ 4.87s: Fingers [140, 143, 143, 138, 131] Arm [-, -, -]
  delay(47);
  servo[0].write(140); // Thumb
  servo[1].write(143); // Index
  servo[2].write(143); // Middle
  servo[3].write(138); // Ring
  servo[4].write(131); // Pinky

  // Keyframe 93 @ 4.92s: Fingers [143, 147, 147, 143, 137] Arm [-, -, -]
  delay(47);
  servo[0].write(143); // Thumb
  servo[1].write(147); // Index
  servo[2].write(147); // Middle
  servo[3].write(143); // Ring
  servo[4].write(137); // Pinky

  // Keyframe 94 @ 5.00s: Fingers [146, 151, 151, 148, 142] Arm [-, -, -]
  smoothMove(0, 146, 4); // Thumb
  smoothMove(1, 151, 4); // Index
  smoothMove(2, 151, 4); // Middle
  smoothMove(3, 148, 4); // Ring
  smoothMove(4, 142, 4); // Pinky

  // Keyframe 95 @ 5.12s: Fingers [147, 153, 155, 153, 148] Arm [-, -, -]
  smoothMove(0, 147, 5); // Thumb
  smoothMove(1, 153, 5); // Index
  smoothMove(2, 155, 5); // Middle
  smoothMove(3, 153, 5); // Ring
  smoothMove(4, 148, 5); // Pinky

  // Keyframe 96 @ 5.41s: Fingers [153, 156, 156, 151, 144] Arm [-, -, -]
  smoothMove(0, 153, 14); // Thumb
  smoothMove(1, 156, 14); // Index
  smoothMove(2, 156, 14); // Middle
  smoothMove(3, 151, 14); // Ring
  smoothMove(4, 144, 14); // Pinky

  // Keyframe 97 @ 5.44s: Fingers [159, 160, 157, 150, 142] Arm [-, -, -]
  delay(31);
  servo[0].write(159); // Thumb
  servo[1].write(160); // Index
  servo[2].write(157); // Middle
  servo[3].write(150); // Ring
  servo[4].write(142); // Pinky

  // Keyframe 98 @ 5.47s: Fingers [168, 167, 163, 155, 147] Arm [-, -, -]
  delay(26);
  servo[0].write(168); // Thumb
  servo[1].write(167); // Index
  servo[2].write(163); // Middle
  servo[3].write(155); // Ring
  servo[4].write(147); // Pinky

  // Keyframe 99 @ 5.91s: Fingers [168, 165, 158, 150, 142] Arm [-, -, -]
  smoothMove(0, 168, 20); // Thumb
  smoothMove(1, 165, 20); // Index
  smoothMove(2, 158, 20); // Middle
  smoothMove(3, 150, 20); // Ring
  smoothMove(4, 142, 20); // Pinky

  // Keyframe 100 @ 5.96s: Fingers [164, 159, 152, 143, 136] Arm [-, -, -]
  smoothMove(0, 164, 2); // Thumb
  smoothMove(1, 159, 2); // Index
  smoothMove(2, 152, 2); // Middle
  smoothMove(3, 143, 2); // Ring
  smoothMove(4, 136, 2); // Pinky

  // Keyframe 101 @ 6.01s: Fingers [158, 153, 146, 137, 130] Arm [-, -, -]
  delay(49);
  servo[0].write(158); // Thumb
  servo[1].write(153); // Index
  servo[2].write(146); // Middle
  servo[3].write(137); // Ring
  servo[4].write(130); // Pinky

  // Keyframe 102 @ 6.16s: Fingers [153, 147, 139, 131, 124] Arm [-, -, -]
  smoothMove(0, 153, 7); // Thumb
  smoothMove(1, 147, 7); // Index
  smoothMove(2, 139, 7); // Middle
  smoothMove(3, 131, 7); // Ring
  smoothMove(4, 124, 7); // Pinky

  // Keyframe 103 @ 6.47s: Fingers [148, 143, 136, 127, 120] Arm [-, -, -]
  smoothMove(0, 148, 15); // Thumb
  smoothMove(1, 143, 15); // Index
  smoothMove(2, 136, 15); // Middle
  smoothMove(3, 127, 15); // Ring
  smoothMove(4, 120, 15); // Pinky

  // Keyframe 104 @ 6.67s: Fingers [142, 139, 132, 124, 116] Arm [-, -, -]
  smoothMove(0, 142, 9); // Thumb
  smoothMove(1, 139, 9); // Index
  smoothMove(2, 132, 9); // Middle
  smoothMove(3, 124, 9); // Ring
  smoothMove(4, 116, 9); // Pinky

  // Keyframe 105 @ 6.82s: Fingers [137, 134, 127, 119, 111] Arm [-, -, -]
  smoothMove(0, 137, 7); // Thumb
  smoothMove(1, 134, 7); // Index
  smoothMove(2, 127, 7); // Middle
  smoothMove(3, 119, 7); // Ring
  smoothMove(4, 111, 7); // Pinky

  // Keyframe 106 @ 6.89s: Fingers [132, 129, 122, 114, 106] Arm [-, -, -]
  smoothMove(0, 132, 3); // Thumb
  smoothMove(1, 129, 3); // Index
  smoothMove(2, 122, 3); // Middle
  smoothMove(3, 114, 3); // Ring
  smoothMove(4, 106, 3); // Pinky

  // Keyframe 107 @ 6.98s: Fingers [126, 123, 116, 108, 100] Arm [-, -, -]
  smoothMove(0, 126, 4); // Thumb
  smoothMove(1, 123, 4); // Index
  smoothMove(2, 116, 4); // Middle
  smoothMove(3, 108, 4); // Ring
  smoothMove(4, 100, 4); // Pinky

  // Keyframe 108 @ 7.01s: Fingers [121, 119, 113, 105, 97] Arm [-, -, -]
  delay(35);
  servo[0].write(121); // Thumb
  servo[1].write(119); // Index
  servo[2].write(113); // Middle
  servo[3].write(105); // Ring
  servo[4].write(97); // Pinky

  // Keyframe 109 @ 7.05s: Fingers [116, 114, 108, 100, 92] Arm [-, -, -]
  delay(38);
  servo[0].write(116); // Thumb
  servo[1].write(114); // Index
  servo[2].write(108); // Middle
  servo[3].write(100); // Ring
  servo[4].write(92); // Pinky

  // Keyframe 110 @ 7.08s: Fingers [110, 110, 105, 98, 90] Arm [-, -, -]
  delay(31);
  servo[0].write(110); // Thumb
  servo[1].write(110); // Index
  servo[2].write(105); // Middle
  servo[3].write(98); // Ring
  servo[4].write(90); // Pinky

  // Keyframe 111 @ 7.14s: Fingers [105, 105, 101, 94, 86] Arm [-, -, -]
  smoothMove(0, 105, 2); // Thumb
  smoothMove(1, 105, 2); // Index
  smoothMove(2, 101, 2); // Middle
  smoothMove(3, 94, 2); // Ring
  smoothMove(4, 86, 2); // Pinky

  // Keyframe 112 @ 7.20s: Fingers [100, 101, 98, 92, 84] Arm [-, -, -]
  smoothMove(0, 100, 3); // Thumb
  smoothMove(1, 101, 3); // Index
  smoothMove(2, 98, 3); // Middle
  smoothMove(3, 92, 3); // Ring
  smoothMove(4, 84, 3); // Pinky

  // Keyframe 113 @ 7.30s: Fingers [94, 96, 94, 89, 81] Arm [-, -, -]
  smoothMove(0, 94, 4); // Thumb
  smoothMove(1, 96, 4); // Index
  smoothMove(2, 94, 4); // Middle
  smoothMove(3, 89, 4); // Ring
  smoothMove(4, 81, 4); // Pinky

  // Keyframe 114 @ 7.43s: Fingers [88, 91, 91, 86, 79] Arm [-, -, -]
  smoothMove(0, 88, 6); // Thumb
  smoothMove(1, 91, 6); // Index
  smoothMove(2, 91, 6); // Middle
  smoothMove(3, 86, 6); // Ring
  smoothMove(4, 79, 6); // Pinky

  // Keyframe 115 @ 7.52s: Fingers [82, 86, 86, 83, 76] Arm [-, -, -]
  smoothMove(0, 82, 4); // Thumb
  smoothMove(1, 86, 4); // Index
  smoothMove(2, 86, 4); // Middle
  smoothMove(3, 83, 4); // Ring
  smoothMove(4, 76, 4); // Pinky

  // Keyframe 116 @ 7.62s: Fingers [77, 81, 82, 79, 73] Arm [-, -, -]
  smoothMove(0, 77, 4); // Thumb
  smoothMove(1, 81, 4); // Index
  smoothMove(2, 82, 4); // Middle
  smoothMove(3, 79, 4); // Ring
  smoothMove(4, 73, 4); // Pinky

  // Keyframe 117 @ 7.67s: Fingers [72, 77, 78, 76, 70] Arm [-, -, -]
  smoothMove(0, 72, 2); // Thumb
  smoothMove(1, 77, 2); // Index
  smoothMove(2, 78, 2); // Middle
  smoothMove(3, 76, 2); // Ring
  smoothMove(4, 70, 2); // Pinky

  // Keyframe 118 @ 7.76s: Fingers [67, 73, 75, 74, 70] Arm [-, -, -]
  smoothMove(0, 67, 4); // Thumb
  smoothMove(1, 73, 4); // Index
  smoothMove(2, 75, 4); // Middle
  smoothMove(3, 74, 4); // Ring
  smoothMove(4, 70, 4); // Pinky

  // Keyframe 119 @ 7.83s: Fingers [61, 67, 71, 70, 66] Arm [-, -, -]
  smoothMove(0, 61, 3); // Thumb
  smoothMove(1, 67, 3); // Index
  smoothMove(2, 71, 3); // Middle
  smoothMove(3, 70, 3); // Ring
  smoothMove(4, 66, 3); // Pinky

  // Keyframe 120 @ 7.88s: Fingers [55, 62, 66, 67, 63] Arm [-, -, -]
  smoothMove(0, 55, 2); // Thumb
  smoothMove(1, 62, 2); // Index
  smoothMove(2, 66, 2); // Middle
  smoothMove(3, 67, 2); // Ring
  smoothMove(4, 63, 2); // Pinky

  // Keyframe 121 @ 7.98s: Fingers [50, 57, 61, 62, 58] Arm [-, -, -]
  smoothMove(0, 50, 4); // Thumb
  smoothMove(1, 57, 4); // Index
  smoothMove(2, 61, 4); // Middle
  smoothMove(3, 62, 4); // Ring
  smoothMove(4, 58, 4); // Pinky

  // Keyframe 122 @ 8.06s: Fingers [47, 54, 57, 57, 53] Arm [-, -, -]
  smoothMove(0, 47, 3); // Thumb
  smoothMove(1, 54, 3); // Index
  smoothMove(2, 57, 3); // Middle
  smoothMove(3, 57, 3); // Ring
  smoothMove(4, 53, 3); // Pinky

  // Keyframe 123 @ 8.17s: Fingers [50, 55, 56, 52, 46] Arm [-, -, -]
  smoothMove(0, 50, 5); // Thumb
  smoothMove(1, 55, 5); // Index
  smoothMove(2, 56, 5); // Middle
  smoothMove(3, 52, 5); // Ring
  smoothMove(4, 46, 5); // Pinky

  // Keyframe 124 @ 8.19s: Fingers [53, 55, 53, 48, 40] Arm [-, -, -]
  delay(23);
  servo[0].write(53); // Thumb
  servo[1].write(55); // Index
  servo[2].write(53); // Middle
  servo[3].write(48); // Ring
  servo[4].write(40); // Pinky

  // Keyframe 125 @ 8.38s: Fingers [54, 54, 49, 42, 34] Arm [-, -, -]
  smoothMove(0, 54, 9); // Thumb
  smoothMove(1, 54, 9); // Index
  smoothMove(2, 49, 9); // Middle
  smoothMove(3, 42, 9); // Ring
  smoothMove(4, 34, 9); // Pinky

  // Keyframe 126 @ 8.41s: Fingers [52, 50, 45, 37, 28] Arm [-, -, -]
  delay(28);
  servo[0].write(52); // Thumb
  servo[1].write(50); // Index
  servo[2].write(45); // Middle
  servo[3].write(37); // Ring
  servo[4].write(28); // Pinky

  // Keyframe 127 @ 8.43s: Fingers [49, 46, 39, 31, 23] Arm [-, -, -]
  delay(26);
  servo[0].write(49); // Thumb
  servo[1].write(46); // Index
  servo[2].write(39); // Middle
  servo[3].write(31); // Ring
  servo[4].write(23); // Pinky

  // Keyframe 128 @ 8.75s: Fingers [41, 45, 45, 41, 35] Arm [-, -, -]
  smoothMove(0, 41, 15); // Thumb
  smoothMove(1, 45, 15); // Index
  smoothMove(2, 45, 15); // Middle
  smoothMove(3, 41, 15); // Ring
  smoothMove(4, 35, 15); // Pinky

  // Keyframe 129 @ 8.78s: Fingers [41, 46, 48, 47, 41] Arm [-, -, -]
  delay(36);
  servo[0].write(41); // Thumb
  servo[1].write(46); // Index
  servo[2].write(48); // Middle
  servo[3].write(47); // Ring
  servo[4].write(41); // Pinky

  // Keyframe 130 @ 8.81s: Fingers [39, 46, 51, 52, 49] Arm [-, -, -]
  delay(27);
  servo[0].write(39); // Thumb
  servo[1].write(46); // Index
  servo[2].write(51); // Middle
  servo[3].write(52); // Ring
  servo[4].write(49); // Pinky

  // Keyframe 131 @ 8.85s: Fingers [36, 44, 51, 54, 54] Arm [-, -, -]
  delay(40);
  servo[0].write(36); // Thumb
  servo[1].write(44); // Index
  servo[2].write(51); // Middle
  servo[3].write(54); // Ring
  servo[4].write(54); // Pinky

  // Keyframe 132 @ 8.91s: Fingers [32, 40, 49, 55, 59] Arm [-, -, -]
  smoothMove(0, 32, 2); // Thumb
  smoothMove(1, 40, 2); // Index
  smoothMove(2, 49, 2); // Middle
  smoothMove(3, 55, 2); // Ring
  smoothMove(4, 59, 2); // Pinky

  // Keyframe 133 @ 9.01s: Fingers [38, 40, 46, 54, 62] Arm [-, -, -]
  smoothMove(0, 38, 5); // Thumb
  smoothMove(1, 40, 5); // Index
  smoothMove(2, 46, 5); // Middle
  smoothMove(3, 54, 5); // Ring
  smoothMove(4, 62, 5); // Pinky

  // Keyframe 134 @ 9.07s: Fingers [44, 45, 49, 57, 65] Arm [-, -, -]
  smoothMove(0, 44, 3); // Thumb
  smoothMove(1, 45, 3); // Index
  smoothMove(2, 49, 3); // Middle
  smoothMove(3, 57, 3); // Ring
  smoothMove(4, 65, 3); // Pinky

  // Keyframe 135 @ 9.12s: Fingers [49, 49, 52, 59, 67] Arm [-, -, -]
  delay(47);
  servo[0].write(49); // Thumb
  servo[1].write(49); // Index
  servo[2].write(52); // Middle
  servo[3].write(59); // Ring
  servo[4].write(67); // Pinky

  // Keyframe 136 @ 9.16s: Fingers [55, 54, 57, 63, 71] Arm [-, -, -]
  delay(36);
  servo[0].write(55); // Thumb
  servo[1].write(54); // Index
  servo[2].write(57); // Middle
  servo[3].write(63); // Ring
  servo[4].write(71); // Pinky

  // Keyframe 137 @ 9.18s: Fingers [60, 60, 63, 70, 78] Arm [-, -, -]
  delay(26);
  servo[0].write(60); // Thumb
  servo[1].write(60); // Index
  servo[2].write(63); // Middle
  servo[3].write(70); // Ring
  servo[4].write(78); // Pinky

  // Keyframe 138 @ 9.20s: Fingers [64, 65, 70, 77, 85] Arm [-, -, -]
  delay(17);
  servo[0].write(64); // Thumb
  servo[1].write(65); // Index
  servo[2].write(70); // Middle
  servo[3].write(77); // Ring
  servo[4].write(85); // Pinky

  // Keyframe 139 @ 9.22s: Fingers [68, 70, 75, 82, 91] Arm [-, -, -]
  delay(17);
  servo[0].write(68); // Thumb
  servo[1].write(70); // Index
  servo[2].write(75); // Middle
  servo[3].write(82); // Ring
  servo[4].write(91); // Pinky

  // Keyframe 140 @ 9.25s: Fingers [73, 75, 81, 89, 97] Arm [-, -, -]
  delay(26);
  servo[0].write(73); // Thumb
  servo[1].write(75); // Index
  servo[2].write(81); // Middle
  servo[3].write(89); // Ring
  servo[4].write(97); // Pinky

  // Keyframe 141 @ 9.26s: Fingers [77, 80, 87, 95, 103] Arm [-, -, -]
  delay(11);
  servo[0].write(77); // Thumb
  servo[1].write(80); // Index
  servo[2].write(87); // Middle
  servo[3].write(95); // Ring
  servo[4].write(103); // Pinky

  // Keyframe 142 @ 9.28s: Fingers [81, 85, 92, 101, 109] Arm [-, -, -]
  delay(24);
  servo[0].write(81); // Thumb
  servo[1].write(85); // Index
  servo[2].write(92); // Middle
  servo[3].write(101); // Ring
  servo[4].write(109); // Pinky

  // Keyframe 143 @ 9.32s: Fingers [86, 91, 99, 107, 114] Arm [-, -, -]
  delay(34);
  servo[0].write(86); // Thumb
  servo[1].write(91); // Index
  servo[2].write(99); // Middle
  servo[3].write(107); // Ring
  servo[4].write(114); // Pinky

  // Keyframe 144 @ 9.35s: Fingers [90, 96, 104, 112, 119] Arm [-, -, -]
  delay(38);
  servo[0].write(90); // Thumb
  servo[1].write(96); // Index
  servo[2].write(104); // Middle
  servo[3].write(112); // Ring
  servo[4].write(119); // Pinky

  // Keyframe 145 @ 9.41s: Fingers [96, 103, 111, 119, 125] Arm [-, -, -]
  smoothMove(0, 96, 2); // Thumb
  smoothMove(1, 103, 2); // Index
  smoothMove(2, 111, 2); // Middle
  smoothMove(3, 119, 2); // Ring
  smoothMove(4, 125, 2); // Pinky

  // Keyframe 146 @ 9.44s: Fingers [103, 111, 119, 126, 131] Arm [-, -, -]
  delay(36);
  servo[0].write(103); // Thumb
  servo[1].write(111); // Index
  servo[2].write(119); // Middle
  servo[3].write(126); // Ring
  servo[4].write(131); // Pinky

  // Keyframe 147 @ 9.47s: Fingers [109, 117, 125, 131, 134] Arm [-, -, -]
  delay(24);
  servo[0].write(109); // Thumb
  servo[1].write(117); // Index
  servo[2].write(125); // Middle
  servo[3].write(131); // Ring
  servo[4].write(134); // Pinky

  // Keyframe 148 @ 9.48s: Fingers [116, 124, 132, 137, 138] Arm [-, -, -]
  delay(15);
  servo[0].write(116); // Thumb
  servo[1].write(124); // Index
  servo[2].write(132); // Middle
  servo[3].write(137); // Ring
  servo[4].write(138); // Pinky

  // Keyframe 149 @ 9.50s: Fingers [121, 130, 136, 140, 140] Arm [-, -, -]
  delay(14);
  servo[0].write(121); // Thumb
  servo[1].write(130); // Index
  servo[2].write(136); // Middle
  servo[3].write(140); // Ring
  servo[4].write(140); // Pinky

  // Keyframe 150 @ 9.51s: Fingers [126, 134, 140, 142, 141] Arm [-, -, -]
  delay(16);
  servo[0].write(126); // Thumb
  servo[1].write(134); // Index
  servo[2].write(140); // Middle
  servo[3].write(142); // Ring
  servo[4].write(141); // Pinky

  // Keyframe 151 @ 9.54s: Fingers [133, 140, 145, 146, 143] Arm [-, -, -]
  delay(31);
  servo[0].write(133); // Thumb
  servo[1].write(140); // Index
  servo[2].write(145); // Middle
  servo[3].write(146); // Ring
  servo[4].write(143); // Pinky

  // Keyframe 152 @ 9.57s: Fingers [138, 145, 148, 148, 144] Arm [-, -, -]
  delay(24);
  servo[0].write(138); // Thumb
  servo[1].write(145); // Index
  servo[2].write(148); // Middle
  servo[3].write(148); // Ring
  servo[4].write(144); // Pinky

  // Keyframe 153 @ 9.59s: Fingers [145, 150, 151, 149, 143] Arm [-, -, -]
  delay(20);
  servo[0].write(145); // Thumb
  servo[1].write(150); // Index
  servo[2].write(151); // Middle
  servo[3].write(149); // Ring
  servo[4].write(143); // Pinky

  // Keyframe 154 @ 9.62s: Fingers [152, 155, 155, 150, 143] Arm [-, -, -]
  delay(29);
  servo[0].write(152); // Thumb
  servo[1].write(155); // Index
  servo[2].write(155); // Middle
  servo[3].write(150); // Ring
  servo[4].write(143); // Pinky

  // Keyframe 155 @ 9.66s: Fingers [158, 159, 156, 150, 142] Arm [-, -, -]
  delay(38);
  servo[0].write(158); // Thumb
  servo[1].write(159); // Index
  servo[2].write(156); // Middle
  servo[3].write(150); // Ring
  servo[4].write(142); // Pinky

  // Keyframe 156 @ 9.71s: Fingers [163, 161, 155, 147, 139] Arm [-, -, -]
  smoothMove(0, 163, 2); // Thumb
  smoothMove(1, 161, 2); // Index
  smoothMove(2, 155, 2); // Middle
  smoothMove(3, 147, 2); // Ring
  smoothMove(4, 139, 2); // Pinky

  // Keyframe 157 @ 9.75s: Fingers [163, 157, 149, 141, 134] Arm [-, -, -]
  delay(35);
  servo[0].write(163); // Thumb
  servo[1].write(157); // Index
  servo[2].write(149); // Middle
  servo[3].write(141); // Ring
  servo[4].write(134); // Pinky

  // Keyframe 158 @ 9.78s: Fingers [159, 151, 143, 136, 132] Arm [-, -, -]
  delay(27);
  servo[0].write(159); // Thumb
  servo[1].write(151); // Index
  servo[2].write(143); // Middle
  servo[3].write(136); // Ring
  servo[4].write(132); // Pinky

  // Keyframe 159 @ 9.81s: Fingers [153, 145, 138, 133, 133] Arm [-, -, -]
  delay(35);
  servo[0].write(153); // Thumb
  servo[1].write(145); // Index
  servo[2].write(138); // Middle
  servo[3].write(133); // Ring
  servo[4].write(133); // Pinky

  // Keyframe 160 @ 9.87s: Fingers [146, 139, 133, 131, 133] Arm [-, -, -]
  smoothMove(0, 146, 2); // Thumb
  smoothMove(1, 139, 2); // Index
  smoothMove(2, 133, 2); // Middle
  smoothMove(3, 131, 2); // Ring
  smoothMove(4, 133, 2); // Pinky

  // Keyframe 161 @ 9.88s: Fingers [140, 133, 130, 131, 136] Arm [-, -, -]
  delay(10);
  servo[0].write(140); // Thumb
  servo[1].write(133); // Index
  servo[2].write(130); // Middle
  servo[3].write(131); // Ring
  servo[4].write(136); // Pinky

  // Keyframe 162 @ 9.91s: Fingers [129, 127, 129, 134, 141] Arm [-, -, -]
  delay(27);
  servo[0].write(129); // Thumb
  servo[1].write(127); // Index
  servo[2].write(129); // Middle
  servo[3].write(134); // Ring
  servo[4].write(141); // Pinky

  // Keyframe 163 @ 9.94s: Fingers [124, 127, 132, 140, 149] Arm [-, -, -]
  delay(27);
  servo[0].write(124); // Thumb
  servo[1].write(127); // Index
  servo[2].write(132); // Middle
  servo[3].write(140); // Ring
  servo[4].write(149); // Pinky

  // Keyframe 164 @ 9.94s: Fingers [124, 129, 137, 145, 153] Arm [-, -, -]
  delay(1);
  servo[0].write(124); // Thumb
  servo[1].write(129); // Index
  servo[2].write(137); // Middle
  servo[3].write(145); // Ring
  servo[4].write(153); // Pinky

  // Keyframe 165 @ 9.97s: Fingers [127, 135, 143, 150, 154] Arm [-, -, -]
  delay(29);
  servo[0].write(127); // Thumb
  servo[1].write(135); // Index
  servo[2].write(143); // Middle
  servo[3].write(150); // Ring
  servo[4].write(154); // Pinky

  // Keyframe 166 @ 10.03s: Fingers [130, 138, 145, 148, 148] Arm [-, -, -]
  smoothMove(0, 130, 3); // Thumb
  smoothMove(1, 138, 3); // Index
  smoothMove(2, 145, 3); // Middle
  smoothMove(3, 148, 3); // Ring
  smoothMove(4, 148, 3); // Pinky

  // Keyframe 167 @ 10.05s: Fingers [131, 138, 143, 145, 142] Arm [-, -, -]
  delay(21);
  servo[0].write(131); // Thumb
  servo[1].write(138); // Index
  servo[2].write(143); // Middle
  servo[3].write(145); // Ring
  servo[4].write(142); // Pinky

  // Keyframe 168 @ 10.09s: Fingers [127, 134, 139, 139, 136] Arm [-, -, -]
  delay(36);
  servo[0].write(127); // Thumb
  servo[1].write(134); // Index
  servo[2].write(139); // Middle
  servo[3].write(139); // Ring
  servo[4].write(136); // Pinky

  // Keyframe 169 @ 10.13s: Fingers [122, 129, 134, 134, 131] Arm [-, -, -]
  delay(40);
  servo[0].write(122); // Thumb
  servo[1].write(129); // Index
  servo[2].write(134); // Middle
  servo[3].write(134); // Ring
  servo[4].write(131); // Pinky

  // Keyframe 170 @ 10.16s: Fingers [116, 124, 129, 131, 128] Arm [-, -, -]
  delay(30);
  servo[0].write(116); // Thumb
  servo[1].write(124); // Index
  servo[2].write(129); // Middle
  servo[3].write(131); // Ring
  servo[4].write(128); // Pinky

  // Keyframe 171 @ 10.19s: Fingers [111, 119, 125, 128, 127] Arm [-, -, -]
  delay(23);
  servo[0].write(111); // Thumb
  servo[1].write(119); // Index
  servo[2].write(125); // Middle
  servo[3].write(128); // Ring
  servo[4].write(127); // Pinky

  // Keyframe 172 @ 10.22s: Fingers [103, 111, 118, 123, 123] Arm [-, -, -]
  delay(33);
  servo[0].write(103); // Thumb
  servo[1].write(111); // Index
  servo[2].write(118); // Middle
  servo[3].write(123); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 173 @ 10.24s: Fingers [98, 106, 114, 119, 121] Arm [-, -, -]
  delay(20);
  servo[0].write(98); // Thumb
  servo[1].write(106); // Index
  servo[2].write(114); // Middle
  servo[3].write(119); // Ring
  servo[4].write(121); // Pinky

  // Keyframe 174 @ 10.25s: Fingers [90, 98, 107, 114, 118] Arm [-, -, -]
  delay(13);
  servo[0].write(90); // Thumb
  servo[1].write(98); // Index
  servo[2].write(107); // Middle
  servo[3].write(114); // Ring
  servo[4].write(118); // Pinky

  // Keyframe 175 @ 10.28s: Fingers [81, 87, 95, 104, 110] Arm [-, -, -]
  delay(23);
  servo[0].write(81); // Thumb
  servo[1].write(87); // Index
  servo[2].write(95); // Middle
  servo[3].write(104); // Ring
  servo[4].write(110); // Pinky

  // Keyframe 176 @ 10.30s: Fingers [78, 83, 90, 99, 106] Arm [-, -, -]
  delay(23);
  servo[0].write(78); // Thumb
  servo[1].write(83); // Index
  servo[2].write(90); // Middle
  servo[3].write(99); // Ring
  servo[4].write(106); // Pinky

  // Keyframe 177 @ 10.33s: Fingers [74, 77, 83, 90, 99] Arm [-, -, -]
  delay(34);
  servo[0].write(74); // Thumb
  servo[1].write(77); // Index
  servo[2].write(83); // Middle
  servo[3].write(90); // Ring
  servo[4].write(99); // Pinky

  // Keyframe 178 @ 10.35s: Fingers [74, 73, 76, 82, 90] Arm [-, -, -]
  delay(12);
  servo[0].write(74); // Thumb
  servo[1].write(73); // Index
  servo[2].write(76); // Middle
  servo[3].write(82); // Ring
  servo[4].write(90); // Pinky

  // Keyframe 179 @ 10.37s: Fingers [75, 72, 73, 78, 85] Arm [-, -, -]
  delay(24);
  servo[0].write(75); // Thumb
  servo[1].write(72); // Index
  servo[2].write(73); // Middle
  servo[3].write(78); // Ring
  servo[4].write(85); // Pinky

  // Keyframe 180 @ 10.43s: Fingers [78, 72, 71, 73, 79] Arm [-, -, -]
  smoothMove(0, 78, 2); // Thumb
  smoothMove(1, 72, 2); // Index
  smoothMove(2, 71, 2); // Middle
  smoothMove(3, 73, 2); // Ring
  smoothMove(4, 79, 2); // Pinky

  // Keyframe 181 @ 10.43s: Fingers [82, 75, 70, 70, 73] Arm [-, -, -]
  delay(7);
  servo[0].write(82); // Thumb
  servo[1].write(75); // Index
  servo[2].write(70); // Middle
  servo[3].write(70); // Ring
  servo[4].write(73); // Pinky

  // Keyframe 182 @ 10.46s: Fingers [87, 79, 72, 69, 70] Arm [-, -, -]
  delay(25);
  servo[0].write(87); // Thumb
  servo[1].write(79); // Index
  servo[2].write(72); // Middle
  servo[3].write(69); // Ring
  servo[4].write(70); // Pinky

  // Keyframe 183 @ 10.49s: Fingers [93, 85, 77, 71, 68] Arm [-, -, -]
  delay(31);
  servo[0].write(93); // Thumb
  servo[1].write(85); // Index
  servo[2].write(77); // Middle
  servo[3].write(71); // Ring
  servo[4].write(68); // Pinky

  // Keyframe 184 @ 10.53s: Fingers [97, 90, 82, 74, 69] Arm [-, -, -]
  delay(38);
  servo[0].write(97); // Thumb
  servo[1].write(90); // Index
  servo[2].write(82); // Middle
  servo[3].write(74); // Ring
  servo[4].write(69); // Pinky

  // Keyframe 185 @ 10.56s: Fingers [102, 98, 90, 82, 74] Arm [-, -, -]
  delay(31);
  servo[0].write(102); // Thumb
  servo[1].write(98); // Index
  servo[2].write(90); // Middle
  servo[3].write(82); // Ring
  servo[4].write(74); // Pinky

  // Keyframe 186 @ 10.58s: Fingers [103, 102, 98, 91, 82] Arm [-, -, -]
  delay(23);
  servo[0].write(103); // Thumb
  servo[1].write(102); // Index
  servo[2].write(98); // Middle
  servo[3].write(91); // Ring
  servo[4].write(82); // Pinky

  // Keyframe 187 @ 10.60s: Fingers [101, 104, 103, 98, 90] Arm [-, -, -]
  delay(16);
  servo[0].write(101); // Thumb
  servo[1].write(104); // Index
  servo[2].write(103); // Middle
  servo[3].write(98); // Ring
  servo[4].write(90); // Pinky

  // Keyframe 188 @ 10.62s: Fingers [95, 102, 104, 103, 99] Arm [-, -, -]
  delay(16);
  servo[0].write(95); // Thumb
  servo[1].write(102); // Index
  servo[2].write(104); // Middle
  servo[3].write(103); // Ring
  servo[4].write(99); // Pinky

  // Keyframe 189 @ 10.63s: Fingers [88, 96, 102, 104, 103] Arm [-, -, -]
  delay(9);
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(102); // Middle
  servo[3].write(104); // Ring
  servo[4].write(103); // Pinky

  // Keyframe 190 @ 10.64s: Fingers [78, 86, 94, 101, 105] Arm [-, -, -]
  delay(17);
  servo[0].write(78); // Thumb
  servo[1].write(86); // Index
  servo[2].write(94); // Middle
  servo[3].write(101); // Ring
  servo[4].write(105); // Pinky

  // Keyframe 191 @ 10.64s: Fingers [72, 77, 85, 94, 101] Arm [-, -, -]
  delay(1);
  servo[0].write(72); // Thumb
  servo[1].write(77); // Index
  servo[2].write(85); // Middle
  servo[3].write(94); // Ring
  servo[4].write(101); // Pinky

  // Keyframe 192 @ 10.65s: Fingers [71, 70, 73, 79, 87] Arm [-, -, -]
  delay(4);
  servo[0].write(71); // Thumb
  servo[1].write(70); // Index
  servo[2].write(73); // Middle
  servo[3].write(79); // Ring
  servo[4].write(87); // Pinky

  // Keyframe 193 @ 10.66s: Fingers [78, 72, 70, 71, 76] Arm [-, -, -]
  delay(8);
  servo[0].write(78); // Thumb
  servo[1].write(72); // Index
  servo[2].write(70); // Middle
  servo[3].write(71); // Ring
  servo[4].write(76); // Pinky

  // Keyframe 194 @ 10.68s: Fingers [89, 81, 74, 70, 70] Arm [-, -, -]
  delay(17);
  servo[0].write(89); // Thumb
  servo[1].write(81); // Index
  servo[2].write(74); // Middle
  servo[3].write(70); // Ring
  servo[4].write(70); // Pinky

  // Keyframe 195 @ 10.68s: Fingers [103, 97, 89, 81, 74] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(97); // Index
  servo[2].write(89); // Middle
  servo[3].write(81); // Ring
  servo[4].write(74); // Pinky

  // Keyframe 196 @ 10.68s: Fingers [107, 105, 100, 92, 84] Arm [-, -, -]
  delay(5);
  servo[0].write(107); // Thumb
  servo[1].write(105); // Index
  servo[2].write(100); // Middle
  servo[3].write(92); // Ring
  servo[4].write(84); // Pinky

  // Keyframe 197 @ 10.69s: Fingers [100, 106, 108, 107, 102] Arm [-, -, -]
  delay(7);
  servo[0].write(100); // Thumb
  servo[1].write(106); // Index
  servo[2].write(108); // Middle
  servo[3].write(107); // Ring
  servo[4].write(102); // Pinky

  // Keyframe 198 @ 10.70s: Fingers [92, 100, 106, 109, 109] Arm [-, -, -]
  delay(13);
  servo[0].write(92); // Thumb
  servo[1].write(100); // Index
  servo[2].write(106); // Middle
  servo[3].write(109); // Ring
  servo[4].write(109); // Pinky

  // Keyframe 199 @ 10.71s: Fingers [80, 87, 95, 103, 110] Arm [-, -, -]
  delay(3);
  servo[0].write(80); // Thumb
  servo[1].write(87); // Index
  servo[2].write(95); // Middle
  servo[3].write(103); // Ring
  servo[4].write(110); // Pinky

  // Keyframe 200 @ 10.71s: Fingers [78, 80, 85, 92, 101] Arm [-, -, -]
  delay(8);
  servo[0].write(78); // Thumb
  servo[1].write(80); // Index
  servo[2].write(85); // Middle
  servo[3].write(92); // Ring
  servo[4].write(101); // Pinky

  // Keyframe 201 @ 11.01s: Fingers [78, 80, 85, 92, 101] Arm [-, -, -]
  smoothMove(0, 78, 14); // Thumb
  smoothMove(1, 80, 14); // Index
  smoothMove(2, 85, 14); // Middle
  smoothMove(3, 92, 14); // Ring
  smoothMove(4, 101, 14); // Pinky

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
