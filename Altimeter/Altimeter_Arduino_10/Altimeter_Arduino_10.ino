#include <Wire.h>
#include "IntersemaBaro.h"

Intersema::BaroPressure_MS5607B baro(true);

void setup() { 
    Serial.begin(115200);
    baro.init();
}

void loop() 
{
  int alt = baro.getHeightCentiMeters();
  //Serial.print("Centimeters: ");
  //Serial.print((float)(alt));
  //Serial.print(", ");
  Serial.print("Altitude (feet): ");
  Serial.println((float)(alt) / 30.48);
  delay(1000);
}
