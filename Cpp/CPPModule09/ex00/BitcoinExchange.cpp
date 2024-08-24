#include "BitcoinExchange.hpp"

void BitcoinExchange::printValidateValue() {
  std::string line;
  std::pair<int, float> temp;

  std::getline(mFile, line);
  if (line != "date | value") {
    std::cout << "Error: Invalid format." << std::endl;
    return;
  }

  while (!mFile.eof()) {
    try {
      float currentRate, value;
      int currentDate;

      temp = getLineInFile('|');
      if (temp.first == 0 && temp.second == 0) continue;
      value = temp.second;
      currentDate = temp.first;
      currentRate = mDatabase.findValue(currentDate);
      printDate(currentDate);
      std::cout << value << " = " << value * currentRate << std::endl;
    } catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
}

void BitcoinExchange::printDate(int date) {
  int year, month, day;

  year = date / 10000;
  date %= 10000;
  month = date / 100;
  day = date % 100;

  std::cout << year << "-" << std::setw(2) << std::setfill('0') << month << "-"
            << std::setw(2) << std::setfill('0') << day << " => ";
}

float BitcoinExchange::validateNum(const std::string& str) {
  std::istringstream convert(str);
  float value;

  if (!(convert >> value && convert.eof()))
    throw std::runtime_error("Error: Invalid value.");
  if (value < 0.0)
    throw std::runtime_error("Error: not a positive number.");
  else if (value > 1000.0)
    throw std::runtime_error("Error: too large a number. ");

  return value;
}

BitcoinExchange::BitcoinExchange(const std::string& name)
    : FileManage(name), mDatabase() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& rhs) : FileManage(rhs) { (void)rhs; }

BitcoinExchange::BitcoinExchange() : FileManage("input.txt"), mDatabase() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  (void)other;
  return *this;
}