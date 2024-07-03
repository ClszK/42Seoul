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

bool NumberUtils::isDouble(const std::string& str) {
  std::istringstream iss(str);
  double doubleTypeCheck;

  return (iss >> doubleTypeCheck) && (iss.eof());
}

bool NumberUtils::isFloat(const std::string& str) {
  if (str.back() != 'f') return false;
  std::string floatStr = str.substr(0, str.length() - 1);

  return (NumberUtils::isDouble(floatStr));
}

double NumberUtils::convertToInt(const std::string& str, bool& impossible) {
  std::istringstream iss(str);
  double value;

  iss >> value;
  if (value < std::numeric_limits<int>::min() ||
      value > std::numeric_limits<int>::max())
    impossible = true;

  return value;
}

double NumberUtils::convertToChar(const std::string& str) {
  return static_cast<double>(str[0]);
}

double NumberUtils::convertToDouble(const std::string& str) {
  std::istringstream iss(str);
  double value;

  iss >> value;

  return value;
}

double NumberUtils::convertToFloat(const std::string& str, bool& impossible) {
  std::string floatStr = str.substr(0, str.length() - 1);
  std::istringstream iss(floatStr);
  double value;

  iss >> value;

  float epsilon = std::numeric_limits<float>::epsilon();
  float floatValue = static_cast<float>(value);

  if (std::fabs(value - std::numeric_limits<float>::max()) < epsilon ||
      (value != 0.0 && floatValue == 0.0))
    impossible = true;

  return value;
}

void NumberUtils::printChar(double value, bool impossible) {
  std::cout << "char: ";
  if (std::isnan(value) || std::isinf(value) || impossible ||
      value > std::numeric_limits<char>::max() ||
      value < std::numeric_limits<char>::min())
    std::cout << "impossible" << std::endl;
  else if (std::isprint(static_cast<char>(value)))
    std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
  else
    std::cout << "Non displayable" << std::endl;
}

void NumberUtils::printInt(double value, bool impossible) {
  int intMinVal = std::numeric_limits<int>::min();
  int intMaxVal = std::numeric_limits<int>::max();

  std::cout << "int: ";
  if (std::isnan(value) || std::isinf(value) || impossible ||
      (value > intMaxVal || value < intMinVal))
    std::cout << "impossible" << std::endl;
  else
    std::cout << static_cast<int>(value) << std::endl;
}

void NumberUtils::printFloat(double value, bool impossible) {
  std::cout << "float: ";

  float floatValue = static_cast<float>(value);
  float epsilon = std::numeric_limits<float>::epsilon();

  if (std::fabs(value - std::numeric_limits<float>::max()) < epsilon ||
      (value != 0.0 && floatValue == 0.0) || impossible)
    std::cout << "impossible" << std::endl;
  else if (floatValue - static_cast<int>(floatValue) == 0)
    std::cout << static_cast<float>(value) << ".0f" << std::endl;
  else
    std::cout << static_cast<float>(value) << "f" << std::endl;
}

void NumberUtils::printDouble(double value, bool impossible) {
  std::cout << "double: ";
  if (impossible)
    std::cout << "impossible" << std::endl;
  else if (value - static_cast<int>(value) == 0)
    std::cout << static_cast<double>(value) << ".0" << std::endl;
  else
    std::cout << std::setprecision(std::numeric_limits<double>::digits10)
              << value << std::endl;
}

/* Not use */

NumberUtils::NumberUtils() {}

NumberUtils::NumberUtils(const NumberUtils& ref) { (void)ref; }

NumberUtils& NumberUtils::operator=(const NumberUtils& other) {
  (void)other;
  return *this;
}

NumberUtils::~NumberUtils() {}