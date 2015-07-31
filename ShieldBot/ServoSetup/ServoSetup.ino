
#include <Servo.h>

Servo servoLeft;
Servo servoRight;

void setup()
{
    //pinMode(13,OUTPUT);
    //pinMode(12,OUTPUT);  
    
    servoRight.attach(12);
    servoLeft.attach(13);
    
    /*
    servoRight.writeMicroseconds(1300);
    delay(3000);
    servoRight.writeMicroseconds(1500);
    delay(1000);
    servoRight.writeMicroseconds(1700);
    delay(3000);
    servoRight.writeMicroseconds(1500);
    */
    //servoLeft.writeMicroseconds(1300); 
    //servoLeft.writeMicroseconds(1700);
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
    
    servoRight.writeMicroseconds(1400);
    servoLeft.writeMicroseconds(1600);
    delay(1000);
       
}
