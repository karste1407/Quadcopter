#include "Arduino.h"
#include "GyroRead.h"

GyroRead::GyroRead(int pin) {
  _pin = pin;
}

int GyroRead::getRawValue() {
  return analogRead(_pin);
}

int GyroRead::getG() {
  int raw = getRawValue();
}
