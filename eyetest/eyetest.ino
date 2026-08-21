/*
 * 10-Servo Hand Control - Generated Movement Code (SIMULTANEOUS PLAYBACK)
 * Generated: 2026-08-19 16:12:07
 * Hardware Config: Default
 * Layers: 2
 * Original Frames Recorded: 3048
 * Loop Duration: 24.93s (recorded) / 24.93s (at 1.0x speed)
 * Playback Speed: 1.0x
 * 
 * Layer Priority (later layers override earlier for same servo):
 * Servo 0 (S0 (D12)): Layer 2
 * Servo 1 (S1 (D11)): Layer 1
 * 
 * Hardware: 5 Finger Servos + 3 Arm Servos
 * Fingers: S0 (D12), S1 (D11), S2 (D10), S3 (D9), S4 (D8)
 * Arm: S5 (D7), S6 (D6), S7 (D5), S8 (D4), S9 (D3)
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
Servo servo[10];
int servoPins[10] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3};

// Range configuration (from hardware preset: Default)
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;

// ---- Organic variation ----------------------------------------------------
// Mirrors the Organic panel in the UI, so the sketch breathes the same way the
// preview did. 0 values = exact replay of the recorded take.
// (Pause Chance is a live-preview control only and is not exported.)
const float WOBBLE_AMOUNT = 3.50;   // degrees of drift per channel
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

// Helper: Map 0-180 to MIN-MAX, reverse specified servos
void writeServo(int index, int pos) {
  pos = applyWobble(index, pos);
  pos = map(pos, 0, 180, MIN_ANGLE, MAX_ANGLE);
  pos = constrain(pos, MIN_ANGLE, MAX_ANGLE);
  if(0) pos = MAX_ANGLE - pos;  // Reverse none
  servo[index].write(pos);
}

// Timing
unsigned long loopStartTime;
unsigned long loopDuration = 24930; // milliseconds (adjusted for 1.0x speed)

// Startup pose (matches first recorded frame per owned servo)
const int startupPositions[10] = {149, 154, 90, 90, 90, 90, 90, 90, 90, 90};

// Layer data structures

// Layer 1: Layer_1 (manual mode) - 83 keyframes
const int layer1_count = 83;
const unsigned long layer1_times[] PROGMEM = {0, 1791, 2880, 2954, 3074, 3324, 3448, 3587, 3726, 3803, 3942, 4057, 6827, 6973, 7072, 7126, 7186, 7252, 7306, 7379, 7446, 7502, 7593, 9176, 9320, 9446, 9511, 9566, 9622, 9689, 9748, 9808, 9895, 9971, 10136, 13886, 13976, 14038, 14130, 14278, 14414, 14660, 14782, 14918, 15002, 15077, 15185, 15391, 15481, 18468, 18524, 18576, 18639, 18694, 19429, 19485, 19556, 20066, 20120, 20173, 20235, 20631, 20825, 20973, 21041, 21098, 21154, 21218, 21288, 21403, 21682, 21842, 22042, 23613, 23682, 23760, 23926, 24015, 24082, 24148, 24315, 24426, 24930};
const int layer1_servo1[] PROGMEM = {  // S1 (D11) (OWNED)
  154, 148, 145, 142, 139, 136, 133, 130, 127, 123, 120, 117, 120, 123, 127, 130, 133, 136, 139, 142, 145, 149, 152, 149, 146, 142, 139, 136, 133, 130, 127, 124, 121, 118, 115, 118, 121, 124, 128, 131, 134, 137, 140, 143, 146, 150, 153, 156, 159, 156, 151, 147, 141, 138, 134, 126, 123, 127, 144, 154, 158, 155, 152, 149, 146, 143, 139, 136, 133, 130, 127, 124, 121, 124, 127, 130, 134, 137, 140, 143, 146, 150, 151};
int layer1_index = 0;

// Layer 2: Layer_2 (manual mode) - 127 keyframes
const int layer2_count = 127;
const unsigned long layer2_times[] PROGMEM = {0, 1341, 1470, 1544, 1601, 1674, 1816, 1914, 1974, 2031, 2150, 2247, 2358, 3865, 3969, 4066, 4119, 4172, 4240, 4314, 4381, 4455, 4798, 6255, 6307, 6368, 6610, 6700, 6755, 6817, 6913, 7364, 7449, 7502, 7554, 7609, 7662, 7729, 7838, 8003, 8344, 8413, 8516, 8829, 8976, 9201, 9343, 9448, 9848, 9923, 10012, 10138, 10266, 10419, 10524, 10648, 10761, 10828, 11018, 11276, 13492, 13590, 13666, 13904, 14064, 14115, 14199, 14815, 14953, 15195, 15356, 15481, 15570, 15766, 15931, 16105, 16203, 16288, 16447, 16758, 16827, 16907, 16971, 17105, 17347, 17480, 17594, 17772, 17898, 17973, 18099, 18231, 18385, 18907, 19069, 19126, 19190, 19256, 19309, 19361, 19462, 19563, 20006, 20334, 20487, 20656, 20778, 20855, 20937, 21044, 21105, 21225, 21352, 22161, 22211, 22262, 22322, 22418, 22612, 22753, 22918, 23264, 23662, 23972, 24069, 24791, 24930};
const int layer2_servo0[] PROGMEM = {  // S0 (D12) (OWNED)
  149, 146, 142, 139, 136, 133, 130, 126, 123, 120, 117, 114, 111, 114, 117, 120, 123, 128, 131, 134, 137, 140, 137, 134, 129, 126, 123, 120, 117, 113, 110, 113, 116, 120, 123, 128, 132, 135, 138, 141, 145, 148, 151, 154, 157, 160, 163, 166, 163, 160, 157, 154, 151, 148, 145, 141, 138, 135, 132, 129, 126, 123, 120, 117, 120, 125, 128, 131, 134, 137, 140, 144, 147, 150, 153, 156, 159, 162, 165, 162, 159, 156, 153, 150, 147, 144, 140, 137, 134, 131, 128, 125, 122, 119, 122, 126, 129, 132, 135, 138, 141, 145, 148, 145, 141, 138, 135, 132, 129, 126, 122, 119, 116, 120, 123, 128, 131, 134, 137, 140, 143, 146, 143, 140, 137, 134, 134};
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

  // Update layer 1 with interpolation (OWNS: S1 (D11))
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
    }
  }

  // Update layer 2 with interpolation (OWNS: S0 (D12))
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
      // Interpolate S0 (D12)
      int curr0 = pgm_read_word(&layer2_servo0[layer2_index]);
      // reading [index + 1] past the end would run off the array
      int next0 = atEnd ? curr0
                  : (int)pgm_read_word(&layer2_servo0[layer2_index + 1]);
      int start0 = pgm_read_word(&layer2_servo0[0]);
      
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
