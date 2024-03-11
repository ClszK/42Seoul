#include "Fixed.hpp"

const int Fixed::num_of_fractional_bit_ = 8;

Fixed::Fixed() : fixed_point_num_val_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    fixed_point_num_val_ = other.getRawBits();
  }
  return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return fixed_point_num_val_;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  fixed_point_num_val_ = raw;
}