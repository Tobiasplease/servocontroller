/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2025-12-04 22:38:24
 * Layers: 4
 * Original Frames Recorded: 3175
 * Loop Duration: 8.22s (recorded) / 8.22s (at 1.0x speed)
 * Playback Speed: 1.0x
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
unsigned long loopDuration = 8220; // milliseconds (adjusted for 1.0x speed)

// Layer data structures

// Layer 1: Layer_1 (manual mode) - 38 keyframes
const int layer1_count = 38;
const unsigned long layer1_times[] PROGMEM = {9, 360, 671, 888, 1007, 1150, 1311, 1400, 1575, 1727, 1872, 1976, 2120, 2272, 2344, 2457, 2696, 2952, 3415, 4337, 4540, 4749, 4901, 5121, 5247, 5414, 5566, 5769, 5911, 6127, 6318, 6407, 6696, 6830, 7023, 7207, 7526, 8203};
const int layer1_servo5[] PROGMEM = {117, 120, 123, 127, 130, 133, 136, 139, 142, 145, 148, 151, 154, 157, 160, 164, 167, 170, 173, 170, 167, 164, 160, 157, 154, 151, 148, 145, 141, 138, 135, 132, 129, 126, 123, 120, 117, 114};
int layer1_index = 0;

// Layer 2: Layer_4 (cursor mode) - 78 keyframes
const int layer2_count = 78;
const unsigned long layer2_times[] PROGMEM = {4, 107, 214, 317, 419, 525, 629, 732, 837, 1011, 1117, 1221, 1325, 1429, 1533, 1636, 1741, 1843, 1948, 2053, 2155, 2261, 2364, 2468, 2573, 2677, 2780, 2884, 2988, 3091, 3204, 3307, 3412, 3516, 3618, 3724, 3828, 3933, 4036, 4144, 4425, 4539, 4642, 4748, 4848, 4955, 5057, 5164, 5268, 5370, 5477, 5579, 5681, 5787, 5891, 5994, 6101, 6202, 6307, 6413, 6515, 6618, 6723, 6827, 6928, 7035, 7139, 7241, 7347, 7451, 7554, 7667, 7771, 7882, 7984, 8090, 8195, 8211};
const int layer2_servo0[] PROGMEM = {139, 136, 129, 125, 123, 129, 131, 138, 150, 156, 167, 171, 161, 139, 125, 112, 109, 104, 93, 79, 73, 67, 58, 51, 43, 40, 41, 47, 57, 73, 92, 102, 115, 127, 143, 154, 165, 168, 165, 160, 154, 148, 141, 134, 128, 117, 107, 100, 97, 91, 78, 71, 63, 42, 33, 27, 24, 19, 14, 10, 13, 23, 44, 60, 77, 84, 90, 97, 108, 121, 134, 142, 141, 136, 131, 126, 120, 116};
const int layer2_servo1[] PROGMEM = {156, 148, 130, 113, 100, 95, 94, 100, 112, 118, 130, 139, 150, 146, 137, 117, 99, 81, 59, 41, 36, 47, 58, 65, 70, 73, 78, 84, 95, 107, 119, 125, 131, 134, 139, 141, 141, 136, 127, 122, 117, 111, 104, 97, 91, 79, 69, 63, 64, 72, 80, 84, 85, 79, 70, 60, 50, 39, 36, 39, 50, 60, 65, 63, 58, 58, 60, 65, 76, 94, 113, 133, 141, 145, 150, 152, 151, 149};
const int layer2_servo2[] PROGMEM = {122, 112, 91, 76, 70, 77, 86, 98, 112, 116, 119, 119, 114, 109, 100, 79, 62, 50, 42, 36, 28, 15, 20, 29, 44, 53, 66, 77, 86, 90, 93, 94, 96, 97, 101, 105, 111, 116, 125, 128, 125, 119, 112, 103, 95, 80, 64, 54, 44, 39, 42, 48, 53, 69, 78, 80, 78, 72, 67, 64, 60, 50, 34, 25, 25, 30, 36, 44, 56, 67, 81, 96, 102, 108, 116, 124, 128, 130};
const int layer2_servo3[] PROGMEM = {105, 100, 91, 88, 93, 111, 123, 136, 150, 154, 156, 151, 124, 101, 89, 74, 72, 74, 76, 73, 66, 35, 20, 15, 16, 21, 30, 39, 49, 56, 65, 71, 80, 89, 105, 118, 136, 148, 164, 166, 162, 156, 149, 141, 133, 118, 102, 91, 77, 57, 40, 35, 32, 32, 41, 48, 53, 51, 46, 36, 23, 13, 12, 22, 44, 56, 67, 76, 88, 95, 101, 105, 103, 99, 98, 98, 98, 97};
const int layer2_servo4[] PROGMEM = {139, 136, 129, 125, 123, 129, 131, 138, 150, 156, 167, 171, 161, 139, 125, 112, 109, 104, 93, 79, 73, 67, 58, 51, 43, 40, 41, 47, 57, 73, 92, 102, 115, 127, 143, 154, 165, 168, 165, 160, 154, 148, 141, 134, 128, 117, 107, 100, 97, 91, 78, 71, 63, 42, 33, 27, 24, 19, 14, 10, 13, 23, 44, 60, 77, 84, 90, 97, 108, 121, 134, 142, 141, 136, 131, 126, 120, 116};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 37 keyframes
const int layer3_count = 37;
const unsigned long layer3_times[] PROGMEM = {5, 341, 494, 573, 1277, 1514, 1731, 1880, 2041, 2187, 2322, 2578, 2674, 2826, 3114, 3286, 3865, 3929, 3983, 4114, 4217, 4548, 5015, 5068, 5192, 5305, 5654, 5807, 5894, 5990, 6102, 6285, 6403, 6825, 7281, 7451, 8203};
const int layer3_servo6[] PROGMEM = {88, 85, 82, 79, 76, 73, 70, 67, 64, 61, 58, 55, 51, 48, 45, 42, 45, 48, 52, 56, 59, 62, 65, 68, 71, 74, 77, 80, 83, 86, 90, 93, 96, 99, 102, 105, 102};
int layer3_index = 0;

// Layer 4: Layer_4 (manual mode) - 88 keyframes
const int layer4_count = 88;
const unsigned long layer4_times[] PROGMEM = {6, 80, 137, 192, 272, 380, 488, 664, 719, 787, 881, 972, 1023, 1079, 1159, 1215, 1272, 1359, 1599, 1656, 1711, 1775, 1832, 1885, 1959, 2078, 2216, 2447, 2538, 2594, 2649, 2711, 2766, 2822, 2887, 2955, 3010, 3069, 3125, 3223, 3307, 3401, 3750, 3854, 3941, 4058, 4382, 4470, 4542, 4619, 4694, 4805, 5269, 5320, 5370, 5468, 5522, 5581, 5645, 5709, 5853, 6476, 6528, 6581, 6632, 6700, 6757, 6820, 7075, 7139, 7196, 7252, 7310, 7363, 7421, 7476, 7532, 7588, 7643, 7700, 7766, 7852, 7908, 7964, 8045, 8101, 8164, 8212};
const int layer4_servo7[] PROGMEM = {129, 132, 135, 140, 143, 146, 149, 146, 143, 140, 137, 134, 131, 127, 124, 121, 117, 114, 118, 121, 124, 128, 131, 134, 137, 140, 143, 140, 137, 134, 129, 122, 119, 116, 113, 110, 106, 103, 100, 97, 94, 91, 94, 98, 101, 104, 100, 97, 94, 91, 87, 84, 87, 93, 96, 99, 103, 106, 110, 113, 116, 112, 108, 101, 95, 92, 87, 84, 87, 91, 94, 98, 101, 105, 109, 114, 120, 124, 130, 134, 137, 140, 144, 147, 150, 153, 156, 160};
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
      
      // Interpolate Thumb
      int curr0 = pgm_read_word(&layer2_servo0[layer2_index]);
      int next0 = pgm_read_word(&layer2_servo0[layer2_index + 1]);
      int start0 = pgm_read_word(&layer2_servo0[0]);
      
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
      int curr1 = pgm_read_word(&layer2_servo1[layer2_index]);
      int next1 = pgm_read_word(&layer2_servo1[layer2_index + 1]);
      int start1 = pgm_read_word(&layer2_servo1[0]);
      
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
      int curr2 = pgm_read_word(&layer2_servo2[layer2_index]);
      int next2 = pgm_read_word(&layer2_servo2[layer2_index + 1]);
      int start2 = pgm_read_word(&layer2_servo2[0]);
      
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
      int curr3 = pgm_read_word(&layer2_servo3[layer2_index]);
      int next3 = pgm_read_word(&layer2_servo3[layer2_index + 1]);
      int start3 = pgm_read_word(&layer2_servo3[0]);
      
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
      int curr4 = pgm_read_word(&layer2_servo4[layer2_index]);
      int next4 = pgm_read_word(&layer2_servo4[layer2_index + 1]);
      int start4 = pgm_read_word(&layer2_servo4[0]);
      
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
      
      // Interpolate Elbow
      int curr6 = pgm_read_word(&layer3_servo6[layer3_index]);
      int next6 = pgm_read_word(&layer3_servo6[layer3_index + 1]);
      int start6 = pgm_read_word(&layer3_servo6[0]);
      
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
