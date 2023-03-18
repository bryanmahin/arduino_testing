#include <Arduino.h>
int latchPin=11;
int clockPin=9;
int dataPin=12;
int count=1;
int dt=3000;
byte binAdd=0b11001000;
byte binAddOLD;
int direction=0;
int rollTrigger=0;
int isOdd;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(latchPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(clockPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,binAdd);
digitalWrite(latchPin,HIGH);


if (direction==1)
{
binAdd=binAdd*2;
} else
{
  
  if (binAdd % 2 == 1)
  {
    binAdd=binAdd*8;
  }
 
  binAdd=binAdd/2;
}

delay(dt);

}