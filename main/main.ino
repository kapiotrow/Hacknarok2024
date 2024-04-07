#include <HCSR04.h>
#include <QMC5883LCompass.h>
#include <WiFi.h>


QMC5883LCompass compass;
int8_t temperature;
int8_t humidity;
int8_t wind_speed;
float  height;
bool alarm;


WiFiServer server(80);
WiFiMulti multi;
WiFiClient client;

const char ssid[] = "KPT-Conference";
const char password[] = "E2ue6Tm&";

const char host[] = "172.98.2.183";
const uint16_t port = 5000;


// Encoder values
int8_t encoder_val = 0;
#define ROTA       16    // GPIO6   PIN8   rotary encoder A
#define ROTB       17    // GPIO7   PIN9   rotary encoder B
#define DEBOUNCE_DELAY 25 // Adjust debounce delay as needed
volatile int8_t encoder_state = 0;
unsigned long lastDebounceTime = 0;


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


  // Enable pin change interrupts for encoder
  encoder_init();
  pinMode(ROTA, INPUT);
  pinMode(ROTB, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  request_temperature(13);
  delay(18);
  get_temperature(13);
  get_snow_cover_height();
  alarm = revolutions();

  wind_speed = abs(encoder_val);
  encoder_val = 0;

  if (alarm) {
    if (!client.connect(host, port)) {
      Serial.println("connection failed");
      return;
    }
    send_avalanche_msg(client);

    client.stop();
  }
  screen(temperature, humidity, height, wind_speed, alarm);

  delay(1000-18);
}
