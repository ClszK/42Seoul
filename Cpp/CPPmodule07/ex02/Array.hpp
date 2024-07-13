#pragma once

#include <exception>
#include <iostream>
#include <typeinfo>

template <typename T>
class Array {
 private:
  T* mArr;
  unsigned int mSize;

 public:
  Array();
  Array(unsigned int n);
  Array(const Array& ref);
  ~Array();
  Array<T>& operator=(const Array<T>& other);
  T& operator[](unsigned int index);
  const T& operator[](unsigned int index) const;
  unsigned int size() const;
};

#include "Array.tpp"