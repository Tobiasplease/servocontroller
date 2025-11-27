/*
 * 8-Servo Hand Control Listener
 * Listens for HAND8 commands from Python and sets servo positions
 * 
 * Pin mapping (reversed order to match wiring):
 * Pin 12: Thumb (servo 0)
 * Pin 11: Index (servo 1)
 * Pin 10: Middle (servo 2)
 * Pin 9: Ring (servo 3)
 * Pin 8: Pinky (servo 4)
 * Pin 7: Shoulder (servo 5)
 * Pin 6: Elbow (servo 6)
 * Pin 5: Wrist (servo 7)
 */

#include <Servo.h>

const int NUM_SERVOS = 8;
const int pins[NUM_SERVOS] = {12, 11, 10, 9, 8, 7, 6, 5};  // Reversed order

Servo servos[NUM_SERVOS];
int currentPositions[NUM_SERVOS];
String inputBuffer = "";

void setup() {
  Serial.begin(9600);
  
  // Attach all servos
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(pins[i]);
    currentPositions[i] = 90;  // Start at center
    servos[i].write(90);
  }
  
  delay(1000);
  Serial.println("8-Servo Hand Control Ready - Listening for HAND8 commands");
}

void loop() {
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
    
    // Set servo positions with constraints
    for (int i = 0; i < NUM_SERVOS; i++) {
      int pos = constrain(positions[i], 0, 180);
      currentPositions[i] = pos;
      servos[i].write(pos);
    }
  }
}
