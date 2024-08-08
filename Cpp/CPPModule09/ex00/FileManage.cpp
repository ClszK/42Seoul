#include "FileManage.hpp"

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

std::string FileManage::splitDateStr(std::istringstream& iss, size_t maxSize) {
  std::string str;
  if (!std::getline(iss, str, '-') || str.size() != maxSize) {
    throw std::runtime_error("Error: Invalid date string format or size => " +
                             str);
  }
  return str;
}

int FileManage::validateDate(const std::string& str) {
  int year, month, daily;
  std::istringstream iss(str);
  std::string yearStr, monthStr, dailyStr;
  int monthlyDate[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  try {
    yearStr = splitDateStr(iss, 4);
    monthStr = splitDateStr(iss, 2);
    dailyStr = splitDateStr(iss, 2);
    year = std::stol(yearStr);
    month = std::stol(monthStr);
    daily = std::stol(dailyStr);
  } catch (const std::invalid_argument& e) {
    std::cerr << "Error: invalid argument in date conversion" << std::endl;
    return 0;
  } catch (const std::runtime_error& re) {
    std::cerr << re.what() << std::endl;
  }

  if (month < 1 || month > 12) {
    std::cerr << "Error: bad date month => " << str << std::endl;
    return 0;
  }

  if (year % 4 == 0 && year % 100 != 0 && year % 400 == 0) monthlyDate[1] = 29;

  if (daily < 1 || daily > monthlyDate[month - 1]) {
    std::cerr << "Error: bad date daily => " << str << std::endl;
    return 0;
  }
  return year * 10000 + month * 100 + daily;
}

float FileManage::validateNum(const std::string& str) {
  std::istringstream convert(str);
  float exchangeRate;

  if (!(convert >> exchangeRate && convert.eof()) ||
      (exchangeRate < 0.0 || exchangeRate > 1000.0))
    return -1.0;
  return exchangeRate;
}

std::map<int, float> FileManage::getLineInFile(char sep) {
  std::map<int, float> result;
  std::string line;

  while (std::getline(mFile, line)) {
    std::istringstream iss(line);
    std::string keyStr;
    std::string valStr;
    float value;
    int date;

    if (!std::getline(iss, keyStr, sep) || !std::getline(iss, valStr) ||
        !iss.eof()) {
      std::cerr << "Error: bad input => " << line << std::endl;
      continue;
    }
    date = validateDate(keyStr);
    value = validateNum(valStr);
    if (date != 0 && value != -1.0) result[date] = value;
  }
  return result;
}

FileManage::FileManage() {}

FileManage::FileManage(const FileManage& rhs) { (void)rhs; }

FileManage& FileManage::operator=(const FileManage& other) {
  (void)other;
  return *this;
}