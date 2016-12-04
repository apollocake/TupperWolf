#include <IRremote.h>
#include "WheelController.h"
#include "IRServoController.h"
#include "IController.h"
#include "WheelMovement.h"
#include "IRServoMovement.h"
#include "IMovement.h"

  IMovement *wm;
  IController *wc;
  IMovement *ir;
  IController *ic;
void setup() {
  Serial.begin(9600);
  wm = new WheelMovement();
  wc = new WheelController(wm);
  ir = new IRServoMovement();
  ic = new IRServoController(ir);
}
void loop() {
  //if too left, go left
  //if too right, go right
  //if
}
