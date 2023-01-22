#include <stdio.h>

#include "tusb.h"
#include "pico/stdlib.h"

int main() {
    tusb_init();
    stdio_init_all();
    printf("\nYUIOP2040: Stdio USB 2\n");
    uint64_t last = 0;
    while(true) {
        uint64_t now = time_us_64() / (1000*1000);
        if (now != last) {
            last = now;
            printf("Stdio USB 2: elapsed %llu seconds\n", last);
        }
        tud_task();
        tight_loop_contents();
    }
}
