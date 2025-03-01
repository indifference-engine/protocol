#include <stdint.h>
#include "../../helpers/main.h"
#include "../../../src/read_f32s.h"

void test()
{
  float actual_f32s[] = {12.49f, -28.4f, 199.0f};
  uint8_t actual_buffer[] = {0x08, 0xe5, 0xba, 0xe1, 0x63, 0x7f, 0xc6, 0xd4, 0xfd, 0x26, 0xc3, 0x0b};

  assert(!read_f32s(actual_buffer, 12, actual_f32s, 3, 2), "read_f32s invalid_2");

  const float expected_f32s[] = {12.49f, -28.4f, 199.0f};
  assert_f32s(expected_f32s, actual_f32s, 3, "read_f32s invalid_2 f32s");
  const uint8_t expected_buffer[] = {0x08, 0xe5, 0xba, 0xe1, 0x63, 0x7f, 0xc6, 0xd4, 0xfd, 0x26, 0xc3, 0x0b};
  assert_u8s(expected_buffer, actual_buffer, 12, "read_f32s invalid_2 buffer");
}
