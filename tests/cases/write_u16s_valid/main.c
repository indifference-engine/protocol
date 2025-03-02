#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/write_u16s.h"

void test()
{
  const uint16_t actual_u16s[] = {0xbae1, 0xc6d4, 0xc30b};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76, 0x70, 0xa6, 0xdf, 0x8f};

  assert(write_u16s(actual_u16s, 3, 9, actual_buffer, 16), "write_u16s valid");

  const uint16_t expected_u16s[] = {0xbae1, 0xc6d4, 0xc30b};
  assert_u16s(expected_u16s, actual_u16s, 3, "write_u16s valid u16s");
  const uint8_t expected_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0xe1, 0xba, 0xd4, 0xc6, 0x0b, 0xc3, 0x8f};
  assert_u8s(expected_buffer, actual_buffer, 16, "write_u16s valid buffer");
}
