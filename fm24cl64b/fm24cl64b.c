#include "fm24cl64b.h"

const size_t FM24CL64B_MAXSIZE = 8192;
const uint16_t FM24CL64B_MAXOFFSET = 0x1fff;

const uint8_t FM24CL64B_BASEADDR = 0x50;

uint8_t fm24cl64b_addr(uint8_t id) {
    return FM24CL64B_BASEADDR | (id & 0x07);
}

int fm24cl64b_read(i2c_inst_t *i2c, uint8_t id, uint16_t offset, uint8_t *dst, size_t len) {
    uint8_t addr = fm24cl64b_addr(id);
    uint8_t off[] = { offset >> 8, offset };
    int ret;
    ret = i2c_write_blocking(i2c, addr, off, sizeof(off), true);
    if (ret != sizeof(off)) {
        return ret < 0 ? ret : PICO_ERROR_GENERIC;
    }
    return i2c_read_blocking(i2c, addr, dst, len, false);
}

int fm24cl64b_write(i2c_inst_t *i2c, uint8_t id, uint16_t offset, uint8_t *src, size_t len) {
    uint8_t off[] = { offset >> 8, offset };
    int ret;
    ret = i2c_write_blocking(i2c, fm24cl64b_addr(id), off, sizeof(off), true);
    if (ret != sizeof(off)) {
        return ret < 0 ? ret : PICO_ERROR_GENERIC;
    }
    for (size_t i = 0; i < len; ++i) {
        bool last = i == len - 1;
        i2c->hw->data_cmd =
            bool_to_bit(last) << I2C_IC_DATA_CMD_STOP_LSB |
            *src++;
        do {
            tight_loop_contents();
        } while (!(i2c->hw->raw_intr_stat & I2C_IC_RAW_INTR_STAT_TX_EMPTY_BITS));
    }
    i2c->restart_on_next = false;
    return len;
}

int fm24cl64b_fill(i2c_inst_t *i2c, uint8_t id, uint16_t offset, uint8_t c, size_t len) {
    uint8_t off[] = { offset >> 8, offset };
    int ret;
    ret = i2c_write_blocking(i2c, fm24cl64b_addr(id), off, sizeof(off), true);
    if (ret != sizeof(off)) {
        return ret < 0 ? ret : PICO_ERROR_GENERIC;
    }
    for (size_t i = 0; i < len; ++i) {
        bool last = i == len - 1;
        i2c->hw->data_cmd = bool_to_bit(last) << I2C_IC_DATA_CMD_STOP_LSB | c;
        do {
            tight_loop_contents();
        } while (!(i2c->hw->raw_intr_stat & I2C_IC_RAW_INTR_STAT_TX_EMPTY_BITS));
    }
    i2c->restart_on_next = false;
    return len;
}
