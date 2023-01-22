add_executable(stdio-usb main.c)

pico_enable_stdio_uart(stdio-usb 0) 
pico_enable_stdio_usb(stdio-usb 1)

target_link_libraries(stdio-usb pico_stdlib)

pico_add_extra_outputs(stdio-usb)
