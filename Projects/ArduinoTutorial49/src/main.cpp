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

float radius=1;
float pi=3.14159;
float area;

int dt=1000;
int finaldt=3000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.setCursor(0,0);
  lcd.print("Enter Radius:");
  while (Serial.available()==0) {}
  radius = Serial.parseFloat();
  Serial.print(radius);
  lcd.setCursor(0,1);
  lcd.print(radius);
  delay(dt);
  lcd.clear();

  area=pi*(radius*radius);

  lcd.setCursor(0,0);
  lcd.print("The area of your");  
  lcd.setCursor(0,1);
  lcd.print("radius is: ");
  delay(dt);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(area); 

  delay(finaldt);
  lcd.clear();

}