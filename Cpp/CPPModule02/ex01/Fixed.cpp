#include "Fixed.hpp"

const int Fixed::num_of_fractional_bit_ = 8;

Fixed::Fixed() : fixed_point_num_(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int convert_fixed_point_val)
    : fixed_point_num_(convert_fixed_point_val
                       << Fixed::num_of_fractional_bit_) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float convert_fixed_point_val_f) {
  std::cout << "Float constructor called" << std::endl;
  fixed_point_num_ = static_cast<int>(
      roundf(convert_fixed_point_val_f * (1 << Fixed::num_of_fractional_bit_)));
}

Fixed::Fixed(const Fixed& other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    fixed_point_num_ = other.fixed_point_num_;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix) {
  os << fix.toFloat();
  return os;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return fixed_point_num_;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  fixed_point_num_ = raw;
}

float Fixed::toFloat(void) const {
  return (static_cast<float>(fixed_point_num_) /
          (1 << Fixed::num_of_fractional_bit_));
}

int Fixed::toInt(void) const {
  return (fixed_point_num_ >> Fixed::num_of_fractional_bit_);
}