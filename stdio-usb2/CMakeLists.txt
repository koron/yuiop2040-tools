add_executable(stdio-usb2 main.c usb_descriptors.c)

pico_enable_stdio_uart(stdio-usb2 0) 
pico_enable_stdio_usb(stdio-usb2 1)

target_compile_definitions(stdio-usb2 PRIVATE
    CFG_TUSB_CONFIG_FILE="my_usb_config.h"
)

target_include_directories(stdio-usb2 PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(stdio-usb2 pico_stdlib tinyusb_device)

pico_add_extra_outputs(stdio-usb2)

# vim:set ts=8 sts=4 sw=4 tw=0 et:
