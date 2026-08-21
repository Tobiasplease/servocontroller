/*
 * 10-Servo Listener -- startup pose 40 deg on every channel
 * Generated from hardware config "Default"
 *
 * Receives: "HAND10,pos0,...,pos9"
 * Sends:    "PIR,1" on motion
 *
 * Channels are numbered, not named after anatomy -- this rig gets rewired
 * per project. The channel index is what the protocol and the UI agree on;
 * the pin is just where that channel is wired right now.
 *
 * S0 -> D12   startup 40
 * S1 -> D11   startup 40
 * S2 -> D10   startup 40
 * S3 -> D9    startup 40
 * S4 -> D8    startup 40
 * S5 -> D7    startup 40
 * S6 -> D6    startup 40
 * S7 -> D5    startup 40
 * S8 -> D4    startup 40
 * S9 -> D2    startup 40   <- moved off D3 to free it for the PIR
 *
 * POSITIONS ARE DEGREES, end to end -- startup pose and live frames alike. What
 * the UI slider reads is what the servo is told. There is no rescaling anywhere
 * in this sketch; MIN_ANGLE/MAX_ANGLE are a hardware backstop that clamps a bad
 * frame, not the expressive range. Set the expressive range in the UI, where it
 * is applied once.
 *
 * Reversal is applied by the HOST before the frame goes out, so it is not
 * repeated here -- doing both inverted an already-inverted value.
 *
 * PIR sensor on D3. D3 and D2 are the only external-interrupt pins on an Uno,
 * and a servo does not care which of them it sits on, so the sensor gets D3 and
 * S9 takes D2. The PIR pin is NOT fixed by the firmware -- it comes from
 * "pir_pin" in hardware_config.json and is baked in when the listener is
 * generated. It has to be a compile-time constant in the sketch, so changing it
 * in the UI means regenerating and reflashing.
 *
 * Baud 115200: a HAND10 frame is ~47 bytes = ~4.1ms of wire time.
 *
 * Regenerate from Hardware Config whenever pins, baud or reversal change, and
 * reflash -- the host will not warn you if they drift apart.
 */

#include <Servo.h>

const int NUM_SERVOS = 10;
const int pins[NUM_SERVOS] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 2};

const int PIR_PIN = 3;
bool lastPirState = false;
unsigned long lastPirSendTime = 0;
const unsigned long PIR_DEBOUNCE_MS = 200;

// Hardware backstop only -- full mechanical scale. The expressive range lives
// in the UI (Angle Range + per-channel limits) and is applied host-side, so it
// can be changed without touching this sketch.
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;

// Degrees. Edit these to re-pose the rest state.
const int startupPositions[NUM_SERVOS] = {40, 40, 40, 40, 40, 40, 40, 40, 40, 40};

Servo servos[NUM_SERVOS];
String inputBuffer = "";

// One path for every write -- startup pose and live frame land in the same
// place because they run the same two lines. Degrees in, degrees out.
void writeChannel(int channel, int deg) {
  servos[channel].write(constrain(deg, MIN_ANGLE, MAX_ANGLE));
}

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);

  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(pins[i]);
    writeChannel(i, startupPositions[i]);
  }

  delay(1000);
  Serial.println("10-Servo Listener Ready - awaiting HAND10 commands");
  Serial.print("PIR on D"); Serial.println(PIR_PIN);
  Serial.print("Range "); Serial.print(MIN_ANGLE);
  Serial.print("-"); Serial.println(MAX_ANGLE);
  for (int i = 0; i < NUM_SERVOS; i++) {
    Serial.print("S"); Serial.print(i);
    Serial.print(" -> D"); Serial.print(pins[i]);
    Serial.print(" start "); Serial.println(startupPositions[i]);
  }
}

void loop() {
  bool pirState = digitalRead(PIR_PIN) == HIGH;
  unsigned long now = millis();

  if (pirState && !lastPirState && (now - lastPirSendTime > PIR_DEBOUNCE_MS)) {
    Serial.println("PIR,1");
    lastPirSendTime = now;
  }
  lastPirState = pirState;

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
  if (!command.startsWith("HAND10,")) return;

  String data = command.substring(7);

  int positions[NUM_SERVOS];
  int parsed = 0;
  int lastComma = -1;

  for (int i = 0; i < NUM_SERVOS; i++) {
    int nextComma = data.indexOf(',', lastComma + 1);

    if (nextComma == -1) {
      // Last field. A short or truncated frame must leave the remaining
      // channels untouched, not slam them to whatever the tail happened
      // to be -- so stop here rather than reusing it.
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

  for (int i = 0; i < parsed; i++) {
    writeChannel(i, positions[i]);
  }
}
