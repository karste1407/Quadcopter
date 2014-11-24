#include "Arduino.h"
#include "Remote.h"

Remote::Remote(int pin){
  _pin = pin;
  _diff = 1;
}

int Remote::getValue() {
  int r = pulseIn(_pin, HIGH);
  _diff = _diff - r;
  return r;
}

int Remote::getDiff() {
  return _diff;
}
