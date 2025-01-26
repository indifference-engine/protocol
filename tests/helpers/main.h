#ifndef MAIN_H

#define MAIN_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

void assert(const bool actual, const char *const description);

void assert_u8s(const uint8_t *const expected, const uint8_t *const actual, const size_t quantity, const char *const description);
void assert_u16s(const uint16_t *const expected, const uint16_t *const actual, const size_t quantity, const char *const description);
void assert_u32s(const uint32_t *const expected, const uint32_t *const actual, const size_t quantity, const char *const description);
void assert_u64s(const uint64_t *const expected, const uint64_t *const actual, const size_t quantity, const char *const description);
void assert_f32s(const float *const expected, const float *const actual, const size_t quantity, const char *const description);
void assert_f64s(const double *const expected, const double *const actual, const size_t quantity, const char *const description);

void test(void);

#endif
