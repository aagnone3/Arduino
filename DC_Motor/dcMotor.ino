// dcMotor.pde - Run DC-motor to one direction

int motorPin = 6;

void setup()
{
 pinMode(motorPin,OUTPUT);
}

void loop()
{
 digitalWrite(motorPin,HIGH); 
 delay(1000);
 digitalWrite(motorPin,LOW);
 delay(500); 
}
