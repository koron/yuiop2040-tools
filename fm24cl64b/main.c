#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

#include "fm24cl64b.h"

static int fram_write256(uint16_t off) {
    int ret;
    uint8_t data[256+2] = { off >> 8, off };
    for (int i = 0; i < 256; i++) {
        data[2+i] = ((i & 0xf0) >> 4) | ((i & 0x0f) << 4);
    }
    ret = i2c_write_blocking(i2c_default, 0x50, data, sizeof(data), false);
    if (ret != sizeof(data)) {
        printf("*** fram_write256 failed: %d\n", ret);
        return -1;
    }
    return 0;
}

static int dump(i2c_inst_t *i2c, uint8_t id, uint16_t offset, size_t len) {
    int ret = 0;
    uint8_t *dst = calloc(len, 1);
    ret = fm24cl64b_read(i2c, id, offset, dst, len);
    if (ret != len) {
        printf("dump failed: %d\n", ret);
        goto END;
    }
    ret = 0;
    printf("     +0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +A +B +C +D +E +F\n");
    for (size_t i = 0; i < len; ++i) {
        if (i % 16 == 0) {
            printf("%04x", (i + offset) & 0x1fff);
        }
        printf(" %02x", dst[i]);
        if (i % 16 == 15) {
            printf("\n");
        }
    }
    if (len % 16 != 0) {
        printf("\n");
    }
END:
    if (dst != NULL) {
        free(dst);
    }
    return ret;
}

int main() {
    stdio_init_all();
    printf("\nFM24CL64B: start\n\n");

    // Setup I2C
    i2c_init(i2c_default, 1000 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(PICO_DEFAULT_I2C_SDA_PIN);
    gpio_pull_up(PICO_DEFAULT_I2C_SCL_PIN);
    bi_decl(bi_2pins_with_func(PICO_DEFAULT_I2C_SDA_PIN, PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C));

    int ret;

    printf("=== START\n");
    ret = dump(i2c_default, 0, 0x1fe0, 32 + 256 + 32);
    if (ret < 0) {
        printf("dump failed: %d\n", ret);
    }

#if 1
    ret = fram_write256(0);
    printf("=== INIT\n");
    dump(i2c_default, 0, 0x1fe0, 32 + 256 + 32);
#endif

#if 1
    ret = fm24cl64b_fill(i2c_default, 0, 0x0040, 0, 128);
    printf("=== CLEAR\n");
    dump(i2c_default, 0, 0x1fe0, 32 + 256 + 32);
#endif

    printf("\n*** done\n");
    return 0;
}
