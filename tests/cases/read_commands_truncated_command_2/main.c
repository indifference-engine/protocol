#include <stddef.h>
#include "../../helpers/main.h"
#include "../../../src/read_commands.h"

static size_t handled_commands;

void handle_command(const uint8_t *const command, const size_t command_length)
{
  switch (handled_commands)
  {
  case 0:
    assert(command_length == 7, "read_commands truncated_command_2 handle_command 0 command_length");

    if (command_length == 7)
    {
      const uint8_t expected_command[] = {0x1d, 0xa8, 0x82, 0x38, 0x56, 0x11, 0x98};
      assert_u8s(expected_command, command, command_length, "read_commands truncated_command_2 handle_command 0 command");
    }
    break;

  case 1:
    assert(command_length == 2, "read_commands truncated_command_2 handle_command 1 command_length");

    if (command_length == 2)
    {
      const uint8_t expected_command[] = {0x55, 0x23};
      assert_u8s(expected_command, command, command_length, "read_commands truncated_command_2 handle_command 1 command");
    }
    break;

  case 2:
    assert(command_length == 5, "read_commands truncated_command_2 handle_command 2 command_length");

    if (command_length == 5)
    {
      const uint8_t expected_command[] = {0xde, 0x4a, 0x37, 0x87, 0x55};
      assert_u8s(expected_command, command, command_length, "read_commands truncated_command_2 handle_command 2 command");
    }
    break;
  }

  handled_commands++;
}

void test()
{
  const uint8_t actual_buffer[] = {0x07, 0x00, 0x00, 0x00, 0x1d, 0xa8, 0x82, 0x38, 0x56, 0x11, 0x98, 0x02, 0x00, 0x00, 0x00, 0x55, 0x23, 0x05, 0x00, 0x00, 0x00, 0xde, 0x4a, 0x37, 0x87, 0x55, 0x08, 0x00, 0x00, 0x00, 0x65, 0xd3, 0x7e, 0x1a, 0x2c, 0x44};

  assert(!read_commands(actual_buffer, 36, handle_command), "read_commands truncated_command_2");

  assert(handled_commands == 3, "read_commands truncated_command_2 handled_commands");
  const uint8_t expected_buffer[] = {0x07, 0x00, 0x00, 0x00, 0x1d, 0xa8, 0x82, 0x38, 0x56, 0x11, 0x98, 0x02, 0x00, 0x00, 0x00, 0x55, 0x23, 0x05, 0x00, 0x00, 0x00, 0xde, 0x4a, 0x37, 0x87, 0x55, 0x08, 0x00, 0x00, 0x00, 0x65, 0xd3, 0x7e, 0x1a, 0x2c, 0x44};
  assert_u8s(expected_buffer, actual_buffer, 36, "read_commands truncated_command_2 buffer");
}
