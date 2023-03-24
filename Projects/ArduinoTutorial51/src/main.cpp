#include <Arduino.h>

int trigPin=12;
int echoPin=11;
int pingTravelTime;
int dt=10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(trigPin,LOW);
delayMicroseconds(10);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
delay(25);
pingTravelTime=pulseIn(echoPin,HIGH);

Serial.println(pingTravelTime);
delay(500);

}