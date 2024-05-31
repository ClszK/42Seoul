#pragma once

#include <iostream>

class Fixed {
 private:
  int fixed_point_num_val_;
  static const int num_of_fractional_bit_;  // 소수점 아래에 있는 비트들

 public:
  Fixed();
  Fixed(const Fixed& other);
  Fixed& operator=(const Fixed& other);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
};
