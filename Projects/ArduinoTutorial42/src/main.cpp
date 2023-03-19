#include <Arduino.h>
int latchPin=11;
int clockPin=9;
int dataPin=12;
int dt=150;
byte binAdd=0b10000000;
int direction=0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(latchPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(clockPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
// digitalWrite(latchPin,LOW);  //TEST 
// shiftOut(dataPin,clockPin,LSBFIRST,binAdd);
// digitalWrite(latchPin,HIGH);

if (direction==1)
{
// Serial.println(binAdd);
digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,binAdd);
digitalWrite(latchPin,HIGH);
binAdd=binAdd*128+binAdd/2;  
} 

if (direction==0) 
{
// Serial.println(binAdd);
digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,binAdd);
digitalWrite(latchPin,HIGH);
binAdd=binAdd/128+binAdd*2;  
}

delay(dt);

}