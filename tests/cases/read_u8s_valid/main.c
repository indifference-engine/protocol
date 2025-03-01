#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/read_u8s.h"

void test()
{
  uint8_t actual_u8s[] = {0x71, 0x51, 0x62};
  const uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b};

  assert(read_u8s(actual_buffer, 6, actual_u8s, 3, 2), "read_u8s valid");

  const uint8_t expected_u8s[] = {0x2b, 0x39, 0xcb};
  assert_u8s(expected_u8s, actual_u8s, 3, "read_u8s valid u8s");
  const uint8_t expected_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b};
  assert_u8s(expected_buffer, actual_buffer, 6, "read_u8s valid buffer");
}
