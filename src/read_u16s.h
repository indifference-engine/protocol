#ifndef READ_U16S_H

#define READ_U16S_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * Attempts to read one or more unsigned 16-bit integers from a buffer.
 * @param buffer The buffer from which to read the unsigned 16-bit integers.
 * @param buffer_length The length of the buffer from which to read the
 *                      unsigned 16-bit integers, in bytes.
 * @param u16s Overwritten with the read unsigned 16-bit integers should the
 *             operation succeed.
 * @param quantity The number of unsigned 16-bit integers to read.
 * @param offset The offset within the buffer from which to read the unsigned
 *               16-bit integers.
 * @return True when the operation succeeds.  False should the requested
 *         integers not fit within the buffer.
 */
bool read_u16s(const uint8_t *const buffer, const size_t buffer_length, uint16_t *const u16s, const size_t quantity, const size_t offset);

#endif
