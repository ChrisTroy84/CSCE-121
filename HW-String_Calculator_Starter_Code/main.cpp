#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    string inputStr;
    string lhs;
    string rhs;
    string sign;
    int length;

    // TODO(student): implement the UI -
    
    cout << ">> ";
    getline(cin, inputStr);
    while (inputStr != "q" && inputStr != "quit") {
        if (inputStr.at(0) == ' ') {
            inputStr = inputStr.substr(1);
        }

        length = inputStr.find(' ');
        lhs = inputStr.substr(0, length);
        inputStr = inputStr.substr(length + 1);

        length = inputStr.find(' ');
        sign = inputStr.substr(0, length);
        inputStr = inputStr.substr(length);

        rhs = inputStr.substr(1);
        lhs = trim_leading_zeros(lhs);
        rhs = trim_leading_zeros(rhs);

        if (sign == "+") {
            cout << endl << "ans =" << endl << endl;
            cout << "    " << add(lhs,rhs) << endl << endl;
        }
        else if (sign == "*") {
            cout << endl << "ans =" << endl << endl;
            cout << "    " << multiply(lhs, rhs) << endl << endl;
        }
        else if (sign == "-") {
            cout << endl << "ans = " << endl << endl;
            cout << "    " << subtract(lhs,rhs) << endl << endl;
        }

        cout << ">> "; 
        getline(cin, inputStr);
        if (inputStr.at(0) == ' ') {
            inputStr = inputStr.substr(1);
        }
    }

    cout << endl << "farvel!" << endl << endl;
    // TODO(student): implement the UI
}

