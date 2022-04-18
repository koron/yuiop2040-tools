#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define SPI_PORT    spi_default
#define SPI_RX      PICO_DEFAULT_SPI_RX_PIN
#define SPI_SCK     PICO_DEFAULT_SPI_SCK_PIN
#define SPI_TX      PICO_DEFAULT_SPI_TX_PIN
#define SPI_CSN     PICO_DEFAULT_SPI_CSN_PIN

int main() {
    setup_default_uart();
    stdio_init_all();
    printf("\nDuplex Matrix Sim\n");

    gpio_init(12);
    gpio_set_dir(12, false);
    gpio_set_pulls(12, true, false);
    gpio_put(12, true);

    gpio_init(13);
    gpio_set_dir(13, true);
    gpio_set_pulls(13, false, true);
    gpio_put(13, false);

    gpio_init(14);
    gpio_set_dir(14, false);
    gpio_set_pulls(14, true, false);
    gpio_put(14, true);

    gpio_init(15);
    gpio_set_dir(15, false);
    gpio_set_pulls(15, true, false);
    gpio_put(15, true);

    uint32_t n = 0;
    while(true) {
        printf("%03d #14=%s #15=%s\n", n++,
                gpio_get(14) ? "Hi" : "Lo",
                gpio_get(15) ? "Hi" : "Lo");
        sleep_ms(1000);
    }
}
