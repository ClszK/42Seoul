#include "Rpn.hpp"

void Rpn::rpn(std::string str) {
  std::istringstream iss(str);
  std::string temp;
  long num;

  while (std::getline(iss, temp, ' ')) {
    if (isLong(temp)) {
      num = std::stol(temp);
      if (num > 10) throw std::runtime_error("Error: Num over 10.");
      stk.push(num);
    } else if (isOperator(temp))
      calc(temp);
    else
      throw std::runtime_error("Error: Element not num or operator.");
  }
  if (stk.size() != 1) throw std::runtime_error("Error: Invalid format.");
  std::cout << stk.top() << std::endl;
}

void Rpn::calc(const std::string& op) {
  long a, b;

  if (stk.size() < 2)
    throw std::runtime_error("Error: Stack not enough element");

  b = stk.top(), stk.pop();
  a = stk.top(), stk.pop();

  if (op == "+") {
    stk.push(a + b);
  } else if (op == "-") {
    stk.push(a - b);
  } else if (op == "*") {
    stk.push(a * b);
  } else {
    if (b == 0) throw std::runtime_error("Error: 0 division");
    stk.push(a / b);
  }
}

bool Rpn::isLong(const std::string& str) {
  try {
    size_t pos;
    std::stol(str, &pos);
    return pos == str.size();
  } catch (const std::exception& e) {
    return false;
  }
}

bool Rpn::isOperator(const std::string& str) {
  return (str == "+" || str == "-" || str == "*" || str == "/");
}

Rpn::Rpn(/* args */) {}

Rpn::~Rpn() {}

/* private */

Rpn::Rpn(const Rpn& rhs) { (void)rhs; }

Rpn& Rpn::operator=(const Rpn& other) {
  (void)other;
  return *this;
}
