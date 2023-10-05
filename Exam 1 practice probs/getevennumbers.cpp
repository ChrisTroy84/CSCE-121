#include <iostream>

using std::cout, std::endl, std::cin;
using namespace std;

/*
    Write a function that receives an array A of n integers (all elements >= 0) 
    and returns a dynamically allocated array containing all the even elements in A. 
    It also returns in the parameter m the number of elements in the created array.
    int* get_even_numbers(int* A, unsigned int n, unsigned int& m);
    
*/

//get even numbers
int* get_even_numbers(int* A, unsigned int n, unsigned int& m) {

    int *temp = new int[n];
    int count = 0;
    for (unsigned int i = 0; i < n; ++i) {
        if (A[i] % 2 == 0) {
            temp[count] = A[i];
            count += 1;
        }
    }
    m = count;
    int *temp2 = new int[m];
    for (unsigned int i = 0; i < m; ++i) {
        temp2[i] = temp[i];
    }

    delete[] temp;
    return temp2;
}
int main() {

    int *array = new int[10];
    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }
    unsigned int m;

    int *out = get_even_numbers(array, 10, m);
     
    for (unsigned int i = 0; i < m; i++) {
        cout << out[i] << " ";
    }
    cout << endl;
    cout << "There are " << m << " even elements in the new array" << endl;

    delete[] array;
    delete[] out;
    return 0;
}