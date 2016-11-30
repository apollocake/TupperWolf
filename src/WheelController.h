#ifndef WHEEL_CONTROLLER_H
#define WHEEL_CONTROLLER_H
#include "IController.h"
#include "IMovement.h"
#include "WheelMovement.h"

class WheelController : public IController {
private:
IMovement *wm;
public:
  WheelController(IMovement*& wm);
 ~WheelController(){}
 void left();
 void right();
 void backward();
 void forward();
};

WheelController::WheelController(IMovement*& wm)
{
  this->wm = wm;
}

void WheelController::left()
{
  wm->left();
}
void WheelController::right()
{
  wm->right();
}
void WheelController::backward()
{
  wm->backward();
}
void WheelController::forward()
{
  wm->forward();
}
#endif
