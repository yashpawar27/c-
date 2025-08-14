#include "functions.h"


int sumOfDigits(int val) {
    int sum = 0;
    int prev = 0;
    
    while(val != 0){
        int digit = val%10;
        if (digit%2 == 0) {
            sum += prev;
        }
        else {
            sum -= prev;
        }

        // sum += digit; // sum = sum + digit
        prev = digit;
        val /= 10; // goes down by a digit each time
    }
    sum += prev;
    return sum;
}