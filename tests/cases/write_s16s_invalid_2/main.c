#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/write_s16s.h"

void test()
{
  const int16_t actual_s16s[] = {-7750, -11066, 3011};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76, 0x70};

  assert(!write_s16s(actual_s16s, 3, 9, actual_buffer, 13), "write_s16s invalid_2");

  const int16_t expected_s16s[] = {-7750, -11066, 3011};
  assert_s16s(expected_s16s, actual_s16s, 3, "write_s16s invalid_2 s16s");
  uint8_t expected_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76, 0x70};
  assert_u8s(expected_buffer, actual_buffer, 13, "write_s16s invalid_2 buffer");
}
