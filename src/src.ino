#include <IRremote.h>
#include "WheelController.h"
#include "IRServoController.h"
#include "IController.h"
#include "WheelMovement.h"
#include "IRServo.h"
#include "IMovement.h"

void setup() {
  Serial.begin(9600);
}
void loop() {
  delay(1000);
  WheelMovement wm;
  IMovement *iwm = &wm;
  WheelController wc(*iwm);
  IController *iwc = &wc;
  
  iwc->left();
  iwc->right();
  iwc->backward();
  iwc->forward();
  
  IRServo ir;
  IMovement *irm = &ir;
  IRServoController rc(*irm);
  IController *irc = &rc;

  irc->left();
  irc->right();
  irc->backward();
  irc->forward();
}
