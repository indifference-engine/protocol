#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/write_s8s.h"

void test()
{
  const int8_t actual_s8s[] = {0x71, -0x51, 0x62};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb};

  assert(write_s8s(actual_s8s, 3, 2, actual_buffer, 5), "write_s8s valid_end");

  const int8_t expected_s8s[] = {0x71, -0x51, 0x62};
  assert_s8s(expected_s8s, actual_s8s, 3, "write_s8s valid_end s8s");
  uint8_t expected_buffer[] = {0x08, 0xe5, 0x71, 0xaf, 0x62};
  assert_u8s(expected_buffer, actual_buffer, 5, "write_s8s valid_end buffer");
}
