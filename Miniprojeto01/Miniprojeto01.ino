
// sensor minimum, discovered through experiment
const int sensorMin = 0;

//sensor maximum, discovered through experiment
const int sensorMax = 500;


int photocellPin = A0;
int LEDPinWhite = 4;
int LEDPinYellow = 3;
int LEDPinRed = 2;

void setup(){
  pinMode(LEDPinWhite, OUTPUT);
  pinMode(LEDPinYellow, OUTPUT);
  pinMode(LEDPinRed, OUTPUT);
  
}

void loop(){
  int analogValue; 
  int range;
  
  //read our photocell
  analogValue = analogRead(photocellPin);
  
  //map the sensor range to a range of four options
  range = map(analogValue, sensorMin, sensorMax, 0,2);
  
  switch(range){
    case 0:
      digitalWrite(LEDPinYellow, HIGH);
      digitalWrite(LEDPinRed, LOW);
      digitalWrite(LEDPinWhite, LOW);
      break;
    case 1:
      digitalWrite(LEDPinYellow, LOW);
      digitalWrite(LEDPinRed, HIGH);
      digitalWrite(LEDPinWhite, LOW);
      break;
    case 2:
      digitalWrite(LEDPinYellow, LOW);
      digitalWrite(LEDPinRed, LOW);
      digitalWrite(LEDPinWhite, HIGH);
      break;
   
  }
  
  delay(250);
}
