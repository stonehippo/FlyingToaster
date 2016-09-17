#include <Arduino.h>

#include "FlyingToaster.h"

const int servoPin = 9;
const int flapInterval = 10;

Servo flapper;

void setup() {
  flapper.attach(servoPin);
  //set the position of the servo to start and wait for a while
  flapper.write(0);
  delay(5000);
  flapper.write(180);
  delay(5000);
}

void loop() {
  flap(&flapper, flapInterval);
}

void flap(Servo *s, int interval) {
  int pos = 0;

  for (pos = 0; pos < 180; pos += 1) {
    s -> write(pos);
    delay(interval);
  }

  for (pos = 180; pos >= 1; pos -= 1) {
    s -> write(pos);
    delay(interval);
  }
}
