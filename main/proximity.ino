#include <HCSR04.h>

float base_height = 0; //we should get it from the encoder

UltraSonicDistanceSensor distanceSensor(11, 12);

void get_snow_cover_height() {
  float distance = distanceSensor.measureDistanceCm();
  height = distance - base_height;
  return;
}
