const int rxPin = 8;
const int sound = 13;

void setup() {
 pinMode(rxPin, INPUT);
 pinMode(sound, OUTPUT); 
}

void loop() {
 int rx = pulseIn(rxPin, HIGH);
 tone(sound, map(rx, 1000, 2000, 0, 3000),map(pulseIn(9, HIGH), 1000, 2000, 0, 50));
 delay(10); 
}
