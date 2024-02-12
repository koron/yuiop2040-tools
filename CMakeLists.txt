cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(yuiop2040_tools C CXX ASM)

set(PICO_BOARD pico)

pico_sdk_init()

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(helloworld)
add_subdirectory(gpiomon)
add_subdirectory(spiinit)
add_subdirectory(duplex-matrix-sim)
add_subdirectory(stdio-usb)
add_subdirectory(stdio-usb2)
add_subdirectory(fm24cl64b)
