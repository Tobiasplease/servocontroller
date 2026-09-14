/*
 * 10-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-08-22 23:56:52
 * Hardware Config: Default
 * Layers: 7
 * Original Frames Recorded: 7044
 * Loop Duration: 15.89s (recorded) / 15.89s (at 1.0x speed)
 * Playback Speed: 1.0x
 * 
 * Layer Priority (later layers override earlier for same servo):
 * Servo 0 (S0 (D12)): Layer 7
 * Servo 1 (S1 (D11)): Layer 1
 * Servo 2 (S2 (D10)): Layer 1
 * Servo 3 (S3 (D9)): Layer 1
 * Servo 4 (S4 (D8)): Layer 1
 * Servo 5 (S5 (D7)): Layer 2
 * Servo 6 (S6 (D6)): Layer 3
 * Servo 7 (S7 (D5)): Layer 4
 * Servo 8 (S8 (D4)): Layer 5
 * Servo 9 (S9 (D2)): Layer 6
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
const int MAX_ANGLE = 180;
// Per-channel performed range: the per-servo limit intersected with the
// expressive range. No host here to apply it, so it is compiled in.
// (Kept ASCII on purpose -- generated sketches are written with the platform
// default codec, and a stray non-ASCII character kills the export on Windows.)
const int servoMin[10] = {0, 0, 0, 0, 0, 0, 0, 50, 0, 0};
const int servoMax[10] = {180, 180, 180, 180, 180, 180, 180, 180, 180, 180};

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
  pos = constrain(pos, servoMin[index], servoMax[index]);
  // Mirror within THIS channel's range -- a shared MAX_ANGLE - pos only lands
  // correctly when every channel starts at 0.
  if(0) pos = servoMin[index] + servoMax[index] - pos;  // Reverse none
  servo[index].write(constrain(pos, MIN_ANGLE, MAX_ANGLE));
}

// Timing
unsigned long loopStartTime;
unsigned long loopDuration = 15890; // milliseconds (adjusted for 1.0x speed)

// Startup pose (matches first recorded frame per owned servo)
const int startupPositions[10] = {112, 7, 7, 7, 7, 101, 139, 87, 82, 31};

// Layer data structures

// Layer 1: Layer_1 (cursor mode) - 109 keyframes
const int layer1_count = 109;
const unsigned long layer1_times[] PROGMEM = {0, 477, 592, 696, 800, 905, 1014, 1122, 1232, 1346, 1547, 1658, 1764, 1868, 1972, 2074, 2181, 2284, 2388, 2494, 2597, 2797, 3138, 3249, 3358, 3466, 3575, 3683, 3786, 3888, 4003, 4107, 4213, 4318, 4421, 4639, 5176, 5284, 5387, 5490, 5594, 5698, 5801, 5908, 6009, 6118, 6220, 6321, 6600, 6767, 6967, 7513, 7618, 7722, 7826, 7945, 8051, 8156, 8260, 8364, 8469, 8589, 8694, 8802, 9031, 9145, 9248, 9352, 9457, 9561, 9665, 9770, 9874, 9977, 10079, 10180, 10372, 11408, 11512, 11614, 11732, 11834, 11938, 12043, 12147, 12250, 12359, 12460, 12562, 12672, 12782, 12918, 13022, 13134, 13746, 13850, 13954, 14054, 14158, 14260, 14361, 14468, 14573, 14677, 14782, 14885, 14997, 15146, 15890};
const int layer1_servo1[] PROGMEM = {  // S1 (D11) (OWNED)
  7, 13, 24, 37, 68, 89, 99, 118, 130, 140, 146, 140, 123, 104, 96, 85, 70, 61, 44, 29, 17, 12, 17, 31, 46, 66, 86, 98, 108, 124, 131, 140, 152, 158, 164, 170, 164, 154, 145, 136, 120, 108, 95, 81, 61, 42, 32, 27, 21, 15, 9, 16, 23, 30, 38, 53, 66, 78, 91, 100, 112, 122, 137, 143, 137, 120, 111, 104, 97, 87, 75, 62, 51, 30, 18, 10, 4, 10, 16, 21, 30, 37, 47, 57, 71, 85, 97, 110, 121, 133, 140, 146, 151, 157, 149, 143, 137, 131, 121, 113, 103, 91, 68, 51, 30, 20, 10, 4, 0};
const int layer1_servo2[] PROGMEM = {  // S2 (D10) (OWNED)
  7, 13, 24, 37, 68, 89, 99, 118, 130, 140, 146, 140, 123, 104, 96, 85, 70, 61, 44, 29, 17, 12, 17, 31, 46, 66, 86, 98, 108, 124, 131, 140, 152, 158, 164, 170, 164, 154, 145, 136, 120, 108, 95, 81, 61, 42, 32, 27, 21, 15, 9, 16, 23, 30, 38, 53, 66, 78, 91, 100, 112, 122, 137, 143, 137, 120, 111, 104, 97, 87, 75, 62, 51, 30, 18, 10, 4, 10, 16, 21, 30, 37, 47, 57, 71, 85, 97, 110, 121, 133, 140, 146, 151, 157, 149, 143, 137, 131, 121, 113, 103, 91, 68, 51, 30, 20, 10, 4, 0};
const int layer1_servo3[] PROGMEM = {  // S3 (D9) (OWNED)
  7, 13, 24, 37, 68, 89, 99, 118, 130, 140, 146, 140, 123, 104, 96, 85, 70, 61, 44, 29, 17, 12, 17, 31, 46, 66, 86, 98, 108, 124, 131, 140, 152, 158, 164, 170, 164, 154, 145, 136, 120, 108, 95, 81, 61, 42, 32, 27, 21, 15, 9, 16, 23, 30, 38, 53, 66, 78, 91, 100, 112, 122, 137, 143, 137, 120, 111, 104, 97, 87, 75, 62, 51, 30, 18, 10, 4, 10, 16, 21, 30, 37, 47, 57, 71, 85, 97, 110, 121, 133, 140, 146, 151, 157, 149, 143, 137, 131, 121, 113, 103, 91, 68, 51, 30, 20, 10, 4, 0};
const int layer1_servo4[] PROGMEM = {  // S4 (D8) (OWNED)
  7, 13, 24, 37, 68, 89, 99, 118, 130, 140, 146, 140, 123, 104, 96, 85, 70, 61, 44, 29, 17, 12, 17, 31, 46, 66, 86, 98, 108, 124, 131, 140, 152, 158, 164, 170, 164, 154, 145, 136, 120, 108, 95, 81, 61, 42, 32, 27, 21, 15, 9, 16, 23, 30, 38, 53, 66, 78, 91, 100, 112, 122, 137, 143, 137, 120, 111, 104, 97, 87, 75, 62, 51, 30, 18, 10, 4, 10, 16, 21, 30, 37, 47, 57, 71, 85, 97, 110, 121, 133, 140, 146, 151, 157, 149, 143, 137, 131, 121, 113, 103, 91, 68, 51, 30, 20, 10, 4, 0};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 89 keyframes
const int layer2_count = 89;
const unsigned long layer2_times[] PROGMEM = {0, 630, 914, 1088, 1151, 1306, 1401, 1538, 1651, 1794, 1921, 2197, 2442, 2514, 2578, 2891, 3497, 3572, 3732, 3937, 4066, 4140, 4301, 4630, 4894, 5383, 5784, 6489, 6641, 6820, 7007, 7194, 7257, 7420, 7568, 7662, 7764, 7916, 8101, 8165, 8292, 8864, 8997, 9086, 9190, 9304, 9430, 9590, 9686, 10151, 10258, 10352, 10520, 10896, 11200, 11296, 11458, 11643, 11746, 11894, 12003, 12141, 12809, 12958, 13036, 13151, 13213, 13339, 13413, 13528, 13616, 13694, 13800, 13910, 13998, 14095, 14274, 14383, 14561, 14861, 15092, 15143, 15208, 15280, 15425, 15553, 15657, 15829, 15890};
const int layer2_servo5[] PROGMEM = {  // S5 (D7) (OWNED)
  101, 98, 95, 91, 87, 84, 81, 78, 75, 72, 69, 72, 75, 78, 81, 84, 81, 78, 75, 72, 69, 66, 63, 59, 56, 52, 49, 52, 56, 59, 62, 65, 68, 72, 76, 79, 82, 86, 89, 92, 96, 93, 90, 86, 83, 80, 77, 74, 70, 74, 77, 80, 84, 87, 84, 80, 77, 74, 70, 67, 64, 61, 64, 67, 70, 73, 77, 80, 83, 86, 90, 93, 96, 100, 103, 106, 109, 112, 115, 118, 115, 112, 109, 106, 102, 99, 96, 92, 90};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 82 keyframes
const int layer3_count = 82;
const unsigned long layer3_times[] PROGMEM = {0, 432, 954, 1196, 1354, 1523, 1675, 1836, 2020, 2226, 2413, 2478, 2550, 2795, 2863, 2967, 3069, 3167, 3265, 3360, 3590, 3942, 3993, 4122, 4431, 4644, 4788, 5005, 5125, 5176, 5502, 5727, 5879, 6082, 6296, 6384, 6922, 7060, 7185, 7307, 7411, 7784, 7991, 8053, 8114, 8169, 8246, 8304, 8399, 8478, 8598, 8688, 9497, 9761, 9936, 10203, 10343, 10548, 10821, 10942, 11342, 11575, 11751, 12000, 12159, 12297, 12473, 12658, 12762, 12972, 13267, 14054, 14135, 14302, 14431, 14521, 14760, 15056, 15110, 15434, 15588, 15890};
const int layer3_servo6[] PROGMEM = {  // S6 (D6) (OWNED)
  139, 136, 133, 130, 127, 123, 120, 117, 113, 110, 106, 103, 100, 97, 94, 91, 87, 84, 81, 78, 75, 79, 82, 85, 89, 93, 96, 99, 103, 106, 109, 112, 115, 119, 122, 125, 122, 119, 116, 113, 109, 112, 115, 118, 123, 126, 129, 132, 135, 139, 142, 146, 142, 139, 136, 133, 130, 127, 124, 121, 124, 127, 131, 134, 137, 140, 143, 147, 150, 153, 156, 153, 150, 147, 144, 140, 136, 139, 142, 146, 149, 151};
int layer3_index = 0;

// Layer 4: Layer_4 (manual mode) - 26 keyframes
const int layer4_count = 26;
const unsigned long layer4_times[] PROGMEM = {0, 113, 617, 833, 1115, 1394, 1643, 2195, 2785, 3070, 3324, 3606, 3918, 4823, 5133, 5571, 6790, 8493, 10216, 10816, 11658, 12779, 13244, 13917, 14866, 15890};
const int layer4_servo7[] PROGMEM = {  // S7 (D5) (OWNED)
  87, 91, 94, 97, 100, 103, 106, 109, 106, 103, 100, 97, 94, 97, 100, 103, 100, 104, 101, 98, 101, 98, 95, 98, 95, 96};
int layer4_index = 0;

// Layer 5: Layer_5 (manual mode) - 35 keyframes
const int layer5_count = 35;
const unsigned long layer5_times[] PROGMEM = {0, 1623, 1873, 2258, 2404, 3342, 4123, 4685, 4910, 5126, 5262, 5437, 5694, 5881, 6080, 6224, 6791, 7434, 7787, 8575, 8789, 9093, 9341, 9566, 9835, 10190, 10492, 10840, 11096, 11497, 13940, 14333, 14675, 15867, 15890};
const int layer5_servo8[] PROGMEM = {  // S8 (D4) (OWNED)
  82, 79, 76, 73, 69, 66, 69, 72, 75, 78, 81, 85, 88, 92, 95, 98, 95, 92, 88, 92, 95, 98, 101, 104, 108, 111, 114, 117, 121, 124, 121, 118, 115, 118, 118};
int layer5_index = 0;

// Layer 6: Layer_6 (manual mode) - 53 keyframes
const int layer6_count = 53;
const unsigned long layer6_times[] PROGMEM = {0, 1029, 1169, 1733, 1998, 2233, 2302, 2451, 2765, 2927, 3528, 3744, 4008, 4497, 4685, 5034, 5113, 5307, 5404, 5595, 6132, 6789, 7036, 7702, 8185, 8568, 9360, 9606, 9738, 9930, 10148, 10755, 10947, 11067, 12173, 12354, 12525, 12646, 12795, 13127, 13575, 13768, 13943, 14104, 14272, 14384, 15217, 15369, 15460, 15622, 15715, 15818, 15890};
const int layer6_servo9[] PROGMEM = {  // S9 (D2) (OWNED)
  31, 28, 25, 28, 31, 34, 38, 41, 38, 35, 31, 28, 25, 22, 19, 22, 25, 29, 32, 35, 32, 29, 26, 23, 20, 16, 20, 24, 27, 30, 33, 30, 27, 24, 27, 30, 33, 37, 40, 43, 39, 36, 32, 29, 26, 23, 26, 29, 32, 35, 38, 41, 43};
int layer6_index = 0;

// Layer 7: Layer_7 (manual mode) - 136 keyframes
const int layer7_count = 136;
const unsigned long layer7_times[] PROGMEM = {0, 534, 591, 670, 955, 1009, 1198, 1259, 1313, 1449, 1744, 1805, 1862, 1912, 1966, 2018, 2094, 2185, 2250, 2301, 2355, 2438, 2505, 2557, 2642, 2761, 3027, 3077, 3175, 3238, 3293, 3458, 3517, 3596, 3650, 3703, 3756, 3811, 3896, 3946, 4053, 4566, 4848, 5252, 5311, 5371, 5448, 5541, 5595, 5693, 5746, 5860, 5930, 5995, 6047, 6106, 6156, 6230, 6383, 6624, 6676, 6735, 6859, 6918, 6970, 7028, 7124, 7180, 7365, 7703, 7803, 7863, 7915, 7966, 8022, 8242, 8471, 8535, 8587, 8680, 8732, 8800, 8903, 9057, 9484, 10259, 10468, 11391, 11470, 11526, 11613, 11670, 11735, 11791, 11849, 11900, 11953, 12015, 12166, 12227, 12278, 12332, 12386, 12503, 12556, 12677, 12728, 12781, 12837, 12888, 12939, 13021, 13115, 13366, 13418, 13476, 13561, 13842, 14147, 14197, 14248, 14300, 14357, 14421, 14501, 14644, 14781, 14880, 14967, 15063, 15165, 15323, 15407, 15533, 15767, 15890};
const int layer7_servo0[] PROGMEM = {  // S0 (D12) (OWNED)
  112, 108, 104, 99, 102, 114, 118, 130, 135, 138, 135, 131, 125, 119, 115, 110, 106, 112, 121, 124, 133, 136, 139, 144, 147, 150, 146, 140, 137, 134, 128, 132, 135, 138, 142, 147, 151, 158, 162, 165, 168, 171, 168, 165, 160, 152, 148, 145, 141, 138, 135, 131, 126, 123, 120, 116, 110, 106, 102, 106, 111, 122, 126, 130, 136, 140, 143, 146, 149, 146, 143, 139, 135, 132, 127, 124, 127, 132, 144, 147, 151, 154, 157, 160, 157, 161, 164, 161, 158, 155, 151, 146, 143, 132, 126, 122, 119, 112, 116, 123, 130, 140, 145, 148, 151, 147, 142, 138, 130, 127, 119, 115, 112, 115, 122, 126, 136, 139, 136, 132, 127, 122, 118, 112, 109, 105, 102, 98, 95, 92, 88, 85, 82, 79, 76, 75};
int layer7_index = 0;

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
    layer4_index = 0;
    layer5_index = 0;
    layer6_index = 0;
    layer7_index = 0;
  }

  // Update layer 1 with interpolation (OWNS: S1 (D11), S2 (D10), S3 (D9), S4 (D8))
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
      // Interpolate S2 (D10)
      int curr2 = pgm_read_word(&layer1_servo2[layer1_index]);
      // reading [index + 1] past the end would run off the array
      int next2 = atEnd ? curr2
                  : (int)pgm_read_word(&layer1_servo2[layer1_index + 1]);
      int start2 = pgm_read_word(&layer1_servo2[0]);
      
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

  // Update layer 3 with interpolation (OWNS: S6 (D6))
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
      // Interpolate S6 (D6)
      int curr6 = pgm_read_word(&layer3_servo6[layer3_index]);
      // reading [index + 1] past the end would run off the array
      int next6 = atEnd ? curr6
                  : (int)pgm_read_word(&layer3_servo6[layer3_index + 1]);
      int start6 = pgm_read_word(&layer3_servo6[0]);
      
      if(curr6 != -1) {
        int pos = (next6 != -1)
                ? curr6 + (int)((next6 - curr6) * factor)
                : curr6;
        
        // Apply blend zone for smooth looping -- runs even once this
        // layer is out of keyframes, so it eases home instead of snapping
        if(isBlending && start6 != -1) {
          pos = pos * (1.0 - blendFactor) + start6 * blendFactor;
        }
        
        writeServo(6, pos);
      }
    }
  }

  // Update layer 4 with interpolation (OWNS: S7 (D5))
  {
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer4_index < layer4_count - 1 &&
          elapsed >= pgm_read_dword(&layer4_times[layer4_index + 1])) {
      layer4_index++;
    }

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer4_index >= layer4_count - 1);
    float factor = 0.0;
    if(!atEnd) {
      unsigned long currentTime = pgm_read_dword(&layer4_times[layer4_index]);
      unsigned long nextTime = pgm_read_dword(&layer4_times[layer4_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }
    }
    {
      // Interpolate S7 (D5)
      int curr7 = pgm_read_word(&layer4_servo7[layer4_index]);
      // reading [index + 1] past the end would run off the array
      int next7 = atEnd ? curr7
                  : (int)pgm_read_word(&layer4_servo7[layer4_index + 1]);
      int start7 = pgm_read_word(&layer4_servo7[0]);
      
      if(curr7 != -1) {
        int pos = (next7 != -1)
                ? curr7 + (int)((next7 - curr7) * factor)
                : curr7;
        
        // Apply blend zone for smooth looping -- runs even once this
        // layer is out of keyframes, so it eases home instead of snapping
        if(isBlending && start7 != -1) {
          pos = pos * (1.0 - blendFactor) + start7 * blendFactor;
        }
        
        writeServo(7, pos);
      }
    }
  }

  // Update layer 5 with interpolation (OWNS: S8 (D4))
  {
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer5_index < layer5_count - 1 &&
          elapsed >= pgm_read_dword(&layer5_times[layer5_index + 1])) {
      layer5_index++;
    }

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer5_index >= layer5_count - 1);
    float factor = 0.0;
    if(!atEnd) {
      unsigned long currentTime = pgm_read_dword(&layer5_times[layer5_index]);
      unsigned long nextTime = pgm_read_dword(&layer5_times[layer5_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }
    }
    {
      // Interpolate S8 (D4)
      int curr8 = pgm_read_word(&layer5_servo8[layer5_index]);
      // reading [index + 1] past the end would run off the array
      int next8 = atEnd ? curr8
                  : (int)pgm_read_word(&layer5_servo8[layer5_index + 1]);
      int start8 = pgm_read_word(&layer5_servo8[0]);
      
      if(curr8 != -1) {
        int pos = (next8 != -1)
                ? curr8 + (int)((next8 - curr8) * factor)
                : curr8;
        
        // Apply blend zone for smooth looping -- runs even once this
        // layer is out of keyframes, so it eases home instead of snapping
        if(isBlending && start8 != -1) {
          pos = pos * (1.0 - blendFactor) + start8 * blendFactor;
        }
        
        writeServo(8, pos);
      }
    }
  }

  // Update layer 6 with interpolation (OWNS: S9 (D2))
  {
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer6_index < layer6_count - 1 &&
          elapsed >= pgm_read_dword(&layer6_times[layer6_index + 1])) {
      layer6_index++;
    }

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer6_index >= layer6_count - 1);
    float factor = 0.0;
    if(!atEnd) {
      unsigned long currentTime = pgm_read_dword(&layer6_times[layer6_index]);
      unsigned long nextTime = pgm_read_dword(&layer6_times[layer6_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }
    }
    {
      // Interpolate S9 (D2)
      int curr9 = pgm_read_word(&layer6_servo9[layer6_index]);
      // reading [index + 1] past the end would run off the array
      int next9 = atEnd ? curr9
                  : (int)pgm_read_word(&layer6_servo9[layer6_index + 1]);
      int start9 = pgm_read_word(&layer6_servo9[0]);
      
      if(curr9 != -1) {
        int pos = (next9 != -1)
                ? curr9 + (int)((next9 - curr9) * factor)
                : curr9;
        
        // Apply blend zone for smooth looping -- runs even once this
        // layer is out of keyframes, so it eases home instead of snapping
        if(isBlending && start9 != -1) {
          pos = pos * (1.0 - blendFactor) + start9 * blendFactor;
        }
        
        writeServo(9, pos);
      }
    }
  }

  // Update layer 7 with interpolation (OWNS: S0 (D12))
  {
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer7_index < layer7_count - 1 &&
          elapsed >= pgm_read_dword(&layer7_times[layer7_index + 1])) {
      layer7_index++;
    }

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer7_index >= layer7_count - 1);
    float factor = 0.0;
    if(!atEnd) {
      unsigned long currentTime = pgm_read_dword(&layer7_times[layer7_index]);
      unsigned long nextTime = pgm_read_dword(&layer7_times[layer7_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }
    }
    {
      // Interpolate S0 (D12)
      int curr0 = pgm_read_word(&layer7_servo0[layer7_index]);
      // reading [index + 1] past the end would run off the array
      int next0 = atEnd ? curr0
                  : (int)pgm_read_word(&layer7_servo0[layer7_index + 1]);
      int start0 = pgm_read_word(&layer7_servo0[0]);
      
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
    }
  }

  delay(5); // 200Hz update rate for smooth interpolation
}
