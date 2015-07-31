// stalkerGuard

const int pingPin = 2;
const int motorPin = 6;
long int duration, distanceInches, distanceCm;
int limitCm = 10;

void setup()
{
 pinMode(motorPin,OUTPUT); 
}

void loop()
{
 pinMode(pingPin,OUTPUT);
 digitalWrite(pingPin,LOW);
 delayMicroseconds(2);
 digitalWrite(pingPin,HIGH);
 delayMicroseconds(6);
 digitalWrite(pingPin,LOW);
 
 pinMode(pingPin,INPUT);
 duration = pulseIn(pingPin,HIGH);
 
 distanceInches = microsecondsToInches(duration);
 distanceCm = microsecondsToCentimeters(duration);
 
 checkLimit();
 delay(100);
}

void checkLimit()
{
 if (distanceCm < limitCm)
 {
  digitalWrite(motorPin,HIGH);
 } 
 else
 {
  digitalWrite(motorPin,LOW); 
 }
}

long microsecondsToInches(long microseconds)
{
 return microseconds / 74 / 2; 
}

long microsecondsToCentimeters(long microseconds)
{
 return microseconds / 29 / 2; 
}

