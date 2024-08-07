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

  const std::string& validateDate(const std::string& str);
  float validateNum(const std::string& str);

  std::map<std::string, float> getLineInFile(char sep);
};