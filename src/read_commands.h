#ifndef READ_COMMANDS_H

#define READ_COMMANDS_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/**
 * Attempts to read a sequence of commands from a buffer.
 * @param buffer The buffer from which to read the commands.
 * @param buffer_length The length of the buffer from which to read the
 *                      commands.
 * @param handle_command Called for each successfully parsed command from the
 *                       buffer.
 * @return True when the operation succeeds.  False should the buffer not
 *         contain complete commands.
 */
bool read_commands(
    const uint8_t *const buffer,
    const size_t buffer_length,
    void (*handle_command)(const uint8_t *const command, const size_t command_length));

#endif
