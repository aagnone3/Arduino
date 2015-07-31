#include <SoftwareSerial.h>
#include "TinyGPS.h"                 // Special version for 1.0

TinyGPS gps;
SoftwareSerial nss(8, 255);            // Yellow wire to pin 6
long beginTime = millis();
long timeMillis = 0;
int mins = 0;
int secs = 0;

void setup() 
{
  delay(1000);
  //Serial.begin(9600);
  Serial.begin(115200);
  nss.begin(4800);
  Serial.println("Reading GPS");
}

void loop() 
{
    timeMillis = millis() - beginTime;
    mins = timeMillis / 60000;
    secs = (timeMillis - (60000*mins)) / 1000;
    Serial.print("Time Elapsed: ");
    Serial.print(mins);
    Serial.print(" mins,");
    Serial.print(secs);
    Serial.println(" secs");
    
  bool newdata = false;
  unsigned long start = millis();
  while (millis() - start < 5000) 
  {  // Update every 5 seconds
    if (feedgps())
      newdata = true;
  }
  if (newdata) 
  {
    gpsdump(gps);
  }

}

// Get and process GPS data
void gpsdump(TinyGPS &gps) 
{
  float latitude, longitude;
  unsigned long age;
  gps.f_get_position(&latitude, &longitude, &age);
  Serial.print(latitude, 4); Serial.print(", "); 
  Serial.println(longitude, 4);
}

// Feed data as it becomes available 
bool feedgps() 
{
  while (nss.available()) 
  {
    if (gps.encode(nss.read()))
      return true;
  }
  return false;
}
