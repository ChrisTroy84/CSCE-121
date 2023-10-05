#include <iostream>

using std::cout, std::endl, std::cin;
using namespace std;

//triproduct
int main() {

int a = 0;
int b = 1;
int c = 2;
int n;

cout << "Enter a number to check if it is a triproduct: " << endl;
cin >> n;
while (a * b * c  <= n) {
    if (a * b * c == n) {
        cout << "n is a triproduct" << endl;
        break;
    }
    a++;
    b++;
    c++;
}
cout << "n is not a triproduct" << endl;

return 0;

}