#pragma once

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

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

  static double convertToInt(const std::string& str, bool& impossible);
  static double convertToChar(const std::string& str);
  static double convertToDouble(const std::string& str);
  static double convertToFloat(const std::string& str, bool& impossible);

  static void printChar(double value, bool impossible);
  static void printInt(double value, bool impossible);
  static void printFloat(double value, bool impossible);
  static void printDouble(double value, bool impossible);
};
