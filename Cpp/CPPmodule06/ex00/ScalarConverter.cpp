#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& str) {
  bool impossible = false;
  double value = 0.0;

  if (NumberUtils::isChar(str))
    value = NumberUtils::convertToChar(str);
  else if (NumberUtils::isInt(str))
    value = NumberUtils::convertToInt(str, impossible);
  else if (NumberUtils::isFloat(str))
    value = NumberUtils::convertToFloat(str);
  else if (NumberUtils::isDouble(str))
    value = NumberUtils::convertToDouble(str);
  else
    impossible = true;

  if (impossible) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
    return;
  }

  std::cout << impossible << std::endl;

  NumberUtils::printChar(value);
  NumberUtils::printInt(value);
  NumberUtils::printFloat(value);
  NumberUtils::printDouble(value);
}

/* Not use */

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
  (void)other;
  return *this;
}

ScalarConverter::~ScalarConverter() {}
