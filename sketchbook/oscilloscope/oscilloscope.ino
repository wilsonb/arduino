#include "oscilloscope.h"

#define ANALOG_IN 0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(ANALOG_IN);
  writeOscilloscope(val);
}
