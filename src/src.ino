#include <IRremote.h>
#include "WheelController.h"
#include "IRServoController.h"
#include "IController.h"
#include "SensorModel.h"
#include "WheelMovement.h"
#include "IRServoMovement.h"
#include "IMovement.h"

  IMovement *wheel_movement;
  IController *wheel_controller;
  IMovement *ir_movement;
  IController *ir_controller;
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
  
  //powr = calculatePower((SensorReporter.getOffset())));
  //wheel_movement.setPower(powr);
  //if too left, go left
  //if(SensorModel.getCorrectionDirection() == Direction.Left);
  //wheel_controller->left();

  //powr = PowerCalculator.calculatePower((SensorReporter.getOffset())));
  //wheel_movement.setPower(powr);
  //if too right, go right
  //if(SensorModel.getCorrectionDirection() == Direction.Left);
  //wheel_controller->right();

  //if 'centered' go forward
  //if(SensorModel.getCorrectionDirection() == Direction.Forward);
  //wheel_controller->forward();

  //if nothing detected
  //if(SensorModel.getCorrectionDirection() == Direction.Backward);
  //wheel_controller->backward();
}
