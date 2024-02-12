add_executable(fm24cl64b main.c)

target_link_libraries(fm24cl64b
	pico_stdlib
	pico_binary_info
	hardware_i2c
	pico_bootsel_via_double_reset
	)

pico_add_extra_outputs(fm24cl64b)
