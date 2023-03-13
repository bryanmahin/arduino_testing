#include <Arduino.h>
int speedPin=5;
int dir1=4;
int dir2=3;
int mSpeed=90;
int mStart=150;
int mStartDelay=50;
int joyx=A0;
int xVal;
int upPin=8;
int downPin=9;
int upVal;
int downVal;
int dt=10;
int fanDir=500; //1-499 is reverse, 500 is stopped, 501-1000 forward.


void setup() {
  // put your setup code here, to run once:
pinMode(speedPin,OUTPUT);
pinMode(dir1,OUTPUT);
pinMode(dir2,OUTPUT);
pinMode(joyx,INPUT);
pinMode(upPin,OUTPUT);
pinMode(downPin,OUTPUT);
digitalWrite(upPin,HIGH);
digitalWrite(downPin,HIGH);
Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:

upVal=digitalRead(upPin);
downVal=digitalRead(downPin);

if (fanDir == 500)
    {
      digitalWrite(dir1,HIGH);
      digitalWrite(dir2,LOW);
      analogWrite(speedPin,0);
      Serial.print("mSpeed:");
      Serial.print(mSpeed);
      Serial.print(" ");
      Serial.print("fanDir:");
      Serial.println(fanDir);
    }

if (upVal==0 && fanDir >= 500 && fanDir <= 664) 
  { 

    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    if (mSpeed < 95)
    {
      analogWrite(speedPin,mStart);
      delay(mStartDelay);
    }
    analogWrite(speedPin,mSpeed);
    mSpeed=mSpeed+1;
    fanDir=fanDir+1;
    Serial.print("mSpeed:");
    Serial.print(mSpeed);
    Serial.print(" ");
    Serial.print("fanDir:");
    Serial.println(fanDir);
  } 

if (downVal==0 && fanDir >= 501 && fanDir <= 665) 
  { 
    digitalWrite(dir1,HIGH);
    digitalWrite(dir2,LOW);
    analogWrite(speedPin,mSpeed);
    mSpeed=mSpeed-1;
    fanDir=fanDir-1;
    Serial.print("mSpeed:");
    Serial.print(mSpeed);
    Serial.print(" ");
    Serial.print("fanDir:");
    Serial.println(fanDir);
  } 


  // if (downVal == 0 && fanDir > 500 && fanDir <= 665) 
  // { 
  //   digitalWrite(dir1,HIGH);
  //   digitalWrite(dir2,LOW);
  //   analogWrite(speedPin,mSpeed);
  //   delay(dt);
  //   mSpeed=mSpeed-1;
  //   fanDir=fanDir-1;
  //   Serial.print("mSpeed:");
  //   Serial.print(mSpeed);
  //   Serial.print(" ");
  //   Serial.print("fanDir:");
  //   Serial.println(fanDir);
  //   if (mSpeed == 89)
  //   {
  //     mSpeed=0;
  //   }
    
  // } 

  


// if (downVal == 0 && mSpeed > 0)
// {
//   Serial.println(mSpeed);
//     digitalWrite(dir1,HIGH);
//     digitalWrite(dir2,LOW);
//     analogWrite(speedPin,mSpeed);
//     delay(dt);
//     mSpeed=mSpeed-1;
// }



// xVal=analogRead(joyx);
// if (xVal > 513 && xVal < 517)
// {
//   digitalWrite(dir1,HIGH);
//   digitalWrite(dir2,LOW);
//   analogWrite(speedPin,0);
//   Serial.println(xVal);
// }
// if (xVal < 513)
// {
//   mSpeed=map(xVal, 513, 0, 83, 255);
//   analogWrite(speedPin,mSpeed);
//   Serial.println(xVal);
// }
// if (xVal > 517)
// {
//   digitalWrite(dir1,LOW);
//   digitalWrite(dir2,HIGH);
//   mSpeed=map(xVal, 517, 1023, 83, 255);
//   analogWrite(speedPin,mSpeed);
//   Serial.println(xVal);
// }

}