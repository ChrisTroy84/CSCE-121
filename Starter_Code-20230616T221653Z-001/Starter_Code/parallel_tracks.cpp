#include <iostream>
#include <iomanip>
#include <cstring>
#include "parallel_tracks.h"

using std::cin, std::cout, std::endl; using std::strcpy;
using std::isspace; using std::isalpha; using std::isupper;

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
  //TODO
  unsigned int i;

  for (i = 0; i < SIZE; ++i) {
	ary[i] = 0.0;
  }
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
  //TODO
  unsigned int i;

	for (i = 0; i < SIZE; ++i) {
		ary[i] = 0;
	}
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(char ary[][STRING_SIZE])
// making sure all values within the array are set to "N/A";
{
	//TODO
	unsigned int i;

	for (i = 0; i < SIZE; ++i) {
		strcpy(ary[i], "N/A");
	}
}

//-------------------------------------------------------
// Name: trim
// PreCondition:  the cstring
// PostCondition: whitespace has been removed from beginning and end of string
//---------------------------------------------------------
void trim(char str[STRING_SIZE]) {
	// TODO
	int len_of_str;
	int start_of_str = 0;
	int end_of_str;
	int i = 0;
	
	len_of_str = strlen(str);
	end_of_str = len_of_str - 1;

	while (isspace(str[start_of_str])) { 									//whitespace at beginning
		start_of_str++;
	}
	while (isspace(str[end_of_str] && end_of_str >= start_of_str)) {		//whitespace at end
		end_of_str--;
	}
	for (i = start_of_str; i <= end_of_str - start_of_str + 1; i++) {							//move non whitespace to beginning
		str[i] = str[i + start_of_str];
	}
	str[end_of_str - start_of_str + 1] = '\0';								// empty string has '\0' at index 0
}

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data(double timeArray[], char countryArray[][STRING_SIZE], 
		unsigned int numberArray[], char lastnameArray[][STRING_SIZE]) 
{
  //TODO
  // Update function to return the correct boolean values based on the parameters
	
    for (unsigned int i = 0; i < SIZE; ++i) {
            cin >> timeArray[i];
            cin >> countryArray[i];
            cin >> numberArray[i];
            cin >> lastnameArray[i];
		//number validation
		if (numberArray[i] > 99) {
			return false;
		} 
		// time validation
		else if (timeArray[i] <= 0.0) {
			return false;
		}
		//country validation

		//name validation
		else if (strlen(lastnameArray[i]) == 0 ) {
			return false;
		}
		else if (strlen(lastnameArray[i]) <= 1) {
			return false;
		}
		/*else if (isalpha(lastnameArray[i][STRING_SIZE])) {
			return true;
		}*/
	
	}
	
	//country validation x1 test
	for (int i = 0; i < 9; ++i) {
		if (strlen(countryArray[i]) != 3) {
			return false;
		}
		else if (strlen(countryArray[i]) == 0) {
			return false;
		}
		else if (isalpha(countryArray[i][STRING_SIZE])) {
			if (isupper(countryArray[i][STRING_SIZE])) {
				return true;
			}
			else {
				return false;
			}
			
		} 
		else {
			return true;
		}
	}
	

	//name validation x2 tests
	for (int i = 0; i < 9; ++i) {
		if (strlen(lastnameArray[i]) == 0 ) {
			return false;
		}
		else if (strlen(lastnameArray[i]) <= 1) {
			return false;
		}
		else if (!isalpha(lastnameArray[i][STRING_SIZE])) {
			return false;
		}
		return false;
		
	
	}

  return true; // set so it will compile

}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	//TODO
	double n_array[SIZE];	// new array
	int i;

	for (i = 0; i < 9; ++i) {
		n_array[i] = timeArray[i];
	}
	double minValue = 99999;
	int minIndex;

	for (i = 1; i < 10; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (n_array[j] < minValue) {
				minValue = n_array[j];
				minIndex = j;
			}
			else {
				minValue = minValue;
			}
		}
		n_array[minIndex] = 99999;
		minValue = 99999;
		rankArray[minIndex] = i;
	}

}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const char countryArray[][STRING_SIZE],
		const char lastnameArray[][STRING_SIZE], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}