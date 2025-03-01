#ifndef READ_F32S_H

#define READ_F32S_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * Attempts to read one or more signed 32-bit IEEE 754 floats from a buffer.
 * @param buffer The buffer from which to read the signed 32-bit IEEE 754
 *               floats.
 * @param buffer_length The length of the buffer from which to read the signed
 *                      32-bit IEEE 754 floats, in bytes.
 * @param s32s Overwritten with the read signed 32-bit IEEE 754 floats should
 *             the operation succeed.
 * @param quantity The number of signed 32-bit IEEE 754 floats to read.
 * @param offset The offset within the buffer from which to read the signed
 *               32-bit IEEE 754 floats.
 * @return True when the operation succeeds.  False should the requested IEEE
 *         754 floats not fit within the buffer.
 */
bool read_f32s(const uint8_t *const buffer, const size_t buffer_length, float *const f32s, const size_t quantity, const size_t offset);

#endif
