#pragma once

#include <fstream>
#include <iostream>
#include <map>

class FileManage {
 private:
  std::ifstream mFile;

 public:
  FileManage();
  FileManage(const std::string& fileName);
  FileManage(const FileManage& rhs);
  FileManage& operator=(const FileManage& other);
  virtual ~FileManage();

  template <typename T>
  std::map<std::string, T> getLineInFile(const std::string& sep);
  virtual bool validateFirst() = 0;
  virtual bool validateSecond() = 0;
};