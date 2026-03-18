/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2025-12-30 20:26:07
 * Layers: 4
 * Original Frames Recorded: 5511
 * Loop Duration: 17.93s (recorded) / 11.95s (at 1.5x speed)
 * Playback Speed: 1.5x
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
unsigned long loopDuration = 11953; // milliseconds (adjusted for 1.5x speed)

// Layer data structures

// Layer 1: Layer_1 (manual mode) - 56 keyframes
const int layer1_count = 56;
const unsigned long layer1_times[] PROGMEM = {10, 866, 1093, 1336, 1462, 1578, 1876, 2110, 2262, 2496, 2705, 2854, 3053, 3321, 3529, 3644, 3773, 4030, 4251, 4518, 4729, 4838, 4968, 5188, 5467, 5746, 5946, 6222, 7004, 7180, 7332, 7513, 7680, 7833, 8012, 8192, 8387, 8513, 8661, 8915, 9062, 9177, 9391, 9525, 9645, 9823, 9950, 10121, 10265, 10390, 10563, 10725, 10936, 11135, 11552, 11943};
const int layer1_servo5[] PROGMEM = {180, 176, 173, 170, 167, 164, 161, 158, 155, 152, 149, 146, 142, 139, 136, 133, 130, 127, 124, 121, 118, 115, 112, 109, 105, 102, 99, 96, 99, 102, 105, 109, 112, 115, 118, 121, 124, 127, 130, 133, 136, 139, 142, 146, 149, 152, 155, 158, 161, 164, 167, 170, 173, 176, 180, 180};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 19 keyframes
const int layer2_count = 19;
const unsigned long layer2_times[] PROGMEM = {0, 304, 1711, 2773, 2948, 3452, 3686, 4180, 7260, 7934, 8066, 8114, 8170, 8213, 8275, 9948, 10195, 10419, 11940};
const int layer2_servo6[] PROGMEM = {93, 96, 99, 102, 105, 109, 112, 115, 112, 109, 105, 102, 99, 96, 93, 90, 87, 84, 85};
int layer2_index = 0;

// Layer 3: Layer_3 (cursor mode) - 161 keyframes
const int layer3_count = 161;
const unsigned long layer3_times[] PROGMEM = {3, 168, 240, 309, 378, 445, 513, 583, 651, 721, 789, 856, 929, 1000, 1070, 1141, 1220, 1289, 1432, 1599, 1673, 1742, 1811, 1885, 1965, 2034, 2102, 2182, 2250, 2320, 2395, 2464, 2562, 2630, 2699, 2776, 2844, 2914, 2985, 3065, 3147, 3225, 3294, 3360, 3433, 3503, 3571, 3646, 3715, 3784, 3858, 3932, 4001, 4068, 4139, 4209, 4280, 4351, 4418, 4490, 4560, 4630, 4698, 4768, 4837, 4907, 4975, 5042, 5109, 5176, 5257, 5335, 5406, 5478, 5550, 5622, 5692, 5770, 5839, 5907, 5982, 6050, 6164, 6250, 6323, 6394, 6464, 6534, 6601, 6670, 6740, 6807, 6878, 6948, 7049, 7119, 7193, 7261, 7336, 7403, 7475, 7543, 7613, 7684, 7755, 7825, 7893, 7973, 8043, 8125, 8200, 8275, 8355, 8426, 8499, 8618, 8684, 8754, 8824, 8892, 8966, 9036, 9104, 9175, 9243, 9312, 9385, 9455, 9525, 9591, 9674, 9777, 9853, 9928, 10001, 10071, 10139, 10206, 10281, 10349, 10417, 10490, 10566, 10634, 10708, 10778, 10848, 10930, 11004, 11079, 11147, 11215, 11300, 11419, 11498, 11590, 11666, 11734, 11803, 11872, 11942};
const int layer3_servo0[] PROGMEM = {68, 73, 89, 96, 104, 109, 114, 122, 128, 115, 101, 95, 89, 79, 73, 74, 77, 81, 86, 89, 87, 81, 73, 67, 61, 56, 47, 44, 46, 49, 53, 52, 47, 39, 29, 14, 14, 16, 20, 24, 30, 36, 41, 51, 57, 62, 67, 75, 85, 91, 99, 106, 114, 115, 113, 112, 115, 121, 127, 135, 139, 127, 112, 101, 94, 89, 85, 81, 76, 70, 64, 61, 52, 48, 44, 42, 45, 48, 52, 59, 66, 72, 78, 83, 90, 98, 106, 115, 125, 134, 136, 127, 118, 113, 119, 128, 132, 133, 133, 130, 124, 114, 108, 97, 87, 77, 60, 55, 44, 36, 22, 17, 21, 36, 56, 59, 60, 60, 59, 59, 60, 67, 73, 78, 83, 89, 100, 107, 114, 121, 126, 131, 137, 147, 155, 162, 166, 168, 162, 149, 140, 129, 121, 112, 105, 98, 84, 76, 71, 66, 66, 66, 69, 74, 75, 75, 73, 70, 68, 66, 67};
const int layer3_servo1[] PROGMEM = {33, 39, 55, 62, 70, 76, 80, 87, 95, 93, 86, 86, 84, 81, 77, 71, 65, 60, 55, 56, 63, 73, 78, 78, 73, 67, 60, 54, 46, 38, 27, 18, 16, 18, 24, 39, 44, 49, 54, 58, 63, 69, 73, 84, 89, 92, 93, 93, 88, 87, 83, 79, 79, 89, 99, 111, 121, 128, 130, 121, 105, 98, 88, 79, 72, 67, 59, 47, 42, 35, 30, 27, 34, 45, 61, 67, 72, 78, 85, 93, 100, 106, 110, 113, 113, 112, 110, 109, 104, 100, 107, 123, 138, 148, 144, 134, 124, 115, 110, 105, 97, 91, 86, 81, 77, 75, 69, 66, 64, 59, 55, 45, 43, 33, 23, 26, 35, 45, 54, 63, 70, 84, 94, 104, 111, 121, 133, 140, 147, 154, 158, 159, 159, 156, 150, 143, 137, 133, 131, 135, 137, 140, 140, 137, 134, 128, 113, 104, 99, 90, 70, 45, 39, 39, 42, 47, 52, 59, 68, 78, 84};
const int layer3_servo2[] PROGMEM = {67, 72, 87, 94, 102, 108, 113, 121, 130, 119, 106, 100, 94, 85, 79, 79, 82, 85, 88, 87, 83, 76, 68, 62, 56, 51, 42, 39, 41, 44, 49, 51, 49, 43, 34, 18, 17, 18, 22, 27, 32, 38, 43, 54, 59, 65, 71, 80, 90, 96, 103, 109, 114, 112, 108, 107, 109, 116, 121, 130, 138, 130, 115, 105, 98, 93, 89, 82, 77, 70, 64, 60, 48, 43, 40, 39, 42, 46, 51, 58, 65, 71, 76, 81, 86, 93, 101, 110, 121, 131, 139, 133, 123, 115, 116, 123, 126, 128, 129, 126, 120, 110, 104, 92, 82, 72, 55, 50, 39, 32, 21, 21, 26, 41, 57, 57, 56, 55, 53, 54, 55, 63, 69, 75, 81, 87, 99, 106, 113, 120, 124, 129, 133, 141, 149, 157, 163, 166, 164, 154, 145, 134, 126, 116, 109, 102, 87, 80, 74, 70, 72, 70, 71, 73, 73, 71, 68, 65, 63, 61, 62};
const int layer3_servo3[] PROGMEM = {35, 41, 58, 65, 73, 78, 82, 88, 95, 90, 82, 81, 79, 76, 71, 66, 60, 56, 54, 59, 67, 79, 84, 83, 77, 72, 64, 59, 52, 44, 31, 20, 15, 14, 19, 34, 40, 46, 51, 55, 61, 66, 70, 80, 86, 88, 89, 87, 83, 81, 79, 77, 80, 93, 104, 116, 126, 133, 135, 126, 107, 96, 85, 76, 69, 64, 56, 47, 42, 36, 30, 29, 39, 51, 65, 70, 75, 80, 85, 93, 100, 106, 111, 115, 116, 117, 115, 114, 109, 103, 105, 118, 133, 146, 147, 139, 129, 120, 115, 109, 102, 96, 91, 86, 82, 80, 73, 71, 67, 62, 56, 41, 38, 28, 22, 28, 39, 50, 59, 68, 75, 88, 97, 107, 114, 122, 133, 140, 148, 154, 159, 162, 162, 161, 156, 148, 140, 135, 130, 131, 132, 135, 135, 133, 130, 124, 109, 100, 95, 85, 65, 41, 38, 40, 45, 51, 57, 65, 74, 83, 88};
const int layer3_servo4[] PROGMEM = {64, 69, 84, 90, 99, 104, 110, 119, 129, 122, 110, 104, 99, 90, 84, 84, 86, 88, 89, 84, 78, 70, 63, 58, 52, 47, 38, 35, 36, 39, 44, 48, 50, 46, 39, 23, 21, 22, 25, 30, 36, 41, 47, 58, 63, 70, 76, 86, 95, 101, 107, 111, 112, 107, 102, 101, 105, 111, 116, 124, 135, 131, 118, 108, 101, 96, 90, 81, 75, 68, 63, 57, 42, 38, 36, 37, 41, 45, 51, 59, 67, 72, 76, 80, 84, 89, 96, 104, 115, 128, 140, 137, 128, 118, 114, 118, 121, 122, 123, 121, 115, 105, 98, 87, 77, 67, 51, 46, 36, 30, 21, 25, 31, 46, 57, 54, 51, 50, 48, 49, 51, 59, 66, 73, 79, 87, 99, 106, 113, 120, 124, 127, 130, 137, 144, 151, 159, 164, 165, 158, 150, 139, 131, 121, 114, 106, 92, 84, 79, 75, 77, 73, 72, 71, 69, 66, 63, 60, 58, 57, 59};
int layer3_index = 0;

// Layer 4: Layer_4 (manual mode) - 165 keyframes
const int layer4_count = 165;
const unsigned long layer4_times[] PROGMEM = {0, 35, 73, 107, 142, 179, 217, 251, 309, 377, 480, 518, 558, 602, 636, 673, 711, 748, 782, 824, 882, 918, 954, 994, 1030, 1067, 1102, 1144, 1185, 1227, 1276, 1328, 1368, 1428, 1477, 1591, 1668, 2001, 2072, 2130, 2178, 2221, 2271, 2312, 2363, 2432, 2468, 2538, 2736, 2786, 2847, 2895, 2933, 2972, 3091, 3194, 3286, 3448, 3537, 3587, 3629, 3665, 3702, 3743, 3780, 3818, 3855, 3889, 3933, 3985, 4025, 4088, 4307, 4441, 4567, 4686, 4749, 4922, 5111, 5228, 5755, 5815, 5861, 5904, 6061, 6232, 6314, 6383, 6476, 6532, 6579, 6679, 6804, 6956, 7116, 7172, 7258, 7374, 7426, 7554, 7752, 7789, 7829, 7866, 7902, 7938, 7988, 8037, 8086, 8144, 8180, 8262, 8415, 8454, 8490, 8527, 8576, 8613, 8651, 8688, 8743, 8842, 8892, 8989, 9029, 9071, 9105, 9155, 9208, 9245, 9279, 9342, 9444, 9478, 9532, 9574, 9617, 9687, 9789, 9847, 9905, 9979, 10022, 10057, 10091, 10126, 10174, 10229, 10297, 10501, 10699, 10766, 10806, 10868, 10940, 11097, 11236, 11604, 11638, 11673, 11719, 11791, 11833, 11888, 11947};
const int layer4_servo7[] PROGMEM = {86, 90, 93, 97, 101, 105, 110, 117, 120, 123, 118, 114, 110, 106, 98, 95, 92, 88, 84, 81, 78, 75, 72, 67, 61, 57, 52, 49, 45, 42, 39, 36, 32, 29, 26, 23, 20, 23, 26, 29, 32, 39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 73, 76, 79, 82, 85, 82, 79, 76, 73, 69, 66, 63, 60, 57, 54, 50, 47, 44, 41, 38, 35, 32, 29, 26, 23, 20, 16, 13, 17, 20, 23, 26, 29, 32, 36, 39, 42, 45, 48, 51, 54, 57, 60, 63, 66, 69, 73, 76, 73, 69, 66, 63, 60, 57, 54, 50, 47, 44, 41, 38, 41, 44, 49, 55, 58, 64, 69, 75, 78, 81, 84, 87, 91, 94, 97, 100, 103, 106, 110, 113, 101, 82, 79, 76, 73, 69, 66, 63, 60, 57, 54, 50, 47, 43, 40, 37, 33, 30, 27, 24, 21, 18, 15, 12, 9, 12, 16, 20, 23, 26, 29, 32, 35};
int layer4_index = 0;

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
    layer1_index = 0;
    layer2_index = 0;
    layer3_index = 0;
    layer4_index = 0;
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
      
      // Interpolate Shoulder
      int curr5 = pgm_read_word(&layer1_servo5[layer1_index]);
      int next5 = pgm_read_word(&layer1_servo5[layer1_index + 1]);
      int start5 = pgm_read_word(&layer1_servo5[0]);
      
      if(curr5 != -1 && next5 != -1) {
        int interpolated = curr5 + (int)((next5 - curr5) * factor);
        
        // Apply blend zone for smooth looping
        if(isBlending && start5 != -1) {
          interpolated = interpolated * (1.0 - blendFactor) + start5 * blendFactor;
        }
        
        servo[5].write(interpolated);
      } else if(curr5 != -1) {
        int pos = curr5;
        
        // Apply blend zone for smooth looping
        if(isBlending && start5 != -1) {
          pos = pos * (1.0 - blendFactor) + start5 * blendFactor;
        }
        
        servo[5].write(pos);
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
      int start6 = pgm_read_word(&layer2_servo6[0]);
      
      if(curr6 != -1 && next6 != -1) {
        int interpolated = curr6 + (int)((next6 - curr6) * factor);
        
        // Apply blend zone for smooth looping
        if(isBlending && start6 != -1) {
          interpolated = interpolated * (1.0 - blendFactor) + start6 * blendFactor;
        }
        
        servo[6].write(interpolated);
      } else if(curr6 != -1) {
        int pos = curr6;
        
        // Apply blend zone for smooth looping
        if(isBlending && start6 != -1) {
          pos = pos * (1.0 - blendFactor) + start6 * blendFactor;
        }
        
        servo[6].write(pos);
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
      
      // Interpolate Thumb
      int curr0 = pgm_read_word(&layer3_servo0[layer3_index]);
      int next0 = pgm_read_word(&layer3_servo0[layer3_index + 1]);
      int start0 = pgm_read_word(&layer3_servo0[0]);
      
      if(curr0 != -1 && next0 != -1) {
        int interpolated = curr0 + (int)((next0 - curr0) * factor);
        
        // Apply blend zone for smooth looping
        if(isBlending && start0 != -1) {
          interpolated = interpolated * (1.0 - blendFactor) + start0 * blendFactor;
        }
        
        servo[0].write(interpolated);
      } else if(curr0 != -1) {
        int pos = curr0;
        
        // Apply blend zone for smooth looping
        if(isBlending && start0 != -1) {
          pos = pos * (1.0 - blendFactor) + start0 * blendFactor;
        }
        
        servo[0].write(pos);
      }
      // Interpolate Index
      int curr1 = pgm_read_word(&layer3_servo1[layer3_index]);
      int next1 = pgm_read_word(&layer3_servo1[layer3_index + 1]);
      int start1 = pgm_read_word(&layer3_servo1[0]);
      
      if(curr1 != -1 && next1 != -1) {
        int interpolated = curr1 + (int)((next1 - curr1) * factor);
        
        // Apply blend zone for smooth looping
        if(isBlending && start1 != -1) {
          interpolated = interpolated * (1.0 - blendFactor) + start1 * blendFactor;
        }
        
        servo[1].write(interpolated);
      } else if(curr1 != -1) {
        int pos = curr1;
        
        // Apply blend zone for smooth looping
        if(isBlending && start1 != -1) {
          pos = pos * (1.0 - blendFactor) + start1 * blendFactor;
        }
        
        servo[1].write(pos);
      }
      // Interpolate Middle
      int curr2 = pgm_read_word(&layer3_servo2[layer3_index]);
      int next2 = pgm_read_word(&layer3_servo2[layer3_index + 1]);
      int start2 = pgm_read_word(&layer3_servo2[0]);
      
      if(curr2 != -1 && next2 != -1) {
        int interpolated = curr2 + (int)((next2 - curr2) * factor);
        
        // Apply blend zone for smooth looping
        if(isBlending && start2 != -1) {
          interpolated = interpolated * (1.0 - blendFactor) + start2 * blendFactor;
        }
        
        servo[2].write(interpolated);
      } else if(curr2 != -1) {
        int pos = curr2;
        
        // Apply blend zone for smooth looping
        if(isBlending && start2 != -1) {
          pos = pos * (1.0 - blendFactor) + start2 * blendFactor;
        }
        
        servo[2].write(pos);
      }
      // Interpolate Ring
      int curr3 = pgm_read_word(&layer3_servo3[layer3_index]);
      int next3 = pgm_read_word(&layer3_servo3[layer3_index + 1]);
      int start3 = pgm_read_word(&layer3_servo3[0]);
      
      if(curr3 != -1 && next3 != -1) {
        int interpolated = curr3 + (int)((next3 - curr3) * factor);
        
        // Apply blend zone for smooth looping
        if(isBlending && start3 != -1) {
          interpolated = interpolated * (1.0 - blendFactor) + start3 * blendFactor;
        }
        
        servo[3].write(interpolated);
      } else if(curr3 != -1) {
        int pos = curr3;
        
        // Apply blend zone for smooth looping
        if(isBlending && start3 != -1) {
          pos = pos * (1.0 - blendFactor) + start3 * blendFactor;
        }
        
        servo[3].write(pos);
      }
      // Interpolate Pinky
      int curr4 = pgm_read_word(&layer3_servo4[layer3_index]);
      int next4 = pgm_read_word(&layer3_servo4[layer3_index + 1]);
      int start4 = pgm_read_word(&layer3_servo4[0]);
      
      if(curr4 != -1 && next4 != -1) {
        int interpolated = curr4 + (int)((next4 - curr4) * factor);
        
        // Apply blend zone for smooth looping
        if(isBlending && start4 != -1) {
          interpolated = interpolated * (1.0 - blendFactor) + start4 * blendFactor;
        }
        
        servo[4].write(interpolated);
      } else if(curr4 != -1) {
        int pos = curr4;
        
        // Apply blend zone for smooth looping
        if(isBlending && start4 != -1) {
          pos = pos * (1.0 - blendFactor) + start4 * blendFactor;
        }
        
        servo[4].write(pos);
      }
    }
  }

  // Update layer 4 with interpolation
  if(layer4_index < layer4_count - 1) {
    unsigned long currentTime = pgm_read_dword(&layer4_times[layer4_index]);
    unsigned long nextTime = pgm_read_dword(&layer4_times[layer4_index + 1]);
    
    // Move to next keyframe if we've passed it
    if(elapsed >= nextTime) {
      layer4_index++;
    }
    
    // Interpolate between current and next keyframe
    if(layer4_index < layer4_count - 1 && elapsed >= currentTime) {
      currentTime = pgm_read_dword(&layer4_times[layer4_index]);
      nextTime = pgm_read_dword(&layer4_times[layer4_index + 1]);
      
      // Calculate interpolation factor (0.0 to 1.0)
      float factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
      factor = constrain(factor, 0.0, 1.0);
      
      // Interpolate Wrist
      int curr7 = pgm_read_word(&layer4_servo7[layer4_index]);
      int next7 = pgm_read_word(&layer4_servo7[layer4_index + 1]);
      int start7 = pgm_read_word(&layer4_servo7[0]);
      
      if(curr7 != -1 && next7 != -1) {
        int interpolated = curr7 + (int)((next7 - curr7) * factor);
        
        // Apply blend zone for smooth looping
        if(isBlending && start7 != -1) {
          interpolated = interpolated * (1.0 - blendFactor) + start7 * blendFactor;
        }
        
        servo[7].write(interpolated);
      } else if(curr7 != -1) {
        int pos = curr7;
        
        // Apply blend zone for smooth looping
        if(isBlending && start7 != -1) {
          pos = pos * (1.0 - blendFactor) + start7 * blendFactor;
        }
        
        servo[7].write(pos);
      }
    }
  }

  delay(5); // 200Hz update rate for smooth interpolation
}
