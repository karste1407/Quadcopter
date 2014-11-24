#include "Arduino.h"

class Remote {
 public:
  Remote(int pin);
  int getValue();
  int getDiff();

 private:
  int _pin;
  int _diff;
};
