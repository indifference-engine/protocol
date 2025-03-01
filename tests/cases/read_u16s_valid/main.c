#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/read_u16s.h"

void test()
{
  uint16_t actual_u16s[] = {0x7151, 0x62FA, 0xE017};
  const uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0x85, 0x13, 0x31, 0x89, 0x10, 0x0F};

  assert(read_u16s(actual_buffer, 12, actual_u16s, 3, 5), "read_u16s valid");

  const uint16_t expected_u16s[] = {0x851b, 0x3113, 0x1089};
  assert_u16s(expected_u16s, actual_u16s, 3, "read_u16s valid u16s");
  const uint8_t expected_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0x85, 0x13, 0x31, 0x89, 0x10, 0x0F};
  assert_u8s(expected_buffer, actual_buffer, 12, "read_u16s valid buffer");
}
