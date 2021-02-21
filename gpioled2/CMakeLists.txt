add_executable(gpioled2
  gpioled2.c
  )

pico_add_extra_outputs(gpioled2)

target_link_libraries(gpioled2 pico_stdlib)
