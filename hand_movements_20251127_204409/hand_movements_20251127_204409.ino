/*
 * 8-Servo Hand Control - Generated Movement Code
 * Generated: 2025-11-27 20:44:09
 * Layers: 4
 * Total Movements: 2192
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
// Duration: 9.2s, Keyframes: 43 (reduced from 509 frames)
void playLayer1() {
  // Keyframe 1 @ 0.03s: Fingers [-, -, -, -, -] Arm [82, -, -]
  delay(25);
  servo[5].write(82); // Shoulder

  // Keyframe 2 @ 0.38s: Fingers [-, -, -, -, -] Arm [84, -, -]
  smoothMove(5, 84, 17); // Shoulder

  // Keyframe 3 @ 0.47s: Fingers [-, -, -, -, -] Arm [86, -, -]
  smoothMove(5, 86, 4); // Shoulder

  // Keyframe 4 @ 0.51s: Fingers [-, -, -, -, -] Arm [88, -, -]
  delay(41);
  servo[5].write(88); // Shoulder

  // Keyframe 5 @ 0.63s: Fingers [-, -, -, -, -] Arm [90, -, -]
  smoothMove(5, 90, 5); // Shoulder

  // Keyframe 6 @ 0.72s: Fingers [-, -, -, -, -] Arm [92, -, -]
  smoothMove(5, 92, 4); // Shoulder

  // Keyframe 7 @ 0.80s: Fingers [-, -, -, -, -] Arm [94, -, -]
  smoothMove(5, 94, 4); // Shoulder

  // Keyframe 8 @ 0.88s: Fingers [-, -, -, -, -] Arm [96, -, -]
  smoothMove(5, 96, 3); // Shoulder

  // Keyframe 9 @ 1.61s: Fingers [-, -, -, -, -] Arm [94, -, -]
  smoothMove(5, 94, 20); // Shoulder

  // Keyframe 10 @ 1.74s: Fingers [-, -, -, -, -] Arm [92, -, -]
  smoothMove(5, 92, 6); // Shoulder

  // Keyframe 11 @ 1.89s: Fingers [-, -, -, -, -] Arm [90, -, -]
  smoothMove(5, 90, 7); // Shoulder

  // Keyframe 12 @ 1.98s: Fingers [-, -, -, -, -] Arm [88, -, -]
  smoothMove(5, 88, 4); // Shoulder

  // Keyframe 13 @ 2.12s: Fingers [-, -, -, -, -] Arm [86, -, -]
  smoothMove(5, 86, 6); // Shoulder

  // Keyframe 14 @ 2.21s: Fingers [-, -, -, -, -] Arm [84, -, -]
  smoothMove(5, 84, 4); // Shoulder

  // Keyframe 15 @ 2.33s: Fingers [-, -, -, -, -] Arm [82, -, -]
  smoothMove(5, 82, 6); // Shoulder

  // Keyframe 16 @ 2.51s: Fingers [-, -, -, -, -] Arm [80, -, -]
  smoothMove(5, 80, 8); // Shoulder

  // Keyframe 17 @ 2.69s: Fingers [-, -, -, -, -] Arm [78, -, -]
  smoothMove(5, 78, 9); // Shoulder

  // Keyframe 18 @ 3.61s: Fingers [-, -, -, -, -] Arm [80, -, -]
  smoothMove(5, 80, 20); // Shoulder

  // Keyframe 19 @ 3.73s: Fingers [-, -, -, -, -] Arm [82, -, -]
  smoothMove(5, 82, 6); // Shoulder

  // Keyframe 20 @ 3.84s: Fingers [-, -, -, -, -] Arm [84, -, -]
  smoothMove(5, 84, 5); // Shoulder

  // Keyframe 21 @ 3.95s: Fingers [-, -, -, -, -] Arm [86, -, -]
  smoothMove(5, 86, 5); // Shoulder

  // Keyframe 22 @ 4.03s: Fingers [-, -, -, -, -] Arm [88, -, -]
  smoothMove(5, 88, 3); // Shoulder

  // Keyframe 23 @ 4.09s: Fingers [-, -, -, -, -] Arm [90, -, -]
  smoothMove(5, 90, 3); // Shoulder

  // Keyframe 24 @ 4.15s: Fingers [-, -, -, -, -] Arm [92, -, -]
  smoothMove(5, 92, 2); // Shoulder

  // Keyframe 25 @ 4.22s: Fingers [-, -, -, -, -] Arm [94, -, -]
  smoothMove(5, 94, 3); // Shoulder

  // Keyframe 26 @ 4.28s: Fingers [-, -, -, -, -] Arm [96, -, -]
  smoothMove(5, 96, 2); // Shoulder

  // Keyframe 27 @ 4.39s: Fingers [-, -, -, -, -] Arm [98, -, -]
  smoothMove(5, 98, 5); // Shoulder

  // Keyframe 28 @ 4.50s: Fingers [-, -, -, -, -] Arm [100, -, -]
  smoothMove(5, 100, 5); // Shoulder

  // Keyframe 29 @ 4.64s: Fingers [-, -, -, -, -] Arm [102, -, -]
  smoothMove(5, 102, 6); // Shoulder

  // Keyframe 30 @ 5.09s: Fingers [-, -, -, -, -] Arm [104, -, -]
  smoothMove(5, 104, 20); // Shoulder

  // Keyframe 31 @ 6.24s: Fingers [-, -, -, -, -] Arm [102, -, -]
  smoothMove(5, 102, 20); // Shoulder

  // Keyframe 32 @ 6.49s: Fingers [-, -, -, -, -] Arm [100, -, -]
  smoothMove(5, 100, 12); // Shoulder

  // Keyframe 33 @ 6.63s: Fingers [-, -, -, -, -] Arm [98, -, -]
  smoothMove(5, 98, 7); // Shoulder

  // Keyframe 34 @ 6.73s: Fingers [-, -, -, -, -] Arm [96, -, -]
  smoothMove(5, 96, 5); // Shoulder

  // Keyframe 35 @ 6.87s: Fingers [-, -, -, -, -] Arm [94, -, -]
  smoothMove(5, 94, 6); // Shoulder

  // Keyframe 36 @ 7.04s: Fingers [-, -, -, -, -] Arm [92, -, -]
  smoothMove(5, 92, 8); // Shoulder

  // Keyframe 37 @ 7.19s: Fingers [-, -, -, -, -] Arm [90, -, -]
  smoothMove(5, 90, 7); // Shoulder

  // Keyframe 38 @ 7.32s: Fingers [-, -, -, -, -] Arm [88, -, -]
  smoothMove(5, 88, 6); // Shoulder

  // Keyframe 39 @ 7.56s: Fingers [-, -, -, -, -] Arm [86, -, -]
  smoothMove(5, 86, 11); // Shoulder

  // Keyframe 40 @ 7.75s: Fingers [-, -, -, -, -] Arm [84, -, -]
  smoothMove(5, 84, 9); // Shoulder

  // Keyframe 41 @ 8.02s: Fingers [-, -, -, -, -] Arm [82, -, -]
  smoothMove(5, 82, 13); // Shoulder

  // Keyframe 42 @ 8.58s: Fingers [-, -, -, -, -] Arm [80, -, -]
  smoothMove(5, 80, 20); // Shoulder

  // Keyframe 43 @ 9.18s: Fingers [-, -, -, -, -] Arm [79, -, -]
  smoothMove(5, 79, 20); // Shoulder

}

// Layer 2: Layer_2 - manual mode
// Duration: 5.7s, Keyframes: 38 (reduced from 392 frames)
void playLayer2() {
  // Keyframe 1 @ 0.00s: Fingers [-, -, -, -, -] Arm [-, 47, -]
  delay(1);
  servo[6].write(47); // Elbow

  // Keyframe 2 @ 0.25s: Fingers [-, -, -, -, -] Arm [-, 49, -]
  smoothMove(6, 49, 12); // Elbow

  // Keyframe 3 @ 0.39s: Fingers [-, -, -, -, -] Arm [-, 51, -]
  smoothMove(6, 51, 6); // Elbow

  // Keyframe 4 @ 0.45s: Fingers [-, -, -, -, -] Arm [-, 54, -]
  smoothMove(6, 54, 2); // Elbow

  // Keyframe 5 @ 0.51s: Fingers [-, -, -, -, -] Arm [-, 56, -]
  smoothMove(6, 56, 3); // Elbow

  // Keyframe 6 @ 0.61s: Fingers [-, -, -, -, -] Arm [-, 58, -]
  smoothMove(6, 58, 4); // Elbow

  // Keyframe 7 @ 0.69s: Fingers [-, -, -, -, -] Arm [-, 60, -]
  smoothMove(6, 60, 3); // Elbow

  // Keyframe 8 @ 0.99s: Fingers [-, -, -, -, -] Arm [-, 58, -]
  smoothMove(6, 58, 15); // Elbow

  // Keyframe 9 @ 1.08s: Fingers [-, -, -, -, -] Arm [-, 56, -]
  smoothMove(6, 56, 4); // Elbow

  // Keyframe 10 @ 1.15s: Fingers [-, -, -, -, -] Arm [-, 54, -]
  smoothMove(6, 54, 3); // Elbow

  // Keyframe 11 @ 1.23s: Fingers [-, -, -, -, -] Arm [-, 51, -]
  smoothMove(6, 51, 4); // Elbow

  // Keyframe 12 @ 1.30s: Fingers [-, -, -, -, -] Arm [-, 49, -]
  smoothMove(6, 49, 3); // Elbow

  // Keyframe 13 @ 1.38s: Fingers [-, -, -, -, -] Arm [-, 47, -]
  smoothMove(6, 47, 3); // Elbow

  // Keyframe 14 @ 1.48s: Fingers [-, -, -, -, -] Arm [-, 45, -]
  smoothMove(6, 45, 5); // Elbow

  // Keyframe 15 @ 1.61s: Fingers [-, -, -, -, -] Arm [-, 43, -]
  smoothMove(6, 43, 6); // Elbow

  // Keyframe 16 @ 2.12s: Fingers [-, -, -, -, -] Arm [-, 45, -]
  smoothMove(6, 45, 20); // Elbow

  // Keyframe 17 @ 2.30s: Fingers [-, -, -, -, -] Arm [-, 47, -]
  smoothMove(6, 47, 8); // Elbow

  // Keyframe 18 @ 2.44s: Fingers [-, -, -, -, -] Arm [-, 49, -]
  smoothMove(6, 49, 6); // Elbow

  // Keyframe 19 @ 2.58s: Fingers [-, -, -, -, -] Arm [-, 51, -]
  smoothMove(6, 51, 7); // Elbow

  // Keyframe 20 @ 3.03s: Fingers [-, -, -, -, -] Arm [-, 49, -]
  smoothMove(6, 49, 20); // Elbow

  // Keyframe 21 @ 3.19s: Fingers [-, -, -, -, -] Arm [-, 47, -]
  smoothMove(6, 47, 7); // Elbow

  // Keyframe 22 @ 3.33s: Fingers [-, -, -, -, -] Arm [-, 45, -]
  smoothMove(6, 45, 6); // Elbow

  // Keyframe 23 @ 3.42s: Fingers [-, -, -, -, -] Arm [-, 43, -]
  smoothMove(6, 43, 4); // Elbow

  // Keyframe 24 @ 3.66s: Fingers [-, -, -, -, -] Arm [-, 41, -]
  smoothMove(6, 41, 11); // Elbow

  // Keyframe 25 @ 3.78s: Fingers [-, -, -, -, -] Arm [-, 39, -]
  smoothMove(6, 39, 6); // Elbow

  // Keyframe 26 @ 4.12s: Fingers [-, -, -, -, -] Arm [-, 41, -]
  smoothMove(6, 41, 16); // Elbow

  // Keyframe 27 @ 4.26s: Fingers [-, -, -, -, -] Arm [-, 43, -]
  smoothMove(6, 43, 6); // Elbow

  // Keyframe 28 @ 4.35s: Fingers [-, -, -, -, -] Arm [-, 45, -]
  smoothMove(6, 45, 4); // Elbow

  // Keyframe 29 @ 4.46s: Fingers [-, -, -, -, -] Arm [-, 47, -]
  smoothMove(6, 47, 5); // Elbow

  // Keyframe 30 @ 4.53s: Fingers [-, -, -, -, -] Arm [-, 49, -]
  smoothMove(6, 49, 3); // Elbow

  // Keyframe 31 @ 4.82s: Fingers [-, -, -, -, -] Arm [-, 51, -]
  smoothMove(6, 51, 14); // Elbow

  // Keyframe 32 @ 5.04s: Fingers [-, -, -, -, -] Arm [-, 49, -]
  smoothMove(6, 49, 11); // Elbow

  // Keyframe 33 @ 5.15s: Fingers [-, -, -, -, -] Arm [-, 47, -]
  smoothMove(6, 47, 5); // Elbow

  // Keyframe 34 @ 5.30s: Fingers [-, -, -, -, -] Arm [-, 45, -]
  smoothMove(6, 45, 7); // Elbow

  // Keyframe 35 @ 5.43s: Fingers [-, -, -, -, -] Arm [-, 43, -]
  smoothMove(6, 43, 6); // Elbow

  // Keyframe 36 @ 5.54s: Fingers [-, -, -, -, -] Arm [-, 41, -]
  smoothMove(6, 41, 5); // Elbow

  // Keyframe 37 @ 5.66s: Fingers [-, -, -, -, -] Arm [-, 39, -]
  smoothMove(6, 39, 6); // Elbow

  // Keyframe 38 @ 5.73s: Fingers [-, -, -, -, -] Arm [-, 38, -]
  smoothMove(6, 38, 3); // Elbow

}

// Layer 3: Layer_3 - manual mode
// Duration: 5.7s, Keyframes: 96 (reduced from 579 frames)
void playLayer3() {
  // Keyframe 1 @ 0.01s: Fingers [-, -, -, -, -] Arm [-, -, 135]
  delay(13);
  servo[7].write(135); // Wrist

  // Keyframe 2 @ 0.24s: Fingers [-, -, -, -, -] Arm [-, -, 133]
  smoothMove(7, 133, 11); // Wrist

  // Keyframe 3 @ 0.29s: Fingers [-, -, -, -, -] Arm [-, -, 131]
  smoothMove(7, 131, 2); // Wrist

  // Keyframe 4 @ 0.35s: Fingers [-, -, -, -, -] Arm [-, -, 129]
  smoothMove(7, 129, 2); // Wrist

  // Keyframe 5 @ 0.44s: Fingers [-, -, -, -, -] Arm [-, -, 126]
  smoothMove(7, 126, 4); // Wrist

  // Keyframe 6 @ 0.49s: Fingers [-, -, -, -, -] Arm [-, -, 124]
  delay(49);
  servo[7].write(124); // Wrist

  // Keyframe 7 @ 0.55s: Fingers [-, -, -, -, -] Arm [-, -, 122]
  smoothMove(7, 122, 3); // Wrist

  // Keyframe 8 @ 0.58s: Fingers [-, -, -, -, -] Arm [-, -, 120]
  delay(28);
  servo[7].write(120); // Wrist

  // Keyframe 9 @ 0.61s: Fingers [-, -, -, -, -] Arm [-, -, 117]
  delay(29);
  servo[7].write(117); // Wrist

  // Keyframe 10 @ 0.64s: Fingers [-, -, -, -, -] Arm [-, -, 115]
  delay(37);
  servo[7].write(115); // Wrist

  // Keyframe 11 @ 0.67s: Fingers [-, -, -, -, -] Arm [-, -, 112]
  delay(23);
  servo[7].write(112); // Wrist

  // Keyframe 12 @ 0.69s: Fingers [-, -, -, -, -] Arm [-, -, 110]
  delay(17);
  servo[7].write(110); // Wrist

  // Keyframe 13 @ 0.75s: Fingers [-, -, -, -, -] Arm [-, -, 108]
  smoothMove(7, 108, 3); // Wrist

  // Keyframe 14 @ 0.81s: Fingers [-, -, -, -, -] Arm [-, -, 106]
  smoothMove(7, 106, 2); // Wrist

  // Keyframe 15 @ 0.84s: Fingers [-, -, -, -, -] Arm [-, -, 104]
  delay(35);
  servo[7].write(104); // Wrist

  // Keyframe 16 @ 0.91s: Fingers [-, -, -, -, -] Arm [-, -, 102]
  smoothMove(7, 102, 3); // Wrist

  // Keyframe 17 @ 0.93s: Fingers [-, -, -, -, -] Arm [-, -, 99]
  delay(26);
  servo[7].write(99); // Wrist

  // Keyframe 18 @ 0.97s: Fingers [-, -, -, -, -] Arm [-, -, 97]
  delay(34);
  servo[7].write(97); // Wrist

  // Keyframe 19 @ 1.03s: Fingers [-, -, -, -, -] Arm [-, -, 95]
  smoothMove(7, 95, 3); // Wrist

  // Keyframe 20 @ 1.07s: Fingers [-, -, -, -, -] Arm [-, -, 93]
  delay(41);
  servo[7].write(93); // Wrist

  // Keyframe 21 @ 1.12s: Fingers [-, -, -, -, -] Arm [-, -, 91]
  smoothMove(7, 91, 2); // Wrist

  // Keyframe 22 @ 1.16s: Fingers [-, -, -, -, -] Arm [-, -, 89]
  delay(42);
  servo[7].write(89); // Wrist

  // Keyframe 23 @ 1.24s: Fingers [-, -, -, -, -] Arm [-, -, 87]
  smoothMove(7, 87, 3); // Wrist

  // Keyframe 24 @ 1.28s: Fingers [-, -, -, -, -] Arm [-, -, 85]
  delay(40);
  servo[7].write(85); // Wrist

  // Keyframe 25 @ 1.44s: Fingers [-, -, -, -, -] Arm [-, -, 83]
  smoothMove(7, 83, 7); // Wrist

  // Keyframe 26 @ 1.69s: Fingers [-, -, -, -, -] Arm [-, -, 85]
  smoothMove(7, 85, 12); // Wrist

  // Keyframe 27 @ 1.75s: Fingers [-, -, -, -, -] Arm [-, -, 87]
  smoothMove(7, 87, 2); // Wrist

  // Keyframe 28 @ 1.79s: Fingers [-, -, -, -, -] Arm [-, -, 89]
  delay(39);
  servo[7].write(89); // Wrist

  // Keyframe 29 @ 1.84s: Fingers [-, -, -, -, -] Arm [-, -, 91]
  smoothMove(7, 91, 2); // Wrist

  // Keyframe 30 @ 1.90s: Fingers [-, -, -, -, -] Arm [-, -, 93]
  smoothMove(7, 93, 2); // Wrist

  // Keyframe 31 @ 1.94s: Fingers [-, -, -, -, -] Arm [-, -, 95]
  delay(43);
  servo[7].write(95); // Wrist

  // Keyframe 32 @ 2.00s: Fingers [-, -, -, -, -] Arm [-, -, 97]
  smoothMove(7, 97, 2); // Wrist

  // Keyframe 33 @ 2.04s: Fingers [-, -, -, -, -] Arm [-, -, 99]
  delay(45);
  servo[7].write(99); // Wrist

  // Keyframe 34 @ 2.07s: Fingers [-, -, -, -, -] Arm [-, -, 101]
  delay(29);
  servo[7].write(101); // Wrist

  // Keyframe 35 @ 2.11s: Fingers [-, -, -, -, -] Arm [-, -, 103]
  delay(38);
  servo[7].write(103); // Wrist

  // Keyframe 36 @ 2.16s: Fingers [-, -, -, -, -] Arm [-, -, 105]
  delay(48);
  servo[7].write(105); // Wrist

  // Keyframe 37 @ 2.20s: Fingers [-, -, -, -, -] Arm [-, -, 108]
  delay(38);
  servo[7].write(108); // Wrist

  // Keyframe 38 @ 2.27s: Fingers [-, -, -, -, -] Arm [-, -, 110]
  smoothMove(7, 110, 3); // Wrist

  // Keyframe 39 @ 2.35s: Fingers [-, -, -, -, -] Arm [-, -, 112]
  smoothMove(7, 112, 3); // Wrist

  // Keyframe 40 @ 2.48s: Fingers [-, -, -, -, -] Arm [-, -, 110]
  smoothMove(7, 110, 6); // Wrist

  // Keyframe 41 @ 2.51s: Fingers [-, -, -, -, -] Arm [-, -, 108]
  delay(24);
  servo[7].write(108); // Wrist

  // Keyframe 42 @ 2.54s: Fingers [-, -, -, -, -] Arm [-, -, 105]
  delay(29);
  servo[7].write(105); // Wrist

  // Keyframe 43 @ 2.58s: Fingers [-, -, -, -, -] Arm [-, -, 103]
  delay(42);
  servo[7].write(103); // Wrist

  // Keyframe 44 @ 2.61s: Fingers [-, -, -, -, -] Arm [-, -, 101]
  delay(30);
  servo[7].write(101); // Wrist

  // Keyframe 45 @ 2.64s: Fingers [-, -, -, -, -] Arm [-, -, 99]
  delay(24);
  servo[7].write(99); // Wrist

  // Keyframe 46 @ 2.65s: Fingers [-, -, -, -, -] Arm [-, -, 97]
  delay(17);
  servo[7].write(97); // Wrist

  // Keyframe 47 @ 2.69s: Fingers [-, -, -, -, -] Arm [-, -, 95]
  delay(37);
  servo[7].write(95); // Wrist

  // Keyframe 48 @ 2.73s: Fingers [-, -, -, -, -] Arm [-, -, 93]
  delay(39);
  servo[7].write(93); // Wrist

  // Keyframe 49 @ 2.77s: Fingers [-, -, -, -, -] Arm [-, -, 91]
  delay(41);
  servo[7].write(91); // Wrist

  // Keyframe 50 @ 2.80s: Fingers [-, -, -, -, -] Arm [-, -, 89]
  delay(31);
  servo[7].write(89); // Wrist

  // Keyframe 51 @ 2.88s: Fingers [-, -, -, -, -] Arm [-, -, 87]
  smoothMove(7, 87, 3); // Wrist

  // Keyframe 52 @ 2.92s: Fingers [-, -, -, -, -] Arm [-, -, 85]
  delay(47);
  servo[7].write(85); // Wrist

  // Keyframe 53 @ 3.03s: Fingers [-, -, -, -, -] Arm [-, -, 83]
  smoothMove(7, 83, 5); // Wrist

  // Keyframe 54 @ 3.11s: Fingers [-, -, -, -, -] Arm [-, -, 81]
  smoothMove(7, 81, 4); // Wrist

  // Keyframe 55 @ 3.17s: Fingers [-, -, -, -, -] Arm [-, -, 79]
  smoothMove(7, 79, 3); // Wrist

  // Keyframe 56 @ 3.26s: Fingers [-, -, -, -, -] Arm [-, -, 77]
  smoothMove(7, 77, 4); // Wrist

  // Keyframe 57 @ 3.30s: Fingers [-, -, -, -, -] Arm [-, -, 75]
  delay(42);
  servo[7].write(75); // Wrist

  // Keyframe 58 @ 3.36s: Fingers [-, -, -, -, -] Arm [-, -, 73]
  smoothMove(7, 73, 3); // Wrist

  // Keyframe 59 @ 3.50s: Fingers [-, -, -, -, -] Arm [-, -, 75]
  smoothMove(7, 75, 6); // Wrist

  // Keyframe 60 @ 3.53s: Fingers [-, -, -, -, -] Arm [-, -, 77]
  delay(30);
  servo[7].write(77); // Wrist

  // Keyframe 61 @ 3.56s: Fingers [-, -, -, -, -] Arm [-, -, 79]
  delay(32);
  servo[7].write(79); // Wrist

  // Keyframe 62 @ 3.61s: Fingers [-, -, -, -, -] Arm [-, -, 81]
  delay(43);
  servo[7].write(81); // Wrist

  // Keyframe 63 @ 3.64s: Fingers [-, -, -, -, -] Arm [-, -, 83]
  delay(29);
  servo[7].write(83); // Wrist

  // Keyframe 64 @ 3.67s: Fingers [-, -, -, -, -] Arm [-, -, 85]
  delay(31);
  servo[7].write(85); // Wrist

  // Keyframe 65 @ 3.70s: Fingers [-, -, -, -, -] Arm [-, -, 87]
  delay(32);
  servo[7].write(87); // Wrist

  // Keyframe 66 @ 3.73s: Fingers [-, -, -, -, -] Arm [-, -, 90]
  delay(32);
  servo[7].write(90); // Wrist

  // Keyframe 67 @ 3.78s: Fingers [-, -, -, -, -] Arm [-, -, 92]
  smoothMove(7, 92, 2); // Wrist

  // Keyframe 68 @ 3.82s: Fingers [-, -, -, -, -] Arm [-, -, 94]
  delay(36);
  servo[7].write(94); // Wrist

  // Keyframe 69 @ 3.88s: Fingers [-, -, -, -, -] Arm [-, -, 96]
  smoothMove(7, 96, 2); // Wrist

  // Keyframe 70 @ 3.94s: Fingers [-, -, -, -, -] Arm [-, -, 98]
  smoothMove(7, 98, 3); // Wrist

  // Keyframe 71 @ 4.01s: Fingers [-, -, -, -, -] Arm [-, -, 100]
  smoothMove(7, 100, 3); // Wrist

  // Keyframe 72 @ 4.06s: Fingers [-, -, -, -, -] Arm [-, -, 102]
  smoothMove(7, 102, 2); // Wrist

  // Keyframe 73 @ 4.09s: Fingers [-, -, -, -, -] Arm [-, -, 104]
  delay(26);
  servo[7].write(104); // Wrist

  // Keyframe 74 @ 4.12s: Fingers [-, -, -, -, -] Arm [-, -, 107]
  delay(28);
  servo[7].write(107); // Wrist

  // Keyframe 75 @ 4.14s: Fingers [-, -, -, -, -] Arm [-, -, 109]
  delay(25);
  servo[7].write(109); // Wrist

  // Keyframe 76 @ 4.17s: Fingers [-, -, -, -, -] Arm [-, -, 111]
  delay(31);
  servo[7].write(111); // Wrist

  // Keyframe 77 @ 4.21s: Fingers [-, -, -, -, -] Arm [-, -, 113]
  delay(38);
  servo[7].write(113); // Wrist

  // Keyframe 78 @ 4.25s: Fingers [-, -, -, -, -] Arm [-, -, 115]
  delay(35);
  servo[7].write(115); // Wrist

  // Keyframe 79 @ 4.28s: Fingers [-, -, -, -, -] Arm [-, -, 117]
  delay(31);
  servo[7].write(117); // Wrist

  // Keyframe 80 @ 4.32s: Fingers [-, -, -, -, -] Arm [-, -, 119]
  delay(40);
  servo[7].write(119); // Wrist

  // Keyframe 81 @ 4.38s: Fingers [-, -, -, -, -] Arm [-, -, 121]
  smoothMove(7, 121, 3); // Wrist

  // Keyframe 82 @ 4.45s: Fingers [-, -, -, -, -] Arm [-, -, 123]
  smoothMove(7, 123, 3); // Wrist

  // Keyframe 83 @ 4.48s: Fingers [-, -, -, -, -] Arm [-, -, 126]
  delay(37);
  servo[7].write(126); // Wrist

  // Keyframe 84 @ 4.53s: Fingers [-, -, -, -, -] Arm [-, -, 128]
  delay(44);
  servo[7].write(128); // Wrist

  // Keyframe 85 @ 4.61s: Fingers [-, -, -, -, -] Arm [-, -, 130]
  smoothMove(7, 130, 4); // Wrist

  // Keyframe 86 @ 4.72s: Fingers [-, -, -, -, -] Arm [-, -, 132]
  smoothMove(7, 132, 5); // Wrist

  // Keyframe 87 @ 4.78s: Fingers [-, -, -, -, -] Arm [-, -, 134]
  smoothMove(7, 134, 3); // Wrist

  // Keyframe 88 @ 4.93s: Fingers [-, -, -, -, -] Arm [-, -, 136]
  smoothMove(7, 136, 7); // Wrist

  // Keyframe 89 @ 5.12s: Fingers [-, -, -, -, -] Arm [-, -, 138]
  smoothMove(7, 138, 9); // Wrist

  // Keyframe 90 @ 5.39s: Fingers [-, -, -, -, -] Arm [-, -, 136]
  smoothMove(7, 136, 13); // Wrist

  // Keyframe 91 @ 5.48s: Fingers [-, -, -, -, -] Arm [-, -, 134]
  smoothMove(7, 134, 4); // Wrist

  // Keyframe 92 @ 5.51s: Fingers [-, -, -, -, -] Arm [-, -, 132]
  delay(31);
  servo[7].write(132); // Wrist

  // Keyframe 93 @ 5.59s: Fingers [-, -, -, -, -] Arm [-, -, 130]
  smoothMove(7, 130, 3); // Wrist

  // Keyframe 94 @ 5.64s: Fingers [-, -, -, -, -] Arm [-, -, 128]
  smoothMove(7, 128, 2); // Wrist

  // Keyframe 95 @ 5.68s: Fingers [-, -, -, -, -] Arm [-, -, 125]
  delay(40);
  servo[7].write(125); // Wrist

  // Keyframe 96 @ 5.73s: Fingers [-, -, -, -, -] Arm [-, -, 123]
  delay(49);
  servo[7].write(123); // Wrist

}

// Layer 4: Layer_4 - cursor mode
// Duration: 5.7s, Keyframes: 248 (reduced from 712 frames)
void playLayer4() {
  // Keyframe 1 @ 0.01s: Fingers [162, 155, 180, 151, 169] Arm [-, -, -]
  delay(9);
  servo[0].write(162); // Thumb
  servo[1].write(155); // Index
  servo[2].write(180); // Middle
  servo[3].write(151); // Ring
  servo[4].write(169); // Pinky

  // Keyframe 2 @ 0.40s: Fingers [165, 153, 180, 153, 166] Arm [-, -, -]
  smoothMove(0, 165, 19); // Thumb
  smoothMove(1, 153, 19); // Index
  smoothMove(2, 180, 19); // Middle
  smoothMove(3, 153, 19); // Ring
  smoothMove(4, 166, 19); // Pinky

  // Keyframe 3 @ 0.42s: Fingers [167, 151, 180, 153, 163] Arm [-, -, -]
  delay(23);
  servo[0].write(167); // Thumb
  servo[1].write(151); // Index
  servo[2].write(180); // Middle
  servo[3].write(153); // Ring
  servo[4].write(163); // Pinky

  // Keyframe 4 @ 0.46s: Fingers [169, 149, 180, 156, 160] Arm [-, -, -]
  delay(39);
  servo[0].write(169); // Thumb
  servo[1].write(149); // Index
  servo[2].write(180); // Middle
  servo[3].write(156); // Ring
  servo[4].write(160); // Pinky

  // Keyframe 5 @ 0.50s: Fingers [169, 148, 180, 156, 158] Arm [-, -, -]
  delay(34);
  servo[0].write(169); // Thumb
  servo[1].write(148); // Index
  servo[2].write(180); // Middle
  servo[3].write(156); // Ring
  servo[4].write(158); // Pinky

  // Keyframe 6 @ 0.57s: Fingers [171, 146, 179, 158, 155] Arm [-, -, -]
  smoothMove(0, 171, 3); // Thumb
  smoothMove(1, 146, 3); // Index
  smoothMove(2, 179, 3); // Middle
  smoothMove(3, 158, 3); // Ring
  smoothMove(4, 155, 3); // Pinky

  // Keyframe 7 @ 0.61s: Fingers [171, 145, 178, 158, 153] Arm [-, -, -]
  delay(35);
  servo[0].write(171); // Thumb
  servo[1].write(145); // Index
  servo[2].write(178); // Middle
  servo[3].write(158); // Ring
  servo[4].write(153); // Pinky

  // Keyframe 8 @ 0.64s: Fingers [172, 143, 175, 158, 150] Arm [-, -, -]
  delay(30);
  servo[0].write(172); // Thumb
  servo[1].write(143); // Index
  servo[2].write(175); // Middle
  servo[3].write(158); // Ring
  servo[4].write(150); // Pinky

  // Keyframe 9 @ 0.65s: Fingers [172, 142, 173, 159, 148] Arm [-, -, -]
  delay(17);
  servo[0].write(172); // Thumb
  servo[1].write(142); // Index
  servo[2].write(173); // Middle
  servo[3].write(159); // Ring
  servo[4].write(148); // Pinky

  // Keyframe 10 @ 0.69s: Fingers [172, 141, 170, 160, 145] Arm [-, -, -]
  delay(31);
  servo[0].write(172); // Thumb
  servo[1].write(141); // Index
  servo[2].write(170); // Middle
  servo[3].write(160); // Ring
  servo[4].write(145); // Pinky

  // Keyframe 11 @ 0.72s: Fingers [171, 139, 168, 159, 143] Arm [-, -, -]
  delay(30);
  servo[0].write(171); // Thumb
  servo[1].write(139); // Index
  servo[2].write(168); // Middle
  servo[3].write(159); // Ring
  servo[4].write(143); // Pinky

  // Keyframe 12 @ 0.79s: Fingers [170, 137, 165, 158, 140] Arm [-, -, -]
  smoothMove(0, 170, 3); // Thumb
  smoothMove(1, 137, 3); // Index
  smoothMove(2, 165, 3); // Middle
  smoothMove(3, 158, 3); // Ring
  smoothMove(4, 140, 3); // Pinky

  // Keyframe 13 @ 0.82s: Fingers [167, 135, 163, 156, 138] Arm [-, -, -]
  delay(34);
  servo[0].write(167); // Thumb
  servo[1].write(135); // Index
  servo[2].write(163); // Middle
  servo[3].write(156); // Ring
  servo[4].write(138); // Pinky

  // Keyframe 14 @ 0.85s: Fingers [165, 133, 160, 154, 135] Arm [-, -, -]
  delay(29);
  servo[0].write(165); // Thumb
  servo[1].write(133); // Index
  servo[2].write(160); // Middle
  servo[3].write(154); // Ring
  servo[4].write(135); // Pinky

  // Keyframe 15 @ 0.92s: Fingers [163, 131, 159, 151, 134] Arm [-, -, -]
  smoothMove(0, 163, 3); // Thumb
  smoothMove(1, 131, 3); // Index
  smoothMove(2, 159, 3); // Middle
  smoothMove(3, 151, 3); // Ring
  smoothMove(4, 134, 3); // Pinky

  // Keyframe 16 @ 0.95s: Fingers [160, 128, 158, 148, 133] Arm [-, -, -]
  delay(33);
  servo[0].write(160); // Thumb
  servo[1].write(128); // Index
  servo[2].write(158); // Middle
  servo[3].write(148); // Ring
  servo[4].write(133); // Pinky

  // Keyframe 17 @ 0.97s: Fingers [158, 127, 158, 146, 132] Arm [-, -, -]
  delay(22);
  servo[0].write(158); // Thumb
  servo[1].write(127); // Index
  servo[2].write(158); // Middle
  servo[3].write(146); // Ring
  servo[4].write(132); // Pinky

  // Keyframe 18 @ 0.98s: Fingers [156, 126, 157, 143, 132] Arm [-, -, -]
  delay(9);
  servo[0].write(156); // Thumb
  servo[1].write(126); // Index
  servo[2].write(157); // Middle
  servo[3].write(143); // Ring
  servo[4].write(132); // Pinky

  // Keyframe 19 @ 1.01s: Fingers [154, 126, 158, 141, 133] Arm [-, -, -]
  delay(31);
  servo[0].write(154); // Thumb
  servo[1].write(126); // Index
  servo[2].write(158); // Middle
  servo[3].write(141); // Ring
  servo[4].write(133); // Pinky

  // Keyframe 20 @ 1.05s: Fingers [151, 125, 158, 138, 133] Arm [-, -, -]
  delay(39);
  servo[0].write(151); // Thumb
  servo[1].write(125); // Index
  servo[2].write(158); // Middle
  servo[3].write(138); // Ring
  servo[4].write(133); // Pinky

  // Keyframe 21 @ 1.07s: Fingers [149, 125, 158, 135, 134] Arm [-, -, -]
  delay(17);
  servo[0].write(149); // Thumb
  servo[1].write(125); // Index
  servo[2].write(158); // Middle
  servo[3].write(135); // Ring
  servo[4].write(134); // Pinky

  // Keyframe 22 @ 1.08s: Fingers [147, 125, 158, 133, 136] Arm [-, -, -]
  delay(7);
  servo[0].write(147); // Thumb
  servo[1].write(125); // Index
  servo[2].write(158); // Middle
  servo[3].write(133); // Ring
  servo[4].write(136); // Pinky

  // Keyframe 23 @ 1.10s: Fingers [144, 126, 158, 131, 137] Arm [-, -, -]
  delay(24);
  servo[0].write(144); // Thumb
  servo[1].write(126); // Index
  servo[2].write(158); // Middle
  servo[3].write(131); // Ring
  servo[4].write(137); // Pinky

  // Keyframe 24 @ 1.12s: Fingers [141, 126, 157, 128, 138] Arm [-, -, -]
  delay(15);
  servo[0].write(141); // Thumb
  servo[1].write(126); // Index
  servo[2].write(157); // Middle
  servo[3].write(128); // Ring
  servo[4].write(138); // Pinky

  // Keyframe 25 @ 1.13s: Fingers [136, 128, 157, 125, 141] Arm [-, -, -]
  delay(17);
  servo[0].write(136); // Thumb
  servo[1].write(128); // Index
  servo[2].write(157); // Middle
  servo[3].write(125); // Ring
  servo[4].write(141); // Pinky

  // Keyframe 26 @ 1.15s: Fingers [134, 129, 156, 123, 143] Arm [-, -, -]
  delay(14);
  servo[0].write(134); // Thumb
  servo[1].write(129); // Index
  servo[2].write(156); // Middle
  servo[3].write(123); // Ring
  servo[4].write(143); // Pinky

  // Keyframe 27 @ 1.17s: Fingers [131, 131, 154, 121, 145] Arm [-, -, -]
  delay(17);
  servo[0].write(131); // Thumb
  servo[1].write(131); // Index
  servo[2].write(154); // Middle
  servo[3].write(121); // Ring
  servo[4].write(145); // Pinky

  // Keyframe 28 @ 1.25s: Fingers [127, 135, 152, 120, 148] Arm [-, -, -]
  smoothMove(0, 127, 4); // Thumb
  smoothMove(1, 135, 4); // Index
  smoothMove(2, 152, 4); // Middle
  smoothMove(3, 120, 4); // Ring
  smoothMove(4, 148, 4); // Pinky

  // Keyframe 29 @ 1.29s: Fingers [125, 138, 150, 120, 151] Arm [-, -, -]
  delay(31);
  servo[0].write(125); // Thumb
  servo[1].write(138); // Index
  servo[2].write(150); // Middle
  servo[3].write(120); // Ring
  servo[4].write(151); // Pinky

  // Keyframe 30 @ 1.35s: Fingers [124, 140, 149, 120, 152] Arm [-, -, -]
  smoothMove(0, 124, 3); // Thumb
  smoothMove(1, 140, 3); // Index
  smoothMove(2, 149, 3); // Middle
  smoothMove(3, 120, 3); // Ring
  smoothMove(4, 152, 3); // Pinky

  // Keyframe 31 @ 1.38s: Fingers [124, 143, 148, 121, 154] Arm [-, -, -]
  delay(31);
  servo[0].write(124); // Thumb
  servo[1].write(143); // Index
  servo[2].write(148); // Middle
  servo[3].write(121); // Ring
  servo[4].write(154); // Pinky

  // Keyframe 32 @ 1.41s: Fingers [124, 145, 149, 123, 156] Arm [-, -, -]
  delay(32);
  servo[0].write(124); // Thumb
  servo[1].write(145); // Index
  servo[2].write(149); // Middle
  servo[3].write(123); // Ring
  servo[4].write(156); // Pinky

  // Keyframe 33 @ 1.44s: Fingers [125, 147, 149, 124, 157] Arm [-, -, -]
  delay(24);
  servo[0].write(125); // Thumb
  servo[1].write(147); // Index
  servo[2].write(149); // Middle
  servo[3].write(124); // Ring
  servo[4].write(157); // Pinky

  // Keyframe 34 @ 1.47s: Fingers [126, 149, 149, 126, 159] Arm [-, -, -]
  delay(29);
  servo[0].write(126); // Thumb
  servo[1].write(149); // Index
  servo[2].write(149); // Middle
  servo[3].write(126); // Ring
  servo[4].write(159); // Pinky

  // Keyframe 35 @ 1.49s: Fingers [126, 152, 148, 128, 161] Arm [-, -, -]
  delay(17);
  servo[0].write(126); // Thumb
  servo[1].write(152); // Index
  servo[2].write(148); // Middle
  servo[3].write(128); // Ring
  servo[4].write(161); // Pinky

  // Keyframe 36 @ 1.57s: Fingers [128, 154, 151, 130, 163] Arm [-, -, -]
  smoothMove(0, 128, 4); // Thumb
  smoothMove(1, 154, 4); // Index
  smoothMove(2, 151, 4); // Middle
  smoothMove(3, 130, 4); // Ring
  smoothMove(4, 163, 4); // Pinky

  // Keyframe 37 @ 1.61s: Fingers [131, 157, 153, 132, 165] Arm [-, -, -]
  delay(38);
  servo[0].write(131); // Thumb
  servo[1].write(157); // Index
  servo[2].write(153); // Middle
  servo[3].write(132); // Ring
  servo[4].write(165); // Pinky

  // Keyframe 38 @ 1.63s: Fingers [132, 157, 155, 133, 166] Arm [-, -, -]
  delay(21);
  servo[0].write(132); // Thumb
  servo[1].write(157); // Index
  servo[2].write(155); // Middle
  servo[3].write(133); // Ring
  servo[4].write(166); // Pinky

  // Keyframe 39 @ 1.64s: Fingers [134, 157, 157, 134, 167] Arm [-, -, -]
  delay(10);
  servo[0].write(134); // Thumb
  servo[1].write(157); // Index
  servo[2].write(157); // Middle
  servo[3].write(134); // Ring
  servo[4].write(167); // Pinky

  // Keyframe 40 @ 1.66s: Fingers [135, 157, 159, 134, 168] Arm [-, -, -]
  delay(24);
  servo[0].write(135); // Thumb
  servo[1].write(157); // Index
  servo[2].write(159); // Middle
  servo[3].write(134); // Ring
  servo[4].write(168); // Pinky

  // Keyframe 41 @ 1.67s: Fingers [137, 158, 161, 135, 168] Arm [-, -, -]
  delay(7);
  servo[0].write(137); // Thumb
  servo[1].write(158); // Index
  servo[2].write(161); // Middle
  servo[3].write(135); // Ring
  servo[4].write(168); // Pinky

  // Keyframe 42 @ 1.68s: Fingers [139, 157, 164, 136, 168] Arm [-, -, -]
  delay(7);
  servo[0].write(139); // Thumb
  servo[1].write(157); // Index
  servo[2].write(164); // Middle
  servo[3].write(136); // Ring
  servo[4].write(168); // Pinky

  // Keyframe 43 @ 1.70s: Fingers [141, 158, 166, 137, 169] Arm [-, -, -]
  delay(24);
  servo[0].write(141); // Thumb
  servo[1].write(158); // Index
  servo[2].write(166); // Middle
  servo[3].write(137); // Ring
  servo[4].write(169); // Pinky

  // Keyframe 44 @ 1.73s: Fingers [144, 157, 169, 138, 169] Arm [-, -, -]
  delay(32);
  servo[0].write(144); // Thumb
  servo[1].write(157); // Index
  servo[2].write(169); // Middle
  servo[3].write(138); // Ring
  servo[4].write(169); // Pinky

  // Keyframe 45 @ 1.75s: Fingers [146, 156, 172, 140, 169] Arm [-, -, -]
  delay(18);
  servo[0].write(146); // Thumb
  servo[1].write(156); // Index
  servo[2].write(172); // Middle
  servo[3].write(140); // Ring
  servo[4].write(169); // Pinky

  // Keyframe 46 @ 1.76s: Fingers [149, 155, 174, 141, 169] Arm [-, -, -]
  delay(12);
  servo[0].write(149); // Thumb
  servo[1].write(155); // Index
  servo[2].write(174); // Middle
  servo[3].write(141); // Ring
  servo[4].write(169); // Pinky

  // Keyframe 47 @ 1.79s: Fingers [154, 153, 177, 144, 167] Arm [-, -, -]
  delay(24);
  servo[0].write(154); // Thumb
  servo[1].write(153); // Index
  servo[2].write(177); // Middle
  servo[3].write(144); // Ring
  servo[4].write(167); // Pinky

  // Keyframe 48 @ 1.81s: Fingers [157, 152, 178, 146, 165] Arm [-, -, -]
  delay(22);
  servo[0].write(157); // Thumb
  servo[1].write(152); // Index
  servo[2].write(178); // Middle
  servo[3].write(146); // Ring
  servo[4].write(165); // Pinky

  // Keyframe 49 @ 1.86s: Fingers [159, 151, 179, 147, 164] Arm [-, -, -]
  delay(50);
  servo[0].write(159); // Thumb
  servo[1].write(151); // Index
  servo[2].write(179); // Middle
  servo[3].write(147); // Ring
  servo[4].write(164); // Pinky

  // Keyframe 50 @ 1.88s: Fingers [157, 152, 178, 146, 165] Arm [-, -, -]
  delay(17);
  servo[0].write(157); // Thumb
  servo[1].write(152); // Index
  servo[2].write(178); // Middle
  servo[3].write(146); // Ring
  servo[4].write(165); // Pinky

  // Keyframe 51 @ 1.91s: Fingers [159, 149, 178, 147, 162] Arm [-, -, -]
  delay(30);
  servo[0].write(159); // Thumb
  servo[1].write(149); // Index
  servo[2].write(178); // Middle
  servo[3].write(147); // Ring
  servo[4].write(162); // Pinky

  // Keyframe 52 @ 1.95s: Fingers [162, 147, 178, 149, 159] Arm [-, -, -]
  delay(40);
  servo[0].write(162); // Thumb
  servo[1].write(147); // Index
  servo[2].write(178); // Middle
  servo[3].write(149); // Ring
  servo[4].write(159); // Pinky

  // Keyframe 53 @ 1.96s: Fingers [165, 145, 178, 151, 156] Arm [-, -, -]
  delay(8);
  servo[0].write(165); // Thumb
  servo[1].write(145); // Index
  servo[2].write(178); // Middle
  servo[3].write(151); // Ring
  servo[4].write(156); // Pinky

  // Keyframe 54 @ 1.98s: Fingers [166, 143, 177, 153, 153] Arm [-, -, -]
  delay(24);
  servo[0].write(166); // Thumb
  servo[1].write(143); // Index
  servo[2].write(177); // Middle
  servo[3].write(153); // Ring
  servo[4].write(153); // Pinky

  // Keyframe 55 @ 2.01s: Fingers [168, 142, 175, 154, 151] Arm [-, -, -]
  delay(32);
  servo[0].write(168); // Thumb
  servo[1].write(142); // Index
  servo[2].write(175); // Middle
  servo[3].write(154); // Ring
  servo[4].write(151); // Pinky

  // Keyframe 56 @ 2.04s: Fingers [169, 141, 174, 155, 149] Arm [-, -, -]
  delay(23);
  servo[0].write(169); // Thumb
  servo[1].write(141); // Index
  servo[2].write(174); // Middle
  servo[3].write(155); // Ring
  servo[4].write(149); // Pinky

  // Keyframe 57 @ 2.06s: Fingers [171, 140, 171, 159, 145] Arm [-, -, -]
  delay(24);
  servo[0].write(171); // Thumb
  servo[1].write(140); // Index
  servo[2].write(171); // Middle
  servo[3].write(159); // Ring
  servo[4].write(145); // Pinky

  // Keyframe 58 @ 2.07s: Fingers [172, 140, 169, 160, 143] Arm [-, -, -]
  delay(7);
  servo[0].write(172); // Thumb
  servo[1].write(140); // Index
  servo[2].write(169); // Middle
  servo[3].write(160); // Ring
  servo[4].write(143); // Pinky

  // Keyframe 59 @ 2.08s: Fingers [172, 140, 166, 161, 142] Arm [-, -, -]
  delay(7);
  servo[0].write(172); // Thumb
  servo[1].write(140); // Index
  servo[2].write(166); // Middle
  servo[3].write(161); // Ring
  servo[4].write(142); // Pinky

  // Keyframe 60 @ 2.09s: Fingers [173, 140, 164, 163, 140] Arm [-, -, -]
  delay(17);
  servo[0].write(173); // Thumb
  servo[1].write(140); // Index
  servo[2].write(164); // Middle
  servo[3].write(163); // Ring
  servo[4].write(140); // Pinky

  // Keyframe 61 @ 2.11s: Fingers [173, 140, 162, 164, 139] Arm [-, -, -]
  delay(16);
  servo[0].write(173); // Thumb
  servo[1].write(140); // Index
  servo[2].write(162); // Middle
  servo[3].write(164); // Ring
  servo[4].write(139); // Pinky

  // Keyframe 62 @ 2.12s: Fingers [173, 140, 159, 165, 138] Arm [-, -, -]
  delay(15);
  servo[0].write(173); // Thumb
  servo[1].write(140); // Index
  servo[2].write(159); // Middle
  servo[3].write(165); // Ring
  servo[4].write(138); // Pinky

  // Keyframe 63 @ 2.14s: Fingers [172, 140, 157, 165, 136] Arm [-, -, -]
  delay(17);
  servo[0].write(172); // Thumb
  servo[1].write(140); // Index
  servo[2].write(157); // Middle
  servo[3].write(165); // Ring
  servo[4].write(136); // Pinky

  // Keyframe 64 @ 2.16s: Fingers [170, 139, 154, 164, 135] Arm [-, -, -]
  delay(15);
  servo[0].write(170); // Thumb
  servo[1].write(139); // Index
  servo[2].write(154); // Middle
  servo[3].write(164); // Ring
  servo[4].write(135); // Pinky

  // Keyframe 65 @ 2.17s: Fingers [170, 140, 151, 165, 134] Arm [-, -, -]
  delay(15);
  servo[0].write(170); // Thumb
  servo[1].write(140); // Index
  servo[2].write(151); // Middle
  servo[3].write(165); // Ring
  servo[4].write(134); // Pinky

  // Keyframe 66 @ 2.19s: Fingers [169, 140, 149, 165, 133] Arm [-, -, -]
  delay(15);
  servo[0].write(169); // Thumb
  servo[1].write(140); // Index
  servo[2].write(149); // Middle
  servo[3].write(165); // Ring
  servo[4].write(133); // Pinky

  // Keyframe 67 @ 2.22s: Fingers [168, 141, 146, 166, 133] Arm [-, -, -]
  delay(33);
  servo[0].write(168); // Thumb
  servo[1].write(141); // Index
  servo[2].write(146); // Middle
  servo[3].write(166); // Ring
  servo[4].write(133); // Pinky

  // Keyframe 68 @ 2.28s: Fingers [165, 139, 142, 163, 130] Arm [-, -, -]
  smoothMove(0, 165, 2); // Thumb
  smoothMove(1, 139, 2); // Index
  smoothMove(2, 142, 2); // Middle
  smoothMove(3, 163, 2); // Ring
  smoothMove(4, 130, 2); // Pinky

  // Keyframe 69 @ 2.29s: Fingers [163, 139, 140, 163, 129] Arm [-, -, -]
  delay(9);
  servo[0].write(163); // Thumb
  servo[1].write(139); // Index
  servo[2].write(140); // Middle
  servo[3].write(163); // Ring
  servo[4].write(129); // Pinky

  // Keyframe 70 @ 2.31s: Fingers [161, 138, 138, 161, 128] Arm [-, -, -]
  delay(23);
  servo[0].write(161); // Thumb
  servo[1].write(138); // Index
  servo[2].write(138); // Middle
  servo[3].write(161); // Ring
  servo[4].write(128); // Pinky

  // Keyframe 71 @ 2.32s: Fingers [160, 138, 136, 160, 127] Arm [-, -, -]
  delay(8);
  servo[0].write(160); // Thumb
  servo[1].write(138); // Index
  servo[2].write(136); // Middle
  servo[3].write(160); // Ring
  servo[4].write(127); // Pinky

  // Keyframe 72 @ 2.37s: Fingers [157, 135, 133, 158, 125] Arm [-, -, -]
  smoothMove(0, 157, 2); // Thumb
  smoothMove(1, 135, 2); // Index
  smoothMove(2, 133, 2); // Middle
  smoothMove(3, 158, 2); // Ring
  smoothMove(4, 125, 2); // Pinky

  // Keyframe 73 @ 2.41s: Fingers [155, 133, 131, 156, 123] Arm [-, -, -]
  delay(40);
  servo[0].write(155); // Thumb
  servo[1].write(133); // Index
  servo[2].write(131); // Middle
  servo[3].write(156); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 74 @ 2.45s: Fingers [153, 131, 129, 154, 120] Arm [-, -, -]
  delay(32);
  servo[0].write(153); // Thumb
  servo[1].write(131); // Index
  servo[2].write(129); // Middle
  servo[3].write(154); // Ring
  servo[4].write(120); // Pinky

  // Keyframe 75 @ 2.46s: Fingers [152, 128, 128, 152, 118] Arm [-, -, -]
  delay(16);
  servo[0].write(152); // Thumb
  servo[1].write(128); // Index
  servo[2].write(128); // Middle
  servo[3].write(152); // Ring
  servo[4].write(118); // Pinky

  // Keyframe 76 @ 2.48s: Fingers [151, 125, 129, 150, 117] Arm [-, -, -]
  delay(15);
  servo[0].write(151); // Thumb
  servo[1].write(125); // Index
  servo[2].write(129); // Middle
  servo[3].write(150); // Ring
  servo[4].write(117); // Pinky

  // Keyframe 77 @ 2.49s: Fingers [150, 122, 129, 147, 115] Arm [-, -, -]
  delay(15);
  servo[0].write(150); // Thumb
  servo[1].write(122); // Index
  servo[2].write(129); // Middle
  servo[3].write(147); // Ring
  servo[4].write(115); // Pinky

  // Keyframe 78 @ 2.50s: Fingers [148, 118, 130, 143, 112] Arm [-, -, -]
  delay(9);
  servo[0].write(148); // Thumb
  servo[1].write(118); // Index
  servo[2].write(130); // Middle
  servo[3].write(143); // Ring
  servo[4].write(112); // Pinky

  // Keyframe 79 @ 2.53s: Fingers [147, 115, 131, 141, 111] Arm [-, -, -]
  delay(23);
  servo[0].write(147); // Thumb
  servo[1].write(115); // Index
  servo[2].write(131); // Middle
  servo[3].write(141); // Ring
  servo[4].write(111); // Pinky

  // Keyframe 80 @ 2.53s: Fingers [146, 114, 132, 138, 111] Arm [-, -, -]
  delay(7);
  servo[0].write(146); // Thumb
  servo[1].write(114); // Index
  servo[2].write(132); // Middle
  servo[3].write(138); // Ring
  servo[4].write(111); // Pinky

  // Keyframe 81 @ 2.56s: Fingers [145, 112, 134, 136, 111] Arm [-, -, -]
  delay(24);
  servo[0].write(145); // Thumb
  servo[1].write(112); // Index
  servo[2].write(134); // Middle
  servo[3].write(136); // Ring
  servo[4].write(111); // Pinky

  // Keyframe 82 @ 2.56s: Fingers [144, 111, 135, 134, 111] Arm [-, -, -]
  delay(1);
  servo[0].write(144); // Thumb
  servo[1].write(111); // Index
  servo[2].write(135); // Middle
  servo[3].write(134); // Ring
  servo[4].write(111); // Pinky

  // Keyframe 83 @ 2.57s: Fingers [142, 109, 136, 131, 111] Arm [-, -, -]
  delay(6);
  servo[0].write(142); // Thumb
  servo[1].write(109); // Index
  servo[2].write(136); // Middle
  servo[3].write(131); // Ring
  servo[4].write(111); // Pinky

  // Keyframe 84 @ 2.57s: Fingers [140, 108, 137, 128, 112] Arm [-, -, -]
  delay(7);
  servo[0].write(140); // Thumb
  servo[1].write(108); // Index
  servo[2].write(137); // Middle
  servo[3].write(128); // Ring
  servo[4].write(112); // Pinky

  // Keyframe 85 @ 2.59s: Fingers [137, 107, 138, 124, 112] Arm [-, -, -]
  delay(12);
  servo[0].write(137); // Thumb
  servo[1].write(107); // Index
  servo[2].write(138); // Middle
  servo[3].write(124); // Ring
  servo[4].write(112); // Pinky

  // Keyframe 86 @ 2.59s: Fingers [135, 107, 140, 121, 115] Arm [-, -, -]
  delay(3);
  servo[0].write(135); // Thumb
  servo[1].write(107); // Index
  servo[2].write(140); // Middle
  servo[3].write(121); // Ring
  servo[4].write(115); // Pinky

  // Keyframe 87 @ 2.60s: Fingers [132, 107, 140, 119, 116] Arm [-, -, -]
  delay(8);
  servo[0].write(132); // Thumb
  servo[1].write(107); // Index
  servo[2].write(140); // Middle
  servo[3].write(119); // Ring
  servo[4].write(116); // Pinky

  // Keyframe 88 @ 2.61s: Fingers [129, 108, 141, 115, 118] Arm [-, -, -]
  delay(16);
  servo[0].write(129); // Thumb
  servo[1].write(108); // Index
  servo[2].write(141); // Middle
  servo[3].write(115); // Ring
  servo[4].write(118); // Pinky

  // Keyframe 89 @ 2.63s: Fingers [127, 108, 141, 113, 119] Arm [-, -, -]
  delay(16);
  servo[0].write(127); // Thumb
  servo[1].write(108); // Index
  servo[2].write(141); // Middle
  servo[3].write(113); // Ring
  servo[4].write(119); // Pinky

  // Keyframe 90 @ 2.68s: Fingers [124, 110, 141, 111, 122] Arm [-, -, -]
  delay(50);
  servo[0].write(124); // Thumb
  servo[1].write(110); // Index
  servo[2].write(141); // Middle
  servo[3].write(111); // Ring
  servo[4].write(122); // Pinky

  // Keyframe 91 @ 2.71s: Fingers [121, 112, 141, 109, 125] Arm [-, -, -]
  delay(28);
  servo[0].write(121); // Thumb
  servo[1].write(112); // Index
  servo[2].write(141); // Middle
  servo[3].write(109); // Ring
  servo[4].write(125); // Pinky

  // Keyframe 92 @ 2.73s: Fingers [119, 114, 141, 108, 128] Arm [-, -, -]
  delay(17);
  servo[0].write(119); // Thumb
  servo[1].write(114); // Index
  servo[2].write(141); // Middle
  servo[3].write(108); // Ring
  servo[4].write(128); // Pinky

  // Keyframe 93 @ 2.74s: Fingers [118, 117, 141, 108, 130] Arm [-, -, -]
  delay(15);
  servo[0].write(118); // Thumb
  servo[1].write(117); // Index
  servo[2].write(141); // Middle
  servo[3].write(108); // Ring
  servo[4].write(130); // Pinky

  // Keyframe 94 @ 2.75s: Fingers [117, 119, 141, 108, 133] Arm [-, -, -]
  delay(7);
  servo[0].write(117); // Thumb
  servo[1].write(119); // Index
  servo[2].write(141); // Middle
  servo[3].write(108); // Ring
  servo[4].write(133); // Pinky

  // Keyframe 95 @ 2.77s: Fingers [115, 122, 140, 108, 135] Arm [-, -, -]
  delay(22);
  servo[0].write(115); // Thumb
  servo[1].write(122); // Index
  servo[2].write(140); // Middle
  servo[3].write(108); // Ring
  servo[4].write(135); // Pinky

  // Keyframe 96 @ 2.78s: Fingers [114, 126, 140, 108, 139] Arm [-, -, -]
  delay(12);
  servo[0].write(114); // Thumb
  servo[1].write(126); // Index
  servo[2].write(140); // Middle
  servo[3].write(108); // Ring
  servo[4].write(139); // Pinky

  // Keyframe 97 @ 2.80s: Fingers [113, 131, 138, 110, 142] Arm [-, -, -]
  delay(19);
  servo[0].write(113); // Thumb
  servo[1].write(131); // Index
  servo[2].write(138); // Middle
  servo[3].write(110); // Ring
  servo[4].write(142); // Pinky

  // Keyframe 98 @ 2.81s: Fingers [114, 135, 138, 113, 146] Arm [-, -, -]
  delay(12);
  servo[0].write(114); // Thumb
  servo[1].write(135); // Index
  servo[2].write(138); // Middle
  servo[3].write(113); // Ring
  servo[4].write(146); // Pinky

  // Keyframe 99 @ 2.82s: Fingers [115, 138, 139, 115, 148] Arm [-, -, -]
  delay(6);
  servo[0].write(115); // Thumb
  servo[1].write(138); // Index
  servo[2].write(139); // Middle
  servo[3].write(115); // Ring
  servo[4].write(148); // Pinky

  // Keyframe 100 @ 2.84s: Fingers [115, 140, 138, 116, 149] Arm [-, -, -]
  delay(19);
  servo[0].write(115); // Thumb
  servo[1].write(140); // Index
  servo[2].write(138); // Middle
  servo[3].write(116); // Ring
  servo[4].write(149); // Pinky

  // Keyframe 101 @ 2.93s: Fingers [117, 142, 140, 118, 151] Arm [-, -, -]
  smoothMove(0, 117, 4); // Thumb
  smoothMove(1, 142, 4); // Index
  smoothMove(2, 140, 4); // Middle
  smoothMove(3, 118, 4); // Ring
  smoothMove(4, 151, 4); // Pinky

  // Keyframe 102 @ 2.94s: Fingers [118, 144, 140, 120, 153] Arm [-, -, -]
  delay(13);
  servo[0].write(118); // Thumb
  servo[1].write(144); // Index
  servo[2].write(140); // Middle
  servo[3].write(120); // Ring
  servo[4].write(153); // Pinky

  // Keyframe 103 @ 2.99s: Fingers [120, 147, 143, 122, 155] Arm [-, -, -]
  delay(44);
  servo[0].write(120); // Thumb
  servo[1].write(147); // Index
  servo[2].write(143); // Middle
  servo[3].write(122); // Ring
  servo[4].write(155); // Pinky

  // Keyframe 104 @ 3.00s: Fingers [122, 149, 143, 124, 157] Arm [-, -, -]
  delay(19);
  servo[0].write(122); // Thumb
  servo[1].write(149); // Index
  servo[2].write(143); // Middle
  servo[3].write(124); // Ring
  servo[4].write(157); // Pinky

  // Keyframe 105 @ 3.05s: Fingers [124, 151, 146, 127, 159] Arm [-, -, -]
  delay(48);
  servo[0].write(124); // Thumb
  servo[1].write(151); // Index
  servo[2].write(146); // Middle
  servo[3].write(127); // Ring
  servo[4].write(159); // Pinky

  // Keyframe 106 @ 3.13s: Fingers [126, 154, 148, 129, 162] Arm [-, -, -]
  smoothMove(0, 126, 3); // Thumb
  smoothMove(1, 154, 3); // Index
  smoothMove(2, 148, 3); // Middle
  smoothMove(3, 129, 3); // Ring
  smoothMove(4, 162, 3); // Pinky

  // Keyframe 107 @ 3.16s: Fingers [128, 154, 150, 129, 162] Arm [-, -, -]
  delay(24);
  servo[0].write(128); // Thumb
  servo[1].write(154); // Index
  servo[2].write(150); // Middle
  servo[3].write(129); // Ring
  servo[4].write(162); // Pinky

  // Keyframe 108 @ 3.19s: Fingers [129, 154, 152, 130, 163] Arm [-, -, -]
  delay(32);
  servo[0].write(129); // Thumb
  servo[1].write(154); // Index
  servo[2].write(152); // Middle
  servo[3].write(130); // Ring
  servo[4].write(163); // Pinky

  // Keyframe 109 @ 3.21s: Fingers [131, 153, 155, 130, 164] Arm [-, -, -]
  delay(24);
  servo[0].write(131); // Thumb
  servo[1].write(153); // Index
  servo[2].write(155); // Middle
  servo[3].write(130); // Ring
  servo[4].write(164); // Pinky

  // Keyframe 110 @ 3.24s: Fingers [133, 153, 158, 131, 164] Arm [-, -, -]
  delay(24);
  servo[0].write(133); // Thumb
  servo[1].write(153); // Index
  servo[2].write(158); // Middle
  servo[3].write(131); // Ring
  servo[4].write(164); // Pinky

  // Keyframe 111 @ 3.25s: Fingers [135, 152, 161, 132, 164] Arm [-, -, -]
  delay(16);
  servo[0].write(135); // Thumb
  servo[1].write(152); // Index
  servo[2].write(161); // Middle
  servo[3].write(132); // Ring
  servo[4].write(164); // Pinky

  // Keyframe 112 @ 3.27s: Fingers [138, 151, 163, 133, 164] Arm [-, -, -]
  delay(15);
  servo[0].write(138); // Thumb
  servo[1].write(151); // Index
  servo[2].write(163); // Middle
  servo[3].write(133); // Ring
  servo[4].write(164); // Pinky

  // Keyframe 113 @ 3.29s: Fingers [140, 150, 165, 133, 163] Arm [-, -, -]
  delay(16);
  servo[0].write(140); // Thumb
  servo[1].write(150); // Index
  servo[2].write(165); // Middle
  servo[3].write(133); // Ring
  servo[4].write(163); // Pinky

  // Keyframe 114 @ 3.32s: Fingers [143, 149, 168, 135, 162] Arm [-, -, -]
  delay(31);
  servo[0].write(143); // Thumb
  servo[1].write(149); // Index
  servo[2].write(168); // Middle
  servo[3].write(135); // Ring
  servo[4].write(162); // Pinky

  // Keyframe 115 @ 3.36s: Fingers [145, 146, 169, 136, 160] Arm [-, -, -]
  delay(45);
  servo[0].write(145); // Thumb
  servo[1].write(146); // Index
  servo[2].write(169); // Middle
  servo[3].write(136); // Ring
  servo[4].write(160); // Pinky

  // Keyframe 116 @ 3.38s: Fingers [148, 143, 170, 137, 157] Arm [-, -, -]
  delay(18);
  servo[0].write(148); // Thumb
  servo[1].write(143); // Index
  servo[2].write(170); // Middle
  servo[3].write(137); // Ring
  servo[4].write(157); // Pinky

  // Keyframe 117 @ 3.41s: Fingers [151, 141, 170, 139, 154] Arm [-, -, -]
  delay(32);
  servo[0].write(151); // Thumb
  servo[1].write(141); // Index
  servo[2].write(170); // Middle
  servo[3].write(139); // Ring
  servo[4].write(154); // Pinky

  // Keyframe 118 @ 3.44s: Fingers [154, 139, 170, 141, 151] Arm [-, -, -]
  delay(31);
  servo[0].write(154); // Thumb
  servo[1].write(139); // Index
  servo[2].write(170); // Middle
  servo[3].write(141); // Ring
  servo[4].write(151); // Pinky

  // Keyframe 119 @ 3.47s: Fingers [155, 137, 170, 142, 148] Arm [-, -, -]
  delay(24);
  servo[0].write(155); // Thumb
  servo[1].write(137); // Index
  servo[2].write(170); // Middle
  servo[3].write(142); // Ring
  servo[4].write(148); // Pinky

  // Keyframe 120 @ 3.49s: Fingers [158, 135, 168, 144, 145] Arm [-, -, -]
  delay(15);
  servo[0].write(158); // Thumb
  servo[1].write(135); // Index
  servo[2].write(168); // Middle
  servo[3].write(144); // Ring
  servo[4].write(145); // Pinky

  // Keyframe 121 @ 3.50s: Fingers [160, 134, 167, 147, 142] Arm [-, -, -]
  delay(16);
  servo[0].write(160); // Thumb
  servo[1].write(134); // Index
  servo[2].write(167); // Middle
  servo[3].write(147); // Ring
  servo[4].write(142); // Pinky

  // Keyframe 122 @ 3.52s: Fingers [161, 132, 165, 148, 139] Arm [-, -, -]
  delay(16);
  servo[0].write(161); // Thumb
  servo[1].write(132); // Index
  servo[2].write(165); // Middle
  servo[3].write(148); // Ring
  servo[4].write(139); // Pinky

  // Keyframe 123 @ 3.53s: Fingers [161, 131, 162, 148, 137] Arm [-, -, -]
  delay(14);
  servo[0].write(161); // Thumb
  servo[1].write(131); // Index
  servo[2].write(162); // Middle
  servo[3].write(148); // Ring
  servo[4].write(137); // Pinky

  // Keyframe 124 @ 3.56s: Fingers [162, 130, 159, 150, 134] Arm [-, -, -]
  delay(23);
  servo[0].write(162); // Thumb
  servo[1].write(130); // Index
  servo[2].write(159); // Middle
  servo[3].write(150); // Ring
  servo[4].write(134); // Pinky

  // Keyframe 125 @ 3.58s: Fingers [163, 130, 157, 152, 132] Arm [-, -, -]
  delay(24);
  servo[0].write(163); // Thumb
  servo[1].write(130); // Index
  servo[2].write(157); // Middle
  servo[3].write(152); // Ring
  servo[4].write(132); // Pinky

  // Keyframe 126 @ 3.59s: Fingers [163, 129, 154, 152, 130] Arm [-, -, -]
  delay(8);
  servo[0].write(163); // Thumb
  servo[1].write(129); // Index
  servo[2].write(154); // Middle
  servo[3].write(152); // Ring
  servo[4].write(130); // Pinky

  // Keyframe 127 @ 3.61s: Fingers [163, 130, 151, 154, 129] Arm [-, -, -]
  delay(19);
  servo[0].write(163); // Thumb
  servo[1].write(130); // Index
  servo[2].write(151); // Middle
  servo[3].write(154); // Ring
  servo[4].write(129); // Pinky

  // Keyframe 128 @ 3.61s: Fingers [162, 129, 148, 154, 127] Arm [-, -, -]
  delay(4);
  servo[0].write(162); // Thumb
  servo[1].write(129); // Index
  servo[2].write(148); // Middle
  servo[3].write(154); // Ring
  servo[4].write(127); // Pinky

  // Keyframe 129 @ 3.63s: Fingers [162, 130, 146, 155, 126] Arm [-, -, -]
  delay(15);
  servo[0].write(162); // Thumb
  servo[1].write(130); // Index
  servo[2].write(146); // Middle
  servo[3].write(155); // Ring
  servo[4].write(126); // Pinky

  // Keyframe 130 @ 3.65s: Fingers [160, 129, 143, 154, 124] Arm [-, -, -]
  delay(25);
  servo[0].write(160); // Thumb
  servo[1].write(129); // Index
  servo[2].write(143); // Middle
  servo[3].write(154); // Ring
  servo[4].write(124); // Pinky

  // Keyframe 131 @ 3.68s: Fingers [159, 129, 140, 155, 123] Arm [-, -, -]
  delay(22);
  servo[0].write(159); // Thumb
  servo[1].write(129); // Index
  servo[2].write(140); // Middle
  servo[3].write(155); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 132 @ 3.70s: Fingers [158, 131, 136, 156, 123] Arm [-, -, -]
  delay(24);
  servo[0].write(158); // Thumb
  servo[1].write(131); // Index
  servo[2].write(136); // Middle
  servo[3].write(156); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 133 @ 3.73s: Fingers [156, 132, 133, 156, 122] Arm [-, -, -]
  delay(26);
  servo[0].write(156); // Thumb
  servo[1].write(132); // Index
  servo[2].write(133); // Middle
  servo[3].write(156); // Ring
  servo[4].write(122); // Pinky

  // Keyframe 134 @ 3.74s: Fingers [155, 133, 131, 156, 123] Arm [-, -, -]
  delay(13);
  servo[0].write(155); // Thumb
  servo[1].write(133); // Index
  servo[2].write(131); // Middle
  servo[3].write(156); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 135 @ 3.76s: Fingers [153, 134, 128, 155, 123] Arm [-, -, -]
  delay(16);
  servo[0].write(153); // Thumb
  servo[1].write(134); // Index
  servo[2].write(128); // Middle
  servo[3].write(155); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 136 @ 3.77s: Fingers [151, 135, 125, 155, 123] Arm [-, -, -]
  delay(14);
  servo[0].write(151); // Thumb
  servo[1].write(135); // Index
  servo[2].write(125); // Middle
  servo[3].write(155); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 137 @ 3.80s: Fingers [148, 135, 122, 153, 122] Arm [-, -, -]
  delay(25);
  servo[0].write(148); // Thumb
  servo[1].write(135); // Index
  servo[2].write(122); // Middle
  servo[3].write(153); // Ring
  servo[4].write(122); // Pinky

  // Keyframe 138 @ 3.82s: Fingers [145, 136, 120, 152, 123] Arm [-, -, -]
  delay(23);
  servo[0].write(145); // Thumb
  servo[1].write(136); // Index
  servo[2].write(120); // Middle
  servo[3].write(152); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 139 @ 3.83s: Fingers [142, 137, 117, 150, 123] Arm [-, -, -]
  delay(8);
  servo[0].write(142); // Thumb
  servo[1].write(137); // Index
  servo[2].write(117); // Middle
  servo[3].write(150); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 140 @ 3.85s: Fingers [139, 137, 115, 149, 124] Arm [-, -, -]
  delay(24);
  servo[0].write(139); // Thumb
  servo[1].write(137); // Index
  servo[2].write(115); // Middle
  servo[3].write(149); // Ring
  servo[4].write(124); // Pinky

  // Keyframe 141 @ 3.87s: Fingers [137, 137, 114, 147, 123] Arm [-, -, -]
  delay(15);
  servo[0].write(137); // Thumb
  servo[1].write(137); // Index
  servo[2].write(114); // Middle
  servo[3].write(147); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 142 @ 3.89s: Fingers [135, 137, 112, 146, 123] Arm [-, -, -]
  delay(23);
  servo[0].write(135); // Thumb
  servo[1].write(137); // Index
  servo[2].write(112); // Middle
  servo[3].write(146); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 143 @ 3.92s: Fingers [133, 138, 111, 144, 125] Arm [-, -, -]
  delay(23);
  servo[0].write(133); // Thumb
  servo[1].write(138); // Index
  servo[2].write(111); // Middle
  servo[3].write(144); // Ring
  servo[4].write(125); // Pinky

  // Keyframe 144 @ 3.95s: Fingers [131, 138, 110, 142, 124] Arm [-, -, -]
  delay(33);
  servo[0].write(131); // Thumb
  servo[1].write(138); // Index
  servo[2].write(110); // Middle
  servo[3].write(142); // Ring
  servo[4].write(124); // Pinky

  // Keyframe 145 @ 3.98s: Fingers [128, 137, 108, 140, 124] Arm [-, -, -]
  delay(28);
  servo[0].write(128); // Thumb
  servo[1].write(137); // Index
  servo[2].write(108); // Middle
  servo[3].write(140); // Ring
  servo[4].write(124); // Pinky

  // Keyframe 146 @ 3.99s: Fingers [125, 138, 107, 138, 125] Arm [-, -, -]
  delay(11);
  servo[0].write(125); // Thumb
  servo[1].write(138); // Index
  servo[2].write(107); // Middle
  servo[3].write(138); // Ring
  servo[4].write(125); // Pinky

  // Keyframe 147 @ 4.01s: Fingers [123, 137, 106, 136, 125] Arm [-, -, -]
  delay(16);
  servo[0].write(123); // Thumb
  servo[1].write(137); // Index
  servo[2].write(106); // Middle
  servo[3].write(136); // Ring
  servo[4].write(125); // Pinky

  // Keyframe 148 @ 4.01s: Fingers [121, 137, 105, 134, 125] Arm [-, -, -]
  delay(7);
  servo[0].write(121); // Thumb
  servo[1].write(137); // Index
  servo[2].write(105); // Middle
  servo[3].write(134); // Ring
  servo[4].write(125); // Pinky

  // Keyframe 149 @ 4.02s: Fingers [119, 138, 105, 132, 126] Arm [-, -, -]
  delay(8);
  servo[0].write(119); // Thumb
  servo[1].write(138); // Index
  servo[2].write(105); // Middle
  servo[3].write(132); // Ring
  servo[4].write(126); // Pinky

  // Keyframe 150 @ 4.04s: Fingers [116, 136, 103, 130, 125] Arm [-, -, -]
  delay(16);
  servo[0].write(116); // Thumb
  servo[1].write(136); // Index
  servo[2].write(103); // Middle
  servo[3].write(130); // Ring
  servo[4].write(125); // Pinky

  // Keyframe 151 @ 4.05s: Fingers [112, 136, 103, 125, 127] Arm [-, -, -]
  delay(15);
  servo[0].write(112); // Thumb
  servo[1].write(136); // Index
  servo[2].write(103); // Middle
  servo[3].write(125); // Ring
  servo[4].write(127); // Pinky

  // Keyframe 152 @ 4.07s: Fingers [109, 136, 103, 123, 128] Arm [-, -, -]
  delay(16);
  servo[0].write(109); // Thumb
  servo[1].write(136); // Index
  servo[2].write(103); // Middle
  servo[3].write(123); // Ring
  servo[4].write(128); // Pinky

  // Keyframe 153 @ 4.08s: Fingers [107, 136, 104, 120, 129] Arm [-, -, -]
  delay(8);
  servo[0].write(107); // Thumb
  servo[1].write(136); // Index
  servo[2].write(104); // Middle
  servo[3].write(120); // Ring
  servo[4].write(129); // Pinky

  // Keyframe 154 @ 4.10s: Fingers [104, 135, 104, 116, 130] Arm [-, -, -]
  delay(24);
  servo[0].write(104); // Thumb
  servo[1].write(135); // Index
  servo[2].write(104); // Middle
  servo[3].write(116); // Ring
  servo[4].write(130); // Pinky

  // Keyframe 155 @ 4.10s: Fingers [101, 133, 105, 113, 130] Arm [-, -, -]
  delay(1);
  servo[0].write(101); // Thumb
  servo[1].write(133); // Index
  servo[2].write(105); // Middle
  servo[3].write(113); // Ring
  servo[4].write(130); // Pinky

  // Keyframe 156 @ 4.12s: Fingers [98, 131, 106, 108, 130] Arm [-, -, -]
  delay(14);
  servo[0].write(98); // Thumb
  servo[1].write(131); // Index
  servo[2].write(106); // Middle
  servo[3].write(108); // Ring
  servo[4].write(130); // Pinky

  // Keyframe 157 @ 4.13s: Fingers [96, 129, 107, 105, 130] Arm [-, -, -]
  delay(14);
  servo[0].write(96); // Thumb
  servo[1].write(129); // Index
  servo[2].write(107); // Middle
  servo[3].write(105); // Ring
  servo[4].write(130); // Pinky

  // Keyframe 158 @ 4.15s: Fingers [94, 127, 108, 102, 129] Arm [-, -, -]
  delay(16);
  servo[0].write(94); // Thumb
  servo[1].write(127); // Index
  servo[2].write(108); // Middle
  servo[3].write(102); // Ring
  servo[4].write(129); // Pinky

  // Keyframe 159 @ 4.17s: Fingers [93, 125, 110, 100, 129] Arm [-, -, -]
  delay(16);
  servo[0].write(93); // Thumb
  servo[1].write(125); // Index
  servo[2].write(110); // Middle
  servo[3].write(100); // Ring
  servo[4].write(129); // Pinky

  // Keyframe 160 @ 4.17s: Fingers [92, 122, 110, 97, 128] Arm [-, -, -]
  delay(7);
  servo[0].write(92); // Thumb
  servo[1].write(122); // Index
  servo[2].write(110); // Middle
  servo[3].write(97); // Ring
  servo[4].write(128); // Pinky

  // Keyframe 161 @ 4.19s: Fingers [92, 120, 112, 95, 127] Arm [-, -, -]
  delay(21);
  servo[0].write(92); // Thumb
  servo[1].write(120); // Index
  servo[2].write(112); // Middle
  servo[3].write(95); // Ring
  servo[4].write(127); // Pinky

  // Keyframe 162 @ 4.21s: Fingers [91, 118, 113, 93, 126] Arm [-, -, -]
  delay(18);
  servo[0].write(91); // Thumb
  servo[1].write(118); // Index
  servo[2].write(113); // Middle
  servo[3].write(93); // Ring
  servo[4].write(126); // Pinky

  // Keyframe 163 @ 4.23s: Fingers [91, 115, 114, 91, 125] Arm [-, -, -]
  delay(16);
  servo[0].write(91); // Thumb
  servo[1].write(115); // Index
  servo[2].write(114); // Middle
  servo[3].write(91); // Ring
  servo[4].write(125); // Pinky

  // Keyframe 164 @ 4.26s: Fingers [91, 113, 115, 90, 123] Arm [-, -, -]
  delay(33);
  servo[0].write(91); // Thumb
  servo[1].write(113); // Index
  servo[2].write(115); // Middle
  servo[3].write(90); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 165 @ 4.26s: Fingers [91, 110, 116, 88, 121] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(110); // Index
  servo[2].write(116); // Middle
  servo[3].write(88); // Ring
  servo[4].write(121); // Pinky

  // Keyframe 166 @ 4.28s: Fingers [91, 107, 117, 88, 119] Arm [-, -, -]
  delay(13);
  servo[0].write(91); // Thumb
  servo[1].write(107); // Index
  servo[2].write(117); // Middle
  servo[3].write(88); // Ring
  servo[4].write(119); // Pinky

  // Keyframe 167 @ 4.29s: Fingers [94, 103, 119, 87, 116] Arm [-, -, -]
  delay(17);
  servo[0].write(94); // Thumb
  servo[1].write(103); // Index
  servo[2].write(119); // Middle
  servo[3].write(87); // Ring
  servo[4].write(116); // Pinky

  // Keyframe 168 @ 4.29s: Fingers [96, 99, 120, 87, 113] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(99); // Index
  servo[2].write(120); // Middle
  servo[3].write(87); // Ring
  servo[4].write(113); // Pinky

  // Keyframe 169 @ 4.30s: Fingers [99, 95, 121, 88, 109] Arm [-, -, -]
  delay(7);
  servo[0].write(99); // Thumb
  servo[1].write(95); // Index
  servo[2].write(121); // Middle
  servo[3].write(88); // Ring
  servo[4].write(109); // Pinky

  // Keyframe 170 @ 4.31s: Fingers [100, 92, 120, 88, 106] Arm [-, -, -]
  delay(7);
  servo[0].write(100); // Thumb
  servo[1].write(92); // Index
  servo[2].write(120); // Middle
  servo[3].write(88); // Ring
  servo[4].write(106); // Pinky

  // Keyframe 171 @ 4.32s: Fingers [104, 88, 120, 91, 100] Arm [-, -, -]
  delay(13);
  servo[0].write(104); // Thumb
  servo[1].write(88); // Index
  servo[2].write(120); // Middle
  servo[3].write(91); // Ring
  servo[4].write(100); // Pinky

  // Keyframe 172 @ 4.33s: Fingers [107, 85, 118, 93, 95] Arm [-, -, -]
  delay(3);
  servo[0].write(107); // Thumb
  servo[1].write(85); // Index
  servo[2].write(118); // Middle
  servo[3].write(93); // Ring
  servo[4].write(95); // Pinky

  // Keyframe 173 @ 4.33s: Fingers [109, 83, 116, 95, 92] Arm [-, -, -]
  delay(7);
  servo[0].write(109); // Thumb
  servo[1].write(83); // Index
  servo[2].write(116); // Middle
  servo[3].write(95); // Ring
  servo[4].write(92); // Pinky

  // Keyframe 174 @ 4.34s: Fingers [110, 82, 115, 97, 89] Arm [-, -, -]
  delay(7);
  servo[0].write(110); // Thumb
  servo[1].write(82); // Index
  servo[2].write(115); // Middle
  servo[3].write(97); // Ring
  servo[4].write(89); // Pinky

  // Keyframe 175 @ 4.35s: Fingers [111, 81, 113, 98, 87] Arm [-, -, -]
  delay(12);
  servo[0].write(111); // Thumb
  servo[1].write(81); // Index
  servo[2].write(113); // Middle
  servo[3].write(98); // Ring
  servo[4].write(87); // Pinky

  // Keyframe 176 @ 4.36s: Fingers [113, 81, 110, 100, 85] Arm [-, -, -]
  delay(3);
  servo[0].write(113); // Thumb
  servo[1].write(81); // Index
  servo[2].write(110); // Middle
  servo[3].write(100); // Ring
  servo[4].write(85); // Pinky

  // Keyframe 177 @ 4.37s: Fingers [113, 80, 106, 102, 82] Arm [-, -, -]
  delay(15);
  servo[0].write(113); // Thumb
  servo[1].write(80); // Index
  servo[2].write(106); // Middle
  servo[3].write(102); // Ring
  servo[4].write(82); // Pinky

  // Keyframe 178 @ 4.39s: Fingers [113, 80, 104, 103, 80] Arm [-, -, -]
  delay(16);
  servo[0].write(113); // Thumb
  servo[1].write(80); // Index
  servo[2].write(104); // Middle
  servo[3].write(103); // Ring
  servo[4].write(80); // Pinky

  // Keyframe 179 @ 4.42s: Fingers [113, 80, 101, 104, 79] Arm [-, -, -]
  delay(32);
  servo[0].write(113); // Thumb
  servo[1].write(80); // Index
  servo[2].write(101); // Middle
  servo[3].write(104); // Ring
  servo[4].write(79); // Pinky

  // Keyframe 180 @ 4.45s: Fingers [114, 81, 98, 107, 78] Arm [-, -, -]
  delay(28);
  servo[0].write(114); // Thumb
  servo[1].write(81); // Index
  servo[2].write(98); // Middle
  servo[3].write(107); // Ring
  servo[4].write(78); // Pinky

  // Keyframe 181 @ 4.47s: Fingers [114, 83, 95, 109, 78] Arm [-, -, -]
  delay(18);
  servo[0].write(114); // Thumb
  servo[1].write(83); // Index
  servo[2].write(95); // Middle
  servo[3].write(109); // Ring
  servo[4].write(78); // Pinky

  // Keyframe 182 @ 4.49s: Fingers [113, 86, 92, 111, 78] Arm [-, -, -]
  delay(25);
  servo[0].write(113); // Thumb
  servo[1].write(86); // Index
  servo[2].write(92); // Middle
  servo[3].write(111); // Ring
  servo[4].write(78); // Pinky

  // Keyframe 183 @ 4.55s: Fingers [114, 88, 91, 112, 79] Arm [-, -, -]
  smoothMove(0, 114, 2); // Thumb
  smoothMove(1, 88, 2); // Index
  smoothMove(2, 91, 2); // Middle
  smoothMove(3, 112, 2); // Ring
  smoothMove(4, 79, 2); // Pinky

  // Keyframe 184 @ 4.56s: Fingers [114, 90, 91, 114, 81] Arm [-, -, -]
  delay(7);
  servo[0].write(114); // Thumb
  servo[1].write(90); // Index
  servo[2].write(91); // Middle
  servo[3].write(114); // Ring
  servo[4].write(81); // Pinky

  // Keyframe 185 @ 4.58s: Fingers [114, 95, 89, 116, 84] Arm [-, -, -]
  delay(18);
  servo[0].write(114); // Thumb
  servo[1].write(95); // Index
  servo[2].write(89); // Middle
  servo[3].write(116); // Ring
  servo[4].write(84); // Pinky

  // Keyframe 186 @ 4.58s: Fingers [113, 103, 88, 119, 90] Arm [-, -, -]
  delay(1);
  servo[0].write(113); // Thumb
  servo[1].write(103); // Index
  servo[2].write(88); // Middle
  servo[3].write(119); // Ring
  servo[4].write(90); // Pinky

  // Keyframe 187 @ 4.58s: Fingers [113, 108, 88, 121, 94] Arm [-, -, -]
  delay(4);
  servo[0].write(113); // Thumb
  servo[1].write(108); // Index
  servo[2].write(88); // Middle
  servo[3].write(121); // Ring
  servo[4].write(94); // Pinky

  // Keyframe 188 @ 4.59s: Fingers [110, 114, 88, 121, 101] Arm [-, -, -]
  delay(8);
  servo[0].write(110); // Thumb
  servo[1].write(114); // Index
  servo[2].write(88); // Middle
  servo[3].write(121); // Ring
  servo[4].write(101); // Pinky

  // Keyframe 189 @ 4.61s: Fingers [107, 121, 90, 120, 108] Arm [-, -, -]
  delay(17);
  servo[0].write(107); // Thumb
  servo[1].write(121); // Index
  servo[2].write(90); // Middle
  servo[3].write(120); // Ring
  servo[4].write(108); // Pinky

  // Keyframe 190 @ 4.61s: Fingers [106, 124, 92, 120, 113] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(124); // Index
  servo[2].write(92); // Middle
  servo[3].write(120); // Ring
  servo[4].write(113); // Pinky

  // Keyframe 191 @ 4.61s: Fingers [104, 128, 95, 118, 118] Arm [-, -, -]
  delay(6);
  servo[0].write(104); // Thumb
  servo[1].write(128); // Index
  servo[2].write(95); // Middle
  servo[3].write(118); // Ring
  servo[4].write(118); // Pinky

  // Keyframe 192 @ 4.64s: Fingers [103, 130, 97, 116, 122] Arm [-, -, -]
  delay(22);
  servo[0].write(103); // Thumb
  servo[1].write(130); // Index
  servo[2].write(97); // Middle
  servo[3].write(116); // Ring
  servo[4].write(122); // Pinky

  // Keyframe 193 @ 4.67s: Fingers [103, 132, 99, 117, 124] Arm [-, -, -]
  delay(34);
  servo[0].write(103); // Thumb
  servo[1].write(132); // Index
  servo[2].write(99); // Middle
  servo[3].write(117); // Ring
  servo[4].write(124); // Pinky

  // Keyframe 194 @ 4.69s: Fingers [106, 134, 102, 119, 127] Arm [-, -, -]
  delay(15);
  servo[0].write(106); // Thumb
  servo[1].write(134); // Index
  servo[2].write(102); // Middle
  servo[3].write(119); // Ring
  servo[4].write(127); // Pinky

  // Keyframe 195 @ 4.69s: Fingers [106, 136, 104, 119, 130] Arm [-, -, -]
  delay(8);
  servo[0].write(106); // Thumb
  servo[1].write(136); // Index
  servo[2].write(104); // Middle
  servo[3].write(119); // Ring
  servo[4].write(130); // Pinky

  // Keyframe 196 @ 4.70s: Fingers [106, 137, 107, 118, 132] Arm [-, -, -]
  delay(7);
  servo[0].write(106); // Thumb
  servo[1].write(137); // Index
  servo[2].write(107); // Middle
  servo[3].write(118); // Ring
  servo[4].write(132); // Pinky

  // Keyframe 197 @ 4.71s: Fingers [106, 138, 110, 117, 135] Arm [-, -, -]
  delay(7);
  servo[0].write(106); // Thumb
  servo[1].write(138); // Index
  servo[2].write(110); // Middle
  servo[3].write(117); // Ring
  servo[4].write(135); // Pinky

  // Keyframe 198 @ 4.73s: Fingers [106, 139, 113, 117, 138] Arm [-, -, -]
  delay(18);
  servo[0].write(106); // Thumb
  servo[1].write(139); // Index
  servo[2].write(113); // Middle
  servo[3].write(117); // Ring
  servo[4].write(138); // Pinky

  // Keyframe 199 @ 4.74s: Fingers [107, 140, 115, 117, 139] Arm [-, -, -]
  delay(12);
  servo[0].write(107); // Thumb
  servo[1].write(140); // Index
  servo[2].write(115); // Middle
  servo[3].write(117); // Ring
  servo[4].write(139); // Pinky

  // Keyframe 200 @ 4.77s: Fingers [109, 142, 117, 119, 141] Arm [-, -, -]
  delay(32);
  servo[0].write(109); // Thumb
  servo[1].write(142); // Index
  servo[2].write(117); // Middle
  servo[3].write(119); // Ring
  servo[4].write(141); // Pinky

  // Keyframe 201 @ 4.79s: Fingers [110, 144, 120, 120, 144] Arm [-, -, -]
  delay(16);
  servo[0].write(110); // Thumb
  servo[1].write(144); // Index
  servo[2].write(120); // Middle
  servo[3].write(120); // Ring
  servo[4].write(144); // Pinky

  // Keyframe 202 @ 4.80s: Fingers [112, 146, 123, 122, 146] Arm [-, -, -]
  delay(15);
  servo[0].write(112); // Thumb
  servo[1].write(146); // Index
  servo[2].write(123); // Middle
  servo[3].write(122); // Ring
  servo[4].write(146); // Pinky

  // Keyframe 203 @ 4.84s: Fingers [115, 148, 125, 124, 148] Arm [-, -, -]
  delay(31);
  servo[0].write(115); // Thumb
  servo[1].write(148); // Index
  servo[2].write(125); // Middle
  servo[3].write(124); // Ring
  servo[4].write(148); // Pinky

  // Keyframe 204 @ 4.86s: Fingers [115, 148, 128, 124, 150] Arm [-, -, -]
  delay(24);
  servo[0].write(115); // Thumb
  servo[1].write(148); // Index
  servo[2].write(128); // Middle
  servo[3].write(124); // Ring
  servo[4].write(150); // Pinky

  // Keyframe 205 @ 4.89s: Fingers [118, 151, 130, 126, 152] Arm [-, -, -]
  delay(32);
  servo[0].write(118); // Thumb
  servo[1].write(151); // Index
  servo[2].write(130); // Middle
  servo[3].write(126); // Ring
  servo[4].write(152); // Pinky

  // Keyframe 206 @ 4.93s: Fingers [120, 153, 132, 129, 154] Arm [-, -, -]
  delay(40);
  servo[0].write(120); // Thumb
  servo[1].write(153); // Index
  servo[2].write(132); // Middle
  servo[3].write(129); // Ring
  servo[4].write(154); // Pinky

  // Keyframe 207 @ 4.98s: Fingers [121, 155, 132, 131, 155] Arm [-, -, -]
  delay(47);
  servo[0].write(121); // Thumb
  servo[1].write(155); // Index
  servo[2].write(132); // Middle
  servo[3].write(131); // Ring
  servo[4].write(155); // Pinky

  // Keyframe 208 @ 5.02s: Fingers [123, 156, 132, 133, 156] Arm [-, -, -]
  delay(40);
  servo[0].write(123); // Thumb
  servo[1].write(156); // Index
  servo[2].write(132); // Middle
  servo[3].write(133); // Ring
  servo[4].write(156); // Pinky

  // Keyframe 209 @ 5.07s: Fingers [125, 158, 132, 136, 157] Arm [-, -, -]
  delay(48);
  servo[0].write(125); // Thumb
  servo[1].write(158); // Index
  servo[2].write(132); // Middle
  servo[3].write(136); // Ring
  servo[4].write(157); // Pinky

  // Keyframe 210 @ 5.09s: Fingers [127, 160, 133, 138, 157] Arm [-, -, -]
  delay(16);
  servo[0].write(127); // Thumb
  servo[1].write(160); // Index
  servo[2].write(133); // Middle
  servo[3].write(138); // Ring
  servo[4].write(157); // Pinky

  // Keyframe 211 @ 5.10s: Fingers [129, 161, 132, 141, 157] Arm [-, -, -]
  delay(14);
  servo[0].write(129); // Thumb
  servo[1].write(161); // Index
  servo[2].write(132); // Middle
  servo[3].write(141); // Ring
  servo[4].write(157); // Pinky

  // Keyframe 212 @ 5.10s: Fingers [131, 162, 132, 143, 157] Arm [-, -, -]
  delay(1);
  servo[0].write(131); // Thumb
  servo[1].write(162); // Index
  servo[2].write(132); // Middle
  servo[3].write(143); // Ring
  servo[4].write(157); // Pinky

  // Keyframe 213 @ 5.12s: Fingers [134, 163, 131, 147, 156] Arm [-, -, -]
  delay(15);
  servo[0].write(134); // Thumb
  servo[1].write(163); // Index
  servo[2].write(131); // Middle
  servo[3].write(147); // Ring
  servo[4].write(156); // Pinky

  // Keyframe 214 @ 5.13s: Fingers [136, 163, 130, 150, 155] Arm [-, -, -]
  delay(16);
  servo[0].write(136); // Thumb
  servo[1].write(163); // Index
  servo[2].write(130); // Middle
  servo[3].write(150); // Ring
  servo[4].write(155); // Pinky

  // Keyframe 215 @ 5.15s: Fingers [138, 163, 130, 152, 154] Arm [-, -, -]
  delay(16);
  servo[0].write(138); // Thumb
  servo[1].write(163); // Index
  servo[2].write(130); // Middle
  servo[3].write(152); // Ring
  servo[4].write(154); // Pinky

  // Keyframe 216 @ 5.18s: Fingers [140, 164, 131, 154, 154] Arm [-, -, -]
  delay(31);
  servo[0].write(140); // Thumb
  servo[1].write(164); // Index
  servo[2].write(131); // Middle
  servo[3].write(154); // Ring
  servo[4].write(154); // Pinky

  // Keyframe 217 @ 5.23s: Fingers [144, 163, 130, 157, 152] Arm [-, -, -]
  delay(47);
  servo[0].write(144); // Thumb
  servo[1].write(163); // Index
  servo[2].write(130); // Middle
  servo[3].write(157); // Ring
  servo[4].write(152); // Pinky

  // Keyframe 218 @ 5.25s: Fingers [148, 161, 130, 161, 148] Arm [-, -, -]
  delay(17);
  servo[0].write(148); // Thumb
  servo[1].write(161); // Index
  servo[2].write(130); // Middle
  servo[3].write(161); // Ring
  servo[4].write(148); // Pinky

  // Keyframe 219 @ 5.26s: Fingers [151, 159, 130, 162, 145] Arm [-, -, -]
  delay(14);
  servo[0].write(151); // Thumb
  servo[1].write(159); // Index
  servo[2].write(130); // Middle
  servo[3].write(162); // Ring
  servo[4].write(145); // Pinky

  // Keyframe 220 @ 5.28s: Fingers [155, 155, 131, 164, 141] Arm [-, -, -]
  delay(17);
  servo[0].write(155); // Thumb
  servo[1].write(155); // Index
  servo[2].write(131); // Middle
  servo[3].write(164); // Ring
  servo[4].write(141); // Pinky

  // Keyframe 221 @ 5.29s: Fingers [159, 150, 134, 166, 137] Arm [-, -, -]
  delay(15);
  servo[0].write(159); // Thumb
  servo[1].write(150); // Index
  servo[2].write(134); // Middle
  servo[3].write(166); // Ring
  servo[4].write(137); // Pinky

  // Keyframe 222 @ 5.32s: Fingers [161, 147, 136, 166, 135] Arm [-, -, -]
  delay(25);
  servo[0].write(161); // Thumb
  servo[1].write(147); // Index
  servo[2].write(136); // Middle
  servo[3].write(166); // Ring
  servo[4].write(135); // Pinky

  // Keyframe 223 @ 5.32s: Fingers [162, 144, 137, 165, 132] Arm [-, -, -]
  delay(7);
  servo[0].write(162); // Thumb
  servo[1].write(144); // Index
  servo[2].write(137); // Middle
  servo[3].write(165); // Ring
  servo[4].write(132); // Pinky

  // Keyframe 224 @ 5.33s: Fingers [164, 141, 140, 164, 131] Arm [-, -, -]
  delay(8);
  servo[0].write(164); // Thumb
  servo[1].write(141); // Index
  servo[2].write(140); // Middle
  servo[3].write(164); // Ring
  servo[4].write(131); // Pinky

  // Keyframe 225 @ 5.35s: Fingers [164, 137, 143, 162, 129] Arm [-, -, -]
  delay(17);
  servo[0].write(164); // Thumb
  servo[1].write(137); // Index
  servo[2].write(143); // Middle
  servo[3].write(162); // Ring
  servo[4].write(129); // Pinky

  // Keyframe 226 @ 5.38s: Fingers [164, 135, 145, 160, 128] Arm [-, -, -]
  delay(29);
  servo[0].write(164); // Thumb
  servo[1].write(135); // Index
  servo[2].write(145); // Middle
  servo[3].write(160); // Ring
  servo[4].write(128); // Pinky

  // Keyframe 227 @ 5.41s: Fingers [163, 132, 145, 157, 127] Arm [-, -, -]
  delay(34);
  servo[0].write(163); // Thumb
  servo[1].write(132); // Index
  servo[2].write(145); // Middle
  servo[3].write(157); // Ring
  servo[4].write(127); // Pinky

  // Keyframe 228 @ 5.43s: Fingers [161, 129, 146, 154, 126] Arm [-, -, -]
  delay(14);
  servo[0].write(161); // Thumb
  servo[1].write(129); // Index
  servo[2].write(146); // Middle
  servo[3].write(154); // Ring
  servo[4].write(126); // Pinky

  // Keyframe 229 @ 5.45s: Fingers [159, 126, 146, 151, 124] Arm [-, -, -]
  delay(16);
  servo[0].write(159); // Thumb
  servo[1].write(126); // Index
  servo[2].write(146); // Middle
  servo[3].write(151); // Ring
  servo[4].write(124); // Pinky

  // Keyframe 230 @ 5.45s: Fingers [158, 125, 146, 149, 123] Arm [-, -, -]
  delay(8);
  servo[0].write(158); // Thumb
  servo[1].write(125); // Index
  servo[2].write(146); // Middle
  servo[3].write(149); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 231 @ 5.46s: Fingers [156, 123, 146, 147, 123] Arm [-, -, -]
  delay(7);
  servo[0].write(156); // Thumb
  servo[1].write(123); // Index
  servo[2].write(146); // Middle
  servo[3].write(147); // Ring
  servo[4].write(123); // Pinky

  // Keyframe 232 @ 5.48s: Fingers [155, 122, 145, 145, 122] Arm [-, -, -]
  delay(17);
  servo[0].write(155); // Thumb
  servo[1].write(122); // Index
  servo[2].write(145); // Middle
  servo[3].write(145); // Ring
  servo[4].write(122); // Pinky

  // Keyframe 233 @ 5.49s: Fingers [152, 118, 144, 141, 119] Arm [-, -, -]
  delay(13);
  servo[0].write(152); // Thumb
  servo[1].write(118); // Index
  servo[2].write(144); // Middle
  servo[3].write(141); // Ring
  servo[4].write(119); // Pinky

  // Keyframe 234 @ 5.52s: Fingers [150, 117, 143, 139, 119] Arm [-, -, -]
  delay(25);
  servo[0].write(150); // Thumb
  servo[1].write(117); // Index
  servo[2].write(143); // Middle
  servo[3].write(139); // Ring
  servo[4].write(119); // Pinky

  // Keyframe 235 @ 5.52s: Fingers [147, 114, 143, 135, 118] Arm [-, -, -]
  servo[0].write(147); // Thumb
  servo[1].write(114); // Index
  servo[2].write(143); // Middle
  servo[3].write(135); // Ring
  servo[4].write(118); // Pinky

  // Keyframe 236 @ 5.52s: Fingers [144, 112, 143, 131, 117] Arm [-, -, -]
  delay(7);
  servo[0].write(144); // Thumb
  servo[1].write(112); // Index
  servo[2].write(143); // Middle
  servo[3].write(131); // Ring
  servo[4].write(117); // Pinky

  // Keyframe 237 @ 5.54s: Fingers [141, 111, 142, 128, 116] Arm [-, -, -]
  delay(15);
  servo[0].write(141); // Thumb
  servo[1].write(111); // Index
  servo[2].write(142); // Middle
  servo[3].write(128); // Ring
  servo[4].write(116); // Pinky

  // Keyframe 238 @ 5.56s: Fingers [139, 109, 141, 126, 115] Arm [-, -, -]
  delay(15);
  servo[0].write(139); // Thumb
  servo[1].write(109); // Index
  servo[2].write(141); // Middle
  servo[3].write(126); // Ring
  servo[4].write(115); // Pinky

  // Keyframe 239 @ 5.57s: Fingers [137, 107, 138, 124, 113] Arm [-, -, -]
  delay(17);
  servo[0].write(137); // Thumb
  servo[1].write(107); // Index
  servo[2].write(138); // Middle
  servo[3].write(124); // Ring
  servo[4].write(113); // Pinky

  // Keyframe 240 @ 5.58s: Fingers [135, 106, 138, 121, 112] Arm [-, -, -]
  delay(7);
  servo[0].write(135); // Thumb
  servo[1].write(106); // Index
  servo[2].write(138); // Middle
  servo[3].write(121); // Ring
  servo[4].write(112); // Pinky

  // Keyframe 241 @ 5.61s: Fingers [132, 103, 135, 119, 110] Arm [-, -, -]
  delay(24);
  servo[0].write(132); // Thumb
  servo[1].write(103); // Index
  servo[2].write(135); // Middle
  servo[3].write(119); // Ring
  servo[4].write(110); // Pinky

  // Keyframe 242 @ 5.61s: Fingers [130, 102, 135, 117, 110] Arm [-, -, -]
  delay(9);
  servo[0].write(130); // Thumb
  servo[1].write(102); // Index
  servo[2].write(135); // Middle
  servo[3].write(117); // Ring
  servo[4].write(110); // Pinky

  // Keyframe 243 @ 5.63s: Fingers [128, 101, 134, 114, 109] Arm [-, -, -]
  delay(14);
  servo[0].write(128); // Thumb
  servo[1].write(101); // Index
  servo[2].write(134); // Middle
  servo[3].write(114); // Ring
  servo[4].write(109); // Pinky

  // Keyframe 244 @ 5.66s: Fingers [125, 98, 131, 111, 106] Arm [-, -, -]
  delay(32);
  servo[0].write(125); // Thumb
  servo[1].write(98); // Index
  servo[2].write(131); // Middle
  servo[3].write(111); // Ring
  servo[4].write(106); // Pinky

  // Keyframe 245 @ 5.68s: Fingers [122, 95, 128, 108, 103] Arm [-, -, -]
  delay(14);
  servo[0].write(122); // Thumb
  servo[1].write(95); // Index
  servo[2].write(128); // Middle
  servo[3].write(108); // Ring
  servo[4].write(103); // Pinky

  // Keyframe 246 @ 5.70s: Fingers [120, 92, 125, 107, 100] Arm [-, -, -]
  delay(23);
  servo[0].write(120); // Thumb
  servo[1].write(92); // Index
  servo[2].write(125); // Middle
  servo[3].write(107); // Ring
  servo[4].write(100); // Pinky

  // Keyframe 247 @ 5.73s: Fingers [118, 90, 122, 105, 97] Arm [-, -, -]
  delay(27);
  servo[0].write(118); // Thumb
  servo[1].write(90); // Index
  servo[2].write(122); // Middle
  servo[3].write(105); // Ring
  servo[4].write(97); // Pinky

  // Keyframe 248 @ 5.73s: Fingers [117, 88, 120, 104, 95] Arm [-, -, -]
  delay(6);
  servo[0].write(117); // Thumb
  servo[1].write(88); // Index
  servo[2].write(120); // Middle
  servo[3].write(104); // Ring
  servo[4].write(95); // Pinky

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
