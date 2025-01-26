#ifndef MAIN_H

#define MAIN_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

void assert(const bool actual, const char *const description);

void assert_u8s(const uint8_t *const expected, const uint8_t *const actual, const size_t quantity, const char *const description);
void assert_u16s(const uint16_t *const expected, const uint16_t *const actual, const size_t quantity, const char *const description);

void test(void);

#endif
