#include <HCSR04.h>

float base_height = 200;

UltraSonicDistanceSensor distanceSensor(11, 12);

void get_snow_cover_height() {
  float distance = distanceSensor.measureDistanceCm();
  height = base_height - distance;
  return;
}
