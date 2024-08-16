#include <exception>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> a(1);
  try {
    a[0] = 1;
    a[1] = 2;
    a[2] = 2;
    for (int i = 0; i < 3; ++i) {
      std::cout << a[i];
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}