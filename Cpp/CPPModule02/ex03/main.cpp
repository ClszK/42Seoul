#include <iostream>

#include "Point.hpp"

int main(void) {
  {
    Point a(0, 0), b(2, 0), c(1, 3), p(1, 1);
    bsp(a, b, c, p);
  }  // 내부
  {
    Point a(0, 0), b(2, 0), c(1, 3), p(2, 2);
    bsp(a, b, c, p);
  }  // 외부
  {
    Point a(0, 0), b(2, 0), c(1, 3), p(0, 0);
    bsp(a, b, c, p);
  }  // 경계선 (A점)
  {
    Point a(0, 0), b(2, 0), c(1, 3), p(1, 2);
    bsp(a, b, c, p);
  }  // 내부
  {
    Point a(0, 0), b(2, 0), c(1, 3), p(1, 3);
    bsp(a, b, c, p);
  }  // 경계선 (AC 변)
  {
    Point a(0, 0), b(2, 0), c(1, 3), p(3, 1);
    bsp(a, b, c, p);
  }  // 외부
  {
    Point a(-1, -1), b(1, -1), c(0, 2), p(0, 0);
    bsp(a, b, c, p);
  }  // 내부
  {
    Point a(-1, -1), b(1, -1), c(0, 2), p(-0.5, 1);
    bsp(a, b, c, p);
  }  // 내부
  {
    Point a(-1, -1), b(1, -1), c(0, 2), p(0.5, 1);
    bsp(a, b, c, p);
  }  // 내부
  {
    Point a(-1, -1), b(1, -1), c(0, 2), p(0, -1);
    bsp(a, b, c, p);
  }  // 경계선 (AB 변)
  {
    Point a(-1, -1), b(1, -1), c(0, 2), p(0, 2);
    bsp(a, b, c, p);
  }  // 경계선 (C점)
  {
    Point a(-1, -1), b(1, -1), c(0, 2), p(1, 1);
    bsp(a, b, c, p);
  }  // 내부
  {
    Point a(-2, -2), b(2, -2), c(0, 3), p(0, -2);
    bsp(a, b, c, p);
  }  // 경계선 (AB 변)
  {
    Point a(-2, -2), b(2, -2), c(0, 3), p(-1, 0);
    bsp(a, b, c, p);
  }  // 내부
  {
    Point a(-2, -2), b(2, -2), c(0, 3), p(1, 0);
    bsp(a, b, c, p);
  }  // 내부
  {
    Point a(-2, -2), b(2, -2), c(0, 3), p(0, 1);
    bsp(a, b, c, p);
  }  // 내부
  {
    Point a(-2, -2), b(2, -2), c(0, 3), p(0, 3);
    bsp(a, b, c, p);
  }  // 경계선 (C점)
  {
    Point a(-2, -2), b(2, -2), c(0, 3), p(2, 2);
    bsp(a, b, c, p);
  }  // 외부
  {
    Point a(-2, -2), b(2, -2), c(0, 3), p(-2, -3);
    bsp(a, b, c, p);
  }  // 외부
  {
    Point a(-2, -2), b(2, -2), c(0, 3), p(2, -3);
    bsp(a, b, c, p);
  }  // 외부

  return 0;
}