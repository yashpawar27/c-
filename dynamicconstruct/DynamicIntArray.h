#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include<iostream>

//write clase definition and method declarations
class DynamicArray<T> {
    int* ary;
    size_t size_;
    size_t capacity_;
    void increaseCapacity(size_t cap=0);
  public:
    DynamicIntArray() : ary(nullptr), size_(0), capacity_(0) {}
    DynamicIntArray(size_t size, T val=0);
    // capacity
    size_t size() const { return size_;}
    size_t capacity() const { return capacity_; }
    bool empty() const { return size == 0; }
    // getters / setters
    T at(size_t index) const;
    T operator[] (size_t index) const;
    T& at(size_t index); //not a safe method, so no need for const
    T& operator[] (size_t index);
    void push_back(T val);

};

template <typename T>
void DynamicArray<T>::increaseCapacity(size_t cap) {
  size_t newCapacity = capacity_*2;
  if (cap > 0 && cap > capacity_) {
      newCapacity = cap;
  }
  if (newCapacity == 0) {
      newCapacity = 1;
  }
  // allocate new array
  int* temp = new int[newCapacity];

  // copy values
  for (size_t i=0; i<capacity_; ++i) {
      temp[i] = ary[i];
  }

  // delete old memory
  delete [] ary;

  // updates
  ary = temp;
  capacity_ = newCapacity;
  temp = nullptr; // not really needed, but good practice
}

template <typename T>
DynamicArray<T>::DynamicIntArray(size_t size, T val):
  ary(nullptr), size(size), capacity_(0) {
  increaseCapacity(newCapacity); //creates the array
  for(size_t i = 0; i < size; i++) {
      ary[i] = val;
  }
}

template <typename T>
int DynamicArray<T>::at(size_t index) const{
  if (index >= size_) {
      throw std::out_of_range("index out of range");
  }
  return ary[index];
}

template <typename T>
int DynamicArray<T>::operator[](size_t index) const{
  return ary[index];
}

template <typename T>
int& DynamicArray<T>::at(size_t index) {
  if(index >= size_) [
      throw std::out_of_range("index >= index")
  ]
}

template <typename T>
int& DynamicArray<T>::operator[] (size_t index) {
  return ary[index];
}

template <typename T>
void DynamicArray<T>::push_back(int val) {
  if (size_ == capacity_) {
      increaseCapacity();
  }
  ary[size_] = val;
  size_++;
}

#endif