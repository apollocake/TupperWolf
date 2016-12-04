#ifndef IR_SERVO_CONTROLLER
#define IR_SERVO_CONTROLLER
#include "IController.h"
#include "IMovement.h"
#include "IRServoMovement.h"

class IRServoController : public IController {
private:
IMovement *wm;
public:
  IRServoController(IMovement*& wm);
 ~IRServoController(){};
 void left();
 void right();
 void backward();
 void forward();
};

IRServoController::IRServoController(IMovement*& wm)
{
  this->wm = wm;
}

void IRServoController::left()
{
  wm->left();
}
void IRServoController::right()
{
  wm->right();
}
void IRServoController::backward()
{
  wm->backward();
}
void IRServoController::forward()
{
  wm->forward();
}
#endif
