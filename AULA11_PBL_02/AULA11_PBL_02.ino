int porta_rele1 = 7;
int porta_rele2 = 8;
int botao1 = 2;
int botao2 = 3;
int estadorele1 = 1;
int estadorele2 = 1;
int leitura1 = 0;
int leitura2 = 0;


void setup() {
  pinMode(porta_rele1, OUTPUT);
  pinMode(porta_rele2, OUTPUT);

  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);

  digitalWrite(porta_rele1, HIGH);
  digitalWrite(porta_rele2, HIGH);

}

void loop() {
  leitura1 = digitalRead(botao1);
  if(leitura1!=0){
    while(digitalRead(botao1)!=0){
    delay(1000);
    
    estadorele1 = !estadorele1;
    digitalWrite(porta_rele1, estadorele1);
    }
  }

  leitura2 = digitalRead(botao2);
  if(leitura2!=0){
    while(digitalRead(botao2)!=0){
    delay(1000);
    
    estadorele2 = !estadorele2;
    digitalWrite(porta_rele2, estadorele2);
    }
  }
}
