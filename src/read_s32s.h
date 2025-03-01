#ifndef READ_S32S_H

#define READ_S32S_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * Attempts to read one or more signed 32-bit integers from a buffer.
 * @param buffer The buffer from which to read the signed 32-bit integers.
 * @param buffer_length The length of the buffer from which to read the signed
 *                      32-bit integers, in bytes.
 * @param s32s Overwritten with the read signed 32-bit integers should the
 *             operation succeed.
 * @param quantity The number of signed 32-bit integers to read.
 * @param offset The offset within the buffer from which to read the signed
 *               32-bit integers.
 * @return True when the operation succeeds.  False should the given integers
 *         not fit within the buffer.
 */
bool read_s32s(const uint8_t *const buffer, const size_t buffer_length, int32_t *const s32s, const size_t quantity, const size_t offset);

#endif
