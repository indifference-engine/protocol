#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/write_s32s.h"

void test()
{
  const int32_t actual_s32s[] = {2137252282, 654169286, -664663101};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76};

  assert(!write_s32s(actual_s32s, 3, 2, actual_buffer, 12), "write_s32s invalid_2");

  const int32_t expected_s32s[] = {2137252282, 654169286, -664663101};
  assert_s32s(expected_s32s, actual_s32s, 3, "write_s32s invalid_2 s32s");
  uint8_t expected_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76};
  assert_u8s(expected_buffer, actual_buffer, 12, "write_s32s invalid_2 buffer");
}
