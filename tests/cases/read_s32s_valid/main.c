#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/read_s32s.h"

void test()
{
  int32_t actual_s32s[] = {0x71510A04, 0x62FA97A2, -0x1FE8267E};
  const uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0x85, 0x13, 0x31, 0x89, 0x10, 0x0F, 0x11, 0x87, 0xAE, 0xF0, 0x88, 0xED};

  assert(read_s32s(actual_buffer, 18, actual_s32s, 3, 5), "read_s32s valid");

  const int32_t expected_s32s[] = {0x3113851b, 0x110F1089, -0x770F5179};
  assert_s32s(expected_s32s, actual_s32s, 3, "read_s32s valid s32s");
  const uint8_t expected_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0x85, 0x13, 0x31, 0x89, 0x10, 0x0F, 0x11, 0x87, 0xAE, 0xF0, 0x88, 0xED};
  assert_u8s(expected_buffer, actual_buffer, 18, "read_s32s valid buffer");
}
