#include <IRremote.h>
#include "WheelController.h"
#include "IController.h"
#include "WheelMovement.h"
#include "IRServo.h"
#include "IMovement.h"

  IMovement *wm;
  IController *wc;
  IMovement *ir;
  IController *ic;
void setup() {
  Serial.begin(9600);
  wm = new WheelMovement();
  wc = new WheelController(wm);
  ir = new IRServo();
  ic = new WheelController(ir);
}
void loop() {
  delay(1000);

  wc->left();
  wc->right();
  wc->backward();
  wc->forward();

  ic->left();
  ic->right();
  ic->backward();
  ic->forward();
}
