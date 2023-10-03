#include <iostream>
#include <string>
#include <sstream>
#include "functions.h"
using std::cin, std::cout, std::endl, std::string, std::istringstream;

int main() {
  // prompt user input
  cout << "Type RPN expression (end with '=')." << endl;
  cout << "> ";
  
  //TODO: create a command-line interface for calculator GUI
  Stack s1;
  istringstream inSS;
  string line;
  getline(cin, line);
  inSS.str(line);
  int rhs;
  int lhs;
  int result;
  Stack calculator;

  while (inSS >> line) {
    if (line == "+") {
      lhs = pop(calculator);
      rhs = pop(calculator);
      push(calculator, lhs+rhs);
    } else if (line == "-") {
      lhs = pop(calculator);
      rhs = pop(calculator);
      push(calculator, lhs-rhs);
    } else if (line == "*") {
      lhs = pop(calculator);
      rhs = pop(calculator);
      push(calculator, lhs*rhs);
    } else if (line == "=") {
      result = pop(calculator);
    } else {
      push(calculator, std::stoi(line));
    }
  }

  cout << "Ans: " << result << endl;
  delete[] calculator.numbers;

  return 0;

}