#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "write_f32s.h"

bool write_s16s(const int16_t *const s16s, const size_t quantity, const size_t offset, uint8_t *const buffer, const size_t buffer_length)
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
      } conversion = {.s16 = s16s[index]};

      buffer[offset + index * 2] = conversion.u8s[0];
      buffer[offset + index * 2 + 1] = conversion.u8s[1];
    }

    return true;
  }
}
