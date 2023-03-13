#include <Arduino.h>
int tiltPin=2;
int tiltVal;
int dt=500;
int redPin=5;
int greenPin=6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(tiltPin,INPUT);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  digitalWrite(tiltPin,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

tiltVal=digitalRead(tiltPin);

Serial.println(tiltVal);
delay(dt);

if(tiltVal ==1)
  {
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
  }else
  {
    digitalWrite(greenPin,HIGH);
    digitalWrite(redPin,LOW);
  }

}