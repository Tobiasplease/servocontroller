/*
 * 10-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-08-23 02:09:31
 * Hardware Config: Default
 * Layers: 6
 * Original Frames Recorded: 4645
 * Loop Duration: 11.96s (recorded) / 11.96s (at 1.0x speed)
 * Playback Speed: 1.0x
 * 
 * Layer Priority (later layers override earlier for same servo):
 * Servo 0 (S0 (D12)): Layer 6
 * Servo 1 (S1 (D11)): Layer 6
 * Servo 2 (S2 (D10)): Layer 6
 * Servo 3 (S3 (D9)): Layer 6
 * Servo 4 (S4 (D8)): Layer 6
 * Servo 5 (S5 (D7)): Layer 5
 * Servo 6 (S6 (D6)): Layer 4
 * Servo 7 (S7 (D5)): Layer 3
 * Servo 8 (S8 (D4)): Layer 2
 * Servo 9 (S9 (D3)): Layer 1
 * 
 * Hardware: 5 group-A channels + 5 group-B channels
 * Group A: S0 (D12), S1 (D11), S2 (D10), S3 (D9), S4 (D8)
 * Group B: S5 (D7), S6 (D6), S7 (D5), S8 (D4), S9 (D3)
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
 * S9 -> D3
 *
 * Stored positions already constrained during recording
 */

#include <Servo.h>

// Servo objects
Servo servo[10];
int servoPins[10] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3};

// Range configuration (from hardware preset: Default)
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;
// Per-channel performed range: the per-servo limit intersected with the
// expressive range. No host here to apply it, so it is compiled in.
// (Kept ASCII on purpose -- generated sketches are written with the platform
// default codec, and a stray non-ASCII character kills the export on Windows.)
const int servoMin[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
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
unsigned long loopDuration = 11960; // milliseconds (adjusted for 1.0x speed)

// Startup pose (matches first recorded frame per owned servo)
const int startupPositions[10] = {84, 121, 70, 32, 84, 7, 78, 74, 109, 50};

// Layer data structures

// Layer 1: Layer_1 (manual mode) - 27 keyframes
const int layer1_count = 27;
const unsigned long layer1_times[] PROGMEM = {0, 791, 968, 1120, 1225, 1407, 1660, 2245, 2375, 2640, 2882, 3381, 4513, 4858, 5320, 6024, 6168, 6768, 7797, 8220, 8653, 9180, 9594, 9883, 10337, 10823, 11960};
const int layer1_servo9[] PROGMEM = {  // S9 (D3) (OWNED)
  50, 53, 57, 60, 63, 66, 70, 67, 64, 60, 57, 54, 57, 60, 63, 66, 69, 73, 69, 66, 63, 60, 56, 53, 50, 47, 49};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 31 keyframes
const int layer2_count = 31;
const unsigned long layer2_times[] PROGMEM = {0, 1553, 1896, 2603, 2820, 3204, 3813, 4070, 4511, 5049, 5289, 5653, 6278, 6732, 7150, 7367, 7566, 7744, 7902, 8179, 8319, 8824, 9145, 9715, 10042, 10340, 10727, 11101, 11422, 11816, 11960};
const int layer2_servo8[] PROGMEM = {  // S8 (D4) (OWNED)
  109, 105, 102, 105, 109, 112, 109, 105, 102, 105, 109, 112, 109, 105, 108, 111, 115, 118, 121, 124, 127, 130, 133, 136, 133, 130, 127, 124, 121, 118, 117};
int layer2_index = 0;

// Layer 3: Layer_3 (manual mode) - 41 keyframes
const int layer3_count = 41;
const unsigned long layer3_times[] PROGMEM = {0, 959, 1232, 1668, 2185, 2417, 2522, 2891, 3203, 3452, 3765, 3925, 4117, 4637, 4704, 4855, 5105, 5272, 5636, 5821, 6602, 6848, 7108, 7333, 7509, 7670, 8079, 8207, 8319, 8455, 8602, 8824, 8992, 9564, 9762, 10117, 10380, 10628, 10949, 11342, 11960};
const int layer3_servo7[] PROGMEM = {  // S7 (D5) (OWNED)
  74, 77, 80, 84, 81, 78, 74, 71, 74, 77, 80, 84, 87, 84, 81, 78, 75, 72, 68, 65, 68, 71, 74, 77, 80, 84, 81, 78, 75, 72, 68, 65, 62, 65, 68, 72, 75, 78, 82, 85, 86};
int layer3_index = 0;

// Layer 4: Layer_4 (manual mode) - 47 keyframes
const int layer4_count = 47;
const unsigned long layer4_times[] PROGMEM = {0, 432, 573, 704, 1138, 1643, 2077, 2526, 2579, 2790, 2936, 3056, 3180, 3408, 3498, 4283, 5080, 5231, 5443, 5542, 5909, 6073, 6201, 6378, 6535, 6748, 6986, 7285, 7722, 7853, 8053, 8198, 8380, 8438, 8678, 8790, 9384, 9649, 9735, 10115, 10539, 10716, 10900, 11103, 11479, 11795, 11960};
const int layer4_servo6[] PROGMEM = {  // S6 (D6) (OWNED)
  78, 81, 84, 87, 90, 93, 97, 94, 91, 87, 84, 81, 78, 75, 72, 68, 72, 75, 78, 81, 84, 81, 78, 75, 72, 68, 65, 62, 65, 68, 72, 75, 78, 81, 84, 87, 84, 81, 78, 75, 78, 81, 84, 88, 91, 94, 96};
int layer4_index = 0;

// Layer 5: Layer_5 (manual mode) - 49 keyframes
const int layer5_count = 49;
const unsigned long layer5_times[] PROGMEM = {0, 806, 998, 1198, 1983, 2198, 2311, 2527, 2800, 3183, 3647, 3799, 3930, 4104, 4416, 4721, 5353, 5553, 5689, 5889, 6068, 6316, 6565, 6978, 7091, 7187, 7284, 7343, 7691, 7776, 7907, 8003, 8123, 10034, 10129, 10187, 10252, 10349, 10517, 10628, 10758, 10981, 11033, 11160, 11257, 11347, 11539, 11654, 11960};
const int layer5_servo5[] PROGMEM = {  // S5 (D7) (OWNED)
  7, 10, 14, 17, 14, 10, 7, 3, 0, 3, 6, 9, 12, 15, 19, 22, 19, 16, 12, 9, 6, 3, 0, 3, 7, 10, 13, 17, 14, 11, 8, 5, 2, 5, 8, 11, 14, 18, 21, 24, 27, 24, 20, 16, 13, 10, 7, 3, 6};
int layer5_index = 0;

// Layer 6: Layer_6 (cursor mode) - 103 keyframes
const int layer6_count = 103;
const unsigned long layer6_times[] PROGMEM = {0, 134, 288, 397, 500, 606, 709, 812, 918, 1022, 1124, 1228, 1335, 1437, 1552, 1667, 1768, 1872, 1981, 2088, 2189, 2290, 2482, 2586, 2687, 2788, 2891, 2995, 3105, 3211, 3315, 3476, 3652, 3756, 3861, 3969, 4101, 4213, 4319, 4598, 4823, 4928, 5067, 5168, 5268, 5480, 5589, 5705, 5809, 5913, 6016, 6120, 6331, 6564, 6739, 6843, 6956, 7062, 7172, 7276, 7377, 7479, 7582, 7688, 7790, 7895, 7998, 8102, 8203, 8311, 8415, 8519, 8640, 8745, 8848, 8952, 9057, 9163, 9265, 9370, 9471, 9572, 9674, 9778, 9882, 9986, 10091, 10196, 10300, 10403, 10508, 10613, 10744, 10853, 10957, 11077, 11197, 11302, 11403, 11567, 11675, 11913, 11960};
const int layer6_servo0[] PROGMEM = {  // S0 (D12) (OWNED)
  84, 89, 94, 105, 110, 116, 130, 141, 147, 150, 150, 149, 143, 137, 132, 127, 123, 122, 118, 116, 114, 114, 118, 123, 129, 139, 140, 138, 135, 129, 124, 120, 115, 111, 110, 111, 111, 112, 116, 121, 124, 128, 127, 121, 114, 109, 105, 106, 106, 108, 110, 114, 119, 122, 123, 123, 121, 117, 112, 109, 106, 104, 103, 102, 104, 110, 117, 128, 134, 140, 146, 151, 154, 152, 149, 143, 139, 133, 126, 117, 110, 104, 99, 97, 102, 109, 115, 120, 124, 131, 139, 146, 146, 145, 134, 129, 126, 123, 119, 114, 106, 102, 101};
const int layer6_servo1[] PROGMEM = {  // S1 (D11) (OWNED)
  121, 124, 126, 131, 134, 136, 132, 125, 117, 108, 98, 93, 83, 75, 70, 65, 63, 66, 82, 90, 100, 112, 117, 121, 121, 110, 101, 91, 82, 72, 66, 60, 56, 56, 58, 65, 70, 75, 83, 88, 86, 82, 77, 64, 54, 49, 49, 52, 63, 76, 83, 90, 95, 93, 87, 79, 73, 68, 63, 63, 66, 70, 77, 88, 97, 104, 108, 110, 109, 106, 104, 104, 110, 126, 138, 148, 155, 158, 160, 158, 155, 151, 147, 139, 136, 133, 126, 119, 114, 109, 110, 116, 122, 127, 131, 128, 119, 109, 104, 98, 95, 96, 98};
const int layer6_servo2[] PROGMEM = {  // S2 (D10) (OWNED)
  70, 71, 72, 74, 75, 75, 68, 63, 61, 60, 61, 62, 63, 61, 56, 51, 41, 36, 29, 32, 38, 48, 54, 58, 58, 53, 51, 48, 46, 44, 41, 38, 33, 25, 22, 21, 21, 23, 29, 34, 35, 38, 38, 36, 32, 28, 20, 18, 16, 21, 25, 31, 36, 36, 35, 33, 31, 27, 22, 19, 16, 17, 19, 26, 34, 41, 45, 49, 51, 52, 56, 61, 64, 68, 75, 85, 94, 100, 107, 110, 110, 109, 105, 92, 83, 74, 63, 56, 51, 49, 53, 60, 63, 66, 68, 64, 56, 47, 42, 37, 32, 32, 34};
const int layer6_servo3[] PROGMEM = {  // S3 (D9) (OWNED)
  32, 36, 39, 47, 51, 55, 66, 79, 91, 102, 113, 118, 124, 123, 118, 113, 101, 92, 65, 57, 52, 50, 54, 60, 65, 83, 90, 95, 99, 102, 100, 98, 92, 80, 74, 66, 62, 60, 62, 67, 73, 83, 88, 93, 92, 88, 76, 71, 60, 53, 53, 55, 60, 65, 71, 78, 79, 77, 71, 64, 56, 51, 46, 40, 41, 47, 54, 66, 75, 87, 98, 108, 108, 94, 87, 80, 78, 75, 73, 68, 65, 61, 57, 50, 48, 50, 53, 57, 61, 72, 82, 90, 88, 84, 71, 65, 63, 61, 57, 52, 44, 39, 38};
const int layer6_servo4[] PROGMEM = {  // S4 (D8) (OWNED)
  84, 89, 94, 105, 110, 116, 130, 141, 147, 150, 150, 149, 143, 137, 132, 127, 123, 122, 118, 116, 114, 114, 118, 123, 129, 139, 140, 138, 135, 129, 124, 120, 115, 111, 110, 111, 111, 112, 116, 121, 124, 128, 127, 121, 114, 109, 105, 106, 106, 108, 110, 114, 119, 122, 123, 123, 121, 117, 112, 109, 106, 104, 103, 102, 104, 110, 117, 128, 134, 140, 146, 151, 154, 152, 149, 143, 139, 133, 126, 117, 110, 104, 99, 97, 102, 109, 115, 120, 124, 131, 139, 146, 146, 145, 134, 129, 126, 123, 119, 114, 106, 102, 101};
int layer6_index = 0;

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
  }

  // Update layer 1 with interpolation (OWNS: S9 (D3))
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
      // Interpolate S9 (D3)
      int curr9 = pgm_read_word(&layer1_servo9[layer1_index]);
      // reading [index + 1] past the end would run off the array
      int next9 = atEnd ? curr9
                  : (int)pgm_read_word(&layer1_servo9[layer1_index + 1]);
      int start9 = pgm_read_word(&layer1_servo9[0]);
      
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

  // Update layer 2 with interpolation (OWNS: S8 (D4))
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
      // Interpolate S8 (D4)
      int curr8 = pgm_read_word(&layer2_servo8[layer2_index]);
      // reading [index + 1] past the end would run off the array
      int next8 = atEnd ? curr8
                  : (int)pgm_read_word(&layer2_servo8[layer2_index + 1]);
      int start8 = pgm_read_word(&layer2_servo8[0]);
      
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

  // Update layer 3 with interpolation (OWNS: S7 (D5))
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
      // Interpolate S7 (D5)
      int curr7 = pgm_read_word(&layer3_servo7[layer3_index]);
      // reading [index + 1] past the end would run off the array
      int next7 = atEnd ? curr7
                  : (int)pgm_read_word(&layer3_servo7[layer3_index + 1]);
      int start7 = pgm_read_word(&layer3_servo7[0]);
      
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

  // Update layer 4 with interpolation (OWNS: S6 (D6))
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
      // Interpolate S6 (D6)
      int curr6 = pgm_read_word(&layer4_servo6[layer4_index]);
      // reading [index + 1] past the end would run off the array
      int next6 = atEnd ? curr6
                  : (int)pgm_read_word(&layer4_servo6[layer4_index + 1]);
      int start6 = pgm_read_word(&layer4_servo6[0]);
      
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

  // Update layer 5 with interpolation (OWNS: S5 (D7))
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
      // Interpolate S5 (D7)
      int curr5 = pgm_read_word(&layer5_servo5[layer5_index]);
      // reading [index + 1] past the end would run off the array
      int next5 = atEnd ? curr5
                  : (int)pgm_read_word(&layer5_servo5[layer5_index + 1]);
      int start5 = pgm_read_word(&layer5_servo5[0]);
      
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

  // Update layer 6 with interpolation (OWNS: S0 (D12), S1 (D11), S2 (D10), S3 (D9), S4 (D8))
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
      // Interpolate S0 (D12)
      int curr0 = pgm_read_word(&layer6_servo0[layer6_index]);
      // reading [index + 1] past the end would run off the array
      int next0 = atEnd ? curr0
                  : (int)pgm_read_word(&layer6_servo0[layer6_index + 1]);
      int start0 = pgm_read_word(&layer6_servo0[0]);
      
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
      int curr1 = pgm_read_word(&layer6_servo1[layer6_index]);
      // reading [index + 1] past the end would run off the array
      int next1 = atEnd ? curr1
                  : (int)pgm_read_word(&layer6_servo1[layer6_index + 1]);
      int start1 = pgm_read_word(&layer6_servo1[0]);
      
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
      int curr2 = pgm_read_word(&layer6_servo2[layer6_index]);
      // reading [index + 1] past the end would run off the array
      int next2 = atEnd ? curr2
                  : (int)pgm_read_word(&layer6_servo2[layer6_index + 1]);
      int start2 = pgm_read_word(&layer6_servo2[0]);
      
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
      int curr3 = pgm_read_word(&layer6_servo3[layer6_index]);
      // reading [index + 1] past the end would run off the array
      int next3 = atEnd ? curr3
                  : (int)pgm_read_word(&layer6_servo3[layer6_index + 1]);
      int start3 = pgm_read_word(&layer6_servo3[0]);
      
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
      int curr4 = pgm_read_word(&layer6_servo4[layer6_index]);
      // reading [index + 1] past the end would run off the array
      int next4 = atEnd ? curr4
                  : (int)pgm_read_word(&layer6_servo4[layer6_index + 1]);
      int start4 = pgm_read_word(&layer6_servo4[0]);
      
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
