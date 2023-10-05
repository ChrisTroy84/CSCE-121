#include <iostream>

using std::cout, std::endl, std::cin;
using namespace std;


int main() {

int n;
int mod;
int digit_fact = 1;
int sum = 0;

cout << "enter an integer n to get the sum of the digit factorials: " << endl;
cin >> n;

while (n != 0) {
    mod = n % 10;
    for (int i = 1; i <= mod; ++i) {
        digit_fact *= i;
    }
    sum += digit_fact;
    
    n /= 10;
}

cout << sum << endl;

}