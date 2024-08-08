#pragma once

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

class FileManage {
 private:
  std::ifstream mFile;

  FileManage();
  FileManage(const FileManage& rhs);
  FileManage& operator=(const FileManage& other);

 public:
  FileManage(const std::string& fileName);
  virtual ~FileManage();

  int validateDate(const std::string& str);
  virtual float validateNum(const std::string& str);
  std::string splitDateStr(std::istringstream& iss, size_t maxSize);

  std::map<int, float> getLineInFile(char sep);
};