#ifndef READ_U8S_H

#define READ_U8S_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * Attempts to read one or more unsigned 8-bit integers from a buffer.
 * @param buffer The buffer from which to read the unsigned 8-bit integers.
 * @param buffer_length The length of the buffer from which to read the
 *                      unsigned 8-bit integers, in bytes.
 * @param u8s Overwritten with the read unsigned 8-bit integers should the
 *            operation succeed.
 * @param quantity The number of unsigned 8-bit integers to read.
 * @param offset The offset within the buffer from which to read the unsigned
 *               8-bit integers.
 * @return True when the operation succeeds.  False should the given integers
 *         not fit within the buffer.
 */
bool read_u8s(const uint8_t *const buffer, const size_t buffer_length, uint8_t *const u8s, const size_t quantity, const size_t offset);

#endif
