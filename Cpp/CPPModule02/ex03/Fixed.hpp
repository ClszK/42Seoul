#pragma once

#include <cmath>
#include <iostream>

class Fixed {
 private:
  int fixed_point_num_;
  static const int num_of_fractional_bit_;  // 소수점 아래에 있는 비트들

 public:
  Fixed();
  Fixed(const int convert_fixed_point_val);
  Fixed(const float convert_fixed_point_val_f);
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  bool operator>(const Fixed& ref) const;
  bool operator<(const Fixed& ref) const;
  bool operator<=(const Fixed& ref) const;
  bool operator>=(const Fixed& ref) const;
  bool operator==(const Fixed& ref) const;
  bool operator!=(const Fixed& ref) const;
  Fixed operator+(const Fixed& ref) const;
  Fixed operator-(const Fixed& ref) const;
  Fixed operator*(const Fixed& ref) const;
  Fixed operator/(const Fixed& ref) const;
  Fixed& operator++();  // 전위 증감 연산자.
  Fixed& operator--();
  const Fixed operator++(int);  // 후위 증감 연산자.
  const Fixed operator--(int);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
  static Fixed& min(Fixed& fixed_1, Fixed& fixed_2);
  static const Fixed& min(const Fixed& fixed_1, const Fixed& fixed_2);
  static Fixed& max(Fixed& fixed_1, Fixed& fixed_2);
  static const Fixed& max(const Fixed& fixed_1, const Fixed& fixed_2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);