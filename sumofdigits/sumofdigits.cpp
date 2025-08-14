#include <iostream>

using std::cin, std::cout, std::endl;


int main() {
    int val = 0;
    int sum = 0;
    cin >> val; // user sets val variable

    while(val != 0){
        int digit = val%10;
        sum += digit; // sum = sum + digit
        val /= 10; // goes down by a digit each time
    }

    cout << "sum is " << sum << endl;
}