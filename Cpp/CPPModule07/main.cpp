#include <iostream>

template <typename T>

T add(T x, T y) {
  return (x + y);
}

int main() {
  int num1 = 10, num2 = 20;
  std::cout << add(num1, num2) << std::endl;

  double n1 = 10.1, n2 = 20.2;
  std::cout << add(n1, n2) << std::endl;
  return 0;
}