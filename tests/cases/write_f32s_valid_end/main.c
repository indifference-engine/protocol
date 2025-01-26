#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/write_f32s.h"

void test()
{
  const float actual_f32s[] = {3.029068e+38f, 1.76130739e-15f, -994160600000000.0f};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76, 0x70, 0xa6};

  assert(write_f32s(actual_f32s, 3, 2, actual_buffer, 14), "write_f32s valid_end");

  const float expected_f32s[] = {3.029068e+38f, 1.76130739e-15f, -994160600000000.0f};
  assert_f32s(expected_f32s, actual_f32s, 3, "write_f32s valid_end f32s");
  uint8_t expected_buffer[] = {0x08, 0xe5, 0xba, 0xe1, 0x63, 0x7f, 0xc6, 0xd4, 0xfd, 0x26, 0xc3, 0x0b, 0x62, 0xd8};
  assert_u8s(expected_buffer, actual_buffer, 14, "write_f32s valid_end buffer");
}
