#include <ACROBOTIC_SSD1306.h>
#include <DHT11.h>
#include <HMC5883L.h>
#include <HCSR04.h>

int16_t temperature;
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
  screen(temperature, height, alarm);
  delay(2000);
  temperature += 100;
}
