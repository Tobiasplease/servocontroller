/*
 * 10-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-08-20 23:31:01
 * Hardware Config: Default
 * Layers: 5
 * Original Frames Recorded: 11903
 * Loop Duration: 33.19s (recorded) / 33.19s (at 1.0x speed)
 * Playback Speed: 1.0x
 * 
 * Layer Priority (later layers override earlier for same servo):
 * Servo 0 (S0 (D12)): Layer 1
 * Servo 1 (S1 (D11)): Layer 3
 * Servo 2 (S2 (D10)): Layer 1
 * Servo 3 (S3 (D9)): Layer 4
 * Servo 4 (S4 (D8)): Layer 5
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
const float WOBBLE_AMOUNT = 1.50;   // degrees of drift per channel
const float TIMING_JITTER = 0.080;   // fraction, e.g. 0.08 = +/-8% tempo
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
unsigned long loopDuration = 33190; // milliseconds (adjusted for 1.0x speed)

// Startup pose (matches first recorded frame per owned servo)
const int startupPositions[10] = {25, 33, 40, 15, 33, 11, 90, 90, 90, 90};

// Layer data structures

// Layer 1: Layer_1 (cursor mode) - 43 keyframes
const int layer1_count = 43;
const unsigned long layer1_times[] PROGMEM = {0, 1166, 1796, 2613, 3456, 4105, 5489, 6459, 7071, 9251, 9742, 11698, 12828, 13288, 14073, 15265, 17337, 19453, 19935, 20327, 21017, 21600, 22042, 22524, 23061, 23638, 24120, 24464, 25067, 25583, 25956, 26413, 26929, 27388, 28135, 28850, 29532, 29811, 30101, 30349, 30657, 32147, 33190};
const int layer1_servo0[] PROGMEM = {  // S0 (D12) (OWNED)
  25, 24, 28, 30, 25, 21, 26, 20, 18, 25, 32, 33, 27, 25, 26, 21, 17, 13, 12, 12, 9, 8, 11, 18, 12, 7, 8, 15, 15, 12, 19, 23, 24, 23, 25, 28, 24, 20, 11, 6, 6, 2, 3};
const int layer1_servo2[] PROGMEM = {  // S2 (D10) (OWNED)
  40, 47, 46, 42, 46, 36, 39, 34, 24, 24, 31, 37, 38, 28, 18, 8, 4, 9, 16, 25, 34, 24, 15, 12, 12, 18, 24, 24, 14, 18, 24, 35, 46, 54, 51, 46, 52, 46, 34, 24, 20, 27, 29};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 203 keyframes
const int layer2_count = 203;
const unsigned long layer2_times[] PROGMEM = {0, 381, 907, 1022, 1130, 1251, 1368, 1477, 1622, 1742, 1856, 2173, 2283, 2384, 2494, 2611, 3336, 3546, 3661, 3765, 3882, 3985, 4091, 4198, 4312, 4466, 5161, 5274, 5385, 5497, 5605, 5717, 6378, 7028, 7142, 7260, 7361, 7472, 7577, 8007, 8114, 8220, 8324, 8436, 8541, 8648, 8756, 8865, 8979, 9134, 9677, 9838, 9950, 10059, 10168, 10281, 10391, 10497, 10770, 10894, 10998, 11110, 11217, 11416, 11524, 11877, 11996, 12114, 12222, 12330, 12439, 12553, 12778, 12894, 13001, 13104, 13222, 13325, 13440, 13556, 13679, 14074, 14177, 14291, 14405, 14514, 14621, 14732, 15010, 15116, 15222, 15331, 15435, 15556, 15660, 16156, 16270, 16387, 16493, 16610, 16719, 17017, 17126, 17229, 17343, 17452, 17571, 17972, 18074, 18197, 18305, 18464, 18765, 18889, 18991, 19097, 19208, 19319, 19603, 19713, 19827, 19930, 20068, 20297, 20458, 20571, 20677, 20797, 20906, 21010, 21402, 21508, 21633, 21736, 21899, 22320, 22439, 22566, 22668, 22825, 23093, 23263, 23385, 23501, 23613, 23721, 23854, 24007, 24355, 24478, 24589, 24696, 24863, 25027, 25139, 25308, 25623, 26163, 26268, 26374, 26483, 26605, 26711, 26820, 27069, 27513, 27640, 27797, 27899, 28005, 28130, 28232, 28338, 28477, 28608, 29151, 29270, 29384, 29493, 29614, 29765, 29871, 30529, 30643, 30759, 30861, 30966, 31102, 31209, 31314, 31423, 31532, 31944, 32055, 32163, 32272, 32377, 32496, 32755, 32873, 32998, 33099, 33190};
const int layer2_servo5[] PROGMEM = {  // S5 (D7) (OWNED)
  11, 18, 24, 41, 72, 88, 105, 119, 132, 145, 155, 134, 104, 66, 28, 3, 3, 9, 20, 33, 49, 66, 82, 101, 116, 124, 117, 105, 84, 74, 66, 46, 39, 73, 96, 112, 140, 151, 165, 167, 153, 122, 97, 73, 56, 49, 36, 27, 20, 5, 12, 19, 28, 73, 112, 139, 157, 167, 151, 119, 96, 70, 48, 26, 15, 26, 36, 67, 88, 109, 122, 133, 132, 116, 99, 75, 60, 36, 19, 8, 0, 14, 43, 72, 84, 102, 120, 130, 105, 92, 81, 57, 37, 25, 4, 4, 37, 69, 99, 117, 129, 130, 101, 70, 41, 16, 0, 27, 54, 90, 121, 144, 131, 101, 80, 47, 23, 7, 7, 51, 81, 102, 119, 120, 113, 103, 79, 47, 38, 26, 26, 53, 70, 90, 97, 82, 76, 66, 57, 44, 38, 45, 64, 78, 91, 105, 112, 120, 109, 72, 58, 42, 35, 28, 22, 15, 9, 16, 26, 47, 60, 78, 90, 98, 104, 105, 97, 91, 80, 57, 45, 27, 14, 8, 1, 10, 21, 44, 67, 87, 98, 111, 112, 97, 82, 72, 58, 46, 34, 18, 11, 0, 11, 28, 79, 110, 129, 148, 110, 79, 40, 32, 21};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 64 keyframes
const int layer3_count = 64;
const unsigned long layer3_times[] PROGMEM = {0, 842, 1143, 1514, 2721, 2835, 3251, 3528, 3921, 4836, 5247, 5371, 5563, 6044, 6515, 6651, 6948, 7164, 7428, 7836, 9511, 11801, 12121, 12273, 12547, 12672, 13450, 13768, 14141, 14635, 15388, 16589, 16855, 17017, 17193, 17484, 17739, 17894, 18721, 20105, 20456, 20929, 21193, 21345, 21898, 22073, 22802, 23065, 23461, 24070, 24524, 24903, 25741, 26159, 27292, 29865, 30738, 31339, 31614, 32023, 32218, 32523, 32668, 33190};
const int layer3_servo1[] PROGMEM = {  // S1 (D11) (OWNED)
  33, 39, 46, 52, 46, 38, 38, 45, 51, 39, 33, 40, 48, 55, 42, 34, 31, 38, 44, 51, 44, 38, 32, 26, 19, 12, 19, 25, 31, 38, 44, 44, 38, 26, 37, 27, 27, 37, 43, 42, 36, 36, 42, 48, 42, 36, 34, 40, 47, 41, 34, 28, 34, 41, 47, 47, 41, 34, 27, 21, 15, 8, 2, 0};
int layer3_index = 0;

// Layer 4: Layer_4 (manual mode) - 82 keyframes
const int layer4_count = 82;
const unsigned long layer4_times[] PROGMEM = {0, 1087, 1202, 1486, 1602, 1744, 2057, 2427, 2742, 2874, 3009, 3187, 3331, 3443, 3580, 4675, 4893, 5094, 5340, 5526, 5934, 6086, 6349, 6681, 7182, 7431, 7558, 7942, 8649, 9783, 10544, 10776, 11056, 11200, 11424, 11720, 13121, 13369, 13521, 13682, 14026, 14230, 14530, 15356, 17620, 18107, 18516, 18772, 19117, 19308, 20013, 20485, 20725, 21006, 21247, 21581, 21726, 21863, 22036, 22167, 22590, 22903, 23391, 23769, 24376, 24736, 25051, 25390, 25689, 25896, 26168, 26489, 27639, 28072, 28532, 29723, 30988, 31419, 32076, 32800, 33133, 33190};
const int layer4_servo3[] PROGMEM = {  // S3 (D9) (OWNED)
  15, 23, 29, 36, 43, 50, 57, 50, 44, 37, 30, 24, 18, 11, 4, 3, 10, 16, 23, 29, 23, 16, 10, 4, 10, 16, 23, 30, 36, 42, 36, 29, 23, 16, 10, 3, 3, 10, 20, 26, 20, 13, 7, 1, 7, 14, 20, 26, 20, 13, 19, 26, 32, 38, 44, 36, 29, 23, 16, 9, 15, 22, 22, 15, 15, 22, 29, 35, 28, 21, 14, 8, 14, 14, 8, 1, 7, 14, 21, 14, 7, 7};
int layer4_index = 0;

// Layer 5: Layer_5 (manual mode) - 66 keyframes
const int layer5_count = 66;
const unsigned long layer5_times[] PROGMEM = {0, 1408, 1721, 2075, 2233, 2443, 2970, 3098, 3280, 3467, 3754, 3922, 4565, 4851, 5191, 5414, 5606, 6076, 6277, 6462, 6733, 8206, 8647, 8983, 10290, 11038, 11469, 11754, 12217, 12602, 12948, 13789, 14286, 15062, 15357, 16588, 17471, 17775, 18335, 19778, 20421, 20786, 21106, 21588, 21717, 22055, 22243, 23349, 23774, 24221, 25182, 26295, 26984, 27653, 28707, 29378, 29824, 30387, 31092, 31468, 31726, 32052, 32533, 32885, 33142, 33190};
const int layer5_servo4[] PROGMEM = {  // S4 (D8) (OWNED)
  33, 27, 21, 27, 33, 40, 33, 26, 19, 13, 7, 0, 6, 12, 19, 25, 31, 25, 18, 11, 5, 5, 11, 19, 12, 12, 19, 26, 32, 26, 20, 20, 26, 26, 19, 26, 26, 20, 14, 13, 20, 26, 32, 32, 25, 19, 12, 12, 18, 24, 16, 23, 22, 15, 9, 15, 21, 28, 22, 15, 8, 2, 9, 15, 22, 25};
int layer5_index = 0;

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
  }

  // Update layer 1 with interpolation (OWNS: S0 (D12), S2 (D10))
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

  // Update layer 3 with interpolation (OWNS: S1 (D11))
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
      // Interpolate S1 (D11)
      int curr1 = pgm_read_word(&layer3_servo1[layer3_index]);
      // reading [index + 1] past the end would run off the array
      int next1 = atEnd ? curr1
                  : (int)pgm_read_word(&layer3_servo1[layer3_index + 1]);
      int start1 = pgm_read_word(&layer3_servo1[0]);
      
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
    }
  }

  // Update layer 4 with interpolation (OWNS: S3 (D9))
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
      // Interpolate S3 (D9)
      int curr3 = pgm_read_word(&layer4_servo3[layer4_index]);
      // reading [index + 1] past the end would run off the array
      int next3 = atEnd ? curr3
                  : (int)pgm_read_word(&layer4_servo3[layer4_index + 1]);
      int start3 = pgm_read_word(&layer4_servo3[0]);
      
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
    }
  }

  // Update layer 5 with interpolation (OWNS: S4 (D8))
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
      // Interpolate S4 (D8)
      int curr4 = pgm_read_word(&layer5_servo4[layer5_index]);
      // reading [index + 1] past the end would run off the array
      int next4 = atEnd ? curr4
                  : (int)pgm_read_word(&layer5_servo4[layer5_index + 1]);
      int start4 = pgm_read_word(&layer5_servo4[0]);
      
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

  delay(5); // 200Hz update rate for smooth interpolation
}
