#include "ScavTrap.hpp"

int main() {
  ScavTrap a;
  std::cout << std::endl;

  ScavTrap b("hi");
  std::cout << std::endl;

  a.attack("hi");
  std::cout << std::endl;

  b.takeDamage(a.getDamage());
  std::cout << std::endl;

  b.beReparied(5);
  std::cout << std::endl;

  b.takeDamage(a.getDamage());
  std::cout << std::endl;

  a.guardGate();
  std::cout << std::endl;

  a.guardGate();
  std::cout << std::endl;

  return 0;
}