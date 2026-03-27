/*
 * 8-Servo Hand Control - Markov Chain Phrase System
 * Generated: 2026-03-23 21:05:33
 * Phrases: 1
 * PIR Sensor: Enabled on pin 2
 * 
 * This sketch uses Markov chains to randomly transition between
 * recorded movement phrases, creating organic, non-repetitive behavior.
 * 
 * Hardware: 5 Finger Servos + 3 Arm Servos
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

// PIR Motion Sensor
const int PIR_PIN = 2;
const unsigned long MOTION_TIMEOUT = 5000; // milliseconds
bool motionDetected = false;
unsigned long lastMotionTime = 0;

// Phrase system
const int NUM_PHRASES = 1;
int currentPhrase = 0;
unsigned long phraseStartTime = 0;

// Transition probability matrix (stored as percentages 0-100)
// Each row represents probabilities of transitioning FROM that phrase TO others
const uint8_t transitionMatrix[NUM_PHRASES][NUM_PHRASES] PROGMEM = {
  {10} // From Phrase 0
};

// ===== PHRASE 0: Current Recording =====
const unsigned long phrase0_duration = 15770;
const int phrase0_layer0_count = 189;
const unsigned long phrase0_layer0_times[] PROGMEM = {11, 581, 643, 698, 750, 804, 893, 950, 1001, 1053, 1108, 1158, 1209, 1262, 1318, 1378, 1430, 1486, 1544, 1597, 1655, 1708, 1769, 1830, 1924, 1985, 2095, 2153, 2209, 2464, 2520, 2576, 2635, 2688, 2749, 2803, 2853, 2904, 2962, 3026, 3084, 3135, 3185, 3240, 3291, 3343, 3451, 3512, 3763, 3942, 3999, 4053, 4129, 4190, 4242, 4295, 4348, 4405, 4461, 4516, 4567, 4641, 4698, 4751, 4813, 4885, 4935, 4985, 5060, 5452, 5510, 5570, 5621, 5673, 5728, 5859, 5915, 5986, 6042, 6211, 6265, 6352, 6407, 6521, 6580, 6681, 6838, 7220, 7283, 7333, 7431, 7482, 7565, 7673, 7734, 7824, 8076, 8389, 8472, 8563, 8614, 8704, 8754, 8875, 8970, 9022, 9082, 9144, 9402, 9456, 9509, 9561, 9613, 9674, 9725, 9777, 9833, 9884, 9937, 9994, 10045, 10096, 10146, 10199, 10251, 10337, 10394, 10524, 10574, 10626, 10682, 10735, 10792, 10852, 10912, 10963, 11014, 11155, 11207, 11264, 11318, 11371, 11422, 11483, 11541, 11601, 11686, 11736, 11854, 11970, 12027, 12083, 12135, 12187, 12244, 12295, 12348, 12401, 12464, 12523, 12574, 12630, 12694, 13044, 13103, 13166, 13230, 13280, 13337, 13389, 13440, 13492, 13553, 13607, 13665, 13768, 13825, 14079, 14140, 14194, 14299, 14351, 14409, 14469, 14528, 14587, 14642, 14721, 15758};
const int phrase0_layer0_servo0[] PROGMEM = {12, 15, 18, 21, 25, 30, 33, 38, 42, 47, 52, 57, 62, 68, 76, 82, 86, 93, 98, 105, 113, 117, 123, 127, 130, 136, 139, 142, 145, 141, 135, 120, 108, 96, 87, 79, 73, 67, 60, 49, 45, 41, 34, 29, 26, 21, 18, 15, 12, 16, 20, 23, 26, 33, 38, 43, 47, 51, 58, 61, 65, 68, 72, 76, 81, 84, 91, 95, 99, 96, 88, 82, 79, 72, 68, 65, 62, 59, 54, 51, 47, 44, 41, 38, 32, 29, 26, 29, 32, 37, 40, 44, 47, 50, 54, 57, 60, 57, 54, 51, 47, 44, 40, 37, 34, 31, 27, 18, 24, 38, 48, 57, 63, 70, 80, 85, 91, 98, 105, 112, 118, 124, 132, 138, 146, 151, 157, 153, 142, 133, 100, 79, 54, 40, 26, 13, 3, 6, 11, 35, 50, 66, 80, 87, 91, 98, 101, 104, 107, 103, 88, 78, 66, 60, 57, 51, 45, 41, 37, 33, 30, 26, 23, 28, 35, 39, 43, 51, 56, 70, 78, 87, 92, 96, 101, 104, 108, 104, 85, 61, 58, 52, 48, 45, 38, 34, 28, 25, 23};
const int phrase0_layer1_count = 178;
const unsigned long phrase0_layer1_times[] PROGMEM = {1, 433, 490, 586, 638, 703, 882, 992, 1062, 1141, 1204, 1259, 1317, 1401, 1566, 1628, 1682, 1756, 1845, 1917, 1979, 2078, 2200, 2257, 2327, 2408, 2480, 2542, 2603, 2669, 2945, 3080, 3139, 3190, 3244, 3300, 3355, 3405, 3461, 3578, 3631, 3696, 3750, 3834, 4211, 4270, 4321, 4375, 4536, 4598, 4703, 4789, 4871, 5008, 5060, 5114, 5172, 5241, 5329, 5380, 5434, 5488, 5570, 5647, 6051, 6105, 6161, 6218, 6269, 6324, 6378, 6431, 6491, 6544, 6599, 6727, 6827, 6890, 6947, 7007, 7062, 7874, 7932, 8005, 8055, 8111, 8197, 8247, 8308, 8362, 8414, 8472, 8529, 8579, 8672, 8882, 9107, 9163, 9215, 9273, 9354, 9407, 9484, 9534, 9615, 9718, 9775, 9874, 10128, 10184, 10245, 10304, 10373, 10435, 10490, 10551, 10602, 10656, 10755, 10884, 10968, 11019, 11244, 11306, 11367, 11430, 11480, 11556, 11821, 11877, 11929, 11981, 12070, 12133, 12229, 12325, 12415, 12508, 12862, 12917, 12977, 13032, 13086, 13144, 13194, 13249, 13312, 13373, 13447, 13506, 13561, 13617, 13668, 13748, 13804, 13871, 14106, 14162, 14213, 14267, 14323, 14421, 14513, 14571, 14845, 14952, 15004, 15155, 15206, 15267, 15344, 15396, 15453, 15508, 15565, 15629, 15699, 15741};
const int phrase0_layer1_servo1[] PROGMEM = {158, 155, 141, 135, 130, 127, 123, 120, 117, 114, 111, 106, 103, 100, 97, 94, 91, 87, 84, 81, 77, 74, 71, 66, 63, 60, 57, 54, 49, 46, 43, 46, 67, 87, 97, 105, 112, 123, 130, 134, 139, 143, 148, 151, 148, 142, 139, 131, 128, 123, 120, 116, 112, 109, 97, 90, 81, 76, 73, 65, 59, 54, 50, 47, 50, 57, 66, 75, 79, 85, 98, 112, 127, 140, 146, 150, 154, 159, 164, 170, 178, 175, 165, 160, 155, 149, 145, 140, 136, 132, 127, 122, 119, 116, 112, 109, 113, 118, 123, 131, 134, 138, 141, 146, 150, 153, 156, 159, 156, 151, 148, 141, 138, 135, 132, 123, 119, 115, 112, 109, 106, 99, 96, 91, 88, 85, 81, 77, 74, 68, 64, 60, 57, 54, 51, 48, 45, 41, 44, 48, 54, 60, 65, 70, 74, 79, 82, 92, 95, 98, 101, 106, 111, 114, 118, 122, 119, 106, 98, 87, 78, 75, 72, 69, 66, 70, 88, 85, 80, 77, 74, 69, 66, 63, 60, 57, 54, 52};
const int phrase0_layer2_count = 212;
const unsigned long phrase0_layer2_times[] PROGMEM = {4, 373, 583, 778, 847, 979, 1047, 1099, 1155, 1208, 1261, 1329, 1382, 1444, 1500, 1635, 1700, 1766, 1818, 1873, 1924, 1992, 2049, 2110, 2276, 2339, 2400, 2459, 2521, 2574, 2635, 2687, 2746, 2808, 2869, 3045, 3101, 3160, 3221, 3278, 3352, 3408, 3469, 3531, 3609, 3713, 3783, 3959, 4021, 4091, 4158, 4209, 4269, 4339, 4407, 4459, 4515, 4570, 4631, 4692, 4742, 4804, 4861, 4929, 4988, 5070, 5141, 5197, 5412, 5472, 5535, 5594, 5664, 5722, 5790, 5843, 5910, 5973, 6047, 6103, 6263, 6318, 6383, 6436, 6498, 6555, 6621, 6673, 6735, 6788, 6850, 6939, 7119, 7181, 7234, 7298, 7352, 7417, 7475, 7546, 7671, 7908, 8019, 8259, 8316, 8381, 8435, 8497, 8553, 8617, 8667, 8730, 8782, 8838, 8892, 9002, 9066, 9121, 9392, 9446, 9511, 9562, 9627, 9722, 9783, 9835, 9894, 9980, 10044, 10104, 10175, 10237, 10347, 10403, 10484, 10548, 10703, 10779, 10984, 11066, 11133, 11192, 11258, 11313, 11369, 11419, 11472, 11531, 11584, 11677, 11734, 11801, 11868, 11942, 12005, 12071, 12168, 12221, 12271, 12326, 12379, 12431, 12481, 12535, 12586, 12646, 12705, 12763, 12824, 12880, 13078, 13132, 13182, 13233, 13289, 13343, 13404, 13456, 13507, 13557, 13609, 13668, 13725, 13783, 13851, 14007, 14064, 14118, 14169, 14225, 14276, 14327, 14379, 14442, 14522, 14575, 14625, 14699, 14780, 14849, 14901, 14959, 15013, 15067, 15157, 15214, 15287, 15395, 15501, 15562, 15698, 15762};
const int phrase0_layer2_servo3[] PROGMEM = {30, 33, 36, 40, 47, 50, 55, 60, 64, 70, 75, 80, 87, 102, 105, 102, 93, 87, 84, 63, 58, 55, 50, 40, 45, 61, 69, 78, 84, 90, 96, 99, 105, 110, 117, 113, 109, 100, 89, 76, 71, 64, 60, 56, 53, 50, 47, 52, 61, 68, 73, 77, 80, 86, 96, 99, 105, 109, 114, 118, 121, 128, 133, 138, 144, 147, 150, 156, 151, 144, 133, 126, 110, 103, 94, 84, 77, 72, 68, 62, 66, 73, 80, 86, 92, 98, 102, 106, 112, 115, 119, 122, 116, 104, 98, 94, 88, 81, 78, 75, 70, 66, 63, 67, 70, 76, 81, 86, 89, 95, 101, 104, 109, 114, 118, 121, 126, 129, 122, 112, 105, 101, 98, 94, 88, 85, 81, 76, 72, 68, 64, 59, 56, 53, 50, 47, 44, 41, 44, 47, 51, 57, 61, 65, 70, 75, 80, 83, 88, 93, 98, 102, 105, 109, 113, 116, 110, 103, 96, 91, 87, 84, 81, 77, 72, 67, 62, 59, 54, 50, 54, 58, 62, 68, 73, 76, 79, 83, 89, 94, 98, 103, 107, 110, 113, 109, 104, 98, 92, 86, 80, 76, 70, 67, 64, 60, 56, 53, 49, 46, 40, 36, 31, 28, 25, 19, 16, 13, 10, 7, 3, 2};
const int phrase0_layer3_count = 200;
const unsigned long phrase0_layer3_times[] PROGMEM = {20, 777, 874, 939, 998, 1279, 1335, 1427, 1586, 1684, 1794, 2167, 2234, 2409, 2462, 2520, 2583, 2645, 2697, 2850, 2907, 2963, 3014, 3073, 3130, 3230, 3284, 3336, 3386, 3438, 3490, 3712, 3766, 3817, 3872, 3969, 4102, 4154, 4204, 4265, 4317, 4373, 4425, 4493, 4625, 4679, 4736, 4786, 4840, 4897, 4975, 5031, 5083, 5136, 5189, 5241, 5300, 5355, 5474, 5531, 5584, 5639, 5694, 5745, 5894, 5950, 6003, 6054, 6105, 6159, 6214, 6270, 6489, 6546, 6598, 6656, 6706, 6759, 6814, 6865, 6915, 6971, 7035, 7088, 7161, 7212, 7373, 7427, 7609, 7660, 7712, 7763, 7814, 7871, 7921, 7973, 8040, 8195, 8288, 8477, 8533, 8584, 8640, 8697, 8748, 8800, 8893, 8946, 9001, 9062, 9113, 9312, 9363, 9414, 9468, 9520, 9571, 9621, 9672, 9723, 9774, 9852, 9952, 10006, 10057, 10109, 10161, 10218, 10271, 10337, 10402, 10499, 10555, 10626, 10679, 10737, 10826, 11095, 11149, 11203, 11257, 11312, 11368, 11455, 11508, 11568, 11626, 11682, 11734, 11786, 11858, 11914, 11967, 12097, 12147, 12202, 12254, 12309, 12360, 12416, 12468, 12521, 12571, 12627, 12679, 12734, 12785, 12840, 12895, 12945, 13001, 13062, 13196, 13742, 13830, 13881, 13935, 13985, 14037, 14090, 14150, 14343, 14400, 14450, 14503, 14561, 14618, 14701, 14755, 14842, 14902, 14957, 15021, 15132, 15220, 15537, 15594, 15654, 15710, 15760};
const int phrase0_layer3_servo2[] PROGMEM = {156, 153, 150, 147, 144, 147, 150, 153, 156, 159, 162, 158, 155, 152, 147, 137, 127, 121, 118, 122, 126, 144, 158, 163, 170, 166, 148, 137, 133, 128, 123, 127, 143, 153, 164, 167, 163, 140, 131, 123, 119, 109, 91, 76, 79, 104, 133, 138, 145, 151, 157, 149, 138, 116, 85, 75, 54, 44, 48, 80, 108, 119, 126, 134, 129, 119, 96, 81, 67, 60, 57, 54, 58, 72, 82, 90, 96, 99, 106, 112, 115, 121, 124, 128, 132, 136, 139, 143, 139, 135, 123, 111, 102, 95, 80, 62, 56, 52, 49, 54, 71, 80, 92, 96, 102, 106, 109, 114, 121, 124, 129, 124, 116, 109, 90, 73, 60, 50, 46, 40, 33, 29, 32, 50, 72, 90, 103, 107, 111, 114, 117, 120, 127, 130, 135, 138, 141, 138, 129, 122, 117, 109, 96, 93, 88, 85, 80, 64, 61, 56, 52, 46, 42, 46, 57, 70, 78, 84, 93, 97, 103, 110, 117, 126, 131, 134, 140, 148, 153, 156, 162, 165, 168, 165, 162, 156, 132, 103, 95, 72, 60, 64, 72, 94, 108, 116, 123, 126, 130, 133, 136, 139, 142, 146, 149, 145, 123, 111, 87, 48};
const int phrase0_layer4_count = 217;
const unsigned long phrase0_layer4_times[] PROGMEM = {5, 689, 745, 796, 847, 904, 963, 1019, 1071, 1125, 1183, 1234, 1286, 1337, 1393, 1482, 1533, 1591, 1649, 1706, 1798, 1934, 1986, 2036, 2094, 2144, 2199, 2255, 2400, 2458, 2516, 2571, 2626, 2677, 2727, 2802, 2853, 2910, 2964, 3014, 3068, 3121, 3174, 3287, 3343, 3398, 3449, 3502, 3559, 3623, 3755, 3813, 3872, 3930, 3987, 4038, 4089, 4154, 4209, 4260, 4316, 4370, 4429, 4485, 4599, 4651, 4702, 4758, 4808, 4863, 4914, 4974, 5085, 5141, 5191, 5243, 5294, 5349, 5400, 5558, 5613, 5671, 5730, 5780, 5832, 5884, 6036, 6089, 6141, 6195, 6248, 6304, 6355, 6413, 6513, 6568, 6619, 6675, 6728, 6782, 6842, 7026, 7076, 7126, 7181, 7232, 7289, 7339, 7392, 7447, 7593, 7650, 7704, 7758, 7809, 7868, 7926, 7980, 8031, 8084, 8164, 8390, 8446, 8496, 8547, 8600, 8652, 8710, 8760, 8816, 8875, 8952, 9167, 9217, 9273, 9328, 9379, 9431, 9482, 9532, 9584, 9635, 9696, 9769, 9832, 9884, 10166, 10226, 10279, 10330, 10386, 10437, 10490, 10566, 10630, 10681, 10799, 10877, 10934, 10987, 11040, 11090, 11149, 11201, 11380, 11433, 11485, 11538, 11595, 11649, 11717, 11846, 12043, 12099, 12156, 12207, 12260, 12313, 12367, 12420, 12472, 12527, 12584, 12639, 12704, 12806, 12862, 12979, 13097, 13147, 13202, 13277, 13334, 13393, 13446, 13547, 13599, 13652, 13725, 13829, 14090, 14145, 14212, 14264, 14326, 14428, 14502, 14660, 14717, 15068, 15149, 15346, 15404, 15462, 15676, 15750, 15763};
const int phrase0_layer4_servo4[] PROGMEM = {14, 18, 23, 29, 35, 38, 46, 51, 64, 82, 102, 127, 138, 146, 152, 148, 124, 87, 75, 33, 30, 35, 71, 94, 123, 136, 152, 156, 151, 119, 78, 64, 54, 50, 44, 48, 58, 84, 102, 118, 135, 144, 149, 143, 105, 85, 45, 27, 8, 5, 11, 43, 74, 102, 121, 134, 144, 147, 133, 112, 63, 55, 31, 26, 29, 35, 67, 87, 102, 128, 143, 146, 142, 120, 64, 51, 44, 36, 20, 24, 49, 69, 88, 104, 125, 135, 132, 99, 77, 51, 47, 34, 20, 13, 18, 50, 76, 102, 109, 124, 132, 129, 116, 97, 86, 69, 50, 41, 32, 24, 28, 40, 45, 57, 68, 82, 94, 106, 113, 117, 121, 116, 100, 97, 91, 84, 70, 61, 55, 50, 46, 43, 47, 53, 60, 64, 68, 76, 84, 94, 101, 106, 110, 113, 116, 121, 118, 105, 90, 86, 77, 69, 61, 52, 49, 43, 46, 50, 67, 80, 101, 112, 127, 138, 135, 115, 98, 65, 56, 29, 26, 23, 26, 45, 55, 61, 70, 75, 79, 85, 88, 96, 103, 106, 109, 112, 116, 119, 116, 110, 105, 101, 94, 84, 78, 75, 70, 66, 63, 60, 63, 68, 72, 79, 82, 85, 88, 92, 95, 98, 101, 104, 111, 114, 117, 120, 120};
int phrase0_layer_indices[5];

void setup() {
  Serial.begin(9600);
  
  // Attach servos
  for(int i = 0; i < 8; i++) {
    servo[i].attach(servoPins[i]);
    servo[i].write(90);
  }
  
  // Setup PIR sensor
  pinMode(PIR_PIN, INPUT);
  Serial.println("PIR Motion Sensor enabled on pin 2");
  
  delay(1000);
  randomSeed(analogRead(A0)); // Seed random from floating analog pin
  Serial.println("Markov Chain Hand Control Ready");
  Serial.print("Phrases loaded: ");
  Serial.println(NUM_PHRASES);
  
  phraseStartTime = millis();
}

int selectNextPhrase(int currentPhrase) {
  // Read transition probabilities for current phrase from PROGMEM
  int randVal = random(100); // 0-99
  int cumulative = 0;
  
  for(int i = 0; i < NUM_PHRASES; i++) {
    cumulative += pgm_read_byte(&transitionMatrix[currentPhrase][i]);
    if(randVal < cumulative) {
      return i;
    }
  }
  
  return 0; // Fallback
}

void loop() {
  // Check PIR sensor
  if(digitalRead(PIR_PIN) == HIGH) {
    motionDetected = true;
    lastMotionTime = millis();
  }
  
  // Check motion timeout
  if(motionDetected && (millis() - lastMotionTime > MOTION_TIMEOUT)) {
    motionDetected = false;
    Serial.println("No motion detected - pausing");
    // Return to center position
    for(int i = 0; i < 8; i++) {
      servo[i].write(90);
    }
    delay(100);
    return;
  }
  
  // Only play phrases if motion detected
  if(!motionDetected) {
    delay(100);
    return;
  }
  
  unsigned long elapsed = millis() - phraseStartTime;
  unsigned long phraseDuration = 0;
  
  // Get current phrase duration
  switch(currentPhrase) {
    case 0: phraseDuration = phrase0_duration; break;
  }
  
  // Check if phrase is complete
  if(elapsed >= phraseDuration) {
    // Transition to next phrase using Markov chain
    int nextPhrase = selectNextPhrase(currentPhrase);
    
    Serial.print("Phrase ");
    Serial.print(currentPhrase);
    Serial.print(" complete. Transitioning to phrase ");
    Serial.println(nextPhrase);
    
    currentPhrase = nextPhrase;
    phraseStartTime = millis();
    elapsed = 0;
    
    // Reset all layer indices for new phrase
    if(currentPhrase == 0) { for(int i = 0; i < 5; i++) phrase0_layer_indices[i] = 0; }
  }
  
  // Play current phrase
  playPhrase(currentPhrase, elapsed);
  
  delay(5); // 200Hz update rate
}

void playPhrase(int phraseNum, unsigned long elapsed) {
  switch(phraseNum) {
    case 0:
      playPhrase0(elapsed);
      break;
  }
}

void playPhrase0(unsigned long elapsed) {
  unsigned long blendZone = phrase0_duration / 10;
  bool isBlending = elapsed >= (phrase0_duration - blendZone);
  float blendFactor = isBlending ? (float)(elapsed - (phrase0_duration - blendZone)) / blendZone : 0;

  // Layer 0
  if(phrase0_layer_indices[0] < phrase0_layer0_count - 1) {
    unsigned long currentTime = pgm_read_dword(&phrase0_layer0_times[phrase0_layer_indices[0]]);
    unsigned long nextTime = pgm_read_dword(&phrase0_layer0_times[phrase0_layer_indices[0] + 1]);
    
    if(elapsed >= nextTime) {
      phrase0_layer_indices[0]++;
    }
    
    float factor = (elapsed >= currentTime && nextTime > currentTime) ? (float)(elapsed - currentTime) / (nextTime - currentTime) : 0;
    if(factor > 1.0) factor = 1.0;

    // Servo 0
    int curr0 = pgm_read_word(&phrase0_layer0_servo0[phrase0_layer_indices[0]]);
    int next0 = pgm_read_word(&phrase0_layer0_servo0[phrase0_layer_indices[0] + 1]);
    int start0 = pgm_read_word(&phrase0_layer0_servo0[0]);
    if(curr0 != -1 && next0 != -1) {
      int interpolated = curr0 + (int)((next0 - curr0) * factor);
      if(isBlending && start0 != -1) {
        interpolated = interpolated * (1.0 - blendFactor) + start0 * blendFactor;
      }
      servo[0].write(interpolated);
    }

  }

  // Layer 1
  if(phrase0_layer_indices[1] < phrase0_layer1_count - 1) {
    unsigned long currentTime = pgm_read_dword(&phrase0_layer1_times[phrase0_layer_indices[1]]);
    unsigned long nextTime = pgm_read_dword(&phrase0_layer1_times[phrase0_layer_indices[1] + 1]);
    
    if(elapsed >= nextTime) {
      phrase0_layer_indices[1]++;
    }
    
    float factor = (elapsed >= currentTime && nextTime > currentTime) ? (float)(elapsed - currentTime) / (nextTime - currentTime) : 0;
    if(factor > 1.0) factor = 1.0;

    // Servo 1
    int curr1 = pgm_read_word(&phrase0_layer1_servo1[phrase0_layer_indices[1]]);
    int next1 = pgm_read_word(&phrase0_layer1_servo1[phrase0_layer_indices[1] + 1]);
    int start1 = pgm_read_word(&phrase0_layer1_servo1[0]);
    if(curr1 != -1 && next1 != -1) {
      int interpolated = curr1 + (int)((next1 - curr1) * factor);
      if(isBlending && start1 != -1) {
        interpolated = interpolated * (1.0 - blendFactor) + start1 * blendFactor;
      }
      servo[1].write(interpolated);
    }

  }

  // Layer 2
  if(phrase0_layer_indices[2] < phrase0_layer2_count - 1) {
    unsigned long currentTime = pgm_read_dword(&phrase0_layer2_times[phrase0_layer_indices[2]]);
    unsigned long nextTime = pgm_read_dword(&phrase0_layer2_times[phrase0_layer_indices[2] + 1]);
    
    if(elapsed >= nextTime) {
      phrase0_layer_indices[2]++;
    }
    
    float factor = (elapsed >= currentTime && nextTime > currentTime) ? (float)(elapsed - currentTime) / (nextTime - currentTime) : 0;
    if(factor > 1.0) factor = 1.0;

    // Servo 3
    int curr3 = pgm_read_word(&phrase0_layer2_servo3[phrase0_layer_indices[2]]);
    int next3 = pgm_read_word(&phrase0_layer2_servo3[phrase0_layer_indices[2] + 1]);
    int start3 = pgm_read_word(&phrase0_layer2_servo3[0]);
    if(curr3 != -1 && next3 != -1) {
      int interpolated = curr3 + (int)((next3 - curr3) * factor);
      if(isBlending && start3 != -1) {
        interpolated = interpolated * (1.0 - blendFactor) + start3 * blendFactor;
      }
      servo[3].write(interpolated);
    }

  }

  // Layer 3
  if(phrase0_layer_indices[3] < phrase0_layer3_count - 1) {
    unsigned long currentTime = pgm_read_dword(&phrase0_layer3_times[phrase0_layer_indices[3]]);
    unsigned long nextTime = pgm_read_dword(&phrase0_layer3_times[phrase0_layer_indices[3] + 1]);
    
    if(elapsed >= nextTime) {
      phrase0_layer_indices[3]++;
    }
    
    float factor = (elapsed >= currentTime && nextTime > currentTime) ? (float)(elapsed - currentTime) / (nextTime - currentTime) : 0;
    if(factor > 1.0) factor = 1.0;

    // Servo 2
    int curr2 = pgm_read_word(&phrase0_layer3_servo2[phrase0_layer_indices[3]]);
    int next2 = pgm_read_word(&phrase0_layer3_servo2[phrase0_layer_indices[3] + 1]);
    int start2 = pgm_read_word(&phrase0_layer3_servo2[0]);
    if(curr2 != -1 && next2 != -1) {
      int interpolated = curr2 + (int)((next2 - curr2) * factor);
      if(isBlending && start2 != -1) {
        interpolated = interpolated * (1.0 - blendFactor) + start2 * blendFactor;
      }
      servo[2].write(interpolated);
    }

  }

  // Layer 4
  if(phrase0_layer_indices[4] < phrase0_layer4_count - 1) {
    unsigned long currentTime = pgm_read_dword(&phrase0_layer4_times[phrase0_layer_indices[4]]);
    unsigned long nextTime = pgm_read_dword(&phrase0_layer4_times[phrase0_layer_indices[4] + 1]);
    
    if(elapsed >= nextTime) {
      phrase0_layer_indices[4]++;
    }
    
    float factor = (elapsed >= currentTime && nextTime > currentTime) ? (float)(elapsed - currentTime) / (nextTime - currentTime) : 0;
    if(factor > 1.0) factor = 1.0;

    // Servo 4
    int curr4 = pgm_read_word(&phrase0_layer4_servo4[phrase0_layer_indices[4]]);
    int next4 = pgm_read_word(&phrase0_layer4_servo4[phrase0_layer_indices[4] + 1]);
    int start4 = pgm_read_word(&phrase0_layer4_servo4[0]);
    if(curr4 != -1 && next4 != -1) {
      int interpolated = curr4 + (int)((next4 - curr4) * factor);
      if(isBlending && start4 != -1) {
        interpolated = interpolated * (1.0 - blendFactor) + start4 * blendFactor;
      }
      servo[4].write(interpolated);
    }

  }

}

