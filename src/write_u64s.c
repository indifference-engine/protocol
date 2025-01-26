#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "write_u64s.h"

bool write_u64s(const uint64_t *const u64s, const size_t quantity, const size_t offset, uint8_t *const buffer, const size_t buffer_length)
{
  if (offset + quantity * 8 > buffer_length)
  {
    return false;
  }
  else
  {
    for (size_t index = 0; index < quantity; index++)
    {
      buffer[offset + index * 8] = u64s[index] >> 56;
      buffer[offset + index * 8 + 1] = (u64s[index] >> 48) & 255;
      buffer[offset + index * 8 + 2] = (u64s[index] >> 40) & 255;
      buffer[offset + index * 8 + 3] = (u64s[index] >> 32) & 255;
      buffer[offset + index * 8 + 4] = (u64s[index] >> 24) & 255;
      buffer[offset + index * 8 + 5] = (u64s[index] >> 16) & 255;
      buffer[offset + index * 8 + 6] = (u64s[index] >> 8) & 255;
      buffer[offset + index * 8 + 7] = u64s[index] & 255;
    }

    return true;
  }
}
