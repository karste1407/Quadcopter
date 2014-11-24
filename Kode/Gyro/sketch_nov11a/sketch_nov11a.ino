int gyroPin = 0, sampleSize = 10;
float gyroVoltage = 3.3, gyroZero = 1.65, gyroSensitivity = 0.057, gyroRate, gyroCali; //gyroRate og gyroCali får ikke en verdi, man sier på en måte "disse finnes, men har ikke en verdi enda". Vi gjør dette for at 'scope`et' til variabelen skal være over hele programmet, altså ikke bare inne i en funksjon

void setup() {
   pinMode(13, OUTPUT);
   analogReference(EXTERNAL); 
   Serial.begin(9600);
   digitalWrite(13, HIGH);
   delay(1000);
   calibrate();
   digitalWrite(13, LOW);
}

void loop() {
  gyroRate = getSample(gyroPin);
  gyroRate = wToV(gyroRate);
  gyroRate -= gyroCali;
  Serial.println(gyroRate);
  
  if(gyroRate > 0.2)  {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
}

void calibrate() {
  gyroCali = getSample(gyroPin);
  gyroCali = wToV(gyroCali);
}

float wToV(float input) {
  input *= gyroVoltage/1023;  
  input -= gyroZero;
  input /= gyroSensitivity;
  return input;
}

int getSample(int pin) {
  long tmp = 0;
    for(int i = 0; i < sampleSize; i++) {
      tmp += analogRead(pin);
    }
    
    return tmp/sampleSize;
}
