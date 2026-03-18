/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2025-12-04 21:15:11
 * Layers: 3
 * Original Frames Recorded: 1163
 * Loop Duration: 4.52s
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

// Servo objects
Servo servo[8];
int servoPins[8] = {12, 11, 10, 9, 8, 7, 6, 5};

// Timing
unsigned long loopStartTime;
unsigned long loopDuration = 4517; // milliseconds

// Layer data structures

// Layer 1: Layer_1 (cursor mode) - 18 keyframes
const int layer1_count = 18;
const unsigned long layer1_times[] PROGMEM = {2, 284, 484, 692, 892, 1100, 1308, 1617, 1831, 2183, 2388, 2593, 2796, 3001, 3204, 3411, 3613, 4464};
const int layer1_servo0[] PROGMEM = {40, 40, 41, 51, 82, 126, 147, 157, 167, 169, 159, 135, 107, 82, 65, 46, 32, 24};
const int layer1_servo1[] PROGMEM = {48, 55, 62, 76, 106, 143, 157, 161, 159, 149, 135, 109, 82, 57, 50, 54, 51, 47};
const int layer1_servo2[] PROGMEM = {24, 35, 47, 70, 100, 123, 133, 135, 135, 133, 127, 109, 85, 56, 29, 30, 34, 38};
const int layer1_servo3[] PROGMEM = {16, 20, 26, 45, 75, 107, 123, 132, 143, 153, 150, 134, 110, 81, 44, 22, 15, 14};
const int layer1_servo4[] PROGMEM = {40, 40, 41, 51, 82, 126, 147, 157, 167, 169, 159, 135, 107, 82, 65, 46, 32, 24};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 7 keyframes
const int layer2_count = 7;
const unsigned long layer2_times[] PROGMEM = {0, 478, 846, 1288, 2056, 2400, 4486};
const int layer2_servo6[] PROGMEM = {74, 69, 65, 61, 65, 69, 67};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 34 keyframes
const int layer3_count = 34;
const unsigned long layer3_times[] PROGMEM = {5, 206, 687, 782, 881, 969, 1069, 1198, 1308, 1382, 1463, 1582, 1735, 1870, 1990, 2148, 2263, 2350, 2511, 2624, 2766, 3199, 3263, 3361, 3475, 3603, 3742, 3854, 3950, 4046, 4159, 4270, 4392, 4487};
const int layer3_servo7[] PROGMEM = {140, 145, 140, 136, 132, 128, 124, 120, 116, 112, 108, 103, 99, 95, 91, 87, 83, 79, 75, 70, 66, 70, 75, 79, 83, 87, 91, 95, 99, 103, 108, 112, 116, 118};
int layer3_index = 0;

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
  
  // Loop the sequence
  if(elapsed >= loopDuration) {
    loopStartTime = millis();
    elapsed = 0;
    layer1_index = 0;
    layer2_index = 0;
    layer3_index = 0;
  }

  // Update layer 1
  if(layer1_index < layer1_count - 1) {
    if(elapsed >= pgm_read_dword(&layer1_times[layer1_index + 1])) {
      layer1_index++;
      // Apply positions for this keyframe
      int pos0 = pgm_read_word(&layer1_servo0[layer1_index]);
      if(pos0 != -1) servo[0].write(pos0); // Thumb
      int pos1 = pgm_read_word(&layer1_servo1[layer1_index]);
      if(pos1 != -1) servo[1].write(pos1); // Index
      int pos2 = pgm_read_word(&layer1_servo2[layer1_index]);
      if(pos2 != -1) servo[2].write(pos2); // Middle
      int pos3 = pgm_read_word(&layer1_servo3[layer1_index]);
      if(pos3 != -1) servo[3].write(pos3); // Ring
      int pos4 = pgm_read_word(&layer1_servo4[layer1_index]);
      if(pos4 != -1) servo[4].write(pos4); // Pinky
    }
  }

  // Update layer 2
  if(layer2_index < layer2_count - 1) {
    if(elapsed >= pgm_read_dword(&layer2_times[layer2_index + 1])) {
      layer2_index++;
      // Apply positions for this keyframe
      int pos6 = pgm_read_word(&layer2_servo6[layer2_index]);
      if(pos6 != -1) servo[6].write(pos6); // Elbow
    }
  }

  // Update layer 3
  if(layer3_index < layer3_count - 1) {
    if(elapsed >= pgm_read_dword(&layer3_times[layer3_index + 1])) {
      layer3_index++;
      // Apply positions for this keyframe
      int pos7 = pgm_read_word(&layer3_servo7[layer3_index]);
      if(pos7 != -1) servo[7].write(pos7); // Wrist
    }
  }

  delay(10); // 100Hz update rate
}
