#include <iostream>

#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;

  std::cout << b << std::endl;

  std::cout << Fixed::max(a, b) << std::endl;
  std::cout << Fixed::min(a, b) << std::endl;

  std::cout << std::endl << "-----------------------" << std::endl << std::endl;

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl << std::endl;

  std::cout << "< is " << ((a < b) ? "true" : "false") << std::endl;
  std::cout << "> is " << ((a > b) ? "true" : "false") << std::endl;
  std::cout << "<= is " << ((a <= b) ? "true" : "false") << std::endl;
  std::cout << ">= is " << ((a >= b) ? "true" : "false") << std::endl;
  std::cout << "== is " << ((a == b) ? "true" : "false") << std::endl;
  std::cout << "!= is " << ((a != b) ? "true" : "false") << std::endl;
  std::cout << std::endl;

  Fixed aa(2);
  Fixed bb(2.1f);

  std::cout << "aa * bb is " << aa * bb << std::endl;
  std::cout << "aa / bb is " << aa / bb << std::endl;
  std::cout << "aa + bb is " << aa + bb << std::endl;
  std::cout << "aa - bb is " << aa - bb << std::endl;
  return 0;
}