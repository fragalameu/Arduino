//Dimer - LED + Potenciometro
int pinoled =9;
int pinopot = A0;
int valorpot = 0;
int luminosidade = 0;


void setup() {
  Serial.begin(9600);
  pinMode(pinoled, OUTPUT);
  pinMode(pinopot, OUTPUT);
}

void loop() {
  //Le o valor - analogico - do pino do potenciometro
  valorpot = analogRead(pinopot);

  //Converte e atribui para a variavel "luminosidade" o valor lido do potenciomentro
  luminosidade = map(valorpot, 0, 1023, 0, 100);

  //Mostra o valor lido do potenciometro no monitor serial
  Serial.print("Valor lido do potenciometro: ");
  Serial.print(valorpot);

  //Mostra o valor da luminosidade no monitor serial
  Serial.print(" = Luminosidade : ");
  Serial.print(luminosidade);

  //Envia sinal analogico para a saída do led com luminosidade variavel
  analogWrite(pinoled, luminosidade);

}
