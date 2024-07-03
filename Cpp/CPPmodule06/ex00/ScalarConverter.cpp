#include "ScalarConverter.hpp"

void ScalarConverter::convert(const char* str) {
  std::string stringStr(str);
  bool impossible = false;
  double value = 0.0;

  if (NumberUtils::isChar(stringStr))
    value = NumberUtils::convertToChar(stringStr);
  else if (NumberUtils::isInt(stringStr))
    value = NumberUtils::convertToInt(stringStr, impossible);
  else if (NumberUtils::isFloat(stringStr))
    value = NumberUtils::convertToFloat(stringStr, impossible);
  else if (NumberUtils::isDouble(stringStr))
    value = NumberUtils::convertToDouble(stringStr);
  else
    impossible = true;

  NumberUtils::printChar(value, impossible);
  NumberUtils::printInt(value, impossible);
  if (std::isnan(value) || std::isinf(value)) {
    std::cout << "float: " << std::showpos << static_cast<float>(value) << "f"
              << std::endl
              << "double: " << static_cast<double>(value) << std::endl;
  } else {
    NumberUtils::printFloat(value, impossible);
    NumberUtils::printDouble(value, impossible);
  }
}

/* Not use */

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  (void)other;
  return *this;
}

ScalarConverter::~ScalarConverter() {}
