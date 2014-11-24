const int SWITCH = 8;
int switchVal;
int max = 1500, min = 1500; //debug

void setup() {
  Serial.begin(9600);
}
double t;
int count = 0;
void loop() {
  count+=1;
  t = millis();
  switchVal=pulseIn(SWITCH, HIGH);
  for(int i = 0; i < map(switchVal, 1000, 2000, 0, 80); i++) {
    Serial.print("|"); 
  }
  Serial.println();
  for(int i = 0; i < sin((float)count/6)*50+25; i++) {
    Serial.print("&");
  }
  Serial.println();
  delay(10);
}
