#include <iostream>

using std::cin, std::cout, std::endl;

int main()
{
    double sum = 0; //initialize and setting the sum variable
    double num = 0;
    unsigned int count = 0; // only take on positive numbers and 0 

    // 'cin' is input, 'cout' is output, 'endl' is endline

    // do-while loop
    do {
        cin >> num;
        if (num >= 0)
        {
            sum += num; // sum = sum + num
            count++;
        }
        
    } while (num >= 0); 
    // this causes the do-part to repeat until an invalid input is used


    if (count == 0) {
        cout << "No numbers entered" << endl;
    }
    else {
        cout << "average is " << sum/count << endl;
    }
}