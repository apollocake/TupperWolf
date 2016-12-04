#ifndef SENSOR_MODEL_H
#define SENSOR_MODEL_H
#include <IRremote.h>
#include "Direction.h"

class SensorModel {
  private:
    Direction current_direction;
    IRsend irsend;
    int freq_bin[5];
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
  current_direction = Direction::LEFT;
}

Direction SensorModel::getCorrectionDirection()
{
  return current_direction;
}
int SensorModel::getOffset()
{
  return 0;
}
void SensorModel::collect(int current_position, unsigned long value)
{
  freq_bin[(current_position - 50) / 20]++;
  Serial.print(freq_bin[0], DEC);
  Serial.print(" ");
  Serial.print(freq_bin[1], DEC);
  Serial.print(" ");
  Serial.print(freq_bin[2], DEC);
  Serial.print(" ");
  Serial.print(freq_bin[3], DEC);
  Serial.print(" ");
  Serial.print(freq_bin[4], DEC);
  Serial.println(" ");

}
void SensorModel::compute()
{
  //
}

void SensorModel::sendCodes() {
  unsigned int lejos_codes[102] = {100, 1100, 100, 650, 100, 300, 150, 300, 100, 350, 100, 350, 100, 350, 100, 300, 150, 600, 100, 350, 100, 350, 100, 300, 150, 300, 150, 300, 100, 650, 100, 650, 100, 350, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  irsend.sendRaw(lejos_codes, 102, 38);
}
#endif
