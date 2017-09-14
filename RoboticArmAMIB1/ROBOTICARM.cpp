///// IMPORT ALL NECESSARY LIBRARIES HERE /////

#include "states.h"
#include "SpeedyStepper.h"
#include "RCServo.h"

namespace ROBOTICARM {

//// DECLARE ALL OBJECTS & VARIABLES HERE /////
int base = 200;
int microsteeping = 8; //low tower A1, high tower A2
int ratio = 2;
byte LOW_PROX_PIN = A6;
byte HIGH_PROX_PIN = A5;
byte HOME_PROX_PIN = A4;
byte MAGNET_PIN = A7;
byte ARM_PIN = 10;

SpeedyStepper armStepper; 
RCServo magnet;

void setup(){
  pinMode(HOME_PROX_PIN, INPUT_PULLUP);
  pinMode(LOW_PROX_PIN, INPUT_PULLUP);
  pinMode(HIGH_PROX_PIN, INPUT_PULLUP);
  pinMode(ARM_PIN, OUTPUT);
  armStepper.connectToPort(2);
  magnet.connectToPin(MAGNET_PIN, 1000, 2000, 0);
  armStepper.setStepsPerRevolution(base*microsteeping*ratio);
  armStepper.setSpeedInRevolutionsPerSecond(.25);
  armStepper.setAccelerationInRevolutionsPerSecondPerSecond(5);

  events::goHome();
}

void enter(){
    //code to run when state is entered
}

void loop(){
    if (digitalRead(HIGH_PROX_PIN) == 0) {
    events::moveToHigh();
    events::magnetOn();
    events::armDown();
    delay(2000);
    events::armUp();
    delay(1000);
    events::moveToLow();
    events::armDown();
    delay(4000);
    events::magnetOff();
    events::armUp();
  }
  else if (digitalRead(LOW_PROX_PIN) == 0) {
    events::moveToLow();
    events::magnetOn();
    events::armDown();
    delay(2000);
    events::armUp();
    delay(4000);
    events::moveToHigh();
    events::armDown();
    delay(4000);
    events::magnetOff();
    events::armUp();
  }
  //events::goHome();
}

void exit(){
    //code to run when state is exited
}

///// ALL EVENTS BELOW THIS LINE ////
void events::moveToHigh() {
  armStepper.moveToPositionInRevolutions(.25);
}

void events::moveToLow() {
  armStepper.moveToPositionInRevolutions(.4);
}

void events::magnetOn() {
  magnet.setServoPosition(-1);
}

void events::magnetOff() {
  magnet.setServoPosition(1);
}

void events::armUp() {
  digitalWrite(ARM_PIN, LOW);
}

void events::armDown() {
  digitalWrite(ARM_PIN, HIGH);
}

void events::goHome() {
  armStepper.moveToHomeInRevolutions(-1, .25, 1, HOME_PROX_PIN);
}
}
