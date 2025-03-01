#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/write_s64s.h"

void test()
{
  const int64_t actual_s64s[] = {4020187612800344506, -4880169684781116218, 2107815140410919875};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76, 0x70, 0xa6, 0xdf, 51, 0x8b, 0x00, 0x88, 0xa9, 0x72, 0x7c, 0x73, 0xc7};

  assert(!write_s64s(actual_s64s, 3, 2, actual_buffer, 24), "write_s64s invalid_1");

  const int64_t expected_s64s[] = {4020187612800344506, -4880169684781116218, 2107815140410919875};
  assert_s64s(expected_s64s, actual_s64s, 3, "write_s64s invalid_1 s64s");
  const uint8_t expected_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76, 0x70, 0xa6, 0xdf, 51, 0x8b, 0x00, 0x88, 0xa9, 0x72, 0x7c, 0x73, 0xc7};
  assert_u8s(expected_buffer, actual_buffer, 24, "write_s64s invalid_1 buffer");
}
