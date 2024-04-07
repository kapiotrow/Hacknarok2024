#include <HCSR04.h>
#include <QMC5883LCompass.h>
#include <WiFi.h>


QMC5883LCompass compass;
int8_t temperature;
int8_t humidity;
int8_t  height;
bool alarm;

WiFiServer server(80);
WiFiMulti multi;
WiFiClient client;


const char ssid[] = "KPT-Conference";
const char password[] = "E2ue6Tm&";

const char host[] = "172.98.2.183";
const uint16_t port = 5000;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  compass.init();
  temperature = 100;
  height      = 0;
  alarm       = false;
  
  multi.addAP(ssid, password);
  for (uint8_t i = 0; i < 3; ++i)
  {
    if (multi.run() != WL_CONNECTED) {
      Serial.println("Unable to connect to network, rebooting in 2 seconds...");
      // delay(50);
    }
  }
  Serial.println("WiFi connected");


}

bool send_msg = false;
void loop() {

  // put your main code here, to run repeatedly:
  request_temperature(13);
  delay(18);
  get_temperature(13);
  alarm = revolutions();
  screen(temperature, humidity, height, alarm);

  if (send_msg) {
    if (!client.connect(host, port)) {
      Serial.println("connection failed");
      return;
    }
    send_avalanche_msg(client);

    client.stop();
  }

  delay(2000-18);


}
