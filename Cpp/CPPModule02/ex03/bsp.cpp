#include <iostream>

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Point ab_vec(b - a);
  Point bc_vec(c - b);
  Point ca_vec(a - c);

  Point ab_norm(ab_vec.getY().toFloat() * -1, ab_vec.getX().toFloat());
  Point bc_norm(bc_vec.getY().toFloat() * -1, bc_vec.getX().toFloat());
  Point ca_norm(ca_vec.getY().toFloat() * -1, ca_vec.getX().toFloat());

  Point ap_vec(point - a);
  Point bp_vec(point - b);
  Point cp_vec(point - c);

  float ab_ap_inner = ap_vec.innerProduct(ab_norm);
  float bc_bp_inner = bp_vec.innerProduct(bc_norm);
  float ca_cp_inner = cp_vec.innerProduct(ca_norm);

  std::cout << std::endl << point << std::endl;
  if ((ab_ap_inner > 0 && bc_bp_inner > 0 && ca_cp_inner > 0) ||
      (ab_ap_inner < 0 && bc_bp_inner < 0 && ca_cp_inner < 0)) {
    std::cout << "진실" << std::endl;
    return true;
  }
  std::cout << "거짓" << std::endl;
  return false;
}