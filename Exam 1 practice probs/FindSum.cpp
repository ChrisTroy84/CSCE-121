#include <iostream>

using std::cout, std::endl, std::cin;
using namespace std;

/*
    Find the Sum
        Write a program that given:
        n where 0 < n < 5000
        a list of n numbers in increasing order 
        a target number k
        prints two distinct elements from the list such that their sum is equal to the target k if such pair exists and ”none” otherwise.
*/

//Find Sum
int main() {

    const unsigned n = 5;
    int k;
    int num_arr[n];
    int count = 0;

    /*cout << "Enter an integer vlaue for 'n': " << endl;
    cin >> n;
    */

    cout << "Enter n (5) values for the list in increasing value: ";
    for (int i = 0; i < 5; ++i) {
        cin >> num_arr[i];
    }

    cout << "Enter an integer value for the targert 'k': ";
    cin >> k;

    for (int i = 0; i < 5; ++i) {
        for (int j = i + 1; j < 5; ++j) {
            if (num_arr[i] + num_arr[j] == k) {
                count = 1;
                cout << "Pair that sums to target value: ";
                cout << num_arr[i] << " " << num_arr[j] << endl;
            } 
        }
    }
    if (count != 1) {
        cout << "None" << endl;
    }

    return 0;
}