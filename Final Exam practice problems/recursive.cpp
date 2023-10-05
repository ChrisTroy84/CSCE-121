#include <iostream>

bool isNumericPalindrome(int num, int& reversedNum, int originalNum) {
    if (num == 0) {
        return true;
    }

    if (isNumericPalindrome(num / 10, reversedNum, originalNum)) {
        int lastDigit = num % 10;
        reversedNum = reversedNum * 10 + lastDigit;
        return originalNum == reversedNum;
    }

    return false;
}

bool isNumericPalindrome(int num) {
    if (num < 0) {
        return false; // Negative numbers are not palindromes
    }

    int reversedNum = 0;
    return isNumericPalindrome(num, reversedNum, num);
}

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    if (isNumericPalindrome(num)) {
        std::cout << num << " is a numeric palindrome." << std::endl;
    } else {
        std::cout << num << " is not a numeric palindrome." << std::endl;
    }

    return 0;
}
