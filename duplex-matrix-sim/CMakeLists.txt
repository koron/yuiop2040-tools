add_executable(duplex-matrix-sim main.c)

target_link_libraries(duplex-matrix-sim
	pico_stdlib)

pico_add_extra_outputs(duplex-matrix-sim)
