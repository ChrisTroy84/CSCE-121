#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if (10 <= a && a < 10000 && a <= b && (b < 10000) && a < 10000 && b >= 10) {
		return true;	
	}
	else if (b >= 10000) {
		return false;
	}
	else {
		return false;
	}
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	/*while (number != 0) {
		int digit1 = number % 10; 			//first digit is from the right
		int digit2 = digit1 % 10;

		if (digit2 < digit1) {				// forms \'
			return 'M';
		}
		else if (digit2 > digit1) {			// forms /
			return 'V';
		} 
		else {
			return 'N';
		}

		number = number / 10;

	}
	*/

	if (number >= 10 && number < 100) {
		int digit1 = number / 10;		// digit1 = 1st digit after dividing by 10
		int digit2 = number % 10;		// digit2 = 2nd digit after using modulo operator
			if (digit1 < digit2) {
				return 'M';
			}
			else if (digit1 > digit2) {
				return 'V';
			}
			else {
				return 'N';
			}
	}

	// for 3 digit numbers (100-999)

	else if (number >= 100 && number < 1000) {
		int digit1 = number / 100;		// Since number is now 3 digits, divide by 100 to get the first digit in the number
		int remainder = number % 100;	// need to declare a new variable in order to get the rest of the digits through int division/modulo op
		int digit2 = remainder / 10;							// gives us the 2nd digit
		int digit3 = remainder % 10;							// gives us the 3rd digit
			if (digit1 < digit2 && digit2 > digit3) {
				return 'M';
			}
			else if (digit1 > digit2 && digit2 < digit3) {
				return 'V';
			}
			else {
				return 'N';
			}
	}

	// for 4 digit numbers (1000 - 9999)

	else if (number >= 1000 && number < 10000) {
		int digit1 = number / 1000;				// number = now 4 digits so divide by 1000 to get first digit
		int remainder = number % 1000;			// need to declare a new variable in order to get the rest of the digits through int division/modulo op
		int digit2 = remainder / 100;			// gets 2nd digit from the remainder (/100) of the initial number 
		int remainder2 = remainder % 100; 		// remainder2 allows us to get the remainder of the last 2 digits in next steps
		int digit3 = remainder2 / 10;
		int digit4 = remainder2 % 10;
			if (digit1 < digit2 && digit2 > digit3 && digit3 < digit4) {
				return 'M';
			}
			else if (digit1 > digit2 && digit2 < digit3 && digit3 > digit4) {
				return 'V';
			}
			else {
				return 'N';
			}
	}

	// 5 digit numbers

	else if (number >= 10000 && number < 100000) {
		int digit1 = number / 10000;
		int remainder = number % 10000;
		int digit2 = remainder / 1000;
		int remainder2 = remainder % 1000;
		int digit3 = remainder2 / 100;
		int remainder3 = remainder2 % 100;
		int digit4 = remainder3 / 10;
		int digit5 = remainder3 % 10;
			if (digit1 < digit2 && digit2 > digit3 && digit3 < digit4 && digit4 > digit5) {
				return 'M';
			}
			else if (digit1 > digit2 && digit2 < digit3 && digit3 > digit4 && digit4 < digit5) {
				return 'V';
			}
			else {
				return 'N';
			}
	}
	else if (number >= 100000 && number < 1000000) {
		int digit1 = number / 100000;
		int remainder = number % 100000;
		int digit2 = remainder / 10000;
		int remainder2 = remainder % 10000;
		int digit3 = remainder2 / 1000;
		int remainder3 = remainder2 % 1000;
		int digit4 = remainder3 / 100;
		int remainder4 = remainder3 % 100;
		int digit5 = remainder4 / 10;
		int digit6 = remainder4 % 10;
			if (digit1 < digit2 && digit2 > digit3 && digit3 < digit4 && digit4 > digit5 && digit5 < digit6) {
				return 'M';
			}
			else if (digit1 > digit2 && digit2 < digit3 && digit3 > digit4 && digit4 < digit5 && digit5 > digit6) {
				return 'V';
			}
			else {
				return 'N';
			}
	}
	else if (number >= 1000000 && number < 10000000) {
		int digit1 = number / 1000000;
		int remainder = number % 1000000;
		int digit2 = remainder / 100000;
		int remainder2 = remainder % 100000;
		int digit3 = remainder2 / 10000;
		int remainder3 = remainder2 % 10000;
		int digit4 = remainder3 / 1000;
		int remainder4 = remainder3 % 1000;
		int digit5 = remainder4 / 100;
		int remainder5 = remainder4 % 100;
		int digit6 = remainder5 / 10;
		int digit7 = remainder5 % 10;
			if (digit1 < digit2 && digit2 > digit3 && digit3 < digit4 && digit4 > digit5 && digit5 < digit6 && digit6 > digit7) {
				return 'M';
			}
			else if (digit1 > digit2 && digit2 < digit3 && digit3 > digit4 && digit4 < digit5 && digit5 > digit6 && digit6 < digit7) {
				return 'V';
			}
			else {
				return 'N';
			}
	}
	else if (number >= 10000000 && number < 100000000) {
		int digit1 = number / 10000000;
		int remainder = number % 10000000;
		int digit2 = remainder / 1000000;
		int remainder2 = remainder % 1000000;
		int digit3 = remainder2 / 100000;
		int remainder3 = remainder2 % 100000;
		int digit4 = remainder3 / 10000;
		int remainder4 = remainder3 % 10000;
		int digit5 = remainder4 / 1000;
		int remainder5 = remainder4 % 1000;
		int digit6 = remainder5 / 100;
		int remainder6 = remainder5 % 100;
		int digit7 = remainder6 / 10;
		int digit8 = remainder6 % 10;

			if (digit1 < digit2 && digit2 > digit3 && digit3 < digit4 && digit4 > digit5 && digit5 < digit6 && digit6 > digit7 && digit7 < digit8) {
				return 'M';
			}
			else if (digit1 > digit2 && digit2 < digit3 && digit3 > digit4 && digit4 < digit5 && digit5 > digit6 && digit6 < digit7 && digit7 > digit8) {
				return 'V';
			}
			else {
				return 'N';
			}

	}
	else if (number >= 100000000 && number < 1000000000) {
		int digit1 = number / 100000000;
		int remainder = number % 100000000;
		int digit2 = remainder / 10000000;
		int remainder2 = remainder % 10000000;
		int digit3 = remainder2 / 1000000;
		int remainder3 = remainder2 % 1000000;
		int digit4 = remainder3 / 100000;
		int remainder4 = remainder3 % 100000;
		int digit5 = remainder4 / 10000;
		int remainder5 = remainder4 % 10000;
		int digit6 = remainder5 / 1000;
		int remainder6 = remainder5 % 1000;
		int digit7 = remainder6 / 100;
		int remainder7 = remainder6 % 100;
		int digit8 = remainder7 / 10;
		int digit9 = remainder7 % 10;
			if (digit1 < digit2 && digit2 > digit3 && digit3 < digit4 && digit4 > digit5 && digit5 < digit6 && digit6 > digit7 && digit7 < digit8 && digit8 > digit9) {
				return 'M';
			}
			else if (digit1 > digit2 && digit2 < digit3 && digit3 > digit4 && digit4 < digit5 && digit5 > digit6 && digit6 < digit7 && digit7 > digit8 && digit8 < digit9) {
				return 'V';
			}
			else {
				return 'N';
			}
	}
	else if (number >= 1000000000) {
		int digit1 = number / 1000000000;
		int remainder = number % 1000000000;
		int digit2 = remainder / 100000000;
		int remainder2 = remainder % 100000000;
		int digit3 = remainder2 / 10000000;
		int remainder3 = remainder2 % 10000000;
		int digit4 = remainder3 / 1000000;
		int remainder4 = remainder3 % 1000000;
		int digit5 = remainder4 / 100000;
		int remainder5 = remainder4 % 100000;
		int digit6 = remainder5 / 10000;
		int remainder6 = remainder5 % 10000;
		int digit7 = remainder6 / 1000;
		int remainder7 = remainder6 % 1000;
		int digit8 = remainder7 / 100;
		int remainder8 = remainder7 % 100;
		int digit9 = remainder8 / 10;
		int digit10 = remainder8 % 10;
			if (digit1 < digit2 && digit2 > digit3 && digit3 < digit4 && digit4 > digit5 && digit5 < digit6 && digit6 > digit7 && digit7 < digit8 && digit8 > digit9
				&& digit9 < digit10) {
				return 'M';
			}
			else if (digit1 > digit2 && digit2 < digit3 && digit3 > digit4 && digit4 < digit5 && digit5 > digit6 && digit6 < digit7 && digit7 > digit8 && digit8 < digit9
				&& digit9 > digit10) {
				return 'V';
			}
			else {
				return 'N';
			}
		}
	else {
		return 'N';
	}
	
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
	
	int num_mountains = 0;
	int num_valleys = 0;

	for (int i = a; i <= b; ++i) {				// using a for loop to check the numbers btwn a and b
		char C = classify_mv_range_type(i);
			if (C == 'M') {						// used "C" for count. Here we are checking to see if the numbers returned 'M' or 'V' and are 
				num_mountains += 1;				// then adding one to the count for the respective count to display in the solution
			}
			else if (C == 'V') {
				num_valleys += 1;
			}
	}

	cout << "There are " << num_mountains << " mountain ranges and " << num_valleys << " valley ranges between "
		<< a << " and " << b << "." << endl;



}