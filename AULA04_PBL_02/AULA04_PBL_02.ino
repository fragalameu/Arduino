const int sensorDark = 600;
int photocellPin = A0;
int LEDPin = 2;

void setup(){
  pinMode(LEDPin, OUTPUT);
}

void loop(){
  int analogValue;
  analogValue = analogRead(photocellPin);
  if(analogValue < sensorDark){
    digitalWrite(LEDPin, HIGH);
    }
  else{
    digitalWrite(LEDPin, LOW);
  }
  delay(1);
}
