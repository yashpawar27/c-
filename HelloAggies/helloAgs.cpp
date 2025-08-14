#include <iostream>

// importing specific objects from std library
using std::cout, std::endl, std::cin, std::string; 


// you don't have to return anything for main() function
int main ()
{
    // '<<' is an arrow, << points to something
    string name;
    cout << "Hello Aggies!" << std::endl;
    cout << "What is your name? ";
    cin >> name; // allows us to input a name
    cout << "Welcome to CSCE 120, " << name << "!" << endl;
    // "Welcome to CSCE 120, Yash!" ^

}