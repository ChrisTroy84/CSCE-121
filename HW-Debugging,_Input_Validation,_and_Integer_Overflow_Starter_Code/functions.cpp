#include <iostream>
using std::cout, std::cin, std::endl;

int Largest(int a, int b, int c) {
  int d = 0;

  if (a >= b && a >= c) {
    d = a;
  } else if (b >= a && b >= c) {
    d = b;
  } else if (c >= a && c >= b) {
    d = c;
  }
  return d;
}

bool SumIsEven(int a, int b) {
  if((a + b)%2 == 0){
    return true;
  } else {
    return false;
  }
}

int BoxesNeeded(int apples) {
  if (apples <= 0) {
    return 0;
  }
  if (apples % 20 == 0) {
    return apples / 20;
  }
  return (apples/20) + 1;
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
  double perc_A; //percent A
  double perc_B; // percent B
  double doub_A = A_correct; //changing A and B to type double
  double doub_B = B_correct;
  double totA = A_total;
  double totB = B_total;

  if ((doub_A < 0) || (doub_B < 0)) {
    throw std::invalid_argument("Invalid argument.");
  }
  if ((doub_A > totA) || (doub_B > totB)) {
    throw std::invalid_argument("Invalid argument.");
  } 
  else if ((A_total <= 0) || (B_total <= 0)) {
    throw std::invalid_argument("Invalid argument.");
  }
  perc_A = doub_A / totA;
  perc_B = doub_B / totB;

  if (perc_A > perc_B) {
    return true;
  } else {
    return false;
  }
}


bool GoodDinner(int pizzas, bool is_weekend) {
  if (((pizzas >= 10) && (pizzas <= 20)) || ((pizzas >= 10) && (is_weekend))) {
    return true;
  }
  else {
    return false;
  }
}

int SumBetween(int low, int high) {
  int value = 0;
  int high_Neg;

  if (high < low) {
    throw std::invalid_argument("Invalid Argument.");
  }
  if ((low < 0 ) && (high > 0)) {
    high_Neg = -1 * high;
    if (low < high_Neg) {
      high = (-1 * high) - 1;
    }
    else if (low > high_Neg) {
      low = (-1 * low) + 1;
    }
    else if (high_Neg == low) {
      return 0;
    }
  }
  if (low == high) {
    return low;
  }

  for (int n = low; n <= high; n++) {
    if ((INT32_MAX - n) < value && n > 0) {
      throw std::overflow_error("Overeflow Error");
    }
    if ((INT32_MIN - n > value && n < 0)) {
      throw std::overflow_error("Overeflow Error");
    }
    value += n;
  }
  return value;
}

int Product(int a, int b) {
  double new_a = a;
  double new_b = b;

  if ((a < 0 && b < 0) || (a > 0 && b > 0)) {
    if (abs(a) > (INT32_MAX / abs(new_b)) || 
    (a == INT32_MIN) || (b == INT32_MIN)) {
      throw std::overflow_error("Overflow Error.");
    }
    return new_a * new_b;
  }
  if (a > b) {
    double d1 = b;
    double d2 = a;
    if (d1 < (INT32_MIN / d2)) {
      throw std::overflow_error("Overflow Error.");
    }
    return new_a * new_b;
  }
  else if (b > a) {
    double d1 = a;
    double d2 = b;
    if (d1 < (INT32_MIN / d2)) {
      throw std::overflow_error("Overflow Error.");
    }
    return new_a * new_b;
  }
  return new_a * new_b;
}