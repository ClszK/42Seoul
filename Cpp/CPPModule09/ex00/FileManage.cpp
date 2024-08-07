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

std::map<std::string, float> FileManage::getLineInFile(char sep) {
  std::map<std::string, float> result;
  std::string line;

  while (std::getline(mFile, line, sep)) {
    std::istringstream iss(line);
    std::string keyStr;
    std::string valStr;
    float value;
  }
}
bool FileManage::validateFirst() {}
bool FileManage::validateSecond() {}