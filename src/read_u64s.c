#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "read_u64s.h"

bool read_u64s(const uint8_t *const buffer, const size_t buffer_length, uint64_t *const u64s, const size_t quantity, const size_t offset)
{
  if (offset + quantity * 8 > buffer_length)
  {
    return false;
  }
  else
  {
    for (size_t index = 0; index < quantity; index++)
    {
      union
      {
        uint64_t u64;
        uint8_t u8s[8];
      } conversion = {.u8s = {
                          buffer[offset + index * 8],
                          buffer[offset + index * 8 + 1],
                          buffer[offset + index * 8 + 2],
                          buffer[offset + index * 8 + 3],
                          buffer[offset + index * 8 + 4],
                          buffer[offset + index * 8 + 5],
                          buffer[offset + index * 8 + 6],
                          buffer[offset + index * 8 + 7],
                      }};

      u64s[index] = conversion.u64;
    }

    return true;
  }
}
