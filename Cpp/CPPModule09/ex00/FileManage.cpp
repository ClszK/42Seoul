#include "FileManage.hpp"

FileManage::FileManage() : mFile("data.csv") {
  if (!mFile.is_open()) throw std::runtime_error("Error: Can't open data.csv");

  if (mFile.peek() == std::ifstream::traits_type::eof()) {
    throw std::runtime_error("Error: File is empty data.csv");
  }
}

FileManage::FileManage(const std::string& fileName) : mFile(fileName.c_str()) {
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
    throw std::runtime_error("Error: Invalid date string format or size => ");
  }

  for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
    if (!std::isdigit(*it)) {
      throw std::runtime_error("Error: Invalid date string format => ");
    }
  }

  return str;
}

int stringToInt(const std::string& str) {
  std::stringstream ss(str);
  int result;
  if (!(ss >> result)) {
    throw std::runtime_error("Error: Invalid integer string format => " + str);
  }
  return result;
}

int FileManage::validateDate(const std::string& str) {
  int year, month, daily;
  std::istringstream iss(str);
  std::string yearStr, monthStr, dailyStr, tempStr;
  int monthlyDate[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  try {
    yearStr = splitDateStr(iss, 4);
    monthStr = splitDateStr(iss, 2);
    dailyStr = splitDateStr(iss, 2, ' ');
  } catch (const std::runtime_error& e) {
    throw std::runtime_error(e.what() + str);
  }

  if (!iss.eof()) {
    iss >> tempStr;
    for (std::string::const_iterator it = tempStr.begin(); it != tempStr.end();
         ++it) {
      if (*it != ' ')
        throw std::runtime_error("Error: Invalid date string format => " + str);
    }
  }

  year = stringToInt(yearStr);
  month = stringToInt(monthStr);
  daily = stringToInt(dailyStr);

  if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    monthlyDate[1] = 29;

  if (month < 1 || month > 12)
    throw std::runtime_error("Error: bad date month.");

  if (daily < 1 || daily > monthlyDate[month - 1])
    throw std::runtime_error("Error: bad date daily.");

  return year * 10000 + month * 100 + daily;
}

std::pair<int, float> FileManage::getLineInFile(char sep) {
  std::string line, keyStr, valStr;

  while (std::getline(mFile, line)) {
    if (line.size()) break;
  }
  if (line.empty() && mFile.eof()) return std::make_pair(0, 0);

  std::istringstream iss(line);
  float value;
  int date;

  if (!std::getline(iss, keyStr, sep) ||
      !(std::getline(iss, valStr) && iss.eof())) {
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