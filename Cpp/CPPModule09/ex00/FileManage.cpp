#include "FileManage.hpp"

FileManage::FileManage() : mFile("data.csv") {
  if (!mFile.is_open()) throw std::runtime_error("Error: Can't open data.csv");

  if (mFile.peek() == std::ifstream::traits_type::eof()) {
    throw std::runtime_error("Error: File is empty data.csv");
  }
}

FileManage::FileManage(const std::string& fileName) : mFile(fileName) {
  if (!mFile.is_open())
    throw std::runtime_error("Error: Can't open " + fileName);

  if (mFile.peek() == std::ifstream::traits_type::eof()) {
    throw std::runtime_error("Error: File is empty " + fileName);
  }
}

FileManage::~FileManage() {
  if (mFile.is_open()) {
    mFile.close();
  }
}

std::string FileManage::splitDateStr(std::istringstream& iss, size_t maxSize,
                                     char seq = '-') {
  std::string str;

  if (!std::getline(iss, str, seq) || str.size() != maxSize) {
    std::cout << str << std::endl;
    throw std::runtime_error("Error: Invalid date string format or size => ");
  }

  return str;
}

int FileManage::validateDate(const std::string& str) {
  int year, month, daily;
  std::istringstream iss(str);
  std::string yearStr, monthStr, dailyStr;
  int monthlyDate[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  yearStr = splitDateStr(iss, 4);
  monthStr = splitDateStr(iss, 2);
  dailyStr = splitDateStr(iss, 2, ' ');
  year = std::stol(yearStr);
  month = std::stol(monthStr);
  daily = std::stol(dailyStr);

  if (month < 1 || month > 12)
    throw std::runtime_error("Error: bad date month => ");

  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    monthlyDate[1] = 29;

  if (daily < 1 || daily > monthlyDate[month - 1])
    throw std::runtime_error("Error: bad date daily=> ");

  return year * 10000 + month * 100 + daily;
}

std::pair<int, float> FileManage::getLineInFile(char sep) {
  std::string line, keyStr, valStr;

  while (std::getline(mFile, line)) {
    if (line.size()) break;
  }

  std::istringstream iss(line);
  float value;
  int date;

  if (iss.eof()) return std::make_pair(0, 0);
  if (!std::getline(iss, keyStr, sep) || !std::getline(iss, valStr) ||
      !iss.eof()) {
    throw std::runtime_error("Error: bad input => " + line);
  }

  date = validateDate(keyStr);
  value = validateNum(valStr);
  return std::make_pair(date, value);
}

/* private */

FileManage::FileManage(const FileManage& rhs) { (void)rhs; }

FileManage& FileManage::operator=(const FileManage& other) {
  (void)other;
  return *this;
}