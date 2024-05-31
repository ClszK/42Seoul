#include "Fixed.hpp"

const int Fixed::num_of_fractional_bit_ = 8;

Fixed::Fixed() : fixed_point_num_(0) {}

Fixed::Fixed(const int convert_fixed_point_val)
    : fixed_point_num_(convert_fixed_point_val
                       << Fixed::num_of_fractional_bit_) {}

Fixed::Fixed(const float convert_fixed_point_val_f) {
  fixed_point_num_ = static_cast<int>(
      roundf(convert_fixed_point_val_f * (1 << Fixed::num_of_fractional_bit_)));
}

Fixed::Fixed(const Fixed& other) { *this = other; }

Fixed& Fixed::operator=(const Fixed& other) {
  if (this != &other) {
    fixed_point_num_ = other.fixed_point_num_;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fix) {
  os << fix.toFloat();
  return os;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const { return fixed_point_num_; }

void Fixed::setRawBits(int const raw) { fixed_point_num_ = raw; }

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