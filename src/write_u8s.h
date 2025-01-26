#ifndef WRITE_U8S_H

#define WRITE_U8S_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * Attempts to write one or more unsigned 8-bit integers to a buffer.
 * @param u8s The unsigned 8-bit integers to write.
 * @param quantity The number of unsigned 8-bit integers to write.
 * @param offset The offset within the buffer from which to write the unsigned
 *               8-bit integers.
 * @param buffer The buffer to which to write the unsigned 8-bit integers.
 * @param buffer_length The length of the buffer to which to write the unsigned
 *                      8-bit integers, in bytes.
 * @return True when the operation succeeds.  False should the given integers
 *         not fit within the buffer.
 */
bool write_u8s(const uint8_t *const u8s, const size_t quantity, const size_t offset, uint8_t *const buffer, const size_t buffer_length);

#endif
