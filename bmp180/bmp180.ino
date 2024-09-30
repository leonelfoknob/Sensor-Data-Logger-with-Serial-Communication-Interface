#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;
double Pressure,Altitude;

void setup() {
  Serial.begin(115200);
  if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1) {}
  }
}
  
void loop() {
  bmp180_compute();
  print_bmp180();
}

void bmp180_compute(){
  Pressure = bmp.readSealevelPressure();
  Altitude = bmp.readAltitude(101500);
}

void print_bmp180(){
    Serial.print("Basınç = ");
    Serial.print(Pressure);
    Serial.print(" Pa");
    Serial.print(" | ");
    Serial.print("Yükseklik = ");
    Serial.print(Altitude);
    Serial.println(" meters");
}
