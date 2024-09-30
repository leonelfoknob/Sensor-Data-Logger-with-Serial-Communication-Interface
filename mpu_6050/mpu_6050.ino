#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;
double Acc_X,Acc_Y,Acc_Z,Gyr_X,Gyr_Y,Gyr_Z;

void setup(void) {
  Serial.begin(115200);
  initialize_mpu6050();
  delay(1000);
}

void loop() {
  update_mpu_val();
  print_mpu_val();
}
void initialize_mpu6050(){
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ); 
}
//update mpu6050 value
 void update_mpu_val(){
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  Acc_X = a.acceleration.x;
  Acc_Y = a.acceleration.y;
  Acc_Z = a.acceleration.z;
  Gyr_X = g.gyro.x;
  Gyr_Y = g.gyro.y;
  Gyr_Z = g.gyro.z;
 }
//print gyroscope and acceleration value
void print_mpu_val(){
  Serial.print("Acceleration X: ");
  Serial.print(Acc_X);
  Serial.print(", Y: ");
  Serial.print(Acc_Y);
  Serial.print(", Z: ");
  Serial.print(Acc_Z);
  Serial.print(" m/s^2");
  Serial.print(" | ");
  Serial.print("Rotation X: ");
  Serial.print(Gyr_X);
  Serial.print(", Y: ");
  Serial.print(Gyr_Y);
  Serial.print(", Z: ");
  Serial.print(Gyr_Z);
  Serial.println(" rad/s");
}
