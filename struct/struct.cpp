
struct Person { // create a new Person class
    string firstname;
    string lastname;
    int grade;
};

#include <iostream>

using std::cin, std::cout, std::endl, std::string;


// define a struct Person
// include firstname, lastname, grade

int main() {
    // declare / define a struct variable
    Person p, b;


    // assign values to elements of the struct (access as well)
    p.firstname = "Yash";
    p.lastname = "Pawar";
    p.grade = 98.9;

    b = p;

    // individually to each element then to all elements at one time
    //    assing one struct to another struct

    // access elements of the struct - i.e. print them
    cout << p.firstname << " " << p.lastname << ": " << p.grade;
}