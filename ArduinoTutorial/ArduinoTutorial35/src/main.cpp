#include <Arduino.h>
#include <Stepper.h>

int buttonPin=2;
int buttonVal;
int buttonValOLD=0;

int stepsPerRevolution=2048;
int motSpeed=10;
int direction=-1;
int directionOLD=1;
int directionOLD2;

Stepper myStepper(stepsPerRevolution, 8,10,9,11);

int dt=100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin,INPUT);
  digitalWrite(buttonPin,HIGH);
  myStepper.setSpeed(motSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonVal=digitalRead(buttonPin);

  if (buttonVal==1 && buttonValOLD==0)
  {
    // if (direction==-1 && directionOLD==1)
    // {
    //   directionOLD2=direction;
    //   Serial.println("reverse");
    //   direction=1;
    // }  

    // if (direction==1 && directionOLD==-1)
    // {
    //   directionOLD2=direction;
    //   Serial.println("forward");
    //   direction=direction-2;
    // }  

    // directionOLD=directionOLD2;  
    direction=direction * (-1);
  } 
  
  myStepper.step(direction);
  buttonValOLD=buttonVal;

}