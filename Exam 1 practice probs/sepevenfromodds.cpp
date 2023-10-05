#include <iostream>

using std::cout, std::endl, std::cin;
using namespace std;

/*
    Write a function that receives an array A of n integers (all elements >= 0) and 
    returns a dynamically allocated array containing all even elements of A first, then all odd elements of A. 
    The signature of the function is: int* separate_even_odd(int* A, unsigned int n);
*/

int* separate_even_odd(int* A, unsigned int n) {

    int *temp = new int[n];
    int count = 0;
    for (unsigned int i = 0; i < n; ++i) {
        if (A[i] % 2 == 0) {
            temp[count] = A[i];
            count += 1;
        }
    }
    for (unsigned int i = 0; i < n; i++) {
        if (A[i] % 2 == 1) {
            temp[count] = A[i];
            count += 1;
        }
    }
    return temp;
}


int main() {

    int *array = new int[10];
    for (unsigned int i = 0; i < 10; i++) {
        array[i] = i;
    }

    int *temp = separate_even_odd(array, 10);

    for (unsigned int i = 0; i < 10; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;

    delete[] temp;
    delete[] array;
    return 0;

}