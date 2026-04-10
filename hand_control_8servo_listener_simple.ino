/*
 * 8-Servo Hand Control Listener (SIMPLIFIED - NO REVERSALS)
 * Receives: "HAND8,pos0,pos1,pos2,pos3,pos4,pos5,pos6,pos7"
 * Sends: "PIR,1" when motion detected
 *
 * Command index -> servo -> pin mapping:
 * pos0 -> Thumb    -> D12
 * pos1 -> Index    -> D11
 * pos2 -> Middle   -> D10
 * pos3 -> Ring     -> D9
 * pos4 -> Pinky    -> D8
 * pos5 -> Shoulder -> D7
 * pos6 -> Elbow    -> D6
 * pos7 -> Wrist    -> D5
 *
 * PIR Sensor on D3
 *
 * NOTE: This listener has NO reversal logic. Python handles all reversals
 * before sending positions. The listener just writes positions directly.
 */

#include <Servo.h>

const int NUM_SERVOS = 8;
const int pins[NUM_SERVOS] = {12, 11, 10, 9, 8, 7, 6, 5};
const char* servoNames[NUM_SERVOS] = {
  "Thumb", "Index", "Middle", "Ring", "Pinky", "Shoulder", "Elbow", "Wrist"
};

// PIR Sensor
const int PIR_PIN = 3;
bool lastPirState = false;
unsigned long lastPirSendTime = 0;
const unsigned long PIR_DEBOUNCE_MS = 200;

// Range configuration (should match Python config)
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;

Servo servos[NUM_SERVOS];
int currentPositions[NUM_SERVOS];
String inputBuffer = "";

void setup() {
  Serial.begin(9600);
  
  // Setup PIR sensor
  pinMode(PIR_PIN, INPUT);
  
  // Attach all servos and center them
  int startPos = (MIN_ANGLE + MAX_ANGLE) / 2;
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(pins[i]);
    currentPositions[i] = startPos;
    servos[i].write(startPos);
  }
  
  delay(1000);
  Serial.println("8-Servo Hand Control Ready (Simplified - No Reversals)");
  Serial.print("PIR Sensor on pin D");
  Serial.println(PIR_PIN);
  Serial.print("Range: ");
  Serial.print(MIN_ANGLE);
  Serial.print("-");
  Serial.println(MAX_ANGLE);
  Serial.println("Python handles all reversals before transmission");
}

void loop() {
  // Check PIR sensor and report motion to Python
  bool pirState = digitalRead(PIR_PIN) == HIGH;
  unsigned long now = millis();
  
  // Send PIR event on rising edge with debounce
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
    String data = command.substring(6);
    
    // Parse comma-separated values
    int positions[NUM_SERVOS];
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
    
    // Python has already mapped from logical 0-180 to hardware range (e.g., 0-45)
    // and applied reversals. We just write the positions directly.
    for (int i = 0; i < NUM_SERVOS; i++) {
      int pos = constrain(positions[i], MIN_ANGLE, MAX_ANGLE);
      currentPositions[i] = pos;
      servos[i].write(pos);
    }
  }
}
