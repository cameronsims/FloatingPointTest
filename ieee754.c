#include "ieee754.h"
#include "menu.h"

#include <stdio.h>

long ieee754_bitsToLong(float* const pFloat) {
	return *(long*)pFloat;	// Converts proper bits from float to a long (so we can change it
}

char* ieee754_getBits(float* const pFloat) {
	// String of bits
	char bitStr[33];
	// Set the last part equal to the terminator
	bitStr[32] = '\0';
	// Convert into long
	long l = ieee754_bitsToLong(pFloat);
	// For every bit
	for (unsigned int i = 0; i < IEEE754_TOTAL_SIZE; i++) {
		// Get the current bit at i
		bool isOn = ((l >> (IEEE754_TOTAL_SIZE - i - 1)) & 0x01);
		// If it is 1 add one, if it is 0 add 0 making it either 0 or 1
		bitStr[i] = '0' + isOn;
	}
	// Return the result
	return bitStr;
}

char ieee754_getSign(const char* const pStr) {
	// From bits 1->8, calculate the number stored in exponent
	return (pStr[0] == '0') ? '+' : '-';
}

int8_t ieee754_getExp(const char* const pStr) {
	// From bits 1->8, calculate the number stored in exponent
	int8_t exp = -IEEE754_BIAS;	// Keep as negative bias, then add to it
	// For all bits
	for (unsigned int i = 1; i < IEEE754_EXPONENT_SIZE + 1; i++) {
		// Sees if the bit is active
		const bool isOn = (pStr[i] == '1');
		// Add Current Bit
		exp += isOn * pow(2, IEEE754_EXPONENT_SIZE - i);
	}
	return exp;
}

float ieee754_getMan(const char* const pStr) {
	// Used so our code looks clean
	const unsigned int mantissaBegin = IEEE754_SIGN_SIZE + IEEE754_EXPONENT_SIZE;
	// From bits 1->8, calculate the number stored in exponent
	float man = 0.0f;	// Keep as base number that we are adding to
	// For every single bit
	for (unsigned int i = mantissaBegin; i < IEEE754_TOTAL_SIZE; i++) {
		// Sees if the bit is active
		const bool isOn = (pStr[i] == '1');
		// Add to the mantissa
		man += isOn * (1 / pow(2, (i - mantissaBegin + 1)));
	}
	// Return the result
	return man;
}