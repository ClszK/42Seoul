#pragma once

#include <algorithm>

#include "FileManage.hpp"

class Database : public FileManage {
 private:
  std::map<int, float> mDatabase;

  Database(const Database& rhs);
  Database& operator=(const Database& other);

 public:
  Database();
  ~Database();

  void createDatabase();
  float findValue(int date);

  virtual float validateNum(const std::string& str);
};
