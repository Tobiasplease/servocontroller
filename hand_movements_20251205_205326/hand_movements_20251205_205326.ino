/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2025-12-05 20:53:26
 * Layers: 4
 * Original Frames Recorded: 4077
 * Loop Duration: 12.83s (recorded) / 9.87s (at 1.3x speed)
 * Playback Speed: 1.3x
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
unsigned long loopDuration = 9869; // milliseconds (adjusted for 1.3x speed)

// Layer data structures

// Layer 1: Layer_1 (manual mode) - 37 keyframes
const int layer1_count = 37;
const unsigned long layer1_times[] PROGMEM = {20, 288, 380, 577, 695, 861, 1061, 1306, 1571, 1705, 1895, 2014, 2200, 2390, 2525, 2674, 2870, 3043, 3201, 3514, 4421, 4630, 4901, 5048, 5307, 5503, 5659, 5841, 5954, 6163, 6310, 6491, 6642, 6950, 7249, 7556, 9856};
const int layer1_servo5[] PROGMEM = {119, 122, 125, 128, 131, 134, 137, 140, 144, 147, 150, 153, 156, 159, 162, 165, 168, 171, 174, 177, 174, 171, 168, 165, 162, 159, 156, 153, 150, 147, 144, 140, 137, 134, 131, 128, 128};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 32 keyframes
const int layer2_count = 32;
const unsigned long layer2_times[] PROGMEM = {3, 911, 1028, 1115, 1185, 1243, 1581, 1827, 2108, 2495, 2614, 2780, 4526, 4674, 4748, 4806, 5334, 5663, 5925, 6099, 6186, 6401, 6638, 6918, 7071, 7314, 7827, 8301, 9254, 9370, 9715, 9844};
const int layer2_servo6[] PROGMEM = {90, 86, 83, 80, 77, 74, 71, 68, 65, 62, 59, 56, 59, 62, 65, 68, 71, 74, 77, 80, 83, 86, 90, 93, 96, 99, 102, 105, 102, 99, 96, 95};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 129 keyframes
const int layer3_count = 129;
const unsigned long layer3_times[] PROGMEM = {14, 188, 235, 276, 317, 358, 398, 444, 490, 532, 573, 613, 653, 706, 745, 788, 827, 896, 987, 1111, 1162, 1205, 1244, 1293, 1345, 1389, 1429, 1468, 1508, 1551, 1594, 1637, 1680, 1723, 1766, 1809, 1852, 1895, 1938, 1987, 2043, 2086, 2129, 2172, 2215, 2259, 2301, 2344, 2383, 2442, 2569, 2693, 2840, 2882, 2929, 2968, 3008, 3052, 3095, 3138, 3192, 3464, 3531, 3573, 3613, 3654, 3749, 3816, 3864, 3966, 4097, 4242, 4694, 4778, 4870, 4916, 5048, 5115, 5186, 5259, 5524, 5611, 5691, 5906, 6136, 6493, 6546, 6599, 6656, 6717, 6808, 6915, 7063, 7111, 7164, 7204, 7259, 7298, 7431, 7475, 7518, 7561, 7603, 7671, 7715, 7765, 7844, 8041, 8083, 8141, 8188, 8240, 8283, 8347, 8421, 8483, 8533, 8600, 8667, 8736, 8847, 8950, 9067, 9172, 9298, 9368, 9533, 9728, 9846};
const int layer3_servo7[] PROGMEM = {124, 121, 118, 114, 108, 99, 91, 85, 82, 77, 72, 68, 61, 58, 54, 50, 47, 44, 41, 44, 47, 54, 57, 61, 64, 68, 72, 80, 85, 90, 99, 102, 108, 113, 119, 124, 127, 131, 135, 138, 134, 127, 120, 115, 108, 104, 101, 95, 92, 88, 85, 82, 85, 90, 94, 99, 103, 106, 110, 114, 117, 114, 111, 106, 102, 99, 96, 93, 90, 86, 83, 80, 83, 87, 90, 93, 96, 99, 102, 105, 109, 112, 115, 118, 121, 124, 128, 131, 134, 137, 140, 143, 139, 134, 131, 127, 124, 120, 117, 112, 108, 104, 99, 96, 93, 90, 87, 90, 94, 97, 100, 103, 107, 111, 114, 117, 120, 123, 126, 130, 133, 136, 139, 142, 145, 148, 151, 154, 154};
int layer3_index = 0;

// Layer 4: Layer_4 (cursor mode) - 118 keyframes
const int layer4_count = 118;
const unsigned long layer4_times[] PROGMEM = {7, 108, 186, 265, 346, 431, 525, 607, 683, 764, 864, 968, 1056, 1134, 1213, 1293, 1373, 1452, 1532, 1612, 1694, 1773, 1881, 2037, 2130, 2212, 2332, 2426, 2512, 2609, 2719, 2812, 2892, 2972, 3054, 3132, 3212, 3293, 3370, 3468, 3550, 3631, 3727, 3810, 3895, 3987, 4074, 4153, 4231, 4324, 4401, 4492, 4578, 4713, 4799, 4878, 4959, 5041, 5118, 5199, 5279, 5362, 5439, 5517, 5605, 5684, 5767, 5846, 5923, 6001, 6079, 6167, 6245, 6325, 6405, 6485, 6565, 6646, 6725, 6804, 6886, 6965, 7045, 7123, 7206, 7286, 7367, 7447, 7527, 7605, 7685, 7767, 7845, 7925, 8003, 8085, 8164, 8244, 8324, 8404, 8483, 8571, 8650, 8728, 8811, 8891, 8969, 9057, 9137, 9219, 9297, 9377, 9457, 9537, 9630, 9709, 9789, 9863};
const int layer4_servo0[] PROGMEM = {94, 97, 102, 103, 104, 106, 108, 110, 116, 121, 123, 128, 143, 145, 144, 140, 136, 136, 141, 150, 162, 163, 160, 157, 152, 149, 145, 142, 137, 132, 129, 130, 139, 146, 149, 150, 146, 139, 134, 133, 140, 143, 143, 137, 131, 123, 118, 114, 109, 106, 101, 97, 92, 87, 81, 74, 60, 52, 43, 36, 31, 25, 23, 29, 35, 36, 31, 31, 37, 43, 52, 57, 67, 76, 86, 102, 116, 119, 110, 110, 113, 111, 101, 88, 83, 74, 65, 55, 42, 33, 24, 26, 47, 59, 67, 75, 81, 87, 88, 85, 89, 91, 89, 82, 71, 62, 56, 49, 42, 34, 20, 9, 5, 7, 22, 29, 32, 35};
const int layer4_servo1[] PROGMEM = {81, 83, 87, 90, 96, 107, 114, 124, 127, 122, 111, 115, 128, 133, 139, 144, 150, 150, 148, 144, 148, 151, 156, 162, 165, 163, 159, 154, 149, 146, 144, 144, 144, 141, 137, 135, 136, 139, 143, 148, 148, 140, 135, 123, 116, 109, 103, 99, 95, 92, 89, 89, 87, 84, 81, 78, 72, 66, 57, 48, 42, 33, 24, 18, 21, 35, 44, 46, 49, 54, 59, 64, 78, 90, 100, 108, 108, 106, 115, 124, 123, 106, 91, 77, 71, 63, 56, 51, 48, 46, 36, 28, 34, 45, 53, 61, 68, 77, 83, 89, 103, 104, 96, 83, 65, 54, 49, 42, 38, 34, 29, 23, 16, 8, 8, 20, 31, 39};
const int layer4_servo2[] PROGMEM = {80, 86, 94, 101, 109, 121, 125, 123, 115, 108, 108, 114, 133, 129, 128, 129, 141, 150, 158, 159, 153, 146, 144, 147, 154, 160, 160, 158, 153, 147, 141, 136, 130, 130, 134, 140, 149, 153, 151, 145, 133, 128, 125, 122, 119, 114, 109, 104, 98, 93, 85, 80, 75, 71, 67, 64, 60, 59, 56, 52, 47, 42, 38, 30, 21, 21, 33, 43, 53, 60, 69, 74, 84, 89, 93, 94, 99, 116, 127, 123, 110, 95, 84, 72, 66, 58, 48, 39, 34, 34, 39, 41, 43, 49, 56, 67, 78, 91, 98, 101, 101, 93, 82, 69, 54, 45, 39, 32, 26, 20, 16, 19, 21, 22, 13, 12, 18, 25};
const int layer4_servo3[] PROGMEM = {94, 98, 104, 107, 109, 111, 113, 110, 111, 116, 122, 128, 144, 143, 140, 134, 133, 137, 145, 155, 164, 161, 156, 152, 148, 147, 146, 143, 138, 133, 128, 127, 134, 142, 148, 151, 151, 144, 136, 132, 135, 138, 139, 136, 132, 125, 120, 116, 111, 106, 99, 93, 87, 82, 76, 68, 56, 49, 43, 37, 33, 28, 28, 34, 35, 31, 27, 30, 39, 45, 56, 61, 69, 76, 83, 97, 113, 123, 115, 109, 108, 106, 98, 86, 81, 73, 62, 50, 37, 29, 25, 31, 51, 61, 69, 77, 85, 92, 94, 89, 88, 87, 84, 77, 67, 59, 53, 45, 37, 29, 15, 7, 7, 12, 24, 27, 27, 30};
const int layer4_servo4[] PROGMEM = {87, 88, 91, 92, 96, 103, 110, 119, 126, 125, 116, 120, 133, 139, 144, 146, 147, 145, 143, 143, 152, 157, 161, 164, 163, 159, 153, 148, 143, 140, 139, 141, 146, 145, 142, 140, 137, 136, 138, 143, 148, 145, 140, 129, 121, 113, 107, 104, 99, 97, 95, 94, 92, 88, 84, 80, 70, 63, 52, 42, 36, 28, 21, 19, 27, 38, 42, 41, 44, 48, 54, 59, 73, 85, 97, 109, 114, 109, 110, 119, 123, 111, 96, 83, 76, 68, 61, 56, 49, 44, 31, 24, 37, 49, 57, 65, 71, 78, 82, 85, 98, 101, 97, 86, 70, 60, 54, 47, 42, 37, 29, 19, 10, 5, 12, 25, 35, 41};
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
      
      // Interpolate Wrist
      int curr7 = pgm_read_word(&layer3_servo7[layer3_index]);
      int next7 = pgm_read_word(&layer3_servo7[layer3_index + 1]);
      int start7 = pgm_read_word(&layer3_servo7[0]);
      
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
      
      // Interpolate Thumb
      int curr0 = pgm_read_word(&layer4_servo0[layer4_index]);
      int next0 = pgm_read_word(&layer4_servo0[layer4_index + 1]);
      int start0 = pgm_read_word(&layer4_servo0[0]);
      
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
      int curr1 = pgm_read_word(&layer4_servo1[layer4_index]);
      int next1 = pgm_read_word(&layer4_servo1[layer4_index + 1]);
      int start1 = pgm_read_word(&layer4_servo1[0]);
      
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
      int curr2 = pgm_read_word(&layer4_servo2[layer4_index]);
      int next2 = pgm_read_word(&layer4_servo2[layer4_index + 1]);
      int start2 = pgm_read_word(&layer4_servo2[0]);
      
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
      int curr3 = pgm_read_word(&layer4_servo3[layer4_index]);
      int next3 = pgm_read_word(&layer4_servo3[layer4_index + 1]);
      int start3 = pgm_read_word(&layer4_servo3[0]);
      
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
      int curr4 = pgm_read_word(&layer4_servo4[layer4_index]);
      int next4 = pgm_read_word(&layer4_servo4[layer4_index + 1]);
      int start4 = pgm_read_word(&layer4_servo4[0]);
      
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

  delay(5); // 200Hz update rate for smooth interpolation
}
