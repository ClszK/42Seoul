#include "FileManager.hpp"

int main(int argc, char* argv[]) {
  if (argc != 4) {
    std::cerr << "Usage: ./a.out filename s1 s2" << std::endl;
    return 1;
  }

  std::string filename = argv[1];
  std::string before_str = argv[2];
  std::string after_str = argv[3];

  if (before_str.length() == 0) {
    std::cout << "Empty before str" << std::endl;
    return 0;
  }

  FileManager fm(filename, before_str, after_str);

  if (!fm.OpenAndCreateFile()) {
    std::cerr << "Fail Open File" << std::endl;
    return 1;
  }

  std::string rline;

  while (fm.ioState() == std::ios_base::goodbit) {
    fm.GetlineInFile(rline);
    fm.WriteLineInFile(rline);
  }

  if (fm.ioState() & std::ios_base::eofbit)
    return 0;
  else {
    std::cerr << "Error I/O System." << std::endl;
    return 1;
  }
}