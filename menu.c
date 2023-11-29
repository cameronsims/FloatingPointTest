#include "menu.h"
#include "ieee754.h"

#include <stdio.h>
#include <string.h>

void menu_showMenu() {
	printf("Please put in a value from 1-6:\n");
	printf("1 - Input a floating point number and see the binary representation\n");
	printf("2 - Show how floating point numbers work\n");
	printf("3 - Exit the program\n");
}

void menu_showHelp() {
	printf("Hello, this is a program to manipulate and explain IEEE-754 Floating Point Numbers!\n");
	printf("First, we must explain how the IEEE-754 Standard Works.\n");
	printf("IEEE754 Standard Floating Point Numbers are made out of a total of %d bits\n", IEEE754_TOTAL_SIZE);
	printf("The sign (+/-) (0/1), is %d bit(s), and contained at the beginning of the string.\n", IEEE754_SIGN_SIZE);
	printf("The exponent is %d bits, it is after the sign, but before the mantissa.\n", IEEE754_EXPONENT_SIZE);
	printf("The mantissa is %d birs, and is after the exponent.\n\n", IEEE754_MANTISSA_SIZE);
	printf("To demonstrate this, we will use the values for 42 and -42.\n");
	// Floating Point Number below
	float f = 42.0f;
	// Show the number's representation
	ieee754_print(&f);
	// Revert it
	f = -f;
	// Show it's representation
	ieee754_print(&f);
}

void menu_badEntry() {
	printf("Entry not recognised, please put in a different character!\n");
}

void ieee754_print(const float* const pFloat) {
	// Get the number in the context of a string
	const char* const str = (const char* const)ieee754_getBits(pFloat);
	// Show the original number
	printf("IEEE754 for %f:\n", *pFloat);
	// For every bit, print the character at the position
	for (int i = 0; i < IEEE754_TOTAL_SIZE; i++) {
		// If it is the beginning of a new section
		if (i == IEEE754_SIGN_SIZE - 1 || i == IEEE754_SIGN_SIZE || i == IEEE754_SIGN_SIZE + IEEE754_EXPONENT_SIZE) {
			printf("(");
		}
		// Print the bit at the associated position
		printf("%c", str[i]);
		// If it is the ending of a new section
		if (i == IEEE754_SIGN_SIZE - 1 || i == IEEE754_EXPONENT_SIZE || i == IEEE754_EXPONENT_SIZE + IEEE754_MANTISSA_SIZE) {
			printf(")");
		}
	}
	// New Line
	printf("\n");

	// Make a copy of the string because it modifies it???
	const char const newStr[33] = IEEE754_EMPTY;
	strcpy_s(newStr, 33 * sizeof(char), str);

	// Get the sign
	const char sign = ieee754_getSign(str);
	// Get the exponent=
	int8_t exp = ieee754_getExp(newStr);
	// Get the mantissa
	float man = (exp != 0.0f) + ieee754_getMan(newStr);

	//printf("(%c)(        )(                       )", sign);
	printf("(%c)(2^%d)(%f)\n\n", sign, exp, man);

}

char menu_getChar() {
	// Set string to some value, so compiler doesn't cry
	char c = ' ';
	// Get a string from the user
	printf("Input a character: ");
	scanf_s("%c", &c);
	// Get rid of newline character
	char workAround;
	scanf_s("%c", &workAround);
	// Return the character to user
	return c;
}

float menu_getFloat() {
	// Set float to zero so that it isn't going to cause the compiler to cry
	float f = 0.0f;
	// Get a float from the user
	printf("Input a floating point number: ");
	scanf_s("%f", &f);
	// Get rid of newline character
	char workAround;
	scanf_s("%c", &workAround);
	// Return the float to user
	return f;
}