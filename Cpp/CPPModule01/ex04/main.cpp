#include <iostream>

#include "FileManager.hpp"
#include "ReplaceString.hpp"

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Usage: ./a.out filename s1 s2" << std::endl;
    return 1;
  }

  FileManager fm(argv[1]);
  ReplaceString rs(argv[2], argv[3]);

  if (!fm.OpenAndCreateFile()) {
    std::cerr << "Fail Open File" << std::endl;
    return 1;
  }

  std::string rline;

  while (fm.GetlineInFile(rline)) {
    rs.Replace(rline);
    std::cout << rline << std::endl;
    fm.WriteLineInFile(rline);
  }

  return 0;
}