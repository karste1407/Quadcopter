#include "GyroRead.h"

GyroRead x = new GyroRead(8);

void setup() {
 Serial.begin(9600);
}

void loop() {
 Serial.println(x->getRawValue());
}