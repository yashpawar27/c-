#include "functions.h"


bool SumIsEven(int a, int b) {
  if((a+b)%2 == 0)
  {
    return true;
  }
  
  return false;
}

int Largest(int a, int b, int c) {
  int out = a;

  if (a > b) {
    out = a;
  } else {
    out = b;
  }

  if (c > out) {
    out = c;
  }

  return out;
}

unsigned int BoxesNeeded(int apples) {
  if (apples <= 0) {
    return 0;
  }

  int out = 0;

  out += apples/20; // divides apples by 20

  if(apples%20 != 0) { // accounts for extra apples
    out +=1;
  }

  return out;
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {


  if (A_total <= 0 || B_total <= 0 || A_correct < 0 || B_correct < 0 || A_correct > A_total ||
  B_correct > B_total) {
    throw std::invalid_argument("");
  }
    
  return ((double)A_correct/A_total) > ((double)B_correct/B_total);

}

bool GoodDinner(int pizzas, bool is_weekend) {

  if (is_weekend) {
    return pizzas >= 10;
  } else {
    return (pizzas >= 10 && pizzas <= 20);
  }

  

}

long long SumBetween(long long low, long long high) {

  long long max = LLONG_MAX; // 9,223,372,036,854,775,807
  long long min = LLONG_MIN; // -9,223,372,036,854,775,808

  if(high < low || high > max || low < min) {
    throw std::invalid_argument("");
  }

  if(low == high) { // edge case
    return high;
  }

if(low == -1*high) { // edge case
  return 0;
}



  long long out = 0;

  if (low < 0 && low > high*-1) { //reduces runtime
    std::cout << "low: " << low << std::endl;
    low *=-1;
    low++;

    if (low == high) {
      return high;
    }

    std::cout << "low: " << low << std::endl;
  } else if (high > 0 && high*-1 > low) { //reduces runtime
    std::cout << "high: " << high << std::endl;
    high *=-1;
    high--;

    if (low == high) {
      return low;
    }

    std::cout << "high: " << high << std::endl;
  } 
  

  for (long long i = low; i <= high; i++) {
    if (i >= 0 && out > max-i) { // checks max 
      throw std::overflow_error("");
    }
    if (i <= 0 && out < min-i) {
      throw std::overflow_error("");
    }
    out += i;
  }

  return out;
}

long long Product(long long a, long long b) {

  long long max = LLONG_MAX;
  long long min = LLONG_MIN;

  if (a < 0 && b > 0 && b > min/a) { // a only is negative
    // a * b > min
    throw std::overflow_error("");
    std::cout << "throws in a is negative" << std::endl;
  } else if (a > 0 && b < 0 && a > min/b) { // b only is negative
    std::cout << "throws in b is negative" << std::endl;
    // a * b > min
    throw std::overflow_error("");
  } else if (a < 0 && b < 0 && a < max/b) { // a & b are negative
    std::cout << "throws in negative" << std::endl;
    // a * b < max
    throw std::overflow_error("");
  } else if (a > 0 && b > 0 && a > max/b) { // a & b are positive
    // std::cout << "throws in positive" << std::endl;
    // std::cout << a << " > " << max/b << std::endl;
    // a * b < max
    // std::cout << a << " > " << max/b << std::endl;
    throw std::overflow_error("");
  }

  return a * b;
}