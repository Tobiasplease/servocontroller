/*
 * 8-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-01-03 18:03:31
 * Layers: 8
 * Original Frames Recorded: 14552
 * Loop Duration: 18.54s (recorded) / 15.45s (at 1.2x speed)
 * Playback Speed: 1.2x
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
unsigned long loopDuration = 15450; // milliseconds (adjusted for 1.2x speed)

// Layer data structures

// Layer 1: Layer_1 (manual mode) - 42 keyframes
const int layer1_count = 42;
const unsigned long layer1_times[] PROGMEM = {17, 1496, 1854, 2276, 2461, 2680, 2941, 3241, 3563, 3837, 4115, 4415, 4691, 5061, 5341, 5548, 5913, 6335, 7827, 8158, 8366, 8751, 9065, 9350, 9515, 9671, 9785, 10082, 10325, 10510, 10757, 10913, 11072, 11252, 11447, 11643, 11858, 12048, 12332, 12620, 13831, 15428};
const int layer1_servo5[] PROGMEM = {106, 103, 100, 97, 94, 91, 88, 85, 82, 79, 76, 73, 69, 66, 63, 60, 57, 54, 57, 60, 63, 66, 69, 73, 76, 79, 82, 85, 88, 91, 94, 97, 100, 103, 106, 110, 113, 116, 119, 122, 119, 119};
int layer1_index = 0;

// Layer 2: Layer_3 (manual mode) - 188 keyframes
const int layer2_count = 188;
const unsigned long layer2_times[] PROGMEM = {16, 1072, 1184, 1227, 1280, 1384, 1546, 1666, 1748, 1826, 1934, 3081, 3158, 3273, 3337, 3404, 3560, 3632, 3700, 3769, 4107, 4192, 4273, 4375, 4640, 4794, 4839, 4888, 4954, 4996, 5059, 5130, 5204, 5276, 5348, 5417, 5487, 5535, 5581, 5625, 5672, 5714, 5765, 5810, 5871, 5919, 5973, 6024, 6071, 6117, 6163, 6209, 6255, 6301, 6354, 6411, 6457, 6510, 6556, 6992, 7041, 7096, 7155, 7201, 7256, 7297, 7342, 7400, 7445, 7492, 7536, 7578, 7625, 7671, 7717, 7763, 7810, 7856, 7897, 7942, 7989, 8038, 8082, 8124, 8170, 8243, 8353, 8573, 8625, 8677, 8726, 8775, 8855, 8927, 8972, 9016, 9063, 9109, 9154, 9201, 9244, 9287, 9329, 9375, 9422, 9474, 9520, 9564, 9606, 9659, 9720, 9786, 9861, 9908, 9949, 9992, 10179, 10225, 10312, 10380, 10468, 10527, 10573, 10619, 10663, 10722, 10786, 10835, 10877, 10923, 10965, 11011, 11075, 11144, 11266, 11319, 11370, 11416, 11483, 11559, 11628, 11700, 11776, 11856, 11907, 11954, 11999, 12051, 12095, 12138, 12184, 12228, 12275, 12322, 12367, 13449, 13492, 13538, 13586, 13629, 13675, 13722, 13770, 13836, 13906, 14056, 14103, 14230, 14288, 14333, 14521, 14563, 14611, 14659, 14710, 14751, 14794, 14849, 14921, 14994, 15045, 15091, 15137, 15180, 15225, 15269, 15334, 15426};
const int layer2_servo7[] PROGMEM = {43, 40, 43, 46, 49, 52, 55, 58, 61, 64, 67, 70, 74, 77, 80, 83, 86, 89, 92, 95, 98, 101, 104, 108, 111, 108, 104, 101, 98, 95, 92, 89, 86, 83, 80, 77, 74, 70, 67, 64, 60, 54, 49, 46, 43, 40, 37, 33, 30, 27, 24, 21, 18, 15, 12, 9, 6, 3, 0, 3, 6, 9, 12, 15, 19, 23, 28, 31, 36, 39, 45, 48, 57, 61, 64, 68, 75, 81, 88, 93, 96, 100, 104, 109, 112, 115, 118, 115, 112, 109, 105, 102, 99, 96, 93, 89, 81, 78, 73, 67, 58, 51, 45, 41, 38, 35, 31, 28, 25, 21, 18, 15, 12, 9, 5, 2, 6, 12, 15, 18, 21, 24, 27, 32, 36, 39, 42, 45, 48, 54, 57, 60, 63, 66, 63, 60, 57, 54, 51, 48, 45, 42, 39, 36, 32, 29, 26, 23, 20, 16, 13, 9, 6, 3, 0, 3, 6, 10, 14, 18, 22, 28, 33, 37, 40, 43, 46, 49, 52, 57, 54, 51, 47, 44, 41, 38, 31, 28, 25, 22, 19, 16, 13, 10, 6, 3, 0, 0};
int layer2_index = 0;

// Layer 3: Layer_4 (manual mode) - 226 keyframes
const int layer3_count = 226;
const unsigned long layer3_times[] PROGMEM = {24, 600, 646, 700, 792, 921, 1001, 1090, 1169, 1448, 1511, 1586, 1640, 1690, 1742, 1787, 1852, 1899, 1944, 1991, 2043, 2094, 2137, 2184, 2238, 2306, 2391, 2436, 2482, 2525, 2571, 2621, 2667, 2710, 2752, 2798, 2840, 2888, 2933, 2979, 3025, 3070, 3112, 3216, 3310, 3378, 3428, 3477, 3541, 3690, 3737, 3795, 3928, 4026, 4123, 4170, 4212, 4259, 4304, 4350, 4392, 4438, 4483, 4529, 4575, 4644, 4690, 4743, 5235, 5277, 5333, 5397, 5525, 5583, 5653, 5696, 5751, 5813, 5906, 5975, 6097, 6143, 6277, 6322, 6368, 6415, 6468, 6513, 6555, 6600, 6647, 6690, 6733, 6780, 6827, 6889, 7596, 7641, 7683, 7734, 7780, 7827, 7873, 7921, 7965, 8008, 8052, 8098, 8204, 8246, 8290, 8333, 8376, 8431, 8474, 8520, 8567, 8622, 8664, 8711, 8765, 8809, 9470, 9514, 9560, 9601, 9648, 9695, 9740, 9785, 9827, 9874, 9920, 9966, 10259, 10302, 10348, 10392, 10433, 10478, 10528, 10574, 10620, 10662, 10708, 10753, 10796, 10844, 10889, 10932, 10976, 11019, 11269, 11319, 11362, 11406, 11450, 11494, 11538, 11581, 11627, 11669, 11720, 11762, 11807, 11853, 11899, 11945, 11987, 12031, 12074, 12116, 12159, 12205, 12247, 12290, 12332, 12381, 12425, 12476, 12522, 12569, 12616, 12685, 12788, 12830, 12875, 12923, 12969, 13027, 13076, 13121, 13169, 13215, 13257, 13321, 13387, 13461, 13567, 13680, 13783, 13865, 13923, 13969, 14026, 14093, 14154, 14200, 14337, 14379, 14426, 14512, 14587, 14656, 14719, 14874, 14923, 14975, 15044, 15115, 15188, 15235, 15293, 15340, 15410, 15443};
const int layer3_servo0[] PROGMEM = {70, 67, 63, 60, 57, 54, 51, 48, 45, 48, 51, 54, 58, 61, 64, 71, 74, 78, 84, 87, 91, 95, 102, 111, 114, 117, 114, 102, 99, 92, 88, 80, 77, 65, 62, 57, 54, 50, 45, 38, 31, 27, 20, 16, 13, 10, 7, 4, 1, 4, 7, 10, 13, 16, 20, 23, 27, 32, 35, 38, 41, 46, 51, 54, 58, 61, 68, 71, 68, 63, 60, 57, 54, 50, 47, 44, 41, 38, 35, 32, 29, 24, 28, 61, 70, 86, 90, 101, 109, 115, 136, 146, 153, 161, 169, 178, 175, 166, 160, 154, 146, 128, 121, 114, 111, 107, 100, 89, 93, 103, 111, 119, 127, 131, 137, 141, 153, 162, 167, 170, 173, 178, 175, 168, 164, 156, 151, 135, 131, 123, 119, 104, 95, 78, 81, 86, 93, 96, 100, 105, 112, 115, 119, 123, 130, 135, 156, 159, 163, 168, 172, 177, 172, 161, 156, 149, 144, 139, 135, 128, 123, 113, 109, 102, 97, 93, 80, 77, 63, 60, 55, 51, 48, 44, 41, 37, 33, 30, 26, 22, 19, 14, 11, 8, 11, 19, 26, 29, 32, 36, 39, 42, 45, 48, 51, 55, 58, 61, 64, 67, 70, 73, 76, 79, 82, 85, 88, 92, 95, 100, 103, 106, 110, 113, 116, 113, 110, 106, 103, 100, 97, 92, 88, 81, 77, 74};
int layer3_index = 0;

// Layer 4: Layer_5 (manual mode) - 214 keyframes
const int layer4_count = 214;
const unsigned long layer4_times[] PROGMEM = {4, 116, 161, 206, 251, 298, 345, 391, 437, 483, 536, 1080, 1132, 1175, 1246, 1288, 1333, 1375, 1427, 1475, 1528, 1589, 1634, 1680, 1722, 1777, 1822, 1867, 1913, 1961, 2006, 2052, 2226, 2271, 2322, 2367, 2411, 2457, 2504, 2549, 2595, 2643, 2690, 2735, 2781, 2828, 2874, 2972, 3018, 3064, 3111, 3157, 3201, 3247, 3314, 3364, 3406, 3453, 3499, 3545, 3587, 3685, 3731, 3777, 3824, 3869, 3916, 3962, 4031, 4101, 4164, 4211, 4257, 4315, 4381, 4436, 4505, 4581, 4627, 4679, 4725, 4806, 4881, 4941, 4989, 5038, 5086, 5130, 5211, 5310, 5357, 5403, 5511, 5729, 5774, 5820, 7081, 7127, 7174, 7222, 7264, 7309, 7353, 7399, 7446, 7492, 7550, 7597, 7641, 7724, 7793, 7944, 8076, 8528, 8701, 8749, 8793, 8841, 8939, 8996, 9135, 9181, 9234, 9281, 9327, 9373, 9418, 9459, 9505, 9562, 9609, 9657, 9700, 9744, 9789, 9832, 9877, 9923, 10004, 10269, 10317, 10360, 10421, 10466, 10513, 10557, 10600, 10644, 10688, 10731, 10773, 10823, 10866, 10918, 10963, 11010, 11056, 11102, 11153, 11196, 11240, 11294, 11336, 11381, 11428, 11470, 11514, 11561, 11625, 11669, 11711, 11757, 11803, 11878, 11923, 11965, 12011, 12086, 12232, 12278, 12322, 12393, 12449, 12495, 12537, 12584, 12632, 12677, 12724, 12776, 12845, 12959, 13001, 13064, 13105, 13151, 13221, 13273, 13319, 13365, 13473, 13526, 13574, 13632, 13678, 13771, 15061, 15166, 15218, 15264, 15311, 15357, 15403, 15444};
const int layer4_servo1[] PROGMEM = {94, 91, 83, 75, 47, 43, 29, 23, 12, 5, 0, 3, 6, 9, 12, 16, 24, 33, 50, 54, 57, 60, 65, 69, 72, 75, 79, 83, 89, 92, 96, 102, 99, 93, 81, 77, 67, 57, 50, 43, 38, 33, 28, 25, 21, 15, 11, 16, 28, 33, 42, 46, 56, 65, 68, 71, 75, 79, 85, 94, 99, 92, 78, 75, 71, 67, 63, 60, 57, 54, 50, 47, 44, 41, 38, 35, 32, 35, 43, 47, 51, 54, 58, 61, 64, 67, 70, 74, 77, 80, 83, 86, 90, 86, 74, 71, 0, 6, 9, 12, 15, 20, 23, 31, 34, 37, 40, 45, 49, 52, 56, 59, 62, 81, 78, 75, 72, 68, 65, 62, 65, 68, 71, 74, 80, 84, 95, 98, 102, 105, 109, 112, 115, 118, 121, 124, 128, 131, 134, 130, 123, 118, 115, 111, 107, 103, 99, 95, 89, 82, 76, 72, 68, 65, 61, 57, 53, 50, 47, 44, 39, 36, 40, 49, 54, 60, 64, 70, 73, 78, 82, 91, 94, 97, 103, 111, 119, 122, 118, 110, 104, 101, 98, 95, 92, 88, 84, 80, 76, 73, 69, 74, 83, 86, 90, 94, 97, 100, 110, 116, 119, 123, 128, 132, 135, 138, 135, 132, 129, 125, 121, 113, 105, 97};
int layer4_index = 0;

// Layer 5: Layer_6 (manual mode) - 274 keyframes
const int layer5_count = 274;
const unsigned long layer5_times[] PROGMEM = {23, 201, 242, 287, 357, 403, 450, 495, 538, 587, 633, 675, 722, 767, 814, 860, 907, 952, 1004, 1186, 1230, 1276, 1320, 1362, 1405, 1451, 1497, 1543, 1595, 1642, 1688, 1734, 1780, 1835, 1879, 1923, 1966, 2046, 2128, 2233, 2306, 2353, 2401, 2452, 2504, 2550, 2597, 2640, 2687, 2736, 2779, 2825, 2870, 2912, 2956, 3003, 3048, 3092, 3138, 3184, 3230, 3277, 3321, 3367, 3422, 3609, 3673, 3765, 3812, 3858, 3910, 3951, 4003, 4049, 4095, 4136, 4182, 4224, 4266, 4309, 4367, 4420, 4465, 4524, 4727, 4991, 5037, 5082, 5138, 5211, 5270, 5334, 5397, 5605, 5651, 5699, 5745, 5786, 5831, 5877, 5924, 5965, 6009, 6052, 6098, 6145, 6190, 6237, 6317, 6377, 6428, 6683, 6728, 6792, 6850, 6900, 6943, 6985, 7032, 7082, 7130, 7172, 7218, 7264, 7308, 7354, 7405, 7447, 7493, 7535, 7578, 7624, 7670, 7712, 7776, 7956, 8002, 8049, 8097, 8145, 8192, 8236, 8283, 8328, 8375, 8421, 8467, 8512, 8564, 8668, 8710, 8757, 8804, 8850, 8897, 8940, 8986, 9031, 9076, 9118, 9160, 9206, 9251, 9296, 9508, 9551, 9595, 9645, 9691, 9738, 9784, 9830, 9876, 9923, 9975, 10019, 10102, 10149, 10195, 10241, 10287, 10331, 10378, 10430, 10478, 10521, 10565, 10612, 10656, 10698, 10741, 10784, 10831, 10878, 10925, 10971, 11146, 11194, 11236, 11283, 11330, 11376, 11421, 11465, 11511, 11562, 11610, 11654, 11707, 11752, 11799, 11851, 11900, 11955, 12001, 12056, 12114, 12160, 12221, 12429, 12478, 12521, 12564, 12609, 12655, 12698, 12740, 12784, 12829, 12876, 12922, 12970, 13013, 13071, 13161, 13205, 13251, 13297, 13342, 13391, 13436, 13480, 13571, 13752, 13823, 13868, 13928, 13980, 14047, 14142, 14201, 14263, 14333, 14437, 14483, 14530, 14581, 14623, 14669, 14714, 14757, 14802, 14847, 14893, 14935, 14980, 15032, 15078, 15124, 15170, 15242, 15357, 15400, 15443};
const int layer5_servo2[] PROGMEM = {156, 153, 148, 145, 142, 138, 134, 130, 127, 123, 120, 117, 111, 104, 99, 95, 91, 87, 84, 87, 91, 95, 98, 101, 105, 111, 115, 120, 123, 129, 134, 137, 145, 148, 152, 156, 164, 167, 170, 173, 169, 163, 160, 157, 154, 151, 146, 139, 133, 123, 116, 108, 103, 98, 90, 84, 80, 76, 69, 64, 60, 55, 48, 44, 41, 38, 35, 39, 42, 45, 51, 58, 65, 69, 75, 84, 91, 95, 100, 103, 106, 110, 114, 117, 120, 117, 113, 110, 107, 104, 101, 98, 95, 98, 102, 105, 108, 112, 121, 134, 139, 143, 147, 153, 158, 163, 166, 170, 173, 176, 179, 176, 172, 169, 166, 162, 155, 147, 138, 130, 127, 123, 116, 104, 100, 92, 87, 82, 77, 73, 65, 62, 58, 54, 51, 54, 61, 68, 79, 84, 91, 100, 110, 117, 123, 127, 133, 136, 139, 136, 126, 120, 109, 101, 93, 87, 79, 72, 68, 60, 51, 46, 36, 30, 34, 41, 55, 62, 68, 74, 80, 86, 96, 100, 103, 106, 103, 94, 89, 86, 82, 79, 75, 68, 63, 58, 51, 46, 41, 34, 29, 23, 20, 14, 10, 7, 10, 13, 16, 22, 27, 31, 34, 37, 41, 44, 47, 51, 59, 65, 69, 72, 75, 78, 88, 94, 97, 119, 123, 120, 117, 109, 106, 103, 100, 93, 87, 84, 79, 75, 70, 65, 58, 55, 58, 65, 69, 72, 77, 81, 86, 91, 94, 97, 100, 103, 106, 109, 112, 115, 118, 121, 124, 121, 115, 111, 108, 104, 100, 93, 87, 82, 77, 69, 61, 57, 54, 50, 47, 44, 41, 44, 48, 54};
int layer5_index = 0;

// Layer 6: Layer_7 (manual mode) - 266 keyframes
const int layer6_count = 266;
const unsigned long layer6_times[] PROGMEM = {9, 315, 367, 415, 458, 503, 579, 641, 707, 756, 830, 902, 957, 1003, 1050, 1101, 1145, 1200, 1246, 1305, 1354, 1396, 1513, 1560, 1605, 1683, 1738, 1784, 1826, 1872, 1923, 2139, 2185, 2232, 2326, 2370, 2414, 2469, 2515, 2558, 2610, 2713, 2755, 2807, 2852, 2897, 2942, 2983, 3028, 3075, 3126, 3171, 3214, 3271, 3319, 3367, 3418, 3492, 3543, 3608, 3707, 3771, 3886, 4065, 4166, 4210, 4256, 4303, 4350, 4401, 4469, 4511, 4557, 4602, 4673, 4747, 4945, 4995, 5044, 5119, 5191, 5233, 5280, 5327, 5372, 5420, 5545, 5587, 5634, 5680, 5725, 5773, 5819, 5865, 5907, 5970, 6027, 6073, 6148, 6200, 6357, 6403, 6455, 6501, 6548, 6595, 6641, 6687, 6744, 6818, 6862, 6904, 6948, 6994, 7040, 7086, 7128, 7180, 7226, 7277, 7486, 7535, 7581, 7863, 7906, 7951, 7994, 8037, 8084, 8130, 8176, 8223, 8279, 8325, 8372, 8434, 8493, 8562, 8673, 8719, 8766, 8811, 8852, 8899, 8945, 8992, 9038, 9084, 9129, 9177, 9223, 9269, 9319, 9361, 9407, 9453, 9507, 9550, 9652, 9695, 9738, 9783, 9830, 9876, 9921, 9963, 10010, 10058, 10102, 10146, 10188, 10236, 10280, 10322, 10368, 10417, 10462, 10510, 10554, 10599, 10721, 10763, 10808, 10853, 10899, 10944, 10990, 11032, 11075, 11121, 11170, 11212, 11254, 11297, 11341, 11387, 11438, 11480, 11538, 11680, 11735, 11786, 11832, 11877, 11931, 11982, 12029, 12117, 12186, 12232, 12279, 12325, 12371, 12418, 12464, 12510, 12560, 12607, 12752, 12829, 12915, 13055, 13100, 13143, 13221, 13291, 13343, 13385, 13432, 13477, 13522, 13570, 13621, 13667, 13714, 13760, 13803, 13852, 13894, 13939, 13984, 14032, 14082, 14125, 14171, 14223, 14289, 14546, 14590, 14634, 14680, 14728, 14773, 14818, 14900, 14945, 15039, 15084, 15132, 15178, 15264, 15311, 15355, 15397, 15439, 15446};
const int layer6_servo3[] PROGMEM = {140, 137, 134, 131, 127, 124, 121, 118, 114, 111, 108, 105, 108, 116, 120, 123, 130, 134, 138, 142, 145, 148, 145, 138, 134, 131, 128, 124, 120, 112, 105, 109, 129, 136, 139, 142, 145, 148, 152, 158, 162, 157, 150, 147, 138, 131, 121, 113, 108, 100, 97, 94, 91, 87, 84, 80, 77, 74, 71, 68, 65, 62, 59, 62, 65, 73, 79, 82, 86, 97, 100, 105, 108, 115, 118, 121, 118, 115, 112, 109, 106, 103, 99, 96, 93, 90, 93, 97, 100, 103, 109, 117, 125, 132, 137, 140, 144, 150, 153, 156, 153, 147, 142, 139, 135, 131, 126, 121, 118, 115, 112, 109, 104, 98, 92, 88, 83, 79, 76, 73, 76, 79, 83, 86, 91, 94, 98, 105, 110, 117, 123, 127, 130, 134, 137, 140, 143, 146, 143, 135, 131, 128, 117, 109, 91, 81, 69, 60, 55, 50, 47, 43, 40, 37, 33, 24, 21, 15, 19, 22, 26, 47, 52, 62, 69, 74, 79, 85, 90, 94, 102, 110, 119, 122, 131, 134, 140, 145, 152, 155, 152, 143, 137, 134, 130, 126, 121, 117, 112, 106, 103, 99, 96, 93, 86, 81, 78, 75, 72, 75, 78, 81, 84, 88, 92, 95, 98, 101, 104, 108, 115, 120, 124, 132, 139, 150, 157, 162, 165, 168, 171, 167, 156, 149, 146, 143, 138, 133, 124, 119, 110, 106, 101, 97, 93, 88, 84, 80, 75, 71, 66, 62, 59, 56, 52, 49, 46, 49, 52, 56, 63, 68, 76, 82, 85, 89, 92, 96, 100, 107, 104, 95, 86, 80, 76, 74};
int layer6_index = 0;

// Layer 7: Layer_8 (manual mode) - 199 keyframes
const int layer7_count = 199;
const unsigned long layer7_times[] PROGMEM = {0, 200, 244, 334, 379, 426, 476, 663, 708, 750, 796, 848, 895, 940, 986, 1028, 1074, 1120, 1166, 1213, 1259, 1306, 1352, 1403, 1467, 1648, 1690, 1738, 1785, 1913, 1962, 2005, 2052, 2109, 2242, 2284, 2332, 2380, 2422, 2468, 2516, 2561, 2607, 2654, 2700, 2746, 2793, 2859, 2994, 3040, 3082, 3139, 3198, 3244, 3297, 3343, 3385, 3431, 3474, 3522, 3568, 3627, 3671, 3725, 3800, 3847, 3904, 3946, 4084, 4125, 4182, 4227, 4288, 4332, 4376, 4420, 4466, 4516, 4559, 4604, 4646, 4692, 4743, 4818, 4883, 4932, 4981, 5033, 5128, 5236, 5362, 5709, 5814, 5930, 6514, 6556, 6599, 6647, 6717, 6768, 6833, 6879, 6926, 6982, 7024, 7070, 7116, 7186, 7249, 7329, 7372, 7417, 7473, 7537, 7591, 7637, 7688, 7776, 7872, 7928, 7994, 8066, 8192, 8842, 9668, 9715, 9760, 10113, 10171, 10234, 10278, 10333, 11070, 11115, 11166, 11219, 11265, 11307, 11353, 11397, 11445, 11490, 11537, 11584, 11629, 11676, 11722, 11819, 11868, 11935, 12015, 12108, 12353, 12398, 12441, 12487, 12533, 12579, 12654, 12806, 12851, 12893, 12937, 13012, 13066, 13119, 13163, 13211, 13257, 13306, 13353, 13400, 13449, 14049, 14098, 14165, 14259, 14303, 14356, 14430, 14500, 14576, 14656, 14742, 14830, 14877, 14928, 14974, 15022, 15067, 15115, 15159, 15204, 15246, 15291, 15345, 15390, 15438, 15444};
const int layer7_servo4[] PROGMEM = {108, 111, 118, 121, 129, 148, 156, 153, 147, 142, 139, 136, 127, 115, 105, 96, 85, 72, 66, 55, 50, 39, 34, 22, 19, 22, 31, 50, 58, 61, 64, 71, 75, 78, 75, 63, 58, 55, 51, 48, 44, 38, 31, 26, 22, 19, 15, 12, 15, 24, 32, 36, 39, 43, 46, 49, 54, 59, 62, 65, 69, 73, 76, 79, 82, 85, 88, 96, 92, 87, 84, 81, 78, 75, 68, 62, 59, 56, 53, 48, 43, 39, 34, 31, 28, 25, 22, 19, 16, 13, 10, 7, 4, 1, 4, 8, 14, 17, 20, 23, 26, 29, 32, 36, 40, 44, 57, 60, 63, 66, 74, 79, 82, 85, 88, 92, 98, 101, 104, 107, 110, 113, 116, 119, 123, 140, 146, 149, 167, 170, 175, 178, 175, 170, 166, 163, 160, 157, 153, 149, 146, 142, 133, 128, 123, 114, 110, 107, 104, 101, 98, 95, 98, 110, 116, 121, 126, 131, 134, 131, 127, 116, 111, 108, 104, 101, 98, 95, 91, 88, 82, 76, 73, 69, 62, 59, 56, 50, 47, 44, 41, 38, 34, 31, 34, 41, 45, 48, 51, 57, 60, 69, 73, 78, 83, 86, 90, 93, 94};
int layer7_index = 0;

// Layer 8: Layer_8 (manual mode) - 23 keyframes
const int layer8_count = 23;
const unsigned long layer8_times[] PROGMEM = {1, 730, 1585, 1987, 2250, 3118, 3679, 4166, 8288, 8606, 8926, 10527, 10777, 10945, 12070, 12339, 12473, 13388, 13547, 14789, 15109, 15227, 15429};
const int layer8_servo6[] PROGMEM = {72, 68, 72, 75, 78, 81, 84, 87, 84, 81, 78, 75, 72, 68, 65, 62, 59, 56, 53, 56, 59, 62, 65};
int layer8_index = 0;

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
    layer5_index = 0;
    layer6_index = 0;
    layer7_index = 0;
    layer8_index = 0;
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
    }
  }

  // Update layer 5 with interpolation
  if(layer5_index < layer5_count - 1) {
    unsigned long currentTime = pgm_read_dword(&layer5_times[layer5_index]);
    unsigned long nextTime = pgm_read_dword(&layer5_times[layer5_index + 1]);
    
    // Move to next keyframe if we've passed it
    if(elapsed >= nextTime) {
      layer5_index++;
    }
    
    // Interpolate between current and next keyframe
    if(layer5_index < layer5_count - 1 && elapsed >= currentTime) {
      currentTime = pgm_read_dword(&layer5_times[layer5_index]);
      nextTime = pgm_read_dword(&layer5_times[layer5_index + 1]);
      
      // Calculate interpolation factor (0.0 to 1.0)
      float factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
      factor = constrain(factor, 0.0, 1.0);
      
      // Interpolate Middle
      int curr2 = pgm_read_word(&layer5_servo2[layer5_index]);
      int next2 = pgm_read_word(&layer5_servo2[layer5_index + 1]);
      int start2 = pgm_read_word(&layer5_servo2[0]);
      
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
    }
  }

  // Update layer 6 with interpolation
  if(layer6_index < layer6_count - 1) {
    unsigned long currentTime = pgm_read_dword(&layer6_times[layer6_index]);
    unsigned long nextTime = pgm_read_dword(&layer6_times[layer6_index + 1]);
    
    // Move to next keyframe if we've passed it
    if(elapsed >= nextTime) {
      layer6_index++;
    }
    
    // Interpolate between current and next keyframe
    if(layer6_index < layer6_count - 1 && elapsed >= currentTime) {
      currentTime = pgm_read_dword(&layer6_times[layer6_index]);
      nextTime = pgm_read_dword(&layer6_times[layer6_index + 1]);
      
      // Calculate interpolation factor (0.0 to 1.0)
      float factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
      factor = constrain(factor, 0.0, 1.0);
      
      // Interpolate Ring
      int curr3 = pgm_read_word(&layer6_servo3[layer6_index]);
      int next3 = pgm_read_word(&layer6_servo3[layer6_index + 1]);
      int start3 = pgm_read_word(&layer6_servo3[0]);
      
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
    }
  }

  // Update layer 7 with interpolation
  if(layer7_index < layer7_count - 1) {
    unsigned long currentTime = pgm_read_dword(&layer7_times[layer7_index]);
    unsigned long nextTime = pgm_read_dword(&layer7_times[layer7_index + 1]);
    
    // Move to next keyframe if we've passed it
    if(elapsed >= nextTime) {
      layer7_index++;
    }
    
    // Interpolate between current and next keyframe
    if(layer7_index < layer7_count - 1 && elapsed >= currentTime) {
      currentTime = pgm_read_dword(&layer7_times[layer7_index]);
      nextTime = pgm_read_dword(&layer7_times[layer7_index + 1]);
      
      // Calculate interpolation factor (0.0 to 1.0)
      float factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
      factor = constrain(factor, 0.0, 1.0);
      
      // Interpolate Pinky
      int curr4 = pgm_read_word(&layer7_servo4[layer7_index]);
      int next4 = pgm_read_word(&layer7_servo4[layer7_index + 1]);
      int start4 = pgm_read_word(&layer7_servo4[0]);
      
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

  // Update layer 8 with interpolation
  if(layer8_index < layer8_count - 1) {
    unsigned long currentTime = pgm_read_dword(&layer8_times[layer8_index]);
    unsigned long nextTime = pgm_read_dword(&layer8_times[layer8_index + 1]);
    
    // Move to next keyframe if we've passed it
    if(elapsed >= nextTime) {
      layer8_index++;
    }
    
    // Interpolate between current and next keyframe
    if(layer8_index < layer8_count - 1 && elapsed >= currentTime) {
      currentTime = pgm_read_dword(&layer8_times[layer8_index]);
      nextTime = pgm_read_dword(&layer8_times[layer8_index + 1]);
      
      // Calculate interpolation factor (0.0 to 1.0)
      float factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
      factor = constrain(factor, 0.0, 1.0);
      
      // Interpolate Elbow
      int curr6 = pgm_read_word(&layer8_servo6[layer8_index]);
      int next6 = pgm_read_word(&layer8_servo6[layer8_index + 1]);
      int start6 = pgm_read_word(&layer8_servo6[0]);
      
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

  delay(5); // 200Hz update rate for smooth interpolation
}
