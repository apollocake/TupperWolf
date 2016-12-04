#include "WheelController.h"
#include "IRServoController.h"
#include "IController.h"
#include "SensorModel.h"
#include "WheelMovement.h"
#include "IRServoMovement.h"
#include "IMovement.h"
#include "Direction.h"


//global pointers for access between setup and loop
SensorModel sensor_model;
IMovement *wheel_movement;
IController *wheel_controller;
IMovement *ir_movement;
IController *ir_controller;
IRServoMovement *ir_movement_handle;
IRServoController *ir_controller_handle;
IRrecv irrecv(12); //set up IR reciever on pin 12
decode_results results;
//function declarations
byte calculatePower(int offset);
void cycle();

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  //allocate on the heap
  wheel_movement = new WheelMovement();
  wheel_controller = new WheelController(wheel_movement);
  ir_movement_handle = new IRServoMovement();
  ir_controller_handle = new IRServoController(ir_movement);
  ir_movement = ir_movement_handle;
  ir_controller = ir_controller_handle;
}
void loop() {

  //move ir sensor
  //cycle_ir(ir_movement_handle, ir_controller_handle);
  //gather sensor input
  if (irrecv.decode(&results)) {
    sensor_model.collect(ir_movement_handle->getPosition(), results.value);
    irrecv.resume(); // Receive the next value
  }

  //calculate input after recieving
  sensor_model.compute();

  //if too left, go left
  if (sensor_model.getCorrectionDirection() == Direction::LEFT) {
    //byte powr = calculatePower((sensor_model.getOffset()));
    //wheel_movement->setPower(powr);
    //wheel_controller->left();
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

    //send the lejos code on Channel 0 to mimic beacon
  sensor_model.sendCodes();
  irrecv.enableIRIn(); // Re-enable receiver
  delay(500);//must delay or tramples over reciever
}

byte calculatePower(int offset) {
  return 0;
}
void cycle_ir(IRServoMovement *&ir_movement, IRServoController *&ir_controller) {
  if (ir_movement->limitReached()) {
    if (ir_movement->getDirection() == Direction::LEFT) {
      ir_movement->right();
      ir_movement->setDirection(Direction::RIGHT);
    } else {
      ir_movement->left();
      ir_movement->setDirection(Direction::LEFT);
    }
  } else {
    if (ir_movement->getDirection() == Direction::LEFT) {
      ir_movement->left();
    } else {
      ir_movement->right();
    }
  }
}
