add_executable(gpioled
  gpioled.c
  )

pico_add_extra_outputs(gpioled)

target_link_libraries(gpioled pico_stdlib)
