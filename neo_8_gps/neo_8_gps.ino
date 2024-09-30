#include <TinyGPS++.h>
/*
 * pinler şu şekilde bağlan
tx --> d19
rx --> d18
*/
static const uint32_t GPSBaud = 9600;
TinyGPSPlus gps;
float Long,Lat,Speed;
int heures,minutes,secondes;


void setup() {
    Serial.begin(9600);
    Serial1.begin(GPSBaud);

}

void loop() {
  get_gps_data();
  prit_gps_data();

}

// Get Latest GPS coordinates
void get_gps_data(){
  while (Serial1.available() > 0)
    if (gps.encode(Serial1.read()))
      Lat = gps.location.lat();
      Long = gps.location.lng();
      Speed = gps.speed.kmph();
      heures = gps.time.hour();
      minutes = gps.time.minute();
      secondes = gps.time.second() ;
  } 
   
void prit_gps_data(){
  Serial.print(Lat);Serial.print(" | ");Serial.print(Long);Serial.print(" | ");Serial.print(Speed);Serial.print(" | ");
  Serial.print(heures);Serial.print(" : ");Serial.print(minutes);Serial.print(" : ");Serial.println(secondes);
}
