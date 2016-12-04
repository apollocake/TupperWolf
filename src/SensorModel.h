#ifndef SENSOR_MODEL_H
#define SENSOR_MODEL_H
#include <IRremote.h>
#include "Direction.h"

class SensorModel {
  private:
    Direction correction_direction;
    IRsend irsend;
    static const int BIN_ARRAY_SIZE = 5;
    static const int MIDPOINT_INDEX = 2;    
    int freq_bin[BIN_ARRAY_SIZE];
    int target_bin_index;
  public:
    SensorModel();
    ~SensorModel() {}
    void collect(int current_position, unsigned long value);
    void compute();
    void sendCodes();
    int getOffset();
    Direction getCorrectionDirection();
};

SensorModel::SensorModel() {
  correction_direction = Direction::FORWARD;
  target_bin_index = 0;
}

Direction SensorModel::getCorrectionDirection()
{
  return correction_direction;
}
//get the absolute value difference
int SensorModel::getOffset()
{
  if((MIDPOINT_INDEX - target_bin_index)> 0)
    return MIDPOINT_INDEX - target_bin_index;
  else
    return target_bin_index - MIDPOINT_INDEX;
}
void SensorModel::collect(int current_position, unsigned long value)
{
  if (value == 0x61A030CF) {
    freq_bin[(current_position - 50) / 20]++;
  }
  Serial.print(freq_bin[4], DEC);
  Serial.print(" ");
  Serial.print(freq_bin[3], DEC);
  Serial.print(" ");
  Serial.print(freq_bin[2], DEC);
  Serial.print(" ");
  Serial.print(freq_bin[1], DEC);
  Serial.print(" ");
  Serial.print(freq_bin[0], DEC);
  Serial.println(" ");

}
void SensorModel::compute()
{
  //calculate the bins for each angle sampled
  int max_num = freq_bin[0];
  target_bin_index = 0;
  for (int i = 0; i < BIN_ARRAY_SIZE; i++) {
    if (freq_bin[i] > max_num) {
      max_num = freq_bin[i];
      target_bin_index = i;
    }
  }
  //reset if numbers get too big
  if (max_num > 5) {
    for (int i = 0; i < BIN_ARRAY_SIZE; i++) {
      freq_bin[i] = 0;
    }
  }
  //calculate the correct direction to move
  if (target_bin_index < 2) {
    correction_direction = Direction::RIGHT;
  }
  else if (target_bin_index > 2) {
    correction_direction = Direction::LEFT;
  }
  else {
    correction_direction = Direction::FORWARD;
  }
}

void SensorModel::sendCodes() {
  unsigned int lejos_codes[102] = {100, 1100, 100, 650, 100, 300, 150, 300, 100, 350, 100, 350, 100, 350, 100, 300, 150, 600, 100, 350, 100, 350, 100, 300, 150, 300, 150, 300, 100, 650, 100, 650, 100, 350, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  irsend.sendRaw(lejos_codes, 102, 38);
  //TV Remote test
  //irsend.sendNEC(0x61A0F00F, 40);
}
#endif
