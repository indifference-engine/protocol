#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "read_s32s.h"

bool read_s32s(const uint8_t *const buffer, const size_t buffer_length, int32_t *const s32s, const size_t quantity, const size_t offset)
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
        int32_t s32;
        uint8_t u8s[4];
      } conversion = {.u8s = {
                          buffer[offset + index * 4],
                          buffer[offset + index * 4 + 1],
                          buffer[offset + index * 4 + 2],
                          buffer[offset + index * 4 + 3],
                      }};

      s32s[index] = conversion.s32;
    }

    return true;
  }
}
