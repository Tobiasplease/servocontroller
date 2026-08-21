/*
 * 10-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-08-20 23:34:37
 * Hardware Config: Default
 * Layers: 2
 * Original Frames Recorded: 6290
 * Loop Duration: 35.24s (recorded) / 35.24s (at 1.0x speed)
 * Playback Speed: 1.0x
 * 
 * Layer Priority (later layers override earlier for same servo):
 * Servo 0 (S0 (D12)): Layer 1
 * Servo 1 (S1 (D11)): Layer 1
 * Servo 2 (S2 (D10)): Layer 1
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
unsigned long loopDuration = 35240; // milliseconds (adjusted for 1.0x speed)

// Startup pose (matches first recorded frame per owned servo)
const int startupPositions[10] = {26, 44, 35, 18, 20, 94, 90, 90, 90, 90};

// Layer data structures

// Layer 1: Layer_1 (cursor mode) - 111 keyframes
const int layer1_count = 111;
const unsigned long layer1_times[] PROGMEM = {0, 854, 1070, 1276, 1377, 2339, 2446, 2555, 2672, 2893, 3080, 3189, 3392, 3665, 4018, 4354, 5566, 6256, 6469, 6602, 6748, 6898, 7076, 7255, 7358, 7639, 7769, 8007, 8160, 8420, 9484, 11230, 11647, 11804, 12051, 12287, 12391, 12554, 12733, 13123, 13318, 13569, 14354, 14901, 15180, 15380, 15653, 17620, 17992, 18588, 19351, 19899, 21951, 22172, 22276, 22542, 22652, 22757, 23051, 23343, 23464, 23653, 23839, 24014, 24396, 25413, 25882, 26264, 26501, 26685, 27185, 27331, 27673, 27784, 28005, 28230, 28341, 28523, 28681, 28955, 29195, 29318, 29506, 29620, 29759, 29926, 30163, 30400, 30643, 30979, 31214, 31443, 31679, 31932, 32068, 32252, 32569, 32671, 32778, 32886, 32998, 33111, 33233, 33350, 33471, 33809, 33922, 34198, 34478, 34665, 35240};
const int layer1_servo0[] PROGMEM = {  // S0 (D12) (OWNED)
  26, 29, 32, 33, 36, 34, 33, 31, 29, 25, 24, 24, 25, 26, 28, 27, 25, 22, 20, 18, 18, 19, 23, 26, 31, 32, 28, 25, 26, 29, 32, 35, 35, 32, 29, 26, 22, 18, 15, 16, 20, 23, 24, 23, 25, 27, 29, 31, 30, 30, 28, 27, 28, 27, 25, 23, 20, 16, 15, 18, 22, 25, 29, 32, 34, 31, 27, 24, 24, 27, 26, 22, 22, 24, 27, 30, 33, 34, 33, 30, 28, 27, 27, 26, 26, 27, 24, 20, 17, 18, 22, 27, 30, 30, 29, 26, 24, 23, 21, 18, 21, 24, 27, 31, 34, 39, 38, 35, 33, 30, 30};
const int layer1_servo1[] PROGMEM = {  // S1 (D11) (OWNED)
  44, 42, 39, 37, 35, 36, 38, 40, 42, 42, 35, 29, 24, 23, 28, 30, 32, 38, 40, 43, 44, 48, 52, 53, 53, 57, 57, 55, 53, 52, 52, 49, 44, 43, 44, 47, 48, 47, 44, 44, 46, 47, 41, 36, 31, 29, 30, 30, 24, 24, 21, 21, 25, 27, 28, 31, 35, 36, 38, 42, 47, 51, 54, 53, 49, 43, 39, 43, 47, 51, 53, 51, 48, 46, 43, 40, 39, 36, 31, 26, 24, 25, 30, 35, 41, 46, 48, 46, 42, 41, 40, 41, 37, 32, 26, 20, 18, 20, 27, 33, 39, 44, 49, 54, 57, 49, 42, 37, 34, 32, 33};
const int layer1_servo2[] PROGMEM = {  // S2 (D10) (OWNED)
  35, 38, 39, 39, 34, 37, 38, 39, 38, 38, 45, 50, 51, 49, 46, 47, 47, 42, 37, 32, 27, 22, 20, 22, 26, 21, 18, 17, 22, 27, 28, 31, 34, 37, 36, 32, 27, 21, 18, 23, 26, 29, 39, 44, 48, 47, 45, 42, 39, 34, 39, 44, 46, 48, 49, 49, 45, 41, 36, 32, 27, 25, 24, 26, 31, 37, 41, 36, 31, 27, 22, 21, 26, 32, 37, 39, 38, 38, 37, 41, 46, 48, 47, 44, 39, 34, 29, 28, 30, 35, 39, 40, 41, 44, 46, 49, 53, 54, 53, 47, 40, 35, 29, 25, 23, 29, 32, 36, 40, 43, 44};
const int layer1_servo3[] PROGMEM = {  // S3 (D9) (OWNED)
  18, 23, 28, 33, 43, 38, 32, 27, 22, 17, 16, 17, 22, 27, 27, 22, 17, 13, 11, 13, 15, 19, 22, 24, 26, 29, 27, 25, 23, 24, 28, 33, 33, 28, 22, 19, 18, 19, 20, 16, 16, 18, 16, 13, 18, 24, 29, 34, 41, 46, 41, 36, 30, 25, 20, 14, 9, 6, 8, 12, 17, 21, 25, 28, 30, 26, 20, 16, 18, 22, 23, 21, 18, 18, 20, 25, 32, 37, 41, 37, 32, 27, 22, 19, 19, 20, 18, 16, 12, 11, 13, 20, 26, 29, 30, 29, 24, 19, 12, 7, 12, 17, 21, 26, 31, 40, 42, 39, 34, 29, 27};
const int layer1_servo4[] PROGMEM = {  // S4 (D8) (OWNED)
  20, 15, 11, 9, 5, 7, 9, 12, 16, 21, 22, 22, 21, 19, 16, 18, 21, 26, 29, 31, 32, 30, 25, 19, 13, 11, 16, 21, 20, 15, 10, 6, 6, 11, 15, 20, 26, 31, 36, 34, 29, 24, 22, 25, 21, 18, 15, 12, 14, 14, 17, 18, 17, 18, 21, 24, 29, 35, 37, 32, 26, 21, 15, 10, 8, 12, 18, 23, 23, 18, 20, 26, 26, 23, 18, 13, 9, 8, 9, 14, 17, 18, 18, 19, 19, 19, 23, 28, 34, 31, 26, 18, 14, 14, 16, 20, 23, 24, 27, 31, 27, 22, 18, 13, 7, 0, 2, 6, 10, 13, 14};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 261 keyframes
const int layer2_count = 261;
const unsigned long layer2_times[] PROGMEM = {0, 929, 984, 1037, 1096, 1154, 1204, 1259, 1310, 1360, 1423, 1475, 1527, 1914, 1966, 2020, 2072, 2125, 2179, 2252, 2473, 2530, 2595, 2654, 2710, 2764, 2820, 2880, 2930, 2982, 3130, 3497, 3552, 3605, 3667, 3722, 3772, 3824, 3883, 3934, 4091, 4158, 4326, 4379, 4437, 4487, 4543, 4594, 4655, 4705, 4758, 4857, 4909, 4965, 5391, 5601, 5662, 5721, 5790, 5845, 5896, 5952, 6033, 6091, 6145, 6197, 6270, 6665, 6716, 6777, 6836, 6889, 6941, 6991, 7053, 7269, 7842, 8253, 8344, 8399, 8453, 8512, 8629, 8679, 9179, 9327, 9383, 9436, 9489, 9545, 9608, 9666, 9826, 10008, 10075, 11330, 11387, 11438, 11499, 11549, 11616, 11685, 12835, 13914, 17912, 18292, 18350, 18457, 18510, 18569, 18625, 18731, 18919, 18985, 19055, 19107, 19168, 19495, 19567, 19676, 19801, 19853, 19905, 19955, 20010, 20068, 20119, 20198, 20597, 20651, 20702, 20825, 20877, 20972, 21025, 21082, 21134, 21194, 21383, 21435, 21493, 21544, 21595, 21648, 21704, 21756, 21809, 22078, 22136, 22191, 22245, 22302, 22361, 22435, 22485, 22566, 22663, 22741, 22792, 22855, 22962, 23082, 23137, 23190, 23240, 23291, 23342, 23400, 23458, 23512, 27476, 27535, 27593, 27654, 27715, 27770, 27826, 27878, 27942, 27993, 28052, 28104, 28157, 28445, 28507, 28566, 28622, 28674, 28729, 28806, 28860, 28916, 28974, 29032, 29398, 29458, 29515, 29593, 29647, 29713, 29775, 29831, 29885, 29950, 30007, 30065, 30119, 30179, 30408, 30474, 30530, 30584, 30639, 30695, 30751, 30804, 31117, 31172, 31243, 31297, 31363, 31421, 31471, 31526, 31577, 31629, 31709, 31781, 32051, 32105, 32172, 32225, 32278, 32333, 32387, 32440, 32491, 32588, 32783, 32834, 32923, 32981, 33077, 33136, 33188, 33269, 33659, 33740, 33796, 33850, 33906, 33959, 34015, 34080, 34754, 34814, 34870, 34928, 35102, 35154, 35240};
const int layer2_servo5[] PROGMEM = {  // S5 (D7) (OWNED)
  94, 97, 104, 108, 112, 117, 121, 131, 138, 149, 152, 161, 168, 164, 156, 139, 122, 96, 36, 33, 42, 57, 60, 63, 67, 70, 101, 109, 121, 125, 128, 124, 115, 112, 98, 95, 74, 61, 39, 14, 10, 1, 4, 10, 32, 42, 79, 115, 124, 130, 142, 147, 161, 165, 162, 158, 142, 121, 115, 72, 68, 59, 56, 38, 31, 23, 8, 18, 46, 54, 103, 122, 148, 157, 167, 170, 167, 129, 120, 85, 79, 76, 73, 51, 59, 66, 92, 114, 119, 135, 139, 152, 155, 158, 161, 154, 144, 105, 101, 58, 55, 13, 155, 152, 138, 132, 109, 104, 100, 59, 47, 44, 41, 27, 24, 5, 0, 3, 9, 44, 47, 73, 81, 97, 101, 112, 119, 122, 103, 96, 60, 55, 47, 44, 33, 25, 17, 11, 18, 66, 73, 118, 122, 142, 165, 170, 175, 169, 165, 153, 138, 134, 77, 73, 54, 51, 48, 44, 10, 0, 3, 6, 23, 40, 56, 86, 98, 116, 131, 149, 146, 143, 136, 125, 120, 109, 98, 93, 90, 74, 70, 57, 53, 56, 60, 94, 113, 128, 143, 146, 149, 152, 156, 161, 155, 121, 115, 112, 81, 77, 72, 55, 46, 42, 22, 16, 13, 9, 13, 62, 83, 120, 123, 155, 164, 177, 173, 168, 164, 95, 88, 72, 62, 48, 35, 17, 12, 1, 9, 43, 50, 74, 85, 119, 145, 153, 162, 165, 152, 115, 111, 84, 79, 49, 33, 6, 19, 34, 47, 55, 73, 104, 138, 164, 160, 156, 144, 108, 104, 93, 91};
int layer2_index = 0;

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
  }

  // Update layer 1 with interpolation (OWNS: S0 (D12), S1 (D11), S2 (D10), S3 (D9), S4 (D8))
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

  delay(5); // 200Hz update rate for smooth interpolation
}
