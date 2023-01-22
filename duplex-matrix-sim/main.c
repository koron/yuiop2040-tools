#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define SPI_PORT    spi_default
#define SPI_RX      PICO_DEFAULT_SPI_RX_PIN
#define SPI_SCK     PICO_DEFAULT_SPI_SCK_PIN
#define SPI_TX      PICO_DEFAULT_SPI_TX_PIN
#define SPI_CSN     PICO_DEFAULT_SPI_CSN_PIN

void main1() {
    gpio_set_dir(12, true);
    //gpio_set_pulls(12, true, false);
    gpio_put(12, true);

    gpio_set_dir(13, true);
    //gpio_set_pulls(13, false, true);
    gpio_put(13, false);

    gpio_set_dir(14, false);
    gpio_set_pulls(14, true, false);
    //gpio_put(14, true);

    gpio_set_dir(15, false);
    gpio_set_pulls(15, true, false);
    //gpio_put(15, true);

    uint32_t n = 0;
    while(true) {
        printf("%03d #14=%s #15=%s\n", n++,
                gpio_get(14) ? "Hi" : "Lo",
                gpio_get(15) ? "Hi" : "Lo");
        sleep_ms(1000);
    }
}

void set_input_low(uint n) {
    gpio_set_dir(n, false);
    gpio_set_pulls(n, false, true);
}

void set_output_high(uint n) {
    gpio_set_dir(n, true);
    gpio_put(n, true);
}

void main2() {
    set_input_low(12);
    set_input_low(13);
    set_input_low(14);
    set_input_low(15);

    set_output_high(15);

    uint32_t n = 0;
    while (true) {
        printf("%03d #13=%s\n", n++, gpio_get(13) ? "Hi" : "Lo");
        sleep_ms(1000);
    }
}

int main() {
    stdio_init_all();
    printf("\nDuplex Matrix Sim\n");

    gpio_init(12);
    gpio_init(13);
    gpio_init(14);
    gpio_init(15);

    main2();
}
