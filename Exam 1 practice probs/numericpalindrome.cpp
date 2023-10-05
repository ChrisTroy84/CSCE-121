#include <iostream>

using std::cout, std::endl, std::cin;
using namespace std;


/*  
    write a boolean function that takes an integer parameter and returns true if the base 10 
    number is a numeric palindrome. Note, you cannot use any type of string to solve this problem
    Ex: isNumericPalindrome(121) = true
    Ex: isNumericPalindrome(220) = false
    isNumericPalindrome(220) → false
    isNumericPalindrome(-220) → false
    isNumericPalindrome(18344381) → true
    isNumericPalindrome(12345) → false
    isNumericPalindrome(1) → true
    isNumericPalindrome(0) → true

*/

bool isNumericPalindrome(int n) {
    
    int num;
    int reverse = 0;                            // variable to store reverse of number
    int last_digit;                             // variable to store right most digit of the number 

    num = n;                                    // stores originial number

    while (n != 0) {
        last_digit = n % 10;
        reverse = reverse * 10 + last_digit;    //gives reverse number
        n = n / 10;
    }    
    if (num == reverse) {                       //if number forwards = number backwards, it is a numeric palindrome
        return true;
    }
    else {
        return false;
    }
}
int main() {
    int n;

    cout << "Enter an integer value 'n' to check if it is a numeric palindrome: " << endl;
    cin >> n;

    if (isNumericPalindrome(n) == true) {
        cout << "Your number is a numeric palindrome!" << endl;
    }
    else {
        cout << "Your number is not a numeric palindrome" << endl;
    }

    return 0;
}