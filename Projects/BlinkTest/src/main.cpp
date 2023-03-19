#include <Arduino.h>
int onboardLED=13;
int wait=250;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(onboardLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(onboardLED,HIGH);
delay(wait);
digitalWrite(onboardLED,LOW);
delay(wait);
Serial.println("Blink LED 123");

}