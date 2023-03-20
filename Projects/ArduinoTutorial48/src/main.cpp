#include <Arduino.h>
#include <LiquidCrystal.h>
#include <Wire.h>

int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;
int j;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int firstNum=1;
int secondNum=1;
String op;
float sum;

int dt=500;
int finaldt=5000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:

lcd.setCursor(0,0);
lcd.print("Enter First #");
while (Serial.available()==0) {}
firstNum = Serial.parseInt();
Serial.print(firstNum);
lcd.setCursor(0,1);
lcd.print(firstNum);
delay(dt);
lcd.clear();
  
lcd.setCursor(0,0);
lcd.print("Operator?");
while (Serial.available()==0) {}
op = Serial.readString();
Serial.print(op);
lcd.setCursor(0,1);
lcd.print(op);
delay(dt);
lcd.clear();  
  
lcd.setCursor(0,0);
lcd.print("Enter Second #");
while (Serial.available()==0) {}
secondNum = Serial.parseInt();
Serial.print(secondNum);
lcd.setCursor(0,1);
lcd.print(secondNum);
delay(dt);
lcd.clear();  
  

if (op == "+")
{
sum=firstNum+secondNum;
}
  
if (op == "-")
{
sum=firstNum-secondNum;
}
  
if (op == "/")
{
sum=firstNum/secondNum;
}
  
if (op == "*")
{
sum=firstNum*secondNum;
}

lcd.setCursor(0,0);
lcd.print("Answer");  
Serial.print(sum);
lcd.setCursor(0,1);
lcd.print(sum); 

  

   
delay(finaldt);
lcd.clear();

}