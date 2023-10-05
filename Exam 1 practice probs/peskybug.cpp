#include <iostream>

using std::cout, std::endl, std::cin;
using namespace std;


bool hasFailingGrade(double grades[], unsigned int size) {
  if (size == 0) {
    throw invalid_argument("There are no grades.");
  }
  
  //bool hasFailing = false;                    can take out this line no need for this function
  for (unsigned int i = 0; i < size; ++i) {
    if (grades[i] < 60) {
        return true;
      //hasFailing = true;                      therefore no need for hasFailing true/false or return statement
    }
    else {
        return false;
      //hasFailing = false;
    }
  }
  //return hasFailing;
}
