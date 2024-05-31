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
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fix);