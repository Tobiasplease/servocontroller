/*
 * 10-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-08-20 23:44:02
 * Hardware Config: Default
 * Layers: 3
 * Original Frames Recorded: 9674
 * Loop Duration: 34.29s (recorded) / 34.29s (at 1.0x speed)
 * Playback Speed: 1.0x
 * 
 * Layer Priority (later layers override earlier for same servo):
 * Servo 0 (S0 (D12)): Layer 1
 * Servo 1 (S1 (D11)): Layer 1
 * Servo 2 (S2 (D10)): Layer 3
 * Servo 3 (S3 (D9)): Layer 1
 * Servo 4 (S4 (D8)): Layer 1
 * Servo 5 (S5 (D7)): Layer 2
 * 
 * Hardware: 5 group-A channels + 5 group-B channels
 * Group A: S0 (D12), S1 (D11), S2 (D10), S3 (D9), S4 (D8)
 * Group B: S5 (D7), S6 (D6), S7 (D5), S8 (D4), S9 (D2)
 *
 * Channel -> pin mapping:
 * S0 -> D12
 * S1 -> D11
 * S2 -> D10
 * S3 -> D9
 * S4 -> D8
 * S5 -> D7
 * S6 -> D6
 * S7 -> D5
 * S8 -> D4
 * S9 -> D2
 *
 * Stored positions already constrained during recording
 */

#include <Servo.h>

// Servo objects
Servo servo[10];
int servoPins[10] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 2};

// Range configuration (from hardware preset: Default)
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 120;

// ---- Organic variation ----------------------------------------------------
// Mirrors the Organic panel in the UI, so the sketch breathes the same way the
// preview did. 0 values = exact replay of the recorded take.
// (Pause Chance is a live-preview control only and is not exported.)
const float WOBBLE_AMOUNT = 0.0;   // degrees of drift per channel
const float TIMING_JITTER = 0.0;   // fraction, e.g. 0.08 = +/-8% tempo
float phaseOffset[10];
float jitterMul = 1.0;
float jitterTarget = 1.0;
unsigned long lastJitterUpdate = 0;
unsigned long organicClock = 0;   // jitter-warped playback clock
unsigned long lastTickMs = 0;

// Layered slow sines rather than random jumps -- random per-frame offsets read
// as twitch on a servo, not as life.
int applyWobble(int index, int pos) {
  if (WOBBLE_AMOUNT <= 0.0) return pos;
  float t = millis() / 1000.0;
  float breath = sin(t * 0.7 + phaseOffset[index]);
  float drift  = sin(t * 0.23 + phaseOffset[index] * 1.7) * 0.6;
  float tremor = sin(t * 2.9 + phaseOffset[index] * 0.4) * 0.15;
  return pos + (int)((breath + drift + tremor) * WOBBLE_AMOUNT * 0.5);
}

// Helper: clamp to the rig's range and reverse the specified channels.
// Recorded positions are already degrees, so nothing is rescaled here -- doing
// so replayed every take smaller than it was performed.
void writeServo(int index, int pos) {
  pos = applyWobble(index, pos);
  pos = constrain(pos, MIN_ANGLE, MAX_ANGLE);
  if(index == 2 || index == 4) pos = MIN_ANGLE + MAX_ANGLE - pos;  // Reverse S2 (D10), S4 (D8)
  servo[index].write(pos);
}

// Timing
unsigned long loopStartTime;
unsigned long loopDuration = 34290; // milliseconds (adjusted for 1.0x speed)

// Startup pose (matches first recorded frame per owned servo)
const int startupPositions[10] = {20, 35, 32, 23, 28, 172, 90, 90, 90, 90};

// Layer data structures

// Layer 1: Layer_1 (cursor mode) - 131 keyframes
const int layer1_count = 131;
const unsigned long layer1_times[] PROGMEM = {0, 386, 491, 597, 1006, 1107, 1211, 1316, 1427, 1759, 1860, 1972, 2076, 2180, 2320, 2428, 2533, 2636, 2813, 2930, 3133, 3237, 3347, 3819, 3973, 4397, 4573, 5006, 5760, 6026, 6199, 7120, 7304, 7465, 7673, 8090, 8202, 8306, 8409, 8545, 8746, 9050, 9196, 9474, 9620, 9730, 9914, 10074, 10388, 10562, 10970, 11131, 11348, 11500, 11717, 11936, 12100, 12357, 12676, 12837, 12994, 13101, 13316, 13749, 13852, 13982, 14101, 14341, 14445, 14565, 14864, 15110, 15391, 15905, 16167, 16665, 16775, 16881, 16998, 17775, 18000, 18265, 18601, 18787, 19133, 19363, 19592, 19738, 19842, 20056, 20163, 20366, 20674, 20907, 21107, 21588, 21715, 22097, 22219, 22426, 22537, 22642, 22871, 22988, 23164, 23348, 23460, 23564, 23780, 24062, 24445, 24682, 24789, 24902, 25037, 25143, 25263, 25383, 25496, 25607, 25732, 25952, 26246, 26351, 26575, 26684, 26815, 27835, 30825, 31865, 34290};
const int layer1_servo0[] PROGMEM = {  // S0 (D12) (OWNED)
  20, 19, 14, 11, 12, 16, 21, 26, 32, 32, 28, 25, 20, 17, 14, 14, 19, 24, 27, 31, 31, 28, 23, 24, 27, 26, 23, 24, 25, 23, 20, 20, 22, 26, 29, 29, 26, 22, 18, 15, 12, 10, 10, 11, 15, 18, 22, 24, 26, 28, 27, 25, 22, 19, 16, 12, 9, 7, 9, 12, 15, 19, 23, 23, 20, 16, 13, 13, 17, 20, 20, 17, 19, 23, 26, 22, 19, 16, 11, 14, 18, 21, 21, 24, 26, 27, 24, 21, 19, 23, 27, 23, 25, 25, 28, 32, 30, 32, 29, 32, 35, 30, 33, 27, 30, 27, 23, 28, 25, 28, 25, 26, 30, 32, 29, 24, 20, 15, 20, 26, 31, 33, 31, 27, 30, 33, 29, 32, 28, 30, 30};
const int layer1_servo1[] PROGMEM = {  // S1 (D11) (OWNED)
  35, 30, 24, 18, 23, 29, 36, 44, 52, 47, 40, 35, 28, 23, 21, 26, 34, 42, 47, 50, 45, 40, 33, 38, 43, 38, 33, 38, 33, 28, 23, 21, 25, 30, 35, 36, 33, 28, 23, 20, 19, 22, 23, 26, 30, 36, 41, 44, 46, 46, 41, 36, 31, 26, 21, 17, 15, 15, 20, 25, 32, 37, 43, 42, 38, 32, 27, 29, 34, 39, 37, 33, 37, 42, 47, 42, 37, 30, 21, 22, 26, 32, 37, 42, 48, 48, 43, 38, 34, 36, 41, 40, 44, 41, 44, 46, 41, 43, 37, 44, 46, 38, 41, 32, 38, 32, 27, 34, 29, 34, 29, 34, 39, 41, 36, 28, 22, 19, 30, 38, 44, 45, 44, 39, 38, 42, 37, 40, 34, 38, 39};
const int layer1_servo3[] PROGMEM = {  // S3 (D9) (OWNED)
  23, 20, 14, 8, 11, 18, 25, 32, 41, 39, 34, 30, 23, 17, 12, 14, 22, 30, 35, 39, 38, 34, 27, 28, 33, 31, 26, 28, 30, 29, 26, 31, 36, 41, 44, 39, 34, 27, 21, 15, 10, 10, 13, 18, 23, 29, 34, 39, 44, 49, 49, 46, 42, 37, 32, 27, 22, 17, 18, 21, 26, 31, 35, 31, 26, 20, 16, 20, 25, 29, 25, 21, 26, 30, 35, 35, 32, 29, 25, 30, 36, 40, 38, 41, 41, 36, 31, 26, 22, 26, 32, 28, 32, 30, 34, 39, 37, 42, 39, 40, 49, 42, 49, 41, 44, 42, 36, 44, 40, 42, 36, 33, 38, 44, 42, 35, 26, 15, 21, 30, 38, 43, 38, 33, 39, 44, 40, 45, 42, 50, 51};
const int layer1_servo4[] PROGMEM = {  // S4 (D8) (OWNED)
  28, 31, 37, 43, 41, 34, 27, 20, 11, 11, 17, 21, 28, 33, 38, 37, 30, 23, 18, 12, 13, 17, 24, 23, 18, 19, 24, 23, 22, 24, 29, 29, 26, 20, 15, 16, 20, 26, 31, 36, 40, 43, 44, 42, 37, 32, 26, 23, 20, 17, 19, 21, 25, 30, 35, 40, 45, 49, 46, 41, 36, 30, 25, 25, 28, 34, 39, 39, 33, 28, 29, 34, 30, 25, 20, 25, 30, 35, 42, 37, 32, 28, 28, 23, 19, 19, 23, 28, 30, 24, 19, 25, 22, 22, 16, 11, 14, 10, 15, 11, 6, 13, 10, 18, 13, 18, 24, 16, 22, 16, 22, 19, 14, 10, 15, 23, 29, 36, 29, 20, 13, 9, 13, 18, 14, 10, 15, 11, 16, 14, 14};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 408 keyframes
const int layer2_count = 408;
const unsigned long layer2_times[] PROGMEM = {0, 205, 258, 309, 363, 420, 478, 536, 594, 645, 700, 755, 819, 932, 1107, 1165, 1221, 1275, 1328, 1379, 1431, 1489, 1549, 1644, 1698, 1840, 1892, 1949, 2006, 2057, 2117, 2382, 2443, 2499, 2558, 2623, 2674, 2732, 2785, 2926, 2980, 3034, 3092, 3155, 3209, 3262, 3430, 3482, 3539, 3599, 3656, 3713, 3772, 3828, 3887, 3946, 4002, 4289, 4342, 4393, 4448, 4505, 4562, 4613, 4683, 4736, 5067, 5120, 5170, 5226, 5279, 5331, 5383, 5434, 5489, 5705, 5760, 5815, 5869, 5925, 5976, 6402, 6457, 6509, 6566, 6618, 6669, 7043, 7100, 7153, 7208, 7259, 7320, 7627, 7677, 7732, 7791, 7849, 7901, 7956, 8011, 8073, 8336, 8394, 8445, 8495, 8550, 8605, 8664, 8716, 9084, 9135, 9186, 9242, 9297, 9352, 9405, 9455, 9516, 9572, 9824, 9878, 9930, 9982, 10036, 10091, 10150, 10201, 10261, 10325, 10468, 10525, 10576, 10627, 10683, 10742, 10798, 10854, 10910, 11039, 11090, 11140, 11191, 11247, 11669, 11723, 11773, 11824, 11884, 11943, 12184, 12235, 12286, 12337, 12407, 12843, 12899, 12955, 13020, 13076, 13129, 13186, 13328, 13381, 13435, 13492, 13548, 13600, 14012, 14073, 14131, 14182, 14233, 14288, 14347, 14403, 14473, 14545, 14597, 14652, 14707, 14763, 14820, 14923, 14997, 15052, 15122, 15178, 15229, 15291, 15348, 15400, 15451, 15507, 15564, 15643, 15825, 15884, 15947, 16004, 16057, 16107, 16160, 16243, 16498, 16557, 16621, 16680, 16732, 16789, 17068, 17118, 17168, 17224, 17280, 17337, 17396, 17728, 17785, 17852, 17911, 17965, 18024, 18408, 18467, 18531, 18586, 18642, 18694, 18822, 18872, 18990, 19040, 19096, 19150, 19206, 19261, 19573, 19627, 19680, 19733, 19798, 19848, 19901, 19955, 20082, 20136, 20199, 20256, 20310, 20367, 20624, 20676, 20729, 20792, 20848, 20904, 20967, 21113, 21174, 21224, 21280, 21335, 21387, 21480, 21535, 21592, 21658, 21714, 21780, 21856, 21914, 21968, 22022, 22079, 22257, 22308, 22361, 22445, 22633, 22691, 22742, 22797, 22853, 22950, 23033, 23083, 23136, 23193, 23249, 23325, 23490, 23546, 23606, 23688, 24139, 24199, 24257, 24311, 24362, 24451, 24515, 24853, 24920, 24980, 25033, 25099, 25492, 25559, 25610, 25660, 25712, 25767, 25821, 25887, 25943, 25994, 26076, 26394, 26602, 26658, 26710, 26765, 27472, 27530, 27596, 27654, 27709, 27765, 27827, 27880, 28247, 28311, 28367, 28431, 28483, 28540, 28613, 28680, 28762, 28814, 28905, 29138, 29203, 29260, 29340, 29394, 29445, 29600, 29704, 29977, 30031, 30088, 30153, 30205, 30277, 30331, 30409, 30460, 30519, 30632, 30689, 30744, 30812, 30881, 30935, 30989, 31118, 31169, 31223, 31274, 31327, 31378, 31451, 31520, 31867, 31921, 31973, 32026, 32079, 32143, 32222, 32279, 32367, 32420, 32474, 32612, 32671, 32728, 32780, 32833, 32889, 32954, 33011, 33070, 33284, 33343, 33400, 33452, 33506, 33776, 33834, 33889, 33943, 33996, 34052, 34133, 34290};
const int layer2_servo5[] PROGMEM = {  // S5 (D7) (OWNED)
  172, 169, 163, 156, 137, 117, 92, 79, 58, 52, 40, 29, 25, 22, 26, 64, 90, 99, 106, 123, 136, 147, 156, 159, 164, 160, 136, 112, 84, 75, 15, 4, 81, 118, 141, 145, 157, 169, 180, 173, 146, 94, 68, 33, 9, 3, 0, 18, 26, 49, 68, 103, 125, 138, 154, 163, 175, 172, 151, 132, 92, 61, 46, 19, 15, 2, 10, 50, 80, 95, 118, 129, 138, 151, 177, 167, 119, 77, 55, 35, 0, 7, 38, 63, 111, 135, 172, 166, 133, 81, 42, 28, 8, 0, 23, 47, 79, 111, 135, 157, 166, 169, 164, 116, 97, 78, 50, 41, 33, 3, 0, 4, 8, 37, 83, 116, 139, 160, 166, 173, 170, 142, 121, 86, 61, 50, 36, 13, 7, 0, 4, 28, 60, 90, 112, 137, 155, 165, 168, 164, 135, 92, 44, 2, 14, 73, 109, 130, 149, 165, 160, 111, 75, 31, 3, 9, 46, 70, 99, 133, 150, 154, 149, 113, 76, 40, 16, 1, 8, 41, 64, 76, 104, 118, 138, 162, 165, 161, 133, 126, 93, 59, 36, 31, 27, 23, 19, 24, 58, 100, 119, 144, 158, 162, 169, 178, 174, 138, 90, 49, 27, 16, 8, 1, 12, 74, 120, 156, 175, 180, 174, 146, 109, 87, 54, 18, 5, 11, 30, 98, 135, 151, 173, 170, 141, 101, 90, 65, 29, 25, 0, 3, 19, 85, 133, 164, 175, 164, 139, 111, 92, 55, 26, 15, 6, 10, 37, 80, 111, 148, 176, 172, 142, 126, 84, 41, 11, 0, 7, 64, 108, 146, 172, 175, 172, 117, 79, 46, 12, 1, 9, 29, 83, 146, 178, 170, 80, 48, 5, 10, 85, 128, 152, 175, 178, 167, 72, 42, 16, 8, 2, 18, 78, 151, 174, 150, 113, 66, 37, 10, 6, 1, 6, 46, 88, 138, 171, 157, 144, 120, 106, 58, 45, 36, 27, 16, 11, 7, 4, 9, 81, 138, 177, 172, 136, 113, 64, 57, 30, 25, 0, 5, 8, 13, 16, 63, 72, 76, 113, 123, 126, 131, 127, 123, 115, 112, 109, 105, 102, 98, 102, 111, 119, 122, 127, 131, 142, 146, 153, 160, 155, 138, 129, 108, 104, 91, 81, 78, 72, 63, 54, 46, 40, 37, 33, 37, 44, 49, 55, 59, 65, 68, 83, 88, 92, 98, 95, 77, 60, 51, 44, 29, 26, 23, 20, 27, 38, 44, 50, 55, 52, 47, 40, 36, 31, 26, 22, 21};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 192 keyframes
const int layer3_count = 192;
const unsigned long layer3_times[] PROGMEM = {0, 595, 655, 742, 866, 1055, 1186, 1242, 2683, 2737, 2819, 2870, 2959, 3012, 3072, 3171, 3547, 3604, 3708, 3803, 4076, 4212, 4332, 4604, 4727, 4996, 5093, 5277, 5420, 5581, 6558, 6621, 6671, 6725, 6820, 7044, 7095, 7151, 8111, 8310, 8609, 8660, 9719, 9769, 10278, 10347, 11561, 11682, 11752, 11804, 11859, 11911, 11973, 12024, 12080, 12207, 12298, 12354, 12410, 12491, 12544, 12638, 12688, 12756, 12859, 13021, 13302, 13457, 13533, 13585, 13644, 13699, 13860, 13921, 14139, 14197, 14247, 14303, 14467, 14530, 14831, 14911, 15225, 15444, 15497, 15970, 16049, 16159, 16405, 16455, 16555, 16609, 16939, 17003, 17163, 17356, 17411, 17500, 18571, 18627, 18682, 18738, 18795, 18850, 18903, 18957, 19119, 19174, 19243, 19299, 19350, 19401, 19489, 19553, 20390, 20463, 20540, 20591, 20641, 20741, 21020, 21076, 21127, 22161, 22218, 22281, 22503, 22594, 22784, 22838, 22896, 23934, 23986, 24096, 24437, 24491, 25991, 26343, 26423, 26624, 26684, 26753, 26814, 27067, 27167, 27361, 27414, 27470, 27525, 27586, 27712, 27810, 27864, 27921, 28816, 28918, 29009, 29105, 29193, 29257, 29357, 29458, 29595, 29665, 29865, 29918, 30310, 30368, 30427, 30521, 30720, 30820, 30890, 30943, 31009, 31856, 31932, 32010, 32236, 32292, 32788, 32850, 33012, 33083, 33555, 33676, 33787, 33949, 34146, 34197, 34283, 34290};
const int layer3_servo2[] PROGMEM = {  // S2 (D10) (OWNED)
  32, 36, 39, 42, 46, 49, 52, 58, 55, 51, 48, 44, 41, 38, 35, 31, 35, 39, 42, 45, 42, 39, 36, 39, 42, 46, 49, 52, 55, 58, 54, 51, 47, 43, 40, 44, 52, 59, 56, 52, 56, 60, 56, 52, 56, 60, 56, 52, 44, 40, 34, 23, 19, 14, 9, 13, 16, 24, 28, 31, 41, 44, 48, 52, 56, 59, 56, 53, 49, 46, 42, 35, 32, 29, 32, 36, 41, 48, 51, 55, 51, 48, 44, 48, 57, 54, 49, 46, 43, 49, 52, 55, 52, 48, 45, 49, 53, 57, 54, 44, 38, 29, 24, 16, 6, 1, 5, 29, 35, 44, 48, 53, 56, 59, 56, 53, 49, 44, 40, 37, 44, 56, 60, 56, 50, 45, 42, 39, 43, 55, 60, 56, 52, 49, 53, 60, 56, 52, 49, 46, 43, 39, 31, 28, 25, 28, 34, 38, 43, 46, 49, 53, 56, 60, 56, 53, 49, 46, 43, 39, 36, 33, 30, 27, 24, 21, 24, 27, 31, 35, 38, 42, 49, 55, 60, 55, 52, 49, 46, 43, 46, 49, 52, 55, 51, 48, 45, 42, 46, 49, 53, 53};
int layer3_index = 0;

void setup() {
  Serial.begin(115200);

  // Attach servos
  for(int i = 0; i < 10; i++) {
    servo[i].attach(servoPins[i]);
        writeServo(i, startupPositions[i]);
  }

  // Spread the wobble phases so channels never breathe in lockstep
  randomSeed(analogRead(A0));
  for (int i = 0; i < 10; i++) {
    phaseOffset[i] = random(0, 628) / 100.0;   // 0..2pi
  }

  delay(1000);
  Serial.println("10-Servo Hand Control Ready - Simultaneous Playback");
  loopStartTime = millis();
  lastTickMs = millis();
}

void loop() {
  // Timing jitter: drift the playback clock slowly around 1.0x instead of
  // stepping it, so the tempo breathes rather than stutters. With
  // TIMING_JITTER = 0 this is exactly millis() - loopStartTime.
  unsigned long nowMs = millis();
  unsigned long deltaMs = nowMs - lastTickMs;
  lastTickMs = nowMs;

  if (TIMING_JITTER > 0.0) {
    if (nowMs - lastJitterUpdate > 1500) {
      jitterTarget = 1.0 + (random(-1000, 1000) / 1000.0) * TIMING_JITTER;
      lastJitterUpdate = nowMs;
    }
    jitterMul += (jitterTarget - jitterMul) * 0.02;   // ease, never jump
  } else {
    jitterMul = 1.0;
  }

  organicClock += (unsigned long)(deltaMs * jitterMul);
  unsigned long elapsed = organicClock;

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
    organicClock = 0;   // the jitter-warped clock is the one being compared
    elapsed = 0;
    layer1_index = 0;
    layer2_index = 0;
    layer3_index = 0;
  }

  // Update layer 1 with interpolation (OWNS: S0 (D12), S1 (D11), S3 (D9), S4 (D8))
  {
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer1_index < layer1_count - 1 &&
          elapsed >= pgm_read_dword(&layer1_times[layer1_index + 1])) {
      layer1_index++;
    }

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer1_index >= layer1_count - 1);
    float factor = 0.0;
    if(!atEnd) {
      unsigned long currentTime = pgm_read_dword(&layer1_times[layer1_index]);
      unsigned long nextTime = pgm_read_dword(&layer1_times[layer1_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }
    }
    {
      // Interpolate S0 (D12)
      int curr0 = pgm_read_word(&layer1_servo0[layer1_index]);
      // reading [index + 1] past the end would run off the array
      int next0 = atEnd ? curr0
                  : (int)pgm_read_word(&layer1_servo0[layer1_index + 1]);
      int start0 = pgm_read_word(&layer1_servo0[0]);
      
      if(curr0 != -1) {
        int pos = (next0 != -1)
                ? curr0 + (int)((next0 - curr0) * factor)
                : curr0;
        
        // Apply blend zone for smooth looping -- runs even once this
        // layer is out of keyframes, so it eases home instead of snapping
        if(isBlending && start0 != -1) {
          pos = pos * (1.0 - blendFactor) + start0 * blendFactor;
        }
        
        writeServo(0, pos);
      }
      // Interpolate S1 (D11)
      int curr1 = pgm_read_word(&layer1_servo1[layer1_index]);
      // reading [index + 1] past the end would run off the array
      int next1 = atEnd ? curr1
                  : (int)pgm_read_word(&layer1_servo1[layer1_index + 1]);
      int start1 = pgm_read_word(&layer1_servo1[0]);
      
      if(curr1 != -1) {
        int pos = (next1 != -1)
                ? curr1 + (int)((next1 - curr1) * factor)
                : curr1;
        
        // Apply blend zone for smooth looping -- runs even once this
        // layer is out of keyframes, so it eases home instead of snapping
        if(isBlending && start1 != -1) {
          pos = pos * (1.0 - blendFactor) + start1 * blendFactor;
        }
        
        writeServo(1, pos);
      }
      // Interpolate S3 (D9)
      int curr3 = pgm_read_word(&layer1_servo3[layer1_index]);
      // reading [index + 1] past the end would run off the array
      int next3 = atEnd ? curr3
                  : (int)pgm_read_word(&layer1_servo3[layer1_index + 1]);
      int start3 = pgm_read_word(&layer1_servo3[0]);
      
      if(curr3 != -1) {
        int pos = (next3 != -1)
                ? curr3 + (int)((next3 - curr3) * factor)
                : curr3;
        
        // Apply blend zone for smooth looping -- runs even once this
        // layer is out of keyframes, so it eases home instead of snapping
        if(isBlending && start3 != -1) {
          pos = pos * (1.0 - blendFactor) + start3 * blendFactor;
        }
        
        writeServo(3, pos);
      }
      // Interpolate S4 (D8)
      int curr4 = pgm_read_word(&layer1_servo4[layer1_index]);
      // reading [index + 1] past the end would run off the array
      int next4 = atEnd ? curr4
                  : (int)pgm_read_word(&layer1_servo4[layer1_index + 1]);
      int start4 = pgm_read_word(&layer1_servo4[0]);
      
      if(curr4 != -1) {
        int pos = (next4 != -1)
                ? curr4 + (int)((next4 - curr4) * factor)
                : curr4;
        
        // Apply blend zone for smooth looping -- runs even once this
        // layer is out of keyframes, so it eases home instead of snapping
        if(isBlending && start4 != -1) {
          pos = pos * (1.0 - blendFactor) + start4 * blendFactor;
        }
        
        writeServo(4, pos);
      }
    }
  }

  // Update layer 2 with interpolation (OWNS: S5 (D7))
  {
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer2_index < layer2_count - 1 &&
          elapsed >= pgm_read_dword(&layer2_times[layer2_index + 1])) {
      layer2_index++;
    }

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer2_index >= layer2_count - 1);
    float factor = 0.0;
    if(!atEnd) {
      unsigned long currentTime = pgm_read_dword(&layer2_times[layer2_index]);
      unsigned long nextTime = pgm_read_dword(&layer2_times[layer2_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }
    }
    {
      // Interpolate S5 (D7)
      int curr5 = pgm_read_word(&layer2_servo5[layer2_index]);
      // reading [index + 1] past the end would run off the array
      int next5 = atEnd ? curr5
                  : (int)pgm_read_word(&layer2_servo5[layer2_index + 1]);
      int start5 = pgm_read_word(&layer2_servo5[0]);
      
      if(curr5 != -1) {
        int pos = (next5 != -1)
                ? curr5 + (int)((next5 - curr5) * factor)
                : curr5;
        
        // Apply blend zone for smooth looping -- runs even once this
        // layer is out of keyframes, so it eases home instead of snapping
        if(isBlending && start5 != -1) {
          pos = pos * (1.0 - blendFactor) + start5 * blendFactor;
        }
        
        writeServo(5, pos);
      }
    }
  }

  // Update layer 3 with interpolation (OWNS: S2 (D10))
  {
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer3_index < layer3_count - 1 &&
          elapsed >= pgm_read_dword(&layer3_times[layer3_index + 1])) {
      layer3_index++;
    }

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer3_index >= layer3_count - 1);
    float factor = 0.0;
    if(!atEnd) {
      unsigned long currentTime = pgm_read_dword(&layer3_times[layer3_index]);
      unsigned long nextTime = pgm_read_dword(&layer3_times[layer3_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }
    }
    {
      // Interpolate S2 (D10)
      int curr2 = pgm_read_word(&layer3_servo2[layer3_index]);
      // reading [index + 1] past the end would run off the array
      int next2 = atEnd ? curr2
                  : (int)pgm_read_word(&layer3_servo2[layer3_index + 1]);
      int start2 = pgm_read_word(&layer3_servo2[0]);
      
      if(curr2 != -1) {
        int pos = (next2 != -1)
                ? curr2 + (int)((next2 - curr2) * factor)
                : curr2;
        
        // Apply blend zone for smooth looping -- runs even once this
        // layer is out of keyframes, so it eases home instead of snapping
        if(isBlending && start2 != -1) {
          pos = pos * (1.0 - blendFactor) + start2 * blendFactor;
        }
        
        writeServo(2, pos);
      }
    }
  }

  delay(5); // 200Hz update rate for smooth interpolation
}
