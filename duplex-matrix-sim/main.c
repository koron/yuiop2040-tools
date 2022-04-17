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

    for (int i = 12; i <= 15; i++) {
        gpio_init(i);
        gpio_set_dir(i, false);
        gpio_pull_up(i);
    }
    gpio_set_dir(13, true);
    gpio_pull_down(13);

    uint32_t n = 0;
    while(true) {
        printf("%03d GPIO15=%s\n", n++, gpio_get(15) ? "Hi" : "Lo");
        sleep_ms(1000);
    }
}
