/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-01-03 15:32:06
 * Layers: 4
 * Original Frames Recorded: 7720
 * Loop Duration: 25.99s (recorded) / 17.33s (at 1.5x speed)
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
unsigned long loopDuration = 17326; // milliseconds (adjusted for 1.5x speed)

// Layer data structures

// Layer 1: Layer_1 (manual mode) - 40 keyframes
const int layer1_count = 40;
const unsigned long layer1_times[] PROGMEM = {14, 1001, 1134, 1301, 1551, 1757, 2259, 2828, 3022, 3212, 3406, 3645, 3990, 4174, 4501, 5345, 5694, 6154, 6622, 7431, 7612, 7693, 7968, 8074, 8203, 8333, 8560, 8690, 8826, 8981, 9113, 9244, 9423, 9604, 9791, 10110, 10480, 11766, 11944, 17310};
const int layer1_servo5[] PROGMEM = {129, 126, 123, 120, 117, 114, 111, 108, 104, 101, 98, 95, 92, 89, 86, 83, 80, 77, 74, 77, 80, 83, 86, 89, 92, 95, 98, 101, 104, 108, 111, 114, 117, 120, 123, 126, 129, 132, 135, 136};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 28 keyframes
const int layer2_count = 28;
const unsigned long layer2_times[] PROGMEM = {1, 700, 743, 1262, 1302, 1336, 1425, 2968, 3072, 3681, 4071, 6848, 7212, 7434, 7549, 7688, 8123, 8172, 8234, 8311, 8427, 9124, 9180, 9224, 9288, 9386, 11564, 17305};
const int layer2_servo6[] PROGMEM = {43, 46, 49, 52, 56, 60, 63, 66, 69, 73, 76, 73, 69, 73, 76, 79, 76, 73, 69, 66, 63, 60, 57, 54, 51, 48, 51, 52};
int layer2_index = 0;

// Layer 3: Layer_4 (cursor mode) - 237 keyframes
const int layer3_count = 237;
const unsigned long layer3_times[] PROGMEM = {5, 101, 171, 241, 313, 387, 461, 531, 609, 679, 758, 847, 941, 1012, 1081, 1154, 1274, 1425, 1507, 1577, 1683, 1770, 1858, 1932, 2001, 2071, 2140, 2214, 2283, 2353, 2431, 2499, 2572, 2644, 2713, 2787, 2861, 2936, 3004, 3074, 3142, 3218, 3286, 3370, 3444, 3514, 3583, 3657, 3727, 3812, 3879, 3949, 4016, 4088, 4157, 4226, 4296, 4369, 4438, 4508, 4578, 4652, 4720, 4790, 4859, 4930, 4998, 5067, 5141, 5220, 5289, 5358, 5428, 5496, 5567, 5636, 5704, 5775, 5848, 5918, 5988, 6071, 6143, 6214, 6293, 6367, 6441, 6510, 6579, 6649, 6718, 6788, 6856, 6927, 6996, 7063, 7130, 7204, 7273, 7347, 7430, 7500, 7572, 7648, 7717, 7787, 7855, 7925, 7995, 8064, 8138, 8212, 8330, 8402, 8471, 8545, 8615, 8683, 8753, 8824, 8891, 8961, 9030, 9099, 9167, 9234, 9304, 9372, 9442, 9511, 9581, 9650, 9727, 9799, 9885, 9956, 10025, 10095, 10163, 10233, 10311, 10387, 10454, 10524, 10598, 10668, 10737, 10806, 10876, 10945, 11015, 11084, 11153, 11233, 11306, 11378, 11449, 11519, 11588, 11662, 11736, 11814, 11888, 11958, 12032, 12106, 12176, 12244, 12317, 12389, 12463, 12531, 12600, 12670, 12740, 12809, 12878, 12966, 13041, 13109, 13179, 13253, 13364, 13443, 13543, 13623, 13718, 13799, 13873, 13971, 14073, 14141, 14215, 14286, 14355, 14424, 14493, 14567, 14636, 14704, 14775, 14849, 14919, 14988, 15057, 15124, 15191, 15261, 15330, 15436, 15506, 15575, 15645, 15714, 15783, 15853, 15927, 16001, 16070, 16140, 16210, 16279, 16346, 16418, 16487, 16556, 16625, 16719, 16787, 16861, 16936, 17005, 17074, 17144, 17212, 17284, 17314};
const int layer3_servo0[] PROGMEM = {121, 122, 123, 125, 129, 133, 138, 146, 148, 150, 149, 147, 145, 140, 131, 125, 119, 114, 113, 113, 113, 112, 112, 112, 111, 110, 110, 109, 109, 108, 106, 103, 100, 96, 89, 84, 75, 68, 61, 54, 48, 40, 37, 34, 30, 27, 25, 28, 32, 36, 39, 41, 44, 48, 52, 58, 64, 72, 82, 94, 113, 127, 138, 144, 143, 139, 133, 127, 121, 116, 113, 112, 111, 111, 111, 110, 108, 103, 99, 95, 91, 88, 87, 86, 86, 84, 84, 81, 79, 74, 66, 59, 53, 46, 41, 37, 39, 40, 43, 43, 38, 24, 18, 16, 15, 18, 26, 38, 52, 69, 84, 91, 95, 95, 88, 79, 70, 63, 57, 52, 47, 43, 44, 48, 56, 72, 86, 96, 108, 118, 124, 129, 133, 137, 142, 145, 146, 145, 141, 136, 131, 124, 117, 110, 101, 92, 83, 74, 66, 59, 51, 39, 36, 33, 29, 25, 22, 21, 21, 23, 27, 33, 38, 47, 57, 87, 101, 106, 111, 114, 118, 122, 123, 125, 126, 126, 126, 125, 125, 126, 126, 129, 135, 140, 146, 151, 155, 158, 161, 163, 164, 164, 164, 162, 158, 154, 146, 133, 121, 111, 103, 93, 82, 75, 67, 58, 53, 50, 43, 38, 35, 32, 30, 31, 40, 46, 57, 80, 108, 118, 120, 120, 120, 118, 116, 115, 116, 122, 129, 138, 151, 158, 164, 168, 169, 168, 166};
const int layer3_servo1[] PROGMEM = {74, 79, 88, 106, 112, 114, 114, 113, 111, 104, 97, 91, 86, 80, 72, 67, 62, 57, 55, 53, 53, 52, 52, 52, 52, 53, 57, 61, 65, 70, 75, 81, 86, 90, 95, 99, 102, 104, 104, 103, 101, 98, 96, 94, 90, 82, 71, 64, 61, 62, 72, 80, 88, 96, 105, 116, 124, 132, 139, 144, 145, 140, 129, 107, 94, 83, 73, 67, 62, 56, 53, 52, 51, 52, 56, 59, 63, 69, 75, 84, 89, 94, 99, 103, 107, 110, 113, 118, 121, 124, 122, 118, 114, 104, 94, 75, 59, 49, 42, 37, 36, 39, 47, 53, 61, 72, 85, 97, 107, 115, 121, 123, 128, 134, 137, 136, 130, 122, 117, 110, 105, 101, 104, 107, 113, 118, 119, 118, 114, 109, 106, 103, 103, 105, 110, 116, 125, 132, 138, 142, 144, 146, 148, 149, 148, 145, 140, 134, 127, 118, 108, 88, 82, 77, 71, 66, 67, 71, 75, 81, 87, 92, 96, 100, 103, 102, 96, 92, 89, 85, 83, 76, 73, 70, 68, 67, 66, 65, 65, 67, 68, 71, 76, 81, 86, 91, 96, 101, 107, 112, 118, 124, 133, 141, 147, 152, 156, 159, 159, 157, 155, 149, 142, 135, 126, 111, 101, 94, 87, 82, 80, 80, 83, 89, 100, 104, 108, 108, 92, 73, 68, 63, 60, 58, 58, 59, 63, 68, 73, 80, 91, 99, 110, 123, 133, 142, 145};
const int layer3_servo2[] PROGMEM = {37, 37, 39, 49, 54, 57, 59, 63, 64, 65, 67, 69, 71, 75, 79, 81, 79, 74, 69, 63, 58, 52, 48, 43, 38, 34, 28, 25, 24, 23, 24, 25, 27, 30, 35, 41, 49, 55, 61, 68, 74, 82, 87, 93, 98, 105, 110, 112, 114, 116, 122, 126, 129, 131, 134, 133, 131, 128, 120, 111, 95, 81, 70, 60, 59, 61, 64, 67, 68, 64, 58, 52, 47, 40, 32, 27, 23, 19, 20, 25, 29, 34, 39, 45, 51, 56, 61, 70, 79, 89, 99, 106, 112, 118, 122, 122, 116, 108, 102, 97, 96, 97, 100, 101, 100, 98, 94, 89, 83, 76, 73, 72, 78, 89, 101, 115, 124, 127, 126, 125, 121, 116, 110, 101, 93, 79, 68, 61, 54, 50, 48, 49, 50, 54, 59, 63, 69, 73, 78, 82, 85, 91, 96, 102, 109, 115, 121, 125, 127, 130, 129, 122, 120, 118, 114, 110, 106, 105, 101, 96, 91, 85, 79, 73, 64, 44, 36, 34, 33, 33, 34, 37, 40, 45, 51, 56, 60, 65, 71, 77, 83, 88, 90, 88, 87, 85, 84, 82, 81, 80, 79, 80, 82, 84, 88, 92, 97, 105, 113, 119, 124, 129, 134, 138, 139, 139, 137, 135, 128, 123, 120, 116, 112, 106, 94, 87, 76, 54, 34, 33, 37, 44, 51, 61, 74, 82, 90, 93, 93, 92, 89, 85, 84, 84, 85, 88, 89};
const int layer3_servo3[] PROGMEM = {85, 79, 75, 68, 71, 76, 83, 96, 101, 110, 119, 124, 129, 135, 139, 139, 137, 132, 127, 122, 117, 113, 107, 102, 97, 91, 81, 73, 67, 61, 55, 48, 41, 36, 30, 26, 21, 20, 19, 19, 20, 24, 28, 33, 39, 49, 65, 77, 85, 90, 89, 88, 86, 83, 81, 76, 72, 68, 63, 61, 62, 68, 78, 97, 107, 116, 124, 128, 127, 123, 117, 113, 106, 99, 87, 78, 67, 54, 44, 36, 31, 28, 28, 29, 30, 30, 31, 33, 36, 40, 43, 47, 51, 60, 68, 84, 95, 100, 103, 103, 98, 82, 71, 64, 54, 44, 34, 29, 28, 30, 36, 40, 44, 49, 53, 59, 64, 67, 67, 67, 63, 58, 50, 42, 36, 33, 36, 40, 48, 58, 67, 75, 80, 86, 91, 92, 90, 87, 81, 76, 72, 68, 65, 64, 63, 63, 64, 65, 67, 71, 73, 73, 73, 73, 71, 68, 61, 56, 47, 38, 31, 25, 22, 19, 18, 28, 41, 47, 54, 61, 70, 82, 90, 100, 109, 115, 120, 126, 131, 136, 141, 146, 148, 148, 147, 145, 142, 139, 136, 131, 125, 120, 113, 106, 99, 94, 87, 79, 75, 73, 72, 73, 75, 78, 81, 86, 90, 90, 85, 80, 75, 68, 59, 48, 34, 30, 25, 27, 50, 79, 89, 101, 110, 122, 132, 138, 144, 147, 149, 151, 149, 144, 138, 129, 122, 114, 110};
const int layer3_servo4[] PROGMEM = {121, 122, 123, 125, 129, 133, 138, 146, 148, 150, 149, 147, 145, 140, 131, 125, 119, 114, 113, 113, 113, 112, 112, 112, 111, 110, 110, 109, 109, 108, 106, 103, 100, 96, 89, 84, 75, 68, 61, 54, 48, 40, 37, 34, 30, 27, 25, 28, 32, 36, 39, 41, 44, 48, 52, 58, 64, 72, 82, 94, 113, 127, 138, 144, 143, 139, 133, 127, 121, 116, 113, 112, 111, 111, 111, 110, 108, 103, 99, 95, 91, 88, 87, 86, 86, 84, 84, 81, 79, 74, 66, 59, 53, 46, 41, 37, 39, 40, 43, 43, 38, 24, 18, 16, 15, 18, 26, 38, 52, 69, 84, 91, 95, 95, 88, 79, 70, 63, 57, 52, 47, 43, 44, 48, 56, 72, 86, 96, 108, 118, 124, 129, 133, 137, 142, 145, 146, 145, 141, 136, 131, 124, 117, 110, 101, 92, 83, 74, 66, 59, 51, 39, 36, 33, 29, 25, 22, 21, 21, 23, 27, 33, 38, 47, 57, 87, 101, 106, 111, 114, 118, 122, 123, 125, 126, 126, 126, 125, 125, 126, 126, 129, 135, 140, 146, 151, 155, 158, 161, 163, 164, 164, 164, 162, 158, 154, 146, 133, 121, 111, 103, 93, 82, 75, 67, 58, 53, 50, 43, 38, 35, 32, 30, 31, 40, 46, 57, 80, 108, 118, 120, 120, 120, 118, 116, 115, 116, 122, 129, 138, 151, 158, 164, 168, 169, 168, 166};
int layer3_index = 0;

// Layer 4: Layer_4 (manual mode) - 194 keyframes
const int layer4_count = 194;
const unsigned long layer4_times[] PROGMEM = {6, 401, 447, 509, 718, 752, 858, 910, 1404, 1530, 1660, 1793, 1904, 2044, 2437, 2479, 2520, 2562, 2632, 2738, 2788, 2826, 2875, 3041, 3242, 3283, 3325, 3366, 3421, 3543, 3621, 3731, 3875, 3997, 4241, 4438, 4588, 4717, 4985, 5123, 5165, 5239, 5296, 5352, 5388, 5426, 5489, 5572, 5639, 5706, 5801, 5868, 5939, 5998, 6067, 6885, 6922, 6959, 7001, 7038, 7079, 7144, 7200, 7236, 7272, 7306, 7342, 7375, 7417, 7468, 7502, 7536, 7646, 7700, 7846, 7889, 7924, 7962, 8004, 8041, 8078, 8115, 8157, 8198, 8233, 8268, 8304, 8346, 8392, 8464, 8522, 8586, 8646, 8710, 8762, 8911, 8953, 8989, 9026, 9068, 9119, 9175, 9225, 9272, 9306, 9350, 9385, 9424, 9461, 9501, 9547, 9625, 9779, 9817, 9863, 9905, 9939, 9984, 10034, 10071, 10113, 10150, 10203, 10250, 10308, 10366, 10409, 10445, 10491, 12083, 12124, 12181, 12224, 12272, 12328, 12379, 12425, 12485, 12540, 12577, 12637, 12729, 12818, 12980, 13086, 13122, 13178, 13216, 13252, 13289, 13325, 13359, 13411, 13451, 13498, 14731, 14787, 14826, 14864, 14897, 14931, 14991, 15029, 15067, 15255, 15403, 15503, 15565, 15856, 15898, 15934, 15979, 16017, 16059, 16093, 16129, 16169, 16203, 16240, 16281, 16318, 16369, 16410, 16453, 16489, 16526, 16572, 16614, 16648, 16685, 16720, 16757, 16795, 17308};
const int layer4_servo7[] PROGMEM = {1, 4, 7, 10, 13, 17, 20, 23, 26, 29, 32, 36, 39, 42, 39, 31, 28, 24, 21, 18, 14, 11, 8, 5, 9, 12, 15, 18, 21, 24, 27, 30, 33, 37, 40, 43, 46, 49, 52, 49, 45, 42, 39, 36, 32, 29, 26, 23, 20, 17, 14, 11, 8, 5, 2, 5, 11, 15, 18, 21, 24, 27, 30, 33, 38, 42, 45, 51, 54, 57, 68, 76, 79, 82, 79, 76, 72, 65, 62, 57, 53, 46, 43, 39, 33, 29, 26, 23, 20, 17, 14, 11, 8, 5, 2, 5, 11, 15, 18, 22, 25, 28, 31, 34, 38, 41, 44, 47, 50, 56, 59, 62, 59, 56, 53, 49, 45, 39, 36, 30, 27, 23, 19, 16, 13, 10, 7, 3, 0, 3, 6, 9, 12, 16, 19, 22, 25, 28, 31, 34, 38, 41, 44, 47, 43, 37, 34, 31, 28, 22, 16, 10, 7, 4, 1, 4, 7, 14, 21, 24, 33, 37, 57, 74, 77, 80, 83, 86, 83, 80, 72, 69, 66, 63, 59, 56, 52, 49, 46, 42, 39, 36, 32, 29, 26, 23, 19, 16, 13, 10, 7, 3, 0, 0};
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
