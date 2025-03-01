#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "read_s64s.h"

bool read_s64s(const uint8_t *const buffer, const size_t buffer_length, int64_t *const s64s, const size_t quantity, const size_t offset)
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
        int64_t s64;
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

      s64s[index] = conversion.s64;
    }

    return true;
  }
}
