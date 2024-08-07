#include <iostream>
#include <string>

#include "iter.hpp"

// 테스트를 위한 함수들
void printInt(int x) { std::cout << x << " "; }

void printDouble(double x) { std::cout << x << " "; }

void printString(const std::string& s) { std::cout << s << " "; }

template <typename T>
void printElement(const T& elem) {
  std::cout << elem << " ";
}

template <typename T>
int printTemp(T a) {
  std::cout << a << " ";
  return a;
}

int main() {
  // int 배열 테스트
  int intArray[] = {1, 2, 3, 4, 5};
  size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);
  std::cout << "Int array: ";
  ::iter(intArray, intArrayLength, printInt);
  std::cout << std::endl;

  // double 배열 테스트
  double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  size_t doubleArrayLength = sizeof(doubleArray) / sizeof(doubleArray[0]);
  std::cout << "Double array: ";
  ::iter(doubleArray, doubleArrayLength, printDouble);
  std::cout << std::endl;

  // string 배열 테스트
  std::string stringArray[] = {"Hello", "World", "!"};
  size_t stringArrayLength = sizeof(stringArray) / sizeof(stringArray[0]);
  std::cout << "String array: ";
  ::iter(stringArray, stringArrayLength, printString);
  std::cout << std::endl;

  // 템플릿 함수 테스트
  std::cout << "Int array with template function: ";
  ::iter(intArray, intArrayLength, printElement<int>);
  std::cout << std::endl;

  std::cout << "Double array with template function: ";
  ::iter(doubleArray, doubleArrayLength, printElement<double>);
  std::cout << std::endl;

  std::cout << "String array with template function: ";
  ::iter(stringArray, stringArrayLength, printElement<std::string>);
  std::cout << std::endl;

  const int intArr2[] = {1, 2, 3, 4, 5};
  ::iter(intArr2, 5, printElement<int>);
  std::cout << std::endl;

  ::iter(intArr2, 5, printTemp<int>);
  std::cout << std::endl;

  return 0;
}
