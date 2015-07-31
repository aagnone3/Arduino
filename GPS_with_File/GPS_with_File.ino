#include <SoftwareSerial.h>
#include "TinyGPS.h"
//#import processing.serial.*;

TinyGPS gps;
SoftwareSerial nss(6, 255);            // Yellow wire to pin 6
//Serial mySerial;
//PrintWriter output;

long beginTime = millis();
long timeMillis = 0;
int mins = 0;
int secs = 0;

void setup() 
{
  //mySerial = new Serial( this, Serial.list()[6], 9600 );
  //output = createWriter( "data.txt" );
  delay(1000);
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
    gpsdump(gps);
  else
    Serial.println("Data not ready");
  
  //draw();
}

// Get and process GPS data
void gpsdump(TinyGPS &gps) 
{
  float flat, flon;
  unsigned long age;
  gps.f_get_position(&flat, &flon, &age);
  Serial.print(flat, 4); Serial.print(", "); 
  Serial.println(flon, 4);
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

/*void draw() 
{
    if (mySerial.available() > 0 ) {
         String value = mySerial.readString();
         if ( value != null ) {
              output.println( value );
         }
    }
}*/
