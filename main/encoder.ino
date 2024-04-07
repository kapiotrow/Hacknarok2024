// ============================================================================
//  encoder ::  rotary ecoder interrupt test
//
//  Arduino IDE settings:
//  board: Raspberry Pi Pico (Arduino-Pico)
//  programmer: none
//
// ============================================================================

#include <qdec.h>


// Rotary encoder pin change interrupt handler
void readEncoder() {
  unsigned long currentMillis = millis();

  // Perform debounce
  if (currentMillis - lastDebounceTime < DEBOUNCE_DELAY) {
    return;
  }

  // Update the last debounce time
  lastDebounceTime = currentMillis;

  encoder_state = (encoder_state << 4) | (digitalRead(ROTB) << 1) | digitalRead(ROTA);
  switch (encoder_state) {
    case 0b00100011:  encoder_val++; break;
    case 0b00110010:  encoder_val--; break;
    case 0b00100000:  encoder_val--; break;
    case 0b00110001:  encoder_val++; break;

    case 0b00010000:  encoder_val++; break;
    case 0b00010011:  encoder_val--; break;
    case 0b00000001:  encoder_val--; break;
    case 0b00000010:  encoder_val++; break;
    default: break;
  }
}

// Rotary encoder initialization
void encoder_init() {
  // Enable pin change interrupts
  attachInterrupt(digitalPinToInterrupt(ROTA), readEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ROTB), readEncoder, CHANGE);
  encoder_state = (digitalRead(ROTB) << 1) | digitalRead(ROTA);
}