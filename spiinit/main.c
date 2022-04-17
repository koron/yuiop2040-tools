#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/spi.h"

#define SPI_PORT    spi_default
#define SPI_RX      PICO_DEFAULT_SPI_RX_PIN
#define SPI_SCK     PICO_DEFAULT_SPI_SCK_PIN
#define SPI_TX      PICO_DEFAULT_SPI_TX_PIN
#define SPI_CSN     PICO_DEFAULT_SPI_CSN_PIN

int main() {
    setup_default_uart();
    stdio_init_all();
    printf("\nspiinit: hello\n");

    gpio_set_function(SPI_RX, GPIO_FUNC_SPI);
    gpio_set_function(SPI_SCK, GPIO_FUNC_SPI);
    gpio_set_function(SPI_TX, GPIO_FUNC_SPI);
    gpio_init(SPI_CSN);
    gpio_set_dir(SPI_CSN, GPIO_OUT);
    gpio_put(SPI_CSN, true);

    spi_init(SPI_PORT, 2*1000*1000);
    spi_set_format(SPI_PORT, 8, 1, 0, SPI_MSB_FIRST);

    uint32_t n = 0;
    while(true) {
        printf("spiinit: %d\n", n++);
        sleep_ms(1000);
    }
}
