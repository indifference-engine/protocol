#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/write_s32s.h"

void test()
{
  const int32_t actual_s32s[] = {2137252282, 654169286, -664663101};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76, 0x70, 0xa6, 0xdf};

  assert(write_s32s(actual_s32s, 3, 2, actual_buffer, 15), "write_s32s valid");

  const int32_t expected_s32s[] = {2137252282, 654169286, -664663101};
  assert_s32s(expected_s32s, actual_s32s, 3, "write_s32s valid s32s");
  uint8_t expected_buffer[] = {0x08, 0xe5, 0xba, 0xe1, 0x63, 0x7f, 0xc6, 0xd4, 0xfd, 0x26, 0xc3, 0x0b, 0x62, 0xd8, 0xdf};
  assert_u8s(expected_buffer, actual_buffer, 15, "write_s32s valid buffer");
}
