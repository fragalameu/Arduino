#include "DHT.h"
#define DHTPIN A1
#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("DHT - OK");
  dht.begin();
}

void loop() {
  // A leitura da temperatura e umidade pode levar 250ms !
  //o atraso do sensor pode chegar a 2 segundos.
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  //testa se o retorno é válido, caso contrário algo está errado
  if (isnan(t)||isnan(h)){
      Serial.println("Faied to read from DHT");
    }
  else{
      Serial.print("Umidade: ");
      Serial.print(h);
      Serial.print("  ");
      Serial.print("Temperatura: ");
      Serial.print(t);
      Serial.println(" C");
    }

  delay(3000);

}
