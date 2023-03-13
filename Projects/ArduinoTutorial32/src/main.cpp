#include <Arduino.h>
#include <servo
int joyX=A0;
int joyY=A1;
int joyButton=2;
int joyX_Val;
int joyY_Val;
int joyButton_Val;



int dt=200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(joyX,INPUT);
  pinMode(joyY,INPUT);
  pinMode(joyButton,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(joyButton,HIGH);
  joyX_Val=analogRead(joyX);
  joyY_Val=analogRead(joyY);
  joyButton_Val=digitalRead(joyButton);
  delay(dt);

  Serial.print("joyX:");
  Serial.print(joyX_Val);
  Serial.print(" joyY:");
  Serial.print(joyY_Val);
  Serial.print(" joyButton:");
  Serial.println(joyButton_Val);
  delay(dt);
}