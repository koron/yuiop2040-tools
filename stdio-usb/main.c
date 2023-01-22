#include <stdio.h>

#include "pico/stdlib.h"

int main() {
    stdio_init_all();
    printf("\nYUIOP2040: Stdio USB\n");
    uint64_t last = 0;
    while(true) {
        uint64_t now = time_us_64() / (1000*1000);
        if (now != last) {
            last = now;
            printf("Stdio USB: elapsed %llu seconds\n", last);
        }
        tight_loop_contents();
    }
}
