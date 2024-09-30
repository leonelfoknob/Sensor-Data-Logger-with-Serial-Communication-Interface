#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>
#include <Wire.h>
#include "DHT.h"
#include <TinyGPS++.h>

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


Adafruit_MPU6050 mpu;
Adafruit_BMP085 bmp;
double Acc_X,Acc_Y,Acc_Z,Gyr_X,Gyr_Y,Gyr_Z,Pressure,Altitude,
dht11_temp_d,dht11_humidity;

static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
float Long,Lat,Speed;
int heures,minutes,secondes;


void setup(void) {
  Serial.begin(115200);
  Serial1.begin(GPSBaud);
  initialize_mpu6050();

  if (!bmp.begin()) {
  while (1) {}
  }

  dht.begin();
  
  delay(1000);
}

void loop() {
  mpu6050_compute();
  bmp180_compute();
  Dht11_compute();
  GPS_compute();
  save_data();
}


//mpu 6050 initializasyon
void initialize_mpu6050(){
  if (!mpu.begin()) {
    while (1) {
      delay(10);
    }
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBanupdate mpu6050 valuedwidth(MPU6050_BAND_5_HZ); 
}
//mpu650 verileri yenileme fonksyon
 void mpu6050_compute(){
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  Acc_X = a.acceleration.x;
  Acc_Y = a.acceleration.y;
  Acc_Z = a.acceleration.z;
  Gyr_X = g.gyro.x;
  Gyr_Y = g.gyro.y;
  Gyr_Z = g.gyro.z;
 }

 //bmp180 verileri okuma ve yenileme fonksyonu
 void bmp180_compute(){
  Pressure = bmp.readSealevelPressure();
  Altitude = bmp.readAltitude(101500);
}
// dht11 verileri okuma ve yenileme fonksyonu
void Dht11_compute(){
  dht11_humidity = dht.readHumidity();
  dht11_temp_d = dht.readTemperature();
}
// gps verileri okuma ve yenileme fonksyonu
void GPS_compute(){
  while (Serial1.available() > 0)
    if (gps.encode(Serial1.read()))
      Lat = gps.location.lat();
      Long = gps.location.lng();
      Speed = gps.speed.kmph();
      heures = gps.time.hour();
      minutes = gps.time.minute();
      secondes = gps.time.second() ;
  } 
//print value function
void save_data(){
  Serial.print(Acc_X);
  Serial.print(",");
  Serial.print(Acc_Y);
  Serial.print(",");
  Serial.print(Acc_Z);
  Serial.print(",");
  Serial.print(Gyr_X);
  Serial.print(",");
  Serial.print(Gyr_Y);
  Serial.print(",");
  Serial.print(Gyr_Z);
  Serial.print(",");
  Serial.print(Pressure);
  Serial.print(",");
  Serial.print(Altitude);
  Serial.print(",");
  Serial.print(dht11_humidity);
  Serial.print(",");
  Serial.print(dht11_temp_d);
  Serial.print(",");
  Serial.print(Lat);
  Serial.print(",");
  Serial.print(Long);
  Serial.print(",");
  Serial.print(Speed);
  Serial.println(",");
  
}
