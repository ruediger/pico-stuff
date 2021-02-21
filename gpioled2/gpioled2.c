/*
  Two LEDs connected to GPIO pins
  pin13 --- >| -- [ R ] -- GND
  pin11 --- >| -- [ R ] -- GND
  And the onboard LED (pin25)
*/

#include "pico/stdlib.h"

int main() {
  const uint LED0 = PICO_DEFAULT_LED_PIN;
  const uint LED1 = 11;
  const uint LED2 = 13;

  const uint LED_MASK =
    1ul << LED0 |  // onboard LED
    1ul << LED1 |
    1ul << LED2;

  gpio_init_mask(LED_MASK);
  gpio_set_dir_out_masked(LED_MASK);
  gpio_clr_mask(1ul << LED0 | 1ul << LED1);
  gpio_set_mask(1ul << LED2);

  for (;;) {
    gpio_xor_mask(1ul << LED0 | 1ul << LED2);
    sleep_ms(500);
    gpio_xor_mask(1ul << LED0 | 1ul << LED1);
    sleep_ms(500);
    gpio_xor_mask(1ul << LED1 | 1ul << LED2);
    sleep_ms(500);
  }
}
