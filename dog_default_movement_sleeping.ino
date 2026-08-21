/*
 * 10-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-08-20 23:47:31
 * Hardware Config: Default
 * Layers: 2
 * Original Frames Recorded: 7699
 * Loop Duration: 56.41s (recorded) / 56.41s (at 1.0x speed)
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
unsigned long loopDuration = 56410; // milliseconds (adjusted for 1.0x speed)

// Startup pose (matches first recorded frame per owned servo)
const int startupPositions[10] = {26, 40, 27, 31, 20, 108, 90, 90, 90, 90};

// Layer data structures

// Layer 1: Layer_1 (cursor mode) - 100 keyframes
const int layer1_count = 100;
const unsigned long layer1_times[] PROGMEM = {0, 2580, 3781, 3997, 4116, 4372, 4621, 5341, 5462, 5573, 5685, 5838, 6585, 7942, 8427, 8979, 9366, 10265, 10895, 10999, 12498, 12704, 13072, 13600, 14008, 14305, 16049, 16826, 18162, 20851, 22900, 24901, 25215, 25550, 26614, 27489, 30052, 30536, 30911, 31375, 31726, 32114, 32376, 32857, 33065, 33323, 33705, 34407, 35131, 36083, 36202, 36313, 36989, 37202, 37388, 38058, 41178, 41460, 41626, 41772, 41896, 42100, 42331, 42613, 42748, 42924, 43221, 44382, 46958, 47174, 47348, 48631, 49074, 49577, 49821, 50247, 50420, 50600, 50797, 50916, 51064, 51209, 51408, 51600, 51876, 52052, 52244, 52616, 52862, 53106, 53325, 53545, 53737, 53894, 54026, 54178, 54342, 54575, 54804, 56410};
const int layer1_servo0[] PROGMEM = {  // S0 (D12) (OWNED)
  26, 27, 26, 25, 23, 23, 24, 23, 24, 25, 25, 25, 27, 28, 28, 29, 27, 29, 27, 23, 25, 22, 21, 22, 23, 22, 22, 20, 22, 22, 22, 25, 27, 27, 23, 20, 17, 20, 16, 14, 12, 13, 17, 20, 20, 18, 15, 14, 16, 16, 20, 24, 23, 19, 17, 19, 19, 22, 23, 22, 21, 24, 22, 19, 19, 22, 24, 20, 22, 18, 19, 20, 20, 19, 19, 20, 16, 18, 21, 21, 17, 14, 16, 19, 19, 16, 17, 20, 19, 16, 14, 18, 20, 17, 15, 18, 20, 16, 16, 18};
const int layer1_servo1[] PROGMEM = {  // S1 (D11) (OWNED)
  40, 35, 32, 31, 33, 38, 43, 38, 33, 30, 30, 34, 33, 38, 43, 38, 33, 38, 41, 42, 41, 41, 39, 37, 42, 42, 41, 39, 41, 39, 35, 34, 33, 32, 27, 24, 22, 24, 26, 26, 27, 28, 28, 33, 36, 35, 30, 29, 32, 28, 27, 28, 29, 29, 31, 29, 25, 25, 28, 32, 36, 35, 30, 32, 35, 37, 32, 34, 38, 35, 34, 37, 34, 36, 33, 36, 33, 32, 34, 37, 35, 30, 32, 35, 37, 33, 32, 35, 37, 32, 30, 33, 37, 34, 31, 32, 36, 32, 32, 33};
const int layer1_servo2[] PROGMEM = {  // S2 (D10) (OWNED)
  27, 31, 29, 23, 18, 13, 11, 13, 18, 25, 31, 32, 30, 29, 24, 28, 29, 27, 26, 20, 25, 20, 16, 15, 13, 17, 22, 17, 22, 27, 32, 33, 30, 27, 29, 29, 28, 30, 25, 26, 29, 34, 38, 34, 29, 24, 24, 28, 24, 23, 24, 28, 23, 22, 22, 22, 27, 33, 36, 35, 30, 32, 37, 34, 29, 29, 34, 32, 27, 27, 32, 27, 32, 27, 33, 28, 29, 34, 34, 28, 24, 26, 31, 31, 25, 26, 32, 31, 26, 24, 29, 32, 27, 25, 30, 34, 29, 28, 33, 32};
const int layer1_servo3[] PROGMEM = {  // S3 (D9) (OWNED)
  31, 33, 38, 42, 43, 43, 40, 43, 44, 41, 36, 31, 36, 34, 34, 36, 38, 37, 32, 31, 30, 30, 35, 40, 38, 33, 29, 34, 29, 27, 25, 30, 36, 41, 38, 36, 33, 36, 33, 27, 22, 17, 17, 22, 24, 27, 28, 23, 28, 33, 38, 39, 41, 38, 31, 37, 37, 35, 29, 24, 24, 28, 25, 21, 23, 26, 28, 23, 26, 24, 22, 25, 22, 24, 21, 24, 22, 20, 24, 25, 26, 25, 20, 23, 26, 25, 21, 24, 26, 27, 22, 21, 25, 25, 20, 21, 24, 23, 20, 21};
const int layer1_servo4[] PROGMEM = {  // S4 (D8) (OWNED)
  20, 19, 19, 21, 24, 24, 23, 24, 23, 21, 21, 21, 18, 17, 16, 16, 18, 15, 19, 24, 21, 26, 27, 26, 25, 25, 25, 28, 25, 25, 26, 21, 19, 19, 24, 29, 34, 29, 35, 38, 40, 39, 34, 29, 29, 32, 36, 38, 35, 34, 29, 23, 25, 30, 34, 31, 30, 26, 24, 26, 28, 23, 26, 31, 31, 25, 23, 28, 26, 32, 30, 28, 29, 30, 30, 29, 34, 32, 27, 28, 33, 37, 35, 30, 30, 35, 33, 28, 30, 35, 37, 32, 29, 34, 36, 31, 29, 35, 34, 32};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 387 keyframes
const int layer2_count = 387;
const unsigned long layer2_times[] PROGMEM = {0, 923, 1056, 1107, 1299, 1349, 1483, 1564, 2025, 2109, 2455, 2507, 2592, 2646, 2748, 2812, 2866, 2917, 3229, 3388, 3445, 3789, 4061, 4258, 4309, 4364, 4420, 4479, 4575, 4731, 4795, 4847, 4898, 4949, 5006, 5349, 5413, 5517, 5622, 5687, 5786, 5911, 5975, 6043, 6098, 6205, 6326, 6448, 6638, 6983, 7038, 7088, 7267, 7319, 7373, 7431, 7502, 7554, 7606, 7659, 7716, 7775, 7831, 8361, 8415, 8471, 8524, 8584, 8636, 8696, 8795, 8856, 8906, 8999, 9078, 9143, 9231, 9493, 9640, 9730, 9794, 9928, 10056, 10185, 10304, 10426, 10578, 10643, 10695, 10937, 11006, 11435, 11489, 11541, 11592, 11643, 11697, 11781, 11840, 11897, 11969, 12023, 12073, 12145, 12204, 13634, 14211, 14335, 14559, 14883, 15216, 15379, 15515, 15659, 15804, 16011, 16153, 16211, 16340, 16724, 16802, 16859, 16909, 16960, 17028, 17244, 17295, 17944, 18397, 18511, 18645, 19016, 19150, 19394, 19483, 19714, 19764, 20488, 20721, 20854, 21143, 21260, 23520, 23904, 23960, 24082, 24135, 24192, 24278, 24345, 24424, 24475, 24538, 24601, 24893, 24961, 25016, 25071, 25125, 25185, 25249, 25300, 25369, 25755, 25812, 25868, 25921, 26041, 26119, 26293, 26348, 26404, 26458, 26514, 26570, 26621, 26676, 26729, 26791, 26858, 27074, 27131, 27186, 27253, 27304, 27362, 27418, 27474, 27636, 27690, 27743, 27795, 27846, 27940, 28033, 28084, 28137, 28202, 28264, 28555, 28606, 28656, 28712, 28771, 28827, 28941, 28999, 29062, 29118, 29204, 29353, 29408, 29460, 29516, 29611, 29663, 29715, 29778, 29843, 29973, 30030, 30085, 30148, 30201, 30266, 30336, 30396, 30475, 30574, 30644, 30730, 30892, 30947, 31005, 31078, 31147, 31221, 31292, 31499, 31551, 31658, 31713, 31823, 32145, 32197, 32253, 32354, 32413, 32487, 32826, 32884, 32950, 33003, 33077, 33182, 33549, 33615, 33711, 33767, 33822, 34156, 34267, 34384, 34846, 35937, 36215, 36535, 36655, 36783, 37104, 37688, 37984, 38177, 38608, 38703, 38768, 38848, 38917, 38976, 39047, 39108, 39163, 39361, 39754, 39808, 39969, 40040, 40090, 40152, 40217, 40337, 40450, 40646, 41403, 41506, 41612, 41713, 41764, 41913, 42065, 42339, 42859, 43072, 43188, 43291, 43597, 43997, 44100, 44353, 44977, 45247, 45794, 46270, 46774, 47254, 48142, 49471, 49640, 49791, 49856, 49967, 50084, 50199, 50303, 50360, 50682, 50791, 50855, 50937, 51055, 51112, 51166, 51253, 51320, 51459, 51549, 51800, 51878, 51938, 51994, 52056, 52110, 52168, 52222, 52285, 52392, 52579, 52635, 52696, 52747, 52798, 52856, 52909, 52968, 53041, 53097, 53154, 53206, 53312, 53369, 53426, 53497, 53547, 53601, 53653, 53704, 53756, 53826, 53896, 54174, 54224, 54277, 54333, 54385, 54438, 54499, 54551, 54602, 54657, 54710, 54769, 54832, 55056, 55121, 55179, 55229, 56410};
const int layer2_servo5[] PROGMEM = {  // S5 (D7) (OWNED)
  108, 104, 101, 97, 94, 91, 87, 84, 88, 91, 87, 83, 80, 76, 73, 69, 63, 56, 53, 49, 29, 26, 23, 26, 33, 39, 49, 52, 55, 58, 62, 68, 71, 76, 80, 77, 73, 70, 66, 62, 58, 55, 52, 48, 44, 41, 38, 35, 31, 34, 38, 42, 45, 52, 56, 61, 65, 78, 83, 98, 112, 117, 122, 118, 113, 108, 104, 101, 97, 94, 90, 87, 82, 79, 76, 68, 65, 62, 59, 56, 52, 48, 45, 42, 39, 35, 32, 24, 20, 16, 12, 16, 20, 28, 31, 34, 42, 45, 49, 59, 62, 70, 79, 83, 87, 84, 81, 77, 74, 70, 67, 64, 61, 57, 54, 51, 48, 44, 41, 45, 48, 52, 56, 62, 66, 69, 73, 70, 66, 63, 60, 57, 53, 50, 47, 44, 41, 44, 47, 51, 54, 57, 54, 51, 47, 44, 41, 38, 34, 31, 27, 24, 21, 11, 14, 18, 22, 27, 31, 37, 40, 45, 50, 46, 43, 37, 33, 30, 27, 30, 39, 48, 52, 57, 62, 68, 72, 77, 80, 83, 79, 68, 64, 61, 53, 48, 45, 42, 45, 52, 56, 63, 66, 69, 72, 76, 81, 85, 88, 85, 81, 76, 66, 62, 57, 54, 50, 47, 44, 38, 42, 53, 61, 67, 71, 78, 83, 86, 90, 86, 79, 74, 71, 67, 62, 59, 55, 50, 47, 42, 38, 41, 47, 51, 55, 59, 62, 65, 61, 56, 52, 47, 44, 48, 51, 55, 58, 62, 65, 61, 57, 54, 51, 47, 44, 47, 50, 54, 57, 60, 57, 54, 51, 54, 51, 48, 44, 41, 38, 34, 31, 28, 25, 28, 32, 35, 39, 43, 55, 58, 64, 67, 71, 67, 63, 60, 57, 53, 50, 46, 43, 40, 37, 40, 43, 47, 51, 56, 59, 62, 66, 63, 60, 56, 53, 49, 52, 56, 59, 56, 53, 49, 46, 42, 39, 36, 39, 42, 45, 49, 52, 55, 58, 61, 64, 61, 58, 55, 51, 48, 45, 42, 39, 36, 32, 29, 32, 36, 42, 46, 51, 54, 59, 64, 70, 74, 68, 57, 52, 47, 42, 33, 28, 25, 22, 18, 14, 11, 14, 20, 30, 39, 44, 48, 51, 55, 59, 62, 67, 64, 60, 55, 47, 42, 37, 32, 26, 23, 20, 9, 6, 0, 3, 13, 21, 33, 33};
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
