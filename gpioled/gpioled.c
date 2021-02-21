/*
  Two LEDs connected to GPIO pins
  pin13 --- >| -- [ R ] -- GND
  pin11 --- >| -- [ R ] -- GND
  And the onboard LED (pin25)
*/

#include "pico/stdlib.h"

int main() {
  const uint LED_PINS[] = {
    PICO_DEFAULT_LED_PIN,  // onboard LED
    11,
    13,
  };

  for (uint i = 0; i < sizeof(LED_PINS)/sizeof(LED_PINS[0]); ++i) {
    gpio_init(LED_PINS[i]);
    gpio_set_dir(LED_PINS[i], GPIO_OUT);
  }

  for (;;) {
    gpio_put(LED_PINS[0], 1);
    gpio_put(LED_PINS[1], 0);
    gpio_put(LED_PINS[2], 0);
    sleep_ms(500);
    gpio_put(LED_PINS[0], 0);
    gpio_put(LED_PINS[1], 1);
    gpio_put(LED_PINS[2], 0);
    sleep_ms(500);
    gpio_put(LED_PINS[0], 0);
    gpio_put(LED_PINS[1], 0);
    gpio_put(LED_PINS[2], 1);
    sleep_ms(500);
  }
}
