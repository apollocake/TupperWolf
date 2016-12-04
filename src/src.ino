#include <IRremote.h>
#include "WheelController.h"
#include "IRServoController.h"
#include "IController.h"
#include "SensorModel.h"
#include "WheelMovement.h"
#include "IRServoMovement.h"
#include "IMovement.h"
#include "Direction.h"

  IMovement *wheel_movement;
  IController *wheel_controller;
  IMovement *ir_movement;
  IController *ir_controller;
byte calculatePower(int offset);
void setup() {
  Serial.begin(9600);
  wheel_movement = new WheelMovement();
  wheel_controller = new WheelController(wheel_movement);
  ir_movement = new IRServoMovement();
  ir_controller = new IRServoController(ir_movement);
}
void loop() {
  //gather sensor input
  //calculate in after recieving
  SensorModel::collect();
  SensorModel::compute();

  //if too left, go left
  if(SensorModel::getCorrectionDirection() == Direction::FORWARD){
    byte powr = calculatePower((SensorModel::getOffset()));
    wheel_movement->setPower(powr);
    wheel_controller->left();
  }

  //if too right, go right
  //if(SensorModel.getCorrectionDirection() == Direction.Left);
  //powr = PowerCalculator.calculatePower((SensorReporter.getOffset())));
  //wheel_movement.setPower(powr);
  //wheel_controller->right();

  //if 'centered' go forward
  //if(SensorModel.getCorrectionDirection() == Direction.Forward);
  //wheel_controller->forward();

  //if nothing detected
  //if(SensorModel.getCorrectionDirection() == Direction.Backward);
  //wheel_controller->backward();
}

byte calculatePower(int offset){
  return 0;
}
