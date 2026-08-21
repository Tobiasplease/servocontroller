/*
 * 10-Servo Hand Control Listener (ACTIVE)
 * Receives: "HAND10,pos0,pos1,...,pos9"
 * Sends: "PIR,1" when motion detected
 *
 * Channels are numbered, not named after anatomy -- this rig gets rewired
 * per project. Channel index is what the protocol and the UI agree on; the
 * pin is just where that channel happens to be wired right now.
 *
 * Channel -> pin mapping (must match pin_mapping in hardware_config.json):
 * S0 -> D12
 * S1 -> D11
 * S2 -> D10
 * S3 -> D9
 * S4 -> D8
 * S5 -> D7
 * S6 -> D6
 * S7 -> D5
 * S8 -> D4
 * S9 -> D3   <- added in the 8 -> 10 expansion
 *
 * PIR Sensor on D2. It used to sit on D3; that pin now drives S9, so the
 * sensor moved. D2 is also an external-interrupt pin if you ever want one.
 *
 * Baud is 115200, NOT 9600. A HAND10 frame is ~46 bytes, which is ~48ms of
 * wire time at 9600 -- longer than the host's send interval, so frames would
 * queue and lag without ever catching up. At 115200 the same frame is ~4ms.
 * The host reads its baud from hardware_config.json; keep the two in sync.
 */

#include <Servo.h>

const int NUM_SERVOS = 10;
const int pins[NUM_SERVOS] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3};

// PIR Sensor
const int PIR_PIN = 2;
bool lastPirState = false;
unsigned long lastPirSendTime = 0;
const unsigned long PIR_DEBOUNCE_MS = 200;  // Min time between PIR reports

// Range configuration. Keep in step with global_min_angle / global_max_angle
// in hardware_config.json -- the host already clamps per channel before
// sending, so this is the hardware backstop, not the expressive range.
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;

// Channel indices to invert. Reversal is per CHANNEL, not per pin: rewiring
// changes which pin a channel uses, but not which way that joint should run.
// Must match "reversed_servos" in hardware_config.json.
const int NUM_REVERSED = 0;
const int reversedChannels[] = {};

bool isReversedChannel(int channel) {
  for (int i = 0; i < NUM_REVERSED; i++) {
    if (reversedChannels[i] == channel) return true;
  }
  return false;
}

Servo servos[NUM_SERVOS];
int currentPositions[NUM_SERVOS];
String inputBuffer = "";

void setup() {
  Serial.begin(115200);

  pinMode(PIR_PIN, INPUT);

  // Attach all servos at the midpoint of the allowed range
  int startPos = (MIN_ANGLE + MAX_ANGLE) / 2;
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(pins[i]);
    currentPositions[i] = startPos;
    servos[i].write(startPos);
  }

  delay(1000);
  Serial.println("10-Servo Hand Control Ready - Listening for HAND10 commands");
  Serial.print("PIR Sensor on pin D");
  Serial.println(PIR_PIN);
  Serial.print("Range: ");
  Serial.print(MIN_ANGLE);
  Serial.print("-");
  Serial.println(MAX_ANGLE);
  Serial.println("Channel mapping: S<n> -> pin");
  for (int i = 0; i < NUM_SERVOS; i++) {
    Serial.print("S");
    Serial.print(i);
    Serial.print(" -> D");
    Serial.print(pins[i]);
    if (isReversedChannel(i)) {
      Serial.print(" (REVERSED)");
    }
    Serial.println();
  }
}

void loop() {
  // Check PIR sensor and report motion to the host
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
    } else if (c != '\r') {
      inputBuffer += c;
    }
  }
}

void processCommand(String command) {
  // Expected format: "HAND10,pos0,pos1,...,pos9"
  if (!command.startsWith("HAND10,")) {
    return;
  }

  String data = command.substring(7);  // strip "HAND10,"

  int positions[NUM_SERVOS];
  int parsed = 0;
  int lastComma = -1;

  for (int i = 0; i < NUM_SERVOS; i++) {
    int nextComma = data.indexOf(',', lastComma + 1);

    if (nextComma == -1) {
      // Last value on the line. If fields ran out early, stop parsing here
      // rather than reading the same tail repeatedly -- a short or truncated
      // frame must leave the remaining channels untouched, not slam them all
      // to whatever the final field happened to be.
      String tail = data.substring(lastComma + 1);
      if (tail.length() == 0) break;
      positions[i] = tail.toInt();
      parsed = i + 1;
      break;
    }

    positions[i] = data.substring(lastComma + 1, nextComma).toInt();
    parsed = i + 1;
    lastComma = nextComma;
  }

  // Only apply channels the frame actually carried
  for (int i = 0; i < parsed; i++) {
    int pos = map(positions[i], 0, 180, MIN_ANGLE, MAX_ANGLE);
    pos = constrain(pos, MIN_ANGLE, MAX_ANGLE);

    if (isReversedChannel(i)) {
      pos = MAX_ANGLE - pos;
    }

    currentPositions[i] = pos;
    servos[i].write(pos);
  }
}
