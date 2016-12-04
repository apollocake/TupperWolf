#ifndef SENSOR_MODEL_H
#define SENSOR_MODEL_H
#include "Direction.h"
class SensorModel {
private:
  static Direction current_direction;
  SensorModel();
 ~SensorModel(){}
public:
 static void collect();
 static void compute();
 static Direction getCorrectionDirection();
};
SensorModel::SensorModel()
{
  //
}

Direction SensorModel::getCorrectionDirection()
{
  return current_direction;
}
void SensorModel::collect()
{
  //
}
void SensorModel::compute()
{
  //
}
Direction SensorModel::current_direction = Direction::FORWARD; //static variables have to be declared outside of class
#endif
