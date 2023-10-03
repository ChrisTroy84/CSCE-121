#include "functions.h"
using std::cin, std::cout, std::endl, std::ostream, std::string;

#define INFO(X)  cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack& stack, int number) {
  // TODO: implement push function for stack
  int i = 0;

  if (stack.capacity == stack.count) {
    stack.capacity *= 2;
    int* temporary = new int[stack.capacity];
    for (i = 0; i < stack.capacity; ++i) {
      temporary[i] = stack.numbers[i];
    }
    temporary[stack.count] = number;
    delete[] stack.numbers;
    stack.numbers = temporary;
  }
  stack.numbers[stack.count] = number;
  stack.count++;
  //INFO_STRUCT(stack);
  //INFO(number);
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  // TODO: implement pop function for stack
  if (stack.count == 0) {
    return INT32_MAX;
  }
  int number = stack.numbers[stack.count-1];
  stack.numbers[stack.count-1] = 0;
  stack.count--;
  return number;
  //INFO_STRUCT(stack);
  //return 0;
}

/**
 * ----- REQUIRED -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
  // TODO: implement peek function for stack
  if (stack.count == 0) {
    return INT32_MAX;
  }
  int * temporary = new int[stack.capacity];
  int total = 0;
  for (int i = 0; i < stack.count - 2; ++i) {
    temporary[i] = stack.numbers[i];
    total += temporary[i];
  }
  int y = stack.count - 1;
  return y;
  delete[] temporary;
  //INFO_STRUCT(stack);
  //return 0;
}
