#include "FileManage.hpp"

FileManage::FileManage(const std::string& fileName) : mFile(fileName) {
  if (!mFile.is_open()) {
    std::cerr << "Can't open " << fileName << '\n';
  }
}

FileManage::~FileManage() {
  if (mFile.is_open()) {
    mFile.close();
  }
}

const std::string& FileManage::validateDate(const std::string& str) {}
float FileManage::validateNum(const std::string& str) {}

std::map<std::string, float> FileManage::getLineInFile(char sep) {
  std::map<std::string, float> result;
  std::string line;

  while (std::getline(mFile, line)) {
    std::istringstream iss(line);
    std::string keyStr;
    std::string valStr;
    float value;

    if (!std::getline(iss, keyStr, sep) || !std::getline(iss, valStr)) {
      std::cerr << "Error: bad input => " << line << std::endl;
      result.clear();
      return result;
    }

    std::istringstream convert(valStr);
  }
}