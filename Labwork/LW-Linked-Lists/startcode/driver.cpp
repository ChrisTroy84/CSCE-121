#include <iostream>
#include <vector>
#include "LinkedList.h"

using std::cin, std::cout, std::endl, std::vector;

// function declarations / prototypes
void testDefaultConstructor();
void testPrint();
void testHasValue();
void testPrintReverse();
void testInsertHead();
void testInsertAfter();
void testConstructorInt();
void testConstructorVector();
void testInsertBefore();
void testRemove();
void testInsertAfter();
void testRemoveAfter();
void testRemoveBefore();
void testRemoveAll();
void testClearAndDestructor();
void testCopyConstructor();
void testCopyAssignment();
void testMemory();

int main() {

// Part 1
    cout << "Testing Part 1" << endl << endl;
    // Part 1 Required
    testDefaultConstructor();
    testPrint();
    // Part 1 Optional
    testHasValue();
    testPrintReverse();

// Part 2
    cout << endl << "Testing Part 2" << endl << endl;
    // Part 2 Required
    testInsertHead();
    testInsertAfter();
    // Part 2 Optional
    testConstructorInt();
    testConstructorVector();

// Part 3
    cout << endl << "Testing Part 3" << endl << endl;
    // Part 3 Required
    testInsertBefore();
    testRemove();
    // Part 3 Optional
    testInsertAfter();
    testRemoveAfter();
    testRemoveBefore();
    testRemoveAll();

    cout << endl << "Testing Part 4" << endl << endl;
    // Part 4 Required
    testClearAndDestructor();
    testCopyConstructor();
    testCopyAssignment();
    testMemory();

}

void testDefaultConstructor() {
    cout << "test default constructor" << endl;
    cout << "LinkedList ll - default constructor" << endl;
    LinkedList ll;
    cout << "head is nullptr" << endl;
    cout << std::boolalpha << (ll.dataH() == nullptr) << endl;
    cout << "tail is nullptr" << endl;
    cout << std::boolalpha << (ll.dataT() == nullptr) << endl;
}

void testPrint() {
    cout << "test print()" << endl;
    cout << "LinkedList ll - default constructor" << endl;
    LinkedList ll;
    cout << "ll.print() - should be 'Empty List'" << endl;
    ll.print();
    cout << "loading linked list with test values - 5 14 8 33" << endl;
    ll.makeTestList();
    cout << "ll.print() - should be 5 14 8 33" << endl;
    ll.print();
}

void testHasValue() {
    cout << "test hasValue()" << endl;
    cout << "LinkedList ll - default constructor" << endl;
    LinkedList ll;
    cout << "loading linked list with test values - 5 14 8 33" << endl;
    ll.makeTestList();
    cout << "ll.hasValue(5) - check if list has 5 which is in the list" << endl;
    cout << std::boolalpha << ll.hasValue(5) << endl;
    cout << "ll.hasValue(22) - check if list has 22 which is NOT in the list" << endl;
    cout << std::boolalpha << ll.hasValue(22) << endl;
}

void testPrintReverse() {
    cout << "test printReverse()" << endl;
    cout << "LinkedList ll - default constructor" << endl;
    LinkedList ll;
    cout << "ll.printReverse() - should be empty list" << endl;
    ll.printReverse();
    cout << "loading linked list with test values - 5 14 8 33" << endl;
    ll.makeTestList();
    cout << "ll.printReverse() - should be 33 8 14 5" << endl;
    ll.printReverse();
}

void testInsertHead() {
    cout << "test insertHead()" << endl;
    cout << "LinkedList ll - default constructor" << endl;
    LinkedList ll;
    cout << "ll.insertHead(7)" << endl;
    ll.insertHead(7);
    cout << "ll.print() - should be 7" << endl;
    ll.print();
    cout << "ll.insertHead(18)" << endl;
    ll.insertHead(18);
    cout << "ll.print() - should be 18 7" << endl;
    ll.print();
    cout << "ll.insertHead(9)" << endl;
    ll.insertHead(9);
    cout << "ll.print() - should be 9 18 7" << endl;
    ll.print();
}

void testInsertAfter() { // required
    cout << "test insertAfter()" << endl;
    cout << "LinkedList ll - default constructor" << endl;   
    LinkedList ll;
    cout << "ll.insertAfter(12, 9) - with empty list" << endl;
    ll.insertAfter(12, 9);
    cout << "ll.print() - should be 12" << endl;
    ll.print();
    cout << "ll.insertAfter(21, 12) - after single item in list" << endl;
    ll.insertAfter (21, 12);
    cout << "ll.print() - should be 12 21" << endl;
    ll.print();
    cout << "ll.insertAfter (3, 21) - after last item in list" << endl;
    ll.insertAfter (3, 21);
    cout << "ll.print() - should be 12 21 3" << endl;
    ll.print();
    cout << "ll.insertAfter(25, 4) - after item not on the list" << endl;
    ll.insertAfter(25, 4);
    cout << "ll.print() - should be 12 21 3 25" << endl;
    ll.print();
    cout << "ll.insertAfter(15, 3) - after item in middle of list" << endl;
    ll.insertAfter(15, 3);
    cout << "ll.print() - should be 12 21 3 15 25" << endl;
    ll.print();
}

void testConstructorInt() {
    cout << "test Constructor from int" << endl;
    cout << "LinkedList ll(11) - construct linked list with a single value" << endl;
    LinkedList ll(11); // OR LinkedList ll = 11;
    cout << "ll.print() - should have 11 as only item" << endl;
    ll.print();
}

void testConstructorVector() {
    cout << "LinkedList ll(v) - costructor that takes a vector" << endl;
    vector<int> v {15, 9, 73, 14};
    LinkedList ll(v); // OR LinkedList ll2b = v;
    cout << "ll.print() - should have 15 9 73 14" << endl;
    ll.print();
}

void testInsertBefore() {
    cout << "LinkedList ll - default constructor" << endl;
    LinkedList ll;
    cout << "ll.insertBefore(3, 11)" << endl;
    ll.insertBefore(3, 11);
    cout << "ll.print() - should have 3" << endl;
    ll.print();
    cout << "ll.insertBefore(2, 3) - before first and only item on list" << endl;
    ll.insertBefore(2, 3);
    cout << "ll.print() - should have 2 3" << endl;
    ll.print();
    cout << "ll.insertBefore(6, 3) - before last item on list" << endl;
    ll.insertBefore(6, 3);
    cout << "ll.print() - should have 2 6 3" << endl;
    ll.print();
    cout << "ll.insertBefore(3, 2) - before first item on list" << endl;
    ll.insertBefore(3, 2);
    cout << "ll.print() - should have 3 2 6 3" << endl;
    ll.print();
}

void testRemove() {
    cout << "test remove()" << endl;
    LinkedList ll;
    ll.insertHead(3);
    ll.insertHead(6);
    ll.insertHead(2);
    ll.insertHead(3);
    cout << "list loaded with 3 2 6 3" << endl;
    cout << "ll.print() - should be 3 2 6 3" << endl;
    ll.print();
    cout << "ll.remove(6) - from middle" << endl;
    ll.remove(6);
    cout << "ll.print() - should be 3 2 3" << endl;
    ll.print();
    cout << "ll.remove(3) - from front" << endl;
    ll.remove(3);
    cout << "ll.print() - should be 2 3" << endl;
    ll.print();
    cout << "ll.remove(3) - from end" << endl;
    ll.remove(3);
    cout << "ll.print() - should be 2" << endl;
    ll.print();
    cout << "ll.remove(2) - last item" << endl;
    ll.remove(3);
    cout << "ll.print() - should be empty list" << endl;
    ll.print();
}

void testRemoveAfter() {
    cout << "test removeAfter()" << endl;
    LinkedList ll;
    ll.insertHead(10);
    ll.insertHead(8);
    ll.insertHead(6);
    ll.insertHead(4);
    ll.insertHead(2);
    cout << "list loaded with 2 4 6 8 10" << endl;
    cout << "ll.print() - should be 2 4 6 8 10" << endl;
    ll.print();
    cout << "ll.removeAfter(25) - after item not on list" << endl;
    ll.remove(25);
    cout << "ll.print() - should be 2 4 6 8 10" << endl;
    ll.print();
    cout << "ll.removeAfter(10) - after last item" << endl;
    ll.removeAfter(10);
    cout << "ll.print() - should be 2 4 6 8 10" << endl;
    ll.print();
    cout << "ll.removeAfter(4) - after middle item" << endl;
    ll.removeAfter(4);
    cout << "ll.print() - should be 2 4 8 10" << endl;
    ll.print();
    cout << "ll.removeAfter(8) - after next to last item (i.e. removes last item)" << endl;
    ll.removeAfter(8);
    cout << "ll.print() - should be 2 4 8" << endl;
    ll.print();
    cout << "ll.removeAfter(2) - after first item" << endl;
    ll.removeAfter(2);
    cout << "ll.print() - should be 2 8" << endl;
    ll.print();
    cout << "ll.removeAfter(2) - after first item and removes last item" << endl;
    ll.removeAfter(2);
    cout << "ll.print() - should be 2" << endl;
    ll.print();
}

void testRemoveBefore() {
    LinkedList ll;
    ll.insertHead(10);
    ll.insertHead(8);
    ll.insertHead(6);
    ll.insertHead(4);
    ll.insertHead(2);
    cout << "list loaded with 2 4 6 8 10" << endl;
    cout << "ll.print() - should be 2 4 6 8 10" << endl;
    ll.print();
    cout << "removeBefore(25) - remove before item not on list" << endl;
    ll.removeBefore(25);
    cout << "ll.print() - should be 2 4 6 8 10" << endl;
    ll.print();
    cout << "removeBefore(2) - remove before first item on list" << endl;
    ll.removeBefore(2);
    cout << "ll.print() - should be 2 4 6 8 10" << endl;
    ll.print();
    cout << "removeBefore(6) - remove before item in middle of list" << endl;
    ll.removeBefore(6);
    cout << "ll.print() - should be 2 6 8 10" << endl;
    ll.print();
    cout << "removeBefore(10) - remove before last item on list" << endl;
    ll.removeBefore(10);
    cout << "ll.print() - should be 2 6 10" << endl;
    ll.print();
    cout << "removeBefore(6) - remove before second item on list (i.e. remove head)" << endl;
    ll.removeBefore(6);
    cout << "ll.print() - should be 6 10" << endl;
    ll.print();
    cout << "LinkedList ll - default constructor" << endl;
    ll.removeBefore(10);
    cout << "ll.print() - should be 10" << endl;
    ll.print();
}

void testRemoveAll() {
    LinkedList ll;
    // If you implemented the constructor from a vector,
    //    you could use that instead to more easily load this list
    cout << "ll.insertHead(2)" << endl;
    ll.insertHead(3);  
    ll.insertHead(2);
    ll.insertHead(2);
    ll.insertHead(2);
    ll.insertHead(1);
    ll.insertHead(3);
    ll.insertHead(3);
    ll.insertHead(3);
    ll.insertHead(2);
    ll.insertHead(3);
    ll.insertHead(2);
    ll.insertHead(2);
    ll.insertHead(4);
    ll.insertHead(2);
    ll.insertHead(3);
    ll.insertHead(1);
    ll.insertHead(2);
    ll.insertHead(2);
    ll.insertHead(4);
    ll.insertHead(4);
    ll.insertHead(4);
    ll.insertHead(3);
    cout << "ll.print() - should be 3 4 4 4 2 2 1 3 2 4 2 2 3 2 3 3 3 1 2 2 2 3" << endl;
    ll.print();
    cout << "ll.removeAll(4) - all in the middle" << endl;
    ll.removeAll(4);
    cout << "ll.print() - should be 3 2 2 1 3 2 2 2 3 2 3 3 3 1 2 2 2 3" << endl;
    ll.print();
    cout << "ll.removeAll(3) - one at each end" << endl;
    ll.removeAll(3);
    cout << "ll.print() - should be 2 2 1 2 2 2 2 1 2 2 2" << endl;
    ll.print();
    cout << "ll.removeAll(2) - multiples at each end" << endl;
    ll.removeAll(2);
    cout << "ll.print() - should be 1 1" << endl;
    ll.print();
    cout << "ll.removeAll(1) - all the same value" << endl;
    ll.removeAll(1);
    cout << "ll.print() - should be Empty List" << endl;
    ll.print();
}

void testClearAndDestructor() {
    cout << "testing clear()" << endl;
    LinkedList ll;
    ll.insertHead(1);
    ll.insertHead(3);
    ll.insertHead(5);
    ll.insertHead(7);
    cout << "load with 7 5 3 1" << endl;
    cout << "ll.print() - should be 7 5 3 1" << endl;
    ll.print();
    cout << "ll.clear()" << endl;
    ll.clear();
    cout << "ll.print() - should be Empty List" << endl;
    ll.print();
    cout << "ll head is nullptr" << endl;
    cout << std::boolalpha << (ll.dataH() == nullptr) << endl;
    cout << "ll tail is nullptr" << endl;
    cout << std::boolalpha << (ll.dataT() == nullptr) << endl;

    { // create local scope to test destructor
    cout << "testing clear()" << endl;
    LinkedList ll;
    ll.insertHead(1);
    ll.insertHead(3);
    ll.insertHead(5);
    ll.insertHead(7);
    cout << "load with 7 5 3 1" << endl;
    cout << "ll.print() - should be 7 5 3 1" << endl;
    ll.print();
    }
    // When ll goes out of scope after the above curly brace
    //   then the destructor is called.
    // if we don't get a memory leak all should be well.
}

void testCopyConstructor() {
        cout << "LinkedList ll_src - Create first list to copy to test copy constructor" << endl;
    LinkedList ll_src;
    cout << "load with some values" << endl;
    ll_src.insertHead(91);
    ll_src.insertHead(27);
    ll_src.insertHead(33);
    cout << "ll_src.print() - should be 33 27 91" << endl;
    ll_src.print();
    cout << "LinkedList ll_cpy = ll_src - uses copy costructor" << endl; 
    LinkedList ll_cpy = ll_src; // OR LinkedList ll_cpy(ll_src);
    cout << "ll_cpy.print() - should be 33 27 91" << endl;
    ll_cpy.print();
    cout << "test deep copy by modifying both lists and printing them out" << endl;
    cout << "ll_src.insertBefore(13, 91)" << endl;
    ll_src.insertBefore(13, 91);
    cout << "ll_src.print() - should be 33 27 13 91" << endl;
    ll_src.print();
    cout << "ll_cpy.insertBefore(4, 27)" << endl;
    ll_cpy.insertBefore(4, 33);
    cout << "ll_cpy.print() - should be 33 4 27 91" << endl;
    ll_cpy.print();
}

void testCopyAssignment() {
    cout << "LinkedList ll_src - Create first list to copy to test copy assignment" << endl;
    LinkedList ll_src;
    cout << "load with some values" << endl;
    ll_src.insertHead(91);
    ll_src.insertHead(27);
    ll_src.insertHead(33);
    cout << "ll_src.print() - should be 33 27 91" << endl;
    ll_src.print();
    cout << "LinkedList ll_cpy - make an empty list" << endl;
    LinkedList ll_cpy;
    cout << "ll_cpy.print() - should be empty list" << endl;
    ll_cpy.print();
    cout << "load with some values" << endl;
    ll_cpy.insertHead(1);
    ll_cpy.insertHead(2);
    ll_cpy.insertHead(3);
    cout << "ll_cpy.print() - should be 3 2 1" << endl;
    ll_cpy.print();
    cout << "ll_cpy = ll_src - use copy assignment" << endl;
    ll_cpy = ll_src;
    cout << "ll_cpy.print() - should be 33 27 91" << endl;
    ll_cpy.print();
    cout << "test deep copy by modifying both lists and printing them out" << endl;
    cout << "ll_src.insertAfter(13, 27)" << endl;
    ll_src.insertAfter(13, 27);
    cout << "ll_src.print() - should be 33 27 13 91" << endl;
    ll_src.print();
    cout << "ll_cpy.insertAfter(4, 33)" << endl;
    ll_cpy.insertAfter(4, 33);
    cout << "ll_cpy.print() - should be 33 4 27 91" << endl;
    ll_cpy.print();
    cout << "ll_cpy = ll_cpy - self assignment" << endl;
    ll_cpy = ll_cpy;
    // ideally ll_cpy should have the same memory addresses, but we're only going to require they have the same values
    cout << "ll_cpy.print() - should be 33 4 27 91" << endl;
    ll_cpy.print();
}

void testMemory() {
    // you should have no memory leaks or memory errors
    // using -fsanitize flag will identify memory errors as you've seen
    // at this point you should have none
    // if you still do, functions to look at are
    //   * destructor
    //   * any function that removes nodes
    //   * copy assignment
}



