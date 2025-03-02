#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/write_u32s.h"

void test()
{
  const uint32_t actual_u32s[] = {0xbae1637f, 0xc6d4fd26, 0xc30b62d8};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76, 0x70, 0xa6};

  assert(write_u32s(actual_u32s, 3, 2, actual_buffer, 14), "write_u32s valid_end");

  const uint32_t expected_u32s[] = {0xbae1637f, 0xc6d4fd26, 0xc30b62d8};
  assert_u32s(expected_u32s, actual_u32s, 3, "write_u32s valid_end u32s");
  const uint8_t expected_buffer[] = {0x08, 0xe5, 0x7f, 0x63, 0xe1, 0xba, 0x26, 0xfd, 0xd4, 0xc6, 0xd8, 0x62, 0x0b, 0xc3};
  assert_u8s(expected_buffer, actual_buffer, 14, "write_u32s valid_end buffer");
}
