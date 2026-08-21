/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-06-07 19:18:25
 * Hardware Config: Default
 * Layers: 2
 * Original Frames Recorded: 3203
 * Loop Duration: 15.82s (recorded) / 22.60s (at 0.7x speed)
 * Playback Speed: 0.7x
 * 
 * Layer Priority (later layers override earlier for same servo):
 * Servo 0 (Thumb): Layer 1
 * Servo 1 (Index): Layer 1
 * Servo 2 (Middle): Layer 1
 * Servo 3 (Ring): Layer 1
 * Servo 4 (Pinky): Layer 1
 * Servo 5 (Shoulder): Layer 2
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
unsigned long loopDuration = 22600; // milliseconds (adjusted for 0.7x speed)

// Startup pose (matches first recorded frame per owned servo)
const int startupPositions[8] = {120, 156, 159, 123, 114, 63, 90, 90};

// Layer data structures

// Layer 1: Layer_1 (cursor mode) - 142 keyframes
const int layer1_count = 142;
const unsigned long layer1_times[] PROGMEM = {21, 476, 626, 774, 924, 1073, 1220, 1496, 1666, 1813, 1963, 2112, 2261, 2409, 2618, 2763, 2911, 3060, 3244, 3393, 3575, 3724, 3872, 4022, 4171, 4319, 4467, 4610, 4756, 4918, 5074, 5221, 5373, 5519, 5667, 5831, 5975, 6127, 6284, 6432, 6581, 6730, 6880, 7029, 7177, 7322, 7474, 7622, 7778, 7930, 8076, 8226, 8387, 8534, 8695, 8844, 8993, 9142, 9293, 9449, 9602, 9747, 9895, 10041, 10193, 10340, 10491, 10639, 10784, 10936, 11085, 11236, 11381, 11531, 11680, 11828, 11976, 12127, 12274, 12423, 12571, 12719, 12867, 13017, 13165, 13314, 13473, 13621, 13770, 13930, 14083, 14228, 14376, 14577, 14731, 14874, 15022, 15165, 15314, 15467, 15610, 15760, 15942, 16092, 16252, 16396, 16550, 16738, 16903, 17048, 17199, 17349, 17492, 17638, 17794, 17940, 18086, 18239, 18390, 18546, 18708, 18858, 19005, 19155, 19303, 19451, 19598, 19748, 19908, 20058, 20207, 20355, 20514, 20663, 20816, 20998, 21143, 21292, 21531, 21745, 21896, 22580};
const int layer1_servo0[] PROGMEM = {  // Thumb (OWNED)
  120, 114, 108, 110, 113, 120, 124, 118, 113, 108, 100, 100, 101, 107, 113, 116, 118, 123, 125, 127, 123, 113, 109, 106, 109, 114, 119, 132, 130, 123, 116, 109, 104, 109, 117, 126, 151, 159, 159, 153, 138, 114, 80, 55, 47, 43, 45, 52, 64, 77, 82, 88, 89, 88, 91, 101, 112, 113, 98, 89, 73, 64, 57, 54, 48, 37, 29, 40, 56, 64, 65, 57, 45, 30, 17, 20, 38, 62, 72, 85, 87, 78, 72, 75, 85, 96, 101, 100, 114, 127, 134, 143, 146, 140, 129, 120, 117, 111, 103, 98, 95, 98, 103, 109, 116, 122, 127, 133, 138, 141, 144, 147, 156, 160, 164, 164, 159, 140, 128, 118, 116, 121, 128, 136, 143, 151, 161, 167, 169, 169, 167, 164, 155, 144, 137, 132, 122, 117, 113, 110, 110, 110};
const int layer1_servo1[] PROGMEM = {  // Index (OWNED)
  156, 150, 135, 123, 117, 111, 105, 101, 101, 101, 111, 119, 126, 136, 142, 143, 133, 125, 120, 116, 111, 109, 113, 120, 129, 131, 126, 117, 112, 106, 108, 113, 123, 144, 153, 159, 159, 147, 134, 122, 102, 80, 66, 60, 65, 72, 82, 85, 83, 73, 66, 55, 52, 52, 56, 66, 76, 78, 75, 74, 78, 78, 78, 84, 81, 68, 43, 22, 21, 29, 41, 56, 63, 62, 52, 29, 21, 27, 35, 55, 74, 97, 104, 110, 122, 133, 135, 117, 105, 103, 103, 107, 112, 105, 92, 87, 87, 89, 95, 103, 115, 128, 137, 145, 152, 157, 160, 162, 162, 160, 151, 147, 139, 136, 137, 130, 123, 116, 119, 130, 145, 157, 164, 169, 171, 171, 164, 156, 148, 142, 135, 128, 119, 113, 111, 111, 112, 115, 120, 126, 134, 136};
const int layer1_servo2[] PROGMEM = {  // Middle (OWNED)
  159, 158, 162, 158, 154, 145, 135, 132, 135, 137, 147, 152, 155, 161, 166, 170, 167, 161, 156, 150, 144, 145, 149, 155, 161, 165, 163, 149, 143, 137, 142, 150, 156, 156, 151, 144, 124, 112, 105, 101, 95, 92, 99, 97, 99, 96, 84, 70, 53, 37, 32, 36, 46, 57, 64, 75, 78, 85, 102, 106, 115, 113, 110, 107, 98, 89, 78, 52, 27, 14, 11, 19, 33, 47, 65, 65, 52, 37, 32, 31, 39, 67, 89, 103, 126, 139, 151, 151, 140, 129, 120, 104, 95, 91, 94, 101, 107, 117, 130, 139, 147, 151, 152, 153, 151, 149, 146, 142, 136, 129, 116, 111, 105, 107, 110, 114, 122, 142, 154, 165, 170, 168, 164, 158, 151, 141, 128, 120, 116, 115, 115, 118, 123, 130, 135, 140, 146, 151, 156, 160, 163, 164};
const int layer1_servo3[] PROGMEM = {  // Ring (OWNED)
  123, 123, 139, 151, 156, 160, 158, 154, 152, 149, 142, 137, 135, 137, 141, 147, 158, 165, 166, 166, 161, 155, 151, 147, 146, 153, 161, 169, 165, 159, 156, 152, 142, 122, 114, 109, 110, 118, 126, 129, 130, 127, 118, 97, 85, 71, 48, 35, 30, 34, 42, 65, 82, 93, 101, 111, 115, 122, 129, 126, 115, 105, 93, 80, 67, 61, 70, 75, 64, 47, 30, 15, 10, 13, 33, 62, 74, 73, 68, 57, 46, 44, 55, 66, 89, 103, 120, 139, 154, 157, 154, 140, 126, 124, 130, 136, 139, 143, 144, 140, 133, 125, 120, 118, 114, 113, 111, 110, 108, 106, 103, 105, 117, 126, 132, 146, 159, 170, 168, 160, 145, 134, 127, 122, 119, 117, 119, 126, 132, 138, 145, 152, 159, 164, 165, 165, 162, 159, 155, 149, 143, 142};
const int layer1_servo4[] PROGMEM = {  // Pinky (OWNED)
  114, 110, 109, 114, 119, 128, 132, 127, 121, 115, 105, 103, 103, 107, 113, 117, 122, 129, 132, 135, 130, 121, 115, 111, 111, 117, 124, 140, 138, 132, 124, 115, 107, 105, 111, 119, 143, 155, 158, 155, 143, 121, 88, 61, 50, 43, 40, 45, 56, 70, 78, 89, 93, 95, 98, 108, 118, 120, 106, 97, 79, 68, 59, 53, 45, 36, 33, 48, 63, 66, 63, 51, 36, 22, 14, 26, 46, 69, 77, 85, 82, 70, 64, 68, 80, 91, 99, 104, 122, 136, 142, 149, 148, 143, 135, 128, 125, 119, 111, 104, 98, 98, 100, 104, 110, 115, 120, 125, 130, 133, 137, 140, 153, 159, 163, 166, 165, 149, 136, 123, 116, 117, 122, 128, 134, 143, 154, 163, 167, 169, 169, 168, 162, 152, 145, 140, 130, 124, 119, 114, 111, 111};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 135 keyframes
const int layer2_count = 135;
const unsigned long layer2_times[] PROGMEM = {18, 271, 377, 525, 657, 801, 883, 1145, 1349, 2202, 2308, 2517, 2640, 2729, 2866, 3027, 3165, 3345, 3487, 3666, 3827, 3907, 3996, 4134, 4270, 4506, 4637, 4712, 4784, 4865, 4944, 5035, 5139, 5276, 5396, 5469, 5545, 5630, 5745, 6028, 6109, 6221, 6299, 6373, 6561, 6645, 6724, 6799, 6873, 7206, 7282, 7364, 7456, 7535, 7764, 7855, 7953, 8026, 8162, 8266, 8345, 8433, 8553, 8905, 8983, 9145, 9231, 9305, 9439, 9521, 9613, 9692, 9784, 9887, 10093, 10514, 10591, 10674, 10756, 10856, 11030, 11219, 11334, 11473, 11605, 11910, 12490, 12572, 12710, 12854, 12944, 13107, 13345, 13471, 13543, 14099, 14202, 14326, 14489, 14580, 14671, 14803, 15332, 15467, 15617, 15778, 15915, 15993, 16228, 16327, 17447, 17581, 17655, 17739, 18036, 18300, 18473, 18646, 18825, 19018, 19767, 19983, 20161, 20366, 21051, 21129, 21358, 21440, 21713, 21788, 21867, 22035, 22174, 22308, 22556};
const int layer2_servo5[] PROGMEM = {  // Shoulder (OWNED)
  63, 66, 72, 75, 78, 81, 84, 87, 90, 87, 83, 80, 76, 73, 69, 66, 63, 60, 56, 53, 49, 43, 39, 36, 32, 36, 39, 43, 47, 51, 54, 57, 61, 64, 68, 72, 77, 80, 83, 80, 76, 73, 69, 66, 62, 59, 52, 49, 46, 49, 55, 58, 62, 67, 70, 74, 77, 81, 84, 87, 92, 95, 98, 94, 91, 87, 84, 78, 75, 70, 67, 62, 59, 55, 52, 55, 58, 62, 66, 69, 73, 76, 79, 83, 86, 89, 86, 83, 80, 77, 74, 70, 67, 64, 61, 64, 68, 71, 75, 78, 82, 85, 82, 78, 75, 72, 69, 66, 62, 59, 63, 66, 69, 72, 76, 73, 69, 66, 63, 60, 64, 67, 70, 74, 70, 66, 63, 60, 57, 53, 50, 47, 44, 41, 39};
int layer2_index = 0;

void setup() {
  Serial.begin(9600);
  
  // Attach servos
  for(int i = 0; i < 8; i++) {
    servo[i].attach(servoPins[i]);
        writeServo(i, startupPositions[i]);
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

  // Update layer 2 with interpolation (OWNS: Shoulder)
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
      
      // Interpolate Shoulder
      int curr5 = pgm_read_word(&layer2_servo5[layer2_index]);
      int next5 = pgm_read_word(&layer2_servo5[layer2_index + 1]);
      int start5 = pgm_read_word(&layer2_servo5[0]);
      
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
