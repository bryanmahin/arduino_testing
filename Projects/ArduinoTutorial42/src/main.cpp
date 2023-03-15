#include <Arduino.h>
int latchPin=11;
int clockPin=9;
int dataPin=12;
int count=1;
int dt=125;

byte myNumb=0b00000000; //0b+binary 

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
shiftOut(dataPin,clockPin,LSBFIRST,myNumb);
digitalWrite(latchPin,HIGH);
delay(dt);
myNumb=myNumb+1;

}