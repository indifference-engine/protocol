#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "write_u8s.h"

bool write_u8s(const uint8_t *const u8s, const size_t quantity, const size_t offset, uint8_t *const buffer, const size_t buffer_length)
{
  if (offset + quantity > buffer_length)
  {
    return false;
  }
  else
  {
    for (size_t index = 0; index < quantity; index++)
    {
      buffer[offset + index] = u8s[index];
    }

    return true;
  }
}
