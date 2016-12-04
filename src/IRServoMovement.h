/*
 *IR output led must be on pin 3
 */

#ifndef IR_SERVO_MOVEMENT_H
#define IR_SERVO_MOVEMENT_H
#include <Servo.h>
#include "IMovement.h"
#include "Direction.h"
using namespace std;

class IRServoMovement : public IMovement {
private:
byte power;
Servo myservo;
const int limit_l = 130;
const int limit_r = 50;
int current_position;
Direction current_direction;
public:
  IRServoMovement();
 ~IRServoMovement(){}
 void left();
 void right();
 void backward();
 void forward();
 int getPosition();
 bool limitReached();
 Direction getDirection();
 void setPower(byte power);
 void setDirection(Direction d);
};

IRServoMovement::IRServoMovement()
{
    myservo.attach(2); // attach servo to pin 2
    power = 255;
    current_position = limit_l;
    current_direction = Direction::LEFT;
}
int IRServoMovement::getPosition()
{
  return current_position;
}
Direction IRServoMovement::getDirection()
{
  return current_direction;
}
void IRServoMovement::setDirection(Direction d)
{
  current_direction = d;
}
bool IRServoMovement::limitReached()
{
  if(current_position == limit_l)
    Serial.println("left limit reached");
  if(current_position == limit_r)
    Serial.println("right limit reached");
  if(current_position == limit_l || current_position == limit_r)
    return true;
  else return false;
}
void IRServoMovement::left()
{
  //num needs to be between the two limits
  if(current_position < limit_l){
    current_position = current_position + 20;
    myservo.write(current_position);
  }
}
void IRServoMovement::right()
{
    //num needs to be between the two limits
  if(current_position > limit_r){
    current_position = current_position - 20;
    myservo.write(current_position);
  }
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
