int potPin = A0;
int ledPins[]={2,3,4,5,6,7};
int ledCount = sizeof(ledPins)/sizeof(ledPins[0]);


void setup() {
  for(int thisLed = 0; thisLed < ledCount; thisLed++){
    pinMode(ledPins[thisLed], OUTPUT);  
  }

}

void loop() {
  int potReading = analogRead(potPin);
  int ledLevel = map(potReading, 0, 1023,0, ledCount);

  for(int thisLed = 0; thisLed < ledCount; thisLed++){
        if(thisLed < ledLevel){
            digitalWrite(ledPins[thisLed], HIGH);  
        }else{
            digitalWrite(ledPins[thisLed], LOW);  
        }       
  }
}
