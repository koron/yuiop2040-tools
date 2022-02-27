#include <stdio.h>

#include "pico/stdlib.h"
#include "hardware/gpio.h"

int main() {
    setup_default_uart();
    printf("\nYUIOP2040: GPIO monitor\n");

    for (int i = 2; i < 30; i++) {
        gpio_init(i);
        gpio_set_dir(i, GPIO_IN);
        gpio_pull_up(i);
    }

    uint64_t last_change = 0;
    uint32_t last_gpio = 0;
    while(true) {
        uint64_t now = time_us_64();
        uint32_t curr = gpio_get_all() & 0x3ffffffc;
        if (last_gpio != curr && now - last_change >= 5000) {
            printf("GPIO: %08lx at %llu\n", curr, now);
            last_gpio = curr;
            last_change = now;
        }
        tight_loop_contents();
    }
}
