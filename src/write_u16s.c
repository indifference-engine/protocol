#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "write_u16s.h"

bool write_u16s(const uint16_t *const u16s, const size_t quantity, const size_t offset, uint8_t *const buffer, const size_t buffer_length)
{
  if (offset + quantity * 2 > buffer_length)
  {
    return false;
  }
  else
  {
    for (size_t index = 0; index < quantity; index++)
    {
      buffer[offset + index * 2] = u16s[index] & 255;
      buffer[offset + index * 2 + 1] = u16s[index] >> 8;
    }

    return true;
  }
}
