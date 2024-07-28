#pragma once

#include <cerrno>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <cstdlib>

class NumberUtils {
 private:
  NumberUtils();
  NumberUtils(const NumberUtils& ref);
  NumberUtils& operator=(const NumberUtils& other);
  ~NumberUtils();

 public:
  static bool isInt(const std::string& str);
  static bool isChar(const std::string& str);
  static bool isDouble(const std::string& str);
  static bool isFloat(const std::string& str);

  static double convertToInt(const std::string& str,
                             bool& impossible);
  static double convertToChar(const std::string& str);
  static double convertToFloat(const std::string& str);
  static double convertToDouble(const std::string& str);

  static void printChar(double value);
  static void printInt(double value);
  static void printFloat(double value);
  static void printDouble(double value);
};
