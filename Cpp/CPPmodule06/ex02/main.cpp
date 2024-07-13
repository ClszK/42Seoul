#include "Dynamic.hpp"

int main() {
  Base* base = Dynamic::generate();

  std::cout << "Pointer : " << std::endl;
  Dynamic::identify(base);
  std::cout << "Reference : " << std::endl;
  Dynamic::identify(*base);

  delete base;
  return 0;
}