#include <Arduino.h>
int latchPin=11;
int clockPin=9;
int dataPin=12;
int count=1;
int dt=250;

byte myNumb=0b00000001; //0b+binary 

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(latchPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(clockPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

if (myNumb == 255) 
  { 
    myNumb=0; 
  } else
  {
    // Serial.println(myNumb);
    myNumb=myNumb+1;
  }

digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,myNumb);
digitalWrite(latchPin,HIGH);
delay(dt);

}