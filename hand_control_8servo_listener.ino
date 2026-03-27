/*
 * 8-Servo Hand Control Listener (ACTIVE)
 * Receives: "HAND8,pos0,pos1,pos2,pos3,pos4,pos5,pos6,pos7"
 * Sends: "PIR,1" when motion detected
 *
 * Exact command index -> servo -> pin mapping:
 * pos0 -> Thumb    -> D12
 * pos1 -> Index    -> D11
 * pos2 -> Middle   -> D10 (REVERSED)
 * pos3 -> Ring     -> D9  (REVERSED)
 * pos4 -> Pinky    -> D8
 * pos5 -> Shoulder -> D7
 * pos6 -> Elbow    -> D6
 * pos7 -> Wrist    -> D5
 *
 * PIR Sensor on D2
 *
 * Note: Arm servos are Shoulder=D7, Elbow=D6, Wrist=D5.
 * Range clamped to 0-45 degrees. Pins 9 and 10 are reversed.
 */

#include <Servo.h>

const int NUM_SERVOS = 8;
const int pins[NUM_SERVOS] = {12, 11, 10, 9, 8, 7, 6, 5};  // Reversed order
const char* servoNames[NUM_SERVOS] = {
  "Thumb", "Index", "Middle", "Ring", "Pinky", "Shoulder", "Elbow", "Wrist"
};

// PIR Sensor
const int PIR_PIN = 3;
bool lastPirState = false;
unsigned long lastPirSendTime = 0;
const unsigned long PIR_DEBOUNCE_MS = 200;  // Min time between PIR reports

// Range configuration
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 45;

// Check if a pin should be reversed
bool isReversedPin(int pin) {
  return (pin == 9 || pin == 10);
}

Servo servos[NUM_SERVOS];
int currentPositions[NUM_SERVOS];
String inputBuffer = "";

void setup() {
  Serial.begin(9600);
  
  // Setup PIR sensor
  pinMode(PIR_PIN, INPUT);
  
  // Attach all servos
  int startPos = (MIN_ANGLE + MAX_ANGLE) / 2;  // Start at midpoint of range
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(pins[i]);
    currentPositions[i] = startPos;
    servos[i].write(startPos);
  }
  
  delay(1000);
  Serial.println("8-Servo Hand Control Ready - Listening for HAND8 commands");
  Serial.print("PIR Sensor on pin D");
  Serial.println(PIR_PIN);
  Serial.print("Range: ");
  Serial.print(MIN_ANGLE);
  Serial.print("-");
  Serial.println(MAX_ANGLE);
  Serial.println("Command mapping: pos0..pos7 -> servo -> pin");
  for (int i = 0; i < NUM_SERVOS; i++) {
    Serial.print("pos");
    Serial.print(i);
    Serial.print(" -> ");
    Serial.print(servoNames[i]);
    Serial.print(" -> D");
    Serial.print(pins[i]);
    if (isReversedPin(pins[i])) {
      Serial.print(" (REVERSED)");
    }
    Serial.println();
  }
}

void loop() {
  // Check PIR sensor and report motion to Python
  bool pirState = digitalRead(PIR_PIN) == HIGH;
  unsigned long now = millis();
  
  // Send PIR event on rising edge (motion detected) with debounce
  if (pirState && !lastPirState && (now - lastPirSendTime > PIR_DEBOUNCE_MS)) {
    Serial.println("PIR,1");
    lastPirSendTime = now;
  }
  lastPirState = pirState;
  
  // Read serial input
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      processCommand(inputBuffer);
      inputBuffer = "";
    } else {
      inputBuffer += c;
    }
  }
}

void processCommand(String command) {
  // Expected format: "HAND8,pos0,pos1,pos2,pos3,pos4,pos5,pos6,pos7"
  if (command.startsWith("HAND8,")) {
    // Remove "HAND8," prefix
    String data = command.substring(6);
    
    // Parse comma-separated values
    int positions[NUM_SERVOS];
    int index = 0;
    int lastComma = -1;
    
    for (int i = 0; i < NUM_SERVOS; i++) {
      int nextComma = data.indexOf(',', lastComma + 1);
      
      if (nextComma == -1) {
        // Last value
        positions[i] = data.substring(lastComma + 1).toInt();
      } else {
        positions[i] = data.substring(lastComma + 1, nextComma).toInt();
      }
      
      lastComma = nextComma;
    }
    
    // Set servo positions with mapping and constraints
    for (int i = 0; i < NUM_SERVOS; i++) {
      // Map 0-180 input to MIN_ANGLE-MAX_ANGLE output
      int pos = map(positions[i], 0, 180, MIN_ANGLE, MAX_ANGLE);
      pos = constrain(pos, MIN_ANGLE, MAX_ANGLE);
      
      // Reverse if this pin is in the reversed list
      if (isReversedPin(pins[i])) {
        pos = MAX_ANGLE - pos;
      }
      
      currentPositions[i] = pos;
      servos[i].write(pos);
    }
  }
}
