#include "Point.hpp"

Point::Point(/* args */) {}

Point::Point(const float point_num_x, const float point_num_y)
    : x_(point_num_x), y_(point_num_y) {}

Point::Point(const Point& other) { *this = other; }

Point& Point::operator=(const Point& other) {
  if (this != &other) {
    x_ = other.x_;
    y_ = other.y_;
  }
  return *this;
}

Point::~Point() {}