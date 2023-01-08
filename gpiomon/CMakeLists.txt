add_executable(gpiomon main.c)

target_compile_definitions(gpiomon PRIVATE
	PICO_DEFAULT_UART_RX_PIN=0
	PICO_DEFAULT_UART_RX_PIN=-1
)

target_link_libraries(gpiomon pico_stdlib)

pico_add_extra_outputs(gpiomon)
