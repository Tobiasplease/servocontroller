// PIR Markov State Machine - Auto-generated
// Generated: 2026-03-30 20:45:27
// Mode: Markov Segments (learned transitions between movement chunks)
//
// Segment length: 2.0s, Chaos: 71%, Blend: 500ms
// idle: 9 segments, active: 6 segments, sleep: 10 segments
//

#include <Servo.h>

// ==================== CONFIGURATION ====================
#define PIR_PIN 3
#define NUM_SERVOS 8
#define UPDATE_INTERVAL 20
#define SAMPLES_PER_SEGMENT 12
#define TOP_K_TRANS 6

const int servoPins[NUM_SERVOS] = {12, 11, 10, 9, 8, 7, 6, 5};
const bool servoReversed[NUM_SERVOS] = {false, false, true, true, false, false, false, false};
const int SERVO_MIN = 0;
const int SERVO_MAX = 45;

// Timing
const unsigned long ACTIVE_DURATION = 30000UL;
const unsigned long SLEEP_TIMEOUT = 300000UL;
const unsigned long STATE_BLEND_TIME = 5000UL;
const unsigned long SEGMENT_DURATION = 2000UL;
const unsigned long SEGMENT_BLEND_TIME = 500UL;

// Organic wobble
const float WOBBLE_AMOUNT = 1.5;
float phaseOffsets[NUM_SERVOS];

// ==================== SEGMENT DATA ====================

// IDLE state: 9 segments
#define NUM_IDLE_SEGMENTS 9
const PROGMEM uint8_t idleSeg[NUM_IDLE_SEGMENTS][SAMPLES_PER_SEGMENT][NUM_SERVOS] = {
  {{172,168,134,21,164,90,90,90},{172,168,111,21,164,90,90,90},{172,168,79,21,164,90,90,90},{160,167,47,21,147,90,90,90},{142,159,30,21,121,90,90,90},{133,154,20,21,83,90,90,90},{114,149,33,21,40,90,90,90},{97,144,48,21,11,90,90,90},{79,136,71,21,0,90,90,90},{65,120,99,21,0,90,90,90},{49,108,127,29,0,90,90,90},{35,96,147,29,16,90,90,90}},
  {{10,70,167,38,79,90,90,90},{5,58,154,58,129,90,90,90},{3,45,141,72,173,90,90,90},{8,34,108,87,179,90,90,90},{18,35,75,110,179,90,90,90},{30,71,51,128,160,90,90,90},{40,92,24,143,131,90,90,90},{53,101,15,155,89,90,90,90},{67,120,12,172,51,90,90,90},{82,144,10,180,28,90,90,90},{100,164,26,180,11,90,90,90},{118,179,49,180,6,90,90,90}},
  {{144,99,125,81,50,90,90,90},{142,97,127,82,50,90,90,90},{139,89,129,79,51,90,90,90},{133,76,131,75,55,90,90,90},{124,72,143,91,67,90,90,90},{124,77,145,98,96,90,90,90},{126,88,142,104,127,90,90,90},{135,99,132,96,147,90,90,90},{140,105,127,92,164,90,90,90},{141,109,125,93,172,90,90,90},{140,113,124,97,172,90,90,90},{134,114,126,106,140,90,90,90}},
  {{128,109,130,112,74,90,90,90},{124,103,136,116,55,90,90,90},{119,103,137,121,45,90,90,90},{117,105,136,125,45,90,90,90},{110,112,131,132,65,90,90,90},{113,117,125,129,116,90,90,90},{120,119,123,123,159,90,90,90},{129,112,128,112,180,90,90,90},{133,106,131,104,180,90,90,90},{131,92,137,98,180,90,90,90},{127,82,142,97,180,90,90,90},{121,71,147,97,167,90,90,90}},
  {{123,66,141,83,67,90,90,90},{131,73,132,74,20,90,90,90},{137,81,128,73,6,90,90,90},{140,88,128,76,5,90,90,90},{137,93,132,87,18,90,90,90},{135,94,134,92,52,90,90,90},{130,94,137,101,115,90,90,90},{123,98,140,115,166,90,90,90},{120,107,134,122,178,90,90,90},{121,117,126,121,178,90,90,90},{130,124,119,112,178,90,90,90},{136,120,121,104,178,90,90,90}},
  {{134,110,128,103,151,90,90,90},{130,106,132,108,98,90,90,90},{128,112,129,113,45,90,90,90},{127,125,117,115,22,90,90,90},{130,130,113,113,0,90,90,90},{137,131,111,105,0,90,90,90},{149,133,108,92,0,90,90,90},{152,135,105,88,11,90,90,90},{156,144,98,86,84,90,90,90},{153,149,94,89,131,90,90,90},{150,152,90,93,164,90,90,90},{140,154,87,101,178,90,90,90}},
  {{129,151,88,109,178,90,90,90},{120,150,85,115,178,90,90,90},{114,151,80,117,166,90,90,90},{110,153,73,116,114,90,90,90},{110,154,70,115,82,90,90,90},{106,156,63,113,41,90,90,90},{100,155,56,111,5,90,90,90},{91,149,54,113,4,90,90,90},{82,143,56,117,1,90,90,90},{77,139,58,119,8,90,90,90},{70,132,59,121,42,90,90,90},{62,126,57,121,95,90,90,90}},
  {{58,122,53,117,154,90,90,90},{58,121,48,111,168,90,90,90},{62,125,44,107,169,90,90,90},{72,135,42,106,162,90,90,90},{76,140,45,109,136,90,90,90},{85,146,53,113,102,90,90,90},{98,151,64,117,66,90,90,90},{107,150,76,119,46,90,90,90},{112,149,81,119,45,90,90,90},{116,145,91,119,48,90,90,90},{119,141,98,120,65,90,90,90},{120,137,104,120,103,90,90,90}},
  {{122,130,112,120,156,90,90,90},{121,127,115,121,172,90,90,90},{122,122,120,121,179,90,90,90},{123,122,121,120,178,90,90,90},{126,116,126,116,159,90,90,90},{130,113,127,111,108,90,90,90},{133,116,124,108,72,90,90,90},{135,122,120,106,43,90,90,90},{137,126,115,105,32,90,90,90},{134,131,111,108,29,90,90,90},{132,131,112,111,38,90,90,90},{130,126,117,113,63,90,90,90}}
};
const PROGMEM uint8_t idleTrans[NUM_IDLE_SEGMENTS][12] = {
  {1,66,4,51,2,45,3,43,5,25,7,22},
  {3,57,2,50,7,39,8,39,4,35,5,32},
  {5,53,8,49,3,41,6,41,4,36,0,32},
  {5,55,8,48,4,40,6,40,2,35,7,33},
  {5,51,8,51,6,48,0,35,3,33,7,33},
  {6,61,8,52,7,40,0,38,3,33,2,28},
  {7,55,3,43,8,43,5,39,2,37,4,35},
  {3,47,8,46,5,44,2,39,6,39,4,36},
  {3,57,2,50,4,45,5,40,6,31,7,30},
};

// ACTIVE state: 6 segments
#define NUM_ACTIVE_SEGMENTS 6
const PROGMEM uint8_t activeSeg[NUM_ACTIVE_SEGMENTS][SAMPLES_PER_SEGMENT][NUM_SERVOS] = {
  {{8,178,163,60,179,90,90,90},{8,172,158,71,166,90,90,90},{8,155,143,88,131,90,90,90},{8,134,119,109,66,90,90,90},{9,96,85,122,20,90,90,90},{26,73,54,137,3,90,90,90},{50,36,29,146,44,90,90,90},{100,21,8,156,84,90,90,90},{134,16,0,165,136,90,90,90},{173,15,0,166,168,90,90,90},{178,39,0,159,179,90,90,90},{179,69,0,140,177,90,90,90}},
  {{176,102,65,98,131,90,90,90},{164,126,107,69,71,90,90,90},{150,146,128,48,31,90,90,90},{130,168,152,31,14,90,90,90},{96,180,166,25,10,90,90,90},{62,180,168,44,56,90,90,90},{33,155,130,78,118,90,90,90},{4,116,82,87,177,90,90,90},{0,103,50,101,180,90,90,90},{6,78,16,117,180,90,90,90},{26,48,0,132,169,90,90,90},{50,28,0,153,120,90,90,90}},
  {{91,21,0,180,24,90,90,90},{116,64,9,180,11,90,90,90},{141,95,23,159,0,90,90,90},{157,109,43,138,16,90,90,90},{172,126,73,127,94,90,90,90},{173,155,86,107,130,90,90,90},{165,173,103,86,161,90,90,90},{146,177,124,67,172,90,90,90},{123,163,127,51,174,90,90,90},{98,128,120,35,138,90,90,90},{67,105,86,28,103,90,90,90},{29,80,48,25,39,90,90,90}},
  {{172,53,87,41,82,90,90,90},{172,53,87,41,116,90,90,90},{171,44,95,49,129,90,90,90},{166,47,105,49,99,90,90,90},{155,57,98,40,76,90,90,90},{133,52,84,41,137,90,90,90},{118,45,83,49,148,90,90,90},{95,43,94,51,85,90,90,90},{68,56,118,50,76,90,90,90},{50,68,110,41,140,90,90,90},{26,66,86,30,142,90,90,90},{11,56,70,38,75,90,90,90}},
  {{52,44,79,52,139,90,90,90},{163,47,100,48,144,90,90,90},{163,70,115,44,78,90,90,90},{128,81,108,36,84,90,90,90},{111,81,83,20,166,90,90,90},{94,73,58,21,166,90,90,90},{80,68,45,36,76,90,90,90},{64,55,56,51,112,90,90,90},{52,50,81,43,158,90,90,90},{31,70,94,31,78,90,90,90},{18,76,84,23,63,90,90,90},{16,70,61,24,162,90,90,90}},
  {{15,61,59,37,102,90,90,90},{155,54,67,43,72,90,90,90},{150,52,81,41,128,90,90,90},{45,59,100,39,146,90,90,90},{82,76,106,36,86,90,90,90},{169,89,96,25,76,90,90,90},{168,83,79,17,138,90,90,90},{151,71,72,23,138,90,90,90},{128,58,75,35,76,90,90,90},{105,54,89,40,109,90,90,90},{92,63,107,41,123,90,90,90},{85,99,107,34,78,90,90,90}}
};
const PROGMEM uint8_t activeTrans[NUM_ACTIVE_SEGMENTS][12] = {
  {1,72,3,49,4,44,2,39,5,36,0,13},
  {2,64,4,57,5,52,3,35,0,33,1,11},
  {5,74,4,58,3,45,1,33,0,31,2,11},
  {5,81,4,66,0,32,1,32,2,32,3,10},
  {5,80,0,48,3,41,1,38,2,34,4,12},
  {4,62,3,60,1,51,0,40,2,30,5,10},
};

// SLEEP state: 10 segments
#define NUM_SLEEP_SEGMENTS 10
const PROGMEM uint8_t sleepSeg[NUM_SLEEP_SEGMENTS][SAMPLES_PER_SEGMENT][NUM_SERVOS] = {
  {{90,90,90,90,38,90,90,90},{90,90,90,90,38,90,90,90},{90,90,90,90,38,90,90,90},{90,90,90,90,42,90,90,90},{90,90,90,90,57,90,90,90},{90,90,90,90,74,90,90,90},{90,90,90,90,101,90,90,90},{90,90,90,90,125,90,90,90},{90,90,90,90,149,90,90,90},{90,90,90,90,160,90,90,90},{90,90,90,90,166,90,90,90},{90,90,90,90,170,90,90,90}},
  {{90,90,90,90,169,90,90,90},{90,90,90,90,153,90,90,90},{90,90,90,90,122,90,90,90},{90,90,90,90,75,90,90,90},{90,90,90,90,21,90,90,90},{90,90,90,90,0,90,90,90},{90,90,90,90,0,90,90,90},{90,90,90,90,0,90,90,90},{90,90,90,90,0,90,90,90},{90,90,90,90,0,90,90,90},{90,90,90,90,0,90,90,90},{90,90,90,90,17,90,90,90}},
  {{90,90,90,90,58,90,90,90},{90,90,90,90,86,90,90,90},{90,90,90,90,120,90,90,90},{90,90,90,90,141,90,90,90},{90,90,90,90,159,90,90,90},{90,90,90,90,162,90,90,90},{90,90,90,90,166,90,90,90},{90,90,90,90,166,90,90,90},{90,90,90,90,166,90,90,90},{90,90,90,90,159,90,90,90},{90,90,90,90,141,90,90,90},{90,90,90,90,112,90,90,90}},
  {{90,90,90,90,70,90,90,90},{90,90,90,90,47,90,90,90},{90,90,90,90,34,90,90,90},{90,90,90,90,18,90,90,90},{90,90,90,90,9,90,90,90},{90,90,90,90,8,90,90,90},{90,90,90,90,8,90,90,90},{90,90,90,90,10,90,90,90},{90,90,90,90,19,90,90,90},{90,90,90,90,45,90,90,90},{90,90,90,90,73,90,90,90},{90,90,90,90,106,90,90,90}},
  {{90,90,90,90,135,90,90,90},{90,90,90,90,149,90,90,90},{90,90,90,90,157,90,90,90},{90,90,90,90,163,90,90,90},{90,90,90,90,166,90,90,90},{90,90,90,90,166,90,90,90},{90,90,90,90,155,90,90,90},{90,90,90,90,114,90,90,90},{90,90,90,90,88,90,90,90},{90,90,90,90,46,90,90,90},{90,90,90,90,12,90,90,90},{90,90,90,90,6,90,90,90}},
  {{90,90,90,90,4,90,90,90},{90,90,90,90,4,90,90,90},{90,90,90,90,5,90,90,90},{90,90,90,90,15,90,90,90},{90,90,90,90,38,90,90,90},{90,90,90,90,64,90,90,90},{90,90,90,90,88,90,90,90},{90,90,90,90,122,90,90,90},{90,90,90,90,156,90,90,90},{90,90,90,90,166,90,90,90},{90,90,90,90,177,90,90,90},{90,90,90,90,179,90,90,90}},
  {{90,90,90,90,179,90,90,90},{90,90,90,90,169,90,90,90},{90,90,90,90,153,90,90,90},{90,90,90,90,126,90,90,90},{90,90,90,90,86,90,90,90},{90,90,90,90,45,90,90,90},{90,90,90,90,29,90,90,90},{90,90,90,90,19,90,90,90},{90,90,90,90,14,90,90,90},{90,90,90,90,10,90,90,90},{90,90,90,90,9,90,90,90},{90,90,90,90,9,90,90,90}},
  {{102,132,104,133,102,90,90,90},{102,132,104,133,102,90,90,90},{102,132,104,133,102,90,90,90},{102,132,104,133,102,90,90,90},{102,132,104,133,102,90,90,90},{102,132,104,133,102,90,90,90},{102,132,104,133,102,90,90,90},{102,132,104,133,102,90,90,90},{100,132,102,134,100,90,90,90},{95,130,103,137,95,90,90,90},{97,127,108,138,97,90,90,90},{98,127,109,138,98,90,90,90}},
  {{104,128,110,134,104,90,90,90},{107,128,111,132,107,90,90,90},{108,127,113,131,108,90,90,90},{108,127,113,131,108,90,90,90},{111,125,116,130,111,90,90,90},{111,125,116,130,111,90,90,90},{105,119,122,136,105,90,90,90},{102,122,118,138,102,90,90,90},{101,125,114,137,101,90,90,90},{107,129,110,132,107,90,90,90},{110,129,111,130,110,90,90,90},{112,126,115,129,112,90,90,90}},
  {{109,121,120,132,109,90,90,90},{108,121,120,133,108,90,90,90},{107,122,119,134,107,90,90,90},{106,123,118,134,106,90,90,90},{108,123,118,133,108,90,90,90},{112,124,118,130,112,90,90,90},{114,122,120,128,114,90,90,90},{116,119,124,127,116,90,90,90},{116,116,126,127,116,90,90,90},{116,115,128,127,116,90,90,90},{114,114,129,129,114,90,90,90},{111,116,127,131,111,90,90,90}}
};
const PROGMEM uint8_t sleepTrans[NUM_SLEEP_SEGMENTS][12] = {
  {1,53,6,52,4,46,7,34,8,34,9,34},
  {5,51,0,50,2,45,3,42,7,32,8,32},
  {4,48,3,44,1,41,7,40,8,40,9,40},
  {4,48,2,43,1,40,7,40,8,40,9,40},
  {5,57,0,50,2,44,3,42,7,30,8,30},
  {6,54,1,53,4,45,7,33,8,33,9,33},
  {5,55,0,50,2,45,3,42,7,31,8,29},
  {8,53,9,50,3,39,2,38,4,38,0,35},
  {9,53,7,50,4,39,3,38,1,36,2,36},
  {8,51,7,49,4,40,3,38,1,37,2,37},
};

// ==================== STATE MACHINE ====================
enum State { STATE_IDLE, STATE_ACTIVE, STATE_SLEEP };
const char* stateNames[] = {"IDLE", "ACTIVE", "SLEEP"};

State currentState = STATE_IDLE;
State previousState = STATE_IDLE;

unsigned long lastMotionTime = 0;
unsigned long stateStartTime = 0;
unsigned long transitionStartTime = 0;
float stateBlendFactor = 1.0;

// Markov segment tracking
int currentSegment = 0;
unsigned long segmentStartTime = 0;
int prevSegmentEndPos[NUM_SERVOS];
bool needsBlend = false;

// Servo positions
int currentPositions[NUM_SERVOS];
int transitionFromPositions[NUM_SERVOS];
Servo servos[NUM_SERVOS];

// ==================== HELPER FUNCTIONS ====================
int applyServoLimits(int position, int servoIdx) {
  // Map 0-180 stored value to MIN_ANGLE-MAX_ANGLE output (matches listener behavior)
  int pos = map(position, 0, 180, SERVO_MIN, SERVO_MAX);
  pos = constrain(pos, SERVO_MIN, SERVO_MAX);
  
  // Apply reversal WITHIN the output range (matches listener: SERVO_MAX - pos)
  if (servoReversed[servoIdx]) {
    pos = SERVO_MAX - pos;
  }
  return pos;
}

float smootherstep(float t) {
  return t * t * t * (t * (t * 6.0 - 15.0) + 10.0);
}

int getNumSegments(State state) {
  switch (state) {
    case STATE_IDLE: return NUM_IDLE_SEGMENTS;
    case STATE_ACTIVE: return NUM_ACTIVE_SEGMENTS;
    case STATE_SLEEP: return NUM_SLEEP_SEGMENTS;
    default: return 0;
  }
}

// Pick next segment using sparse transition table (top-K most likely transitions)
int pickNextSegment(State state, int currentSeg) {
  int numSegs = getNumSegments(state);
  if (numSegs <= 1) return 0;
  
  // Get sparse transitions for this segment
  uint8_t transData[TOP_K_TRANS * 2];
  switch (state) {
    case STATE_IDLE: for(int i=0;i<TOP_K_TRANS*2;i++) transData[i]=pgm_read_byte(&idleTrans[currentSeg][i]); break;
    case STATE_ACTIVE: for(int i=0;i<TOP_K_TRANS*2;i++) transData[i]=pgm_read_byte(&activeTrans[currentSeg][i]); break;
    case STATE_SLEEP: for(int i=0;i<TOP_K_TRANS*2;i++) transData[i]=pgm_read_byte(&sleepTrans[currentSeg][i]); break;
    default: return random(numSegs);
  }
  
  // Calculate total probability and pick
  int total = 0;
  for (int i = 0; i < TOP_K_TRANS; i++) {
    total += transData[i*2 + 1];
  }
  if (total == 0) return random(numSegs);
  
  int target = random(total);
  int cumulative = 0;
  for (int i = 0; i < TOP_K_TRANS; i++) {
    cumulative += transData[i*2 + 1];
    if (target < cumulative) {
      return transData[i*2];  // Return the segment index
    }
  }
  return transData[0];  // Fallback to first option
}

void getSegmentPosition(State state, int segIdx, int sampleIdx, int* positions) {
  for (int i = 0; i < NUM_SERVOS; i++) {
    uint8_t pos;
    switch (state) {
      case STATE_IDLE: pos = pgm_read_byte(&idleSeg[segIdx][sampleIdx][i]); break;
      case STATE_ACTIVE: pos = pgm_read_byte(&activeSeg[segIdx][sampleIdx][i]); break;
      case STATE_SLEEP: pos = pgm_read_byte(&sleepSeg[segIdx][sampleIdx][i]); break;
      default: pos = 90; break;
    }
    positions[i] = pos;
  }
}

// ==================== MAIN FUNCTIONS ====================
void triggerMotion() {
  Serial.println("!!! PIR MOTION DETECTED !!!");
  lastMotionTime = millis();
  if (currentState == STATE_SLEEP) {
    startStateTransition(STATE_ACTIVE);
  } else if (currentState == STATE_IDLE) {
    startStateTransition(STATE_ACTIVE);
  }
}

void startStateTransition(State newState) {
  Serial.print(">>> STATE CHANGE: ");
  Serial.print(stateNames[currentState]);
  Serial.print(" -> ");
  Serial.println(stateNames[newState]);
  
  for (int i = 0; i < NUM_SERVOS; i++) {
    transitionFromPositions[i] = currentPositions[i];
  }
  previousState = currentState;
  currentState = newState;
  transitionStartTime = millis();
  stateBlendFactor = 0;
  
  // Reset segment to random start
  currentSegment = random(getNumSegments(newState));
  segmentStartTime = millis();
  needsBlend = false;
}

void checkStateTransitions() {
  unsigned long now = millis();
  unsigned long timeSinceMotion = now - lastMotionTime;
  
  switch (currentState) {
    case STATE_ACTIVE:
      if (timeSinceMotion >= ACTIVE_DURATION) {
        startStateTransition(STATE_IDLE);
      }
      break;
    case STATE_IDLE:
      if (timeSinceMotion >= SLEEP_TIMEOUT) {
        startStateTransition(STATE_SLEEP);
      }
      break;
    case STATE_SLEEP:
      break;
  }
  
  // Update state blend factor
  if (millis() - transitionStartTime < STATE_BLEND_TIME) {
    stateBlendFactor = smootherstep((float)(millis() - transitionStartTime) / STATE_BLEND_TIME);
  } else {
    stateBlendFactor = 1.0;
  }
}

void updateServos() {
  unsigned long now = millis();
  int numSegs = getNumSegments(currentState);
  if (numSegs == 0) return;
  
  // Check if segment is done
  if (now - segmentStartTime >= SEGMENT_DURATION) {
    // Save end positions for blending
    int sampleIdx = SAMPLES_PER_SEGMENT - 1;
    getSegmentPosition(currentState, currentSegment, sampleIdx, prevSegmentEndPos);
    
    // Pick next segment via Markov
    currentSegment = pickNextSegment(currentState, currentSegment);
    segmentStartTime = now;
    needsBlend = true;
  }
  
  // Calculate position within segment WITH INTERPOLATION
  float progress = (float)(now - segmentStartTime) / SEGMENT_DURATION;
  float sampleFloat = progress * (SAMPLES_PER_SEGMENT - 1);  // Range 0 to N-1
  int sampleIdx = (int)sampleFloat;
  float interpFactor = sampleFloat - sampleIdx;  // Fractional part
  sampleIdx = constrain(sampleIdx, 0, SAMPLES_PER_SEGMENT - 2);  // Leave room for next sample
  
  // Get current and next sample for interpolation
  int posA[NUM_SERVOS], posB[NUM_SERVOS];
  getSegmentPosition(currentState, currentSegment, sampleIdx, posA);
  getSegmentPosition(currentState, currentSegment, sampleIdx + 1, posB);
  
  // Interpolate between samples for smooth motion
  int targetPositions[NUM_SERVOS];
  for (int i = 0; i < NUM_SERVOS; i++) {
    targetPositions[i] = posA[i] + (int)((posB[i] - posA[i]) * interpFactor);
  }
  
  // Blend from previous segment end if needed
  if (needsBlend && (now - segmentStartTime) < SEGMENT_BLEND_TIME) {
    float blendFactor = smootherstep((float)(now - segmentStartTime) / SEGMENT_BLEND_TIME);
    for (int i = 0; i < NUM_SERVOS; i++) {
      targetPositions[i] = prevSegmentEndPos[i] + (int)((targetPositions[i] - prevSegmentEndPos[i]) * blendFactor);
    }
  } else {
    needsBlend = false;
  }
  
  // Apply state transition blend
  if (stateBlendFactor < 1.0) {
    for (int i = 0; i < NUM_SERVOS; i++) {
      currentPositions[i] = transitionFromPositions[i] + (int)((targetPositions[i] - transitionFromPositions[i]) * stateBlendFactor);
    }
  } else {
    for (int i = 0; i < NUM_SERVOS; i++) {
      currentPositions[i] = targetPositions[i];
    }
  }
  
  // Apply organic wobble and write to servos
  float t = millis() / 1000.0;
  for (int i = 0; i < NUM_SERVOS; i++) {
    int finalPos = currentPositions[i];
    
    if (WOBBLE_AMOUNT > 0) {
      float phase = phaseOffsets[i];
      float breath = sin(t * 0.9 + phase) * 0.5;
      float drift = sin(t * 2.5 + phase * 1.3) * 0.3;
      float tremor = sin(t * 7.5 + phase * 2.1) * 0.2;
      finalPos += (int)((breath + drift + tremor) * WOBBLE_AMOUNT);
    }
    
    servos[i].write(applyServoLimits(finalPos, i));
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("PIR Markov State Machine Starting...");
  
  randomSeed(analogRead(0));
  pinMode(PIR_PIN, INPUT);
  
  for (int i = 0; i < NUM_SERVOS; i++) {
    phaseOffsets[i] = random(0, 628) / 100.0;
    servos[i].attach(servoPins[i]);
    servos[i].write(90);
    currentPositions[i] = 90;
  }
  
  lastMotionTime = millis();
  stateStartTime = millis();
  transitionStartTime = millis();
  segmentStartTime = millis();
  currentSegment = random(getNumSegments(STATE_IDLE));
  
  Serial.println("Ready - Markov segment mode active");
  Serial.print("Segment duration: "); Serial.print(SEGMENT_DURATION); Serial.println("ms");
  Serial.print("State blend time: "); Serial.print(STATE_BLEND_TIME); Serial.println("ms");
}

unsigned long lastDebugTime = 0;

void loop() {
  bool pirHigh = digitalRead(PIR_PIN) == HIGH;
  if (pirHigh) {
    triggerMotion();
  }
  
  checkStateTransitions();
  updateServos();
  
  // Debug output every 2 seconds
  if (millis() - lastDebugTime > 2000) {
    Serial.print("State:"); Serial.print(stateNames[currentState]);
    Serial.print(" Seg:"); Serial.print(currentSegment);
    Serial.print("/"); Serial.print(getNumSegments(currentState));
    Serial.print(" Blend:"); Serial.print(stateBlendFactor);
    Serial.print(" PIR:"); Serial.println(pirHigh ? "HIGH" : "LOW");
    lastDebugTime = millis();
  }
  
  delay(UPDATE_INTERVAL);
}
