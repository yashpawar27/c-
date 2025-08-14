#include <iostream>

using std::cout;
using std::endl;

int main() {
  int i = 4;
  // declare pointer variable k based on i

  int* k = nullptr; //nullptr is essential the 0 address (null); nullptr has a datatype
  k = &i; // k is the ADDRESS of i. It does not equal the value of i

  // replace ??? with the address of the variable i
  cout << "address of i: " << &i << endl; // address i *
  cout << "value in i:   " << i << endl; 

  // replace ??? with the address of the varaible k
  cout << "address of k: " << &k << endl; // address of the of address i
  cout << "value in k:   " << k << endl; // address i *

  // replace ??? with dereference of k
  cout << "value in *k:  " << *k << endl; // value of i

}