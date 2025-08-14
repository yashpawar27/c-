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
  INFO_STRUCT(stack);
  INFO(number);

  if(stack.count >= stack.capacity) {
    resize(stack);
  }

  stack.numbers[stack.count] = number;
  stack.count++;
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  // TODO: implement pop function for stack
  INFO_STRUCT(stack);

  if(stack.count == 0) {
    return INT32_MAX;
  }

  int out = stack.numbers[stack.count-1]; //dereference
  stack.count --;

  return out;
}

/**
 * ----- REQUIRED -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
  // TODO: implement peek function for stack
  INFO_STRUCT(stack);

  if(stack.count == 0) {
    return INT32_MAX;
  }


  return stack.numbers[stack.count-1];
}

void resize(Stack& stack) {

  stack.capacity *= 2;
  int* nums = new int[stack.capacity]; // empty array

  for(int i = 0; i < stack.count; i++) {
    nums[i] = stack.numbers[i];
  }

  stack.numbers = nums;
}


// void Calculator() {
//   Stack stack;
//   string input;
//   cin >> input;

//   while(input!="") {
//     if(input=="+") {
//       int right_num = pop(stack);
//       int left_num = pop(stack);
      
//     }
//   }
// }