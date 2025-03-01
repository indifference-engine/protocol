#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "read_u32s.h"

bool read_u32s(const uint8_t *const buffer, const size_t buffer_length, uint32_t *const u32s, const size_t quantity, const size_t offset)
{
  if (offset + quantity * 4 > buffer_length)
  {
    return false;
  }
  else
  {
    for (size_t index = 0; index < quantity; index++)
    {
      union
      {
        uint32_t u32;
        uint8_t u8s[4];
      } conversion = {.u8s = {
                          buffer[offset + index * 4],
                          buffer[offset + index * 4 + 1],
                          buffer[offset + index * 4 + 2],
                          buffer[offset + index * 4 + 3],
                      }};

      u32s[index] = conversion.u32;
    }

    return true;
  }
}
