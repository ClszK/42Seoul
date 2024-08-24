#pragma once

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

class FileManage {
 protected:
  std::ifstream mFile;

 private:
  FileManage(const FileManage& rhs);
  FileManage& operator=(const FileManage& other);

 public:
  FileManage();
  FileManage(const std::string& fileName);
  virtual ~FileManage();

  int validateDate(const std::string& str);
  virtual float validateNum(const std::string& str) = 0;
  std::string splitDateStr(std::istringstream& iss, size_t maxSize, char seq);

  std::pair<int, float> getLineInFile(char sep);
};