add_executable(helloworld main.c)

target_link_libraries(helloworld pico_stdlib)

pico_add_extra_outputs(helloworld)
