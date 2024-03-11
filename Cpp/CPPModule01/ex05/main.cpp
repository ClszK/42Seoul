#include "Harl.hpp"

int main() {
  Harl test;

  test.complain("ERROR");
  test.complain("DEBUG");
  test.complain("INFO");
  test.complain("WARNING");

  return 0;
}