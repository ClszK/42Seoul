#pragma once

#include <exception>
#include <iostream>
#include <sstream>
#include <stack>
#include <limits>
#include <cctype>
#include <cstdlib>

class Rpn {
 private:
  std::stack<long> stk;

  Rpn(const Rpn& rhs);
  Rpn& operator=(const Rpn& other);

 public:
  Rpn();
  ~Rpn();
  void rpn(std::string str);
  bool isLong(const std::string& str);
  bool isOperator(const std::string& str);
  void calc(const std::string& op);
};
