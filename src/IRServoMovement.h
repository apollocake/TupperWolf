#ifndef IR_SERVO_MOVEMENT_H
#define IR_SERVO_MOVEMENT_H

#include "IMovement.h"
using namespace std;

class IRServoMovement : public IMovement {
private:

public:
  IRServoMovement();
 ~IRServoMovement(){}
 void left();
 void right();
 void backward();
 void forward();
 void setPower(byte power);
};

IRServoMovement::IRServoMovement()
{
}

void IRServoMovement::left()
{
  Serial.println("left");
}
void IRServoMovement::right()
{
  Serial.println("right");
}
void IRServoMovement::backward()
{
  Serial.println("IR Scanner can't move backward");
}
void IRServoMovement::forward()
{
  Serial.println("IR Scanner can't move forward");
}
void IRServoMovement::setPower(byte power)
{
  Serial.println("Power not set");
}
#endif
