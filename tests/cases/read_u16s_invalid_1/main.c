#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/read_u16s.h"

void test()
{
  uint16_t actual_u16s[] = {0x7151, 0x62FA, 0xE017};
  const uint8_t actual_buffer[] = {0x0F, 0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0x85, 0x13, 0x31, 0x89, 0x10};

  assert(!read_u16s(actual_buffer, 12, actual_u16s, 3, 7), "read_u16s invalid_1");

  const uint16_t expected_u16s[] = {0x7151, 0x62FA, 0xE017};
  assert_u16s(expected_u16s, actual_u16s, 3, "read_u16s invalid_1 u16s");
  const uint8_t expected_buffer[] = {0x0F, 0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0x85, 0x13, 0x31, 0x89, 0x10};
  assert_u8s(expected_buffer, actual_buffer, 12, "read_u16s invalid_1 buffer");
}
