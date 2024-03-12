#pragma once

#include "Fixed.hpp"

class Point {
 private:
  Fixed x_;
  Fixed y_;
  /* data */
 public:
  Point();
  Point(const float point_num_x, const float point_num_y);
  Point(const Point& other);
  Point& operator=(const Point& other);
  ~Point();
};
