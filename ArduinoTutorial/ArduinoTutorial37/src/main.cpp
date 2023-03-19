#include <Arduino.h>
int speedPin=5;
int dir1=4;
int dir2=3;
int mSpeed=150;
int mStart=255;
int joyx=A0;
int xVal;



void setup() {
  // put your setup code here, to run once:
pinMode(speedPin,OUTPUT);
pinMode(dir1,OUTPUT);
pinMode(dir2,OUTPUT);
pinMode(joyx,INPUT);
Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:



xVal=analogRead(joyx);



if (xVal > 513 && xVal < 517)
{
  digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  analogWrite(speedPin,0);
  Serial.println(xVal);
}
if (xVal < 513)
{
  mSpeed=map(xVal, 513, 0, 83, 255);
  analogWrite(speedPin,mSpeed);
  Serial.println(xVal);
}
if (xVal > 517)
{
  digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
  mSpeed=map(xVal, 517, 1023, 83, 255);
  analogWrite(speedPin,mSpeed);
  Serial.println(xVal);
}

}