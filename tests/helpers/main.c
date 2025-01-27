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
      fprintf(stderr, "FAIL - %s (%lu: %d != %d)\n", description, index, expected[index], actual[index]);
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
      fprintf(stderr, "FAIL - %s (%lu: %d != %d)\n", description, index, expected[index], actual[index]);
      return;
    }
  }
}

void assert_u32s(const uint32_t *const expected, const uint32_t *const actual, const size_t quantity, const char *const description)
{
  for (size_t index = 0; index < quantity; index++)
  {
    if (expected[index] != actual[index])
    {
      exit_code = 1;
      fprintf(stderr, "FAIL - %s (%lu: %d != %d)\n", description, index, expected[index], actual[index]);
      return;
    }
  }
}

void assert_u64s(const uint64_t *const expected, const uint64_t *const actual, const size_t quantity, const char *const description)
{
  for (size_t index = 0; index < quantity; index++)
  {
    if (expected[index] != actual[index])
    {
      exit_code = 1;
      fprintf(stderr, "FAIL - %s (%lu: %llu != %llu)\n", description, index, expected[index], actual[index]);
      return;
    }
  }
}

void assert_f32s(const float *const expected, const float *const actual, const size_t quantity, const char *const description)
{
  for (size_t index = 0; index < quantity; index++)
  {
    if (expected[index] != actual[index])
    {
      exit_code = 1;
      fprintf(stderr, "FAIL - %s (%lu: %f != %f)\n", description, index, expected[index], actual[index]);
      return;
    }
  }
}

void assert_f64s(const double *const expected, const double *const actual, const size_t quantity, const char *const description)
{
  for (size_t index = 0; index < quantity; index++)
  {
    if (expected[index] != actual[index])
    {
      exit_code = 1;
      fprintf(stderr, "FAIL - %s (%lu: %f != %f)\n", description, index, expected[index], actual[index]);
      return;
    }
  }
}

void assert_s8s(const int8_t *const expected, const int8_t *const actual, const size_t quantity, const char *const description)
{
  for (size_t index = 0; index < quantity; index++)
  {
    if (expected[index] != actual[index])
    {
      exit_code = 1;
      fprintf(stderr, "FAIL - %s (%lu: %d != %d)\n", description, index, expected[index], actual[index]);
      return;
    }
  }
}

void assert_s16s(const int16_t *const expected, const int16_t *const actual, const size_t quantity, const char *const description)
{
  for (size_t index = 0; index < quantity; index++)
  {
    if (expected[index] != actual[index])
    {
      exit_code = 1;
      fprintf(stderr, "FAIL - %s (%lu: %d != %d)\n", description, index, expected[index], actual[index]);
      return;
    }
  }
}

void assert_s32s(const int32_t *const expected, const int32_t *const actual, const size_t quantity, const char *const description)
{
  for (size_t index = 0; index < quantity; index++)
  {
    if (expected[index] != actual[index])
    {
      exit_code = 1;
      fprintf(stderr, "FAIL - %s (%lu: %d != %d)\n", description, index, expected[index], actual[index]);
      return;
    }
  }
}

void assert_s64s(const int64_t *const expected, const int64_t *const actual, const size_t quantity, const char *const description)
{
  for (size_t index = 0; index < quantity; index++)
  {
    if (expected[index] != actual[index])
    {
      exit_code = 1;
      fprintf(stderr, "FAIL - %s (%lu: %lld != %lld)\n", description, index, expected[index], actual[index]);
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
