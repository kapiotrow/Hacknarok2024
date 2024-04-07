#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void screen(int8_t temperature, int8_t humidity, float height, int8_t wind_speed, bool alarm) {
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  
  //delay(2000); // Pause for 2 seconds
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.print("Temperature: ");
  display.print(temperature);
  display.println("@C");

  display.print("Wind: ");
  display.println(wind_speed);

  display.print("Snow height: ");
  display.print(height);
  display.println("cm");

  display.print("Humidity: ");
  display.print(humidity);
  display.println("%");

  if (alarm){
    display.println("THE SNOW IS COMING");
  }
  else {
    if (temperature > 5) {
    display.println("Temperature above 0!");
    }
    if (wind_speed > 2) {
      display.println("Strong winds!");
    }
    if (height > 60) {
      display.println("Thick snow cover!");
    }
    else {
      display.println("The weather is good");
    }
  }

  display.display();
}
