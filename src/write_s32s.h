#ifndef WRITE_S32S_H

#define WRITE_S32S_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * Attempts to write one or more signed 32-bit integers to a buffer.
 * @param s32s The signed 32-bit integers to write.
 * @param quantity The number of signed 32-bit integers to write.
 * @param offset The offset within the buffer from which to write the signed
 *               32-bit integers.
 * @param buffer The buffer to which to write the signed 32-bit integers.
 * @param buffer_length The length of the buffer to which to write the signed
 *                      32-bit integers, in bytes.
 * @return True when the operation succeeds.  False should the given integers
 *         not fit within the buffer.
 */
bool write_s32s(const int32_t *const s32s, const size_t quantity, const size_t offset, uint8_t *const buffer, const size_t buffer_length);

#endif
