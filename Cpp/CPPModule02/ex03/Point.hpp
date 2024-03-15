#pragma once

#include "Fixed.hpp"

class Point {
 private:
  const Fixed x_;
  const Fixed y_;
  /* data */
 public:
  Point();
  Point(const float point_num_x, const float point_num_y);
  Point(const Point& other);
  Point& operator=(const Point& other);
  Point operator-(const Point& ref) const;

  ~Point();

  Fixed getX(void) const;
  Fixed getY(void) const;
  float innerProduct(const Point& norm_vec);
};

std::ostream& operator<<(std::ostream& os, const Point& pt);
bool bsp(Point const a, Point const b, Point const c, Point const point);
