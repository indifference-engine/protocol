#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/write_s16s.h"

void test()
{
  const int16_t actual_s16s[] = {-7750, -11066, 3011};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76, 0x70, 0xa6, 0xdf, 0x8f};

  assert(write_s16s(actual_s16s, 3, 9, actual_buffer, 16), "write_s16s valid");

  const int16_t expected_s16s[] = {-7750, -11066, 3011};
  assert_s16s(expected_s16s, actual_s16s, 3, "write_s16s valid s16s");
  const uint8_t expected_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0xba, 0xe1, 0xc6, 0xd4, 0xc3, 0x0b, 0x8f};
  assert_u8s(expected_buffer, actual_buffer, 16, "write_s16s valid buffer");
}
