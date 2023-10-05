#include <iostream>

using std::cout, std::endl, std::cin;
using namespace std;

/*
    write a function with the following signature:
    int* get_array_ordered_by_frequency(int *a, unsigned int size_a, unsigned int& new_array_size);
    that, given an array a of  size_a elements, it returns a dynamically allocated array such that the new array
    contains all elements of a (without repetition), ordered by how frequently they appear in a.

    Function parameters:
    i.) a is an array of integers
    ii.) size_a is the number of elements in array a
    iii.) new_array_size is the number of elements in the array being created by the function
    The function returns the address of a dynamically created array such as the new array contains 
    the numbers that appear in a, ordered by frequency
*/

bool is_in(int *a, int b, int size) {
    for (unsigned int i = 0; i < size; i++) {
        if (a[i] == b) {
            return true;
        }
    }
    return false;
}

int count(int *a, int b, int size) {
    int count = 0;
    for (unsigned int i = 0; i < size; i++) {
        if (a[i] == b) {
            count += 1;
        }
    }
    return count;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int *get_array_ordered_by_frequency(int *a, unsigned int size_a, unsigned int& new_array_size) {

    int *counts = new int[new_array_size];
    int *sorted = new int[new_array_size];

    int size = 0;

    if (is_in(a, 0, size_a)) {
        sorted[0] = 0;
        counts[0] = count(a, 0, size_a);
        size += 1;
    }

    for (unsigned int i = 0; i < size_a; i++) {
        if (!is_in(sorted, a[i], new_array_size)) {
            sorted[size] = a[i];
            counts[size] = count(a, a[i], size_a);
            size += 1;
        }
    }

    new_array_size = size;
    for (unsigned int i = 0; i < size - 1; i++) {
        for (unsigned int j = 0; j < size - 1; j++) {
            if (counts[j] < counts[j + 1]) {
                swap(sorted[j], sorted[j + 1]);
                swap(counts[j], counts[j + 1]);
            }
        }
    }

    return sorted;
}

int main() {

    int *array = new int[8];
    int x[8] = {-1, 3, -1, 1, 1, 4, 3, 3};
    for (unsigned int i = 0; i < 8; i++) {
        array[i] = x[i];
    }
    unsigned int size = 4;
    int *temp = get_array_ordered_by_frequency(array, 8, size);

    for (unsigned int i = 0; i < size; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
    delete[] array;
    delete[] temp;
    return 0;
}