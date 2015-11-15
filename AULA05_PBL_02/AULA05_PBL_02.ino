int timer = 200;

void setup(){
  for (int thisPin = 2; thisPin < 8; thisPin++)
  {
    pinMode(thisPin, OUTPUT);
  }
}

void loop(){
  for (int thisPin = 2; thisPin < 8; thisPin++)
  {
    // turn the pin on
    digitalWrite(thisPin, HIGH);
    // wait to turn it off sp we can see it
    delay(timer);
    //turn the pin off
    digitalWrite(thisPin, LOW);
  }
  
  for (int thisPin = 7; thisPin < 1; thisPin--)
  {
    // turn the pin on
    digitalWrite(thisPin, HIGH);
    // wait to turn it off sp we can see it
    delay(timer);
    //turn the pin off
    digitalWrite(thisPin, LOW);
  }
  
}
