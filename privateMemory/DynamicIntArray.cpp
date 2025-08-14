#include "DynamicIntArray.h"

//You can set the max capacity by setting cap
void DynamicIntArray::increaseCapacity(size_t cap) { //uses scope resolution
    size_t newCapacity = capacity*2;
    if (capacity > 0 && cap > capacity) {
        newCapacity = cap;
    }
    if (newCapacity == 0) {
        newCapacity = 1;
    }
    //allocate new array
    int* temp = new int[capacity];

    //copy values
    for(size_t i = 0; i < capacity; i++) {
        temp[i] = ary[i];
    }

    //delete old memory
    delete [] ary;

    //updates
    ary = temp;
    capacity = newCapacity;
    temp = nullptr; // not needed but good practice
}