#include "Rpn.hpp"

void Rpn::rpn(std::string str) {
  std::istringstream iss(str);
  std::string temp;
  long num;

  while (std::getline(iss, temp, ' ')) {
    if (isLong(temp)) {
      num = temp[0] - '0';
      stk.push(num);
    } else if (isOperator(temp))
      calc(temp);
    else
      throw std::runtime_error("Error");
  }
  if (stk.size() != 1) throw std::runtime_error("Error");
  std::cout << stk.top() << std::endl;
}

void Rpn::calc(const std::string& op) {
  long a, b, cal;

  if (stk.size() < 2) throw std::runtime_error("Error");

  b = stk.top(), stk.pop();
  a = stk.top(), stk.pop();

  if (op == "+") {
    cal = a + b;
  } else if (op == "-") {
    cal = a - b;
  } else if (op == "*") {
    cal = a * b;
  } else {
    if (b == 0) throw std::runtime_error("Error");
    cal = a / b;
  }
  if (cal > std::numeric_limits<int>::max() ||
      cal < std::numeric_limits<int>::min())
    throw std::runtime_error("Error");
  stk.push(cal);
}

bool Rpn::isLong(const std::string& str) {
  if (str.size() == 1 && std::isdigit(str[0]))
    return true;
  return false;
}


bool Rpn::isOperator(const std::string& str) {
  return (str == "+" || str == "-" || str == "*" || str == "/");
}

Rpn::Rpn() {}

Rpn::~Rpn() {}

/* private */

Rpn::Rpn(const Rpn& rhs) { (void)rhs; }

Rpn& Rpn::operator=(const Rpn& other) {
  (void)other;
  return *this;
}
