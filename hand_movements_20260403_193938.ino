/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-04-03 19:39:38
 * Hardware Config: Default
 * Layers: 4
 * Original Frames Recorded: 3456
 * Loop Duration: 5.96s (recorded) / 3.97s (at 1.5x speed)
 * Playback Speed: 1.5x
 * 
 * Layer Priority (later layers override earlier for same servo):
 * Servo 0 (Thumb): Layer 4
 * Servo 1 (Index): Layer 4
 * Servo 2 (Middle): Layer 4
 * Servo 3 (Ring): Layer 4
 * Servo 4 (Pinky): Layer 4
 * Servo 5 (Shoulder): Layer 3
 * Servo 6 (Elbow): Layer 2
 * Servo 7 (Wrist): Layer 1
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
const int MAX_ANGLE = 45;

// Helper: Map 0-180 to MIN-MAX, reverse specified servos
void writeServo(int index, int pos) {
  pos = map(pos, 0, 180, MIN_ANGLE, MAX_ANGLE);
  pos = constrain(pos, MIN_ANGLE, MAX_ANGLE);
  if(index == 2 || index == 3) pos = MAX_ANGLE - pos;  // Reverse Middle, Ring
  servo[index].write(pos);
}

// Timing
unsigned long loopStartTime;
unsigned long loopDuration = 3973; // milliseconds (adjusted for 1.5x speed)

// Layer data structures

// Layer 1: Layer_1 (manual mode) - 78 keyframes
const int layer1_count = 78;
const unsigned long layer1_times[] PROGMEM = {1, 302, 338, 372, 409, 443, 479, 515, 553, 588, 754, 788, 823, 857, 890, 926, 965, 999, 1035, 1068, 1104, 1139, 1265, 1300, 1336, 1373, 1410, 1448, 1482, 1518, 1552, 1588, 1624, 1658, 1694, 1731, 1850, 1887, 1921, 1956, 1990, 2029, 2065, 2099, 2135, 2172, 2208, 2244, 2278, 2332, 2370, 2427, 2499, 2533, 2567, 2602, 2638, 2673, 2709, 2748, 2784, 2822, 2859, 2897, 2936, 2973, 3073, 3111, 3145, 3183, 3218, 3254, 3289, 3330, 3368, 3405, 3465, 3966};
const int layer1_servo7[] PROGMEM = {  // Wrist (OWNED)
  72, 76, 85, 103, 118, 125, 129, 136, 144, 148, 145, 140, 133, 125, 117, 113, 108, 101, 90, 77, 67, 59, 62, 69, 75, 81, 88, 92, 95, 103, 113, 131, 142, 149, 152, 155, 152, 144, 135, 126, 120, 113, 105, 95, 82, 74, 64, 55, 49, 46, 41, 38, 41, 50, 56, 63, 71, 81, 95, 104, 110, 118, 124, 130, 133, 137, 134, 123, 114, 108, 103, 95, 86, 82, 78, 74, 71, 70};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 56 keyframes
const int layer2_count = 56;
const unsigned long layer2_times[] PROGMEM = {3, 428, 506, 542, 589, 623, 831, 864, 899, 939, 976, 1110, 1151, 1269, 1322, 1387, 1424, 1466, 1600, 1635, 1673, 1713, 1776, 1833, 2054, 2090, 2126, 2171, 2208, 2245, 2292, 2475, 2510, 2543, 2581, 2625, 2661, 2714, 2772, 2913, 2953, 2994, 3035, 3077, 3125, 3238, 3274, 3322, 3374, 3412, 3580, 3614, 3647, 3687, 3733, 3965};
const int layer2_servo6[] PROGMEM = {  // Elbow (OWNED)
  70, 74, 77, 80, 83, 88, 85, 80, 73, 69, 65, 62, 59, 62, 65, 68, 73, 76, 73, 66, 63, 59, 56, 53, 56, 61, 64, 68, 73, 76, 79, 76, 70, 67, 64, 61, 58, 55, 51, 55, 63, 68, 72, 75, 78, 74, 70, 67, 63, 60, 64, 69, 73, 77, 80, 79};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 57 keyframes
const int layer3_count = 57;
const unsigned long layer3_times[] PROGMEM = {4, 74, 110, 153, 239, 342, 382, 451, 492, 570, 660, 910, 948, 981, 1022, 1101, 1203, 1240, 1289, 1324, 1363, 1432, 1491, 1588, 1625, 1667, 1709, 1747, 1784, 2013, 2050, 2094, 2147, 2378, 2415, 2451, 2499, 2536, 2741, 2775, 2812, 2902, 3026, 3191, 3227, 3262, 3303, 3351, 3414, 3578, 3623, 3659, 3694, 3729, 3815, 3948, 3959};
const int layer3_servo5[] PROGMEM = {  // Shoulder (OWNED)
  108, 112, 115, 120, 123, 120, 112, 109, 105, 102, 99, 103, 109, 115, 118, 122, 119, 113, 110, 107, 104, 100, 97, 100, 108, 112, 115, 118, 122, 119, 115, 112, 108, 111, 117, 120, 123, 127, 124, 119, 114, 111, 108, 111, 114, 118, 121, 124, 128, 124, 121, 114, 111, 106, 103, 107, 110};
int layer3_index = 0;

// Layer 4: Layer_4 (cursor mode) - 112 keyframes
const int layer4_count = 112;
const unsigned long layer4_times[] PROGMEM = {3, 131, 166, 201, 235, 270, 305, 339, 374, 408, 443, 478, 513, 547, 582, 616, 651, 686, 720, 757, 792, 826, 860, 893, 928, 963, 998, 1032, 1067, 1104, 1150, 1184, 1219, 1253, 1288, 1323, 1357, 1392, 1427, 1462, 1498, 1534, 1568, 1603, 1637, 1672, 1707, 1742, 1776, 1811, 1845, 1880, 1915, 1949, 1984, 2019, 2053, 2088, 2123, 2157, 2192, 2227, 2261, 2296, 2342, 2376, 2411, 2445, 2480, 2514, 2549, 2584, 2618, 2653, 2688, 2722, 2757, 2792, 2825, 2859, 2893, 2928, 2962, 2997, 3031, 3066, 3101, 3136, 3170, 3205, 3239, 3274, 3309, 3343, 3378, 3413, 3447, 3482, 3517, 3551, 3587, 3621, 3655, 3690, 3725, 3762, 3804, 3845, 3880, 3927, 3962, 3970};
const int layer4_servo0[] PROGMEM = {  // Thumb (OWNED)
  152, 156, 160, 155, 147, 138, 132, 129, 122, 102, 81, 65, 56, 49, 43, 41, 42, 47, 52, 59, 67, 81, 93, 104, 116, 125, 134, 136, 141, 141, 140, 138, 131, 125, 112, 96, 84, 74, 63, 59, 61, 68, 75, 89, 113, 129, 147, 159, 162, 161, 157, 151, 145, 138, 129, 125, 121, 116, 110, 100, 92, 86, 85, 86, 87, 86, 84, 80, 74, 69, 66, 60, 53, 45, 37, 29, 24, 23, 28, 43, 65, 85, 103, 112, 124, 132, 141, 154, 165, 170, 170, 162, 151, 144, 135, 130, 127, 126, 126, 125, 123, 119, 112, 106, 102, 105, 108, 112, 115, 114, 111, 110};
const int layer4_servo1[] PROGMEM = {  // Index (OWNED)
  127, 130, 123, 111, 103, 97, 93, 95, 100, 111, 116, 115, 114, 112, 109, 108, 109, 113, 118, 124, 134, 146, 154, 158, 160, 159, 155, 151, 146, 136, 130, 120, 115, 111, 118, 125, 127, 127, 125, 125, 128, 135, 142, 154, 167, 169, 165, 153, 139, 125, 111, 97, 90, 82, 73, 75, 81, 91, 100, 113, 123, 132, 138, 141, 144, 145, 147, 146, 140, 133, 126, 114, 99, 88, 79, 78, 81, 85, 94, 109, 119, 126, 131, 136, 142, 146, 147, 148, 143, 132, 117, 103, 86, 78, 69, 64, 61, 61, 66, 78, 90, 103, 116, 125, 133, 137, 141, 146, 155, 157, 159, 160};
const int layer4_servo2[] PROGMEM = {  // Middle (OWNED)
  118, 115, 118, 127, 135, 143, 148, 148, 145, 130, 110, 95, 84, 72, 59, 53, 46, 37, 31, 28, 27, 31, 38, 48, 58, 68, 81, 88, 97, 109, 115, 126, 131, 135, 124, 106, 92, 78, 63, 51, 40, 29, 24, 26, 38, 53, 73, 92, 106, 117, 126, 133, 139, 146, 155, 159, 159, 154, 145, 127, 107, 84, 68, 61, 56, 51, 40, 28, 16, 11, 10, 14, 22, 31, 40, 45, 50, 56, 60, 70, 85, 95, 100, 98, 95, 94, 95, 98, 102, 109, 114, 120, 124, 127, 132, 137, 143, 150, 156, 158, 153, 143, 126, 112, 97, 91, 86, 81, 67, 62, 53, 51};
const int layer4_servo3[] PROGMEM = {  // Ring (OWNED)
  124, 119, 111, 111, 118, 130, 138, 143, 155, 168, 167, 160, 150, 138, 121, 111, 101, 89, 83, 82, 86, 96, 105, 113, 120, 124, 128, 130, 132, 135, 136, 139, 146, 152, 160, 159, 154, 144, 130, 115, 101, 89, 84, 91, 104, 113, 118, 117, 115, 111, 106, 103, 107, 112, 121, 135, 148, 160, 166, 168, 161, 147, 134, 127, 123, 117, 106, 91, 72, 58, 50, 43, 41, 46, 55, 68, 85, 100, 115, 135, 151, 155, 153, 148, 141, 136, 131, 122, 112, 100, 87, 81, 74, 73, 75, 81, 88, 100, 118, 138, 150, 158, 161, 158, 151, 147, 142, 137, 127, 123, 117, 115};
const int layer4_servo4[] PROGMEM = {  // Pinky (OWNED)
  118, 124, 135, 135, 128, 116, 108, 102, 87, 55, 32, 20, 16, 16, 19, 22, 28, 37, 43, 46, 48, 52, 56, 61, 69, 76, 85, 88, 95, 98, 99, 101, 93, 85, 66, 47, 37, 31, 27, 31, 38, 47, 53, 59, 70, 81, 99, 117, 127, 134, 140, 141, 137, 131, 122, 110, 98, 83, 69, 52, 43, 40, 42, 44, 46, 47, 49, 53, 58, 64, 68, 70, 71, 66, 58, 44, 31, 20, 14, 13, 23, 37, 54, 63, 75, 85, 95, 112, 129, 145, 158, 160, 160, 157, 152, 146, 141, 134, 123, 108, 94, 80, 66, 57, 53, 56, 59, 63, 67, 67, 65, 65};
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

  // Update layer 1 with interpolation (OWNS: Wrist)
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
      
      // Interpolate Wrist
      int curr7 = pgm_read_word(&layer1_servo7[layer1_index]);
      int next7 = pgm_read_word(&layer1_servo7[layer1_index + 1]);
      int start7 = pgm_read_word(&layer1_servo7[0]);
      
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

  // Update layer 2 with interpolation (OWNS: Elbow)
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

  // Update layer 3 with interpolation (OWNS: Shoulder)
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
      
      // Interpolate Shoulder
      int curr5 = pgm_read_word(&layer3_servo5[layer3_index]);
      int next5 = pgm_read_word(&layer3_servo5[layer3_index + 1]);
      int start5 = pgm_read_word(&layer3_servo5[0]);
      
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

  // Update layer 4 with interpolation (OWNS: Thumb, Index, Middle, Ring, Pinky)
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
      int curr1 = pgm_read_word(&layer4_servo1[layer4_index]);
      int next1 = pgm_read_word(&layer4_servo1[layer4_index + 1]);
      int start1 = pgm_read_word(&layer4_servo1[0]);
      
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
      int curr2 = pgm_read_word(&layer4_servo2[layer4_index]);
      int next2 = pgm_read_word(&layer4_servo2[layer4_index + 1]);
      int start2 = pgm_read_word(&layer4_servo2[0]);
      
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
      int curr3 = pgm_read_word(&layer4_servo3[layer4_index]);
      int next3 = pgm_read_word(&layer4_servo3[layer4_index + 1]);
      int start3 = pgm_read_word(&layer4_servo3[0]);
      
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
      int curr4 = pgm_read_word(&layer4_servo4[layer4_index]);
      int next4 = pgm_read_word(&layer4_servo4[layer4_index + 1]);
      int start4 = pgm_read_word(&layer4_servo4[0]);
      
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

  delay(5); // 200Hz update rate for smooth interpolation
}
