#include <HCSR04.h>

int8_t temperature;
int8_t humidity;
int8_t  height;
bool alarm;

void setup() {
  // put your setup code here, to run once:
  temperature = 100;
  height      = 0;
  alarm       = false;

}

void loop() {
  // put your main code here, to run repeatedly:
  request_temperature(13);
  delay(18);
  get_temperature(13);
  screen(temperature, humidity, height, alarm);
  delay(2000-18);
}
