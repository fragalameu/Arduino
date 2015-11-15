int LEDRedPin = 5;
int LEDYellowPin = 4;
int LEDGreenPin = 3;


void setup(){
  Serial.begin(9600);
  pinMode(LEDRedPin, OUTPUT);
  pinMode(LEDYellowPin, OUTPUT);
  pinMode(LEDGreenPin, OUTPUT);
 

}


void loop(){

        digitalWrite(LEDGreenPin, HIGH);
        delay(3000);
        digitalWrite(LEDGreenPin, LOW);   
        digitalWrite(LEDYellowPin, HIGH);
        delay(500);
        digitalWrite(LEDYellowPin, LOW);
        digitalWrite(LEDRedPin, HIGH);
        delay(2000);
        digitalWrite(LEDRedPin, LOW);
       
}
