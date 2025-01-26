#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "write_s8s.h"

bool write_s8s(const int8_t *const s8s, const size_t quantity, const size_t offset, uint8_t *const buffer, const size_t buffer_length)
{
  if (offset + quantity > buffer_length)
  {
    return false;
  }
  else
  {
    for (size_t index = 0; index < quantity; index++)
    {
      buffer[offset + index] = s8s[index];
    }

    return true;
  }
}
