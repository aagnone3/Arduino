/*
Digital Input
*/

const int buttonPin = 13; //using digital pin 13 for the button pin
int buttonState = 0; // variable for storing the button status

void setup()
{
 // initialize the pushbutton pin as as input
pinMode(buttonPin,INPUT); 
  
  // initialize the serial port
  Serial.begin(9600); // start serial for output
}

void loop()
{  
 // read the state of the pushbutton value
buttonState = digitalRead(buttonPin);

// output button state
Serial.print("\nThe Button State is ");
Serial.print(buttonState);

// Delay 1000ms
delay(1000);
}
