#include <Arduino.h>
int ledPin=13;
int dt=1000;
// byte bNum=B00000110;
// byte flippedbNum;   

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


digitalWrite(ledPin,HIGH);
delay(dt);
digitalWrite(ledPin,LOW);
delay(dt);

// flippedbNum = ~bNum;
Serial.println("test");

}