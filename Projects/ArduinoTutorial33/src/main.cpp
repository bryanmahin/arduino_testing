#include <Arduino.h>
#include <Servo.h>

int joyX=A0;
int joyY=A1;
int joyButton=2;
int joyX_Val;
int joyY_Val;
int joyButton_Val;
int servoPin1=5;
int servoPin2=6;
Servo myServo1;
Servo myServo2;
int servoPos1;
int servoPos2;
int buzzerPin=3;


int dt=200;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(joyX,INPUT);
  pinMode(joyY,INPUT);
  pinMode(joyButton,INPUT);
  pinMode(buzzerPin,OUTPUT);
  myServo1.attach(servoPin1);
  myServo2.attach(servoPin2);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(joyButton,HIGH);
  joyX_Val=analogRead(joyX);
  joyY_Val=analogRead(joyY);
  joyButton_Val=digitalRead(joyButton);
  // delay(dt);

  // Serial.print("joyX:");
  // Serial.print(joyX_Val);
  // Serial.print(" joyY:");
  // Serial.print(joyY_Val);
  // Serial.print(" joyButton:");
  // Serial.println(joyButton_Val);
  // delay(dt);

  servoPos1=map(joyX_Val, 0, 1023, 0, 180);
  servoPos2=map(joyY_Val, 0, 1023, 0, 180);

  myServo1.write(servoPos1);
  myServo2.write(servoPos2);
  
  if (joyButton_Val==0)
  {
    digitalWrite(buzzerPin,HIGH);
  } else
  {
    digitalWrite(buzzerPin,LOW);
  }
}