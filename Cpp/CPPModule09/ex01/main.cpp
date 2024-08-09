#include "Rpn.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Error: Invalid arguments" << std::endl;
    return 1;
  }

  Rpn r;

  try {
    r.rpn(argv[1]);
  } catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}