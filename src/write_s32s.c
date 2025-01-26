#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "write_s32s.h"

bool write_s32s(const int32_t *const s32s, const size_t quantity, const size_t offset, uint8_t *const buffer, const size_t buffer_length)
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
      } conversion = {.s32 = s32s[index]};

      buffer[offset + index * 4] = conversion.u8s[0];
      buffer[offset + index * 4 + 1] = conversion.u8s[1];
      buffer[offset + index * 4 + 2] = conversion.u8s[2];
      buffer[offset + index * 4 + 3] = conversion.u8s[3];
    }

    return true;
  }
}
