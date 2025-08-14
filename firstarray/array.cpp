#include <iostream>

using std::cin, std::cout, std::endl;

//an array is a pointer to a block of memory
//ary[i] is a version of a dereference

// function to initialize
void initializeAry(int ary[], int size) {
    for(unsigned int i = 0; i < size; i++) {
        ary[i] = i + 1;
    }
    cout << endl;
}
// function to print (use const to prevent changing)
printAry(int ary[SIZE], int SIZE) {
    for(unsigned int i = 0; i < size; i++) {
        cout << ary[i] << " ";
    }
    cout << endl;
}

int main() {
    // declare/define array
    const unsigned int SIZE = 10;
    int ary[SIZE]; //must have a const variable for size

    // initialize with braces (modern) - do second
    // initialize with function and loop (traditional) - do first (includes traversal)
    initializeAry(ary[], SIZE);
    // print values from array through function (includes traversal)
    printAry(ary[], SIZE);
    cout << endl;

    // cout << "bad access: " << endl;
    // cout << ary[-1] << endl;

    
}