#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "write_s64s.h"

bool write_s64s(const int64_t *const s64s, const size_t quantity, const size_t offset, uint8_t *const buffer, const size_t buffer_length)
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
      } conversion = {.s64 = s64s[index]};

      buffer[offset + index * 8] = conversion.u8s[0];
      buffer[offset + index * 8 + 1] = conversion.u8s[1];
      buffer[offset + index * 8 + 2] = conversion.u8s[2];
      buffer[offset + index * 8 + 3] = conversion.u8s[3];
      buffer[offset + index * 8 + 4] = conversion.u8s[4];
      buffer[offset + index * 8 + 5] = conversion.u8s[5];
      buffer[offset + index * 8 + 6] = conversion.u8s[6];
      buffer[offset + index * 8 + 7] = conversion.u8s[7];
    }

    return true;
  }
}
