
#include <Servo.h>

Servo servoLeft;
Servo servoRight;

void setup()
{
    //pinMode(13,OUTPUT);
    //pinMode(12,OUTPUT);  
    
    servoLeft.attach(13);
    servoLeft.writeMicroseconds(1500); 
    
    //servoLeft.attach(12);
    //servoLeft.writeMicroseconds(1500);
}


void loop()
{
    /*
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    delay(1000);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    delay(1000);
    */
 
       
}
