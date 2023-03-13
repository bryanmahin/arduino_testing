#include <Arduino.h>

int button1=7;
int button2=8;
int button1val;
int button2val;
int redLED=3;
int brightness=0;
int brightnessSpeed=8;
int buzzer=4;
int buzzerDelay=500;
int dt=50;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(button1,INPUT);
pinMode(button2,INPUT);
pinMode(redLED,OUTPUT);
pinMode(buzzer,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  button1val=digitalRead(button1);
  button2val=digitalRead(button2);


  if (button1val==0)
  {
   Serial.println(brightness);
   analogWrite(redLED,brightness);
   brightness=brightness+brightnessSpeed;
   delay(dt);

  }

   if (button2val==0)
  {
   Serial.println(brightness);
   analogWrite(redLED,brightness);
   brightness=brightness-brightnessSpeed;
   delay(dt);
  }

  if(brightness>255)
  {
    brightness=255;
    digitalWrite(buzzer,HIGH);
    delay(buzzerDelay);
    digitalWrite(buzzer,LOW); 
  }
  if(brightness<0)
  {
    brightness=0;
    digitalWrite(buzzer,HIGH);
    delay(buzzerDelay);
    digitalWrite(buzzer,LOW); 
  } 

}