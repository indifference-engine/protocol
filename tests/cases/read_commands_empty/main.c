#include <stddef.h>
#include "../../helpers/main.h"
#include "../../../src/read_commands.h"

void handle_command(const uint8_t *const command, const size_t command_length)
{
  fail("read_commands handle_command");
}

void test()
{
  assert(read_commands(NULL, 0, handle_command), "read_commands empty");
}
