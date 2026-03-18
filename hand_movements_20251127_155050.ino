/*
 * 8-Servo Hand Control - Generated Movement Code
 * Generated: 2025-11-27 15:50:50
 * Layers: 4
 * Total Movements: 4436
 * 
 * Hardware: 5 Finger Servos + 3 Arm Servos
 * Fingers: Thumb, Index, Middle, Ring, Pinky
 * Arm: Shoulder, Elbow, Wrist
 * 
 * Pin Mapping (reversed order):
 * Pin 12 -> Thumb (servo 0)
 * Pin 11 -> Index (servo 1)
 * Pin 10 -> Middle (servo 2)
 * Pin 9  -> Ring (servo 3)
 * Pin 8  -> Pinky (servo 4)
 * Pin 7  -> Shoulder (servo 5)
 * Pin 6  -> Elbow (servo 6)
 * Pin 5  -> Wrist (servo 7)
 */

#include <Servo.h>

// Servo objects for 8 servos (5 fingers + 3 arm)
Servo servo[8];

// Servo pins - REVERSED ORDER to match hardware (12-5)
int servoPins[8] = {12, 11, 10, 9, 8, 7, 6, 5};

void setup() {
  Serial.begin(9600);
  
  // Attach servos
  for(int i = 0; i < 8; i++) {
    servo[i].attach(servoPins[i]);
    servo[i].write(90); // Center position
  }
  
  delay(1000);
  Serial.println("8-Servo Hand Control Ready");
}

void loop() {
  Serial.println("Playing recorded sequence...");
  
  playLayer1(); // Layer_2 (manual mode)
  delay(2000); // Pause between layers

  playLayer2(); // Layer_3 (manual mode)
  delay(2000); // Pause between layers

  playLayer3(); // Layer_4 (manual mode)
  delay(2000); // Pause between layers

  playLayer4(); // Layer_4 (cursor mode)
  delay(2000); // Pause between layers

}

// Layer 1: Layer_2 - manual mode
// Duration: 14.2s, Points: 1394
void playLayer1() {
  delay(25);
  // Step 1: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  delay(30);
  // Step 2: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  delay(14);
  // Step 3: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(30);
  // Step 4: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(28);
  // Step 5: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(32);
  // Step 6: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(31);
  // Step 7: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(31);
  // Step 8: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 9: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 10: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 11: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 12: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 13: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 14: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 15: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 16: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 17: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 18: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 19: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 20: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 21: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 22: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  delay(12);
  // Step 23: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  delay(19);
  // Step 24: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  delay(30);
  // Step 25: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 26: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 27: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 28: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 29: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 30: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 31: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 32: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 33: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 34: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 35: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 36: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 37: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 38: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 39: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  // Step 40: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 41: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 42: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 43: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 44: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 45: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 46: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 47: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 48: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 49: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 50: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 51: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  delay(23);
  // Step 52: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 53: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  delay(17);
  // Step 54: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 55: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  delay(12);
  // Step 56: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 57: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 58: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 59: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 60: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 61: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 62: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 63: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  delay(12);
  // Step 64: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 65: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 66: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 67: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 68: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 69: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 70: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 71: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 72: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 73: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 74: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 75: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 76: Fingers [-, -, -, -, -] Arm [-, -, 89]
  servo[7].write(89); // Wrist

  // Step 77: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  delay(15);
  // Step 78: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 79: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 80: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 81: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 82: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 83: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 84: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 85: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 86: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 87: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 88: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 89: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 90: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 91: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 92: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 93: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 94: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 95: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 96: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 97: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 98: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 99: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 100: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  delay(15);
  // Step 101: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 102: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 103: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  delay(19);
  // Step 104: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 105: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 106: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  delay(15);
  // Step 107: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 108: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 109: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 110: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 111: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 112: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 113: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  delay(16);
  // Step 114: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 115: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 116: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  delay(31);
  // Step 117: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 118: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 119: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 120: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 121: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 122: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  delay(21);
  // Step 123: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  delay(11);
  // Step 124: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  delay(16);
  // Step 125: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 126: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 127: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  delay(18);
  // Step 128: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  delay(29);
  // Step 129: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 130: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  delay(25);
  // Step 131: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  // Step 132: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  delay(12);
  // Step 133: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(12);
  // Step 134: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 135: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(19);
  // Step 136: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 137: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 138: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  delay(12);
  // Step 139: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 140: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 141: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 142: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 143: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 144: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 145: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 146: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 147: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 148: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 149: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  delay(15);
  // Step 150: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  delay(31);
  // Step 151: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  delay(16);
  // Step 152: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  delay(16);
  // Step 153: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 154: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 155: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 156: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 157: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 158: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 159: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 160: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 161: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 162: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 163: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 164: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  delay(17);
  // Step 165: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 166: Fingers [-, -, -, -, -] Arm [-, -, 89]
  servo[7].write(89); // Wrist

  // Step 167: Fingers [-, -, -, -, -] Arm [-, -, 89]
  servo[7].write(89); // Wrist

  // Step 168: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 169: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 170: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 171: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 172: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 173: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 174: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 175: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 176: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 177: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 178: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 179: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 180: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 181: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 182: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 183: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 184: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 185: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 186: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 187: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  delay(16);
  // Step 188: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 189: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 190: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  delay(14);
  // Step 191: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  delay(18);
  // Step 192: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  delay(14);
  // Step 193: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 194: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  delay(14);
  // Step 195: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 196: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  delay(21);
  // Step 197: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 198: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 199: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 200: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  delay(11);
  // Step 201: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 202: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 203: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 204: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 205: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 206: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 207: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 208: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 209: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  // Step 210: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 211: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 212: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 213: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 214: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 215: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 216: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 217: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  delay(11);
  // Step 218: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 219: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  delay(13);
  // Step 220: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  delay(15);
  // Step 221: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 222: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 223: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 224: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 225: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 226: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  delay(12);
  // Step 227: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 228: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 229: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 230: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 231: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  delay(11);
  // Step 232: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 233: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 234: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 235: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 236: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 237: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 238: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  delay(17);
  // Step 239: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 240: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 241: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 242: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 243: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 244: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 245: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  delay(15);
  // Step 246: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 247: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  delay(15);
  // Step 248: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 249: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 250: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 251: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  delay(23);
  // Step 252: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 253: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  delay(12);
  // Step 254: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  delay(21);
  // Step 255: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  delay(30);
  // Step 256: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  delay(30);
  // Step 257: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 258: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  delay(22);
  // Step 259: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 260: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 261: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(14);
  // Step 262: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 263: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 264: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(15);
  // Step 265: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 266: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(11);
  // Step 267: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 268: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 269: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  delay(19);
  // Step 270: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 271: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 272: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  delay(15);
  // Step 273: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 274: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 275: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 276: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 277: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 278: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  delay(19);
  // Step 279: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 280: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  delay(22);
  // Step 281: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 282: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  delay(29);
  // Step 283: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  delay(32);
  // Step 284: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 285: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 286: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  delay(15);
  // Step 287: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  delay(30);
  // Step 288: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 289: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  delay(20);
  // Step 290: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  delay(14);
  // Step 291: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  delay(20);
  // Step 292: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  delay(29);
  // Step 293: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  delay(12);
  // Step 294: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  delay(17);
  // Step 295: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 296: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 297: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  delay(14);
  // Step 298: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 299: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 300: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 301: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  delay(13);
  // Step 302: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 303: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  delay(18);
  // Step 304: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 305: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  delay(13);
  // Step 306: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 307: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  delay(32);
  // Step 308: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  delay(29);
  // Step 309: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 310: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 311: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  delay(15);
  // Step 312: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 313: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  delay(15);
  // Step 314: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 315: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 316: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 317: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 318: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 319: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 320: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  delay(31);
  // Step 321: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  delay(31);
  // Step 322: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 323: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  delay(16);
  // Step 324: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 325: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 326: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  delay(22);
  // Step 327: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 328: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 329: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  delay(14);
  // Step 330: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 331: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 332: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  delay(20);
  // Step 333: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 334: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  delay(22);
  // Step 335: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 336: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  delay(12);
  // Step 337: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 338: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 339: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  delay(20);
  // Step 340: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 341: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 342: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  delay(18);
  // Step 343: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  delay(13);
  // Step 344: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(13);
  // Step 345: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(16);
  // Step 346: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(17);
  // Step 347: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 348: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 349: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(22);
  // Step 350: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(33);
  // Step 351: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 352: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 353: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(15);
  // Step 354: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 355: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(17);
  // Step 356: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 357: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 358: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 359: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  delay(13);
  // Step 360: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 361: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  delay(17);
  // Step 362: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 363: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  delay(20);
  // Step 364: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 365: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  delay(14);
  // Step 366: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  delay(16);
  // Step 367: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 368: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 369: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 370: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 371: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  delay(19);
  // Step 372: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 373: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 374: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 375: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  delay(12);
  // Step 376: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  delay(18);
  // Step 377: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  delay(13);
  // Step 378: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 379: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 380: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  delay(14);
  // Step 381: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 382: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  delay(12);
  // Step 383: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 384: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 385: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 386: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 387: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  delay(12);
  // Step 388: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 389: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 390: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  delay(20);
  // Step 391: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  delay(11);
  // Step 392: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 393: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 394: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  delay(13);
  // Step 395: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 396: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 397: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 398: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 399: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 400: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 401: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 402: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 403: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 404: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 405: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  delay(16);
  // Step 406: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 407: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  delay(13);
  // Step 408: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  delay(15);
  // Step 409: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 410: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 411: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 412: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  // Step 413: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  delay(12);
  // Step 414: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 415: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 416: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 417: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 418: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 419: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 420: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 421: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  delay(12);
  // Step 422: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 423: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 424: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 425: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 426: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 427: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 428: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 429: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 430: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 431: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 432: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 433: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  delay(12);
  // Step 434: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  delay(14);
  // Step 435: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 436: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 437: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 438: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 439: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 440: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 441: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  delay(11);
  // Step 442: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 443: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 444: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 445: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  delay(17);
  // Step 446: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 447: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  delay(15);
  // Step 448: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 449: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 450: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 451: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  delay(19);
  // Step 452: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 453: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 454: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  delay(16);
  // Step 455: Fingers [-, -, -, -, -] Arm [-, -, 89]
  servo[7].write(89); // Wrist

  // Step 456: Fingers [-, -, -, -, -] Arm [-, -, 89]
  servo[7].write(89); // Wrist

  // Step 457: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 458: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 459: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 460: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 461: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 462: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 463: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 464: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 465: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 466: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 467: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 468: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 469: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  delay(11);
  // Step 470: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 471: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 472: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  delay(11);
  // Step 473: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 474: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  delay(12);
  // Step 475: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 476: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 477: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  delay(17);
  // Step 478: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 479: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  delay(13);
  // Step 480: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 481: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 482: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 483: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 484: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 485: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 486: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 487: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  delay(15);
  // Step 488: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 489: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 490: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 491: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 492: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 493: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 494: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 495: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 496: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  // Step 497: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  // Step 498: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  // Step 499: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 500: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 501: Fingers [-, -, -, -, -] Arm [-, -, 106]
  servo[7].write(106); // Wrist

  // Step 502: Fingers [-, -, -, -, -] Arm [-, -, 106]
  servo[7].write(106); // Wrist

  // Step 503: Fingers [-, -, -, -, -] Arm [-, -, 107]
  servo[7].write(107); // Wrist

  // Step 504: Fingers [-, -, -, -, -] Arm [-, -, 108]
  servo[7].write(108); // Wrist

  delay(11);
  // Step 505: Fingers [-, -, -, -, -] Arm [-, -, 109]
  servo[7].write(109); // Wrist

  // Step 506: Fingers [-, -, -, -, -] Arm [-, -, 109]
  servo[7].write(109); // Wrist

  delay(16);
  // Step 507: Fingers [-, -, -, -, -] Arm [-, -, 111]
  servo[7].write(111); // Wrist

  // Step 508: Fingers [-, -, -, -, -] Arm [-, -, 113]
  servo[7].write(113); // Wrist

  // Step 509: Fingers [-, -, -, -, -] Arm [-, -, 113]
  servo[7].write(113); // Wrist

  delay(15);
  // Step 510: Fingers [-, -, -, -, -] Arm [-, -, 114]
  servo[7].write(114); // Wrist

  // Step 511: Fingers [-, -, -, -, -] Arm [-, -, 115]
  servo[7].write(115); // Wrist

  // Step 512: Fingers [-, -, -, -, -] Arm [-, -, 115]
  servo[7].write(115); // Wrist

  // Step 513: Fingers [-, -, -, -, -] Arm [-, -, 116]
  servo[7].write(116); // Wrist

  // Step 514: Fingers [-, -, -, -, -] Arm [-, -, 118]
  servo[7].write(118); // Wrist

  // Step 515: Fingers [-, -, -, -, -] Arm [-, -, 118]
  servo[7].write(118); // Wrist

  // Step 516: Fingers [-, -, -, -, -] Arm [-, -, 118]
  servo[7].write(118); // Wrist

  // Step 517: Fingers [-, -, -, -, -] Arm [-, -, 119]
  servo[7].write(119); // Wrist

  // Step 518: Fingers [-, -, -, -, -] Arm [-, -, 119]
  servo[7].write(119); // Wrist

  // Step 519: Fingers [-, -, -, -, -] Arm [-, -, 120]
  servo[7].write(120); // Wrist

  // Step 520: Fingers [-, -, -, -, -] Arm [-, -, 120]
  servo[7].write(120); // Wrist

  // Step 521: Fingers [-, -, -, -, -] Arm [-, -, 120]
  servo[7].write(120); // Wrist

  delay(12);
  // Step 522: Fingers [-, -, -, -, -] Arm [-, -, 121]
  servo[7].write(121); // Wrist

  // Step 523: Fingers [-, -, -, -, -] Arm [-, -, 121]
  servo[7].write(121); // Wrist

  // Step 524: Fingers [-, -, -, -, -] Arm [-, -, 121]
  servo[7].write(121); // Wrist

  // Step 525: Fingers [-, -, -, -, -] Arm [-, -, 121]
  servo[7].write(121); // Wrist

  // Step 526: Fingers [-, -, -, -, -] Arm [-, -, 122]
  servo[7].write(122); // Wrist

  delay(21);
  // Step 527: Fingers [-, -, -, -, -] Arm [-, -, 122]
  servo[7].write(122); // Wrist

  // Step 528: Fingers [-, -, -, -, -] Arm [-, -, 122]
  servo[7].write(122); // Wrist

  delay(13);
  // Step 529: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  // Step 530: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  // Step 531: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  // Step 532: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  // Step 533: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  // Step 534: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  delay(14);
  // Step 535: Fingers [-, -, -, -, -] Arm [-, -, 125]
  servo[7].write(125); // Wrist

  // Step 536: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(13);
  // Step 537: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 538: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(13);
  // Step 539: Fingers [-, -, -, -, -] Arm [-, -, 127]
  servo[7].write(127); // Wrist

  // Step 540: Fingers [-, -, -, -, -] Arm [-, -, 127]
  servo[7].write(127); // Wrist

  // Step 541: Fingers [-, -, -, -, -] Arm [-, -, 127]
  servo[7].write(127); // Wrist

  // Step 542: Fingers [-, -, -, -, -] Arm [-, -, 128]
  servo[7].write(128); // Wrist

  // Step 543: Fingers [-, -, -, -, -] Arm [-, -, 128]
  servo[7].write(128); // Wrist

  // Step 544: Fingers [-, -, -, -, -] Arm [-, -, 129]
  servo[7].write(129); // Wrist

  // Step 545: Fingers [-, -, -, -, -] Arm [-, -, 129]
  servo[7].write(129); // Wrist

  delay(12);
  // Step 546: Fingers [-, -, -, -, -] Arm [-, -, 129]
  servo[7].write(129); // Wrist

  delay(15);
  // Step 547: Fingers [-, -, -, -, -] Arm [-, -, 129]
  servo[7].write(129); // Wrist

  // Step 548: Fingers [-, -, -, -, -] Arm [-, -, 130]
  servo[7].write(130); // Wrist

  // Step 549: Fingers [-, -, -, -, -] Arm [-, -, 130]
  servo[7].write(130); // Wrist

  // Step 550: Fingers [-, -, -, -, -] Arm [-, -, 131]
  servo[7].write(131); // Wrist

  // Step 551: Fingers [-, -, -, -, -] Arm [-, -, 131]
  servo[7].write(131); // Wrist

  // Step 552: Fingers [-, -, -, -, -] Arm [-, -, 132]
  servo[7].write(132); // Wrist

  // Step 553: Fingers [-, -, -, -, -] Arm [-, -, 132]
  servo[7].write(132); // Wrist

  // Step 554: Fingers [-, -, -, -, -] Arm [-, -, 133]
  servo[7].write(133); // Wrist

  // Step 555: Fingers [-, -, -, -, -] Arm [-, -, 134]
  servo[7].write(134); // Wrist

  // Step 556: Fingers [-, -, -, -, -] Arm [-, -, 134]
  servo[7].write(134); // Wrist

  // Step 557: Fingers [-, -, -, -, -] Arm [-, -, 134]
  servo[7].write(134); // Wrist

  // Step 558: Fingers [-, -, -, -, -] Arm [-, -, 134]
  servo[7].write(134); // Wrist

  delay(13);
  // Step 559: Fingers [-, -, -, -, -] Arm [-, -, 135]
  servo[7].write(135); // Wrist

  // Step 560: Fingers [-, -, -, -, -] Arm [-, -, 135]
  servo[7].write(135); // Wrist

  // Step 561: Fingers [-, -, -, -, -] Arm [-, -, 135]
  servo[7].write(135); // Wrist

  // Step 562: Fingers [-, -, -, -, -] Arm [-, -, 136]
  servo[7].write(136); // Wrist

  delay(14);
  // Step 563: Fingers [-, -, -, -, -] Arm [-, -, 136]
  servo[7].write(136); // Wrist

  // Step 564: Fingers [-, -, -, -, -] Arm [-, -, 136]
  servo[7].write(136); // Wrist

  delay(16);
  // Step 565: Fingers [-, -, -, -, -] Arm [-, -, 137]
  servo[7].write(137); // Wrist

  // Step 566: Fingers [-, -, -, -, -] Arm [-, -, 137]
  servo[7].write(137); // Wrist

  // Step 567: Fingers [-, -, -, -, -] Arm [-, -, 137]
  servo[7].write(137); // Wrist

  // Step 568: Fingers [-, -, -, -, -] Arm [-, -, 138]
  servo[7].write(138); // Wrist

  // Step 569: Fingers [-, -, -, -, -] Arm [-, -, 138]
  servo[7].write(138); // Wrist

  // Step 570: Fingers [-, -, -, -, -] Arm [-, -, 138]
  servo[7].write(138); // Wrist

  // Step 571: Fingers [-, -, -, -, -] Arm [-, -, 139]
  servo[7].write(139); // Wrist

  // Step 572: Fingers [-, -, -, -, -] Arm [-, -, 139]
  servo[7].write(139); // Wrist

  // Step 573: Fingers [-, -, -, -, -] Arm [-, -, 140]
  servo[7].write(140); // Wrist

  // Step 574: Fingers [-, -, -, -, -] Arm [-, -, 140]
  servo[7].write(140); // Wrist

  // Step 575: Fingers [-, -, -, -, -] Arm [-, -, 141]
  servo[7].write(141); // Wrist

  // Step 576: Fingers [-, -, -, -, -] Arm [-, -, 141]
  servo[7].write(141); // Wrist

  // Step 577: Fingers [-, -, -, -, -] Arm [-, -, 141]
  servo[7].write(141); // Wrist

  // Step 578: Fingers [-, -, -, -, -] Arm [-, -, 142]
  servo[7].write(142); // Wrist

  // Step 579: Fingers [-, -, -, -, -] Arm [-, -, 142]
  servo[7].write(142); // Wrist

  // Step 580: Fingers [-, -, -, -, -] Arm [-, -, 142]
  servo[7].write(142); // Wrist

  // Step 581: Fingers [-, -, -, -, -] Arm [-, -, 143]
  servo[7].write(143); // Wrist

  delay(17);
  // Step 582: Fingers [-, -, -, -, -] Arm [-, -, 143]
  servo[7].write(143); // Wrist

  // Step 583: Fingers [-, -, -, -, -] Arm [-, -, 144]
  servo[7].write(144); // Wrist

  delay(11);
  // Step 584: Fingers [-, -, -, -, -] Arm [-, -, 145]
  servo[7].write(145); // Wrist

  // Step 585: Fingers [-, -, -, -, -] Arm [-, -, 145]
  servo[7].write(145); // Wrist

  // Step 586: Fingers [-, -, -, -, -] Arm [-, -, 145]
  servo[7].write(145); // Wrist

  // Step 587: Fingers [-, -, -, -, -] Arm [-, -, 145]
  servo[7].write(145); // Wrist

  // Step 588: Fingers [-, -, -, -, -] Arm [-, -, 146]
  servo[7].write(146); // Wrist

  delay(22);
  // Step 589: Fingers [-, -, -, -, -] Arm [-, -, 146]
  servo[7].write(146); // Wrist

  delay(31);
  // Step 590: Fingers [-, -, -, -, -] Arm [-, -, 146]
  servo[7].write(146); // Wrist

  delay(11);
  // Step 591: Fingers [-, -, -, -, -] Arm [-, -, 146]
  servo[7].write(146); // Wrist

  delay(15);
  // Step 592: Fingers [-, -, -, -, -] Arm [-, -, 147]
  servo[7].write(147); // Wrist

  // Step 593: Fingers [-, -, -, -, -] Arm [-, -, 147]
  servo[7].write(147); // Wrist

  // Step 594: Fingers [-, -, -, -, -] Arm [-, -, 147]
  servo[7].write(147); // Wrist

  // Step 595: Fingers [-, -, -, -, -] Arm [-, -, 148]
  servo[7].write(148); // Wrist

  // Step 596: Fingers [-, -, -, -, -] Arm [-, -, 148]
  servo[7].write(148); // Wrist

  // Step 597: Fingers [-, -, -, -, -] Arm [-, -, 148]
  servo[7].write(148); // Wrist

  delay(11);
  // Step 598: Fingers [-, -, -, -, -] Arm [-, -, 149]
  servo[7].write(149); // Wrist

  delay(15);
  // Step 599: Fingers [-, -, -, -, -] Arm [-, -, 149]
  servo[7].write(149); // Wrist

  // Step 600: Fingers [-, -, -, -, -] Arm [-, -, 150]
  servo[7].write(150); // Wrist

  // Step 601: Fingers [-, -, -, -, -] Arm [-, -, 150]
  servo[7].write(150); // Wrist

  // Step 602: Fingers [-, -, -, -, -] Arm [-, -, 150]
  servo[7].write(150); // Wrist

  // Step 603: Fingers [-, -, -, -, -] Arm [-, -, 151]
  servo[7].write(151); // Wrist

  delay(22);
  // Step 604: Fingers [-, -, -, -, -] Arm [-, -, 151]
  servo[7].write(151); // Wrist

  // Step 605: Fingers [-, -, -, -, -] Arm [-, -, 151]
  servo[7].write(151); // Wrist

  // Step 606: Fingers [-, -, -, -, -] Arm [-, -, 151]
  servo[7].write(151); // Wrist

  delay(14);
  // Step 607: Fingers [-, -, -, -, -] Arm [-, -, 151]
  servo[7].write(151); // Wrist

  // Step 608: Fingers [-, -, -, -, -] Arm [-, -, 152]
  servo[7].write(152); // Wrist

  delay(15);
  // Step 609: Fingers [-, -, -, -, -] Arm [-, -, 153]
  servo[7].write(153); // Wrist

  // Step 610: Fingers [-, -, -, -, -] Arm [-, -, 153]
  servo[7].write(153); // Wrist

  delay(12);
  // Step 611: Fingers [-, -, -, -, -] Arm [-, -, 153]
  servo[7].write(153); // Wrist

  // Step 612: Fingers [-, -, -, -, -] Arm [-, -, 154]
  servo[7].write(154); // Wrist

  // Step 613: Fingers [-, -, -, -, -] Arm [-, -, 154]
  servo[7].write(154); // Wrist

  // Step 614: Fingers [-, -, -, -, -] Arm [-, -, 154]
  servo[7].write(154); // Wrist

  // Step 615: Fingers [-, -, -, -, -] Arm [-, -, 155]
  servo[7].write(155); // Wrist

  delay(20);
  // Step 616: Fingers [-, -, -, -, -] Arm [-, -, 155]
  servo[7].write(155); // Wrist

  // Step 617: Fingers [-, -, -, -, -] Arm [-, -, 155]
  servo[7].write(155); // Wrist

  // Step 618: Fingers [-, -, -, -, -] Arm [-, -, 156]
  servo[7].write(156); // Wrist

  // Step 619: Fingers [-, -, -, -, -] Arm [-, -, 156]
  servo[7].write(156); // Wrist

  // Step 620: Fingers [-, -, -, -, -] Arm [-, -, 156]
  servo[7].write(156); // Wrist

  delay(14);
  // Step 621: Fingers [-, -, -, -, -] Arm [-, -, 157]
  servo[7].write(157); // Wrist

  // Step 622: Fingers [-, -, -, -, -] Arm [-, -, 157]
  servo[7].write(157); // Wrist

  delay(19);
  // Step 623: Fingers [-, -, -, -, -] Arm [-, -, 157]
  servo[7].write(157); // Wrist

  delay(15);
  // Step 624: Fingers [-, -, -, -, -] Arm [-, -, 157]
  servo[7].write(157); // Wrist

  // Step 625: Fingers [-, -, -, -, -] Arm [-, -, 158]
  servo[7].write(158); // Wrist

  delay(16);
  // Step 626: Fingers [-, -, -, -, -] Arm [-, -, 158]
  servo[7].write(158); // Wrist

  // Step 627: Fingers [-, -, -, -, -] Arm [-, -, 158]
  servo[7].write(158); // Wrist

  delay(35);
  // Step 628: Fingers [-, -, -, -, -] Arm [-, -, 158]
  servo[7].write(158); // Wrist

  delay(12);
  // Step 629: Fingers [-, -, -, -, -] Arm [-, -, 158]
  servo[7].write(158); // Wrist

  // Step 630: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  delay(14);
  // Step 631: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  delay(18);
  // Step 632: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  // Step 633: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  // Step 634: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  delay(31);
  // Step 635: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  // Step 636: Fingers [-, -, -, -, -] Arm [-, -, 160]
  servo[7].write(160); // Wrist

  delay(13);
  // Step 637: Fingers [-, -, -, -, -] Arm [-, -, 160]
  servo[7].write(160); // Wrist

  // Step 638: Fingers [-, -, -, -, -] Arm [-, -, 160]
  servo[7].write(160); // Wrist

  // Step 639: Fingers [-, -, -, -, -] Arm [-, -, 160]
  servo[7].write(160); // Wrist

  delay(22);
  // Step 640: Fingers [-, -, -, -, -] Arm [-, -, 160]
  servo[7].write(160); // Wrist

  delay(23);
  // Step 641: Fingers [-, -, -, -, -] Arm [-, -, 161]
  servo[7].write(161); // Wrist

  // Step 642: Fingers [-, -, -, -, -] Arm [-, -, 161]
  servo[7].write(161); // Wrist

  delay(34);
  // Step 643: Fingers [-, -, -, -, -] Arm [-, -, 161]
  servo[7].write(161); // Wrist

  delay(18);
  // Step 644: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  delay(12);
  // Step 645: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  // Step 646: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  delay(22);
  // Step 647: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  delay(30);
  // Step 648: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  delay(29);
  // Step 649: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  delay(22);
  // Step 650: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  // Step 651: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  // Step 652: Fingers [-, -, -, -, -] Arm [-, -, 163]
  servo[7].write(163); // Wrist

  delay(28);
  // Step 653: Fingers [-, -, -, -, -] Arm [-, -, 163]
  servo[7].write(163); // Wrist

  delay(31);
  // Step 654: Fingers [-, -, -, -, -] Arm [-, -, 163]
  servo[7].write(163); // Wrist

  delay(30);
  // Step 655: Fingers [-, -, -, -, -] Arm [-, -, 163]
  servo[7].write(163); // Wrist

  delay(19);
  // Step 656: Fingers [-, -, -, -, -] Arm [-, -, 163]
  servo[7].write(163); // Wrist

  delay(11);
  // Step 657: Fingers [-, -, -, -, -] Arm [-, -, 163]
  servo[7].write(163); // Wrist

  delay(31);
  // Step 658: Fingers [-, -, -, -, -] Arm [-, -, 163]
  servo[7].write(163); // Wrist

  delay(30);
  // Step 659: Fingers [-, -, -, -, -] Arm [-, -, 163]
  servo[7].write(163); // Wrist

  delay(30);
  // Step 660: Fingers [-, -, -, -, -] Arm [-, -, 163]
  servo[7].write(163); // Wrist

  delay(30);
  // Step 661: Fingers [-, -, -, -, -] Arm [-, -, 163]
  servo[7].write(163); // Wrist

  // Step 662: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  delay(23);
  // Step 663: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  delay(30);
  // Step 664: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  delay(32);
  // Step 665: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  delay(26);
  // Step 666: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  // Step 667: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  delay(15);
  // Step 668: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  // Step 669: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  // Step 670: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  // Step 671: Fingers [-, -, -, -, -] Arm [-, -, 165]
  servo[7].write(165); // Wrist

  // Step 672: Fingers [-, -, -, -, -] Arm [-, -, 165]
  servo[7].write(165); // Wrist

  // Step 673: Fingers [-, -, -, -, -] Arm [-, -, 165]
  servo[7].write(165); // Wrist

  // Step 674: Fingers [-, -, -, -, -] Arm [-, -, 165]
  servo[7].write(165); // Wrist

  // Step 675: Fingers [-, -, -, -, -] Arm [-, -, 165]
  servo[7].write(165); // Wrist

  // Step 676: Fingers [-, -, -, -, -] Arm [-, -, 165]
  servo[7].write(165); // Wrist

  // Step 677: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  // Step 678: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  // Step 679: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  delay(33);
  // Step 680: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  // Step 681: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  // Step 682: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  // Step 683: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  // Step 684: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  delay(22);
  // Step 685: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  // Step 686: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  // Step 687: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  delay(28);
  // Step 688: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  delay(31);
  // Step 689: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  delay(22);
  // Step 690: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  // Step 691: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  delay(30);
  // Step 692: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  delay(23);
  // Step 693: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  // Step 694: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  delay(16);
  // Step 695: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  delay(14);
  // Step 696: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  // Step 697: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  delay(19);
  // Step 698: Fingers [-, -, -, -, -] Arm [-, -, 166]
  servo[7].write(166); // Wrist

  delay(20);
  // Step 699: Fingers [-, -, -, -, -] Arm [-, -, 165]
  servo[7].write(165); // Wrist

  // Step 700: Fingers [-, -, -, -, -] Arm [-, -, 165]
  servo[7].write(165); // Wrist

  // Step 701: Fingers [-, -, -, -, -] Arm [-, -, 165]
  servo[7].write(165); // Wrist

  // Step 702: Fingers [-, -, -, -, -] Arm [-, -, 165]
  servo[7].write(165); // Wrist

  // Step 703: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  // Step 704: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  // Step 705: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  // Step 706: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  // Step 707: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  // Step 708: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  // Step 709: Fingers [-, -, -, -, -] Arm [-, -, 164]
  servo[7].write(164); // Wrist

  delay(14);
  // Step 710: Fingers [-, -, -, -, -] Arm [-, -, 163]
  servo[7].write(163); // Wrist

  delay(16);
  // Step 711: Fingers [-, -, -, -, -] Arm [-, -, 163]
  servo[7].write(163); // Wrist

  // Step 712: Fingers [-, -, -, -, -] Arm [-, -, 163]
  servo[7].write(163); // Wrist

  delay(19);
  // Step 713: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  // Step 714: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  // Step 715: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  delay(20);
  // Step 716: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  // Step 717: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  // Step 718: Fingers [-, -, -, -, -] Arm [-, -, 162]
  servo[7].write(162); // Wrist

  delay(12);
  // Step 719: Fingers [-, -, -, -, -] Arm [-, -, 161]
  servo[7].write(161); // Wrist

  // Step 720: Fingers [-, -, -, -, -] Arm [-, -, 161]
  servo[7].write(161); // Wrist

  // Step 721: Fingers [-, -, -, -, -] Arm [-, -, 160]
  servo[7].write(160); // Wrist

  // Step 722: Fingers [-, -, -, -, -] Arm [-, -, 160]
  servo[7].write(160); // Wrist

  delay(11);
  // Step 723: Fingers [-, -, -, -, -] Arm [-, -, 160]
  servo[7].write(160); // Wrist

  // Step 724: Fingers [-, -, -, -, -] Arm [-, -, 160]
  servo[7].write(160); // Wrist

  delay(12);
  // Step 725: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  delay(14);
  // Step 726: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  // Step 727: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  delay(27);
  // Step 728: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  delay(31);
  // Step 729: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  delay(28);
  // Step 730: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  // Step 731: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  delay(25);
  // Step 732: Fingers [-, -, -, -, -] Arm [-, -, 159]
  servo[7].write(159); // Wrist

  // Step 733: Fingers [-, -, -, -, -] Arm [-, -, 158]
  servo[7].write(158); // Wrist

  // Step 734: Fingers [-, -, -, -, -] Arm [-, -, 158]
  servo[7].write(158); // Wrist

  // Step 735: Fingers [-, -, -, -, -] Arm [-, -, 157]
  servo[7].write(157); // Wrist

  // Step 736: Fingers [-, -, -, -, -] Arm [-, -, 157]
  servo[7].write(157); // Wrist

  // Step 737: Fingers [-, -, -, -, -] Arm [-, -, 157]
  servo[7].write(157); // Wrist

  // Step 738: Fingers [-, -, -, -, -] Arm [-, -, 156]
  servo[7].write(156); // Wrist

  // Step 739: Fingers [-, -, -, -, -] Arm [-, -, 156]
  servo[7].write(156); // Wrist

  delay(15);
  // Step 740: Fingers [-, -, -, -, -] Arm [-, -, 156]
  servo[7].write(156); // Wrist

  // Step 741: Fingers [-, -, -, -, -] Arm [-, -, 156]
  servo[7].write(156); // Wrist

  delay(14);
  // Step 742: Fingers [-, -, -, -, -] Arm [-, -, 155]
  servo[7].write(155); // Wrist

  // Step 743: Fingers [-, -, -, -, -] Arm [-, -, 155]
  servo[7].write(155); // Wrist

  delay(12);
  // Step 744: Fingers [-, -, -, -, -] Arm [-, -, 155]
  servo[7].write(155); // Wrist

  delay(22);
  // Step 745: Fingers [-, -, -, -, -] Arm [-, -, 155]
  servo[7].write(155); // Wrist

  // Step 746: Fingers [-, -, -, -, -] Arm [-, -, 155]
  servo[7].write(155); // Wrist

  delay(21);
  // Step 747: Fingers [-, -, -, -, -] Arm [-, -, 155]
  servo[7].write(155); // Wrist

  delay(11);
  // Step 748: Fingers [-, -, -, -, -] Arm [-, -, 154]
  servo[7].write(154); // Wrist

  delay(20);
  // Step 749: Fingers [-, -, -, -, -] Arm [-, -, 154]
  servo[7].write(154); // Wrist

  // Step 750: Fingers [-, -, -, -, -] Arm [-, -, 154]
  servo[7].write(154); // Wrist

  delay(20);
  // Step 751: Fingers [-, -, -, -, -] Arm [-, -, 154]
  servo[7].write(154); // Wrist

  // Step 752: Fingers [-, -, -, -, -] Arm [-, -, 153]
  servo[7].write(153); // Wrist

  // Step 753: Fingers [-, -, -, -, -] Arm [-, -, 153]
  servo[7].write(153); // Wrist

  delay(17);
  // Step 754: Fingers [-, -, -, -, -] Arm [-, -, 153]
  servo[7].write(153); // Wrist

  // Step 755: Fingers [-, -, -, -, -] Arm [-, -, 153]
  servo[7].write(153); // Wrist

  delay(15);
  // Step 756: Fingers [-, -, -, -, -] Arm [-, -, 152]
  servo[7].write(152); // Wrist

  // Step 757: Fingers [-, -, -, -, -] Arm [-, -, 152]
  servo[7].write(152); // Wrist

  // Step 758: Fingers [-, -, -, -, -] Arm [-, -, 152]
  servo[7].write(152); // Wrist

  // Step 759: Fingers [-, -, -, -, -] Arm [-, -, 151]
  servo[7].write(151); // Wrist

  delay(14);
  // Step 760: Fingers [-, -, -, -, -] Arm [-, -, 151]
  servo[7].write(151); // Wrist

  // Step 761: Fingers [-, -, -, -, -] Arm [-, -, 151]
  servo[7].write(151); // Wrist

  // Step 762: Fingers [-, -, -, -, -] Arm [-, -, 150]
  servo[7].write(150); // Wrist

  // Step 763: Fingers [-, -, -, -, -] Arm [-, -, 149]
  servo[7].write(149); // Wrist

  // Step 764: Fingers [-, -, -, -, -] Arm [-, -, 149]
  servo[7].write(149); // Wrist

  // Step 765: Fingers [-, -, -, -, -] Arm [-, -, 149]
  servo[7].write(149); // Wrist

  // Step 766: Fingers [-, -, -, -, -] Arm [-, -, 148]
  servo[7].write(148); // Wrist

  // Step 767: Fingers [-, -, -, -, -] Arm [-, -, 148]
  servo[7].write(148); // Wrist

  // Step 768: Fingers [-, -, -, -, -] Arm [-, -, 147]
  servo[7].write(147); // Wrist

  // Step 769: Fingers [-, -, -, -, -] Arm [-, -, 147]
  servo[7].write(147); // Wrist

  // Step 770: Fingers [-, -, -, -, -] Arm [-, -, 147]
  servo[7].write(147); // Wrist

  delay(13);
  // Step 771: Fingers [-, -, -, -, -] Arm [-, -, 146]
  servo[7].write(146); // Wrist

  delay(14);
  // Step 772: Fingers [-, -, -, -, -] Arm [-, -, 146]
  servo[7].write(146); // Wrist

  // Step 773: Fingers [-, -, -, -, -] Arm [-, -, 145]
  servo[7].write(145); // Wrist

  // Step 774: Fingers [-, -, -, -, -] Arm [-, -, 145]
  servo[7].write(145); // Wrist

  delay(17);
  // Step 775: Fingers [-, -, -, -, -] Arm [-, -, 145]
  servo[7].write(145); // Wrist

  // Step 776: Fingers [-, -, -, -, -] Arm [-, -, 144]
  servo[7].write(144); // Wrist

  // Step 777: Fingers [-, -, -, -, -] Arm [-, -, 144]
  servo[7].write(144); // Wrist

  delay(13);
  // Step 778: Fingers [-, -, -, -, -] Arm [-, -, 143]
  servo[7].write(143); // Wrist

  // Step 779: Fingers [-, -, -, -, -] Arm [-, -, 143]
  servo[7].write(143); // Wrist

  delay(13);
  // Step 780: Fingers [-, -, -, -, -] Arm [-, -, 142]
  servo[7].write(142); // Wrist

  delay(12);
  // Step 781: Fingers [-, -, -, -, -] Arm [-, -, 142]
  servo[7].write(142); // Wrist

  // Step 782: Fingers [-, -, -, -, -] Arm [-, -, 142]
  servo[7].write(142); // Wrist

  delay(23);
  // Step 783: Fingers [-, -, -, -, -] Arm [-, -, 141]
  servo[7].write(141); // Wrist

  // Step 784: Fingers [-, -, -, -, -] Arm [-, -, 141]
  servo[7].write(141); // Wrist

  delay(28);
  // Step 785: Fingers [-, -, -, -, -] Arm [-, -, 141]
  servo[7].write(141); // Wrist

  delay(24);
  // Step 786: Fingers [-, -, -, -, -] Arm [-, -, 141]
  servo[7].write(141); // Wrist

  // Step 787: Fingers [-, -, -, -, -] Arm [-, -, 141]
  servo[7].write(141); // Wrist

  // Step 788: Fingers [-, -, -, -, -] Arm [-, -, 140]
  servo[7].write(140); // Wrist

  // Step 789: Fingers [-, -, -, -, -] Arm [-, -, 140]
  servo[7].write(140); // Wrist

  // Step 790: Fingers [-, -, -, -, -] Arm [-, -, 139]
  servo[7].write(139); // Wrist

  // Step 791: Fingers [-, -, -, -, -] Arm [-, -, 139]
  servo[7].write(139); // Wrist

  // Step 792: Fingers [-, -, -, -, -] Arm [-, -, 138]
  servo[7].write(138); // Wrist

  // Step 793: Fingers [-, -, -, -, -] Arm [-, -, 138]
  servo[7].write(138); // Wrist

  delay(17);
  // Step 794: Fingers [-, -, -, -, -] Arm [-, -, 138]
  servo[7].write(138); // Wrist

  // Step 795: Fingers [-, -, -, -, -] Arm [-, -, 137]
  servo[7].write(137); // Wrist

  // Step 796: Fingers [-, -, -, -, -] Arm [-, -, 137]
  servo[7].write(137); // Wrist

  // Step 797: Fingers [-, -, -, -, -] Arm [-, -, 136]
  servo[7].write(136); // Wrist

  delay(15);
  // Step 798: Fingers [-, -, -, -, -] Arm [-, -, 136]
  servo[7].write(136); // Wrist

  // Step 799: Fingers [-, -, -, -, -] Arm [-, -, 136]
  servo[7].write(136); // Wrist

  // Step 800: Fingers [-, -, -, -, -] Arm [-, -, 135]
  servo[7].write(135); // Wrist

  // Step 801: Fingers [-, -, -, -, -] Arm [-, -, 135]
  servo[7].write(135); // Wrist

  // Step 802: Fingers [-, -, -, -, -] Arm [-, -, 134]
  servo[7].write(134); // Wrist

  // Step 803: Fingers [-, -, -, -, -] Arm [-, -, 134]
  servo[7].write(134); // Wrist

  delay(11);
  // Step 804: Fingers [-, -, -, -, -] Arm [-, -, 133]
  servo[7].write(133); // Wrist

  // Step 805: Fingers [-, -, -, -, -] Arm [-, -, 133]
  servo[7].write(133); // Wrist

  // Step 806: Fingers [-, -, -, -, -] Arm [-, -, 133]
  servo[7].write(133); // Wrist

  // Step 807: Fingers [-, -, -, -, -] Arm [-, -, 132]
  servo[7].write(132); // Wrist

  // Step 808: Fingers [-, -, -, -, -] Arm [-, -, 132]
  servo[7].write(132); // Wrist

  // Step 809: Fingers [-, -, -, -, -] Arm [-, -, 131]
  servo[7].write(131); // Wrist

  // Step 810: Fingers [-, -, -, -, -] Arm [-, -, 131]
  servo[7].write(131); // Wrist

  // Step 811: Fingers [-, -, -, -, -] Arm [-, -, 131]
  servo[7].write(131); // Wrist

  // Step 812: Fingers [-, -, -, -, -] Arm [-, -, 130]
  servo[7].write(130); // Wrist

  // Step 813: Fingers [-, -, -, -, -] Arm [-, -, 129]
  servo[7].write(129); // Wrist

  delay(12);
  // Step 814: Fingers [-, -, -, -, -] Arm [-, -, 129]
  servo[7].write(129); // Wrist

  // Step 815: Fingers [-, -, -, -, -] Arm [-, -, 128]
  servo[7].write(128); // Wrist

  // Step 816: Fingers [-, -, -, -, -] Arm [-, -, 128]
  servo[7].write(128); // Wrist

  // Step 817: Fingers [-, -, -, -, -] Arm [-, -, 127]
  servo[7].write(127); // Wrist

  // Step 818: Fingers [-, -, -, -, -] Arm [-, -, 127]
  servo[7].write(127); // Wrist

  // Step 819: Fingers [-, -, -, -, -] Arm [-, -, 127]
  servo[7].write(127); // Wrist

  // Step 820: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 821: Fingers [-, -, -, -, -] Arm [-, -, 125]
  servo[7].write(125); // Wrist

  // Step 822: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  // Step 823: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  // Step 824: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  delay(18);
  // Step 825: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  // Step 826: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  delay(14);
  // Step 827: Fingers [-, -, -, -, -] Arm [-, -, 122]
  servo[7].write(122); // Wrist

  // Step 828: Fingers [-, -, -, -, -] Arm [-, -, 122]
  servo[7].write(122); // Wrist

  // Step 829: Fingers [-, -, -, -, -] Arm [-, -, 122]
  servo[7].write(122); // Wrist

  // Step 830: Fingers [-, -, -, -, -] Arm [-, -, 121]
  servo[7].write(121); // Wrist

  delay(11);
  // Step 831: Fingers [-, -, -, -, -] Arm [-, -, 120]
  servo[7].write(120); // Wrist

  // Step 832: Fingers [-, -, -, -, -] Arm [-, -, 120]
  servo[7].write(120); // Wrist

  // Step 833: Fingers [-, -, -, -, -] Arm [-, -, 119]
  servo[7].write(119); // Wrist

  // Step 834: Fingers [-, -, -, -, -] Arm [-, -, 119]
  servo[7].write(119); // Wrist

  // Step 835: Fingers [-, -, -, -, -] Arm [-, -, 118]
  servo[7].write(118); // Wrist

  // Step 836: Fingers [-, -, -, -, -] Arm [-, -, 117]
  servo[7].write(117); // Wrist

  // Step 837: Fingers [-, -, -, -, -] Arm [-, -, 117]
  servo[7].write(117); // Wrist

  // Step 838: Fingers [-, -, -, -, -] Arm [-, -, 117]
  servo[7].write(117); // Wrist

  // Step 839: Fingers [-, -, -, -, -] Arm [-, -, 116]
  servo[7].write(116); // Wrist

  // Step 840: Fingers [-, -, -, -, -] Arm [-, -, 115]
  servo[7].write(115); // Wrist

  delay(17);
  // Step 841: Fingers [-, -, -, -, -] Arm [-, -, 115]
  servo[7].write(115); // Wrist

  // Step 842: Fingers [-, -, -, -, -] Arm [-, -, 115]
  servo[7].write(115); // Wrist

  // Step 843: Fingers [-, -, -, -, -] Arm [-, -, 114]
  servo[7].write(114); // Wrist

  // Step 844: Fingers [-, -, -, -, -] Arm [-, -, 113]
  servo[7].write(113); // Wrist

  // Step 845: Fingers [-, -, -, -, -] Arm [-, -, 113]
  servo[7].write(113); // Wrist

  // Step 846: Fingers [-, -, -, -, -] Arm [-, -, 113]
  servo[7].write(113); // Wrist

  // Step 847: Fingers [-, -, -, -, -] Arm [-, -, 112]
  servo[7].write(112); // Wrist

  // Step 848: Fingers [-, -, -, -, -] Arm [-, -, 111]
  servo[7].write(111); // Wrist

  // Step 849: Fingers [-, -, -, -, -] Arm [-, -, 110]
  servo[7].write(110); // Wrist

  // Step 850: Fingers [-, -, -, -, -] Arm [-, -, 110]
  servo[7].write(110); // Wrist

  // Step 851: Fingers [-, -, -, -, -] Arm [-, -, 110]
  servo[7].write(110); // Wrist

  // Step 852: Fingers [-, -, -, -, -] Arm [-, -, 109]
  servo[7].write(109); // Wrist

  delay(13);
  // Step 853: Fingers [-, -, -, -, -] Arm [-, -, 108]
  servo[7].write(108); // Wrist

  // Step 854: Fingers [-, -, -, -, -] Arm [-, -, 108]
  servo[7].write(108); // Wrist

  // Step 855: Fingers [-, -, -, -, -] Arm [-, -, 108]
  servo[7].write(108); // Wrist

  delay(25);
  // Step 856: Fingers [-, -, -, -, -] Arm [-, -, 108]
  servo[7].write(108); // Wrist

  delay(21);
  // Step 857: Fingers [-, -, -, -, -] Arm [-, -, 107]
  servo[7].write(107); // Wrist

  // Step 858: Fingers [-, -, -, -, -] Arm [-, -, 107]
  servo[7].write(107); // Wrist

  // Step 859: Fingers [-, -, -, -, -] Arm [-, -, 107]
  servo[7].write(107); // Wrist

  // Step 860: Fingers [-, -, -, -, -] Arm [-, -, 106]
  servo[7].write(106); // Wrist

  delay(22);
  // Step 861: Fingers [-, -, -, -, -] Arm [-, -, 106]
  servo[7].write(106); // Wrist

  // Step 862: Fingers [-, -, -, -, -] Arm [-, -, 106]
  servo[7].write(106); // Wrist

  // Step 863: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  delay(15);
  // Step 864: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 865: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 866: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  // Step 867: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  // Step 868: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  delay(11);
  // Step 869: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(15);
  // Step 870: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 871: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 872: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 873: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 874: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 875: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 876: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 877: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 878: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 879: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  delay(12);
  // Step 880: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 881: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 882: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 883: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 884: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 885: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 886: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 887: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  delay(19);
  // Step 888: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 889: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 890: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 891: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  delay(16);
  // Step 892: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 893: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 894: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 895: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 896: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 897: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 898: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 899: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 900: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 901: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  delay(12);
  // Step 902: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 903: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 904: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 905: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 906: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 907: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 908: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 909: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 910: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 911: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 912: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 913: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 914: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 915: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 916: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 917: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 918: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  // Step 919: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  // Step 920: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  delay(15);
  // Step 921: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 922: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 923: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 924: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 925: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 926: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 927: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 928: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 929: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 930: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 931: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 932: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 933: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 934: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 935: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 936: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 937: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 938: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 939: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 940: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 941: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 942: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 943: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 944: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 945: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 946: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  delay(12);
  // Step 947: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 948: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  delay(18);
  // Step 949: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 950: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  delay(28);
  // Step 951: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  delay(34);
  // Step 952: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  delay(14);
  // Step 953: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  delay(17);
  // Step 954: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  delay(15);
  // Step 955: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 956: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 957: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 958: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 959: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  delay(12);
  // Step 960: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 961: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  delay(11);
  // Step 962: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  delay(16);
  // Step 963: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 964: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  delay(26);
  // Step 965: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 966: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 967: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 968: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 969: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(13);
  // Step 970: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(26);
  // Step 971: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(11);
  // Step 972: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(18);
  // Step 973: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(29);
  // Step 974: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(17);
  // Step 975: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(14);
  // Step 976: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 977: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 978: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 979: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 980: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 981: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(17);
  // Step 982: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(24);
  // Step 983: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 984: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(12);
  // Step 985: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(14);
  // Step 986: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(15);
  // Step 987: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(13);
  // Step 988: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(29);
  // Step 989: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(20);
  // Step 990: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 991: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(21);
  // Step 992: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 993: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(31);
  // Step 994: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(23);
  // Step 995: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 996: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(28);
  // Step 997: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 998: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 999: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 1000: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(13);
  // Step 1001: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 1002: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 1003: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 1004: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(18);
  // Step 1005: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 1006: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 1007: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(15);
  // Step 1008: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 1009: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 1010: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 1011: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 1012: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  delay(12);
  // Step 1013: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 1014: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  delay(12);
  // Step 1015: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  delay(17);
  // Step 1016: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  delay(14);
  // Step 1017: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 1018: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  delay(11);
  // Step 1019: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 1020: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 1021: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 1022: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  delay(20);
  // Step 1023: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 1024: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  delay(15);
  // Step 1025: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 1026: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  delay(28);
  // Step 1027: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 1028: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 1029: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  delay(15);
  // Step 1030: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  delay(18);
  // Step 1031: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  delay(14);
  // Step 1032: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 1033: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 1034: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 1035: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 1036: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 1037: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  delay(19);
  // Step 1038: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 1039: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  delay(19);
  // Step 1040: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  delay(27);
  // Step 1041: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 1042: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  delay(25);
  // Step 1043: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 1044: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 1045: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  delay(14);
  // Step 1046: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 1047: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  delay(22);
  // Step 1048: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 1049: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  delay(16);
  // Step 1050: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 1051: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 1052: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  delay(13);
  // Step 1053: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  delay(14);
  // Step 1054: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  delay(17);
  // Step 1055: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 1056: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  delay(14);
  // Step 1057: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  delay(16);
  // Step 1058: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 1059: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  delay(23);
  // Step 1060: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 1061: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  delay(21);
  // Step 1062: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  delay(25);
  // Step 1063: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 1064: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  delay(14);
  // Step 1065: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 1066: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 1067: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 1068: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  delay(12);
  // Step 1069: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 1070: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 1071: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 1072: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  delay(16);
  // Step 1073: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 1074: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 1075: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 1076: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 1077: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 1078: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  // Step 1079: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  // Step 1080: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 1081: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 1082: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 1083: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 1084: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  delay(13);
  // Step 1085: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 1086: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 1087: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 1088: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  delay(13);
  // Step 1089: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 1090: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 1091: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 1092: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  delay(15);
  // Step 1093: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 1094: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 1095: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 1096: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  delay(12);
  // Step 1097: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 1098: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 1099: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  delay(15);
  // Step 1100: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 1101: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 1102: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 1103: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 1104: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 1105: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 1106: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 1107: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 1108: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 1109: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 1110: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  delay(17);
  // Step 1111: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 1112: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 1113: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 1114: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  delay(16);
  // Step 1115: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 1116: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  delay(24);
  // Step 1117: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 1118: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  delay(15);
  // Step 1119: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 1120: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 1121: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 1122: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 1123: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 1124: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 1125: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 1126: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 1127: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  delay(14);
  // Step 1128: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  delay(11);
  // Step 1129: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 1130: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 1131: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 1132: Fingers [-, -, -, -, -] Arm [-, -, 89]
  servo[7].write(89); // Wrist

  // Step 1133: Fingers [-, -, -, -, -] Arm [-, -, 89]
  servo[7].write(89); // Wrist

  // Step 1134: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 1135: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 1136: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 1137: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 1138: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 1139: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 1140: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 1141: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  delay(13);
  // Step 1142: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 1143: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 1144: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 1145: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 1146: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 1147: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 1148: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 1149: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  delay(16);
  // Step 1150: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 1151: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 1152: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 1153: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 1154: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 1155: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 1156: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 1157: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 1158: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 1159: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 1160: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 1161: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 1162: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  delay(14);
  // Step 1163: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  delay(32);
  // Step 1164: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 1165: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  delay(23);
  // Step 1166: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 1167: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  delay(15);
  // Step 1168: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 1169: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 1170: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 1171: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 1172: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 1173: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 1174: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 1175: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 1176: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  // Step 1177: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  // Step 1178: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 1179: Fingers [-, -, -, -, -] Arm [-, -, 106]
  servo[7].write(106); // Wrist

  // Step 1180: Fingers [-, -, -, -, -] Arm [-, -, 106]
  servo[7].write(106); // Wrist

  // Step 1181: Fingers [-, -, -, -, -] Arm [-, -, 107]
  servo[7].write(107); // Wrist

  // Step 1182: Fingers [-, -, -, -, -] Arm [-, -, 107]
  servo[7].write(107); // Wrist

  // Step 1183: Fingers [-, -, -, -, -] Arm [-, -, 108]
  servo[7].write(108); // Wrist

  // Step 1184: Fingers [-, -, -, -, -] Arm [-, -, 109]
  servo[7].write(109); // Wrist

  // Step 1185: Fingers [-, -, -, -, -] Arm [-, -, 109]
  servo[7].write(109); // Wrist

  // Step 1186: Fingers [-, -, -, -, -] Arm [-, -, 109]
  servo[7].write(109); // Wrist

  // Step 1187: Fingers [-, -, -, -, -] Arm [-, -, 110]
  servo[7].write(110); // Wrist

  // Step 1188: Fingers [-, -, -, -, -] Arm [-, -, 111]
  servo[7].write(111); // Wrist

  // Step 1189: Fingers [-, -, -, -, -] Arm [-, -, 111]
  servo[7].write(111); // Wrist

  // Step 1190: Fingers [-, -, -, -, -] Arm [-, -, 111]
  servo[7].write(111); // Wrist

  // Step 1191: Fingers [-, -, -, -, -] Arm [-, -, 111]
  servo[7].write(111); // Wrist

  // Step 1192: Fingers [-, -, -, -, -] Arm [-, -, 112]
  servo[7].write(112); // Wrist

  // Step 1193: Fingers [-, -, -, -, -] Arm [-, -, 113]
  servo[7].write(113); // Wrist

  // Step 1194: Fingers [-, -, -, -, -] Arm [-, -, 113]
  servo[7].write(113); // Wrist

  delay(12);
  // Step 1195: Fingers [-, -, -, -, -] Arm [-, -, 113]
  servo[7].write(113); // Wrist

  delay(12);
  // Step 1196: Fingers [-, -, -, -, -] Arm [-, -, 114]
  servo[7].write(114); // Wrist

  // Step 1197: Fingers [-, -, -, -, -] Arm [-, -, 114]
  servo[7].write(114); // Wrist

  delay(39);
  // Step 1198: Fingers [-, -, -, -, -] Arm [-, -, 114]
  servo[7].write(114); // Wrist

  // Step 1199: Fingers [-, -, -, -, -] Arm [-, -, 114]
  servo[7].write(114); // Wrist

  delay(15);
  // Step 1200: Fingers [-, -, -, -, -] Arm [-, -, 115]
  servo[7].write(115); // Wrist

  // Step 1201: Fingers [-, -, -, -, -] Arm [-, -, 115]
  servo[7].write(115); // Wrist

  delay(14);
  // Step 1202: Fingers [-, -, -, -, -] Arm [-, -, 115]
  servo[7].write(115); // Wrist

  // Step 1203: Fingers [-, -, -, -, -] Arm [-, -, 116]
  servo[7].write(116); // Wrist

  // Step 1204: Fingers [-, -, -, -, -] Arm [-, -, 116]
  servo[7].write(116); // Wrist

  // Step 1205: Fingers [-, -, -, -, -] Arm [-, -, 116]
  servo[7].write(116); // Wrist

  // Step 1206: Fingers [-, -, -, -, -] Arm [-, -, 117]
  servo[7].write(117); // Wrist

  delay(19);
  // Step 1207: Fingers [-, -, -, -, -] Arm [-, -, 117]
  servo[7].write(117); // Wrist

  // Step 1208: Fingers [-, -, -, -, -] Arm [-, -, 117]
  servo[7].write(117); // Wrist

  delay(14);
  // Step 1209: Fingers [-, -, -, -, -] Arm [-, -, 118]
  servo[7].write(118); // Wrist

  // Step 1210: Fingers [-, -, -, -, -] Arm [-, -, 118]
  servo[7].write(118); // Wrist

  delay(13);
  // Step 1211: Fingers [-, -, -, -, -] Arm [-, -, 118]
  servo[7].write(118); // Wrist

  delay(16);
  // Step 1212: Fingers [-, -, -, -, -] Arm [-, -, 118]
  servo[7].write(118); // Wrist

  delay(31);
  // Step 1213: Fingers [-, -, -, -, -] Arm [-, -, 118]
  servo[7].write(118); // Wrist

  // Step 1214: Fingers [-, -, -, -, -] Arm [-, -, 119]
  servo[7].write(119); // Wrist

  delay(22);
  // Step 1215: Fingers [-, -, -, -, -] Arm [-, -, 119]
  servo[7].write(119); // Wrist

  // Step 1216: Fingers [-, -, -, -, -] Arm [-, -, 119]
  servo[7].write(119); // Wrist

  // Step 1217: Fingers [-, -, -, -, -] Arm [-, -, 120]
  servo[7].write(120); // Wrist

  delay(20);
  // Step 1218: Fingers [-, -, -, -, -] Arm [-, -, 120]
  servo[7].write(120); // Wrist

  // Step 1219: Fingers [-, -, -, -, -] Arm [-, -, 120]
  servo[7].write(120); // Wrist

  // Step 1220: Fingers [-, -, -, -, -] Arm [-, -, 121]
  servo[7].write(121); // Wrist

  // Step 1221: Fingers [-, -, -, -, -] Arm [-, -, 121]
  servo[7].write(121); // Wrist

  delay(11);
  // Step 1222: Fingers [-, -, -, -, -] Arm [-, -, 121]
  servo[7].write(121); // Wrist

  // Step 1223: Fingers [-, -, -, -, -] Arm [-, -, 122]
  servo[7].write(122); // Wrist

  // Step 1224: Fingers [-, -, -, -, -] Arm [-, -, 122]
  servo[7].write(122); // Wrist

  // Step 1225: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  // Step 1226: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  // Step 1227: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  // Step 1228: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  // Step 1229: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  delay(15);
  // Step 1230: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  delay(35);
  // Step 1231: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  delay(12);
  // Step 1232: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  delay(18);
  // Step 1233: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  // Step 1234: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  delay(24);
  // Step 1235: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  // Step 1236: Fingers [-, -, -, -, -] Arm [-, -, 125]
  servo[7].write(125); // Wrist

  delay(14);
  // Step 1237: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 1238: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(32);
  // Step 1239: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(28);
  // Step 1240: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(19);
  // Step 1241: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(11);
  // Step 1242: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(27);
  // Step 1243: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 1244: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(25);
  // Step 1245: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(30);
  // Step 1246: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 1247: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(26);
  // Step 1248: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(12);
  // Step 1249: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(17);
  // Step 1250: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(30);
  // Step 1251: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(30);
  // Step 1252: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 1253: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(21);
  // Step 1254: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(31);
  // Step 1255: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(20);
  // Step 1256: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(11);
  // Step 1257: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(30);
  // Step 1258: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(20);
  // Step 1259: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 1260: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 1261: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 1262: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(12);
  // Step 1263: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 1264: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 1265: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(14);
  // Step 1266: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 1267: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(16);
  // Step 1268: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(24);
  // Step 1269: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  delay(31);
  // Step 1270: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 1271: Fingers [-, -, -, -, -] Arm [-, -, 126]
  servo[7].write(126); // Wrist

  // Step 1272: Fingers [-, -, -, -, -] Arm [-, -, 125]
  servo[7].write(125); // Wrist

  delay(13);
  // Step 1273: Fingers [-, -, -, -, -] Arm [-, -, 125]
  servo[7].write(125); // Wrist

  // Step 1274: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  delay(16);
  // Step 1275: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  // Step 1276: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  // Step 1277: Fingers [-, -, -, -, -] Arm [-, -, 124]
  servo[7].write(124); // Wrist

  delay(16);
  // Step 1278: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  // Step 1279: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  // Step 1280: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  delay(17);
  // Step 1281: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  // Step 1282: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  // Step 1283: Fingers [-, -, -, -, -] Arm [-, -, 123]
  servo[7].write(123); // Wrist

  delay(13);
  // Step 1284: Fingers [-, -, -, -, -] Arm [-, -, 122]
  servo[7].write(122); // Wrist

  // Step 1285: Fingers [-, -, -, -, -] Arm [-, -, 122]
  servo[7].write(122); // Wrist

  // Step 1286: Fingers [-, -, -, -, -] Arm [-, -, 122]
  servo[7].write(122); // Wrist

  delay(11);
  // Step 1287: Fingers [-, -, -, -, -] Arm [-, -, 121]
  servo[7].write(121); // Wrist

  // Step 1288: Fingers [-, -, -, -, -] Arm [-, -, 121]
  servo[7].write(121); // Wrist

  // Step 1289: Fingers [-, -, -, -, -] Arm [-, -, 120]
  servo[7].write(120); // Wrist

  // Step 1290: Fingers [-, -, -, -, -] Arm [-, -, 120]
  servo[7].write(120); // Wrist

  // Step 1291: Fingers [-, -, -, -, -] Arm [-, -, 120]
  servo[7].write(120); // Wrist

  // Step 1292: Fingers [-, -, -, -, -] Arm [-, -, 120]
  servo[7].write(120); // Wrist

  // Step 1293: Fingers [-, -, -, -, -] Arm [-, -, 119]
  servo[7].write(119); // Wrist

  // Step 1294: Fingers [-, -, -, -, -] Arm [-, -, 119]
  servo[7].write(119); // Wrist

  // Step 1295: Fingers [-, -, -, -, -] Arm [-, -, 118]
  servo[7].write(118); // Wrist

  delay(12);
  // Step 1296: Fingers [-, -, -, -, -] Arm [-, -, 118]
  servo[7].write(118); // Wrist

  // Step 1297: Fingers [-, -, -, -, -] Arm [-, -, 117]
  servo[7].write(117); // Wrist

  // Step 1298: Fingers [-, -, -, -, -] Arm [-, -, 117]
  servo[7].write(117); // Wrist

  // Step 1299: Fingers [-, -, -, -, -] Arm [-, -, 116]
  servo[7].write(116); // Wrist

  delay(12);
  // Step 1300: Fingers [-, -, -, -, -] Arm [-, -, 116]
  servo[7].write(116); // Wrist

  // Step 1301: Fingers [-, -, -, -, -] Arm [-, -, 116]
  servo[7].write(116); // Wrist

  delay(24);
  // Step 1302: Fingers [-, -, -, -, -] Arm [-, -, 116]
  servo[7].write(116); // Wrist

  // Step 1303: Fingers [-, -, -, -, -] Arm [-, -, 115]
  servo[7].write(115); // Wrist

  // Step 1304: Fingers [-, -, -, -, -] Arm [-, -, 115]
  servo[7].write(115); // Wrist

  // Step 1305: Fingers [-, -, -, -, -] Arm [-, -, 115]
  servo[7].write(115); // Wrist

  // Step 1306: Fingers [-, -, -, -, -] Arm [-, -, 115]
  servo[7].write(115); // Wrist

  // Step 1307: Fingers [-, -, -, -, -] Arm [-, -, 114]
  servo[7].write(114); // Wrist

  // Step 1308: Fingers [-, -, -, -, -] Arm [-, -, 114]
  servo[7].write(114); // Wrist

  // Step 1309: Fingers [-, -, -, -, -] Arm [-, -, 114]
  servo[7].write(114); // Wrist

  // Step 1310: Fingers [-, -, -, -, -] Arm [-, -, 114]
  servo[7].write(114); // Wrist

  // Step 1311: Fingers [-, -, -, -, -] Arm [-, -, 113]
  servo[7].write(113); // Wrist

  delay(17);
  // Step 1312: Fingers [-, -, -, -, -] Arm [-, -, 113]
  servo[7].write(113); // Wrist

  // Step 1313: Fingers [-, -, -, -, -] Arm [-, -, 112]
  servo[7].write(112); // Wrist

  // Step 1314: Fingers [-, -, -, -, -] Arm [-, -, 112]
  servo[7].write(112); // Wrist

  // Step 1315: Fingers [-, -, -, -, -] Arm [-, -, 111]
  servo[7].write(111); // Wrist

  // Step 1316: Fingers [-, -, -, -, -] Arm [-, -, 111]
  servo[7].write(111); // Wrist

  // Step 1317: Fingers [-, -, -, -, -] Arm [-, -, 111]
  servo[7].write(111); // Wrist

  // Step 1318: Fingers [-, -, -, -, -] Arm [-, -, 110]
  servo[7].write(110); // Wrist

  delay(11);
  // Step 1319: Fingers [-, -, -, -, -] Arm [-, -, 110]
  servo[7].write(110); // Wrist

  // Step 1320: Fingers [-, -, -, -, -] Arm [-, -, 110]
  servo[7].write(110); // Wrist

  delay(15);
  // Step 1321: Fingers [-, -, -, -, -] Arm [-, -, 109]
  servo[7].write(109); // Wrist

  // Step 1322: Fingers [-, -, -, -, -] Arm [-, -, 109]
  servo[7].write(109); // Wrist

  // Step 1323: Fingers [-, -, -, -, -] Arm [-, -, 109]
  servo[7].write(109); // Wrist

  delay(16);
  // Step 1324: Fingers [-, -, -, -, -] Arm [-, -, 108]
  servo[7].write(108); // Wrist

  // Step 1325: Fingers [-, -, -, -, -] Arm [-, -, 108]
  servo[7].write(108); // Wrist

  delay(15);
  // Step 1326: Fingers [-, -, -, -, -] Arm [-, -, 107]
  servo[7].write(107); // Wrist

  delay(15);
  // Step 1327: Fingers [-, -, -, -, -] Arm [-, -, 107]
  servo[7].write(107); // Wrist

  // Step 1328: Fingers [-, -, -, -, -] Arm [-, -, 106]
  servo[7].write(106); // Wrist

  delay(27);
  // Step 1329: Fingers [-, -, -, -, -] Arm [-, -, 106]
  servo[7].write(106); // Wrist

  // Step 1330: Fingers [-, -, -, -, -] Arm [-, -, 106]
  servo[7].write(106); // Wrist

  delay(20);
  // Step 1331: Fingers [-, -, -, -, -] Arm [-, -, 106]
  servo[7].write(106); // Wrist

  // Step 1332: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  delay(12);
  // Step 1333: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 1334: Fingers [-, -, -, -, -] Arm [-, -, 105]
  servo[7].write(105); // Wrist

  // Step 1335: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  // Step 1336: Fingers [-, -, -, -, -] Arm [-, -, 104]
  servo[7].write(104); // Wrist

  // Step 1337: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 1338: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 1339: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(14);
  // Step 1340: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 1341: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 1342: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  delay(11);
  // Step 1343: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 1344: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 1345: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 1346: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  delay(18);
  // Step 1347: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 1348: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 1349: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  delay(13);
  // Step 1350: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 1351: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  delay(28);
  // Step 1352: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 1353: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  delay(17);
  // Step 1354: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 1355: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 1356: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  delay(14);
  // Step 1357: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 1358: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 1359: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 1360: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 1361: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 1362: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 1363: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  delay(11);
  // Step 1364: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 1365: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 1366: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 1367: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 1368: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  delay(31);
  // Step 1369: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  delay(30);
  // Step 1370: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  delay(29);
  // Step 1371: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  delay(16);
  // Step 1372: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  delay(13);
  // Step 1373: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 1374: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 1375: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 1376: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 1377: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 1378: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 1379: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 1380: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 1381: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 1382: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 1383: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 1384: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 1385: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  delay(17);
  // Step 1386: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 1387: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 1388: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  delay(22);
  // Step 1389: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 1390: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  delay(26);
  // Step 1391: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 1392: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  delay(15);
  // Step 1393: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 1394: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

}

// Layer 2: Layer_3 - manual mode
// Duration: 14.2s, Points: 653
void playLayer2() {
  delay(26);
  // Step 1: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(32);
  // Step 2: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(29);
  // Step 3: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(31);
  // Step 4: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(30);
  // Step 5: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(30);
  // Step 6: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(32);
  // Step 7: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(30);
  // Step 8: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(31);
  // Step 9: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(23);
  // Step 10: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 11: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 12: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(23);
  // Step 13: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 14: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(14);
  // Step 15: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  // Step 16: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(32);
  // Step 17: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  // Step 18: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(18);
  // Step 19: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  // Step 20: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(21);
  // Step 21: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  // Step 22: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 23: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(19);
  // Step 24: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(30);
  // Step 25: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 26: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  // Step 27: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(17);
  // Step 28: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(31);
  // Step 29: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(30);
  // Step 30: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(32);
  // Step 31: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(28);
  // Step 32: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(30);
  // Step 33: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(42);
  // Step 34: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(14);
  // Step 35: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  // Step 36: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 37: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(20);
  // Step 38: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 39: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 40: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  // Step 41: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(21);
  // Step 42: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  // Step 43: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  // Step 44: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(22);
  // Step 45: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  // Step 46: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(18);
  // Step 47: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 48: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(12);
  // Step 49: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(14);
  // Step 50: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(30);
  // Step 51: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(17);
  // Step 52: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(15);
  // Step 53: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  // Step 54: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(25);
  // Step 55: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  // Step 56: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  // Step 57: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(12);
  // Step 58: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(30);
  // Step 59: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(12);
  // Step 60: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(14);
  // Step 61: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  // Step 62: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(20);
  // Step 63: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(26);
  // Step 64: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  // Step 65: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  // Step 66: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(14);
  // Step 67: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  // Step 68: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(38);
  // Step 69: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(20);
  // Step 70: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  // Step 71: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(11);
  // Step 72: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(19);
  // Step 73: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  // Step 74: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(22);
  // Step 75: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(25);
  // Step 76: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  // Step 77: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(17);
  // Step 78: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(14);
  // Step 79: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  // Step 80: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  // Step 81: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  delay(17);
  // Step 82: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  delay(31);
  // Step 83: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  delay(14);
  // Step 84: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(16);
  // Step 85: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(31);
  // Step 86: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(31);
  // Step 87: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(30);
  // Step 88: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(13);
  // Step 89: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(16);
  // Step 90: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(19);
  // Step 91: Fingers [-, -, -, -, -] Arm [-, 130, -]
  servo[6].write(130); // Elbow

  delay(12);
  // Step 92: Fingers [-, -, -, -, -] Arm [-, 130, -]
  servo[6].write(130); // Elbow

  // Step 93: Fingers [-, -, -, -, -] Arm [-, 130, -]
  servo[6].write(130); // Elbow

  delay(22);
  // Step 94: Fingers [-, -, -, -, -] Arm [-, 130, -]
  servo[6].write(130); // Elbow

  delay(31);
  // Step 95: Fingers [-, -, -, -, -] Arm [-, 130, -]
  servo[6].write(130); // Elbow

  delay(31);
  // Step 96: Fingers [-, -, -, -, -] Arm [-, 130, -]
  servo[6].write(130); // Elbow

  delay(31);
  // Step 97: Fingers [-, -, -, -, -] Arm [-, 130, -]
  servo[6].write(130); // Elbow

  delay(31);
  // Step 98: Fingers [-, -, -, -, -] Arm [-, 130, -]
  servo[6].write(130); // Elbow

  delay(18);
  // Step 99: Fingers [-, -, -, -, -] Arm [-, 130, -]
  servo[6].write(130); // Elbow

  delay(12);
  // Step 100: Fingers [-, -, -, -, -] Arm [-, 130, -]
  servo[6].write(130); // Elbow

  // Step 101: Fingers [-, -, -, -, -] Arm [-, 130, -]
  servo[6].write(130); // Elbow

  // Step 102: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(15);
  // Step 103: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(32);
  // Step 104: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  // Step 105: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(12);
  // Step 106: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  // Step 107: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  delay(28);
  // Step 108: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  // Step 109: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  delay(20);
  // Step 110: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  // Step 111: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(32);
  // Step 112: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(25);
  // Step 113: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  // Step 114: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  // Step 115: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(24);
  // Step 116: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  // Step 117: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(14);
  // Step 118: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  // Step 119: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(29);
  // Step 120: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(14);
  // Step 121: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(13);
  // Step 122: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  // Step 123: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(26);
  // Step 124: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  // Step 125: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(14);
  // Step 126: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  // Step 127: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(30);
  // Step 128: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(15);
  // Step 129: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(13);
  // Step 130: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  // Step 131: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(27);
  // Step 132: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(29);
  // Step 133: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(18);
  // Step 134: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(11);
  // Step 135: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  // Step 136: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(24);
  // Step 137: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(25);
  // Step 138: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 139: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 140: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(23);
  // Step 141: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(28);
  // Step 142: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 143: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  // Step 144: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(21);
  // Step 145: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(30);
  // Step 146: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(31);
  // Step 147: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(27);
  // Step 148: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  // Step 149: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(20);
  // Step 150: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  // Step 151: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(21);
  // Step 152: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(27);
  // Step 153: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(29);
  // Step 154: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(21);
  // Step 155: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 156: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(11);
  // Step 157: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(20);
  // Step 158: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(30);
  // Step 159: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 160: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  // Step 161: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(16);
  // Step 162: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(33);
  // Step 163: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(29);
  // Step 164: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(31);
  // Step 165: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(31);
  // Step 166: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(30);
  // Step 167: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(31);
  // Step 168: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(30);
  // Step 169: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(31);
  // Step 170: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  // Step 171: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(23);
  // Step 172: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(31);
  // Step 173: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(29);
  // Step 174: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(32);
  // Step 175: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(33);
  // Step 176: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  // Step 177: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(21);
  // Step 178: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(30);
  // Step 179: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(21);
  // Step 180: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  // Step 181: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  // Step 182: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(21);
  // Step 183: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(29);
  // Step 184: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(31);
  // Step 185: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 186: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 187: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(12);
  // Step 188: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(21);
  // Step 189: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(11);
  // Step 190: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  // Step 191: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(20);
  // Step 192: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(20);
  // Step 193: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(12);
  // Step 194: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  // Step 195: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(19);
  // Step 196: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 197: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(18);
  // Step 198: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 199: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(26);
  // Step 200: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(31);
  // Step 201: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(17);
  // Step 202: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(12);
  // Step 203: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(32);
  // Step 204: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(30);
  // Step 205: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(31);
  // Step 206: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  // Step 207: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(20);
  // Step 208: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(31);
  // Step 209: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(19);
  // Step 210: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(12);
  // Step 211: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  // Step 212: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(23);
  // Step 213: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(30);
  // Step 214: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(29);
  // Step 215: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  // Step 216: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  // Step 217: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(13);
  // Step 218: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  // Step 219: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(29);
  // Step 220: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(20);
  // Step 221: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  // Step 222: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(35);
  // Step 223: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(27);
  // Step 224: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(32);
  // Step 225: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(26);
  // Step 226: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  // Step 227: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(31);
  // Step 228: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(13);
  // Step 229: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(31);
  // Step 230: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(30);
  // Step 231: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  // Step 232: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(23);
  // Step 233: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  // Step 234: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(22);
  // Step 235: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(29);
  // Step 236: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  // Step 237: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(21);
  // Step 238: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  // Step 239: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(23);
  // Step 240: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(11);
  // Step 241: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  delay(17);
  // Step 242: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  // Step 243: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  delay(24);
  // Step 244: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  delay(28);
  // Step 245: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  delay(28);
  // Step 246: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  // Step 247: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(25);
  // Step 248: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(30);
  // Step 249: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(32);
  // Step 250: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  // Step 251: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(20);
  // Step 252: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(32);
  // Step 253: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(31);
  // Step 254: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(32);
  // Step 255: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(13);
  // Step 256: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  delay(15);
  // Step 257: Fingers [-, -, -, -, -] Arm [-, 129, -]
  servo[6].write(129); // Elbow

  // Step 258: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  delay(25);
  // Step 259: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  // Step 260: Fingers [-, -, -, -, -] Arm [-, 128, -]
  servo[6].write(128); // Elbow

  delay(11);
  // Step 261: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  // Step 262: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(32);
  // Step 263: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  // Step 264: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  // Step 265: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(12);
  // Step 266: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(20);
  // Step 267: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(13);
  // Step 268: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  // Step 269: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(21);
  // Step 270: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(32);
  // Step 271: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(29);
  // Step 272: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(28);
  // Step 273: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(19);
  // Step 274: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  // Step 275: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  // Step 276: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(20);
  // Step 277: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(34);
  // Step 278: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  // Step 279: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(22);
  // Step 280: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  // Step 281: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(23);
  // Step 282: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(30);
  // Step 283: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(30);
  // Step 284: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(31);
  // Step 285: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  // Step 286: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(23);
  // Step 287: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(30);
  // Step 288: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(11);
  // Step 289: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(20);
  // Step 290: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(31);
  // Step 291: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(30);
  // Step 292: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(31);
  // Step 293: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(27);
  // Step 294: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  // Step 295: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  // Step 296: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(19);
  // Step 297: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(30);
  // Step 298: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  // Step 299: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 300: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 301: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(30);
  // Step 302: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(27);
  // Step 303: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 304: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(25);
  // Step 305: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  // Step 306: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(23);
  // Step 307: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(29);
  // Step 308: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(31);
  // Step 309: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(31);
  // Step 310: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(30);
  // Step 311: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(30);
  // Step 312: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(15);
  // Step 313: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(13);
  // Step 314: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  // Step 315: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(23);
  // Step 316: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  // Step 317: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 318: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(18);
  // Step 319: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(31);
  // Step 320: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(29);
  // Step 321: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(22);
  // Step 322: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 323: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(31);
  // Step 324: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(32);
  // Step 325: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(30);
  // Step 326: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 327: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(23);
  // Step 328: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(30);
  // Step 329: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(29);
  // Step 330: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  // Step 331: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(26);
  // Step 332: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(31);
  // Step 333: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(31);
  // Step 334: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(30);
  // Step 335: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(31);
  // Step 336: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(30);
  // Step 337: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(30);
  // Step 338: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(31);
  // Step 339: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(30);
  // Step 340: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(15);
  // Step 341: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(15);
  // Step 342: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(12);
  // Step 343: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(14);
  // Step 344: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  // Step 345: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  // Step 346: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(11);
  // Step 347: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(15);
  // Step 348: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(22);
  // Step 349: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 350: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(30);
  // Step 351: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 352: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 353: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(29);
  // Step 354: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 355: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(29);
  // Step 356: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 357: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(30);
  // Step 358: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(30);
  // Step 359: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 360: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(12);
  // Step 361: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(19);
  // Step 362: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(29);
  // Step 363: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(33);
  // Step 364: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  // Step 365: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(22);
  // Step 366: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  // Step 367: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(21);
  // Step 368: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  // Step 369: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  // Step 370: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  // Step 371: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  // Step 372: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  delay(33);
  // Step 373: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  delay(31);
  // Step 374: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  delay(30);
  // Step 375: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  delay(32);
  // Step 376: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  delay(29);
  // Step 377: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  delay(30);
  // Step 378: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  delay(31);
  // Step 379: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  delay(30);
  // Step 380: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  delay(23);
  // Step 381: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  // Step 382: Fingers [-, -, -, -, -] Arm [-, 112, -]
  servo[6].write(112); // Elbow

  delay(12);
  // Step 383: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(20);
  // Step 384: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(30);
  // Step 385: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(12);
  // Step 386: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(13);
  // Step 387: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  // Step 388: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(26);
  // Step 389: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  // Step 390: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(30);
  // Step 391: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  // Step 392: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(26);
  // Step 393: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(31);
  // Step 394: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(31);
  // Step 395: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(14);
  // Step 396: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(15);
  // Step 397: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(31);
  // Step 398: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  // Step 399: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(23);
  // Step 400: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  // Step 401: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(14);
  // Step 402: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(12);
  // Step 403: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(31);
  // Step 404: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(29);
  // Step 405: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(23);
  // Step 406: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 407: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 408: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(20);
  // Step 409: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  // Step 410: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(25);
  // Step 411: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(30);
  // Step 412: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(28);
  // Step 413: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(33);
  // Step 414: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(29);
  // Step 415: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(32);
  // Step 416: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(33);
  // Step 417: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(27);
  // Step 418: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(32);
  // Step 419: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  // Step 420: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(23);
  // Step 421: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(20);
  // Step 422: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  // Step 423: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(32);
  // Step 424: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(31);
  // Step 425: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  // Step 426: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(24);
  // Step 427: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(31);
  // Step 428: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(30);
  // Step 429: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(33);
  // Step 430: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(27);
  // Step 431: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(14);
  // Step 432: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(15);
  // Step 433: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(18);
  // Step 434: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(12);
  // Step 435: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(31);
  // Step 436: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(30);
  // Step 437: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(30);
  // Step 438: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(29);
  // Step 439: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(18);
  // Step 440: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(13);
  // Step 441: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(29);
  // Step 442: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(26);
  // Step 443: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 444: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(28);
  // Step 445: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(29);
  // Step 446: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(31);
  // Step 447: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(12);
  // Step 448: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(20);
  // Step 449: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  // Step 450: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(19);
  // Step 451: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(30);
  // Step 452: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(32);
  // Step 453: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(30);
  // Step 454: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(30);
  // Step 455: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(30);
  // Step 456: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(31);
  // Step 457: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(30);
  // Step 458: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(11);
  // Step 459: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(19);
  // Step 460: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(32);
  // Step 461: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  // Step 462: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(20);
  // Step 463: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(30);
  // Step 464: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(31);
  // Step 465: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(32);
  // Step 466: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(31);
  // Step 467: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(28);
  // Step 468: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(31);
  // Step 469: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(32);
  // Step 470: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(31);
  // Step 471: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  // Step 472: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(19);
  // Step 473: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(32);
  // Step 474: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  // Step 475: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(22);
  // Step 476: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(18);
  // Step 477: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(13);
  // Step 478: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(30);
  // Step 479: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(31);
  // Step 480: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(28);
  // Step 481: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  // Step 482: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(21);
  // Step 483: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(30);
  // Step 484: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(30);
  // Step 485: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(32);
  // Step 486: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(27);
  // Step 487: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(11);
  // Step 488: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(23);
  // Step 489: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(11);
  // Step 490: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(20);
  // Step 491: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(31);
  // Step 492: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(33);
  // Step 493: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(29);
  // Step 494: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(12);
  // Step 495: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(15);
  // Step 496: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(33);
  // Step 497: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(31);
  // Step 498: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(31);
  // Step 499: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(30);
  // Step 500: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(31);
  // Step 501: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(30);
  // Step 502: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(31);
  // Step 503: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(30);
  // Step 504: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(32);
  // Step 505: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(30);
  // Step 506: Fingers [-, -, -, -, -] Arm [-, 127, -]
  servo[6].write(127); // Elbow

  delay(18);
  // Step 507: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(12);
  // Step 508: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(28);
  // Step 509: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(33);
  // Step 510: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(22);
  // Step 511: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(14);
  // Step 512: Fingers [-, -, -, -, -] Arm [-, 126, -]
  servo[6].write(126); // Elbow

  delay(15);
  // Step 513: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(23);
  // Step 514: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(30);
  // Step 515: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(25);
  // Step 516: Fingers [-, -, -, -, -] Arm [-, 125, -]
  servo[6].write(125); // Elbow

  delay(29);
  // Step 517: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  // Step 518: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(33);
  // Step 519: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  // Step 520: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(23);
  // Step 521: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(31);
  // Step 522: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(33);
  // Step 523: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(31);
  // Step 524: Fingers [-, -, -, -, -] Arm [-, 124, -]
  servo[6].write(124); // Elbow

  delay(23);
  // Step 525: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  // Step 526: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(28);
  // Step 527: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  // Step 528: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(26);
  // Step 529: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(30);
  // Step 530: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(32);
  // Step 531: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(30);
  // Step 532: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(32);
  // Step 533: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(29);
  // Step 534: Fingers [-, -, -, -, -] Arm [-, 123, -]
  servo[6].write(123); // Elbow

  delay(16);
  // Step 535: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(13);
  // Step 536: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(31);
  // Step 537: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(30);
  // Step 538: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  // Step 539: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  delay(19);
  // Step 540: Fingers [-, -, -, -, -] Arm [-, 122, -]
  servo[6].write(122); // Elbow

  // Step 541: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(19);
  // Step 542: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  // Step 543: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(31);
  // Step 544: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(31);
  // Step 545: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(30);
  // Step 546: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(33);
  // Step 547: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(28);
  // Step 548: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(31);
  // Step 549: Fingers [-, -, -, -, -] Arm [-, 121, -]
  servo[6].write(121); // Elbow

  delay(14);
  // Step 550: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(13);
  // Step 551: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(30);
  // Step 552: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(31);
  // Step 553: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(21);
  // Step 554: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  // Step 555: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(32);
  // Step 556: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(31);
  // Step 557: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(31);
  // Step 558: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(31);
  // Step 559: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(29);
  // Step 560: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(32);
  // Step 561: Fingers [-, -, -, -, -] Arm [-, 120, -]
  servo[6].write(120); // Elbow

  delay(14);
  // Step 562: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(14);
  // Step 563: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(12);
  // Step 564: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(20);
  // Step 565: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(28);
  // Step 566: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(31);
  // Step 567: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  delay(32);
  // Step 568: Fingers [-, -, -, -, -] Arm [-, 119, -]
  servo[6].write(119); // Elbow

  // Step 569: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  // Step 570: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(17);
  // Step 571: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(30);
  // Step 572: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(29);
  // Step 573: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(31);
  // Step 574: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(29);
  // Step 575: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(31);
  // Step 576: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(30);
  // Step 577: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(33);
  // Step 578: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(42);
  // Step 579: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(30);
  // Step 580: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(32);
  // Step 581: Fingers [-, -, -, -, -] Arm [-, 118, -]
  servo[6].write(118); // Elbow

  delay(21);
  // Step 582: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 583: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(25);
  // Step 584: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  // Step 585: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(34);
  // Step 586: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(31);
  // Step 587: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(33);
  // Step 588: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(29);
  // Step 589: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(27);
  // Step 590: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(32);
  // Step 591: Fingers [-, -, -, -, -] Arm [-, 117, -]
  servo[6].write(117); // Elbow

  delay(16);
  // Step 592: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(14);
  // Step 593: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(30);
  // Step 594: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(11);
  // Step 595: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(20);
  // Step 596: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(29);
  // Step 597: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(33);
  // Step 598: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(30);
  // Step 599: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  delay(25);
  // Step 600: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  // Step 601: Fingers [-, -, -, -, -] Arm [-, 116, -]
  servo[6].write(116); // Elbow

  // Step 602: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(25);
  // Step 603: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(29);
  // Step 604: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(31);
  // Step 605: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(32);
  // Step 606: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(29);
  // Step 607: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(30);
  // Step 608: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(33);
  // Step 609: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(25);
  // Step 610: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  // Step 611: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  delay(31);
  // Step 612: Fingers [-, -, -, -, -] Arm [-, 115, -]
  servo[6].write(115); // Elbow

  // Step 613: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(23);
  // Step 614: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(31);
  // Step 615: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(28);
  // Step 616: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(35);
  // Step 617: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(29);
  // Step 618: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(31);
  // Step 619: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(30);
  // Step 620: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(32);
  // Step 621: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(29);
  // Step 622: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(25);
  // Step 623: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  // Step 624: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(30);
  // Step 625: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(30);
  // Step 626: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  delay(31);
  // Step 627: Fingers [-, -, -, -, -] Arm [-, 114, -]
  servo[6].write(114); // Elbow

  // Step 628: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(21);
  // Step 629: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(32);
  // Step 630: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(30);
  // Step 631: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 632: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 633: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 634: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(30);
  // Step 635: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(30);
  // Step 636: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 637: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 638: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 639: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 640: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(30);
  // Step 641: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 642: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(32);
  // Step 643: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(30);
  // Step 644: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(29);
  // Step 645: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  // Step 646: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  // Step 647: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(17);
  // Step 648: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(31);
  // Step 649: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(30);
  // Step 650: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(30);
  // Step 651: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(45);
  // Step 652: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

  delay(30);
  // Step 653: Fingers [-, -, -, -, -] Arm [-, 113, -]
  servo[6].write(113); // Elbow

}

// Layer 3: Layer_4 - manual mode
// Duration: 14.2s, Points: 827
void playLayer3() {
  // Step 1: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  delay(25);
  // Step 2: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  delay(15);
  // Step 3: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  delay(12);
  // Step 4: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  delay(27);
  // Step 5: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  delay(13);
  // Step 6: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(16);
  // Step 7: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(28);
  // Step 8: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(12);
  // Step 9: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  // Step 10: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  // Step 11: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  // Step 12: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  // Step 13: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(14);
  // Step 14: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(17);
  // Step 15: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(19);
  // Step 16: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(21);
  // Step 17: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  // Step 18: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(30);
  // Step 19: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(35);
  // Step 20: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  // Step 21: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(13);
  // Step 22: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  // Step 23: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(29);
  // Step 24: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(31);
  // Step 25: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(29);
  // Step 26: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(32);
  // Step 27: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  // Step 28: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(20);
  // Step 29: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(29);
  // Step 30: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(32);
  // Step 31: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(29);
  // Step 32: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(32);
  // Step 33: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(19);
  // Step 34: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(23);
  // Step 35: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  // Step 36: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(25);
  // Step 37: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(29);
  // Step 38: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(19);
  // Step 39: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(11);
  // Step 40: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(19);
  // Step 41: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 42: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(13);
  // Step 43: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(17);
  // Step 44: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(31);
  // Step 45: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 46: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 47: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(16);
  // Step 48: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(31);
  // Step 49: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(19);
  // Step 50: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(11);
  // Step 51: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(18);
  // Step 52: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(14);
  // Step 53: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(25);
  // Step 54: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  // Step 55: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(32);
  // Step 56: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(28);
  // Step 57: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  // Step 58: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(24);
  // Step 59: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(32);
  // Step 60: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(32);
  // Step 61: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  // Step 62: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(23);
  // Step 63: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  // Step 64: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(24);
  // Step 65: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(29);
  // Step 66: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(11);
  // Step 67: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(20);
  // Step 68: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(16);
  // Step 69: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(14);
  // Step 70: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(12);
  // Step 71: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(16);
  // Step 72: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(29);
  // Step 73: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  // Step 74: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(25);
  // Step 75: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(29);
  // Step 76: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(31);
  // Step 77: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(31);
  // Step 78: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(29);
  // Step 79: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(19);
  // Step 80: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(13);
  // Step 81: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(28);
  // Step 82: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(14);
  // Step 83: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(15);
  // Step 84: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(25);
  // Step 85: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 86: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(30);
  // Step 87: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(18);
  // Step 88: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(13);
  // Step 89: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(30);
  // Step 90: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(32);
  // Step 91: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(31);
  // Step 92: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(30);
  // Step 93: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(15);
  // Step 94: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(17);
  // Step 95: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(28);
  // Step 96: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(30);
  // Step 97: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 98: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(20);
  // Step 99: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(20);
  // Step 100: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(12);
  // Step 101: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(29);
  // Step 102: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 103: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(20);
  // Step 104: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(31);
  // Step 105: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  // Step 106: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(23);
  // Step 107: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(11);
  // Step 108: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(14);
  // Step 109: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  // Step 110: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(29);
  // Step 111: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  // Step 112: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  // Step 113: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  // Step 114: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  // Step 115: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(12);
  // Step 116: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  // Step 117: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  // Step 118: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(25);
  // Step 119: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(23);
  // Step 120: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 121: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(27);
  // Step 122: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(32);
  // Step 123: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 124: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 125: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(14);
  // Step 126: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 127: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(12);
  // Step 128: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(24);
  // Step 129: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(34);
  // Step 130: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 131: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(22);
  // Step 132: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(17);
  // Step 133: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(12);
  // Step 134: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(32);
  // Step 135: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  // Step 136: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(19);
  // Step 137: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  // Step 138: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(24);
  // Step 139: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(29);
  // Step 140: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  // Step 141: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(23);
  // Step 142: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(13);
  // Step 143: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(14);
  // Step 144: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(31);
  // Step 145: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  // Step 146: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(23);
  // Step 147: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  // Step 148: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(22);
  // Step 149: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(11);
  // Step 150: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  // Step 151: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  delay(11);
  // Step 152: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  // Step 153: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  delay(17);
  // Step 154: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  // Step 155: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  delay(14);
  // Step 156: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  delay(14);
  // Step 157: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  delay(25);
  // Step 158: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  // Step 159: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  delay(37);
  // Step 160: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  delay(19);
  // Step 161: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  // Step 162: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  // Step 163: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  // Step 164: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  // Step 165: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  delay(16);
  // Step 166: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  delay(26);
  // Step 167: Fingers [-, -, -, -, -] Arm [53, -, -]
  servo[5].write(53); // Shoulder

  // Step 168: Fingers [-, -, -, -, -] Arm [53, -, -]
  servo[5].write(53); // Shoulder

  delay(27);
  // Step 169: Fingers [-, -, -, -, -] Arm [53, -, -]
  servo[5].write(53); // Shoulder

  delay(14);
  // Step 170: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  delay(16);
  // Step 171: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  // Step 172: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  delay(18);
  // Step 173: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  // Step 174: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  delay(27);
  // Step 175: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  // Step 176: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  delay(14);
  // Step 177: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  delay(22);
  // Step 178: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  delay(18);
  // Step 179: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  // Step 180: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  // Step 181: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  delay(28);
  // Step 182: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  delay(17);
  // Step 183: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  delay(15);
  // Step 184: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  // Step 185: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  delay(16);
  // Step 186: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  // Step 187: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  delay(13);
  // Step 188: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  delay(14);
  // Step 189: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  // Step 190: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  delay(31);
  // Step 191: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  delay(17);
  // Step 192: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  delay(13);
  // Step 193: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  // Step 194: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  // Step 195: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  // Step 196: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  // Step 197: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  // Step 198: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  // Step 199: Fingers [-, -, -, -, -] Arm [62, -, -]
  servo[5].write(62); // Shoulder

  // Step 200: Fingers [-, -, -, -, -] Arm [62, -, -]
  servo[5].write(62); // Shoulder

  // Step 201: Fingers [-, -, -, -, -] Arm [62, -, -]
  servo[5].write(62); // Shoulder

  // Step 202: Fingers [-, -, -, -, -] Arm [63, -, -]
  servo[5].write(63); // Shoulder

  // Step 203: Fingers [-, -, -, -, -] Arm [63, -, -]
  servo[5].write(63); // Shoulder

  // Step 204: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 205: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 206: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 207: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(24);
  // Step 208: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 209: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 210: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 211: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 212: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(32);
  // Step 213: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 214: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(16);
  // Step 215: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 216: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(29);
  // Step 217: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 218: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(15);
  // Step 219: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 220: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(22);
  // Step 221: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(13);
  // Step 222: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(25);
  // Step 223: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 224: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(28);
  // Step 225: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 226: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(32);
  // Step 227: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 228: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(15);
  // Step 229: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 230: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(27);
  // Step 231: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 232: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(34);
  // Step 233: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(13);
  // Step 234: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 235: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 236: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 237: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(16);
  // Step 238: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 239: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(11);
  // Step 240: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 241: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 242: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(16);
  // Step 243: Fingers [-, -, -, -, -] Arm [63, -, -]
  servo[5].write(63); // Shoulder

  // Step 244: Fingers [-, -, -, -, -] Arm [63, -, -]
  servo[5].write(63); // Shoulder

  delay(15);
  // Step 245: Fingers [-, -, -, -, -] Arm [63, -, -]
  servo[5].write(63); // Shoulder

  delay(14);
  // Step 246: Fingers [-, -, -, -, -] Arm [63, -, -]
  servo[5].write(63); // Shoulder

  delay(14);
  // Step 247: Fingers [-, -, -, -, -] Arm [62, -, -]
  servo[5].write(62); // Shoulder

  // Step 248: Fingers [-, -, -, -, -] Arm [62, -, -]
  servo[5].write(62); // Shoulder

  // Step 249: Fingers [-, -, -, -, -] Arm [62, -, -]
  servo[5].write(62); // Shoulder

  // Step 250: Fingers [-, -, -, -, -] Arm [62, -, -]
  servo[5].write(62); // Shoulder

  delay(22);
  // Step 251: Fingers [-, -, -, -, -] Arm [62, -, -]
  servo[5].write(62); // Shoulder

  delay(32);
  // Step 252: Fingers [-, -, -, -, -] Arm [62, -, -]
  servo[5].write(62); // Shoulder

  // Step 253: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  // Step 254: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  // Step 255: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  // Step 256: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  delay(14);
  // Step 257: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  // Step 258: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  delay(24);
  // Step 259: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  // Step 260: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  // Step 261: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  delay(19);
  // Step 262: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  delay(17);
  // Step 263: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  delay(15);
  // Step 264: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  delay(24);
  // Step 265: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  // Step 266: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  // Step 267: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  delay(20);
  // Step 268: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  // Step 269: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  delay(25);
  // Step 270: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  delay(11);
  // Step 271: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  delay(17);
  // Step 272: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  // Step 273: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  delay(15);
  // Step 274: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  // Step 275: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  delay(20);
  // Step 276: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  // Step 277: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  // Step 278: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  delay(33);
  // Step 279: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  // Step 280: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  // Step 281: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  delay(18);
  // Step 282: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  delay(24);
  // Step 283: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  // Step 284: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  delay(22);
  // Step 285: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  // Step 286: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  delay(12);
  // Step 287: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  delay(24);
  // Step 288: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  delay(32);
  // Step 289: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  // Step 290: Fingers [-, -, -, -, -] Arm [53, -, -]
  servo[5].write(53); // Shoulder

  delay(24);
  // Step 291: Fingers [-, -, -, -, -] Arm [53, -, -]
  servo[5].write(53); // Shoulder

  // Step 292: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  delay(21);
  // Step 293: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  // Step 294: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  delay(19);
  // Step 295: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  delay(19);
  // Step 296: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  // Step 297: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  delay(20);
  // Step 298: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  // Step 299: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  // Step 300: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  delay(19);
  // Step 301: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  delay(16);
  // Step 302: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  delay(16);
  // Step 303: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  delay(22);
  // Step 304: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  // Step 305: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  delay(35);
  // Step 306: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  delay(29);
  // Step 307: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  delay(13);
  // Step 308: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  delay(18);
  // Step 309: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  // Step 310: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  delay(19);
  // Step 311: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  // Step 312: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(11);
  // Step 313: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  // Step 314: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(25);
  // Step 315: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  // Step 316: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(12);
  // Step 317: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  // Step 318: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  // Step 319: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(25);
  // Step 320: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  // Step 321: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(26);
  // Step 322: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  // Step 323: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(21);
  // Step 324: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(32);
  // Step 325: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(30);
  // Step 326: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(31);
  // Step 327: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(30);
  // Step 328: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  // Step 329: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(24);
  // Step 330: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  // Step 331: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(13);
  // Step 332: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  // Step 333: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(19);
  // Step 334: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(13);
  // Step 335: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(29);
  // Step 336: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  // Step 337: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(20);
  // Step 338: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  // Step 339: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  // Step 340: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  // Step 341: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  // Step 342: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  // Step 343: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(11);
  // Step 344: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  // Step 345: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(11);
  // Step 346: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(18);
  // Step 347: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  delay(21);
  // Step 348: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  // Step 349: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  // Step 350: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  delay(13);
  // Step 351: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  // Step 352: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  // Step 353: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  // Step 354: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  delay(21);
  // Step 355: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  // Step 356: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  // Step 357: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  // Step 358: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  // Step 359: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  // Step 360: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  delay(21);
  // Step 361: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  delay(12);
  // Step 362: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  delay(17);
  // Step 363: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  delay(30);
  // Step 364: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  // Step 365: Fingers [-, -, -, -, -] Arm [53, -, -]
  servo[5].write(53); // Shoulder

  delay(11);
  // Step 366: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  // Step 367: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  // Step 368: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  delay(30);
  // Step 369: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  // Step 370: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  delay(21);
  // Step 371: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  delay(32);
  // Step 372: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  // Step 373: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  delay(18);
  // Step 374: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  // Step 375: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  // Step 376: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  delay(19);
  // Step 377: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  // Step 378: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  delay(19);
  // Step 379: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  // Step 380: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  delay(25);
  // Step 381: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  delay(17);
  // Step 382: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  delay(12);
  // Step 383: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  delay(12);
  // Step 384: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  // Step 385: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  delay(13);
  // Step 386: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  delay(26);
  // Step 387: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  // Step 388: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  delay(34);
  // Step 389: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  delay(30);
  // Step 390: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  delay(23);
  // Step 391: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  // Step 392: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  delay(35);
  // Step 393: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  // Step 394: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  // Step 395: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  delay(14);
  // Step 396: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  // Step 397: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  delay(19);
  // Step 398: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  // Step 399: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  delay(30);
  // Step 400: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  delay(31);
  // Step 401: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  delay(29);
  // Step 402: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  delay(30);
  // Step 403: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  delay(30);
  // Step 404: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  delay(11);
  // Step 405: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  delay(19);
  // Step 406: Fingers [-, -, -, -, -] Arm [61, -, -]
  servo[5].write(61); // Shoulder

  // Step 407: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  delay(13);
  // Step 408: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  // Step 409: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  delay(14);
  // Step 410: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  delay(14);
  // Step 411: Fingers [-, -, -, -, -] Arm [60, -, -]
  servo[5].write(60); // Shoulder

  // Step 412: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  // Step 413: Fingers [-, -, -, -, -] Arm [59, -, -]
  servo[5].write(59); // Shoulder

  // Step 414: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  // Step 415: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  // Step 416: Fingers [-, -, -, -, -] Arm [58, -, -]
  servo[5].write(58); // Shoulder

  // Step 417: Fingers [-, -, -, -, -] Arm [57, -, -]
  servo[5].write(57); // Shoulder

  // Step 418: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  // Step 419: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  // Step 420: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  delay(18);
  // Step 421: Fingers [-, -, -, -, -] Arm [56, -, -]
  servo[5].write(56); // Shoulder

  delay(22);
  // Step 422: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  // Step 423: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  // Step 424: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  // Step 425: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  delay(12);
  // Step 426: Fingers [-, -, -, -, -] Arm [55, -, -]
  servo[5].write(55); // Shoulder

  delay(17);
  // Step 427: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  delay(14);
  // Step 428: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  delay(11);
  // Step 429: Fingers [-, -, -, -, -] Arm [54, -, -]
  servo[5].write(54); // Shoulder

  delay(15);
  // Step 430: Fingers [-, -, -, -, -] Arm [53, -, -]
  servo[5].write(53); // Shoulder

  // Step 431: Fingers [-, -, -, -, -] Arm [53, -, -]
  servo[5].write(53); // Shoulder

  delay(14);
  // Step 432: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  delay(16);
  // Step 433: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  // Step 434: Fingers [-, -, -, -, -] Arm [52, -, -]
  servo[5].write(52); // Shoulder

  // Step 435: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  // Step 436: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  // Step 437: Fingers [-, -, -, -, -] Arm [51, -, -]
  servo[5].write(51); // Shoulder

  // Step 438: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  // Step 439: Fingers [-, -, -, -, -] Arm [50, -, -]
  servo[5].write(50); // Shoulder

  delay(12);
  // Step 440: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  // Step 441: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  delay(11);
  // Step 442: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  delay(23);
  // Step 443: Fingers [-, -, -, -, -] Arm [49, -, -]
  servo[5].write(49); // Shoulder

  // Step 444: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(25);
  // Step 445: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(22);
  // Step 446: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  // Step 447: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(34);
  // Step 448: Fingers [-, -, -, -, -] Arm [48, -, -]
  servo[5].write(48); // Shoulder

  delay(27);
  // Step 449: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  // Step 450: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(23);
  // Step 451: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  // Step 452: Fingers [-, -, -, -, -] Arm [47, -, -]
  servo[5].write(47); // Shoulder

  delay(13);
  // Step 453: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(16);
  // Step 454: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(14);
  // Step 455: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(12);
  // Step 456: Fingers [-, -, -, -, -] Arm [46, -, -]
  servo[5].write(46); // Shoulder

  delay(12);
  // Step 457: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(15);
  // Step 458: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(25);
  // Step 459: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  // Step 460: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(12);
  // Step 461: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(15);
  // Step 462: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(16);
  // Step 463: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(22);
  // Step 464: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(25);
  // Step 465: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 466: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 467: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(24);
  // Step 468: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(31);
  // Step 469: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 470: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(13);
  // Step 471: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  // Step 472: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(28);
  // Step 473: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  // Step 474: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(27);
  // Step 475: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  // Step 476: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(22);
  // Step 477: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(30);
  // Step 478: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  // Step 479: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(23);
  // Step 480: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  // Step 481: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(20);
  // Step 482: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(26);
  // Step 483: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  // Step 484: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(17);
  // Step 485: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  // Step 486: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  // Step 487: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(24);
  // Step 488: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  // Step 489: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(20);
  // Step 490: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(29);
  // Step 491: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  // Step 492: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(17);
  // Step 493: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 494: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(38);
  // Step 495: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(29);
  // Step 496: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(31);
  // Step 497: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 498: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(23);
  // Step 499: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 500: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 501: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(14);
  // Step 502: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(13);
  // Step 503: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 504: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 505: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  // Step 506: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(30);
  // Step 507: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  // Step 508: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(25);
  // Step 509: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(30);
  // Step 510: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(30);
  // Step 511: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(31);
  // Step 512: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  // Step 513: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(18);
  // Step 514: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(27);
  // Step 515: Fingers [-, -, -, -, -] Arm [35, -, -]
  servo[5].write(35); // Shoulder

  // Step 516: Fingers [-, -, -, -, -] Arm [35, -, -]
  servo[5].write(35); // Shoulder

  delay(31);
  // Step 517: Fingers [-, -, -, -, -] Arm [35, -, -]
  servo[5].write(35); // Shoulder

  delay(32);
  // Step 518: Fingers [-, -, -, -, -] Arm [35, -, -]
  servo[5].write(35); // Shoulder

  delay(12);
  // Step 519: Fingers [-, -, -, -, -] Arm [34, -, -]
  servo[5].write(34); // Shoulder

  // Step 520: Fingers [-, -, -, -, -] Arm [34, -, -]
  servo[5].write(34); // Shoulder

  delay(27);
  // Step 521: Fingers [-, -, -, -, -] Arm [34, -, -]
  servo[5].write(34); // Shoulder

  delay(20);
  // Step 522: Fingers [-, -, -, -, -] Arm [34, -, -]
  servo[5].write(34); // Shoulder

  // Step 523: Fingers [-, -, -, -, -] Arm [34, -, -]
  servo[5].write(34); // Shoulder

  delay(23);
  // Step 524: Fingers [-, -, -, -, -] Arm [33, -, -]
  servo[5].write(33); // Shoulder

  // Step 525: Fingers [-, -, -, -, -] Arm [33, -, -]
  servo[5].write(33); // Shoulder

  delay(12);
  // Step 526: Fingers [-, -, -, -, -] Arm [33, -, -]
  servo[5].write(33); // Shoulder

  // Step 527: Fingers [-, -, -, -, -] Arm [33, -, -]
  servo[5].write(33); // Shoulder

  // Step 528: Fingers [-, -, -, -, -] Arm [33, -, -]
  servo[5].write(33); // Shoulder

  delay(16);
  // Step 529: Fingers [-, -, -, -, -] Arm [32, -, -]
  servo[5].write(32); // Shoulder

  delay(23);
  // Step 530: Fingers [-, -, -, -, -] Arm [32, -, -]
  servo[5].write(32); // Shoulder

  // Step 531: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(23);
  // Step 532: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(11);
  // Step 533: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(17);
  // Step 534: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  // Step 535: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(23);
  // Step 536: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(31);
  // Step 537: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(32);
  // Step 538: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(29);
  // Step 539: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(16);
  // Step 540: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(13);
  // Step 541: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(31);
  // Step 542: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(28);
  // Step 543: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  // Step 544: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(27);
  // Step 545: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  // Step 546: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(24);
  // Step 547: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(31);
  // Step 548: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(31);
  // Step 549: Fingers [-, -, -, -, -] Arm [31, -, -]
  servo[5].write(31); // Shoulder

  delay(14);
  // Step 550: Fingers [-, -, -, -, -] Arm [32, -, -]
  servo[5].write(32); // Shoulder

  delay(13);
  // Step 551: Fingers [-, -, -, -, -] Arm [32, -, -]
  servo[5].write(32); // Shoulder

  // Step 552: Fingers [-, -, -, -, -] Arm [32, -, -]
  servo[5].write(32); // Shoulder

  delay(15);
  // Step 553: Fingers [-, -, -, -, -] Arm [33, -, -]
  servo[5].write(33); // Shoulder

  // Step 554: Fingers [-, -, -, -, -] Arm [33, -, -]
  servo[5].write(33); // Shoulder

  delay(34);
  // Step 555: Fingers [-, -, -, -, -] Arm [33, -, -]
  servo[5].write(33); // Shoulder

  // Step 556: Fingers [-, -, -, -, -] Arm [33, -, -]
  servo[5].write(33); // Shoulder

  // Step 557: Fingers [-, -, -, -, -] Arm [33, -, -]
  servo[5].write(33); // Shoulder

  delay(12);
  // Step 558: Fingers [-, -, -, -, -] Arm [33, -, -]
  servo[5].write(33); // Shoulder

  delay(11);
  // Step 559: Fingers [-, -, -, -, -] Arm [34, -, -]
  servo[5].write(34); // Shoulder

  delay(21);
  // Step 560: Fingers [-, -, -, -, -] Arm [34, -, -]
  servo[5].write(34); // Shoulder

  // Step 561: Fingers [-, -, -, -, -] Arm [34, -, -]
  servo[5].write(34); // Shoulder

  delay(12);
  // Step 562: Fingers [-, -, -, -, -] Arm [35, -, -]
  servo[5].write(35); // Shoulder

  delay(11);
  // Step 563: Fingers [-, -, -, -, -] Arm [35, -, -]
  servo[5].write(35); // Shoulder

  delay(31);
  // Step 564: Fingers [-, -, -, -, -] Arm [35, -, -]
  servo[5].write(35); // Shoulder

  delay(30);
  // Step 565: Fingers [-, -, -, -, -] Arm [35, -, -]
  servo[5].write(35); // Shoulder

  delay(29);
  // Step 566: Fingers [-, -, -, -, -] Arm [35, -, -]
  servo[5].write(35); // Shoulder

  delay(32);
  // Step 567: Fingers [-, -, -, -, -] Arm [35, -, -]
  servo[5].write(35); // Shoulder

  // Step 568: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(20);
  // Step 569: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(27);
  // Step 570: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(15);
  // Step 571: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(19);
  // Step 572: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  // Step 573: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(17);
  // Step 574: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 575: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(34);
  // Step 576: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 577: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(24);
  // Step 578: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(31);
  // Step 579: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(30);
  // Step 580: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(31);
  // Step 581: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(15);
  // Step 582: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(15);
  // Step 583: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(25);
  // Step 584: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 585: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(33);
  // Step 586: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(19);
  // Step 587: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(12);
  // Step 588: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  // Step 589: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(22);
  // Step 590: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(32);
  // Step 591: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(30);
  // Step 592: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  // Step 593: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(24);
  // Step 594: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(31);
  // Step 595: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(16);
  // Step 596: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(13);
  // Step 597: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(30);
  // Step 598: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  // Step 599: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(20);
  // Step 600: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  // Step 601: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(27);
  // Step 602: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(28);
  // Step 603: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(31);
  // Step 604: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(29);
  // Step 605: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(31);
  // Step 606: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  // Step 607: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(21);
  // Step 608: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(31);
  // Step 609: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(30);
  // Step 610: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(12);
  // Step 611: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(18);
  // Step 612: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(29);
  // Step 613: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 614: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(34);
  // Step 615: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 616: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(20);
  // Step 617: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(29);
  // Step 618: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(16);
  // Step 619: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 620: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 621: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(29);
  // Step 622: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(12);
  // Step 623: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(17);
  // Step 624: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(31);
  // Step 625: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(31);
  // Step 626: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(23);
  // Step 627: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 628: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(15);
  // Step 629: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(15);
  // Step 630: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 631: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(18);
  // Step 632: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 633: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(14);
  // Step 634: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 635: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(13);
  // Step 636: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 637: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(25);
  // Step 638: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(29);
  // Step 639: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(31);
  // Step 640: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(31);
  // Step 641: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(15);
  // Step 642: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(15);
  // Step 643: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(31);
  // Step 644: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 645: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(21);
  // Step 646: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 647: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(19);
  // Step 648: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(33);
  // Step 649: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 650: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(25);
  // Step 651: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 652: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 653: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(16);
  // Step 654: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(31);
  // Step 655: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(32);
  // Step 656: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  // Step 657: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(22);
  // Step 658: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(31);
  // Step 659: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  // Step 660: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(24);
  // Step 661: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(29);
  // Step 662: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(30);
  // Step 663: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(14);
  // Step 664: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(16);
  // Step 665: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(30);
  // Step 666: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(18);
  // Step 667: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(12);
  // Step 668: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(30);
  // Step 669: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(32);
  // Step 670: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(18);
  // Step 671: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(11);
  // Step 672: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(30);
  // Step 673: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(31);
  // Step 674: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  // Step 675: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(23);
  // Step 676: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  // Step 677: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(26);
  // Step 678: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(16);
  // Step 679: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(14);
  // Step 680: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(30);
  // Step 681: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(30);
  // Step 682: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(12);
  // Step 683: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(15);
  // Step 684: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  // Step 685: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(16);
  // Step 686: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  // Step 687: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(37);
  // Step 688: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  // Step 689: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(22);
  // Step 690: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(31);
  // Step 691: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 692: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(22);
  // Step 693: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(27);
  // Step 694: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 695: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(28);
  // Step 696: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(31);
  // Step 697: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(30);
  // Step 698: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 699: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(21);
  // Step 700: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 701: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 702: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(15);
  // Step 703: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(18);
  // Step 704: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(12);
  // Step 705: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 706: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(23);
  // Step 707: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(31);
  // Step 708: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(29);
  // Step 709: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 710: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(27);
  // Step 711: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(30);
  // Step 712: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(30);
  // Step 713: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(17);
  // Step 714: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 715: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 716: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(33);
  // Step 717: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(30);
  // Step 718: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 719: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 720: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(15);
  // Step 721: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(27);
  // Step 722: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(34);
  // Step 723: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  // Step 724: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(25);
  // Step 725: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(30);
  // Step 726: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  delay(30);
  // Step 727: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  // Step 728: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  // Step 729: Fingers [-, -, -, -, -] Arm [36, -, -]
  servo[5].write(36); // Shoulder

  // Step 730: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 731: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(32);
  // Step 732: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(30);
  // Step 733: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(33);
  // Step 734: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 735: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(22);
  // Step 736: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(31);
  // Step 737: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(17);
  // Step 738: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(12);
  // Step 739: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  delay(31);
  // Step 740: Fingers [-, -, -, -, -] Arm [37, -, -]
  servo[5].write(37); // Shoulder

  // Step 741: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(19);
  // Step 742: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(31);
  // Step 743: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(21);
  // Step 744: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(13);
  // Step 745: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(26);
  // Step 746: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 747: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(29);
  // Step 748: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(30);
  // Step 749: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(30);
  // Step 750: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  delay(30);
  // Step 751: Fingers [-, -, -, -, -] Arm [38, -, -]
  servo[5].write(38); // Shoulder

  // Step 752: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(23);
  // Step 753: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(12);
  // Step 754: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(18);
  // Step 755: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(13);
  // Step 756: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(18);
  // Step 757: Fingers [-, -, -, -, -] Arm [39, -, -]
  servo[5].write(39); // Shoulder

  delay(14);
  // Step 758: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(15);
  // Step 759: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(34);
  // Step 760: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  // Step 761: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(20);
  // Step 762: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(33);
  // Step 763: Fingers [-, -, -, -, -] Arm [40, -, -]
  servo[5].write(40); // Shoulder

  delay(24);
  // Step 764: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  // Step 765: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(28);
  // Step 766: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(31);
  // Step 767: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(28);
  // Step 768: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  // Step 769: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(31);
  // Step 770: Fingers [-, -, -, -, -] Arm [41, -, -]
  servo[5].write(41); // Shoulder

  delay(17);
  // Step 771: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(13);
  // Step 772: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(29);
  // Step 773: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(31);
  // Step 774: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(29);
  // Step 775: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(16);
  // Step 776: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  // Step 777: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  // Step 778: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  // Step 779: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(18);
  // Step 780: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  // Step 781: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(35);
  // Step 782: Fingers [-, -, -, -, -] Arm [42, -, -]
  servo[5].write(42); // Shoulder

  delay(11);
  // Step 783: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(15);
  // Step 784: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 785: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 786: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(25);
  // Step 787: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(31);
  // Step 788: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(29);
  // Step 789: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 790: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(22);
  // Step 791: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(18);
  // Step 792: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  delay(12);
  // Step 793: Fingers [-, -, -, -, -] Arm [43, -, -]
  servo[5].write(43); // Shoulder

  // Step 794: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 795: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 796: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 797: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 798: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 799: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 800: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  // Step 801: Fingers [-, -, -, -, -] Arm [44, -, -]
  servo[5].write(44); // Shoulder

  delay(11);
  // Step 802: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(25);
  // Step 803: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(32);
  // Step 804: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(30);
  // Step 805: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(31);
  // Step 806: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(24);
  // Step 807: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  // Step 808: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(34);
  // Step 809: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(29);
  // Step 810: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(29);
  // Step 811: Fingers [-, -, -, -, -] Arm [45, -, -]
  servo[5].write(45); // Shoulder

  delay(13);
  // Step 812: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  // Step 813: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  delay(11);
  // Step 814: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  delay(29);
  // Step 815: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  delay(33);
  // Step 816: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  delay(15);
  // Step 817: Fingers [-, -, -, -, -] Arm [119, -, -]
  servo[5].write(119); // Shoulder

  delay(12);
  // Step 818: Fingers [-, -, -, -, -] Arm [119, -, -]
  servo[5].write(119); // Shoulder

  delay(33);
  // Step 819: Fingers [-, -, -, -, -] Arm [119, -, -]
  servo[5].write(119); // Shoulder

  delay(28);
  // Step 820: Fingers [-, -, -, -, -] Arm [119, -, -]
  servo[5].write(119); // Shoulder

  delay(31);
  // Step 821: Fingers [-, -, -, -, -] Arm [119, -, -]
  servo[5].write(119); // Shoulder

  delay(30);
  // Step 822: Fingers [-, -, -, -, -] Arm [119, -, -]
  servo[5].write(119); // Shoulder

  delay(30);
  // Step 823: Fingers [-, -, -, -, -] Arm [119, -, -]
  servo[5].write(119); // Shoulder

  delay(30);
  // Step 824: Fingers [-, -, -, -, -] Arm [119, -, -]
  servo[5].write(119); // Shoulder

  delay(29);
  // Step 825: Fingers [-, -, -, -, -] Arm [119, -, -]
  servo[5].write(119); // Shoulder

  delay(31);
  // Step 826: Fingers [-, -, -, -, -] Arm [119, -, -]
  servo[5].write(119); // Shoulder

  delay(31);
  // Step 827: Fingers [-, -, -, -, -] Arm [119, -, -]
  servo[5].write(119); // Shoulder

}

// Layer 4: Layer_4 - cursor mode
// Duration: 14.2s, Points: 1562
void playLayer4() {
  delay(31);
  // Step 1: Fingers [116, 128, 126, 113, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(128); // Index
  servo[2].write(126); // Middle
  servo[3].write(113); // Ring
  servo[4].write(116); // Pinky

  delay(31);
  // Step 2: Fingers [116, 128, 126, 113, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(128); // Index
  servo[2].write(126); // Middle
  servo[3].write(113); // Ring
  servo[4].write(116); // Pinky

  delay(31);
  // Step 3: Fingers [116, 128, 126, 113, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(128); // Index
  servo[2].write(126); // Middle
  servo[3].write(113); // Ring
  servo[4].write(116); // Pinky

  // Step 4: Fingers [117, 129, 127, 115, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(129); // Index
  servo[2].write(127); // Middle
  servo[3].write(115); // Ring
  servo[4].write(117); // Pinky

  // Step 5: Fingers [117, 130, 127, 114, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(130); // Index
  servo[2].write(127); // Middle
  servo[3].write(114); // Ring
  servo[4].write(117); // Pinky

  // Step 6: Fingers [119, 131, 128, 116, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(131); // Index
  servo[2].write(128); // Middle
  servo[3].write(116); // Ring
  servo[4].write(119); // Pinky

  // Step 7: Fingers [120, 132, 129, 117, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(132); // Index
  servo[2].write(129); // Middle
  servo[3].write(117); // Ring
  servo[4].write(120); // Pinky

  // Step 8: Fingers [120, 132, 129, 117, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(132); // Index
  servo[2].write(129); // Middle
  servo[3].write(117); // Ring
  servo[4].write(120); // Pinky

  // Step 9: Fingers [121, 133, 129, 117, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(133); // Index
  servo[2].write(129); // Middle
  servo[3].write(117); // Ring
  servo[4].write(121); // Pinky

  // Step 10: Fingers [122, 134, 130, 118, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(134); // Index
  servo[2].write(130); // Middle
  servo[3].write(118); // Ring
  servo[4].write(122); // Pinky

  // Step 11: Fingers [122, 134, 130, 118, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(134); // Index
  servo[2].write(130); // Middle
  servo[3].write(118); // Ring
  servo[4].write(122); // Pinky

  // Step 12: Fingers [124, 135, 131, 119, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(135); // Index
  servo[2].write(131); // Middle
  servo[3].write(119); // Ring
  servo[4].write(124); // Pinky

  // Step 13: Fingers [124, 135, 131, 119, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(135); // Index
  servo[2].write(131); // Middle
  servo[3].write(119); // Ring
  servo[4].write(124); // Pinky

  // Step 14: Fingers [124, 136, 131, 119, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(136); // Index
  servo[2].write(131); // Middle
  servo[3].write(119); // Ring
  servo[4].write(124); // Pinky

  // Step 15: Fingers [125, 137, 132, 120, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(137); // Index
  servo[2].write(132); // Middle
  servo[3].write(120); // Ring
  servo[4].write(125); // Pinky

  // Step 16: Fingers [125, 137, 131, 120, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(137); // Index
  servo[2].write(131); // Middle
  servo[3].write(120); // Ring
  servo[4].write(125); // Pinky

  // Step 17: Fingers [125, 137, 131, 120, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(137); // Index
  servo[2].write(131); // Middle
  servo[3].write(120); // Ring
  servo[4].write(125); // Pinky

  delay(35);
  // Step 18: Fingers [125, 137, 131, 120, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(137); // Index
  servo[2].write(131); // Middle
  servo[3].write(120); // Ring
  servo[4].write(125); // Pinky

  delay(31);
  // Step 19: Fingers [125, 137, 131, 120, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(137); // Index
  servo[2].write(131); // Middle
  servo[3].write(120); // Ring
  servo[4].write(125); // Pinky

  delay(32);
  // Step 20: Fingers [125, 137, 131, 120, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(137); // Index
  servo[2].write(131); // Middle
  servo[3].write(120); // Ring
  servo[4].write(125); // Pinky

  delay(31);
  // Step 21: Fingers [125, 137, 131, 120, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(137); // Index
  servo[2].write(131); // Middle
  servo[3].write(120); // Ring
  servo[4].write(125); // Pinky

  delay(31);
  // Step 22: Fingers [125, 137, 131, 120, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(137); // Index
  servo[2].write(131); // Middle
  servo[3].write(120); // Ring
  servo[4].write(125); // Pinky

  // Step 23: Fingers [126, 137, 131, 120, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(137); // Index
  servo[2].write(131); // Middle
  servo[3].write(120); // Ring
  servo[4].write(126); // Pinky

  // Step 24: Fingers [126, 137, 131, 120, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(137); // Index
  servo[2].write(131); // Middle
  servo[3].write(120); // Ring
  servo[4].write(126); // Pinky

  // Step 25: Fingers [126, 137, 130, 120, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(137); // Index
  servo[2].write(130); // Middle
  servo[3].write(120); // Ring
  servo[4].write(126); // Pinky

  // Step 26: Fingers [126, 137, 130, 120, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(137); // Index
  servo[2].write(130); // Middle
  servo[3].write(120); // Ring
  servo[4].write(126); // Pinky

  // Step 27: Fingers [128, 138, 130, 120, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(138); // Index
  servo[2].write(130); // Middle
  servo[3].write(120); // Ring
  servo[4].write(128); // Pinky

  // Step 28: Fingers [128, 138, 130, 120, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(138); // Index
  servo[2].write(130); // Middle
  servo[3].write(120); // Ring
  servo[4].write(128); // Pinky

  // Step 29: Fingers [129, 138, 129, 120, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(138); // Index
  servo[2].write(129); // Middle
  servo[3].write(120); // Ring
  servo[4].write(129); // Pinky

  // Step 30: Fingers [130, 138, 128, 120, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(138); // Index
  servo[2].write(128); // Middle
  servo[3].write(120); // Ring
  servo[4].write(130); // Pinky

  // Step 31: Fingers [130, 138, 128, 120, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(138); // Index
  servo[2].write(128); // Middle
  servo[3].write(120); // Ring
  servo[4].write(130); // Pinky

  // Step 32: Fingers [130, 138, 128, 120, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(138); // Index
  servo[2].write(128); // Middle
  servo[3].write(120); // Ring
  servo[4].write(130); // Pinky

  // Step 33: Fingers [131, 138, 127, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(138); // Index
  servo[2].write(127); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  // Step 34: Fingers [131, 138, 127, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(138); // Index
  servo[2].write(127); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  // Step 35: Fingers [131, 138, 127, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(138); // Index
  servo[2].write(127); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  // Step 36: Fingers [131, 138, 127, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(138); // Index
  servo[2].write(127); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  // Step 37: Fingers [131, 138, 127, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(138); // Index
  servo[2].write(127); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  delay(24);
  // Step 38: Fingers [131, 138, 127, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(138); // Index
  servo[2].write(127); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  delay(30);
  // Step 39: Fingers [131, 138, 127, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(138); // Index
  servo[2].write(127); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  delay(13);
  // Step 40: Fingers [131, 137, 126, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(137); // Index
  servo[2].write(126); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  delay(16);
  // Step 41: Fingers [131, 137, 126, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(137); // Index
  servo[2].write(126); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  // Step 42: Fingers [131, 136, 125, 119, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(136); // Index
  servo[2].write(125); // Middle
  servo[3].write(119); // Ring
  servo[4].write(131); // Pinky

  // Step 43: Fingers [130, 136, 124, 119, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(136); // Index
  servo[2].write(124); // Middle
  servo[3].write(119); // Ring
  servo[4].write(130); // Pinky

  // Step 44: Fingers [129, 135, 124, 118, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(135); // Index
  servo[2].write(124); // Middle
  servo[3].write(118); // Ring
  servo[4].write(129); // Pinky

  // Step 45: Fingers [129, 134, 123, 117, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(134); // Index
  servo[2].write(123); // Middle
  servo[3].write(117); // Ring
  servo[4].write(129); // Pinky

  // Step 46: Fingers [129, 134, 123, 117, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(134); // Index
  servo[2].write(123); // Middle
  servo[3].write(117); // Ring
  servo[4].write(129); // Pinky

  // Step 47: Fingers [129, 134, 122, 117, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(134); // Index
  servo[2].write(122); // Middle
  servo[3].write(117); // Ring
  servo[4].write(129); // Pinky

  // Step 48: Fingers [128, 133, 121, 116, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(133); // Index
  servo[2].write(121); // Middle
  servo[3].write(116); // Ring
  servo[4].write(128); // Pinky

  delay(15);
  // Step 49: Fingers [127, 132, 120, 115, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(132); // Index
  servo[2].write(120); // Middle
  servo[3].write(115); // Ring
  servo[4].write(127); // Pinky

  // Step 50: Fingers [127, 132, 120, 115, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(132); // Index
  servo[2].write(120); // Middle
  servo[3].write(115); // Ring
  servo[4].write(127); // Pinky

  delay(17);
  // Step 51: Fingers [127, 131, 119, 115, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(131); // Index
  servo[2].write(119); // Middle
  servo[3].write(115); // Ring
  servo[4].write(127); // Pinky

  delay(13);
  // Step 52: Fingers [127, 131, 119, 115, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(131); // Index
  servo[2].write(119); // Middle
  servo[3].write(115); // Ring
  servo[4].write(127); // Pinky

  // Step 53: Fingers [126, 130, 118, 114, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(130); // Index
  servo[2].write(118); // Middle
  servo[3].write(114); // Ring
  servo[4].write(126); // Pinky

  // Step 54: Fingers [126, 130, 118, 114, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(130); // Index
  servo[2].write(118); // Middle
  servo[3].write(114); // Ring
  servo[4].write(126); // Pinky

  // Step 55: Fingers [125, 129, 117, 113, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(129); // Index
  servo[2].write(117); // Middle
  servo[3].write(113); // Ring
  servo[4].write(125); // Pinky

  // Step 56: Fingers [125, 129, 117, 113, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(129); // Index
  servo[2].write(117); // Middle
  servo[3].write(113); // Ring
  servo[4].write(125); // Pinky

  // Step 57: Fingers [125, 129, 117, 113, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(129); // Index
  servo[2].write(117); // Middle
  servo[3].write(113); // Ring
  servo[4].write(125); // Pinky

  delay(15);
  // Step 58: Fingers [124, 128, 116, 112, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(128); // Index
  servo[2].write(116); // Middle
  servo[3].write(112); // Ring
  servo[4].write(124); // Pinky

  delay(11);
  // Step 59: Fingers [124, 128, 116, 112, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(128); // Index
  servo[2].write(116); // Middle
  servo[3].write(112); // Ring
  servo[4].write(124); // Pinky

  // Step 60: Fingers [124, 127, 115, 112, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(127); // Index
  servo[2].write(115); // Middle
  servo[3].write(112); // Ring
  servo[4].write(124); // Pinky

  // Step 61: Fingers [123, 127, 115, 111, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(127); // Index
  servo[2].write(115); // Middle
  servo[3].write(111); // Ring
  servo[4].write(123); // Pinky

  // Step 62: Fingers [123, 126, 114, 110, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(126); // Index
  servo[2].write(114); // Middle
  servo[3].write(110); // Ring
  servo[4].write(123); // Pinky

  // Step 63: Fingers [123, 126, 114, 110, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(126); // Index
  servo[2].write(114); // Middle
  servo[3].write(110); // Ring
  servo[4].write(123); // Pinky

  delay(15);
  // Step 64: Fingers [122, 125, 113, 110, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(125); // Index
  servo[2].write(113); // Middle
  servo[3].write(110); // Ring
  servo[4].write(122); // Pinky

  delay(17);
  // Step 65: Fingers [122, 125, 113, 110, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(125); // Index
  servo[2].write(113); // Middle
  servo[3].write(110); // Ring
  servo[4].write(122); // Pinky

  // Step 66: Fingers [121, 125, 113, 109, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(125); // Index
  servo[2].write(113); // Middle
  servo[3].write(109); // Ring
  servo[4].write(121); // Pinky

  // Step 67: Fingers [121, 124, 112, 108, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(124); // Index
  servo[2].write(112); // Middle
  servo[3].write(108); // Ring
  servo[4].write(121); // Pinky

  // Step 68: Fingers [121, 124, 112, 109, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(124); // Index
  servo[2].write(112); // Middle
  servo[3].write(109); // Ring
  servo[4].write(121); // Pinky

  // Step 69: Fingers [121, 124, 112, 109, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(124); // Index
  servo[2].write(112); // Middle
  servo[3].write(109); // Ring
  servo[4].write(121); // Pinky

  // Step 70: Fingers [120, 123, 111, 108, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(123); // Index
  servo[2].write(111); // Middle
  servo[3].write(108); // Ring
  servo[4].write(120); // Pinky

  // Step 71: Fingers [120, 123, 110, 107, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(123); // Index
  servo[2].write(110); // Middle
  servo[3].write(107); // Ring
  servo[4].write(120); // Pinky

  delay(13);
  // Step 72: Fingers [120, 123, 110, 107, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(123); // Index
  servo[2].write(110); // Middle
  servo[3].write(107); // Ring
  servo[4].write(120); // Pinky

  // Step 73: Fingers [119, 122, 110, 107, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(122); // Index
  servo[2].write(110); // Middle
  servo[3].write(107); // Ring
  servo[4].write(119); // Pinky

  delay(15);
  // Step 74: Fingers [118, 122, 109, 106, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(122); // Index
  servo[2].write(109); // Middle
  servo[3].write(106); // Ring
  servo[4].write(118); // Pinky

  // Step 75: Fingers [118, 122, 109, 106, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(122); // Index
  servo[2].write(109); // Middle
  servo[3].write(106); // Ring
  servo[4].write(118); // Pinky

  // Step 76: Fingers [118, 121, 109, 105, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(121); // Index
  servo[2].write(109); // Middle
  servo[3].write(105); // Ring
  servo[4].write(118); // Pinky

  delay(11);
  // Step 77: Fingers [117, 120, 108, 105, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(120); // Index
  servo[2].write(108); // Middle
  servo[3].write(105); // Ring
  servo[4].write(117); // Pinky

  // Step 78: Fingers [117, 120, 108, 105, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(120); // Index
  servo[2].write(108); // Middle
  servo[3].write(105); // Ring
  servo[4].write(117); // Pinky

  // Step 79: Fingers [117, 120, 107, 104, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(120); // Index
  servo[2].write(107); // Middle
  servo[3].write(104); // Ring
  servo[4].write(117); // Pinky

  // Step 80: Fingers [116, 119, 106, 104, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(119); // Index
  servo[2].write(106); // Middle
  servo[3].write(104); // Ring
  servo[4].write(116); // Pinky

  // Step 81: Fingers [115, 118, 106, 103, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(118); // Index
  servo[2].write(106); // Middle
  servo[3].write(103); // Ring
  servo[4].write(115); // Pinky

  // Step 82: Fingers [115, 118, 106, 103, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(118); // Index
  servo[2].write(106); // Middle
  servo[3].write(103); // Ring
  servo[4].write(115); // Pinky

  delay(14);
  // Step 83: Fingers [115, 118, 105, 102, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(118); // Index
  servo[2].write(105); // Middle
  servo[3].write(102); // Ring
  servo[4].write(115); // Pinky

  // Step 84: Fingers [114, 117, 104, 102, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(117); // Index
  servo[2].write(104); // Middle
  servo[3].write(102); // Ring
  servo[4].write(114); // Pinky

  // Step 85: Fingers [114, 117, 104, 102, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(117); // Index
  servo[2].write(104); // Middle
  servo[3].write(102); // Ring
  servo[4].write(114); // Pinky

  // Step 86: Fingers [114, 116, 104, 101, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(116); // Index
  servo[2].write(104); // Middle
  servo[3].write(101); // Ring
  servo[4].write(114); // Pinky

  // Step 87: Fingers [113, 116, 103, 100, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(116); // Index
  servo[2].write(103); // Middle
  servo[3].write(100); // Ring
  servo[4].write(113); // Pinky

  delay(18);
  // Step 88: Fingers [113, 116, 103, 100, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(116); // Index
  servo[2].write(103); // Middle
  servo[3].write(100); // Ring
  servo[4].write(113); // Pinky

  // Step 89: Fingers [112, 115, 102, 100, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(115); // Index
  servo[2].write(102); // Middle
  servo[3].write(100); // Ring
  servo[4].write(112); // Pinky

  // Step 90: Fingers [112, 114, 102, 99, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(114); // Index
  servo[2].write(102); // Middle
  servo[3].write(99); // Ring
  servo[4].write(112); // Pinky

  // Step 91: Fingers [111, 114, 101, 99, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(114); // Index
  servo[2].write(101); // Middle
  servo[3].write(99); // Ring
  servo[4].write(111); // Pinky

  // Step 92: Fingers [111, 114, 101, 99, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(114); // Index
  servo[2].write(101); // Middle
  servo[3].write(99); // Ring
  servo[4].write(111); // Pinky

  // Step 93: Fingers [110, 113, 101, 98, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(113); // Index
  servo[2].write(101); // Middle
  servo[3].write(98); // Ring
  servo[4].write(110); // Pinky

  delay(12);
  // Step 94: Fingers [110, 112, 100, 97, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(112); // Index
  servo[2].write(100); // Middle
  servo[3].write(97); // Ring
  servo[4].write(110); // Pinky

  // Step 95: Fingers [109, 112, 99, 97, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(112); // Index
  servo[2].write(99); // Middle
  servo[3].write(97); // Ring
  servo[4].write(109); // Pinky

  // Step 96: Fingers [109, 112, 99, 97, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(112); // Index
  servo[2].write(99); // Middle
  servo[3].write(97); // Ring
  servo[4].write(109); // Pinky

  // Step 97: Fingers [108, 111, 99, 96, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(111); // Index
  servo[2].write(99); // Middle
  servo[3].write(96); // Ring
  servo[4].write(108); // Pinky

  // Step 98: Fingers [108, 110, 98, 95, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(110); // Index
  servo[2].write(98); // Middle
  servo[3].write(95); // Ring
  servo[4].write(108); // Pinky

  // Step 99: Fingers [107, 110, 97, 95, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(110); // Index
  servo[2].write(97); // Middle
  servo[3].write(95); // Ring
  servo[4].write(107); // Pinky

  // Step 100: Fingers [107, 110, 97, 95, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(110); // Index
  servo[2].write(97); // Middle
  servo[3].write(95); // Ring
  servo[4].write(107); // Pinky

  // Step 101: Fingers [107, 109, 97, 94, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(109); // Index
  servo[2].write(97); // Middle
  servo[3].write(94); // Ring
  servo[4].write(107); // Pinky

  delay(24);
  // Step 102: Fingers [107, 109, 97, 94, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(109); // Index
  servo[2].write(97); // Middle
  servo[3].write(94); // Ring
  servo[4].write(107); // Pinky

  // Step 103: Fingers [106, 109, 96, 93, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(109); // Index
  servo[2].write(96); // Middle
  servo[3].write(93); // Ring
  servo[4].write(106); // Pinky

  delay(17);
  // Step 104: Fingers [105, 108, 95, 93, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(108); // Index
  servo[2].write(95); // Middle
  servo[3].write(93); // Ring
  servo[4].write(105); // Pinky

  delay(13);
  // Step 105: Fingers [105, 108, 95, 93, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(108); // Index
  servo[2].write(95); // Middle
  servo[3].write(93); // Ring
  servo[4].write(105); // Pinky

  // Step 106: Fingers [105, 107, 95, 92, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(107); // Index
  servo[2].write(95); // Middle
  servo[3].write(92); // Ring
  servo[4].write(105); // Pinky

  delay(19);
  // Step 107: Fingers [104, 107, 94, 92, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(107); // Index
  servo[2].write(94); // Middle
  servo[3].write(92); // Ring
  servo[4].write(104); // Pinky

  // Step 108: Fingers [104, 107, 94, 92, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(107); // Index
  servo[2].write(94); // Middle
  servo[3].write(92); // Ring
  servo[4].write(104); // Pinky

  delay(11);
  // Step 109: Fingers [103, 106, 94, 91, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(106); // Index
  servo[2].write(94); // Middle
  servo[3].write(91); // Ring
  servo[4].write(103); // Pinky

  delay(17);
  // Step 110: Fingers [103, 106, 94, 91, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(106); // Index
  servo[2].write(94); // Middle
  servo[3].write(91); // Ring
  servo[4].write(103); // Pinky

  delay(13);
  // Step 111: Fingers [103, 105, 93, 90, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(105); // Index
  servo[2].write(93); // Middle
  servo[3].write(90); // Ring
  servo[4].write(103); // Pinky

  // Step 112: Fingers [102, 105, 92, 90, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(105); // Index
  servo[2].write(92); // Middle
  servo[3].write(90); // Ring
  servo[4].write(102); // Pinky

  // Step 113: Fingers [102, 105, 92, 90, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(105); // Index
  servo[2].write(92); // Middle
  servo[3].write(90); // Ring
  servo[4].write(102); // Pinky

  // Step 114: Fingers [101, 104, 92, 89, 101] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(104); // Index
  servo[2].write(92); // Middle
  servo[3].write(89); // Ring
  servo[4].write(101); // Pinky

  // Step 115: Fingers [101, 104, 92, 89, 101] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(104); // Index
  servo[2].write(92); // Middle
  servo[3].write(89); // Ring
  servo[4].write(101); // Pinky

  // Step 116: Fingers [101, 104, 92, 89, 101] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(104); // Index
  servo[2].write(92); // Middle
  servo[3].write(89); // Ring
  servo[4].write(101); // Pinky

  // Step 117: Fingers [100, 104, 91, 88, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(104); // Index
  servo[2].write(91); // Middle
  servo[3].write(88); // Ring
  servo[4].write(100); // Pinky

  delay(25);
  // Step 118: Fingers [100, 104, 91, 88, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(104); // Index
  servo[2].write(91); // Middle
  servo[3].write(88); // Ring
  servo[4].write(100); // Pinky

  // Step 119: Fingers [99, 102, 90, 87, 99] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(102); // Index
  servo[2].write(90); // Middle
  servo[3].write(87); // Ring
  servo[4].write(99); // Pinky

  // Step 120: Fingers [99, 102, 90, 87, 99] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(102); // Index
  servo[2].write(90); // Middle
  servo[3].write(87); // Ring
  servo[4].write(99); // Pinky

  delay(15);
  // Step 121: Fingers [98, 102, 90, 86, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(102); // Index
  servo[2].write(90); // Middle
  servo[3].write(86); // Ring
  servo[4].write(98); // Pinky

  // Step 122: Fingers [98, 102, 90, 86, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(102); // Index
  servo[2].write(90); // Middle
  servo[3].write(86); // Ring
  servo[4].write(98); // Pinky

  delay(19);
  // Step 123: Fingers [98, 101, 89, 85, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(101); // Index
  servo[2].write(89); // Middle
  servo[3].write(85); // Ring
  servo[4].write(98); // Pinky

  // Step 124: Fingers [97, 101, 88, 85, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(101); // Index
  servo[2].write(88); // Middle
  servo[3].write(85); // Ring
  servo[4].write(97); // Pinky

  // Step 125: Fingers [97, 101, 88, 85, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(101); // Index
  servo[2].write(88); // Middle
  servo[3].write(85); // Ring
  servo[4].write(97); // Pinky

  // Step 126: Fingers [97, 101, 89, 85, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(101); // Index
  servo[2].write(89); // Middle
  servo[3].write(85); // Ring
  servo[4].write(97); // Pinky

  delay(20);
  // Step 127: Fingers [97, 101, 89, 85, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(101); // Index
  servo[2].write(89); // Middle
  servo[3].write(85); // Ring
  servo[4].write(97); // Pinky

  // Step 128: Fingers [96, 100, 88, 84, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(100); // Index
  servo[2].write(88); // Middle
  servo[3].write(84); // Ring
  servo[4].write(96); // Pinky

  delay(22);
  // Step 129: Fingers [96, 100, 88, 84, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(100); // Index
  servo[2].write(88); // Middle
  servo[3].write(84); // Ring
  servo[4].write(96); // Pinky

  // Step 130: Fingers [96, 100, 88, 84, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(100); // Index
  servo[2].write(88); // Middle
  servo[3].write(84); // Ring
  servo[4].write(96); // Pinky

  // Step 131: Fingers [95, 99, 87, 83, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(99); // Index
  servo[2].write(87); // Middle
  servo[3].write(83); // Ring
  servo[4].write(95); // Pinky

  // Step 132: Fingers [95, 100, 88, 83, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(100); // Index
  servo[2].write(88); // Middle
  servo[3].write(83); // Ring
  servo[4].write(95); // Pinky

  delay(16);
  // Step 133: Fingers [95, 100, 88, 83, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(100); // Index
  servo[2].write(88); // Middle
  servo[3].write(83); // Ring
  servo[4].write(95); // Pinky

  delay(30);
  // Step 134: Fingers [95, 100, 88, 83, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(100); // Index
  servo[2].write(88); // Middle
  servo[3].write(83); // Ring
  servo[4].write(95); // Pinky

  // Step 135: Fingers [94, 99, 87, 83, 94] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(99); // Index
  servo[2].write(87); // Middle
  servo[3].write(83); // Ring
  servo[4].write(94); // Pinky

  // Step 136: Fingers [94, 98, 87, 82, 94] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(98); // Index
  servo[2].write(87); // Middle
  servo[3].write(82); // Ring
  servo[4].write(94); // Pinky

  delay(16);
  // Step 137: Fingers [93, 99, 87, 82, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(99); // Index
  servo[2].write(87); // Middle
  servo[3].write(82); // Ring
  servo[4].write(93); // Pinky

  // Step 138: Fingers [93, 99, 87, 82, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(99); // Index
  servo[2].write(87); // Middle
  servo[3].write(82); // Ring
  servo[4].write(93); // Pinky

  // Step 139: Fingers [92, 98, 87, 81, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(98); // Index
  servo[2].write(87); // Middle
  servo[3].write(81); // Ring
  servo[4].write(92); // Pinky

  // Step 140: Fingers [91, 98, 87, 80, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(98); // Index
  servo[2].write(87); // Middle
  servo[3].write(80); // Ring
  servo[4].write(91); // Pinky

  // Step 141: Fingers [91, 98, 87, 80, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(98); // Index
  servo[2].write(87); // Middle
  servo[3].write(80); // Ring
  servo[4].write(91); // Pinky

  // Step 142: Fingers [90, 97, 86, 79, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(97); // Index
  servo[2].write(86); // Middle
  servo[3].write(79); // Ring
  servo[4].write(90); // Pinky

  // Step 143: Fingers [90, 97, 86, 79, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(97); // Index
  servo[2].write(86); // Middle
  servo[3].write(79); // Ring
  servo[4].write(90); // Pinky

  // Step 144: Fingers [90, 97, 86, 79, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(97); // Index
  servo[2].write(86); // Middle
  servo[3].write(79); // Ring
  servo[4].write(90); // Pinky

  // Step 145: Fingers [90, 97, 87, 79, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(97); // Index
  servo[2].write(87); // Middle
  servo[3].write(79); // Ring
  servo[4].write(90); // Pinky

  delay(15);
  // Step 146: Fingers [89, 97, 86, 79, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(97); // Index
  servo[2].write(86); // Middle
  servo[3].write(79); // Ring
  servo[4].write(89); // Pinky

  // Step 147: Fingers [89, 97, 86, 79, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(97); // Index
  servo[2].write(86); // Middle
  servo[3].write(79); // Ring
  servo[4].write(89); // Pinky

  delay(11);
  // Step 148: Fingers [88, 96, 86, 78, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(86); // Middle
  servo[3].write(78); // Ring
  servo[4].write(88); // Pinky

  delay(17);
  // Step 149: Fingers [88, 96, 86, 78, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(86); // Middle
  servo[3].write(78); // Ring
  servo[4].write(88); // Pinky

  // Step 150: Fingers [88, 96, 86, 78, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(86); // Middle
  servo[3].write(78); // Ring
  servo[4].write(88); // Pinky

  delay(26);
  // Step 151: Fingers [88, 96, 86, 78, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(86); // Middle
  servo[3].write(78); // Ring
  servo[4].write(88); // Pinky

  delay(31);
  // Step 152: Fingers [88, 96, 86, 78, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(86); // Middle
  servo[3].write(78); // Ring
  servo[4].write(88); // Pinky

  delay(13);
  // Step 153: Fingers [88, 96, 86, 78, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(86); // Middle
  servo[3].write(78); // Ring
  servo[4].write(88); // Pinky

  delay(17);
  // Step 154: Fingers [88, 96, 86, 78, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(86); // Middle
  servo[3].write(78); // Ring
  servo[4].write(88); // Pinky

  // Step 155: Fingers [88, 96, 86, 78, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(86); // Middle
  servo[3].write(78); // Ring
  servo[4].write(88); // Pinky

  delay(15);
  // Step 156: Fingers [87, 96, 87, 78, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(96); // Index
  servo[2].write(87); // Middle
  servo[3].write(78); // Ring
  servo[4].write(87); // Pinky

  // Step 157: Fingers [87, 96, 87, 78, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(96); // Index
  servo[2].write(87); // Middle
  servo[3].write(78); // Ring
  servo[4].write(87); // Pinky

  // Step 158: Fingers [87, 96, 87, 78, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(96); // Index
  servo[2].write(87); // Middle
  servo[3].write(78); // Ring
  servo[4].write(87); // Pinky

  // Step 159: Fingers [88, 97, 87, 79, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(97); // Index
  servo[2].write(87); // Middle
  servo[3].write(79); // Ring
  servo[4].write(88); // Pinky

  delay(14);
  // Step 160: Fingers [88, 97, 87, 79, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(97); // Index
  servo[2].write(87); // Middle
  servo[3].write(79); // Ring
  servo[4].write(88); // Pinky

  // Step 161: Fingers [88, 97, 88, 79, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(97); // Index
  servo[2].write(88); // Middle
  servo[3].write(79); // Ring
  servo[4].write(88); // Pinky

  // Step 162: Fingers [88, 97, 88, 79, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(97); // Index
  servo[2].write(88); // Middle
  servo[3].write(79); // Ring
  servo[4].write(88); // Pinky

  delay(13);
  // Step 163: Fingers [88, 97, 88, 79, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(97); // Index
  servo[2].write(88); // Middle
  servo[3].write(79); // Ring
  servo[4].write(88); // Pinky

  delay(27);
  // Step 164: Fingers [88, 97, 88, 79, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(97); // Index
  servo[2].write(88); // Middle
  servo[3].write(79); // Ring
  servo[4].write(88); // Pinky

  delay(15);
  // Step 165: Fingers [88, 98, 89, 80, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(98); // Index
  servo[2].write(89); // Middle
  servo[3].write(80); // Ring
  servo[4].write(88); // Pinky

  // Step 166: Fingers [89, 99, 90, 81, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(99); // Index
  servo[2].write(90); // Middle
  servo[3].write(81); // Ring
  servo[4].write(89); // Pinky

  // Step 167: Fingers [89, 99, 90, 81, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(99); // Index
  servo[2].write(90); // Middle
  servo[3].write(81); // Ring
  servo[4].write(89); // Pinky

  delay(33);
  // Step 168: Fingers [89, 99, 90, 81, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(99); // Index
  servo[2].write(90); // Middle
  servo[3].write(81); // Ring
  servo[4].write(89); // Pinky

  // Step 169: Fingers [90, 99, 91, 81, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(99); // Index
  servo[2].write(91); // Middle
  servo[3].write(81); // Ring
  servo[4].write(90); // Pinky

  // Step 170: Fingers [90, 100, 91, 82, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(100); // Index
  servo[2].write(91); // Middle
  servo[3].write(82); // Ring
  servo[4].write(90); // Pinky

  // Step 171: Fingers [91, 100, 92, 82, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(100); // Index
  servo[2].write(92); // Middle
  servo[3].write(82); // Ring
  servo[4].write(91); // Pinky

  // Step 172: Fingers [91, 100, 92, 82, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(100); // Index
  servo[2].write(92); // Middle
  servo[3].write(82); // Ring
  servo[4].write(91); // Pinky

  // Step 173: Fingers [92, 102, 94, 84, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(102); // Index
  servo[2].write(94); // Middle
  servo[3].write(84); // Ring
  servo[4].write(92); // Pinky

  // Step 174: Fingers [92, 102, 94, 84, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(102); // Index
  servo[2].write(94); // Middle
  servo[3].write(84); // Ring
  servo[4].write(92); // Pinky

  // Step 175: Fingers [93, 103, 95, 85, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(103); // Index
  servo[2].write(95); // Middle
  servo[3].write(85); // Ring
  servo[4].write(93); // Pinky

  // Step 176: Fingers [93, 103, 95, 85, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(103); // Index
  servo[2].write(95); // Middle
  servo[3].write(85); // Ring
  servo[4].write(93); // Pinky

  // Step 177: Fingers [93, 104, 96, 86, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(104); // Index
  servo[2].write(96); // Middle
  servo[3].write(86); // Ring
  servo[4].write(93); // Pinky

  // Step 178: Fingers [94, 104, 97, 86, 94] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(104); // Index
  servo[2].write(97); // Middle
  servo[3].write(86); // Ring
  servo[4].write(94); // Pinky

  // Step 179: Fingers [94, 105, 98, 87, 94] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(105); // Index
  servo[2].write(98); // Middle
  servo[3].write(87); // Ring
  servo[4].write(94); // Pinky

  // Step 180: Fingers [95, 105, 98, 88, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(105); // Index
  servo[2].write(98); // Middle
  servo[3].write(88); // Ring
  servo[4].write(95); // Pinky

  // Step 181: Fingers [95, 105, 98, 88, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(105); // Index
  servo[2].write(98); // Middle
  servo[3].write(88); // Ring
  servo[4].write(95); // Pinky

  // Step 182: Fingers [95, 105, 99, 88, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(105); // Index
  servo[2].write(99); // Middle
  servo[3].write(88); // Ring
  servo[4].write(95); // Pinky

  // Step 183: Fingers [95, 106, 99, 88, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(106); // Index
  servo[2].write(99); // Middle
  servo[3].write(88); // Ring
  servo[4].write(95); // Pinky

  delay(16);
  // Step 184: Fingers [95, 106, 99, 88, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(106); // Index
  servo[2].write(99); // Middle
  servo[3].write(88); // Ring
  servo[4].write(95); // Pinky

  // Step 185: Fingers [96, 107, 100, 89, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(107); // Index
  servo[2].write(100); // Middle
  servo[3].write(89); // Ring
  servo[4].write(96); // Pinky

  delay(17);
  // Step 186: Fingers [96, 107, 101, 90, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(107); // Index
  servo[2].write(101); // Middle
  servo[3].write(90); // Ring
  servo[4].write(96); // Pinky

  // Step 187: Fingers [96, 107, 101, 90, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(107); // Index
  servo[2].write(101); // Middle
  servo[3].write(90); // Ring
  servo[4].write(96); // Pinky

  // Step 188: Fingers [97, 108, 101, 90, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(108); // Index
  servo[2].write(101); // Middle
  servo[3].write(90); // Ring
  servo[4].write(97); // Pinky

  delay(18);
  // Step 189: Fingers [97, 108, 101, 90, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(108); // Index
  servo[2].write(101); // Middle
  servo[3].write(90); // Ring
  servo[4].write(97); // Pinky

  delay(11);
  // Step 190: Fingers [97, 108, 101, 90, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(108); // Index
  servo[2].write(101); // Middle
  servo[3].write(90); // Ring
  servo[4].write(97); // Pinky

  // Step 191: Fingers [97, 108, 102, 91, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(108); // Index
  servo[2].write(102); // Middle
  servo[3].write(91); // Ring
  servo[4].write(97); // Pinky

  delay(19);
  // Step 192: Fingers [97, 108, 102, 91, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(108); // Index
  servo[2].write(102); // Middle
  servo[3].write(91); // Ring
  servo[4].write(97); // Pinky

  // Step 193: Fingers [97, 108, 102, 91, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(108); // Index
  servo[2].write(102); // Middle
  servo[3].write(91); // Ring
  servo[4].write(97); // Pinky

  // Step 194: Fingers [98, 109, 103, 92, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(109); // Index
  servo[2].write(103); // Middle
  servo[3].write(92); // Ring
  servo[4].write(98); // Pinky

  delay(24);
  // Step 195: Fingers [98, 109, 103, 92, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(109); // Index
  servo[2].write(103); // Middle
  servo[3].write(92); // Ring
  servo[4].write(98); // Pinky

  // Step 196: Fingers [99, 110, 104, 93, 99] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(110); // Index
  servo[2].write(104); // Middle
  servo[3].write(93); // Ring
  servo[4].write(99); // Pinky

  delay(15);
  // Step 197: Fingers [100, 111, 105, 94, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(111); // Index
  servo[2].write(105); // Middle
  servo[3].write(94); // Ring
  servo[4].write(100); // Pinky

  // Step 198: Fingers [100, 111, 105, 94, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(111); // Index
  servo[2].write(105); // Middle
  servo[3].write(94); // Ring
  servo[4].write(100); // Pinky

  delay(37);
  // Step 199: Fingers [100, 111, 105, 94, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(111); // Index
  servo[2].write(105); // Middle
  servo[3].write(94); // Ring
  servo[4].write(100); // Pinky

  // Step 200: Fingers [100, 111, 106, 94, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(111); // Index
  servo[2].write(106); // Middle
  servo[3].write(94); // Ring
  servo[4].write(100); // Pinky

  delay(12);
  // Step 201: Fingers [101, 112, 106, 95, 101] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(112); // Index
  servo[2].write(106); // Middle
  servo[3].write(95); // Ring
  servo[4].write(101); // Pinky

  // Step 202: Fingers [101, 113, 107, 96, 101] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(113); // Index
  servo[2].write(107); // Middle
  servo[3].write(96); // Ring
  servo[4].write(101); // Pinky

  // Step 203: Fingers [101, 113, 107, 96, 101] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(113); // Index
  servo[2].write(107); // Middle
  servo[3].write(96); // Ring
  servo[4].write(101); // Pinky

  delay(16);
  // Step 204: Fingers [102, 113, 108, 96, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(113); // Index
  servo[2].write(108); // Middle
  servo[3].write(96); // Ring
  servo[4].write(102); // Pinky

  delay(13);
  // Step 205: Fingers [102, 113, 108, 96, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(113); // Index
  servo[2].write(108); // Middle
  servo[3].write(96); // Ring
  servo[4].write(102); // Pinky

  // Step 206: Fingers [103, 115, 109, 98, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(115); // Index
  servo[2].write(109); // Middle
  servo[3].write(98); // Ring
  servo[4].write(103); // Pinky

  delay(20);
  // Step 207: Fingers [103, 115, 109, 98, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(115); // Index
  servo[2].write(109); // Middle
  servo[3].write(98); // Ring
  servo[4].write(103); // Pinky

  // Step 208: Fingers [104, 115, 109, 98, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(115); // Index
  servo[2].write(109); // Middle
  servo[3].write(98); // Ring
  servo[4].write(104); // Pinky

  delay(13);
  // Step 209: Fingers [104, 116, 110, 99, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(116); // Index
  servo[2].write(110); // Middle
  servo[3].write(99); // Ring
  servo[4].write(104); // Pinky

  // Step 210: Fingers [104, 116, 110, 99, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(116); // Index
  servo[2].write(110); // Middle
  servo[3].write(99); // Ring
  servo[4].write(104); // Pinky

  // Step 211: Fingers [106, 117, 112, 100, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(117); // Index
  servo[2].write(112); // Middle
  servo[3].write(100); // Ring
  servo[4].write(106); // Pinky

  delay(16);
  // Step 212: Fingers [106, 118, 112, 101, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(118); // Index
  servo[2].write(112); // Middle
  servo[3].write(101); // Ring
  servo[4].write(106); // Pinky

  // Step 213: Fingers [106, 118, 112, 101, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(118); // Index
  servo[2].write(112); // Middle
  servo[3].write(101); // Ring
  servo[4].write(106); // Pinky

  // Step 214: Fingers [107, 118, 113, 101, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(118); // Index
  servo[2].write(113); // Middle
  servo[3].write(101); // Ring
  servo[4].write(107); // Pinky

  delay(25);
  // Step 215: Fingers [107, 118, 113, 101, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(118); // Index
  servo[2].write(113); // Middle
  servo[3].write(101); // Ring
  servo[4].write(107); // Pinky

  // Step 216: Fingers [108, 119, 114, 102, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(119); // Index
  servo[2].write(114); // Middle
  servo[3].write(102); // Ring
  servo[4].write(108); // Pinky

  delay(14);
  // Step 217: Fingers [108, 120, 114, 103, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(120); // Index
  servo[2].write(114); // Middle
  servo[3].write(103); // Ring
  servo[4].write(108); // Pinky

  // Step 218: Fingers [108, 120, 114, 103, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(120); // Index
  servo[2].write(114); // Middle
  servo[3].write(103); // Ring
  servo[4].write(108); // Pinky

  delay(19);
  // Step 219: Fingers [109, 120, 115, 103, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(120); // Index
  servo[2].write(115); // Middle
  servo[3].write(103); // Ring
  servo[4].write(109); // Pinky

  delay(13);
  // Step 220: Fingers [109, 120, 115, 103, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(120); // Index
  servo[2].write(115); // Middle
  servo[3].write(103); // Ring
  servo[4].write(109); // Pinky

  // Step 221: Fingers [110, 121, 115, 104, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(121); // Index
  servo[2].write(115); // Middle
  servo[3].write(104); // Ring
  servo[4].write(110); // Pinky

  // Step 222: Fingers [110, 122, 116, 105, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(122); // Index
  servo[2].write(116); // Middle
  servo[3].write(105); // Ring
  servo[4].write(110); // Pinky

  delay(14);
  // Step 223: Fingers [111, 122, 117, 105, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(122); // Index
  servo[2].write(117); // Middle
  servo[3].write(105); // Ring
  servo[4].write(111); // Pinky

  // Step 224: Fingers [111, 122, 117, 105, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(122); // Index
  servo[2].write(117); // Middle
  servo[3].write(105); // Ring
  servo[4].write(111); // Pinky

  delay(26);
  // Step 225: Fingers [111, 122, 117, 105, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(122); // Index
  servo[2].write(117); // Middle
  servo[3].write(105); // Ring
  servo[4].write(111); // Pinky

  delay(16);
  // Step 226: Fingers [111, 123, 117, 106, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(123); // Index
  servo[2].write(117); // Middle
  servo[3].write(106); // Ring
  servo[4].write(111); // Pinky

  delay(20);
  // Step 227: Fingers [111, 123, 117, 106, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(123); // Index
  servo[2].write(117); // Middle
  servo[3].write(106); // Ring
  servo[4].write(111); // Pinky

  // Step 228: Fingers [112, 124, 118, 107, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(124); // Index
  servo[2].write(118); // Middle
  servo[3].write(107); // Ring
  servo[4].write(112); // Pinky

  delay(21);
  // Step 229: Fingers [112, 124, 118, 107, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(124); // Index
  servo[2].write(118); // Middle
  servo[3].write(107); // Ring
  servo[4].write(112); // Pinky

  // Step 230: Fingers [113, 124, 119, 107, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(124); // Index
  servo[2].write(119); // Middle
  servo[3].write(107); // Ring
  servo[4].write(113); // Pinky

  // Step 231: Fingers [113, 125, 119, 108, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(125); // Index
  servo[2].write(119); // Middle
  servo[3].write(108); // Ring
  servo[4].write(113); // Pinky

  delay(16);
  // Step 232: Fingers [114, 125, 119, 108, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(125); // Index
  servo[2].write(119); // Middle
  servo[3].write(108); // Ring
  servo[4].write(114); // Pinky

  // Step 233: Fingers [114, 125, 119, 108, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(125); // Index
  servo[2].write(119); // Middle
  servo[3].write(108); // Ring
  servo[4].write(114); // Pinky

  // Step 234: Fingers [114, 126, 120, 108, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(126); // Index
  servo[2].write(120); // Middle
  servo[3].write(108); // Ring
  servo[4].write(114); // Pinky

  delay(14);
  // Step 235: Fingers [115, 126, 120, 109, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(126); // Index
  servo[2].write(120); // Middle
  servo[3].write(109); // Ring
  servo[4].write(115); // Pinky

  // Step 236: Fingers [115, 126, 120, 109, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(126); // Index
  servo[2].write(120); // Middle
  servo[3].write(109); // Ring
  servo[4].write(115); // Pinky

  delay(15);
  // Step 237: Fingers [115, 127, 121, 110, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(127); // Index
  servo[2].write(121); // Middle
  servo[3].write(110); // Ring
  servo[4].write(115); // Pinky

  // Step 238: Fingers [116, 127, 122, 110, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(127); // Index
  servo[2].write(122); // Middle
  servo[3].write(110); // Ring
  servo[4].write(116); // Pinky

  // Step 239: Fingers [116, 127, 122, 110, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(127); // Index
  servo[2].write(122); // Middle
  servo[3].write(110); // Ring
  servo[4].write(116); // Pinky

  delay(23);
  // Step 240: Fingers [117, 128, 122, 111, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(128); // Index
  servo[2].write(122); // Middle
  servo[3].write(111); // Ring
  servo[4].write(117); // Pinky

  // Step 241: Fingers [117, 128, 122, 111, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(128); // Index
  servo[2].write(122); // Middle
  servo[3].write(111); // Ring
  servo[4].write(117); // Pinky

  // Step 242: Fingers [117, 128, 122, 111, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(128); // Index
  servo[2].write(122); // Middle
  servo[3].write(111); // Ring
  servo[4].write(117); // Pinky

  // Step 243: Fingers [118, 129, 123, 112, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(129); // Index
  servo[2].write(123); // Middle
  servo[3].write(112); // Ring
  servo[4].write(118); // Pinky

  delay(16);
  // Step 244: Fingers [118, 129, 123, 112, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(129); // Index
  servo[2].write(123); // Middle
  servo[3].write(112); // Ring
  servo[4].write(118); // Pinky

  // Step 245: Fingers [118, 129, 122, 111, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(129); // Index
  servo[2].write(122); // Middle
  servo[3].write(111); // Ring
  servo[4].write(118); // Pinky

  // Step 246: Fingers [118, 129, 123, 112, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(129); // Index
  servo[2].write(123); // Middle
  servo[3].write(112); // Ring
  servo[4].write(118); // Pinky

  // Step 247: Fingers [119, 130, 124, 113, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(130); // Index
  servo[2].write(124); // Middle
  servo[3].write(113); // Ring
  servo[4].write(119); // Pinky

  // Step 248: Fingers [119, 130, 124, 113, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(130); // Index
  servo[2].write(124); // Middle
  servo[3].write(113); // Ring
  servo[4].write(119); // Pinky

  // Step 249: Fingers [119, 130, 124, 113, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(130); // Index
  servo[2].write(124); // Middle
  servo[3].write(113); // Ring
  servo[4].write(119); // Pinky

  // Step 250: Fingers [120, 131, 124, 113, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(131); // Index
  servo[2].write(124); // Middle
  servo[3].write(113); // Ring
  servo[4].write(120); // Pinky

  delay(18);
  // Step 251: Fingers [121, 131, 125, 114, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(131); // Index
  servo[2].write(125); // Middle
  servo[3].write(114); // Ring
  servo[4].write(121); // Pinky

  // Step 252: Fingers [121, 131, 125, 114, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(131); // Index
  servo[2].write(125); // Middle
  servo[3].write(114); // Ring
  servo[4].write(121); // Pinky

  // Step 253: Fingers [121, 131, 125, 114, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(131); // Index
  servo[2].write(125); // Middle
  servo[3].write(114); // Ring
  servo[4].write(121); // Pinky

  // Step 254: Fingers [121, 132, 125, 115, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(132); // Index
  servo[2].write(125); // Middle
  servo[3].write(115); // Ring
  servo[4].write(121); // Pinky

  // Step 255: Fingers [122, 133, 126, 115, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(133); // Index
  servo[2].write(126); // Middle
  servo[3].write(115); // Ring
  servo[4].write(122); // Pinky

  delay(17);
  // Step 256: Fingers [122, 133, 126, 115, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(133); // Index
  servo[2].write(126); // Middle
  servo[3].write(115); // Ring
  servo[4].write(122); // Pinky

  // Step 257: Fingers [123, 133, 126, 116, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(133); // Index
  servo[2].write(126); // Middle
  servo[3].write(116); // Ring
  servo[4].write(123); // Pinky

  // Step 258: Fingers [124, 134, 127, 116, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(134); // Index
  servo[2].write(127); // Middle
  servo[3].write(116); // Ring
  servo[4].write(124); // Pinky

  delay(14);
  // Step 259: Fingers [125, 135, 127, 117, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(135); // Index
  servo[2].write(127); // Middle
  servo[3].write(117); // Ring
  servo[4].write(125); // Pinky

  delay(12);
  // Step 260: Fingers [125, 135, 127, 117, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(135); // Index
  servo[2].write(127); // Middle
  servo[3].write(117); // Ring
  servo[4].write(125); // Pinky

  delay(30);
  // Step 261: Fingers [125, 135, 127, 117, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(135); // Index
  servo[2].write(127); // Middle
  servo[3].write(117); // Ring
  servo[4].write(125); // Pinky

  delay(22);
  // Step 262: Fingers [125, 135, 128, 118, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(135); // Index
  servo[2].write(128); // Middle
  servo[3].write(118); // Ring
  servo[4].write(125); // Pinky

  // Step 263: Fingers [125, 135, 128, 118, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(135); // Index
  servo[2].write(128); // Middle
  servo[3].write(118); // Ring
  servo[4].write(125); // Pinky

  // Step 264: Fingers [126, 135, 128, 118, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(135); // Index
  servo[2].write(128); // Middle
  servo[3].write(118); // Ring
  servo[4].write(126); // Pinky

  // Step 265: Fingers [126, 135, 127, 118, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(135); // Index
  servo[2].write(127); // Middle
  servo[3].write(118); // Ring
  servo[4].write(126); // Pinky

  // Step 266: Fingers [127, 136, 128, 118, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(136); // Index
  servo[2].write(128); // Middle
  servo[3].write(118); // Ring
  servo[4].write(127); // Pinky

  // Step 267: Fingers [127, 137, 128, 119, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(127); // Pinky

  // Step 268: Fingers [127, 137, 128, 119, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(127); // Pinky

  // Step 269: Fingers [127, 137, 128, 119, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(127); // Pinky

  delay(24);
  // Step 270: Fingers [127, 137, 128, 119, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(127); // Pinky

  delay(29);
  // Step 271: Fingers [127, 137, 128, 119, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(127); // Pinky

  delay(21);
  // Step 272: Fingers [128, 137, 128, 119, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(128); // Pinky

  // Step 273: Fingers [128, 137, 128, 119, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(128); // Pinky

  // Step 274: Fingers [128, 137, 128, 119, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(128); // Pinky

  // Step 275: Fingers [128, 137, 128, 119, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(128); // Pinky

  // Step 276: Fingers [129, 137, 128, 119, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(129); // Pinky

  delay(16);
  // Step 277: Fingers [129, 137, 128, 119, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(129); // Pinky

  // Step 278: Fingers [129, 137, 128, 119, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(129); // Pinky

  delay(28);
  // Step 279: Fingers [129, 137, 128, 119, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(129); // Pinky

  delay(22);
  // Step 280: Fingers [129, 137, 128, 119, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(129); // Pinky

  // Step 281: Fingers [129, 137, 128, 119, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(137); // Index
  servo[2].write(128); // Middle
  servo[3].write(119); // Ring
  servo[4].write(129); // Pinky

  // Step 282: Fingers [129, 137, 127, 119, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(137); // Index
  servo[2].write(127); // Middle
  servo[3].write(119); // Ring
  servo[4].write(129); // Pinky

  // Step 283: Fingers [130, 137, 127, 120, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(137); // Index
  servo[2].write(127); // Middle
  servo[3].write(120); // Ring
  servo[4].write(130); // Pinky

  // Step 284: Fingers [130, 137, 127, 120, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(137); // Index
  servo[2].write(127); // Middle
  servo[3].write(120); // Ring
  servo[4].write(130); // Pinky

  // Step 285: Fingers [131, 137, 126, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(137); // Index
  servo[2].write(126); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  // Step 286: Fingers [131, 137, 126, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(137); // Index
  servo[2].write(126); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  delay(17);
  // Step 287: Fingers [131, 137, 126, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(137); // Index
  servo[2].write(126); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  // Step 288: Fingers [131, 137, 126, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(137); // Index
  servo[2].write(126); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  // Step 289: Fingers [131, 137, 125, 120, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(137); // Index
  servo[2].write(125); // Middle
  servo[3].write(120); // Ring
  servo[4].write(131); // Pinky

  // Step 290: Fingers [132, 137, 125, 120, 132] Arm [-, -, -]
  servo[0].write(132); // Thumb
  servo[1].write(137); // Index
  servo[2].write(125); // Middle
  servo[3].write(120); // Ring
  servo[4].write(132); // Pinky

  // Step 291: Fingers [132, 137, 125, 120, 132] Arm [-, -, -]
  servo[0].write(132); // Thumb
  servo[1].write(137); // Index
  servo[2].write(125); // Middle
  servo[3].write(120); // Ring
  servo[4].write(132); // Pinky

  delay(30);
  // Step 292: Fingers [132, 137, 125, 120, 132] Arm [-, -, -]
  servo[0].write(132); // Thumb
  servo[1].write(137); // Index
  servo[2].write(125); // Middle
  servo[3].write(120); // Ring
  servo[4].write(132); // Pinky

  delay(30);
  // Step 293: Fingers [132, 137, 125, 120, 132] Arm [-, -, -]
  servo[0].write(132); // Thumb
  servo[1].write(137); // Index
  servo[2].write(125); // Middle
  servo[3].write(120); // Ring
  servo[4].write(132); // Pinky

  delay(23);
  // Step 294: Fingers [131, 136, 124, 119, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(136); // Index
  servo[2].write(124); // Middle
  servo[3].write(119); // Ring
  servo[4].write(131); // Pinky

  // Step 295: Fingers [131, 136, 124, 119, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(136); // Index
  servo[2].write(124); // Middle
  servo[3].write(119); // Ring
  servo[4].write(131); // Pinky

  // Step 296: Fingers [131, 136, 124, 119, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(136); // Index
  servo[2].write(124); // Middle
  servo[3].write(119); // Ring
  servo[4].write(131); // Pinky

  // Step 297: Fingers [131, 135, 123, 119, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(135); // Index
  servo[2].write(123); // Middle
  servo[3].write(119); // Ring
  servo[4].write(131); // Pinky

  // Step 298: Fingers [130, 135, 123, 118, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(135); // Index
  servo[2].write(123); // Middle
  servo[3].write(118); // Ring
  servo[4].write(130); // Pinky

  // Step 299: Fingers [130, 135, 123, 118, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(135); // Index
  servo[2].write(123); // Middle
  servo[3].write(118); // Ring
  servo[4].write(130); // Pinky

  delay(14);
  // Step 300: Fingers [130, 134, 122, 118, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(134); // Index
  servo[2].write(122); // Middle
  servo[3].write(118); // Ring
  servo[4].write(130); // Pinky

  delay(22);
  // Step 301: Fingers [130, 134, 122, 118, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(134); // Index
  servo[2].write(122); // Middle
  servo[3].write(118); // Ring
  servo[4].write(130); // Pinky

  // Step 302: Fingers [129, 133, 121, 117, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(133); // Index
  servo[2].write(121); // Middle
  servo[3].write(117); // Ring
  servo[4].write(129); // Pinky

  // Step 303: Fingers [129, 133, 120, 117, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(133); // Index
  servo[2].write(120); // Middle
  servo[3].write(117); // Ring
  servo[4].write(129); // Pinky

  // Step 304: Fingers [128, 132, 120, 116, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(132); // Index
  servo[2].write(120); // Middle
  servo[3].write(116); // Ring
  servo[4].write(128); // Pinky

  // Step 305: Fingers [128, 131, 119, 116, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(131); // Index
  servo[2].write(119); // Middle
  servo[3].write(116); // Ring
  servo[4].write(128); // Pinky

  // Step 306: Fingers [128, 131, 119, 116, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(131); // Index
  servo[2].write(119); // Middle
  servo[3].write(116); // Ring
  servo[4].write(128); // Pinky

  // Step 307: Fingers [127, 130, 118, 115, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(130); // Index
  servo[2].write(118); // Middle
  servo[3].write(115); // Ring
  servo[4].write(127); // Pinky

  // Step 308: Fingers [127, 130, 117, 114, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(130); // Index
  servo[2].write(117); // Middle
  servo[3].write(114); // Ring
  servo[4].write(127); // Pinky

  // Step 309: Fingers [126, 129, 117, 114, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(129); // Index
  servo[2].write(117); // Middle
  servo[3].write(114); // Ring
  servo[4].write(126); // Pinky

  // Step 310: Fingers [126, 129, 117, 114, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(129); // Index
  servo[2].write(117); // Middle
  servo[3].write(114); // Ring
  servo[4].write(126); // Pinky

  // Step 311: Fingers [126, 128, 116, 113, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(128); // Index
  servo[2].write(116); // Middle
  servo[3].write(113); // Ring
  servo[4].write(126); // Pinky

  // Step 312: Fingers [125, 128, 115, 113, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(128); // Index
  servo[2].write(115); // Middle
  servo[3].write(113); // Ring
  servo[4].write(125); // Pinky

  delay(16);
  // Step 313: Fingers [125, 127, 114, 112, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(127); // Index
  servo[2].write(114); // Middle
  servo[3].write(112); // Ring
  servo[4].write(125); // Pinky

  // Step 314: Fingers [125, 127, 114, 112, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(127); // Index
  servo[2].write(114); // Middle
  servo[3].write(112); // Ring
  servo[4].write(125); // Pinky

  // Step 315: Fingers [124, 126, 114, 112, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(126); // Index
  servo[2].write(114); // Middle
  servo[3].write(112); // Ring
  servo[4].write(124); // Pinky

  // Step 316: Fingers [123, 126, 113, 111, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(126); // Index
  servo[2].write(113); // Middle
  servo[3].write(111); // Ring
  servo[4].write(123); // Pinky

  delay(15);
  // Step 317: Fingers [123, 126, 113, 111, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(126); // Index
  servo[2].write(113); // Middle
  servo[3].write(111); // Ring
  servo[4].write(123); // Pinky

  // Step 318: Fingers [123, 125, 112, 110, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(125); // Index
  servo[2].write(112); // Middle
  servo[3].write(110); // Ring
  servo[4].write(123); // Pinky

  // Step 319: Fingers [122, 124, 112, 110, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(124); // Index
  servo[2].write(112); // Middle
  servo[3].write(110); // Ring
  servo[4].write(122); // Pinky

  // Step 320: Fingers [122, 124, 111, 109, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(124); // Index
  servo[2].write(111); // Middle
  servo[3].write(109); // Ring
  servo[4].write(122); // Pinky

  // Step 321: Fingers [122, 124, 111, 109, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(124); // Index
  servo[2].write(111); // Middle
  servo[3].write(109); // Ring
  servo[4].write(122); // Pinky

  // Step 322: Fingers [120, 122, 110, 108, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(122); // Index
  servo[2].write(110); // Middle
  servo[3].write(108); // Ring
  servo[4].write(120); // Pinky

  // Step 323: Fingers [120, 122, 109, 107, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(122); // Index
  servo[2].write(109); // Middle
  servo[3].write(107); // Ring
  servo[4].write(120); // Pinky

  // Step 324: Fingers [119, 120, 108, 106, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(120); // Index
  servo[2].write(108); // Middle
  servo[3].write(106); // Ring
  servo[4].write(119); // Pinky

  // Step 325: Fingers [119, 120, 108, 106, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(120); // Index
  servo[2].write(108); // Middle
  servo[3].write(106); // Ring
  servo[4].write(119); // Pinky

  // Step 326: Fingers [118, 120, 107, 105, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(120); // Index
  servo[2].write(107); // Middle
  servo[3].write(105); // Ring
  servo[4].write(118); // Pinky

  // Step 327: Fingers [117, 119, 106, 105, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(119); // Index
  servo[2].write(106); // Middle
  servo[3].write(105); // Ring
  servo[4].write(117); // Pinky

  delay(17);
  // Step 328: Fingers [117, 119, 106, 105, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(119); // Index
  servo[2].write(106); // Middle
  servo[3].write(105); // Ring
  servo[4].write(117); // Pinky

  // Step 329: Fingers [116, 118, 105, 103, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(118); // Index
  servo[2].write(105); // Middle
  servo[3].write(103); // Ring
  servo[4].write(116); // Pinky

  // Step 330: Fingers [115, 117, 105, 103, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(117); // Index
  servo[2].write(105); // Middle
  servo[3].write(103); // Ring
  servo[4].write(115); // Pinky

  // Step 331: Fingers [115, 117, 104, 102, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(117); // Index
  servo[2].write(104); // Middle
  servo[3].write(102); // Ring
  servo[4].write(115); // Pinky

  delay(15);
  // Step 332: Fingers [115, 117, 104, 102, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(117); // Index
  servo[2].write(104); // Middle
  servo[3].write(102); // Ring
  servo[4].write(115); // Pinky

  // Step 333: Fingers [114, 116, 103, 101, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(116); // Index
  servo[2].write(103); // Middle
  servo[3].write(101); // Ring
  servo[4].write(114); // Pinky

  // Step 334: Fingers [113, 115, 103, 101, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(115); // Index
  servo[2].write(103); // Middle
  servo[3].write(101); // Ring
  servo[4].write(113); // Pinky

  // Step 335: Fingers [113, 115, 102, 100, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(115); // Index
  servo[2].write(102); // Middle
  servo[3].write(100); // Ring
  servo[4].write(113); // Pinky

  // Step 336: Fingers [112, 114, 101, 100, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(114); // Index
  servo[2].write(101); // Middle
  servo[3].write(100); // Ring
  servo[4].write(112); // Pinky

  // Step 337: Fingers [112, 114, 101, 100, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(114); // Index
  servo[2].write(101); // Middle
  servo[3].write(100); // Ring
  servo[4].write(112); // Pinky

  // Step 338: Fingers [111, 113, 101, 99, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(113); // Index
  servo[2].write(101); // Middle
  servo[3].write(99); // Ring
  servo[4].write(111); // Pinky

  // Step 339: Fingers [111, 113, 100, 98, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(113); // Index
  servo[2].write(100); // Middle
  servo[3].write(98); // Ring
  servo[4].write(111); // Pinky

  // Step 340: Fingers [110, 112, 100, 98, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(112); // Index
  servo[2].write(100); // Middle
  servo[3].write(98); // Ring
  servo[4].write(110); // Pinky

  // Step 341: Fingers [109, 112, 99, 97, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(112); // Index
  servo[2].write(99); // Middle
  servo[3].write(97); // Ring
  servo[4].write(109); // Pinky

  // Step 342: Fingers [109, 112, 99, 97, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(112); // Index
  servo[2].write(99); // Middle
  servo[3].write(97); // Ring
  servo[4].write(109); // Pinky

  // Step 343: Fingers [109, 111, 98, 96, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(111); // Index
  servo[2].write(98); // Middle
  servo[3].write(96); // Ring
  servo[4].write(109); // Pinky

  // Step 344: Fingers [108, 110, 98, 95, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(110); // Index
  servo[2].write(98); // Middle
  servo[3].write(95); // Ring
  servo[4].write(108); // Pinky

  // Step 345: Fingers [108, 110, 98, 95, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(110); // Index
  servo[2].write(98); // Middle
  servo[3].write(95); // Ring
  servo[4].write(108); // Pinky

  // Step 346: Fingers [107, 109, 97, 94, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(109); // Index
  servo[2].write(97); // Middle
  servo[3].write(94); // Ring
  servo[4].write(107); // Pinky

  // Step 347: Fingers [107, 109, 97, 94, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(109); // Index
  servo[2].write(97); // Middle
  servo[3].write(94); // Ring
  servo[4].write(107); // Pinky

  delay(17);
  // Step 348: Fingers [106, 109, 96, 93, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(109); // Index
  servo[2].write(96); // Middle
  servo[3].write(93); // Ring
  servo[4].write(106); // Pinky

  // Step 349: Fingers [106, 109, 96, 93, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(109); // Index
  servo[2].write(96); // Middle
  servo[3].write(93); // Ring
  servo[4].write(106); // Pinky

  // Step 350: Fingers [106, 109, 96, 93, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(109); // Index
  servo[2].write(96); // Middle
  servo[3].write(93); // Ring
  servo[4].write(106); // Pinky

  // Step 351: Fingers [105, 108, 96, 93, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(93); // Ring
  servo[4].write(105); // Pinky

  delay(14);
  // Step 352: Fingers [105, 108, 96, 93, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(93); // Ring
  servo[4].write(105); // Pinky

  delay(18);
  // Step 353: Fingers [104, 108, 95, 92, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(108); // Index
  servo[2].write(95); // Middle
  servo[3].write(92); // Ring
  servo[4].write(104); // Pinky

  delay(15);
  // Step 354: Fingers [104, 108, 96, 92, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(92); // Ring
  servo[4].write(104); // Pinky

  // Step 355: Fingers [104, 108, 96, 92, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(92); // Ring
  servo[4].write(104); // Pinky

  // Step 356: Fingers [104, 108, 96, 92, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(92); // Ring
  servo[4].write(104); // Pinky

  // Step 357: Fingers [103, 107, 95, 91, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(107); // Index
  servo[2].write(95); // Middle
  servo[3].write(91); // Ring
  servo[4].write(103); // Pinky

  // Step 358: Fingers [103, 107, 95, 91, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(107); // Index
  servo[2].write(95); // Middle
  servo[3].write(91); // Ring
  servo[4].write(103); // Pinky

  // Step 359: Fingers [103, 107, 95, 91, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(107); // Index
  servo[2].write(95); // Middle
  servo[3].write(91); // Ring
  servo[4].write(103); // Pinky

  // Step 360: Fingers [103, 107, 96, 91, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(107); // Index
  servo[2].write(96); // Middle
  servo[3].write(91); // Ring
  servo[4].write(103); // Pinky

  // Step 361: Fingers [102, 107, 96, 91, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(107); // Index
  servo[2].write(96); // Middle
  servo[3].write(91); // Ring
  servo[4].write(102); // Pinky

  // Step 362: Fingers [102, 108, 96, 91, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(91); // Ring
  servo[4].write(102); // Pinky

  delay(15);
  // Step 363: Fingers [102, 108, 96, 91, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(91); // Ring
  servo[4].write(102); // Pinky

  delay(38);
  // Step 364: Fingers [102, 108, 96, 91, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(91); // Ring
  servo[4].write(102); // Pinky

  // Step 365: Fingers [102, 108, 96, 91, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(91); // Ring
  servo[4].write(102); // Pinky

  // Step 366: Fingers [102, 108, 96, 91, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(91); // Ring
  servo[4].write(102); // Pinky

  delay(12);
  // Step 367: Fingers [102, 108, 96, 91, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(91); // Ring
  servo[4].write(102); // Pinky

  // Step 368: Fingers [102, 108, 97, 91, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(108); // Index
  servo[2].write(97); // Middle
  servo[3].write(91); // Ring
  servo[4].write(102); // Pinky

  // Step 369: Fingers [103, 109, 98, 92, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(109); // Index
  servo[2].write(98); // Middle
  servo[3].write(92); // Ring
  servo[4].write(103); // Pinky

  // Step 370: Fingers [103, 110, 99, 92, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(110); // Index
  servo[2].write(99); // Middle
  servo[3].write(92); // Ring
  servo[4].write(103); // Pinky

  // Step 371: Fingers [103, 110, 99, 92, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(110); // Index
  servo[2].write(99); // Middle
  servo[3].write(92); // Ring
  servo[4].write(103); // Pinky

  // Step 372: Fingers [103, 111, 100, 93, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(111); // Index
  servo[2].write(100); // Middle
  servo[3].write(93); // Ring
  servo[4].write(103); // Pinky

  // Step 373: Fingers [104, 111, 101, 93, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(111); // Index
  servo[2].write(101); // Middle
  servo[3].write(93); // Ring
  servo[4].write(104); // Pinky

  // Step 374: Fingers [104, 112, 102, 94, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(112); // Index
  servo[2].write(102); // Middle
  servo[3].write(94); // Ring
  servo[4].write(104); // Pinky

  // Step 375: Fingers [104, 112, 102, 94, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(112); // Index
  servo[2].write(102); // Middle
  servo[3].write(94); // Ring
  servo[4].write(104); // Pinky

  // Step 376: Fingers [104, 112, 102, 94, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(112); // Index
  servo[2].write(102); // Middle
  servo[3].write(94); // Ring
  servo[4].write(104); // Pinky

  // Step 377: Fingers [105, 113, 103, 95, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(113); // Index
  servo[2].write(103); // Middle
  servo[3].write(95); // Ring
  servo[4].write(105); // Pinky

  delay(13);
  // Step 378: Fingers [105, 113, 103, 95, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(113); // Index
  servo[2].write(103); // Middle
  servo[3].write(95); // Ring
  servo[4].write(105); // Pinky

  // Step 379: Fingers [105, 113, 103, 95, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(113); // Index
  servo[2].write(103); // Middle
  servo[3].write(95); // Ring
  servo[4].write(105); // Pinky

  // Step 380: Fingers [106, 114, 104, 96, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(114); // Index
  servo[2].write(104); // Middle
  servo[3].write(96); // Ring
  servo[4].write(106); // Pinky

  // Step 381: Fingers [106, 114, 105, 97, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(114); // Index
  servo[2].write(105); // Middle
  servo[3].write(97); // Ring
  servo[4].write(106); // Pinky

  delay(15);
  // Step 382: Fingers [108, 116, 106, 98, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(116); // Index
  servo[2].write(106); // Middle
  servo[3].write(98); // Ring
  servo[4].write(108); // Pinky

  // Step 383: Fingers [108, 116, 106, 98, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(116); // Index
  servo[2].write(106); // Middle
  servo[3].write(98); // Ring
  servo[4].write(108); // Pinky

  // Step 384: Fingers [108, 116, 107, 98, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(116); // Index
  servo[2].write(107); // Middle
  servo[3].write(98); // Ring
  servo[4].write(108); // Pinky

  // Step 385: Fingers [108, 116, 107, 98, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(116); // Index
  servo[2].write(107); // Middle
  servo[3].write(98); // Ring
  servo[4].write(108); // Pinky

  delay(14);
  // Step 386: Fingers [109, 118, 108, 100, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(118); // Index
  servo[2].write(108); // Middle
  servo[3].write(100); // Ring
  servo[4].write(109); // Pinky

  // Step 387: Fingers [109, 118, 108, 100, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(118); // Index
  servo[2].write(108); // Middle
  servo[3].write(100); // Ring
  servo[4].write(109); // Pinky

  delay(15);
  // Step 388: Fingers [110, 118, 109, 100, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(118); // Index
  servo[2].write(109); // Middle
  servo[3].write(100); // Ring
  servo[4].write(110); // Pinky

  // Step 389: Fingers [110, 119, 110, 101, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(119); // Index
  servo[2].write(110); // Middle
  servo[3].write(101); // Ring
  servo[4].write(110); // Pinky

  // Step 390: Fingers [110, 119, 110, 101, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(119); // Index
  servo[2].write(110); // Middle
  servo[3].write(101); // Ring
  servo[4].write(110); // Pinky

  // Step 391: Fingers [111, 120, 110, 102, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(120); // Index
  servo[2].write(110); // Middle
  servo[3].write(102); // Ring
  servo[4].write(111); // Pinky

  // Step 392: Fingers [111, 120, 111, 102, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(120); // Index
  servo[2].write(111); // Middle
  servo[3].write(102); // Ring
  servo[4].write(111); // Pinky

  delay(16);
  // Step 393: Fingers [112, 121, 113, 103, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(121); // Index
  servo[2].write(113); // Middle
  servo[3].write(103); // Ring
  servo[4].write(112); // Pinky

  // Step 394: Fingers [112, 121, 113, 103, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(121); // Index
  servo[2].write(113); // Middle
  servo[3].write(103); // Ring
  servo[4].write(112); // Pinky

  // Step 395: Fingers [114, 123, 114, 105, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(123); // Index
  servo[2].write(114); // Middle
  servo[3].write(105); // Ring
  servo[4].write(114); // Pinky

  // Step 396: Fingers [114, 123, 115, 105, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(123); // Index
  servo[2].write(115); // Middle
  servo[3].write(105); // Ring
  servo[4].write(114); // Pinky

  // Step 397: Fingers [115, 124, 115, 106, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(124); // Index
  servo[2].write(115); // Middle
  servo[3].write(106); // Ring
  servo[4].write(115); // Pinky

  // Step 398: Fingers [115, 125, 116, 107, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(125); // Index
  servo[2].write(116); // Middle
  servo[3].write(107); // Ring
  servo[4].write(115); // Pinky

  // Step 399: Fingers [115, 125, 116, 107, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(125); // Index
  servo[2].write(116); // Middle
  servo[3].write(107); // Ring
  servo[4].write(115); // Pinky

  // Step 400: Fingers [116, 125, 117, 107, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(125); // Index
  servo[2].write(117); // Middle
  servo[3].write(107); // Ring
  servo[4].write(116); // Pinky

  // Step 401: Fingers [116, 126, 118, 108, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(126); // Index
  servo[2].write(118); // Middle
  servo[3].write(108); // Ring
  servo[4].write(116); // Pinky

  // Step 402: Fingers [116, 126, 118, 108, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(126); // Index
  servo[2].write(118); // Middle
  servo[3].write(108); // Ring
  servo[4].write(116); // Pinky

  delay(14);
  // Step 403: Fingers [117, 127, 118, 109, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(127); // Index
  servo[2].write(118); // Middle
  servo[3].write(109); // Ring
  servo[4].write(117); // Pinky

  // Step 404: Fingers [118, 127, 119, 109, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(127); // Index
  servo[2].write(119); // Middle
  servo[3].write(109); // Ring
  servo[4].write(118); // Pinky

  // Step 405: Fingers [118, 127, 119, 109, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(127); // Index
  servo[2].write(119); // Middle
  servo[3].write(109); // Ring
  servo[4].write(118); // Pinky

  delay(14);
  // Step 406: Fingers [118, 128, 119, 110, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(128); // Index
  servo[2].write(119); // Middle
  servo[3].write(110); // Ring
  servo[4].write(118); // Pinky

  // Step 407: Fingers [119, 128, 120, 111, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(128); // Index
  servo[2].write(120); // Middle
  servo[3].write(111); // Ring
  servo[4].write(119); // Pinky

  delay(15);
  // Step 408: Fingers [119, 128, 120, 111, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(128); // Index
  servo[2].write(120); // Middle
  servo[3].write(111); // Ring
  servo[4].write(119); // Pinky

  delay(12);
  // Step 409: Fingers [120, 130, 122, 112, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(130); // Index
  servo[2].write(122); // Middle
  servo[3].write(112); // Ring
  servo[4].write(120); // Pinky

  // Step 410: Fingers [121, 131, 123, 113, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(131); // Index
  servo[2].write(123); // Middle
  servo[3].write(113); // Ring
  servo[4].write(121); // Pinky

  // Step 411: Fingers [123, 132, 124, 114, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(132); // Index
  servo[2].write(124); // Middle
  servo[3].write(114); // Ring
  servo[4].write(123); // Pinky

  // Step 412: Fingers [123, 132, 124, 114, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(132); // Index
  servo[2].write(124); // Middle
  servo[3].write(114); // Ring
  servo[4].write(123); // Pinky

  delay(13);
  // Step 413: Fingers [123, 133, 125, 115, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(133); // Index
  servo[2].write(125); // Middle
  servo[3].write(115); // Ring
  servo[4].write(123); // Pinky

  // Step 414: Fingers [124, 134, 125, 116, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(134); // Index
  servo[2].write(125); // Middle
  servo[3].write(116); // Ring
  servo[4].write(124); // Pinky

  // Step 415: Fingers [124, 134, 126, 116, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(134); // Index
  servo[2].write(126); // Middle
  servo[3].write(116); // Ring
  servo[4].write(124); // Pinky

  // Step 416: Fingers [125, 135, 127, 117, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(135); // Index
  servo[2].write(127); // Middle
  servo[3].write(117); // Ring
  servo[4].write(125); // Pinky

  // Step 417: Fingers [125, 135, 127, 117, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(135); // Index
  servo[2].write(127); // Middle
  servo[3].write(117); // Ring
  servo[4].write(125); // Pinky

  delay(16);
  // Step 418: Fingers [126, 135, 127, 118, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(135); // Index
  servo[2].write(127); // Middle
  servo[3].write(118); // Ring
  servo[4].write(126); // Pinky

  // Step 419: Fingers [126, 136, 128, 118, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(136); // Index
  servo[2].write(128); // Middle
  servo[3].write(118); // Ring
  servo[4].write(126); // Pinky

  // Step 420: Fingers [127, 137, 129, 119, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(137); // Index
  servo[2].write(129); // Middle
  servo[3].write(119); // Ring
  servo[4].write(127); // Pinky

  // Step 421: Fingers [128, 137, 129, 119, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(137); // Index
  servo[2].write(129); // Middle
  servo[3].write(119); // Ring
  servo[4].write(128); // Pinky

  // Step 422: Fingers [128, 137, 129, 119, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(137); // Index
  servo[2].write(129); // Middle
  servo[3].write(119); // Ring
  servo[4].write(128); // Pinky

  delay(13);
  // Step 423: Fingers [128, 138, 130, 120, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(138); // Index
  servo[2].write(130); // Middle
  servo[3].write(120); // Ring
  servo[4].write(128); // Pinky

  delay(15);
  // Step 424: Fingers [128, 138, 130, 120, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(138); // Index
  servo[2].write(130); // Middle
  servo[3].write(120); // Ring
  servo[4].write(128); // Pinky

  // Step 425: Fingers [129, 139, 131, 121, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(139); // Index
  servo[2].write(131); // Middle
  servo[3].write(121); // Ring
  servo[4].write(129); // Pinky

  // Step 426: Fingers [130, 139, 131, 121, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(139); // Index
  servo[2].write(131); // Middle
  servo[3].write(121); // Ring
  servo[4].write(130); // Pinky

  // Step 427: Fingers [130, 140, 132, 122, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(140); // Index
  servo[2].write(132); // Middle
  servo[3].write(122); // Ring
  servo[4].write(130); // Pinky

  // Step 428: Fingers [130, 140, 132, 122, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(140); // Index
  servo[2].write(132); // Middle
  servo[3].write(122); // Ring
  servo[4].write(130); // Pinky

  // Step 429: Fingers [131, 141, 132, 123, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(141); // Index
  servo[2].write(132); // Middle
  servo[3].write(123); // Ring
  servo[4].write(131); // Pinky

  // Step 430: Fingers [131, 141, 133, 123, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(141); // Index
  servo[2].write(133); // Middle
  servo[3].write(123); // Ring
  servo[4].write(131); // Pinky

  delay(16);
  // Step 431: Fingers [131, 141, 133, 123, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(141); // Index
  servo[2].write(133); // Middle
  servo[3].write(123); // Ring
  servo[4].write(131); // Pinky

  // Step 432: Fingers [133, 142, 134, 125, 133] Arm [-, -, -]
  servo[0].write(133); // Thumb
  servo[1].write(142); // Index
  servo[2].write(134); // Middle
  servo[3].write(125); // Ring
  servo[4].write(133); // Pinky

  // Step 433: Fingers [133, 143, 135, 125, 133] Arm [-, -, -]
  servo[0].write(133); // Thumb
  servo[1].write(143); // Index
  servo[2].write(135); // Middle
  servo[3].write(125); // Ring
  servo[4].write(133); // Pinky

  // Step 434: Fingers [135, 144, 136, 126, 135] Arm [-, -, -]
  servo[0].write(135); // Thumb
  servo[1].write(144); // Index
  servo[2].write(136); // Middle
  servo[3].write(126); // Ring
  servo[4].write(135); // Pinky

  // Step 435: Fingers [135, 144, 136, 126, 135] Arm [-, -, -]
  servo[0].write(135); // Thumb
  servo[1].write(144); // Index
  servo[2].write(136); // Middle
  servo[3].write(126); // Ring
  servo[4].write(135); // Pinky

  // Step 436: Fingers [136, 146, 138, 128, 136] Arm [-, -, -]
  servo[0].write(136); // Thumb
  servo[1].write(146); // Index
  servo[2].write(138); // Middle
  servo[3].write(128); // Ring
  servo[4].write(136); // Pinky

  // Step 437: Fingers [138, 148, 140, 130, 138] Arm [-, -, -]
  servo[0].write(138); // Thumb
  servo[1].write(148); // Index
  servo[2].write(140); // Middle
  servo[3].write(130); // Ring
  servo[4].write(138); // Pinky

  // Step 438: Fingers [140, 150, 141, 132, 140] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(150); // Index
  servo[2].write(141); // Middle
  servo[3].write(132); // Ring
  servo[4].write(140); // Pinky

  // Step 439: Fingers [140, 150, 141, 132, 140] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(150); // Index
  servo[2].write(141); // Middle
  servo[3].write(132); // Ring
  servo[4].write(140); // Pinky

  // Step 440: Fingers [142, 151, 143, 133, 142] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(151); // Index
  servo[2].write(143); // Middle
  servo[3].write(133); // Ring
  servo[4].write(142); // Pinky

  // Step 441: Fingers [144, 153, 145, 135, 144] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(153); // Index
  servo[2].write(145); // Middle
  servo[3].write(135); // Ring
  servo[4].write(144); // Pinky

  // Step 442: Fingers [146, 155, 147, 137, 146] Arm [-, -, -]
  servo[0].write(146); // Thumb
  servo[1].write(155); // Index
  servo[2].write(147); // Middle
  servo[3].write(137); // Ring
  servo[4].write(146); // Pinky

  // Step 443: Fingers [147, 157, 148, 139, 147] Arm [-, -, -]
  servo[0].write(147); // Thumb
  servo[1].write(157); // Index
  servo[2].write(148); // Middle
  servo[3].write(139); // Ring
  servo[4].write(147); // Pinky

  // Step 444: Fingers [147, 157, 148, 139, 147] Arm [-, -, -]
  servo[0].write(147); // Thumb
  servo[1].write(157); // Index
  servo[2].write(148); // Middle
  servo[3].write(139); // Ring
  servo[4].write(147); // Pinky

  // Step 445: Fingers [149, 158, 150, 140, 149] Arm [-, -, -]
  servo[0].write(149); // Thumb
  servo[1].write(158); // Index
  servo[2].write(150); // Middle
  servo[3].write(140); // Ring
  servo[4].write(149); // Pinky

  // Step 446: Fingers [150, 159, 150, 141, 150] Arm [-, -, -]
  servo[0].write(150); // Thumb
  servo[1].write(159); // Index
  servo[2].write(150); // Middle
  servo[3].write(141); // Ring
  servo[4].write(150); // Pinky

  // Step 447: Fingers [151, 160, 151, 142, 151] Arm [-, -, -]
  servo[0].write(151); // Thumb
  servo[1].write(160); // Index
  servo[2].write(151); // Middle
  servo[3].write(142); // Ring
  servo[4].write(151); // Pinky

  // Step 448: Fingers [151, 160, 152, 142, 151] Arm [-, -, -]
  servo[0].write(151); // Thumb
  servo[1].write(160); // Index
  servo[2].write(152); // Middle
  servo[3].write(142); // Ring
  servo[4].write(151); // Pinky

  // Step 449: Fingers [151, 160, 152, 142, 151] Arm [-, -, -]
  servo[0].write(151); // Thumb
  servo[1].write(160); // Index
  servo[2].write(152); // Middle
  servo[3].write(142); // Ring
  servo[4].write(151); // Pinky

  delay(16);
  // Step 450: Fingers [152, 161, 152, 143, 152] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(161); // Index
  servo[2].write(152); // Middle
  servo[3].write(143); // Ring
  servo[4].write(152); // Pinky

  delay(13);
  // Step 451: Fingers [152, 161, 152, 143, 152] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(161); // Index
  servo[2].write(152); // Middle
  servo[3].write(143); // Ring
  servo[4].write(152); // Pinky

  // Step 452: Fingers [152, 162, 153, 144, 152] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(162); // Index
  servo[2].write(153); // Middle
  servo[3].write(144); // Ring
  servo[4].write(152); // Pinky

  delay(18);
  // Step 453: Fingers [152, 162, 153, 144, 152] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(162); // Index
  servo[2].write(153); // Middle
  servo[3].write(144); // Ring
  servo[4].write(152); // Pinky

  // Step 454: Fingers [153, 162, 154, 144, 153] Arm [-, -, -]
  servo[0].write(153); // Thumb
  servo[1].write(162); // Index
  servo[2].write(154); // Middle
  servo[3].write(144); // Ring
  servo[4].write(153); // Pinky

  // Step 455: Fingers [154, 163, 154, 145, 154] Arm [-, -, -]
  servo[0].write(154); // Thumb
  servo[1].write(163); // Index
  servo[2].write(154); // Middle
  servo[3].write(145); // Ring
  servo[4].write(154); // Pinky

  delay(17);
  // Step 456: Fingers [154, 163, 154, 145, 154] Arm [-, -, -]
  servo[0].write(154); // Thumb
  servo[1].write(163); // Index
  servo[2].write(154); // Middle
  servo[3].write(145); // Ring
  servo[4].write(154); // Pinky

  // Step 457: Fingers [155, 164, 155, 146, 155] Arm [-, -, -]
  servo[0].write(155); // Thumb
  servo[1].write(164); // Index
  servo[2].write(155); // Middle
  servo[3].write(146); // Ring
  servo[4].write(155); // Pinky

  // Step 458: Fingers [155, 164, 155, 146, 155] Arm [-, -, -]
  servo[0].write(155); // Thumb
  servo[1].write(164); // Index
  servo[2].write(155); // Middle
  servo[3].write(146); // Ring
  servo[4].write(155); // Pinky

  delay(11);
  // Step 459: Fingers [156, 165, 156, 147, 156] Arm [-, -, -]
  servo[0].write(156); // Thumb
  servo[1].write(165); // Index
  servo[2].write(156); // Middle
  servo[3].write(147); // Ring
  servo[4].write(156); // Pinky

  // Step 460: Fingers [156, 165, 156, 147, 156] Arm [-, -, -]
  servo[0].write(156); // Thumb
  servo[1].write(165); // Index
  servo[2].write(156); // Middle
  servo[3].write(147); // Ring
  servo[4].write(156); // Pinky

  delay(11);
  // Step 461: Fingers [157, 166, 157, 148, 157] Arm [-, -, -]
  servo[0].write(157); // Thumb
  servo[1].write(166); // Index
  servo[2].write(157); // Middle
  servo[3].write(148); // Ring
  servo[4].write(157); // Pinky

  delay(20);
  // Step 462: Fingers [157, 166, 157, 148, 157] Arm [-, -, -]
  servo[0].write(157); // Thumb
  servo[1].write(166); // Index
  servo[2].write(157); // Middle
  servo[3].write(148); // Ring
  servo[4].write(157); // Pinky

  delay(11);
  // Step 463: Fingers [158, 167, 158, 149, 158] Arm [-, -, -]
  servo[0].write(158); // Thumb
  servo[1].write(167); // Index
  servo[2].write(158); // Middle
  servo[3].write(149); // Ring
  servo[4].write(158); // Pinky

  // Step 464: Fingers [159, 168, 159, 150, 159] Arm [-, -, -]
  servo[0].write(159); // Thumb
  servo[1].write(168); // Index
  servo[2].write(159); // Middle
  servo[3].write(150); // Ring
  servo[4].write(159); // Pinky

  delay(13);
  // Step 465: Fingers [159, 168, 159, 150, 159] Arm [-, -, -]
  servo[0].write(159); // Thumb
  servo[1].write(168); // Index
  servo[2].write(159); // Middle
  servo[3].write(150); // Ring
  servo[4].write(159); // Pinky

  // Step 466: Fingers [161, 169, 160, 151, 161] Arm [-, -, -]
  servo[0].write(161); // Thumb
  servo[1].write(169); // Index
  servo[2].write(160); // Middle
  servo[3].write(151); // Ring
  servo[4].write(161); // Pinky

  // Step 467: Fingers [161, 170, 161, 152, 161] Arm [-, -, -]
  servo[0].write(161); // Thumb
  servo[1].write(170); // Index
  servo[2].write(161); // Middle
  servo[3].write(152); // Ring
  servo[4].write(161); // Pinky

  // Step 468: Fingers [162, 171, 161, 153, 162] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(171); // Index
  servo[2].write(161); // Middle
  servo[3].write(153); // Ring
  servo[4].write(162); // Pinky

  // Step 469: Fingers [163, 171, 162, 153, 163] Arm [-, -, -]
  servo[0].write(163); // Thumb
  servo[1].write(171); // Index
  servo[2].write(162); // Middle
  servo[3].write(153); // Ring
  servo[4].write(163); // Pinky

  // Step 470: Fingers [163, 171, 162, 153, 163] Arm [-, -, -]
  servo[0].write(163); // Thumb
  servo[1].write(171); // Index
  servo[2].write(162); // Middle
  servo[3].write(153); // Ring
  servo[4].write(163); // Pinky

  // Step 471: Fingers [164, 172, 163, 155, 164] Arm [-, -, -]
  servo[0].write(164); // Thumb
  servo[1].write(172); // Index
  servo[2].write(163); // Middle
  servo[3].write(155); // Ring
  servo[4].write(164); // Pinky

  // Step 472: Fingers [166, 174, 164, 156, 166] Arm [-, -, -]
  servo[0].write(166); // Thumb
  servo[1].write(174); // Index
  servo[2].write(164); // Middle
  servo[3].write(156); // Ring
  servo[4].write(166); // Pinky

  // Step 473: Fingers [166, 174, 164, 156, 166] Arm [-, -, -]
  servo[0].write(166); // Thumb
  servo[1].write(174); // Index
  servo[2].write(164); // Middle
  servo[3].write(156); // Ring
  servo[4].write(166); // Pinky

  // Step 474: Fingers [166, 174, 164, 156, 166] Arm [-, -, -]
  servo[0].write(166); // Thumb
  servo[1].write(174); // Index
  servo[2].write(164); // Middle
  servo[3].write(156); // Ring
  servo[4].write(166); // Pinky

  // Step 475: Fingers [168, 176, 166, 158, 168] Arm [-, -, -]
  servo[0].write(168); // Thumb
  servo[1].write(176); // Index
  servo[2].write(166); // Middle
  servo[3].write(158); // Ring
  servo[4].write(168); // Pinky

  // Step 476: Fingers [169, 176, 166, 158, 169] Arm [-, -, -]
  servo[0].write(169); // Thumb
  servo[1].write(176); // Index
  servo[2].write(166); // Middle
  servo[3].write(158); // Ring
  servo[4].write(169); // Pinky

  // Step 477: Fingers [169, 177, 167, 159, 169] Arm [-, -, -]
  servo[0].write(169); // Thumb
  servo[1].write(177); // Index
  servo[2].write(167); // Middle
  servo[3].write(159); // Ring
  servo[4].write(169); // Pinky

  // Step 478: Fingers [170, 177, 167, 160, 170] Arm [-, -, -]
  servo[0].write(170); // Thumb
  servo[1].write(177); // Index
  servo[2].write(167); // Middle
  servo[3].write(160); // Ring
  servo[4].write(170); // Pinky

  // Step 479: Fingers [170, 177, 167, 160, 170] Arm [-, -, -]
  servo[0].write(170); // Thumb
  servo[1].write(177); // Index
  servo[2].write(167); // Middle
  servo[3].write(160); // Ring
  servo[4].write(170); // Pinky

  // Step 480: Fingers [171, 178, 167, 160, 171] Arm [-, -, -]
  servo[0].write(171); // Thumb
  servo[1].write(178); // Index
  servo[2].write(167); // Middle
  servo[3].write(160); // Ring
  servo[4].write(171); // Pinky

  // Step 481: Fingers [172, 179, 168, 161, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(168); // Middle
  servo[3].write(161); // Ring
  servo[4].write(172); // Pinky

  // Step 482: Fingers [172, 179, 169, 162, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(162); // Ring
  servo[4].write(172); // Pinky

  // Step 483: Fingers [172, 179, 169, 162, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(162); // Ring
  servo[4].write(172); // Pinky

  // Step 484: Fingers [172, 179, 169, 162, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(162); // Ring
  servo[4].write(172); // Pinky

  delay(22);
  // Step 485: Fingers [172, 179, 169, 162, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(162); // Ring
  servo[4].write(172); // Pinky

  delay(29);
  // Step 486: Fingers [172, 179, 169, 162, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(162); // Ring
  servo[4].write(172); // Pinky

  delay(29);
  // Step 487: Fingers [172, 179, 169, 162, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(162); // Ring
  servo[4].write(172); // Pinky

  delay(19);
  // Step 488: Fingers [173, 180, 169, 162, 173] Arm [-, -, -]
  servo[0].write(173); // Thumb
  servo[1].write(180); // Index
  servo[2].write(169); // Middle
  servo[3].write(162); // Ring
  servo[4].write(173); // Pinky

  // Step 489: Fingers [174, 180, 170, 163, 174] Arm [-, -, -]
  servo[0].write(174); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(163); // Ring
  servo[4].write(174); // Pinky

  // Step 490: Fingers [174, 180, 170, 163, 174] Arm [-, -, -]
  servo[0].write(174); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(163); // Ring
  servo[4].write(174); // Pinky

  // Step 491: Fingers [174, 180, 169, 163, 174] Arm [-, -, -]
  servo[0].write(174); // Thumb
  servo[1].write(180); // Index
  servo[2].write(169); // Middle
  servo[3].write(163); // Ring
  servo[4].write(174); // Pinky

  // Step 492: Fingers [175, 180, 170, 164, 175] Arm [-, -, -]
  servo[0].write(175); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(164); // Ring
  servo[4].write(175); // Pinky

  delay(17);
  // Step 493: Fingers [175, 180, 170, 164, 175] Arm [-, -, -]
  servo[0].write(175); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(164); // Ring
  servo[4].write(175); // Pinky

  // Step 494: Fingers [175, 180, 170, 164, 175] Arm [-, -, -]
  servo[0].write(175); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(164); // Ring
  servo[4].write(175); // Pinky

  delay(23);
  // Step 495: Fingers [175, 180, 170, 164, 175] Arm [-, -, -]
  servo[0].write(175); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(164); // Ring
  servo[4].write(175); // Pinky

  // Step 496: Fingers [176, 180, 171, 164, 176] Arm [-, -, -]
  servo[0].write(176); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(164); // Ring
  servo[4].write(176); // Pinky

  delay(26);
  // Step 497: Fingers [176, 180, 171, 164, 176] Arm [-, -, -]
  servo[0].write(176); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(164); // Ring
  servo[4].write(176); // Pinky

  delay(14);
  // Step 498: Fingers [176, 180, 171, 165, 176] Arm [-, -, -]
  servo[0].write(176); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(165); // Ring
  servo[4].write(176); // Pinky

  delay(14);
  // Step 499: Fingers [176, 180, 171, 165, 176] Arm [-, -, -]
  servo[0].write(176); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(165); // Ring
  servo[4].write(176); // Pinky

  // Step 500: Fingers [177, 180, 172, 166, 177] Arm [-, -, -]
  servo[0].write(177); // Thumb
  servo[1].write(180); // Index
  servo[2].write(172); // Middle
  servo[3].write(166); // Ring
  servo[4].write(177); // Pinky

  delay(19);
  // Step 501: Fingers [177, 180, 171, 166, 177] Arm [-, -, -]
  servo[0].write(177); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(166); // Ring
  servo[4].write(177); // Pinky

  // Step 502: Fingers [177, 180, 171, 166, 177] Arm [-, -, -]
  servo[0].write(177); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(166); // Ring
  servo[4].write(177); // Pinky

  delay(30);
  // Step 503: Fingers [177, 180, 171, 166, 177] Arm [-, -, -]
  servo[0].write(177); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(166); // Ring
  servo[4].write(177); // Pinky

  delay(26);
  // Step 504: Fingers [177, 180, 171, 166, 177] Arm [-, -, -]
  servo[0].write(177); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(166); // Ring
  servo[4].write(177); // Pinky

  // Step 505: Fingers [177, 180, 171, 166, 177] Arm [-, -, -]
  servo[0].write(177); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(166); // Ring
  servo[4].write(177); // Pinky

  delay(16);
  // Step 506: Fingers [178, 180, 171, 166, 178] Arm [-, -, -]
  servo[0].write(178); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(166); // Ring
  servo[4].write(178); // Pinky

  delay(16);
  // Step 507: Fingers [178, 180, 171, 166, 178] Arm [-, -, -]
  servo[0].write(178); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(166); // Ring
  servo[4].write(178); // Pinky

  // Step 508: Fingers [178, 180, 171, 166, 178] Arm [-, -, -]
  servo[0].write(178); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(166); // Ring
  servo[4].write(178); // Pinky

  delay(25);
  // Step 509: Fingers [178, 180, 171, 166, 178] Arm [-, -, -]
  servo[0].write(178); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(166); // Ring
  servo[4].write(178); // Pinky

  // Step 510: Fingers [178, 180, 171, 166, 178] Arm [-, -, -]
  servo[0].write(178); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(166); // Ring
  servo[4].write(178); // Pinky

  // Step 511: Fingers [178, 180, 170, 166, 178] Arm [-, -, -]
  servo[0].write(178); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(166); // Ring
  servo[4].write(178); // Pinky

  delay(24);
  // Step 512: Fingers [178, 180, 170, 166, 178] Arm [-, -, -]
  servo[0].write(178); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(166); // Ring
  servo[4].write(178); // Pinky

  // Step 513: Fingers [178, 180, 170, 166, 178] Arm [-, -, -]
  servo[0].write(178); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(166); // Ring
  servo[4].write(178); // Pinky

  delay(15);
  // Step 514: Fingers [179, 180, 170, 166, 179] Arm [-, -, -]
  servo[0].write(179); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(166); // Ring
  servo[4].write(179); // Pinky

  // Step 515: Fingers [179, 180, 170, 166, 179] Arm [-, -, -]
  servo[0].write(179); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(166); // Ring
  servo[4].write(179); // Pinky

  // Step 516: Fingers [179, 180, 171, 167, 179] Arm [-, -, -]
  servo[0].write(179); // Thumb
  servo[1].write(180); // Index
  servo[2].write(171); // Middle
  servo[3].write(167); // Ring
  servo[4].write(179); // Pinky

  // Step 517: Fingers [180, 180, 170, 167, 180] Arm [-, -, -]
  servo[0].write(180); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(167); // Ring
  servo[4].write(180); // Pinky

  // Step 518: Fingers [180, 180, 170, 167, 180] Arm [-, -, -]
  servo[0].write(180); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(167); // Ring
  servo[4].write(180); // Pinky

  delay(13);
  // Step 519: Fingers [180, 180, 170, 167, 180] Arm [-, -, -]
  servo[0].write(180); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(167); // Ring
  servo[4].write(180); // Pinky

  delay(11);
  // Step 520: Fingers [180, 180, 170, 167, 180] Arm [-, -, -]
  servo[0].write(180); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(167); // Ring
  servo[4].write(180); // Pinky

  // Step 521: Fingers [180, 180, 170, 168, 180] Arm [-, -, -]
  servo[0].write(180); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(168); // Ring
  servo[4].write(180); // Pinky

  // Step 522: Fingers [180, 180, 170, 168, 180] Arm [-, -, -]
  servo[0].write(180); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(168); // Ring
  servo[4].write(180); // Pinky

  delay(11);
  // Step 523: Fingers [180, 180, 170, 168, 180] Arm [-, -, -]
  servo[0].write(180); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(168); // Ring
  servo[4].write(180); // Pinky

  delay(33);
  // Step 524: Fingers [180, 180, 170, 168, 180] Arm [-, -, -]
  servo[0].write(180); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(168); // Ring
  servo[4].write(180); // Pinky

  delay(31);
  // Step 525: Fingers [180, 180, 170, 168, 180] Arm [-, -, -]
  servo[0].write(180); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(168); // Ring
  servo[4].write(180); // Pinky

  delay(20);
  // Step 526: Fingers [180, 180, 170, 168, 180] Arm [-, -, -]
  servo[0].write(180); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(168); // Ring
  servo[4].write(180); // Pinky

  // Step 527: Fingers [180, 180, 170, 168, 180] Arm [-, -, -]
  servo[0].write(180); // Thumb
  servo[1].write(180); // Index
  servo[2].write(170); // Middle
  servo[3].write(168); // Ring
  servo[4].write(180); // Pinky

  // Step 528: Fingers [180, 180, 169, 167, 180] Arm [-, -, -]
  servo[0].write(180); // Thumb
  servo[1].write(180); // Index
  servo[2].write(169); // Middle
  servo[3].write(167); // Ring
  servo[4].write(180); // Pinky

  // Step 529: Fingers [179, 180, 168, 167, 179] Arm [-, -, -]
  servo[0].write(179); // Thumb
  servo[1].write(180); // Index
  servo[2].write(168); // Middle
  servo[3].write(167); // Ring
  servo[4].write(179); // Pinky

  delay(13);
  // Step 530: Fingers [179, 180, 168, 167, 179] Arm [-, -, -]
  servo[0].write(179); // Thumb
  servo[1].write(180); // Index
  servo[2].write(168); // Middle
  servo[3].write(167); // Ring
  servo[4].write(179); // Pinky

  // Step 531: Fingers [179, 180, 167, 166, 179] Arm [-, -, -]
  servo[0].write(179); // Thumb
  servo[1].write(180); // Index
  servo[2].write(167); // Middle
  servo[3].write(166); // Ring
  servo[4].write(179); // Pinky

  // Step 532: Fingers [179, 180, 167, 166, 179] Arm [-, -, -]
  servo[0].write(179); // Thumb
  servo[1].write(180); // Index
  servo[2].write(167); // Middle
  servo[3].write(166); // Ring
  servo[4].write(179); // Pinky

  delay(11);
  // Step 533: Fingers [178, 179, 166, 166, 178] Arm [-, -, -]
  servo[0].write(178); // Thumb
  servo[1].write(179); // Index
  servo[2].write(166); // Middle
  servo[3].write(166); // Ring
  servo[4].write(178); // Pinky

  // Step 534: Fingers [178, 179, 166, 166, 178] Arm [-, -, -]
  servo[0].write(178); // Thumb
  servo[1].write(179); // Index
  servo[2].write(166); // Middle
  servo[3].write(166); // Ring
  servo[4].write(178); // Pinky

  // Step 535: Fingers [179, 179, 166, 166, 179] Arm [-, -, -]
  servo[0].write(179); // Thumb
  servo[1].write(179); // Index
  servo[2].write(166); // Middle
  servo[3].write(166); // Ring
  servo[4].write(179); // Pinky

  delay(18);
  // Step 536: Fingers [178, 178, 166, 165, 178] Arm [-, -, -]
  servo[0].write(178); // Thumb
  servo[1].write(178); // Index
  servo[2].write(166); // Middle
  servo[3].write(165); // Ring
  servo[4].write(178); // Pinky

  // Step 537: Fingers [178, 178, 166, 165, 178] Arm [-, -, -]
  servo[0].write(178); // Thumb
  servo[1].write(178); // Index
  servo[2].write(166); // Middle
  servo[3].write(165); // Ring
  servo[4].write(178); // Pinky

  // Step 538: Fingers [177, 178, 165, 165, 177] Arm [-, -, -]
  servo[0].write(177); // Thumb
  servo[1].write(178); // Index
  servo[2].write(165); // Middle
  servo[3].write(165); // Ring
  servo[4].write(177); // Pinky

  delay(18);
  // Step 539: Fingers [177, 177, 164, 164, 177] Arm [-, -, -]
  servo[0].write(177); // Thumb
  servo[1].write(177); // Index
  servo[2].write(164); // Middle
  servo[3].write(164); // Ring
  servo[4].write(177); // Pinky

  // Step 540: Fingers [177, 177, 164, 164, 177] Arm [-, -, -]
  servo[0].write(177); // Thumb
  servo[1].write(177); // Index
  servo[2].write(164); // Middle
  servo[3].write(164); // Ring
  servo[4].write(177); // Pinky

  delay(34);
  // Step 541: Fingers [177, 177, 164, 164, 177] Arm [-, -, -]
  servo[0].write(177); // Thumb
  servo[1].write(177); // Index
  servo[2].write(164); // Middle
  servo[3].write(164); // Ring
  servo[4].write(177); // Pinky

  // Step 542: Fingers [176, 176, 164, 163, 176] Arm [-, -, -]
  servo[0].write(176); // Thumb
  servo[1].write(176); // Index
  servo[2].write(164); // Middle
  servo[3].write(163); // Ring
  servo[4].write(176); // Pinky

  delay(19);
  // Step 543: Fingers [176, 176, 164, 163, 176] Arm [-, -, -]
  servo[0].write(176); // Thumb
  servo[1].write(176); // Index
  servo[2].write(164); // Middle
  servo[3].write(163); // Ring
  servo[4].write(176); // Pinky

  // Step 544: Fingers [176, 176, 163, 164, 176] Arm [-, -, -]
  servo[0].write(176); // Thumb
  servo[1].write(176); // Index
  servo[2].write(163); // Middle
  servo[3].write(164); // Ring
  servo[4].write(176); // Pinky

  delay(15);
  // Step 545: Fingers [176, 176, 163, 163, 176] Arm [-, -, -]
  servo[0].write(176); // Thumb
  servo[1].write(176); // Index
  servo[2].write(163); // Middle
  servo[3].write(163); // Ring
  servo[4].write(176); // Pinky

  // Step 546: Fingers [176, 176, 163, 163, 176] Arm [-, -, -]
  servo[0].write(176); // Thumb
  servo[1].write(176); // Index
  servo[2].write(163); // Middle
  servo[3].write(163); // Ring
  servo[4].write(176); // Pinky

  // Step 547: Fingers [175, 175, 162, 162, 175] Arm [-, -, -]
  servo[0].write(175); // Thumb
  servo[1].write(175); // Index
  servo[2].write(162); // Middle
  servo[3].write(162); // Ring
  servo[4].write(175); // Pinky

  // Step 548: Fingers [174, 174, 162, 162, 174] Arm [-, -, -]
  servo[0].write(174); // Thumb
  servo[1].write(174); // Index
  servo[2].write(162); // Middle
  servo[3].write(162); // Ring
  servo[4].write(174); // Pinky

  // Step 549: Fingers [173, 173, 160, 161, 173] Arm [-, -, -]
  servo[0].write(173); // Thumb
  servo[1].write(173); // Index
  servo[2].write(160); // Middle
  servo[3].write(161); // Ring
  servo[4].write(173); // Pinky

  // Step 550: Fingers [173, 173, 160, 161, 173] Arm [-, -, -]
  servo[0].write(173); // Thumb
  servo[1].write(173); // Index
  servo[2].write(160); // Middle
  servo[3].write(161); // Ring
  servo[4].write(173); // Pinky

  // Step 551: Fingers [173, 172, 159, 160, 173] Arm [-, -, -]
  servo[0].write(173); // Thumb
  servo[1].write(172); // Index
  servo[2].write(159); // Middle
  servo[3].write(160); // Ring
  servo[4].write(173); // Pinky

  delay(16);
  // Step 552: Fingers [172, 171, 159, 159, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(171); // Index
  servo[2].write(159); // Middle
  servo[3].write(159); // Ring
  servo[4].write(172); // Pinky

  // Step 553: Fingers [172, 171, 159, 159, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(171); // Index
  servo[2].write(159); // Middle
  servo[3].write(159); // Ring
  servo[4].write(172); // Pinky

  delay(12);
  // Step 554: Fingers [172, 171, 159, 160, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(171); // Index
  servo[2].write(159); // Middle
  servo[3].write(160); // Ring
  servo[4].write(172); // Pinky

  // Step 555: Fingers [172, 171, 158, 159, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(171); // Index
  servo[2].write(158); // Middle
  servo[3].write(159); // Ring
  servo[4].write(172); // Pinky

  delay(13);
  // Step 556: Fingers [172, 171, 158, 159, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(171); // Index
  servo[2].write(158); // Middle
  servo[3].write(159); // Ring
  servo[4].write(172); // Pinky

  // Step 557: Fingers [171, 170, 157, 158, 171] Arm [-, -, -]
  servo[0].write(171); // Thumb
  servo[1].write(170); // Index
  servo[2].write(157); // Middle
  servo[3].write(158); // Ring
  servo[4].write(171); // Pinky

  delay(19);
  // Step 558: Fingers [171, 170, 157, 158, 171] Arm [-, -, -]
  servo[0].write(171); // Thumb
  servo[1].write(170); // Index
  servo[2].write(157); // Middle
  servo[3].write(158); // Ring
  servo[4].write(171); // Pinky

  // Step 559: Fingers [170, 169, 157, 158, 170] Arm [-, -, -]
  servo[0].write(170); // Thumb
  servo[1].write(169); // Index
  servo[2].write(157); // Middle
  servo[3].write(158); // Ring
  servo[4].write(170); // Pinky

  // Step 560: Fingers [170, 169, 156, 157, 170] Arm [-, -, -]
  servo[0].write(170); // Thumb
  servo[1].write(169); // Index
  servo[2].write(156); // Middle
  servo[3].write(157); // Ring
  servo[4].write(170); // Pinky

  delay(15);
  // Step 561: Fingers [170, 169, 156, 157, 170] Arm [-, -, -]
  servo[0].write(170); // Thumb
  servo[1].write(169); // Index
  servo[2].write(156); // Middle
  servo[3].write(157); // Ring
  servo[4].write(170); // Pinky

  // Step 562: Fingers [169, 168, 155, 157, 169] Arm [-, -, -]
  servo[0].write(169); // Thumb
  servo[1].write(168); // Index
  servo[2].write(155); // Middle
  servo[3].write(157); // Ring
  servo[4].write(169); // Pinky

  // Step 563: Fingers [169, 167, 155, 156, 169] Arm [-, -, -]
  servo[0].write(169); // Thumb
  servo[1].write(167); // Index
  servo[2].write(155); // Middle
  servo[3].write(156); // Ring
  servo[4].write(169); // Pinky

  // Step 564: Fingers [168, 167, 154, 155, 168] Arm [-, -, -]
  servo[0].write(168); // Thumb
  servo[1].write(167); // Index
  servo[2].write(154); // Middle
  servo[3].write(155); // Ring
  servo[4].write(168); // Pinky

  delay(13);
  // Step 565: Fingers [168, 167, 154, 155, 168] Arm [-, -, -]
  servo[0].write(168); // Thumb
  servo[1].write(167); // Index
  servo[2].write(154); // Middle
  servo[3].write(155); // Ring
  servo[4].write(168); // Pinky

  // Step 566: Fingers [167, 166, 153, 155, 167] Arm [-, -, -]
  servo[0].write(167); // Thumb
  servo[1].write(166); // Index
  servo[2].write(153); // Middle
  servo[3].write(155); // Ring
  servo[4].write(167); // Pinky

  // Step 567: Fingers [167, 165, 153, 154, 167] Arm [-, -, -]
  servo[0].write(167); // Thumb
  servo[1].write(165); // Index
  servo[2].write(153); // Middle
  servo[3].write(154); // Ring
  servo[4].write(167); // Pinky

  // Step 568: Fingers [166, 165, 152, 153, 166] Arm [-, -, -]
  servo[0].write(166); // Thumb
  servo[1].write(165); // Index
  servo[2].write(152); // Middle
  servo[3].write(153); // Ring
  servo[4].write(166); // Pinky

  delay(17);
  // Step 569: Fingers [166, 165, 152, 153, 166] Arm [-, -, -]
  servo[0].write(166); // Thumb
  servo[1].write(165); // Index
  servo[2].write(152); // Middle
  servo[3].write(153); // Ring
  servo[4].write(166); // Pinky

  // Step 570: Fingers [165, 163, 151, 152, 165] Arm [-, -, -]
  servo[0].write(165); // Thumb
  servo[1].write(163); // Index
  servo[2].write(151); // Middle
  servo[3].write(152); // Ring
  servo[4].write(165); // Pinky

  delay(21);
  // Step 571: Fingers [165, 163, 151, 152, 165] Arm [-, -, -]
  servo[0].write(165); // Thumb
  servo[1].write(163); // Index
  servo[2].write(151); // Middle
  servo[3].write(152); // Ring
  servo[4].write(165); // Pinky

  delay(15);
  // Step 572: Fingers [164, 163, 150, 152, 164] Arm [-, -, -]
  servo[0].write(164); // Thumb
  servo[1].write(163); // Index
  servo[2].write(150); // Middle
  servo[3].write(152); // Ring
  servo[4].write(164); // Pinky

  delay(16);
  // Step 573: Fingers [164, 163, 150, 152, 164] Arm [-, -, -]
  servo[0].write(164); // Thumb
  servo[1].write(163); // Index
  servo[2].write(150); // Middle
  servo[3].write(152); // Ring
  servo[4].write(164); // Pinky

  // Step 574: Fingers [164, 162, 149, 151, 164] Arm [-, -, -]
  servo[0].write(164); // Thumb
  servo[1].write(162); // Index
  servo[2].write(149); // Middle
  servo[3].write(151); // Ring
  servo[4].write(164); // Pinky

  delay(14);
  // Step 575: Fingers [162, 161, 148, 150, 162] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(161); // Index
  servo[2].write(148); // Middle
  servo[3].write(150); // Ring
  servo[4].write(162); // Pinky

  // Step 576: Fingers [162, 161, 148, 150, 162] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(161); // Index
  servo[2].write(148); // Middle
  servo[3].write(150); // Ring
  servo[4].write(162); // Pinky

  // Step 577: Fingers [162, 160, 147, 149, 162] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(160); // Index
  servo[2].write(147); // Middle
  servo[3].write(149); // Ring
  servo[4].write(162); // Pinky

  delay(13);
  // Step 578: Fingers [161, 159, 147, 148, 161] Arm [-, -, -]
  servo[0].write(161); // Thumb
  servo[1].write(159); // Index
  servo[2].write(147); // Middle
  servo[3].write(148); // Ring
  servo[4].write(161); // Pinky

  // Step 579: Fingers [161, 159, 147, 148, 161] Arm [-, -, -]
  servo[0].write(161); // Thumb
  servo[1].write(159); // Index
  servo[2].write(147); // Middle
  servo[3].write(148); // Ring
  servo[4].write(161); // Pinky

  // Step 580: Fingers [160, 159, 146, 148, 160] Arm [-, -, -]
  servo[0].write(160); // Thumb
  servo[1].write(159); // Index
  servo[2].write(146); // Middle
  servo[3].write(148); // Ring
  servo[4].write(160); // Pinky

  // Step 581: Fingers [159, 158, 145, 146, 159] Arm [-, -, -]
  servo[0].write(159); // Thumb
  servo[1].write(158); // Index
  servo[2].write(145); // Middle
  servo[3].write(146); // Ring
  servo[4].write(159); // Pinky

  // Step 582: Fingers [158, 157, 144, 146, 158] Arm [-, -, -]
  servo[0].write(158); // Thumb
  servo[1].write(157); // Index
  servo[2].write(144); // Middle
  servo[3].write(146); // Ring
  servo[4].write(158); // Pinky

  // Step 583: Fingers [157, 156, 143, 145, 157] Arm [-, -, -]
  servo[0].write(157); // Thumb
  servo[1].write(156); // Index
  servo[2].write(143); // Middle
  servo[3].write(145); // Ring
  servo[4].write(157); // Pinky

  // Step 584: Fingers [157, 156, 143, 145, 157] Arm [-, -, -]
  servo[0].write(157); // Thumb
  servo[1].write(156); // Index
  servo[2].write(143); // Middle
  servo[3].write(145); // Ring
  servo[4].write(157); // Pinky

  // Step 585: Fingers [156, 154, 142, 143, 156] Arm [-, -, -]
  servo[0].write(156); // Thumb
  servo[1].write(154); // Index
  servo[2].write(142); // Middle
  servo[3].write(143); // Ring
  servo[4].write(156); // Pinky

  // Step 586: Fingers [155, 154, 141, 143, 155] Arm [-, -, -]
  servo[0].write(155); // Thumb
  servo[1].write(154); // Index
  servo[2].write(141); // Middle
  servo[3].write(143); // Ring
  servo[4].write(155); // Pinky

  // Step 587: Fingers [154, 152, 140, 142, 154] Arm [-, -, -]
  servo[0].write(154); // Thumb
  servo[1].write(152); // Index
  servo[2].write(140); // Middle
  servo[3].write(142); // Ring
  servo[4].write(154); // Pinky

  // Step 588: Fingers [153, 151, 138, 140, 153] Arm [-, -, -]
  servo[0].write(153); // Thumb
  servo[1].write(151); // Index
  servo[2].write(138); // Middle
  servo[3].write(140); // Ring
  servo[4].write(153); // Pinky

  // Step 589: Fingers [153, 151, 138, 140, 153] Arm [-, -, -]
  servo[0].write(153); // Thumb
  servo[1].write(151); // Index
  servo[2].write(138); // Middle
  servo[3].write(140); // Ring
  servo[4].write(153); // Pinky

  // Step 590: Fingers [152, 150, 138, 140, 152] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(150); // Index
  servo[2].write(138); // Middle
  servo[3].write(140); // Ring
  servo[4].write(152); // Pinky

  // Step 591: Fingers [152, 150, 137, 139, 152] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(150); // Index
  servo[2].write(137); // Middle
  servo[3].write(139); // Ring
  servo[4].write(152); // Pinky

  // Step 592: Fingers [150, 148, 136, 138, 150] Arm [-, -, -]
  servo[0].write(150); // Thumb
  servo[1].write(148); // Index
  servo[2].write(136); // Middle
  servo[3].write(138); // Ring
  servo[4].write(150); // Pinky

  // Step 593: Fingers [150, 148, 135, 137, 150] Arm [-, -, -]
  servo[0].write(150); // Thumb
  servo[1].write(148); // Index
  servo[2].write(135); // Middle
  servo[3].write(137); // Ring
  servo[4].write(150); // Pinky

  // Step 594: Fingers [150, 148, 135, 137, 150] Arm [-, -, -]
  servo[0].write(150); // Thumb
  servo[1].write(148); // Index
  servo[2].write(135); // Middle
  servo[3].write(137); // Ring
  servo[4].write(150); // Pinky

  // Step 595: Fingers [149, 147, 135, 136, 149] Arm [-, -, -]
  servo[0].write(149); // Thumb
  servo[1].write(147); // Index
  servo[2].write(135); // Middle
  servo[3].write(136); // Ring
  servo[4].write(149); // Pinky

  // Step 596: Fingers [148, 146, 133, 135, 148] Arm [-, -, -]
  servo[0].write(148); // Thumb
  servo[1].write(146); // Index
  servo[2].write(133); // Middle
  servo[3].write(135); // Ring
  servo[4].write(148); // Pinky

  delay(16);
  // Step 597: Fingers [147, 145, 133, 135, 147] Arm [-, -, -]
  servo[0].write(147); // Thumb
  servo[1].write(145); // Index
  servo[2].write(133); // Middle
  servo[3].write(135); // Ring
  servo[4].write(147); // Pinky

  // Step 598: Fingers [147, 145, 133, 135, 147] Arm [-, -, -]
  servo[0].write(147); // Thumb
  servo[1].write(145); // Index
  servo[2].write(133); // Middle
  servo[3].write(135); // Ring
  servo[4].write(147); // Pinky

  // Step 599: Fingers [146, 145, 132, 134, 146] Arm [-, -, -]
  servo[0].write(146); // Thumb
  servo[1].write(145); // Index
  servo[2].write(132); // Middle
  servo[3].write(134); // Ring
  servo[4].write(146); // Pinky

  delay(11);
  // Step 600: Fingers [145, 143, 131, 133, 145] Arm [-, -, -]
  servo[0].write(145); // Thumb
  servo[1].write(143); // Index
  servo[2].write(131); // Middle
  servo[3].write(133); // Ring
  servo[4].write(145); // Pinky

  // Step 601: Fingers [145, 143, 131, 133, 145] Arm [-, -, -]
  servo[0].write(145); // Thumb
  servo[1].write(143); // Index
  servo[2].write(131); // Middle
  servo[3].write(133); // Ring
  servo[4].write(145); // Pinky

  // Step 602: Fingers [145, 143, 130, 132, 145] Arm [-, -, -]
  servo[0].write(145); // Thumb
  servo[1].write(143); // Index
  servo[2].write(130); // Middle
  servo[3].write(132); // Ring
  servo[4].write(145); // Pinky

  // Step 603: Fingers [144, 142, 130, 131, 144] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(142); // Index
  servo[2].write(130); // Middle
  servo[3].write(131); // Ring
  servo[4].write(144); // Pinky

  // Step 604: Fingers [143, 141, 129, 131, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(141); // Index
  servo[2].write(129); // Middle
  servo[3].write(131); // Ring
  servo[4].write(143); // Pinky

  // Step 605: Fingers [143, 141, 129, 131, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(141); // Index
  servo[2].write(129); // Middle
  servo[3].write(131); // Ring
  servo[4].write(143); // Pinky

  // Step 606: Fingers [143, 141, 128, 130, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(141); // Index
  servo[2].write(128); // Middle
  servo[3].write(130); // Ring
  servo[4].write(143); // Pinky

  // Step 607: Fingers [141, 140, 127, 129, 141] Arm [-, -, -]
  servo[0].write(141); // Thumb
  servo[1].write(140); // Index
  servo[2].write(127); // Middle
  servo[3].write(129); // Ring
  servo[4].write(141); // Pinky

  // Step 608: Fingers [141, 139, 126, 128, 141] Arm [-, -, -]
  servo[0].write(141); // Thumb
  servo[1].write(139); // Index
  servo[2].write(126); // Middle
  servo[3].write(128); // Ring
  servo[4].write(141); // Pinky

  // Step 609: Fingers [140, 138, 126, 127, 140] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(138); // Index
  servo[2].write(126); // Middle
  servo[3].write(127); // Ring
  servo[4].write(140); // Pinky

  // Step 610: Fingers [140, 138, 126, 127, 140] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(138); // Index
  servo[2].write(126); // Middle
  servo[3].write(127); // Ring
  servo[4].write(140); // Pinky

  // Step 611: Fingers [139, 137, 125, 126, 139] Arm [-, -, -]
  servo[0].write(139); // Thumb
  servo[1].write(137); // Index
  servo[2].write(125); // Middle
  servo[3].write(126); // Ring
  servo[4].write(139); // Pinky

  // Step 612: Fingers [138, 137, 124, 125, 138] Arm [-, -, -]
  servo[0].write(138); // Thumb
  servo[1].write(137); // Index
  servo[2].write(124); // Middle
  servo[3].write(125); // Ring
  servo[4].write(138); // Pinky

  // Step 613: Fingers [137, 136, 123, 125, 137] Arm [-, -, -]
  servo[0].write(137); // Thumb
  servo[1].write(136); // Index
  servo[2].write(123); // Middle
  servo[3].write(125); // Ring
  servo[4].write(137); // Pinky

  // Step 614: Fingers [136, 135, 122, 123, 136] Arm [-, -, -]
  servo[0].write(136); // Thumb
  servo[1].write(135); // Index
  servo[2].write(122); // Middle
  servo[3].write(123); // Ring
  servo[4].write(136); // Pinky

  // Step 615: Fingers [136, 135, 122, 123, 136] Arm [-, -, -]
  servo[0].write(136); // Thumb
  servo[1].write(135); // Index
  servo[2].write(122); // Middle
  servo[3].write(123); // Ring
  servo[4].write(136); // Pinky

  // Step 616: Fingers [135, 134, 121, 122, 135] Arm [-, -, -]
  servo[0].write(135); // Thumb
  servo[1].write(134); // Index
  servo[2].write(121); // Middle
  servo[3].write(122); // Ring
  servo[4].write(135); // Pinky

  // Step 617: Fingers [133, 132, 120, 121, 133] Arm [-, -, -]
  servo[0].write(133); // Thumb
  servo[1].write(132); // Index
  servo[2].write(120); // Middle
  servo[3].write(121); // Ring
  servo[4].write(133); // Pinky

  // Step 618: Fingers [133, 132, 119, 120, 133] Arm [-, -, -]
  servo[0].write(133); // Thumb
  servo[1].write(132); // Index
  servo[2].write(119); // Middle
  servo[3].write(120); // Ring
  servo[4].write(133); // Pinky

  // Step 619: Fingers [131, 130, 117, 118, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(130); // Index
  servo[2].write(117); // Middle
  servo[3].write(118); // Ring
  servo[4].write(131); // Pinky

  // Step 620: Fingers [131, 130, 117, 118, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(130); // Index
  servo[2].write(117); // Middle
  servo[3].write(118); // Ring
  servo[4].write(131); // Pinky

  // Step 621: Fingers [129, 129, 116, 117, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(129); // Index
  servo[2].write(116); // Middle
  servo[3].write(117); // Ring
  servo[4].write(129); // Pinky

  // Step 622: Fingers [128, 128, 115, 115, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(128); // Index
  servo[2].write(115); // Middle
  servo[3].write(115); // Ring
  servo[4].write(128); // Pinky

  // Step 623: Fingers [127, 127, 114, 114, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(127); // Index
  servo[2].write(114); // Middle
  servo[3].write(114); // Ring
  servo[4].write(127); // Pinky

  // Step 624: Fingers [126, 126, 113, 113, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(126); // Index
  servo[2].write(113); // Middle
  servo[3].write(113); // Ring
  servo[4].write(126); // Pinky

  // Step 625: Fingers [126, 126, 113, 113, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(126); // Index
  servo[2].write(113); // Middle
  servo[3].write(113); // Ring
  servo[4].write(126); // Pinky

  // Step 626: Fingers [125, 125, 113, 112, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(125); // Index
  servo[2].write(113); // Middle
  servo[3].write(112); // Ring
  servo[4].write(125); // Pinky

  // Step 627: Fingers [124, 125, 112, 112, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(125); // Index
  servo[2].write(112); // Middle
  servo[3].write(112); // Ring
  servo[4].write(124); // Pinky

  // Step 628: Fingers [124, 124, 111, 111, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(124); // Index
  servo[2].write(111); // Middle
  servo[3].write(111); // Ring
  servo[4].write(124); // Pinky

  // Step 629: Fingers [124, 124, 111, 111, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(124); // Index
  servo[2].write(111); // Middle
  servo[3].write(111); // Ring
  servo[4].write(124); // Pinky

  // Step 630: Fingers [123, 124, 111, 110, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(124); // Index
  servo[2].write(111); // Middle
  servo[3].write(110); // Ring
  servo[4].write(123); // Pinky

  // Step 631: Fingers [122, 123, 110, 109, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(123); // Index
  servo[2].write(110); // Middle
  servo[3].write(109); // Ring
  servo[4].write(122); // Pinky

  // Step 632: Fingers [121, 122, 109, 108, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(122); // Index
  servo[2].write(109); // Middle
  servo[3].write(108); // Ring
  servo[4].write(121); // Pinky

  // Step 633: Fingers [120, 121, 109, 107, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(121); // Index
  servo[2].write(109); // Middle
  servo[3].write(107); // Ring
  servo[4].write(120); // Pinky

  // Step 634: Fingers [120, 121, 109, 107, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(121); // Index
  servo[2].write(109); // Middle
  servo[3].write(107); // Ring
  servo[4].write(120); // Pinky

  // Step 635: Fingers [119, 120, 108, 106, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(120); // Index
  servo[2].write(108); // Middle
  servo[3].write(106); // Ring
  servo[4].write(119); // Pinky

  // Step 636: Fingers [117, 119, 106, 105, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(119); // Index
  servo[2].write(106); // Middle
  servo[3].write(105); // Ring
  servo[4].write(117); // Pinky

  // Step 637: Fingers [117, 118, 106, 104, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(118); // Index
  servo[2].write(106); // Middle
  servo[3].write(104); // Ring
  servo[4].write(117); // Pinky

  // Step 638: Fingers [117, 118, 106, 104, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(118); // Index
  servo[2].write(106); // Middle
  servo[3].write(104); // Ring
  servo[4].write(117); // Pinky

  // Step 639: Fingers [116, 118, 105, 103, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(118); // Index
  servo[2].write(105); // Middle
  servo[3].write(103); // Ring
  servo[4].write(116); // Pinky

  // Step 640: Fingers [115, 117, 105, 103, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(117); // Index
  servo[2].write(105); // Middle
  servo[3].write(103); // Ring
  servo[4].write(115); // Pinky

  // Step 641: Fingers [114, 117, 104, 102, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(117); // Index
  servo[2].write(104); // Middle
  servo[3].write(102); // Ring
  servo[4].write(114); // Pinky

  // Step 642: Fingers [114, 117, 104, 102, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(117); // Index
  servo[2].write(104); // Middle
  servo[3].write(102); // Ring
  servo[4].write(114); // Pinky

  // Step 643: Fingers [114, 117, 104, 102, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(117); // Index
  servo[2].write(104); // Middle
  servo[3].write(102); // Ring
  servo[4].write(114); // Pinky

  // Step 644: Fingers [113, 116, 103, 100, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(116); // Index
  servo[2].write(103); // Middle
  servo[3].write(100); // Ring
  servo[4].write(113); // Pinky

  // Step 645: Fingers [112, 115, 103, 100, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(115); // Index
  servo[2].write(103); // Middle
  servo[3].write(100); // Ring
  servo[4].write(112); // Pinky

  // Step 646: Fingers [111, 115, 103, 99, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(115); // Index
  servo[2].write(103); // Middle
  servo[3].write(99); // Ring
  servo[4].write(111); // Pinky

  // Step 647: Fingers [111, 115, 103, 99, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(115); // Index
  servo[2].write(103); // Middle
  servo[3].write(99); // Ring
  servo[4].write(111); // Pinky

  // Step 648: Fingers [110, 114, 101, 97, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(114); // Index
  servo[2].write(101); // Middle
  servo[3].write(97); // Ring
  servo[4].write(110); // Pinky

  // Step 649: Fingers [109, 113, 101, 97, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(113); // Index
  servo[2].write(101); // Middle
  servo[3].write(97); // Ring
  servo[4].write(109); // Pinky

  // Step 650: Fingers [108, 112, 101, 96, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(112); // Index
  servo[2].write(101); // Middle
  servo[3].write(96); // Ring
  servo[4].write(108); // Pinky

  // Step 651: Fingers [108, 112, 101, 96, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(112); // Index
  servo[2].write(101); // Middle
  servo[3].write(96); // Ring
  servo[4].write(108); // Pinky

  // Step 652: Fingers [108, 112, 101, 96, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(112); // Index
  servo[2].write(101); // Middle
  servo[3].write(96); // Ring
  servo[4].write(108); // Pinky

  // Step 653: Fingers [106, 111, 100, 95, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(111); // Index
  servo[2].write(100); // Middle
  servo[3].write(95); // Ring
  servo[4].write(106); // Pinky

  // Step 654: Fingers [105, 110, 99, 93, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(110); // Index
  servo[2].write(99); // Middle
  servo[3].write(93); // Ring
  servo[4].write(105); // Pinky

  // Step 655: Fingers [105, 110, 99, 93, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(110); // Index
  servo[2].write(99); // Middle
  servo[3].write(93); // Ring
  servo[4].write(105); // Pinky

  // Step 656: Fingers [105, 110, 99, 93, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(110); // Index
  servo[2].write(99); // Middle
  servo[3].write(93); // Ring
  servo[4].write(105); // Pinky

  // Step 657: Fingers [104, 110, 98, 92, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(110); // Index
  servo[2].write(98); // Middle
  servo[3].write(92); // Ring
  servo[4].write(104); // Pinky

  // Step 658: Fingers [103, 109, 98, 92, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(109); // Index
  servo[2].write(98); // Middle
  servo[3].write(92); // Ring
  servo[4].write(103); // Pinky

  // Step 659: Fingers [102, 108, 97, 91, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(108); // Index
  servo[2].write(97); // Middle
  servo[3].write(91); // Ring
  servo[4].write(102); // Pinky

  // Step 660: Fingers [102, 108, 97, 91, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(108); // Index
  servo[2].write(97); // Middle
  servo[3].write(91); // Ring
  servo[4].write(102); // Pinky

  // Step 661: Fingers [102, 108, 97, 91, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(108); // Index
  servo[2].write(97); // Middle
  servo[3].write(91); // Ring
  servo[4].write(102); // Pinky

  // Step 662: Fingers [101, 107, 96, 90, 101] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(107); // Index
  servo[2].write(96); // Middle
  servo[3].write(90); // Ring
  servo[4].write(101); // Pinky

  // Step 663: Fingers [100, 107, 96, 90, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(107); // Index
  servo[2].write(96); // Middle
  servo[3].write(90); // Ring
  servo[4].write(100); // Pinky

  // Step 664: Fingers [99, 106, 96, 88, 99] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(106); // Index
  servo[2].write(96); // Middle
  servo[3].write(88); // Ring
  servo[4].write(99); // Pinky

  // Step 665: Fingers [98, 105, 95, 88, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(105); // Index
  servo[2].write(95); // Middle
  servo[3].write(88); // Ring
  servo[4].write(98); // Pinky

  // Step 666: Fingers [98, 105, 95, 88, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(105); // Index
  servo[2].write(95); // Middle
  servo[3].write(88); // Ring
  servo[4].write(98); // Pinky

  // Step 667: Fingers [96, 104, 94, 86, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(104); // Index
  servo[2].write(94); // Middle
  servo[3].write(86); // Ring
  servo[4].write(96); // Pinky

  // Step 668: Fingers [95, 104, 94, 86, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(104); // Index
  servo[2].write(94); // Middle
  servo[3].write(86); // Ring
  servo[4].write(95); // Pinky

  // Step 669: Fingers [94, 103, 94, 85, 94] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(103); // Index
  servo[2].write(94); // Middle
  servo[3].write(85); // Ring
  servo[4].write(94); // Pinky

  // Step 670: Fingers [93, 102, 94, 84, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(102); // Index
  servo[2].write(94); // Middle
  servo[3].write(84); // Ring
  servo[4].write(93); // Pinky

  // Step 671: Fingers [93, 102, 94, 84, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(102); // Index
  servo[2].write(94); // Middle
  servo[3].write(84); // Ring
  servo[4].write(93); // Pinky

  // Step 672: Fingers [92, 102, 94, 84, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(102); // Index
  servo[2].write(94); // Middle
  servo[3].write(84); // Ring
  servo[4].write(92); // Pinky

  // Step 673: Fingers [91, 101, 93, 83, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(101); // Index
  servo[2].write(93); // Middle
  servo[3].write(83); // Ring
  servo[4].write(91); // Pinky

  // Step 674: Fingers [91, 101, 93, 83, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(101); // Index
  servo[2].write(93); // Middle
  servo[3].write(83); // Ring
  servo[4].write(91); // Pinky

  // Step 675: Fingers [90, 100, 93, 83, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(100); // Index
  servo[2].write(93); // Middle
  servo[3].write(83); // Ring
  servo[4].write(90); // Pinky

  // Step 676: Fingers [90, 100, 93, 83, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(100); // Index
  servo[2].write(93); // Middle
  servo[3].write(83); // Ring
  servo[4].write(90); // Pinky

  delay(13);
  // Step 677: Fingers [89, 100, 93, 82, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(100); // Index
  servo[2].write(93); // Middle
  servo[3].write(82); // Ring
  servo[4].write(89); // Pinky

  // Step 678: Fingers [88, 99, 92, 81, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(99); // Index
  servo[2].write(92); // Middle
  servo[3].write(81); // Ring
  servo[4].write(88); // Pinky

  // Step 679: Fingers [88, 99, 92, 81, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(99); // Index
  servo[2].write(92); // Middle
  servo[3].write(81); // Ring
  servo[4].write(88); // Pinky

  // Step 680: Fingers [88, 99, 92, 81, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(99); // Index
  servo[2].write(92); // Middle
  servo[3].write(81); // Ring
  servo[4].write(88); // Pinky

  // Step 681: Fingers [87, 98, 92, 81, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(98); // Index
  servo[2].write(92); // Middle
  servo[3].write(81); // Ring
  servo[4].write(87); // Pinky

  // Step 682: Fingers [87, 98, 92, 81, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(98); // Index
  servo[2].write(92); // Middle
  servo[3].write(81); // Ring
  servo[4].write(87); // Pinky

  // Step 683: Fingers [86, 97, 92, 80, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(97); // Index
  servo[2].write(92); // Middle
  servo[3].write(80); // Ring
  servo[4].write(86); // Pinky

  // Step 684: Fingers [86, 97, 92, 80, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(97); // Index
  servo[2].write(92); // Middle
  servo[3].write(80); // Ring
  servo[4].write(86); // Pinky

  // Step 685: Fingers [85, 97, 91, 80, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(97); // Index
  servo[2].write(91); // Middle
  servo[3].write(80); // Ring
  servo[4].write(85); // Pinky

  delay(16);
  // Step 686: Fingers [85, 97, 91, 80, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(97); // Index
  servo[2].write(91); // Middle
  servo[3].write(80); // Ring
  servo[4].write(85); // Pinky

  // Step 687: Fingers [85, 97, 91, 80, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(97); // Index
  servo[2].write(91); // Middle
  servo[3].write(80); // Ring
  servo[4].write(85); // Pinky

  // Step 688: Fingers [85, 97, 92, 80, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(97); // Index
  servo[2].write(92); // Middle
  servo[3].write(80); // Ring
  servo[4].write(85); // Pinky

  delay(11);
  // Step 689: Fingers [84, 96, 91, 79, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(96); // Index
  servo[2].write(91); // Middle
  servo[3].write(79); // Ring
  servo[4].write(84); // Pinky

  // Step 690: Fingers [83, 95, 91, 79, 83] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(95); // Index
  servo[2].write(91); // Middle
  servo[3].write(79); // Ring
  servo[4].write(83); // Pinky

  // Step 691: Fingers [83, 95, 91, 79, 83] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(95); // Index
  servo[2].write(91); // Middle
  servo[3].write(79); // Ring
  servo[4].write(83); // Pinky

  // Step 692: Fingers [82, 94, 91, 78, 82] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(94); // Index
  servo[2].write(91); // Middle
  servo[3].write(78); // Ring
  servo[4].write(82); // Pinky

  // Step 693: Fingers [81, 94, 90, 78, 81] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(94); // Index
  servo[2].write(90); // Middle
  servo[3].write(78); // Ring
  servo[4].write(81); // Pinky

  // Step 694: Fingers [80, 93, 90, 77, 80] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(93); // Index
  servo[2].write(90); // Middle
  servo[3].write(77); // Ring
  servo[4].write(80); // Pinky

  // Step 695: Fingers [80, 93, 90, 78, 80] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(93); // Index
  servo[2].write(90); // Middle
  servo[3].write(78); // Ring
  servo[4].write(80); // Pinky

  // Step 696: Fingers [80, 93, 90, 78, 80] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(93); // Index
  servo[2].write(90); // Middle
  servo[3].write(78); // Ring
  servo[4].write(80); // Pinky

  // Step 697: Fingers [79, 92, 90, 77, 79] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(92); // Index
  servo[2].write(90); // Middle
  servo[3].write(77); // Ring
  servo[4].write(79); // Pinky

  // Step 698: Fingers [79, 92, 90, 77, 79] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(92); // Index
  servo[2].write(90); // Middle
  servo[3].write(77); // Ring
  servo[4].write(79); // Pinky

  delay(12);
  // Step 699: Fingers [79, 92, 90, 77, 79] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(92); // Index
  servo[2].write(90); // Middle
  servo[3].write(77); // Ring
  servo[4].write(79); // Pinky

  // Step 700: Fingers [78, 91, 89, 77, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(91); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(78); // Pinky

  // Step 701: Fingers [78, 91, 89, 77, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(91); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(78); // Pinky

  delay(18);
  // Step 702: Fingers [78, 91, 89, 77, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(91); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(78); // Pinky

  delay(31);
  // Step 703: Fingers [78, 91, 89, 77, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(91); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(78); // Pinky

  delay(29);
  // Step 704: Fingers [78, 91, 89, 77, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(91); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(78); // Pinky

  delay(31);
  // Step 705: Fingers [78, 91, 89, 77, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(91); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(78); // Pinky

  delay(29);
  // Step 706: Fingers [78, 91, 89, 77, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(91); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(78); // Pinky

  delay(30);
  // Step 707: Fingers [78, 91, 89, 77, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(91); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(78); // Pinky

  delay(31);
  // Step 708: Fingers [78, 91, 89, 77, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(91); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(78); // Pinky

  delay(31);
  // Step 709: Fingers [78, 91, 89, 77, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(91); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(78); // Pinky

  delay(30);
  // Step 710: Fingers [78, 91, 89, 77, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(91); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(78); // Pinky

  // Step 711: Fingers [78, 91, 89, 77, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(91); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(78); // Pinky

  // Step 712: Fingers [78, 91, 90, 78, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(91); // Index
  servo[2].write(90); // Middle
  servo[3].write(78); // Ring
  servo[4].write(78); // Pinky

  // Step 713: Fingers [79, 92, 92, 79, 79] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(92); // Index
  servo[2].write(92); // Middle
  servo[3].write(79); // Ring
  servo[4].write(79); // Pinky

  // Step 714: Fingers [79, 92, 92, 80, 79] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(92); // Index
  servo[2].write(92); // Middle
  servo[3].write(80); // Ring
  servo[4].write(79); // Pinky

  // Step 715: Fingers [79, 92, 92, 80, 79] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(92); // Index
  servo[2].write(92); // Middle
  servo[3].write(80); // Ring
  servo[4].write(79); // Pinky

  // Step 716: Fingers [80, 92, 93, 80, 80] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(92); // Index
  servo[2].write(93); // Middle
  servo[3].write(80); // Ring
  servo[4].write(80); // Pinky

  // Step 717: Fingers [80, 93, 94, 81, 80] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(93); // Index
  servo[2].write(94); // Middle
  servo[3].write(81); // Ring
  servo[4].write(80); // Pinky

  // Step 718: Fingers [81, 93, 94, 82, 81] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(93); // Index
  servo[2].write(94); // Middle
  servo[3].write(82); // Ring
  servo[4].write(81); // Pinky

  delay(16);
  // Step 719: Fingers [81, 93, 94, 82, 81] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(93); // Index
  servo[2].write(94); // Middle
  servo[3].write(82); // Ring
  servo[4].write(81); // Pinky

  // Step 720: Fingers [81, 94, 95, 83, 81] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(94); // Index
  servo[2].write(95); // Middle
  servo[3].write(83); // Ring
  servo[4].write(81); // Pinky

  delay(19);
  // Step 721: Fingers [81, 94, 95, 83, 81] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(94); // Index
  servo[2].write(95); // Middle
  servo[3].write(83); // Ring
  servo[4].write(81); // Pinky

  delay(11);
  // Step 722: Fingers [82, 95, 96, 83, 82] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(95); // Index
  servo[2].write(96); // Middle
  servo[3].write(83); // Ring
  servo[4].write(82); // Pinky

  delay(18);
  // Step 723: Fingers [82, 95, 96, 83, 82] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(95); // Index
  servo[2].write(96); // Middle
  servo[3].write(83); // Ring
  servo[4].write(82); // Pinky

  // Step 724: Fingers [82, 95, 97, 84, 82] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(95); // Index
  servo[2].write(97); // Middle
  servo[3].write(84); // Ring
  servo[4].write(82); // Pinky

  delay(14);
  // Step 725: Fingers [83, 96, 97, 85, 83] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(96); // Index
  servo[2].write(97); // Middle
  servo[3].write(85); // Ring
  servo[4].write(83); // Pinky

  // Step 726: Fingers [83, 96, 97, 85, 83] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(96); // Index
  servo[2].write(97); // Middle
  servo[3].write(85); // Ring
  servo[4].write(83); // Pinky

  // Step 727: Fingers [84, 96, 98, 85, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(96); // Index
  servo[2].write(98); // Middle
  servo[3].write(85); // Ring
  servo[4].write(84); // Pinky

  // Step 728: Fingers [84, 97, 99, 86, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(97); // Index
  servo[2].write(99); // Middle
  servo[3].write(86); // Ring
  servo[4].write(84); // Pinky

  delay(22);
  // Step 729: Fingers [84, 97, 99, 86, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(97); // Index
  servo[2].write(99); // Middle
  servo[3].write(86); // Ring
  servo[4].write(84); // Pinky

  // Step 730: Fingers [85, 97, 99, 87, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(97); // Index
  servo[2].write(99); // Middle
  servo[3].write(87); // Ring
  servo[4].write(85); // Pinky

  // Step 731: Fingers [85, 98, 100, 87, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(98); // Index
  servo[2].write(100); // Middle
  servo[3].write(87); // Ring
  servo[4].write(85); // Pinky

  // Step 732: Fingers [86, 99, 101, 88, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(99); // Index
  servo[2].write(101); // Middle
  servo[3].write(88); // Ring
  servo[4].write(86); // Pinky

  delay(16);
  // Step 733: Fingers [86, 99, 101, 88, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(99); // Index
  servo[2].write(101); // Middle
  servo[3].write(88); // Ring
  servo[4].write(86); // Pinky

  // Step 734: Fingers [87, 99, 101, 89, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(99); // Index
  servo[2].write(101); // Middle
  servo[3].write(89); // Ring
  servo[4].write(87); // Pinky

  // Step 735: Fingers [88, 100, 103, 90, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(100); // Index
  servo[2].write(103); // Middle
  servo[3].write(90); // Ring
  servo[4].write(88); // Pinky

  delay(17);
  // Step 736: Fingers [88, 100, 103, 90, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(100); // Index
  servo[2].write(103); // Middle
  servo[3].write(90); // Ring
  servo[4].write(88); // Pinky

  // Step 737: Fingers [88, 101, 103, 91, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(101); // Index
  servo[2].write(103); // Middle
  servo[3].write(91); // Ring
  servo[4].write(88); // Pinky

  // Step 738: Fingers [90, 102, 105, 92, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(102); // Index
  servo[2].write(105); // Middle
  servo[3].write(92); // Ring
  servo[4].write(90); // Pinky

  // Step 739: Fingers [90, 103, 105, 93, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(103); // Index
  servo[2].write(105); // Middle
  servo[3].write(93); // Ring
  servo[4].write(90); // Pinky

  // Step 740: Fingers [91, 103, 106, 94, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(103); // Index
  servo[2].write(106); // Middle
  servo[3].write(94); // Ring
  servo[4].write(91); // Pinky

  // Step 741: Fingers [91, 103, 106, 94, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(103); // Index
  servo[2].write(106); // Middle
  servo[3].write(94); // Ring
  servo[4].write(91); // Pinky

  // Step 742: Fingers [92, 105, 107, 95, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(105); // Index
  servo[2].write(107); // Middle
  servo[3].write(95); // Ring
  servo[4].write(92); // Pinky

  // Step 743: Fingers [93, 105, 108, 95, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(105); // Index
  servo[2].write(108); // Middle
  servo[3].write(95); // Ring
  servo[4].write(93); // Pinky

  // Step 744: Fingers [94, 107, 109, 97, 94] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(107); // Index
  servo[2].write(109); // Middle
  servo[3].write(97); // Ring
  servo[4].write(94); // Pinky

  // Step 745: Fingers [95, 107, 110, 97, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(107); // Index
  servo[2].write(110); // Middle
  servo[3].write(97); // Ring
  servo[4].write(95); // Pinky

  // Step 746: Fingers [95, 107, 110, 97, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(107); // Index
  servo[2].write(110); // Middle
  servo[3].write(97); // Ring
  servo[4].write(95); // Pinky

  // Step 747: Fingers [96, 108, 111, 99, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(108); // Index
  servo[2].write(111); // Middle
  servo[3].write(99); // Ring
  servo[4].write(96); // Pinky

  // Step 748: Fingers [97, 110, 112, 100, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(110); // Index
  servo[2].write(112); // Middle
  servo[3].write(100); // Ring
  servo[4].write(97); // Pinky

  // Step 749: Fingers [98, 110, 113, 101, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(110); // Index
  servo[2].write(113); // Middle
  servo[3].write(101); // Ring
  servo[4].write(98); // Pinky

  // Step 750: Fingers [98, 111, 114, 101, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(111); // Index
  servo[2].write(114); // Middle
  servo[3].write(101); // Ring
  servo[4].write(98); // Pinky

  // Step 751: Fingers [98, 111, 114, 101, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(111); // Index
  servo[2].write(114); // Middle
  servo[3].write(101); // Ring
  servo[4].write(98); // Pinky

  // Step 752: Fingers [100, 112, 115, 103, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(112); // Index
  servo[2].write(115); // Middle
  servo[3].write(103); // Ring
  servo[4].write(100); // Pinky

  // Step 753: Fingers [101, 113, 116, 104, 101] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(113); // Index
  servo[2].write(116); // Middle
  servo[3].write(104); // Ring
  servo[4].write(101); // Pinky

  // Step 754: Fingers [102, 114, 117, 105, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(114); // Index
  servo[2].write(117); // Middle
  servo[3].write(105); // Ring
  servo[4].write(102); // Pinky

  // Step 755: Fingers [102, 114, 117, 105, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(114); // Index
  servo[2].write(117); // Middle
  servo[3].write(105); // Ring
  servo[4].write(102); // Pinky

  // Step 756: Fingers [103, 115, 118, 106, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(115); // Index
  servo[2].write(118); // Middle
  servo[3].write(106); // Ring
  servo[4].write(103); // Pinky

  // Step 757: Fingers [104, 117, 120, 107, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(117); // Index
  servo[2].write(120); // Middle
  servo[3].write(107); // Ring
  servo[4].write(104); // Pinky

  // Step 758: Fingers [105, 117, 120, 108, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(117); // Index
  servo[2].write(120); // Middle
  servo[3].write(108); // Ring
  servo[4].write(105); // Pinky

  delay(15);
  // Step 759: Fingers [105, 117, 120, 108, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(117); // Index
  servo[2].write(120); // Middle
  servo[3].write(108); // Ring
  servo[4].write(105); // Pinky

  delay(11);
  // Step 760: Fingers [106, 118, 121, 109, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(118); // Index
  servo[2].write(121); // Middle
  servo[3].write(109); // Ring
  servo[4].write(106); // Pinky

  // Step 761: Fingers [107, 120, 123, 110, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(120); // Index
  servo[2].write(123); // Middle
  servo[3].write(110); // Ring
  servo[4].write(107); // Pinky

  // Step 762: Fingers [108, 120, 123, 111, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(120); // Index
  servo[2].write(123); // Middle
  servo[3].write(111); // Ring
  servo[4].write(108); // Pinky

  delay(16);
  // Step 763: Fingers [108, 120, 123, 111, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(120); // Index
  servo[2].write(123); // Middle
  servo[3].write(111); // Ring
  servo[4].write(108); // Pinky

  // Step 764: Fingers [109, 122, 125, 112, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(122); // Index
  servo[2].write(125); // Middle
  servo[3].write(112); // Ring
  servo[4].write(109); // Pinky

  // Step 765: Fingers [110, 122, 125, 113, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(122); // Index
  servo[2].write(125); // Middle
  servo[3].write(113); // Ring
  servo[4].write(110); // Pinky

  // Step 766: Fingers [111, 123, 126, 113, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(123); // Index
  servo[2].write(126); // Middle
  servo[3].write(113); // Ring
  servo[4].write(111); // Pinky

  // Step 767: Fingers [111, 124, 127, 114, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(124); // Index
  servo[2].write(127); // Middle
  servo[3].write(114); // Ring
  servo[4].write(111); // Pinky

  // Step 768: Fingers [111, 124, 127, 114, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(124); // Index
  servo[2].write(127); // Middle
  servo[3].write(114); // Ring
  servo[4].write(111); // Pinky

  // Step 769: Fingers [112, 125, 128, 115, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(125); // Index
  servo[2].write(128); // Middle
  servo[3].write(115); // Ring
  servo[4].write(112); // Pinky

  // Step 770: Fingers [113, 126, 128, 116, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(126); // Index
  servo[2].write(128); // Middle
  servo[3].write(116); // Ring
  servo[4].write(113); // Pinky

  // Step 771: Fingers [114, 126, 129, 117, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(126); // Index
  servo[2].write(129); // Middle
  servo[3].write(117); // Ring
  servo[4].write(114); // Pinky

  // Step 772: Fingers [114, 127, 130, 117, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(127); // Index
  servo[2].write(130); // Middle
  servo[3].write(117); // Ring
  servo[4].write(114); // Pinky

  // Step 773: Fingers [114, 127, 130, 117, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(127); // Index
  servo[2].write(130); // Middle
  servo[3].write(117); // Ring
  servo[4].write(114); // Pinky

  // Step 774: Fingers [115, 128, 130, 118, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(128); // Index
  servo[2].write(130); // Middle
  servo[3].write(118); // Ring
  servo[4].write(115); // Pinky

  delay(12);
  // Step 775: Fingers [116, 129, 132, 119, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(129); // Index
  servo[2].write(132); // Middle
  servo[3].write(119); // Ring
  servo[4].write(116); // Pinky

  // Step 776: Fingers [117, 129, 132, 120, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(129); // Index
  servo[2].write(132); // Middle
  servo[3].write(120); // Ring
  servo[4].write(117); // Pinky

  // Step 777: Fingers [117, 129, 132, 120, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(129); // Index
  servo[2].write(132); // Middle
  servo[3].write(120); // Ring
  servo[4].write(117); // Pinky

  // Step 778: Fingers [118, 130, 133, 120, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(130); // Index
  servo[2].write(133); // Middle
  servo[3].write(120); // Ring
  servo[4].write(118); // Pinky

  // Step 779: Fingers [119, 131, 134, 122, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(131); // Index
  servo[2].write(134); // Middle
  servo[3].write(122); // Ring
  servo[4].write(119); // Pinky

  // Step 780: Fingers [120, 133, 135, 123, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(133); // Index
  servo[2].write(135); // Middle
  servo[3].write(123); // Ring
  servo[4].write(120); // Pinky

  // Step 781: Fingers [121, 133, 136, 123, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(133); // Index
  servo[2].write(136); // Middle
  servo[3].write(123); // Ring
  servo[4].write(121); // Pinky

  // Step 782: Fingers [121, 133, 136, 123, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(133); // Index
  servo[2].write(136); // Middle
  servo[3].write(123); // Ring
  servo[4].write(121); // Pinky

  // Step 783: Fingers [122, 135, 137, 125, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(135); // Index
  servo[2].write(137); // Middle
  servo[3].write(125); // Ring
  servo[4].write(122); // Pinky

  // Step 784: Fingers [123, 136, 138, 125, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(136); // Index
  servo[2].write(138); // Middle
  servo[3].write(125); // Ring
  servo[4].write(123); // Pinky

  // Step 785: Fingers [124, 137, 139, 126, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(137); // Index
  servo[2].write(139); // Middle
  servo[3].write(126); // Ring
  servo[4].write(124); // Pinky

  // Step 786: Fingers [124, 137, 139, 126, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(137); // Index
  servo[2].write(139); // Middle
  servo[3].write(126); // Ring
  servo[4].write(124); // Pinky

  // Step 787: Fingers [126, 138, 140, 128, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(138); // Index
  servo[2].write(140); // Middle
  servo[3].write(128); // Ring
  servo[4].write(126); // Pinky

  // Step 788: Fingers [126, 139, 141, 128, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(139); // Index
  servo[2].write(141); // Middle
  servo[3].write(128); // Ring
  servo[4].write(126); // Pinky

  // Step 789: Fingers [127, 140, 141, 129, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(140); // Index
  servo[2].write(141); // Middle
  servo[3].write(129); // Ring
  servo[4].write(127); // Pinky

  // Step 790: Fingers [129, 142, 143, 130, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(142); // Index
  servo[2].write(143); // Middle
  servo[3].write(130); // Ring
  servo[4].write(129); // Pinky

  // Step 791: Fingers [129, 142, 143, 130, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(142); // Index
  servo[2].write(143); // Middle
  servo[3].write(130); // Ring
  servo[4].write(129); // Pinky

  // Step 792: Fingers [131, 143, 144, 132, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(143); // Index
  servo[2].write(144); // Middle
  servo[3].write(132); // Ring
  servo[4].write(131); // Pinky

  // Step 793: Fingers [131, 144, 145, 132, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(144); // Index
  servo[2].write(145); // Middle
  servo[3].write(132); // Ring
  servo[4].write(131); // Pinky

  // Step 794: Fingers [133, 145, 146, 133, 133] Arm [-, -, -]
  servo[0].write(133); // Thumb
  servo[1].write(145); // Index
  servo[2].write(146); // Middle
  servo[3].write(133); // Ring
  servo[4].write(133); // Pinky

  // Step 795: Fingers [135, 147, 148, 135, 135] Arm [-, -, -]
  servo[0].write(135); // Thumb
  servo[1].write(147); // Index
  servo[2].write(148); // Middle
  servo[3].write(135); // Ring
  servo[4].write(135); // Pinky

  // Step 796: Fingers [135, 147, 148, 135, 135] Arm [-, -, -]
  servo[0].write(135); // Thumb
  servo[1].write(147); // Index
  servo[2].write(148); // Middle
  servo[3].write(135); // Ring
  servo[4].write(135); // Pinky

  // Step 797: Fingers [136, 148, 148, 135, 136] Arm [-, -, -]
  servo[0].write(136); // Thumb
  servo[1].write(148); // Index
  servo[2].write(148); // Middle
  servo[3].write(135); // Ring
  servo[4].write(136); // Pinky

  // Step 798: Fingers [137, 150, 149, 137, 137] Arm [-, -, -]
  servo[0].write(137); // Thumb
  servo[1].write(150); // Index
  servo[2].write(149); // Middle
  servo[3].write(137); // Ring
  servo[4].write(137); // Pinky

  // Step 799: Fingers [137, 150, 150, 137, 137] Arm [-, -, -]
  servo[0].write(137); // Thumb
  servo[1].write(150); // Index
  servo[2].write(150); // Middle
  servo[3].write(137); // Ring
  servo[4].write(137); // Pinky

  // Step 800: Fingers [138, 151, 151, 138, 138] Arm [-, -, -]
  servo[0].write(138); // Thumb
  servo[1].write(151); // Index
  servo[2].write(151); // Middle
  servo[3].write(138); // Ring
  servo[4].write(138); // Pinky

  // Step 801: Fingers [138, 151, 151, 138, 138] Arm [-, -, -]
  servo[0].write(138); // Thumb
  servo[1].write(151); // Index
  servo[2].write(151); // Middle
  servo[3].write(138); // Ring
  servo[4].write(138); // Pinky

  // Step 802: Fingers [139, 152, 151, 138, 139] Arm [-, -, -]
  servo[0].write(139); // Thumb
  servo[1].write(152); // Index
  servo[2].write(151); // Middle
  servo[3].write(138); // Ring
  servo[4].write(139); // Pinky

  // Step 803: Fingers [140, 152, 152, 139, 140] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(152); // Index
  servo[2].write(152); // Middle
  servo[3].write(139); // Ring
  servo[4].write(140); // Pinky

  // Step 804: Fingers [140, 153, 152, 140, 140] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(153); // Index
  servo[2].write(152); // Middle
  servo[3].write(140); // Ring
  servo[4].write(140); // Pinky

  // Step 805: Fingers [140, 153, 152, 140, 140] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(153); // Index
  servo[2].write(152); // Middle
  servo[3].write(140); // Ring
  servo[4].write(140); // Pinky

  // Step 806: Fingers [141, 154, 153, 140, 141] Arm [-, -, -]
  servo[0].write(141); // Thumb
  servo[1].write(154); // Index
  servo[2].write(153); // Middle
  servo[3].write(140); // Ring
  servo[4].write(141); // Pinky

  // Step 807: Fingers [142, 154, 153, 141, 142] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(154); // Index
  servo[2].write(153); // Middle
  servo[3].write(141); // Ring
  servo[4].write(142); // Pinky

  delay(18);
  // Step 808: Fingers [142, 155, 154, 141, 142] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(155); // Index
  servo[2].write(154); // Middle
  servo[3].write(141); // Ring
  servo[4].write(142); // Pinky

  // Step 809: Fingers [142, 155, 154, 141, 142] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(155); // Index
  servo[2].write(154); // Middle
  servo[3].write(141); // Ring
  servo[4].write(142); // Pinky

  // Step 810: Fingers [143, 156, 155, 142, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(156); // Index
  servo[2].write(155); // Middle
  servo[3].write(142); // Ring
  servo[4].write(143); // Pinky

  // Step 811: Fingers [144, 156, 155, 143, 144] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(156); // Index
  servo[2].write(155); // Middle
  servo[3].write(143); // Ring
  servo[4].write(144); // Pinky

  // Step 812: Fingers [144, 157, 156, 143, 144] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(157); // Index
  servo[2].write(156); // Middle
  servo[3].write(143); // Ring
  servo[4].write(144); // Pinky

  // Step 813: Fingers [145, 158, 156, 144, 145] Arm [-, -, -]
  servo[0].write(145); // Thumb
  servo[1].write(158); // Index
  servo[2].write(156); // Middle
  servo[3].write(144); // Ring
  servo[4].write(145); // Pinky

  // Step 814: Fingers [145, 158, 156, 144, 145] Arm [-, -, -]
  servo[0].write(145); // Thumb
  servo[1].write(158); // Index
  servo[2].write(156); // Middle
  servo[3].write(144); // Ring
  servo[4].write(145); // Pinky

  // Step 815: Fingers [146, 159, 157, 144, 146] Arm [-, -, -]
  servo[0].write(146); // Thumb
  servo[1].write(159); // Index
  servo[2].write(157); // Middle
  servo[3].write(144); // Ring
  servo[4].write(146); // Pinky

  delay(13);
  // Step 816: Fingers [147, 159, 157, 145, 147] Arm [-, -, -]
  servo[0].write(147); // Thumb
  servo[1].write(159); // Index
  servo[2].write(157); // Middle
  servo[3].write(145); // Ring
  servo[4].write(147); // Pinky

  // Step 817: Fingers [147, 159, 157, 145, 147] Arm [-, -, -]
  servo[0].write(147); // Thumb
  servo[1].write(159); // Index
  servo[2].write(157); // Middle
  servo[3].write(145); // Ring
  servo[4].write(147); // Pinky

  // Step 818: Fingers [148, 161, 159, 146, 148] Arm [-, -, -]
  servo[0].write(148); // Thumb
  servo[1].write(161); // Index
  servo[2].write(159); // Middle
  servo[3].write(146); // Ring
  servo[4].write(148); // Pinky

  // Step 819: Fingers [148, 161, 159, 146, 148] Arm [-, -, -]
  servo[0].write(148); // Thumb
  servo[1].write(161); // Index
  servo[2].write(159); // Middle
  servo[3].write(146); // Ring
  servo[4].write(148); // Pinky

  // Step 820: Fingers [149, 162, 160, 147, 149] Arm [-, -, -]
  servo[0].write(149); // Thumb
  servo[1].write(162); // Index
  servo[2].write(160); // Middle
  servo[3].write(147); // Ring
  servo[4].write(149); // Pinky

  // Step 821: Fingers [149, 162, 160, 147, 149] Arm [-, -, -]
  servo[0].write(149); // Thumb
  servo[1].write(162); // Index
  servo[2].write(160); // Middle
  servo[3].write(147); // Ring
  servo[4].write(149); // Pinky

  // Step 822: Fingers [150, 162, 160, 147, 150] Arm [-, -, -]
  servo[0].write(150); // Thumb
  servo[1].write(162); // Index
  servo[2].write(160); // Middle
  servo[3].write(147); // Ring
  servo[4].write(150); // Pinky

  // Step 823: Fingers [150, 163, 160, 148, 150] Arm [-, -, -]
  servo[0].write(150); // Thumb
  servo[1].write(163); // Index
  servo[2].write(160); // Middle
  servo[3].write(148); // Ring
  servo[4].write(150); // Pinky

  // Step 824: Fingers [152, 164, 161, 149, 152] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(164); // Index
  servo[2].write(161); // Middle
  servo[3].write(149); // Ring
  servo[4].write(152); // Pinky

  // Step 825: Fingers [152, 164, 161, 149, 152] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(164); // Index
  servo[2].write(161); // Middle
  servo[3].write(149); // Ring
  servo[4].write(152); // Pinky

  // Step 826: Fingers [152, 164, 161, 149, 152] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(164); // Index
  servo[2].write(161); // Middle
  servo[3].write(149); // Ring
  servo[4].write(152); // Pinky

  // Step 827: Fingers [153, 165, 162, 149, 153] Arm [-, -, -]
  servo[0].write(153); // Thumb
  servo[1].write(165); // Index
  servo[2].write(162); // Middle
  servo[3].write(149); // Ring
  servo[4].write(153); // Pinky

  // Step 828: Fingers [153, 166, 162, 150, 153] Arm [-, -, -]
  servo[0].write(153); // Thumb
  servo[1].write(166); // Index
  servo[2].write(162); // Middle
  servo[3].write(150); // Ring
  servo[4].write(153); // Pinky

  // Step 829: Fingers [154, 166, 163, 150, 154] Arm [-, -, -]
  servo[0].write(154); // Thumb
  servo[1].write(166); // Index
  servo[2].write(163); // Middle
  servo[3].write(150); // Ring
  servo[4].write(154); // Pinky

  delay(16);
  // Step 830: Fingers [154, 166, 163, 150, 154] Arm [-, -, -]
  servo[0].write(154); // Thumb
  servo[1].write(166); // Index
  servo[2].write(163); // Middle
  servo[3].write(150); // Ring
  servo[4].write(154); // Pinky

  // Step 831: Fingers [155, 168, 164, 152, 155] Arm [-, -, -]
  servo[0].write(155); // Thumb
  servo[1].write(168); // Index
  servo[2].write(164); // Middle
  servo[3].write(152); // Ring
  servo[4].write(155); // Pinky

  // Step 832: Fingers [156, 168, 164, 152, 156] Arm [-, -, -]
  servo[0].write(156); // Thumb
  servo[1].write(168); // Index
  servo[2].write(164); // Middle
  servo[3].write(152); // Ring
  servo[4].write(156); // Pinky

  // Step 833: Fingers [156, 168, 164, 152, 156] Arm [-, -, -]
  servo[0].write(156); // Thumb
  servo[1].write(168); // Index
  servo[2].write(164); // Middle
  servo[3].write(152); // Ring
  servo[4].write(156); // Pinky

  // Step 834: Fingers [156, 168, 164, 152, 156] Arm [-, -, -]
  servo[0].write(156); // Thumb
  servo[1].write(168); // Index
  servo[2].write(164); // Middle
  servo[3].write(152); // Ring
  servo[4].write(156); // Pinky

  // Step 835: Fingers [157, 169, 164, 152, 157] Arm [-, -, -]
  servo[0].write(157); // Thumb
  servo[1].write(169); // Index
  servo[2].write(164); // Middle
  servo[3].write(152); // Ring
  servo[4].write(157); // Pinky

  // Step 836: Fingers [157, 169, 164, 152, 157] Arm [-, -, -]
  servo[0].write(157); // Thumb
  servo[1].write(169); // Index
  servo[2].write(164); // Middle
  servo[3].write(152); // Ring
  servo[4].write(157); // Pinky

  // Step 837: Fingers [158, 170, 165, 153, 158] Arm [-, -, -]
  servo[0].write(158); // Thumb
  servo[1].write(170); // Index
  servo[2].write(165); // Middle
  servo[3].write(153); // Ring
  servo[4].write(158); // Pinky

  // Step 838: Fingers [159, 171, 165, 154, 159] Arm [-, -, -]
  servo[0].write(159); // Thumb
  servo[1].write(171); // Index
  servo[2].write(165); // Middle
  servo[3].write(154); // Ring
  servo[4].write(159); // Pinky

  // Step 839: Fingers [159, 171, 165, 154, 159] Arm [-, -, -]
  servo[0].write(159); // Thumb
  servo[1].write(171); // Index
  servo[2].write(165); // Middle
  servo[3].write(154); // Ring
  servo[4].write(159); // Pinky

  // Step 840: Fingers [160, 171, 166, 154, 160] Arm [-, -, -]
  servo[0].write(160); // Thumb
  servo[1].write(171); // Index
  servo[2].write(166); // Middle
  servo[3].write(154); // Ring
  servo[4].write(160); // Pinky

  delay(13);
  // Step 841: Fingers [160, 172, 165, 154, 160] Arm [-, -, -]
  servo[0].write(160); // Thumb
  servo[1].write(172); // Index
  servo[2].write(165); // Middle
  servo[3].write(154); // Ring
  servo[4].write(160); // Pinky

  delay(12);
  // Step 842: Fingers [160, 172, 165, 154, 160] Arm [-, -, -]
  servo[0].write(160); // Thumb
  servo[1].write(172); // Index
  servo[2].write(165); // Middle
  servo[3].write(154); // Ring
  servo[4].write(160); // Pinky

  delay(12);
  // Step 843: Fingers [161, 172, 166, 155, 161] Arm [-, -, -]
  servo[0].write(161); // Thumb
  servo[1].write(172); // Index
  servo[2].write(166); // Middle
  servo[3].write(155); // Ring
  servo[4].write(161); // Pinky

  // Step 844: Fingers [162, 173, 167, 156, 162] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(173); // Index
  servo[2].write(167); // Middle
  servo[3].write(156); // Ring
  servo[4].write(162); // Pinky

  // Step 845: Fingers [162, 173, 167, 156, 162] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(173); // Index
  servo[2].write(167); // Middle
  servo[3].write(156); // Ring
  servo[4].write(162); // Pinky

  delay(27);
  // Step 846: Fingers [163, 174, 167, 156, 163] Arm [-, -, -]
  servo[0].write(163); // Thumb
  servo[1].write(174); // Index
  servo[2].write(167); // Middle
  servo[3].write(156); // Ring
  servo[4].write(163); // Pinky

  // Step 847: Fingers [164, 175, 168, 157, 164] Arm [-, -, -]
  servo[0].write(164); // Thumb
  servo[1].write(175); // Index
  servo[2].write(168); // Middle
  servo[3].write(157); // Ring
  servo[4].write(164); // Pinky

  // Step 848: Fingers [164, 175, 168, 157, 164] Arm [-, -, -]
  servo[0].write(164); // Thumb
  servo[1].write(175); // Index
  servo[2].write(168); // Middle
  servo[3].write(157); // Ring
  servo[4].write(164); // Pinky

  // Step 849: Fingers [164, 175, 168, 157, 164] Arm [-, -, -]
  servo[0].write(164); // Thumb
  servo[1].write(175); // Index
  servo[2].write(168); // Middle
  servo[3].write(157); // Ring
  servo[4].write(164); // Pinky

  delay(31);
  // Step 850: Fingers [164, 175, 168, 157, 164] Arm [-, -, -]
  servo[0].write(164); // Thumb
  servo[1].write(175); // Index
  servo[2].write(168); // Middle
  servo[3].write(157); // Ring
  servo[4].write(164); // Pinky

  delay(30);
  // Step 851: Fingers [164, 175, 168, 157, 164] Arm [-, -, -]
  servo[0].write(164); // Thumb
  servo[1].write(175); // Index
  servo[2].write(168); // Middle
  servo[3].write(157); // Ring
  servo[4].write(164); // Pinky

  // Step 852: Fingers [165, 175, 167, 157, 165] Arm [-, -, -]
  servo[0].write(165); // Thumb
  servo[1].write(175); // Index
  servo[2].write(167); // Middle
  servo[3].write(157); // Ring
  servo[4].write(165); // Pinky

  delay(14);
  // Step 853: Fingers [165, 176, 168, 158, 165] Arm [-, -, -]
  servo[0].write(165); // Thumb
  servo[1].write(176); // Index
  servo[2].write(168); // Middle
  servo[3].write(158); // Ring
  servo[4].write(165); // Pinky

  // Step 854: Fingers [165, 176, 168, 158, 165] Arm [-, -, -]
  servo[0].write(165); // Thumb
  servo[1].write(176); // Index
  servo[2].write(168); // Middle
  servo[3].write(158); // Ring
  servo[4].write(165); // Pinky

  // Step 855: Fingers [166, 176, 168, 158, 166] Arm [-, -, -]
  servo[0].write(166); // Thumb
  servo[1].write(176); // Index
  servo[2].write(168); // Middle
  servo[3].write(158); // Ring
  servo[4].write(166); // Pinky

  // Step 856: Fingers [167, 176, 168, 158, 167] Arm [-, -, -]
  servo[0].write(167); // Thumb
  servo[1].write(176); // Index
  servo[2].write(168); // Middle
  servo[3].write(158); // Ring
  servo[4].write(167); // Pinky

  // Step 857: Fingers [168, 178, 169, 160, 168] Arm [-, -, -]
  servo[0].write(168); // Thumb
  servo[1].write(178); // Index
  servo[2].write(169); // Middle
  servo[3].write(160); // Ring
  servo[4].write(168); // Pinky

  // Step 858: Fingers [169, 178, 169, 160, 169] Arm [-, -, -]
  servo[0].write(169); // Thumb
  servo[1].write(178); // Index
  servo[2].write(169); // Middle
  servo[3].write(160); // Ring
  servo[4].write(169); // Pinky

  // Step 859: Fingers [169, 178, 169, 160, 169] Arm [-, -, -]
  servo[0].write(169); // Thumb
  servo[1].write(178); // Index
  servo[2].write(169); // Middle
  servo[3].write(160); // Ring
  servo[4].write(169); // Pinky

  delay(16);
  // Step 860: Fingers [170, 178, 169, 160, 170] Arm [-, -, -]
  servo[0].write(170); // Thumb
  servo[1].write(178); // Index
  servo[2].write(169); // Middle
  servo[3].write(160); // Ring
  servo[4].write(170); // Pinky

  // Step 861: Fingers [171, 179, 169, 161, 171] Arm [-, -, -]
  servo[0].write(171); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(161); // Ring
  servo[4].write(171); // Pinky

  delay(14);
  // Step 862: Fingers [171, 179, 169, 161, 171] Arm [-, -, -]
  servo[0].write(171); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(161); // Ring
  servo[4].write(171); // Pinky

  // Step 863: Fingers [171, 179, 169, 161, 171] Arm [-, -, -]
  servo[0].write(171); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(161); // Ring
  servo[4].write(171); // Pinky

  // Step 864: Fingers [171, 179, 169, 161, 171] Arm [-, -, -]
  servo[0].write(171); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(161); // Ring
  servo[4].write(171); // Pinky

  // Step 865: Fingers [172, 179, 169, 162, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(162); // Ring
  servo[4].write(172); // Pinky

  delay(22);
  // Step 866: Fingers [172, 179, 169, 162, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(162); // Ring
  servo[4].write(172); // Pinky

  // Step 867: Fingers [172, 179, 169, 162, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(162); // Ring
  servo[4].write(172); // Pinky

  delay(16);
  // Step 868: Fingers [172, 179, 169, 162, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(162); // Ring
  servo[4].write(172); // Pinky

  // Step 869: Fingers [172, 179, 169, 162, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(169); // Middle
  servo[3].write(162); // Ring
  servo[4].write(172); // Pinky

  // Step 870: Fingers [172, 179, 168, 161, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(168); // Middle
  servo[3].write(161); // Ring
  servo[4].write(172); // Pinky

  // Step 871: Fingers [172, 179, 168, 161, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(168); // Middle
  servo[3].write(161); // Ring
  servo[4].write(172); // Pinky

  // Step 872: Fingers [172, 179, 168, 161, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(168); // Middle
  servo[3].write(161); // Ring
  servo[4].write(172); // Pinky

  // Step 873: Fingers [172, 179, 168, 161, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(179); // Index
  servo[2].write(168); // Middle
  servo[3].write(161); // Ring
  servo[4].write(172); // Pinky

  // Step 874: Fingers [172, 178, 167, 161, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(178); // Index
  servo[2].write(167); // Middle
  servo[3].write(161); // Ring
  servo[4].write(172); // Pinky

  // Step 875: Fingers [172, 178, 167, 161, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(178); // Index
  servo[2].write(167); // Middle
  servo[3].write(161); // Ring
  servo[4].write(172); // Pinky

  // Step 876: Fingers [172, 177, 165, 160, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(177); // Index
  servo[2].write(165); // Middle
  servo[3].write(160); // Ring
  servo[4].write(172); // Pinky

  delay(14);
  // Step 877: Fingers [172, 177, 165, 160, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(177); // Index
  servo[2].write(165); // Middle
  servo[3].write(160); // Ring
  servo[4].write(172); // Pinky

  // Step 878: Fingers [172, 177, 165, 160, 172] Arm [-, -, -]
  servo[0].write(172); // Thumb
  servo[1].write(177); // Index
  servo[2].write(165); // Middle
  servo[3].write(160); // Ring
  servo[4].write(172); // Pinky

  // Step 879: Fingers [171, 176, 164, 160, 171] Arm [-, -, -]
  servo[0].write(171); // Thumb
  servo[1].write(176); // Index
  servo[2].write(164); // Middle
  servo[3].write(160); // Ring
  servo[4].write(171); // Pinky

  // Step 880: Fingers [171, 176, 164, 159, 171] Arm [-, -, -]
  servo[0].write(171); // Thumb
  servo[1].write(176); // Index
  servo[2].write(164); // Middle
  servo[3].write(159); // Ring
  servo[4].write(171); // Pinky

  // Step 881: Fingers [170, 175, 163, 158, 170] Arm [-, -, -]
  servo[0].write(170); // Thumb
  servo[1].write(175); // Index
  servo[2].write(163); // Middle
  servo[3].write(158); // Ring
  servo[4].write(170); // Pinky

  // Step 882: Fingers [170, 175, 163, 158, 170] Arm [-, -, -]
  servo[0].write(170); // Thumb
  servo[1].write(175); // Index
  servo[2].write(163); // Middle
  servo[3].write(158); // Ring
  servo[4].write(170); // Pinky

  // Step 883: Fingers [170, 174, 163, 158, 170] Arm [-, -, -]
  servo[0].write(170); // Thumb
  servo[1].write(174); // Index
  servo[2].write(163); // Middle
  servo[3].write(158); // Ring
  servo[4].write(170); // Pinky

  // Step 884: Fingers [169, 174, 162, 157, 169] Arm [-, -, -]
  servo[0].write(169); // Thumb
  servo[1].write(174); // Index
  servo[2].write(162); // Middle
  servo[3].write(157); // Ring
  servo[4].write(169); // Pinky

  // Step 885: Fingers [168, 173, 161, 156, 168] Arm [-, -, -]
  servo[0].write(168); // Thumb
  servo[1].write(173); // Index
  servo[2].write(161); // Middle
  servo[3].write(156); // Ring
  servo[4].write(168); // Pinky

  delay(12);
  // Step 886: Fingers [168, 173, 161, 156, 168] Arm [-, -, -]
  servo[0].write(168); // Thumb
  servo[1].write(173); // Index
  servo[2].write(161); // Middle
  servo[3].write(156); // Ring
  servo[4].write(168); // Pinky

  // Step 887: Fingers [168, 172, 161, 156, 168] Arm [-, -, -]
  servo[0].write(168); // Thumb
  servo[1].write(172); // Index
  servo[2].write(161); // Middle
  servo[3].write(156); // Ring
  servo[4].write(168); // Pinky

  delay(13);
  // Step 888: Fingers [167, 172, 160, 155, 167] Arm [-, -, -]
  servo[0].write(167); // Thumb
  servo[1].write(172); // Index
  servo[2].write(160); // Middle
  servo[3].write(155); // Ring
  servo[4].write(167); // Pinky

  // Step 889: Fingers [167, 172, 160, 155, 167] Arm [-, -, -]
  servo[0].write(167); // Thumb
  servo[1].write(172); // Index
  servo[2].write(160); // Middle
  servo[3].write(155); // Ring
  servo[4].write(167); // Pinky

  // Step 890: Fingers [166, 171, 159, 155, 166] Arm [-, -, -]
  servo[0].write(166); // Thumb
  servo[1].write(171); // Index
  servo[2].write(159); // Middle
  servo[3].write(155); // Ring
  servo[4].write(166); // Pinky

  // Step 891: Fingers [165, 170, 158, 153, 165] Arm [-, -, -]
  servo[0].write(165); // Thumb
  servo[1].write(170); // Index
  servo[2].write(158); // Middle
  servo[3].write(153); // Ring
  servo[4].write(165); // Pinky

  // Step 892: Fingers [165, 170, 158, 153, 165] Arm [-, -, -]
  servo[0].write(165); // Thumb
  servo[1].write(170); // Index
  servo[2].write(158); // Middle
  servo[3].write(153); // Ring
  servo[4].write(165); // Pinky

  // Step 893: Fingers [165, 169, 157, 153, 165] Arm [-, -, -]
  servo[0].write(165); // Thumb
  servo[1].write(169); // Index
  servo[2].write(157); // Middle
  servo[3].write(153); // Ring
  servo[4].write(165); // Pinky

  // Step 894: Fingers [165, 169, 157, 153, 165] Arm [-, -, -]
  servo[0].write(165); // Thumb
  servo[1].write(169); // Index
  servo[2].write(157); // Middle
  servo[3].write(153); // Ring
  servo[4].write(165); // Pinky

  // Step 895: Fingers [163, 168, 156, 151, 163] Arm [-, -, -]
  servo[0].write(163); // Thumb
  servo[1].write(168); // Index
  servo[2].write(156); // Middle
  servo[3].write(151); // Ring
  servo[4].write(163); // Pinky

  // Step 896: Fingers [163, 167, 155, 151, 163] Arm [-, -, -]
  servo[0].write(163); // Thumb
  servo[1].write(167); // Index
  servo[2].write(155); // Middle
  servo[3].write(151); // Ring
  servo[4].write(163); // Pinky

  // Step 897: Fingers [162, 167, 155, 150, 162] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(167); // Index
  servo[2].write(155); // Middle
  servo[3].write(150); // Ring
  servo[4].write(162); // Pinky

  delay(14);
  // Step 898: Fingers [162, 167, 155, 150, 162] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(167); // Index
  servo[2].write(155); // Middle
  servo[3].write(150); // Ring
  servo[4].write(162); // Pinky

  // Step 899: Fingers [162, 166, 154, 150, 162] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(166); // Index
  servo[2].write(154); // Middle
  servo[3].write(150); // Ring
  servo[4].write(162); // Pinky

  // Step 900: Fingers [161, 165, 153, 149, 161] Arm [-, -, -]
  servo[0].write(161); // Thumb
  servo[1].write(165); // Index
  servo[2].write(153); // Middle
  servo[3].write(149); // Ring
  servo[4].write(161); // Pinky

  delay(15);
  // Step 901: Fingers [161, 165, 153, 149, 161] Arm [-, -, -]
  servo[0].write(161); // Thumb
  servo[1].write(165); // Index
  servo[2].write(153); // Middle
  servo[3].write(149); // Ring
  servo[4].write(161); // Pinky

  delay(16);
  // Step 902: Fingers [160, 165, 153, 148, 160] Arm [-, -, -]
  servo[0].write(160); // Thumb
  servo[1].write(165); // Index
  servo[2].write(153); // Middle
  servo[3].write(148); // Ring
  servo[4].write(160); // Pinky

  // Step 903: Fingers [160, 164, 152, 148, 160] Arm [-, -, -]
  servo[0].write(160); // Thumb
  servo[1].write(164); // Index
  servo[2].write(152); // Middle
  servo[3].write(148); // Ring
  servo[4].write(160); // Pinky

  // Step 904: Fingers [160, 164, 152, 148, 160] Arm [-, -, -]
  servo[0].write(160); // Thumb
  servo[1].write(164); // Index
  servo[2].write(152); // Middle
  servo[3].write(148); // Ring
  servo[4].write(160); // Pinky

  // Step 905: Fingers [159, 163, 151, 147, 159] Arm [-, -, -]
  servo[0].write(159); // Thumb
  servo[1].write(163); // Index
  servo[2].write(151); // Middle
  servo[3].write(147); // Ring
  servo[4].write(159); // Pinky

  // Step 906: Fingers [158, 162, 150, 146, 158] Arm [-, -, -]
  servo[0].write(158); // Thumb
  servo[1].write(162); // Index
  servo[2].write(150); // Middle
  servo[3].write(146); // Ring
  servo[4].write(158); // Pinky

  // Step 907: Fingers [158, 162, 150, 146, 158] Arm [-, -, -]
  servo[0].write(158); // Thumb
  servo[1].write(162); // Index
  servo[2].write(150); // Middle
  servo[3].write(146); // Ring
  servo[4].write(158); // Pinky

  // Step 908: Fingers [157, 161, 149, 145, 157] Arm [-, -, -]
  servo[0].write(157); // Thumb
  servo[1].write(161); // Index
  servo[2].write(149); // Middle
  servo[3].write(145); // Ring
  servo[4].write(157); // Pinky

  // Step 909: Fingers [156, 160, 148, 144, 156] Arm [-, -, -]
  servo[0].write(156); // Thumb
  servo[1].write(160); // Index
  servo[2].write(148); // Middle
  servo[3].write(144); // Ring
  servo[4].write(156); // Pinky

  delay(16);
  // Step 910: Fingers [156, 160, 148, 144, 156] Arm [-, -, -]
  servo[0].write(156); // Thumb
  servo[1].write(160); // Index
  servo[2].write(148); // Middle
  servo[3].write(144); // Ring
  servo[4].write(156); // Pinky

  // Step 911: Fingers [155, 159, 147, 143, 155] Arm [-, -, -]
  servo[0].write(155); // Thumb
  servo[1].write(159); // Index
  servo[2].write(147); // Middle
  servo[3].write(143); // Ring
  servo[4].write(155); // Pinky

  // Step 912: Fingers [154, 158, 146, 142, 154] Arm [-, -, -]
  servo[0].write(154); // Thumb
  servo[1].write(158); // Index
  servo[2].write(146); // Middle
  servo[3].write(142); // Ring
  servo[4].write(154); // Pinky

  // Step 913: Fingers [153, 157, 144, 141, 153] Arm [-, -, -]
  servo[0].write(153); // Thumb
  servo[1].write(157); // Index
  servo[2].write(144); // Middle
  servo[3].write(141); // Ring
  servo[4].write(153); // Pinky

  delay(16);
  // Step 914: Fingers [153, 157, 144, 141, 153] Arm [-, -, -]
  servo[0].write(153); // Thumb
  servo[1].write(157); // Index
  servo[2].write(144); // Middle
  servo[3].write(141); // Ring
  servo[4].write(153); // Pinky

  // Step 915: Fingers [152, 155, 143, 140, 152] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(155); // Index
  servo[2].write(143); // Middle
  servo[3].write(140); // Ring
  servo[4].write(152); // Pinky

  // Step 916: Fingers [151, 154, 142, 139, 151] Arm [-, -, -]
  servo[0].write(151); // Thumb
  servo[1].write(154); // Index
  servo[2].write(142); // Middle
  servo[3].write(139); // Ring
  servo[4].write(151); // Pinky

  delay(15);
  // Step 917: Fingers [150, 153, 141, 138, 150] Arm [-, -, -]
  servo[0].write(150); // Thumb
  servo[1].write(153); // Index
  servo[2].write(141); // Middle
  servo[3].write(138); // Ring
  servo[4].write(150); // Pinky

  // Step 918: Fingers [150, 153, 141, 138, 150] Arm [-, -, -]
  servo[0].write(150); // Thumb
  servo[1].write(153); // Index
  servo[2].write(141); // Middle
  servo[3].write(138); // Ring
  servo[4].write(150); // Pinky

  // Step 919: Fingers [149, 152, 140, 137, 149] Arm [-, -, -]
  servo[0].write(149); // Thumb
  servo[1].write(152); // Index
  servo[2].write(140); // Middle
  servo[3].write(137); // Ring
  servo[4].write(149); // Pinky

  delay(11);
  // Step 920: Fingers [148, 151, 138, 135, 148] Arm [-, -, -]
  servo[0].write(148); // Thumb
  servo[1].write(151); // Index
  servo[2].write(138); // Middle
  servo[3].write(135); // Ring
  servo[4].write(148); // Pinky

  // Step 921: Fingers [147, 150, 138, 135, 147] Arm [-, -, -]
  servo[0].write(147); // Thumb
  servo[1].write(150); // Index
  servo[2].write(138); // Middle
  servo[3].write(135); // Ring
  servo[4].write(147); // Pinky

  // Step 922: Fingers [147, 150, 138, 135, 147] Arm [-, -, -]
  servo[0].write(147); // Thumb
  servo[1].write(150); // Index
  servo[2].write(138); // Middle
  servo[3].write(135); // Ring
  servo[4].write(147); // Pinky

  // Step 923: Fingers [147, 149, 137, 134, 147] Arm [-, -, -]
  servo[0].write(147); // Thumb
  servo[1].write(149); // Index
  servo[2].write(137); // Middle
  servo[3].write(134); // Ring
  servo[4].write(147); // Pinky

  // Step 924: Fingers [146, 149, 136, 134, 146] Arm [-, -, -]
  servo[0].write(146); // Thumb
  servo[1].write(149); // Index
  servo[2].write(136); // Middle
  servo[3].write(134); // Ring
  servo[4].write(146); // Pinky

  // Step 925: Fingers [145, 148, 136, 133, 145] Arm [-, -, -]
  servo[0].write(145); // Thumb
  servo[1].write(148); // Index
  servo[2].write(136); // Middle
  servo[3].write(133); // Ring
  servo[4].write(145); // Pinky

  // Step 926: Fingers [145, 148, 136, 133, 145] Arm [-, -, -]
  servo[0].write(145); // Thumb
  servo[1].write(148); // Index
  servo[2].write(136); // Middle
  servo[3].write(133); // Ring
  servo[4].write(145); // Pinky

  // Step 927: Fingers [145, 147, 135, 132, 145] Arm [-, -, -]
  servo[0].write(145); // Thumb
  servo[1].write(147); // Index
  servo[2].write(135); // Middle
  servo[3].write(132); // Ring
  servo[4].write(145); // Pinky

  // Step 928: Fingers [144, 147, 134, 132, 144] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(147); // Index
  servo[2].write(134); // Middle
  servo[3].write(132); // Ring
  servo[4].write(144); // Pinky

  // Step 929: Fingers [144, 146, 134, 131, 144] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(146); // Index
  servo[2].write(134); // Middle
  servo[3].write(131); // Ring
  servo[4].write(144); // Pinky

  // Step 930: Fingers [143, 146, 133, 130, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(146); // Index
  servo[2].write(133); // Middle
  servo[3].write(130); // Ring
  servo[4].write(143); // Pinky

  // Step 931: Fingers [143, 146, 133, 130, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(146); // Index
  servo[2].write(133); // Middle
  servo[3].write(130); // Ring
  servo[4].write(143); // Pinky

  // Step 932: Fingers [142, 145, 132, 130, 142] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(145); // Index
  servo[2].write(132); // Middle
  servo[3].write(130); // Ring
  servo[4].write(142); // Pinky

  // Step 933: Fingers [141, 144, 131, 129, 141] Arm [-, -, -]
  servo[0].write(141); // Thumb
  servo[1].write(144); // Index
  servo[2].write(131); // Middle
  servo[3].write(129); // Ring
  servo[4].write(141); // Pinky

  // Step 934: Fingers [140, 143, 131, 128, 140] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(143); // Index
  servo[2].write(131); // Middle
  servo[3].write(128); // Ring
  servo[4].write(140); // Pinky

  // Step 935: Fingers [140, 143, 131, 128, 140] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(143); // Index
  servo[2].write(131); // Middle
  servo[3].write(128); // Ring
  servo[4].write(140); // Pinky

  // Step 936: Fingers [139, 142, 129, 127, 139] Arm [-, -, -]
  servo[0].write(139); // Thumb
  servo[1].write(142); // Index
  servo[2].write(129); // Middle
  servo[3].write(127); // Ring
  servo[4].write(139); // Pinky

  // Step 937: Fingers [138, 141, 129, 126, 138] Arm [-, -, -]
  servo[0].write(138); // Thumb
  servo[1].write(141); // Index
  servo[2].write(129); // Middle
  servo[3].write(126); // Ring
  servo[4].write(138); // Pinky

  delay(15);
  // Step 938: Fingers [138, 141, 129, 126, 138] Arm [-, -, -]
  servo[0].write(138); // Thumb
  servo[1].write(141); // Index
  servo[2].write(129); // Middle
  servo[3].write(126); // Ring
  servo[4].write(138); // Pinky

  // Step 939: Fingers [137, 140, 127, 125, 137] Arm [-, -, -]
  servo[0].write(137); // Thumb
  servo[1].write(140); // Index
  servo[2].write(127); // Middle
  servo[3].write(125); // Ring
  servo[4].write(137); // Pinky

  delay(11);
  // Step 940: Fingers [137, 139, 127, 124, 137] Arm [-, -, -]
  servo[0].write(137); // Thumb
  servo[1].write(139); // Index
  servo[2].write(127); // Middle
  servo[3].write(124); // Ring
  servo[4].write(137); // Pinky

  // Step 941: Fingers [136, 139, 126, 123, 136] Arm [-, -, -]
  servo[0].write(136); // Thumb
  servo[1].write(139); // Index
  servo[2].write(126); // Middle
  servo[3].write(123); // Ring
  servo[4].write(136); // Pinky

  // Step 942: Fingers [136, 139, 126, 123, 136] Arm [-, -, -]
  servo[0].write(136); // Thumb
  servo[1].write(139); // Index
  servo[2].write(126); // Middle
  servo[3].write(123); // Ring
  servo[4].write(136); // Pinky

  // Step 943: Fingers [135, 138, 125, 123, 135] Arm [-, -, -]
  servo[0].write(135); // Thumb
  servo[1].write(138); // Index
  servo[2].write(125); // Middle
  servo[3].write(123); // Ring
  servo[4].write(135); // Pinky

  // Step 944: Fingers [135, 137, 125, 122, 135] Arm [-, -, -]
  servo[0].write(135); // Thumb
  servo[1].write(137); // Index
  servo[2].write(125); // Middle
  servo[3].write(122); // Ring
  servo[4].write(135); // Pinky

  delay(16);
  // Step 945: Fingers [133, 136, 124, 121, 133] Arm [-, -, -]
  servo[0].write(133); // Thumb
  servo[1].write(136); // Index
  servo[2].write(124); // Middle
  servo[3].write(121); // Ring
  servo[4].write(133); // Pinky

  // Step 946: Fingers [133, 136, 124, 121, 133] Arm [-, -, -]
  servo[0].write(133); // Thumb
  servo[1].write(136); // Index
  servo[2].write(124); // Middle
  servo[3].write(121); // Ring
  servo[4].write(133); // Pinky

  // Step 947: Fingers [133, 135, 123, 120, 133] Arm [-, -, -]
  servo[0].write(133); // Thumb
  servo[1].write(135); // Index
  servo[2].write(123); // Middle
  servo[3].write(120); // Ring
  servo[4].write(133); // Pinky

  // Step 948: Fingers [132, 135, 122, 120, 132] Arm [-, -, -]
  servo[0].write(132); // Thumb
  servo[1].write(135); // Index
  servo[2].write(122); // Middle
  servo[3].write(120); // Ring
  servo[4].write(132); // Pinky

  // Step 949: Fingers [131, 134, 122, 119, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(134); // Index
  servo[2].write(122); // Middle
  servo[3].write(119); // Ring
  servo[4].write(131); // Pinky

  delay(14);
  // Step 950: Fingers [131, 134, 122, 119, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(134); // Index
  servo[2].write(122); // Middle
  servo[3].write(119); // Ring
  servo[4].write(131); // Pinky

  // Step 951: Fingers [131, 133, 121, 118, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(133); // Index
  servo[2].write(121); // Middle
  servo[3].write(118); // Ring
  servo[4].write(131); // Pinky

  // Step 952: Fingers [130, 133, 120, 118, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(133); // Index
  servo[2].write(120); // Middle
  servo[3].write(118); // Ring
  servo[4].write(130); // Pinky

  // Step 953: Fingers [129, 132, 120, 117, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(132); // Index
  servo[2].write(120); // Middle
  servo[3].write(117); // Ring
  servo[4].write(129); // Pinky

  delay(12);
  // Step 954: Fingers [129, 132, 120, 117, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(132); // Index
  servo[2].write(120); // Middle
  servo[3].write(117); // Ring
  servo[4].write(129); // Pinky

  // Step 955: Fingers [129, 132, 119, 116, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(132); // Index
  servo[2].write(119); // Middle
  servo[3].write(116); // Ring
  servo[4].write(129); // Pinky

  // Step 956: Fingers [128, 131, 118, 116, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(131); // Index
  servo[2].write(118); // Middle
  servo[3].write(116); // Ring
  servo[4].write(128); // Pinky

  // Step 957: Fingers [128, 130, 118, 115, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(130); // Index
  servo[2].write(118); // Middle
  servo[3].write(115); // Ring
  servo[4].write(128); // Pinky

  // Step 958: Fingers [126, 129, 117, 114, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(129); // Index
  servo[2].write(117); // Middle
  servo[3].write(114); // Ring
  servo[4].write(126); // Pinky

  // Step 959: Fingers [126, 129, 117, 114, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(129); // Index
  servo[2].write(117); // Middle
  servo[3].write(114); // Ring
  servo[4].write(126); // Pinky

  // Step 960: Fingers [125, 128, 115, 113, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(128); // Index
  servo[2].write(115); // Middle
  servo[3].write(113); // Ring
  servo[4].write(125); // Pinky

  // Step 961: Fingers [124, 127, 115, 112, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(127); // Index
  servo[2].write(115); // Middle
  servo[3].write(112); // Ring
  servo[4].write(124); // Pinky

  // Step 962: Fingers [124, 127, 114, 111, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(127); // Index
  servo[2].write(114); // Middle
  servo[3].write(111); // Ring
  servo[4].write(124); // Pinky

  // Step 963: Fingers [124, 127, 114, 111, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(127); // Index
  servo[2].write(114); // Middle
  servo[3].write(111); // Ring
  servo[4].write(124); // Pinky

  // Step 964: Fingers [122, 125, 113, 110, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(125); // Index
  servo[2].write(113); // Middle
  servo[3].write(110); // Ring
  servo[4].write(122); // Pinky

  // Step 965: Fingers [122, 125, 112, 109, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(125); // Index
  servo[2].write(112); // Middle
  servo[3].write(109); // Ring
  servo[4].write(122); // Pinky

  // Step 966: Fingers [121, 124, 112, 109, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(124); // Index
  servo[2].write(112); // Middle
  servo[3].write(109); // Ring
  servo[4].write(121); // Pinky

  // Step 967: Fingers [120, 123, 110, 107, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(123); // Index
  servo[2].write(110); // Middle
  servo[3].write(107); // Ring
  servo[4].write(120); // Pinky

  // Step 968: Fingers [120, 123, 110, 107, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(123); // Index
  servo[2].write(110); // Middle
  servo[3].write(107); // Ring
  servo[4].write(120); // Pinky

  // Step 969: Fingers [119, 122, 110, 107, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(122); // Index
  servo[2].write(110); // Middle
  servo[3].write(107); // Ring
  servo[4].write(119); // Pinky

  // Step 970: Fingers [118, 121, 109, 105, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(121); // Index
  servo[2].write(109); // Middle
  servo[3].write(105); // Ring
  servo[4].write(118); // Pinky

  delay(17);
  // Step 971: Fingers [118, 121, 109, 105, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(121); // Index
  servo[2].write(109); // Middle
  servo[3].write(105); // Ring
  servo[4].write(118); // Pinky

  delay(11);
  // Step 972: Fingers [117, 120, 108, 105, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(120); // Index
  servo[2].write(108); // Middle
  servo[3].write(105); // Ring
  servo[4].write(117); // Pinky

  // Step 973: Fingers [116, 120, 107, 104, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(120); // Index
  servo[2].write(107); // Middle
  servo[3].write(104); // Ring
  servo[4].write(116); // Pinky

  // Step 974: Fingers [116, 119, 107, 103, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(119); // Index
  servo[2].write(107); // Middle
  servo[3].write(103); // Ring
  servo[4].write(116); // Pinky

  // Step 975: Fingers [116, 119, 107, 103, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(119); // Index
  servo[2].write(107); // Middle
  servo[3].write(103); // Ring
  servo[4].write(116); // Pinky

  delay(17);
  // Step 976: Fingers [115, 118, 106, 103, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(118); // Index
  servo[2].write(106); // Middle
  servo[3].write(103); // Ring
  servo[4].write(115); // Pinky

  // Step 977: Fingers [115, 119, 106, 103, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(119); // Index
  servo[2].write(106); // Middle
  servo[3].write(103); // Ring
  servo[4].write(115); // Pinky

  // Step 978: Fingers [115, 119, 106, 103, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(119); // Index
  servo[2].write(106); // Middle
  servo[3].write(103); // Ring
  servo[4].write(115); // Pinky

  // Step 979: Fingers [114, 117, 105, 101, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(117); // Index
  servo[2].write(105); // Middle
  servo[3].write(101); // Ring
  servo[4].write(114); // Pinky

  // Step 980: Fingers [113, 117, 105, 101, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(117); // Index
  servo[2].write(105); // Middle
  servo[3].write(101); // Ring
  servo[4].write(113); // Pinky

  // Step 981: Fingers [111, 115, 103, 99, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(115); // Index
  servo[2].write(103); // Middle
  servo[3].write(99); // Ring
  servo[4].write(111); // Pinky

  // Step 982: Fingers [111, 115, 103, 99, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(115); // Index
  servo[2].write(103); // Middle
  servo[3].write(99); // Ring
  servo[4].write(111); // Pinky

  // Step 983: Fingers [110, 114, 102, 98, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(114); // Index
  servo[2].write(102); // Middle
  servo[3].write(98); // Ring
  servo[4].write(110); // Pinky

  // Step 984: Fingers [110, 114, 102, 98, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(114); // Index
  servo[2].write(102); // Middle
  servo[3].write(98); // Ring
  servo[4].write(110); // Pinky

  // Step 985: Fingers [109, 114, 102, 97, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(114); // Index
  servo[2].write(102); // Middle
  servo[3].write(97); // Ring
  servo[4].write(109); // Pinky

  // Step 986: Fingers [109, 114, 102, 97, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(114); // Index
  servo[2].write(102); // Middle
  servo[3].write(97); // Ring
  servo[4].write(109); // Pinky

  // Step 987: Fingers [109, 113, 101, 97, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(113); // Index
  servo[2].write(101); // Middle
  servo[3].write(97); // Ring
  servo[4].write(109); // Pinky

  delay(16);
  // Step 988: Fingers [107, 112, 100, 95, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(112); // Index
  servo[2].write(100); // Middle
  servo[3].write(95); // Ring
  servo[4].write(107); // Pinky

  // Step 989: Fingers [107, 112, 100, 95, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(112); // Index
  servo[2].write(100); // Middle
  servo[3].write(95); // Ring
  servo[4].write(107); // Pinky

  // Step 990: Fingers [107, 112, 100, 95, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(112); // Index
  servo[2].write(100); // Middle
  servo[3].write(95); // Ring
  servo[4].write(107); // Pinky

  // Step 991: Fingers [107, 111, 99, 95, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(111); // Index
  servo[2].write(99); // Middle
  servo[3].write(95); // Ring
  servo[4].write(107); // Pinky

  // Step 992: Fingers [106, 111, 99, 94, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(111); // Index
  servo[2].write(99); // Middle
  servo[3].write(94); // Ring
  servo[4].write(106); // Pinky

  // Step 993: Fingers [104, 109, 98, 93, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(109); // Index
  servo[2].write(98); // Middle
  servo[3].write(93); // Ring
  servo[4].write(104); // Pinky

  // Step 994: Fingers [104, 109, 98, 93, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(109); // Index
  servo[2].write(98); // Middle
  servo[3].write(93); // Ring
  servo[4].write(104); // Pinky

  // Step 995: Fingers [104, 109, 97, 92, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(109); // Index
  servo[2].write(97); // Middle
  servo[3].write(92); // Ring
  servo[4].write(104); // Pinky

  // Step 996: Fingers [103, 108, 96, 91, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(91); // Ring
  servo[4].write(103); // Pinky

  // Step 997: Fingers [102, 107, 96, 91, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(107); // Index
  servo[2].write(96); // Middle
  servo[3].write(91); // Ring
  servo[4].write(102); // Pinky

  // Step 998: Fingers [102, 107, 96, 91, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(107); // Index
  servo[2].write(96); // Middle
  servo[3].write(91); // Ring
  servo[4].write(102); // Pinky

  // Step 999: Fingers [102, 107, 95, 90, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(107); // Index
  servo[2].write(95); // Middle
  servo[3].write(90); // Ring
  servo[4].write(102); // Pinky

  // Step 1000: Fingers [101, 106, 95, 89, 101] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(106); // Index
  servo[2].write(95); // Middle
  servo[3].write(89); // Ring
  servo[4].write(101); // Pinky

  // Step 1001: Fingers [101, 106, 95, 89, 101] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(106); // Index
  servo[2].write(95); // Middle
  servo[3].write(89); // Ring
  servo[4].write(101); // Pinky

  // Step 1002: Fingers [100, 106, 94, 89, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(106); // Index
  servo[2].write(94); // Middle
  servo[3].write(89); // Ring
  servo[4].write(100); // Pinky

  // Step 1003: Fingers [100, 106, 94, 89, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(106); // Index
  servo[2].write(94); // Middle
  servo[3].write(89); // Ring
  servo[4].write(100); // Pinky

  // Step 1004: Fingers [99, 105, 94, 88, 99] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(105); // Index
  servo[2].write(94); // Middle
  servo[3].write(88); // Ring
  servo[4].write(99); // Pinky

  delay(20);
  // Step 1005: Fingers [99, 105, 94, 88, 99] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(105); // Index
  servo[2].write(94); // Middle
  servo[3].write(88); // Ring
  servo[4].write(99); // Pinky

  // Step 1006: Fingers [99, 104, 93, 87, 99] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(104); // Index
  servo[2].write(93); // Middle
  servo[3].write(87); // Ring
  servo[4].write(99); // Pinky

  delay(16);
  // Step 1007: Fingers [99, 104, 93, 87, 99] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(104); // Index
  servo[2].write(93); // Middle
  servo[3].write(87); // Ring
  servo[4].write(99); // Pinky

  // Step 1008: Fingers [99, 104, 93, 87, 99] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(104); // Index
  servo[2].write(93); // Middle
  servo[3].write(87); // Ring
  servo[4].write(99); // Pinky

  // Step 1009: Fingers [98, 104, 93, 87, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(104); // Index
  servo[2].write(93); // Middle
  servo[3].write(87); // Ring
  servo[4].write(98); // Pinky

  delay(13);
  // Step 1010: Fingers [97, 103, 92, 86, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(103); // Index
  servo[2].write(92); // Middle
  servo[3].write(86); // Ring
  servo[4].write(97); // Pinky

  // Step 1011: Fingers [97, 103, 92, 86, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(103); // Index
  servo[2].write(92); // Middle
  servo[3].write(86); // Ring
  servo[4].write(97); // Pinky

  // Step 1012: Fingers [97, 103, 91, 85, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(103); // Index
  servo[2].write(91); // Middle
  servo[3].write(85); // Ring
  servo[4].write(97); // Pinky

  // Step 1013: Fingers [96, 102, 91, 85, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(102); // Index
  servo[2].write(91); // Middle
  servo[3].write(85); // Ring
  servo[4].write(96); // Pinky

  // Step 1014: Fingers [95, 101, 90, 84, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(101); // Index
  servo[2].write(90); // Middle
  servo[3].write(84); // Ring
  servo[4].write(95); // Pinky

  // Step 1015: Fingers [94, 101, 90, 83, 94] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(101); // Index
  servo[2].write(90); // Middle
  servo[3].write(83); // Ring
  servo[4].write(94); // Pinky

  // Step 1016: Fingers [94, 101, 90, 83, 94] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(101); // Index
  servo[2].write(90); // Middle
  servo[3].write(83); // Ring
  servo[4].write(94); // Pinky

  // Step 1017: Fingers [94, 100, 89, 83, 94] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(100); // Index
  servo[2].write(89); // Middle
  servo[3].write(83); // Ring
  servo[4].write(94); // Pinky

  // Step 1018: Fingers [94, 100, 89, 83, 94] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(100); // Index
  servo[2].write(89); // Middle
  servo[3].write(83); // Ring
  servo[4].write(94); // Pinky

  // Step 1019: Fingers [93, 100, 89, 82, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(100); // Index
  servo[2].write(89); // Middle
  servo[3].write(82); // Ring
  servo[4].write(93); // Pinky

  // Step 1020: Fingers [93, 100, 89, 82, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(100); // Index
  servo[2].write(89); // Middle
  servo[3].write(82); // Ring
  servo[4].write(93); // Pinky

  delay(17);
  // Step 1021: Fingers [92, 99, 88, 81, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(99); // Index
  servo[2].write(88); // Middle
  servo[3].write(81); // Ring
  servo[4].write(92); // Pinky

  // Step 1022: Fingers [92, 99, 88, 81, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(99); // Index
  servo[2].write(88); // Middle
  servo[3].write(81); // Ring
  servo[4].write(92); // Pinky

  // Step 1023: Fingers [92, 99, 88, 81, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(99); // Index
  servo[2].write(88); // Middle
  servo[3].write(81); // Ring
  servo[4].write(92); // Pinky

  // Step 1024: Fingers [91, 98, 88, 81, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(98); // Index
  servo[2].write(88); // Middle
  servo[3].write(81); // Ring
  servo[4].write(91); // Pinky

  delay(11);
  // Step 1025: Fingers [91, 98, 87, 80, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(98); // Index
  servo[2].write(87); // Middle
  servo[3].write(80); // Ring
  servo[4].write(91); // Pinky

  // Step 1026: Fingers [91, 98, 87, 80, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(98); // Index
  servo[2].write(87); // Middle
  servo[3].write(80); // Ring
  servo[4].write(91); // Pinky

  // Step 1027: Fingers [90, 97, 86, 79, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(97); // Index
  servo[2].write(86); // Middle
  servo[3].write(79); // Ring
  servo[4].write(90); // Pinky

  delay(24);
  // Step 1028: Fingers [90, 97, 86, 79, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(97); // Index
  servo[2].write(86); // Middle
  servo[3].write(79); // Ring
  servo[4].write(90); // Pinky

  // Step 1029: Fingers [90, 97, 87, 79, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(97); // Index
  servo[2].write(87); // Middle
  servo[3].write(79); // Ring
  servo[4].write(90); // Pinky

  // Step 1030: Fingers [89, 96, 86, 79, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(96); // Index
  servo[2].write(86); // Middle
  servo[3].write(79); // Ring
  servo[4].write(89); // Pinky

  // Step 1031: Fingers [89, 97, 86, 79, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(97); // Index
  servo[2].write(86); // Middle
  servo[3].write(79); // Ring
  servo[4].write(89); // Pinky

  // Step 1032: Fingers [88, 96, 86, 78, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(86); // Middle
  servo[3].write(78); // Ring
  servo[4].write(88); // Pinky

  // Step 1033: Fingers [88, 96, 86, 78, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(86); // Middle
  servo[3].write(78); // Ring
  servo[4].write(88); // Pinky

  // Step 1034: Fingers [87, 95, 85, 77, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(95); // Index
  servo[2].write(85); // Middle
  servo[3].write(77); // Ring
  servo[4].write(87); // Pinky

  // Step 1035: Fingers [87, 95, 86, 77, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(95); // Index
  servo[2].write(86); // Middle
  servo[3].write(77); // Ring
  servo[4].write(87); // Pinky

  // Step 1036: Fingers [87, 95, 86, 77, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(95); // Index
  servo[2].write(86); // Middle
  servo[3].write(77); // Ring
  servo[4].write(87); // Pinky

  // Step 1037: Fingers [86, 95, 85, 77, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(95); // Index
  servo[2].write(85); // Middle
  servo[3].write(77); // Ring
  servo[4].write(86); // Pinky

  // Step 1038: Fingers [86, 95, 85, 77, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(95); // Index
  servo[2].write(85); // Middle
  servo[3].write(77); // Ring
  servo[4].write(86); // Pinky

  // Step 1039: Fingers [85, 94, 85, 76, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(94); // Index
  servo[2].write(85); // Middle
  servo[3].write(76); // Ring
  servo[4].write(85); // Pinky

  // Step 1040: Fingers [85, 94, 85, 76, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(94); // Index
  servo[2].write(85); // Middle
  servo[3].write(76); // Ring
  servo[4].write(85); // Pinky

  // Step 1041: Fingers [85, 94, 85, 76, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(94); // Index
  servo[2].write(85); // Middle
  servo[3].write(76); // Ring
  servo[4].write(85); // Pinky

  delay(14);
  // Step 1042: Fingers [85, 94, 85, 76, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(94); // Index
  servo[2].write(85); // Middle
  servo[3].write(76); // Ring
  servo[4].write(85); // Pinky

  delay(30);
  // Step 1043: Fingers [85, 94, 85, 76, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(94); // Index
  servo[2].write(85); // Middle
  servo[3].write(76); // Ring
  servo[4].write(85); // Pinky

  delay(30);
  // Step 1044: Fingers [85, 94, 85, 76, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(94); // Index
  servo[2].write(85); // Middle
  servo[3].write(76); // Ring
  servo[4].write(85); // Pinky

  delay(30);
  // Step 1045: Fingers [85, 94, 85, 76, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(94); // Index
  servo[2].write(85); // Middle
  servo[3].write(76); // Ring
  servo[4].write(85); // Pinky

  delay(31);
  // Step 1046: Fingers [85, 94, 85, 76, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(94); // Index
  servo[2].write(85); // Middle
  servo[3].write(76); // Ring
  servo[4].write(85); // Pinky

  delay(31);
  // Step 1047: Fingers [85, 94, 85, 76, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(94); // Index
  servo[2].write(85); // Middle
  servo[3].write(76); // Ring
  servo[4].write(85); // Pinky

  delay(14);
  // Step 1048: Fingers [85, 94, 85, 76, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(94); // Index
  servo[2].write(85); // Middle
  servo[3].write(76); // Ring
  servo[4].write(85); // Pinky

  // Step 1049: Fingers [84, 94, 86, 76, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(94); // Index
  servo[2].write(86); // Middle
  servo[3].write(76); // Ring
  servo[4].write(84); // Pinky

  // Step 1050: Fingers [84, 94, 86, 76, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(94); // Index
  servo[2].write(86); // Middle
  servo[3].write(76); // Ring
  servo[4].write(84); // Pinky

  // Step 1051: Fingers [84, 94, 86, 76, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(94); // Index
  servo[2].write(86); // Middle
  servo[3].write(76); // Ring
  servo[4].write(84); // Pinky

  // Step 1052: Fingers [84, 94, 86, 76, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(94); // Index
  servo[2].write(86); // Middle
  servo[3].write(76); // Ring
  servo[4].write(84); // Pinky

  // Step 1053: Fingers [84, 94, 86, 76, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(94); // Index
  servo[2].write(86); // Middle
  servo[3].write(76); // Ring
  servo[4].write(84); // Pinky

  // Step 1054: Fingers [83, 94, 87, 76, 83] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(94); // Index
  servo[2].write(87); // Middle
  servo[3].write(76); // Ring
  servo[4].write(83); // Pinky

  // Step 1055: Fingers [83, 94, 87, 76, 83] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(94); // Index
  servo[2].write(87); // Middle
  servo[3].write(76); // Ring
  servo[4].write(83); // Pinky

  // Step 1056: Fingers [83, 94, 87, 76, 83] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(94); // Index
  servo[2].write(87); // Middle
  servo[3].write(76); // Ring
  servo[4].write(83); // Pinky

  // Step 1057: Fingers [84, 94, 88, 77, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(94); // Index
  servo[2].write(88); // Middle
  servo[3].write(77); // Ring
  servo[4].write(84); // Pinky

  // Step 1058: Fingers [83, 94, 88, 77, 83] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(94); // Index
  servo[2].write(88); // Middle
  servo[3].write(77); // Ring
  servo[4].write(83); // Pinky

  // Step 1059: Fingers [84, 95, 89, 78, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(95); // Index
  servo[2].write(89); // Middle
  servo[3].write(78); // Ring
  servo[4].write(84); // Pinky

  // Step 1060: Fingers [84, 95, 89, 78, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(95); // Index
  servo[2].write(89); // Middle
  servo[3].write(78); // Ring
  servo[4].write(84); // Pinky

  // Step 1061: Fingers [84, 95, 89, 78, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(95); // Index
  servo[2].write(89); // Middle
  servo[3].write(78); // Ring
  servo[4].write(84); // Pinky

  // Step 1062: Fingers [84, 96, 90, 78, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(96); // Index
  servo[2].write(90); // Middle
  servo[3].write(78); // Ring
  servo[4].write(84); // Pinky

  // Step 1063: Fingers [84, 95, 90, 78, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(95); // Index
  servo[2].write(90); // Middle
  servo[3].write(78); // Ring
  servo[4].write(84); // Pinky

  // Step 1064: Fingers [84, 95, 90, 78, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(95); // Index
  servo[2].write(90); // Middle
  servo[3].write(78); // Ring
  servo[4].write(84); // Pinky

  // Step 1065: Fingers [85, 96, 91, 79, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(96); // Index
  servo[2].write(91); // Middle
  servo[3].write(79); // Ring
  servo[4].write(85); // Pinky

  delay(13);
  // Step 1066: Fingers [86, 97, 92, 80, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(97); // Index
  servo[2].write(92); // Middle
  servo[3].write(80); // Ring
  servo[4].write(86); // Pinky

  // Step 1067: Fingers [86, 97, 92, 80, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(97); // Index
  servo[2].write(92); // Middle
  servo[3].write(80); // Ring
  servo[4].write(86); // Pinky

  // Step 1068: Fingers [86, 98, 93, 81, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(98); // Index
  servo[2].write(93); // Middle
  servo[3].write(81); // Ring
  servo[4].write(86); // Pinky

  // Step 1069: Fingers [86, 98, 93, 81, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(98); // Index
  servo[2].write(93); // Middle
  servo[3].write(81); // Ring
  servo[4].write(86); // Pinky

  // Step 1070: Fingers [87, 98, 94, 82, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(98); // Index
  servo[2].write(94); // Middle
  servo[3].write(82); // Ring
  servo[4].write(87); // Pinky

  // Step 1071: Fingers [87, 98, 94, 82, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(98); // Index
  servo[2].write(94); // Middle
  servo[3].write(82); // Ring
  servo[4].write(87); // Pinky

  // Step 1072: Fingers [86, 98, 94, 82, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(98); // Index
  servo[2].write(94); // Middle
  servo[3].write(82); // Ring
  servo[4].write(86); // Pinky

  // Step 1073: Fingers [88, 100, 95, 83, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(100); // Index
  servo[2].write(95); // Middle
  servo[3].write(83); // Ring
  servo[4].write(88); // Pinky

  // Step 1074: Fingers [87, 99, 95, 83, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(99); // Index
  servo[2].write(95); // Middle
  servo[3].write(83); // Ring
  servo[4].write(87); // Pinky

  delay(15);
  // Step 1075: Fingers [87, 99, 95, 83, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(99); // Index
  servo[2].write(95); // Middle
  servo[3].write(83); // Ring
  servo[4].write(87); // Pinky

  // Step 1076: Fingers [88, 100, 96, 84, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(100); // Index
  servo[2].write(96); // Middle
  servo[3].write(84); // Ring
  servo[4].write(88); // Pinky

  // Step 1077: Fingers [89, 101, 97, 85, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(101); // Index
  servo[2].write(97); // Middle
  servo[3].write(85); // Ring
  servo[4].write(89); // Pinky

  delay(16);
  // Step 1078: Fingers [89, 101, 98, 85, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(101); // Index
  servo[2].write(98); // Middle
  servo[3].write(85); // Ring
  servo[4].write(89); // Pinky

  // Step 1079: Fingers [89, 101, 98, 85, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(101); // Index
  servo[2].write(98); // Middle
  servo[3].write(85); // Ring
  servo[4].write(89); // Pinky

  // Step 1080: Fingers [90, 102, 99, 87, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(102); // Index
  servo[2].write(99); // Middle
  servo[3].write(87); // Ring
  servo[4].write(90); // Pinky

  // Step 1081: Fingers [90, 102, 99, 87, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(102); // Index
  servo[2].write(99); // Middle
  servo[3].write(87); // Ring
  servo[4].write(90); // Pinky

  // Step 1082: Fingers [91, 103, 100, 88, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(103); // Index
  servo[2].write(100); // Middle
  servo[3].write(88); // Ring
  servo[4].write(91); // Pinky

  // Step 1083: Fingers [91, 103, 100, 88, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(103); // Index
  servo[2].write(100); // Middle
  servo[3].write(88); // Ring
  servo[4].write(91); // Pinky

  // Step 1084: Fingers [91, 104, 101, 88, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(104); // Index
  servo[2].write(101); // Middle
  servo[3].write(88); // Ring
  servo[4].write(91); // Pinky

  // Step 1085: Fingers [92, 105, 102, 90, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(105); // Index
  servo[2].write(102); // Middle
  servo[3].write(90); // Ring
  servo[4].write(92); // Pinky

  // Step 1086: Fingers [92, 105, 102, 90, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(105); // Index
  servo[2].write(102); // Middle
  servo[3].write(90); // Ring
  servo[4].write(92); // Pinky

  // Step 1087: Fingers [93, 106, 104, 91, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(106); // Index
  servo[2].write(104); // Middle
  servo[3].write(91); // Ring
  servo[4].write(93); // Pinky

  // Step 1088: Fingers [93, 106, 104, 91, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(106); // Index
  servo[2].write(104); // Middle
  servo[3].write(91); // Ring
  servo[4].write(93); // Pinky

  // Step 1089: Fingers [94, 106, 104, 92, 94] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(106); // Index
  servo[2].write(104); // Middle
  servo[3].write(92); // Ring
  servo[4].write(94); // Pinky

  // Step 1090: Fingers [95, 108, 106, 93, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(108); // Index
  servo[2].write(106); // Middle
  servo[3].write(93); // Ring
  servo[4].write(95); // Pinky

  // Step 1091: Fingers [95, 108, 106, 93, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(108); // Index
  servo[2].write(106); // Middle
  servo[3].write(93); // Ring
  servo[4].write(95); // Pinky

  // Step 1092: Fingers [95, 108, 106, 93, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(108); // Index
  servo[2].write(106); // Middle
  servo[3].write(93); // Ring
  servo[4].write(95); // Pinky

  // Step 1093: Fingers [96, 108, 106, 94, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(108); // Index
  servo[2].write(106); // Middle
  servo[3].write(94); // Ring
  servo[4].write(96); // Pinky

  // Step 1094: Fingers [96, 109, 107, 94, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(109); // Index
  servo[2].write(107); // Middle
  servo[3].write(94); // Ring
  servo[4].write(96); // Pinky

  // Step 1095: Fingers [96, 109, 107, 94, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(109); // Index
  servo[2].write(107); // Middle
  servo[3].write(94); // Ring
  servo[4].write(96); // Pinky

  // Step 1096: Fingers [97, 109, 108, 95, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(109); // Index
  servo[2].write(108); // Middle
  servo[3].write(95); // Ring
  servo[4].write(97); // Pinky

  // Step 1097: Fingers [97, 110, 108, 96, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(110); // Index
  servo[2].write(108); // Middle
  servo[3].write(96); // Ring
  servo[4].write(97); // Pinky

  // Step 1098: Fingers [98, 111, 109, 97, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(111); // Index
  servo[2].write(109); // Middle
  servo[3].write(97); // Ring
  servo[4].write(98); // Pinky

  // Step 1099: Fingers [98, 111, 110, 97, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(111); // Index
  servo[2].write(110); // Middle
  servo[3].write(97); // Ring
  servo[4].write(98); // Pinky

  // Step 1100: Fingers [98, 111, 110, 97, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(111); // Index
  servo[2].write(110); // Middle
  servo[3].write(97); // Ring
  servo[4].write(98); // Pinky

  // Step 1101: Fingers [99, 112, 111, 98, 99] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(112); // Index
  servo[2].write(111); // Middle
  servo[3].write(98); // Ring
  servo[4].write(99); // Pinky

  // Step 1102: Fingers [100, 112, 111, 99, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(112); // Index
  servo[2].write(111); // Middle
  servo[3].write(99); // Ring
  servo[4].write(100); // Pinky

  // Step 1103: Fingers [102, 114, 113, 101, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(114); // Index
  servo[2].write(113); // Middle
  servo[3].write(101); // Ring
  servo[4].write(102); // Pinky

  // Step 1104: Fingers [102, 115, 114, 101, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(115); // Index
  servo[2].write(114); // Middle
  servo[3].write(101); // Ring
  servo[4].write(102); // Pinky

  // Step 1105: Fingers [102, 115, 114, 101, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(115); // Index
  servo[2].write(114); // Middle
  servo[3].write(101); // Ring
  servo[4].write(102); // Pinky

  // Step 1106: Fingers [103, 115, 115, 102, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(115); // Index
  servo[2].write(115); // Middle
  servo[3].write(102); // Ring
  servo[4].write(103); // Pinky

  // Step 1107: Fingers [103, 116, 115, 102, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(116); // Index
  servo[2].write(115); // Middle
  servo[3].write(102); // Ring
  servo[4].write(103); // Pinky

  // Step 1108: Fingers [105, 117, 117, 104, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(117); // Index
  servo[2].write(117); // Middle
  servo[3].write(104); // Ring
  servo[4].write(105); // Pinky

  delay(14);
  // Step 1109: Fingers [105, 117, 117, 104, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(117); // Index
  servo[2].write(117); // Middle
  servo[3].write(104); // Ring
  servo[4].write(105); // Pinky

  // Step 1110: Fingers [106, 119, 118, 105, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(119); // Index
  servo[2].write(118); // Middle
  servo[3].write(105); // Ring
  servo[4].write(106); // Pinky

  // Step 1111: Fingers [106, 119, 118, 106, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(119); // Index
  servo[2].write(118); // Middle
  servo[3].write(106); // Ring
  servo[4].write(106); // Pinky

  // Step 1112: Fingers [108, 120, 120, 107, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(120); // Index
  servo[2].write(120); // Middle
  servo[3].write(107); // Ring
  servo[4].write(108); // Pinky

  // Step 1113: Fingers [108, 120, 120, 107, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(120); // Index
  servo[2].write(120); // Middle
  servo[3].write(107); // Ring
  servo[4].write(108); // Pinky

  // Step 1114: Fingers [108, 121, 120, 108, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(121); // Index
  servo[2].write(120); // Middle
  servo[3].write(108); // Ring
  servo[4].write(108); // Pinky

  // Step 1115: Fingers [109, 122, 121, 108, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(122); // Index
  servo[2].write(121); // Middle
  servo[3].write(108); // Ring
  servo[4].write(109); // Pinky

  // Step 1116: Fingers [109, 122, 121, 108, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(122); // Index
  servo[2].write(121); // Middle
  servo[3].write(108); // Ring
  servo[4].write(109); // Pinky

  // Step 1117: Fingers [110, 122, 122, 109, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(122); // Index
  servo[2].write(122); // Middle
  servo[3].write(109); // Ring
  servo[4].write(110); // Pinky

  // Step 1118: Fingers [111, 124, 123, 110, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(124); // Index
  servo[2].write(123); // Middle
  servo[3].write(110); // Ring
  servo[4].write(111); // Pinky

  // Step 1119: Fingers [112, 124, 124, 111, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(124); // Index
  servo[2].write(124); // Middle
  servo[3].write(111); // Ring
  servo[4].write(112); // Pinky

  // Step 1120: Fingers [113, 126, 125, 112, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(126); // Index
  servo[2].write(125); // Middle
  servo[3].write(112); // Ring
  servo[4].write(113); // Pinky

  // Step 1121: Fingers [113, 126, 125, 112, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(126); // Index
  servo[2].write(125); // Middle
  servo[3].write(112); // Ring
  servo[4].write(113); // Pinky

  // Step 1122: Fingers [113, 126, 126, 113, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(126); // Index
  servo[2].write(126); // Middle
  servo[3].write(113); // Ring
  servo[4].write(113); // Pinky

  // Step 1123: Fingers [115, 127, 127, 114, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(127); // Index
  servo[2].write(127); // Middle
  servo[3].write(114); // Ring
  servo[4].write(115); // Pinky

  // Step 1124: Fingers [115, 128, 127, 115, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(128); // Index
  servo[2].write(127); // Middle
  servo[3].write(115); // Ring
  servo[4].write(115); // Pinky

  // Step 1125: Fingers [116, 129, 128, 115, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(129); // Index
  servo[2].write(128); // Middle
  servo[3].write(115); // Ring
  servo[4].write(116); // Pinky

  // Step 1126: Fingers [116, 129, 128, 115, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(129); // Index
  servo[2].write(128); // Middle
  servo[3].write(115); // Ring
  servo[4].write(116); // Pinky

  // Step 1127: Fingers [117, 130, 129, 116, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(130); // Index
  servo[2].write(129); // Middle
  servo[3].write(116); // Ring
  servo[4].write(117); // Pinky

  // Step 1128: Fingers [118, 131, 130, 117, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(131); // Index
  servo[2].write(130); // Middle
  servo[3].write(117); // Ring
  servo[4].write(118); // Pinky

  // Step 1129: Fingers [119, 132, 130, 118, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(132); // Index
  servo[2].write(130); // Middle
  servo[3].write(118); // Ring
  servo[4].write(119); // Pinky

  // Step 1130: Fingers [120, 132, 131, 118, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(132); // Index
  servo[2].write(131); // Middle
  servo[3].write(118); // Ring
  servo[4].write(120); // Pinky

  // Step 1131: Fingers [120, 132, 131, 118, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(132); // Index
  servo[2].write(131); // Middle
  servo[3].write(118); // Ring
  servo[4].write(120); // Pinky

  // Step 1132: Fingers [120, 133, 132, 119, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(133); // Index
  servo[2].write(132); // Middle
  servo[3].write(119); // Ring
  servo[4].write(120); // Pinky

  // Step 1133: Fingers [121, 133, 132, 120, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(133); // Index
  servo[2].write(132); // Middle
  servo[3].write(120); // Ring
  servo[4].write(121); // Pinky

  // Step 1134: Fingers [122, 135, 133, 121, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(135); // Index
  servo[2].write(133); // Middle
  servo[3].write(121); // Ring
  servo[4].write(122); // Pinky

  // Step 1135: Fingers [122, 135, 133, 121, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(135); // Index
  servo[2].write(133); // Middle
  servo[3].write(121); // Ring
  servo[4].write(122); // Pinky

  // Step 1136: Fingers [123, 136, 134, 121, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(136); // Index
  servo[2].write(134); // Middle
  servo[3].write(121); // Ring
  servo[4].write(123); // Pinky

  // Step 1137: Fingers [124, 136, 134, 122, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(136); // Index
  servo[2].write(134); // Middle
  servo[3].write(122); // Ring
  servo[4].write(124); // Pinky

  // Step 1138: Fingers [125, 138, 136, 123, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(138); // Index
  servo[2].write(136); // Middle
  servo[3].write(123); // Ring
  servo[4].write(125); // Pinky

  // Step 1139: Fingers [127, 140, 137, 125, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(140); // Index
  servo[2].write(137); // Middle
  servo[3].write(125); // Ring
  servo[4].write(127); // Pinky

  // Step 1140: Fingers [127, 140, 137, 125, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(140); // Index
  servo[2].write(137); // Middle
  servo[3].write(125); // Ring
  servo[4].write(127); // Pinky

  // Step 1141: Fingers [129, 141, 138, 126, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(141); // Index
  servo[2].write(138); // Middle
  servo[3].write(126); // Ring
  servo[4].write(129); // Pinky

  // Step 1142: Fingers [130, 142, 140, 127, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(142); // Index
  servo[2].write(140); // Middle
  servo[3].write(127); // Ring
  servo[4].write(130); // Pinky

  // Step 1143: Fingers [132, 144, 141, 128, 132] Arm [-, -, -]
  servo[0].write(132); // Thumb
  servo[1].write(144); // Index
  servo[2].write(141); // Middle
  servo[3].write(128); // Ring
  servo[4].write(132); // Pinky

  // Step 1144: Fingers [133, 145, 142, 129, 133] Arm [-, -, -]
  servo[0].write(133); // Thumb
  servo[1].write(145); // Index
  servo[2].write(142); // Middle
  servo[3].write(129); // Ring
  servo[4].write(133); // Pinky

  // Step 1145: Fingers [133, 145, 142, 129, 133] Arm [-, -, -]
  servo[0].write(133); // Thumb
  servo[1].write(145); // Index
  servo[2].write(142); // Middle
  servo[3].write(129); // Ring
  servo[4].write(133); // Pinky

  // Step 1146: Fingers [134, 146, 142, 130, 134] Arm [-, -, -]
  servo[0].write(134); // Thumb
  servo[1].write(146); // Index
  servo[2].write(142); // Middle
  servo[3].write(130); // Ring
  servo[4].write(134); // Pinky

  // Step 1147: Fingers [135, 147, 143, 131, 135] Arm [-, -, -]
  servo[0].write(135); // Thumb
  servo[1].write(147); // Index
  servo[2].write(143); // Middle
  servo[3].write(131); // Ring
  servo[4].write(135); // Pinky

  // Step 1148: Fingers [136, 148, 144, 132, 136] Arm [-, -, -]
  servo[0].write(136); // Thumb
  servo[1].write(148); // Index
  servo[2].write(144); // Middle
  servo[3].write(132); // Ring
  servo[4].write(136); // Pinky

  // Step 1149: Fingers [137, 149, 144, 132, 137] Arm [-, -, -]
  servo[0].write(137); // Thumb
  servo[1].write(149); // Index
  servo[2].write(144); // Middle
  servo[3].write(132); // Ring
  servo[4].write(137); // Pinky

  // Step 1150: Fingers [137, 149, 144, 132, 137] Arm [-, -, -]
  servo[0].write(137); // Thumb
  servo[1].write(149); // Index
  servo[2].write(144); // Middle
  servo[3].write(132); // Ring
  servo[4].write(137); // Pinky

  // Step 1151: Fingers [138, 150, 144, 133, 138] Arm [-, -, -]
  servo[0].write(138); // Thumb
  servo[1].write(150); // Index
  servo[2].write(144); // Middle
  servo[3].write(133); // Ring
  servo[4].write(138); // Pinky

  // Step 1152: Fingers [139, 150, 145, 133, 139] Arm [-, -, -]
  servo[0].write(139); // Thumb
  servo[1].write(150); // Index
  servo[2].write(145); // Middle
  servo[3].write(133); // Ring
  servo[4].write(139); // Pinky

  // Step 1153: Fingers [139, 150, 145, 133, 139] Arm [-, -, -]
  servo[0].write(139); // Thumb
  servo[1].write(150); // Index
  servo[2].write(145); // Middle
  servo[3].write(133); // Ring
  servo[4].write(139); // Pinky

  // Step 1154: Fingers [140, 151, 145, 134, 140] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(151); // Index
  servo[2].write(145); // Middle
  servo[3].write(134); // Ring
  servo[4].write(140); // Pinky

  // Step 1155: Fingers [140, 151, 145, 134, 140] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(151); // Index
  servo[2].write(145); // Middle
  servo[3].write(134); // Ring
  servo[4].write(140); // Pinky

  // Step 1156: Fingers [140, 151, 145, 134, 140] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(151); // Index
  servo[2].write(145); // Middle
  servo[3].write(134); // Ring
  servo[4].write(140); // Pinky

  // Step 1157: Fingers [141, 152, 146, 134, 141] Arm [-, -, -]
  servo[0].write(141); // Thumb
  servo[1].write(152); // Index
  servo[2].write(146); // Middle
  servo[3].write(134); // Ring
  servo[4].write(141); // Pinky

  // Step 1158: Fingers [141, 152, 146, 135, 141] Arm [-, -, -]
  servo[0].write(141); // Thumb
  servo[1].write(152); // Index
  servo[2].write(146); // Middle
  servo[3].write(135); // Ring
  servo[4].write(141); // Pinky

  // Step 1159: Fingers [142, 152, 146, 135, 142] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(152); // Index
  servo[2].write(146); // Middle
  servo[3].write(135); // Ring
  servo[4].write(142); // Pinky

  // Step 1160: Fingers [142, 152, 146, 135, 142] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(152); // Index
  servo[2].write(146); // Middle
  servo[3].write(135); // Ring
  servo[4].write(142); // Pinky

  // Step 1161: Fingers [142, 153, 146, 135, 142] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(153); // Index
  servo[2].write(146); // Middle
  servo[3].write(135); // Ring
  servo[4].write(142); // Pinky

  delay(18);
  // Step 1162: Fingers [143, 153, 146, 136, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(153); // Index
  servo[2].write(146); // Middle
  servo[3].write(136); // Ring
  servo[4].write(143); // Pinky

  // Step 1163: Fingers [143, 153, 146, 136, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(153); // Index
  servo[2].write(146); // Middle
  servo[3].write(136); // Ring
  servo[4].write(143); // Pinky

  delay(17);
  // Step 1164: Fingers [143, 153, 146, 136, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(153); // Index
  servo[2].write(146); // Middle
  servo[3].write(136); // Ring
  servo[4].write(143); // Pinky

  delay(13);
  // Step 1165: Fingers [143, 153, 146, 136, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(153); // Index
  servo[2].write(146); // Middle
  servo[3].write(136); // Ring
  servo[4].write(143); // Pinky

  // Step 1166: Fingers [143, 153, 146, 135, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(153); // Index
  servo[2].write(146); // Middle
  servo[3].write(135); // Ring
  servo[4].write(143); // Pinky

  // Step 1167: Fingers [143, 153, 146, 135, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(153); // Index
  servo[2].write(146); // Middle
  servo[3].write(135); // Ring
  servo[4].write(143); // Pinky

  delay(16);
  // Step 1168: Fingers [143, 153, 146, 135, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(153); // Index
  servo[2].write(146); // Middle
  servo[3].write(135); // Ring
  servo[4].write(143); // Pinky

  // Step 1169: Fingers [143, 153, 145, 135, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(153); // Index
  servo[2].write(145); // Middle
  servo[3].write(135); // Ring
  servo[4].write(143); // Pinky

  // Step 1170: Fingers [144, 153, 145, 135, 144] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(153); // Index
  servo[2].write(145); // Middle
  servo[3].write(135); // Ring
  servo[4].write(144); // Pinky

  // Step 1171: Fingers [144, 153, 145, 135, 144] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(153); // Index
  servo[2].write(145); // Middle
  servo[3].write(135); // Ring
  servo[4].write(144); // Pinky

  // Step 1172: Fingers [144, 153, 144, 135, 144] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(153); // Index
  servo[2].write(144); // Middle
  servo[3].write(135); // Ring
  servo[4].write(144); // Pinky

  // Step 1173: Fingers [144, 153, 144, 135, 144] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(153); // Index
  servo[2].write(144); // Middle
  servo[3].write(135); // Ring
  servo[4].write(144); // Pinky

  // Step 1174: Fingers [143, 152, 143, 134, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(152); // Index
  servo[2].write(143); // Middle
  servo[3].write(134); // Ring
  servo[4].write(143); // Pinky

  // Step 1175: Fingers [144, 152, 142, 134, 144] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(152); // Index
  servo[2].write(142); // Middle
  servo[3].write(134); // Ring
  servo[4].write(144); // Pinky

  // Step 1176: Fingers [143, 151, 141, 133, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(151); // Index
  servo[2].write(141); // Middle
  servo[3].write(133); // Ring
  servo[4].write(143); // Pinky

  // Step 1177: Fingers [143, 150, 140, 132, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(150); // Index
  servo[2].write(140); // Middle
  servo[3].write(132); // Ring
  servo[4].write(143); // Pinky

  // Step 1178: Fingers [143, 150, 140, 132, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(150); // Index
  servo[2].write(140); // Middle
  servo[3].write(132); // Ring
  servo[4].write(143); // Pinky

  // Step 1179: Fingers [143, 150, 139, 132, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(150); // Index
  servo[2].write(139); // Middle
  servo[3].write(132); // Ring
  servo[4].write(143); // Pinky

  // Step 1180: Fingers [144, 150, 139, 133, 144] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(150); // Index
  servo[2].write(139); // Middle
  servo[3].write(133); // Ring
  servo[4].write(144); // Pinky

  // Step 1181: Fingers [143, 148, 137, 131, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(148); // Index
  servo[2].write(137); // Middle
  servo[3].write(131); // Ring
  servo[4].write(143); // Pinky

  // Step 1182: Fingers [143, 148, 137, 131, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(148); // Index
  servo[2].write(137); // Middle
  servo[3].write(131); // Ring
  servo[4].write(143); // Pinky

  // Step 1183: Fingers [143, 148, 137, 131, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(148); // Index
  servo[2].write(137); // Middle
  servo[3].write(131); // Ring
  servo[4].write(143); // Pinky

  // Step 1184: Fingers [143, 148, 136, 131, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(148); // Index
  servo[2].write(136); // Middle
  servo[3].write(131); // Ring
  servo[4].write(143); // Pinky

  // Step 1185: Fingers [143, 147, 135, 131, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(147); // Index
  servo[2].write(135); // Middle
  servo[3].write(131); // Ring
  servo[4].write(143); // Pinky

  // Step 1186: Fingers [143, 147, 135, 131, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(147); // Index
  servo[2].write(135); // Middle
  servo[3].write(131); // Ring
  servo[4].write(143); // Pinky

  // Step 1187: Fingers [143, 146, 134, 131, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(146); // Index
  servo[2].write(134); // Middle
  servo[3].write(131); // Ring
  servo[4].write(143); // Pinky

  // Step 1188: Fingers [143, 146, 134, 131, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(146); // Index
  servo[2].write(134); // Middle
  servo[3].write(131); // Ring
  servo[4].write(143); // Pinky

  // Step 1189: Fingers [143, 146, 133, 130, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(146); // Index
  servo[2].write(133); // Middle
  servo[3].write(130); // Ring
  servo[4].write(143); // Pinky

  // Step 1190: Fingers [143, 146, 133, 130, 143] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(146); // Index
  servo[2].write(133); // Middle
  servo[3].write(130); // Ring
  servo[4].write(143); // Pinky

  // Step 1191: Fingers [142, 145, 132, 130, 142] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(145); // Index
  servo[2].write(132); // Middle
  servo[3].write(130); // Ring
  servo[4].write(142); // Pinky

  // Step 1192: Fingers [142, 144, 132, 129, 142] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(144); // Index
  servo[2].write(132); // Middle
  servo[3].write(129); // Ring
  servo[4].write(142); // Pinky

  // Step 1193: Fingers [142, 144, 132, 129, 142] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(144); // Index
  servo[2].write(132); // Middle
  servo[3].write(129); // Ring
  servo[4].write(142); // Pinky

  // Step 1194: Fingers [141, 144, 131, 129, 141] Arm [-, -, -]
  servo[0].write(141); // Thumb
  servo[1].write(144); // Index
  servo[2].write(131); // Middle
  servo[3].write(129); // Ring
  servo[4].write(141); // Pinky

  // Step 1195: Fingers [141, 143, 130, 128, 141] Arm [-, -, -]
  servo[0].write(141); // Thumb
  servo[1].write(143); // Index
  servo[2].write(130); // Middle
  servo[3].write(128); // Ring
  servo[4].write(141); // Pinky

  // Step 1196: Fingers [141, 143, 130, 128, 141] Arm [-, -, -]
  servo[0].write(141); // Thumb
  servo[1].write(143); // Index
  servo[2].write(130); // Middle
  servo[3].write(128); // Ring
  servo[4].write(141); // Pinky

  // Step 1197: Fingers [141, 143, 130, 128, 141] Arm [-, -, -]
  servo[0].write(141); // Thumb
  servo[1].write(143); // Index
  servo[2].write(130); // Middle
  servo[3].write(128); // Ring
  servo[4].write(141); // Pinky

  // Step 1198: Fingers [140, 141, 129, 127, 140] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(141); // Index
  servo[2].write(129); // Middle
  servo[3].write(127); // Ring
  servo[4].write(140); // Pinky

  // Step 1199: Fingers [138, 140, 128, 126, 138] Arm [-, -, -]
  servo[0].write(138); // Thumb
  servo[1].write(140); // Index
  servo[2].write(128); // Middle
  servo[3].write(126); // Ring
  servo[4].write(138); // Pinky

  // Step 1200: Fingers [137, 139, 126, 125, 137] Arm [-, -, -]
  servo[0].write(137); // Thumb
  servo[1].write(139); // Index
  servo[2].write(126); // Middle
  servo[3].write(125); // Ring
  servo[4].write(137); // Pinky

  // Step 1201: Fingers [137, 138, 125, 124, 137] Arm [-, -, -]
  servo[0].write(137); // Thumb
  servo[1].write(138); // Index
  servo[2].write(125); // Middle
  servo[3].write(124); // Ring
  servo[4].write(137); // Pinky

  // Step 1202: Fingers [137, 138, 125, 124, 137] Arm [-, -, -]
  servo[0].write(137); // Thumb
  servo[1].write(138); // Index
  servo[2].write(125); // Middle
  servo[3].write(124); // Ring
  servo[4].write(137); // Pinky

  // Step 1203: Fingers [135, 137, 124, 123, 135] Arm [-, -, -]
  servo[0].write(135); // Thumb
  servo[1].write(137); // Index
  servo[2].write(124); // Middle
  servo[3].write(123); // Ring
  servo[4].write(135); // Pinky

  // Step 1204: Fingers [134, 135, 123, 122, 134] Arm [-, -, -]
  servo[0].write(134); // Thumb
  servo[1].write(135); // Index
  servo[2].write(123); // Middle
  servo[3].write(122); // Ring
  servo[4].write(134); // Pinky

  // Step 1205: Fingers [134, 134, 122, 121, 134] Arm [-, -, -]
  servo[0].write(134); // Thumb
  servo[1].write(134); // Index
  servo[2].write(122); // Middle
  servo[3].write(121); // Ring
  servo[4].write(134); // Pinky

  // Step 1206: Fingers [133, 133, 120, 120, 133] Arm [-, -, -]
  servo[0].write(133); // Thumb
  servo[1].write(133); // Index
  servo[2].write(120); // Middle
  servo[3].write(120); // Ring
  servo[4].write(133); // Pinky

  // Step 1207: Fingers [133, 133, 120, 120, 133] Arm [-, -, -]
  servo[0].write(133); // Thumb
  servo[1].write(133); // Index
  servo[2].write(120); // Middle
  servo[3].write(120); // Ring
  servo[4].write(133); // Pinky

  // Step 1208: Fingers [131, 132, 119, 119, 131] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(132); // Index
  servo[2].write(119); // Middle
  servo[3].write(119); // Ring
  servo[4].write(131); // Pinky

  // Step 1209: Fingers [130, 131, 118, 117, 130] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(131); // Index
  servo[2].write(118); // Middle
  servo[3].write(117); // Ring
  servo[4].write(130); // Pinky

  // Step 1210: Fingers [129, 130, 117, 117, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(130); // Index
  servo[2].write(117); // Middle
  servo[3].write(117); // Ring
  servo[4].write(129); // Pinky

  // Step 1211: Fingers [129, 130, 117, 117, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(130); // Index
  servo[2].write(117); // Middle
  servo[3].write(117); // Ring
  servo[4].write(129); // Pinky

  // Step 1212: Fingers [129, 129, 116, 116, 129] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(129); // Index
  servo[2].write(116); // Middle
  servo[3].write(116); // Ring
  servo[4].write(129); // Pinky

  // Step 1213: Fingers [128, 128, 116, 116, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(128); // Index
  servo[2].write(116); // Middle
  servo[3].write(116); // Ring
  servo[4].write(128); // Pinky

  // Step 1214: Fingers [128, 128, 115, 115, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(128); // Index
  servo[2].write(115); // Middle
  servo[3].write(115); // Ring
  servo[4].write(128); // Pinky

  // Step 1215: Fingers [128, 128, 115, 115, 128] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(128); // Index
  servo[2].write(115); // Middle
  servo[3].write(115); // Ring
  servo[4].write(128); // Pinky

  // Step 1216: Fingers [126, 127, 114, 114, 126] Arm [-, -, -]
  servo[0].write(126); // Thumb
  servo[1].write(127); // Index
  servo[2].write(114); // Middle
  servo[3].write(114); // Ring
  servo[4].write(126); // Pinky

  // Step 1217: Fingers [127, 126, 114, 114, 127] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(126); // Index
  servo[2].write(114); // Middle
  servo[3].write(114); // Ring
  servo[4].write(127); // Pinky

  // Step 1218: Fingers [125, 125, 112, 113, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(125); // Index
  servo[2].write(112); // Middle
  servo[3].write(113); // Ring
  servo[4].write(125); // Pinky

  // Step 1219: Fingers [125, 124, 112, 112, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(124); // Index
  servo[2].write(112); // Middle
  servo[3].write(112); // Ring
  servo[4].write(125); // Pinky

  // Step 1220: Fingers [125, 124, 112, 112, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(124); // Index
  servo[2].write(112); // Middle
  servo[3].write(112); // Ring
  servo[4].write(125); // Pinky

  // Step 1221: Fingers [124, 123, 110, 111, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(123); // Index
  servo[2].write(110); // Middle
  servo[3].write(111); // Ring
  servo[4].write(124); // Pinky

  // Step 1222: Fingers [123, 122, 110, 110, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(122); // Index
  servo[2].write(110); // Middle
  servo[3].write(110); // Ring
  servo[4].write(123); // Pinky

  // Step 1223: Fingers [122, 121, 108, 109, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(121); // Index
  servo[2].write(108); // Middle
  servo[3].write(109); // Ring
  servo[4].write(122); // Pinky

  // Step 1224: Fingers [121, 120, 107, 108, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(120); // Index
  servo[2].write(107); // Middle
  servo[3].write(108); // Ring
  servo[4].write(121); // Pinky

  // Step 1225: Fingers [121, 120, 107, 108, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(120); // Index
  servo[2].write(107); // Middle
  servo[3].write(108); // Ring
  servo[4].write(121); // Pinky

  delay(17);
  // Step 1226: Fingers [120, 119, 106, 107, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(119); // Index
  servo[2].write(106); // Middle
  servo[3].write(107); // Ring
  servo[4].write(120); // Pinky

  // Step 1227: Fingers [119, 118, 105, 106, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(118); // Index
  servo[2].write(105); // Middle
  servo[3].write(106); // Ring
  servo[4].write(119); // Pinky

  // Step 1228: Fingers [118, 117, 104, 105, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(117); // Index
  servo[2].write(104); // Middle
  servo[3].write(105); // Ring
  servo[4].write(118); // Pinky

  // Step 1229: Fingers [118, 116, 104, 105, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(116); // Index
  servo[2].write(104); // Middle
  servo[3].write(105); // Ring
  servo[4].write(118); // Pinky

  // Step 1230: Fingers [118, 116, 104, 105, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(116); // Index
  servo[2].write(104); // Middle
  servo[3].write(105); // Ring
  servo[4].write(118); // Pinky

  // Step 1231: Fingers [117, 116, 103, 104, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(116); // Index
  servo[2].write(103); // Middle
  servo[3].write(104); // Ring
  servo[4].write(117); // Pinky

  // Step 1232: Fingers [116, 115, 102, 104, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(115); // Index
  servo[2].write(102); // Middle
  servo[3].write(104); // Ring
  servo[4].write(116); // Pinky

  // Step 1233: Fingers [116, 114, 102, 103, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(114); // Index
  servo[2].write(102); // Middle
  servo[3].write(103); // Ring
  servo[4].write(116); // Pinky

  // Step 1234: Fingers [115, 114, 101, 102, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(114); // Index
  servo[2].write(101); // Middle
  servo[3].write(102); // Ring
  servo[4].write(115); // Pinky

  // Step 1235: Fingers [115, 114, 101, 102, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(114); // Index
  servo[2].write(101); // Middle
  servo[3].write(102); // Ring
  servo[4].write(115); // Pinky

  // Step 1236: Fingers [114, 113, 100, 102, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(113); // Index
  servo[2].write(100); // Middle
  servo[3].write(102); // Ring
  servo[4].write(114); // Pinky

  // Step 1237: Fingers [114, 112, 100, 101, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(112); // Index
  servo[2].write(100); // Middle
  servo[3].write(101); // Ring
  servo[4].write(114); // Pinky

  // Step 1238: Fingers [113, 112, 99, 101, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(112); // Index
  servo[2].write(99); // Middle
  servo[3].write(101); // Ring
  servo[4].write(113); // Pinky

  delay(12);
  // Step 1239: Fingers [113, 112, 99, 101, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(112); // Index
  servo[2].write(99); // Middle
  servo[3].write(101); // Ring
  servo[4].write(113); // Pinky

  // Step 1240: Fingers [113, 111, 98, 100, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(111); // Index
  servo[2].write(98); // Middle
  servo[3].write(100); // Ring
  servo[4].write(113); // Pinky

  delay(12);
  // Step 1241: Fingers [111, 110, 97, 99, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(110); // Index
  servo[2].write(97); // Middle
  servo[3].write(99); // Ring
  servo[4].write(111); // Pinky

  delay(12);
  // Step 1242: Fingers [111, 110, 97, 99, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(110); // Index
  servo[2].write(97); // Middle
  servo[3].write(99); // Ring
  servo[4].write(111); // Pinky

  delay(13);
  // Step 1243: Fingers [110, 108, 96, 98, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(98); // Ring
  servo[4].write(110); // Pinky

  delay(15);
  // Step 1244: Fingers [110, 108, 96, 98, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(108); // Index
  servo[2].write(96); // Middle
  servo[3].write(98); // Ring
  servo[4].write(110); // Pinky

  // Step 1245: Fingers [109, 108, 95, 97, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(108); // Index
  servo[2].write(95); // Middle
  servo[3].write(97); // Ring
  servo[4].write(109); // Pinky

  // Step 1246: Fingers [108, 106, 94, 96, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(106); // Index
  servo[2].write(94); // Middle
  servo[3].write(96); // Ring
  servo[4].write(108); // Pinky

  // Step 1247: Fingers [108, 106, 93, 95, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(106); // Index
  servo[2].write(93); // Middle
  servo[3].write(95); // Ring
  servo[4].write(108); // Pinky

  // Step 1248: Fingers [107, 105, 93, 94, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(105); // Index
  servo[2].write(93); // Middle
  servo[3].write(94); // Ring
  servo[4].write(107); // Pinky

  // Step 1249: Fingers [107, 105, 93, 94, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(105); // Index
  servo[2].write(93); // Middle
  servo[3].write(94); // Ring
  servo[4].write(107); // Pinky

  // Step 1250: Fingers [106, 104, 92, 94, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(104); // Index
  servo[2].write(92); // Middle
  servo[3].write(94); // Ring
  servo[4].write(106); // Pinky

  // Step 1251: Fingers [105, 103, 91, 92, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(103); // Index
  servo[2].write(91); // Middle
  servo[3].write(92); // Ring
  servo[4].write(105); // Pinky

  // Step 1252: Fingers [104, 102, 89, 91, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(102); // Index
  servo[2].write(89); // Middle
  servo[3].write(91); // Ring
  servo[4].write(104); // Pinky

  // Step 1253: Fingers [103, 101, 89, 90, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(101); // Index
  servo[2].write(89); // Middle
  servo[3].write(90); // Ring
  servo[4].write(103); // Pinky

  // Step 1254: Fingers [103, 101, 89, 90, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(101); // Index
  servo[2].write(89); // Middle
  servo[3].write(90); // Ring
  servo[4].write(103); // Pinky

  // Step 1255: Fingers [102, 101, 88, 90, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(101); // Index
  servo[2].write(88); // Middle
  servo[3].write(90); // Ring
  servo[4].write(102); // Pinky

  // Step 1256: Fingers [101, 100, 87, 88, 101] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(100); // Index
  servo[2].write(87); // Middle
  servo[3].write(88); // Ring
  servo[4].write(101); // Pinky

  // Step 1257: Fingers [100, 99, 86, 88, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(99); // Index
  servo[2].write(86); // Middle
  servo[3].write(88); // Ring
  servo[4].write(100); // Pinky

  // Step 1258: Fingers [100, 98, 86, 87, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(98); // Index
  servo[2].write(86); // Middle
  servo[3].write(87); // Ring
  servo[4].write(100); // Pinky

  // Step 1259: Fingers [100, 98, 86, 87, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(98); // Index
  servo[2].write(86); // Middle
  servo[3].write(87); // Ring
  servo[4].write(100); // Pinky

  // Step 1260: Fingers [98, 97, 84, 86, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(97); // Index
  servo[2].write(84); // Middle
  servo[3].write(86); // Ring
  servo[4].write(98); // Pinky

  // Step 1261: Fingers [98, 96, 84, 85, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(96); // Index
  servo[2].write(84); // Middle
  servo[3].write(85); // Ring
  servo[4].write(98); // Pinky

  // Step 1262: Fingers [97, 96, 83, 84, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(96); // Index
  servo[2].write(83); // Middle
  servo[3].write(84); // Ring
  servo[4].write(97); // Pinky

  // Step 1263: Fingers [96, 95, 83, 84, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(95); // Index
  servo[2].write(83); // Middle
  servo[3].write(84); // Ring
  servo[4].write(96); // Pinky

  // Step 1264: Fingers [96, 95, 83, 84, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(95); // Index
  servo[2].write(83); // Middle
  servo[3].write(84); // Ring
  servo[4].write(96); // Pinky

  // Step 1265: Fingers [95, 94, 81, 82, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(94); // Index
  servo[2].write(81); // Middle
  servo[3].write(82); // Ring
  servo[4].write(95); // Pinky

  // Step 1266: Fingers [94, 94, 81, 82, 94] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(94); // Index
  servo[2].write(81); // Middle
  servo[3].write(82); // Ring
  servo[4].write(94); // Pinky

  // Step 1267: Fingers [93, 92, 80, 80, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(92); // Index
  servo[2].write(80); // Middle
  servo[3].write(80); // Ring
  servo[4].write(93); // Pinky

  // Step 1268: Fingers [93, 92, 80, 80, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(92); // Index
  servo[2].write(80); // Middle
  servo[3].write(80); // Ring
  servo[4].write(93); // Pinky

  // Step 1269: Fingers [92, 92, 79, 80, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(92); // Index
  servo[2].write(79); // Middle
  servo[3].write(80); // Ring
  servo[4].write(92); // Pinky

  // Step 1270: Fingers [92, 91, 78, 79, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(91); // Index
  servo[2].write(78); // Middle
  servo[3].write(79); // Ring
  servo[4].write(92); // Pinky

  // Step 1271: Fingers [90, 90, 77, 77, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(90); // Index
  servo[2].write(77); // Middle
  servo[3].write(77); // Ring
  servo[4].write(90); // Pinky

  delay(16);
  // Step 1272: Fingers [90, 90, 77, 77, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(90); // Index
  servo[2].write(77); // Middle
  servo[3].write(77); // Ring
  servo[4].write(90); // Pinky

  // Step 1273: Fingers [90, 89, 77, 77, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(89); // Index
  servo[2].write(77); // Middle
  servo[3].write(77); // Ring
  servo[4].write(90); // Pinky

  // Step 1274: Fingers [89, 89, 76, 76, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(89); // Index
  servo[2].write(76); // Middle
  servo[3].write(76); // Ring
  servo[4].write(89); // Pinky

  // Step 1275: Fingers [88, 88, 75, 76, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(88); // Index
  servo[2].write(75); // Middle
  servo[3].write(76); // Ring
  servo[4].write(88); // Pinky

  delay(14);
  // Step 1276: Fingers [88, 88, 75, 76, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(88); // Index
  servo[2].write(75); // Middle
  servo[3].write(76); // Ring
  servo[4].write(88); // Pinky

  // Step 1277: Fingers [88, 88, 75, 75, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(88); // Index
  servo[2].write(75); // Middle
  servo[3].write(75); // Ring
  servo[4].write(88); // Pinky

  // Step 1278: Fingers [86, 86, 74, 74, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(86); // Index
  servo[2].write(74); // Middle
  servo[3].write(74); // Ring
  servo[4].write(86); // Pinky

  // Step 1279: Fingers [86, 86, 74, 74, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(86); // Index
  servo[2].write(74); // Middle
  servo[3].write(74); // Ring
  servo[4].write(86); // Pinky

  // Step 1280: Fingers [86, 86, 73, 73, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(86); // Index
  servo[2].write(73); // Middle
  servo[3].write(73); // Ring
  servo[4].write(86); // Pinky

  // Step 1281: Fingers [86, 86, 73, 73, 86] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(86); // Index
  servo[2].write(73); // Middle
  servo[3].write(73); // Ring
  servo[4].write(86); // Pinky

  // Step 1282: Fingers [84, 85, 72, 71, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(85); // Index
  servo[2].write(72); // Middle
  servo[3].write(71); // Ring
  servo[4].write(84); // Pinky

  // Step 1283: Fingers [84, 84, 71, 71, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(84); // Index
  servo[2].write(71); // Middle
  servo[3].write(71); // Ring
  servo[4].write(84); // Pinky

  // Step 1284: Fingers [83, 83, 71, 70, 83] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(83); // Index
  servo[2].write(71); // Middle
  servo[3].write(70); // Ring
  servo[4].write(83); // Pinky

  // Step 1285: Fingers [81, 82, 69, 69, 81] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(82); // Index
  servo[2].write(69); // Middle
  servo[3].write(69); // Ring
  servo[4].write(81); // Pinky

  // Step 1286: Fingers [81, 82, 69, 69, 81] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(82); // Index
  servo[2].write(69); // Middle
  servo[3].write(69); // Ring
  servo[4].write(81); // Pinky

  // Step 1287: Fingers [81, 82, 70, 69, 81] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(82); // Index
  servo[2].write(70); // Middle
  servo[3].write(69); // Ring
  servo[4].write(81); // Pinky

  // Step 1288: Fingers [81, 82, 69, 68, 81] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(82); // Index
  servo[2].write(69); // Middle
  servo[3].write(68); // Ring
  servo[4].write(81); // Pinky

  delay(17);
  // Step 1289: Fingers [80, 81, 69, 67, 80] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(81); // Index
  servo[2].write(69); // Middle
  servo[3].write(67); // Ring
  servo[4].write(80); // Pinky

  // Step 1290: Fingers [80, 81, 69, 67, 80] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(81); // Index
  servo[2].write(69); // Middle
  servo[3].write(67); // Ring
  servo[4].write(80); // Pinky

  // Step 1291: Fingers [80, 81, 69, 67, 80] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(81); // Index
  servo[2].write(69); // Middle
  servo[3].write(67); // Ring
  servo[4].write(80); // Pinky

  // Step 1292: Fingers [79, 81, 68, 66, 79] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(81); // Index
  servo[2].write(68); // Middle
  servo[3].write(66); // Ring
  servo[4].write(79); // Pinky

  delay(15);
  // Step 1293: Fingers [79, 81, 68, 66, 79] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(81); // Index
  servo[2].write(68); // Middle
  servo[3].write(66); // Ring
  servo[4].write(79); // Pinky

  // Step 1294: Fingers [78, 80, 68, 66, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(80); // Index
  servo[2].write(68); // Middle
  servo[3].write(66); // Ring
  servo[4].write(78); // Pinky

  delay(28);
  // Step 1295: Fingers [78, 80, 68, 66, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(80); // Index
  servo[2].write(68); // Middle
  servo[3].write(66); // Ring
  servo[4].write(78); // Pinky

  delay(31);
  // Step 1296: Fingers [78, 80, 68, 66, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(80); // Index
  servo[2].write(68); // Middle
  servo[3].write(66); // Ring
  servo[4].write(78); // Pinky

  delay(31);
  // Step 1297: Fingers [78, 80, 68, 66, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(80); // Index
  servo[2].write(68); // Middle
  servo[3].write(66); // Ring
  servo[4].write(78); // Pinky

  delay(30);
  // Step 1298: Fingers [78, 80, 68, 66, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(80); // Index
  servo[2].write(68); // Middle
  servo[3].write(66); // Ring
  servo[4].write(78); // Pinky

  delay(32);
  // Step 1299: Fingers [78, 80, 68, 66, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(80); // Index
  servo[2].write(68); // Middle
  servo[3].write(66); // Ring
  servo[4].write(78); // Pinky

  delay(28);
  // Step 1300: Fingers [78, 80, 68, 66, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(80); // Index
  servo[2].write(68); // Middle
  servo[3].write(66); // Ring
  servo[4].write(78); // Pinky

  // Step 1301: Fingers [78, 80, 67, 65, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(80); // Index
  servo[2].write(67); // Middle
  servo[3].write(65); // Ring
  servo[4].write(78); // Pinky

  // Step 1302: Fingers [75, 78, 65, 63, 75] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(78); // Index
  servo[2].write(65); // Middle
  servo[3].write(63); // Ring
  servo[4].write(75); // Pinky

  // Step 1303: Fingers [74, 77, 64, 61, 74] Arm [-, -, -]
  servo[0].write(74); // Thumb
  servo[1].write(77); // Index
  servo[2].write(64); // Middle
  servo[3].write(61); // Ring
  servo[4].write(74); // Pinky

  // Step 1304: Fingers [74, 77, 64, 61, 74] Arm [-, -, -]
  servo[0].write(74); // Thumb
  servo[1].write(77); // Index
  servo[2].write(64); // Middle
  servo[3].write(61); // Ring
  servo[4].write(74); // Pinky

  // Step 1305: Fingers [73, 76, 64, 61, 73] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(76); // Index
  servo[2].write(64); // Middle
  servo[3].write(61); // Ring
  servo[4].write(73); // Pinky

  delay(11);
  // Step 1306: Fingers [72, 76, 63, 60, 72] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(76); // Index
  servo[2].write(63); // Middle
  servo[3].write(60); // Ring
  servo[4].write(72); // Pinky

  // Step 1307: Fingers [72, 76, 63, 60, 72] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(76); // Index
  servo[2].write(63); // Middle
  servo[3].write(60); // Ring
  servo[4].write(72); // Pinky

  // Step 1308: Fingers [72, 76, 63, 60, 72] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(76); // Index
  servo[2].write(63); // Middle
  servo[3].write(60); // Ring
  servo[4].write(72); // Pinky

  delay(27);
  // Step 1309: Fingers [72, 76, 63, 60, 72] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(76); // Index
  servo[2].write(63); // Middle
  servo[3].write(60); // Ring
  servo[4].write(72); // Pinky

  delay(30);
  // Step 1310: Fingers [72, 76, 63, 60, 72] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(76); // Index
  servo[2].write(63); // Middle
  servo[3].write(60); // Ring
  servo[4].write(72); // Pinky

  delay(31);
  // Step 1311: Fingers [72, 76, 63, 60, 72] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(76); // Index
  servo[2].write(63); // Middle
  servo[3].write(60); // Ring
  servo[4].write(72); // Pinky

  // Step 1312: Fingers [72, 76, 64, 60, 72] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(76); // Index
  servo[2].write(64); // Middle
  servo[3].write(60); // Ring
  servo[4].write(72); // Pinky

  // Step 1313: Fingers [71, 75, 63, 59, 71] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(75); // Index
  servo[2].write(63); // Middle
  servo[3].write(59); // Ring
  servo[4].write(71); // Pinky

  // Step 1314: Fingers [70, 75, 63, 58, 70] Arm [-, -, -]
  servo[0].write(70); // Thumb
  servo[1].write(75); // Index
  servo[2].write(63); // Middle
  servo[3].write(58); // Ring
  servo[4].write(70); // Pinky

  delay(15);
  // Step 1315: Fingers [70, 75, 63, 58, 70] Arm [-, -, -]
  servo[0].write(70); // Thumb
  servo[1].write(75); // Index
  servo[2].write(63); // Middle
  servo[3].write(58); // Ring
  servo[4].write(70); // Pinky

  // Step 1316: Fingers [69, 74, 62, 58, 69] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(74); // Index
  servo[2].write(62); // Middle
  servo[3].write(58); // Ring
  servo[4].write(69); // Pinky

  // Step 1317: Fingers [69, 74, 62, 57, 69] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(74); // Index
  servo[2].write(62); // Middle
  servo[3].write(57); // Ring
  servo[4].write(69); // Pinky

  // Step 1318: Fingers [68, 74, 62, 57, 68] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(74); // Index
  servo[2].write(62); // Middle
  servo[3].write(57); // Ring
  servo[4].write(68); // Pinky

  // Step 1319: Fingers [67, 72, 61, 56, 67] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(72); // Index
  servo[2].write(61); // Middle
  servo[3].write(56); // Ring
  servo[4].write(67); // Pinky

  // Step 1320: Fingers [67, 72, 61, 56, 67] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(72); // Index
  servo[2].write(61); // Middle
  servo[3].write(56); // Ring
  servo[4].write(67); // Pinky

  // Step 1321: Fingers [67, 73, 61, 56, 67] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(73); // Index
  servo[2].write(61); // Middle
  servo[3].write(56); // Ring
  servo[4].write(67); // Pinky

  // Step 1322: Fingers [66, 72, 60, 55, 66] Arm [-, -, -]
  servo[0].write(66); // Thumb
  servo[1].write(72); // Index
  servo[2].write(60); // Middle
  servo[3].write(55); // Ring
  servo[4].write(66); // Pinky

  // Step 1323: Fingers [66, 72, 61, 55, 66] Arm [-, -, -]
  servo[0].write(66); // Thumb
  servo[1].write(72); // Index
  servo[2].write(61); // Middle
  servo[3].write(55); // Ring
  servo[4].write(66); // Pinky

  // Step 1324: Fingers [65, 71, 60, 54, 65] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(71); // Index
  servo[2].write(60); // Middle
  servo[3].write(54); // Ring
  servo[4].write(65); // Pinky

  // Step 1325: Fingers [65, 71, 60, 54, 65] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(71); // Index
  servo[2].write(60); // Middle
  servo[3].write(54); // Ring
  servo[4].write(65); // Pinky

  // Step 1326: Fingers [64, 71, 60, 53, 64] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(71); // Index
  servo[2].write(60); // Middle
  servo[3].write(53); // Ring
  servo[4].write(64); // Pinky

  // Step 1327: Fingers [63, 70, 59, 53, 63] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(70); // Index
  servo[2].write(59); // Middle
  servo[3].write(53); // Ring
  servo[4].write(63); // Pinky

  // Step 1328: Fingers [63, 70, 59, 52, 63] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(70); // Index
  servo[2].write(59); // Middle
  servo[3].write(52); // Ring
  servo[4].write(63); // Pinky

  // Step 1329: Fingers [61, 68, 58, 51, 61] Arm [-, -, -]
  servo[0].write(61); // Thumb
  servo[1].write(68); // Index
  servo[2].write(58); // Middle
  servo[3].write(51); // Ring
  servo[4].write(61); // Pinky

  // Step 1330: Fingers [61, 68, 58, 51, 61] Arm [-, -, -]
  servo[0].write(61); // Thumb
  servo[1].write(68); // Index
  servo[2].write(58); // Middle
  servo[3].write(51); // Ring
  servo[4].write(61); // Pinky

  // Step 1331: Fingers [61, 68, 58, 51, 61] Arm [-, -, -]
  servo[0].write(61); // Thumb
  servo[1].write(68); // Index
  servo[2].write(58); // Middle
  servo[3].write(51); // Ring
  servo[4].write(61); // Pinky

  // Step 1332: Fingers [60, 68, 58, 50, 60] Arm [-, -, -]
  servo[0].write(60); // Thumb
  servo[1].write(68); // Index
  servo[2].write(58); // Middle
  servo[3].write(50); // Ring
  servo[4].write(60); // Pinky

  // Step 1333: Fingers [59, 67, 58, 49, 59] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(67); // Index
  servo[2].write(58); // Middle
  servo[3].write(49); // Ring
  servo[4].write(59); // Pinky

  // Step 1334: Fingers [59, 67, 58, 49, 59] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(67); // Index
  servo[2].write(58); // Middle
  servo[3].write(49); // Ring
  servo[4].write(59); // Pinky

  // Step 1335: Fingers [58, 67, 57, 49, 58] Arm [-, -, -]
  servo[0].write(58); // Thumb
  servo[1].write(67); // Index
  servo[2].write(57); // Middle
  servo[3].write(49); // Ring
  servo[4].write(58); // Pinky

  // Step 1336: Fingers [57, 66, 57, 48, 57] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(66); // Index
  servo[2].write(57); // Middle
  servo[3].write(48); // Ring
  servo[4].write(57); // Pinky

  // Step 1337: Fingers [56, 65, 56, 47, 56] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(65); // Index
  servo[2].write(56); // Middle
  servo[3].write(47); // Ring
  servo[4].write(56); // Pinky

  // Step 1338: Fingers [55, 65, 56, 47, 55] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(65); // Index
  servo[2].write(56); // Middle
  servo[3].write(47); // Ring
  servo[4].write(55); // Pinky

  // Step 1339: Fingers [55, 65, 56, 47, 55] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(65); // Index
  servo[2].write(56); // Middle
  servo[3].write(47); // Ring
  servo[4].write(55); // Pinky

  // Step 1340: Fingers [54, 64, 56, 46, 54] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(64); // Index
  servo[2].write(56); // Middle
  servo[3].write(46); // Ring
  servo[4].write(54); // Pinky

  delay(17);
  // Step 1341: Fingers [54, 64, 56, 46, 54] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(64); // Index
  servo[2].write(56); // Middle
  servo[3].write(46); // Ring
  servo[4].write(54); // Pinky

  // Step 1342: Fingers [54, 63, 55, 45, 54] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(63); // Index
  servo[2].write(55); // Middle
  servo[3].write(45); // Ring
  servo[4].write(54); // Pinky

  // Step 1343: Fingers [53, 63, 55, 45, 53] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(63); // Index
  servo[2].write(55); // Middle
  servo[3].write(45); // Ring
  servo[4].write(53); // Pinky

  // Step 1344: Fingers [53, 63, 56, 46, 53] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(63); // Index
  servo[2].write(56); // Middle
  servo[3].write(46); // Ring
  servo[4].write(53); // Pinky

  // Step 1345: Fingers [53, 63, 56, 46, 53] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(63); // Index
  servo[2].write(56); // Middle
  servo[3].write(46); // Ring
  servo[4].write(53); // Pinky

  // Step 1346: Fingers [53, 63, 56, 46, 53] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(63); // Index
  servo[2].write(56); // Middle
  servo[3].write(46); // Ring
  servo[4].write(53); // Pinky

  // Step 1347: Fingers [52, 63, 55, 45, 52] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(63); // Index
  servo[2].write(55); // Middle
  servo[3].write(45); // Ring
  servo[4].write(52); // Pinky

  // Step 1348: Fingers [52, 63, 56, 45, 52] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(63); // Index
  servo[2].write(56); // Middle
  servo[3].write(45); // Ring
  servo[4].write(52); // Pinky

  // Step 1349: Fingers [52, 63, 56, 45, 52] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(63); // Index
  servo[2].write(56); // Middle
  servo[3].write(45); // Ring
  servo[4].write(52); // Pinky

  // Step 1350: Fingers [52, 63, 56, 45, 52] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(63); // Index
  servo[2].write(56); // Middle
  servo[3].write(45); // Ring
  servo[4].write(52); // Pinky

  // Step 1351: Fingers [51, 62, 55, 44, 51] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(62); // Index
  servo[2].write(55); // Middle
  servo[3].write(44); // Ring
  servo[4].write(51); // Pinky

  // Step 1352: Fingers [50, 61, 55, 44, 50] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(61); // Index
  servo[2].write(55); // Middle
  servo[3].write(44); // Ring
  servo[4].write(50); // Pinky

  // Step 1353: Fingers [50, 61, 55, 44, 50] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(61); // Index
  servo[2].write(55); // Middle
  servo[3].write(44); // Ring
  servo[4].write(50); // Pinky

  // Step 1354: Fingers [50, 61, 55, 44, 50] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(61); // Index
  servo[2].write(55); // Middle
  servo[3].write(44); // Ring
  servo[4].write(50); // Pinky

  // Step 1355: Fingers [49, 61, 56, 44, 49] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(61); // Index
  servo[2].write(56); // Middle
  servo[3].write(44); // Ring
  servo[4].write(49); // Pinky

  delay(12);
  // Step 1356: Fingers [49, 61, 56, 44, 49] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(61); // Index
  servo[2].write(56); // Middle
  servo[3].write(44); // Ring
  servo[4].write(49); // Pinky

  // Step 1357: Fingers [49, 61, 56, 44, 49] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(61); // Index
  servo[2].write(56); // Middle
  servo[3].write(44); // Ring
  servo[4].write(49); // Pinky

  // Step 1358: Fingers [49, 61, 56, 44, 49] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(61); // Index
  servo[2].write(56); // Middle
  servo[3].write(44); // Ring
  servo[4].write(49); // Pinky

  delay(14);
  // Step 1359: Fingers [49, 61, 56, 44, 49] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(61); // Index
  servo[2].write(56); // Middle
  servo[3].write(44); // Ring
  servo[4].write(49); // Pinky

  // Step 1360: Fingers [49, 61, 56, 44, 49] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(61); // Index
  servo[2].write(56); // Middle
  servo[3].write(44); // Ring
  servo[4].write(49); // Pinky

  // Step 1361: Fingers [48, 60, 57, 45, 48] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(60); // Index
  servo[2].write(57); // Middle
  servo[3].write(45); // Ring
  servo[4].write(48); // Pinky

  // Step 1362: Fingers [48, 60, 57, 45, 48] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(60); // Index
  servo[2].write(57); // Middle
  servo[3].write(45); // Ring
  servo[4].write(48); // Pinky

  delay(14);
  // Step 1363: Fingers [48, 60, 57, 45, 48] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(60); // Index
  servo[2].write(57); // Middle
  servo[3].write(45); // Ring
  servo[4].write(48); // Pinky

  // Step 1364: Fingers [48, 60, 57, 45, 48] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(60); // Index
  servo[2].write(57); // Middle
  servo[3].write(45); // Ring
  servo[4].write(48); // Pinky

  delay(26);
  // Step 1365: Fingers [48, 60, 57, 45, 48] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(60); // Index
  servo[2].write(57); // Middle
  servo[3].write(45); // Ring
  servo[4].write(48); // Pinky

  delay(30);
  // Step 1366: Fingers [48, 60, 57, 45, 48] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(60); // Index
  servo[2].write(57); // Middle
  servo[3].write(45); // Ring
  servo[4].write(48); // Pinky

  // Step 1367: Fingers [48, 60, 57, 45, 48] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(60); // Index
  servo[2].write(57); // Middle
  servo[3].write(45); // Ring
  servo[4].write(48); // Pinky

  // Step 1368: Fingers [47, 60, 58, 45, 47] Arm [-, -, -]
  servo[0].write(47); // Thumb
  servo[1].write(60); // Index
  servo[2].write(58); // Middle
  servo[3].write(45); // Ring
  servo[4].write(47); // Pinky

  // Step 1369: Fingers [48, 60, 59, 46, 48] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(60); // Index
  servo[2].write(59); // Middle
  servo[3].write(46); // Ring
  servo[4].write(48); // Pinky

  // Step 1370: Fingers [48, 60, 59, 46, 48] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(60); // Index
  servo[2].write(59); // Middle
  servo[3].write(46); // Ring
  servo[4].write(48); // Pinky

  // Step 1371: Fingers [48, 61, 60, 47, 48] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(61); // Index
  servo[2].write(60); // Middle
  servo[3].write(47); // Ring
  servo[4].write(48); // Pinky

  // Step 1372: Fingers [48, 61, 60, 47, 48] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(61); // Index
  servo[2].write(60); // Middle
  servo[3].write(47); // Ring
  servo[4].write(48); // Pinky

  // Step 1373: Fingers [48, 61, 61, 48, 48] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(61); // Index
  servo[2].write(61); // Middle
  servo[3].write(48); // Ring
  servo[4].write(48); // Pinky

  // Step 1374: Fingers [49, 62, 62, 49, 49] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(62); // Index
  servo[2].write(62); // Middle
  servo[3].write(49); // Ring
  servo[4].write(49); // Pinky

  // Step 1375: Fingers [49, 62, 62, 49, 49] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(62); // Index
  servo[2].write(62); // Middle
  servo[3].write(49); // Ring
  servo[4].write(49); // Pinky

  // Step 1376: Fingers [50, 63, 63, 50, 50] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(63); // Index
  servo[2].write(63); // Middle
  servo[3].write(50); // Ring
  servo[4].write(50); // Pinky

  delay(15);
  // Step 1377: Fingers [50, 63, 64, 51, 50] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(63); // Index
  servo[2].write(64); // Middle
  servo[3].write(51); // Ring
  servo[4].write(50); // Pinky

  // Step 1378: Fingers [50, 63, 64, 51, 50] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(63); // Index
  servo[2].write(64); // Middle
  servo[3].write(51); // Ring
  servo[4].write(50); // Pinky

  // Step 1379: Fingers [51, 64, 64, 52, 51] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(64); // Index
  servo[2].write(64); // Middle
  servo[3].write(52); // Ring
  servo[4].write(51); // Pinky

  // Step 1380: Fingers [51, 64, 65, 53, 51] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(64); // Index
  servo[2].write(65); // Middle
  servo[3].write(53); // Ring
  servo[4].write(51); // Pinky

  // Step 1381: Fingers [53, 65, 67, 54, 53] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(65); // Index
  servo[2].write(67); // Middle
  servo[3].write(54); // Ring
  servo[4].write(53); // Pinky

  // Step 1382: Fingers [53, 66, 67, 55, 53] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(66); // Index
  servo[2].write(67); // Middle
  servo[3].write(55); // Ring
  servo[4].write(53); // Pinky

  // Step 1383: Fingers [53, 66, 67, 55, 53] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(66); // Index
  servo[2].write(67); // Middle
  servo[3].write(55); // Ring
  servo[4].write(53); // Pinky

  // Step 1384: Fingers [54, 66, 68, 55, 54] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(66); // Index
  servo[2].write(68); // Middle
  servo[3].write(55); // Ring
  servo[4].write(54); // Pinky

  // Step 1385: Fingers [54, 67, 69, 56, 54] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(67); // Index
  servo[2].write(69); // Middle
  servo[3].write(56); // Ring
  servo[4].write(54); // Pinky

  // Step 1386: Fingers [55, 67, 70, 57, 55] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(67); // Index
  servo[2].write(70); // Middle
  servo[3].write(57); // Ring
  servo[4].write(55); // Pinky

  // Step 1387: Fingers [55, 67, 70, 57, 55] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(67); // Index
  servo[2].write(70); // Middle
  servo[3].write(57); // Ring
  servo[4].write(55); // Pinky

  // Step 1388: Fingers [54, 67, 70, 57, 54] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(67); // Index
  servo[2].write(70); // Middle
  servo[3].write(57); // Ring
  servo[4].write(54); // Pinky

  // Step 1389: Fingers [55, 67, 70, 58, 55] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(67); // Index
  servo[2].write(70); // Middle
  servo[3].write(58); // Ring
  servo[4].write(55); // Pinky

  // Step 1390: Fingers [56, 68, 71, 59, 56] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(68); // Index
  servo[2].write(71); // Middle
  servo[3].write(59); // Ring
  servo[4].write(56); // Pinky

  // Step 1391: Fingers [56, 69, 72, 59, 56] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(69); // Index
  servo[2].write(72); // Middle
  servo[3].write(59); // Ring
  servo[4].write(56); // Pinky

  // Step 1392: Fingers [56, 69, 72, 59, 56] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(69); // Index
  servo[2].write(72); // Middle
  servo[3].write(59); // Ring
  servo[4].write(56); // Pinky

  // Step 1393: Fingers [58, 70, 73, 61, 58] Arm [-, -, -]
  servo[0].write(58); // Thumb
  servo[1].write(70); // Index
  servo[2].write(73); // Middle
  servo[3].write(61); // Ring
  servo[4].write(58); // Pinky

  // Step 1394: Fingers [58, 71, 74, 61, 58] Arm [-, -, -]
  servo[0].write(58); // Thumb
  servo[1].write(71); // Index
  servo[2].write(74); // Middle
  servo[3].write(61); // Ring
  servo[4].write(58); // Pinky

  // Step 1395: Fingers [59, 71, 74, 62, 59] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(71); // Index
  servo[2].write(74); // Middle
  servo[3].write(62); // Ring
  servo[4].write(59); // Pinky

  // Step 1396: Fingers [59, 71, 74, 62, 59] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(71); // Index
  servo[2].write(74); // Middle
  servo[3].write(62); // Ring
  servo[4].write(59); // Pinky

  // Step 1397: Fingers [60, 72, 75, 62, 60] Arm [-, -, -]
  servo[0].write(60); // Thumb
  servo[1].write(72); // Index
  servo[2].write(75); // Middle
  servo[3].write(62); // Ring
  servo[4].write(60); // Pinky

  // Step 1398: Fingers [60, 73, 75, 63, 60] Arm [-, -, -]
  servo[0].write(60); // Thumb
  servo[1].write(73); // Index
  servo[2].write(75); // Middle
  servo[3].write(63); // Ring
  servo[4].write(60); // Pinky

  // Step 1399: Fingers [61, 74, 77, 64, 61] Arm [-, -, -]
  servo[0].write(61); // Thumb
  servo[1].write(74); // Index
  servo[2].write(77); // Middle
  servo[3].write(64); // Ring
  servo[4].write(61); // Pinky

  delay(15);
  // Step 1400: Fingers [61, 74, 77, 64, 61] Arm [-, -, -]
  servo[0].write(61); // Thumb
  servo[1].write(74); // Index
  servo[2].write(77); // Middle
  servo[3].write(64); // Ring
  servo[4].write(61); // Pinky

  // Step 1401: Fingers [63, 75, 78, 66, 63] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(75); // Index
  servo[2].write(78); // Middle
  servo[3].write(66); // Ring
  servo[4].write(63); // Pinky

  // Step 1402: Fingers [63, 76, 79, 66, 63] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(76); // Index
  servo[2].write(79); // Middle
  servo[3].write(66); // Ring
  servo[4].write(63); // Pinky

  // Step 1403: Fingers [64, 76, 79, 67, 64] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(76); // Index
  servo[2].write(79); // Middle
  servo[3].write(67); // Ring
  servo[4].write(64); // Pinky

  // Step 1404: Fingers [64, 76, 79, 67, 64] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(76); // Index
  servo[2].write(79); // Middle
  servo[3].write(67); // Ring
  servo[4].write(64); // Pinky

  // Step 1405: Fingers [65, 77, 80, 68, 65] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(77); // Index
  servo[2].write(80); // Middle
  servo[3].write(68); // Ring
  servo[4].write(65); // Pinky

  // Step 1406: Fingers [65, 77, 81, 68, 65] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(77); // Index
  servo[2].write(81); // Middle
  servo[3].write(68); // Ring
  servo[4].write(65); // Pinky

  // Step 1407: Fingers [65, 77, 81, 69, 65] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(77); // Index
  servo[2].write(81); // Middle
  servo[3].write(69); // Ring
  servo[4].write(65); // Pinky

  // Step 1408: Fingers [66, 78, 81, 69, 66] Arm [-, -, -]
  servo[0].write(66); // Thumb
  servo[1].write(78); // Index
  servo[2].write(81); // Middle
  servo[3].write(69); // Ring
  servo[4].write(66); // Pinky

  // Step 1409: Fingers [66, 78, 81, 69, 66] Arm [-, -, -]
  servo[0].write(66); // Thumb
  servo[1].write(78); // Index
  servo[2].write(81); // Middle
  servo[3].write(69); // Ring
  servo[4].write(66); // Pinky

  // Step 1410: Fingers [67, 79, 83, 70, 67] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(79); // Index
  servo[2].write(83); // Middle
  servo[3].write(70); // Ring
  servo[4].write(67); // Pinky

  delay(17);
  // Step 1411: Fingers [68, 80, 84, 72, 68] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(80); // Index
  servo[2].write(84); // Middle
  servo[3].write(72); // Ring
  servo[4].write(68); // Pinky

  // Step 1412: Fingers [68, 80, 84, 72, 68] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(80); // Index
  servo[2].write(84); // Middle
  servo[3].write(72); // Ring
  servo[4].write(68); // Pinky

  delay(15);
  // Step 1413: Fingers [69, 81, 85, 73, 69] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(81); // Index
  servo[2].write(85); // Middle
  servo[3].write(73); // Ring
  servo[4].write(69); // Pinky

  // Step 1414: Fingers [69, 82, 85, 73, 69] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(82); // Index
  servo[2].write(85); // Middle
  servo[3].write(73); // Ring
  servo[4].write(69); // Pinky

  // Step 1415: Fingers [69, 82, 85, 73, 69] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(82); // Index
  servo[2].write(85); // Middle
  servo[3].write(73); // Ring
  servo[4].write(69); // Pinky

  // Step 1416: Fingers [70, 82, 86, 74, 70] Arm [-, -, -]
  servo[0].write(70); // Thumb
  servo[1].write(82); // Index
  servo[2].write(86); // Middle
  servo[3].write(74); // Ring
  servo[4].write(70); // Pinky

  // Step 1417: Fingers [71, 83, 87, 74, 71] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(83); // Index
  servo[2].write(87); // Middle
  servo[3].write(74); // Ring
  servo[4].write(71); // Pinky

  // Step 1418: Fingers [71, 84, 87, 75, 71] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(84); // Index
  servo[2].write(87); // Middle
  servo[3].write(75); // Ring
  servo[4].write(71); // Pinky

  delay(17);
  // Step 1419: Fingers [71, 84, 87, 75, 71] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(84); // Index
  servo[2].write(87); // Middle
  servo[3].write(75); // Ring
  servo[4].write(71); // Pinky

  // Step 1420: Fingers [72, 84, 88, 76, 72] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(84); // Index
  servo[2].write(88); // Middle
  servo[3].write(76); // Ring
  servo[4].write(72); // Pinky

  // Step 1421: Fingers [72, 84, 88, 76, 72] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(84); // Index
  servo[2].write(88); // Middle
  servo[3].write(76); // Ring
  servo[4].write(72); // Pinky

  // Step 1422: Fingers [73, 85, 89, 77, 73] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(85); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(73); // Pinky

  delay(14);
  // Step 1423: Fingers [73, 85, 89, 77, 73] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(85); // Index
  servo[2].write(89); // Middle
  servo[3].write(77); // Ring
  servo[4].write(73); // Pinky

  // Step 1424: Fingers [74, 86, 90, 78, 74] Arm [-, -, -]
  servo[0].write(74); // Thumb
  servo[1].write(86); // Index
  servo[2].write(90); // Middle
  servo[3].write(78); // Ring
  servo[4].write(74); // Pinky

  // Step 1425: Fingers [75, 87, 90, 78, 75] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(87); // Index
  servo[2].write(90); // Middle
  servo[3].write(78); // Ring
  servo[4].write(75); // Pinky

  // Step 1426: Fingers [76, 88, 92, 80, 76] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(88); // Index
  servo[2].write(92); // Middle
  servo[3].write(80); // Ring
  servo[4].write(76); // Pinky

  // Step 1427: Fingers [76, 89, 92, 80, 76] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(89); // Index
  servo[2].write(92); // Middle
  servo[3].write(80); // Ring
  servo[4].write(76); // Pinky

  // Step 1428: Fingers [76, 89, 92, 80, 76] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(89); // Index
  servo[2].write(92); // Middle
  servo[3].write(80); // Ring
  servo[4].write(76); // Pinky

  // Step 1429: Fingers [77, 89, 93, 81, 77] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(89); // Index
  servo[2].write(93); // Middle
  servo[3].write(81); // Ring
  servo[4].write(77); // Pinky

  // Step 1430: Fingers [78, 90, 94, 81, 78] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(90); // Index
  servo[2].write(94); // Middle
  servo[3].write(81); // Ring
  servo[4].write(78); // Pinky

  delay(15);
  // Step 1431: Fingers [79, 91, 95, 83, 79] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(91); // Index
  servo[2].write(95); // Middle
  servo[3].write(83); // Ring
  servo[4].write(79); // Pinky

  // Step 1432: Fingers [79, 91, 95, 83, 79] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(91); // Index
  servo[2].write(95); // Middle
  servo[3].write(83); // Ring
  servo[4].write(79); // Pinky

  // Step 1433: Fingers [80, 92, 95, 83, 80] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(92); // Index
  servo[2].write(95); // Middle
  servo[3].write(83); // Ring
  servo[4].write(80); // Pinky

  // Step 1434: Fingers [80, 93, 96, 84, 80] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(93); // Index
  servo[2].write(96); // Middle
  servo[3].write(84); // Ring
  servo[4].write(80); // Pinky

  // Step 1435: Fingers [81, 93, 97, 85, 81] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(93); // Index
  servo[2].write(97); // Middle
  servo[3].write(85); // Ring
  servo[4].write(81); // Pinky

  // Step 1436: Fingers [81, 93, 97, 85, 81] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(93); // Index
  servo[2].write(97); // Middle
  servo[3].write(85); // Ring
  servo[4].write(81); // Pinky

  // Step 1437: Fingers [82, 94, 97, 85, 82] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(94); // Index
  servo[2].write(97); // Middle
  servo[3].write(85); // Ring
  servo[4].write(82); // Pinky

  // Step 1438: Fingers [82, 94, 97, 85, 82] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(94); // Index
  servo[2].write(97); // Middle
  servo[3].write(85); // Ring
  servo[4].write(82); // Pinky

  // Step 1439: Fingers [83, 96, 98, 86, 83] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(96); // Index
  servo[2].write(98); // Middle
  servo[3].write(86); // Ring
  servo[4].write(83); // Pinky

  // Step 1440: Fingers [84, 97, 100, 87, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(97); // Index
  servo[2].write(100); // Middle
  servo[3].write(87); // Ring
  servo[4].write(84); // Pinky

  // Step 1441: Fingers [84, 97, 100, 87, 84] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(97); // Index
  servo[2].write(100); // Middle
  servo[3].write(87); // Ring
  servo[4].write(84); // Pinky

  // Step 1442: Fingers [85, 98, 100, 88, 85] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(98); // Index
  servo[2].write(100); // Middle
  servo[3].write(88); // Ring
  servo[4].write(85); // Pinky

  // Step 1443: Fingers [87, 99, 101, 89, 87] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(99); // Index
  servo[2].write(101); // Middle
  servo[3].write(89); // Ring
  servo[4].write(87); // Pinky

  // Step 1444: Fingers [88, 100, 103, 90, 88] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(100); // Index
  servo[2].write(103); // Middle
  servo[3].write(90); // Ring
  servo[4].write(88); // Pinky

  // Step 1445: Fingers [89, 101, 103, 91, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(101); // Index
  servo[2].write(103); // Middle
  servo[3].write(91); // Ring
  servo[4].write(89); // Pinky

  // Step 1446: Fingers [89, 101, 103, 91, 89] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(101); // Index
  servo[2].write(103); // Middle
  servo[3].write(91); // Ring
  servo[4].write(89); // Pinky

  // Step 1447: Fingers [90, 103, 104, 92, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(103); // Index
  servo[2].write(104); // Middle
  servo[3].write(92); // Ring
  servo[4].write(90); // Pinky

  // Step 1448: Fingers [91, 103, 105, 92, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(103); // Index
  servo[2].write(105); // Middle
  servo[3].write(92); // Ring
  servo[4].write(91); // Pinky

  // Step 1449: Fingers [91, 104, 106, 93, 91] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(104); // Index
  servo[2].write(106); // Middle
  servo[3].write(93); // Ring
  servo[4].write(91); // Pinky

  // Step 1450: Fingers [92, 105, 106, 94, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(105); // Index
  servo[2].write(106); // Middle
  servo[3].write(94); // Ring
  servo[4].write(92); // Pinky

  // Step 1451: Fingers [92, 105, 106, 94, 92] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(105); // Index
  servo[2].write(106); // Middle
  servo[3].write(94); // Ring
  servo[4].write(92); // Pinky

  // Step 1452: Fingers [93, 106, 107, 95, 93] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(106); // Index
  servo[2].write(107); // Middle
  servo[3].write(95); // Ring
  servo[4].write(93); // Pinky

  delay(11);
  // Step 1453: Fingers [95, 107, 108, 96, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(107); // Index
  servo[2].write(108); // Middle
  servo[3].write(96); // Ring
  servo[4].write(95); // Pinky

  delay(13);
  // Step 1454: Fingers [95, 107, 108, 96, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(107); // Index
  servo[2].write(108); // Middle
  servo[3].write(96); // Ring
  servo[4].write(95); // Pinky

  delay(14);
  // Step 1455: Fingers [96, 108, 109, 96, 96] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(108); // Index
  servo[2].write(109); // Middle
  servo[3].write(96); // Ring
  servo[4].write(96); // Pinky

  // Step 1456: Fingers [97, 110, 110, 98, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(110); // Index
  servo[2].write(110); // Middle
  servo[3].write(98); // Ring
  servo[4].write(97); // Pinky

  delay(13);
  // Step 1457: Fingers [97, 110, 110, 98, 97] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(110); // Index
  servo[2].write(110); // Middle
  servo[3].write(98); // Ring
  servo[4].write(97); // Pinky

  delay(11);
  // Step 1458: Fingers [98, 110, 111, 98, 98] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(110); // Index
  servo[2].write(111); // Middle
  servo[3].write(98); // Ring
  servo[4].write(98); // Pinky

  // Step 1459: Fingers [99, 112, 112, 99, 99] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(112); // Index
  servo[2].write(112); // Middle
  servo[3].write(99); // Ring
  servo[4].write(99); // Pinky

  delay(15);
  // Step 1460: Fingers [100, 113, 113, 100, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(113); // Index
  servo[2].write(113); // Middle
  servo[3].write(100); // Ring
  servo[4].write(100); // Pinky

  // Step 1461: Fingers [100, 113, 113, 100, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(113); // Index
  servo[2].write(113); // Middle
  servo[3].write(100); // Ring
  servo[4].write(100); // Pinky

  // Step 1462: Fingers [100, 113, 113, 100, 100] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(113); // Index
  servo[2].write(113); // Middle
  servo[3].write(100); // Ring
  servo[4].write(100); // Pinky

  // Step 1463: Fingers [101, 114, 114, 101, 101] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(114); // Index
  servo[2].write(114); // Middle
  servo[3].write(101); // Ring
  servo[4].write(101); // Pinky

  delay(16);
  // Step 1464: Fingers [101, 114, 114, 101, 101] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(114); // Index
  servo[2].write(114); // Middle
  servo[3].write(101); // Ring
  servo[4].write(101); // Pinky

  delay(13);
  // Step 1465: Fingers [102, 114, 114, 102, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(114); // Index
  servo[2].write(114); // Middle
  servo[3].write(102); // Ring
  servo[4].write(102); // Pinky

  delay(19);
  // Step 1466: Fingers [102, 114, 114, 102, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(114); // Index
  servo[2].write(114); // Middle
  servo[3].write(102); // Ring
  servo[4].write(102); // Pinky

  delay(31);
  // Step 1467: Fingers [102, 114, 114, 102, 102] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(114); // Index
  servo[2].write(114); // Middle
  servo[3].write(102); // Ring
  servo[4].write(102); // Pinky

  delay(16);
  // Step 1468: Fingers [103, 116, 115, 103, 103] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(116); // Index
  servo[2].write(115); // Middle
  servo[3].write(103); // Ring
  servo[4].write(103); // Pinky

  // Step 1469: Fingers [104, 117, 116, 103, 104] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(117); // Index
  servo[2].write(116); // Middle
  servo[3].write(103); // Ring
  servo[4].write(104); // Pinky

  delay(13);
  // Step 1470: Fingers [105, 118, 117, 105, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(118); // Index
  servo[2].write(117); // Middle
  servo[3].write(105); // Ring
  servo[4].write(105); // Pinky

  // Step 1471: Fingers [105, 118, 117, 105, 105] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(118); // Index
  servo[2].write(117); // Middle
  servo[3].write(105); // Ring
  servo[4].write(105); // Pinky

  // Step 1472: Fingers [106, 119, 118, 105, 106] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(119); // Index
  servo[2].write(118); // Middle
  servo[3].write(105); // Ring
  servo[4].write(106); // Pinky

  // Step 1473: Fingers [107, 119, 118, 106, 107] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(119); // Index
  servo[2].write(118); // Middle
  servo[3].write(106); // Ring
  servo[4].write(107); // Pinky

  // Step 1474: Fingers [108, 121, 119, 107, 108] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(121); // Index
  servo[2].write(119); // Middle
  servo[3].write(107); // Ring
  servo[4].write(108); // Pinky

  // Step 1475: Fingers [109, 122, 120, 107, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(122); // Index
  servo[2].write(120); // Middle
  servo[3].write(107); // Ring
  servo[4].write(109); // Pinky

  // Step 1476: Fingers [109, 122, 120, 107, 109] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(122); // Index
  servo[2].write(120); // Middle
  servo[3].write(107); // Ring
  servo[4].write(109); // Pinky

  // Step 1477: Fingers [110, 122, 120, 108, 110] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(122); // Index
  servo[2].write(120); // Middle
  servo[3].write(108); // Ring
  servo[4].write(110); // Pinky

  // Step 1478: Fingers [111, 123, 121, 108, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(123); // Index
  servo[2].write(121); // Middle
  servo[3].write(108); // Ring
  servo[4].write(111); // Pinky

  delay(15);
  // Step 1479: Fingers [111, 123, 121, 108, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(123); // Index
  servo[2].write(121); // Middle
  servo[3].write(108); // Ring
  servo[4].write(111); // Pinky

  // Step 1480: Fingers [111, 124, 121, 109, 111] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(124); // Index
  servo[2].write(121); // Middle
  servo[3].write(109); // Ring
  servo[4].write(111); // Pinky

  // Step 1481: Fingers [112, 125, 122, 109, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(125); // Index
  servo[2].write(122); // Middle
  servo[3].write(109); // Ring
  servo[4].write(112); // Pinky

  // Step 1482: Fingers [113, 125, 122, 110, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(125); // Index
  servo[2].write(122); // Middle
  servo[3].write(110); // Ring
  servo[4].write(113); // Pinky

  delay(14);
  // Step 1483: Fingers [113, 125, 122, 110, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(125); // Index
  servo[2].write(122); // Middle
  servo[3].write(110); // Ring
  servo[4].write(113); // Pinky

  // Step 1484: Fingers [113, 126, 123, 111, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(126); // Index
  servo[2].write(123); // Middle
  servo[3].write(111); // Ring
  servo[4].write(113); // Pinky

  // Step 1485: Fingers [114, 127, 123, 111, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(127); // Index
  servo[2].write(123); // Middle
  servo[3].write(111); // Ring
  servo[4].write(114); // Pinky

  // Step 1486: Fingers [115, 127, 124, 112, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(127); // Index
  servo[2].write(124); // Middle
  servo[3].write(112); // Ring
  servo[4].write(115); // Pinky

  delay(17);
  // Step 1487: Fingers [115, 127, 124, 112, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(127); // Index
  servo[2].write(124); // Middle
  servo[3].write(112); // Ring
  servo[4].write(115); // Pinky

  // Step 1488: Fingers [116, 128, 124, 112, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(128); // Index
  servo[2].write(124); // Middle
  servo[3].write(112); // Ring
  servo[4].write(116); // Pinky

  // Step 1489: Fingers [117, 129, 125, 113, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(129); // Index
  servo[2].write(125); // Middle
  servo[3].write(113); // Ring
  servo[4].write(117); // Pinky

  // Step 1490: Fingers [117, 129, 125, 113, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(129); // Index
  servo[2].write(125); // Middle
  servo[3].write(113); // Ring
  servo[4].write(117); // Pinky

  // Step 1491: Fingers [117, 129, 125, 113, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(129); // Index
  servo[2].write(125); // Middle
  servo[3].write(113); // Ring
  servo[4].write(117); // Pinky

  // Step 1492: Fingers [117, 129, 125, 113, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(129); // Index
  servo[2].write(125); // Middle
  servo[3].write(113); // Ring
  servo[4].write(117); // Pinky

  // Step 1493: Fingers [118, 130, 125, 113, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(130); // Index
  servo[2].write(125); // Middle
  servo[3].write(113); // Ring
  servo[4].write(118); // Pinky

  // Step 1494: Fingers [118, 130, 126, 114, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(130); // Index
  servo[2].write(126); // Middle
  servo[3].write(114); // Ring
  servo[4].write(118); // Pinky

  delay(16);
  // Step 1495: Fingers [118, 130, 126, 114, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(130); // Index
  servo[2].write(126); // Middle
  servo[3].write(114); // Ring
  servo[4].write(118); // Pinky

  delay(15);
  // Step 1496: Fingers [118, 130, 126, 114, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(130); // Index
  servo[2].write(126); // Middle
  servo[3].write(114); // Ring
  servo[4].write(118); // Pinky

  delay(16);
  // Step 1497: Fingers [118, 130, 126, 114, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(130); // Index
  servo[2].write(126); // Middle
  servo[3].write(114); // Ring
  servo[4].write(118); // Pinky

  delay(16);
  // Step 1498: Fingers [119, 131, 126, 114, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(131); // Index
  servo[2].write(126); // Middle
  servo[3].write(114); // Ring
  servo[4].write(119); // Pinky

  // Step 1499: Fingers [120, 132, 127, 115, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(132); // Index
  servo[2].write(127); // Middle
  servo[3].write(115); // Ring
  servo[4].write(120); // Pinky

  // Step 1500: Fingers [120, 132, 127, 115, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(132); // Index
  servo[2].write(127); // Middle
  servo[3].write(115); // Ring
  servo[4].write(120); // Pinky

  // Step 1501: Fingers [121, 132, 127, 116, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(132); // Index
  servo[2].write(127); // Middle
  servo[3].write(116); // Ring
  servo[4].write(121); // Pinky

  // Step 1502: Fingers [121, 132, 127, 116, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(132); // Index
  servo[2].write(127); // Middle
  servo[3].write(116); // Ring
  servo[4].write(121); // Pinky

  // Step 1503: Fingers [121, 133, 128, 116, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(133); // Index
  servo[2].write(128); // Middle
  servo[3].write(116); // Ring
  servo[4].write(121); // Pinky

  // Step 1504: Fingers [122, 134, 128, 117, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(134); // Index
  servo[2].write(128); // Middle
  servo[3].write(117); // Ring
  servo[4].write(122); // Pinky

  // Step 1505: Fingers [122, 134, 128, 117, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(134); // Index
  servo[2].write(128); // Middle
  servo[3].write(117); // Ring
  servo[4].write(122); // Pinky

  // Step 1506: Fingers [123, 134, 129, 117, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(134); // Index
  servo[2].write(129); // Middle
  servo[3].write(117); // Ring
  servo[4].write(123); // Pinky

  // Step 1507: Fingers [123, 134, 129, 117, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(134); // Index
  servo[2].write(129); // Middle
  servo[3].write(117); // Ring
  servo[4].write(123); // Pinky

  // Step 1508: Fingers [124, 135, 129, 118, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(135); // Index
  servo[2].write(129); // Middle
  servo[3].write(118); // Ring
  servo[4].write(124); // Pinky

  // Step 1509: Fingers [125, 136, 130, 119, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(136); // Index
  servo[2].write(130); // Middle
  servo[3].write(119); // Ring
  servo[4].write(125); // Pinky

  // Step 1510: Fingers [125, 136, 130, 119, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(136); // Index
  servo[2].write(130); // Middle
  servo[3].write(119); // Ring
  servo[4].write(125); // Pinky

  // Step 1511: Fingers [125, 136, 130, 118, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(136); // Index
  servo[2].write(130); // Middle
  servo[3].write(118); // Ring
  servo[4].write(125); // Pinky

  delay(26);
  // Step 1512: Fingers [125, 136, 130, 118, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(136); // Index
  servo[2].write(130); // Middle
  servo[3].write(118); // Ring
  servo[4].write(125); // Pinky

  // Step 1513: Fingers [125, 136, 129, 118, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(136); // Index
  servo[2].write(129); // Middle
  servo[3].write(118); // Ring
  servo[4].write(125); // Pinky

  delay(17);
  // Step 1514: Fingers [125, 136, 129, 118, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(136); // Index
  servo[2].write(129); // Middle
  servo[3].write(118); // Ring
  servo[4].write(125); // Pinky

  // Step 1515: Fingers [125, 136, 129, 118, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(136); // Index
  servo[2].write(129); // Middle
  servo[3].write(118); // Ring
  servo[4].write(125); // Pinky

  // Step 1516: Fingers [125, 136, 129, 118, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(136); // Index
  servo[2].write(129); // Middle
  servo[3].write(118); // Ring
  servo[4].write(125); // Pinky

  delay(21);
  // Step 1517: Fingers [125, 136, 129, 118, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(136); // Index
  servo[2].write(129); // Middle
  servo[3].write(118); // Ring
  servo[4].write(125); // Pinky

  delay(32);
  // Step 1518: Fingers [125, 136, 129, 118, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(136); // Index
  servo[2].write(129); // Middle
  servo[3].write(118); // Ring
  servo[4].write(125); // Pinky

  delay(15);
  // Step 1519: Fingers [125, 135, 128, 118, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(135); // Index
  servo[2].write(128); // Middle
  servo[3].write(118); // Ring
  servo[4].write(125); // Pinky

  // Step 1520: Fingers [125, 135, 128, 118, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(135); // Index
  servo[2].write(128); // Middle
  servo[3].write(118); // Ring
  servo[4].write(125); // Pinky

  // Step 1521: Fingers [125, 135, 128, 118, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(135); // Index
  servo[2].write(128); // Middle
  servo[3].write(118); // Ring
  servo[4].write(125); // Pinky

  // Step 1522: Fingers [125, 135, 127, 117, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(135); // Index
  servo[2].write(127); // Middle
  servo[3].write(117); // Ring
  servo[4].write(125); // Pinky

  // Step 1523: Fingers [125, 134, 126, 116, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(134); // Index
  servo[2].write(126); // Middle
  servo[3].write(116); // Ring
  servo[4].write(125); // Pinky

  // Step 1524: Fingers [125, 134, 126, 116, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(134); // Index
  servo[2].write(126); // Middle
  servo[3].write(116); // Ring
  servo[4].write(125); // Pinky

  // Step 1525: Fingers [125, 134, 126, 116, 125] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(134); // Index
  servo[2].write(126); // Middle
  servo[3].write(116); // Ring
  servo[4].write(125); // Pinky

  delay(23);
  // Step 1526: Fingers [124, 134, 125, 116, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(134); // Index
  servo[2].write(125); // Middle
  servo[3].write(116); // Ring
  servo[4].write(124); // Pinky

  // Step 1527: Fingers [124, 134, 125, 116, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(134); // Index
  servo[2].write(125); // Middle
  servo[3].write(116); // Ring
  servo[4].write(124); // Pinky

  delay(30);
  // Step 1528: Fingers [124, 134, 125, 116, 124] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(134); // Index
  servo[2].write(125); // Middle
  servo[3].write(116); // Ring
  servo[4].write(124); // Pinky

  // Step 1529: Fingers [123, 132, 124, 114, 123] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(132); // Index
  servo[2].write(124); // Middle
  servo[3].write(114); // Ring
  servo[4].write(123); // Pinky

  // Step 1530: Fingers [122, 132, 123, 114, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(132); // Index
  servo[2].write(123); // Middle
  servo[3].write(114); // Ring
  servo[4].write(122); // Pinky

  // Step 1531: Fingers [122, 131, 122, 113, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(131); // Index
  servo[2].write(122); // Middle
  servo[3].write(113); // Ring
  servo[4].write(122); // Pinky

  // Step 1532: Fingers [122, 131, 122, 113, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(131); // Index
  servo[2].write(122); // Middle
  servo[3].write(113); // Ring
  servo[4].write(122); // Pinky

  // Step 1533: Fingers [122, 131, 122, 113, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(131); // Index
  servo[2].write(122); // Middle
  servo[3].write(113); // Ring
  servo[4].write(122); // Pinky

  // Step 1534: Fingers [122, 130, 121, 112, 122] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(130); // Index
  servo[2].write(121); // Middle
  servo[3].write(112); // Ring
  servo[4].write(122); // Pinky

  // Step 1535: Fingers [121, 130, 121, 112, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(130); // Index
  servo[2].write(121); // Middle
  servo[3].write(112); // Ring
  servo[4].write(121); // Pinky

  delay(13);
  // Step 1536: Fingers [121, 130, 121, 112, 121] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(130); // Index
  servo[2].write(121); // Middle
  servo[3].write(112); // Ring
  servo[4].write(121); // Pinky

  // Step 1537: Fingers [120, 129, 120, 111, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(129); // Index
  servo[2].write(120); // Middle
  servo[3].write(111); // Ring
  servo[4].write(120); // Pinky

  delay(20);
  // Step 1538: Fingers [120, 128, 119, 111, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(128); // Index
  servo[2].write(119); // Middle
  servo[3].write(111); // Ring
  servo[4].write(120); // Pinky

  // Step 1539: Fingers [120, 128, 119, 111, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(128); // Index
  servo[2].write(119); // Middle
  servo[3].write(111); // Ring
  servo[4].write(120); // Pinky

  delay(32);
  // Step 1540: Fingers [120, 128, 119, 111, 120] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(128); // Index
  servo[2].write(119); // Middle
  servo[3].write(111); // Ring
  servo[4].write(120); // Pinky

  delay(14);
  // Step 1541: Fingers [119, 128, 119, 110, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(128); // Index
  servo[2].write(119); // Middle
  servo[3].write(110); // Ring
  servo[4].write(119); // Pinky

  delay(15);
  // Step 1542: Fingers [119, 128, 119, 110, 119] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(128); // Index
  servo[2].write(119); // Middle
  servo[3].write(110); // Ring
  servo[4].write(119); // Pinky

  // Step 1543: Fingers [118, 127, 118, 109, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(127); // Index
  servo[2].write(118); // Middle
  servo[3].write(109); // Ring
  servo[4].write(118); // Pinky

  delay(12);
  // Step 1544: Fingers [118, 127, 117, 109, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(127); // Index
  servo[2].write(117); // Middle
  servo[3].write(109); // Ring
  servo[4].write(118); // Pinky

  // Step 1545: Fingers [118, 127, 117, 109, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(127); // Index
  servo[2].write(117); // Middle
  servo[3].write(109); // Ring
  servo[4].write(118); // Pinky

  // Step 1546: Fingers [118, 127, 117, 109, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(127); // Index
  servo[2].write(117); // Middle
  servo[3].write(109); // Ring
  servo[4].write(118); // Pinky

  // Step 1547: Fingers [117, 126, 117, 108, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(126); // Index
  servo[2].write(117); // Middle
  servo[3].write(108); // Ring
  servo[4].write(117); // Pinky

  delay(16);
  // Step 1548: Fingers [118, 126, 116, 108, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(126); // Index
  servo[2].write(116); // Middle
  servo[3].write(108); // Ring
  servo[4].write(118); // Pinky

  // Step 1549: Fingers [118, 126, 116, 108, 118] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(126); // Index
  servo[2].write(116); // Middle
  servo[3].write(108); // Ring
  servo[4].write(118); // Pinky

  // Step 1550: Fingers [117, 125, 116, 107, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(125); // Index
  servo[2].write(116); // Middle
  servo[3].write(107); // Ring
  servo[4].write(117); // Pinky

  delay(22);
  // Step 1551: Fingers [117, 125, 116, 107, 117] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(125); // Index
  servo[2].write(116); // Middle
  servo[3].write(107); // Ring
  servo[4].write(117); // Pinky

  // Step 1552: Fingers [116, 125, 115, 107, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(125); // Index
  servo[2].write(115); // Middle
  servo[3].write(107); // Ring
  servo[4].write(116); // Pinky

  delay(12);
  // Step 1553: Fingers [116, 124, 114, 106, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(124); // Index
  servo[2].write(114); // Middle
  servo[3].write(106); // Ring
  servo[4].write(116); // Pinky

  // Step 1554: Fingers [116, 124, 114, 106, 116] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(124); // Index
  servo[2].write(114); // Middle
  servo[3].write(106); // Ring
  servo[4].write(116); // Pinky

  // Step 1555: Fingers [115, 123, 114, 105, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(123); // Index
  servo[2].write(114); // Middle
  servo[3].write(105); // Ring
  servo[4].write(115); // Pinky

  // Step 1556: Fingers [115, 123, 113, 105, 115] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(123); // Index
  servo[2].write(113); // Middle
  servo[3].write(105); // Ring
  servo[4].write(115); // Pinky

  // Step 1557: Fingers [114, 122, 112, 104, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(122); // Index
  servo[2].write(112); // Middle
  servo[3].write(104); // Ring
  servo[4].write(114); // Pinky

  delay(15);
  // Step 1558: Fingers [114, 122, 112, 104, 114] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(122); // Index
  servo[2].write(112); // Middle
  servo[3].write(104); // Ring
  servo[4].write(114); // Pinky

  delay(12);
  // Step 1559: Fingers [113, 121, 111, 103, 113] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(121); // Index
  servo[2].write(111); // Middle
  servo[3].write(103); // Ring
  servo[4].write(113); // Pinky

  // Step 1560: Fingers [112, 120, 110, 102, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(120); // Index
  servo[2].write(110); // Middle
  servo[3].write(102); // Ring
  servo[4].write(112); // Pinky

  delay(19);
  // Step 1561: Fingers [112, 120, 110, 102, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(120); // Index
  servo[2].write(110); // Middle
  servo[3].write(102); // Ring
  servo[4].write(112); // Pinky

  // Step 1562: Fingers [112, 119, 109, 102, 112] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(119); // Index
  servo[2].write(109); // Middle
  servo[3].write(102); // Ring
  servo[4].write(112); // Pinky

}

// Utility Functions
void centerAllServos() {
  Serial.println("Centering all servos...");
  for(int i = 0; i < 8; i++) {
    servo[i].write(90);
    delay(100);
  }
}

void smoothMove(int servoIndex, int targetAngle, int steps = 20) {
  int currentAngle = servo[servoIndex].read();
  int stepSize = (targetAngle - currentAngle) / steps;
  
  for(int i = 0; i < steps; i++) {
    servo[servoIndex].write(currentAngle + (stepSize * i));
    delay(50);
  }
  servo[servoIndex].write(targetAngle);
}

// Individual servo control functions
void setFingers(int thumb, int index, int middle, int ring, int pinky) {
  servo[0].write(thumb);
  servo[1].write(index);
  servo[2].write(middle); 
  servo[3].write(ring);
  servo[4].write(pinky);
}

void setArm(int wristRotate, int wristTilt, int elbow) {
  servo[5].write(wristRotate);
  servo[6].write(wristTilt);
  servo[7].write(elbow);
}
