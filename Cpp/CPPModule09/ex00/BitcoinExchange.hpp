#pragma once

#include <iomanip>

#include "Database.hpp"

class BitcoinExchange : public FileManage {
 private:
  Database mDatabase;

  BitcoinExchange();

 public:
  void printValidateValue();
  void printDate(int date);

  BitcoinExchange(const std::string& name);
  BitcoinExchange(const BitcoinExchange& rhs);
  BitcoinExchange& operator=(const BitcoinExchange& other);
  ~BitcoinExchange();

  virtual float validateNum(const std::string& str);
};