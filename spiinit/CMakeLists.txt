add_executable(spiinit main.c)

target_link_libraries(spiinit
	hardware_spi
	pico_stdlib)

pico_add_extra_outputs(spiinit)
