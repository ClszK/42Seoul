#include "Database.hpp"

Database::~Database() {}

Database::Database() : FileManage() { createDatabase(); }

void Database::createDatabase() {
  std::string line;
  std::pair<int, float> temp;

  std::getline(mFile, line);
  if (line != "date,exchange_rate") {
    std::cout << "Error: Invalid format." << std::endl;
    return;
  }

  while (!mFile.eof()) {
    try {
      temp = getLineInFile(',');
      if (temp.first == 0 && temp.second) continue;
      mDatabase.insert(getLineInFile(','));
    } catch (const std::exception& e) {
      std::cout << e.what() << std::endl;
    }
  }
}

float Database::validateNum(const std::string& str) {
  std::istringstream convert(str);
  float exchangeRate;

  if (!(convert >> exchangeRate && convert.eof()) || (exchangeRate < 0))
    throw std::runtime_error("Error: Rate negative.");
  return exchangeRate;
}

float Database::findValue(int date) {
  std::map<int, float>::iterator pos = mDatabase.lower_bound(date);

  if (pos == mDatabase.end() || pos->first != date) {
    if (pos == mDatabase.begin())
      throw std::runtime_error("Error: Not Found Date.");
    --pos;
  }
  return pos->second;
}

/* private */

Database::Database(const Database& rhs) { (void)rhs; }

Database& Database::operator=(const Database& other) {
  (void)other;
  return *this;
}