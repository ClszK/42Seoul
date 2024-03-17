#include "FragTrap.hpp"

int main() {
  ClapTrap aa;
  std::cout << std::endl;

  FragTrap a("AA");
  std::cout << std::endl;

  FragTrap b;
  std::cout << std::endl;

  FragTrap c(a);
  std::cout << std::endl;

  b = a;
  std::cout << std::endl;

  aa.attack("TEST");
  a.attack("TEST");
  std::cout << std::endl;

  aa.takeDamage(a.getDamage());
  b.takeDamage(a.getDamage());
  std::cout << std::endl;

  aa.beReparied(10);
  b.beReparied(10);
  std::cout << std::endl;

  c.highFivesGuys();
  std::cout << std::endl;

  a = b;
  std::cout << std::endl;

  std::cout << "Name : " << a.getName() << std::endl;
  std::cout << "Health: " << a.getHealth() << std::endl;
  std::cout << "Energy: " << a.getEnergy() << std::endl;
  std::cout << "Damage: " << a.getDamage() << std::endl;
  std::cout << std::endl;
  return 0;
}