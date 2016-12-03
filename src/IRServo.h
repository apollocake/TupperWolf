#ifndef IR_SERVO_H
#define IR_SERVO_H

#include "IMovement.h"
using namespace std;

class IRServo : public IMovement {
private:

public:
  IRServo(){}
 ~IRServo(){}
 void left();
 void right();
 void backward();
 void forward();
};

void IRServo::left()
{
  Serial.println("left");
}
void IRServo::right()
{
  Serial.println("right");
}
void IRServo::backward()
{
  Serial.println("IR Scanner can't move backward");
}
void IRServo::forward()
{
  Serial.println("IR Scanner can't move forward");
}
#endif
