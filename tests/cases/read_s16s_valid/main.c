#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/read_s16s.h"

void test()
{
  int16_t actual_s16s[] = {0x7151, 0x62FA, -0x1FE8};
  const uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0x85, 0x13, 0x31, 0x89, 0x10, 0x0F};

  assert(read_s16s(actual_buffer, 12, actual_s16s, 3, 5), "read_s16s valid");

  const int16_t expected_s16s[] = {-0x7AE5, 0x3113, 0x1089};
  assert_s16s(expected_s16s, actual_s16s, 3, "read_s16s valid s16s");
  const uint8_t expected_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0x85, 0x13, 0x31, 0x89, 0x10, 0x0F};
  assert_u8s(expected_buffer, actual_buffer, 12, "read_s16s valid buffer");
}
