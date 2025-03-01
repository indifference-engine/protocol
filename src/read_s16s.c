#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "read_s16s.h"

bool read_s16s(const uint8_t *const buffer, const size_t buffer_length, int16_t *const s16s, const size_t quantity, const size_t offset)
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
        int16_t s16;
        uint8_t u8s[2];
      } conversion = {.u8s = {buffer[offset + index * 2], buffer[offset + index * 2 + 1]}};

      s16s[index] = conversion.s16;
    }

    return true;
  }
}
