#include "DHT.h"
#define DHTPIN A1
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("DHT - OK");
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if(isnan(t)||isnan(h)){
    Serial.println("Failed to read from DHT");  
  }else{
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print(" ");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println("C");
  }
  delay(3000);
}