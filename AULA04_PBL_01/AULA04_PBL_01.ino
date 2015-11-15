// sensor minimum, discovered through experiment
const int sensorMin = 0;

//sensor maximum, discovered through experiment
const int sensorMax = 800;

// the photocell voltage divider pin
int photocellPin = A0;

void setup(){
  // set up serial at 9600 baud
  Serial.begin(9600);
}

void loop(){
  int analogValue; 
  int range;
  
  //read our photocell
  analogValue = analogRead(photocellPin);
  
  //map the sensor range to a range of four options
  range = map(analogValue, sensorMin, sensorMax, 0,3);
  
  switch(range){
    case 0:
      Serial.println("dark");
      break;
    case 1:
      Serial.println("dim");
      break;
    case 2:
      Serial.println("medium");
      break;
    case 3:
      Serial.println("bright");
      break;  
  }
  
  delay(250);
  
}
