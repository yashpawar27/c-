#include <iostream>

using std::cin, std::cout, std::endl;

void redecorate(int* x, int newVal) { //this rewrites the value in the memory address
    *x = newVal; // dereference x and set the pointer to newVal's address
}

void needToMove(int* x) { 
    // actual parameter for x should be assigned a new memory address
    x = new int(*x);
     // sets x equal to a new pointer
     // this also creates a memory leak bc memory is left behind
}

int main() {
    int* a = new int(5); //pointer is equal to the new int address
    int* b = a; //pointer is equal to the 'a' pointer

    cout << "value of a:  " << a << endl;
    cout << "value of *a: " << *a << endl;
    cout << "value of b:  " << b << endl;
    cout << "value of *b: " << *b << endl;
    cout << endl;

    redecorate(a, 9);
    redecorate(b, 8);

    cout << "value of a:  " << a << endl;
    cout << "value of *a: " << *a << endl;
    cout << "value of b:  " << b << endl;
    cout << "value of *b: " << *b << endl;
    cout << endl;

    needToMove(b);
    redecorate(b, 3);

    cout << "value of a:  " << a << endl;
    cout << "value of *a: " << *a << endl;
    cout << "value of b:  " << b << endl;
    cout << "value of *b: " << *b << endl;
    cout << endl;

    delete a;
    if(a != b) {
        delete b;
    }
    a = nullptr;
    b = nullptr;

}