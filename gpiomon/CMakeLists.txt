add_executable(gpiomon main.c)

target_link_libraries(gpiomon pico_stdlib)

pico_add_extra_outputs(gpiomon)
