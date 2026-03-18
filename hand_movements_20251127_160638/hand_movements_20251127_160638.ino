/*
 * 8-Servo Hand Control - Generated Movement Code
 * Generated: 2025-11-27 16:06:38
 * Layers: 4
 * Total Movements: 3833
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
  
  playLayer1(); // Layer_1 (manual mode)
  delay(2000); // Pause between layers

  playLayer2(); // Layer_2 (manual mode)
  delay(2000); // Pause between layers

  playLayer3(); // Layer_3 (manual mode)
  delay(2000); // Pause between layers

  playLayer4(); // Layer_4 (cursor mode)
  delay(2000); // Pause between layers

}

// Layer 1: Layer_1 - manual mode
// Duration: 10.7s, Points: 624
void playLayer1() {
  delay(15);
  // Step 1: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  // Step 2: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(11);
  // Step 3: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(12);
  // Step 4: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(28);
  // Step 5: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(12);
  // Step 6: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(20);
  // Step 7: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(32);
  // Step 8: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(11);
  // Step 9: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(20);
  // Step 10: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(20);
  // Step 11: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  // Step 12: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  delay(21);
  // Step 13: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  // Step 14: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  // Step 15: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  delay(11);
  // Step 16: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(16);
  // Step 17: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  // Step 18: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(22);
  // Step 19: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  // Step 20: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(20);
  // Step 21: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  // Step 22: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(20);
  // Step 23: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  // Step 24: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(22);
  // Step 25: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(12);
  // Step 26: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(18);
  // Step 27: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(28);
  // Step 28: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  // Step 29: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(28);
  // Step 30: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(14);
  // Step 31: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(16);
  // Step 32: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(31);
  // Step 33: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(18);
  // Step 34: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(12);
  // Step 35: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  // Step 36: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(22);
  // Step 37: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  // Step 38: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(17);
  // Step 39: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  // Step 40: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(27);
  // Step 41: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(17);
  // Step 42: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(19);
  // Step 43: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  // Step 44: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(23);
  // Step 45: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  // Step 46: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  // Step 47: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(17);
  // Step 48: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  // Step 49: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(24);
  // Step 50: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  // Step 51: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(25);
  // Step 52: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  // Step 53: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(21);
  // Step 54: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  // Step 55: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(21);
  // Step 56: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(31);
  // Step 57: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(30);
  // Step 58: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(31);
  // Step 59: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(29);
  // Step 60: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(31);
  // Step 61: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(27);
  // Step 62: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(30);
  // Step 63: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(34);
  // Step 64: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(11);
  // Step 65: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(21);
  // Step 66: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(25);
  // Step 67: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  // Step 68: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(34);
  // Step 69: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(11);
  // Step 70: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(19);
  // Step 71: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(12);
  // Step 72: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(15);
  // Step 73: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(31);
  // Step 74: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  // Step 75: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(18);
  // Step 76: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  // Step 77: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(21);
  // Step 78: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  // Step 79: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  // Step 80: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(34);
  // Step 81: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(30);
  // Step 82: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  // Step 83: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(14);
  // Step 84: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  // Step 85: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(34);
  // Step 86: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  // Step 87: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(20);
  // Step 88: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  // Step 89: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(23);
  // Step 90: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(32);
  // Step 91: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(29);
  // Step 92: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(15);
  // Step 93: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(16);
  // Step 94: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  // Step 95: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  // Step 96: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(14);
  // Step 97: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(30);
  // Step 98: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  // Step 99: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  // Step 100: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(13);
  // Step 101: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(19);
  // Step 102: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(11);
  // Step 103: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(30);
  // Step 104: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  // Step 105: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(23);
  // Step 106: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(16);
  // Step 107: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(16);
  // Step 108: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(31);
  // Step 109: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  // Step 110: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(23);
  // Step 111: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(18);
  // Step 112: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(12);
  // Step 113: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  // Step 114: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(23);
  // Step 115: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  // Step 116: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(21);
  // Step 117: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  // Step 118: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(24);
  // Step 119: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(31);
  // Step 120: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  // Step 121: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(24);
  // Step 122: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  // Step 123: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(23);
  // Step 124: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  // Step 125: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  delay(23);
  // Step 126: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  // Step 127: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  delay(22);
  // Step 128: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  // Step 129: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  delay(19);
  // Step 130: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  // Step 131: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(33);
  // Step 132: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(31);
  // Step 133: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(31);
  // Step 134: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(13);
  // Step 135: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(17);
  // Step 136: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(30);
  // Step 137: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  // Step 138: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(24);
  // Step 139: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  // Step 140: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(21);
  // Step 141: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(16);
  // Step 142: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(13);
  // Step 143: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  // Step 144: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  // Step 145: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(14);
  // Step 146: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  // Step 147: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(19);
  // Step 148: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  // Step 149: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(24);
  // Step 150: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  // Step 151: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(16);
  // Step 152: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  // Step 153: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(24);
  // Step 154: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  // Step 155: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(35);
  // Step 156: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(19);
  // Step 157: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(12);
  // Step 158: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(31);
  // Step 159: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  // Step 160: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(19);
  // Step 161: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(31);
  // Step 162: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(20);
  // Step 163: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  // Step 164: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  // Step 165: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(18);
  // Step 166: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  // Step 167: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(14);
  // Step 168: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(14);
  // Step 169: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  // Step 170: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(32);
  // Step 171: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  // Step 172: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  delay(24);
  // Step 173: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  delay(20);
  // Step 174: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  // Step 175: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  delay(12);
  // Step 176: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  // Step 177: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  // Step 178: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(30);
  // Step 179: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(27);
  // Step 180: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(34);
  // Step 181: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  // Step 182: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(26);
  // Step 183: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(30);
  // Step 184: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(30);
  // Step 185: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(11);
  // Step 186: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(19);
  // Step 187: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(27);
  // Step 188: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(34);
  // Step 189: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  // Step 190: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(24);
  // Step 191: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(31);
  // Step 192: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  // Step 193: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(22);
  // Step 194: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(31);
  // Step 195: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(30);
  // Step 196: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(20);
  // Step 197: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(11);
  // Step 198: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(30);
  // Step 199: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(32);
  // Step 200: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(27);
  // Step 201: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(33);
  // Step 202: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(31);
  // Step 203: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(31);
  // Step 204: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(30);
  // Step 205: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  // Step 206: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(19);
  // Step 207: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(28);
  // Step 208: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  // Step 209: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  // Step 210: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(18);
  // Step 211: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(30);
  // Step 212: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(23);
  // Step 213: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  // Step 214: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(35);
  // Step 215: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(30);
  // Step 216: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(32);
  // Step 217: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  // Step 218: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(18);
  // Step 219: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(31);
  // Step 220: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(14);
  // Step 221: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(16);
  // Step 222: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(27);
  // Step 223: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(33);
  // Step 224: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  // Step 225: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(21);
  // Step 226: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(25);
  // Step 227: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(36);
  // Step 228: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  // Step 229: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(22);
  // Step 230: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(17);
  // Step 231: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(17);
  // Step 232: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(14);
  // Step 233: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(16);
  // Step 234: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(31);
  // Step 235: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  // Step 236: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(24);
  // Step 237: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(29);
  // Step 238: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(30);
  // Step 239: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(19);
  // Step 240: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(12);
  // Step 241: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(30);
  // Step 242: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(30);
  // Step 243: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(14);
  // Step 244: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  // Step 245: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  // Step 246: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(37);
  // Step 247: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(25);
  // Step 248: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  // Step 249: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(33);
  // Step 250: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(31);
  // Step 251: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(30);
  // Step 252: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(31);
  // Step 253: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(31);
  // Step 254: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(29);
  // Step 255: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  // Step 256: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(26);
  // Step 257: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(31);
  // Step 258: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(26);
  // Step 259: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  // Step 260: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(11);
  // Step 261: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(21);
  // Step 262: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(31);
  // Step 263: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(20);
  // Step 264: Fingers [-, -, -, -, -] Arm [-, 52, -]
  servo[6].write(52); // Elbow

  // Step 265: Fingers [-, -, -, -, -] Arm [-, 52, -]
  servo[6].write(52); // Elbow

  delay(33);
  // Step 266: Fingers [-, -, -, -, -] Arm [-, 52, -]
  servo[6].write(52); // Elbow

  delay(12);
  // Step 267: Fingers [-, -, -, -, -] Arm [-, 52, -]
  servo[6].write(52); // Elbow

  delay(17);
  // Step 268: Fingers [-, -, -, -, -] Arm [-, 52, -]
  servo[6].write(52); // Elbow

  // Step 269: Fingers [-, -, -, -, -] Arm [-, 52, -]
  servo[6].write(52); // Elbow

  delay(21);
  // Step 270: Fingers [-, -, -, -, -] Arm [-, 52, -]
  servo[6].write(52); // Elbow

  delay(27);
  // Step 271: Fingers [-, -, -, -, -] Arm [-, 52, -]
  servo[6].write(52); // Elbow

  // Step 272: Fingers [-, -, -, -, -] Arm [-, 53, -]
  servo[6].write(53); // Elbow

  delay(31);
  // Step 273: Fingers [-, -, -, -, -] Arm [-, 53, -]
  servo[6].write(53); // Elbow

  // Step 274: Fingers [-, -, -, -, -] Arm [-, 54, -]
  servo[6].write(54); // Elbow

  delay(25);
  // Step 275: Fingers [-, -, -, -, -] Arm [-, 54, -]
  servo[6].write(54); // Elbow

  delay(29);
  // Step 276: Fingers [-, -, -, -, -] Arm [-, 54, -]
  servo[6].write(54); // Elbow

  // Step 277: Fingers [-, -, -, -, -] Arm [-, 54, -]
  servo[6].write(54); // Elbow

  delay(26);
  // Step 278: Fingers [-, -, -, -, -] Arm [-, 54, -]
  servo[6].write(54); // Elbow

  delay(29);
  // Step 279: Fingers [-, -, -, -, -] Arm [-, 54, -]
  servo[6].write(54); // Elbow

  delay(30);
  // Step 280: Fingers [-, -, -, -, -] Arm [-, 54, -]
  servo[6].write(54); // Elbow

  // Step 281: Fingers [-, -, -, -, -] Arm [-, 55, -]
  servo[6].write(55); // Elbow

  delay(20);
  // Step 282: Fingers [-, -, -, -, -] Arm [-, 55, -]
  servo[6].write(55); // Elbow

  // Step 283: Fingers [-, -, -, -, -] Arm [-, 55, -]
  servo[6].write(55); // Elbow

  delay(33);
  // Step 284: Fingers [-, -, -, -, -] Arm [-, 55, -]
  servo[6].write(55); // Elbow

  // Step 285: Fingers [-, -, -, -, -] Arm [-, 55, -]
  servo[6].write(55); // Elbow

  delay(24);
  // Step 286: Fingers [-, -, -, -, -] Arm [-, 55, -]
  servo[6].write(55); // Elbow

  delay(28);
  // Step 287: Fingers [-, -, -, -, -] Arm [-, 55, -]
  servo[6].write(55); // Elbow

  // Step 288: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(27);
  // Step 289: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(13);
  // Step 290: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(18);
  // Step 291: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(30);
  // Step 292: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(19);
  // Step 293: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(11);
  // Step 294: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(24);
  // Step 295: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 296: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(21);
  // Step 297: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 298: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(35);
  // Step 299: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 300: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(26);
  // Step 301: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 302: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(23);
  // Step 303: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(24);
  // Step 304: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 305: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(20);
  // Step 306: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(14);
  // Step 307: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(17);
  // Step 308: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(13);
  // Step 309: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(27);
  // Step 310: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 311: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(27);
  // Step 312: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 313: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(17);
  // Step 314: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 315: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(29);
  // Step 316: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 317: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(24);
  // Step 318: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(30);
  // Step 319: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(31);
  // Step 320: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 321: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(21);
  // Step 322: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(25);
  // Step 323: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 324: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(31);
  // Step 325: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 326: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(15);
  // Step 327: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 328: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(29);
  // Step 329: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 330: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(21);
  // Step 331: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 332: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(19);
  // Step 333: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  delay(17);
  // Step 334: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 335: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 336: Fingers [-, -, -, -, -] Arm [-, 56, -]
  servo[6].write(56); // Elbow

  // Step 337: Fingers [-, -, -, -, -] Arm [-, 55, -]
  servo[6].write(55); // Elbow

  // Step 338: Fingers [-, -, -, -, -] Arm [-, 55, -]
  servo[6].write(55); // Elbow

  delay(16);
  // Step 339: Fingers [-, -, -, -, -] Arm [-, 55, -]
  servo[6].write(55); // Elbow

  // Step 340: Fingers [-, -, -, -, -] Arm [-, 55, -]
  servo[6].write(55); // Elbow

  // Step 341: Fingers [-, -, -, -, -] Arm [-, 55, -]
  servo[6].write(55); // Elbow

  delay(22);
  // Step 342: Fingers [-, -, -, -, -] Arm [-, 55, -]
  servo[6].write(55); // Elbow

  delay(18);
  // Step 343: Fingers [-, -, -, -, -] Arm [-, 54, -]
  servo[6].write(54); // Elbow

  // Step 344: Fingers [-, -, -, -, -] Arm [-, 54, -]
  servo[6].write(54); // Elbow

  // Step 345: Fingers [-, -, -, -, -] Arm [-, 54, -]
  servo[6].write(54); // Elbow

  delay(30);
  // Step 346: Fingers [-, -, -, -, -] Arm [-, 54, -]
  servo[6].write(54); // Elbow

  // Step 347: Fingers [-, -, -, -, -] Arm [-, 54, -]
  servo[6].write(54); // Elbow

  delay(25);
  // Step 348: Fingers [-, -, -, -, -] Arm [-, 54, -]
  servo[6].write(54); // Elbow

  // Step 349: Fingers [-, -, -, -, -] Arm [-, 53, -]
  servo[6].write(53); // Elbow

  // Step 350: Fingers [-, -, -, -, -] Arm [-, 52, -]
  servo[6].write(52); // Elbow

  delay(17);
  // Step 351: Fingers [-, -, -, -, -] Arm [-, 52, -]
  servo[6].write(52); // Elbow

  delay(24);
  // Step 352: Fingers [-, -, -, -, -] Arm [-, 52, -]
  servo[6].write(52); // Elbow

  // Step 353: Fingers [-, -, -, -, -] Arm [-, 52, -]
  servo[6].write(52); // Elbow

  delay(19);
  // Step 354: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  delay(12);
  // Step 355: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  // Step 356: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  // Step 357: Fingers [-, -, -, -, -] Arm [-, 51, -]
  servo[6].write(51); // Elbow

  // Step 358: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(13);
  // Step 359: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  // Step 360: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  // Step 361: Fingers [-, -, -, -, -] Arm [-, 50, -]
  servo[6].write(50); // Elbow

  delay(15);
  // Step 362: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  // Step 363: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  delay(29);
  // Step 364: Fingers [-, -, -, -, -] Arm [-, 49, -]
  servo[6].write(49); // Elbow

  // Step 365: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(19);
  // Step 366: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  // Step 367: Fingers [-, -, -, -, -] Arm [-, 48, -]
  servo[6].write(48); // Elbow

  delay(12);
  // Step 368: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  // Step 369: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  // Step 370: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  // Step 371: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  // Step 372: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  // Step 373: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  // Step 374: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(21);
  // Step 375: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  // Step 376: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(24);
  // Step 377: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  // Step 378: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(35);
  // Step 379: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  // Step 380: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(24);
  // Step 381: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  // Step 382: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  // Step 383: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(13);
  // Step 384: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(27);
  // Step 385: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  // Step 386: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  delay(30);
  // Step 387: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  // Step 388: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  delay(21);
  // Step 389: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  // Step 390: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  // Step 391: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(14);
  // Step 392: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  // Step 393: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(14);
  // Step 394: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(15);
  // Step 395: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  // Step 396: Fingers [-, -, -, -, -] Arm [-, 39, -]
  servo[6].write(39); // Elbow

  delay(19);
  // Step 397: Fingers [-, -, -, -, -] Arm [-, 39, -]
  servo[6].write(39); // Elbow

  // Step 398: Fingers [-, -, -, -, -] Arm [-, 39, -]
  servo[6].write(39); // Elbow

  delay(30);
  // Step 399: Fingers [-, -, -, -, -] Arm [-, 39, -]
  servo[6].write(39); // Elbow

  delay(28);
  // Step 400: Fingers [-, -, -, -, -] Arm [-, 39, -]
  servo[6].write(39); // Elbow

  delay(28);
  // Step 401: Fingers [-, -, -, -, -] Arm [-, 39, -]
  servo[6].write(39); // Elbow

  delay(12);
  // Step 402: Fingers [-, -, -, -, -] Arm [-, 39, -]
  servo[6].write(39); // Elbow

  // Step 403: Fingers [-, -, -, -, -] Arm [-, 38, -]
  servo[6].write(38); // Elbow

  // Step 404: Fingers [-, -, -, -, -] Arm [-, 38, -]
  servo[6].write(38); // Elbow

  delay(13);
  // Step 405: Fingers [-, -, -, -, -] Arm [-, 38, -]
  servo[6].write(38); // Elbow

  delay(18);
  // Step 406: Fingers [-, -, -, -, -] Arm [-, 38, -]
  servo[6].write(38); // Elbow

  // Step 407: Fingers [-, -, -, -, -] Arm [-, 38, -]
  servo[6].write(38); // Elbow

  delay(22);
  // Step 408: Fingers [-, -, -, -, -] Arm [-, 38, -]
  servo[6].write(38); // Elbow

  // Step 409: Fingers [-, -, -, -, -] Arm [-, 37, -]
  servo[6].write(37); // Elbow

  delay(23);
  // Step 410: Fingers [-, -, -, -, -] Arm [-, 37, -]
  servo[6].write(37); // Elbow

  // Step 411: Fingers [-, -, -, -, -] Arm [-, 37, -]
  servo[6].write(37); // Elbow

  delay(13);
  // Step 412: Fingers [-, -, -, -, -] Arm [-, 36, -]
  servo[6].write(36); // Elbow

  delay(13);
  // Step 413: Fingers [-, -, -, -, -] Arm [-, 36, -]
  servo[6].write(36); // Elbow

  delay(32);
  // Step 414: Fingers [-, -, -, -, -] Arm [-, 36, -]
  servo[6].write(36); // Elbow

  // Step 415: Fingers [-, -, -, -, -] Arm [-, 36, -]
  servo[6].write(36); // Elbow

  delay(22);
  // Step 416: Fingers [-, -, -, -, -] Arm [-, 36, -]
  servo[6].write(36); // Elbow

  delay(27);
  // Step 417: Fingers [-, -, -, -, -] Arm [-, 36, -]
  servo[6].write(36); // Elbow

  // Step 418: Fingers [-, -, -, -, -] Arm [-, 35, -]
  servo[6].write(35); // Elbow

  // Step 419: Fingers [-, -, -, -, -] Arm [-, 35, -]
  servo[6].write(35); // Elbow

  delay(25);
  // Step 420: Fingers [-, -, -, -, -] Arm [-, 35, -]
  servo[6].write(35); // Elbow

  // Step 421: Fingers [-, -, -, -, -] Arm [-, 34, -]
  servo[6].write(34); // Elbow

  // Step 422: Fingers [-, -, -, -, -] Arm [-, 34, -]
  servo[6].write(34); // Elbow

  delay(15);
  // Step 423: Fingers [-, -, -, -, -] Arm [-, 34, -]
  servo[6].write(34); // Elbow

  // Step 424: Fingers [-, -, -, -, -] Arm [-, 33, -]
  servo[6].write(33); // Elbow

  // Step 425: Fingers [-, -, -, -, -] Arm [-, 33, -]
  servo[6].write(33); // Elbow

  // Step 426: Fingers [-, -, -, -, -] Arm [-, 33, -]
  servo[6].write(33); // Elbow

  delay(12);
  // Step 427: Fingers [-, -, -, -, -] Arm [-, 33, -]
  servo[6].write(33); // Elbow

  // Step 428: Fingers [-, -, -, -, -] Arm [-, 32, -]
  servo[6].write(32); // Elbow

  // Step 429: Fingers [-, -, -, -, -] Arm [-, 32, -]
  servo[6].write(32); // Elbow

  delay(23);
  // Step 430: Fingers [-, -, -, -, -] Arm [-, 32, -]
  servo[6].write(32); // Elbow

  delay(13);
  // Step 431: Fingers [-, -, -, -, -] Arm [-, 32, -]
  servo[6].write(32); // Elbow

  delay(16);
  // Step 432: Fingers [-, -, -, -, -] Arm [-, 32, -]
  servo[6].write(32); // Elbow

  // Step 433: Fingers [-, -, -, -, -] Arm [-, 31, -]
  servo[6].write(31); // Elbow

  delay(25);
  // Step 434: Fingers [-, -, -, -, -] Arm [-, 31, -]
  servo[6].write(31); // Elbow

  // Step 435: Fingers [-, -, -, -, -] Arm [-, 31, -]
  servo[6].write(31); // Elbow

  // Step 436: Fingers [-, -, -, -, -] Arm [-, 31, -]
  servo[6].write(31); // Elbow

  delay(21);
  // Step 437: Fingers [-, -, -, -, -] Arm [-, 31, -]
  servo[6].write(31); // Elbow

  // Step 438: Fingers [-, -, -, -, -] Arm [-, 30, -]
  servo[6].write(30); // Elbow

  delay(18);
  // Step 439: Fingers [-, -, -, -, -] Arm [-, 30, -]
  servo[6].write(30); // Elbow

  // Step 440: Fingers [-, -, -, -, -] Arm [-, 30, -]
  servo[6].write(30); // Elbow

  // Step 441: Fingers [-, -, -, -, -] Arm [-, 30, -]
  servo[6].write(30); // Elbow

  delay(27);
  // Step 442: Fingers [-, -, -, -, -] Arm [-, 30, -]
  servo[6].write(30); // Elbow

  // Step 443: Fingers [-, -, -, -, -] Arm [-, 30, -]
  servo[6].write(30); // Elbow

  // Step 444: Fingers [-, -, -, -, -] Arm [-, 29, -]
  servo[6].write(29); // Elbow

  // Step 445: Fingers [-, -, -, -, -] Arm [-, 29, -]
  servo[6].write(29); // Elbow

  // Step 446: Fingers [-, -, -, -, -] Arm [-, 29, -]
  servo[6].write(29); // Elbow

  delay(17);
  // Step 447: Fingers [-, -, -, -, -] Arm [-, 29, -]
  servo[6].write(29); // Elbow

  // Step 448: Fingers [-, -, -, -, -] Arm [-, 29, -]
  servo[6].write(29); // Elbow

  delay(20);
  // Step 449: Fingers [-, -, -, -, -] Arm [-, 29, -]
  servo[6].write(29); // Elbow

  // Step 450: Fingers [-, -, -, -, -] Arm [-, 29, -]
  servo[6].write(29); // Elbow

  delay(11);
  // Step 451: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  delay(15);
  // Step 452: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  // Step 453: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  // Step 454: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  delay(15);
  // Step 455: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  delay(25);
  // Step 456: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  // Step 457: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  delay(21);
  // Step 458: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  // Step 459: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(40);
  // Step 460: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(19);
  // Step 461: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(11);
  // Step 462: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(31);
  // Step 463: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(14);
  // Step 464: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(15);
  // Step 465: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  // Step 466: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(12);
  // Step 467: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(14);
  // Step 468: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(17);
  // Step 469: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(16);
  // Step 470: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(23);
  // Step 471: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  // Step 472: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  // Step 473: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(21);
  // Step 474: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  // Step 475: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(22);
  // Step 476: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  // Step 477: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  // Step 478: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(15);
  // Step 479: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(24);
  // Step 480: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  // Step 481: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(29);
  // Step 482: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(15);
  // Step 483: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(12);
  // Step 484: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(28);
  // Step 485: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(17);
  // Step 486: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  // Step 487: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  // Step 488: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  delay(20);
  // Step 489: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  delay(15);
  // Step 490: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  delay(31);
  // Step 491: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  delay(16);
  // Step 492: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  delay(14);
  // Step 493: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  delay(30);
  // Step 494: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  // Step 495: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  delay(21);
  // Step 496: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  delay(30);
  // Step 497: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  delay(12);
  // Step 498: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  delay(17);
  // Step 499: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  // Step 500: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  delay(21);
  // Step 501: Fingers [-, -, -, -, -] Arm [-, 25, -]
  servo[6].write(25); // Elbow

  // Step 502: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(23);
  // Step 503: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  // Step 504: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(23);
  // Step 505: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  // Step 506: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(21);
  // Step 507: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(11);
  // Step 508: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  delay(19);
  // Step 509: Fingers [-, -, -, -, -] Arm [-, 26, -]
  servo[6].write(26); // Elbow

  // Step 510: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(23);
  // Step 511: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  // Step 512: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(21);
  // Step 513: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(30);
  // Step 514: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  // Step 515: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  // Step 516: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  delay(18);
  // Step 517: Fingers [-, -, -, -, -] Arm [-, 27, -]
  servo[6].write(27); // Elbow

  // Step 518: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  delay(21);
  // Step 519: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  delay(31);
  // Step 520: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  delay(11);
  // Step 521: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  delay(18);
  // Step 522: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  // Step 523: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  delay(24);
  // Step 524: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  delay(30);
  // Step 525: Fingers [-, -, -, -, -] Arm [-, 28, -]
  servo[6].write(28); // Elbow

  // Step 526: Fingers [-, -, -, -, -] Arm [-, 29, -]
  servo[6].write(29); // Elbow

  delay(28);
  // Step 527: Fingers [-, -, -, -, -] Arm [-, 29, -]
  servo[6].write(29); // Elbow

  // Step 528: Fingers [-, -, -, -, -] Arm [-, 29, -]
  servo[6].write(29); // Elbow

  // Step 529: Fingers [-, -, -, -, -] Arm [-, 29, -]
  servo[6].write(29); // Elbow

  delay(14);
  // Step 530: Fingers [-, -, -, -, -] Arm [-, 29, -]
  servo[6].write(29); // Elbow

  // Step 531: Fingers [-, -, -, -, -] Arm [-, 30, -]
  servo[6].write(30); // Elbow

  delay(21);
  // Step 532: Fingers [-, -, -, -, -] Arm [-, 30, -]
  servo[6].write(30); // Elbow

  delay(31);
  // Step 533: Fingers [-, -, -, -, -] Arm [-, 30, -]
  servo[6].write(30); // Elbow

  // Step 534: Fingers [-, -, -, -, -] Arm [-, 30, -]
  servo[6].write(30); // Elbow

  // Step 535: Fingers [-, -, -, -, -] Arm [-, 31, -]
  servo[6].write(31); // Elbow

  delay(12);
  // Step 536: Fingers [-, -, -, -, -] Arm [-, 31, -]
  servo[6].write(31); // Elbow

  delay(29);
  // Step 537: Fingers [-, -, -, -, -] Arm [-, 31, -]
  servo[6].write(31); // Elbow

  delay(14);
  // Step 538: Fingers [-, -, -, -, -] Arm [-, 31, -]
  servo[6].write(31); // Elbow

  delay(16);
  // Step 539: Fingers [-, -, -, -, -] Arm [-, 31, -]
  servo[6].write(31); // Elbow

  delay(30);
  // Step 540: Fingers [-, -, -, -, -] Arm [-, 31, -]
  servo[6].write(31); // Elbow

  delay(31);
  // Step 541: Fingers [-, -, -, -, -] Arm [-, 31, -]
  servo[6].write(31); // Elbow

  // Step 542: Fingers [-, -, -, -, -] Arm [-, 32, -]
  servo[6].write(32); // Elbow

  delay(22);
  // Step 543: Fingers [-, -, -, -, -] Arm [-, 32, -]
  servo[6].write(32); // Elbow

  // Step 544: Fingers [-, -, -, -, -] Arm [-, 32, -]
  servo[6].write(32); // Elbow

  delay(20);
  // Step 545: Fingers [-, -, -, -, -] Arm [-, 32, -]
  servo[6].write(32); // Elbow

  delay(26);
  // Step 546: Fingers [-, -, -, -, -] Arm [-, 33, -]
  servo[6].write(33); // Elbow

  // Step 547: Fingers [-, -, -, -, -] Arm [-, 33, -]
  servo[6].write(33); // Elbow

  delay(33);
  // Step 548: Fingers [-, -, -, -, -] Arm [-, 33, -]
  servo[6].write(33); // Elbow

  delay(31);
  // Step 549: Fingers [-, -, -, -, -] Arm [-, 33, -]
  servo[6].write(33); // Elbow

  delay(30);
  // Step 550: Fingers [-, -, -, -, -] Arm [-, 33, -]
  servo[6].write(33); // Elbow

  // Step 551: Fingers [-, -, -, -, -] Arm [-, 33, -]
  servo[6].write(33); // Elbow

  delay(21);
  // Step 552: Fingers [-, -, -, -, -] Arm [-, 33, -]
  servo[6].write(33); // Elbow

  // Step 553: Fingers [-, -, -, -, -] Arm [-, 34, -]
  servo[6].write(34); // Elbow

  delay(21);
  // Step 554: Fingers [-, -, -, -, -] Arm [-, 34, -]
  servo[6].write(34); // Elbow

  delay(18);
  // Step 555: Fingers [-, -, -, -, -] Arm [-, 34, -]
  servo[6].write(34); // Elbow

  delay(12);
  // Step 556: Fingers [-, -, -, -, -] Arm [-, 34, -]
  servo[6].write(34); // Elbow

  delay(21);
  // Step 557: Fingers [-, -, -, -, -] Arm [-, 35, -]
  servo[6].write(35); // Elbow

  // Step 558: Fingers [-, -, -, -, -] Arm [-, 35, -]
  servo[6].write(35); // Elbow

  delay(31);
  // Step 559: Fingers [-, -, -, -, -] Arm [-, 35, -]
  servo[6].write(35); // Elbow

  delay(14);
  // Step 560: Fingers [-, -, -, -, -] Arm [-, 36, -]
  servo[6].write(36); // Elbow

  delay(18);
  // Step 561: Fingers [-, -, -, -, -] Arm [-, 36, -]
  servo[6].write(36); // Elbow

  delay(29);
  // Step 562: Fingers [-, -, -, -, -] Arm [-, 36, -]
  servo[6].write(36); // Elbow

  // Step 563: Fingers [-, -, -, -, -] Arm [-, 36, -]
  servo[6].write(36); // Elbow

  delay(23);
  // Step 564: Fingers [-, -, -, -, -] Arm [-, 36, -]
  servo[6].write(36); // Elbow

  delay(31);
  // Step 565: Fingers [-, -, -, -, -] Arm [-, 36, -]
  servo[6].write(36); // Elbow

  delay(16);
  // Step 566: Fingers [-, -, -, -, -] Arm [-, 37, -]
  servo[6].write(37); // Elbow

  delay(13);
  // Step 567: Fingers [-, -, -, -, -] Arm [-, 37, -]
  servo[6].write(37); // Elbow

  // Step 568: Fingers [-, -, -, -, -] Arm [-, 37, -]
  servo[6].write(37); // Elbow

  delay(25);
  // Step 569: Fingers [-, -, -, -, -] Arm [-, 37, -]
  servo[6].write(37); // Elbow

  delay(11);
  // Step 570: Fingers [-, -, -, -, -] Arm [-, 38, -]
  servo[6].write(38); // Elbow

  delay(19);
  // Step 571: Fingers [-, -, -, -, -] Arm [-, 38, -]
  servo[6].write(38); // Elbow

  delay(11);
  // Step 572: Fingers [-, -, -, -, -] Arm [-, 38, -]
  servo[6].write(38); // Elbow

  delay(18);
  // Step 573: Fingers [-, -, -, -, -] Arm [-, 38, -]
  servo[6].write(38); // Elbow

  delay(20);
  // Step 574: Fingers [-, -, -, -, -] Arm [-, 39, -]
  servo[6].write(39); // Elbow

  // Step 575: Fingers [-, -, -, -, -] Arm [-, 39, -]
  servo[6].write(39); // Elbow

  delay(22);
  // Step 576: Fingers [-, -, -, -, -] Arm [-, 39, -]
  servo[6].write(39); // Elbow

  // Step 577: Fingers [-, -, -, -, -] Arm [-, 39, -]
  servo[6].write(39); // Elbow

  delay(15);
  // Step 578: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(14);
  // Step 579: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(32);
  // Step 580: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  // Step 581: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(21);
  // Step 582: Fingers [-, -, -, -, -] Arm [-, 40, -]
  servo[6].write(40); // Elbow

  delay(19);
  // Step 583: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(11);
  // Step 584: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(31);
  // Step 585: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  // Step 586: Fingers [-, -, -, -, -] Arm [-, 41, -]
  servo[6].write(41); // Elbow

  delay(13);
  // Step 587: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  // Step 588: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  delay(20);
  // Step 589: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  // Step 590: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  // Step 591: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  delay(25);
  // Step 592: Fingers [-, -, -, -, -] Arm [-, 42, -]
  servo[6].write(42); // Elbow

  delay(11);
  // Step 593: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(20);
  // Step 594: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(28);
  // Step 595: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  // Step 596: Fingers [-, -, -, -, -] Arm [-, 43, -]
  servo[6].write(43); // Elbow

  delay(19);
  // Step 597: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  // Step 598: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(29);
  // Step 599: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  // Step 600: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(22);
  // Step 601: Fingers [-, -, -, -, -] Arm [-, 44, -]
  servo[6].write(44); // Elbow

  delay(13);
  // Step 602: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(15);
  // Step 603: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  // Step 604: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  // Step 605: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  delay(17);
  // Step 606: Fingers [-, -, -, -, -] Arm [-, 45, -]
  servo[6].write(45); // Elbow

  // Step 607: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(23);
  // Step 608: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(31);
  // Step 609: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  // Step 610: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(25);
  // Step 611: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  // Step 612: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  delay(24);
  // Step 613: Fingers [-, -, -, -, -] Arm [-, 46, -]
  servo[6].write(46); // Elbow

  // Step 614: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(20);
  // Step 615: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(31);
  // Step 616: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(30);
  // Step 617: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(30);
  // Step 618: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(30);
  // Step 619: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  // Step 620: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(24);
  // Step 621: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(30);
  // Step 622: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(30);
  // Step 623: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

  delay(30);
  // Step 624: Fingers [-, -, -, -, -] Arm [-, 47, -]
  servo[6].write(47); // Elbow

}

// Layer 2: Layer_2 - manual mode
// Duration: 10.7s, Points: 641
void playLayer2() {
  // Step 1: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(29);
  // Step 2: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(28);
  // Step 3: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(32);
  // Step 4: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(32);
  // Step 5: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(27);
  // Step 6: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(31);
  // Step 7: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(32);
  // Step 8: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(30);
  // Step 9: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(30);
  // Step 10: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(30);
  // Step 11: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(30);
  // Step 12: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  // Step 13: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  // Step 14: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  // Step 15: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  // Step 16: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  // Step 17: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(13);
  // Step 18: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 19: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(11);
  // Step 20: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(26);
  // Step 21: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 22: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(17);
  // Step 23: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  // Step 24: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(32);
  // Step 25: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(25);
  // Step 26: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 27: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(14);
  // Step 28: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(14);
  // Step 29: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(35);
  // Step 30: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 31: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(23);
  // Step 32: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(13);
  // Step 33: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(17);
  // Step 34: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 35: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(18);
  // Step 36: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(34);
  // Step 37: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 38: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(25);
  // Step 39: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  // Step 40: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(21);
  // Step 41: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(31);
  // Step 42: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(11);
  // Step 43: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(19);
  // Step 44: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(13);
  // Step 45: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(17);
  // Step 46: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(14);
  // Step 47: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(14);
  // Step 48: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  // Step 49: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(24);
  // Step 50: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  // Step 51: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(11);
  // Step 52: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(14);
  // Step 53: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(16);
  // Step 54: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  // Step 55: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  // Step 56: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  delay(34);
  // Step 57: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  // Step 58: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(20);
  // Step 59: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(31);
  // Step 60: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(30);
  // Step 61: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(23);
  // Step 62: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 63: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(37);
  // Step 64: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(15);
  // Step 65: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(16);
  // Step 66: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(31);
  // Step 67: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(30);
  // Step 68: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(30);
  // Step 69: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(30);
  // Step 70: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(33);
  // Step 71: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(28);
  // Step 72: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(31);
  // Step 73: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(30);
  // Step 74: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(32);
  // Step 75: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(17);
  // Step 76: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(13);
  // Step 77: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(30);
  // Step 78: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 79: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(24);
  // Step 80: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(20);
  // Step 81: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 82: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(13);
  // Step 83: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(15);
  // Step 84: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 85: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(20);
  // Step 86: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(28);
  // Step 87: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 88: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(17);
  // Step 89: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  // Step 90: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(13);
  // Step 91: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(13);
  // Step 92: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  // Step 93: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(22);
  // Step 94: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(30);
  // Step 95: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(30);
  // Step 96: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(32);
  // Step 97: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(29);
  // Step 98: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(23);
  // Step 99: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 100: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(31);
  // Step 101: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(17);
  // Step 102: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(14);
  // Step 103: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(30);
  // Step 104: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 105: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(23);
  // Step 106: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(18);
  // Step 107: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(12);
  // Step 108: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(27);
  // Step 109: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 110: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(33);
  // Step 111: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 112: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(20);
  // Step 113: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 114: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 115: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(15);
  // Step 116: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 117: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(17);
  // Step 118: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 119: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(37);
  // Step 120: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 121: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(23);
  // Step 122: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 123: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(22);
  // Step 124: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 125: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(19);
  // Step 126: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 127: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(11);
  // Step 128: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(16);
  // Step 129: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(16);
  // Step 130: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 131: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 132: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(19);
  // Step 133: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 134: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 135: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(12);
  // Step 136: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 137: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(21);
  // Step 138: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  // Step 139: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  // Step 140: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(20);
  // Step 141: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  // Step 142: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(35);
  // Step 143: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  // Step 144: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(16);
  // Step 145: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 146: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(31);
  // Step 147: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 148: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(29);
  // Step 149: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(29);
  // Step 150: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 151: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 152: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(19);
  // Step 153: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 154: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(14);
  // Step 155: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 156: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(34);
  // Step 157: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 158: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  delay(23);
  // Step 159: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  // Step 160: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(26);
  // Step 161: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  // Step 162: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(22);
  // Step 163: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  // Step 164: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(24);
  // Step 165: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(31);
  // Step 166: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(31);
  // Step 167: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  // Step 168: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(21);
  // Step 169: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  // Step 170: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(24);
  // Step 171: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  // Step 172: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(23);
  // Step 173: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  // Step 174: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(23);
  // Step 175: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(17);
  // Step 176: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(14);
  // Step 177: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  // Step 178: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 179: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 180: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 181: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(28);
  // Step 182: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 183: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(19);
  // Step 184: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 185: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(20);
  // Step 186: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  // Step 187: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(24);
  // Step 188: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  // Step 189: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(21);
  // Step 190: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 191: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 192: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(30);
  // Step 193: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 194: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 195: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(14);
  // Step 196: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 197: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(20);
  // Step 198: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(31);
  // Step 199: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(12);
  // Step 200: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(18);
  // Step 201: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(12);
  // Step 202: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(17);
  // Step 203: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(30);
  // Step 204: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  // Step 205: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(23);
  // Step 206: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(24);
  // Step 207: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  // Step 208: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(28);
  // Step 209: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(24);
  // Step 210: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  // Step 211: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(21);
  // Step 212: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  // Step 213: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(29);
  // Step 214: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(29);
  // Step 215: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  // Step 216: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(27);
  // Step 217: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(15);
  // Step 218: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(14);
  // Step 219: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  // Step 220: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(24);
  // Step 221: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  // Step 222: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  // Step 223: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(12);
  // Step 224: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  // Step 225: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(19);
  // Step 226: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 227: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(16);
  // Step 228: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 229: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 230: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(12);
  // Step 231: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(16);
  // Step 232: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  // Step 233: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  // Step 234: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(14);
  // Step 235: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 236: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(23);
  // Step 237: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 238: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(27);
  // Step 239: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 240: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 241: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(14);
  // Step 242: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(17);
  // Step 243: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(15);
  // Step 244: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  // Step 245: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(25);
  // Step 246: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(31);
  // Step 247: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(11);
  // Step 248: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(18);
  // Step 249: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  // Step 250: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(23);
  // Step 251: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(28);
  // Step 252: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(15);
  // Step 253: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(16);
  // Step 254: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  // Step 255: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(22);
  // Step 256: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(31);
  // Step 257: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  // Step 258: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(20);
  // Step 259: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(27);
  // Step 260: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  // Step 261: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(26);
  // Step 262: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  // Step 263: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(26);
  // Step 264: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  // Step 265: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  // Step 266: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(17);
  // Step 267: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(30);
  // Step 268: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  // Step 269: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  delay(18);
  // Step 270: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 271: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(30);
  // Step 272: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 273: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 274: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(22);
  // Step 275: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 276: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(25);
  // Step 277: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 278: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(18);
  // Step 279: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 280: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(37);
  // Step 281: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 282: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(26);
  // Step 283: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 284: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(26);
  // Step 285: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  // Step 286: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(24);
  // Step 287: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(31);
  // Step 288: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(17);
  // Step 289: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(13);
  // Step 290: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(26);
  // Step 291: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 292: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(30);
  // Step 293: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 294: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(24);
  // Step 295: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 296: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 297: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(22);
  // Step 298: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 299: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(20);
  // Step 300: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(31);
  // Step 301: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(31);
  // Step 302: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 303: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(21);
  // Step 304: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(27);
  // Step 305: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 306: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(25);
  // Step 307: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 308: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(14);
  // Step 309: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 310: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(26);
  // Step 311: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 312: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 313: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(11);
  // Step 314: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 315: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 316: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(11);
  // Step 317: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  // Step 318: Fingers [-, -, -, -, -] Arm [64, -, -]
  servo[5].write(64); // Shoulder

  delay(17);
  // Step 319: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(13);
  // Step 320: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 321: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(16);
  // Step 322: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 323: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  delay(31);
  // Step 324: Fingers [-, -, -, -, -] Arm [65, -, -]
  servo[5].write(65); // Shoulder

  // Step 325: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 326: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  delay(25);
  // Step 327: Fingers [-, -, -, -, -] Arm [66, -, -]
  servo[5].write(66); // Shoulder

  // Step 328: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(11);
  // Step 329: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(11);
  // Step 330: Fingers [-, -, -, -, -] Arm [67, -, -]
  servo[5].write(67); // Shoulder

  delay(12);
  // Step 331: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(16);
  // Step 332: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 333: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(23);
  // Step 334: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 335: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 336: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(14);
  // Step 337: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(17);
  // Step 338: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 339: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 340: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(11);
  // Step 341: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(21);
  // Step 342: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(25);
  // Step 343: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  // Step 344: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  delay(20);
  // Step 345: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  // Step 346: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  // Step 347: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  // Step 348: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(14);
  // Step 349: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  // Step 350: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  // Step 351: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(19);
  // Step 352: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(15);
  // Step 353: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(24);
  // Step 354: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  // Step 355: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(25);
  // Step 356: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(14);
  // Step 357: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(15);
  // Step 358: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  // Step 359: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  // Step 360: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(11);
  // Step 361: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  // Step 362: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(35);
  // Step 363: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  // Step 364: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(21);
  // Step 365: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(28);
  // Step 366: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  // Step 367: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(25);
  // Step 368: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 369: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 370: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(17);
  // Step 371: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(29);
  // Step 372: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 373: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(25);
  // Step 374: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(24);
  // Step 375: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  // Step 376: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(33);
  // Step 377: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(11);
  // Step 378: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(18);
  // Step 379: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(12);
  // Step 380: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(18);
  // Step 381: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(31);
  // Step 382: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(22);
  // Step 383: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 384: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(34);
  // Step 385: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(31);
  // Step 386: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(17);
  // Step 387: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(11);
  // Step 388: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 389: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(23);
  // Step 390: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(31);
  // Step 391: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(31);
  // Step 392: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(30);
  // Step 393: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  // Step 394: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(24);
  // Step 395: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(33);
  // Step 396: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  // Step 397: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(21);
  // Step 398: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(30);
  // Step 399: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(30);
  // Step 400: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(30);
  // Step 401: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  // Step 402: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(26);
  // Step 403: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(30);
  // Step 404: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  // Step 405: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  delay(20);
  // Step 406: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  delay(20);
  // Step 407: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  delay(11);
  // Step 408: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  delay(31);
  // Step 409: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  // Step 410: Fingers [-, -, -, -, -] Arm [83, -, -]
  servo[5].write(83); // Shoulder

  // Step 411: Fingers [-, -, -, -, -] Arm [83, -, -]
  servo[5].write(83); // Shoulder

  // Step 412: Fingers [-, -, -, -, -] Arm [83, -, -]
  servo[5].write(83); // Shoulder

  // Step 413: Fingers [-, -, -, -, -] Arm [83, -, -]
  servo[5].write(83); // Shoulder

  delay(29);
  // Step 414: Fingers [-, -, -, -, -] Arm [83, -, -]
  servo[5].write(83); // Shoulder

  delay(33);
  // Step 415: Fingers [-, -, -, -, -] Arm [83, -, -]
  servo[5].write(83); // Shoulder

  delay(31);
  // Step 416: Fingers [-, -, -, -, -] Arm [83, -, -]
  servo[5].write(83); // Shoulder

  // Step 417: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(24);
  // Step 418: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(30);
  // Step 419: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  // Step 420: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(22);
  // Step 421: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(22);
  // Step 422: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  // Step 423: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(31);
  // Step 424: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(22);
  // Step 425: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  // Step 426: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(35);
  // Step 427: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(30);
  // Step 428: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(32);
  // Step 429: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(30);
  // Step 430: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(30);
  // Step 431: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  // Step 432: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(24);
  // Step 433: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(30);
  // Step 434: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  // Step 435: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(17);
  // Step 436: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  // Step 437: Fingers [-, -, -, -, -] Arm [84, -, -]
  servo[5].write(84); // Shoulder

  delay(21);
  // Step 438: Fingers [-, -, -, -, -] Arm [83, -, -]
  servo[5].write(83); // Shoulder

  // Step 439: Fingers [-, -, -, -, -] Arm [83, -, -]
  servo[5].write(83); // Shoulder

  // Step 440: Fingers [-, -, -, -, -] Arm [83, -, -]
  servo[5].write(83); // Shoulder

  delay(16);
  // Step 441: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  // Step 442: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  delay(11);
  // Step 443: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  // Step 444: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  // Step 445: Fingers [-, -, -, -, -] Arm [82, -, -]
  servo[5].write(82); // Shoulder

  delay(17);
  // Step 446: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  // Step 447: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(14);
  // Step 448: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  delay(15);
  // Step 449: Fingers [-, -, -, -, -] Arm [81, -, -]
  servo[5].write(81); // Shoulder

  // Step 450: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  // Step 451: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  delay(16);
  // Step 452: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  // Step 453: Fingers [-, -, -, -, -] Arm [80, -, -]
  servo[5].write(80); // Shoulder

  // Step 454: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(12);
  // Step 455: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 456: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(25);
  // Step 457: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 458: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(13);
  // Step 459: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  delay(22);
  // Step 460: Fingers [-, -, -, -, -] Arm [79, -, -]
  servo[5].write(79); // Shoulder

  // Step 461: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(16);
  // Step 462: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  // Step 463: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(27);
  // Step 464: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 465: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(31);
  // Step 466: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 467: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(16);
  // Step 468: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 469: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(27);
  // Step 470: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(25);
  // Step 471: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 472: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(27);
  // Step 473: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 474: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(21);
  // Step 475: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(26);
  // Step 476: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 477: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(23);
  // Step 478: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(24);
  // Step 479: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  // Step 480: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(25);
  // Step 481: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  // Step 482: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(23);
  // Step 483: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  // Step 484: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(30);
  // Step 485: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(14);
  // Step 486: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(15);
  // Step 487: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(24);
  // Step 488: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  // Step 489: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  // Step 490: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(21);
  // Step 491: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(31);
  // Step 492: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(30);
  // Step 493: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(19);
  // Step 494: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(12);
  // Step 495: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  // Step 496: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(21);
  // Step 497: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(30);
  // Step 498: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(31);
  // Step 499: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  // Step 500: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  delay(24);
  // Step 501: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  // Step 502: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(21);
  // Step 503: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 504: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 505: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(12);
  // Step 506: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(18);
  // Step 507: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 508: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 509: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(31);
  // Step 510: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 511: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(25);
  // Step 512: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(24);
  // Step 513: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 514: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(33);
  // Step 515: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(31);
  // Step 516: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(30);
  // Step 517: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 518: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(20);
  // Step 519: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(16);
  // Step 520: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(17);
  // Step 521: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(11);
  // Step 522: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(17);
  // Step 523: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(24);
  // Step 524: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 525: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(33);
  // Step 526: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 527: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(23);
  // Step 528: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(11);
  // Step 529: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(20);
  // Step 530: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(27);
  // Step 531: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 532: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(22);
  // Step 533: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(16);
  // Step 534: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(18);
  // Step 535: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 536: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(21);
  // Step 537: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(17);
  // Step 538: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 539: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 540: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(33);
  // Step 541: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  // Step 542: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(21);
  // Step 543: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(28);
  // Step 544: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(13);
  // Step 545: Fingers [-, -, -, -, -] Arm [68, -, -]
  servo[5].write(68); // Shoulder

  delay(12);
  // Step 546: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 547: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(20);
  // Step 548: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 549: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(31);
  // Step 550: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 551: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(21);
  // Step 552: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 553: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  delay(21);
  // Step 554: Fingers [-, -, -, -, -] Arm [69, -, -]
  servo[5].write(69); // Shoulder

  // Step 555: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 556: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(13);
  // Step 557: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 558: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(34);
  // Step 559: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  delay(30);
  // Step 560: Fingers [-, -, -, -, -] Arm [70, -, -]
  servo[5].write(70); // Shoulder

  // Step 561: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  // Step 562: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  delay(14);
  // Step 563: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  delay(30);
  // Step 564: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  delay(31);
  // Step 565: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  delay(30);
  // Step 566: Fingers [-, -, -, -, -] Arm [71, -, -]
  servo[5].write(71); // Shoulder

  // Step 567: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(22);
  // Step 568: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(30);
  // Step 569: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(11);
  // Step 570: Fingers [-, -, -, -, -] Arm [72, -, -]
  servo[5].write(72); // Shoulder

  delay(16);
  // Step 571: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  // Step 572: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(31);
  // Step 573: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(15);
  // Step 574: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(16);
  // Step 575: Fingers [-, -, -, -, -] Arm [73, -, -]
  servo[5].write(73); // Shoulder

  delay(22);
  // Step 576: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  // Step 577: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(28);
  // Step 578: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  // Step 579: Fingers [-, -, -, -, -] Arm [74, -, -]
  servo[5].write(74); // Shoulder

  delay(16);
  // Step 580: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  // Step 581: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(33);
  // Step 582: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  // Step 583: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(29);
  // Step 584: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(25);
  // Step 585: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 586: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(16);
  // Step 587: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(14);
  // Step 588: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(17);
  // Step 589: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(15);
  // Step 590: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 591: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(24);
  // Step 592: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(14);
  // Step 593: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(17);
  // Step 594: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(30);
  // Step 595: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 596: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(23);
  // Step 597: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(30);
  // Step 598: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 599: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(12);
  // Step 600: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(11);
  // Step 601: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(27);
  // Step 602: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(32);
  // Step 603: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 604: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 605: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(18);
  // Step 606: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 607: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(22);
  // Step 608: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(33);
  // Step 609: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  // Step 610: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(21);
  // Step 611: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(30);
  // Step 612: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  // Step 613: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(20);
  // Step 614: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  // Step 615: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(27);
  // Step 616: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  // Step 617: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  delay(24);
  // Step 618: Fingers [-, -, -, -, -] Arm [78, -, -]
  servo[5].write(78); // Shoulder

  // Step 619: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(24);
  // Step 620: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 621: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 622: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(17);
  // Step 623: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(23);
  // Step 624: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 625: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  delay(34);
  // Step 626: Fingers [-, -, -, -, -] Arm [77, -, -]
  servo[5].write(77); // Shoulder

  // Step 627: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 628: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 629: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 630: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(32);
  // Step 631: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 632: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  delay(21);
  // Step 633: Fingers [-, -, -, -, -] Arm [76, -, -]
  servo[5].write(76); // Shoulder

  // Step 634: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(21);
  // Step 635: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(31);
  // Step 636: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(32);
  // Step 637: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(13);
  // Step 638: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(17);
  // Step 639: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  // Step 640: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

  delay(17);
  // Step 641: Fingers [-, -, -, -, -] Arm [75, -, -]
  servo[5].write(75); // Shoulder

}

// Layer 3: Layer_3 - manual mode
// Duration: 10.7s, Points: 1255
void playLayer3() {
  delay(13);
  // Step 1: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  delay(32);
  // Step 2: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 3: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  delay(18);
  // Step 4: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  delay(30);
  // Step 5: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  delay(33);
  // Step 6: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 7: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 8: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  delay(15);
  // Step 9: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 10: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 11: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 12: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 13: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 14: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 15: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 16: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 17: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 18: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 19: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 20: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 21: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 22: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 23: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 24: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  // Step 25: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 26: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 27: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 28: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 29: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 30: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 31: Fingers [-, -, -, -, -] Arm [-, -, 30]
  servo[7].write(30); // Wrist

  // Step 32: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 33: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  // Step 34: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  // Step 35: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  // Step 36: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  // Step 37: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  // Step 38: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 39: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 40: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 41: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  delay(13);
  // Step 42: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  delay(15);
  // Step 43: Fingers [-, -, -, -, -] Arm [-, -, 23]
  servo[7].write(23); // Wrist

  // Step 44: Fingers [-, -, -, -, -] Arm [-, -, 23]
  servo[7].write(23); // Wrist

  // Step 45: Fingers [-, -, -, -, -] Arm [-, -, 23]
  servo[7].write(23); // Wrist

  delay(12);
  // Step 46: Fingers [-, -, -, -, -] Arm [-, -, 22]
  servo[7].write(22); // Wrist

  // Step 47: Fingers [-, -, -, -, -] Arm [-, -, 22]
  servo[7].write(22); // Wrist

  // Step 48: Fingers [-, -, -, -, -] Arm [-, -, 22]
  servo[7].write(22); // Wrist

  // Step 49: Fingers [-, -, -, -, -] Arm [-, -, 21]
  servo[7].write(21); // Wrist

  // Step 50: Fingers [-, -, -, -, -] Arm [-, -, 21]
  servo[7].write(21); // Wrist

  delay(13);
  // Step 51: Fingers [-, -, -, -, -] Arm [-, -, 20]
  servo[7].write(20); // Wrist

  // Step 52: Fingers [-, -, -, -, -] Arm [-, -, 20]
  servo[7].write(20); // Wrist

  // Step 53: Fingers [-, -, -, -, -] Arm [-, -, 19]
  servo[7].write(19); // Wrist

  // Step 54: Fingers [-, -, -, -, -] Arm [-, -, 19]
  servo[7].write(19); // Wrist

  // Step 55: Fingers [-, -, -, -, -] Arm [-, -, 18]
  servo[7].write(18); // Wrist

  // Step 56: Fingers [-, -, -, -, -] Arm [-, -, 18]
  servo[7].write(18); // Wrist

  // Step 57: Fingers [-, -, -, -, -] Arm [-, -, 18]
  servo[7].write(18); // Wrist

  // Step 58: Fingers [-, -, -, -, -] Arm [-, -, 17]
  servo[7].write(17); // Wrist

  // Step 59: Fingers [-, -, -, -, -] Arm [-, -, 16]
  servo[7].write(16); // Wrist

  delay(20);
  // Step 60: Fingers [-, -, -, -, -] Arm [-, -, 16]
  servo[7].write(16); // Wrist

  // Step 61: Fingers [-, -, -, -, -] Arm [-, -, 16]
  servo[7].write(16); // Wrist

  // Step 62: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  delay(17);
  // Step 63: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  delay(32);
  // Step 64: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  delay(29);
  // Step 65: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  delay(30);
  // Step 66: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  // Step 67: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  delay(21);
  // Step 68: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  // Step 69: Fingers [-, -, -, -, -] Arm [-, -, 14]
  servo[7].write(14); // Wrist

  // Step 70: Fingers [-, -, -, -, -] Arm [-, -, 14]
  servo[7].write(14); // Wrist

  // Step 71: Fingers [-, -, -, -, -] Arm [-, -, 13]
  servo[7].write(13); // Wrist

  // Step 72: Fingers [-, -, -, -, -] Arm [-, -, 13]
  servo[7].write(13); // Wrist

  // Step 73: Fingers [-, -, -, -, -] Arm [-, -, 13]
  servo[7].write(13); // Wrist

  // Step 74: Fingers [-, -, -, -, -] Arm [-, -, 13]
  servo[7].write(13); // Wrist

  delay(13);
  // Step 75: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  delay(12);
  // Step 76: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  // Step 77: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  delay(19);
  // Step 78: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  // Step 79: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  // Step 80: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  delay(15);
  // Step 81: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  delay(16);
  // Step 82: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  delay(16);
  // Step 83: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  // Step 84: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  delay(24);
  // Step 85: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  delay(31);
  // Step 86: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  // Step 87: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  delay(22);
  // Step 88: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  // Step 89: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  // Step 90: Fingers [-, -, -, -, -] Arm [-, -, 11]
  servo[7].write(11); // Wrist

  delay(13);
  // Step 91: Fingers [-, -, -, -, -] Arm [-, -, 11]
  servo[7].write(11); // Wrist

  delay(20);
  // Step 92: Fingers [-, -, -, -, -] Arm [-, -, 11]
  servo[7].write(11); // Wrist

  // Step 93: Fingers [-, -, -, -, -] Arm [-, -, 11]
  servo[7].write(11); // Wrist

  delay(16);
  // Step 94: Fingers [-, -, -, -, -] Arm [-, -, 11]
  servo[7].write(11); // Wrist

  // Step 95: Fingers [-, -, -, -, -] Arm [-, -, 11]
  servo[7].write(11); // Wrist

  // Step 96: Fingers [-, -, -, -, -] Arm [-, -, 11]
  servo[7].write(11); // Wrist

  // Step 97: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  // Step 98: Fingers [-, -, -, -, -] Arm [-, -, 12]
  servo[7].write(12); // Wrist

  // Step 99: Fingers [-, -, -, -, -] Arm [-, -, 13]
  servo[7].write(13); // Wrist

  // Step 100: Fingers [-, -, -, -, -] Arm [-, -, 13]
  servo[7].write(13); // Wrist

  // Step 101: Fingers [-, -, -, -, -] Arm [-, -, 13]
  servo[7].write(13); // Wrist

  // Step 102: Fingers [-, -, -, -, -] Arm [-, -, 14]
  servo[7].write(14); // Wrist

  // Step 103: Fingers [-, -, -, -, -] Arm [-, -, 14]
  servo[7].write(14); // Wrist

  delay(13);
  // Step 104: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  // Step 105: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  // Step 106: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  delay(27);
  // Step 107: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  // Step 108: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  delay(20);
  // Step 109: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  // Step 110: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  delay(22);
  // Step 111: Fingers [-, -, -, -, -] Arm [-, -, 15]
  servo[7].write(15); // Wrist

  delay(16);
  // Step 112: Fingers [-, -, -, -, -] Arm [-, -, 16]
  servo[7].write(16); // Wrist

  delay(15);
  // Step 113: Fingers [-, -, -, -, -] Arm [-, -, 16]
  servo[7].write(16); // Wrist

  // Step 114: Fingers [-, -, -, -, -] Arm [-, -, 16]
  servo[7].write(16); // Wrist

  // Step 115: Fingers [-, -, -, -, -] Arm [-, -, 17]
  servo[7].write(17); // Wrist

  // Step 116: Fingers [-, -, -, -, -] Arm [-, -, 18]
  servo[7].write(18); // Wrist

  // Step 117: Fingers [-, -, -, -, -] Arm [-, -, 18]
  servo[7].write(18); // Wrist

  // Step 118: Fingers [-, -, -, -, -] Arm [-, -, 18]
  servo[7].write(18); // Wrist

  // Step 119: Fingers [-, -, -, -, -] Arm [-, -, 19]
  servo[7].write(19); // Wrist

  // Step 120: Fingers [-, -, -, -, -] Arm [-, -, 19]
  servo[7].write(19); // Wrist

  delay(13);
  // Step 121: Fingers [-, -, -, -, -] Arm [-, -, 20]
  servo[7].write(20); // Wrist

  // Step 122: Fingers [-, -, -, -, -] Arm [-, -, 20]
  servo[7].write(20); // Wrist

  // Step 123: Fingers [-, -, -, -, -] Arm [-, -, 20]
  servo[7].write(20); // Wrist

  // Step 124: Fingers [-, -, -, -, -] Arm [-, -, 21]
  servo[7].write(21); // Wrist

  // Step 125: Fingers [-, -, -, -, -] Arm [-, -, 21]
  servo[7].write(21); // Wrist

  // Step 126: Fingers [-, -, -, -, -] Arm [-, -, 21]
  servo[7].write(21); // Wrist

  // Step 127: Fingers [-, -, -, -, -] Arm [-, -, 21]
  servo[7].write(21); // Wrist

  // Step 128: Fingers [-, -, -, -, -] Arm [-, -, 22]
  servo[7].write(22); // Wrist

  delay(13);
  // Step 129: Fingers [-, -, -, -, -] Arm [-, -, 22]
  servo[7].write(22); // Wrist

  // Step 130: Fingers [-, -, -, -, -] Arm [-, -, 22]
  servo[7].write(22); // Wrist

  delay(30);
  // Step 131: Fingers [-, -, -, -, -] Arm [-, -, 22]
  servo[7].write(22); // Wrist

  // Step 132: Fingers [-, -, -, -, -] Arm [-, -, 23]
  servo[7].write(23); // Wrist

  // Step 133: Fingers [-, -, -, -, -] Arm [-, -, 23]
  servo[7].write(23); // Wrist

  delay(17);
  // Step 134: Fingers [-, -, -, -, -] Arm [-, -, 23]
  servo[7].write(23); // Wrist

  // Step 135: Fingers [-, -, -, -, -] Arm [-, -, 23]
  servo[7].write(23); // Wrist

  delay(22);
  // Step 136: Fingers [-, -, -, -, -] Arm [-, -, 23]
  servo[7].write(23); // Wrist

  // Step 137: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 138: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 139: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 140: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 141: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 142: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  // Step 143: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  // Step 144: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  // Step 145: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  // Step 146: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  delay(13);
  // Step 147: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 148: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 149: Fingers [-, -, -, -, -] Arm [-, -, 30]
  servo[7].write(30); // Wrist

  // Step 150: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 151: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 152: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 153: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  delay(15);
  // Step 154: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 155: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 156: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 157: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  delay(14);
  // Step 158: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 159: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  delay(16);
  // Step 160: Fingers [-, -, -, -, -] Arm [-, -, 35]
  servo[7].write(35); // Wrist

  // Step 161: Fingers [-, -, -, -, -] Arm [-, -, 35]
  servo[7].write(35); // Wrist

  delay(13);
  // Step 162: Fingers [-, -, -, -, -] Arm [-, -, 35]
  servo[7].write(35); // Wrist

  // Step 163: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 164: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 165: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 166: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  // Step 167: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  // Step 168: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  // Step 169: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 170: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 171: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 172: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 173: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 174: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 175: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 176: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 177: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 178: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 179: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 180: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 181: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 182: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 183: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 184: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 185: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 186: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 187: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(15);
  // Step 188: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 189: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 190: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(16);
  // Step 191: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 192: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(35);
  // Step 193: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(25);
  // Step 194: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 195: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(13);
  // Step 196: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(16);
  // Step 197: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 198: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 199: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 200: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 201: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 202: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 203: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 204: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 205: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 206: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 207: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 208: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 209: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 210: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 211: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 212: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 213: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 214: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 215: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 216: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 217: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 218: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  delay(16);
  // Step 219: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 220: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 221: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 222: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 223: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 224: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  delay(12);
  // Step 225: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  delay(15);
  // Step 226: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 227: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 228: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 229: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 230: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 231: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 232: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 233: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 234: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 235: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 236: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 237: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 238: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 239: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 240: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 241: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 242: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 243: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 244: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 245: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 246: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 247: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 248: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 249: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  delay(14);
  // Step 250: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 251: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  delay(11);
  // Step 252: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 253: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 254: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 255: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 256: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 257: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 258: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 259: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 260: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 261: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  delay(14);
  // Step 262: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 263: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 264: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  delay(13);
  // Step 265: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 266: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 267: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 268: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 269: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 270: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 271: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 272: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  delay(11);
  // Step 273: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 274: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 275: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  delay(17);
  // Step 276: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 277: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  delay(21);
  // Step 278: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  delay(12);
  // Step 279: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 280: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 281: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 282: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 283: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 284: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 285: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 286: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 287: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 288: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 289: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 290: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 291: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 292: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 293: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  delay(13);
  // Step 294: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 295: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 296: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 297: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 298: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 299: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 300: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(24);
  // Step 301: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 302: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 303: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(14);
  // Step 304: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 305: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(29);
  // Step 306: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 307: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 308: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(16);
  // Step 309: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(15);
  // Step 310: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(17);
  // Step 311: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(15);
  // Step 312: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(15);
  // Step 313: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(31);
  // Step 314: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(30);
  // Step 315: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 316: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 317: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(19);
  // Step 318: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 319: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(14);
  // Step 320: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 321: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  delay(32);
  // Step 322: Fingers [-, -, -, -, -] Arm [-, -, 103]
  servo[7].write(103); // Wrist

  // Step 323: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  // Step 324: Fingers [-, -, -, -, -] Arm [-, -, 102]
  servo[7].write(102); // Wrist

  delay(15);
  // Step 325: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 326: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  delay(13);
  // Step 327: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  delay(15);
  // Step 328: Fingers [-, -, -, -, -] Arm [-, -, 101]
  servo[7].write(101); // Wrist

  // Step 329: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 330: Fingers [-, -, -, -, -] Arm [-, -, 100]
  servo[7].write(100); // Wrist

  // Step 331: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 332: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  delay(13);
  // Step 333: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  delay(14);
  // Step 334: Fingers [-, -, -, -, -] Arm [-, -, 99]
  servo[7].write(99); // Wrist

  // Step 335: Fingers [-, -, -, -, -] Arm [-, -, 98]
  servo[7].write(98); // Wrist

  // Step 336: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  delay(16);
  // Step 337: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 338: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 339: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  delay(12);
  // Step 340: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 341: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 342: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 343: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 344: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 345: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 346: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 347: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 348: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 349: Fingers [-, -, -, -, -] Arm [-, -, 89]
  servo[7].write(89); // Wrist

  // Step 350: Fingers [-, -, -, -, -] Arm [-, -, 89]
  servo[7].write(89); // Wrist

  // Step 351: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 352: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  delay(16);
  // Step 353: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 354: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 355: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 356: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 357: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 358: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  delay(14);
  // Step 359: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 360: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 361: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 362: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 363: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 364: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 365: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 366: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 367: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 368: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 369: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 370: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  delay(11);
  // Step 371: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 372: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 373: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 374: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 375: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 376: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 377: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 378: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 379: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 380: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 381: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  // Step 382: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  // Step 383: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 384: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 385: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 386: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 387: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 388: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  delay(23);
  // Step 389: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 390: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  delay(16);
  // Step 391: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 392: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  delay(13);
  // Step 393: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 394: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 395: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 396: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 397: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 398: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 399: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 400: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  delay(15);
  // Step 401: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 402: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 403: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  delay(11);
  // Step 404: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 405: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 406: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 407: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 408: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  delay(14);
  // Step 409: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 410: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 411: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 412: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 413: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 414: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 415: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 416: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 417: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 418: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 419: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 420: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 421: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 422: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 423: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 424: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 425: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 426: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 427: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 428: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 429: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 430: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  delay(16);
  // Step 431: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 432: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 433: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 434: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  delay(16);
  // Step 435: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  delay(11);
  // Step 436: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 437: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 438: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 439: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 440: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 441: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 442: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 443: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 444: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 445: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 446: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 447: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  // Step 448: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  delay(13);
  // Step 449: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  delay(14);
  // Step 450: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 451: Fingers [-, -, -, -, -] Arm [-, -, 35]
  servo[7].write(35); // Wrist

  // Step 452: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  delay(15);
  // Step 453: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 454: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  delay(16);
  // Step 455: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 456: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  delay(22);
  // Step 457: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 458: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 459: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  delay(21);
  // Step 460: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 461: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 462: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  // Step 463: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  delay(15);
  // Step 464: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  // Step 465: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  // Step 466: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  // Step 467: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  // Step 468: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  // Step 469: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 470: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 471: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 472: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 473: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 474: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 475: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 476: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 477: Fingers [-, -, -, -, -] Arm [-, -, 35]
  servo[7].write(35); // Wrist

  // Step 478: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 479: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 480: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 481: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  // Step 482: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  // Step 483: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 484: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 485: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 486: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 487: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 488: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 489: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 490: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 491: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 492: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 493: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 494: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 495: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  delay(15);
  // Step 496: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 497: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 498: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 499: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 500: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  delay(11);
  // Step 501: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 502: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 503: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 504: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 505: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 506: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 507: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  delay(11);
  // Step 508: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 509: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 510: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 511: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 512: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 513: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 514: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(17);
  // Step 515: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 516: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 517: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 518: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(15);
  // Step 519: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 520: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 521: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 522: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 523: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  delay(13);
  // Step 524: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  delay(15);
  // Step 525: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 526: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 527: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 528: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 529: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 530: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 531: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 532: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 533: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 534: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 535: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 536: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 537: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 538: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 539: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 540: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 541: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  delay(15);
  // Step 542: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 543: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 544: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 545: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 546: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 547: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 548: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 549: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 550: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 551: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 552: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  delay(19);
  // Step 553: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 554: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 555: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 556: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 557: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  delay(21);
  // Step 558: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 559: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 560: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 561: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  delay(11);
  // Step 562: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 563: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  delay(13);
  // Step 564: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 565: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 566: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 567: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  delay(19);
  // Step 568: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 569: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 570: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 571: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  delay(11);
  // Step 572: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 573: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 574: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 575: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  delay(11);
  // Step 576: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 577: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 578: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 579: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 580: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 581: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 582: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  delay(14);
  // Step 583: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 584: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  delay(14);
  // Step 585: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 586: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 587: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 588: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 589: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  delay(15);
  // Step 590: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 591: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 592: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  delay(12);
  // Step 593: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 594: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 595: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 596: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 597: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 598: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 599: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 600: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 601: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 602: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 603: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 604: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 605: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 606: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 607: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 608: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  delay(13);
  // Step 609: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 610: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 611: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 612: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 613: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 614: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 615: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 616: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 617: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 618: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 619: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  delay(15);
  // Step 620: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 621: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 622: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  delay(11);
  // Step 623: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  delay(16);
  // Step 624: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 625: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  delay(12);
  // Step 626: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 627: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 628: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  delay(11);
  // Step 629: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  delay(16);
  // Step 630: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  // Step 631: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  delay(14);
  // Step 632: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 633: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  delay(13);
  // Step 634: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 635: Fingers [-, -, -, -, -] Arm [-, -, 35]
  servo[7].write(35); // Wrist

  // Step 636: Fingers [-, -, -, -, -] Arm [-, -, 35]
  servo[7].write(35); // Wrist

  // Step 637: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  delay(14);
  // Step 638: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 639: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 640: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 641: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  delay(13);
  // Step 642: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 643: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  delay(11);
  // Step 644: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 645: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 646: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 647: Fingers [-, -, -, -, -] Arm [-, -, 30]
  servo[7].write(30); // Wrist

  // Step 648: Fingers [-, -, -, -, -] Arm [-, -, 30]
  servo[7].write(30); // Wrist

  // Step 649: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 650: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 651: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 652: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  delay(13);
  // Step 653: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  // Step 654: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  // Step 655: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  delay(16);
  // Step 656: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  // Step 657: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  delay(22);
  // Step 658: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  // Step 659: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  delay(11);
  // Step 660: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  delay(14);
  // Step 661: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  delay(17);
  // Step 662: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  delay(15);
  // Step 663: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 664: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 665: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 666: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 667: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 668: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 669: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 670: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  delay(11);
  // Step 671: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 672: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 673: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  delay(12);
  // Step 674: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 675: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 676: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  delay(13);
  // Step 677: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 678: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 679: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  delay(13);
  // Step 680: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 681: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 682: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 683: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 684: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 685: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 686: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  delay(15);
  // Step 687: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 688: Fingers [-, -, -, -, -] Arm [-, -, 24]
  servo[7].write(24); // Wrist

  // Step 689: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 690: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 691: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 692: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 693: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  // Step 694: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  // Step 695: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  // Step 696: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  // Step 697: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  // Step 698: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 699: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 700: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 701: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 702: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 703: Fingers [-, -, -, -, -] Arm [-, -, 30]
  servo[7].write(30); // Wrist

  // Step 704: Fingers [-, -, -, -, -] Arm [-, -, 30]
  servo[7].write(30); // Wrist

  // Step 705: Fingers [-, -, -, -, -] Arm [-, -, 30]
  servo[7].write(30); // Wrist

  // Step 706: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 707: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 708: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 709: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 710: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  // Step 711: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  // Step 712: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 713: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 714: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 715: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 716: Fingers [-, -, -, -, -] Arm [-, -, 35]
  servo[7].write(35); // Wrist

  // Step 717: Fingers [-, -, -, -, -] Arm [-, -, 35]
  servo[7].write(35); // Wrist

  // Step 718: Fingers [-, -, -, -, -] Arm [-, -, 35]
  servo[7].write(35); // Wrist

  // Step 719: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 720: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 721: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  // Step 722: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  delay(19);
  // Step 723: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 724: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 725: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 726: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  delay(15);
  // Step 727: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 728: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 729: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  delay(16);
  // Step 730: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 731: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 732: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 733: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 734: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 735: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  delay(13);
  // Step 736: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  delay(16);
  // Step 737: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 738: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 739: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  delay(12);
  // Step 740: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 741: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  delay(11);
  // Step 742: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  delay(17);
  // Step 743: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 744: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 745: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 746: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 747: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 748: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  delay(13);
  // Step 749: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 750: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  delay(11);
  // Step 751: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 752: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  delay(13);
  // Step 753: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 754: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  delay(13);
  // Step 755: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 756: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  delay(12);
  // Step 757: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(15);
  // Step 758: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 759: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(17);
  // Step 760: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 761: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 762: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  delay(11);
  // Step 763: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 764: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 765: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 766: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 767: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 768: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 769: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  delay(14);
  // Step 770: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  delay(12);
  // Step 771: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 772: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  delay(11);
  // Step 773: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 774: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 775: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 776: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 777: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 778: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 779: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 780: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 781: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 782: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 783: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 784: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 785: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 786: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 787: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 788: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 789: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  delay(14);
  // Step 790: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 791: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 792: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 793: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 794: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 795: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 796: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 797: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  delay(15);
  // Step 798: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 799: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 800: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 801: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 802: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 803: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 804: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 805: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 806: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 807: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 808: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 809: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 810: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 811: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 812: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 813: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 814: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 815: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  // Step 816: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 817: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 818: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 819: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  delay(15);
  // Step 820: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 821: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 822: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 823: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 824: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 825: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 826: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 827: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  delay(15);
  // Step 828: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 829: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 830: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 831: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 832: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 833: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 834: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 835: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 836: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 837: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 838: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 839: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 840: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 841: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 842: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 843: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  delay(18);
  // Step 844: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 845: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  delay(20);
  // Step 846: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 847: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  delay(25);
  // Step 848: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 849: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 850: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 851: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 852: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 853: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 854: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 855: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 856: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 857: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 858: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 859: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  delay(13);
  // Step 860: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 861: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 862: Fingers [-, -, -, -, -] Arm [-, -, 89]
  servo[7].write(89); // Wrist

  delay(12);
  // Step 863: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 864: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  delay(12);
  // Step 865: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 866: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 867: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 868: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  delay(32);
  // Step 869: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  delay(31);
  // Step 870: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  delay(22);
  // Step 871: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 872: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  delay(12);
  // Step 873: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  delay(18);
  // Step 874: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 875: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 876: Fingers [-, -, -, -, -] Arm [-, -, 89]
  servo[7].write(89); // Wrist

  // Step 877: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 878: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 879: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 880: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 881: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 882: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 883: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 884: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 885: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 886: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  delay(14);
  // Step 887: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 888: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 889: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 890: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  delay(16);
  // Step 891: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 892: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  delay(26);
  // Step 893: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 894: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  delay(18);
  // Step 895: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 896: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  delay(23);
  // Step 897: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 898: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  delay(27);
  // Step 899: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 900: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  delay(17);
  // Step 901: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 902: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  delay(12);
  // Step 903: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 904: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 905: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 906: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 907: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  delay(16);
  // Step 908: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 909: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 910: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  delay(17);
  // Step 911: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 912: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 913: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  delay(15);
  // Step 914: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 915: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  delay(15);
  // Step 916: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 917: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  delay(27);
  // Step 918: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 919: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  delay(14);
  // Step 920: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  delay(13);
  // Step 921: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 922: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  delay(26);
  // Step 923: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 924: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 925: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 926: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  delay(11);
  // Step 927: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 928: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  delay(11);
  // Step 929: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 930: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 931: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 932: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 933: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 934: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  delay(13);
  // Step 935: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  // Step 936: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  // Step 937: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 938: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 939: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 940: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 941: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 942: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 943: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 944: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 945: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 946: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 947: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 948: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 949: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 950: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 951: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 952: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 953: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 954: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  delay(11);
  // Step 955: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 956: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 957: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  delay(13);
  // Step 958: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 959: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  delay(11);
  // Step 960: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 961: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 962: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 963: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 964: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 965: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 966: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 967: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  delay(13);
  // Step 968: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 969: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 970: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 971: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 972: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 973: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 974: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 975: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 976: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 977: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  // Step 978: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 979: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 980: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 981: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 982: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(12);
  // Step 983: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 984: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 985: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 986: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 987: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 988: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 989: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  delay(17);
  // Step 990: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 991: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 992: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 993: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  delay(14);
  // Step 994: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 995: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 996: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  delay(13);
  // Step 997: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 998: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 999: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  delay(14);
  // Step 1000: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 1001: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 1002: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 1003: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  delay(12);
  // Step 1004: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 1005: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 1006: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  delay(13);
  // Step 1007: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 1008: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 1009: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 1010: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  delay(17);
  // Step 1011: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  // Step 1012: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  // Step 1013: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 1014: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 1015: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 1016: Fingers [-, -, -, -, -] Arm [-, -, 35]
  servo[7].write(35); // Wrist

  delay(12);
  // Step 1017: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 1018: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 1019: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 1020: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  delay(17);
  // Step 1021: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 1022: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  // Step 1023: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  delay(12);
  // Step 1024: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 1025: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 1026: Fingers [-, -, -, -, -] Arm [-, -, 30]
  servo[7].write(30); // Wrist

  delay(13);
  // Step 1027: Fingers [-, -, -, -, -] Arm [-, -, 30]
  servo[7].write(30); // Wrist

  // Step 1028: Fingers [-, -, -, -, -] Arm [-, -, 30]
  servo[7].write(30); // Wrist

  // Step 1029: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 1030: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 1031: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 1032: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 1033: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  // Step 1034: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  // Step 1035: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  // Step 1036: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  delay(23);
  // Step 1037: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  // Step 1038: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  // Step 1039: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  delay(16);
  // Step 1040: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  // Step 1041: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  delay(11);
  // Step 1042: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  delay(16);
  // Step 1043: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  // Step 1044: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  // Step 1045: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  delay(16);
  // Step 1046: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  // Step 1047: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  delay(15);
  // Step 1048: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  // Step 1049: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  delay(18);
  // Step 1050: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 1051: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 1052: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  delay(13);
  // Step 1053: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  delay(15);
  // Step 1054: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 1055: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  delay(13);
  // Step 1056: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 1057: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  delay(29);
  // Step 1058: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 1059: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  delay(32);
  // Step 1060: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 1061: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  delay(22);
  // Step 1062: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 1063: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 1064: Fingers [-, -, -, -, -] Arm [-, -, 25]
  servo[7].write(25); // Wrist

  // Step 1065: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  // Step 1066: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  delay(11);
  // Step 1067: Fingers [-, -, -, -, -] Arm [-, -, 26]
  servo[7].write(26); // Wrist

  // Step 1068: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  // Step 1069: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  // Step 1070: Fingers [-, -, -, -, -] Arm [-, -, 27]
  servo[7].write(27); // Wrist

  delay(11);
  // Step 1071: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  // Step 1072: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  // Step 1073: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  // Step 1074: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  // Step 1075: Fingers [-, -, -, -, -] Arm [-, -, 28]
  servo[7].write(28); // Wrist

  // Step 1076: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 1077: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  delay(12);
  // Step 1078: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 1079: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 1080: Fingers [-, -, -, -, -] Arm [-, -, 29]
  servo[7].write(29); // Wrist

  // Step 1081: Fingers [-, -, -, -, -] Arm [-, -, 30]
  servo[7].write(30); // Wrist

  delay(23);
  // Step 1082: Fingers [-, -, -, -, -] Arm [-, -, 30]
  servo[7].write(30); // Wrist

  // Step 1083: Fingers [-, -, -, -, -] Arm [-, -, 30]
  servo[7].write(30); // Wrist

  // Step 1084: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 1085: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 1086: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 1087: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  // Step 1088: Fingers [-, -, -, -, -] Arm [-, -, 31]
  servo[7].write(31); // Wrist

  delay(13);
  // Step 1089: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  // Step 1090: Fingers [-, -, -, -, -] Arm [-, -, 32]
  servo[7].write(32); // Wrist

  delay(26);
  // Step 1091: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  // Step 1092: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  delay(20);
  // Step 1093: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  delay(12);
  // Step 1094: Fingers [-, -, -, -, -] Arm [-, -, 33]
  servo[7].write(33); // Wrist

  delay(12);
  // Step 1095: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  // Step 1096: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  delay(11);
  // Step 1097: Fingers [-, -, -, -, -] Arm [-, -, 34]
  servo[7].write(34); // Wrist

  delay(13);
  // Step 1098: Fingers [-, -, -, -, -] Arm [-, -, 35]
  servo[7].write(35); // Wrist

  delay(19);
  // Step 1099: Fingers [-, -, -, -, -] Arm [-, -, 35]
  servo[7].write(35); // Wrist

  // Step 1100: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 1101: Fingers [-, -, -, -, -] Arm [-, -, 36]
  servo[7].write(36); // Wrist

  // Step 1102: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  // Step 1103: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  // Step 1104: Fingers [-, -, -, -, -] Arm [-, -, 37]
  servo[7].write(37); // Wrist

  delay(16);
  // Step 1105: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 1106: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  delay(13);
  // Step 1107: Fingers [-, -, -, -, -] Arm [-, -, 38]
  servo[7].write(38); // Wrist

  // Step 1108: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 1109: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 1110: Fingers [-, -, -, -, -] Arm [-, -, 39]
  servo[7].write(39); // Wrist

  // Step 1111: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 1112: Fingers [-, -, -, -, -] Arm [-, -, 40]
  servo[7].write(40); // Wrist

  // Step 1113: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 1114: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 1115: Fingers [-, -, -, -, -] Arm [-, -, 41]
  servo[7].write(41); // Wrist

  // Step 1116: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 1117: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 1118: Fingers [-, -, -, -, -] Arm [-, -, 42]
  servo[7].write(42); // Wrist

  // Step 1119: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 1120: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 1121: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 1122: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  // Step 1123: Fingers [-, -, -, -, -] Arm [-, -, 43]
  servo[7].write(43); // Wrist

  delay(12);
  // Step 1124: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 1125: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  delay(11);
  // Step 1126: Fingers [-, -, -, -, -] Arm [-, -, 44]
  servo[7].write(44); // Wrist

  // Step 1127: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 1128: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 1129: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 1130: Fingers [-, -, -, -, -] Arm [-, -, 45]
  servo[7].write(45); // Wrist

  // Step 1131: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 1132: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 1133: Fingers [-, -, -, -, -] Arm [-, -, 46]
  servo[7].write(46); // Wrist

  // Step 1134: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 1135: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  delay(13);
  // Step 1136: Fingers [-, -, -, -, -] Arm [-, -, 47]
  servo[7].write(47); // Wrist

  // Step 1137: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 1138: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 1139: Fingers [-, -, -, -, -] Arm [-, -, 48]
  servo[7].write(48); // Wrist

  // Step 1140: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  delay(16);
  // Step 1141: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 1142: Fingers [-, -, -, -, -] Arm [-, -, 49]
  servo[7].write(49); // Wrist

  // Step 1143: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 1144: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 1145: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 1146: Fingers [-, -, -, -, -] Arm [-, -, 50]
  servo[7].write(50); // Wrist

  // Step 1147: Fingers [-, -, -, -, -] Arm [-, -, 51]
  servo[7].write(51); // Wrist

  delay(16);
  // Step 1148: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 1149: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 1150: Fingers [-, -, -, -, -] Arm [-, -, 52]
  servo[7].write(52); // Wrist

  // Step 1151: Fingers [-, -, -, -, -] Arm [-, -, 53]
  servo[7].write(53); // Wrist

  // Step 1152: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 1153: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 1154: Fingers [-, -, -, -, -] Arm [-, -, 54]
  servo[7].write(54); // Wrist

  // Step 1155: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 1156: Fingers [-, -, -, -, -] Arm [-, -, 55]
  servo[7].write(55); // Wrist

  // Step 1157: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 1158: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 1159: Fingers [-, -, -, -, -] Arm [-, -, 56]
  servo[7].write(56); // Wrist

  // Step 1160: Fingers [-, -, -, -, -] Arm [-, -, 57]
  servo[7].write(57); // Wrist

  // Step 1161: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  // Step 1162: Fingers [-, -, -, -, -] Arm [-, -, 58]
  servo[7].write(58); // Wrist

  delay(12);
  // Step 1163: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 1164: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 1165: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 1166: Fingers [-, -, -, -, -] Arm [-, -, 59]
  servo[7].write(59); // Wrist

  // Step 1167: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  delay(16);
  // Step 1168: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 1169: Fingers [-, -, -, -, -] Arm [-, -, 60]
  servo[7].write(60); // Wrist

  // Step 1170: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 1171: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 1172: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 1173: Fingers [-, -, -, -, -] Arm [-, -, 61]
  servo[7].write(61); // Wrist

  // Step 1174: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  // Step 1175: Fingers [-, -, -, -, -] Arm [-, -, 62]
  servo[7].write(62); // Wrist

  delay(14);
  // Step 1176: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 1177: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  delay(15);
  // Step 1178: Fingers [-, -, -, -, -] Arm [-, -, 63]
  servo[7].write(63); // Wrist

  // Step 1179: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 1180: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 1181: Fingers [-, -, -, -, -] Arm [-, -, 64]
  servo[7].write(64); // Wrist

  // Step 1182: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  delay(15);
  // Step 1183: Fingers [-, -, -, -, -] Arm [-, -, 65]
  servo[7].write(65); // Wrist

  // Step 1184: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 1185: Fingers [-, -, -, -, -] Arm [-, -, 66]
  servo[7].write(66); // Wrist

  // Step 1186: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 1187: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 1188: Fingers [-, -, -, -, -] Arm [-, -, 67]
  servo[7].write(67); // Wrist

  // Step 1189: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 1190: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 1191: Fingers [-, -, -, -, -] Arm [-, -, 68]
  servo[7].write(68); // Wrist

  // Step 1192: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 1193: Fingers [-, -, -, -, -] Arm [-, -, 69]
  servo[7].write(69); // Wrist

  // Step 1194: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  // Step 1195: Fingers [-, -, -, -, -] Arm [-, -, 70]
  servo[7].write(70); // Wrist

  delay(12);
  // Step 1196: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  delay(17);
  // Step 1197: Fingers [-, -, -, -, -] Arm [-, -, 71]
  servo[7].write(71); // Wrist

  // Step 1198: Fingers [-, -, -, -, -] Arm [-, -, 72]
  servo[7].write(72); // Wrist

  // Step 1199: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 1200: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 1201: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 1202: Fingers [-, -, -, -, -] Arm [-, -, 73]
  servo[7].write(73); // Wrist

  // Step 1203: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 1204: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  delay(16);
  // Step 1205: Fingers [-, -, -, -, -] Arm [-, -, 74]
  servo[7].write(74); // Wrist

  // Step 1206: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  delay(24);
  // Step 1207: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 1208: Fingers [-, -, -, -, -] Arm [-, -, 75]
  servo[7].write(75); // Wrist

  // Step 1209: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 1210: Fingers [-, -, -, -, -] Arm [-, -, 76]
  servo[7].write(76); // Wrist

  // Step 1211: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 1212: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  delay(11);
  // Step 1213: Fingers [-, -, -, -, -] Arm [-, -, 77]
  servo[7].write(77); // Wrist

  // Step 1214: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  delay(11);
  // Step 1215: Fingers [-, -, -, -, -] Arm [-, -, 78]
  servo[7].write(78); // Wrist

  // Step 1216: Fingers [-, -, -, -, -] Arm [-, -, 79]
  servo[7].write(79); // Wrist

  // Step 1217: Fingers [-, -, -, -, -] Arm [-, -, 80]
  servo[7].write(80); // Wrist

  // Step 1218: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  // Step 1219: Fingers [-, -, -, -, -] Arm [-, -, 81]
  servo[7].write(81); // Wrist

  delay(11);
  // Step 1220: Fingers [-, -, -, -, -] Arm [-, -, 82]
  servo[7].write(82); // Wrist

  // Step 1221: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 1222: Fingers [-, -, -, -, -] Arm [-, -, 83]
  servo[7].write(83); // Wrist

  // Step 1223: Fingers [-, -, -, -, -] Arm [-, -, 84]
  servo[7].write(84); // Wrist

  // Step 1224: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 1225: Fingers [-, -, -, -, -] Arm [-, -, 85]
  servo[7].write(85); // Wrist

  // Step 1226: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 1227: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 1228: Fingers [-, -, -, -, -] Arm [-, -, 86]
  servo[7].write(86); // Wrist

  // Step 1229: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 1230: Fingers [-, -, -, -, -] Arm [-, -, 87]
  servo[7].write(87); // Wrist

  // Step 1231: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 1232: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 1233: Fingers [-, -, -, -, -] Arm [-, -, 88]
  servo[7].write(88); // Wrist

  // Step 1234: Fingers [-, -, -, -, -] Arm [-, -, 89]
  servo[7].write(89); // Wrist

  // Step 1235: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 1236: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 1237: Fingers [-, -, -, -, -] Arm [-, -, 90]
  servo[7].write(90); // Wrist

  // Step 1238: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  delay(13);
  // Step 1239: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 1240: Fingers [-, -, -, -, -] Arm [-, -, 91]
  servo[7].write(91); // Wrist

  // Step 1241: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  // Step 1242: Fingers [-, -, -, -, -] Arm [-, -, 92]
  servo[7].write(92); // Wrist

  delay(12);
  // Step 1243: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  // Step 1244: Fingers [-, -, -, -, -] Arm [-, -, 93]
  servo[7].write(93); // Wrist

  delay(12);
  // Step 1245: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  delay(16);
  // Step 1246: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 1247: Fingers [-, -, -, -, -] Arm [-, -, 94]
  servo[7].write(94); // Wrist

  // Step 1248: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  delay(13);
  // Step 1249: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 1250: Fingers [-, -, -, -, -] Arm [-, -, 95]
  servo[7].write(95); // Wrist

  // Step 1251: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 1252: Fingers [-, -, -, -, -] Arm [-, -, 96]
  servo[7].write(96); // Wrist

  // Step 1253: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 1254: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

  // Step 1255: Fingers [-, -, -, -, -] Arm [-, -, 97]
  servo[7].write(97); // Wrist

}

// Layer 4: Layer_4 - cursor mode
// Duration: 10.7s, Points: 1313
void playLayer4() {
  // Step 1: Fingers [72, 126, 89, 58, 114] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(126); // Index
  servo[2].write(89); // Middle
  servo[3].write(58); // Ring
  servo[4].write(114); // Pinky

  delay(11);
  // Step 2: Fingers [71, 126, 89, 57, 113] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(126); // Index
  servo[2].write(89); // Middle
  servo[3].write(57); // Ring
  servo[4].write(113); // Pinky

  // Step 3: Fingers [69, 124, 91, 56, 111] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(124); // Index
  servo[2].write(91); // Middle
  servo[3].write(56); // Ring
  servo[4].write(111); // Pinky

  // Step 4: Fingers [69, 124, 90, 56, 111] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(124); // Index
  servo[2].write(90); // Middle
  servo[3].write(56); // Ring
  servo[4].write(111); // Pinky

  // Step 5: Fingers [69, 124, 90, 56, 111] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(124); // Index
  servo[2].write(90); // Middle
  servo[3].write(56); // Ring
  servo[4].write(111); // Pinky

  delay(11);
  // Step 6: Fingers [68, 124, 90, 55, 110] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(124); // Index
  servo[2].write(90); // Middle
  servo[3].write(55); // Ring
  servo[4].write(110); // Pinky

  // Step 7: Fingers [68, 123, 89, 55, 110] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(123); // Index
  servo[2].write(89); // Middle
  servo[3].write(55); // Ring
  servo[4].write(110); // Pinky

  // Step 8: Fingers [67, 122, 89, 54, 109] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(122); // Index
  servo[2].write(89); // Middle
  servo[3].write(54); // Ring
  servo[4].write(109); // Pinky

  // Step 9: Fingers [65, 121, 90, 53, 107] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(121); // Index
  servo[2].write(90); // Middle
  servo[3].write(53); // Ring
  servo[4].write(107); // Pinky

  // Step 10: Fingers [65, 121, 90, 53, 107] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(121); // Index
  servo[2].write(90); // Middle
  servo[3].write(53); // Ring
  servo[4].write(107); // Pinky

  // Step 11: Fingers [64, 121, 90, 52, 106] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(121); // Index
  servo[2].write(90); // Middle
  servo[3].write(52); // Ring
  servo[4].write(106); // Pinky

  // Step 12: Fingers [64, 120, 89, 52, 106] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(120); // Index
  servo[2].write(89); // Middle
  servo[3].write(52); // Ring
  servo[4].write(106); // Pinky

  // Step 13: Fingers [63, 120, 89, 52, 106] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(120); // Index
  servo[2].write(89); // Middle
  servo[3].write(52); // Ring
  servo[4].write(106); // Pinky

  // Step 14: Fingers [61, 118, 90, 50, 103] Arm [-, -, -]
  servo[0].write(61); // Thumb
  servo[1].write(118); // Index
  servo[2].write(90); // Middle
  servo[3].write(50); // Ring
  servo[4].write(103); // Pinky

  // Step 15: Fingers [61, 118, 90, 50, 103] Arm [-, -, -]
  servo[0].write(61); // Thumb
  servo[1].write(118); // Index
  servo[2].write(90); // Middle
  servo[3].write(50); // Ring
  servo[4].write(103); // Pinky

  // Step 16: Fingers [60, 118, 90, 50, 102] Arm [-, -, -]
  servo[0].write(60); // Thumb
  servo[1].write(118); // Index
  servo[2].write(90); // Middle
  servo[3].write(50); // Ring
  servo[4].write(102); // Pinky

  // Step 17: Fingers [60, 117, 90, 49, 102] Arm [-, -, -]
  servo[0].write(60); // Thumb
  servo[1].write(117); // Index
  servo[2].write(90); // Middle
  servo[3].write(49); // Ring
  servo[4].write(102); // Pinky

  // Step 18: Fingers [60, 117, 89, 49, 102] Arm [-, -, -]
  servo[0].write(60); // Thumb
  servo[1].write(117); // Index
  servo[2].write(89); // Middle
  servo[3].write(49); // Ring
  servo[4].write(102); // Pinky

  // Step 19: Fingers [59, 116, 89, 49, 101] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(116); // Index
  servo[2].write(89); // Middle
  servo[3].write(49); // Ring
  servo[4].write(101); // Pinky

  // Step 20: Fingers [59, 116, 89, 49, 101] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(116); // Index
  servo[2].write(89); // Middle
  servo[3].write(49); // Ring
  servo[4].write(101); // Pinky

  // Step 21: Fingers [59, 116, 88, 48, 101] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(116); // Index
  servo[2].write(88); // Middle
  servo[3].write(48); // Ring
  servo[4].write(101); // Pinky

  delay(12);
  // Step 22: Fingers [58, 116, 88, 48, 100] Arm [-, -, -]
  servo[0].write(58); // Thumb
  servo[1].write(116); // Index
  servo[2].write(88); // Middle
  servo[3].write(48); // Ring
  servo[4].write(100); // Pinky

  // Step 23: Fingers [58, 116, 88, 48, 100] Arm [-, -, -]
  servo[0].write(58); // Thumb
  servo[1].write(116); // Index
  servo[2].write(88); // Middle
  servo[3].write(48); // Ring
  servo[4].write(100); // Pinky

  // Step 24: Fingers [57, 115, 87, 47, 99] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(115); // Index
  servo[2].write(87); // Middle
  servo[3].write(47); // Ring
  servo[4].write(99); // Pinky

  delay(12);
  // Step 25: Fingers [57, 114, 87, 46, 99] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(114); // Index
  servo[2].write(87); // Middle
  servo[3].write(46); // Ring
  servo[4].write(99); // Pinky

  // Step 26: Fingers [57, 114, 87, 46, 99] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(114); // Index
  servo[2].write(87); // Middle
  servo[3].write(46); // Ring
  servo[4].write(99); // Pinky

  // Step 27: Fingers [57, 114, 86, 46, 99] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(114); // Index
  servo[2].write(86); // Middle
  servo[3].write(46); // Ring
  servo[4].write(99); // Pinky

  // Step 28: Fingers [56, 113, 86, 46, 98] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(113); // Index
  servo[2].write(86); // Middle
  servo[3].write(46); // Ring
  servo[4].write(98); // Pinky

  // Step 29: Fingers [56, 113, 85, 45, 98] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(113); // Index
  servo[2].write(85); // Middle
  servo[3].write(45); // Ring
  servo[4].write(98); // Pinky

  delay(14);
  // Step 30: Fingers [56, 113, 85, 45, 98] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(113); // Index
  servo[2].write(85); // Middle
  servo[3].write(45); // Ring
  servo[4].write(98); // Pinky

  // Step 31: Fingers [55, 112, 84, 44, 97] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(112); // Index
  servo[2].write(84); // Middle
  servo[3].write(44); // Ring
  servo[4].write(97); // Pinky

  // Step 32: Fingers [54, 112, 84, 44, 96] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(112); // Index
  servo[2].write(84); // Middle
  servo[3].write(44); // Ring
  servo[4].write(96); // Pinky

  delay(14);
  // Step 33: Fingers [54, 111, 83, 43, 96] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(111); // Index
  servo[2].write(83); // Middle
  servo[3].write(43); // Ring
  servo[4].write(96); // Pinky

  // Step 34: Fingers [54, 111, 83, 43, 96] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(111); // Index
  servo[2].write(83); // Middle
  servo[3].write(43); // Ring
  servo[4].write(96); // Pinky

  // Step 35: Fingers [53, 110, 83, 43, 95] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(110); // Index
  servo[2].write(83); // Middle
  servo[3].write(43); // Ring
  servo[4].write(95); // Pinky

  // Step 36: Fingers [53, 110, 82, 42, 95] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(110); // Index
  servo[2].write(82); // Middle
  servo[3].write(42); // Ring
  servo[4].write(95); // Pinky

  delay(13);
  // Step 37: Fingers [52, 110, 82, 42, 94] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(110); // Index
  servo[2].write(82); // Middle
  servo[3].write(42); // Ring
  servo[4].write(94); // Pinky

  // Step 38: Fingers [52, 110, 82, 42, 94] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(110); // Index
  servo[2].write(82); // Middle
  servo[3].write(42); // Ring
  servo[4].write(94); // Pinky

  // Step 39: Fingers [52, 109, 82, 41, 94] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(109); // Index
  servo[2].write(82); // Middle
  servo[3].write(41); // Ring
  servo[4].write(94); // Pinky

  delay(14);
  // Step 40: Fingers [51, 109, 81, 41, 93] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(109); // Index
  servo[2].write(81); // Middle
  servo[3].write(41); // Ring
  servo[4].write(93); // Pinky

  // Step 41: Fingers [51, 109, 81, 41, 93] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(109); // Index
  servo[2].write(81); // Middle
  servo[3].write(41); // Ring
  servo[4].write(93); // Pinky

  // Step 42: Fingers [51, 108, 81, 40, 93] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(108); // Index
  servo[2].write(81); // Middle
  servo[3].write(40); // Ring
  servo[4].write(93); // Pinky

  // Step 43: Fingers [51, 108, 80, 40, 93] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(108); // Index
  servo[2].write(80); // Middle
  servo[3].write(40); // Ring
  servo[4].write(93); // Pinky

  // Step 44: Fingers [50, 108, 80, 40, 92] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(108); // Index
  servo[2].write(80); // Middle
  servo[3].write(40); // Ring
  servo[4].write(92); // Pinky

  // Step 45: Fingers [50, 108, 80, 40, 92] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(108); // Index
  servo[2].write(80); // Middle
  servo[3].write(40); // Ring
  servo[4].write(92); // Pinky

  // Step 46: Fingers [50, 107, 79, 39, 92] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(107); // Index
  servo[2].write(79); // Middle
  servo[3].write(39); // Ring
  servo[4].write(92); // Pinky

  // Step 47: Fingers [51, 107, 76, 39, 93] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(107); // Index
  servo[2].write(76); // Middle
  servo[3].write(39); // Ring
  servo[4].write(93); // Pinky

  // Step 48: Fingers [50, 107, 76, 38, 92] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(107); // Index
  servo[2].write(76); // Middle
  servo[3].write(38); // Ring
  servo[4].write(92); // Pinky

  // Step 49: Fingers [50, 106, 75, 38, 92] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(106); // Index
  servo[2].write(75); // Middle
  servo[3].write(38); // Ring
  servo[4].write(92); // Pinky

  // Step 50: Fingers [50, 106, 75, 38, 92] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(106); // Index
  servo[2].write(75); // Middle
  servo[3].write(38); // Ring
  servo[4].write(92); // Pinky

  // Step 51: Fingers [49, 106, 75, 38, 92] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(106); // Index
  servo[2].write(75); // Middle
  servo[3].write(38); // Ring
  servo[4].write(92); // Pinky

  // Step 52: Fingers [49, 105, 75, 37, 91] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(105); // Index
  servo[2].write(75); // Middle
  servo[3].write(37); // Ring
  servo[4].write(91); // Pinky

  // Step 53: Fingers [48, 105, 74, 37, 91] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(105); // Index
  servo[2].write(74); // Middle
  servo[3].write(37); // Ring
  servo[4].write(91); // Pinky

  // Step 54: Fingers [48, 105, 74, 37, 91] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(105); // Index
  servo[2].write(74); // Middle
  servo[3].write(37); // Ring
  servo[4].write(91); // Pinky

  // Step 55: Fingers [48, 105, 74, 36, 90] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(105); // Index
  servo[2].write(74); // Middle
  servo[3].write(36); // Ring
  servo[4].write(90); // Pinky

  // Step 56: Fingers [49, 105, 71, 36, 91] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(105); // Index
  servo[2].write(71); // Middle
  servo[3].write(36); // Ring
  servo[4].write(91); // Pinky

  // Step 57: Fingers [49, 104, 70, 36, 91] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(104); // Index
  servo[2].write(70); // Middle
  servo[3].write(36); // Ring
  servo[4].write(91); // Pinky

  // Step 58: Fingers [48, 104, 70, 35, 90] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(104); // Index
  servo[2].write(70); // Middle
  servo[3].write(35); // Ring
  servo[4].write(90); // Pinky

  // Step 59: Fingers [48, 104, 70, 35, 90] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(104); // Index
  servo[2].write(70); // Middle
  servo[3].write(35); // Ring
  servo[4].write(90); // Pinky

  // Step 60: Fingers [50, 104, 67, 35, 92] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(104); // Index
  servo[2].write(67); // Middle
  servo[3].write(35); // Ring
  servo[4].write(92); // Pinky

  // Step 61: Fingers [49, 103, 67, 35, 91] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(103); // Index
  servo[2].write(67); // Middle
  servo[3].write(35); // Ring
  servo[4].write(91); // Pinky

  // Step 62: Fingers [49, 103, 66, 35, 91] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(103); // Index
  servo[2].write(66); // Middle
  servo[3].write(35); // Ring
  servo[4].write(91); // Pinky

  // Step 63: Fingers [48, 103, 66, 34, 90] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(103); // Index
  servo[2].write(66); // Middle
  servo[3].write(34); // Ring
  servo[4].write(90); // Pinky

  // Step 64: Fingers [48, 103, 66, 34, 90] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(103); // Index
  servo[2].write(66); // Middle
  servo[3].write(34); // Ring
  servo[4].write(90); // Pinky

  // Step 65: Fingers [50, 103, 63, 35, 92] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(103); // Index
  servo[2].write(63); // Middle
  servo[3].write(35); // Ring
  servo[4].write(92); // Pinky

  delay(11);
  // Step 66: Fingers [49, 102, 63, 34, 91] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(102); // Index
  servo[2].write(63); // Middle
  servo[3].write(34); // Ring
  servo[4].write(91); // Pinky

  // Step 67: Fingers [51, 103, 61, 35, 93] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(103); // Index
  servo[2].write(61); // Middle
  servo[3].write(35); // Ring
  servo[4].write(93); // Pinky

  // Step 68: Fingers [51, 103, 61, 35, 93] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(103); // Index
  servo[2].write(61); // Middle
  servo[3].write(35); // Ring
  servo[4].write(93); // Pinky

  // Step 69: Fingers [51, 102, 60, 35, 92] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(102); // Index
  servo[2].write(60); // Middle
  servo[3].write(35); // Ring
  servo[4].write(92); // Pinky

  delay(13);
  // Step 70: Fingers [50, 102, 60, 34, 92] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(102); // Index
  servo[2].write(60); // Middle
  servo[3].write(34); // Ring
  servo[4].write(92); // Pinky

  // Step 71: Fingers [50, 102, 60, 34, 92] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(102); // Index
  servo[2].write(60); // Middle
  servo[3].write(34); // Ring
  servo[4].write(92); // Pinky

  // Step 72: Fingers [52, 102, 58, 35, 94] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(102); // Index
  servo[2].write(58); // Middle
  servo[3].write(35); // Ring
  servo[4].write(94); // Pinky

  // Step 73: Fingers [52, 102, 57, 35, 93] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(102); // Index
  servo[2].write(57); // Middle
  servo[3].write(35); // Ring
  servo[4].write(93); // Pinky

  // Step 74: Fingers [52, 101, 57, 35, 93] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(101); // Index
  servo[2].write(57); // Middle
  servo[3].write(35); // Ring
  servo[4].write(93); // Pinky

  delay(15);
  // Step 75: Fingers [52, 101, 57, 35, 93] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(101); // Index
  servo[2].write(57); // Middle
  servo[3].write(35); // Ring
  servo[4].write(93); // Pinky

  // Step 76: Fingers [53, 101, 54, 35, 94] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(101); // Index
  servo[2].write(54); // Middle
  servo[3].write(35); // Ring
  servo[4].write(94); // Pinky

  // Step 77: Fingers [53, 100, 54, 35, 93] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(100); // Index
  servo[2].write(54); // Middle
  servo[3].write(35); // Ring
  servo[4].write(93); // Pinky

  // Step 78: Fingers [52, 100, 53, 35, 93] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(100); // Index
  servo[2].write(53); // Middle
  servo[3].write(35); // Ring
  servo[4].write(93); // Pinky

  // Step 79: Fingers [52, 100, 53, 35, 93] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(100); // Index
  servo[2].write(53); // Middle
  servo[3].write(35); // Ring
  servo[4].write(93); // Pinky

  // Step 80: Fingers [54, 100, 51, 36, 94] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(100); // Index
  servo[2].write(51); // Middle
  servo[3].write(36); // Ring
  servo[4].write(94); // Pinky

  // Step 81: Fingers [56, 99, 49, 37, 95] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(99); // Index
  servo[2].write(49); // Middle
  servo[3].write(37); // Ring
  servo[4].write(95); // Pinky

  // Step 82: Fingers [56, 99, 48, 37, 94] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(99); // Index
  servo[2].write(48); // Middle
  servo[3].write(37); // Ring
  servo[4].write(94); // Pinky

  delay(17);
  // Step 83: Fingers [56, 99, 48, 37, 94] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(99); // Index
  servo[2].write(48); // Middle
  servo[3].write(37); // Ring
  servo[4].write(94); // Pinky

  // Step 84: Fingers [55, 98, 48, 36, 94] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(98); // Index
  servo[2].write(48); // Middle
  servo[3].write(36); // Ring
  servo[4].write(94); // Pinky

  // Step 85: Fingers [58, 98, 46, 38, 95] Arm [-, -, -]
  servo[0].write(58); // Thumb
  servo[1].write(98); // Index
  servo[2].write(46); // Middle
  servo[3].write(38); // Ring
  servo[4].write(95); // Pinky

  // Step 86: Fingers [57, 98, 45, 37, 95] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(98); // Index
  servo[2].write(45); // Middle
  servo[3].write(37); // Ring
  servo[4].write(95); // Pinky

  delay(16);
  // Step 87: Fingers [57, 98, 45, 37, 95] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(98); // Index
  servo[2].write(45); // Middle
  servo[3].write(37); // Ring
  servo[4].write(95); // Pinky

  // Step 88: Fingers [59, 97, 44, 39, 96] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(97); // Index
  servo[2].write(44); // Middle
  servo[3].write(39); // Ring
  servo[4].write(96); // Pinky

  // Step 89: Fingers [59, 97, 43, 38, 95] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(97); // Index
  servo[2].write(43); // Middle
  servo[3].write(38); // Ring
  servo[4].write(95); // Pinky

  delay(14);
  // Step 90: Fingers [63, 95, 39, 42, 96] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(95); // Index
  servo[2].write(39); // Middle
  servo[3].write(42); // Ring
  servo[4].write(96); // Pinky

  // Step 91: Fingers [63, 95, 39, 42, 96] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(95); // Index
  servo[2].write(39); // Middle
  servo[3].write(42); // Ring
  servo[4].write(96); // Pinky

  delay(11);
  // Step 92: Fingers [63, 95, 39, 41, 96] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(95); // Index
  servo[2].write(39); // Middle
  servo[3].write(41); // Ring
  servo[4].write(96); // Pinky

  // Step 93: Fingers [67, 93, 35, 45, 97] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(93); // Index
  servo[2].write(35); // Middle
  servo[3].write(45); // Ring
  servo[4].write(97); // Pinky

  // Step 94: Fingers [69, 91, 33, 47, 96] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(91); // Index
  servo[2].write(33); // Middle
  servo[3].write(47); // Ring
  servo[4].write(96); // Pinky

  // Step 95: Fingers [71, 90, 32, 49, 97] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(90); // Index
  servo[2].write(32); // Middle
  servo[3].write(49); // Ring
  servo[4].write(97); // Pinky

  // Step 96: Fingers [71, 90, 32, 49, 97] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(90); // Index
  servo[2].write(32); // Middle
  servo[3].write(49); // Ring
  servo[4].write(97); // Pinky

  // Step 97: Fingers [75, 87, 29, 53, 96] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(87); // Index
  servo[2].write(29); // Middle
  servo[3].write(53); // Ring
  servo[4].write(96); // Pinky

  // Step 98: Fingers [77, 85, 28, 55, 96] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(85); // Index
  servo[2].write(28); // Middle
  servo[3].write(55); // Ring
  servo[4].write(96); // Pinky

  // Step 99: Fingers [78, 83, 27, 57, 95] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(83); // Index
  servo[2].write(27); // Middle
  servo[3].write(57); // Ring
  servo[4].write(95); // Pinky

  // Step 100: Fingers [81, 79, 25, 61, 93] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(79); // Index
  servo[2].write(25); // Middle
  servo[3].write(61); // Ring
  servo[4].write(93); // Pinky

  // Step 101: Fingers [81, 79, 25, 61, 93] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(79); // Index
  servo[2].write(25); // Middle
  servo[3].write(61); // Ring
  servo[4].write(93); // Pinky

  // Step 102: Fingers [83, 78, 24, 63, 92] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(78); // Index
  servo[2].write(24); // Middle
  servo[3].write(63); // Ring
  servo[4].write(92); // Pinky

  // Step 103: Fingers [85, 76, 24, 65, 91] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(76); // Index
  servo[2].write(24); // Middle
  servo[3].write(65); // Ring
  servo[4].write(91); // Pinky

  // Step 104: Fingers [86, 73, 23, 67, 90] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(73); // Index
  servo[2].write(23); // Middle
  servo[3].write(67); // Ring
  servo[4].write(90); // Pinky

  // Step 105: Fingers [86, 73, 23, 67, 90] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(73); // Index
  servo[2].write(23); // Middle
  servo[3].write(67); // Ring
  servo[4].write(90); // Pinky

  // Step 106: Fingers [87, 71, 23, 69, 89] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(71); // Index
  servo[2].write(23); // Middle
  servo[3].write(69); // Ring
  servo[4].write(89); // Pinky

  // Step 107: Fingers [88, 69, 22, 71, 87] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(69); // Index
  servo[2].write(22); // Middle
  servo[3].write(71); // Ring
  servo[4].write(87); // Pinky

  delay(13);
  // Step 108: Fingers [89, 66, 23, 73, 85] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(66); // Index
  servo[2].write(23); // Middle
  servo[3].write(73); // Ring
  servo[4].write(85); // Pinky

  // Step 109: Fingers [89, 66, 23, 73, 85] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(66); // Index
  servo[2].write(23); // Middle
  servo[3].write(73); // Ring
  servo[4].write(85); // Pinky

  // Step 110: Fingers [91, 62, 23, 77, 82] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(62); // Index
  servo[2].write(23); // Middle
  servo[3].write(77); // Ring
  servo[4].write(82); // Pinky

  // Step 111: Fingers [92, 60, 24, 79, 81] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(60); // Index
  servo[2].write(24); // Middle
  servo[3].write(79); // Ring
  servo[4].write(81); // Pinky

  delay(14);
  // Step 112: Fingers [92, 60, 24, 79, 81] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(60); // Index
  servo[2].write(24); // Middle
  servo[3].write(79); // Ring
  servo[4].write(81); // Pinky

  delay(19);
  // Step 113: Fingers [93, 58, 25, 80, 79] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(58); // Index
  servo[2].write(25); // Middle
  servo[3].write(80); // Ring
  servo[4].write(79); // Pinky

  // Step 114: Fingers [94, 55, 25, 82, 77] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(55); // Index
  servo[2].write(25); // Middle
  servo[3].write(82); // Ring
  servo[4].write(77); // Pinky

  delay(13);
  // Step 115: Fingers [94, 55, 25, 82, 77] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(55); // Index
  servo[2].write(25); // Middle
  servo[3].write(82); // Ring
  servo[4].write(77); // Pinky

  // Step 116: Fingers [94, 53, 26, 84, 75] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(53); // Index
  servo[2].write(26); // Middle
  servo[3].write(84); // Ring
  servo[4].write(75); // Pinky

  // Step 117: Fingers [94, 51, 27, 85, 73] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(51); // Index
  servo[2].write(27); // Middle
  servo[3].write(85); // Ring
  servo[4].write(73); // Pinky

  // Step 118: Fingers [95, 51, 28, 86, 73] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(51); // Index
  servo[2].write(28); // Middle
  servo[3].write(86); // Ring
  servo[4].write(73); // Pinky

  // Step 119: Fingers [95, 51, 28, 86, 73] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(51); // Index
  servo[2].write(28); // Middle
  servo[3].write(86); // Ring
  servo[4].write(73); // Pinky

  // Step 120: Fingers [95, 47, 30, 88, 69] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(47); // Index
  servo[2].write(30); // Middle
  servo[3].write(88); // Ring
  servo[4].write(69); // Pinky

  // Step 121: Fingers [95, 47, 31, 89, 70] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(47); // Index
  servo[2].write(31); // Middle
  servo[3].write(89); // Ring
  servo[4].write(70); // Pinky

  // Step 122: Fingers [95, 45, 32, 90, 68] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(45); // Index
  servo[2].write(32); // Middle
  servo[3].write(90); // Ring
  servo[4].write(68); // Pinky

  // Step 123: Fingers [95, 43, 34, 91, 65] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(43); // Index
  servo[2].write(34); // Middle
  servo[3].write(91); // Ring
  servo[4].write(65); // Pinky

  // Step 124: Fingers [95, 43, 34, 91, 65] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(43); // Index
  servo[2].write(34); // Middle
  servo[3].write(91); // Ring
  servo[4].write(65); // Pinky

  // Step 125: Fingers [95, 42, 36, 93, 64] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(42); // Index
  servo[2].write(36); // Middle
  servo[3].write(93); // Ring
  servo[4].write(64); // Pinky

  // Step 126: Fingers [94, 40, 37, 93, 61] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(40); // Index
  servo[2].write(37); // Middle
  servo[3].write(93); // Ring
  servo[4].write(61); // Pinky

  delay(14);
  // Step 127: Fingers [94, 40, 37, 93, 61] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(40); // Index
  servo[2].write(37); // Middle
  servo[3].write(93); // Ring
  servo[4].write(61); // Pinky

  // Step 128: Fingers [94, 38, 39, 94, 59] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(38); // Index
  servo[2].write(39); // Middle
  servo[3].write(94); // Ring
  servo[4].write(59); // Pinky

  // Step 129: Fingers [94, 38, 40, 95, 60] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(38); // Index
  servo[2].write(40); // Middle
  servo[3].write(95); // Ring
  servo[4].write(60); // Pinky

  delay(17);
  // Step 130: Fingers [94, 37, 42, 96, 58] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(37); // Index
  servo[2].write(42); // Middle
  servo[3].write(96); // Ring
  servo[4].write(58); // Pinky

  // Step 131: Fingers [94, 37, 42, 96, 58] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(37); // Index
  servo[2].write(42); // Middle
  servo[3].write(96); // Ring
  servo[4].write(58); // Pinky

  // Step 132: Fingers [93, 36, 44, 96, 56] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(36); // Index
  servo[2].write(44); // Middle
  servo[3].write(96); // Ring
  servo[4].write(56); // Pinky

  // Step 133: Fingers [93, 36, 44, 96, 56] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(36); // Index
  servo[2].write(44); // Middle
  servo[3].write(96); // Ring
  servo[4].write(56); // Pinky

  // Step 134: Fingers [92, 34, 46, 97, 54] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(34); // Index
  servo[2].write(46); // Middle
  servo[3].write(97); // Ring
  servo[4].write(54); // Pinky

  delay(11);
  // Step 135: Fingers [92, 34, 46, 97, 54] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(34); // Index
  servo[2].write(46); // Middle
  servo[3].write(97); // Ring
  servo[4].write(54); // Pinky

  // Step 136: Fingers [90, 32, 51, 97, 50] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(32); // Index
  servo[2].write(51); // Middle
  servo[3].write(97); // Ring
  servo[4].write(50); // Pinky

  // Step 137: Fingers [89, 31, 53, 98, 48] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(31); // Index
  servo[2].write(53); // Middle
  servo[3].write(98); // Ring
  servo[4].write(48); // Pinky

  // Step 138: Fingers [89, 31, 53, 98, 48] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(31); // Index
  servo[2].write(53); // Middle
  servo[3].write(98); // Ring
  servo[4].write(48); // Pinky

  // Step 139: Fingers [90, 32, 54, 98, 49] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(32); // Index
  servo[2].write(54); // Middle
  servo[3].write(98); // Ring
  servo[4].write(49); // Pinky

  // Step 140: Fingers [88, 31, 56, 98, 47] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(31); // Index
  servo[2].write(56); // Middle
  servo[3].write(98); // Ring
  servo[4].write(47); // Pinky

  // Step 141: Fingers [89, 31, 56, 98, 47] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(31); // Index
  servo[2].write(56); // Middle
  servo[3].write(98); // Ring
  servo[4].write(47); // Pinky

  delay(19);
  // Step 142: Fingers [89, 31, 56, 98, 47] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(31); // Index
  servo[2].write(56); // Middle
  servo[3].write(98); // Ring
  servo[4].write(47); // Pinky

  // Step 143: Fingers [88, 30, 59, 98, 45] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(30); // Index
  servo[2].write(59); // Middle
  servo[3].write(98); // Ring
  servo[4].write(45); // Pinky

  delay(11);
  // Step 144: Fingers [86, 30, 61, 98, 44] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(30); // Index
  servo[2].write(61); // Middle
  servo[3].write(98); // Ring
  servo[4].write(44); // Pinky

  // Step 145: Fingers [86, 30, 61, 98, 44] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(30); // Index
  servo[2].write(61); // Middle
  servo[3].write(98); // Ring
  servo[4].write(44); // Pinky

  // Step 146: Fingers [86, 30, 62, 98, 44] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(30); // Index
  servo[2].write(62); // Middle
  servo[3].write(98); // Ring
  servo[4].write(44); // Pinky

  // Step 147: Fingers [87, 30, 62, 99, 44] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(30); // Index
  servo[2].write(62); // Middle
  servo[3].write(99); // Ring
  servo[4].write(44); // Pinky

  // Step 148: Fingers [85, 30, 64, 98, 43] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(30); // Index
  servo[2].write(64); // Middle
  servo[3].write(98); // Ring
  servo[4].write(43); // Pinky

  // Step 149: Fingers [85, 30, 64, 98, 43] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(30); // Index
  servo[2].write(64); // Middle
  servo[3].write(98); // Ring
  servo[4].write(43); // Pinky

  // Step 150: Fingers [85, 30, 65, 99, 43] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(30); // Index
  servo[2].write(65); // Middle
  servo[3].write(99); // Ring
  servo[4].write(43); // Pinky

  delay(14);
  // Step 151: Fingers [84, 30, 67, 98, 42] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(30); // Index
  servo[2].write(67); // Middle
  servo[3].write(98); // Ring
  servo[4].write(42); // Pinky

  // Step 152: Fingers [84, 30, 67, 98, 42] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(30); // Index
  servo[2].write(67); // Middle
  servo[3].write(98); // Ring
  servo[4].write(42); // Pinky

  delay(15);
  // Step 153: Fingers [84, 30, 68, 99, 42] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(30); // Index
  servo[2].write(68); // Middle
  servo[3].write(99); // Ring
  servo[4].write(42); // Pinky

  // Step 154: Fingers [82, 30, 70, 98, 40] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(30); // Index
  servo[2].write(70); // Middle
  servo[3].write(98); // Ring
  servo[4].write(40); // Pinky

  // Step 155: Fingers [82, 30, 70, 98, 40] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(30); // Index
  servo[2].write(70); // Middle
  servo[3].write(98); // Ring
  servo[4].write(40); // Pinky

  // Step 156: Fingers [83, 30, 70, 98, 41] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(30); // Index
  servo[2].write(70); // Middle
  servo[3].write(98); // Ring
  servo[4].write(41); // Pinky

  // Step 157: Fingers [81, 30, 73, 97, 39] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(30); // Index
  servo[2].write(73); // Middle
  servo[3].write(97); // Ring
  servo[4].write(39); // Pinky

  // Step 158: Fingers [81, 30, 73, 98, 40] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(30); // Index
  servo[2].write(73); // Middle
  servo[3].write(98); // Ring
  servo[4].write(40); // Pinky

  delay(15);
  // Step 159: Fingers [81, 30, 73, 98, 40] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(30); // Index
  servo[2].write(73); // Middle
  servo[3].write(98); // Ring
  servo[4].write(40); // Pinky

  // Step 160: Fingers [82, 31, 74, 98, 40] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(31); // Index
  servo[2].write(74); // Middle
  servo[3].write(98); // Ring
  servo[4].write(40); // Pinky

  // Step 161: Fingers [80, 31, 77, 98, 40] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(31); // Index
  servo[2].write(77); // Middle
  servo[3].write(98); // Ring
  servo[4].write(40); // Pinky

  delay(16);
  // Step 162: Fingers [80, 31, 77, 98, 40] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(31); // Index
  servo[2].write(77); // Middle
  servo[3].write(98); // Ring
  servo[4].write(40); // Pinky

  // Step 163: Fingers [81, 32, 77, 98, 40] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(32); // Index
  servo[2].write(77); // Middle
  servo[3].write(98); // Ring
  servo[4].write(40); // Pinky

  delay(16);
  // Step 164: Fingers [81, 32, 77, 99, 40] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(32); // Index
  servo[2].write(77); // Middle
  servo[3].write(99); // Ring
  servo[4].write(40); // Pinky

  // Step 165: Fingers [81, 32, 77, 99, 40] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(32); // Index
  servo[2].write(77); // Middle
  servo[3].write(99); // Ring
  servo[4].write(40); // Pinky

  // Step 166: Fingers [82, 33, 78, 99, 41] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(33); // Index
  servo[2].write(78); // Middle
  servo[3].write(99); // Ring
  servo[4].write(41); // Pinky

  delay(11);
  // Step 167: Fingers [80, 33, 80, 98, 39] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(33); // Index
  servo[2].write(80); // Middle
  servo[3].write(98); // Ring
  servo[4].write(39); // Pinky

  // Step 168: Fingers [80, 33, 80, 98, 39] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(33); // Index
  servo[2].write(80); // Middle
  servo[3].write(98); // Ring
  servo[4].write(39); // Pinky

  // Step 169: Fingers [80, 33, 80, 98, 40] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(33); // Index
  servo[2].write(80); // Middle
  servo[3].write(98); // Ring
  servo[4].write(40); // Pinky

  delay(16);
  // Step 170: Fingers [80, 34, 81, 99, 40] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(34); // Index
  servo[2].write(81); // Middle
  servo[3].write(99); // Ring
  servo[4].write(40); // Pinky

  // Step 171: Fingers [80, 34, 81, 99, 40] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(34); // Index
  servo[2].write(81); // Middle
  servo[3].write(99); // Ring
  servo[4].write(40); // Pinky

  // Step 172: Fingers [81, 34, 81, 99, 41] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(34); // Index
  servo[2].write(81); // Middle
  servo[3].write(99); // Ring
  servo[4].write(41); // Pinky

  // Step 173: Fingers [79, 34, 84, 98, 40] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(34); // Index
  servo[2].write(84); // Middle
  servo[3].write(98); // Ring
  servo[4].write(40); // Pinky

  delay(13);
  // Step 174: Fingers [77, 35, 86, 97, 39] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(35); // Index
  servo[2].write(86); // Middle
  servo[3].write(97); // Ring
  servo[4].write(39); // Pinky

  // Step 175: Fingers [77, 35, 86, 97, 39] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(35); // Index
  servo[2].write(86); // Middle
  servo[3].write(97); // Ring
  servo[4].write(39); // Pinky

  // Step 176: Fingers [78, 36, 87, 97, 40] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(36); // Index
  servo[2].write(87); // Middle
  servo[3].write(97); // Ring
  servo[4].write(40); // Pinky

  // Step 177: Fingers [78, 36, 87, 98, 40] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(36); // Index
  servo[2].write(87); // Middle
  servo[3].write(98); // Ring
  servo[4].write(40); // Pinky

  delay(25);
  // Step 178: Fingers [78, 36, 87, 98, 40] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(36); // Index
  servo[2].write(87); // Middle
  servo[3].write(98); // Ring
  servo[4].write(40); // Pinky

  // Step 179: Fingers [79, 36, 87, 98, 40] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(36); // Index
  servo[2].write(87); // Middle
  servo[3].write(98); // Ring
  servo[4].write(40); // Pinky

  // Step 180: Fingers [80, 37, 88, 99, 41] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(37); // Index
  servo[2].write(88); // Middle
  servo[3].write(99); // Ring
  servo[4].write(41); // Pinky

  delay(13);
  // Step 181: Fingers [80, 37, 88, 99, 41] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(37); // Index
  servo[2].write(88); // Middle
  servo[3].write(99); // Ring
  servo[4].write(41); // Pinky

  // Step 182: Fingers [80, 38, 89, 100, 42] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(38); // Index
  servo[2].write(89); // Middle
  servo[3].write(100); // Ring
  servo[4].write(42); // Pinky

  // Step 183: Fingers [81, 38, 90, 100, 43] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(38); // Index
  servo[2].write(90); // Middle
  servo[3].write(100); // Ring
  servo[4].write(43); // Pinky

  // Step 184: Fingers [79, 39, 92, 99, 42] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(39); // Index
  servo[2].write(92); // Middle
  servo[3].write(99); // Ring
  servo[4].write(42); // Pinky

  // Step 185: Fingers [79, 39, 92, 99, 42] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(39); // Index
  servo[2].write(92); // Middle
  servo[3].write(99); // Ring
  servo[4].write(42); // Pinky

  // Step 186: Fingers [79, 39, 92, 99, 42] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(39); // Index
  servo[2].write(92); // Middle
  servo[3].write(99); // Ring
  servo[4].write(42); // Pinky

  // Step 187: Fingers [80, 40, 93, 100, 43] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(40); // Index
  servo[2].write(93); // Middle
  servo[3].write(100); // Ring
  servo[4].write(43); // Pinky

  delay(15);
  // Step 188: Fingers [81, 41, 94, 101, 44] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(41); // Index
  servo[2].write(94); // Middle
  servo[3].write(101); // Ring
  servo[4].write(44); // Pinky

  // Step 189: Fingers [81, 41, 94, 101, 44] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(41); // Index
  servo[2].write(94); // Middle
  servo[3].write(101); // Ring
  servo[4].write(44); // Pinky

  // Step 190: Fingers [81, 41, 94, 101, 44] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(41); // Index
  servo[2].write(94); // Middle
  servo[3].write(101); // Ring
  servo[4].write(44); // Pinky

  // Step 191: Fingers [82, 42, 95, 102, 45] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(42); // Index
  servo[2].write(95); // Middle
  servo[3].write(102); // Ring
  servo[4].write(45); // Pinky

  // Step 192: Fingers [82, 43, 95, 103, 45] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(43); // Index
  servo[2].write(95); // Middle
  servo[3].write(103); // Ring
  servo[4].write(45); // Pinky

  // Step 193: Fingers [81, 44, 98, 102, 45] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(44); // Index
  servo[2].write(98); // Middle
  servo[3].write(102); // Ring
  servo[4].write(45); // Pinky

  // Step 194: Fingers [81, 44, 98, 102, 45] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(44); // Index
  servo[2].write(98); // Middle
  servo[3].write(102); // Ring
  servo[4].write(45); // Pinky

  // Step 195: Fingers [82, 44, 99, 102, 46] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(44); // Index
  servo[2].write(99); // Middle
  servo[3].write(102); // Ring
  servo[4].write(46); // Pinky

  // Step 196: Fingers [82, 45, 99, 103, 46] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(45); // Index
  servo[2].write(99); // Middle
  servo[3].write(103); // Ring
  servo[4].write(46); // Pinky

  // Step 197: Fingers [82, 45, 99, 103, 47] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(45); // Index
  servo[2].write(99); // Middle
  servo[3].write(103); // Ring
  servo[4].write(47); // Pinky

  // Step 198: Fingers [83, 46, 100, 103, 47] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(46); // Index
  servo[2].write(100); // Middle
  servo[3].write(103); // Ring
  servo[4].write(47); // Pinky

  // Step 199: Fingers [83, 46, 100, 103, 47] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(46); // Index
  servo[2].write(100); // Middle
  servo[3].write(103); // Ring
  servo[4].write(47); // Pinky

  // Step 200: Fingers [83, 46, 100, 104, 48] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(46); // Index
  servo[2].write(100); // Middle
  servo[3].write(104); // Ring
  servo[4].write(48); // Pinky

  // Step 201: Fingers [84, 47, 101, 104, 48] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(47); // Index
  servo[2].write(101); // Middle
  servo[3].write(104); // Ring
  servo[4].write(48); // Pinky

  // Step 202: Fingers [82, 48, 103, 103, 48] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(48); // Index
  servo[2].write(103); // Middle
  servo[3].write(103); // Ring
  servo[4].write(48); // Pinky

  // Step 203: Fingers [82, 48, 103, 103, 48] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(48); // Index
  servo[2].write(103); // Middle
  servo[3].write(103); // Ring
  servo[4].write(48); // Pinky

  // Step 204: Fingers [83, 48, 104, 104, 48] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(48); // Index
  servo[2].write(104); // Middle
  servo[3].write(104); // Ring
  servo[4].write(48); // Pinky

  delay(14);
  // Step 205: Fingers [83, 49, 104, 104, 49] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(49); // Index
  servo[2].write(104); // Middle
  servo[3].write(104); // Ring
  servo[4].write(49); // Pinky

  // Step 206: Fingers [83, 49, 104, 104, 49] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(49); // Index
  servo[2].write(104); // Middle
  servo[3].write(104); // Ring
  servo[4].write(49); // Pinky

  delay(15);
  // Step 207: Fingers [84, 49, 105, 105, 49] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(49); // Index
  servo[2].write(105); // Middle
  servo[3].write(105); // Ring
  servo[4].write(49); // Pinky

  // Step 208: Fingers [84, 50, 105, 105, 50] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(50); // Index
  servo[2].write(105); // Middle
  servo[3].write(105); // Ring
  servo[4].write(50); // Pinky

  // Step 209: Fingers [84, 50, 105, 105, 50] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(50); // Index
  servo[2].write(105); // Middle
  servo[3].write(105); // Ring
  servo[4].write(50); // Pinky

  delay(13);
  // Step 210: Fingers [82, 50, 107, 103, 49] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(50); // Index
  servo[2].write(107); // Middle
  servo[3].write(103); // Ring
  servo[4].write(49); // Pinky

  // Step 211: Fingers [82, 51, 107, 104, 50] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(51); // Index
  servo[2].write(107); // Middle
  servo[3].write(104); // Ring
  servo[4].write(50); // Pinky

  // Step 212: Fingers [82, 51, 107, 104, 50] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(51); // Index
  servo[2].write(107); // Middle
  servo[3].write(104); // Ring
  servo[4].write(50); // Pinky

  // Step 213: Fingers [83, 51, 108, 104, 50] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(51); // Index
  servo[2].write(108); // Middle
  servo[3].write(104); // Ring
  servo[4].write(50); // Pinky

  delay(15);
  // Step 214: Fingers [83, 52, 109, 105, 51] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(52); // Index
  servo[2].write(109); // Middle
  servo[3].write(105); // Ring
  servo[4].write(51); // Pinky

  // Step 215: Fingers [83, 52, 109, 105, 51] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(52); // Index
  servo[2].write(109); // Middle
  servo[3].write(105); // Ring
  servo[4].write(51); // Pinky

  // Step 216: Fingers [84, 53, 109, 105, 51] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(53); // Index
  servo[2].write(109); // Middle
  servo[3].write(105); // Ring
  servo[4].write(51); // Pinky

  // Step 217: Fingers [82, 53, 111, 103, 51] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(53); // Index
  servo[2].write(111); // Middle
  servo[3].write(103); // Ring
  servo[4].write(51); // Pinky

  // Step 218: Fingers [83, 54, 112, 104, 52] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(54); // Index
  servo[2].write(112); // Middle
  servo[3].write(104); // Ring
  servo[4].write(52); // Pinky

  // Step 219: Fingers [83, 54, 112, 104, 52] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(54); // Index
  servo[2].write(112); // Middle
  servo[3].write(104); // Ring
  servo[4].write(52); // Pinky

  // Step 220: Fingers [83, 55, 112, 105, 52] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(55); // Index
  servo[2].write(112); // Middle
  servo[3].write(105); // Ring
  servo[4].write(52); // Pinky

  // Step 221: Fingers [83, 55, 112, 105, 52] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(55); // Index
  servo[2].write(112); // Middle
  servo[3].write(105); // Ring
  servo[4].write(52); // Pinky

  delay(16);
  // Step 222: Fingers [83, 55, 112, 105, 52] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(55); // Index
  servo[2].write(112); // Middle
  servo[3].write(105); // Ring
  servo[4].write(52); // Pinky

  // Step 223: Fingers [84, 56, 113, 106, 53] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(56); // Index
  servo[2].write(113); // Middle
  servo[3].write(106); // Ring
  servo[4].write(53); // Pinky

  // Step 224: Fingers [85, 56, 114, 106, 54] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(56); // Index
  servo[2].write(114); // Middle
  servo[3].write(106); // Ring
  servo[4].write(54); // Pinky

  // Step 225: Fingers [85, 57, 115, 107, 55] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(57); // Index
  servo[2].write(115); // Middle
  servo[3].write(107); // Ring
  servo[4].write(55); // Pinky

  // Step 226: Fingers [85, 57, 115, 107, 55] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(57); // Index
  servo[2].write(115); // Middle
  servo[3].write(107); // Ring
  servo[4].write(55); // Pinky

  // Step 227: Fingers [86, 58, 115, 108, 55] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(58); // Index
  servo[2].write(115); // Middle
  servo[3].write(108); // Ring
  servo[4].write(55); // Pinky

  // Step 228: Fingers [87, 59, 116, 109, 56] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(59); // Index
  servo[2].write(116); // Middle
  servo[3].write(109); // Ring
  servo[4].write(56); // Pinky

  // Step 229: Fingers [88, 60, 117, 110, 57] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(60); // Index
  servo[2].write(117); // Middle
  servo[3].write(110); // Ring
  servo[4].write(57); // Pinky

  // Step 230: Fingers [88, 60, 117, 110, 57] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(60); // Index
  servo[2].write(117); // Middle
  servo[3].write(110); // Ring
  servo[4].write(57); // Pinky

  // Step 231: Fingers [88, 60, 117, 110, 58] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(60); // Index
  servo[2].write(117); // Middle
  servo[3].write(110); // Ring
  servo[4].write(58); // Pinky

  // Step 232: Fingers [89, 61, 118, 111, 58] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(61); // Index
  servo[2].write(118); // Middle
  servo[3].write(111); // Ring
  servo[4].write(58); // Pinky

  // Step 233: Fingers [90, 62, 119, 112, 59] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(62); // Index
  servo[2].write(119); // Middle
  servo[3].write(112); // Ring
  servo[4].write(59); // Pinky

  // Step 234: Fingers [91, 63, 120, 113, 60] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(63); // Index
  servo[2].write(120); // Middle
  servo[3].write(113); // Ring
  servo[4].write(60); // Pinky

  // Step 235: Fingers [91, 63, 120, 113, 60] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(63); // Index
  servo[2].write(120); // Middle
  servo[3].write(113); // Ring
  servo[4].write(60); // Pinky

  delay(13);
  // Step 236: Fingers [91, 63, 120, 113, 61] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(63); // Index
  servo[2].write(120); // Middle
  servo[3].write(113); // Ring
  servo[4].write(61); // Pinky

  // Step 237: Fingers [92, 64, 121, 114, 61] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(64); // Index
  servo[2].write(121); // Middle
  servo[3].write(114); // Ring
  servo[4].write(61); // Pinky

  // Step 238: Fingers [93, 65, 122, 115, 62] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(65); // Index
  servo[2].write(122); // Middle
  servo[3].write(115); // Ring
  servo[4].write(62); // Pinky

  // Step 239: Fingers [94, 65, 123, 115, 63] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(65); // Index
  servo[2].write(123); // Middle
  servo[3].write(115); // Ring
  servo[4].write(63); // Pinky

  // Step 240: Fingers [94, 65, 123, 115, 63] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(65); // Index
  servo[2].write(123); // Middle
  servo[3].write(115); // Ring
  servo[4].write(63); // Pinky

  // Step 241: Fingers [94, 66, 123, 116, 64] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(66); // Index
  servo[2].write(123); // Middle
  servo[3].write(116); // Ring
  servo[4].write(64); // Pinky

  // Step 242: Fingers [97, 66, 122, 119, 64] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(66); // Index
  servo[2].write(122); // Middle
  servo[3].write(119); // Ring
  servo[4].write(64); // Pinky

  // Step 243: Fingers [98, 67, 123, 119, 65] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(67); // Index
  servo[2].write(123); // Middle
  servo[3].write(119); // Ring
  servo[4].write(65); // Pinky

  // Step 244: Fingers [101, 67, 122, 122, 67] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(67); // Index
  servo[2].write(122); // Middle
  servo[3].write(122); // Ring
  servo[4].write(67); // Pinky

  // Step 245: Fingers [101, 67, 122, 122, 67] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(67); // Index
  servo[2].write(122); // Middle
  servo[3].write(122); // Ring
  servo[4].write(67); // Pinky

  // Step 246: Fingers [101, 67, 123, 123, 67] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(67); // Index
  servo[2].write(123); // Middle
  servo[3].write(123); // Ring
  servo[4].write(67); // Pinky

  // Step 247: Fingers [102, 68, 123, 123, 68] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(68); // Index
  servo[2].write(123); // Middle
  servo[3].write(123); // Ring
  servo[4].write(68); // Pinky

  // Step 248: Fingers [103, 68, 124, 124, 68] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(68); // Index
  servo[2].write(124); // Middle
  servo[3].write(124); // Ring
  servo[4].write(68); // Pinky

  // Step 249: Fingers [103, 69, 124, 124, 69] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(69); // Index
  servo[2].write(124); // Middle
  servo[3].write(124); // Ring
  servo[4].write(69); // Pinky

  // Step 250: Fingers [103, 69, 124, 124, 69] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(69); // Index
  servo[2].write(124); // Middle
  servo[3].write(124); // Ring
  servo[4].write(69); // Pinky

  // Step 251: Fingers [106, 69, 123, 127, 70] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(69); // Index
  servo[2].write(123); // Middle
  servo[3].write(127); // Ring
  servo[4].write(70); // Pinky

  delay(15);
  // Step 252: Fingers [106, 69, 123, 127, 70] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(69); // Index
  servo[2].write(123); // Middle
  servo[3].write(127); // Ring
  servo[4].write(70); // Pinky

  // Step 253: Fingers [107, 70, 124, 127, 71] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(70); // Index
  servo[2].write(124); // Middle
  servo[3].write(127); // Ring
  servo[4].write(71); // Pinky

  // Step 254: Fingers [107, 70, 124, 128, 71] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(70); // Index
  servo[2].write(124); // Middle
  servo[3].write(128); // Ring
  servo[4].write(71); // Pinky

  // Step 255: Fingers [110, 70, 123, 130, 73] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(70); // Index
  servo[2].write(123); // Middle
  servo[3].write(130); // Ring
  servo[4].write(73); // Pinky

  // Step 256: Fingers [110, 70, 123, 130, 73] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(70); // Index
  servo[2].write(123); // Middle
  servo[3].write(130); // Ring
  servo[4].write(73); // Pinky

  // Step 257: Fingers [110, 70, 123, 130, 73] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(70); // Index
  servo[2].write(123); // Middle
  servo[3].write(130); // Ring
  servo[4].write(73); // Pinky

  // Step 258: Fingers [111, 71, 124, 131, 74] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(71); // Index
  servo[2].write(124); // Middle
  servo[3].write(131); // Ring
  servo[4].write(74); // Pinky

  delay(14);
  // Step 259: Fingers [111, 72, 124, 132, 74] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(72); // Index
  servo[2].write(124); // Middle
  servo[3].write(132); // Ring
  servo[4].write(74); // Pinky

  // Step 260: Fingers [111, 72, 124, 132, 74] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(72); // Index
  servo[2].write(124); // Middle
  servo[3].write(132); // Ring
  servo[4].write(74); // Pinky

  // Step 261: Fingers [112, 72, 125, 132, 75] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(72); // Index
  servo[2].write(125); // Middle
  servo[3].write(132); // Ring
  servo[4].write(75); // Pinky

  // Step 262: Fingers [114, 72, 123, 134, 76] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(72); // Index
  servo[2].write(123); // Middle
  servo[3].write(134); // Ring
  servo[4].write(76); // Pinky

  // Step 263: Fingers [115, 73, 124, 134, 77] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(73); // Index
  servo[2].write(124); // Middle
  servo[3].write(134); // Ring
  servo[4].write(77); // Pinky

  // Step 264: Fingers [115, 73, 124, 134, 77] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(73); // Index
  servo[2].write(124); // Middle
  servo[3].write(134); // Ring
  servo[4].write(77); // Pinky

  // Step 265: Fingers [115, 73, 124, 135, 77] Arm [-, -, -]
  servo[0].write(115); // Thumb
  servo[1].write(73); // Index
  servo[2].write(124); // Middle
  servo[3].write(135); // Ring
  servo[4].write(77); // Pinky

  // Step 266: Fingers [116, 73, 124, 135, 77] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(73); // Index
  servo[2].write(124); // Middle
  servo[3].write(135); // Ring
  servo[4].write(77); // Pinky

  // Step 267: Fingers [118, 74, 123, 137, 79] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(74); // Index
  servo[2].write(123); // Middle
  servo[3].write(137); // Ring
  servo[4].write(79); // Pinky

  // Step 268: Fingers [118, 74, 123, 137, 79] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(74); // Index
  servo[2].write(123); // Middle
  servo[3].write(137); // Ring
  servo[4].write(79); // Pinky

  // Step 269: Fingers [121, 74, 121, 139, 81] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(74); // Index
  servo[2].write(121); // Middle
  servo[3].write(139); // Ring
  servo[4].write(81); // Pinky

  // Step 270: Fingers [121, 74, 122, 139, 81] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(74); // Index
  servo[2].write(122); // Middle
  servo[3].write(139); // Ring
  servo[4].write(81); // Pinky

  // Step 271: Fingers [121, 74, 122, 139, 81] Arm [-, -, -]
  servo[0].write(121); // Thumb
  servo[1].write(74); // Index
  servo[2].write(122); // Middle
  servo[3].write(139); // Ring
  servo[4].write(81); // Pinky

  // Step 272: Fingers [122, 75, 122, 140, 82] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(75); // Index
  servo[2].write(122); // Middle
  servo[3].write(140); // Ring
  servo[4].write(82); // Pinky

  // Step 273: Fingers [124, 75, 120, 141, 83] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(75); // Index
  servo[2].write(120); // Middle
  servo[3].write(141); // Ring
  servo[4].write(83); // Pinky

  delay(16);
  // Step 274: Fingers [124, 75, 120, 141, 83] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(75); // Index
  servo[2].write(120); // Middle
  servo[3].write(141); // Ring
  servo[4].write(83); // Pinky

  // Step 275: Fingers [125, 76, 121, 142, 84] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(76); // Index
  servo[2].write(121); // Middle
  servo[3].write(142); // Ring
  servo[4].write(84); // Pinky

  // Step 276: Fingers [125, 76, 121, 142, 84] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(76); // Index
  servo[2].write(121); // Middle
  servo[3].write(142); // Ring
  servo[4].write(84); // Pinky

  // Step 277: Fingers [128, 77, 119, 144, 86] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(77); // Index
  servo[2].write(119); // Middle
  servo[3].write(144); // Ring
  servo[4].write(86); // Pinky

  // Step 278: Fingers [128, 77, 120, 144, 86] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(77); // Index
  servo[2].write(120); // Middle
  servo[3].write(144); // Ring
  servo[4].write(86); // Pinky

  // Step 279: Fingers [128, 77, 120, 144, 86] Arm [-, -, -]
  servo[0].write(128); // Thumb
  servo[1].write(77); // Index
  servo[2].write(120); // Middle
  servo[3].write(144); // Ring
  servo[4].write(86); // Pinky

  // Step 280: Fingers [130, 78, 118, 146, 88] Arm [-, -, -]
  servo[0].write(130); // Thumb
  servo[1].write(78); // Index
  servo[2].write(118); // Middle
  servo[3].write(146); // Ring
  servo[4].write(88); // Pinky

  // Step 281: Fingers [131, 78, 119, 146, 89] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(78); // Index
  servo[2].write(119); // Middle
  servo[3].write(146); // Ring
  servo[4].write(89); // Pinky

  // Step 282: Fingers [133, 79, 117, 148, 91] Arm [-, -, -]
  servo[0].write(133); // Thumb
  servo[1].write(79); // Index
  servo[2].write(117); // Middle
  servo[3].write(148); // Ring
  servo[4].write(91); // Pinky

  // Step 283: Fingers [134, 80, 117, 148, 91] Arm [-, -, -]
  servo[0].write(134); // Thumb
  servo[1].write(80); // Index
  servo[2].write(117); // Middle
  servo[3].write(148); // Ring
  servo[4].write(91); // Pinky

  // Step 284: Fingers [134, 80, 117, 148, 91] Arm [-, -, -]
  servo[0].write(134); // Thumb
  servo[1].write(80); // Index
  servo[2].write(117); // Middle
  servo[3].write(148); // Ring
  servo[4].write(91); // Pinky

  // Step 285: Fingers [134, 80, 118, 148, 92] Arm [-, -, -]
  servo[0].write(134); // Thumb
  servo[1].write(80); // Index
  servo[2].write(118); // Middle
  servo[3].write(148); // Ring
  servo[4].write(92); // Pinky

  // Step 286: Fingers [136, 81, 116, 150, 94] Arm [-, -, -]
  servo[0].write(136); // Thumb
  servo[1].write(81); // Index
  servo[2].write(116); // Middle
  servo[3].write(150); // Ring
  servo[4].write(94); // Pinky

  delay(14);
  // Step 287: Fingers [137, 82, 116, 150, 94] Arm [-, -, -]
  servo[0].write(137); // Thumb
  servo[1].write(82); // Index
  servo[2].write(116); // Middle
  servo[3].write(150); // Ring
  servo[4].write(94); // Pinky

  // Step 288: Fingers [137, 82, 116, 150, 94] Arm [-, -, -]
  servo[0].write(137); // Thumb
  servo[1].write(82); // Index
  servo[2].write(116); // Middle
  servo[3].write(150); // Ring
  servo[4].write(94); // Pinky

  // Step 289: Fingers [137, 82, 117, 150, 95] Arm [-, -, -]
  servo[0].write(137); // Thumb
  servo[1].write(82); // Index
  servo[2].write(117); // Middle
  servo[3].write(150); // Ring
  servo[4].write(95); // Pinky

  // Step 290: Fingers [138, 82, 117, 151, 95] Arm [-, -, -]
  servo[0].write(138); // Thumb
  servo[1].write(82); // Index
  servo[2].write(117); // Middle
  servo[3].write(151); // Ring
  servo[4].write(95); // Pinky

  // Step 291: Fingers [139, 83, 115, 151, 97] Arm [-, -, -]
  servo[0].write(139); // Thumb
  servo[1].write(83); // Index
  servo[2].write(115); // Middle
  servo[3].write(151); // Ring
  servo[4].write(97); // Pinky

  // Step 292: Fingers [142, 84, 113, 152, 99] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(84); // Index
  servo[2].write(113); // Middle
  servo[3].write(152); // Ring
  servo[4].write(99); // Pinky

  // Step 293: Fingers [142, 84, 113, 152, 99] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(84); // Index
  servo[2].write(113); // Middle
  servo[3].write(152); // Ring
  servo[4].write(99); // Pinky

  // Step 294: Fingers [142, 85, 113, 153, 100] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(85); // Index
  servo[2].write(113); // Middle
  servo[3].write(153); // Ring
  servo[4].write(100); // Pinky

  // Step 295: Fingers [142, 85, 114, 153, 100] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(85); // Index
  servo[2].write(114); // Middle
  servo[3].write(153); // Ring
  servo[4].write(100); // Pinky

  // Step 296: Fingers [143, 86, 114, 154, 101] Arm [-, -, -]
  servo[0].write(143); // Thumb
  servo[1].write(86); // Index
  servo[2].write(114); // Middle
  servo[3].write(154); // Ring
  servo[4].write(101); // Pinky

  // Step 297: Fingers [145, 87, 113, 155, 103] Arm [-, -, -]
  servo[0].write(145); // Thumb
  servo[1].write(87); // Index
  servo[2].write(113); // Middle
  servo[3].write(155); // Ring
  servo[4].write(103); // Pinky

  // Step 298: Fingers [145, 87, 113, 155, 103] Arm [-, -, -]
  servo[0].write(145); // Thumb
  servo[1].write(87); // Index
  servo[2].write(113); // Middle
  servo[3].write(155); // Ring
  servo[4].write(103); // Pinky

  // Step 299: Fingers [145, 88, 113, 155, 104] Arm [-, -, -]
  servo[0].write(145); // Thumb
  servo[1].write(88); // Index
  servo[2].write(113); // Middle
  servo[3].write(155); // Ring
  servo[4].write(104); // Pinky

  // Step 300: Fingers [146, 88, 113, 155, 104] Arm [-, -, -]
  servo[0].write(146); // Thumb
  servo[1].write(88); // Index
  servo[2].write(113); // Middle
  servo[3].write(155); // Ring
  servo[4].write(104); // Pinky

  // Step 301: Fingers [148, 89, 112, 156, 106] Arm [-, -, -]
  servo[0].write(148); // Thumb
  servo[1].write(89); // Index
  servo[2].write(112); // Middle
  servo[3].write(156); // Ring
  servo[4].write(106); // Pinky

  // Step 302: Fingers [150, 92, 110, 157, 109] Arm [-, -, -]
  servo[0].write(150); // Thumb
  servo[1].write(92); // Index
  servo[2].write(110); // Middle
  servo[3].write(157); // Ring
  servo[4].write(109); // Pinky

  // Step 303: Fingers [150, 92, 110, 157, 109] Arm [-, -, -]
  servo[0].write(150); // Thumb
  servo[1].write(92); // Index
  servo[2].write(110); // Middle
  servo[3].write(157); // Ring
  servo[4].write(109); // Pinky

  // Step 304: Fingers [152, 94, 109, 158, 112] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(94); // Index
  servo[2].write(109); // Middle
  servo[3].write(158); // Ring
  servo[4].write(112); // Pinky

  // Step 305: Fingers [152, 94, 109, 158, 113] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(94); // Index
  servo[2].write(109); // Middle
  servo[3].write(158); // Ring
  servo[4].write(113); // Pinky

  // Step 306: Fingers [156, 98, 107, 159, 118] Arm [-, -, -]
  servo[0].write(156); // Thumb
  servo[1].write(98); // Index
  servo[2].write(107); // Middle
  servo[3].write(159); // Ring
  servo[4].write(118); // Pinky

  // Step 307: Fingers [156, 99, 107, 159, 119] Arm [-, -, -]
  servo[0].write(156); // Thumb
  servo[1].write(99); // Index
  servo[2].write(107); // Middle
  servo[3].write(159); // Ring
  servo[4].write(119); // Pinky

  // Step 308: Fingers [156, 99, 107, 159, 119] Arm [-, -, -]
  servo[0].write(156); // Thumb
  servo[1].write(99); // Index
  servo[2].write(107); // Middle
  servo[3].write(159); // Ring
  servo[4].write(119); // Pinky

  // Step 309: Fingers [158, 101, 106, 159, 122] Arm [-, -, -]
  servo[0].write(158); // Thumb
  servo[1].write(101); // Index
  servo[2].write(106); // Middle
  servo[3].write(159); // Ring
  servo[4].write(122); // Pinky

  // Step 310: Fingers [159, 104, 105, 160, 125] Arm [-, -, -]
  servo[0].write(159); // Thumb
  servo[1].write(104); // Index
  servo[2].write(105); // Middle
  servo[3].write(160); // Ring
  servo[4].write(125); // Pinky

  delay(14);
  // Step 311: Fingers [159, 104, 105, 160, 125] Arm [-, -, -]
  servo[0].write(159); // Thumb
  servo[1].write(104); // Index
  servo[2].write(105); // Middle
  servo[3].write(160); // Ring
  servo[4].write(125); // Pinky

  // Step 312: Fingers [160, 106, 103, 159, 127] Arm [-, -, -]
  servo[0].write(160); // Thumb
  servo[1].write(106); // Index
  servo[2].write(103); // Middle
  servo[3].write(159); // Ring
  servo[4].write(127); // Pinky

  delay(24);
  // Step 313: Fingers [160, 106, 103, 159, 127] Arm [-, -, -]
  servo[0].write(160); // Thumb
  servo[1].write(106); // Index
  servo[2].write(103); // Middle
  servo[3].write(159); // Ring
  servo[4].write(127); // Pinky

  // Step 314: Fingers [161, 108, 102, 159, 130] Arm [-, -, -]
  servo[0].write(161); // Thumb
  servo[1].write(108); // Index
  servo[2].write(102); // Middle
  servo[3].write(159); // Ring
  servo[4].write(130); // Pinky

  // Step 315: Fingers [162, 111, 101, 158, 133] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(111); // Index
  servo[2].write(101); // Middle
  servo[3].write(158); // Ring
  servo[4].write(133); // Pinky

  delay(23);
  // Step 316: Fingers [162, 111, 101, 158, 133] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(111); // Index
  servo[2].write(101); // Middle
  servo[3].write(158); // Ring
  servo[4].write(133); // Pinky

  // Step 317: Fingers [162, 113, 99, 157, 135] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(113); // Index
  servo[2].write(99); // Middle
  servo[3].write(157); // Ring
  servo[4].write(135); // Pinky

  // Step 318: Fingers [162, 115, 98, 156, 137] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(115); // Index
  servo[2].write(98); // Middle
  servo[3].write(156); // Ring
  servo[4].write(137); // Pinky

  // Step 319: Fingers [163, 117, 97, 155, 139] Arm [-, -, -]
  servo[0].write(163); // Thumb
  servo[1].write(117); // Index
  servo[2].write(97); // Middle
  servo[3].write(155); // Ring
  servo[4].write(139); // Pinky

  // Step 320: Fingers [163, 117, 97, 155, 139] Arm [-, -, -]
  servo[0].write(163); // Thumb
  servo[1].write(117); // Index
  servo[2].write(97); // Middle
  servo[3].write(155); // Ring
  servo[4].write(139); // Pinky

  // Step 321: Fingers [163, 119, 96, 154, 141] Arm [-, -, -]
  servo[0].write(163); // Thumb
  servo[1].write(119); // Index
  servo[2].write(96); // Middle
  servo[3].write(154); // Ring
  servo[4].write(141); // Pinky

  // Step 322: Fingers [162, 122, 95, 152, 143] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(122); // Index
  servo[2].write(95); // Middle
  servo[3].write(152); // Ring
  servo[4].write(143); // Pinky

  // Step 323: Fingers [162, 124, 94, 151, 146] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(124); // Index
  servo[2].write(94); // Middle
  servo[3].write(151); // Ring
  servo[4].write(146); // Pinky

  // Step 324: Fingers [162, 124, 94, 151, 146] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(124); // Index
  servo[2].write(94); // Middle
  servo[3].write(151); // Ring
  servo[4].write(146); // Pinky

  // Step 325: Fingers [163, 125, 95, 151, 146] Arm [-, -, -]
  servo[0].write(163); // Thumb
  servo[1].write(125); // Index
  servo[2].write(95); // Middle
  servo[3].write(151); // Ring
  servo[4].write(146); // Pinky

  // Step 326: Fingers [162, 127, 94, 150, 148] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(127); // Index
  servo[2].write(94); // Middle
  servo[3].write(150); // Ring
  servo[4].write(148); // Pinky

  // Step 327: Fingers [162, 129, 93, 148, 150] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(129); // Index
  servo[2].write(93); // Middle
  servo[3].write(148); // Ring
  servo[4].write(150); // Pinky

  delay(15);
  // Step 328: Fingers [162, 129, 93, 148, 150] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(129); // Index
  servo[2].write(93); // Middle
  servo[3].write(148); // Ring
  servo[4].write(150); // Pinky

  // Step 329: Fingers [160, 134, 93, 144, 154] Arm [-, -, -]
  servo[0].write(160); // Thumb
  servo[1].write(134); // Index
  servo[2].write(93); // Middle
  servo[3].write(144); // Ring
  servo[4].write(154); // Pinky

  // Step 330: Fingers [160, 137, 93, 143, 156] Arm [-, -, -]
  servo[0].write(160); // Thumb
  servo[1].write(137); // Index
  servo[2].write(93); // Middle
  servo[3].write(143); // Ring
  servo[4].write(156); // Pinky

  delay(16);
  // Step 331: Fingers [160, 137, 93, 143, 156] Arm [-, -, -]
  servo[0].write(160); // Thumb
  servo[1].write(137); // Index
  servo[2].write(93); // Middle
  servo[3].write(143); // Ring
  servo[4].write(156); // Pinky

  // Step 332: Fingers [157, 141, 93, 139, 158] Arm [-, -, -]
  servo[0].write(157); // Thumb
  servo[1].write(141); // Index
  servo[2].write(93); // Middle
  servo[3].write(139); // Ring
  servo[4].write(158); // Pinky

  // Step 333: Fingers [155, 145, 93, 135, 161] Arm [-, -, -]
  servo[0].write(155); // Thumb
  servo[1].write(145); // Index
  servo[2].write(93); // Middle
  servo[3].write(135); // Ring
  servo[4].write(161); // Pinky

  // Step 334: Fingers [153, 148, 94, 133, 162] Arm [-, -, -]
  servo[0].write(153); // Thumb
  servo[1].write(148); // Index
  servo[2].write(94); // Middle
  servo[3].write(133); // Ring
  servo[4].write(162); // Pinky

  // Step 335: Fingers [152, 150, 95, 131, 163] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(150); // Index
  servo[2].write(95); // Middle
  servo[3].write(131); // Ring
  servo[4].write(163); // Pinky

  // Step 336: Fingers [152, 150, 95, 131, 163] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(150); // Index
  servo[2].write(95); // Middle
  servo[3].write(131); // Ring
  servo[4].write(163); // Pinky

  // Step 337: Fingers [148, 154, 97, 127, 165] Arm [-, -, -]
  servo[0].write(148); // Thumb
  servo[1].write(154); // Index
  servo[2].write(97); // Middle
  servo[3].write(127); // Ring
  servo[4].write(165); // Pinky

  // Step 338: Fingers [146, 155, 98, 124, 165] Arm [-, -, -]
  servo[0].write(146); // Thumb
  servo[1].write(155); // Index
  servo[2].write(98); // Middle
  servo[3].write(124); // Ring
  servo[4].write(165); // Pinky

  // Step 339: Fingers [144, 157, 99, 122, 166] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(157); // Index
  servo[2].write(99); // Middle
  servo[3].write(122); // Ring
  servo[4].write(166); // Pinky

  delay(17);
  // Step 340: Fingers [144, 157, 99, 122, 166] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(157); // Index
  servo[2].write(99); // Middle
  servo[3].write(122); // Ring
  servo[4].write(166); // Pinky

  // Step 341: Fingers [142, 158, 100, 120, 166] Arm [-, -, -]
  servo[0].write(142); // Thumb
  servo[1].write(158); // Index
  servo[2].write(100); // Middle
  servo[3].write(120); // Ring
  servo[4].write(166); // Pinky

  // Step 342: Fingers [140, 159, 101, 118, 166] Arm [-, -, -]
  servo[0].write(140); // Thumb
  servo[1].write(159); // Index
  servo[2].write(101); // Middle
  servo[3].write(118); // Ring
  servo[4].write(166); // Pinky

  delay(16);
  // Step 343: Fingers [138, 161, 103, 116, 166] Arm [-, -, -]
  servo[0].write(138); // Thumb
  servo[1].write(161); // Index
  servo[2].write(103); // Middle
  servo[3].write(116); // Ring
  servo[4].write(166); // Pinky

  // Step 344: Fingers [138, 161, 103, 116, 166] Arm [-, -, -]
  servo[0].write(138); // Thumb
  servo[1].write(161); // Index
  servo[2].write(103); // Middle
  servo[3].write(116); // Ring
  servo[4].write(166); // Pinky

  // Step 345: Fingers [136, 162, 104, 114, 166] Arm [-, -, -]
  servo[0].write(136); // Thumb
  servo[1].write(162); // Index
  servo[2].write(104); // Middle
  servo[3].write(114); // Ring
  servo[4].write(166); // Pinky

  // Step 346: Fingers [134, 163, 106, 112, 165] Arm [-, -, -]
  servo[0].write(134); // Thumb
  servo[1].write(163); // Index
  servo[2].write(106); // Middle
  servo[3].write(112); // Ring
  servo[4].write(165); // Pinky

  // Step 347: Fingers [131, 164, 107, 110, 165] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(164); // Index
  servo[2].write(107); // Middle
  servo[3].write(110); // Ring
  servo[4].write(165); // Pinky

  // Step 348: Fingers [131, 164, 107, 110, 165] Arm [-, -, -]
  servo[0].write(131); // Thumb
  servo[1].write(164); // Index
  servo[2].write(107); // Middle
  servo[3].write(110); // Ring
  servo[4].write(165); // Pinky

  // Step 349: Fingers [129, 164, 109, 108, 164] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(164); // Index
  servo[2].write(109); // Middle
  servo[3].write(108); // Ring
  servo[4].write(164); // Pinky

  // Step 350: Fingers [127, 165, 111, 106, 163] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(165); // Index
  servo[2].write(111); // Middle
  servo[3].write(106); // Ring
  servo[4].write(163); // Pinky

  // Step 351: Fingers [125, 165, 113, 105, 162] Arm [-, -, -]
  servo[0].write(125); // Thumb
  servo[1].write(165); // Index
  servo[2].write(113); // Middle
  servo[3].write(105); // Ring
  servo[4].write(162); // Pinky

  // Step 352: Fingers [123, 166, 115, 103, 161] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(166); // Index
  servo[2].write(115); // Middle
  servo[3].write(103); // Ring
  servo[4].write(161); // Pinky

  // Step 353: Fingers [123, 166, 115, 103, 161] Arm [-, -, -]
  servo[0].write(123); // Thumb
  servo[1].write(166); // Index
  servo[2].write(115); // Middle
  servo[3].write(103); // Ring
  servo[4].write(161); // Pinky

  // Step 354: Fingers [120, 166, 117, 102, 160] Arm [-, -, -]
  servo[0].write(120); // Thumb
  servo[1].write(166); // Index
  servo[2].write(117); // Middle
  servo[3].write(102); // Ring
  servo[4].write(160); // Pinky

  // Step 355: Fingers [118, 166, 119, 100, 159] Arm [-, -, -]
  servo[0].write(118); // Thumb
  servo[1].write(166); // Index
  servo[2].write(119); // Middle
  servo[3].write(100); // Ring
  servo[4].write(159); // Pinky

  // Step 356: Fingers [116, 166, 121, 99, 157] Arm [-, -, -]
  servo[0].write(116); // Thumb
  servo[1].write(166); // Index
  servo[2].write(121); // Middle
  servo[3].write(99); // Ring
  servo[4].write(157); // Pinky

  // Step 357: Fingers [114, 166, 124, 98, 156] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(166); // Index
  servo[2].write(124); // Middle
  servo[3].write(98); // Ring
  servo[4].write(156); // Pinky

  // Step 358: Fingers [114, 166, 124, 98, 156] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(166); // Index
  servo[2].write(124); // Middle
  servo[3].write(98); // Ring
  servo[4].write(156); // Pinky

  delay(11);
  // Step 359: Fingers [112, 165, 126, 97, 154] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(165); // Index
  servo[2].write(126); // Middle
  servo[3].write(97); // Ring
  servo[4].write(154); // Pinky

  delay(14);
  // Step 360: Fingers [108, 164, 130, 95, 150] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(164); // Index
  servo[2].write(130); // Middle
  servo[3].write(95); // Ring
  servo[4].write(150); // Pinky

  // Step 361: Fingers [108, 164, 130, 95, 150] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(164); // Index
  servo[2].write(130); // Middle
  servo[3].write(95); // Ring
  servo[4].write(150); // Pinky

  delay(16);
  // Step 362: Fingers [106, 162, 132, 94, 148] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(162); // Index
  servo[2].write(132); // Middle
  servo[3].write(94); // Ring
  servo[4].write(148); // Pinky

  delay(15);
  // Step 363: Fingers [106, 162, 132, 94, 148] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(162); // Index
  servo[2].write(132); // Middle
  servo[3].write(94); // Ring
  servo[4].write(148); // Pinky

  // Step 364: Fingers [104, 162, 134, 94, 146] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(162); // Index
  servo[2].write(134); // Middle
  servo[3].write(94); // Ring
  servo[4].write(146); // Pinky

  // Step 365: Fingers [103, 160, 136, 93, 144] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(160); // Index
  servo[2].write(136); // Middle
  servo[3].write(93); // Ring
  servo[4].write(144); // Pinky

  // Step 366: Fingers [101, 159, 138, 93, 142] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(159); // Index
  servo[2].write(138); // Middle
  servo[3].write(93); // Ring
  servo[4].write(142); // Pinky

  // Step 367: Fingers [101, 159, 138, 93, 142] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(159); // Index
  servo[2].write(138); // Middle
  servo[3].write(93); // Ring
  servo[4].write(142); // Pinky

  // Step 368: Fingers [99, 158, 140, 93, 140] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(158); // Index
  servo[2].write(140); // Middle
  servo[3].write(93); // Ring
  servo[4].write(140); // Pinky

  delay(14);
  // Step 369: Fingers [97, 154, 144, 92, 135] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(154); // Index
  servo[2].write(144); // Middle
  servo[3].write(92); // Ring
  servo[4].write(135); // Pinky

  // Step 370: Fingers [97, 154, 144, 92, 135] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(154); // Index
  servo[2].write(144); // Middle
  servo[3].write(92); // Ring
  servo[4].write(135); // Pinky

  // Step 371: Fingers [96, 154, 143, 92, 134] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(154); // Index
  servo[2].write(143); // Middle
  servo[3].write(92); // Ring
  servo[4].write(134); // Pinky

  // Step 372: Fingers [95, 152, 145, 92, 132] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(152); // Index
  servo[2].write(145); // Middle
  servo[3].write(92); // Ring
  servo[4].write(132); // Pinky

  delay(22);
  // Step 373: Fingers [95, 152, 145, 92, 132] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(152); // Index
  servo[2].write(145); // Middle
  servo[3].write(92); // Ring
  servo[4].write(132); // Pinky

  // Step 374: Fingers [94, 150, 147, 92, 130] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(150); // Index
  servo[2].write(147); // Middle
  servo[3].write(92); // Ring
  servo[4].write(130); // Pinky

  // Step 375: Fingers [93, 149, 149, 93, 127] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(149); // Index
  servo[2].write(149); // Middle
  servo[3].write(93); // Ring
  servo[4].write(127); // Pinky

  delay(16);
  // Step 376: Fingers [93, 148, 148, 93, 127] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(148); // Index
  servo[2].write(148); // Middle
  servo[3].write(93); // Ring
  servo[4].write(127); // Pinky

  // Step 377: Fingers [93, 148, 148, 93, 127] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(148); // Index
  servo[2].write(148); // Middle
  servo[3].write(93); // Ring
  servo[4].write(127); // Pinky

  // Step 378: Fingers [92, 146, 150, 93, 125] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(146); // Index
  servo[2].write(150); // Middle
  servo[3].write(93); // Ring
  servo[4].write(125); // Pinky

  delay(13);
  // Step 379: Fingers [91, 142, 153, 95, 120] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(142); // Index
  servo[2].write(153); // Middle
  servo[3].write(95); // Ring
  servo[4].write(120); // Pinky

  // Step 380: Fingers [91, 142, 153, 95, 120] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(142); // Index
  servo[2].write(153); // Middle
  servo[3].write(95); // Ring
  servo[4].write(120); // Pinky

  // Step 381: Fingers [90, 141, 152, 94, 119] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(141); // Index
  servo[2].write(152); // Middle
  servo[3].write(94); // Ring
  servo[4].write(119); // Pinky

  // Step 382: Fingers [90, 139, 154, 96, 117] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(139); // Index
  servo[2].write(154); // Middle
  servo[3].write(96); // Ring
  servo[4].write(117); // Pinky

  delay(15);
  // Step 383: Fingers [90, 139, 153, 95, 117] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(139); // Index
  servo[2].write(153); // Middle
  servo[3].write(95); // Ring
  servo[4].write(117); // Pinky

  // Step 384: Fingers [90, 139, 153, 95, 117] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(139); // Index
  servo[2].write(153); // Middle
  servo[3].write(95); // Ring
  servo[4].write(117); // Pinky

  // Step 385: Fingers [90, 137, 155, 96, 115] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(137); // Index
  servo[2].write(155); // Middle
  servo[3].write(96); // Ring
  servo[4].write(115); // Pinky

  // Step 386: Fingers [90, 135, 156, 98, 113] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(135); // Index
  servo[2].write(156); // Middle
  servo[3].write(98); // Ring
  servo[4].write(113); // Pinky

  // Step 387: Fingers [89, 132, 157, 99, 110] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(132); // Index
  servo[2].write(157); // Middle
  servo[3].write(99); // Ring
  servo[4].write(110); // Pinky

  // Step 388: Fingers [89, 132, 157, 99, 110] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(132); // Index
  servo[2].write(157); // Middle
  servo[3].write(99); // Ring
  servo[4].write(110); // Pinky

  // Step 389: Fingers [89, 132, 156, 98, 110] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(132); // Index
  servo[2].write(156); // Middle
  servo[3].write(98); // Ring
  servo[4].write(110); // Pinky

  // Step 390: Fingers [89, 130, 157, 100, 108] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(130); // Index
  servo[2].write(157); // Middle
  servo[3].write(100); // Ring
  servo[4].write(108); // Pinky

  // Step 391: Fingers [89, 129, 157, 100, 107] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(129); // Index
  servo[2].write(157); // Middle
  servo[3].write(100); // Ring
  servo[4].write(107); // Pinky

  // Step 392: Fingers [89, 129, 157, 100, 107] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(129); // Index
  servo[2].write(157); // Middle
  servo[3].write(100); // Ring
  servo[4].write(107); // Pinky

  // Step 393: Fingers [89, 127, 158, 101, 105] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(127); // Index
  servo[2].write(158); // Middle
  servo[3].write(101); // Ring
  servo[4].write(105); // Pinky

  // Step 394: Fingers [89, 126, 157, 101, 105] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(126); // Index
  servo[2].write(157); // Middle
  servo[3].write(101); // Ring
  servo[4].write(105); // Pinky

  delay(17);
  // Step 395: Fingers [90, 124, 158, 103, 103] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(124); // Index
  servo[2].write(158); // Middle
  servo[3].write(103); // Ring
  servo[4].write(103); // Pinky

  // Step 396: Fingers [90, 124, 158, 103, 103] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(124); // Index
  servo[2].write(158); // Middle
  servo[3].write(103); // Ring
  servo[4].write(103); // Pinky

  // Step 397: Fingers [89, 124, 158, 102, 103] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(124); // Index
  servo[2].write(158); // Middle
  servo[3].write(102); // Ring
  servo[4].write(103); // Pinky

  // Step 398: Fingers [89, 121, 158, 104, 100] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(121); // Index
  servo[2].write(158); // Middle
  servo[3].write(104); // Ring
  servo[4].write(100); // Pinky

  delay(21);
  // Step 399: Fingers [89, 121, 158, 104, 100] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(121); // Index
  servo[2].write(158); // Middle
  servo[3].write(104); // Ring
  servo[4].write(100); // Pinky

  // Step 400: Fingers [89, 121, 157, 103, 100] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(121); // Index
  servo[2].write(157); // Middle
  servo[3].write(103); // Ring
  servo[4].write(100); // Pinky

  // Step 401: Fingers [90, 119, 158, 105, 98] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(119); // Index
  servo[2].write(158); // Middle
  servo[3].write(105); // Ring
  servo[4].write(98); // Pinky

  delay(16);
  // Step 402: Fingers [90, 118, 158, 105, 98] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(118); // Index
  servo[2].write(158); // Middle
  servo[3].write(105); // Ring
  servo[4].write(98); // Pinky

  // Step 403: Fingers [90, 118, 158, 105, 98] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(118); // Index
  servo[2].write(158); // Middle
  servo[3].write(105); // Ring
  servo[4].write(98); // Pinky

  delay(28);
  // Step 404: Fingers [90, 118, 158, 105, 98] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(118); // Index
  servo[2].write(158); // Middle
  servo[3].write(105); // Ring
  servo[4].write(98); // Pinky

  // Step 405: Fingers [89, 118, 157, 104, 97] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(118); // Index
  servo[2].write(157); // Middle
  servo[3].write(104); // Ring
  servo[4].write(97); // Pinky

  // Step 406: Fingers [90, 115, 157, 106, 96] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(115); // Index
  servo[2].write(157); // Middle
  servo[3].write(106); // Ring
  servo[4].write(96); // Pinky

  // Step 407: Fingers [90, 115, 157, 106, 95] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(115); // Index
  servo[2].write(157); // Middle
  servo[3].write(106); // Ring
  servo[4].write(95); // Pinky

  // Step 408: Fingers [90, 115, 157, 106, 95] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(115); // Index
  servo[2].write(157); // Middle
  servo[3].write(106); // Ring
  servo[4].write(95); // Pinky

  // Step 409: Fingers [89, 115, 157, 105, 95] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(115); // Index
  servo[2].write(157); // Middle
  servo[3].write(105); // Ring
  servo[4].write(95); // Pinky

  // Step 410: Fingers [89, 114, 156, 105, 95] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(114); // Index
  servo[2].write(156); // Middle
  servo[3].write(105); // Ring
  servo[4].write(95); // Pinky

  delay(14);
  // Step 411: Fingers [89, 114, 156, 105, 95] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(114); // Index
  servo[2].write(156); // Middle
  servo[3].write(105); // Ring
  servo[4].write(95); // Pinky

  // Step 412: Fingers [90, 112, 156, 107, 93] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(112); // Index
  servo[2].write(156); // Middle
  servo[3].write(107); // Ring
  servo[4].write(93); // Pinky

  // Step 413: Fingers [89, 112, 156, 106, 93] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(112); // Index
  servo[2].write(156); // Middle
  servo[3].write(106); // Ring
  servo[4].write(93); // Pinky

  delay(16);
  // Step 414: Fingers [90, 109, 156, 108, 91] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(109); // Index
  servo[2].write(156); // Middle
  servo[3].write(108); // Ring
  servo[4].write(91); // Pinky

  // Step 415: Fingers [90, 109, 156, 108, 91] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(109); // Index
  servo[2].write(156); // Middle
  servo[3].write(108); // Ring
  servo[4].write(91); // Pinky

  // Step 416: Fingers [90, 109, 155, 108, 90] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(109); // Index
  servo[2].write(155); // Middle
  servo[3].write(108); // Ring
  servo[4].write(90); // Pinky

  delay(15);
  // Step 417: Fingers [89, 108, 155, 107, 90] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(108); // Index
  servo[2].write(155); // Middle
  servo[3].write(107); // Ring
  servo[4].write(90); // Pinky

  // Step 418: Fingers [89, 108, 155, 107, 90] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(108); // Index
  servo[2].write(155); // Middle
  servo[3].write(107); // Ring
  servo[4].write(90); // Pinky

  // Step 419: Fingers [91, 106, 155, 109, 89] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(106); // Index
  servo[2].write(155); // Middle
  servo[3].write(109); // Ring
  servo[4].write(89); // Pinky

  // Step 420: Fingers [90, 106, 154, 109, 88] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(106); // Index
  servo[2].write(154); // Middle
  servo[3].write(109); // Ring
  servo[4].write(88); // Pinky

  delay(19);
  // Step 421: Fingers [90, 106, 154, 109, 88] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(106); // Index
  servo[2].write(154); // Middle
  servo[3].write(109); // Ring
  servo[4].write(88); // Pinky

  // Step 422: Fingers [90, 105, 154, 108, 87] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(105); // Index
  servo[2].write(154); // Middle
  servo[3].write(108); // Ring
  servo[4].write(87); // Pinky

  delay(11);
  // Step 423: Fingers [91, 102, 153, 110, 86] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(102); // Index
  servo[2].write(153); // Middle
  servo[3].write(110); // Ring
  servo[4].write(86); // Pinky

  // Step 424: Fingers [91, 102, 153, 110, 86] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(102); // Index
  servo[2].write(153); // Middle
  servo[3].write(110); // Ring
  servo[4].write(86); // Pinky

  // Step 425: Fingers [90, 102, 152, 109, 85] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(102); // Index
  servo[2].write(152); // Middle
  servo[3].write(109); // Ring
  servo[4].write(85); // Pinky

  // Step 426: Fingers [90, 101, 152, 109, 85] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(101); // Index
  servo[2].write(152); // Middle
  servo[3].write(109); // Ring
  servo[4].write(85); // Pinky

  // Step 427: Fingers [89, 101, 152, 109, 85] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(101); // Index
  servo[2].write(152); // Middle
  servo[3].write(109); // Ring
  servo[4].write(85); // Pinky

  // Step 428: Fingers [89, 101, 152, 109, 85] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(101); // Index
  servo[2].write(152); // Middle
  servo[3].write(109); // Ring
  servo[4].write(85); // Pinky

  delay(11);
  // Step 429: Fingers [90, 99, 151, 110, 83] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(99); // Index
  servo[2].write(151); // Middle
  servo[3].write(110); // Ring
  servo[4].write(83); // Pinky

  delay(21);
  // Step 430: Fingers [90, 99, 151, 110, 83] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(99); // Index
  servo[2].write(151); // Middle
  servo[3].write(110); // Ring
  servo[4].write(83); // Pinky

  // Step 431: Fingers [90, 98, 150, 110, 82] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(98); // Index
  servo[2].write(150); // Middle
  servo[3].write(110); // Ring
  servo[4].write(82); // Pinky

  delay(16);
  // Step 432: Fingers [89, 97, 150, 109, 82] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(97); // Index
  servo[2].write(150); // Middle
  servo[3].write(109); // Ring
  servo[4].write(82); // Pinky

  // Step 433: Fingers [89, 97, 150, 109, 82] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(97); // Index
  servo[2].write(150); // Middle
  servo[3].write(109); // Ring
  servo[4].write(82); // Pinky

  delay(14);
  // Step 434: Fingers [89, 97, 149, 109, 81] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(97); // Index
  servo[2].write(149); // Middle
  servo[3].write(109); // Ring
  servo[4].write(81); // Pinky

  // Step 435: Fingers [88, 96, 149, 108, 81] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(149); // Middle
  servo[3].write(108); // Ring
  servo[4].write(81); // Pinky

  // Step 436: Fingers [88, 96, 149, 108, 81] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(149); // Middle
  servo[3].write(108); // Ring
  servo[4].write(81); // Pinky

  // Step 437: Fingers [88, 96, 148, 108, 81] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(96); // Index
  servo[2].write(148); // Middle
  servo[3].write(108); // Ring
  servo[4].write(81); // Pinky

  delay(15);
  // Step 438: Fingers [87, 96, 148, 107, 80] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(96); // Index
  servo[2].write(148); // Middle
  servo[3].write(107); // Ring
  servo[4].write(80); // Pinky

  // Step 439: Fingers [87, 96, 148, 107, 80] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(96); // Index
  servo[2].write(148); // Middle
  servo[3].write(107); // Ring
  servo[4].write(80); // Pinky

  delay(12);
  // Step 440: Fingers [89, 93, 147, 109, 79] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(93); // Index
  servo[2].write(147); // Middle
  servo[3].write(109); // Ring
  servo[4].write(79); // Pinky

  // Step 441: Fingers [88, 93, 147, 109, 78] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(93); // Index
  servo[2].write(147); // Middle
  servo[3].write(109); // Ring
  servo[4].write(78); // Pinky

  // Step 442: Fingers [88, 92, 146, 108, 78] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(92); // Index
  servo[2].write(146); // Middle
  servo[3].write(108); // Ring
  servo[4].write(78); // Pinky

  // Step 443: Fingers [88, 92, 146, 108, 78] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(92); // Index
  servo[2].write(146); // Middle
  servo[3].write(108); // Ring
  servo[4].write(78); // Pinky

  // Step 444: Fingers [87, 92, 146, 108, 78] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(92); // Index
  servo[2].write(146); // Middle
  servo[3].write(108); // Ring
  servo[4].write(78); // Pinky

  delay(15);
  // Step 445: Fingers [86, 91, 145, 107, 77] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(91); // Index
  servo[2].write(145); // Middle
  servo[3].write(107); // Ring
  servo[4].write(77); // Pinky

  // Step 446: Fingers [86, 91, 145, 107, 77] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(91); // Index
  servo[2].write(145); // Middle
  servo[3].write(107); // Ring
  servo[4].write(77); // Pinky

  // Step 447: Fingers [86, 91, 144, 107, 76] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(91); // Index
  servo[2].write(144); // Middle
  servo[3].write(107); // Ring
  servo[4].write(76); // Pinky

  delay(16);
  // Step 448: Fingers [86, 90, 144, 106, 76] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(90); // Index
  servo[2].write(144); // Middle
  servo[3].write(106); // Ring
  servo[4].write(76); // Pinky

  // Step 449: Fingers [86, 90, 144, 106, 76] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(90); // Index
  servo[2].write(144); // Middle
  servo[3].write(106); // Ring
  servo[4].write(76); // Pinky

  delay(11);
  // Step 450: Fingers [85, 89, 143, 105, 75] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(89); // Index
  servo[2].write(143); // Middle
  servo[3].write(105); // Ring
  servo[4].write(75); // Pinky

  delay(14);
  // Step 451: Fingers [84, 89, 143, 105, 75] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(89); // Index
  servo[2].write(143); // Middle
  servo[3].write(105); // Ring
  servo[4].write(75); // Pinky

  // Step 452: Fingers [84, 89, 143, 105, 75] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(89); // Index
  servo[2].write(143); // Middle
  servo[3].write(105); // Ring
  servo[4].write(75); // Pinky

  // Step 453: Fingers [84, 89, 142, 104, 74] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(89); // Index
  servo[2].write(142); // Middle
  servo[3].write(104); // Ring
  servo[4].write(74); // Pinky

  // Step 454: Fingers [84, 88, 142, 104, 74] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(88); // Index
  servo[2].write(142); // Middle
  servo[3].write(104); // Ring
  servo[4].write(74); // Pinky

  delay(12);
  // Step 455: Fingers [84, 88, 142, 104, 74] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(88); // Index
  servo[2].write(142); // Middle
  servo[3].write(104); // Ring
  servo[4].write(74); // Pinky

  // Step 456: Fingers [81, 89, 142, 101, 74] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(89); // Index
  servo[2].write(142); // Middle
  servo[3].write(101); // Ring
  servo[4].write(74); // Pinky

  // Step 457: Fingers [81, 89, 141, 101, 73] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(89); // Index
  servo[2].write(141); // Middle
  servo[3].write(101); // Ring
  servo[4].write(73); // Pinky

  // Step 458: Fingers [80, 88, 141, 100, 73] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(88); // Index
  servo[2].write(141); // Middle
  servo[3].write(100); // Ring
  servo[4].write(73); // Pinky

  // Step 459: Fingers [80, 88, 141, 100, 73] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(88); // Index
  servo[2].write(141); // Middle
  servo[3].write(100); // Ring
  servo[4].write(73); // Pinky

  delay(15);
  // Step 460: Fingers [80, 88, 140, 100, 72] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(88); // Index
  servo[2].write(140); // Middle
  servo[3].write(100); // Ring
  servo[4].write(72); // Pinky

  // Step 461: Fingers [79, 88, 140, 99, 72] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(88); // Index
  servo[2].write(140); // Middle
  servo[3].write(99); // Ring
  servo[4].write(72); // Pinky

  // Step 462: Fingers [79, 88, 140, 99, 72] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(88); // Index
  servo[2].write(140); // Middle
  servo[3].write(99); // Ring
  servo[4].write(72); // Pinky

  // Step 463: Fingers [78, 90, 140, 97, 73] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(90); // Index
  servo[2].write(140); // Middle
  servo[3].write(97); // Ring
  servo[4].write(73); // Pinky

  // Step 464: Fingers [77, 89, 140, 97, 73] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(89); // Index
  servo[2].write(140); // Middle
  servo[3].write(97); // Ring
  servo[4].write(73); // Pinky

  // Step 465: Fingers [77, 89, 139, 96, 72] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(89); // Index
  servo[2].write(139); // Middle
  servo[3].write(96); // Ring
  servo[4].write(72); // Pinky

  // Step 466: Fingers [76, 88, 139, 96, 72] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(88); // Index
  servo[2].write(139); // Middle
  servo[3].write(96); // Ring
  servo[4].write(72); // Pinky

  // Step 467: Fingers [76, 88, 139, 96, 72] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(88); // Index
  servo[2].write(139); // Middle
  servo[3].write(96); // Ring
  servo[4].write(72); // Pinky

  // Step 468: Fingers [76, 88, 138, 95, 71] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(88); // Index
  servo[2].write(138); // Middle
  servo[3].write(95); // Ring
  servo[4].write(71); // Pinky

  // Step 469: Fingers [76, 87, 138, 95, 71] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(87); // Index
  servo[2].write(138); // Middle
  servo[3].write(95); // Ring
  servo[4].write(71); // Pinky

  delay(15);
  // Step 470: Fingers [76, 87, 138, 95, 71] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(87); // Index
  servo[2].write(138); // Middle
  servo[3].write(95); // Ring
  servo[4].write(71); // Pinky

  // Step 471: Fingers [75, 87, 138, 95, 71] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(87); // Index
  servo[2].write(138); // Middle
  servo[3].write(95); // Ring
  servo[4].write(71); // Pinky

  // Step 472: Fingers [73, 89, 137, 92, 71] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(89); // Index
  servo[2].write(137); // Middle
  servo[3].write(92); // Ring
  servo[4].write(71); // Pinky

  delay(16);
  // Step 473: Fingers [73, 88, 137, 92, 71] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(88); // Index
  servo[2].write(137); // Middle
  servo[3].write(92); // Ring
  servo[4].write(71); // Pinky

  delay(12);
  // Step 474: Fingers [73, 88, 137, 92, 71] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(88); // Index
  servo[2].write(137); // Middle
  servo[3].write(92); // Ring
  servo[4].write(71); // Pinky

  // Step 475: Fingers [72, 88, 137, 91, 70] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(88); // Index
  servo[2].write(137); // Middle
  servo[3].write(91); // Ring
  servo[4].write(70); // Pinky

  // Step 476: Fingers [72, 87, 136, 90, 70] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(87); // Index
  servo[2].write(136); // Middle
  servo[3].write(90); // Ring
  servo[4].write(70); // Pinky

  // Step 477: Fingers [71, 87, 135, 90, 69] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(87); // Index
  servo[2].write(135); // Middle
  servo[3].write(90); // Ring
  servo[4].write(69); // Pinky

  // Step 478: Fingers [71, 87, 135, 90, 69] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(87); // Index
  servo[2].write(135); // Middle
  servo[3].write(90); // Ring
  servo[4].write(69); // Pinky

  // Step 479: Fingers [71, 86, 135, 89, 69] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(86); // Index
  servo[2].write(135); // Middle
  servo[3].write(89); // Ring
  servo[4].write(69); // Pinky

  // Step 480: Fingers [69, 88, 134, 87, 70] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(88); // Index
  servo[2].write(134); // Middle
  servo[3].write(87); // Ring
  servo[4].write(70); // Pinky

  // Step 481: Fingers [69, 87, 134, 86, 69] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(87); // Index
  servo[2].write(134); // Middle
  servo[3].write(86); // Ring
  servo[4].write(69); // Pinky

  // Step 482: Fingers [68, 87, 134, 86, 69] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(87); // Index
  servo[2].write(134); // Middle
  servo[3].write(86); // Ring
  servo[4].write(69); // Pinky

  // Step 483: Fingers [68, 87, 134, 86, 69] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(87); // Index
  servo[2].write(134); // Middle
  servo[3].write(86); // Ring
  servo[4].write(69); // Pinky

  // Step 484: Fingers [66, 88, 133, 83, 69] Arm [-, -, -]
  servo[0].write(66); // Thumb
  servo[1].write(88); // Index
  servo[2].write(133); // Middle
  servo[3].write(83); // Ring
  servo[4].write(69); // Pinky

  // Step 485: Fingers [65, 87, 132, 82, 68] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(87); // Index
  servo[2].write(132); // Middle
  servo[3].write(82); // Ring
  servo[4].write(68); // Pinky

  // Step 486: Fingers [65, 87, 131, 82, 68] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(87); // Index
  servo[2].write(131); // Middle
  servo[3].write(82); // Ring
  servo[4].write(68); // Pinky

  // Step 487: Fingers [65, 87, 131, 82, 68] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(87); // Index
  servo[2].write(131); // Middle
  servo[3].write(82); // Ring
  servo[4].write(68); // Pinky

  // Step 488: Fingers [64, 87, 131, 81, 68] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(87); // Index
  servo[2].write(131); // Middle
  servo[3].write(81); // Ring
  servo[4].write(68); // Pinky

  // Step 489: Fingers [64, 86, 131, 81, 67] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(86); // Index
  servo[2].write(131); // Middle
  servo[3].write(81); // Ring
  servo[4].write(67); // Pinky

  // Step 490: Fingers [62, 87, 129, 78, 68] Arm [-, -, -]
  servo[0].write(62); // Thumb
  servo[1].write(87); // Index
  servo[2].write(129); // Middle
  servo[3].write(78); // Ring
  servo[4].write(68); // Pinky

  // Step 491: Fingers [62, 87, 129, 78, 68] Arm [-, -, -]
  servo[0].write(62); // Thumb
  servo[1].write(87); // Index
  servo[2].write(129); // Middle
  servo[3].write(78); // Ring
  servo[4].write(68); // Pinky

  // Step 492: Fingers [62, 87, 129, 78, 67] Arm [-, -, -]
  servo[0].write(62); // Thumb
  servo[1].write(87); // Index
  servo[2].write(129); // Middle
  servo[3].write(78); // Ring
  servo[4].write(67); // Pinky

  // Step 493: Fingers [60, 88, 128, 75, 68] Arm [-, -, -]
  servo[0].write(60); // Thumb
  servo[1].write(88); // Index
  servo[2].write(128); // Middle
  servo[3].write(75); // Ring
  servo[4].write(68); // Pinky

  // Step 494: Fingers [59, 88, 127, 74, 68] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(88); // Index
  servo[2].write(127); // Middle
  servo[3].write(74); // Ring
  servo[4].write(68); // Pinky

  // Step 495: Fingers [59, 88, 127, 74, 68] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(88); // Index
  servo[2].write(127); // Middle
  servo[3].write(74); // Ring
  servo[4].write(68); // Pinky

  // Step 496: Fingers [58, 90, 126, 72, 69] Arm [-, -, -]
  servo[0].write(58); // Thumb
  servo[1].write(90); // Index
  servo[2].write(126); // Middle
  servo[3].write(72); // Ring
  servo[4].write(69); // Pinky

  // Step 497: Fingers [57, 89, 126, 71, 68] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(89); // Index
  servo[2].write(126); // Middle
  servo[3].write(71); // Ring
  servo[4].write(68); // Pinky

  delay(17);
  // Step 498: Fingers [57, 88, 125, 71, 68] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(88); // Index
  servo[2].write(125); // Middle
  servo[3].write(71); // Ring
  servo[4].write(68); // Pinky

  // Step 499: Fingers [57, 88, 125, 71, 68] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(88); // Index
  servo[2].write(125); // Middle
  servo[3].write(71); // Ring
  servo[4].write(68); // Pinky

  // Step 500: Fingers [56, 88, 125, 70, 67] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(88); // Index
  servo[2].write(125); // Middle
  servo[3].write(70); // Ring
  servo[4].write(67); // Pinky

  // Step 501: Fingers [55, 90, 124, 68, 69] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(90); // Index
  servo[2].write(124); // Middle
  servo[3].write(68); // Ring
  servo[4].write(69); // Pinky

  // Step 502: Fingers [55, 89, 123, 68, 68] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(89); // Index
  servo[2].write(123); // Middle
  servo[3].write(68); // Ring
  servo[4].write(68); // Pinky

  // Step 503: Fingers [55, 89, 123, 68, 68] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(89); // Index
  servo[2].write(123); // Middle
  servo[3].write(68); // Ring
  servo[4].write(68); // Pinky

  // Step 504: Fingers [54, 89, 123, 67, 68] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(89); // Index
  servo[2].write(123); // Middle
  servo[3].write(67); // Ring
  servo[4].write(68); // Pinky

  // Step 505: Fingers [53, 91, 122, 65, 69] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(91); // Index
  servo[2].write(122); // Middle
  servo[3].write(65); // Ring
  servo[4].write(69); // Pinky

  // Step 506: Fingers [52, 90, 121, 64, 68] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(90); // Index
  servo[2].write(121); // Middle
  servo[3].write(64); // Ring
  servo[4].write(68); // Pinky

  delay(14);
  // Step 507: Fingers [52, 90, 121, 64, 68] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(90); // Index
  servo[2].write(121); // Middle
  servo[3].write(64); // Ring
  servo[4].write(68); // Pinky

  // Step 508: Fingers [52, 89, 120, 63, 67] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(89); // Index
  servo[2].write(120); // Middle
  servo[3].write(63); // Ring
  servo[4].write(67); // Pinky

  // Step 509: Fingers [51, 89, 119, 63, 67] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(89); // Index
  servo[2].write(119); // Middle
  servo[3].write(63); // Ring
  servo[4].write(67); // Pinky

  // Step 510: Fingers [51, 88, 119, 63, 67] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(88); // Index
  servo[2].write(119); // Middle
  servo[3].write(63); // Ring
  servo[4].write(67); // Pinky

  // Step 511: Fingers [50, 88, 119, 62, 66] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(88); // Index
  servo[2].write(119); // Middle
  servo[3].write(62); // Ring
  servo[4].write(66); // Pinky

  // Step 512: Fingers [50, 88, 119, 62, 66] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(88); // Index
  servo[2].write(119); // Middle
  servo[3].write(62); // Ring
  servo[4].write(66); // Pinky

  // Step 513: Fingers [49, 89, 117, 60, 67] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(89); // Index
  servo[2].write(117); // Middle
  servo[3].write(60); // Ring
  servo[4].write(67); // Pinky

  // Step 514: Fingers [49, 89, 116, 59, 67] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(89); // Index
  servo[2].write(116); // Middle
  servo[3].write(59); // Ring
  servo[4].write(67); // Pinky

  // Step 515: Fingers [48, 88, 116, 59, 66] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(88); // Index
  servo[2].write(116); // Middle
  servo[3].write(59); // Ring
  servo[4].write(66); // Pinky

  // Step 516: Fingers [47, 90, 114, 56, 68] Arm [-, -, -]
  servo[0].write(47); // Thumb
  servo[1].write(90); // Index
  servo[2].write(114); // Middle
  servo[3].write(56); // Ring
  servo[4].write(68); // Pinky

  // Step 517: Fingers [47, 90, 114, 56, 68] Arm [-, -, -]
  servo[0].write(47); // Thumb
  servo[1].write(90); // Index
  servo[2].write(114); // Middle
  servo[3].write(56); // Ring
  servo[4].write(68); // Pinky

  // Step 518: Fingers [46, 89, 113, 55, 67] Arm [-, -, -]
  servo[0].write(46); // Thumb
  servo[1].write(89); // Index
  servo[2].write(113); // Middle
  servo[3].write(55); // Ring
  servo[4].write(67); // Pinky

  // Step 519: Fingers [46, 88, 113, 55, 66] Arm [-, -, -]
  servo[0].write(46); // Thumb
  servo[1].write(88); // Index
  servo[2].write(113); // Middle
  servo[3].write(55); // Ring
  servo[4].write(66); // Pinky

  // Step 520: Fingers [45, 88, 112, 55, 66] Arm [-, -, -]
  servo[0].write(45); // Thumb
  servo[1].write(88); // Index
  servo[2].write(112); // Middle
  servo[3].write(55); // Ring
  servo[4].write(66); // Pinky

  // Step 521: Fingers [45, 88, 112, 55, 66] Arm [-, -, -]
  servo[0].write(45); // Thumb
  servo[1].write(88); // Index
  servo[2].write(112); // Middle
  servo[3].write(55); // Ring
  servo[4].write(66); // Pinky

  // Step 522: Fingers [44, 89, 110, 52, 67] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(89); // Index
  servo[2].write(110); // Middle
  servo[3].write(52); // Ring
  servo[4].write(67); // Pinky

  // Step 523: Fingers [44, 91, 109, 51, 69] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(91); // Index
  servo[2].write(109); // Middle
  servo[3].write(51); // Ring
  servo[4].write(69); // Pinky

  // Step 524: Fingers [43, 91, 108, 50, 68] Arm [-, -, -]
  servo[0].write(43); // Thumb
  servo[1].write(91); // Index
  servo[2].write(108); // Middle
  servo[3].write(50); // Ring
  servo[4].write(68); // Pinky

  // Step 525: Fingers [43, 90, 108, 50, 68] Arm [-, -, -]
  servo[0].write(43); // Thumb
  servo[1].write(90); // Index
  servo[2].write(108); // Middle
  servo[3].write(50); // Ring
  servo[4].write(68); // Pinky

  // Step 526: Fingers [43, 90, 108, 50, 68] Arm [-, -, -]
  servo[0].write(43); // Thumb
  servo[1].write(90); // Index
  servo[2].write(108); // Middle
  servo[3].write(50); // Ring
  servo[4].write(68); // Pinky

  // Step 527: Fingers [43, 92, 106, 48, 70] Arm [-, -, -]
  servo[0].write(43); // Thumb
  servo[1].write(92); // Index
  servo[2].write(106); // Middle
  servo[3].write(48); // Ring
  servo[4].write(70); // Pinky

  // Step 528: Fingers [42, 93, 104, 46, 71] Arm [-, -, -]
  servo[0].write(42); // Thumb
  servo[1].write(93); // Index
  servo[2].write(104); // Middle
  servo[3].write(46); // Ring
  servo[4].write(71); // Pinky

  // Step 529: Fingers [41, 93, 103, 46, 71] Arm [-, -, -]
  servo[0].write(41); // Thumb
  servo[1].write(93); // Index
  servo[2].write(103); // Middle
  servo[3].write(46); // Ring
  servo[4].write(71); // Pinky

  // Step 530: Fingers [41, 93, 103, 46, 71] Arm [-, -, -]
  servo[0].write(41); // Thumb
  servo[1].write(93); // Index
  servo[2].write(103); // Middle
  servo[3].write(46); // Ring
  servo[4].write(71); // Pinky

  // Step 531: Fingers [41, 92, 103, 45, 70] Arm [-, -, -]
  servo[0].write(41); // Thumb
  servo[1].write(92); // Index
  servo[2].write(103); // Middle
  servo[3].write(45); // Ring
  servo[4].write(70); // Pinky

  // Step 532: Fingers [41, 94, 101, 44, 72] Arm [-, -, -]
  servo[0].write(41); // Thumb
  servo[1].write(94); // Index
  servo[2].write(101); // Middle
  servo[3].write(44); // Ring
  servo[4].write(72); // Pinky

  // Step 533: Fingers [41, 95, 98, 42, 73] Arm [-, -, -]
  servo[0].write(41); // Thumb
  servo[1].write(95); // Index
  servo[2].write(98); // Middle
  servo[3].write(42); // Ring
  servo[4].write(73); // Pinky

  // Step 534: Fingers [40, 94, 98, 42, 73] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(94); // Index
  servo[2].write(98); // Middle
  servo[3].write(42); // Ring
  servo[4].write(73); // Pinky

  // Step 535: Fingers [40, 94, 98, 42, 73] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(94); // Index
  servo[2].write(98); // Middle
  servo[3].write(42); // Ring
  servo[4].write(73); // Pinky

  // Step 536: Fingers [40, 96, 96, 40, 75] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(96); // Index
  servo[2].write(96); // Middle
  servo[3].write(40); // Ring
  servo[4].write(75); // Pinky

  // Step 537: Fingers [41, 97, 94, 39, 76] Arm [-, -, -]
  servo[0].write(41); // Thumb
  servo[1].write(97); // Index
  servo[2].write(94); // Middle
  servo[3].write(39); // Ring
  servo[4].write(76); // Pinky

  // Step 538: Fingers [40, 97, 93, 39, 76] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(97); // Index
  servo[2].write(93); // Middle
  servo[3].write(39); // Ring
  servo[4].write(76); // Pinky

  // Step 539: Fingers [40, 96, 93, 38, 76] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(96); // Index
  servo[2].write(93); // Middle
  servo[3].write(38); // Ring
  servo[4].write(76); // Pinky

  // Step 540: Fingers [40, 96, 93, 38, 76] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(96); // Index
  servo[2].write(93); // Middle
  servo[3].write(38); // Ring
  servo[4].write(76); // Pinky

  // Step 541: Fingers [40, 97, 90, 37, 77] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(97); // Index
  servo[2].write(90); // Middle
  servo[3].write(37); // Ring
  servo[4].write(77); // Pinky

  // Step 542: Fingers [40, 98, 87, 36, 79] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(98); // Index
  servo[2].write(87); // Middle
  servo[3].write(36); // Ring
  servo[4].write(79); // Pinky

  // Step 543: Fingers [40, 98, 87, 36, 78] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(98); // Index
  servo[2].write(87); // Middle
  servo[3].write(36); // Ring
  servo[4].write(78); // Pinky

  // Step 544: Fingers [40, 98, 87, 36, 78] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(98); // Index
  servo[2].write(87); // Middle
  servo[3].write(36); // Ring
  servo[4].write(78); // Pinky

  // Step 545: Fingers [41, 99, 85, 35, 80] Arm [-, -, -]
  servo[0].write(41); // Thumb
  servo[1].write(99); // Index
  servo[2].write(85); // Middle
  servo[3].write(35); // Ring
  servo[4].write(80); // Pinky

  // Step 546: Fingers [40, 98, 84, 35, 80] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(98); // Index
  servo[2].write(84); // Middle
  servo[3].write(35); // Ring
  servo[4].write(80); // Pinky

  delay(15);
  // Step 547: Fingers [41, 99, 82, 34, 81] Arm [-, -, -]
  servo[0].write(41); // Thumb
  servo[1].write(99); // Index
  servo[2].write(82); // Middle
  servo[3].write(34); // Ring
  servo[4].write(81); // Pinky

  // Step 548: Fingers [41, 99, 82, 34, 81] Arm [-, -, -]
  servo[0].write(41); // Thumb
  servo[1].write(99); // Index
  servo[2].write(82); // Middle
  servo[3].write(34); // Ring
  servo[4].write(81); // Pinky

  // Step 549: Fingers [42, 100, 79, 34, 83] Arm [-, -, -]
  servo[0].write(42); // Thumb
  servo[1].write(100); // Index
  servo[2].write(79); // Middle
  servo[3].write(34); // Ring
  servo[4].write(83); // Pinky

  // Step 550: Fingers [42, 100, 79, 34, 83] Arm [-, -, -]
  servo[0].write(42); // Thumb
  servo[1].write(100); // Index
  servo[2].write(79); // Middle
  servo[3].write(34); // Ring
  servo[4].write(83); // Pinky

  // Step 551: Fingers [42, 100, 76, 33, 84] Arm [-, -, -]
  servo[0].write(42); // Thumb
  servo[1].write(100); // Index
  servo[2].write(76); // Middle
  servo[3].write(33); // Ring
  servo[4].write(84); // Pinky

  delay(14);
  // Step 552: Fingers [42, 100, 76, 33, 84] Arm [-, -, -]
  servo[0].write(42); // Thumb
  servo[1].write(100); // Index
  servo[2].write(76); // Middle
  servo[3].write(33); // Ring
  servo[4].write(84); // Pinky

  // Step 553: Fingers [42, 100, 75, 32, 83] Arm [-, -, -]
  servo[0].write(42); // Thumb
  servo[1].write(100); // Index
  servo[2].write(75); // Middle
  servo[3].write(32); // Ring
  servo[4].write(83); // Pinky

  // Step 554: Fingers [45, 101, 70, 33, 87] Arm [-, -, -]
  servo[0].write(45); // Thumb
  servo[1].write(101); // Index
  servo[2].write(70); // Middle
  servo[3].write(33); // Ring
  servo[4].write(87); // Pinky

  // Step 555: Fingers [44, 101, 70, 32, 86] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(101); // Index
  servo[2].write(70); // Middle
  servo[3].write(32); // Ring
  servo[4].write(86); // Pinky

  delay(16);
  // Step 556: Fingers [44, 101, 70, 32, 86] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(101); // Index
  servo[2].write(70); // Middle
  servo[3].write(32); // Ring
  servo[4].write(86); // Pinky

  // Step 557: Fingers [44, 100, 70, 32, 86] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(100); // Index
  servo[2].write(70); // Middle
  servo[3].write(32); // Ring
  servo[4].write(86); // Pinky

  // Step 558: Fingers [46, 101, 67, 33, 88] Arm [-, -, -]
  servo[0].write(46); // Thumb
  servo[1].write(101); // Index
  servo[2].write(67); // Middle
  servo[3].write(33); // Ring
  servo[4].write(88); // Pinky

  // Step 559: Fingers [47, 101, 65, 33, 89] Arm [-, -, -]
  servo[0].write(47); // Thumb
  servo[1].write(101); // Index
  servo[2].write(65); // Middle
  servo[3].write(33); // Ring
  servo[4].write(89); // Pinky

  delay(16);
  // Step 560: Fingers [47, 101, 65, 33, 89] Arm [-, -, -]
  servo[0].write(47); // Thumb
  servo[1].write(101); // Index
  servo[2].write(65); // Middle
  servo[3].write(33); // Ring
  servo[4].write(89); // Pinky

  // Step 561: Fingers [47, 101, 64, 33, 89] Arm [-, -, -]
  servo[0].write(47); // Thumb
  servo[1].write(101); // Index
  servo[2].write(64); // Middle
  servo[3].write(33); // Ring
  servo[4].write(89); // Pinky

  // Step 562: Fingers [48, 101, 62, 33, 90] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(101); // Index
  servo[2].write(62); // Middle
  servo[3].write(33); // Ring
  servo[4].write(90); // Pinky

  delay(16);
  // Step 563: Fingers [50, 101, 59, 34, 91] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(101); // Index
  servo[2].write(59); // Middle
  servo[3].write(34); // Ring
  servo[4].write(91); // Pinky

  // Step 564: Fingers [50, 101, 59, 34, 91] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(101); // Index
  servo[2].write(59); // Middle
  servo[3].write(34); // Ring
  servo[4].write(91); // Pinky

  // Step 565: Fingers [49, 101, 59, 33, 91] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(101); // Index
  servo[2].write(59); // Middle
  servo[3].write(33); // Ring
  servo[4].write(91); // Pinky

  // Step 566: Fingers [51, 100, 56, 34, 92] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(100); // Index
  servo[2].write(56); // Middle
  servo[3].write(34); // Ring
  servo[4].write(92); // Pinky

  // Step 567: Fingers [52, 100, 53, 35, 93] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(100); // Index
  servo[2].write(53); // Middle
  servo[3].write(35); // Ring
  servo[4].write(93); // Pinky

  // Step 568: Fingers [54, 100, 51, 36, 94] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(100); // Index
  servo[2].write(51); // Middle
  servo[3].write(36); // Ring
  servo[4].write(94); // Pinky

  // Step 569: Fingers [54, 100, 51, 36, 94] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(100); // Index
  servo[2].write(51); // Middle
  servo[3].write(36); // Ring
  servo[4].write(94); // Pinky

  // Step 570: Fingers [56, 99, 48, 37, 94] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(99); // Index
  servo[2].write(48); // Middle
  servo[3].write(37); // Ring
  servo[4].write(94); // Pinky

  // Step 571: Fingers [55, 98, 48, 36, 94] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(98); // Index
  servo[2].write(48); // Middle
  servo[3].write(36); // Ring
  servo[4].write(94); // Pinky

  // Step 572: Fingers [59, 97, 44, 39, 96] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(97); // Index
  servo[2].write(44); // Middle
  servo[3].write(39); // Ring
  servo[4].write(96); // Pinky

  // Step 573: Fingers [59, 97, 43, 38, 95] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(97); // Index
  servo[2].write(43); // Middle
  servo[3].write(38); // Ring
  servo[4].write(95); // Pinky

  // Step 574: Fingers [59, 97, 43, 38, 95] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(97); // Index
  servo[2].write(43); // Middle
  servo[3].write(38); // Ring
  servo[4].write(95); // Pinky

  // Step 575: Fingers [63, 95, 39, 42, 96] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(95); // Index
  servo[2].write(39); // Middle
  servo[3].write(42); // Ring
  servo[4].write(96); // Pinky

  // Step 576: Fingers [65, 94, 37, 43, 96] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(94); // Index
  servo[2].write(37); // Middle
  servo[3].write(43); // Ring
  servo[4].write(96); // Pinky

  // Step 577: Fingers [67, 92, 35, 45, 96] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(92); // Index
  servo[2].write(35); // Middle
  servo[3].write(45); // Ring
  servo[4].write(96); // Pinky

  // Step 578: Fingers [67, 92, 35, 45, 96] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(92); // Index
  servo[2].write(35); // Middle
  servo[3].write(45); // Ring
  servo[4].write(96); // Pinky

  // Step 579: Fingers [69, 91, 33, 47, 96] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(91); // Index
  servo[2].write(33); // Middle
  servo[3].write(47); // Ring
  servo[4].write(96); // Pinky

  // Step 580: Fingers [71, 90, 32, 48, 96] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(90); // Index
  servo[2].write(32); // Middle
  servo[3].write(48); // Ring
  servo[4].write(96); // Pinky

  // Step 581: Fingers [73, 88, 30, 50, 96] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(88); // Index
  servo[2].write(30); // Middle
  servo[3].write(50); // Ring
  servo[4].write(96); // Pinky

  // Step 582: Fingers [74, 87, 29, 52, 96] Arm [-, -, -]
  servo[0].write(74); // Thumb
  servo[1].write(87); // Index
  servo[2].write(29); // Middle
  servo[3].write(52); // Ring
  servo[4].write(96); // Pinky

  // Step 583: Fingers [74, 87, 29, 52, 96] Arm [-, -, -]
  servo[0].write(74); // Thumb
  servo[1].write(87); // Index
  servo[2].write(29); // Middle
  servo[3].write(52); // Ring
  servo[4].write(96); // Pinky

  // Step 584: Fingers [76, 85, 27, 54, 95] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(85); // Index
  servo[2].write(27); // Middle
  servo[3].write(54); // Ring
  servo[4].write(95); // Pinky

  // Step 585: Fingers [78, 83, 26, 56, 94] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(83); // Index
  servo[2].write(26); // Middle
  servo[3].write(56); // Ring
  servo[4].write(94); // Pinky

  // Step 586: Fingers [79, 81, 25, 58, 93] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(81); // Index
  servo[2].write(25); // Middle
  servo[3].write(58); // Ring
  servo[4].write(93); // Pinky

  // Step 587: Fingers [81, 79, 24, 60, 92] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(79); // Index
  servo[2].write(24); // Middle
  servo[3].write(60); // Ring
  servo[4].write(92); // Pinky

  // Step 588: Fingers [81, 79, 24, 60, 92] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(79); // Index
  servo[2].write(24); // Middle
  servo[3].write(60); // Ring
  servo[4].write(92); // Pinky

  // Step 589: Fingers [82, 76, 23, 62, 91] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(76); // Index
  servo[2].write(23); // Middle
  servo[3].write(62); // Ring
  servo[4].write(91); // Pinky

  delay(16);
  // Step 590: Fingers [84, 74, 22, 64, 90] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(74); // Index
  servo[2].write(22); // Middle
  servo[3].write(64); // Ring
  servo[4].write(90); // Pinky

  // Step 591: Fingers [84, 74, 22, 64, 90] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(74); // Index
  servo[2].write(22); // Middle
  servo[3].write(64); // Ring
  servo[4].write(90); // Pinky

  // Step 592: Fingers [85, 72, 22, 66, 89] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(72); // Index
  servo[2].write(22); // Middle
  servo[3].write(66); // Ring
  servo[4].write(89); // Pinky

  // Step 593: Fingers [86, 69, 21, 67, 87] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(69); // Index
  servo[2].write(21); // Middle
  servo[3].write(67); // Ring
  servo[4].write(87); // Pinky

  delay(15);
  // Step 594: Fingers [86, 69, 21, 67, 87] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(69); // Index
  servo[2].write(21); // Middle
  servo[3].write(67); // Ring
  servo[4].write(87); // Pinky

  // Step 595: Fingers [87, 67, 21, 69, 86] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(67); // Index
  servo[2].write(21); // Middle
  servo[3].write(69); // Ring
  servo[4].write(86); // Pinky

  delay(24);
  // Step 596: Fingers [87, 67, 21, 69, 86] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(67); // Index
  servo[2].write(21); // Middle
  servo[3].write(69); // Ring
  servo[4].write(86); // Pinky

  // Step 597: Fingers [88, 65, 21, 71, 84] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(65); // Index
  servo[2].write(21); // Middle
  servo[3].write(71); // Ring
  servo[4].write(84); // Pinky

  // Step 598: Fingers [89, 63, 22, 73, 83] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(63); // Index
  servo[2].write(22); // Middle
  servo[3].write(73); // Ring
  servo[4].write(83); // Pinky

  delay(13);
  // Step 599: Fingers [89, 63, 22, 73, 83] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(63); // Index
  servo[2].write(22); // Middle
  servo[3].write(73); // Ring
  servo[4].write(83); // Pinky

  delay(13);
  // Step 600: Fingers [90, 61, 22, 75, 81] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(61); // Index
  servo[2].write(22); // Middle
  servo[3].write(75); // Ring
  servo[4].write(81); // Pinky

  // Step 601: Fingers [91, 58, 23, 77, 79] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(58); // Index
  servo[2].write(23); // Middle
  servo[3].write(77); // Ring
  servo[4].write(79); // Pinky

  // Step 602: Fingers [91, 58, 22, 77, 79] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(58); // Index
  servo[2].write(22); // Middle
  servo[3].write(77); // Ring
  servo[4].write(79); // Pinky

  // Step 603: Fingers [91, 58, 22, 77, 79] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(58); // Index
  servo[2].write(22); // Middle
  servo[3].write(77); // Ring
  servo[4].write(79); // Pinky

  // Step 604: Fingers [92, 54, 24, 80, 75] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(54); // Index
  servo[2].write(24); // Middle
  servo[3].write(80); // Ring
  servo[4].write(75); // Pinky

  // Step 605: Fingers [93, 49, 26, 84, 71] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(49); // Index
  servo[2].write(26); // Middle
  servo[3].write(84); // Ring
  servo[4].write(71); // Pinky

  // Step 606: Fingers [93, 47, 27, 85, 69] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(47); // Index
  servo[2].write(27); // Middle
  servo[3].write(85); // Ring
  servo[4].write(69); // Pinky

  // Step 607: Fingers [93, 47, 27, 85, 69] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(47); // Index
  servo[2].write(27); // Middle
  servo[3].write(85); // Ring
  servo[4].write(69); // Pinky

  // Step 608: Fingers [92, 41, 31, 89, 63] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(41); // Index
  servo[2].write(31); // Middle
  servo[3].write(89); // Ring
  servo[4].write(63); // Pinky

  // Step 609: Fingers [92, 39, 33, 90, 61] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(39); // Index
  servo[2].write(33); // Middle
  servo[3].write(90); // Ring
  servo[4].write(61); // Pinky

  // Step 610: Fingers [90, 33, 38, 91, 53] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(33); // Index
  servo[2].write(38); // Middle
  servo[3].write(91); // Ring
  servo[4].write(53); // Pinky

  // Step 611: Fingers [86, 28, 44, 92, 47] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(28); // Index
  servo[2].write(44); // Middle
  servo[3].write(92); // Ring
  servo[4].write(47); // Pinky

  // Step 612: Fingers [86, 28, 44, 92, 47] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(28); // Index
  servo[2].write(44); // Middle
  servo[3].write(92); // Ring
  servo[4].write(47); // Pinky

  // Step 613: Fingers [83, 25, 47, 92, 42] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(25); // Index
  servo[2].write(47); // Middle
  servo[3].write(92); // Ring
  servo[4].write(42); // Pinky

  // Step 614: Fingers [80, 23, 52, 91, 38] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(23); // Index
  servo[2].write(52); // Middle
  servo[3].write(91); // Ring
  servo[4].write(38); // Pinky

  // Step 615: Fingers [76, 21, 56, 90, 34] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(21); // Index
  servo[2].write(56); // Middle
  servo[3].write(90); // Ring
  servo[4].write(34); // Pinky

  // Step 616: Fingers [73, 20, 60, 88, 31] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(20); // Index
  servo[2].write(60); // Middle
  servo[3].write(88); // Ring
  servo[4].write(31); // Pinky

  // Step 617: Fingers [73, 20, 60, 88, 31] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(20); // Index
  servo[2].write(60); // Middle
  servo[3].write(88); // Ring
  servo[4].write(31); // Pinky

  // Step 618: Fingers [71, 20, 62, 87, 29] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(20); // Index
  servo[2].write(62); // Middle
  servo[3].write(87); // Ring
  servo[4].write(29); // Pinky

  // Step 619: Fingers [69, 20, 65, 86, 28] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(20); // Index
  servo[2].write(65); // Middle
  servo[3].write(86); // Ring
  servo[4].write(28); // Pinky

  // Step 620: Fingers [66, 19, 67, 85, 26] Arm [-, -, -]
  servo[0].write(66); // Thumb
  servo[1].write(19); // Index
  servo[2].write(67); // Middle
  servo[3].write(85); // Ring
  servo[4].write(26); // Pinky

  // Step 621: Fingers [64, 20, 69, 83, 25] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(20); // Index
  servo[2].write(69); // Middle
  servo[3].write(83); // Ring
  servo[4].write(25); // Pinky

  // Step 622: Fingers [64, 20, 69, 83, 25] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(20); // Index
  servo[2].write(69); // Middle
  servo[3].write(83); // Ring
  servo[4].write(25); // Pinky

  // Step 623: Fingers [64, 19, 68, 83, 25] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(19); // Index
  servo[2].write(68); // Middle
  servo[3].write(83); // Ring
  servo[4].write(25); // Pinky

  // Step 624: Fingers [62, 19, 70, 81, 23] Arm [-, -, -]
  servo[0].write(62); // Thumb
  servo[1].write(19); // Index
  servo[2].write(70); // Middle
  servo[3].write(81); // Ring
  servo[4].write(23); // Pinky

  // Step 625: Fingers [60, 20, 72, 80, 22] Arm [-, -, -]
  servo[0].write(60); // Thumb
  servo[1].write(20); // Index
  servo[2].write(72); // Middle
  servo[3].write(80); // Ring
  servo[4].write(22); // Pinky

  // Step 626: Fingers [55, 21, 76, 76, 21] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(21); // Index
  servo[2].write(76); // Middle
  servo[3].write(76); // Ring
  servo[4].write(21); // Pinky

  // Step 627: Fingers [55, 21, 76, 76, 21] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(21); // Index
  servo[2].write(76); // Middle
  servo[3].write(76); // Ring
  servo[4].write(21); // Pinky

  // Step 628: Fingers [51, 22, 80, 72, 20] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(22); // Index
  servo[2].write(80); // Middle
  servo[3].write(72); // Ring
  servo[4].write(20); // Pinky

  // Step 629: Fingers [48, 23, 81, 70, 19] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(23); // Index
  servo[2].write(81); // Middle
  servo[3].write(70); // Ring
  servo[4].write(19); // Pinky

  // Step 630: Fingers [44, 26, 84, 66, 19] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(26); // Index
  servo[2].write(84); // Middle
  servo[3].write(66); // Ring
  servo[4].write(19); // Pinky

  // Step 631: Fingers [44, 26, 84, 66, 19] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(26); // Index
  servo[2].write(84); // Middle
  servo[3].write(66); // Ring
  servo[4].write(19); // Pinky

  // Step 632: Fingers [42, 27, 85, 64, 19] Arm [-, -, -]
  servo[0].write(42); // Thumb
  servo[1].write(27); // Index
  servo[2].write(85); // Middle
  servo[3].write(64); // Ring
  servo[4].write(19); // Pinky

  // Step 633: Fingers [40, 28, 86, 62, 19] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(28); // Index
  servo[2].write(86); // Middle
  servo[3].write(62); // Ring
  servo[4].write(19); // Pinky

  // Step 634: Fingers [38, 30, 87, 59, 19] Arm [-, -, -]
  servo[0].write(38); // Thumb
  servo[1].write(30); // Index
  servo[2].write(87); // Middle
  servo[3].write(59); // Ring
  servo[4].write(19); // Pinky

  delay(13);
  // Step 635: Fingers [38, 30, 87, 59, 19] Arm [-, -, -]
  servo[0].write(38); // Thumb
  servo[1].write(30); // Index
  servo[2].write(87); // Middle
  servo[3].write(59); // Ring
  servo[4].write(19); // Pinky

  // Step 636: Fingers [36, 31, 88, 57, 20] Arm [-, -, -]
  servo[0].write(36); // Thumb
  servo[1].write(31); // Index
  servo[2].write(88); // Middle
  servo[3].write(57); // Ring
  servo[4].write(20); // Pinky

  // Step 637: Fingers [34, 33, 89, 55, 20] Arm [-, -, -]
  servo[0].write(34); // Thumb
  servo[1].write(33); // Index
  servo[2].write(89); // Middle
  servo[3].write(55); // Ring
  servo[4].write(20); // Pinky

  delay(15);
  // Step 638: Fingers [32, 35, 89, 53, 21] Arm [-, -, -]
  servo[0].write(32); // Thumb
  servo[1].write(35); // Index
  servo[2].write(89); // Middle
  servo[3].write(53); // Ring
  servo[4].write(21); // Pinky

  // Step 639: Fingers [32, 35, 89, 53, 21] Arm [-, -, -]
  servo[0].write(32); // Thumb
  servo[1].write(35); // Index
  servo[2].write(89); // Middle
  servo[3].write(53); // Ring
  servo[4].write(21); // Pinky

  delay(19);
  // Step 640: Fingers [30, 37, 90, 51, 22] Arm [-, -, -]
  servo[0].write(30); // Thumb
  servo[1].write(37); // Index
  servo[2].write(90); // Middle
  servo[3].write(51); // Ring
  servo[4].write(22); // Pinky

  delay(11);
  // Step 641: Fingers [30, 37, 90, 51, 22] Arm [-, -, -]
  servo[0].write(30); // Thumb
  servo[1].write(37); // Index
  servo[2].write(90); // Middle
  servo[3].write(51); // Ring
  servo[4].write(22); // Pinky

  delay(11);
  // Step 642: Fingers [27, 41, 91, 46, 24] Arm [-, -, -]
  servo[0].write(27); // Thumb
  servo[1].write(41); // Index
  servo[2].write(91); // Middle
  servo[3].write(46); // Ring
  servo[4].write(24); // Pinky

  // Step 643: Fingers [26, 43, 91, 44, 25] Arm [-, -, -]
  servo[0].write(26); // Thumb
  servo[1].write(43); // Index
  servo[2].write(91); // Middle
  servo[3].write(44); // Ring
  servo[4].write(25); // Pinky

  // Step 644: Fingers [26, 43, 91, 44, 25] Arm [-, -, -]
  servo[0].write(26); // Thumb
  servo[1].write(43); // Index
  servo[2].write(91); // Middle
  servo[3].write(44); // Ring
  servo[4].write(25); // Pinky

  // Step 645: Fingers [26, 43, 91, 44, 26] Arm [-, -, -]
  servo[0].write(26); // Thumb
  servo[1].write(43); // Index
  servo[2].write(91); // Middle
  servo[3].write(44); // Ring
  servo[4].write(26); // Pinky

  // Step 646: Fingers [24, 48, 91, 40, 28] Arm [-, -, -]
  servo[0].write(24); // Thumb
  servo[1].write(48); // Index
  servo[2].write(91); // Middle
  servo[3].write(40); // Ring
  servo[4].write(28); // Pinky

  // Step 647: Fingers [23, 50, 91, 38, 30] Arm [-, -, -]
  servo[0].write(23); // Thumb
  servo[1].write(50); // Index
  servo[2].write(91); // Middle
  servo[3].write(38); // Ring
  servo[4].write(30); // Pinky

  delay(15);
  // Step 648: Fingers [23, 50, 91, 38, 30] Arm [-, -, -]
  servo[0].write(23); // Thumb
  servo[1].write(50); // Index
  servo[2].write(91); // Middle
  servo[3].write(38); // Ring
  servo[4].write(30); // Pinky

  // Step 649: Fingers [22, 52, 90, 36, 32] Arm [-, -, -]
  servo[0].write(22); // Thumb
  servo[1].write(52); // Index
  servo[2].write(90); // Middle
  servo[3].write(36); // Ring
  servo[4].write(32); // Pinky

  // Step 650: Fingers [21, 54, 89, 34, 33] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(54); // Index
  servo[2].write(89); // Middle
  servo[3].write(34); // Ring
  servo[4].write(33); // Pinky

  // Step 651: Fingers [21, 55, 90, 35, 34] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(55); // Index
  servo[2].write(90); // Middle
  servo[3].write(35); // Ring
  servo[4].write(34); // Pinky

  delay(13);
  // Step 652: Fingers [21, 55, 90, 35, 34] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(55); // Index
  servo[2].write(90); // Middle
  servo[3].write(35); // Ring
  servo[4].write(34); // Pinky

  delay(24);
  // Step 653: Fingers [21, 57, 89, 33, 36] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(57); // Index
  servo[2].write(89); // Middle
  servo[3].write(33); // Ring
  servo[4].write(36); // Pinky

  // Step 654: Fingers [21, 57, 89, 33, 36] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(57); // Index
  servo[2].write(89); // Middle
  servo[3].write(33); // Ring
  servo[4].write(36); // Pinky

  delay(31);
  // Step 655: Fingers [21, 57, 89, 33, 36] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(57); // Index
  servo[2].write(89); // Middle
  servo[3].write(33); // Ring
  servo[4].write(36); // Pinky

  // Step 656: Fingers [21, 60, 89, 32, 38] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(60); // Index
  servo[2].write(89); // Middle
  servo[3].write(32); // Ring
  servo[4].write(38); // Pinky

  // Step 657: Fingers [20, 62, 88, 30, 40] Arm [-, -, -]
  servo[0].write(20); // Thumb
  servo[1].write(62); // Index
  servo[2].write(88); // Middle
  servo[3].write(30); // Ring
  servo[4].write(40); // Pinky

  delay(16);
  // Step 658: Fingers [20, 62, 88, 30, 40] Arm [-, -, -]
  servo[0].write(20); // Thumb
  servo[1].write(62); // Index
  servo[2].write(88); // Middle
  servo[3].write(30); // Ring
  servo[4].write(40); // Pinky

  // Step 659: Fingers [20, 64, 87, 29, 42] Arm [-, -, -]
  servo[0].write(20); // Thumb
  servo[1].write(64); // Index
  servo[2].write(87); // Middle
  servo[3].write(29); // Ring
  servo[4].write(42); // Pinky

  delay(17);
  // Step 660: Fingers [20, 67, 86, 28, 44] Arm [-, -, -]
  servo[0].write(20); // Thumb
  servo[1].write(67); // Index
  servo[2].write(86); // Middle
  servo[3].write(28); // Ring
  servo[4].write(44); // Pinky

  // Step 661: Fingers [20, 67, 86, 28, 44] Arm [-, -, -]
  servo[0].write(20); // Thumb
  servo[1].write(67); // Index
  servo[2].write(86); // Middle
  servo[3].write(28); // Ring
  servo[4].write(44); // Pinky

  // Step 662: Fingers [20, 69, 85, 26, 47] Arm [-, -, -]
  servo[0].write(20); // Thumb
  servo[1].write(69); // Index
  servo[2].write(85); // Middle
  servo[3].write(26); // Ring
  servo[4].write(47); // Pinky

  delay(13);
  // Step 663: Fingers [21, 71, 83, 25, 49] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(71); // Index
  servo[2].write(83); // Middle
  servo[3].write(25); // Ring
  servo[4].write(49); // Pinky

  // Step 664: Fingers [21, 71, 83, 25, 49] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(71); // Index
  servo[2].write(83); // Middle
  servo[3].write(25); // Ring
  servo[4].write(49); // Pinky

  // Step 665: Fingers [21, 71, 84, 26, 49] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(71); // Index
  servo[2].write(84); // Middle
  servo[3].write(26); // Ring
  servo[4].write(49); // Pinky

  // Step 666: Fingers [21, 73, 82, 25, 51] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(73); // Index
  servo[2].write(82); // Middle
  servo[3].write(25); // Ring
  servo[4].write(51); // Pinky

  // Step 667: Fingers [22, 74, 82, 25, 52] Arm [-, -, -]
  servo[0].write(22); // Thumb
  servo[1].write(74); // Index
  servo[2].write(82); // Middle
  servo[3].write(25); // Ring
  servo[4].write(52); // Pinky

  // Step 668: Fingers [22, 76, 81, 24, 54] Arm [-, -, -]
  servo[0].write(22); // Thumb
  servo[1].write(76); // Index
  servo[2].write(81); // Middle
  servo[3].write(24); // Ring
  servo[4].write(54); // Pinky

  // Step 669: Fingers [22, 76, 81, 24, 54] Arm [-, -, -]
  servo[0].write(22); // Thumb
  servo[1].write(76); // Index
  servo[2].write(81); // Middle
  servo[3].write(24); // Ring
  servo[4].write(54); // Pinky

  // Step 670: Fingers [23, 78, 80, 24, 57] Arm [-, -, -]
  servo[0].write(23); // Thumb
  servo[1].write(78); // Index
  servo[2].write(80); // Middle
  servo[3].write(24); // Ring
  servo[4].write(57); // Pinky

  // Step 671: Fingers [24, 80, 78, 23, 59] Arm [-, -, -]
  servo[0].write(24); // Thumb
  servo[1].write(80); // Index
  servo[2].write(78); // Middle
  servo[3].write(23); // Ring
  servo[4].write(59); // Pinky

  // Step 672: Fingers [25, 82, 77, 23, 62] Arm [-, -, -]
  servo[0].write(25); // Thumb
  servo[1].write(82); // Index
  servo[2].write(77); // Middle
  servo[3].write(23); // Ring
  servo[4].write(62); // Pinky

  // Step 673: Fingers [25, 82, 77, 23, 62] Arm [-, -, -]
  servo[0].write(25); // Thumb
  servo[1].write(82); // Index
  servo[2].write(77); // Middle
  servo[3].write(23); // Ring
  servo[4].write(62); // Pinky

  // Step 674: Fingers [26, 84, 75, 23, 64] Arm [-, -, -]
  servo[0].write(26); // Thumb
  servo[1].write(84); // Index
  servo[2].write(75); // Middle
  servo[3].write(23); // Ring
  servo[4].write(64); // Pinky

  // Step 675: Fingers [28, 86, 73, 23, 67] Arm [-, -, -]
  servo[0].write(28); // Thumb
  servo[1].write(86); // Index
  servo[2].write(73); // Middle
  servo[3].write(23); // Ring
  servo[4].write(67); // Pinky

  delay(16);
  // Step 676: Fingers [30, 88, 71, 23, 69] Arm [-, -, -]
  servo[0].write(30); // Thumb
  servo[1].write(88); // Index
  servo[2].write(71); // Middle
  servo[3].write(23); // Ring
  servo[4].write(69); // Pinky

  // Step 677: Fingers [30, 88, 71, 23, 69] Arm [-, -, -]
  servo[0].write(30); // Thumb
  servo[1].write(88); // Index
  servo[2].write(71); // Middle
  servo[3].write(23); // Ring
  servo[4].write(69); // Pinky

  // Step 678: Fingers [30, 88, 72, 24, 70] Arm [-, -, -]
  servo[0].write(30); // Thumb
  servo[1].write(88); // Index
  servo[2].write(72); // Middle
  servo[3].write(24); // Ring
  servo[4].write(70); // Pinky

  // Step 679: Fingers [31, 90, 70, 24, 72] Arm [-, -, -]
  servo[0].write(31); // Thumb
  servo[1].write(90); // Index
  servo[2].write(70); // Middle
  servo[3].write(24); // Ring
  servo[4].write(72); // Pinky

  delay(14);
  // Step 680: Fingers [32, 90, 70, 24, 72] Arm [-, -, -]
  servo[0].write(32); // Thumb
  servo[1].write(90); // Index
  servo[2].write(70); // Middle
  servo[3].write(24); // Ring
  servo[4].write(72); // Pinky

  // Step 681: Fingers [32, 90, 70, 24, 72] Arm [-, -, -]
  servo[0].write(32); // Thumb
  servo[1].write(90); // Index
  servo[2].write(70); // Middle
  servo[3].write(24); // Ring
  servo[4].write(72); // Pinky

  // Step 682: Fingers [33, 91, 68, 24, 74] Arm [-, -, -]
  servo[0].write(33); // Thumb
  servo[1].write(91); // Index
  servo[2].write(68); // Middle
  servo[3].write(24); // Ring
  servo[4].write(74); // Pinky

  // Step 683: Fingers [35, 93, 66, 25, 77] Arm [-, -, -]
  servo[0].write(35); // Thumb
  servo[1].write(93); // Index
  servo[2].write(66); // Middle
  servo[3].write(25); // Ring
  servo[4].write(77); // Pinky

  delay(21);
  // Step 684: Fingers [35, 93, 66, 25, 77] Arm [-, -, -]
  servo[0].write(35); // Thumb
  servo[1].write(93); // Index
  servo[2].write(66); // Middle
  servo[3].write(25); // Ring
  servo[4].write(77); // Pinky

  delay(11);
  // Step 685: Fingers [35, 93, 67, 25, 77] Arm [-, -, -]
  servo[0].write(35); // Thumb
  servo[1].write(93); // Index
  servo[2].write(67); // Middle
  servo[3].write(25); // Ring
  servo[4].write(77); // Pinky

  // Step 686: Fingers [37, 94, 65, 26, 79] Arm [-, -, -]
  servo[0].write(37); // Thumb
  servo[1].write(94); // Index
  servo[2].write(65); // Middle
  servo[3].write(26); // Ring
  servo[4].write(79); // Pinky

  // Step 687: Fingers [38, 94, 65, 26, 80] Arm [-, -, -]
  servo[0].write(38); // Thumb
  servo[1].write(94); // Index
  servo[2].write(65); // Middle
  servo[3].write(26); // Ring
  servo[4].write(80); // Pinky

  // Step 688: Fingers [40, 96, 63, 27, 82] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(96); // Index
  servo[2].write(63); // Middle
  servo[3].write(27); // Ring
  servo[4].write(82); // Pinky

  // Step 689: Fingers [40, 96, 63, 27, 82] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(96); // Index
  servo[2].write(63); // Middle
  servo[3].write(27); // Ring
  servo[4].write(82); // Pinky

  delay(28);
  // Step 690: Fingers [40, 96, 63, 27, 82] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(96); // Index
  servo[2].write(63); // Middle
  servo[3].write(27); // Ring
  servo[4].write(82); // Pinky

  // Step 691: Fingers [44, 97, 59, 29, 86] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(97); // Index
  servo[2].write(59); // Middle
  servo[3].write(29); // Ring
  servo[4].write(86); // Pinky

  delay(16);
  // Step 692: Fingers [44, 98, 60, 30, 86] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(98); // Index
  servo[2].write(60); // Middle
  servo[3].write(30); // Ring
  servo[4].write(86); // Pinky

  delay(11);
  // Step 693: Fingers [44, 98, 60, 30, 86] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(98); // Index
  servo[2].write(60); // Middle
  servo[3].write(30); // Ring
  servo[4].write(86); // Pinky

  // Step 694: Fingers [47, 99, 58, 31, 88] Arm [-, -, -]
  servo[0].write(47); // Thumb
  servo[1].write(99); // Index
  servo[2].write(58); // Middle
  servo[3].write(31); // Ring
  servo[4].write(88); // Pinky

  delay(21);
  // Step 695: Fingers [47, 99, 58, 31, 88] Arm [-, -, -]
  servo[0].write(47); // Thumb
  servo[1].write(99); // Index
  servo[2].write(58); // Middle
  servo[3].write(31); // Ring
  servo[4].write(88); // Pinky

  // Step 696: Fingers [47, 99, 58, 31, 89] Arm [-, -, -]
  servo[0].write(47); // Thumb
  servo[1].write(99); // Index
  servo[2].write(58); // Middle
  servo[3].write(31); // Ring
  servo[4].write(89); // Pinky

  // Step 697: Fingers [49, 99, 56, 32, 90] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(99); // Index
  servo[2].write(56); // Middle
  servo[3].write(32); // Ring
  servo[4].write(90); // Pinky

  // Step 698: Fingers [49, 100, 56, 33, 91] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(100); // Index
  servo[2].write(56); // Middle
  servo[3].write(33); // Ring
  servo[4].write(91); // Pinky

  // Step 699: Fingers [49, 100, 56, 33, 91] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(100); // Index
  servo[2].write(56); // Middle
  servo[3].write(33); // Ring
  servo[4].write(91); // Pinky

  // Step 700: Fingers [52, 100, 54, 34, 92] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(100); // Index
  servo[2].write(54); // Middle
  servo[3].write(34); // Ring
  servo[4].write(92); // Pinky

  // Step 701: Fingers [52, 100, 55, 34, 93] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(100); // Index
  servo[2].write(55); // Middle
  servo[3].write(34); // Ring
  servo[4].write(93); // Pinky

  // Step 702: Fingers [52, 101, 55, 35, 93] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(101); // Index
  servo[2].write(55); // Middle
  servo[3].write(35); // Ring
  servo[4].write(93); // Pinky

  // Step 703: Fingers [52, 101, 55, 35, 93] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(101); // Index
  servo[2].write(55); // Middle
  servo[3].write(35); // Ring
  servo[4].write(93); // Pinky

  // Step 704: Fingers [55, 101, 53, 37, 95] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(101); // Index
  servo[2].write(53); // Middle
  servo[3].write(37); // Ring
  servo[4].write(95); // Pinky

  delay(15);
  // Step 705: Fingers [55, 102, 54, 37, 95] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(102); // Index
  servo[2].write(54); // Middle
  servo[3].write(37); // Ring
  servo[4].write(95); // Pinky

  // Step 706: Fingers [55, 102, 54, 37, 95] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(102); // Index
  servo[2].write(54); // Middle
  servo[3].write(37); // Ring
  servo[4].write(95); // Pinky

  // Step 707: Fingers [56, 102, 54, 37, 96] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(102); // Index
  servo[2].write(54); // Middle
  servo[3].write(37); // Ring
  servo[4].write(96); // Pinky

  // Step 708: Fingers [58, 102, 53, 39, 97] Arm [-, -, -]
  servo[0].write(58); // Thumb
  servo[1].write(102); // Index
  servo[2].write(53); // Middle
  servo[3].write(39); // Ring
  servo[4].write(97); // Pinky

  delay(14);
  // Step 709: Fingers [58, 102, 53, 39, 97] Arm [-, -, -]
  servo[0].write(58); // Thumb
  servo[1].write(102); // Index
  servo[2].write(53); // Middle
  servo[3].write(39); // Ring
  servo[4].write(97); // Pinky

  // Step 710: Fingers [59, 103, 53, 40, 98] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(103); // Index
  servo[2].write(53); // Middle
  servo[3].write(40); // Ring
  servo[4].write(98); // Pinky

  // Step 711: Fingers [59, 103, 53, 40, 98] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(103); // Index
  servo[2].write(53); // Middle
  servo[3].write(40); // Ring
  servo[4].write(98); // Pinky

  delay(17);
  // Step 712: Fingers [62, 103, 52, 42, 100] Arm [-, -, -]
  servo[0].write(62); // Thumb
  servo[1].write(103); // Index
  servo[2].write(52); // Middle
  servo[3].write(42); // Ring
  servo[4].write(100); // Pinky

  // Step 713: Fingers [62, 103, 52, 42, 100] Arm [-, -, -]
  servo[0].write(62); // Thumb
  servo[1].write(103); // Index
  servo[2].write(52); // Middle
  servo[3].write(42); // Ring
  servo[4].write(100); // Pinky

  delay(11);
  // Step 714: Fingers [64, 103, 50, 44, 101] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(103); // Index
  servo[2].write(50); // Middle
  servo[3].write(44); // Ring
  servo[4].write(101); // Pinky

  // Step 715: Fingers [65, 104, 51, 45, 102] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(104); // Index
  servo[2].write(51); // Middle
  servo[3].write(45); // Ring
  servo[4].write(102); // Pinky

  delay(15);
  // Step 716: Fingers [65, 104, 51, 45, 102] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(104); // Index
  servo[2].write(51); // Middle
  servo[3].write(45); // Ring
  servo[4].write(102); // Pinky

  delay(12);
  // Step 717: Fingers [68, 104, 50, 47, 103] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(104); // Index
  servo[2].write(50); // Middle
  servo[3].write(47); // Ring
  servo[4].write(103); // Pinky

  // Step 718: Fingers [68, 105, 50, 48, 104] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(105); // Index
  servo[2].write(50); // Middle
  servo[3].write(48); // Ring
  servo[4].write(104); // Pinky

  // Step 719: Fingers [69, 105, 51, 48, 104] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(105); // Index
  servo[2].write(51); // Middle
  servo[3].write(48); // Ring
  servo[4].write(104); // Pinky

  // Step 720: Fingers [69, 105, 51, 48, 104] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(105); // Index
  servo[2].write(51); // Middle
  servo[3].write(48); // Ring
  servo[4].write(104); // Pinky

  delay(16);
  // Step 721: Fingers [71, 105, 49, 50, 105] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(105); // Index
  servo[2].write(49); // Middle
  servo[3].write(50); // Ring
  servo[4].write(105); // Pinky

  // Step 722: Fingers [72, 105, 50, 51, 106] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(105); // Index
  servo[2].write(50); // Middle
  servo[3].write(51); // Ring
  servo[4].write(106); // Pinky

  // Step 723: Fingers [72, 106, 50, 51, 106] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(106); // Index
  servo[2].write(50); // Middle
  servo[3].write(51); // Ring
  servo[4].write(106); // Pinky

  // Step 724: Fingers [72, 106, 50, 51, 106] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(106); // Index
  servo[2].write(50); // Middle
  servo[3].write(51); // Ring
  servo[4].write(106); // Pinky

  // Step 725: Fingers [73, 106, 50, 51, 106] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(106); // Index
  servo[2].write(50); // Middle
  servo[3].write(51); // Ring
  servo[4].write(106); // Pinky

  // Step 726: Fingers [75, 106, 49, 54, 108] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(106); // Index
  servo[2].write(49); // Middle
  servo[3].write(54); // Ring
  servo[4].write(108); // Pinky

  delay(15);
  // Step 727: Fingers [75, 106, 49, 54, 108] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(106); // Index
  servo[2].write(49); // Middle
  servo[3].write(54); // Ring
  servo[4].write(108); // Pinky

  // Step 728: Fingers [76, 106, 50, 54, 108] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(106); // Index
  servo[2].write(50); // Middle
  servo[3].write(54); // Ring
  servo[4].write(108); // Pinky

  // Step 729: Fingers [78, 106, 48, 57, 109] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(106); // Index
  servo[2].write(48); // Middle
  servo[3].write(57); // Ring
  servo[4].write(109); // Pinky

  // Step 730: Fingers [79, 106, 49, 57, 109] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(106); // Index
  servo[2].write(49); // Middle
  servo[3].write(57); // Ring
  servo[4].write(109); // Pinky

  delay(16);
  // Step 731: Fingers [79, 106, 49, 57, 109] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(106); // Index
  servo[2].write(49); // Middle
  servo[3].write(57); // Ring
  servo[4].write(109); // Pinky

  // Step 732: Fingers [79, 107, 49, 57, 110] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(107); // Index
  servo[2].write(49); // Middle
  servo[3].write(57); // Ring
  servo[4].write(110); // Pinky

  // Step 733: Fingers [80, 107, 50, 58, 110] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(107); // Index
  servo[2].write(50); // Middle
  servo[3].write(58); // Ring
  servo[4].write(110); // Pinky

  delay(17);
  // Step 734: Fingers [82, 106, 48, 60, 111] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(106); // Index
  servo[2].write(48); // Middle
  servo[3].write(60); // Ring
  servo[4].write(111); // Pinky

  // Step 735: Fingers [82, 106, 48, 60, 111] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(106); // Index
  servo[2].write(48); // Middle
  servo[3].write(60); // Ring
  servo[4].write(111); // Pinky

  // Step 736: Fingers [83, 107, 49, 61, 111] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(107); // Index
  servo[2].write(49); // Middle
  servo[3].write(61); // Ring
  servo[4].write(111); // Pinky

  delay(11);
  // Step 737: Fingers [84, 108, 50, 61, 112] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(108); // Index
  servo[2].write(50); // Middle
  servo[3].write(61); // Ring
  servo[4].write(112); // Pinky

  // Step 738: Fingers [86, 106, 48, 64, 112] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(106); // Index
  servo[2].write(48); // Middle
  servo[3].write(64); // Ring
  servo[4].write(112); // Pinky

  // Step 739: Fingers [86, 106, 48, 64, 112] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(106); // Index
  servo[2].write(48); // Middle
  servo[3].write(64); // Ring
  servo[4].write(112); // Pinky

  // Step 740: Fingers [86, 107, 49, 64, 113] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(107); // Index
  servo[2].write(49); // Middle
  servo[3].write(64); // Ring
  servo[4].write(113); // Pinky

  delay(14);
  // Step 741: Fingers [87, 108, 50, 65, 114] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(108); // Index
  servo[2].write(50); // Middle
  servo[3].write(65); // Ring
  servo[4].write(114); // Pinky

  // Step 742: Fingers [87, 108, 50, 65, 114] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(108); // Index
  servo[2].write(50); // Middle
  servo[3].write(65); // Ring
  servo[4].write(114); // Pinky

  delay(11);
  // Step 743: Fingers [87, 108, 50, 65, 114] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(108); // Index
  servo[2].write(50); // Middle
  servo[3].write(65); // Ring
  servo[4].write(114); // Pinky

  delay(15);
  // Step 744: Fingers [87, 108, 50, 65, 114] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(108); // Index
  servo[2].write(50); // Middle
  servo[3].write(65); // Ring
  servo[4].write(114); // Pinky

  // Step 745: Fingers [88, 109, 50, 66, 114] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(109); // Index
  servo[2].write(50); // Middle
  servo[3].write(66); // Ring
  servo[4].write(114); // Pinky

  // Step 746: Fingers [88, 109, 51, 66, 115] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(109); // Index
  servo[2].write(51); // Middle
  servo[3].write(66); // Ring
  servo[4].write(115); // Pinky

  // Step 747: Fingers [89, 109, 51, 67, 115] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(109); // Index
  servo[2].write(51); // Middle
  servo[3].write(67); // Ring
  servo[4].write(115); // Pinky

  // Step 748: Fingers [89, 109, 51, 67, 115] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(109); // Index
  servo[2].write(51); // Middle
  servo[3].write(67); // Ring
  servo[4].write(115); // Pinky

  // Step 749: Fingers [92, 109, 51, 69, 116] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(109); // Index
  servo[2].write(51); // Middle
  servo[3].write(69); // Ring
  servo[4].write(116); // Pinky

  delay(15);
  // Step 750: Fingers [92, 109, 51, 70, 117] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(109); // Index
  servo[2].write(51); // Middle
  servo[3].write(70); // Ring
  servo[4].write(117); // Pinky

  // Step 751: Fingers [92, 109, 51, 70, 117] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(109); // Index
  servo[2].write(51); // Middle
  servo[3].write(70); // Ring
  servo[4].write(117); // Pinky

  // Step 752: Fingers [95, 109, 51, 73, 117] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(109); // Index
  servo[2].write(51); // Middle
  servo[3].write(73); // Ring
  servo[4].write(117); // Pinky

  // Step 753: Fingers [96, 110, 52, 74, 118] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(110); // Index
  servo[2].write(52); // Middle
  servo[3].write(74); // Ring
  servo[4].write(118); // Pinky

  // Step 754: Fingers [96, 110, 52, 74, 119] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(110); // Index
  servo[2].write(52); // Middle
  servo[3].write(74); // Ring
  servo[4].write(119); // Pinky

  // Step 755: Fingers [97, 111, 53, 75, 119] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(111); // Index
  servo[2].write(53); // Middle
  servo[3].write(75); // Ring
  servo[4].write(119); // Pinky

  // Step 756: Fingers [97, 111, 53, 75, 119] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(111); // Index
  servo[2].write(53); // Middle
  servo[3].write(75); // Ring
  servo[4].write(119); // Pinky

  // Step 757: Fingers [98, 111, 53, 75, 120] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(111); // Index
  servo[2].write(53); // Middle
  servo[3].write(75); // Ring
  servo[4].write(120); // Pinky

  // Step 758: Fingers [98, 112, 54, 76, 120] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(112); // Index
  servo[2].write(54); // Middle
  servo[3].write(76); // Ring
  servo[4].write(120); // Pinky

  // Step 759: Fingers [99, 113, 55, 77, 121] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(113); // Index
  servo[2].write(55); // Middle
  servo[3].write(77); // Ring
  servo[4].write(121); // Pinky

  // Step 760: Fingers [102, 112, 55, 80, 122] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(112); // Index
  servo[2].write(55); // Middle
  servo[3].write(80); // Ring
  servo[4].write(122); // Pinky

  // Step 761: Fingers [102, 112, 55, 80, 122] Arm [-, -, -]
  servo[0].write(102); // Thumb
  servo[1].write(112); // Index
  servo[2].write(55); // Middle
  servo[3].write(80); // Ring
  servo[4].write(122); // Pinky

  // Step 762: Fingers [103, 113, 56, 81, 123] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(113); // Index
  servo[2].write(56); // Middle
  servo[3].write(81); // Ring
  servo[4].write(123); // Pinky

  // Step 763: Fingers [104, 114, 56, 81, 123] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(114); // Index
  servo[2].write(56); // Middle
  servo[3].write(81); // Ring
  servo[4].write(123); // Pinky

  // Step 764: Fingers [104, 115, 57, 82, 124] Arm [-, -, -]
  servo[0].write(104); // Thumb
  servo[1].write(115); // Index
  servo[2].write(57); // Middle
  servo[3].write(82); // Ring
  servo[4].write(124); // Pinky

  // Step 765: Fingers [105, 115, 57, 83, 125] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(115); // Index
  servo[2].write(57); // Middle
  servo[3].write(83); // Ring
  servo[4].write(125); // Pinky

  // Step 766: Fingers [105, 115, 57, 83, 125] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(115); // Index
  servo[2].write(57); // Middle
  servo[3].write(83); // Ring
  servo[4].write(125); // Pinky

  // Step 767: Fingers [106, 116, 59, 84, 126] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(116); // Index
  servo[2].write(59); // Middle
  servo[3].write(84); // Ring
  servo[4].write(126); // Pinky

  // Step 768: Fingers [107, 117, 59, 85, 127] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(117); // Index
  servo[2].write(59); // Middle
  servo[3].write(85); // Ring
  servo[4].write(127); // Pinky

  // Step 769: Fingers [108, 118, 60, 86, 128] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(118); // Index
  servo[2].write(60); // Middle
  servo[3].write(86); // Ring
  servo[4].write(128); // Pinky

  // Step 770: Fingers [109, 119, 62, 87, 129] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(119); // Index
  servo[2].write(62); // Middle
  servo[3].write(87); // Ring
  servo[4].write(129); // Pinky

  // Step 771: Fingers [109, 119, 62, 87, 129] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(119); // Index
  servo[2].write(62); // Middle
  servo[3].write(87); // Ring
  servo[4].write(129); // Pinky

  // Step 772: Fingers [110, 120, 62, 88, 130] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(120); // Index
  servo[2].write(62); // Middle
  servo[3].write(88); // Ring
  servo[4].write(130); // Pinky

  // Step 773: Fingers [111, 121, 63, 89, 131] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(121); // Index
  servo[2].write(63); // Middle
  servo[3].write(89); // Ring
  servo[4].write(131); // Pinky

  // Step 774: Fingers [112, 122, 64, 90, 132] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(122); // Index
  servo[2].write(64); // Middle
  servo[3].write(90); // Ring
  servo[4].write(132); // Pinky

  // Step 775: Fingers [112, 123, 65, 90, 132] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(123); // Index
  servo[2].write(65); // Middle
  servo[3].write(90); // Ring
  servo[4].write(132); // Pinky

  // Step 776: Fingers [112, 123, 65, 90, 132] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(123); // Index
  servo[2].write(65); // Middle
  servo[3].write(90); // Ring
  servo[4].write(132); // Pinky

  // Step 777: Fingers [112, 125, 67, 89, 134] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(125); // Index
  servo[2].write(67); // Middle
  servo[3].write(89); // Ring
  servo[4].write(134); // Pinky

  // Step 778: Fingers [111, 128, 70, 89, 135] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(128); // Index
  servo[2].write(70); // Middle
  servo[3].write(89); // Ring
  servo[4].write(135); // Pinky

  // Step 779: Fingers [113, 130, 72, 90, 137] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(130); // Index
  servo[2].write(72); // Middle
  servo[3].write(90); // Ring
  servo[4].write(137); // Pinky

  // Step 780: Fingers [113, 130, 72, 90, 137] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(130); // Index
  servo[2].write(72); // Middle
  servo[3].write(90); // Ring
  servo[4].write(137); // Pinky

  // Step 781: Fingers [114, 131, 73, 92, 138] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(131); // Index
  servo[2].write(73); // Middle
  servo[3].write(92); // Ring
  servo[4].write(138); // Pinky

  // Step 782: Fingers [113, 134, 75, 91, 139] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(134); // Index
  servo[2].write(75); // Middle
  servo[3].write(91); // Ring
  servo[4].write(139); // Pinky

  // Step 783: Fingers [112, 136, 78, 90, 140] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(136); // Index
  servo[2].write(78); // Middle
  servo[3].write(90); // Ring
  servo[4].write(140); // Pinky

  // Step 784: Fingers [113, 137, 79, 90, 141] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(137); // Index
  servo[2].write(79); // Middle
  servo[3].write(90); // Ring
  servo[4].write(141); // Pinky

  // Step 785: Fingers [113, 137, 79, 90, 141] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(137); // Index
  servo[2].write(79); // Middle
  servo[3].write(90); // Ring
  servo[4].write(141); // Pinky

  // Step 786: Fingers [111, 138, 81, 89, 142] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(138); // Index
  servo[2].write(81); // Middle
  servo[3].write(89); // Ring
  servo[4].write(142); // Pinky

  // Step 787: Fingers [112, 139, 82, 90, 142] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(139); // Index
  servo[2].write(82); // Middle
  servo[3].write(90); // Ring
  servo[4].write(142); // Pinky

  // Step 788: Fingers [113, 141, 83, 91, 144] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(141); // Index
  servo[2].write(83); // Middle
  servo[3].write(91); // Ring
  servo[4].write(144); // Pinky

  // Step 789: Fingers [114, 141, 84, 92, 145] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(141); // Index
  servo[2].write(84); // Middle
  servo[3].write(92); // Ring
  servo[4].write(145); // Pinky

  // Step 790: Fingers [114, 141, 84, 92, 145] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(141); // Index
  servo[2].write(84); // Middle
  servo[3].write(92); // Ring
  servo[4].write(145); // Pinky

  // Step 791: Fingers [113, 143, 86, 91, 145] Arm [-, -, -]
  servo[0].write(113); // Thumb
  servo[1].write(143); // Index
  servo[2].write(86); // Middle
  servo[3].write(91); // Ring
  servo[4].write(145); // Pinky

  // Step 792: Fingers [111, 145, 89, 90, 145] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(145); // Index
  servo[2].write(89); // Middle
  servo[3].write(90); // Ring
  servo[4].write(145); // Pinky

  // Step 793: Fingers [110, 146, 92, 89, 145] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(146); // Index
  servo[2].write(92); // Middle
  servo[3].write(89); // Ring
  servo[4].write(145); // Pinky

  // Step 794: Fingers [111, 147, 93, 90, 146] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(147); // Index
  servo[2].write(93); // Middle
  servo[3].write(90); // Ring
  servo[4].write(146); // Pinky

  // Step 795: Fingers [111, 147, 93, 90, 146] Arm [-, -, -]
  servo[0].write(111); // Thumb
  servo[1].write(147); // Index
  servo[2].write(93); // Middle
  servo[3].write(90); // Ring
  servo[4].write(146); // Pinky

  // Step 796: Fingers [109, 149, 95, 89, 146] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(149); // Index
  servo[2].write(95); // Middle
  servo[3].write(89); // Ring
  servo[4].write(146); // Pinky

  // Step 797: Fingers [108, 150, 98, 88, 146] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(150); // Index
  servo[2].write(98); // Middle
  servo[3].write(88); // Ring
  servo[4].write(146); // Pinky

  // Step 798: Fingers [109, 150, 99, 89, 146] Arm [-, -, -]
  servo[0].write(109); // Thumb
  servo[1].write(150); // Index
  servo[2].write(99); // Middle
  servo[3].write(89); // Ring
  servo[4].write(146); // Pinky

  // Step 799: Fingers [107, 151, 101, 88, 146] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(151); // Index
  servo[2].write(101); // Middle
  servo[3].write(88); // Ring
  servo[4].write(146); // Pinky

  // Step 800: Fingers [107, 151, 101, 88, 146] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(151); // Index
  servo[2].write(101); // Middle
  servo[3].write(88); // Ring
  servo[4].write(146); // Pinky

  // Step 801: Fingers [108, 152, 102, 89, 147] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(152); // Index
  servo[2].write(102); // Middle
  servo[3].write(89); // Ring
  servo[4].write(147); // Pinky

  // Step 802: Fingers [106, 152, 104, 88, 146] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(152); // Index
  servo[2].write(104); // Middle
  servo[3].write(88); // Ring
  servo[4].write(146); // Pinky

  delay(16);
  // Step 803: Fingers [106, 153, 105, 88, 146] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(153); // Index
  servo[2].write(105); // Middle
  servo[3].write(88); // Ring
  servo[4].write(146); // Pinky

  // Step 804: Fingers [106, 153, 105, 88, 146] Arm [-, -, -]
  servo[0].write(106); // Thumb
  servo[1].write(153); // Index
  servo[2].write(105); // Middle
  servo[3].write(88); // Ring
  servo[4].write(146); // Pinky

  // Step 805: Fingers [105, 153, 107, 87, 145] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(153); // Index
  servo[2].write(107); // Middle
  servo[3].write(87); // Ring
  servo[4].write(145); // Pinky

  delay(11);
  // Step 806: Fingers [103, 153, 110, 86, 144] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(153); // Index
  servo[2].write(110); // Middle
  servo[3].write(86); // Ring
  servo[4].write(144); // Pinky

  // Step 807: Fingers [103, 154, 110, 87, 145] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(154); // Index
  servo[2].write(110); // Middle
  servo[3].write(87); // Ring
  servo[4].write(145); // Pinky

  // Step 808: Fingers [103, 154, 110, 87, 145] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(154); // Index
  servo[2].write(110); // Middle
  servo[3].write(87); // Ring
  servo[4].write(145); // Pinky

  // Step 809: Fingers [99, 153, 115, 85, 142] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(153); // Index
  servo[2].write(115); // Middle
  servo[3].write(85); // Ring
  servo[4].write(142); // Pinky

  // Step 810: Fingers [100, 154, 115, 85, 142] Arm [-, -, -]
  servo[0].write(100); // Thumb
  servo[1].write(154); // Index
  servo[2].write(115); // Middle
  servo[3].write(85); // Ring
  servo[4].write(142); // Pinky

  // Step 811: Fingers [97, 153, 120, 84, 139] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(153); // Index
  servo[2].write(120); // Middle
  servo[3].write(84); // Ring
  servo[4].write(139); // Pinky

  // Step 812: Fingers [97, 153, 121, 85, 139] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(153); // Index
  servo[2].write(121); // Middle
  servo[3].write(85); // Ring
  servo[4].write(139); // Pinky

  // Step 813: Fingers [97, 153, 121, 85, 139] Arm [-, -, -]
  servo[0].write(97); // Thumb
  servo[1].write(153); // Index
  servo[2].write(121); // Middle
  servo[3].write(85); // Ring
  servo[4].write(139); // Pinky

  // Step 814: Fingers [95, 152, 123, 84, 137] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(152); // Index
  servo[2].write(123); // Middle
  servo[3].write(84); // Ring
  servo[4].write(137); // Pinky

  // Step 815: Fingers [94, 151, 125, 84, 136] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(151); // Index
  servo[2].write(125); // Middle
  servo[3].write(84); // Ring
  servo[4].write(136); // Pinky

  // Step 816: Fingers [94, 152, 125, 84, 136] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(152); // Index
  servo[2].write(125); // Middle
  servo[3].write(84); // Ring
  servo[4].write(136); // Pinky

  delay(13);
  // Step 817: Fingers [94, 152, 125, 84, 136] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(152); // Index
  servo[2].write(125); // Middle
  servo[3].write(84); // Ring
  servo[4].write(136); // Pinky

  delay(11);
  // Step 818: Fingers [91, 149, 130, 84, 132] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(149); // Index
  servo[2].write(130); // Middle
  servo[3].write(84); // Ring
  servo[4].write(132); // Pinky

  // Step 819: Fingers [92, 150, 130, 84, 132] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(150); // Index
  servo[2].write(130); // Middle
  servo[3].write(84); // Ring
  servo[4].write(132); // Pinky

  // Step 820: Fingers [92, 150, 130, 84, 132] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(150); // Index
  servo[2].write(130); // Middle
  servo[3].write(84); // Ring
  servo[4].write(132); // Pinky

  // Step 821: Fingers [91, 149, 133, 85, 131] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(149); // Index
  servo[2].write(133); // Middle
  servo[3].write(85); // Ring
  servo[4].write(131); // Pinky

  // Step 822: Fingers [88, 146, 137, 85, 126] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(146); // Index
  servo[2].write(137); // Middle
  servo[3].write(85); // Ring
  servo[4].write(126); // Pinky

  // Step 823: Fingers [88, 144, 139, 85, 124] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(144); // Index
  servo[2].write(139); // Middle
  servo[3].write(85); // Ring
  servo[4].write(124); // Pinky

  // Step 824: Fingers [88, 144, 139, 85, 124] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(144); // Index
  servo[2].write(139); // Middle
  servo[3].write(85); // Ring
  servo[4].write(124); // Pinky

  // Step 825: Fingers [86, 141, 143, 87, 120] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(141); // Index
  servo[2].write(143); // Middle
  servo[3].write(87); // Ring
  servo[4].write(120); // Pinky

  // Step 826: Fingers [86, 136, 148, 90, 114] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(136); // Index
  servo[2].write(148); // Middle
  servo[3].write(90); // Ring
  servo[4].write(114); // Pinky

  // Step 827: Fingers [86, 132, 151, 93, 110] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(132); // Index
  servo[2].write(151); // Middle
  servo[3].write(93); // Ring
  servo[4].write(110); // Pinky

  // Step 828: Fingers [87, 126, 155, 98, 104] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(126); // Index
  servo[2].write(155); // Middle
  servo[3].write(98); // Ring
  servo[4].write(104); // Pinky

  // Step 829: Fingers [87, 126, 155, 98, 104] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(126); // Index
  servo[2].write(155); // Middle
  servo[3].write(98); // Ring
  servo[4].write(104); // Pinky

  // Step 830: Fingers [88, 124, 156, 100, 103] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(124); // Index
  servo[2].write(156); // Middle
  servo[3].write(100); // Ring
  servo[4].write(103); // Pinky

  // Step 831: Fingers [90, 120, 158, 104, 100] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(120); // Index
  servo[2].write(158); // Middle
  servo[3].write(104); // Ring
  servo[4].write(100); // Pinky

  // Step 832: Fingers [94, 114, 160, 111, 96] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(114); // Index
  servo[2].write(160); // Middle
  servo[3].write(111); // Ring
  servo[4].write(96); // Pinky

  // Step 833: Fingers [95, 112, 160, 113, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(112); // Index
  servo[2].write(160); // Middle
  servo[3].write(113); // Ring
  servo[4].write(95); // Pinky

  // Step 834: Fingers [95, 112, 160, 113, 95] Arm [-, -, -]
  servo[0].write(95); // Thumb
  servo[1].write(112); // Index
  servo[2].write(160); // Middle
  servo[3].write(113); // Ring
  servo[4].write(95); // Pinky

  // Step 835: Fingers [99, 110, 161, 119, 93] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(110); // Index
  servo[2].write(161); // Middle
  servo[3].write(119); // Ring
  servo[4].write(93); // Pinky

  // Step 836: Fingers [103, 106, 160, 123, 92] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(106); // Index
  servo[2].write(160); // Middle
  servo[3].write(123); // Ring
  servo[4].write(92); // Pinky

  // Step 837: Fingers [107, 103, 159, 129, 91] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(103); // Index
  servo[2].write(159); // Middle
  servo[3].write(129); // Ring
  servo[4].write(91); // Pinky

  // Step 838: Fingers [112, 101, 158, 134, 91] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(101); // Index
  servo[2].write(158); // Middle
  servo[3].write(134); // Ring
  servo[4].write(91); // Pinky

  // Step 839: Fingers [112, 101, 158, 134, 91] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(101); // Index
  servo[2].write(158); // Middle
  servo[3].write(134); // Ring
  servo[4].write(91); // Pinky

  // Step 840: Fingers [117, 99, 157, 139, 92] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(99); // Index
  servo[2].write(157); // Middle
  servo[3].write(139); // Ring
  servo[4].write(92); // Pinky

  // Step 841: Fingers [124, 96, 153, 146, 93] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(96); // Index
  servo[2].write(153); // Middle
  servo[3].write(146); // Ring
  servo[4].write(93); // Pinky

  // Step 842: Fingers [129, 95, 150, 150, 95] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(95); // Index
  servo[2].write(150); // Middle
  servo[3].write(150); // Ring
  servo[4].write(95); // Pinky

  // Step 843: Fingers [134, 95, 147, 154, 97] Arm [-, -, -]
  servo[0].write(134); // Thumb
  servo[1].write(95); // Index
  servo[2].write(147); // Middle
  servo[3].write(154); // Ring
  servo[4].write(97); // Pinky

  // Step 844: Fingers [134, 95, 147, 154, 97] Arm [-, -, -]
  servo[0].write(134); // Thumb
  servo[1].write(95); // Index
  servo[2].write(147); // Middle
  servo[3].write(154); // Ring
  servo[4].write(97); // Pinky

  // Step 845: Fingers [139, 94, 144, 158, 100] Arm [-, -, -]
  servo[0].write(139); // Thumb
  servo[1].write(94); // Index
  servo[2].write(144); // Middle
  servo[3].write(158); // Ring
  servo[4].write(100); // Pinky

  // Step 846: Fingers [145, 95, 137, 162, 104] Arm [-, -, -]
  servo[0].write(145); // Thumb
  servo[1].write(95); // Index
  servo[2].write(137); // Middle
  servo[3].write(162); // Ring
  servo[4].write(104); // Pinky

  // Step 847: Fingers [148, 95, 136, 163, 106] Arm [-, -, -]
  servo[0].write(148); // Thumb
  servo[1].write(95); // Index
  servo[2].write(136); // Middle
  servo[3].write(163); // Ring
  servo[4].write(106); // Pinky

  // Step 848: Fingers [152, 97, 131, 165, 110] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(97); // Index
  servo[2].write(131); // Middle
  servo[3].write(165); // Ring
  servo[4].write(110); // Pinky

  // Step 849: Fingers [152, 97, 131, 165, 110] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(97); // Index
  servo[2].write(131); // Middle
  servo[3].write(165); // Ring
  servo[4].write(110); // Pinky

  // Step 850: Fingers [156, 98, 127, 166, 113] Arm [-, -, -]
  servo[0].write(156); // Thumb
  servo[1].write(98); // Index
  servo[2].write(127); // Middle
  servo[3].write(166); // Ring
  servo[4].write(113); // Pinky

  // Step 851: Fingers [159, 101, 123, 167, 118] Arm [-, -, -]
  servo[0].write(159); // Thumb
  servo[1].write(101); // Index
  servo[2].write(123); // Middle
  servo[3].write(167); // Ring
  servo[4].write(118); // Pinky

  // Step 852: Fingers [162, 104, 119, 168, 122] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(104); // Index
  servo[2].write(119); // Middle
  servo[3].write(168); // Ring
  servo[4].write(122); // Pinky

  // Step 853: Fingers [163, 105, 117, 168, 125] Arm [-, -, -]
  servo[0].write(163); // Thumb
  servo[1].write(105); // Index
  servo[2].write(117); // Middle
  servo[3].write(168); // Ring
  servo[4].write(125); // Pinky

  // Step 854: Fingers [163, 105, 117, 168, 125] Arm [-, -, -]
  servo[0].write(163); // Thumb
  servo[1].write(105); // Index
  servo[2].write(117); // Middle
  servo[3].write(168); // Ring
  servo[4].write(125); // Pinky

  delay(15);
  // Step 855: Fingers [168, 114, 108, 165, 136] Arm [-, -, -]
  servo[0].write(168); // Thumb
  servo[1].write(114); // Index
  servo[2].write(108); // Middle
  servo[3].write(165); // Ring
  servo[4].write(136); // Pinky

  // Step 856: Fingers [168, 118, 105, 163, 141] Arm [-, -, -]
  servo[0].write(168); // Thumb
  servo[1].write(118); // Index
  servo[2].write(105); // Middle
  servo[3].write(163); // Ring
  servo[4].write(141); // Pinky

  // Step 857: Fingers [168, 118, 105, 163, 141] Arm [-, -, -]
  servo[0].write(168); // Thumb
  servo[1].write(118); // Index
  servo[2].write(105); // Middle
  servo[3].write(163); // Ring
  servo[4].write(141); // Pinky

  // Step 858: Fingers [169, 121, 105, 163, 144] Arm [-, -, -]
  servo[0].write(169); // Thumb
  servo[1].write(121); // Index
  servo[2].write(105); // Middle
  servo[3].write(163); // Ring
  servo[4].write(144); // Pinky

  // Step 859: Fingers [169, 126, 102, 160, 148] Arm [-, -, -]
  servo[0].write(169); // Thumb
  servo[1].write(126); // Index
  servo[2].write(102); // Middle
  servo[3].write(160); // Ring
  servo[4].write(148); // Pinky

  // Step 860: Fingers [169, 131, 101, 157, 152] Arm [-, -, -]
  servo[0].write(169); // Thumb
  servo[1].write(131); // Index
  servo[2].write(101); // Middle
  servo[3].write(157); // Ring
  servo[4].write(152); // Pinky

  // Step 861: Fingers [168, 133, 100, 156, 154] Arm [-, -, -]
  servo[0].write(168); // Thumb
  servo[1].write(133); // Index
  servo[2].write(100); // Middle
  servo[3].write(156); // Ring
  servo[4].write(154); // Pinky

  // Step 862: Fingers [168, 133, 100, 156, 154] Arm [-, -, -]
  servo[0].write(168); // Thumb
  servo[1].write(133); // Index
  servo[2].write(100); // Middle
  servo[3].write(156); // Ring
  servo[4].write(154); // Pinky

  // Step 863: Fingers [168, 138, 99, 153, 158] Arm [-, -, -]
  servo[0].write(168); // Thumb
  servo[1].write(138); // Index
  servo[2].write(99); // Middle
  servo[3].write(153); // Ring
  servo[4].write(158); // Pinky

  // Step 864: Fingers [166, 142, 99, 149, 162] Arm [-, -, -]
  servo[0].write(166); // Thumb
  servo[1].write(142); // Index
  servo[2].write(99); // Middle
  servo[3].write(149); // Ring
  servo[4].write(162); // Pinky

  delay(17);
  // Step 865: Fingers [164, 145, 99, 147, 163] Arm [-, -, -]
  servo[0].write(164); // Thumb
  servo[1].write(145); // Index
  servo[2].write(99); // Middle
  servo[3].write(147); // Ring
  servo[4].write(163); // Pinky

  // Step 866: Fingers [164, 145, 99, 147, 163] Arm [-, -, -]
  servo[0].write(164); // Thumb
  servo[1].write(145); // Index
  servo[2].write(99); // Middle
  servo[3].write(147); // Ring
  servo[4].write(163); // Pinky

  // Step 867: Fingers [163, 147, 99, 145, 164] Arm [-, -, -]
  servo[0].write(163); // Thumb
  servo[1].write(147); // Index
  servo[2].write(99); // Middle
  servo[3].write(145); // Ring
  servo[4].write(164); // Pinky

  // Step 868: Fingers [162, 149, 99, 142, 166] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(149); // Index
  servo[2].write(99); // Middle
  servo[3].write(142); // Ring
  servo[4].write(166); // Pinky

  delay(15);
  // Step 869: Fingers [162, 149, 99, 142, 166] Arm [-, -, -]
  servo[0].write(162); // Thumb
  servo[1].write(149); // Index
  servo[2].write(99); // Middle
  servo[3].write(142); // Ring
  servo[4].write(166); // Pinky

  // Step 870: Fingers [160, 151, 99, 140, 167] Arm [-, -, -]
  servo[0].write(160); // Thumb
  servo[1].write(151); // Index
  servo[2].write(99); // Middle
  servo[3].write(140); // Ring
  servo[4].write(167); // Pinky

  // Step 871: Fingers [158, 152, 99, 138, 167] Arm [-, -, -]
  servo[0].write(158); // Thumb
  servo[1].write(152); // Index
  servo[2].write(99); // Middle
  servo[3].write(138); // Ring
  servo[4].write(167); // Pinky

  delay(16);
  // Step 872: Fingers [155, 156, 100, 133, 169] Arm [-, -, -]
  servo[0].write(155); // Thumb
  servo[1].write(156); // Index
  servo[2].write(100); // Middle
  servo[3].write(133); // Ring
  servo[4].write(169); // Pinky

  // Step 873: Fingers [155, 156, 100, 133, 169] Arm [-, -, -]
  servo[0].write(155); // Thumb
  servo[1].write(156); // Index
  servo[2].write(100); // Middle
  servo[3].write(133); // Ring
  servo[4].write(169); // Pinky

  // Step 874: Fingers [152, 157, 101, 131, 169] Arm [-, -, -]
  servo[0].write(152); // Thumb
  servo[1].write(157); // Index
  servo[2].write(101); // Middle
  servo[3].write(131); // Ring
  servo[4].write(169); // Pinky

  // Step 875: Fingers [148, 160, 102, 126, 169] Arm [-, -, -]
  servo[0].write(148); // Thumb
  servo[1].write(160); // Index
  servo[2].write(102); // Middle
  servo[3].write(126); // Ring
  servo[4].write(169); // Pinky

  // Step 876: Fingers [144, 163, 105, 121, 169] Arm [-, -, -]
  servo[0].write(144); // Thumb
  servo[1].write(163); // Index
  servo[2].write(105); // Middle
  servo[3].write(121); // Ring
  servo[4].write(169); // Pinky

  // Step 877: Fingers [141, 164, 106, 119, 169] Arm [-, -, -]
  servo[0].write(141); // Thumb
  servo[1].write(164); // Index
  servo[2].write(106); // Middle
  servo[3].write(119); // Ring
  servo[4].write(169); // Pinky

  // Step 878: Fingers [141, 164, 106, 119, 169] Arm [-, -, -]
  servo[0].write(141); // Thumb
  servo[1].write(164); // Index
  servo[2].write(106); // Middle
  servo[3].write(119); // Ring
  servo[4].write(169); // Pinky

  // Step 879: Fingers [136, 165, 108, 114, 168] Arm [-, -, -]
  servo[0].write(136); // Thumb
  servo[1].write(165); // Index
  servo[2].write(108); // Middle
  servo[3].write(114); // Ring
  servo[4].write(168); // Pinky

  // Step 880: Fingers [134, 166, 110, 113, 167] Arm [-, -, -]
  servo[0].write(134); // Thumb
  servo[1].write(166); // Index
  servo[2].write(110); // Middle
  servo[3].write(113); // Ring
  servo[4].write(167); // Pinky

  // Step 881: Fingers [132, 167, 112, 111, 166] Arm [-, -, -]
  servo[0].write(132); // Thumb
  servo[1].write(167); // Index
  servo[2].write(112); // Middle
  servo[3].write(111); // Ring
  servo[4].write(166); // Pinky

  // Step 882: Fingers [132, 167, 112, 111, 166] Arm [-, -, -]
  servo[0].write(132); // Thumb
  servo[1].write(167); // Index
  servo[2].write(112); // Middle
  servo[3].write(111); // Ring
  servo[4].write(166); // Pinky

  // Step 883: Fingers [129, 167, 113, 109, 165] Arm [-, -, -]
  servo[0].write(129); // Thumb
  servo[1].write(167); // Index
  servo[2].write(113); // Middle
  servo[3].write(109); // Ring
  servo[4].write(165); // Pinky

  // Step 884: Fingers [127, 167, 115, 107, 164] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(167); // Index
  servo[2].write(115); // Middle
  servo[3].write(107); // Ring
  servo[4].write(164); // Pinky

  delay(17);
  // Step 885: Fingers [127, 167, 115, 107, 164] Arm [-, -, -]
  servo[0].write(127); // Thumb
  servo[1].write(167); // Index
  servo[2].write(115); // Middle
  servo[3].write(107); // Ring
  servo[4].write(164); // Pinky

  // Step 886: Fingers [124, 167, 116, 105, 162] Arm [-, -, -]
  servo[0].write(124); // Thumb
  servo[1].write(167); // Index
  servo[2].write(116); // Middle
  servo[3].write(105); // Ring
  servo[4].write(162); // Pinky

  // Step 887: Fingers [122, 167, 118, 103, 161] Arm [-, -, -]
  servo[0].write(122); // Thumb
  servo[1].write(167); // Index
  servo[2].write(118); // Middle
  servo[3].write(103); // Ring
  servo[4].write(161); // Pinky

  delay(12);
  // Step 888: Fingers [119, 167, 120, 101, 160] Arm [-, -, -]
  servo[0].write(119); // Thumb
  servo[1].write(167); // Index
  servo[2].write(120); // Middle
  servo[3].write(101); // Ring
  servo[4].write(160); // Pinky

  // Step 889: Fingers [117, 166, 122, 100, 158] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(166); // Index
  servo[2].write(122); // Middle
  servo[3].write(100); // Ring
  servo[4].write(158); // Pinky

  // Step 890: Fingers [117, 166, 122, 100, 158] Arm [-, -, -]
  servo[0].write(117); // Thumb
  servo[1].write(166); // Index
  servo[2].write(122); // Middle
  servo[3].write(100); // Ring
  servo[4].write(158); // Pinky

  // Step 891: Fingers [114, 166, 124, 98, 156] Arm [-, -, -]
  servo[0].write(114); // Thumb
  servo[1].write(166); // Index
  servo[2].write(124); // Middle
  servo[3].write(98); // Ring
  servo[4].write(156); // Pinky

  delay(16);
  // Step 892: Fingers [112, 165, 126, 97, 154] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(165); // Index
  servo[2].write(126); // Middle
  servo[3].write(97); // Ring
  servo[4].write(154); // Pinky

  // Step 893: Fingers [112, 165, 126, 97, 154] Arm [-, -, -]
  servo[0].write(112); // Thumb
  servo[1].write(165); // Index
  servo[2].write(126); // Middle
  servo[3].write(97); // Ring
  servo[4].write(154); // Pinky

  // Step 894: Fingers [110, 164, 128, 96, 152] Arm [-, -, -]
  servo[0].write(110); // Thumb
  servo[1].write(164); // Index
  servo[2].write(128); // Middle
  servo[3].write(96); // Ring
  servo[4].write(152); // Pinky

  // Step 895: Fingers [108, 163, 129, 95, 150] Arm [-, -, -]
  servo[0].write(108); // Thumb
  servo[1].write(163); // Index
  servo[2].write(129); // Middle
  servo[3].write(95); // Ring
  servo[4].write(150); // Pinky

  // Step 896: Fingers [107, 163, 129, 94, 150] Arm [-, -, -]
  servo[0].write(107); // Thumb
  servo[1].write(163); // Index
  servo[2].write(129); // Middle
  servo[3].write(94); // Ring
  servo[4].write(150); // Pinky

  // Step 897: Fingers [105, 162, 131, 94, 148] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(162); // Index
  servo[2].write(131); // Middle
  servo[3].write(94); // Ring
  servo[4].write(148); // Pinky

  // Step 898: Fingers [105, 162, 131, 94, 148] Arm [-, -, -]
  servo[0].write(105); // Thumb
  servo[1].write(162); // Index
  servo[2].write(131); // Middle
  servo[3].write(94); // Ring
  servo[4].write(148); // Pinky

  // Step 899: Fingers [103, 161, 133, 93, 145] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(161); // Index
  servo[2].write(133); // Middle
  servo[3].write(93); // Ring
  servo[4].write(145); // Pinky

  // Step 900: Fingers [103, 160, 133, 92, 145] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(160); // Index
  servo[2].write(133); // Middle
  servo[3].write(92); // Ring
  servo[4].write(145); // Pinky

  delay(15);
  // Step 901: Fingers [103, 160, 133, 92, 145] Arm [-, -, -]
  servo[0].write(103); // Thumb
  servo[1].write(160); // Index
  servo[2].write(133); // Middle
  servo[3].write(92); // Ring
  servo[4].write(145); // Pinky

  // Step 902: Fingers [101, 159, 135, 92, 143] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(159); // Index
  servo[2].write(135); // Middle
  servo[3].write(92); // Ring
  servo[4].write(143); // Pinky

  // Step 903: Fingers [101, 159, 134, 92, 142] Arm [-, -, -]
  servo[0].write(101); // Thumb
  servo[1].write(159); // Index
  servo[2].write(134); // Middle
  servo[3].write(92); // Ring
  servo[4].write(142); // Pinky

  // Step 904: Fingers [99, 158, 136, 91, 140] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(158); // Index
  servo[2].write(136); // Middle
  servo[3].write(91); // Ring
  servo[4].write(140); // Pinky

  delay(17);
  // Step 905: Fingers [99, 158, 136, 91, 140] Arm [-, -, -]
  servo[0].write(99); // Thumb
  servo[1].write(158); // Index
  servo[2].write(136); // Middle
  servo[3].write(91); // Ring
  servo[4].write(140); // Pinky

  // Step 906: Fingers [98, 156, 138, 91, 138] Arm [-, -, -]
  servo[0].write(98); // Thumb
  servo[1].write(156); // Index
  servo[2].write(138); // Middle
  servo[3].write(91); // Ring
  servo[4].write(138); // Pinky

  // Step 907: Fingers [96, 155, 140, 91, 136] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(155); // Index
  servo[2].write(140); // Middle
  servo[3].write(91); // Ring
  servo[4].write(136); // Pinky

  // Step 908: Fingers [96, 154, 140, 91, 135] Arm [-, -, -]
  servo[0].write(96); // Thumb
  servo[1].write(154); // Index
  servo[2].write(140); // Middle
  servo[3].write(91); // Ring
  servo[4].write(135); // Pinky

  // Step 909: Fingers [94, 152, 141, 90, 133] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(152); // Index
  servo[2].write(141); // Middle
  servo[3].write(90); // Ring
  servo[4].write(133); // Pinky

  // Step 910: Fingers [94, 152, 141, 90, 133] Arm [-, -, -]
  servo[0].write(94); // Thumb
  servo[1].write(152); // Index
  servo[2].write(141); // Middle
  servo[3].write(90); // Ring
  servo[4].write(133); // Pinky

  // Step 911: Fingers [93, 150, 143, 90, 130] Arm [-, -, -]
  servo[0].write(93); // Thumb
  servo[1].write(150); // Index
  servo[2].write(143); // Middle
  servo[3].write(90); // Ring
  servo[4].write(130); // Pinky

  // Step 912: Fingers [92, 149, 145, 91, 128] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(149); // Index
  servo[2].write(145); // Middle
  servo[3].write(91); // Ring
  servo[4].write(128); // Pinky

  // Step 913: Fingers [92, 148, 145, 90, 127] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(148); // Index
  servo[2].write(145); // Middle
  servo[3].write(90); // Ring
  servo[4].write(127); // Pinky

  delay(15);
  // Step 914: Fingers [92, 148, 145, 90, 127] Arm [-, -, -]
  servo[0].write(92); // Thumb
  servo[1].write(148); // Index
  servo[2].write(145); // Middle
  servo[3].write(90); // Ring
  servo[4].write(127); // Pinky

  // Step 915: Fingers [91, 146, 146, 91, 125] Arm [-, -, -]
  servo[0].write(91); // Thumb
  servo[1].write(146); // Index
  servo[2].write(146); // Middle
  servo[3].write(91); // Ring
  servo[4].write(125); // Pinky

  // Step 916: Fingers [90, 146, 146, 90, 124] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(146); // Index
  servo[2].write(146); // Middle
  servo[3].write(90); // Ring
  servo[4].write(124); // Pinky

  delay(15);
  // Step 917: Fingers [90, 144, 147, 91, 122] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(144); // Index
  servo[2].write(147); // Middle
  servo[3].write(91); // Ring
  servo[4].write(122); // Pinky

  // Step 918: Fingers [90, 144, 147, 91, 122] Arm [-, -, -]
  servo[0].write(90); // Thumb
  servo[1].write(144); // Index
  servo[2].write(147); // Middle
  servo[3].write(91); // Ring
  servo[4].write(122); // Pinky

  // Step 919: Fingers [89, 143, 147, 90, 122] Arm [-, -, -]
  servo[0].write(89); // Thumb
  servo[1].write(143); // Index
  servo[2].write(147); // Middle
  servo[3].write(90); // Ring
  servo[4].write(122); // Pinky

  delay(15);
  // Step 920: Fingers [88, 141, 148, 91, 119] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(141); // Index
  servo[2].write(148); // Middle
  servo[3].write(91); // Ring
  servo[4].write(119); // Pinky

  // Step 921: Fingers [88, 141, 148, 91, 119] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(141); // Index
  servo[2].write(148); // Middle
  servo[3].write(91); // Ring
  servo[4].write(119); // Pinky

  // Step 922: Fingers [88, 139, 150, 92, 117] Arm [-, -, -]
  servo[0].write(88); // Thumb
  servo[1].write(139); // Index
  servo[2].write(150); // Middle
  servo[3].write(92); // Ring
  servo[4].write(117); // Pinky

  // Step 923: Fingers [87, 139, 149, 91, 116] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(139); // Index
  servo[2].write(149); // Middle
  servo[3].write(91); // Ring
  servo[4].write(116); // Pinky

  // Step 924: Fingers [87, 138, 149, 91, 116] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(138); // Index
  servo[2].write(149); // Middle
  servo[3].write(91); // Ring
  servo[4].write(116); // Pinky

  // Step 925: Fingers [87, 138, 149, 91, 116] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(138); // Index
  servo[2].write(149); // Middle
  servo[3].write(91); // Ring
  servo[4].write(116); // Pinky

  // Step 926: Fingers [87, 136, 150, 92, 114] Arm [-, -, -]
  servo[0].write(87); // Thumb
  servo[1].write(136); // Index
  servo[2].write(150); // Middle
  servo[3].write(92); // Ring
  servo[4].write(114); // Pinky

  // Step 927: Fingers [86, 136, 150, 92, 113] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(136); // Index
  servo[2].write(150); // Middle
  servo[3].write(92); // Ring
  servo[4].write(113); // Pinky

  delay(14);
  // Step 928: Fingers [86, 136, 150, 92, 113] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(136); // Index
  servo[2].write(150); // Middle
  servo[3].write(92); // Ring
  servo[4].write(113); // Pinky

  // Step 929: Fingers [86, 133, 151, 93, 111] Arm [-, -, -]
  servo[0].write(86); // Thumb
  servo[1].write(133); // Index
  servo[2].write(151); // Middle
  servo[3].write(93); // Ring
  servo[4].write(111); // Pinky

  delay(11);
  // Step 930: Fingers [85, 133, 150, 92, 110] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(133); // Index
  servo[2].write(150); // Middle
  servo[3].write(92); // Ring
  servo[4].write(110); // Pinky

  // Step 931: Fingers [85, 130, 151, 93, 108] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(130); // Index
  servo[2].write(151); // Middle
  servo[3].write(93); // Ring
  servo[4].write(108); // Pinky

  // Step 932: Fingers [85, 130, 151, 93, 108] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(130); // Index
  servo[2].write(151); // Middle
  servo[3].write(93); // Ring
  servo[4].write(108); // Pinky

  delay(13);
  // Step 933: Fingers [85, 128, 152, 95, 106] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(128); // Index
  servo[2].write(152); // Middle
  servo[3].write(95); // Ring
  servo[4].write(106); // Pinky

  delay(16);
  // Step 934: Fingers [85, 128, 152, 95, 106] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(128); // Index
  servo[2].write(152); // Middle
  servo[3].write(95); // Ring
  servo[4].write(106); // Pinky

  // Step 935: Fingers [85, 128, 152, 94, 105] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(128); // Index
  servo[2].write(152); // Middle
  servo[3].write(94); // Ring
  servo[4].write(105); // Pinky

  delay(26);
  // Step 936: Fingers [85, 128, 152, 94, 105] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(128); // Index
  servo[2].write(152); // Middle
  servo[3].write(94); // Ring
  servo[4].write(105); // Pinky

  // Step 937: Fingers [85, 125, 153, 95, 103] Arm [-, -, -]
  servo[0].write(85); // Thumb
  servo[1].write(125); // Index
  servo[2].write(153); // Middle
  servo[3].write(95); // Ring
  servo[4].write(103); // Pinky

  delay(19);
  // Step 938: Fingers [84, 124, 152, 95, 103] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(124); // Index
  servo[2].write(152); // Middle
  servo[3].write(95); // Ring
  servo[4].write(103); // Pinky

  delay(11);
  // Step 939: Fingers [84, 124, 152, 95, 103] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(124); // Index
  servo[2].write(152); // Middle
  servo[3].write(95); // Ring
  servo[4].write(103); // Pinky

  // Step 940: Fingers [84, 124, 152, 94, 102] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(124); // Index
  servo[2].write(152); // Middle
  servo[3].write(94); // Ring
  servo[4].write(102); // Pinky

  delay(21);
  // Step 941: Fingers [84, 124, 152, 94, 102] Arm [-, -, -]
  servo[0].write(84); // Thumb
  servo[1].write(124); // Index
  servo[2].write(152); // Middle
  servo[3].write(94); // Ring
  servo[4].write(102); // Pinky

  // Step 942: Fingers [83, 124, 151, 94, 102] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(124); // Index
  servo[2].write(151); // Middle
  servo[3].write(94); // Ring
  servo[4].write(102); // Pinky

  // Step 943: Fingers [83, 123, 151, 94, 101] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(123); // Index
  servo[2].write(151); // Middle
  servo[3].write(94); // Ring
  servo[4].write(101); // Pinky

  delay(17);
  // Step 944: Fingers [83, 123, 151, 94, 101] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(123); // Index
  servo[2].write(151); // Middle
  servo[3].write(94); // Ring
  servo[4].write(101); // Pinky

  // Step 945: Fingers [83, 123, 150, 93, 101] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(123); // Index
  servo[2].write(150); // Middle
  servo[3].write(93); // Ring
  servo[4].write(101); // Pinky

  // Step 946: Fingers [83, 120, 151, 94, 99] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(120); // Index
  servo[2].write(151); // Middle
  servo[3].write(94); // Ring
  servo[4].write(99); // Pinky

  delay(14);
  // Step 947: Fingers [82, 120, 151, 94, 98] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(120); // Index
  servo[2].write(151); // Middle
  servo[3].write(94); // Ring
  servo[4].write(98); // Pinky

  // Step 948: Fingers [82, 120, 151, 94, 98] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(120); // Index
  servo[2].write(151); // Middle
  servo[3].write(94); // Ring
  servo[4].write(98); // Pinky

  // Step 949: Fingers [82, 119, 150, 94, 98] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(119); // Index
  servo[2].write(150); // Middle
  servo[3].write(94); // Ring
  servo[4].write(98); // Pinky

  // Step 950: Fingers [81, 119, 150, 93, 97] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(119); // Index
  servo[2].write(150); // Middle
  servo[3].write(93); // Ring
  servo[4].write(97); // Pinky

  delay(14);
  // Step 951: Fingers [81, 118, 149, 93, 97] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(118); // Index
  servo[2].write(149); // Middle
  servo[3].write(93); // Ring
  servo[4].write(97); // Pinky

  // Step 952: Fingers [81, 118, 149, 93, 97] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(118); // Index
  servo[2].write(149); // Middle
  servo[3].write(93); // Ring
  servo[4].write(97); // Pinky

  // Step 953: Fingers [80, 118, 149, 92, 96] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(118); // Index
  servo[2].write(149); // Middle
  servo[3].write(92); // Ring
  servo[4].write(96); // Pinky

  // Step 954: Fingers [81, 115, 149, 94, 94] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(115); // Index
  servo[2].write(149); // Middle
  servo[3].write(94); // Ring
  servo[4].write(94); // Pinky

  // Step 955: Fingers [80, 115, 149, 93, 94] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(115); // Index
  servo[2].write(149); // Middle
  servo[3].write(93); // Ring
  servo[4].write(94); // Pinky

  // Step 956: Fingers [80, 115, 149, 93, 94] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(115); // Index
  servo[2].write(149); // Middle
  servo[3].write(93); // Ring
  servo[4].write(94); // Pinky

  delay(15);
  // Step 957: Fingers [80, 114, 148, 93, 93] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(114); // Index
  servo[2].write(148); // Middle
  servo[3].write(93); // Ring
  servo[4].write(93); // Pinky

  delay(18);
  // Step 958: Fingers [80, 114, 148, 93, 93] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(114); // Index
  servo[2].write(148); // Middle
  servo[3].write(93); // Ring
  servo[4].write(93); // Pinky

  // Step 959: Fingers [79, 114, 148, 92, 93] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(114); // Index
  servo[2].write(148); // Middle
  servo[3].write(92); // Ring
  servo[4].write(93); // Pinky

  // Step 960: Fingers [80, 111, 148, 94, 91] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(111); // Index
  servo[2].write(148); // Middle
  servo[3].write(94); // Ring
  servo[4].write(91); // Pinky

  // Step 961: Fingers [79, 111, 148, 93, 90] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(111); // Index
  servo[2].write(148); // Middle
  servo[3].write(93); // Ring
  servo[4].write(90); // Pinky

  delay(14);
  // Step 962: Fingers [79, 111, 148, 93, 90] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(111); // Index
  servo[2].write(148); // Middle
  servo[3].write(93); // Ring
  servo[4].write(90); // Pinky

  // Step 963: Fingers [79, 111, 147, 93, 90] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(111); // Index
  servo[2].write(147); // Middle
  servo[3].write(93); // Ring
  servo[4].write(90); // Pinky

  delay(16);
  // Step 964: Fingers [78, 110, 147, 92, 89] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(110); // Index
  servo[2].write(147); // Middle
  servo[3].write(92); // Ring
  servo[4].write(89); // Pinky

  // Step 965: Fingers [78, 110, 147, 92, 89] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(110); // Index
  servo[2].write(147); // Middle
  servo[3].write(92); // Ring
  servo[4].write(89); // Pinky

  // Step 966: Fingers [78, 110, 146, 92, 89] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(110); // Index
  servo[2].write(146); // Middle
  servo[3].write(92); // Ring
  servo[4].write(89); // Pinky

  // Step 967: Fingers [79, 107, 147, 94, 87] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(107); // Index
  servo[2].write(147); // Middle
  servo[3].write(94); // Ring
  servo[4].write(87); // Pinky

  // Step 968: Fingers [78, 107, 146, 94, 87] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(107); // Index
  servo[2].write(146); // Middle
  servo[3].write(94); // Ring
  servo[4].write(87); // Pinky

  // Step 969: Fingers [78, 107, 146, 94, 87] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(107); // Index
  servo[2].write(146); // Middle
  servo[3].write(94); // Ring
  servo[4].write(87); // Pinky

  delay(20);
  // Step 970: Fingers [78, 106, 146, 93, 86] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(106); // Index
  servo[2].write(146); // Middle
  servo[3].write(93); // Ring
  servo[4].write(86); // Pinky

  // Step 971: Fingers [77, 106, 145, 92, 86] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(106); // Index
  servo[2].write(145); // Middle
  servo[3].write(92); // Ring
  servo[4].write(86); // Pinky

  // Step 972: Fingers [77, 106, 145, 92, 86] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(106); // Index
  servo[2].write(145); // Middle
  servo[3].write(92); // Ring
  servo[4].write(86); // Pinky

  // Step 973: Fingers [77, 105, 145, 92, 85] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(105); // Index
  servo[2].write(145); // Middle
  servo[3].write(92); // Ring
  servo[4].write(85); // Pinky

  // Step 974: Fingers [77, 103, 145, 93, 83] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(103); // Index
  servo[2].write(145); // Middle
  servo[3].write(93); // Ring
  servo[4].write(83); // Pinky

  // Step 975: Fingers [77, 102, 144, 93, 83] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(102); // Index
  servo[2].write(144); // Middle
  servo[3].write(93); // Ring
  servo[4].write(83); // Pinky

  // Step 976: Fingers [77, 102, 144, 93, 83] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(102); // Index
  servo[2].write(144); // Middle
  servo[3].write(93); // Ring
  servo[4].write(83); // Pinky

  // Step 977: Fingers [77, 99, 144, 94, 80] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(99); // Index
  servo[2].write(144); // Middle
  servo[3].write(94); // Ring
  servo[4].write(80); // Pinky

  // Step 978: Fingers [77, 99, 143, 94, 80] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(99); // Index
  servo[2].write(143); // Middle
  servo[3].write(94); // Ring
  servo[4].write(80); // Pinky

  // Step 979: Fingers [76, 98, 143, 93, 79] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(98); // Index
  servo[2].write(143); // Middle
  servo[3].write(93); // Ring
  servo[4].write(79); // Pinky

  // Step 980: Fingers [76, 98, 142, 93, 79] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(98); // Index
  servo[2].write(142); // Middle
  servo[3].write(93); // Ring
  servo[4].write(79); // Pinky

  // Step 981: Fingers [76, 98, 142, 93, 79] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(98); // Index
  servo[2].write(142); // Middle
  servo[3].write(93); // Ring
  servo[4].write(79); // Pinky

  // Step 982: Fingers [75, 98, 142, 92, 79] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(98); // Index
  servo[2].write(142); // Middle
  servo[3].write(92); // Ring
  servo[4].write(79); // Pinky

  // Step 983: Fingers [75, 97, 142, 92, 78] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(97); // Index
  servo[2].write(142); // Middle
  servo[3].write(92); // Ring
  servo[4].write(78); // Pinky

  // Step 984: Fingers [75, 97, 141, 92, 78] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(97); // Index
  servo[2].write(141); // Middle
  servo[3].write(92); // Ring
  servo[4].write(78); // Pinky

  delay(16);
  // Step 985: Fingers [75, 97, 141, 92, 78] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(97); // Index
  servo[2].write(141); // Middle
  servo[3].write(92); // Ring
  servo[4].write(78); // Pinky

  // Step 986: Fingers [74, 96, 140, 91, 77] Arm [-, -, -]
  servo[0].write(74); // Thumb
  servo[1].write(96); // Index
  servo[2].write(140); // Middle
  servo[3].write(91); // Ring
  servo[4].write(77); // Pinky

  delay(12);
  // Step 987: Fingers [75, 93, 140, 92, 75] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(93); // Index
  servo[2].write(140); // Middle
  servo[3].write(92); // Ring
  servo[4].write(75); // Pinky

  // Step 988: Fingers [74, 93, 140, 92, 75] Arm [-, -, -]
  servo[0].write(74); // Thumb
  servo[1].write(93); // Index
  servo[2].write(140); // Middle
  servo[3].write(92); // Ring
  servo[4].write(75); // Pinky

  // Step 989: Fingers [74, 93, 140, 92, 75] Arm [-, -, -]
  servo[0].write(74); // Thumb
  servo[1].write(93); // Index
  servo[2].write(140); // Middle
  servo[3].write(92); // Ring
  servo[4].write(75); // Pinky

  // Step 990: Fingers [74, 92, 139, 92, 74] Arm [-, -, -]
  servo[0].write(74); // Thumb
  servo[1].write(92); // Index
  servo[2].write(139); // Middle
  servo[3].write(92); // Ring
  servo[4].write(74); // Pinky

  // Step 991: Fingers [73, 92, 139, 91, 74] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(92); // Index
  servo[2].write(139); // Middle
  servo[3].write(91); // Ring
  servo[4].write(74); // Pinky

  // Step 992: Fingers [73, 92, 138, 91, 73] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(92); // Index
  servo[2].write(138); // Middle
  servo[3].write(91); // Ring
  servo[4].write(73); // Pinky

  // Step 993: Fingers [72, 91, 138, 90, 73] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(91); // Index
  servo[2].write(138); // Middle
  servo[3].write(90); // Ring
  servo[4].write(73); // Pinky

  // Step 994: Fingers [72, 91, 138, 90, 73] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(91); // Index
  servo[2].write(138); // Middle
  servo[3].write(90); // Ring
  servo[4].write(73); // Pinky

  // Step 995: Fingers [72, 91, 137, 90, 73] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(91); // Index
  servo[2].write(137); // Middle
  servo[3].write(90); // Ring
  servo[4].write(73); // Pinky

  // Step 996: Fingers [73, 88, 137, 92, 71] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(88); // Index
  servo[2].write(137); // Middle
  servo[3].write(92); // Ring
  servo[4].write(71); // Pinky

  // Step 997: Fingers [72, 88, 137, 91, 70] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(88); // Index
  servo[2].write(137); // Middle
  servo[3].write(91); // Ring
  servo[4].write(70); // Pinky

  // Step 998: Fingers [72, 87, 136, 90, 70] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(87); // Index
  servo[2].write(136); // Middle
  servo[3].write(90); // Ring
  servo[4].write(70); // Pinky

  // Step 999: Fingers [72, 87, 136, 90, 70] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(87); // Index
  servo[2].write(136); // Middle
  servo[3].write(90); // Ring
  servo[4].write(70); // Pinky

  // Step 1000: Fingers [73, 84, 135, 92, 68] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(84); // Index
  servo[2].write(135); // Middle
  servo[3].write(92); // Ring
  servo[4].write(68); // Pinky

  // Step 1001: Fingers [72, 84, 135, 92, 68] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(84); // Index
  servo[2].write(135); // Middle
  servo[3].write(92); // Ring
  servo[4].write(68); // Pinky

  // Step 1002: Fingers [72, 84, 134, 91, 67] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(84); // Index
  servo[2].write(134); // Middle
  servo[3].write(91); // Ring
  servo[4].write(67); // Pinky

  // Step 1003: Fingers [71, 83, 134, 91, 67] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(83); // Index
  servo[2].write(134); // Middle
  servo[3].write(91); // Ring
  servo[4].write(67); // Pinky

  // Step 1004: Fingers [71, 83, 134, 91, 67] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(83); // Index
  servo[2].write(134); // Middle
  servo[3].write(91); // Ring
  servo[4].write(67); // Pinky

  // Step 1005: Fingers [71, 83, 133, 90, 66] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(83); // Index
  servo[2].write(133); // Middle
  servo[3].write(90); // Ring
  servo[4].write(66); // Pinky

  // Step 1006: Fingers [71, 82, 133, 90, 66] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(82); // Index
  servo[2].write(133); // Middle
  servo[3].write(90); // Ring
  servo[4].write(66); // Pinky

  // Step 1007: Fingers [70, 82, 133, 89, 65] Arm [-, -, -]
  servo[0].write(70); // Thumb
  servo[1].write(82); // Index
  servo[2].write(133); // Middle
  servo[3].write(89); // Ring
  servo[4].write(65); // Pinky

  // Step 1008: Fingers [71, 79, 132, 91, 64] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(79); // Index
  servo[2].write(132); // Middle
  servo[3].write(91); // Ring
  servo[4].write(64); // Pinky

  // Step 1009: Fingers [71, 79, 132, 91, 64] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(79); // Index
  servo[2].write(132); // Middle
  servo[3].write(91); // Ring
  servo[4].write(64); // Pinky

  // Step 1010: Fingers [71, 79, 131, 91, 64] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(79); // Index
  servo[2].write(131); // Middle
  servo[3].write(91); // Ring
  servo[4].write(64); // Pinky

  // Step 1011: Fingers [70, 79, 131, 90, 63] Arm [-, -, -]
  servo[0].write(70); // Thumb
  servo[1].write(79); // Index
  servo[2].write(131); // Middle
  servo[3].write(90); // Ring
  servo[4].write(63); // Pinky

  // Step 1012: Fingers [70, 78, 130, 90, 62] Arm [-, -, -]
  servo[0].write(70); // Thumb
  servo[1].write(78); // Index
  servo[2].write(130); // Middle
  servo[3].write(90); // Ring
  servo[4].write(62); // Pinky

  // Step 1013: Fingers [71, 75, 129, 91, 61] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(75); // Index
  servo[2].write(129); // Middle
  servo[3].write(91); // Ring
  servo[4].write(61); // Pinky

  // Step 1014: Fingers [71, 75, 129, 91, 61] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(75); // Index
  servo[2].write(129); // Middle
  servo[3].write(91); // Ring
  servo[4].write(61); // Pinky

  // Step 1015: Fingers [70, 75, 129, 91, 61] Arm [-, -, -]
  servo[0].write(70); // Thumb
  servo[1].write(75); // Index
  servo[2].write(129); // Middle
  servo[3].write(91); // Ring
  servo[4].write(61); // Pinky

  // Step 1016: Fingers [69, 74, 128, 90, 60] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(74); // Index
  servo[2].write(128); // Middle
  servo[3].write(90); // Ring
  servo[4].write(60); // Pinky

  // Step 1017: Fingers [69, 73, 127, 89, 59] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(73); // Index
  servo[2].write(127); // Middle
  servo[3].write(89); // Ring
  servo[4].write(59); // Pinky

  // Step 1018: Fingers [69, 73, 127, 89, 59] Arm [-, -, -]
  servo[0].write(69); // Thumb
  servo[1].write(73); // Index
  servo[2].write(127); // Middle
  servo[3].write(89); // Ring
  servo[4].write(59); // Pinky

  // Step 1019: Fingers [70, 71, 126, 91, 58] Arm [-, -, -]
  servo[0].write(70); // Thumb
  servo[1].write(71); // Index
  servo[2].write(126); // Middle
  servo[3].write(91); // Ring
  servo[4].write(58); // Pinky

  // Step 1020: Fingers [70, 71, 126, 91, 57] Arm [-, -, -]
  servo[0].write(70); // Thumb
  servo[1].write(71); // Index
  servo[2].write(126); // Middle
  servo[3].write(91); // Ring
  servo[4].write(57); // Pinky

  // Step 1021: Fingers [68, 69, 124, 89, 56] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(69); // Index
  servo[2].write(124); // Middle
  servo[3].write(89); // Ring
  servo[4].write(56); // Pinky

  delay(17);
  // Step 1022: Fingers [68, 69, 124, 89, 56] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(69); // Index
  servo[2].write(124); // Middle
  servo[3].write(89); // Ring
  servo[4].write(56); // Pinky

  // Step 1023: Fingers [68, 69, 124, 89, 55] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(69); // Index
  servo[2].write(124); // Middle
  servo[3].write(89); // Ring
  servo[4].write(55); // Pinky

  // Step 1024: Fingers [67, 68, 123, 88, 55] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(68); // Index
  servo[2].write(123); // Middle
  servo[3].write(88); // Ring
  servo[4].write(55); // Pinky

  delay(13);
  // Step 1025: Fingers [68, 66, 122, 90, 54] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(66); // Index
  servo[2].write(122); // Middle
  servo[3].write(90); // Ring
  servo[4].write(54); // Pinky

  // Step 1026: Fingers [68, 66, 122, 90, 54] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(66); // Index
  servo[2].write(122); // Middle
  servo[3].write(90); // Ring
  servo[4].write(54); // Pinky

  // Step 1027: Fingers [68, 65, 122, 89, 53] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(65); // Index
  servo[2].write(122); // Middle
  servo[3].write(89); // Ring
  servo[4].write(53); // Pinky

  // Step 1028: Fingers [67, 65, 121, 89, 52] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(65); // Index
  servo[2].write(121); // Middle
  servo[3].write(89); // Ring
  servo[4].write(52); // Pinky

  // Step 1029: Fingers [67, 64, 120, 88, 52] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(64); // Index
  servo[2].write(120); // Middle
  servo[3].write(88); // Ring
  servo[4].write(52); // Pinky

  // Step 1030: Fingers [66, 64, 120, 88, 51] Arm [-, -, -]
  servo[0].write(66); // Thumb
  servo[1].write(64); // Index
  servo[2].write(120); // Middle
  servo[3].write(88); // Ring
  servo[4].write(51); // Pinky

  // Step 1031: Fingers [66, 64, 120, 88, 51] Arm [-, -, -]
  servo[0].write(66); // Thumb
  servo[1].write(64); // Index
  servo[2].write(120); // Middle
  servo[3].write(88); // Ring
  servo[4].write(51); // Pinky

  // Step 1032: Fingers [68, 62, 119, 90, 51] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(62); // Index
  servo[2].write(119); // Middle
  servo[3].write(90); // Ring
  servo[4].write(51); // Pinky

  // Step 1033: Fingers [67, 61, 118, 89, 50] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(61); // Index
  servo[2].write(118); // Middle
  servo[3].write(89); // Ring
  servo[4].write(50); // Pinky

  // Step 1034: Fingers [66, 60, 117, 88, 49] Arm [-, -, -]
  servo[0].write(66); // Thumb
  servo[1].write(60); // Index
  servo[2].write(117); // Middle
  servo[3].write(88); // Ring
  servo[4].write(49); // Pinky

  delay(14);
  // Step 1035: Fingers [66, 60, 117, 88, 49] Arm [-, -, -]
  servo[0].write(66); // Thumb
  servo[1].write(60); // Index
  servo[2].write(117); // Middle
  servo[3].write(88); // Ring
  servo[4].write(49); // Pinky

  // Step 1036: Fingers [66, 59, 116, 87, 48] Arm [-, -, -]
  servo[0].write(66); // Thumb
  servo[1].write(59); // Index
  servo[2].write(116); // Middle
  servo[3].write(87); // Ring
  servo[4].write(48); // Pinky

  // Step 1037: Fingers [65, 59, 116, 87, 48] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(59); // Index
  servo[2].write(116); // Middle
  servo[3].write(87); // Ring
  servo[4].write(48); // Pinky

  // Step 1038: Fingers [64, 58, 115, 86, 47] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(58); // Index
  servo[2].write(115); // Middle
  servo[3].write(86); // Ring
  servo[4].write(47); // Pinky

  delay(16);
  // Step 1039: Fingers [64, 58, 115, 86, 47] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(58); // Index
  servo[2].write(115); // Middle
  servo[3].write(86); // Ring
  servo[4].write(47); // Pinky

  // Step 1040: Fingers [63, 57, 114, 85, 46] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(57); // Index
  servo[2].write(114); // Middle
  servo[3].write(85); // Ring
  servo[4].write(46); // Pinky

  // Step 1041: Fingers [65, 56, 113, 87, 46] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(56); // Index
  servo[2].write(113); // Middle
  servo[3].write(87); // Ring
  servo[4].write(46); // Pinky

  // Step 1042: Fingers [65, 55, 113, 87, 45] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(55); // Index
  servo[2].write(113); // Middle
  servo[3].write(87); // Ring
  servo[4].write(45); // Pinky

  // Step 1043: Fingers [64, 54, 112, 86, 45] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(54); // Index
  servo[2].write(112); // Middle
  servo[3].write(86); // Ring
  servo[4].write(45); // Pinky

  // Step 1044: Fingers [64, 54, 112, 86, 45] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(54); // Index
  servo[2].write(112); // Middle
  servo[3].write(86); // Ring
  servo[4].write(45); // Pinky

  // Step 1045: Fingers [64, 54, 112, 86, 44] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(54); // Index
  servo[2].write(112); // Middle
  servo[3].write(86); // Ring
  servo[4].write(44); // Pinky

  // Step 1046: Fingers [63, 54, 111, 85, 44] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(54); // Index
  servo[2].write(111); // Middle
  servo[3].write(85); // Ring
  servo[4].write(44); // Pinky

  // Step 1047: Fingers [63, 53, 111, 85, 43] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(53); // Index
  servo[2].write(111); // Middle
  servo[3].write(85); // Ring
  servo[4].write(43); // Pinky

  // Step 1048: Fingers [63, 53, 111, 85, 43] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(53); // Index
  servo[2].write(111); // Middle
  servo[3].write(85); // Ring
  servo[4].write(43); // Pinky

  // Step 1049: Fingers [62, 53, 110, 84, 43] Arm [-, -, -]
  servo[0].write(62); // Thumb
  servo[1].write(53); // Index
  servo[2].write(110); // Middle
  servo[3].write(84); // Ring
  servo[4].write(43); // Pinky

  // Step 1050: Fingers [62, 52, 110, 84, 42] Arm [-, -, -]
  servo[0].write(62); // Thumb
  servo[1].write(52); // Index
  servo[2].write(110); // Middle
  servo[3].write(84); // Ring
  servo[4].write(42); // Pinky

  // Step 1051: Fingers [62, 52, 109, 84, 42] Arm [-, -, -]
  servo[0].write(62); // Thumb
  servo[1].write(52); // Index
  servo[2].write(109); // Middle
  servo[3].write(84); // Ring
  servo[4].write(42); // Pinky

  // Step 1052: Fingers [61, 51, 109, 83, 41] Arm [-, -, -]
  servo[0].write(61); // Thumb
  servo[1].write(51); // Index
  servo[2].write(109); // Middle
  servo[3].write(83); // Ring
  servo[4].write(41); // Pinky

  // Step 1053: Fingers [61, 51, 109, 83, 41] Arm [-, -, -]
  servo[0].write(61); // Thumb
  servo[1].write(51); // Index
  servo[2].write(109); // Middle
  servo[3].write(83); // Ring
  servo[4].write(41); // Pinky

  // Step 1054: Fingers [60, 51, 108, 82, 41] Arm [-, -, -]
  servo[0].write(60); // Thumb
  servo[1].write(51); // Index
  servo[2].write(108); // Middle
  servo[3].write(82); // Ring
  servo[4].write(41); // Pinky

  // Step 1055: Fingers [60, 50, 108, 82, 40] Arm [-, -, -]
  servo[0].write(60); // Thumb
  servo[1].write(50); // Index
  servo[2].write(108); // Middle
  servo[3].write(82); // Ring
  servo[4].write(40); // Pinky

  delay(13);
  // Step 1056: Fingers [60, 50, 108, 82, 40] Arm [-, -, -]
  servo[0].write(60); // Thumb
  servo[1].write(50); // Index
  servo[2].write(108); // Middle
  servo[3].write(82); // Ring
  servo[4].write(40); // Pinky

  // Step 1057: Fingers [59, 49, 107, 81, 39] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(49); // Index
  servo[2].write(107); // Middle
  servo[3].write(81); // Ring
  servo[4].write(39); // Pinky

  // Step 1058: Fingers [57, 51, 108, 79, 40] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(51); // Index
  servo[2].write(108); // Middle
  servo[3].write(79); // Ring
  servo[4].write(40); // Pinky

  // Step 1059: Fingers [57, 50, 107, 78, 39] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(50); // Index
  servo[2].write(107); // Middle
  servo[3].write(78); // Ring
  servo[4].write(39); // Pinky

  // Step 1060: Fingers [57, 50, 107, 78, 39] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(50); // Index
  servo[2].write(107); // Middle
  servo[3].write(78); // Ring
  servo[4].write(39); // Pinky

  // Step 1061: Fingers [56, 50, 107, 78, 39] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(50); // Index
  servo[2].write(107); // Middle
  servo[3].write(78); // Ring
  servo[4].write(39); // Pinky

  // Step 1062: Fingers [56, 50, 107, 78, 39] Arm [-, -, -]
  servo[0].write(56); // Thumb
  servo[1].write(50); // Index
  servo[2].write(107); // Middle
  servo[3].write(78); // Ring
  servo[4].write(39); // Pinky

  // Step 1063: Fingers [54, 51, 107, 75, 39] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(51); // Index
  servo[2].write(107); // Middle
  servo[3].write(75); // Ring
  servo[4].write(39); // Pinky

  // Step 1064: Fingers [53, 51, 107, 75, 39] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(51); // Index
  servo[2].write(107); // Middle
  servo[3].write(75); // Ring
  servo[4].write(39); // Pinky

  // Step 1065: Fingers [53, 51, 107, 75, 39] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(51); // Index
  servo[2].write(107); // Middle
  servo[3].write(75); // Ring
  servo[4].write(39); // Pinky

  // Step 1066: Fingers [53, 50, 107, 75, 38] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(50); // Index
  servo[2].write(107); // Middle
  servo[3].write(75); // Ring
  servo[4].write(38); // Pinky

  // Step 1067: Fingers [51, 52, 107, 72, 38] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(52); // Index
  servo[2].write(107); // Middle
  servo[3].write(72); // Ring
  servo[4].write(38); // Pinky

  delay(16);
  // Step 1068: Fingers [51, 52, 107, 72, 38] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(52); // Index
  servo[2].write(107); // Middle
  servo[3].write(72); // Ring
  servo[4].write(38); // Pinky

  // Step 1069: Fingers [50, 51, 106, 71, 38] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(51); // Index
  servo[2].write(106); // Middle
  servo[3].write(71); // Ring
  servo[4].write(38); // Pinky

  // Step 1070: Fingers [49, 53, 107, 69, 39] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(53); // Index
  servo[2].write(107); // Middle
  servo[3].write(69); // Ring
  servo[4].write(39); // Pinky

  // Step 1071: Fingers [48, 53, 107, 69, 38] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(53); // Index
  servo[2].write(107); // Middle
  servo[3].write(69); // Ring
  servo[4].write(38); // Pinky

  // Step 1072: Fingers [48, 52, 106, 68, 38] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(52); // Index
  servo[2].write(106); // Middle
  servo[3].write(68); // Ring
  servo[4].write(38); // Pinky

  // Step 1073: Fingers [48, 52, 106, 68, 38] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(52); // Index
  servo[2].write(106); // Middle
  servo[3].write(68); // Ring
  servo[4].write(38); // Pinky

  // Step 1074: Fingers [47, 52, 106, 68, 38] Arm [-, -, -]
  servo[0].write(47); // Thumb
  servo[1].write(52); // Index
  servo[2].write(106); // Middle
  servo[3].write(68); // Ring
  servo[4].write(38); // Pinky

  // Step 1075: Fingers [47, 52, 105, 68, 37] Arm [-, -, -]
  servo[0].write(47); // Thumb
  servo[1].write(52); // Index
  servo[2].write(105); // Middle
  servo[3].write(68); // Ring
  servo[4].write(37); // Pinky

  // Step 1076: Fingers [45, 54, 106, 65, 38] Arm [-, -, -]
  servo[0].write(45); // Thumb
  servo[1].write(54); // Index
  servo[2].write(106); // Middle
  servo[3].write(65); // Ring
  servo[4].write(38); // Pinky

  // Step 1077: Fingers [44, 53, 105, 64, 37] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(53); // Index
  servo[2].write(105); // Middle
  servo[3].write(64); // Ring
  servo[4].write(37); // Pinky

  // Step 1078: Fingers [44, 53, 105, 64, 37] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(53); // Index
  servo[2].write(105); // Middle
  servo[3].write(64); // Ring
  servo[4].write(37); // Pinky

  // Step 1079: Fingers [42, 54, 105, 62, 38] Arm [-, -, -]
  servo[0].write(42); // Thumb
  servo[1].write(54); // Index
  servo[2].write(105); // Middle
  servo[3].write(62); // Ring
  servo[4].write(38); // Pinky

  // Step 1080: Fingers [41, 56, 105, 59, 39] Arm [-, -, -]
  servo[0].write(41); // Thumb
  servo[1].write(56); // Index
  servo[2].write(105); // Middle
  servo[3].write(59); // Ring
  servo[4].write(39); // Pinky

  // Step 1081: Fingers [40, 55, 104, 59, 38] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(55); // Index
  servo[2].write(104); // Middle
  servo[3].write(59); // Ring
  servo[4].write(38); // Pinky

  // Step 1082: Fingers [40, 55, 104, 59, 38] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(55); // Index
  servo[2].write(104); // Middle
  servo[3].write(59); // Ring
  servo[4].write(38); // Pinky

  // Step 1083: Fingers [40, 55, 104, 58, 38] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(55); // Index
  servo[2].write(104); // Middle
  servo[3].write(58); // Ring
  servo[4].write(38); // Pinky

  // Step 1084: Fingers [38, 57, 103, 56, 39] Arm [-, -, -]
  servo[0].write(38); // Thumb
  servo[1].write(57); // Index
  servo[2].write(103); // Middle
  servo[3].write(56); // Ring
  servo[4].write(39); // Pinky

  // Step 1085: Fingers [38, 56, 103, 55, 38] Arm [-, -, -]
  servo[0].write(38); // Thumb
  servo[1].write(56); // Index
  servo[2].write(103); // Middle
  servo[3].write(55); // Ring
  servo[4].write(38); // Pinky

  delay(14);
  // Step 1086: Fingers [38, 56, 103, 55, 38] Arm [-, -, -]
  servo[0].write(38); // Thumb
  servo[1].write(56); // Index
  servo[2].write(103); // Middle
  servo[3].write(55); // Ring
  servo[4].write(38); // Pinky

  // Step 1087: Fingers [37, 56, 103, 55, 38] Arm [-, -, -]
  servo[0].write(37); // Thumb
  servo[1].write(56); // Index
  servo[2].write(103); // Middle
  servo[3].write(55); // Ring
  servo[4].write(38); // Pinky

  // Step 1088: Fingers [35, 58, 102, 52, 39] Arm [-, -, -]
  servo[0].write(35); // Thumb
  servo[1].write(58); // Index
  servo[2].write(102); // Middle
  servo[3].write(52); // Ring
  servo[4].write(39); // Pinky

  // Step 1089: Fingers [34, 59, 101, 50, 40] Arm [-, -, -]
  servo[0].write(34); // Thumb
  servo[1].write(59); // Index
  servo[2].write(101); // Middle
  servo[3].write(50); // Ring
  servo[4].write(40); // Pinky

  // Step 1090: Fingers [33, 59, 101, 49, 39] Arm [-, -, -]
  servo[0].write(33); // Thumb
  servo[1].write(59); // Index
  servo[2].write(101); // Middle
  servo[3].write(49); // Ring
  servo[4].write(39); // Pinky

  // Step 1091: Fingers [33, 59, 101, 49, 39] Arm [-, -, -]
  servo[0].write(33); // Thumb
  servo[1].write(59); // Index
  servo[2].write(101); // Middle
  servo[3].write(49); // Ring
  servo[4].write(39); // Pinky

  // Step 1092: Fingers [32, 60, 100, 47, 40] Arm [-, -, -]
  servo[0].write(32); // Thumb
  servo[1].write(60); // Index
  servo[2].write(100); // Middle
  servo[3].write(47); // Ring
  servo[4].write(40); // Pinky

  // Step 1093: Fingers [30, 59, 98, 45, 39] Arm [-, -, -]
  servo[0].write(30); // Thumb
  servo[1].write(59); // Index
  servo[2].write(98); // Middle
  servo[3].write(45); // Ring
  servo[4].write(39); // Pinky

  // Step 1094: Fingers [29, 61, 97, 43, 40] Arm [-, -, -]
  servo[0].write(29); // Thumb
  servo[1].write(61); // Index
  servo[2].write(97); // Middle
  servo[3].write(43); // Ring
  servo[4].write(40); // Pinky

  // Step 1095: Fingers [29, 61, 97, 43, 40] Arm [-, -, -]
  servo[0].write(29); // Thumb
  servo[1].write(61); // Index
  servo[2].write(97); // Middle
  servo[3].write(43); // Ring
  servo[4].write(40); // Pinky

  // Step 1096: Fingers [29, 60, 97, 43, 40] Arm [-, -, -]
  servo[0].write(29); // Thumb
  servo[1].write(60); // Index
  servo[2].write(97); // Middle
  servo[3].write(43); // Ring
  servo[4].write(40); // Pinky

  // Step 1097: Fingers [27, 62, 96, 40, 41] Arm [-, -, -]
  servo[0].write(27); // Thumb
  servo[1].write(62); // Index
  servo[2].write(96); // Middle
  servo[3].write(40); // Ring
  servo[4].write(41); // Pinky

  // Step 1098: Fingers [27, 61, 95, 40, 40] Arm [-, -, -]
  servo[0].write(27); // Thumb
  servo[1].write(61); // Index
  servo[2].write(95); // Middle
  servo[3].write(40); // Ring
  servo[4].write(40); // Pinky

  // Step 1099: Fingers [27, 61, 95, 40, 40] Arm [-, -, -]
  servo[0].write(27); // Thumb
  servo[1].write(61); // Index
  servo[2].write(95); // Middle
  servo[3].write(40); // Ring
  servo[4].write(40); // Pinky

  // Step 1100: Fingers [26, 64, 94, 38, 42] Arm [-, -, -]
  servo[0].write(26); // Thumb
  servo[1].write(64); // Index
  servo[2].write(94); // Middle
  servo[3].write(38); // Ring
  servo[4].write(42); // Pinky

  // Step 1101: Fingers [25, 65, 93, 35, 43] Arm [-, -, -]
  servo[0].write(25); // Thumb
  servo[1].write(65); // Index
  servo[2].write(93); // Middle
  servo[3].write(35); // Ring
  servo[4].write(43); // Pinky

  // Step 1102: Fingers [24, 65, 92, 35, 43] Arm [-, -, -]
  servo[0].write(24); // Thumb
  servo[1].write(65); // Index
  servo[2].write(92); // Middle
  servo[3].write(35); // Ring
  servo[4].write(43); // Pinky

  // Step 1103: Fingers [23, 64, 91, 34, 42] Arm [-, -, -]
  servo[0].write(23); // Thumb
  servo[1].write(64); // Index
  servo[2].write(91); // Middle
  servo[3].write(34); // Ring
  servo[4].write(42); // Pinky

  // Step 1104: Fingers [23, 64, 91, 34, 42] Arm [-, -, -]
  servo[0].write(23); // Thumb
  servo[1].write(64); // Index
  servo[2].write(91); // Middle
  servo[3].write(34); // Ring
  servo[4].write(42); // Pinky

  // Step 1105: Fingers [23, 65, 90, 32, 43] Arm [-, -, -]
  servo[0].write(23); // Thumb
  servo[1].write(65); // Index
  servo[2].write(90); // Middle
  servo[3].write(32); // Ring
  servo[4].write(43); // Pinky

  // Step 1106: Fingers [22, 67, 88, 30, 45] Arm [-, -, -]
  servo[0].write(22); // Thumb
  servo[1].write(67); // Index
  servo[2].write(88); // Middle
  servo[3].write(30); // Ring
  servo[4].write(45); // Pinky

  delay(12);
  // Step 1107: Fingers [21, 66, 87, 29, 44] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(66); // Index
  servo[2].write(87); // Middle
  servo[3].write(29); // Ring
  servo[4].write(44); // Pinky

  // Step 1108: Fingers [21, 66, 87, 29, 44] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(66); // Index
  servo[2].write(87); // Middle
  servo[3].write(29); // Ring
  servo[4].write(44); // Pinky

  // Step 1109: Fingers [20, 68, 85, 27, 45] Arm [-, -, -]
  servo[0].write(20); // Thumb
  servo[1].write(68); // Index
  servo[2].write(85); // Middle
  servo[3].write(27); // Ring
  servo[4].write(45); // Pinky

  // Step 1110: Fingers [20, 67, 85, 27, 45] Arm [-, -, -]
  servo[0].write(20); // Thumb
  servo[1].write(67); // Index
  servo[2].write(85); // Middle
  servo[3].write(27); // Ring
  servo[4].write(45); // Pinky

  // Step 1111: Fingers [19, 67, 85, 26, 45] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(67); // Index
  servo[2].write(85); // Middle
  servo[3].write(26); // Ring
  servo[4].write(45); // Pinky

  // Step 1112: Fingers [19, 67, 85, 26, 45] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(67); // Index
  servo[2].write(85); // Middle
  servo[3].write(26); // Ring
  servo[4].write(45); // Pinky

  // Step 1113: Fingers [20, 69, 83, 25, 47] Arm [-, -, -]
  servo[0].write(20); // Thumb
  servo[1].write(69); // Index
  servo[2].write(83); // Middle
  servo[3].write(25); // Ring
  servo[4].write(47); // Pinky

  // Step 1114: Fingers [19, 68, 83, 25, 46] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(68); // Index
  servo[2].write(83); // Middle
  servo[3].write(25); // Ring
  servo[4].write(46); // Pinky

  delay(21);
  // Step 1115: Fingers [19, 68, 83, 25, 46] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(68); // Index
  servo[2].write(83); // Middle
  servo[3].write(25); // Ring
  servo[4].write(46); // Pinky

  // Step 1116: Fingers [19, 68, 82, 24, 46] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(68); // Index
  servo[2].write(82); // Middle
  servo[3].write(24); // Ring
  servo[4].write(46); // Pinky

  // Step 1117: Fingers [19, 70, 81, 23, 48] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(70); // Index
  servo[2].write(81); // Middle
  servo[3].write(23); // Ring
  servo[4].write(48); // Pinky

  delay(25);
  // Step 1118: Fingers [19, 70, 81, 23, 48] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(70); // Index
  servo[2].write(81); // Middle
  servo[3].write(23); // Ring
  servo[4].write(48); // Pinky

  // Step 1119: Fingers [19, 70, 80, 23, 48] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(70); // Index
  servo[2].write(80); // Middle
  servo[3].write(23); // Ring
  servo[4].write(48); // Pinky

  // Step 1120: Fingers [18, 69, 80, 22, 47] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(69); // Index
  servo[2].write(80); // Middle
  servo[3].write(22); // Ring
  servo[4].write(47); // Pinky

  delay(16);
  // Step 1121: Fingers [18, 69, 80, 22, 47] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(69); // Index
  servo[2].write(80); // Middle
  servo[3].write(22); // Ring
  servo[4].write(47); // Pinky

  // Step 1122: Fingers [18, 71, 78, 21, 49] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(71); // Index
  servo[2].write(78); // Middle
  servo[3].write(21); // Ring
  servo[4].write(49); // Pinky

  // Step 1123: Fingers [18, 71, 78, 21, 49] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(71); // Index
  servo[2].write(78); // Middle
  servo[3].write(21); // Ring
  servo[4].write(49); // Pinky

  delay(23);
  // Step 1124: Fingers [18, 71, 78, 21, 49] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(71); // Index
  servo[2].write(78); // Middle
  servo[3].write(21); // Ring
  servo[4].write(49); // Pinky

  // Step 1125: Fingers [18, 72, 76, 19, 51] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(72); // Index
  servo[2].write(76); // Middle
  servo[3].write(19); // Ring
  servo[4].write(51); // Pinky

  delay(17);
  // Step 1126: Fingers [19, 74, 74, 19, 53] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(74); // Index
  servo[2].write(74); // Middle
  servo[3].write(19); // Ring
  servo[4].write(53); // Pinky

  // Step 1127: Fingers [19, 74, 74, 19, 53] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(74); // Index
  servo[2].write(74); // Middle
  servo[3].write(19); // Ring
  servo[4].write(53); // Pinky

  delay(11);
  // Step 1128: Fingers [18, 74, 74, 18, 53] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(74); // Index
  servo[2].write(74); // Middle
  servo[3].write(18); // Ring
  servo[4].write(53); // Pinky

  // Step 1129: Fingers [18, 73, 73, 18, 52] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(73); // Index
  servo[2].write(73); // Middle
  servo[3].write(18); // Ring
  servo[4].write(52); // Pinky

  // Step 1130: Fingers [19, 75, 71, 17, 54] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(75); // Index
  servo[2].write(71); // Middle
  servo[3].write(17); // Ring
  servo[4].write(54); // Pinky

  // Step 1131: Fingers [18, 75, 71, 17, 54] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(75); // Index
  servo[2].write(71); // Middle
  servo[3].write(17); // Ring
  servo[4].write(54); // Pinky

  // Step 1132: Fingers [18, 75, 71, 17, 54] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(75); // Index
  servo[2].write(71); // Middle
  servo[3].write(17); // Ring
  servo[4].write(54); // Pinky

  delay(12);
  // Step 1133: Fingers [19, 76, 69, 16, 56] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(76); // Index
  servo[2].write(69); // Middle
  servo[3].write(16); // Ring
  servo[4].write(56); // Pinky

  delay(17);
  // Step 1134: Fingers [18, 75, 68, 15, 55] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(75); // Index
  servo[2].write(68); // Middle
  servo[3].write(15); // Ring
  servo[4].write(55); // Pinky

  // Step 1135: Fingers [18, 75, 68, 15, 55] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(75); // Index
  servo[2].write(68); // Middle
  servo[3].write(15); // Ring
  servo[4].write(55); // Pinky

  delay(15);
  // Step 1136: Fingers [19, 77, 66, 15, 57] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(77); // Index
  servo[2].write(66); // Middle
  servo[3].write(15); // Ring
  servo[4].write(57); // Pinky

  delay(15);
  // Step 1137: Fingers [19, 77, 66, 15, 57] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(77); // Index
  servo[2].write(66); // Middle
  servo[3].write(15); // Ring
  servo[4].write(57); // Pinky

  // Step 1138: Fingers [18, 76, 65, 14, 57] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(76); // Index
  servo[2].write(65); // Middle
  servo[3].write(14); // Ring
  servo[4].write(57); // Pinky

  // Step 1139: Fingers [19, 78, 63, 14, 59] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(78); // Index
  servo[2].write(63); // Middle
  servo[3].write(14); // Ring
  servo[4].write(59); // Pinky

  delay(15);
  // Step 1140: Fingers [19, 78, 63, 14, 59] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(78); // Index
  servo[2].write(63); // Middle
  servo[3].write(14); // Ring
  servo[4].write(59); // Pinky

  // Step 1141: Fingers [20, 79, 61, 14, 61] Arm [-, -, -]
  servo[0].write(20); // Thumb
  servo[1].write(79); // Index
  servo[2].write(61); // Middle
  servo[3].write(14); // Ring
  servo[4].write(61); // Pinky

  delay(22);
  // Step 1142: Fingers [20, 79, 61, 14, 61] Arm [-, -, -]
  servo[0].write(20); // Thumb
  servo[1].write(79); // Index
  servo[2].write(61); // Middle
  servo[3].write(14); // Ring
  servo[4].write(61); // Pinky

  // Step 1143: Fingers [20, 78, 60, 13, 60] Arm [-, -, -]
  servo[0].write(20); // Thumb
  servo[1].write(78); // Index
  servo[2].write(60); // Middle
  servo[3].write(13); // Ring
  servo[4].write(60); // Pinky

  // Step 1144: Fingers [21, 79, 58, 13, 62] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(79); // Index
  servo[2].write(58); // Middle
  servo[3].write(13); // Ring
  servo[4].write(62); // Pinky

  // Step 1145: Fingers [21, 79, 58, 13, 62] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(79); // Index
  servo[2].write(58); // Middle
  servo[3].write(13); // Ring
  servo[4].write(62); // Pinky

  delay(14);
  // Step 1146: Fingers [21, 79, 58, 13, 62] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(79); // Index
  servo[2].write(58); // Middle
  servo[3].write(13); // Ring
  servo[4].write(62); // Pinky

  delay(17);
  // Step 1147: Fingers [22, 80, 55, 13, 63] Arm [-, -, -]
  servo[0].write(22); // Thumb
  servo[1].write(80); // Index
  servo[2].write(55); // Middle
  servo[3].write(13); // Ring
  servo[4].write(63); // Pinky

  delay(12);
  // Step 1148: Fingers [22, 80, 55, 13, 63] Arm [-, -, -]
  servo[0].write(22); // Thumb
  servo[1].write(80); // Index
  servo[2].write(55); // Middle
  servo[3].write(13); // Ring
  servo[4].write(63); // Pinky

  // Step 1149: Fingers [21, 79, 55, 12, 63] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(79); // Index
  servo[2].write(55); // Middle
  servo[3].write(12); // Ring
  servo[4].write(63); // Pinky

  // Step 1150: Fingers [23, 80, 53, 12, 65] Arm [-, -, -]
  servo[0].write(23); // Thumb
  servo[1].write(80); // Index
  servo[2].write(53); // Middle
  servo[3].write(12); // Ring
  servo[4].write(65); // Pinky

  // Step 1151: Fingers [24, 81, 50, 12, 66] Arm [-, -, -]
  servo[0].write(24); // Thumb
  servo[1].write(81); // Index
  servo[2].write(50); // Middle
  servo[3].write(12); // Ring
  servo[4].write(66); // Pinky

  // Step 1152: Fingers [24, 81, 50, 12, 66] Arm [-, -, -]
  servo[0].write(24); // Thumb
  servo[1].write(81); // Index
  servo[2].write(50); // Middle
  servo[3].write(12); // Ring
  servo[4].write(66); // Pinky

  // Step 1153: Fingers [24, 80, 50, 12, 66] Arm [-, -, -]
  servo[0].write(24); // Thumb
  servo[1].write(80); // Index
  servo[2].write(50); // Middle
  servo[3].write(12); // Ring
  servo[4].write(66); // Pinky

  // Step 1154: Fingers [26, 81, 47, 13, 68] Arm [-, -, -]
  servo[0].write(26); // Thumb
  servo[1].write(81); // Index
  servo[2].write(47); // Middle
  servo[3].write(13); // Ring
  servo[4].write(68); // Pinky

  // Step 1155: Fingers [25, 81, 47, 12, 67] Arm [-, -, -]
  servo[0].write(25); // Thumb
  servo[1].write(81); // Index
  servo[2].write(47); // Middle
  servo[3].write(12); // Ring
  servo[4].write(67); // Pinky

  delay(16);
  // Step 1156: Fingers [25, 81, 47, 12, 67] Arm [-, -, -]
  servo[0].write(25); // Thumb
  servo[1].write(81); // Index
  servo[2].write(47); // Middle
  servo[3].write(12); // Ring
  servo[4].write(67); // Pinky

  // Step 1157: Fingers [27, 81, 45, 13, 69] Arm [-, -, -]
  servo[0].write(27); // Thumb
  servo[1].write(81); // Index
  servo[2].write(45); // Middle
  servo[3].write(13); // Ring
  servo[4].write(69); // Pinky

  // Step 1158: Fingers [27, 81, 44, 13, 69] Arm [-, -, -]
  servo[0].write(27); // Thumb
  servo[1].write(81); // Index
  servo[2].write(44); // Middle
  servo[3].write(13); // Ring
  servo[4].write(69); // Pinky

  delay(14);
  // Step 1159: Fingers [28, 81, 42, 13, 70] Arm [-, -, -]
  servo[0].write(28); // Thumb
  servo[1].write(81); // Index
  servo[2].write(42); // Middle
  servo[3].write(13); // Ring
  servo[4].write(70); // Pinky

  // Step 1160: Fingers [28, 81, 42, 13, 70] Arm [-, -, -]
  servo[0].write(28); // Thumb
  servo[1].write(81); // Index
  servo[2].write(42); // Middle
  servo[3].write(13); // Ring
  servo[4].write(70); // Pinky

  // Step 1161: Fingers [30, 81, 39, 14, 71] Arm [-, -, -]
  servo[0].write(30); // Thumb
  servo[1].write(81); // Index
  servo[2].write(39); // Middle
  servo[3].write(14); // Ring
  servo[4].write(71); // Pinky

  // Step 1162: Fingers [32, 81, 37, 15, 73] Arm [-, -, -]
  servo[0].write(32); // Thumb
  servo[1].write(81); // Index
  servo[2].write(37); // Middle
  servo[3].write(15); // Ring
  servo[4].write(73); // Pinky

  delay(23);
  // Step 1163: Fingers [32, 81, 37, 15, 73] Arm [-, -, -]
  servo[0].write(32); // Thumb
  servo[1].write(81); // Index
  servo[2].write(37); // Middle
  servo[3].write(15); // Ring
  servo[4].write(73); // Pinky

  // Step 1164: Fingers [35, 81, 32, 17, 75] Arm [-, -, -]
  servo[0].write(35); // Thumb
  servo[1].write(81); // Index
  servo[2].write(32); // Middle
  servo[3].write(17); // Ring
  servo[4].write(75); // Pinky

  // Step 1165: Fingers [38, 81, 30, 18, 76] Arm [-, -, -]
  servo[0].write(38); // Thumb
  servo[1].write(81); // Index
  servo[2].write(30); // Middle
  servo[3].write(18); // Ring
  servo[4].write(76); // Pinky

  delay(13);
  // Step 1166: Fingers [38, 81, 30, 18, 76] Arm [-, -, -]
  servo[0].write(38); // Thumb
  servo[1].write(81); // Index
  servo[2].write(30); // Middle
  servo[3].write(18); // Ring
  servo[4].write(76); // Pinky

  // Step 1167: Fingers [40, 80, 28, 20, 77] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(80); // Index
  servo[2].write(28); // Middle
  servo[3].write(20); // Ring
  servo[4].write(77); // Pinky

  delay(20);
  // Step 1168: Fingers [40, 80, 28, 20, 77] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(80); // Index
  servo[2].write(28); // Middle
  servo[3].write(20); // Ring
  servo[4].write(77); // Pinky

  // Step 1169: Fingers [42, 80, 26, 21, 78] Arm [-, -, -]
  servo[0].write(42); // Thumb
  servo[1].write(80); // Index
  servo[2].write(26); // Middle
  servo[3].write(21); // Ring
  servo[4].write(78); // Pinky

  delay(22);
  // Step 1170: Fingers [42, 80, 26, 21, 78] Arm [-, -, -]
  servo[0].write(42); // Thumb
  servo[1].write(80); // Index
  servo[2].write(26); // Middle
  servo[3].write(21); // Ring
  servo[4].write(78); // Pinky

  // Step 1171: Fingers [44, 79, 24, 23, 79] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(79); // Index
  servo[2].write(24); // Middle
  servo[3].write(23); // Ring
  servo[4].write(79); // Pinky

  delay(23);
  // Step 1172: Fingers [44, 79, 24, 23, 79] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(79); // Index
  servo[2].write(24); // Middle
  servo[3].write(23); // Ring
  servo[4].write(79); // Pinky

  // Step 1173: Fingers [46, 79, 22, 25, 80] Arm [-, -, -]
  servo[0].write(46); // Thumb
  servo[1].write(79); // Index
  servo[2].write(22); // Middle
  servo[3].write(25); // Ring
  servo[4].write(80); // Pinky

  delay(12);
  // Step 1174: Fingers [49, 78, 21, 27, 80] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(78); // Index
  servo[2].write(21); // Middle
  servo[3].write(27); // Ring
  servo[4].write(80); // Pinky

  // Step 1175: Fingers [49, 78, 21, 27, 80] Arm [-, -, -]
  servo[0].write(49); // Thumb
  servo[1].write(78); // Index
  servo[2].write(21); // Middle
  servo[3].write(27); // Ring
  servo[4].write(80); // Pinky

  // Step 1176: Fingers [51, 77, 19, 29, 80] Arm [-, -, -]
  servo[0].write(51); // Thumb
  servo[1].write(77); // Index
  servo[2].write(19); // Middle
  servo[3].write(29); // Ring
  servo[4].write(80); // Pinky

  // Step 1177: Fingers [53, 76, 18, 31, 81] Arm [-, -, -]
  servo[0].write(53); // Thumb
  servo[1].write(76); // Index
  servo[2].write(18); // Middle
  servo[3].write(31); // Ring
  servo[4].write(81); // Pinky

  delay(15);
  // Step 1178: Fingers [55, 74, 16, 33, 81] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(74); // Index
  servo[2].write(16); // Middle
  servo[3].write(33); // Ring
  servo[4].write(81); // Pinky

  // Step 1179: Fingers [55, 74, 16, 33, 81] Arm [-, -, -]
  servo[0].write(55); // Thumb
  servo[1].write(74); // Index
  servo[2].write(16); // Middle
  servo[3].write(33); // Ring
  servo[4].write(81); // Pinky

  // Step 1180: Fingers [59, 72, 14, 37, 81] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(72); // Index
  servo[2].write(14); // Middle
  servo[3].write(37); // Ring
  servo[4].write(81); // Pinky

  delay(11);
  // Step 1181: Fingers [61, 70, 13, 39, 80] Arm [-, -, -]
  servo[0].write(61); // Thumb
  servo[1].write(70); // Index
  servo[2].write(13); // Middle
  servo[3].write(39); // Ring
  servo[4].write(80); // Pinky

  // Step 1182: Fingers [62, 71, 13, 40, 81] Arm [-, -, -]
  servo[0].write(62); // Thumb
  servo[1].write(71); // Index
  servo[2].write(13); // Middle
  servo[3].write(40); // Ring
  servo[4].write(81); // Pinky

  // Step 1183: Fingers [62, 71, 13, 40, 81] Arm [-, -, -]
  servo[0].write(62); // Thumb
  servo[1].write(71); // Index
  servo[2].write(13); // Middle
  servo[3].write(40); // Ring
  servo[4].write(81); // Pinky

  // Step 1184: Fingers [64, 69, 12, 42, 80] Arm [-, -, -]
  servo[0].write(64); // Thumb
  servo[1].write(69); // Index
  servo[2].write(12); // Middle
  servo[3].write(42); // Ring
  servo[4].write(80); // Pinky

  // Step 1185: Fingers [66, 67, 11, 44, 80] Arm [-, -, -]
  servo[0].write(66); // Thumb
  servo[1].write(67); // Index
  servo[2].write(11); // Middle
  servo[3].write(44); // Ring
  servo[4].write(80); // Pinky

  // Step 1186: Fingers [67, 65, 11, 47, 79] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(65); // Index
  servo[2].write(11); // Middle
  servo[3].write(47); // Ring
  servo[4].write(79); // Pinky

  delay(15);
  // Step 1187: Fingers [67, 65, 11, 47, 79] Arm [-, -, -]
  servo[0].write(67); // Thumb
  servo[1].write(65); // Index
  servo[2].write(11); // Middle
  servo[3].write(47); // Ring
  servo[4].write(79); // Pinky

  // Step 1188: Fingers [71, 62, 10, 51, 77] Arm [-, -, -]
  servo[0].write(71); // Thumb
  servo[1].write(62); // Index
  servo[2].write(10); // Middle
  servo[3].write(51); // Ring
  servo[4].write(77); // Pinky

  // Step 1189: Fingers [72, 60, 9, 53, 76] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(60); // Index
  servo[2].write(9); // Middle
  servo[3].write(53); // Ring
  servo[4].write(76); // Pinky

  delay(16);
  // Step 1190: Fingers [74, 57, 9, 55, 75] Arm [-, -, -]
  servo[0].write(74); // Thumb
  servo[1].write(57); // Index
  servo[2].write(9); // Middle
  servo[3].write(55); // Ring
  servo[4].write(75); // Pinky

  // Step 1191: Fingers [74, 57, 9, 55, 75] Arm [-, -, -]
  servo[0].write(74); // Thumb
  servo[1].write(57); // Index
  servo[2].write(9); // Middle
  servo[3].write(55); // Ring
  servo[4].write(75); // Pinky

  // Step 1192: Fingers [75, 55, 9, 57, 74] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(55); // Index
  servo[2].write(9); // Middle
  servo[3].write(57); // Ring
  servo[4].write(74); // Pinky

  // Step 1193: Fingers [77, 54, 10, 60, 73] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(54); // Index
  servo[2].write(10); // Middle
  servo[3].write(60); // Ring
  servo[4].write(73); // Pinky

  delay(16);
  // Step 1194: Fingers [77, 54, 10, 60, 73] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(54); // Index
  servo[2].write(10); // Middle
  servo[3].write(60); // Ring
  servo[4].write(73); // Pinky

  // Step 1195: Fingers [78, 51, 10, 62, 71] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(51); // Index
  servo[2].write(10); // Middle
  servo[3].write(62); // Ring
  servo[4].write(71); // Pinky

  // Step 1196: Fingers [79, 50, 11, 64, 70] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(50); // Index
  servo[2].write(11); // Middle
  servo[3].write(64); // Ring
  servo[4].write(70); // Pinky

  // Step 1197: Fingers [80, 47, 12, 66, 68] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(47); // Index
  servo[2].write(12); // Middle
  servo[3].write(66); // Ring
  servo[4].write(68); // Pinky

  // Step 1198: Fingers [81, 45, 12, 68, 67] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(45); // Index
  servo[2].write(12); // Middle
  servo[3].write(68); // Ring
  servo[4].write(67); // Pinky

  // Step 1199: Fingers [81, 45, 12, 68, 67] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(45); // Index
  servo[2].write(12); // Middle
  servo[3].write(68); // Ring
  servo[4].write(67); // Pinky

  // Step 1200: Fingers [81, 43, 13, 70, 65] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(43); // Index
  servo[2].write(13); // Middle
  servo[3].write(70); // Ring
  servo[4].write(65); // Pinky

  // Step 1201: Fingers [82, 41, 14, 71, 63] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(41); // Index
  servo[2].write(14); // Middle
  servo[3].write(71); // Ring
  servo[4].write(63); // Pinky

  // Step 1202: Fingers [82, 39, 15, 73, 61] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(39); // Index
  servo[2].write(15); // Middle
  servo[3].write(73); // Ring
  servo[4].write(61); // Pinky

  // Step 1203: Fingers [82, 39, 15, 73, 61] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(39); // Index
  servo[2].write(15); // Middle
  servo[3].write(73); // Ring
  servo[4].write(61); // Pinky

  delay(15);
  // Step 1204: Fingers [82, 36, 16, 74, 59] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(36); // Index
  servo[2].write(16); // Middle
  servo[3].write(74); // Ring
  servo[4].write(59); // Pinky

  delay(17);
  // Step 1205: Fingers [82, 36, 16, 74, 59] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(36); // Index
  servo[2].write(16); // Middle
  servo[3].write(74); // Ring
  servo[4].write(59); // Pinky

  // Step 1206: Fingers [83, 35, 18, 76, 57] Arm [-, -, -]
  servo[0].write(83); // Thumb
  servo[1].write(35); // Index
  servo[2].write(18); // Middle
  servo[3].write(76); // Ring
  servo[4].write(57); // Pinky

  delay(15);
  // Step 1207: Fingers [82, 33, 19, 77, 55] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(33); // Index
  servo[2].write(19); // Middle
  servo[3].write(77); // Ring
  servo[4].write(55); // Pinky

  // Step 1208: Fingers [82, 33, 19, 77, 55] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(33); // Index
  servo[2].write(19); // Middle
  servo[3].write(77); // Ring
  servo[4].write(55); // Pinky

  // Step 1209: Fingers [82, 31, 21, 78, 53] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(31); // Index
  servo[2].write(21); // Middle
  servo[3].write(78); // Ring
  servo[4].write(53); // Pinky

  // Step 1210: Fingers [82, 29, 22, 79, 50] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(29); // Index
  servo[2].write(22); // Middle
  servo[3].write(79); // Ring
  servo[4].write(50); // Pinky

  delay(15);
  // Step 1211: Fingers [82, 29, 22, 79, 50] Arm [-, -, -]
  servo[0].write(82); // Thumb
  servo[1].write(29); // Index
  servo[2].write(22); // Middle
  servo[3].write(79); // Ring
  servo[4].write(50); // Pinky

  // Step 1212: Fingers [81, 27, 24, 80, 48] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(27); // Index
  servo[2].write(24); // Middle
  servo[3].write(80); // Ring
  servo[4].write(48); // Pinky

  // Step 1213: Fingers [81, 25, 26, 81, 46] Arm [-, -, -]
  servo[0].write(81); // Thumb
  servo[1].write(25); // Index
  servo[2].write(26); // Middle
  servo[3].write(81); // Ring
  servo[4].write(46); // Pinky

  delay(16);
  // Step 1214: Fingers [80, 24, 28, 82, 44] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(24); // Index
  servo[2].write(28); // Middle
  servo[3].write(82); // Ring
  servo[4].write(44); // Pinky

  // Step 1215: Fingers [80, 24, 28, 82, 44] Arm [-, -, -]
  servo[0].write(80); // Thumb
  servo[1].write(24); // Index
  servo[2].write(28); // Middle
  servo[3].write(82); // Ring
  servo[4].write(44); // Pinky

  // Step 1216: Fingers [79, 22, 30, 82, 42] Arm [-, -, -]
  servo[0].write(79); // Thumb
  servo[1].write(22); // Index
  servo[2].write(30); // Middle
  servo[3].write(82); // Ring
  servo[4].write(42); // Pinky

  // Step 1217: Fingers [78, 20, 32, 83, 40] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(20); // Index
  servo[2].write(32); // Middle
  servo[3].write(83); // Ring
  servo[4].write(40); // Pinky

  // Step 1218: Fingers [78, 20, 32, 83, 40] Arm [-, -, -]
  servo[0].write(78); // Thumb
  servo[1].write(20); // Index
  servo[2].write(32); // Middle
  servo[3].write(83); // Ring
  servo[4].write(40); // Pinky

  // Step 1219: Fingers [77, 19, 34, 83, 38] Arm [-, -, -]
  servo[0].write(77); // Thumb
  servo[1].write(19); // Index
  servo[2].write(34); // Middle
  servo[3].write(83); // Ring
  servo[4].write(38); // Pinky

  // Step 1220: Fingers [76, 18, 37, 83, 36] Arm [-, -, -]
  servo[0].write(76); // Thumb
  servo[1].write(18); // Index
  servo[2].write(37); // Middle
  servo[3].write(83); // Ring
  servo[4].write(36); // Pinky

  delay(16);
  // Step 1221: Fingers [75, 17, 39, 83, 34] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(17); // Index
  servo[2].write(39); // Middle
  servo[3].write(83); // Ring
  servo[4].write(34); // Pinky

  // Step 1222: Fingers [75, 17, 39, 83, 34] Arm [-, -, -]
  servo[0].write(75); // Thumb
  servo[1].write(17); // Index
  servo[2].write(39); // Middle
  servo[3].write(83); // Ring
  servo[4].write(34); // Pinky

  // Step 1223: Fingers [73, 16, 41, 83, 32] Arm [-, -, -]
  servo[0].write(73); // Thumb
  servo[1].write(16); // Index
  servo[2].write(41); // Middle
  servo[3].write(83); // Ring
  servo[4].write(32); // Pinky

  // Step 1224: Fingers [72, 15, 43, 83, 30] Arm [-, -, -]
  servo[0].write(72); // Thumb
  servo[1].write(15); // Index
  servo[2].write(43); // Middle
  servo[3].write(83); // Ring
  servo[4].write(30); // Pinky

  // Step 1225: Fingers [70, 14, 45, 82, 28] Arm [-, -, -]
  servo[0].write(70); // Thumb
  servo[1].write(14); // Index
  servo[2].write(45); // Middle
  servo[3].write(82); // Ring
  servo[4].write(28); // Pinky

  // Step 1226: Fingers [70, 14, 45, 82, 28] Arm [-, -, -]
  servo[0].write(70); // Thumb
  servo[1].write(14); // Index
  servo[2].write(45); // Middle
  servo[3].write(82); // Ring
  servo[4].write(28); // Pinky

  // Step 1227: Fingers [68, 13, 48, 82, 26] Arm [-, -, -]
  servo[0].write(68); // Thumb
  servo[1].write(13); // Index
  servo[2].write(48); // Middle
  servo[3].write(82); // Ring
  servo[4].write(26); // Pinky

  // Step 1228: Fingers [65, 12, 52, 80, 23] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(12); // Index
  servo[2].write(52); // Middle
  servo[3].write(80); // Ring
  servo[4].write(23); // Pinky

  // Step 1229: Fingers [65, 12, 53, 80, 23] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(12); // Index
  servo[2].write(53); // Middle
  servo[3].write(80); // Ring
  servo[4].write(23); // Pinky

  // Step 1230: Fingers [65, 12, 53, 80, 23] Arm [-, -, -]
  servo[0].write(65); // Thumb
  servo[1].write(12); // Index
  servo[2].write(53); // Middle
  servo[3].write(80); // Ring
  servo[4].write(23); // Pinky

  // Step 1231: Fingers [63, 12, 55, 79, 21] Arm [-, -, -]
  servo[0].write(63); // Thumb
  servo[1].write(12); // Index
  servo[2].write(55); // Middle
  servo[3].write(79); // Ring
  servo[4].write(21); // Pinky

  // Step 1232: Fingers [61, 12, 57, 78, 20] Arm [-, -, -]
  servo[0].write(61); // Thumb
  servo[1].write(12); // Index
  servo[2].write(57); // Middle
  servo[3].write(78); // Ring
  servo[4].write(20); // Pinky

  delay(15);
  // Step 1233: Fingers [61, 12, 57, 78, 20] Arm [-, -, -]
  servo[0].write(61); // Thumb
  servo[1].write(12); // Index
  servo[2].write(57); // Middle
  servo[3].write(78); // Ring
  servo[4].write(20); // Pinky

  // Step 1234: Fingers [59, 12, 59, 77, 19] Arm [-, -, -]
  servo[0].write(59); // Thumb
  servo[1].write(12); // Index
  servo[2].write(59); // Middle
  servo[3].write(77); // Ring
  servo[4].write(19); // Pinky

  delay(17);
  // Step 1235: Fingers [57, 12, 61, 75, 17] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(12); // Index
  servo[2].write(61); // Middle
  servo[3].write(75); // Ring
  servo[4].write(17); // Pinky

  // Step 1236: Fingers [57, 12, 61, 75, 17] Arm [-, -, -]
  servo[0].write(57); // Thumb
  servo[1].write(12); // Index
  servo[2].write(61); // Middle
  servo[3].write(75); // Ring
  servo[4].write(17); // Pinky

  delay(22);
  // Step 1237: Fingers [54, 12, 63, 74, 16] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(12); // Index
  servo[2].write(63); // Middle
  servo[3].write(74); // Ring
  servo[4].write(16); // Pinky

  // Step 1238: Fingers [54, 12, 63, 74, 16] Arm [-, -, -]
  servo[0].write(54); // Thumb
  servo[1].write(12); // Index
  servo[2].write(63); // Middle
  servo[3].write(74); // Ring
  servo[4].write(16); // Pinky

  // Step 1239: Fingers [52, 12, 65, 72, 15] Arm [-, -, -]
  servo[0].write(52); // Thumb
  servo[1].write(12); // Index
  servo[2].write(65); // Middle
  servo[3].write(72); // Ring
  servo[4].write(15); // Pinky

  // Step 1240: Fingers [50, 13, 68, 71, 15] Arm [-, -, -]
  servo[0].write(50); // Thumb
  servo[1].write(13); // Index
  servo[2].write(68); // Middle
  servo[3].write(71); // Ring
  servo[4].write(15); // Pinky

  delay(14);
  // Step 1241: Fingers [48, 14, 69, 69, 14] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(14); // Index
  servo[2].write(69); // Middle
  servo[3].write(69); // Ring
  servo[4].write(14); // Pinky

  // Step 1242: Fingers [48, 14, 69, 69, 14] Arm [-, -, -]
  servo[0].write(48); // Thumb
  servo[1].write(14); // Index
  servo[2].write(69); // Middle
  servo[3].write(69); // Ring
  servo[4].write(14); // Pinky

  delay(17);
  // Step 1243: Fingers [46, 15, 72, 68, 14] Arm [-, -, -]
  servo[0].write(46); // Thumb
  servo[1].write(15); // Index
  servo[2].write(72); // Middle
  servo[3].write(68); // Ring
  servo[4].write(14); // Pinky

  delay(12);
  // Step 1244: Fingers [46, 15, 72, 68, 14] Arm [-, -, -]
  servo[0].write(46); // Thumb
  servo[1].write(15); // Index
  servo[2].write(72); // Middle
  servo[3].write(68); // Ring
  servo[4].write(14); // Pinky

  // Step 1245: Fingers [44, 16, 73, 66, 13] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(16); // Index
  servo[2].write(73); // Middle
  servo[3].write(66); // Ring
  servo[4].write(13); // Pinky

  // Step 1246: Fingers [42, 17, 75, 64, 13] Arm [-, -, -]
  servo[0].write(42); // Thumb
  servo[1].write(17); // Index
  servo[2].write(75); // Middle
  servo[3].write(64); // Ring
  servo[4].write(13); // Pinky

  // Step 1247: Fingers [42, 18, 75, 65, 13] Arm [-, -, -]
  servo[0].write(42); // Thumb
  servo[1].write(18); // Index
  servo[2].write(75); // Middle
  servo[3].write(65); // Ring
  servo[4].write(13); // Pinky

  // Step 1248: Fingers [40, 19, 77, 62, 13] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(19); // Index
  servo[2].write(77); // Middle
  servo[3].write(62); // Ring
  servo[4].write(13); // Pinky

  // Step 1249: Fingers [40, 19, 77, 62, 13] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(19); // Index
  servo[2].write(77); // Middle
  servo[3].write(62); // Ring
  servo[4].write(13); // Pinky

  // Step 1250: Fingers [38, 20, 78, 60, 13] Arm [-, -, -]
  servo[0].write(38); // Thumb
  servo[1].write(20); // Index
  servo[2].write(78); // Middle
  servo[3].write(60); // Ring
  servo[4].write(13); // Pinky

  delay(15);
  // Step 1251: Fingers [34, 23, 81, 56, 14] Arm [-, -, -]
  servo[0].write(34); // Thumb
  servo[1].write(23); // Index
  servo[2].write(81); // Middle
  servo[3].write(56); // Ring
  servo[4].write(14); // Pinky

  // Step 1252: Fingers [34, 23, 81, 56, 14] Arm [-, -, -]
  servo[0].write(34); // Thumb
  servo[1].write(23); // Index
  servo[2].write(81); // Middle
  servo[3].write(56); // Ring
  servo[4].write(14); // Pinky

  // Step 1253: Fingers [32, 25, 82, 54, 14] Arm [-, -, -]
  servo[0].write(32); // Thumb
  servo[1].write(25); // Index
  servo[2].write(82); // Middle
  servo[3].write(54); // Ring
  servo[4].write(14); // Pinky

  // Step 1254: Fingers [30, 26, 83, 52, 15] Arm [-, -, -]
  servo[0].write(30); // Thumb
  servo[1].write(26); // Index
  servo[2].write(83); // Middle
  servo[3].write(52); // Ring
  servo[4].write(15); // Pinky

  // Step 1255: Fingers [29, 29, 84, 50, 16] Arm [-, -, -]
  servo[0].write(29); // Thumb
  servo[1].write(29); // Index
  servo[2].write(84); // Middle
  servo[3].write(50); // Ring
  servo[4].write(16); // Pinky

  // Step 1256: Fingers [29, 29, 85, 51, 16] Arm [-, -, -]
  servo[0].write(29); // Thumb
  servo[1].write(29); // Index
  servo[2].write(85); // Middle
  servo[3].write(51); // Ring
  servo[4].write(16); // Pinky

  // Step 1257: Fingers [29, 29, 85, 51, 16] Arm [-, -, -]
  servo[0].write(29); // Thumb
  servo[1].write(29); // Index
  servo[2].write(85); // Middle
  servo[3].write(51); // Ring
  servo[4].write(16); // Pinky

  // Step 1258: Fingers [26, 33, 86, 46, 18] Arm [-, -, -]
  servo[0].write(26); // Thumb
  servo[1].write(33); // Index
  servo[2].write(86); // Middle
  servo[3].write(46); // Ring
  servo[4].write(18); // Pinky

  // Step 1259: Fingers [23, 37, 87, 42, 20] Arm [-, -, -]
  servo[0].write(23); // Thumb
  servo[1].write(37); // Index
  servo[2].write(87); // Middle
  servo[3].write(42); // Ring
  servo[4].write(20); // Pinky

  delay(16);
  // Step 1260: Fingers [23, 37, 87, 42, 20] Arm [-, -, -]
  servo[0].write(23); // Thumb
  servo[1].write(37); // Index
  servo[2].write(87); // Middle
  servo[3].write(42); // Ring
  servo[4].write(20); // Pinky

  // Step 1261: Fingers [22, 39, 87, 40, 21] Arm [-, -, -]
  servo[0].write(22); // Thumb
  servo[1].write(39); // Index
  servo[2].write(87); // Middle
  servo[3].write(40); // Ring
  servo[4].write(21); // Pinky

  // Step 1262: Fingers [21, 41, 87, 38, 23] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(41); // Index
  servo[2].write(87); // Middle
  servo[3].write(38); // Ring
  servo[4].write(23); // Pinky

  // Step 1263: Fingers [21, 42, 87, 38, 23] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(42); // Index
  servo[2].write(87); // Middle
  servo[3].write(38); // Ring
  servo[4].write(23); // Pinky

  // Step 1264: Fingers [19, 46, 87, 34, 26] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(46); // Index
  servo[2].write(87); // Middle
  servo[3].write(34); // Ring
  servo[4].write(26); // Pinky

  // Step 1265: Fingers [19, 46, 87, 34, 26] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(46); // Index
  servo[2].write(87); // Middle
  servo[3].write(34); // Ring
  servo[4].write(26); // Pinky

  // Step 1266: Fingers [18, 48, 86, 32, 28] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(48); // Index
  servo[2].write(86); // Middle
  servo[3].write(32); // Ring
  servo[4].write(28); // Pinky

  // Step 1267: Fingers [18, 51, 86, 31, 30] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(51); // Index
  servo[2].write(86); // Middle
  servo[3].write(31); // Ring
  servo[4].write(30); // Pinky

  // Step 1268: Fingers [17, 53, 85, 29, 32] Arm [-, -, -]
  servo[0].write(17); // Thumb
  servo[1].write(53); // Index
  servo[2].write(85); // Middle
  servo[3].write(29); // Ring
  servo[4].write(32); // Pinky

  // Step 1269: Fingers [17, 53, 85, 29, 32] Arm [-, -, -]
  servo[0].write(17); // Thumb
  servo[1].write(53); // Index
  servo[2].write(85); // Middle
  servo[3].write(29); // Ring
  servo[4].write(32); // Pinky

  // Step 1270: Fingers [16, 58, 84, 26, 36] Arm [-, -, -]
  servo[0].write(16); // Thumb
  servo[1].write(58); // Index
  servo[2].write(84); // Middle
  servo[3].write(26); // Ring
  servo[4].write(36); // Pinky

  // Step 1271: Fingers [16, 60, 83, 25, 38] Arm [-, -, -]
  servo[0].write(16); // Thumb
  servo[1].write(60); // Index
  servo[2].write(83); // Middle
  servo[3].write(25); // Ring
  servo[4].write(38); // Pinky

  // Step 1272: Fingers [16, 62, 82, 23, 40] Arm [-, -, -]
  servo[0].write(16); // Thumb
  servo[1].write(62); // Index
  servo[2].write(82); // Middle
  servo[3].write(23); // Ring
  servo[4].write(40); // Pinky

  // Step 1273: Fingers [17, 65, 81, 23, 43] Arm [-, -, -]
  servo[0].write(17); // Thumb
  servo[1].write(65); // Index
  servo[2].write(81); // Middle
  servo[3].write(23); // Ring
  servo[4].write(43); // Pinky

  // Step 1274: Fingers [17, 65, 81, 23, 43] Arm [-, -, -]
  servo[0].write(17); // Thumb
  servo[1].write(65); // Index
  servo[2].write(81); // Middle
  servo[3].write(23); // Ring
  servo[4].write(43); // Pinky

  // Step 1275: Fingers [17, 65, 81, 23, 43] Arm [-, -, -]
  servo[0].write(17); // Thumb
  servo[1].write(65); // Index
  servo[2].write(81); // Middle
  servo[3].write(23); // Ring
  servo[4].write(43); // Pinky

  // Step 1276: Fingers [17, 67, 80, 22, 45] Arm [-, -, -]
  servo[0].write(17); // Thumb
  servo[1].write(67); // Index
  servo[2].write(80); // Middle
  servo[3].write(22); // Ring
  servo[4].write(45); // Pinky

  // Step 1277: Fingers [17, 69, 78, 21, 48] Arm [-, -, -]
  servo[0].write(17); // Thumb
  servo[1].write(69); // Index
  servo[2].write(78); // Middle
  servo[3].write(21); // Ring
  servo[4].write(48); // Pinky

  delay(15);
  // Step 1278: Fingers [17, 69, 78, 21, 48] Arm [-, -, -]
  servo[0].write(17); // Thumb
  servo[1].write(69); // Index
  servo[2].write(78); // Middle
  servo[3].write(21); // Ring
  servo[4].write(48); // Pinky

  // Step 1279: Fingers [18, 71, 77, 20, 50] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(71); // Index
  servo[2].write(77); // Middle
  servo[3].write(20); // Ring
  servo[4].write(50); // Pinky

  // Step 1280: Fingers [18, 72, 77, 20, 50] Arm [-, -, -]
  servo[0].write(18); // Thumb
  servo[1].write(72); // Index
  servo[2].write(77); // Middle
  servo[3].write(20); // Ring
  servo[4].write(50); // Pinky

  delay(15);
  // Step 1281: Fingers [19, 74, 75, 19, 52] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(74); // Index
  servo[2].write(75); // Middle
  servo[3].write(19); // Ring
  servo[4].write(52); // Pinky

  // Step 1282: Fingers [19, 74, 75, 19, 52] Arm [-, -, -]
  servo[0].write(19); // Thumb
  servo[1].write(74); // Index
  servo[2].write(75); // Middle
  servo[3].write(19); // Ring
  servo[4].write(52); // Pinky

  delay(11);
  // Step 1283: Fingers [20, 76, 74, 19, 55] Arm [-, -, -]
  servo[0].write(20); // Thumb
  servo[1].write(76); // Index
  servo[2].write(74); // Middle
  servo[3].write(19); // Ring
  servo[4].write(55); // Pinky

  // Step 1284: Fingers [21, 78, 72, 19, 58] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(78); // Index
  servo[2].write(72); // Middle
  servo[3].write(19); // Ring
  servo[4].write(58); // Pinky

  // Step 1285: Fingers [21, 78, 72, 19, 58] Arm [-, -, -]
  servo[0].write(21); // Thumb
  servo[1].write(78); // Index
  servo[2].write(72); // Middle
  servo[3].write(19); // Ring
  servo[4].write(58); // Pinky

  // Step 1286: Fingers [23, 80, 71, 19, 60] Arm [-, -, -]
  servo[0].write(23); // Thumb
  servo[1].write(80); // Index
  servo[2].write(71); // Middle
  servo[3].write(19); // Ring
  servo[4].write(60); // Pinky

  // Step 1287: Fingers [24, 82, 69, 19, 63] Arm [-, -, -]
  servo[0].write(24); // Thumb
  servo[1].write(82); // Index
  servo[2].write(69); // Middle
  servo[3].write(19); // Ring
  servo[4].write(63); // Pinky

  // Step 1288: Fingers [25, 83, 67, 19, 65] Arm [-, -, -]
  servo[0].write(25); // Thumb
  servo[1].write(83); // Index
  servo[2].write(67); // Middle
  servo[3].write(19); // Ring
  servo[4].write(65); // Pinky

  // Step 1289: Fingers [25, 83, 67, 19, 65] Arm [-, -, -]
  servo[0].write(25); // Thumb
  servo[1].write(83); // Index
  servo[2].write(67); // Middle
  servo[3].write(19); // Ring
  servo[4].write(65); // Pinky

  // Step 1290: Fingers [25, 84, 67, 19, 65] Arm [-, -, -]
  servo[0].write(25); // Thumb
  servo[1].write(84); // Index
  servo[2].write(67); // Middle
  servo[3].write(19); // Ring
  servo[4].write(65); // Pinky

  // Step 1291: Fingers [27, 85, 65, 19, 67] Arm [-, -, -]
  servo[0].write(27); // Thumb
  servo[1].write(85); // Index
  servo[2].write(65); // Middle
  servo[3].write(19); // Ring
  servo[4].write(67); // Pinky

  delay(13);
  // Step 1292: Fingers [27, 85, 66, 20, 68] Arm [-, -, -]
  servo[0].write(27); // Thumb
  servo[1].write(85); // Index
  servo[2].write(66); // Middle
  servo[3].write(20); // Ring
  servo[4].write(68); // Pinky

  // Step 1293: Fingers [27, 85, 66, 20, 68] Arm [-, -, -]
  servo[0].write(27); // Thumb
  servo[1].write(85); // Index
  servo[2].write(66); // Middle
  servo[3].write(20); // Ring
  servo[4].write(68); // Pinky

  // Step 1294: Fingers [29, 87, 64, 20, 70] Arm [-, -, -]
  servo[0].write(29); // Thumb
  servo[1].write(87); // Index
  servo[2].write(64); // Middle
  servo[3].write(20); // Ring
  servo[4].write(70); // Pinky

  // Step 1295: Fingers [30, 88, 62, 20, 72] Arm [-, -, -]
  servo[0].write(30); // Thumb
  servo[1].write(88); // Index
  servo[2].write(62); // Middle
  servo[3].write(20); // Ring
  servo[4].write(72); // Pinky

  // Step 1296: Fingers [32, 89, 60, 21, 75] Arm [-, -, -]
  servo[0].write(32); // Thumb
  servo[1].write(89); // Index
  servo[2].write(60); // Middle
  servo[3].write(21); // Ring
  servo[4].write(75); // Pinky

  // Step 1297: Fingers [32, 89, 60, 21, 75] Arm [-, -, -]
  servo[0].write(32); // Thumb
  servo[1].write(89); // Index
  servo[2].write(60); // Middle
  servo[3].write(21); // Ring
  servo[4].write(75); // Pinky

  delay(17);
  // Step 1298: Fingers [35, 91, 58, 22, 77] Arm [-, -, -]
  servo[0].write(35); // Thumb
  servo[1].write(91); // Index
  servo[2].write(58); // Middle
  servo[3].write(22); // Ring
  servo[4].write(77); // Pinky

  delay(14);
  // Step 1299: Fingers [35, 91, 58, 22, 77] Arm [-, -, -]
  servo[0].write(35); // Thumb
  servo[1].write(91); // Index
  servo[2].write(58); // Middle
  servo[3].write(22); // Ring
  servo[4].write(77); // Pinky

  // Step 1300: Fingers [36, 91, 56, 23, 79] Arm [-, -, -]
  servo[0].write(36); // Thumb
  servo[1].write(91); // Index
  servo[2].write(56); // Middle
  servo[3].write(23); // Ring
  servo[4].write(79); // Pinky

  // Step 1301: Fingers [37, 92, 56, 23, 79] Arm [-, -, -]
  servo[0].write(37); // Thumb
  servo[1].write(92); // Index
  servo[2].write(56); // Middle
  servo[3].write(23); // Ring
  servo[4].write(79); // Pinky

  delay(13);
  // Step 1302: Fingers [37, 92, 56, 23, 79] Arm [-, -, -]
  servo[0].write(37); // Thumb
  servo[1].write(92); // Index
  servo[2].write(56); // Middle
  servo[3].write(23); // Ring
  servo[4].write(79); // Pinky

  delay(18);
  // Step 1303: Fingers [39, 92, 54, 24, 81] Arm [-, -, -]
  servo[0].write(39); // Thumb
  servo[1].write(92); // Index
  servo[2].write(54); // Middle
  servo[3].write(24); // Ring
  servo[4].write(81); // Pinky

  // Step 1304: Fingers [39, 93, 54, 24, 81] Arm [-, -, -]
  servo[0].write(39); // Thumb
  servo[1].write(93); // Index
  servo[2].write(54); // Middle
  servo[3].write(24); // Ring
  servo[4].write(81); // Pinky

  // Step 1305: Fingers [39, 93, 54, 24, 81] Arm [-, -, -]
  servo[0].write(39); // Thumb
  servo[1].write(93); // Index
  servo[2].write(54); // Middle
  servo[3].write(24); // Ring
  servo[4].write(81); // Pinky

  // Step 1306: Fingers [40, 93, 55, 25, 82] Arm [-, -, -]
  servo[0].write(40); // Thumb
  servo[1].write(93); // Index
  servo[2].write(55); // Middle
  servo[3].write(25); // Ring
  servo[4].write(82); // Pinky

  // Step 1307: Fingers [41, 94, 53, 26, 83] Arm [-, -, -]
  servo[0].write(41); // Thumb
  servo[1].write(94); // Index
  servo[2].write(53); // Middle
  servo[3].write(26); // Ring
  servo[4].write(83); // Pinky

  delay(19);
  // Step 1308: Fingers [41, 94, 53, 26, 83] Arm [-, -, -]
  servo[0].write(41); // Thumb
  servo[1].write(94); // Index
  servo[2].write(53); // Middle
  servo[3].write(26); // Ring
  servo[4].write(83); // Pinky

  // Step 1309: Fingers [42, 94, 53, 26, 84] Arm [-, -, -]
  servo[0].write(42); // Thumb
  servo[1].write(94); // Index
  servo[2].write(53); // Middle
  servo[3].write(26); // Ring
  servo[4].write(84); // Pinky

  delay(13);
  // Step 1310: Fingers [44, 94, 51, 27, 85] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(94); // Index
  servo[2].write(51); // Middle
  servo[3].write(27); // Ring
  servo[4].write(85); // Pinky

  // Step 1311: Fingers [44, 94, 51, 27, 85] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(94); // Index
  servo[2].write(51); // Middle
  servo[3].write(27); // Ring
  servo[4].write(85); // Pinky

  // Step 1312: Fingers [44, 95, 51, 28, 86] Arm [-, -, -]
  servo[0].write(44); // Thumb
  servo[1].write(95); // Index
  servo[2].write(51); // Middle
  servo[3].write(28); // Ring
  servo[4].write(86); // Pinky

  // Step 1313: Fingers [47, 95, 50, 29, 88] Arm [-, -, -]
  servo[0].write(47); // Thumb
  servo[1].write(95); // Index
  servo[2].write(50); // Middle
  servo[3].write(29); // Ring
  servo[4].write(88); // Pinky

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
