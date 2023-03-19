#include <Arduino.h>
int button=2;
int buttonVal;
int dt=100;
int buzzer=4;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(button,INPUT);
digitalWrite(button,HIGH);
pinMode(buzzer,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

buttonVal=digitalRead(button);
Serial.println(buttonVal);
// delay(dt);

if(buttonVal==0)
{
  digitalWrite(buzzer,HIGH);
} else
{
  digitalWrite(buzzer,LOW);
}

}