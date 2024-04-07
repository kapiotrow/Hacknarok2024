#include <DHT11.h>

// BUFFER TO RECEIVE
uint8_t cnt;
uint8_t idx;
uint8_t bits[5];

void request_temperature(int pin){
  cnt = 7;
  idx = 0;

	// EMPTY BUFFER
	for (int i=0; i< 5; i++) bits[i] = 0;

	// REQUEST SAMPLE
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
}

void get_temperature(int pin)
{
	digitalWrite(pin, HIGH);
	delayMicroseconds(40);
	pinMode(pin, INPUT);

	// ACKNOWLEDGE or TIMEOUT
	unsigned int loopCnt = 10000;
	while(digitalRead(pin) == LOW)

    if (loopCnt-- == 0) {
      Serial.println(F("ERROR DHTLIB TIMEOUT"));
      return;
    }

	loopCnt = 10000;
	while(digitalRead(pin) == HIGH)

    if (loopCnt-- == 0) {
      Serial.println(F("ERROR DHTLIB TIMEOUT"));
      return;
    }

	// READ OUTPUT - 40 BITS => 5 BYTES or TIMEOUT
	for (int i=0; i<40; i++)
	{
		loopCnt = 10000;
		while(digitalRead(pin) == LOW)

      if (loopCnt-- == 0) {
        Serial.println(F("ERROR DHTLIB TIMEOUT"));
        return;
      }

		unsigned long t = micros();

		loopCnt = 10000;
		while(digitalRead(pin) == HIGH)
      if (loopCnt-- == 0) {
        Serial.println(F("ERROR DHTLIB TIMEOUT"));
        return;
      }

		if ((micros() - t) > 40) bits[idx] |= (1 << cnt);
		if (cnt == 0)   // next byte?
		{
			cnt = 7;    // restart at MSB
			idx++;      // next byte!
		}
		else cnt--;
	}

	// WRITE TO RIGHT VARS
        // as bits[1] and bits[3] are allways zero they are omitted in formulas.
	humidity    = bits[0]; 
	temperature = bits[2]; 

	uint8_t sum = bits[0] + bits[2];  

  if (bits[4] != sum) {
    Serial.println(F("ERROR DHTLIB CHECKSUM MISSMATCH"));
    return;
  }
	return;
}


