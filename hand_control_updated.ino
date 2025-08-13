#include <Servo.h>

const int NUM_SERVOS = 4;
const int pins[NUM_SERVOS] = {8, 9, 10, 11};
const bool isMirrored[NUM_SERVOS] = {false, false, true, true};

Servo servos[NUM_SERVOS];
int currentAngles[NUM_SERVOS];
int targetAngles[NUM_SERVOS];
unsigned long lastUpdate[NUM_SERVOS];
int speeds[NUM_SERVOS];  // Dynamic speed intervals for hybrid responsiveness

// EXPANDED SERVO RANGE - matches Python interface (0-180)
const int minAngle = 0;
const int maxAngle = 180;

String inputBuffer = "";

void setup() {
  Serial.begin(9600);
  Serial.println("Hand Controller Ready - Hybrid Responsive Mode");
  
  // Initialize servos
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(pins[i]);
    currentAngles[i] = 90;  // Start at middle position
    targetAngles[i] = 90;
    lastUpdate[i] = 0;
    speeds[i] = 8;  // Default balanced speed
    writeMapped(i, currentAngles[i]);
  }
  
  delay(1000);
  Serial.println("Servos initialized - Hybrid mode active");
}

void loop() {
  unsigned long now = millis();
  
  // Handle commands from consciousness interface
  handleSerialInput();
  
  // Update servo positions with hybrid approach
  updateServoPositions(now);
}

void handleSerialInput() {
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
  if (command.startsWith("HAND,")) {
    // Parse hand command: "HAND,f0,f1,f2,f3"
    int commaIndex = command.indexOf(',');
    String fingerData = command.substring(commaIndex + 1);
    
    int fingerPositions[4];
    int index = 0;
    int lastComma = -1;
    
    for (int i = 0; i < 4 && index < 4; i++) {
      int nextComma = fingerData.indexOf(',', lastComma + 1);
      if (nextComma == -1 && i == 3) {
        fingerPositions[index] = fingerData.substring(lastComma + 1).toInt();
      } else if (nextComma != -1) {
        fingerPositions[index] = fingerData.substring(lastComma + 1, nextComma).toInt();
      }
      lastComma = nextComma;
      index++;
    }
    
    // Set targets with HYBRID ADAPTIVE SPEEDS
    for (int i = 0; i < NUM_SERVOS; i++) {
      int newTarget = constrain(fingerPositions[i], minAngle, maxAngle);
      targetAngles[i] = newTarget;
      
      // Calculate movement distance for this servo
      int distance = abs(newTarget - currentAngles[i]);
      
      // HYBRID APPROACH: Combine responsiveness with smoothness
      if (distance > 40) {
        // Large movements: Fast but not instant (prevents choppiness)
        speeds[i] = 2;  // 2ms intervals = very responsive but smooth
      } else if (distance > 20) {
        // Medium movements: Balanced speed
        speeds[i] = 4;  // 4ms intervals = good responsiveness
      } else if (distance > 8) {
        // Small movements: Smooth but still responsive
        speeds[i] = 6;  // 6ms intervals = smooth motion
      } else {
        // Fine adjustments: Prioritize smoothness
        speeds[i] = 12; // 12ms intervals = very smooth for precision
      }
    }
  }
  else if (command.startsWith("HEARTBEAT")) {
    Serial.println("Heartbeat acknowledged");
  }
}

void updateServoPositions(unsigned long now) {
  // HYBRID MOVEMENT: Variable timing + adaptive step sizes
  for (int i = 0; i < NUM_SERVOS; i++) {
    if (now - lastUpdate[i] >= speeds[i]) {
      int distance = abs(targetAngles[i] - currentAngles[i]);
      
      if (distance > 0) {
        // ADAPTIVE STEP SIZES for optimal movement
        int stepSize = 1;  // Default smooth step
        
        if (distance > 30 && speeds[i] <= 2) {
          // Large movements with fast timing: bigger steps for responsiveness
          stepSize = 4;
        } else if (distance > 15 && speeds[i] <= 4) {
          // Medium movements with medium timing: moderate steps
          stepSize = 2;
        } else if (distance > 5) {
          // Small movements: single steps for smoothness
          stepSize = 1;
        } else {
          // Final approach: minimal steps
          stepSize = 1;
        }
        
        // Move toward target
        if (currentAngles[i] < targetAngles[i]) {
          currentAngles[i] = min(currentAngles[i] + stepSize, targetAngles[i]);
        } else if (currentAngles[i] > targetAngles[i]) {
          currentAngles[i] = max(currentAngles[i] - stepSize, targetAngles[i]);
        }
        
        writeMapped(i, currentAngles[i]);
      }
      
      lastUpdate[i] = now;
    }
  }
}

void writeMapped(int i, int angle) {
  int mappedAngle = isMirrored[i] ? (180 - angle) : angle;
  servos[i].write(mappedAngle);
}