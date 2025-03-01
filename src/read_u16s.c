#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "read_u16s.h"

bool read_u16s(const uint8_t *const buffer, const size_t buffer_length, uint16_t *const u16s, const size_t quantity, const size_t offset)
{
  if (offset + quantity * 2 > buffer_length)
  {
    return false;
  }
  else
  {
    for (size_t index = 0; index < quantity; index++)
    {
      union
      {
        uint16_t u16;
        uint8_t u8s[2];
      } conversion = {.u8s = {buffer[offset + index * 2], buffer[offset + index * 2 + 1]}};

      u16s[index] = conversion.u16;
    }

    return true;
  }
}
