#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void screen(int16_t temperature, int8_t height, bool alarm) {
  Serial.begin(9600);

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
  display.print("Human temperature: ");
  display.print(temperature / 1024);
  display.print(".");
  display.print(temperature % 1024);
  display.println("@C");

  display.print("Snow height: ");
  display.print(height);
  display.println("cm");

  if (!alarm){
    display.println("Enjoy the weather (O‿O)");
  }
  else {
    display.println("RUN!!! THE SNOW IS COMING");
    display.println("THE SNOW IS COMING");
    display.println("THE SNOW IS COMING");
  }

  display.display();
}
