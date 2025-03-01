#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/write_u32s.h"

void test()
{
  const uint32_t actual_u32s[] = {0xbae1637f, 0xc6d4fd26, 0xc30b62d8};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76, 0x70, 0xa6, 0xdf};

  assert(write_u32s(actual_u32s, 3, 2, actual_buffer, 15), "write_u32s valid");

  const uint32_t expected_u32s[] = {0xbae1637f, 0xc6d4fd26, 0xc30b62d8};
  assert_u32s(expected_u32s, actual_u32s, 3, "write_u32s valid u32s");
  const uint8_t expected_buffer[] = {0x08, 0xe5, 0xba, 0xe1, 0x63, 0x7f, 0xc6, 0xd4, 0xfd, 0x26, 0xc3, 0x0b, 0x62, 0xd8, 0xdf};
  assert_u8s(expected_buffer, actual_buffer, 15, "write_u32s valid buffer");
}
