#include <iostream>

using std::cout, std::endl, std::cin;
using namespace std;

//multiples
void printMultiples(int n, int k, int l) {
    int count = 0;
    int num = 1;

    while (count < n) {
        if (num % k == 0 || num % l == 0) {
        cout << num << " ";
        count++;
        }
    num++;
    }
}

int main() {
    int n;
    int k;
    int l;

    cout << "Enter ints for n, k, and l: " << endl;
    cin >> n >> k >> l;

    printMultiples(n, k, l);

    return 0;

}