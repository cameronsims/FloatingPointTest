#include <stdio.h> 

#include "ieee754.h"
#include "menu.h"

int main() {
	// Set to a default value
	float number = 0.0f;
	// Get an option from the user
	char option = ' ';
	// Select what to do
	while (option != '3') {
		// Show the menu to the user
		menu_showMenu();
		// Get a character from the user
		option = menu_getChar();
		// Jump to option
		switch (option) {
		  // Input a decimal number
		  case '1': {
			// Get a number from user
			number = menu_getFloat();
			// Show the user the binary representation
			ieee754_print(&number);
			break;
		  }
		  // Show how floating points work
		  case '2': {
			  // Blah blah blah... E. T. C!
			  menu_showHelp();
			  break;
		  }
		  // Exit
		  case '3': {
			  // Exit the program
			  break;
		  }
		  // ARG!!!
		  case '\0': {
			  break;
		  }
		  // If there is no behaviour
		  default:{
			// Set default value
			option = '1';
			// Show user what they did wrong
			menu_badEntry();
			break;
		  }
		}
	}
}