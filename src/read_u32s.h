#ifndef READ_U32S_H

#define READ_U32S_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * Attempts to read one or more unsigned 32-bit integers from a buffer.
 * @param buffer The buffer from which to read the unsigned 32-bit integers.
 * @param buffer_length The length of the buffer from which to read the
 *                      unsigned 32-bit integers, in bytes.
 * @param u32s Overwritten with the read unsigned 32-bit integers should the
 *             operation succeed.
 * @param quantity The number of unsigned 32-bit integers to read.
 * @param offset The offset within the buffer from which to read the unsigned
 *               32-bit integers.
 * @return True when the operation succeeds.  False should the requested
 *         integers not fit within the buffer.
 */
bool read_u32s(const uint8_t *const buffer, const size_t buffer_length, uint32_t *const u32s, const size_t quantity, const size_t offset);

#endif
