#include <iostream>

using std::cin, std::cout, std::endl;

int main()
{
    double a, b, c, largest; // initialize variables
    a = b = c = largest = 0; // set variables
    cin >> a >> b >> c; // user inputs to set the values

    //if-statements
    if(a > b && a > c)
    {
        largest = a;
    }
    else if(b > c) // a is already out of consideration
    {
        largest = b;
    }
    else
    {
        largest = c;
    }

    cout << "Largest: " << largest << endl; 

}

