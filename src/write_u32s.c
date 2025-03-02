#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "write_u32s.h"

bool write_u32s(const uint32_t *const u32s, const size_t quantity, const size_t offset, uint8_t *const buffer, const size_t buffer_length)
{
  if (offset + quantity * 4 > buffer_length)
  {
    return false;
  }
  else
  {
    for (size_t index = 0; index < quantity; index++)
    {
      buffer[offset + index * 4] = u32s[index] & 255;
      buffer[offset + index * 4 + 1] = (u32s[index] >> 8) & 255;
      buffer[offset + index * 4 + 2] = (u32s[index] >> 16) & 255;
      buffer[offset + index * 4 + 3] = u32s[index] >> 24;
    }

    return true;
  }
}
