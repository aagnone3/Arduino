// Digital Input and Output Game


int currentLED = 2;
int delayValue = 200;

void setup()
{
  Serial.print("Fucking anything");
 // initialize digital pin 13 as input
pinMode(13,INPUT);

//initialize digital pin 2 to 5 as output
pinMode(2,OUTPUT); // white LED
pinMode(3,OUTPUT); // yellow LED
pinMode(4,OUTPUT); // green LED
pinMode(5,OUTPUT); // red LED
}

int checkInput()
{
 if (digitalRead(13) == 0)
 {
  return 1;
 } 
 else
 {
  return 0; 
 }
}

void loop()
{
  Serial.print(currentLED);
 // Check if the button is pressed at the right moment
 if (digitalRead(13) == 0)
 {
     if (currentLED == 4) 
     {
       // Blink correct (green) LED
      digitalWrite(4,HIGH);
      delay(200);
      digitalWrite(4,LOW);
      delay(200);
      digitalWrite(4,HIGH);
      delay(200);
      digitalWrite(4,LOW);
      delay(200);
     
     // Speed up the LEDs 
     delayValue = delayValue - 20; 
     }
     
     else
     {
      // Blink the wrong LED
     digitalWrite(currentLED,HIGH);
     delay(200);
     digitalWrite(currentLED,LOW);
     delay(200);
     digitalWrite(currentLED,HIGH);
     delay(200);
     digitalWrite(currentLED,LOW);
     delay(200); 
     }
 } 
 
 // Loop LED from white --> yellow --> green --> red
 digitalWrite(currentLED,HIGH);
 delay(delayValue);
 digitalWrite(currentLED,LOW);
 delay(delayValue);
 currentLED = currentLED + 1;
 Serial.print(currentLED);
 if (currentLED > 5)
 {
  currentLED = 2; 
 }
}
