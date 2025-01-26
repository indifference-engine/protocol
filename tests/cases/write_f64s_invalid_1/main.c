#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/write_f64s.h"

void test()
{
  const double actual_f64s[] = {-13606.667950, -2903822.304621, -0.000502};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76, 0x70, 0xa6, 0xdf, 51, 0x8b, 0x00, 0x88, 0xa9, 0x72, 0x7c, 0x73, 0xc7, 0xf6};

  assert(!write_f64s(actual_f64s, 3, 2, actual_buffer, 25), "write_f64s invalid_1");

  const double expected_f64s[] = {-13606.667950, -2903822.304621, -0.000502};
  assert_f64s(expected_f64s, actual_f64s, 3, "write_f64s invalid_1 f64s");
  uint8_t expected_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76, 0x70, 0xa6, 0xdf, 51, 0x8b, 0x00, 0x88, 0xa9, 0x72, 0x7c, 0x73, 0xc7, 0xf6};
  assert_u8s(expected_buffer, actual_buffer, 25, "write_f64s invalid_1 buffer");
}
