#include <IRremote.h>
#include "WheelController.h"
#include "IController.h"
#include "WheelMovement.h"
#include "IMovement.h"

void setup() {
  Serial.begin(9600);
}
void loop() {
  delay(1000);
  IMovement *wm = new WheelMovement();
  IController *wc = new WheelController(wm);
  wc->left();
  wc->right();
  wc->backward();
  wc->forward();
  delete wc;
  delete wm;
}
