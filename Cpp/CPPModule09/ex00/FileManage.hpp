#pragma once

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

  std::map<std::string, float> getLineInFile(char sep);
  bool validateFirst();
  bool validateSecond();
};