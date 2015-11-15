int LEDRedPin = 5;
int LEDYellowPin = 4;
int LEDGreenPin = 3;
int LEDWhitePin = 2;

void setup(){
  Serial.begin(9600);
  pinMode(LEDRedPin, OUTPUT);
  pinMode(LEDYellowPin, OUTPUT);
  pinMode(LEDGreenPin, OUTPUT);
  pinMode(LEDWhitePin, OUTPUT);

}

void toggleLED(int LEDPin){
  digitalWrite(LEDPin, !digitalRead(LEDPin));
}

void loop(){
  if (Serial.available() > 0){
    
    int inByte = Serial.read();
    
    switch (inByte){
      case 'r':
        toggleLED(LEDRedPin);
        break;
      case 'y':
        toggleLED(LEDYellowPin);
        break;
      case 'g':
        toggleLED(LEDGreenPin);
        break;
      case 'w':
        toggleLED(LEDWhitePin);
        break;    
      default:
        digitalWrite(LEDRedPin, LOW);
        digitalWrite(LEDYellowPin, LOW);
        digitalWrite(LEDGreenPin, LOW);
        digitalWrite(LEDWhitePin, LOW);
        break;      
    }
  }
}
