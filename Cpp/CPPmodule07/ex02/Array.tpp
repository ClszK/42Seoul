#include "Array.hpp"

template <typename T>
Array<T>::Array() : mArr(new T[0]), mSize(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : mArr(new T[n]), mSize(n) {
  for (size_t i = 0; i < mSize; ++i) mArr[i] = 0;
  std::cout << "Type is ";
  std::cout << typeid(T).name() << std::endl;
}

template <typename T>
Array<T>::Array(const Array<T>& ref)
    : mArr(new T[ref.mSize]), mSize(ref.mSize) {
  for (size_t i = 0; i < mSize; ++i) mArr[i] = ref.mArr[i];
  std::cout << "Type is ";
  std::cout << typeid(T).name() << std::endl;
}

template <typename T>
Array<T>::~Array() {
  delete[] mArr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
  if (this != &other) {
    delete[] mArr;

    mSize = other.mSize;
    mArr = new T[mSize];
    for (size_t i = 0; i < mSize; ++i) mArr[i] = other.mArr[i];
    std::cout << "Type is ";
    std::cout << typeid(T).name() << std::endl;
  }

  return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
  if (index >= mSize)
    throw std::out_of_range("Index out of range.");
  return mArr[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
  if (index >= mSize)
    throw std::out_of_range("Index out of range.");
  return mArr[index];
}

template <typename T>
unsigned int Array<T>::size() const {
  return mSize;
}