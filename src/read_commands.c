#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "read_commands.h"
#include "read_u32s.h"

bool read_commands(
    const uint8_t *const buffer,
    const size_t buffer_length,
    void (*handle_command)(const uint8_t *const command, const size_t command_length))
{
  size_t offset = 0;

  while (offset < buffer_length)
  {
    uint32_t command_length;

    if (!read_u32s(buffer, buffer_length, &command_length, 1, offset))
    {
      return false;
    }

    offset += 4;

    if (offset + command_length > buffer_length)
    {
      return false;
    }

    handle_command(buffer + offset, command_length);

    offset += command_length;
  }

  return true;
}
