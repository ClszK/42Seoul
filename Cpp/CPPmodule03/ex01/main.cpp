#include "ScavTrap.hpp"

int main() {
  ClapTrap aa;
  std::cout << std::endl;

  ScavTrap a;
  std::cout << std::endl;

  ScavTrap b("AA");
  std::cout << std::endl;

  ScavTrap c(b);
  std::cout << std::endl;

  aa.attack("AA");
  b.attack("AA");
  std::cout << std::endl;

  aa.takeDamage(a.getDamage());
  b.takeDamage(a.getDamage());
  std::cout << std::endl;

  aa.beReparied(5);
  b.beReparied(5);
  std::cout << std::endl;

  a.guardGate();
  std::cout << std::endl;

  a = b;
  a.guardGate();
  std::cout << std::endl;

  std::cout << "Name : " << a.getName() << std::endl;
  std::cout << "Health: " << a.getHealth() << std::endl;
  std::cout << "Energy: " << a.getEnergy() << std::endl;
  std::cout << "Damage: " << a.getDamage() << std::endl;
  std::cout << std::endl;
  return 0;
}