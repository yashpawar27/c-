#include <iostream>
#include "functions.h" //imports functions.h which contains sumOfDigits method

using std::cin, std::cout, std::endl;

// unneeded const < (this is a header guard)
const int twelve = 12;




int main() {
    int val = 0;
    cin >> val; // user sets val variable
    cout << "sum is " << sumOfDigits(val) << endl;
}