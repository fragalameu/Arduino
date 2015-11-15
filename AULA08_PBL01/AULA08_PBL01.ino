#include "DHT.h"
#define DHTPIN A5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE); 

void setup() {
 Serial.begin(9600);
 dht.begin();
}

void loop() {
  float umidade;
  float temperatura;

  if(Serial.available() >0){
    int inByte = Serial.read();

      switch(inByte){
        case 'u': 
          umidade = dht.readHumidity();
          if(isnan(umidade)){
            Serial.println("DHT11 com erro - Sem leitura de umidade");
          }else{
            Serial.print("Umidade: ");
            Serial.print(umidade);
            Serial.println(" %");
          }
          break;
        case 't': 
          temperatura = dht.readTemperature();
          if(isnan(temperatura)){
            Serial.println("DHT11 com erro - Sem leitura de temperatura");
          }else{
            Serial.print("Temperatura: ");
            Serial.print(temperatura);
            Serial.println(" C");
          }
          break;  
          default:
            Serial.println("Sem leitura");
            break;
        }
  }

}
