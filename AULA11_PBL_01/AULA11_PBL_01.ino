int porta_rele1 = 7;
int porta_rele2 = 8;


void setup() {
  pinMode(porta_rele1, OUTPUT);
  pinMode(porta_rele2, OUTPUT);

}

void loop() {
  digitalWrite(porta_rele1, LOW);
  digitalWrite(porta_rele2, HIGH);
  delay(2000);


 digitalWrite(porta_rele2, LOW);
  digitalWrite(porta_rele1, HIGH);
  delay(2000);
  

}
