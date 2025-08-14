#include <iostream>

// leak happens when you lose access to the heap

int getANumber() {
   int* z = new int(15); // 2nd memory leak bc its not deleted
   return *z;
}

int main() {
   int* k = new int(3);
   k = new int (7); // the int 3 memory address is now lost/leaked
   int w = getANumber();
}
