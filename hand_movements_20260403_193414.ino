/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-04-03 19:34:14
 * Hardware Config: Default
 * Layers: 4
 * Original Frames Recorded: 6321
 * Loop Duration: 18.89s (recorded) / 18.89s (at 1.0x speed)
 * Playback Speed: 1.0x
 * 
 * Layer Priority (later layers override earlier for same servo):
 * Servo 0 (Thumb): Layer 4
 * Servo 1 (Index): Layer 4
 * Servo 2 (Middle): Layer 4
 * Servo 3 (Ring): Layer 4
 * Servo 4 (Pinky): Layer 4
 * Servo 5 (Shoulder): Layer 1
 * Servo 6 (Elbow): Layer 2
 * Servo 7 (Wrist): Layer 3
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
unsigned long loopDuration = 18890; // milliseconds (adjusted for 1.0x speed)

// Layer data structures

// Layer 1: Layer_1 (manual mode) - 71 keyframes
const int layer1_count = 71;
const unsigned long layer1_times[] PROGMEM = {20, 357, 590, 772, 957, 1101, 1212, 1364, 1492, 1786, 2812, 2953, 3163, 3260, 3352, 3565, 3842, 3936, 4388, 4565, 4692, 4813, 5004, 5188, 5341, 5588, 5837, 6678, 6924, 7239, 7469, 8396, 8612, 8859, 9052, 9271, 9525, 10060, 11229, 11404, 11578, 11762, 11997, 12237, 12700, 12853, 12988, 13100, 13268, 13443, 13596, 13821, 14097, 14708, 14764, 15060, 15156, 15327, 15485, 15853, 16388, 16723, 16988, 17133, 17717, 17878, 17996, 18220, 18314, 18593, 18868};
const int layer1_servo5[] PROGMEM = {  // Shoulder (OWNED)
  83, 87, 91, 94, 97, 100, 103, 106, 109, 112, 109, 106, 102, 99, 96, 93, 89, 86, 90, 93, 96, 99, 102, 105, 109, 112, 115, 112, 108, 104, 101, 104, 108, 111, 114, 117, 120, 123, 120, 117, 114, 111, 108, 104, 101, 104, 108, 111, 114, 117, 120, 123, 127, 123, 119, 116, 113, 109, 106, 102, 99, 95, 92, 88, 92, 95, 98, 101, 105, 108, 108};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 77 keyframes
const int layer2_count = 77;
const unsigned long layer2_times[] PROGMEM = {20, 787, 971, 1195, 1395, 1634, 1746, 2754, 3175, 3518, 3670, 3848, 3937, 4217, 4777, 4968, 5280, 5656, 5879, 6175, 7174, 7279, 7553, 7806, 8114, 8613, 8785, 8982, 9570, 9669, 9907, 10212, 10288, 10437, 10622, 10682, 10805, 11017, 11325, 11996, 12083, 12165, 12301, 12508, 12708, 13307, 13380, 13476, 13681, 13834, 14183, 14545, 14683, 14898, 15074, 15410, 15577, 15786, 15914, 16194, 16529, 16613, 16737, 16905, 17129, 17201, 17254, 17475, 17576, 17654, 17743, 17836, 17982, 18083, 18600, 18722, 18867};
const int layer2_servo6[] PROGMEM = {  // Elbow (OWNED)
  78, 75, 72, 68, 65, 62, 58, 61, 65, 68, 71, 74, 77, 80, 77, 74, 70, 67, 64, 60, 63, 66, 70, 73, 77, 74, 70, 67, 70, 74, 77, 74, 71, 68, 64, 61, 58, 55, 52, 55, 59, 62, 65, 68, 72, 69, 66, 63, 60, 57, 53, 57, 60, 63, 66, 70, 73, 77, 80, 83, 80, 77, 74, 70, 67, 64, 60, 63, 66, 70, 73, 77, 80, 83, 80, 77, 75};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 237 keyframes
const int layer3_count = 237;
const unsigned long layer3_times[] PROGMEM = {19, 472, 553, 604, 677, 729, 787, 917, 972, 1022, 1073, 1129, 1185, 1245, 1453, 1517, 1761, 1818, 1883, 1938, 2005, 2061, 2116, 2170, 2226, 2289, 2365, 2420, 2477, 2529, 2708, 2886, 2949, 3006, 3120, 3173, 3229, 3293, 3381, 3501, 3621, 3732, 3789, 3845, 3895, 3946, 4003, 4061, 4125, 4212, 4264, 4331, 4386, 4437, 4550, 4642, 4704, 4755, 4813, 4877, 4965, 5020, 5077, 5139, 5194, 5257, 5325, 5683, 5739, 5801, 5861, 5913, 5964, 6020, 6073, 6133, 6187, 6238, 6297, 6352, 6410, 6469, 6529, 6579, 6636, 6692, 6756, 6828, 6893, 6959, 7069, 7125, 7178, 7238, 7301, 7354, 7422, 7482, 7568, 7893, 7948, 8005, 8115, 8207, 8302, 8365, 8417, 8476, 8532, 8585, 8638, 8722, 8862, 8918, 8984, 9068, 9125, 9180, 9269, 9321, 9376, 9468, 9596, 9701, 9933, 9988, 10091, 10200, 10341, 10429, 10669, 10721, 10773, 10941, 11005, 11100, 11157, 11229, 11324, 11380, 11469, 11541, 11693, 11804, 11931, 12184, 12237, 12305, 12372, 12429, 12483, 12539, 12638, 12693, 12747, 12804, 12877, 12932, 12988, 13044, 13109, 13204, 13259, 13356, 13537, 13589, 13645, 13706, 13760, 13818, 13879, 13941, 13993, 14076, 14132, 14189, 14244, 14342, 14405, 14465, 14532, 14788, 14852, 14913, 14980, 15033, 15124, 15186, 15262, 15339, 15448, 15500, 15556, 15621, 15679, 15748, 15819, 15884, 15937, 15987, 16038, 16088, 16140, 16193, 16247, 16300, 16364, 16520, 16572, 16626, 16680, 16732, 16788, 16839, 16896, 16948, 17004, 17060, 17116, 17186, 17381, 17436, 17596, 17668, 17749, 17868, 17940, 18028, 18164, 18252, 18314, 18612, 18664, 18716, 18772, 18827, 18881};
const int layer3_servo7[] PROGMEM = {  // Wrist (OWNED)
  93, 90, 87, 83, 80, 76, 73, 69, 65, 62, 55, 47, 44, 41, 38, 34, 38, 46, 49, 52, 56, 60, 64, 67, 72, 75, 78, 82, 86, 90, 86, 83, 78, 74, 71, 67, 64, 61, 58, 55, 51, 55, 62, 65, 70, 77, 81, 85, 88, 92, 97, 101, 104, 107, 110, 113, 117, 121, 124, 128, 131, 134, 138, 141, 144, 148, 151, 148, 143, 139, 136, 130, 126, 120, 115, 110, 105, 101, 98, 93, 89, 85, 82, 77, 72, 67, 63, 58, 55, 51, 48, 44, 41, 36, 32, 29, 26, 22, 19, 22, 27, 31, 34, 38, 41, 45, 48, 51, 56, 59, 63, 66, 63, 59, 56, 52, 48, 45, 42, 38, 34, 31, 28, 24, 27, 33, 37, 40, 43, 47, 50, 59, 65, 62, 58, 55, 52, 49, 45, 42, 39, 36, 33, 29, 26, 29, 32, 36, 40, 43, 46, 49, 52, 56, 59, 63, 66, 69, 74, 77, 81, 84, 88, 91, 88, 81, 78, 75, 72, 68, 65, 62, 58, 55, 50, 47, 44, 41, 38, 35, 31, 36, 39, 42, 46, 49, 52, 56, 59, 62, 65, 69, 74, 77, 80, 83, 87, 90, 94, 97, 100, 103, 108, 113, 120, 126, 130, 126, 116, 109, 105, 102, 99, 95, 90, 86, 80, 74, 71, 67, 71, 76, 79, 83, 86, 90, 93, 96, 100, 103, 106, 103, 100, 96, 92, 88, 87};
int layer3_index = 0;

// Layer 4: Layer_4 (cursor mode) - 159 keyframes
const int layer4_count = 159;
const unsigned long layer4_times[] PROGMEM = {19, 546, 700, 837, 992, 1122, 1230, 1341, 1454, 1568, 1671, 1779, 1884, 1990, 2095, 2201, 2306, 2412, 2517, 2624, 2728, 2833, 2947, 3053, 3163, 3271, 3377, 3515, 3621, 3726, 3834, 3937, 4108, 4210, 4359, 4465, 4571, 4675, 4781, 4885, 4992, 5098, 5203, 5309, 5414, 5520, 5625, 5731, 5836, 5941, 6047, 6152, 6258, 6363, 6468, 6575, 6680, 6782, 6891, 6994, 7101, 7256, 7361, 7467, 7588, 7733, 7840, 7945, 8051, 8157, 8259, 8367, 8472, 8577, 8680, 8790, 8896, 8999, 9106, 9212, 9317, 9430, 9537, 9642, 9747, 9860, 9966, 10075, 10178, 10372, 10478, 10582, 10689, 10793, 10899, 11005, 11110, 11216, 11321, 11430, 11546, 11670, 11777, 11896, 12011, 12116, 12221, 12335, 12489, 12603, 13008, 13114, 13225, 13373, 13477, 13609, 13729, 13845, 13950, 14071, 14177, 14297, 14420, 14528, 14631, 14754, 14858, 14988, 15094, 15207, 15310, 15414, 15605, 15710, 15827, 15952, 16077, 16181, 16287, 16393, 16498, 16608, 16725, 16829, 16936, 17041, 17146, 17252, 17358, 17463, 17609, 17723, 17836, 18007, 18178, 18291, 18437, 18542, 18885};
const int layer4_servo0[] PROGMEM = {  // Thumb (OWNED)
  72, 77, 82, 87, 92, 96, 100, 102, 103, 104, 103, 100, 96, 92, 87, 81, 73, 67, 61, 54, 49, 42, 34, 31, 28, 27, 26, 26, 28, 28, 30, 35, 39, 48, 53, 54, 52, 50, 48, 46, 45, 44, 45, 47, 51, 59, 68, 81, 96, 109, 111, 114, 117, 118, 121, 120, 119, 117, 114, 112, 107, 105, 109, 115, 120, 125, 129, 133, 135, 135, 132, 129, 122, 116, 109, 98, 85, 74, 61, 48, 37, 29, 24, 20, 18, 18, 23, 30, 35, 39, 39, 41, 44, 52, 66, 74, 80, 88, 98, 108, 114, 123, 126, 129, 130, 130, 128, 126, 126, 123, 119, 118, 117, 115, 108, 104, 91, 86, 78, 71, 60, 50, 44, 41, 31, 29, 28, 27, 27, 30, 32, 36, 40, 41, 42, 44, 45, 50, 55, 60, 65, 70, 76, 80, 89, 100, 105, 110, 116, 120, 123, 125, 125, 124, 124, 124, 122, 120, 119};
const int layer4_servo1[] PROGMEM = {  // Index (OWNED)
  15, 18, 20, 24, 28, 34, 40, 46, 51, 58, 68, 79, 84, 88, 96, 101, 106, 108, 110, 110, 108, 105, 98, 94, 88, 79, 72, 67, 55, 44, 36, 28, 24, 20, 23, 26, 34, 42, 50, 59, 69, 81, 88, 102, 110, 122, 130, 135, 134, 127, 122, 117, 111, 104, 95, 85, 79, 65, 55, 50, 44, 41, 45, 51, 56, 62, 67, 74, 83, 90, 96, 99, 105, 108, 113, 116, 118, 117, 115, 109, 101, 92, 84, 73, 63, 52, 47, 47, 50, 55, 65, 83, 98, 114, 129, 134, 137, 139, 139, 136, 132, 125, 120, 114, 109, 103, 91, 84, 78, 72, 69, 74, 80, 85, 93, 96, 105, 107, 110, 112, 112, 109, 106, 104, 92, 89, 84, 80, 71, 68, 66, 65, 70, 84, 90, 96, 102, 112, 118, 124, 126, 128, 129, 129, 128, 125, 122, 118, 113, 108, 102, 97, 91, 86, 80, 75, 70, 65, 62};
const int layer4_servo2[] PROGMEM = {  // Middle (OWNED)
  135, 137, 142, 147, 152, 157, 162, 164, 165, 165, 164, 161, 158, 154, 146, 138, 128, 120, 111, 100, 94, 87, 78, 74, 69, 64, 63, 63, 67, 73, 80, 88, 93, 102, 100, 95, 84, 74, 66, 58, 51, 46, 44, 44, 46, 53, 62, 78, 95, 113, 119, 126, 132, 137, 142, 147, 149, 151, 149, 146, 138, 133, 127, 125, 126, 126, 127, 130, 132, 134, 135, 136, 135, 134, 130, 125, 116, 108, 98, 88, 83, 79, 74, 71, 71, 73, 73, 71, 68, 63, 56, 49, 47, 50, 59, 65, 71, 79, 89, 101, 108, 118, 123, 127, 130, 134, 140, 143, 143, 145, 150, 151, 151, 150, 148, 146, 137, 131, 124, 116, 104, 94, 88, 82, 71, 68, 66, 64, 62, 60, 59, 58, 53, 48, 47, 47, 48, 52, 56, 63, 70, 78, 85, 91, 102, 113, 119, 124, 129, 134, 137, 139, 142, 144, 145, 145, 146, 146, 145};
const int layer4_servo3[] PROGMEM = {  // Ring (OWNED)
  78, 78, 81, 84, 89, 94, 102, 108, 113, 120, 129, 139, 145, 150, 155, 158, 160, 160, 159, 156, 153, 149, 142, 137, 128, 117, 109, 104, 94, 90, 86, 81, 78, 74, 70, 68, 66, 66, 68, 71, 75, 83, 87, 98, 106, 116, 125, 132, 134, 131, 130, 128, 125, 123, 116, 112, 109, 99, 90, 85, 75, 70, 64, 62, 63, 63, 65, 71, 80, 89, 99, 105, 118, 126, 133, 142, 149, 152, 152, 149, 147, 142, 135, 125, 116, 107, 98, 88, 83, 79, 82, 91, 101, 112, 122, 125, 128, 130, 130, 128, 126, 120, 117, 112, 109, 107, 103, 100, 95, 94, 100, 107, 114, 120, 133, 138, 150, 153, 156, 157, 156, 153, 149, 145, 133, 128, 122, 117, 107, 99, 93, 87, 84, 90, 95, 99, 105, 113, 120, 126, 131, 136, 139, 140, 140, 138, 135, 132, 127, 121, 117, 112, 108, 105, 101, 97, 94, 90, 88};
const int layer4_servo4[] PROGMEM = {  // Pinky (OWNED)
  72, 77, 82, 87, 92, 96, 100, 102, 103, 104, 103, 100, 96, 92, 87, 81, 73, 67, 61, 54, 49, 42, 34, 31, 28, 27, 26, 26, 28, 28, 30, 35, 39, 48, 53, 54, 52, 50, 48, 46, 45, 44, 45, 47, 51, 59, 68, 81, 96, 109, 111, 114, 117, 118, 121, 120, 119, 117, 114, 112, 107, 105, 109, 115, 120, 125, 129, 133, 135, 135, 132, 129, 122, 116, 109, 98, 85, 74, 61, 48, 37, 29, 24, 20, 18, 18, 23, 30, 35, 39, 39, 41, 44, 52, 66, 74, 80, 88, 98, 108, 114, 123, 126, 129, 130, 130, 128, 126, 126, 123, 119, 118, 117, 115, 108, 104, 91, 86, 78, 71, 60, 50, 44, 41, 31, 29, 28, 27, 27, 30, 32, 36, 40, 41, 42, 44, 45, 50, 55, 60, 65, 70, 76, 80, 89, 100, 105, 110, 116, 120, 123, 125, 125, 124, 124, 124, 122, 120, 119};
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

  // Update layer 1 with interpolation (OWNS: Shoulder)
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

  // Update layer 3 with interpolation (OWNS: Wrist)
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
