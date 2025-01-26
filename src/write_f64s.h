#ifndef WRITE_F64S_H

#define WRITE_F64S_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * Attempts to read one or more 64-bit IEEE 754 floats from a buffer.
 * @param f64s The 64-bit IEEE 754 floats to write.
 * @param quantity The number of 64-bit IEEE 754 floats to write.
 * @param offset The offset within the buffer from which to write the 64-bit
 *               IEEE 754 floats.
 * @param buffer The buffer to which to write the 64-bit IEEE 754 floats.
 * @param buffer_length The length of the buffer to which to write the 64-bit
 *                      IEEE floats, in bytes.
 * @return True when the operation succeeds.  False should the given floats not
 *         fit within the buffer.
 */
bool write_f64s(const double *const f64s, const size_t quantity, const size_t offset, uint8_t *const buffer, const size_t buffer_length);

#endif
