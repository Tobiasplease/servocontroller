/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2025-12-04 22:19:25
 * Layers: 4
 * Original Frames Recorded: 3164
 * Loop Duration: 8.97s (recorded) / 8.97s (at 1.0x speed)
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
unsigned long loopDuration = 8970; // milliseconds (adjusted for 1.0x speed)

// Layer data structures

// Layer 1: Layer_1 (cursor mode) - 77 keyframes
const int layer1_count = 77;
const unsigned long layer1_times[] PROGMEM = {3, 134, 238, 341, 455, 558, 659, 775, 875, 983, 1086, 1188, 1294, 1398, 1499, 1602, 1703, 1819, 1927, 2030, 2136, 2243, 2407, 2520, 2624, 2725, 2831, 2943, 3079, 3184, 3285, 3390, 3495, 3607, 3711, 3832, 3936, 4079, 4239, 4520, 4719, 4824, 4927, 5031, 5135, 5239, 5344, 5448, 5551, 5656, 5760, 5864, 5968, 6070, 6177, 6280, 6382, 6488, 6592, 6789, 6896, 7133, 7240, 7343, 7445, 7553, 7656, 7757, 7857, 7960, 8065, 8168, 8332, 8433, 8536, 8637, 8945};
const int layer1_servo0[] PROGMEM = {134, 129, 125, 130, 134, 142, 144, 142, 131, 124, 121, 120, 119, 121, 128, 136, 141, 139, 125, 115, 105, 101, 101, 105, 111, 117, 123, 125, 124, 113, 92, 77, 65, 56, 47, 37, 29, 24, 25, 29, 34, 41, 50, 56, 63, 70, 82, 91, 102, 102, 94, 82, 65, 52, 41, 34, 29, 27, 26, 36, 41, 44, 48, 54, 68, 85, 105, 124, 133, 130, 124, 110, 104, 96, 96, 99, 99};
const int layer1_servo1[] PROGMEM = {123, 120, 110, 110, 114, 123, 130, 135, 130, 121, 115, 108, 101, 99, 104, 113, 124, 127, 125, 118, 106, 100, 95, 94, 96, 100, 106, 111, 116, 116, 107, 94, 83, 75, 66, 59, 53, 48, 47, 47, 47, 47, 47, 45, 43, 46, 59, 71, 92, 100, 107, 104, 90, 77, 64, 53, 44, 37, 33, 21, 22, 22, 23, 29, 42, 60, 81, 102, 121, 128, 133, 130, 128, 102, 83, 81, 81};
const int layer1_servo2[] PROGMEM = {100, 96, 90, 94, 99, 106, 109, 110, 104, 96, 90, 85, 83, 87, 95, 101, 105, 104, 99, 92, 81, 75, 70, 71, 75, 81, 87, 90, 92, 91, 86, 76, 65, 58, 50, 46, 43, 39, 34, 29, 25, 22, 21, 22, 27, 38, 48, 55, 68, 75, 85, 92, 89, 77, 55, 36, 25, 14, 9, 1, 5, 8, 17, 30, 46, 61, 74, 88, 99, 103, 110, 113, 118, 127, 105, 100, 100};
const int layer1_servo3[] PROGMEM = {111, 106, 105, 114, 119, 125, 123, 118, 106, 99, 97, 97, 100, 110, 119, 124, 122, 117, 100, 90, 79, 75, 76, 82, 90, 97, 104, 104, 100, 88, 71, 58, 47, 39, 30, 24, 20, 15, 12, 11, 12, 17, 25, 34, 46, 62, 70, 75, 78, 77, 72, 69, 64, 52, 31, 17, 9, 3, 2, 16, 24, 30, 41, 56, 71, 86, 98, 110, 111, 105, 100, 94, 94, 120, 118, 117, 117};
const int layer1_servo4[] PROGMEM = {134, 129, 125, 130, 134, 142, 144, 142, 131, 124, 121, 120, 119, 121, 128, 136, 141, 139, 125, 115, 105, 101, 101, 105, 111, 117, 123, 125, 124, 113, 92, 77, 65, 56, 47, 37, 29, 24, 25, 29, 34, 41, 50, 56, 63, 70, 82, 91, 102, 102, 94, 82, 65, 52, 41, 34, 29, 27, 26, 36, 41, 44, 48, 54, 68, 85, 105, 124, 133, 130, 124, 110, 104, 96, 96, 99, 99};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 102 keyframes
const int layer2_count = 102;
const unsigned long layer2_times[] PROGMEM = {1, 243, 307, 363, 421, 484, 684, 735, 788, 845, 899, 965, 1043, 1099, 1163, 1219, 1275, 1331, 1386, 1442, 1492, 1674, 1728, 1784, 1839, 1922, 2005, 2094, 2155, 2205, 2265, 2327, 2380, 2431, 2499, 2868, 2956, 3043, 3139, 3219, 3338, 3436, 3539, 3610, 3855, 3907, 3967, 4051, 4114, 4308, 4365, 4450, 4609, 4711, 4779, 5083, 5138, 5212, 5266, 5331, 5420, 5475, 5529, 5586, 5642, 5811, 5874, 5943, 6019, 6416, 6474, 6536, 6593, 6651, 6711, 6761, 6817, 6874, 6930, 7018, 7074, 7147, 7198, 7288, 7362, 7466, 7583, 7633, 7777, 7866, 8002, 8233, 8321, 8393, 8502, 8594, 8649, 8722, 8793, 8850, 8913, 8955};
const int layer2_servo7[] PROGMEM = {131, 128, 124, 121, 118, 114, 118, 124, 130, 133, 136, 139, 142, 147, 150, 153, 157, 160, 165, 169, 173, 169, 166, 162, 159, 156, 153, 150, 147, 142, 139, 136, 132, 128, 124, 128, 131, 134, 137, 140, 144, 147, 150, 153, 150, 145, 141, 138, 135, 132, 129, 126, 122, 119, 116, 119, 122, 125, 129, 132, 135, 139, 142, 146, 149, 152, 155, 158, 162, 158, 155, 152, 149, 146, 143, 140, 135, 132, 129, 126, 122, 119, 116, 113, 110, 107, 104, 101, 98, 95, 92, 95, 98, 101, 105, 108, 111, 114, 117, 120, 124, 127};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 29 keyframes
const int layer3_count = 29;
const unsigned long layer3_times[] PROGMEM = {6, 517, 636, 925, 1157, 1597, 1765, 2013, 2309, 2525, 3308, 3500, 3908, 4074, 4796, 5041, 5451, 5796, 6004, 6475, 7061, 7369, 7652, 7991, 8269, 8479, 8644, 8867, 8939};
const int layer3_servo6[] PROGMEM = {91, 94, 97, 100, 103, 100, 97, 94, 91, 87, 91, 94, 91, 87, 91, 94, 97, 94, 91, 87, 91, 94, 97, 100, 97, 94, 91, 87, 87};
int layer3_index = 0;

// Layer 4: Layer_4 (manual mode) - 32 keyframes
const int layer4_count = 32;
const unsigned long layer4_times[] PROGMEM = {5, 201, 252, 491, 1119, 1306, 1574, 1822, 2567, 2719, 3338, 3494, 3661, 4355, 4648, 4891, 5458, 5697, 5904, 6480, 6687, 6857, 6998, 7492, 7617, 7775, 7931, 8523, 8658, 8770, 8929, 8946};
const int layer4_servo5[] PROGMEM = {88, 92, 95, 98, 95, 92, 89, 86, 89, 92, 89, 86, 83, 86, 89, 92, 89, 86, 83, 86, 89, 92, 95, 92, 89, 86, 83, 86, 89, 92, 95, 95};
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
      
      // Interpolate Thumb
      int curr0 = pgm_read_word(&layer1_servo0[layer1_index]);
      int next0 = pgm_read_word(&layer1_servo0[layer1_index + 1]);
      int start0 = pgm_read_word(&layer1_servo0[0]);
      
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
      int curr1 = pgm_read_word(&layer1_servo1[layer1_index]);
      int next1 = pgm_read_word(&layer1_servo1[layer1_index + 1]);
      int start1 = pgm_read_word(&layer1_servo1[0]);
      
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
      int curr2 = pgm_read_word(&layer1_servo2[layer1_index]);
      int next2 = pgm_read_word(&layer1_servo2[layer1_index + 1]);
      int start2 = pgm_read_word(&layer1_servo2[0]);
      
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
      int curr3 = pgm_read_word(&layer1_servo3[layer1_index]);
      int next3 = pgm_read_word(&layer1_servo3[layer1_index + 1]);
      int start3 = pgm_read_word(&layer1_servo3[0]);
      
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
      int curr4 = pgm_read_word(&layer1_servo4[layer1_index]);
      int next4 = pgm_read_word(&layer1_servo4[layer1_index + 1]);
      int start4 = pgm_read_word(&layer1_servo4[0]);
      
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
      
      // Interpolate Wrist
      int curr7 = pgm_read_word(&layer2_servo7[layer2_index]);
      int next7 = pgm_read_word(&layer2_servo7[layer2_index + 1]);
      int start7 = pgm_read_word(&layer2_servo7[0]);
      
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
      
      // Interpolate Shoulder
      int curr5 = pgm_read_word(&layer4_servo5[layer4_index]);
      int next5 = pgm_read_word(&layer4_servo5[layer4_index + 1]);
      int start5 = pgm_read_word(&layer4_servo5[0]);
      
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

  delay(5); // 200Hz update rate for smooth interpolation
}
