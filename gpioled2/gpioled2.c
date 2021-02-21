/*
  Two LEDs connected to GPIO pins
  pin13 --- >| -- [ R ] -- GND
  pin11 --- >| -- [ R ] -- GND
  And the onboard LED (pin25)
*/

#include "pico/stdlib.h"

int main() {
  const uint LED_MASK =
    1ul << PICO_DEFAULT_LED_PIN |  // onboard LED
    1ul << 11 |
    1ul << 13;

  gpio_init_mask(LED_MASK);
  gpio_set_dir_out_masked(LED_MASK);
  gpio_clr_mask(1ul << PICO_DEFAULT_LED_PIN | 1ul << 11);
  gpio_set_mask(1ul << 13);

  for (;;) {
    gpio_xor_mask(1ul << PICO_DEFAULT_LED_PIN | 1ul << 13);
    sleep_ms(500);
    gpio_xor_mask(1ul << PICO_DEFAULT_LED_PIN | 1ul << 11);
    sleep_ms(500);
    gpio_xor_mask(1ul << 11 | 1ul << 13);
    sleep_ms(500);
  }
}
