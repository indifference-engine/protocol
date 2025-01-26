#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "write_f32s.h"

bool write_f32s(const float *const f32s, const size_t quantity, const size_t offset, uint8_t *const buffer, const size_t buffer_length)
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
        float f32;
        uint8_t u8s[4];
      } conversion = {.f32 = f32s[index]};

      buffer[offset + index * 4] = conversion.u8s[0];
      buffer[offset + index * 4 + 1] = conversion.u8s[1];
      buffer[offset + index * 4 + 2] = conversion.u8s[2];
      buffer[offset + index * 4 + 3] = conversion.u8s[3];
    }

    return true;
  }
}
