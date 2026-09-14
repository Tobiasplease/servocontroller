/*
 * 10-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-08-23 01:56:32
 * Hardware Config: Default
 * Layers: 20
 * Original Frames Recorded: 21196
 * Loop Duration: 13.83s (recorded) / 13.83s (at 1.0x speed)
 * Playback Speed: 1.0x
 * 
 * Layer Priority (later layers override earlier for same servo):
 * Servo 0 (S0 (D12)): Layer 19
 * Servo 1 (S1 (D11)): Layer 19
 * Servo 2 (S2 (D10)): Layer 19
 * Servo 3 (S3 (D9)): Layer 19
 * Servo 4 (S4 (D8)): Layer 19
 * Servo 5 (S5 (D7)): Layer 17
 * Servo 6 (S6 (D6)): Layer 18
 * Servo 7 (S7 (D5)): Layer 16
 * Servo 8 (S8 (D4)): Layer 20
 * Servo 9 (S9 (D2)): Layer 14
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
unsigned long loopDuration = 13830; // milliseconds (adjusted for 1.0x speed)

// Startup pose (matches first recorded frame per owned servo)
const int startupPositions[10] = {160, 160, 160, 160, 160, 18, 111, 85, 90, 16};

// Layer data structures

// Layer 1: Layer_1 - MASKED by later layer(s)

// Layer 2: Layer_2 - MASKED by later layer(s)

// Layer 3: Layer_3 - MASKED by later layer(s)

// Layer 4: Layer_4 - MASKED by later layer(s)

// Layer 5: Layer_5 - MASKED by later layer(s)

// Layer 6: Layer_6 - MASKED by later layer(s)

// Layer 7: Layer_7 - MASKED by later layer(s)

// Layer 8: Layer_8 - MASKED by later layer(s)

// Layer 9: Layer_9 - MASKED by later layer(s)

// Layer 10: Layer_10 - MASKED by later layer(s)

// Layer 11: Layer_11 - MASKED by later layer(s)

// Layer 12: Layer_12 - MASKED by later layer(s)

// Layer 13: Layer_13 - MASKED by later layer(s)

// Layer 14: Layer_14 (manual mode) - 24 keyframes
const int layer14_count = 24;
const unsigned long layer14_times[] PROGMEM = {0, 1004, 1604, 2349, 2909, 3774, 4223, 4726, 5504, 6373, 6808, 7493, 8121, 9419, 9678, 10031, 10291, 11324, 11652, 12170, 12727, 13119, 13711, 13830};
const int layer14_servo9[] PROGMEM = {  // S9 (D2) (OWNED)
  16, 25, 22, 12, 21, 24, 14, 24, 20, 10, 21, 25, 15, 11, 22, 25, 15, 20, 29, 19, 15, 25, 22, 19};
int layer14_index = 0;

// Layer 15: Layer_15 - MASKED by later layer(s)

// Layer 16: Layer_16 (manual mode) - 15 keyframes
const int layer16_count = 15;
const unsigned long layer16_times[] PROGMEM = {0, 1418, 1940, 3013, 3981, 4708, 6478, 8250, 8906, 10115, 10507, 11397, 12489, 13661, 13830};
const int layer16_servo7[] PROGMEM = {  // S7 (D5) (OWNED)
  85, 96, 86, 76, 80, 83, 80, 77, 87, 90, 81, 90, 93, 90, 94};
int layer16_index = 0;

// Layer 17: Layer_17 (manual mode) - 36 keyframes
const int layer17_count = 36;
const unsigned long layer17_times[] PROGMEM = {0, 728, 1120, 1476, 1969, 2888, 3229, 3661, 3933, 4415, 4863, 5176, 5570, 5857, 6394, 6620, 6947, 7196, 7647, 7864, 8093, 8749, 9055, 9515, 10016, 10367, 10689, 11025, 11284, 11474, 11763, 12045, 12341, 12845, 13526, 13830};
const int layer17_servo5[] PROGMEM = {  // S5 (D7) (OWNED)
  18, 29, 38, 47, 38, 41, 31, 22, 32, 42, 32, 22, 31, 44, 33, 22, 13, 25, 28, 19, 9, 12, 22, 12, 2, 11, 21, 31, 22, 12, 3, 12, 22, 19, 15, 24};
int layer17_index = 0;

// Layer 18: Layer_18 (manual mode) - 33 keyframes
const int layer18_count = 33;
const unsigned long layer18_times[] PROGMEM = {0, 1010, 1566, 2055, 2432, 3073, 3531, 3756, 4387, 4888, 5085, 5596, 6175, 6438, 6728, 7116, 7304, 7547, 7878, 8093, 8700, 8972, 9477, 9661, 10208, 10408, 11062, 11355, 11850, 12401, 13122, 13790, 13830};
const int layer18_servo6[] PROGMEM = {  // S6 (D6) (OWNED)
  111, 120, 117, 114, 123, 120, 111, 121, 118, 115, 124, 112, 109, 119, 128, 131, 120, 111, 116, 126, 129, 119, 122, 132, 135, 126, 123, 133, 123, 127, 130, 133, 135};
int layer18_index = 0;

// Layer 19: Layer_19 (cursor mode) - 35 keyframes
const int layer19_count = 35;
const unsigned long layer19_times[] PROGMEM = {0, 767, 1095, 1512, 1832, 2234, 2569, 2959, 3283, 3636, 3948, 4416, 4865, 5200, 5511, 6343, 6678, 6993, 7747, 8079, 8394, 8839, 9374, 9719, 10119, 10447, 10779, 11315, 11636, 12098, 12411, 12856, 13196, 13650, 13830};
const int layer19_servo0[] PROGMEM = {  // S0 (D12) (OWNED)
  160, 138, 106, 126, 160, 120, 86, 135, 148, 116, 90, 96, 111, 88, 39, 6, 70, 115, 151, 118, 90, 103, 113, 85, 91, 116, 135, 95, 68, 100, 133, 108, 83, 103, 125};
const int layer19_servo1[] PROGMEM = {  // S1 (D11) (OWNED)
  160, 138, 106, 126, 160, 120, 86, 135, 148, 116, 90, 96, 111, 88, 39, 6, 70, 115, 151, 118, 90, 103, 113, 85, 91, 116, 135, 95, 68, 100, 133, 108, 83, 103, 125};
const int layer19_servo2[] PROGMEM = {  // S2 (D10) (OWNED)
  160, 138, 106, 126, 160, 120, 86, 135, 148, 116, 90, 96, 111, 88, 39, 6, 70, 115, 151, 118, 90, 103, 113, 85, 91, 116, 135, 95, 68, 100, 133, 108, 83, 103, 125};
const int layer19_servo3[] PROGMEM = {  // S3 (D9) (OWNED)
  160, 138, 106, 126, 160, 120, 86, 135, 148, 116, 90, 96, 111, 88, 39, 6, 70, 115, 151, 118, 90, 103, 113, 85, 91, 116, 135, 95, 68, 100, 133, 108, 83, 103, 125};
const int layer19_servo4[] PROGMEM = {  // S4 (D8) (OWNED)
  160, 138, 106, 126, 160, 120, 86, 135, 148, 116, 90, 96, 111, 88, 39, 6, 70, 115, 151, 118, 90, 103, 113, 85, 91, 116, 135, 95, 68, 100, 133, 108, 83, 103, 125};
int layer19_index = 0;

// Layer 20: Layer_20 (manual mode) - 21 keyframes
const int layer20_count = 21;
const unsigned long layer20_times[] PROGMEM = {0, 1151, 1998, 2882, 3789, 4631, 5147, 5408, 6016, 6388, 6925, 7528, 8325, 9029, 9661, 10302, 11081, 11939, 12765, 13806, 13830};
const int layer20_servo8[] PROGMEM = {  // S8 (D4) (OWNED)
  90, 99, 96, 106, 96, 93, 103, 112, 115, 105, 95, 86, 76, 85, 89, 80, 89, 86, 83, 86, 85};
int layer20_index = 0;

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
    layer14_index = 0;
    layer16_index = 0;
    layer17_index = 0;
    layer18_index = 0;
    layer19_index = 0;
    layer20_index = 0;
  }

  // Update layer 14 with interpolation (OWNS: S9 (D2))
  {
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer14_index < layer14_count - 1 &&
          elapsed >= pgm_read_dword(&layer14_times[layer14_index + 1])) {
      layer14_index++;
    }

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer14_index >= layer14_count - 1);
    float factor = 0.0;
    if(!atEnd) {
      unsigned long currentTime = pgm_read_dword(&layer14_times[layer14_index]);
      unsigned long nextTime = pgm_read_dword(&layer14_times[layer14_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }
    }
    {
      // Interpolate S9 (D2)
      int curr9 = pgm_read_word(&layer14_servo9[layer14_index]);
      // reading [index + 1] past the end would run off the array
      int next9 = atEnd ? curr9
                  : (int)pgm_read_word(&layer14_servo9[layer14_index + 1]);
      int start9 = pgm_read_word(&layer14_servo9[0]);
      
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

  // Update layer 16 with interpolation (OWNS: S7 (D5))
  {
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer16_index < layer16_count - 1 &&
          elapsed >= pgm_read_dword(&layer16_times[layer16_index + 1])) {
      layer16_index++;
    }

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer16_index >= layer16_count - 1);
    float factor = 0.0;
    if(!atEnd) {
      unsigned long currentTime = pgm_read_dword(&layer16_times[layer16_index]);
      unsigned long nextTime = pgm_read_dword(&layer16_times[layer16_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }
    }
    {
      // Interpolate S7 (D5)
      int curr7 = pgm_read_word(&layer16_servo7[layer16_index]);
      // reading [index + 1] past the end would run off the array
      int next7 = atEnd ? curr7
                  : (int)pgm_read_word(&layer16_servo7[layer16_index + 1]);
      int start7 = pgm_read_word(&layer16_servo7[0]);
      
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

  // Update layer 17 with interpolation (OWNS: S5 (D7))
  {
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer17_index < layer17_count - 1 &&
          elapsed >= pgm_read_dword(&layer17_times[layer17_index + 1])) {
      layer17_index++;
    }

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer17_index >= layer17_count - 1);
    float factor = 0.0;
    if(!atEnd) {
      unsigned long currentTime = pgm_read_dword(&layer17_times[layer17_index]);
      unsigned long nextTime = pgm_read_dword(&layer17_times[layer17_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }
    }
    {
      // Interpolate S5 (D7)
      int curr5 = pgm_read_word(&layer17_servo5[layer17_index]);
      // reading [index + 1] past the end would run off the array
      int next5 = atEnd ? curr5
                  : (int)pgm_read_word(&layer17_servo5[layer17_index + 1]);
      int start5 = pgm_read_word(&layer17_servo5[0]);
      
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

  // Update layer 18 with interpolation (OWNS: S6 (D6))
  {
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer18_index < layer18_count - 1 &&
          elapsed >= pgm_read_dword(&layer18_times[layer18_index + 1])) {
      layer18_index++;
    }

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer18_index >= layer18_count - 1);
    float factor = 0.0;
    if(!atEnd) {
      unsigned long currentTime = pgm_read_dword(&layer18_times[layer18_index]);
      unsigned long nextTime = pgm_read_dword(&layer18_times[layer18_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }
    }
    {
      // Interpolate S6 (D6)
      int curr6 = pgm_read_word(&layer18_servo6[layer18_index]);
      // reading [index + 1] past the end would run off the array
      int next6 = atEnd ? curr6
                  : (int)pgm_read_word(&layer18_servo6[layer18_index + 1]);
      int start6 = pgm_read_word(&layer18_servo6[0]);
      
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

  // Update layer 19 with interpolation (OWNS: S0 (D12), S1 (D11), S2 (D10), S3 (D9), S4 (D8))
  {
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer19_index < layer19_count - 1 &&
          elapsed >= pgm_read_dword(&layer19_times[layer19_index + 1])) {
      layer19_index++;
    }

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer19_index >= layer19_count - 1);
    float factor = 0.0;
    if(!atEnd) {
      unsigned long currentTime = pgm_read_dword(&layer19_times[layer19_index]);
      unsigned long nextTime = pgm_read_dword(&layer19_times[layer19_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }
    }
    {
      // Interpolate S0 (D12)
      int curr0 = pgm_read_word(&layer19_servo0[layer19_index]);
      // reading [index + 1] past the end would run off the array
      int next0 = atEnd ? curr0
                  : (int)pgm_read_word(&layer19_servo0[layer19_index + 1]);
      int start0 = pgm_read_word(&layer19_servo0[0]);
      
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
      int curr1 = pgm_read_word(&layer19_servo1[layer19_index]);
      // reading [index + 1] past the end would run off the array
      int next1 = atEnd ? curr1
                  : (int)pgm_read_word(&layer19_servo1[layer19_index + 1]);
      int start1 = pgm_read_word(&layer19_servo1[0]);
      
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
      int curr2 = pgm_read_word(&layer19_servo2[layer19_index]);
      // reading [index + 1] past the end would run off the array
      int next2 = atEnd ? curr2
                  : (int)pgm_read_word(&layer19_servo2[layer19_index + 1]);
      int start2 = pgm_read_word(&layer19_servo2[0]);
      
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
      int curr3 = pgm_read_word(&layer19_servo3[layer19_index]);
      // reading [index + 1] past the end would run off the array
      int next3 = atEnd ? curr3
                  : (int)pgm_read_word(&layer19_servo3[layer19_index + 1]);
      int start3 = pgm_read_word(&layer19_servo3[0]);
      
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
      int curr4 = pgm_read_word(&layer19_servo4[layer19_index]);
      // reading [index + 1] past the end would run off the array
      int next4 = atEnd ? curr4
                  : (int)pgm_read_word(&layer19_servo4[layer19_index + 1]);
      int start4 = pgm_read_word(&layer19_servo4[0]);
      
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

  // Update layer 20 with interpolation (OWNS: S8 (D4))
  {
    // Catch up in a while loop: one index per pass could fall behind
    // whenever keyframes land closer together than the loop period.
    while(layer20_index < layer20_count - 1 &&
          elapsed >= pgm_read_dword(&layer20_times[layer20_index + 1])) {
      layer20_index++;
    }

    // A layer that has run out of keyframes HOLDS its final pose and keeps
    // blending. The old guard skipped the whole block once the index hit the
    // end, so such a layer froze with no blend and then snapped back at the
    // loop reset.
    bool atEnd = (layer20_index >= layer20_count - 1);
    float factor = 0.0;
    if(!atEnd) {
      unsigned long currentTime = pgm_read_dword(&layer20_times[layer20_index]);
      unsigned long nextTime = pgm_read_dword(&layer20_times[layer20_index + 1]);
      if(nextTime > currentTime && elapsed >= currentTime) {
        factor = (float)(elapsed - currentTime) / (float)(nextTime - currentTime);
        factor = constrain(factor, 0.0, 1.0);
      }
    }
    {
      // Interpolate S8 (D4)
      int curr8 = pgm_read_word(&layer20_servo8[layer20_index]);
      // reading [index + 1] past the end would run off the array
      int next8 = atEnd ? curr8
                  : (int)pgm_read_word(&layer20_servo8[layer20_index + 1]);
      int start8 = pgm_read_word(&layer20_servo8[0]);
      
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

  delay(5); // 200Hz update rate for smooth interpolation
}
