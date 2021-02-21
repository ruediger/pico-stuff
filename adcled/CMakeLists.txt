add_executable(adcled
  adcled.c
  )

pico_add_extra_outputs(adcled)

# write to usb
pico_enable_stdio_usb(adcled 1)

target_link_libraries(adcled pico_stdlib hardware_adc)
