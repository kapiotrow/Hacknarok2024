# Hacknarok2024

## Concept
System used for avalanche detection, warning and direct protection. Consists of one field device and one wearable deice. 
### Field device
* Measures the snow cover height to predict avalanches
* Detects the avalanche and sends a warning to the wearable device.
### Wearable device
* Receives avalanche warnings from the field device
* Detects the avalanche hit and deploys airbags
* Monitors body temperature.
## Architecture

## List of parts used in the project
### Raspberry Pico W
https://datasheets.raspberrypi.com/picow/pico-w-datasheet.pdf
### Ultrasound proximity sensor HC-SR04
Used to measure the snow cover height.\
https://www.alldatasheet.com/datasheet-pdf/pdf/1132204/ETC2/HCSR04.html
### OLED screen
https://www.winstar.com.tw/products/oled-module/graphic-oled-display/oled-12864.html
### Magnetometer
Due to limited resorces we were able to use, the magnometer is used for the avalanche detection based on object's rotation.\
https://www.alldatasheet.com/datasheet-pdf/pdf/428790/HONEYWELL/HMC5883L.html
### Temperature sensor 
Used to check the body temperature.\
https://www.mouser.com/datasheet/2/758/DHT11-Technical-Data-Sheet-Translated-Version-1143054.pdf
