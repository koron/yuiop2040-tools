#include <stdio.h>

#include "pico/stdlib.h"

int main() {
    stdio_init_all();
    printf("\nYUIOP2040: Hello World\n");
    while(true) {
        tight_loop_contents();
    }
}
