/* 
 	NOTE: you must: #include <SoftwareSerial.h>
 	BEFORE including the ParallaxLCD.h header
 */

#include <SoftwareSerial.h>
#include <ParallaxLCD.h>

#define ROWS 2
#define COLS 16

ParallaxLCD lcd(2,2,16); // desired pin, rows, cols

/**
 * Initialize the 2-dimensional custom character byte array.
 * Even though each 'byte' is 0-255, only the lowest 5 bytes are used. So only
 *  0-31 are valid values.
 */
 
/* 
byte customCharacters[8][8] = {0, 4, 14, 31, 14, 4, 0, 0,   // Diamond
                               0, 10, 14, 31, 31, 14, 4, 0, // Heart
                               0, 4, 14, 31, 14, 4, 14, 0,  // Spade
                               4, 14, 4, 10, 31, 10, 4, 14, // Club (sorta...)
                               4, 14, 21, 4, 4, 4, 4, 4,    // Up
                               4, 4, 4, 4, 4, 21, 14, 4,    // Down
                               27, 22, 13, 27, 22, 13, 27, 22, // Stipple pattern #1
                               29, 14, 23, 27, 29, 14, 23, 27  // Stipple pattern #2
                             };
                             */
void setup () 
{
  lcd.setup();
  //lcd.backLightOff();
  lcd.empty();
  lcd.backLightOn();
  
}


void loop () 
{
  lcd.empty();
  lcd.pos(0,0);
  lcd.at(0,1,"Hello World!");
  delay(10000);
  
  //lcd.at(2,9,millis());
}


