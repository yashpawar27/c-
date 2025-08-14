#include <iostream>
#include <limits>

using std::cin, std::cout, std::endl;

int main()
{
    cout << "Please provide a number of lines to print the stair-case pattern : ";
    unsigned int no_lines;
    cin >> no_lines;

    while(cin.fail()) { //ensures no bad input
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        cout << "Enter a valid integer: ";
        cin >> no_lines;
    }
    
    for (unsigned int i = 1; i <= no_lines ; ++i) {
        for (unsigned int j = 1 ; j <= i ; ++j) {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}