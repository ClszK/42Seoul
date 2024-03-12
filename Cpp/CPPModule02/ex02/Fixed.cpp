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

bool Fixed::operator>(const Fixed& ref) const {
  return (fixed_point_num_ > ref.fixed_point_num_);
}

bool Fixed::operator<(const Fixed& ref) const {
  return (fixed_point_num_ < ref.fixed_point_num_);
}

bool Fixed::operator<=(const Fixed& ref) const {
  return (fixed_point_num_ <= ref.fixed_point_num_);
}

bool Fixed::operator>=(const Fixed& ref) const {
  return (fixed_point_num_ >= ref.fixed_point_num_);
}

bool Fixed::operator==(const Fixed& ref) const {
  return (fixed_point_num_ == ref.fixed_point_num_);
}

bool Fixed::operator!=(const Fixed& ref) const {
  return (fixed_point_num_ != ref.fixed_point_num_);
}

Fixed Fixed::operator+(const Fixed& ref) const {
  Fixed temp;

  temp.fixed_point_num_ = (fixed_point_num_ + ref.fixed_point_num_);
  return temp;
}

Fixed Fixed::operator-(const Fixed& ref) const {
  Fixed temp;
  temp.fixed_point_num_ = (fixed_point_num_ - ref.fixed_point_num_);
  return temp;
}

Fixed Fixed::operator*(const Fixed& ref) const {
  Fixed temp(this->toFloat() * ref.toFloat());
  return temp;
}

Fixed Fixed::operator/(const Fixed& ref) const {
  Fixed temp(this->toFloat() / ref.toFloat());
  return temp;
}

Fixed& Fixed::operator++() {
  ++fixed_point_num_;
  return *this;
}

Fixed& Fixed::operator--() {
  --fixed_point_num_;
  return *this;
}

const Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  ++fixed_point_num_;
  return temp;
}

const Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  --fixed_point_num_;
  return temp;
}

Fixed& Fixed::min(Fixed& fixed_1, Fixed& fixed_2) {
  if (fixed_1 < fixed_2) return fixed_1;
  return fixed_2;
}

const Fixed& Fixed::min(const Fixed& fixed_1, const Fixed& fixed_2) {
  if (fixed_1 < fixed_2) return fixed_1;
  return fixed_2;
}

Fixed& Fixed::max(Fixed& fixed_1, Fixed& fixed_2) {
  if (fixed_1 > fixed_2) return fixed_1;
  return fixed_2;
}

const Fixed& Fixed::max(const Fixed& fixed_1, const Fixed& fixed_2) {
  if (fixed_1 > fixed_2) return fixed_1;
  return fixed_2;
}