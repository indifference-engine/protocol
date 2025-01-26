#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include "main.h"

static int exit_code = 0;

void assert(const bool actual, const char *const description)
{
  if (!actual)
  {
    exit_code = 1;
    fprintf(stderr, "FAIL - %s\n", description);
  }
}

void assert_u8s(const uint8_t *const expected, const uint8_t *const actual, const size_t quantity, const char *const description)
{
  for (size_t index = 0; index < quantity; index++)
  {
    if (expected[index] != actual[index])
    {
      exit_code = 1;
      fprintf(stderr, "FAIL - %s (%llu: %d != %d)\n", description, index, expected[index], actual[index]);
      return;
    }
  }
}

void assert_u16s(const uint16_t *const expected, const uint16_t *const actual, const size_t quantity, const char *const description)
{
  for (size_t index = 0; index < quantity; index++)
  {
    if (expected[index] != actual[index])
    {
      exit_code = 1;
      fprintf(stderr, "FAIL - %s (%llu: %d != %d)\n", description, index, expected[index], actual[index]);
      return;
    }
  }
}

int main(const int argc, const char *const *const argv)
{
  (void)(argc);
  (void)(argv);

  test();
  return exit_code;
}
