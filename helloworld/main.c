#include <stdio.h>

#include "pico/stdlib.h"

int main() {
    setup_default_uart();
    printf("\nYUIOP2040: Hello World\n");
    while(true) {
        tight_loop_contents();
    }
}
