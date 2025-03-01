#ifndef READ_S8S_H

#define READ_S8S_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * Attempts to read one or more signed 8-bit integers from a buffer.
 * @param buffer The buffer from which to read the signed 8-bit integers.
 * @param buffer_length The length of the buffer from which to read the signed
 *                      8-bit integers, in bytes.
 * @param u8s Overwritten with the read signed 8-bit integers should the
 *            operation succeed.
 * @param quantity The number of signed 8-bit integers to read.
 * @param offset The offset within the buffer from which to read the signed
 *               8-bit integers.
 * @return True when the operation succeeds.  False should the requested
 *         integers not fit within the buffer.
 */
bool read_s8s(const uint8_t *const buffer, const size_t buffer_length, int8_t *const s8s, const size_t quantity, const size_t offset);

#endif
