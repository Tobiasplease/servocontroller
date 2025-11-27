/*
 * Simple Arm Scratch Movement
 * 8 Servos: Fingers (pins 12-8) + Arm (pins 7-5)
 * 
 * Pins 12-8: Fingers (pinky, ring, middle, index, thumb)
 * Pin 7: Wrist Tilt
 * Pin 6: Elbow  
 * Pin 5: Shoulder
 * 
 * Simple coordinated scratching motion on the arm servos
 * Fingers stay in a neutral/relaxed position
 */

#include <Servo.h>

// 8 servos total
Servo servos[8];
int pins[8] = {5, 6, 7, 8, 9, 10, 11, 12};

// Arm servos (pins 5, 6, 7)
#define SHOULDER 0  // pin 5
#define ELBOW    1  // pin 6
#define WRIST    2  // pin 7

// Finger servos (pins 8-12) - indices 3-7
#define THUMB  3   // pin 8
#define INDEX  4   // pin 9
#define MIDDLE 5   // pin 10
#define RING   6   // pin 11
#define PINKY  7   // pin 12

// Scratch movement parameters
float angle = 0;
float scratchSpeed = 0.002;  // adjust for faster/slower

// Arm movement ranges (adjust these to calibrate)
int shoulderCenter = 90;
int elbowCenter = 90;
int wristCenter = 90;

int shoulderRange = 15;  // how much shoulder moves
int elbowRange = 20;     // how much elbow moves
int wristRange = 25;     // how much wrist moves

// Finger rest position
int fingerRest = 70;  // adjust for your hand's neutral position

void setup() {
  Serial.begin(9600);
  
  // Attach all servos
  for (int i = 0; i < 8; i++) {
    servos[i].attach(pins[i]);
  }
  
  // Set fingers to rest position
  for (int i = THUMB; i <= PINKY; i++) {
    servos[i].write(fingerRest);
  }
  
  // Center arm servos
  servos[SHOULDER].write(shoulderCenter);
  servos[ELBOW].write(elbowCenter);
  servos[WRIST].write(wristCenter);
  
  delay(1000);
  Serial.println("Arm Scratch Ready");
}

void loop() {
  unsigned long now = millis();
  
  // Advance the scratch cycle
  angle += scratchSpeed;
  if (angle > TWO_PI) angle -= TWO_PI;
  
  // Create coordinated scratching motion
  // Each servo contributes to the overall movement
  
  // Wrist: main vertical scratching motion
  int wristPos = wristCenter + wristRange * sin(angle);
  
  // Elbow: slower compensation movement
  int elbowPos = elbowCenter + elbowRange * sin(angle * 0.7);
  
  // Shoulder: subtle stabilization
  int shoulderPos = shoulderCenter + shoulderRange * sin(angle * 0.3);
  
  // Write positions
  servos[SHOULDER].write(shoulderPos);
  servos[ELBOW].write(elbowPos);
  servos[WRIST].write(wristPos);
  
  delay(20);  // ~50Hz update rate
}
