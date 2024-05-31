#include "Point.hpp"

Point::Point() {}

Point::Point(const float point_num_x, const float point_num_y)
    : x_(point_num_x), y_(point_num_y) {}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {}

Point& Point::operator=(const Point& other) {
  if (this != &other) {
    const_cast<Fixed&>(x_) = other.getX();
    const_cast<Fixed&>(y_) = other.getY();
  }
  return *this;
}

Point Point::operator-(const Point& ref) const {
  Point temp((x_ - ref.getX()).toFloat(), (y_ - ref.getY()).toFloat());

  return temp;
}

float Point::innerProduct(const Point& norm_vec) {
  return (x_ * norm_vec.getX() + y_ * norm_vec.getY()).toFloat();
}

Point::~Point() {}

Fixed Point::getX(void) const { return x_; }

Fixed Point::getY(void) const { return y_; }

std::ostream& operator<<(std::ostream& os, const Point& pt) {
  os << "( " << pt.getX() << " , " << pt.getY() << " )";
  return os;
}