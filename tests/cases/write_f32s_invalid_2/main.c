#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/write_f32s.h"

void test()
{
  const float actual_f32s[] = {3.029068e+38f, 1.76130739e-15f, -994160600000000.0f};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76};

  assert(!write_f32s(actual_f32s, 3, 2, actual_buffer, 12), "write_f32s invalid_2");

  const float expected_f32s[] = {3.029068e+38f, 1.76130739e-15f, -994160600000000.0f};
  assert_f32s(expected_f32s, actual_f32s, 3, "write_f32s invalid_2 f32s");
  const uint8_t expected_buffer[] = {0x08, 0xe5, 0x2b, 0x39, 0xcb, 0x1b, 0xf1, 0x87, 0x31, 0x09, 0xfe, 0x76};
  assert_u8s(expected_buffer, actual_buffer, 12, "write_f32s invalid_2 buffer");
}
