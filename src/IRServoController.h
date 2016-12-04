#ifndef IR_SERVO_CONTROLLER
#define IR_SERVO_CONTROLLER
#include "IController.h"
#include "IMovement.h"
#include "Direction.h"
#include "IRServoMovement.h"

class IRServoController : public IController {
private:
IMovement *wm;
Direction current_direction;
public:
  IRServoController(IMovement*& wm);
 ~IRServoController(){};
 void left();
 void right();
 void backward();
 void forward();
 void cycle();
 Direction getCurrentDirection();
};

IRServoController::IRServoController(IMovement*& wm)
{
  this->wm = wm;
  current_direction = Direction::RIGHT;
}
Direction IRServoController::getCurrentDirection()
{
  return current_direction;
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
