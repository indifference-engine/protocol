#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/write_f64s.h"

void test()
{
  const double actual_f64s[] = {-13606.667950, -2903822.304621, -0.000502};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76, 0x70, 0xa6, 0xdf, 51, 0x8b, 0x00, 0x88, 0xa9, 0x72, 0x7c, 0x73, 0xc7, 0xf6, 0x52};

  assert(write_f64s(actual_f64s, 3, 2, actual_buffer, 26), "write_f64s valid_end");

  const double expected_f64s[] = {-13606.667950, -2903822.304621, -0.000502};
  assert_f64s(expected_f64s, actual_f64s, 3, "write_f64s valid_end f64s");
  const uint8_t expected_buffer[] = {0x08, 0xe5, 0xae, 0xb6, 0x62, 0x7f, 0x55, 0x93, 0xca, 0xc0, 0x28, 0xd2, 0xfd, 0x26, 0x87, 0x27, 0x46, 0xc1, 0xe9, 0x5f, 0x92, 0xca, 0x14, 0x73, 0x40, 0xbf};
  assert_u8s(expected_buffer, actual_buffer, 26, "write_f64s valid_end buffer");
}
