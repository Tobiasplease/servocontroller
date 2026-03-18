/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2025-12-04 21:20:27
 * Layers: 3
 * Original Frames Recorded: 1885
 * Loop Duration: 7.22s
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
unsigned long loopDuration = 7216; // milliseconds

// Layer data structures

// Layer 1: Layer_1 (cursor mode) - 65 keyframes
const int layer1_count = 65;
const unsigned long layer1_times[] PROGMEM = {23, 133, 235, 337, 443, 548, 650, 755, 860, 960, 1068, 1171, 1291, 1739, 1844, 1948, 2051, 2156, 2258, 2365, 2468, 2571, 2671, 2772, 2876, 2980, 3083, 3188, 3289, 3395, 3500, 3603, 3708, 3811, 3913, 4019, 4124, 4225, 4332, 4437, 4541, 4643, 4787, 4899, 5004, 5115, 5220, 5323, 5428, 5532, 5634, 5736, 5837, 5940, 6040, 6147, 6252, 6357, 6460, 6563, 6664, 6765, 6882, 7043, 7192};
const int layer1_servo0[] PROGMEM = {46, 51, 96, 115, 135, 136, 125, 101, 77, 71, 69, 72, 79, 32, 23, 18, 12, 19, 34, 51, 53, 63, 95, 127, 166, 177, 160, 142, 128, 116, 110, 110, 110, 103, 85, 70, 49, 37, 31, 32, 34, 40, 44, 51, 56, 65, 73, 80, 91, 98, 97, 89, 72, 52, 28, 25, 34, 43, 61, 74, 91, 99, 105, 109, 111};
const int layer1_servo1[] PROGMEM = {108, 112, 126, 125, 108, 77, 62, 41, 26, 19, 13, 11, 15, 88, 86, 81, 63, 47, 38, 46, 73, 112, 158, 175, 166, 131, 99, 78, 65, 54, 47, 47, 61, 81, 98, 106, 107, 100, 89, 85, 82, 86, 92, 106, 116, 128, 136, 142, 145, 139, 133, 123, 112, 105, 91, 88, 95, 103, 123, 138, 153, 159, 162, 162, 162};
const int layer1_servo2[] PROGMEM = {95, 93, 70, 63, 50, 52, 56, 63, 65, 57, 43, 29, 10, 58, 77, 86, 101, 104, 101, 109, 134, 153, 153, 133, 103, 87, 82, 79, 74, 68, 53, 37, 21, 21, 36, 53, 82, 104, 116, 120, 123, 130, 134, 138, 138, 136, 133, 127, 111, 90, 81, 70, 62, 70, 85, 99, 113, 123, 135, 140, 138, 136, 134, 128, 125};
const int layer1_servo3[] PROGMEM = {33, 32, 40, 52, 77, 110, 119, 123, 115, 108, 99, 90, 74, 2, 14, 23, 49, 76, 98, 114, 114, 104, 90, 85, 102, 133, 143, 142, 137, 130, 116, 99, 71, 43, 23, 17, 24, 40, 59, 67, 75, 84, 86, 82, 79, 73, 69, 65, 57, 49, 44, 36, 22, 17, 22, 37, 53, 63, 73, 76, 76, 77, 77, 75, 73};
const int layer1_servo4[] PROGMEM = {46, 51, 96, 115, 135, 136, 125, 101, 77, 71, 69, 72, 79, 32, 23, 18, 12, 19, 34, 51, 53, 63, 95, 127, 166, 177, 160, 142, 128, 116, 110, 110, 110, 103, 85, 70, 49, 37, 31, 32, 34, 40, 44, 51, 56, 65, 73, 80, 91, 98, 97, 89, 72, 52, 28, 25, 34, 43, 61, 74, 91, 99, 105, 109, 111};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 28 keyframes
const int layer2_count = 28;
const unsigned long layer2_times[] PROGMEM = {6, 192, 299, 417, 790, 1055, 1215, 1366, 1560, 1808, 2057, 2200, 2313, 2492, 2992, 3112, 3280, 3423, 3545, 3704, 4000, 4071, 4168, 4294, 4560, 5162, 5214, 5824};
const int layer2_servo6[] PROGMEM = {79, 76, 73, 70, 67, 70, 73, 76, 79, 82, 79, 76, 73, 70, 73, 76, 79, 82, 85, 88, 85, 82, 79, 76, 73, 76, 79, 81};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 65 keyframes
const int layer3_count = 65;
const unsigned long layer3_times[] PROGMEM = {9, 59, 116, 172, 273, 325, 392, 551, 661, 716, 767, 819, 875, 930, 988, 1041, 1098, 1148, 1203, 1259, 1317, 1367, 1423, 1481, 1537, 1595, 1877, 1927, 2030, 2080, 2140, 2195, 2253, 2306, 2360, 2414, 2471, 2531, 2596, 2820, 2873, 2927, 2982, 3040, 3093, 3156, 3220, 3276, 3328, 3429, 3483, 3541, 3668, 3877, 3929, 3980, 4036, 4090, 4148, 4200, 4285, 4338, 4419, 4513, 5070};
const int layer3_servo7[] PROGMEM = {110, 99, 90, 85, 82, 79, 74, 71, 74, 82, 85, 89, 96, 102, 108, 113, 117, 120, 125, 132, 136, 139, 143, 147, 155, 158, 155, 147, 144, 140, 134, 130, 126, 122, 116, 113, 109, 106, 103, 106, 113, 118, 121, 127, 131, 134, 138, 141, 145, 148, 151, 154, 158, 155, 150, 146, 139, 134, 131, 128, 124, 118, 115, 112, 111};
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

  // Update layer 1 with interpolation
  if(layer1_index < layer1_count - 1) {
    unsigned long currentTime = pgm_read_dword(&layer1_times[layer1_index]);
    unsigned long nextTime = pgm_read_dword(&layer1_times[layer1_index + 1]);
    
    // Move to next keyframe if we've passed it
    if(elapsed >= nextTime) {
      layer1_index++;
    }
    
    // Interpolate between current and next keyframe
    if(layer1_index < layer1_count - 1 && elapsed >= currentTime) {
      currentTime = pgm_read_dword(&layer1_times[layer1_index]);
      nextTime = pgm_read_dword(&layer1_times[layer1_index + 1]);
      
      // Calculate interpolation factor (0.0 to 1.0)
      float factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
      factor = constrain(factor, 0.0, 1.0);
      
      // Interpolate Thumb
      int curr0 = pgm_read_word(&layer1_servo0[layer1_index]);
      int next0 = pgm_read_word(&layer1_servo0[layer1_index + 1]);
      if(curr0 != -1 && next0 != -1) {
        int interpolated = curr0 + (int)((next0 - curr0) * factor);
        servo[0].write(interpolated);
      } else if(curr0 != -1) {
        servo[0].write(curr0);
      }
      // Interpolate Index
      int curr1 = pgm_read_word(&layer1_servo1[layer1_index]);
      int next1 = pgm_read_word(&layer1_servo1[layer1_index + 1]);
      if(curr1 != -1 && next1 != -1) {
        int interpolated = curr1 + (int)((next1 - curr1) * factor);
        servo[1].write(interpolated);
      } else if(curr1 != -1) {
        servo[1].write(curr1);
      }
      // Interpolate Middle
      int curr2 = pgm_read_word(&layer1_servo2[layer1_index]);
      int next2 = pgm_read_word(&layer1_servo2[layer1_index + 1]);
      if(curr2 != -1 && next2 != -1) {
        int interpolated = curr2 + (int)((next2 - curr2) * factor);
        servo[2].write(interpolated);
      } else if(curr2 != -1) {
        servo[2].write(curr2);
      }
      // Interpolate Ring
      int curr3 = pgm_read_word(&layer1_servo3[layer1_index]);
      int next3 = pgm_read_word(&layer1_servo3[layer1_index + 1]);
      if(curr3 != -1 && next3 != -1) {
        int interpolated = curr3 + (int)((next3 - curr3) * factor);
        servo[3].write(interpolated);
      } else if(curr3 != -1) {
        servo[3].write(curr3);
      }
      // Interpolate Pinky
      int curr4 = pgm_read_word(&layer1_servo4[layer1_index]);
      int next4 = pgm_read_word(&layer1_servo4[layer1_index + 1]);
      if(curr4 != -1 && next4 != -1) {
        int interpolated = curr4 + (int)((next4 - curr4) * factor);
        servo[4].write(interpolated);
      } else if(curr4 != -1) {
        servo[4].write(curr4);
      }
    }
  }

  // Update layer 2 with interpolation
  if(layer2_index < layer2_count - 1) {
    unsigned long currentTime = pgm_read_dword(&layer2_times[layer2_index]);
    unsigned long nextTime = pgm_read_dword(&layer2_times[layer2_index + 1]);
    
    // Move to next keyframe if we've passed it
    if(elapsed >= nextTime) {
      layer2_index++;
    }
    
    // Interpolate between current and next keyframe
    if(layer2_index < layer2_count - 1 && elapsed >= currentTime) {
      currentTime = pgm_read_dword(&layer2_times[layer2_index]);
      nextTime = pgm_read_dword(&layer2_times[layer2_index + 1]);
      
      // Calculate interpolation factor (0.0 to 1.0)
      float factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
      factor = constrain(factor, 0.0, 1.0);
      
      // Interpolate Elbow
      int curr6 = pgm_read_word(&layer2_servo6[layer2_index]);
      int next6 = pgm_read_word(&layer2_servo6[layer2_index + 1]);
      if(curr6 != -1 && next6 != -1) {
        int interpolated = curr6 + (int)((next6 - curr6) * factor);
        servo[6].write(interpolated);
      } else if(curr6 != -1) {
        servo[6].write(curr6);
      }
    }
  }

  // Update layer 3 with interpolation
  if(layer3_index < layer3_count - 1) {
    unsigned long currentTime = pgm_read_dword(&layer3_times[layer3_index]);
    unsigned long nextTime = pgm_read_dword(&layer3_times[layer3_index + 1]);
    
    // Move to next keyframe if we've passed it
    if(elapsed >= nextTime) {
      layer3_index++;
    }
    
    // Interpolate between current and next keyframe
    if(layer3_index < layer3_count - 1 && elapsed >= currentTime) {
      currentTime = pgm_read_dword(&layer3_times[layer3_index]);
      nextTime = pgm_read_dword(&layer3_times[layer3_index + 1]);
      
      // Calculate interpolation factor (0.0 to 1.0)
      float factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
      factor = constrain(factor, 0.0, 1.0);
      
      // Interpolate Wrist
      int curr7 = pgm_read_word(&layer3_servo7[layer3_index]);
      int next7 = pgm_read_word(&layer3_servo7[layer3_index + 1]);
      if(curr7 != -1 && next7 != -1) {
        int interpolated = curr7 + (int)((next7 - curr7) * factor);
        servo[7].write(interpolated);
      } else if(curr7 != -1) {
        servo[7].write(curr7);
      }
    }
  }

  delay(5); // 200Hz update rate for smooth interpolation
}
