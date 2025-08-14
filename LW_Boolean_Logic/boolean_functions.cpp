#include <iostream>
#include "boolean_functions.h"

using std::cin, std::cout, std::endl, std::boolalpha;

void printNOT()
{
    // TODO: replace ?s with 0 or 1
    cout << "--- print NOT ---" << endl;

    cout << " x | NOT x" << endl;
    cout << "---+-------" << endl;
    cout << " 0 |   1" << endl;
    cout << " 1 |   0" << endl;

    cout << endl;
}

void printOR()
{
    // TODO: replace ?s with 0 or 1
    cout << "--- print OR ---" << endl;

    cout << " x | y | x OR y" << endl;
    cout << "---+---+--------" << endl;
    cout << " 0 | 0 |   0" << endl;
    cout << " 0 | 1 |   1" << endl;
    cout << " 1 | 0 |   1" << endl;
    cout << " 1 | 1 |   1" << endl;

    cout << endl;
}

void printAND()
{
    // TODO: replace ?s with 0 or 1
    cout << "--- print AND ---" << endl;

    cout << " x | y | x AND y" << endl;
    cout << "---+---+---------" << endl;
    cout << " 0 | 0 |    0" << endl;
    cout << " 0 | 1 |    0" << endl;
    cout << " 1 | 0 |    0" << endl;
    cout << " 1 | 1 |    1" << endl;

    cout << endl;
}

void printXOR()
{
    // TODO: replace ?s with 0 or 1
    cout << "--- print XOR ---" << endl;

    cout << " x | y | x XOR y" << endl;
    cout << "---+---+---------" << endl;
    cout << " 0 | 0 |    0" << endl;
    cout << " 0 | 1 |    1" << endl;
    cout << " 1 | 0 |    1" << endl;
    cout << " 1 | 1 |    0" << endl;

    cout << endl;
}

bool booleanLogic1(bool x, bool y, bool z)
{
    cout << "--- Boolean Logic 1 ---" << endl;

    bool value = false; // TODO: Fill this in
    value = x || y || z;
    cout << boolalpha << x << " OR " << y << " OR " << z << " = " << value << endl;

    cout << endl;
    return value;
}

bool booleanLogic2(bool x, bool y, bool z)
{
    cout << "--- Boolean Logic 2 ---" << endl;

    bool value = false; // TODO: Fill this in
    value = x && y && z;
    cout << boolalpha << x << " AND " << y << " AND " << z << " = " << value << endl;

    cout << endl;
    return value;
}

bool booleanLogic3(bool x, bool y, bool z)
{
    cout << "--- Boolean Logic 3 ---" << endl;

    bool value = false; // TODO: Fill this in
    value = x ^ y ^ z;
    cout << boolalpha << x << " XOR " << y << " XOR " << z << " = " << value << endl;

    cout << endl;
    return value;
}

// this function counts the letters in str
unsigned int countLetters(std::string str) 
{
    // TODO: fix error
    cout << "--- count Letters ---" << endl;


    /* "isalpha(str.at(i))" returns a number (0 or 1) for false or true
     & not a boolean, thus an if-statement wouldn't need the "== true" */
    unsigned int count = 0;
    for (unsigned int i=0; i<str.size(); ++i) {
        if (isalpha(str.at(i))) {
            count++;
        }
    }
    return count;
}

bool f(bool x, bool y, bool z)
{
    cout << "--- f ---" << endl;

    bool boolVal = true; // TODO: Fill this in

    if ((x==0 && y == 0 && z == 0) || (x==1 && y==1 && z==0) || (x==1 && y==0 && z==1)) {
        boolVal = false;
    }
    
    return boolVal;
}

void setAssignments(bool &w, bool &x, bool &y, bool &z)
// You'll learn what the & means in the function signature later this semester
// You don't need to calculate the value
{
    cout << "--- set Assignments ---" << endl;

    // TODO: Assign boolean values the four variables so that
    //   the boolean formula calcualtes to true
    w = false;
    x = false;
    y = false;
    z = false;
}




