#ifndef WHEEL_MOVEMENT_H
#define WHEEL_MOVEMENT_H

#include "IMovement.h"
#include "Direction.h"

class WheelMovement : public IMovement {
private:
byte power;
Direction current_direction;
public:
  WheelMovement();
 ~WheelMovement(){}
 void left();
 void right();
 void backward();
 void forward();
 Direction getDirection();
 void setPower(byte power);
};

WheelMovement::WheelMovement()
{
  power = 255;
}
Direction WheelMovement::getDirection(){
  return current_direction;  
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
void WheelMovement::setPower(byte power)
{
  //Serial.println("Power not set");
}
#endif
