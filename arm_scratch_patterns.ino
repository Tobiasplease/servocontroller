/*
 * Arm Scratch Movement - Multiple Patterns
 * 8 Servos: Fingers (pins 12-8) + Arm (pins 7-5)
 * 
 * Pins 12-8: Fingers (stay at rest)
 * Pin 7: Wrist Tilt
 * Pin 6: Elbow  
 * Pin 5: Shoulder
 * 
 * Change SCRATCH_PATTERN to switch between different movements:
 * 1 = Vertical scratch
 * 2 = Horizontal scratch  
 * 3 = Circular scratch
 * 4 = Random organic movement
 */

#include <Servo.h>

// === PATTERN SELECTION ===
#define SCRATCH_PATTERN 1  // Change this: 1, 2, 3, or 4

// 8 servos total
Servo servos[8];
int pins[8] = {5, 6, 7, 8, 9, 10, 11, 12};

// Arm servos
#define SHOULDER 0  // pin 5
#define ELBOW    1  // pin 6
#define WRIST    2  // pin 7

// Finger servos - indices 3-7
#define THUMB  3
#define INDEX  4
#define MIDDLE 5
#define RING   6
#define PINKY  7

// Movement state
float angle = 0;
float speed = 0.002;

// Calibration - adjust these for your hardware
int shoulderCenter = 90;
int elbowCenter = 90;
int wristCenter = 90;

int shoulderRange = 15;
int elbowRange = 20;
int wristRange = 25;

int fingerRest = 70;

void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < 8; i++) {
    servos[i].attach(pins[i]);
  }
  
  // Set fingers to rest
  for (int i = THUMB; i <= PINKY; i++) {
    servos[i].write(fingerRest);
  }
  
  // Center arms
  servos[SHOULDER].write(shoulderCenter);
  servos[ELBOW].write(elbowCenter);
  servos[WRIST].write(wristCenter);
  
  delay(1000);
  
  #if SCRATCH_PATTERN == 1
    Serial.println("Pattern: VERTICAL SCRATCH");
  #elif SCRATCH_PATTERN == 2
    Serial.println("Pattern: HORIZONTAL SCRATCH");
  #elif SCRATCH_PATTERN == 3
    Serial.println("Pattern: CIRCULAR SCRATCH");
  #elif SCRATCH_PATTERN == 4
    Serial.println("Pattern: ORGANIC MOVEMENT");
  #endif
}

void loop() {
  angle += speed;
  if (angle > TWO_PI) angle -= TWO_PI;
  
  int shoulderPos, elbowPos, wristPos;
  
  #if SCRATCH_PATTERN == 1
    // ===== VERTICAL SCRATCH =====
    // Up and down motion, mainly wrist and elbow
    wristPos = wristCenter + wristRange * sin(angle);
    elbowPos = elbowCenter + elbowRange * sin(angle * 0.7);
    shoulderPos = shoulderCenter + shoulderRange * 0.3 * sin(angle * 0.5);
    
  #elif SCRATCH_PATTERN == 2
    // ===== HORIZONTAL SCRATCH =====
    // Side to side motion, mainly shoulder and wrist
    shoulderPos = shoulderCenter + shoulderRange * sin(angle);
    wristPos = wristCenter + wristRange * 0.6 * sin(angle * 1.2);
    elbowPos = elbowCenter + elbowRange * 0.3 * cos(angle);
    
  #elif SCRATCH_PATTERN == 3
    // ===== CIRCULAR SCRATCH =====
    // Coordinated circular motion
    shoulderPos = shoulderCenter + shoulderRange * cos(angle);
    wristPos = wristCenter + wristRange * sin(angle);
    elbowPos = elbowCenter + elbowRange * sin(angle * 0.5);
    
  #elif SCRATCH_PATTERN == 4
    // ===== ORGANIC MOVEMENT =====
    // Multiple frequencies combined for natural feel
    wristPos = wristCenter + wristRange * (sin(angle) + 0.3 * sin(angle * 2.7));
    elbowPos = elbowCenter + elbowRange * (cos(angle * 0.7) + 0.2 * sin(angle * 1.3));
    shoulderPos = shoulderCenter + shoulderRange * sin(angle * 0.4);
    
  #else
    // Default to centered
    shoulderPos = shoulderCenter;
    elbowPos = elbowCenter;
    wristPos = wristCenter;
  #endif
  
  // Write positions
  servos[SHOULDER].write(shoulderPos);
  servos[ELBOW].write(elbowPos);
  servos[WRIST].write(wristPos);
  
  delay(20);
}
