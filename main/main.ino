#include <HCSR04.h>
#include <QMC5883LCompass.h>

QMC5883LCompass compass;
int8_t temperature;
int8_t humidity;
int8_t  height;
bool alarm;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  compass.init();
  temperature = 100;
  height      = 0;
  alarm       = false;

}

void loop() {
  // put your main code here, to run repeatedly:
  request_temperature(13);
  delay(18);
  get_temperature(13);
  alarm = revolutions();
  screen(temperature, humidity, height, alarm);
  delay(2000-18);
}
