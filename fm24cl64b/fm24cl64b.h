#pragma once

#include "hardware/i2c.h"

extern const size_t FM24CL64B_MAXSIZE;

extern const uint16_t FM24CL64B_MAXOFFSET;

extern const uint8_t FM24CL64B_BASEADDR;

#ifdef __cplusplus
extern "C" {
#endif

/*! \brief Read data from FM24CL64B at offset to dst.
 *
 * \param i2c Either \ref i2c0 or \ref i2c1
 * \param id Device ID: 0~7
 * \param offset Start address on FM24CL64B to read
 * \param dst Pointer to buffer to read data
 * \param len Length of data in bytes to read
 */
int fm24cl64b_read(i2c_inst_t *i2c, uint8_t id, uint16_t offset, uint8_t *dst, size_t len);

/*! \brief Write src to FM24CL64B at offset.
 *
 * \param i2c Either \ref i2c0 or \ref i2c1
 * \param id Device ID: 0~7
 * \param offset Start address on FM24CL64B to write
 * \param src Pointer to data to write
 * \param len Length of data in bytes to write
 */
int fm24cl64b_write(i2c_inst_t *i2c, uint8_t id, uint16_t offset, uint8_t *src, size_t len);


/*! \brief Fill a block of FM24CL64B with c start at offset.
 *
 * \param i2c Either \ref i2c0 or \ref i2c1
 * \param id Device ID: 0~7
 * \param offset Start address on FM24CL64B to fill
 * \param c Value to fill with
 * \param len Length of data in bytes to write
 */
int fm24cl64b_fill(i2c_inst_t *i2c, uint8_t id, uint16_t offset, uint8_t c, size_t len);

#ifdef __cplusplus
}
#endif
