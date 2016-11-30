#ifndef WHEEL_MOVEMENT_H
#define WHEEL_MOVEMENT_H

#include "IMovement.h"

class WheelMovement : public IMovement {
private:

public:
  WheelMovement();
 ~WheelMovement(){}
 void left();
 void right();
 void backward();
 void forward();
};

WheelMovement::WheelMovement()
{
}

void WheelMovement::left()
{
  Serial.println("left");
}
void WheelMovement::right()
{
  Serial.println("right");
}
void WheelMovement::backward()
{
  Serial.println("backward");
}
void WheelMovement::forward()
{
  Serial.println("forward");
}
#endif
