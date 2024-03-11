#include "Harl.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage : " << argv[0] << "[ DEBUG / INFO / WARNING / ERROR ]"
              << std::endl;
    return 1;
  }
  Harl print_complain;

  print_complain.complain(argv[1]);

  return 0;
}