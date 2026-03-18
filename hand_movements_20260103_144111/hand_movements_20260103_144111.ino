/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-01-03 14:41:11
 * Layers: 4
 * Original Frames Recorded: 8415
 * Loop Duration: 26.31s (recorded) / 17.54s (at 1.5x speed)
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
unsigned long loopDuration = 17540; // milliseconds (adjusted for 1.5x speed)

// Layer data structures

// Layer 1: Layer_1 (manual mode) - 50 keyframes
const int layer1_count = 50;
const unsigned long layer1_times[] PROGMEM = {0, 1228, 1591, 2010, 2320, 2587, 2889, 3403, 3843, 4185, 5013, 5349, 5623, 5803, 6057, 6332, 6669, 6970, 7326, 7544, 7696, 7886, 8052, 9806, 9925, 10269, 10394, 10652, 10824, 11111, 11282, 11528, 11719, 11948, 12143, 12290, 12493, 12675, 12846, 13054, 13354, 13555, 13790, 14079, 14404, 14519, 15349, 15512, 16510, 17527};
const int layer1_servo5[] PROGMEM = {139, 136, 133, 130, 127, 123, 120, 117, 114, 111, 108, 105, 102, 99, 96, 93, 90, 86, 83, 80, 77, 74, 71, 74, 77, 80, 83, 86, 90, 93, 96, 99, 102, 105, 108, 111, 114, 117, 120, 123, 127, 130, 133, 136, 139, 142, 145, 148, 145, 145};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 39 keyframes
const int layer2_count = 39;
const unsigned long layer2_times[] PROGMEM = {17, 617, 974, 1854, 2150, 2479, 2708, 2867, 4388, 5065, 5477, 5898, 6111, 7727, 7948, 8517, 8807, 9544, 9808, 10132, 10197, 10260, 10368, 11455, 11942, 12044, 12243, 12794, 12993, 13187, 13461, 13728, 13974, 14334, 14843, 14919, 15046, 15263, 17521};
const int layer2_servo6[] PROGMEM = {55, 58, 61, 64, 67, 70, 74, 77, 80, 83, 86, 89, 92, 95, 98, 101, 104, 101, 98, 95, 92, 89, 86, 83, 80, 77, 74, 70, 67, 64, 61, 58, 55, 52, 49, 46, 43, 40, 40};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 239 keyframes
const int layer3_count = 239;
const unsigned long layer3_times[] PROGMEM = {17, 680, 714, 754, 806, 851, 905, 944, 1000, 1035, 1069, 1104, 1140, 1189, 1226, 1295, 1378, 1420, 1457, 1494, 1531, 1574, 1612, 1652, 1689, 1746, 1802, 1860, 1906, 1968, 2044, 2137, 2410, 2465, 2513, 2567, 2605, 2642, 2679, 2713, 2748, 2789, 2846, 2909, 2956, 3021, 3080, 3120, 3160, 3211, 3271, 3325, 3639, 3678, 3713, 3756, 3794, 3834, 3887, 3922, 3958, 3999, 4034, 4084, 4121, 4159, 4203, 4247, 4307, 4437, 4474, 4511, 4549, 4585, 4626, 4662, 4710, 4783, 4834, 4870, 4904, 4949, 4983, 5020, 5057, 5095, 5131, 5168, 5214, 5275, 5385, 5431, 5487, 5561, 5617, 5666, 5731, 5793, 5847, 5899, 5936, 5974, 6011, 6047, 6081, 6117, 6152, 6195, 6232, 6285, 6324, 6366, 6426, 6528, 6622, 6704, 6746, 6801, 6846, 6893, 6950, 6995, 7045, 7083, 7134, 7188, 7241, 7305, 7342, 7384, 7421, 7475, 7531, 7611, 7821, 7919, 8255, 8499, 8546, 8611, 8675, 8723, 8759, 8800, 8848, 8958, 9034, 9143, 9394, 9430, 9471, 9504, 9542, 9578, 9612, 9650, 9698, 9739, 9776, 9818, 9860, 9900, 9943, 10017, 10086, 10188, 10350, 10478, 10810, 10919, 10961, 11012, 11122, 11376, 11978, 12045, 12104, 12158, 12213, 12292, 12346, 12383, 12420, 12456, 12493, 12537, 12576, 12612, 12650, 12686, 12727, 12763, 12802, 12844, 12878, 12913, 12954, 12987, 13024, 13060, 13107, 13163, 13221, 13306, 13412, 13519, 14360, 14397, 14444, 14480, 14531, 14568, 14696, 14777, 14814, 14848, 15966, 16105, 16198, 16244, 16292, 16350, 16392, 16452, 16498, 16540, 16577, 16629, 16682, 16741, 16795, 17132, 17182, 17220, 17255, 17313, 17382, 17478, 17531};
const int layer3_servo7[] PROGMEM = {15, 19, 24, 28, 31, 34, 38, 41, 44, 50, 54, 58, 63, 66, 69, 73, 76, 79, 82, 85, 88, 92, 95, 99, 102, 105, 109, 112, 115, 118, 121, 124, 121, 118, 115, 112, 109, 105, 101, 97, 94, 91, 87, 84, 81, 78, 75, 72, 69, 66, 63, 60, 63, 66, 73, 76, 79, 82, 85, 89, 92, 95, 98, 101, 104, 108, 111, 114, 117, 114, 111, 108, 104, 100, 97, 94, 91, 88, 85, 82, 79, 76, 73, 68, 65, 62, 59, 56, 52, 49, 52, 56, 59, 62, 65, 68, 71, 74, 77, 80, 83, 86, 90, 93, 96, 99, 103, 106, 110, 113, 116, 119, 122, 125, 128, 125, 122, 119, 116, 113, 110, 106, 103, 100, 97, 94, 91, 88, 85, 82, 79, 76, 73, 69, 66, 63, 66, 63, 60, 57, 54, 51, 48, 45, 42, 39, 36, 32, 37, 42, 46, 54, 62, 71, 76, 79, 82, 86, 93, 96, 99, 102, 105, 109, 112, 115, 118, 121, 124, 127, 130, 133, 136, 139, 136, 133, 130, 127, 124, 121, 118, 114, 111, 107, 104, 101, 98, 94, 90, 86, 83, 80, 77, 74, 70, 66, 62, 57, 53, 49, 46, 43, 40, 37, 34, 31, 34, 41, 44, 51, 55, 58, 61, 57, 52, 49, 39, 42, 39, 36, 33, 30, 27, 24, 20, 17, 14, 11, 8, 5, 2, 5, 8, 11, 15, 18, 21, 24, 27};
int layer3_index = 0;

// Layer 4: Layer_4 (cursor mode) - 219 keyframes
const int layer4_count = 219;
const unsigned long layer4_times[] PROGMEM = {10, 282, 354, 429, 498, 573, 698, 822, 892, 961, 1031, 1109, 1184, 1253, 1322, 1392, 1461, 1531, 1599, 1669, 1739, 1808, 1878, 1947, 2016, 2085, 2155, 2225, 2295, 2365, 2441, 2508, 2576, 2646, 2719, 2793, 2864, 2931, 3001, 3076, 3146, 3234, 3303, 3373, 3442, 3511, 3585, 3656, 3724, 3795, 3864, 3937, 4007, 4074, 4141, 4211, 4279, 4349, 4418, 4486, 4554, 4627, 4696, 4767, 4834, 4904, 4973, 5048, 5116, 5186, 5256, 5335, 5409, 5488, 5558, 5626, 5696, 5765, 5835, 5904, 5972, 6039, 6118, 7941, 8015, 8117, 8223, 8291, 8361, 8431, 8499, 8569, 8644, 8714, 8782, 8857, 8926, 8997, 9064, 9135, 9204, 9273, 9343, 9413, 9482, 9550, 9621, 9695, 9763, 9834, 9903, 9973, 10042, 10111, 10181, 10255, 10325, 10392, 10463, 10532, 10599, 10667, 10736, 10815, 10884, 10954, 11028, 11097, 11168, 11237, 11306, 11374, 11445, 11519, 11588, 11657, 11727, 11801, 11871, 11940, 12038, 12106, 12180, 12260, 12333, 12402, 12471, 12542, 12612, 12680, 12750, 12820, 12888, 12958, 13026, 13095, 13166, 13236, 13305, 13374, 13467, 13536, 13606, 13680, 13749, 13820, 13888, 13958, 14026, 14097, 14166, 14234, 14305, 14378, 14449, 14517, 14585, 14662, 14731, 14800, 14911, 14979, 15051, 15119, 15189, 15258, 15326, 15392, 15466, 15541, 15614, 15688, 15757, 15827, 15901, 15970, 16040, 16114, 16184, 16253, 16322, 16396, 16466, 16535, 16609, 16679, 16747, 16817, 16887, 16956, 17023, 17090, 17160, 17229, 17299, 17377, 17447, 17521, 17535};
const int layer4_servo0[] PROGMEM = {50, 55, 63, 72, 82, 87, 93, 93, 71, 62, 49, 38, 33, 29, 34, 47, 61, 74, 83, 96, 103, 107, 99, 85, 65, 54, 50, 50, 49, 48, 44, 38, 47, 54, 62, 72, 82, 90, 99, 105, 104, 100, 89, 75, 69, 66, 64, 63, 62, 60, 56, 48, 45, 49, 71, 84, 101, 117, 130, 139, 145, 143, 137, 120, 110, 96, 87, 82, 80, 80, 77, 72, 63, 57, 52, 43, 57, 75, 84, 100, 107, 111, 109, 89, 87, 83, 78, 74, 59, 60, 76, 92, 114, 124, 133, 139, 144, 145, 148, 153, 163, 168, 176, 177, 171, 163, 149, 130, 122, 111, 106, 100, 97, 93, 88, 81, 68, 57, 38, 23, 23, 34, 54, 60, 65, 71, 80, 84, 85, 82, 78, 82, 89, 99, 143, 160, 168, 167, 161, 152, 148, 140, 134, 128, 125, 120, 118, 110, 98, 86, 77, 64, 45, 24, 18, 19, 21, 28, 41, 47, 52, 60, 69, 72, 70, 69, 72, 77, 84, 94, 111, 117, 148, 154, 160, 159, 155, 150, 141, 132, 127, 121, 119, 117, 116, 113, 109, 103, 94, 87, 75, 62, 49, 38, 31, 30, 30, 33, 36, 40, 46, 50, 53, 60, 67, 76, 94, 104, 113, 127, 136, 145, 159, 163, 162, 158, 154, 150, 148};
const int layer4_servo1[] PROGMEM = {99, 100, 101, 103, 104, 104, 106, 110, 124, 121, 112, 99, 92, 90, 98, 106, 110, 112, 112, 115, 122, 133, 142, 141, 128, 112, 97, 88, 79, 72, 72, 90, 110, 117, 123, 128, 131, 133, 136, 141, 158, 157, 151, 138, 125, 114, 104, 92, 85, 79, 76, 81, 88, 112, 128, 131, 130, 127, 125, 133, 156, 163, 169, 172, 169, 160, 146, 131, 107, 97, 87, 84, 84, 79, 78, 95, 120, 132, 137, 148, 155, 165, 172, 133, 128, 122, 119, 116, 117, 120, 135, 137, 130, 123, 115, 106, 97, 89, 88, 91, 102, 110, 127, 139, 152, 160, 166, 167, 165, 158, 153, 147, 142, 133, 128, 126, 121, 116, 101, 77, 58, 45, 38, 41, 44, 50, 58, 65, 72, 86, 119, 136, 152, 162, 170, 156, 138, 126, 113, 97, 92, 81, 74, 69, 66, 66, 70, 80, 93, 101, 104, 105, 102, 87, 72, 62, 54, 49, 49, 49, 53, 58, 67, 73, 80, 90, 121, 135, 146, 157, 167, 168, 156, 147, 125, 115, 104, 94, 82, 71, 66, 61, 60, 63, 68, 73, 81, 89, 96, 101, 105, 107, 105, 101, 95, 90, 86, 84, 84, 86, 90, 93, 99, 111, 123, 137, 157, 163, 168, 170, 168, 165, 149, 136, 124, 110, 101, 94, 91};
const int layer4_servo2[] PROGMEM = {58, 55, 51, 48, 44, 42, 44, 49, 89, 97, 109, 115, 114, 109, 100, 84, 71, 60, 56, 54, 61, 76, 95, 110, 129, 138, 140, 139, 135, 131, 129, 127, 117, 109, 104, 96, 90, 86, 85, 89, 124, 129, 138, 150, 154, 155, 154, 149, 144, 140, 136, 135, 135, 124, 100, 88, 74, 64, 62, 69, 94, 102, 113, 136, 146, 160, 170, 172, 165, 158, 150, 147, 144, 139, 136, 132, 115, 105, 102, 106, 113, 132, 158, 179, 176, 172, 168, 164, 143, 140, 114, 92, 68, 59, 54, 52, 54, 59, 66, 76, 84, 84, 87, 88, 92, 96, 105, 116, 118, 115, 110, 104, 97, 83, 78, 81, 86, 92, 102, 111, 111, 108, 100, 102, 104, 110, 118, 126, 134, 149, 168, 169, 165, 157, 112, 93, 82, 78, 72, 65, 62, 56, 52, 46, 41, 33, 28, 24, 29, 39, 46, 56, 74, 96, 105, 109, 109, 109, 112, 113, 117, 121, 131, 136, 143, 150, 162, 163, 159, 152, 137, 131, 93, 83, 72, 69, 66, 64, 59, 53, 47, 40, 35, 29, 26, 23, 24, 27, 33, 39, 49, 62, 76, 89, 101, 110, 117, 122, 126, 130, 136, 140, 143, 149, 153, 155, 148, 142, 135, 123, 113, 104, 86, 78, 73, 68, 66, 63, 63};
const int layer4_servo3[] PROGMEM = {9, 10, 12, 16, 22, 26, 30, 31, 36, 38, 45, 54, 54, 48, 36, 24, 21, 23, 26, 35, 42, 49, 52, 54, 65, 81, 93, 100, 106, 107, 101, 76, 53, 46, 43, 41, 41, 43, 48, 52, 70, 72, 75, 87, 98, 106, 114, 120, 122, 121, 116, 102, 92, 61, 43, 41, 45, 54, 67, 76, 82, 82, 82, 84, 87, 97, 111, 123, 137, 141, 140, 135, 124, 116, 111, 81, 52, 47, 49, 58, 65, 78, 96, 135, 136, 132, 127, 122, 86, 80, 54, 47, 52, 60, 71, 85, 101, 115, 125, 138, 145, 143, 137, 125, 110, 100, 87, 78, 75, 68, 63, 57, 52, 44, 38, 36, 33, 33, 39, 57, 76, 96, 116, 120, 125, 131, 140, 145, 147, 146, 127, 115, 103, 94, 85, 96, 112, 118, 119, 119, 118, 115, 111, 106, 99, 88, 76, 54, 34, 24, 19, 15, 17, 33, 51, 66, 76, 88, 104, 111, 116, 123, 133, 135, 133, 129, 113, 105, 97, 89, 81, 79, 85, 91, 107, 113, 118, 120, 118, 113, 108, 100, 93, 83, 74, 63, 52, 41, 30, 25, 19, 17, 19, 26, 38, 50, 62, 71, 78, 84, 92, 97, 97, 99, 97, 93, 85, 82, 80, 80, 81, 84, 96, 105, 111, 116, 119, 119, 120};
const int layer4_servo4[] PROGMEM = {50, 55, 63, 72, 82, 87, 93, 93, 71, 62, 49, 38, 33, 29, 34, 47, 61, 74, 83, 96, 103, 107, 99, 85, 65, 54, 50, 50, 49, 48, 44, 38, 47, 54, 62, 72, 82, 90, 99, 105, 104, 100, 89, 75, 69, 66, 64, 63, 62, 60, 56, 48, 45, 49, 71, 84, 101, 117, 130, 139, 145, 143, 137, 120, 110, 96, 87, 82, 80, 80, 77, 72, 63, 57, 52, 43, 57, 75, 84, 100, 107, 111, 109, 89, 87, 83, 78, 74, 59, 60, 76, 92, 114, 124, 133, 139, 144, 145, 148, 153, 163, 168, 176, 177, 171, 163, 149, 130, 122, 111, 106, 100, 97, 93, 88, 81, 68, 57, 38, 23, 23, 34, 54, 60, 65, 71, 80, 84, 85, 82, 78, 82, 89, 99, 143, 160, 168, 167, 161, 152, 148, 140, 134, 128, 125, 120, 118, 110, 98, 86, 77, 64, 45, 24, 18, 19, 21, 28, 41, 47, 52, 60, 69, 72, 70, 69, 72, 77, 84, 94, 111, 117, 148, 154, 160, 159, 155, 150, 141, 132, 127, 121, 119, 117, 116, 113, 109, 103, 94, 87, 75, 62, 49, 38, 31, 30, 30, 33, 36, 40, 46, 50, 53, 60, 67, 76, 94, 104, 113, 127, 136, 145, 159, 163, 162, 158, 154, 150, 148};
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
