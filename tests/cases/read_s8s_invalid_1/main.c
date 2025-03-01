#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/read_s8s.h"

void test()
{
  int8_t actual_s8s[] = {-0x71, -0x51, 0x62};
  const uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b};

  assert(!read_s8s(actual_buffer, 6, actual_s8s, 3, 4), "read_s8s invalid_1");

  const int8_t expected_s8s[] = {-0x71, -0x51, 0x62};
  assert_s8s(expected_s8s, actual_s8s, 3, "read_s8s invalid_1 s8s");
  const uint8_t expected_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b};
  assert_u8s(expected_buffer, actual_buffer, 6, "read_s8s invalid_1 buffer");
}
