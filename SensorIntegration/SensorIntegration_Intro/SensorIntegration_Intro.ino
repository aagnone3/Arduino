#include <SoftwareSerial.h>
#include "TinyGPS.h"                 // Special version for 1.0
#include <DistanceSensor.h>
#include <ParallaxLCD.h>

#define ROWS 2
#define COLS 16

// Object Declarations
ParallaxLCD         lcd(2,2,16); // desired pin, rows, cols
DistanceSensor      distSens1(3,4,6); // trig, echo, motor pin declarations
//DistanceSensor      distSens2(
TinyGPS gps;
SoftwareSerial nss(8, 255);            // Yellow wire to pin 6


// Variable Declarations
long     sensorData,lastSensorData;
long     beginTime = millis();
long     timeMillis = 0;
int      loopNum = 0;
int      mins = 0;
int      secs = 0;
boolean  underThresholdState;
 
 
 
void setup () 
{
  delay(1000);
  Serial.begin(115200);
  nss.begin(4800);
  Serial.println("Reading GPS");
  
  for(unsigned int i=0;i < 5; ++i )
  {
      tone(4v,1000,50);
      delay(150);
  }
  /*
  lcd.setup();
  lcd.backLightOff();
  lcd.empty();
  lcd.backLightOn();
  lcd.at(0,1,"Hello World!");
  */
  
  distSens1.setThreshold(15);
}


void loop () 
{
    
    updateTime();
    //printTime(true);
    Serial.println("============================");
    Serial.print("Time Elapsed: ");
    Serial.print(mins);
    Serial.print(" mins,");
    Serial.print(secs);
    Serial.println(" secs");
    
    
    // Update the Distance Sensor
    distSens1.updateSensorData();
  
  
    if( distSens1.underThreshold() == true )
    {
        if(underThresholdState == false)
        {
            //lcd.empty();
            //lcd.at(0,1,"Under Thresh!");
            Serial.println("Under Threshold!!");
        }
    
          underThresholdState = true;
      }
      else
      {
          underThresholdState = false; 
      }
  

      // Print current distance data to the LCD
      Serial.print("Distance String Data: ");
      Serial.println(distSens1.getStringData());
      Serial.print("Distance(Feet): ");
      Serial.println(distSens1.getFeet());
  
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
      
  //updateScreen();
  lastSensorData = sensorData;
  //delay(100);
  
}





// Get and process GPS data
void gpsdump(TinyGPS &gps) 
{
  float latitude, longitude;
  unsigned long age;
  gps.f_get_position(&latitude, &longitude, &age);
  Serial.print("GPS Data: ");
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



/*
=========================================================
                  HELPER FUNCTIONS
=========================================================
*/


void updateScreen()
{
    if(++loopNum % 25 == 0)
    {
        lcd.empty();
        lcd.at(0,1,"DS1 Data");
        lcd.cr();
        lcd.at(1,1,distSens1.getStringData()); 
    }    
}


void updateTime()
{
    long timeMillis = millis() - beginTime;
    mins = timeMillis / 60000;
    secs = (timeMillis - (60000*mins)) / 1000;
}


void printTime(boolean updated)
{
    if(updated != true){updateTime();}
 
    lcd.empty();
    lcd.at(0,1,"Mins: ");
    lcd.at(0,7,mins);
    lcd.at(1,1,"Secs: ");
    lcd.at(1,7,secs);
}


long getMins(boolean updated)
{
    if(updated != true)
    {
        updateTime();
    }
 
    return mins;   
}


long getSecs(boolean updated)
{
    if(updated != true)
    {
        updateTime();
    }
 
    return secs;   
}
