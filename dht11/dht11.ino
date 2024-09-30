#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

float dht11_temp_d,dht11_temp_f,dht11_humidity;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  Dht11_compute();
  Dht11_print();
  delay(1000);
}

void Dht11_compute(){
  dht11_humidity = dht.readHumidity();
  dht11_temp_d = dht.readTemperature();
  dht11_temp_f = dht.readTemperature(true);
}

void Dht11_print(){
  Serial.print(F("Humidity: "));
  Serial.print(dht11_humidity);
  Serial.print(F("%  Temperature: "));
  Serial.print(dht11_temp_d);
  Serial.print(F("°C "));
  Serial.println(dht11_temp_f);
}
