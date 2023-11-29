#include <stdbool.h>
#include <stdint.h>
#include <math.h>

// IEEE754 - Defines

#define IEEE754_SIGN_SIZE 1

#define IEEE754_EXPONENT_SIZE 8

#define IEEE754_MANTISSA_SIZE 23

#define IEEE754_TOTAL_SIZE IEEE754_SIGN_SIZE + IEEE754_EXPONENT_SIZE + IEEE754_MANTISSA_SIZE

#define IEEE754_BIAS 127

#define IEEE754_EMPTY "00000000000000000000000000000000"

// IEEE754 - Functions

long ieee754_bitsToLong(float* const pFloat);

char* ieee754_getBits(float* const pFloat);

char ieee754_getSign(const char* const pStr);
int8_t ieee754_getExp(const char* const pStr);
float ieee754_getMan(const char* const pStr);