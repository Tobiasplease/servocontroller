/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-04-09 17:32:38
 * Hardware Config: Default
 * Layers: 4
 * Original Frames Recorded: 3803
 * Loop Duration: 7.39s (recorded) / 12.32s (at 0.6x speed)
 * Playback Speed: 0.6x
 * 
 * Layer Priority (later layers override earlier for same servo):
 * Servo 0 (Thumb): Layer 1
 * Servo 1 (Index): Layer 1
 * Servo 2 (Middle): Layer 1
 * Servo 3 (Ring): Layer 1
 * Servo 4 (Pinky): Layer 1
 * Servo 5 (Shoulder): Layer 4
 * Servo 6 (Elbow): Layer 3
 * Servo 7 (Wrist): Layer 2
 * 
 * Hardware: 5 Finger Servos + 3 Arm Servos
 * Fingers: Thumb, Index, Middle, Ring, Pinky
 * Arm: Shoulder, Elbow, Wrist
 * 
 * Pin Mapping:
 * Pin 12 -> Thumb (servo 0)
 * Pin 11 -> Index (servo 1)
 * Pin 10 -> Middle (servo 2)
 * Pin 9 -> Ring (servo 3)
 * Pin 8 -> Pinky (servo 4)
 * Pin 7 -> Shoulder (servo 5)
 * Pin 6 -> Elbow (servo 6)
 * Pin 5 -> Wrist (servo 7)
 * 
 * Stored positions already constrained during recording
 */

#include <Servo.h>

// Servo objects
Servo servo[8];
int servoPins[8] = {12, 11, 10, 9, 8, 7, 6, 5};

// Range configuration (from hardware preset: Default)
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;

// Helper: Map 0-180 to MIN-MAX, reverse specified servos
void writeServo(int index, int pos) {
  pos = map(pos, 0, 180, MIN_ANGLE, MAX_ANGLE);
  pos = constrain(pos, MIN_ANGLE, MAX_ANGLE);
  if(0) pos = MAX_ANGLE - pos;  // Reverse none
  servo[index].write(pos);
}

// Timing
unsigned long loopStartTime;
unsigned long loopDuration = 12316; // milliseconds (adjusted for 0.6x speed)

// Layer data structures

// Layer 1: Layer_1 (cursor mode) - 68 keyframes
const int layer1_count = 68;
const unsigned long layer1_times[] PROGMEM = {12, 437, 611, 784, 957, 1129, 1304, 1477, 1645, 1823, 1995, 2168, 2344, 2514, 2690, 2863, 3037, 3211, 3384, 3568, 3756, 3928, 4104, 4277, 4448, 4625, 4797, 4971, 5143, 5317, 5492, 5665, 5846, 6025, 6196, 6363, 6534, 6707, 6883, 7051, 7226, 7396, 7569, 7742, 7924, 8104, 8286, 8464, 8649, 8822, 8996, 9169, 9339, 9516, 9690, 9861, 10049, 10220, 10396, 10569, 10742, 10917, 11090, 11264, 11438, 11620, 11797, 12295};
const int layer1_servo0[] PROGMEM = {  // Thumb (OWNED)
  89, 91, 87, 74, 52, 30, 19, 22, 45, 69, 91, 79, 56, 26, 23, 35, 56, 70, 77, 71, 34, 21, 45, 72, 90, 85, 62, 43, 21, 22, 45, 68, 74, 61, 39, 28, 34, 53, 70, 91, 90, 76, 52, 20, 24, 52, 67, 86, 92, 89, 71, 59, 44, 38, 54, 74, 87, 94, 87, 62, 31, 20, 18, 27, 40, 49, 56, 57};
const int layer1_servo1[] PROGMEM = {  // Index (OWNED)
  80, 84, 91, 86, 69, 44, 23, 20, 30, 52, 85, 89, 72, 38, 22, 25, 40, 53, 61, 54, 24, 25, 62, 85, 88, 74, 45, 29, 18, 34, 62, 81, 86, 77, 54, 36, 27, 38, 53, 81, 93, 87, 69, 31, 18, 36, 50, 72, 79, 74, 54, 45, 37, 46, 70, 89, 97, 97, 74, 45, 22, 19, 23, 41, 56, 66, 72, 73};
const int layer1_servo2[] PROGMEM = {  // Middle (OWNED)
  65, 72, 88, 91, 83, 61, 34, 25, 21, 36, 73, 92, 85, 54, 30, 22, 28, 37, 45, 38, 21, 37, 78, 91, 78, 58, 30, 20, 23, 50, 76, 88, 91, 90, 71, 50, 28, 28, 38, 67, 88, 91, 82, 46, 20, 24, 35, 55, 62, 57, 41, 37, 38, 60, 86, 100, 100, 92, 58, 31, 19, 26, 35, 58, 72, 80, 84, 85};
const int layer1_servo3[] PROGMEM = {  // Ring (OWNED)
  49, 55, 77, 89, 90, 77, 50, 37, 19, 24, 56, 88, 92, 70, 43, 27, 22, 26, 31, 27, 26, 52, 88, 90, 62, 41, 21, 19, 35, 66, 86, 88, 88, 95, 86, 67, 36, 24, 27, 50, 77, 86, 88, 63, 30, 19, 24, 39, 46, 42, 35, 36, 46, 77, 99, 103, 95, 81, 41, 22, 24, 39, 50, 73, 84, 88, 89, 89};
const int layer1_servo4[] PROGMEM = {  // Pinky (OWNED)
  33, 39, 62, 79, 91, 88, 67, 53, 25, 19, 40, 76, 91, 84, 60, 39, 24, 22, 23, 22, 38, 69, 92, 81, 46, 27, 19, 25, 50, 80, 88, 80, 78, 93, 95, 82, 51, 29, 23, 35, 61, 75, 87, 78, 44, 21, 20, 28, 33, 33, 36, 43, 61, 92, 106, 99, 83, 65, 29, 21, 36, 55, 67, 85, 89, 89, 87, 87};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 156 keyframes
const int layer2_count = 156;
const unsigned long layer2_times[] PROGMEM = {1, 169, 223, 276, 331, 410, 462, 833, 887, 1034, 1120, 1170, 1229, 1282, 1383, 1610, 1663, 1717, 1774, 1838, 1889, 1978, 2135, 2186, 2236, 2290, 2353, 2409, 2466, 2529, 2645, 2699, 2751, 2802, 2857, 2914, 3001, 3068, 3129, 3252, 3306, 3358, 3410, 3464, 3516, 3568, 3625, 3681, 3736, 3790, 4017, 4073, 4137, 4193, 4249, 4305, 4387, 4442, 4513, 4681, 4737, 4793, 4849, 4904, 4956, 5007, 5074, 5128, 5181, 5232, 5286, 5490, 5543, 5624, 5693, 5744, 5800, 5864, 5914, 5965, 6036, 6332, 6392, 6442, 6496, 6553, 6608, 6680, 6733, 6791, 7135, 7193, 7271, 7350, 7401, 7456, 7536, 7623, 7719, 7815, 7970, 8023, 8074, 8159, 8234, 8284, 8335, 8391, 8446, 8687, 8763, 8819, 8903, 8993, 9054, 9126, 9190, 9262, 9326, 9380, 9567, 9622, 9678, 9758, 9813, 9879, 9942, 10079, 10265, 10317, 10374, 10429, 10518, 10590, 10646, 10701, 10920, 10976, 11027, 11085, 11142, 11192, 11245, 11397, 11551, 11606, 11663, 11735, 11792, 11852, 11909, 11981, 12040, 12101, 12263, 12306};
const int layer2_servo7[] PROGMEM = {  // Wrist (OWNED)
  121, 117, 105, 97, 91, 87, 84, 88, 97, 100, 103, 109, 114, 117, 120, 117, 106, 98, 90, 87, 84, 80, 84, 92, 96, 105, 112, 116, 122, 126, 122, 110, 103, 96, 93, 87, 84, 80, 77, 81, 87, 93, 97, 103, 108, 113, 117, 120, 124, 128, 124, 117, 114, 107, 104, 100, 97, 92, 85, 88, 95, 98, 102, 106, 111, 115, 119, 123, 127, 130, 133, 128, 121, 117, 114, 110, 106, 103, 99, 95, 91, 94, 97, 101, 105, 109, 112, 115, 119, 123, 120, 117, 113, 110, 106, 102, 99, 95, 92, 88, 92, 99, 105, 108, 112, 115, 119, 123, 127, 123, 120, 117, 114, 111, 108, 104, 99, 96, 93, 90, 93, 100, 106, 110, 113, 116, 120, 123, 120, 115, 110, 106, 103, 100, 97, 93, 96, 101, 106, 112, 117, 121, 126, 129, 126, 121, 118, 115, 110, 107, 103, 100, 97, 93, 97, 104};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 78 keyframes
const int layer3_count = 78;
const unsigned long layer3_times[] PROGMEM = {20, 123, 191, 375, 607, 663, 919, 1223, 1318, 1648, 1703, 1759, 1845, 1973, 2254, 2309, 2378, 2509, 2876, 2949, 3372, 3477, 3840, 3892, 4028, 4321, 4396, 4466, 4587, 5007, 5075, 5202, 5601, 5699, 5881, 6026, 6388, 6489, 6571, 6665, 6769, 7113, 7197, 7255, 7327, 7448, 7544, 7919, 8048, 8144, 8334, 8473, 8587, 8644, 8737, 8836, 8991, 9301, 9360, 9414, 9510, 9629, 9862, 9987, 10171, 10438, 10567, 10624, 10716, 10821, 11278, 11365, 11453, 11581, 11893, 11972, 12044, 12284};
const int layer3_servo6[] PROGMEM = {  // Elbow (OWNED)
  82, 79, 76, 73, 76, 79, 82, 79, 76, 73, 76, 80, 83, 86, 83, 79, 76, 73, 76, 79, 75, 72, 76, 81, 84, 80, 77, 74, 70, 74, 77, 80, 77, 74, 70, 67, 70, 73, 76, 79, 82, 79, 76, 73, 69, 66, 63, 66, 70, 73, 76, 73, 70, 67, 64, 61, 58, 61, 65, 69, 73, 76, 73, 69, 66, 63, 66, 70, 74, 77, 74, 71, 68, 65, 68, 71, 74, 75};
int layer3_index = 0;

// Layer 4: Layer_4 (manual mode) - 47 keyframes
const int layer4_count = 47;
const unsigned long layer4_times[] PROGMEM = {18, 786, 1757, 1834, 2100, 2573, 2729, 3197, 3259, 3529, 3657, 3777, 3864, 4064, 4448, 5151, 5682, 5807, 6211, 6415, 6591, 6895, 6951, 7007, 7502, 7659, 7805, 7971, 8382, 8502, 8669, 8838, 9373, 9492, 9589, 10045, 10109, 10229, 10495, 10684, 10805, 10909, 11260, 11341, 11434, 11756, 12291};
const int layer4_servo5[] PROGMEM = {  // Shoulder (OWNED)
  16, 20, 23, 26, 29, 26, 23, 26, 30, 33, 30, 27, 23, 20, 23, 20, 23, 26, 23, 20, 16, 13, 18, 21, 24, 21, 18, 14, 18, 21, 24, 27, 24, 21, 18, 21, 24, 27, 30, 27, 24, 21, 18, 21, 24, 27, 26};
int layer4_index = 0;

void setup() {
  Serial.begin(9600);
  
  // Attach servos
  for(int i = 0; i < 8; i++) {
    servo[i].attach(servoPins[i]);
    writeServo(i, 90);  // Center position
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

  // Update layer 1 with interpolation (OWNS: Thumb, Index, Middle, Ring, Pinky)
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
        
        writeServo(0, interpolated);
      } else if(curr0 != -1) {
        int pos = curr0;
        
        // Apply blend zone for smooth looping
        if(isBlending && start0 != -1) {
          pos = pos * (1.0 - blendFactor) + start0 * blendFactor;
        }
        
        writeServo(0, pos);
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
        
        writeServo(1, interpolated);
      } else if(curr1 != -1) {
        int pos = curr1;
        
        // Apply blend zone for smooth looping
        if(isBlending && start1 != -1) {
          pos = pos * (1.0 - blendFactor) + start1 * blendFactor;
        }
        
        writeServo(1, pos);
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
        
        writeServo(2, interpolated);
      } else if(curr2 != -1) {
        int pos = curr2;
        
        // Apply blend zone for smooth looping
        if(isBlending && start2 != -1) {
          pos = pos * (1.0 - blendFactor) + start2 * blendFactor;
        }
        
        writeServo(2, pos);
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
        
        writeServo(3, interpolated);
      } else if(curr3 != -1) {
        int pos = curr3;
        
        // Apply blend zone for smooth looping
        if(isBlending && start3 != -1) {
          pos = pos * (1.0 - blendFactor) + start3 * blendFactor;
        }
        
        writeServo(3, pos);
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
        
        writeServo(4, interpolated);
      } else if(curr4 != -1) {
        int pos = curr4;
        
        // Apply blend zone for smooth looping
        if(isBlending && start4 != -1) {
          pos = pos * (1.0 - blendFactor) + start4 * blendFactor;
        }
        
        writeServo(4, pos);
      }
    }
  }

  // Update layer 2 with interpolation (OWNS: Wrist)
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
        
        writeServo(7, interpolated);
      } else if(curr7 != -1) {
        int pos = curr7;
        
        // Apply blend zone for smooth looping
        if(isBlending && start7 != -1) {
          pos = pos * (1.0 - blendFactor) + start7 * blendFactor;
        }
        
        writeServo(7, pos);
      }
    }
  }

  // Update layer 3 with interpolation (OWNS: Elbow)
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
        
        writeServo(6, interpolated);
      } else if(curr6 != -1) {
        int pos = curr6;
        
        // Apply blend zone for smooth looping
        if(isBlending && start6 != -1) {
          pos = pos * (1.0 - blendFactor) + start6 * blendFactor;
        }
        
        writeServo(6, pos);
      }
    }
  }

  // Update layer 4 with interpolation (OWNS: Shoulder)
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
        
        writeServo(5, interpolated);
      } else if(curr5 != -1) {
        int pos = curr5;
        
        // Apply blend zone for smooth looping
        if(isBlending && start5 != -1) {
          pos = pos * (1.0 - blendFactor) + start5 * blendFactor;
        }
        
        writeServo(5, pos);
      }
    }
  }

  delay(5); // 200Hz update rate for smooth interpolation
}
