/*
  Two LEDs connected to GPIO pins
  pin13 --- >| -- [ R ] -- GND
  pin11 --- >| -- [ R ] -- GND
  And the onboard LED (pin25)

  ADC set up using 1MOhm potentionmeter.
  pin.. (+3.3) --- [ varR ] -- GND
  pin26 --------------|
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main() {
  stdio_init_all();
  printf("----- ADC LED -----\n");

  const uint LED0 = PICO_DEFAULT_LED_PIN;
  const uint LED1 = 11;
  const uint LED2 = 13;

  gpio_init(LED0);
  gpio_set_dir(LED0, GPIO_OUT);
  gpio_init(LED1);
  gpio_set_dir(LED1, GPIO_OUT);
  gpio_init(LED2);
  gpio_set_dir(LED2, GPIO_OUT);

  adc_init();
  adc_gpio_init(26);
  adc_select_input(0);
  // 3.3V 12bit ADC
  const float conversion_factor = 3.3f/(1<<12);
  for (;;) {
    uint16_t result = adc_read();
    float voltage = result * conversion_factor;
    printf("Raw value 0x%03x, voltage %f V\n", result, voltage);
    gpio_put(LED0, voltage > 1.0);
    gpio_put(LED1, voltage > 2.0);
    gpio_put(LED2, voltage > 3.0);
    sleep_ms(250);
  }
}
