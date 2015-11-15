//Dimer - LED + Potenciometro
int pinoled =9;
int pinopot = A0;
int valorpot = 0;
int velocidade = 0;


void setup() {
  Serial.begin(9600);
  pinMode(pinoled, OUTPUT);
  pinMode(pinopot, OUTPUT);
}

void loop() {
  //Le o valor - analogico - do pino do potenciometro
  valorpot = analogRead(pinopot);

  //Converte e atribui para a variavel "luminosidade" o valor lido do potenciomentro
  velocidade = map(valorpot, 0, 1023, 0, 100);

  //Mostra o valor lido do potenciometro no monitor serial
  Serial.print("Velocidade: ");
  Serial.print(velocidade);

  digitalWrite(pinoled, HIGH);
  delay(velocidade);
  digitalWrite(pinoled, LOW);

}
