#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#define DHTTYPE DHT11

int sensePin=2;
DHT HT(sensePin,DHTTYPE);
float humidity;
float tempC;
float tempF;
int setTime=500;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
HT.begin();
delay(setTime);
}


void loop() {
  // put your main code here, to run repeatedly:
humidity=HT.readHumidity();
tempC=HT.readTemperature();
tempF=HT.readTemperature(true);

Serial.print(" Humidity: ");
Serial.print(humidity);
Serial.print(" Temp F: ");
Serial.print(tempF);
Serial.print(" Temp C: ");
Serial.println(tempC);
delay(setTime);

}