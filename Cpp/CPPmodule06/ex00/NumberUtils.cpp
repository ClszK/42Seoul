#include "NumberUtils.hpp"

bool NumberUtils::isInt(const std::string& str) {
  size_t i = 0;

  if (str[0] == '-' || str[0] == '+') ++i;
  for (; i < str.length(); ++i)
    if (!std::isdigit(str[i])) return false;
  if (i == 0) return false;
  return true;
}

bool NumberUtils::isChar(const std::string& str) {
  return str.length() == 1 && !std::isdigit(str[0]);
}

bool NumberUtils::isFloat(const std::string& str) {
  if (str[str.size() - 1] != 'f') return false;
  std::string floatStr = str.substr(0, str.length() - 1);

  return (NumberUtils::isDouble(floatStr));
}

bool NumberUtils::isDouble(const std::string& str) {
  std::istringstream iss(str);
  double doubleTypeCheck;

  return (iss >> doubleTypeCheck) && (iss.eof());
}

/*------------------convert-----------------*/

double NumberUtils::convertToChar(const std::string& str) {
  return static_cast<double>(static_cast<char>(str[0]));
}

double NumberUtils::convertToInt(const std::string& str,
                                 bool& impossible) {
  errno = 0;
  long intValue = std::strtol(str.c_str(), NULL, 10);

  if (errno == ERANGE ||
      intValue < std::numeric_limits<int>::min() ||
      intValue > std::numeric_limits<int>::max()) {
    impossible = true;
    return 0.0;
  }

  return static_cast<double>(static_cast<int>(intValue));
}

double NumberUtils::convertToFloat(const std::string& str) {
  std::string floatStr = str.substr(0, str.length() - 1);
  std::istringstream iss(floatStr);
  float value;

  iss >> value;

  return static_cast<double>(value);
}

double NumberUtils::convertToDouble(const std::string& str) {
  std::istringstream iss(str);
  double value;

  iss >> value;

  return value;
}

void NumberUtils::printChar(double value) {
  char charValue = static_cast<char>(value);

  std::cout << "char: ";
  if (std::isnan(value) || std::isinf(value) ||
      value > std::numeric_limits<char>::max() ||
      value < std::numeric_limits<char>::min())
    std::cout << "impossible" << std::endl;
  else if (std::isprint(charValue))
    std::cout << "'" << charValue << "'" << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
}

void NumberUtils::printInt(double value) {
  int intMinVal = std::numeric_limits<int>::min();
  int intMaxVal = std::numeric_limits<int>::max();

  std::cout << "int: ";
  if (std::isnan(value) || std::isinf(value) ||
      (value > intMaxVal || value < intMinVal))
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(value) << std::endl;
}

void NumberUtils::printFloat(double value) {
  std::cout << "float: ";

  float floatValue = static_cast<float>(value);
  double intPart;

  if (std::isnan(floatValue) || std::isinf(floatValue))
    std::cout << std::showpos << floatValue << "f" << std::endl;
  else if (std::modf(floatValue, &intPart) == 0.0)
    std::cout << floatValue << ".0f" << std::endl;
  else
    std::cout << floatValue << "f" << std::endl;
}

void NumberUtils::printDouble(double value) {
  double intPart = 0.0;

  std::cout << "double: ";
  if (std::isnan(value) || std::isinf(value))
    std::cout << std::showpos << value << std::endl;
  else if (std::modf(value, &intPart) == 0.0)
    std::cout << value << ".0" << std::endl;
  else
    std::cout << value << std::endl;
}

/* Not use */

NumberUtils::NumberUtils() {}
NumberUtils::NumberUtils(const NumberUtils& ref) { (void)ref; }
NumberUtils& NumberUtils::operator=(const NumberUtils& other) {
  (void)other;
  return *this;
}
NumberUtils::~NumberUtils() {}