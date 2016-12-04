#ifndef WHEEL_MOVEMENT_H
#define WHEEL_MOVEMENT_H
#define FULLSTEP 4
#define HALFSTEP 8
#include "IMovement.h"
#include "Direction.h"
#include <AccelStepper.h>
#include <MultiStepper.h>

// motor pins
#define motorPin1  4     // Blue   - 28BYJ48 pin 1
#define motorPin2  5     // Pink   - 28BYJ48 pin 2
#define motorPin3  6     // Yellow - 28BYJ48 pin 3
#define motorPin4  7     // Orange - 28BYJ48 pin 4

                        
#define motorPin5  8     // Blue   - 28BYJ48 pin 1
#define motorPin6  9     // Pink   - 28BYJ48 pin 2
#define motorPin7  10    // Yellow - 28BYJ48 pin 3
#define motorPin8  11    // Orange - 28BYJ48 pin 4
AccelStepper stepper1(FULLSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(FULLSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

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
  power = 100;
}
Direction WheelMovement::getDirection(){
  return current_direction;  
}
void WheelMovement::left()
{
  stepper1.moveTo(-500);
  stepper1.setSpeed(200);
  stepper2.moveTo(500);
  stepper2.setSpeed(200);
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
  this->power = power;
}
#endif
