/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2025-12-04 21:58:02
 * Layers: 4
 * Original Frames Recorded: 3735
 * Loop Duration: 20.40s (recorded) / 20.40s (at 1.0x speed)
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
unsigned long loopDuration = 20401; // milliseconds (adjusted for 1.0x speed)

// Layer data structures

// Layer 1: Layer_1 (manual mode) - 53 keyframes
const int layer1_count = 53;
const unsigned long layer1_times[] PROGMEM = {2, 497, 722, 978, 1154, 1386, 1692, 1878, 2130, 2306, 2529, 2698, 2858, 3034, 3201, 3399, 3604, 3818, 3978, 4117, 4402, 4619, 4894, 5362, 5858, 5989, 6218, 6374, 6505, 6602, 6778, 6869, 6938, 7149, 7309, 7531, 7654, 7850, 7991, 8066, 8160, 8347, 8490, 8623, 8750, 8842, 8969, 9121, 9310, 9410, 9545, 9674, 12215};
const int layer1_servo5[] PROGMEM = {87, 90, 93, 96, 99, 102, 105, 109, 112, 115, 118, 121, 124, 127, 130, 133, 136, 139, 142, 146, 149, 152, 155, 158, 155, 152, 149, 146, 142, 139, 136, 133, 130, 127, 124, 121, 118, 115, 112, 109, 105, 102, 99, 96, 93, 90, 87, 84, 81, 78, 75, 72, 69};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 31 keyframes
const int layer2_count = 31;
const unsigned long layer2_times[] PROGMEM = {0, 442, 627, 1596, 1731, 2376, 3284, 3685, 4874, 5227, 5694, 5819, 8486, 9169, 9307, 10780, 10832, 10883, 10952, 11007, 11420, 11934, 12025, 12936, 13803, 13908, 14587, 15771, 16138, 16700, 20370};
const int layer2_servo6[] PROGMEM = {105, 102, 99, 96, 93, 90, 86, 83, 80, 77, 74, 71, 74, 77, 81, 84, 88, 91, 94, 97, 94, 97, 100, 103, 106, 110, 113, 116, 113, 110, 107};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 96 keyframes
const int layer3_count = 96;
const unsigned long layer3_times[] PROGMEM = {27, 501, 735, 912, 1001, 1126, 1310, 1382, 1567, 1652, 1870, 1926, 1991, 2070, 2167, 2336, 2830, 2924, 3063, 3118, 3175, 3246, 3312, 3362, 3414, 3468, 3528, 3583, 3634, 3687, 3742, 3813, 3871, 3965, 4031, 4087, 4151, 4206, 4263, 4318, 4391, 4443, 4510, 4631, 4758, 4940, 5342, 5622, 5676, 5730, 5808, 5909, 6006, 6134, 6491, 6567, 6719, 6775, 6857, 6912, 6996, 7047, 7111, 7162, 7490, 7621, 7687, 7782, 7838, 7889, 7943, 8054, 8173, 8247, 8374, 8505, 8659, 8735, 8790, 8856, 8910, 8967, 9054, 9107, 9158, 9208, 9263, 9327, 9383, 9438, 9495, 9588, 9782, 10014, 10082, 10175};
const int layer3_servo7[] PROGMEM = {129, 132, 135, 138, 141, 145, 148, 151, 154, 157, 160, 163, 166, 169, 172, 175, 172, 169, 166, 161, 156, 153, 150, 146, 142, 139, 136, 131, 127, 122, 119, 116, 111, 108, 104, 101, 97, 92, 88, 85, 82, 78, 75, 72, 69, 66, 63, 66, 72, 78, 81, 84, 88, 91, 94, 97, 100, 103, 106, 113, 116, 120, 123, 127, 130, 133, 136, 139, 142, 146, 151, 154, 157, 161, 164, 167, 164, 161, 157, 153, 148, 144, 140, 134, 131, 124, 120, 117, 113, 104, 98, 95, 92, 95, 103, 103};
int layer3_index = 0;

// Layer 4: Layer_4 (cursor mode) - 88 keyframes
const int layer4_count = 88;
const unsigned long layer4_times[] PROGMEM = {21, 344, 448, 550, 655, 768, 868, 976, 1079, 1184, 1287, 1390, 1496, 1599, 1702, 1808, 1921, 2024, 2128, 2232, 2344, 2444, 2551, 2656, 2757, 2864, 2968, 3080, 3221, 3345, 3455, 3559, 3664, 3769, 3871, 3975, 4079, 4183, 4287, 4428, 4535, 4639, 4743, 4863, 5025, 5205, 5361, 5488, 5591, 5694, 5800, 5917, 6025, 6129, 6252, 6415, 6520, 6622, 7088, 7199, 7319, 7431, 7533, 7639, 7744, 7844, 7951, 8056, 8156, 8264, 8366, 8466, 8575, 8677, 8784, 8896, 9007, 9112, 9255, 9359, 9463, 9576, 9680, 9783, 9888, 10006, 10129, 10175};
const int layer4_servo0[] PROGMEM = {94, 128, 142, 147, 147, 140, 121, 108, 104, 106, 103, 99, 88, 70, 65, 71, 78, 85, 91, 95, 99, 99, 98, 98, 96, 92, 89, 86, 80, 78, 88, 103, 114, 121, 130, 138, 138, 135, 132, 131, 130, 131, 134, 134, 133, 129, 125, 120, 113, 107, 101, 96, 87, 82, 76, 72, 65, 63, 68, 76, 81, 93, 98, 102, 101, 123, 120, 108, 97, 87, 80, 75, 66, 61, 55, 54, 55, 58, 62, 68, 81, 90, 101, 102, 100, 94, 90, 89};
const int layer4_servo1[] PROGMEM = {118, 148, 125, 118, 117, 126, 139, 138, 128, 112, 106, 91, 85, 89, 96, 96, 95, 95, 98, 103, 110, 115, 122, 126, 126, 115, 108, 102, 97, 92, 80, 78, 84, 91, 100, 108, 117, 128, 140, 145, 154, 161, 164, 162, 160, 155, 150, 146, 141, 135, 129, 124, 117, 112, 106, 102, 91, 71, 71, 74, 78, 90, 101, 117, 129, 105, 92, 77, 66, 62, 64, 67, 73, 77, 80, 82, 85, 88, 92, 99, 104, 100, 86, 76, 71, 64, 60, 59};
const int layer4_servo2[] PROGMEM = {110, 145, 154, 148, 140, 121, 110, 112, 120, 124, 121, 115, 105, 88, 71, 66, 66, 70, 75, 80, 84, 87, 92, 96, 102, 108, 106, 104, 99, 97, 103, 108, 108, 113, 122, 134, 147, 151, 150, 150, 145, 142, 137, 133, 129, 125, 120, 115, 111, 106, 99, 94, 88, 86, 84, 82, 80, 81, 86, 93, 98, 110, 116, 120, 112, 105, 107, 102, 89, 72, 62, 56, 50, 49, 49, 53, 61, 67, 72, 74, 73, 75, 83, 87, 90, 90, 88, 87};
const int layer4_servo3[] PROGMEM = {99, 130, 125, 128, 133, 143, 139, 125, 109, 98, 94, 85, 75, 71, 80, 90, 95, 101, 105, 110, 114, 116, 116, 116, 111, 96, 90, 85, 80, 75, 73, 84, 99, 108, 117, 122, 120, 121, 125, 128, 135, 143, 151, 152, 152, 148, 144, 139, 132, 125, 119, 114, 104, 98, 89, 84, 72, 56, 58, 64, 69, 81, 88, 100, 111, 123, 110, 92, 82, 81, 81, 81, 80, 79, 73, 72, 70, 71, 75, 83, 100, 105, 103, 95, 89, 78, 72, 71};
const int layer4_servo4[] PROGMEM = {125, 158, 143, 131, 121, 112, 121, 130, 135, 128, 124, 110, 103, 99, 90, 81, 76, 76, 79, 85, 91, 96, 107, 113, 121, 122, 118, 114, 109, 105, 99, 92, 89, 95, 104, 116, 133, 147, 155, 158, 160, 160, 156, 151, 146, 141, 135, 131, 128, 123, 117, 112, 107, 105, 103, 100, 96, 86, 88, 92, 96, 108, 118, 130, 130, 94, 90, 83, 70, 57, 52, 51, 54, 58, 65, 71, 80, 86, 91, 93, 88, 81, 73, 72, 72, 71, 70, 69};
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
