// PIR Markov State Machine - Auto-generated
// Generated: 2026-04-07 18:49:53
// Mode: Markov Segments (learned transitions between movement chunks)
//
// Segment length: 3.0s, Chaos: 30%, Blend: 100ms
// idle: 9 segments, active: 5 segments, sleep: 19 segments
//

#include <Servo.h>

// ==================== CONFIGURATION ====================
#define PIR_PIN 3
#define NUM_SERVOS 8
#define UPDATE_INTERVAL 20
#define SAMPLES_PER_SEGMENT 12
#define TOP_K_TRANS 6

const int servoPins[NUM_SERVOS] = {12, 11, 10, 9, 8, 7, 6, 5};
const int SERVO_MIN = 0;
const int SERVO_MAX = 45;

// Check if a pin should be reversed (matches listener behavior)
bool isReversedPin(int pin) {
  return (pin == 9 || pin == 10);
}

// Timing
const unsigned long ACTIVE_DURATION = 10000UL;
const unsigned long SLEEP_TIMEOUT = 120000UL;
const unsigned long STATE_BLEND_TIME = 5000UL;
// const unsigned long SEGMENT_DURATION = 3000UL;  // Now variable per segment
const unsigned long SEGMENT_BLEND_TIME = 100UL;

// Organic wobble
const float WOBBLE_AMOUNT = 1.5;
float phaseOffsets[NUM_SERVOS];

// ==================== SEGMENT DATA ====================

// IDLE state: 9 segments
#define NUM_IDLE_SEGMENTS 9
const PROGMEM unsigned int idleDurations[NUM_IDLE_SEGMENTS] = {
  2752, 2169, 2250, 2023, 2390, 2848, 1904, 2296, 1917
};
const PROGMEM uint8_t idleSeg[NUM_IDLE_SEGMENTS][SAMPLES_PER_SEGMENT][NUM_SERVOS] = {
  {{151,151,151,151,151,52,93,86},{148,148,148,148,148,52,93,89},{139,139,139,139,139,52,94,96},{128,128,128,128,128,52,96,101},{123,123,123,123,123,52,98,101},{125,125,125,125,125,56,98,95},{139,139,139,139,139,61,98,86},{153,153,153,153,153,62,97,80},{165,165,165,165,165,62,94,76},{179,179,179,179,179,61,94,86},{168,168,168,168,168,60,94,90},{156,156,156,156,156,58,97,97}},
  {{138,138,138,138,138,53,97,105},{139,139,139,139,139,51,95,112},{149,149,149,149,149,51,94,114},{160,160,160,160,160,55,94,107},{164,164,164,164,164,57,94,100},{153,153,153,153,153,60,93,92},{139,139,139,139,139,61,92,88},{122,122,122,122,122,61,92,84},{109,109,109,109,109,61,92,83},{105,105,105,105,105,59,92,88},{116,116,116,116,116,57,92,94},{132,132,132,132,132,56,92,97}},
  {{150,150,150,150,150,57,93,91},{155,155,155,155,155,60,96,86},{155,155,155,155,155,62,98,80},{141,141,141,141,141,65,100,76},{126,126,126,126,126,68,101,75},{119,119,119,119,119,70,101,82},{117,117,117,117,117,72,103,90},{123,123,123,123,123,73,103,91},{134,134,134,134,134,74,102,84},{144,144,144,144,144,72,99,79},{149,149,149,149,149,68,97,73},{153,153,153,153,153,64,94,66}},
  {{137,137,137,137,137,62,94,63},{119,119,119,119,119,62,94,58},{106,106,106,106,106,62,97,58},{104,104,104,104,104,64,99,70},{113,113,113,113,113,67,101,78},{125,125,125,125,125,69,103,84},{141,141,141,141,141,73,103,90},{149,149,149,149,149,74,101,95},{153,153,153,153,153,74,97,98},{143,143,143,143,143,73,96,99},{130,130,130,130,130,70,92,101},{123,123,123,123,123,68,92,101}},
  {{149,149,149,149,149,56,87,112},{149,149,149,149,149,60,87,112},{146,146,146,146,146,62,87,112},{142,142,142,142,142,65,87,108},{136,136,136,136,136,68,90,104},{132,132,132,132,132,70,94,99},{125,125,125,125,125,70,97,94},{116,116,116,116,116,67,99,87},{107,107,107,107,107,62,100,80},{97,97,97,97,97,60,101,69},{87,87,87,87,87,60,104,60},{77,77,77,77,77,60,106,50}},
  {{59,59,59,59,59,62,109,42},{50,50,50,50,50,64,112,37},{38,38,38,38,38,67,115,30},{30,30,30,30,30,69,116,27},{22,22,22,22,22,72,116,22},{15,15,15,15,15,74,116,18},{11,11,11,11,11,74,112,13},{6,6,6,6,6,70,111,11},{5,5,5,5,5,68,108,11},{5,5,5,5,5,67,104,11},{12,12,12,12,12,66,103,11},{24,24,24,24,24,64,100,11}},
  {{36,36,36,36,36,62,98,20},{39,39,39,39,39,64,98,24},{33,33,33,33,33,66,98,28},{26,26,26,26,26,68,100,28},{20,20,20,20,20,72,102,28},{17,17,17,17,17,73,105,24},{21,21,21,21,21,75,108,20},{32,32,32,32,32,76,105,15},{39,39,39,39,39,79,100,15},{46,46,46,46,46,79,96,19},{52,52,52,52,52,78,92,21},{55,55,55,55,55,75,92,26}},
  {{45,45,45,45,45,71,95,33},{35,35,35,35,35,68,99,37},{25,25,25,25,25,65,100,39},{19,19,19,19,19,61,101,37},{12,12,12,12,12,60,103,32},{6,6,6,6,6,56,105,23},{3,3,3,3,3,55,105,23},{3,3,3,3,3,55,106,19},{2,2,2,2,2,55,101,18},{2,2,2,2,2,55,100,20},{5,5,5,5,5,55,98,25},{5,5,5,5,5,55,97,30}},
  {{10,10,10,10,10,55,95,34},{23,23,23,23,23,55,94,38},{27,27,27,27,27,55,94,41},{31,31,31,31,31,55,94,39},{34,34,34,34,34,55,96,35},{28,28,28,28,28,55,98,30},{20,20,20,20,20,55,100,26},{14,14,14,14,14,55,102,22},{1,1,1,1,1,55,102,20},{0,0,0,0,0,55,101,18},{0,0,0,0,0,55,98,18},{0,0,0,0,0,55,96,19}}
};
const PROGMEM uint8_t idleTrans[NUM_IDLE_SEGMENTS][12] = {
  {2,67,4,65,1,59,3,54,0,5,5,4},
  {3,61,2,59,4,59,0,58,5,12,1,5},
  {0,67,3,63,4,58,1,57,2,5,5,4},
  {1,64,2,54,4,54,0,53,5,19,7,7},
  {5,70,7,57,6,47,3,31,1,25,8,23},
  {6,85,8,78,7,73,5,6,0,5,1,5},
  {7,91,5,88,8,52,3,9,6,7,0,5},
  {8,109,6,76,5,47,7,7,0,6,1,6},
  {6,94,7,77,5,55,8,10,0,8,1,8},
};

// ACTIVE state: 5 segments
#define NUM_ACTIVE_SEGMENTS 5
const PROGMEM unsigned int activeDurations[NUM_ACTIVE_SEGMENTS] = {
  1920, 2818, 2066, 2065, 2360
};
const PROGMEM uint8_t activeSeg[NUM_ACTIVE_SEGMENTS][SAMPLES_PER_SEGMENT][NUM_SERVOS] = {
  {{90,146,90,90,90,68,90,59},{90,123,90,90,90,76,90,65},{90,94,90,90,90,80,90,72},{90,131,90,90,90,77,90,69},{90,161,90,90,90,72,90,62},{90,118,90,90,90,70,90,55},{90,96,90,90,90,76,90,56},{90,127,90,90,90,79,90,71},{90,156,90,90,90,76,90,68},{90,164,90,90,90,72,90,55},{90,116,90,90,90,69,90,49},{90,80,90,90,90,76,90,52}},
  {{90,127,90,90,90,79,90,69},{90,153,90,90,90,75,90,69},{90,122,90,90,90,70,90,61},{90,83,90,90,90,67,90,55},{90,88,90,90,90,74,90,60},{90,137,90,90,90,82,90,70},{90,163,90,90,90,84,90,72},{90,126,90,90,90,77,90,67},{90,74,90,90,90,70,90,76},{90,51,90,90,90,74,90,86},{90,43,90,90,90,80,90,90},{90,40,90,90,90,85,90,81}},
  {{79,79,79,79,79,68,82,12},{81,81,81,81,81,73,86,12},{75,75,75,75,75,75,94,12},{53,53,53,53,53,74,100,12},{42,42,42,42,42,69,98,18},{35,35,35,35,35,68,91,23},{30,30,30,30,30,64,86,30},{29,29,29,29,29,67,82,43},{28,28,28,28,28,73,80,55},{27,27,27,27,27,74,73,78},{32,32,32,32,32,78,67,94},{49,49,49,49,49,74,65,104}},
  {{97,97,97,97,97,68,62,79},{153,153,153,153,153,63,60,67},{168,168,168,168,168,60,63,49},{170,170,170,170,170,56,69,37},{158,158,158,158,158,51,74,33},{128,128,128,128,128,50,77,50},{90,90,90,90,90,52,72,65},{53,53,53,53,53,57,69,83},{22,22,22,22,22,60,65,65},{15,15,15,15,15,66,65,43},{23,23,23,23,23,69,68,28},{49,49,49,49,49,74,73,27}},
  {{107,107,107,107,107,70,78,52},{131,131,131,131,131,65,77,79},{147,147,147,147,147,60,66,99},{153,153,153,153,153,55,64,94},{136,136,136,136,136,52,61,80},{97,97,97,97,97,52,68,60},{42,42,42,42,42,57,76,34},{11,11,11,11,11,61,79,21},{6,6,6,6,6,64,79,21},{10,10,10,10,10,68,70,46},{43,43,43,43,43,69,65,57},{69,69,69,69,69,69,64,69}}
};
const PROGMEM uint8_t activeTrans[NUM_ACTIVE_SEGMENTS][12] = {
  {2,62,3,62,4,62,1,61,0,5,0,0},
  {3,70,4,63,2,62,0,51,1,6,0,0},
  {3,72,1,65,0,55,4,51,2,9,0,0},
  {2,87,1,57,0,52,4,50,3,8,0,0},
  {2,66,3,66,1,61,0,55,4,6,0,0},
};

// SLEEP state: 19 segments
#define NUM_SLEEP_SEGMENTS 19
const PROGMEM unsigned int sleepDurations[NUM_SLEEP_SEGMENTS] = {
  2666, 1532, 2106, 1826, 1526, 1875, 2117, 2548, 1842, 2569, 1978, 1875, 1613, 1850, 2594, 1888, 2247, 2323, 2129
};
const PROGMEM uint8_t sleepSeg[NUM_SLEEP_SEGMENTS][SAMPLES_PER_SEGMENT][NUM_SERVOS] = {
  {{151,155,158,159,158,26,56,70},{151,155,158,159,158,28,56,70},{151,155,158,159,158,28,56,67},{151,155,158,159,158,28,58,63},{150,155,157,158,157,28,59,60},{149,154,157,158,158,28,59,59},{146,152,156,158,158,28,59,56},{146,152,156,158,158,28,59,56},{146,152,156,158,158,30,59,58},{141,148,153,156,158,31,59,61},{140,147,152,156,157,32,59,64},{136,143,149,154,156,32,59,65}},
  {{132,140,147,152,155,34,59,66},{129,138,145,150,154,35,58,67},{124,133,141,147,152,40,58,66},{124,133,141,147,152,44,57,63},{124,133,141,147,152,41,57,58},{119,129,137,144,150,40,57,56},{119,129,137,144,150,40,57,55},{119,129,137,144,150,41,57,52},{109,120,129,137,144,42,57,51},{106,116,126,135,142,42,56,50},{101,111,122,131,139,44,56,49},{90,101,112,122,131,44,56,47}},
  {{71,82,94,105,115,44,55,47},{63,74,85,96,107,46,55,47},{56,67,78,89,100,46,54,46},{51,62,73,84,95,47,54,45},{48,59,69,81,92,47,54,44},{41,51,61,72,83,48,54,44},{39,48,58,69,80,48,52,43},{34,42,52,62,73,48,52,43},{30,38,47,57,68,48,52,43},{26,33,41,51,61,49,52,43},{24,31,39,48,58,50,51,46},{24,31,39,48,58,51,51,48}},
  {{23,30,37,46,56,51,50,52},{23,29,37,46,56,51,50,54},{20,25,32,40,50,51,50,57},{18,23,29,36,45,29,50,59},{16,20,26,33,41,29,50,61},{14,17,21,26,34,28,50,61},{14,15,18,23,29,28,50,61},{14,14,17,21,27,28,51,61},{15,14,15,18,23,29,52,58},{19,16,14,15,17,29,52,57},{30,24,19,16,15,31,54,55},{42,33,26,21,17,31,55,54}},
  {{46,37,30,24,19,33,55,50},{49,40,32,25,20,33,55,50},{52,42,34,27,21,34,55,49},{63,53,44,35,28,35,55,47},{77,66,56,46,37,35,55,47},{86,74,63,53,44,35,55,45},{92,81,69,59,49,37,55,43},{97,86,75,64,53,38,55,43},{106,95,83,72,61,40,56,43},{112,102,90,79,68,40,56,45},{119,108,97,86,75,41,57,47},{128,118,108,97,85,41,57,49}},
  {{137,129,119,109,98,43,58,50},{140,131,122,112,101,43,59,54},{143,136,127,117,106,44,59,55},{144,137,128,118,108,47,59,57},{145,138,130,120,110,47,59,58},{147,141,132,123,113,47,59,59},{147,141,132,123,113,48,59,60},{147,141,132,123,113,50,59,61},{149,143,135,126,116,52,59,61},{152,147,140,132,122,53,59,60},{154,150,143,136,127,54,59,58},{157,154,148,142,134,55,59,56}},
  {{158,159,157,154,149,55,58,54},{153,157,158,158,156,56,57,51},{147,152,156,158,158,56,57,50},{141,147,153,156,158,56,57,48},{112,122,131,140,147,57,57,48},{89,100,111,121,131,57,57,47},{82,93,104,115,125,57,56,45},{68,79,90,101,112,57,56,43},{65,76,87,98,109,57,55,43},{58,69,80,91,102,57,55,42},{47,57,68,79,90,57,55,42},{39,48,58,69,80,56,55,49}},
  {{36,44,54,64,75,56,55,62},{28,35,43,53,63,56,55,75},{20,24,30,38,46,55,55,83},{16,17,20,25,31,55,54,79},{16,16,18,21,26,55,54,68},{18,16,16,18,22,54,54,61},{26,21,18,17,17,54,54,57},{31,25,20,18,16,53,52,54},{39,32,25,21,18,51,52,51},{48,39,31,25,21,51,52,49},{49,40,33,26,22,51,52,45},{64,53,44,36,29,51,52,38}},
  {{93,82,71,60,50,51,52,30},{107,96,85,73,63,51,51,25},{109,98,86,75,64,50,51,24},{112,101,90,79,68,50,51,30},{130,121,110,99,88,50,50,36},{140,131,121,110,99,49,50,41},{151,144,136,127,117,49,50,42},{155,149,141,133,123,48,49,42},{160,156,151,144,136,48,49,42},{162,159,155,149,141,48,49,43},{163,161,158,154,147,47,49,41},{162,163,161,158,154,47,49,36}},
  {{161,162,162,160,157,46,49,30},{159,162,162,161,159,46,49,29},{157,161,162,162,160,46,49,31},{154,158,161,162,162,46,50,36},{153,158,161,162,162,45,50,38},{153,158,161,162,162,45,50,40},{153,158,161,162,162,44,51,40},{153,158,161,162,162,44,52,40},{153,158,161,162,162,44,52,36},{153,158,161,162,162,43,54,31},{153,158,161,162,162,43,54,29},{153,158,161,162,162,42,54,24}},
  {{153,158,161,162,162,44,54,20},{153,158,161,162,162,44,54,26},{153,158,161,162,162,44,54,31},{153,158,161,162,162,44,54,36},{153,158,161,162,162,45,54,41},{153,158,161,162,161,46,54,38},{154,158,161,162,161,46,54,30},{155,159,161,162,161,49,54,26},{155,159,161,162,161,49,54,20},{155,159,161,162,160,49,54,18},{155,159,161,162,160,49,54,19},{155,159,161,162,160,50,54,22}},
  {{155,159,161,161,160,50,54,28},{156,159,161,161,160,50,54,31},{157,160,161,161,159,51,54,36},{159,161,161,160,157,50,54,38},{159,161,161,159,156,48,54,38},{160,161,161,159,155,47,54,31},{160,161,161,158,154,46,54,27},{161,161,160,157,153,46,54,24},{161,161,159,155,150,45,54,20},{161,160,158,153,147,45,53,15},{161,158,154,148,141,42,53,11},{159,155,150,143,135,42,53,10}},
  {{151,144,136,127,117,41,52,18},{147,139,131,121,110,40,52,23},{141,133,123,113,102,40,52,27},{135,126,115,105,93,40,52,33},{126,115,105,93,82,39,52,38},{116,105,94,82,71,39,52,47},{106,94,83,72,61,39,52,51},{94,82,71,60,51,39,52,60},{94,82,71,60,51,41,52,63},{94,82,71,60,51,42,55,65},{94,82,71,60,51,43,58,60},{109,98,87,76,65,44,58,49}},
  {{121,110,99,88,77,45,58,34},{129,119,108,97,85,45,57,33},{131,122,111,100,89,46,57,34},{131,122,111,100,89,47,56,41},{131,122,111,100,89,48,56,48},{131,122,111,100,89,50,56,57},{131,122,111,100,89,50,54,62},{123,112,101,90,79,52,53,64},{99,88,77,66,55,52,52,64},{85,74,63,53,44,53,52,64},{68,58,48,40,32,55,52,56},{47,38,31,26,22,55,50,50}},
  {{31,26,22,20,19,55,50,38},{20,19,20,22,26,55,49,33},{24,28,35,42,51,53,48,37},{26,31,38,46,56,50,48,40},{33,40,49,58,69,49,48,50},{46,55,66,76,88,48,48,54},{52,62,72,83,95,47,46,60},{83,94,105,116,127,47,46,61},{83,94,105,116,127,47,44,63},{96,108,118,129,138,46,43,65},{160,163,164,163,161,46,42,69},{160,163,164,163,161,46,41,74}},
  {{160,156,150,143,134,46,41,79},{152,145,137,128,117,46,39,86},{147,139,130,120,110,46,39,90},{145,137,128,117,107,46,39,91},{126,116,105,93,82,46,38,93},{124,113,102,91,80,47,38,93},{122,112,101,89,78,48,37,90},{120,110,99,87,76,48,37,83},{122,111,100,89,78,48,37,76},{123,113,102,90,79,50,36,71},{132,123,112,101,90,50,36,65},{158,153,147,139,130,51,36,56}},
  {{163,162,159,154,148,52,36,53},{162,163,163,160,156,52,36,57},{158,161,163,163,161,52,36,61},{151,157,161,163,163,54,36,64},{138,146,152,158,161,55,36,67},{93,104,115,125,135,55,36,70},{77,89,100,111,121,55,35,71},{60,71,82,93,104,55,34,73},{45,55,65,76,87,55,34,73},{34,42,51,61,71,54,32,70},{23,28,34,42,50,52,32,68},{19,22,26,32,39,52,31,62}},
  {{21,19,19,20,23,50,30,55},{28,23,20,19,19,49,29,51},{41,34,28,23,20,48,29,51},{55,46,38,31,25,47,28,53},{62,52,43,35,29,47,28,56},{70,59,50,41,33,47,28,59},{78,67,57,47,39,47,28,59},{89,78,67,56,47,47,28,63},{106,95,84,73,62,47,29,63},{115,104,92,81,70,47,29,61},{127,117,106,95,84,47,31,56},{135,125,115,104,93,47,33,51}},
  {{144,136,127,117,106,47,34,44},{150,143,135,126,116,47,34,41},{154,149,141,133,123,47,35,38},{157,152,145,138,129,47,36,33},{158,153,147,139,130,47,37,33},{161,158,154,148,141,47,38,30},{162,161,159,155,150,47,39,27},{161,161,160,157,152,47,42,24},{161,161,161,158,154,47,42,21},{159,161,161,160,156,47,42,20},{158,161,161,160,157,47,42,22},{155,159,161,161,159,47,42,27}}
};
const PROGMEM uint8_t sleepTrans[NUM_SLEEP_SEGMENTS][12] = {
  {1,51,6,42,15,40,16,40,11,39,9,39},
  {2,53,5,45,13,42,18,42,12,39,15,32},
  {3,55,7,46,14,41,4,40,17,40,8,29},
  {4,62,14,55,17,51,7,38,8,32,2,14},
  {13,51,5,50,18,44,12,37,2,36,8,34},
  {6,46,15,43,16,43,1,41,0,40,9,40},
  {7,57,3,48,8,38,2,38,4,36,14,35},
  {4,50,14,47,3,45,8,44,17,41,13,24},
  {9,45,11,44,6,42,10,42,16,42,0,37},
  {10,49,11,48,6,41,16,40,0,38,1,36},
  {11,50,9,47,6,42,16,41,0,37,1,36},
  {12,46,10,44,9,43,6,41,16,40,18,37},
  {13,54,8,50,2,41,5,41,18,35,7,32},
  {4,50,14,48,17,44,3,43,7,36,8,31},
  {16,44,0,44,6,43,15,42,9,40,1,39},
  {16,45,6,44,18,41,9,41,12,41,0,40},
  {17,52,3,48,14,46,4,44,7,38,8,24},
  {5,50,18,49,13,45,12,40,15,34,2,33},
  {9,46,11,45,10,44,16,41,6,40,0,36},
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
int prevSegmentEndPos[NUM_SERVOS];  // End positions from previous segment
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
  
  // Apply reversal WITHIN the output range based on PIN (matches listener)
  if (isReversedPin(servoPins[servoIdx])) {
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

unsigned int getSegmentDuration(State state, int segmentIdx) {
  switch (state) {
    case STATE_IDLE: 
      if (segmentIdx < NUM_IDLE_SEGMENTS)
        return pgm_read_word(&idleDurations[segmentIdx]);
      break;
    case STATE_ACTIVE: 
      if (segmentIdx < NUM_ACTIVE_SEGMENTS)
        return pgm_read_word(&activeDurations[segmentIdx]);
      break;
    case STATE_SLEEP: 
      if (segmentIdx < NUM_SLEEP_SEGMENTS)
        return pgm_read_word(&sleepDurations[segmentIdx]);
      break;
  }
  return 1000; // Fallback to 1 second
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
  
  // Time within current segment
  unsigned long segmentElapsed = now - segmentStartTime;
  unsigned int currentSegmentDuration = getSegmentDuration(currentState, currentSegment);
  
  // Check if segment is done
  if (segmentElapsed >= currentSegmentDuration) {
    // Store last sample position for blending
    int lastIdx = SAMPLES_PER_SEGMENT - 1;
    getSegmentPosition(currentState, currentSegment, lastIdx, prevSegmentEndPos);
    
    // Pick next segment
    currentSegment = pickNextSegment(currentState, currentSegment);
    segmentStartTime = now;
    needsBlend = true;
    segmentElapsed = 0;
    currentSegmentDuration = getSegmentDuration(currentState, currentSegment);
  }
  
  // Calculate position within segment WITH INTERPOLATION
  float progress = (float)segmentElapsed / currentSegmentDuration;
  float sampleFloat = progress * (SAMPLES_PER_SEGMENT - 1);
  int sampleIdx = constrain((int)sampleFloat, 0, SAMPLES_PER_SEGMENT - 2);
  float interpFactor = sampleFloat - sampleIdx;
  
  int posA[NUM_SERVOS], posB[NUM_SERVOS];
  getSegmentPosition(currentState, currentSegment, sampleIdx, posA);
  getSegmentPosition(currentState, currentSegment, sampleIdx + 1, posB);
  
  int targetPositions[NUM_SERVOS];
  for (int i = 0; i < NUM_SERVOS; i++) {
    targetPositions[i] = posA[i] + (int)((posB[i] - posA[i]) * interpFactor);
  }
  
  // Blend from previous segment if needed
  if (needsBlend && segmentElapsed < SEGMENT_BLEND_TIME) {
    float blendFactor = smootherstep((float)segmentElapsed / SEGMENT_BLEND_TIME);
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
  needsBlend = false;
  
  Serial.println("Ready - Markov segment mode (variable durations)");
  Serial.print("Blend time: "); Serial.print(SEGMENT_BLEND_TIME); Serial.println("ms");
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
    Serial.print(" PIR:"); Serial.println(pirHigh  ? "HIGH" : "LOW");
    lastDebugTime = millis();
  }
  
  delay(UPDATE_INTERVAL);
}
