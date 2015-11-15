const int sensorDark = 500;
int photocellPin = A1;
int LEDPin = 3;

void setup(){
  pinMode(LEDPin,INPUT);
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
