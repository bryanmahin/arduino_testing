#include <Arduino.h>
#include <Servo.h>
int photoSen=A0;
int photoVal;
int servoPin=9;
int servoPos;
int servoBuffer=500;
Servo myServo;
String msg1="What angle for the Servo?";
int lightOff=0;
int lightOn=180;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(photoSen,INPUT);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  photoVal=analogRead(photoSen);
  Serial.println(photoVal);

  servoPos=map(photoVal, 500, 800, 0, 180);

  if(photoVal > 700 )
  {
  myServo.write(lightOn);

  } else { myServo.write(lightOff); }

  delay(servoBuffer);
  Serial.println(photoVal);
}