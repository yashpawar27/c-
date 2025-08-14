#include <iostream>
#include <cmath>
#include "./nth_root.h"

int main() {
    {   // MINIMUM REQUIREMENT (for this lab)
        // just call the function with various values of n and x
        for (int n = -6; n < 7; n++) {
            for (int x = -2; x < 5; x++) {
                    try {
                        nth_root(n, x);
                    } catch(std::exception& e) {}
            }
        }
        nth_root(1, 2.5);
        
    }

    {   // TRY HARD
        // report the value

        double actual = 1;
        actual = nth_root(1, 2.5);
        std::cout << "nth_root(1, 2.5) = " << actual << std::endl;

        for (int n = -6; n < 7; n++) {
            for (int x = -2; x < 5; x++) {
                try {
                    actual = nth_root(n, x);
                std::cout << "nth_root(" << x << ", "<< n <<") = " << actual << std::endl;
                } catch(std::exception& e) {}
                
            }
        }

        
    }

    {   // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1);
        double expected = 1;

        

        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
    }
}
