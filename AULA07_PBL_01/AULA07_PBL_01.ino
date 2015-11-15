
#include <SoftwareSerial.h>
SoftwareSerial BTserial(2,3); // RX | TX

char c = ' ';


void setup() {
  Serial.begin(9600);
  Serial.println("Arduino esta pronto!");
  Serial.println("Lembre-se de selecionar Both NL & CR no Monitor Serial:");
  BTserial.begin(38400);

}

void loop() {
  if (BTserial.available()){
      c = BTserial.read();
      Serial.write(c);
    }
  if(Serial.available()){
      c = Serial.read();
      BTserial.write(c);
    }
    
}
