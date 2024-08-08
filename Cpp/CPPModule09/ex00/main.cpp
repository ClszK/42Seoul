#include <iostream>

#include "FileManage.hpp"

int main() {
  FileManage test("data.csv");
  std::map<int, float> returnTest = test.getLineInFile(',');

  for (auto& elem : returnTest) {
    std::cout << elem.first << " " << elem.second << std::endl;
  }
  return 0;
}