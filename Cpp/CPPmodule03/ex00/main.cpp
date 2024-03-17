#include "ClapTrap.hpp"

int main() {
  ClapTrap a("hi");
  std::cout << std::endl;

  ClapTrap b;
  std::cout << std::endl;

  a.attack(b.getName());
  std::cout << std::endl;

  b.takeDamage(a.getDamage());
  std::cout << std::endl;

  for (int i = 0; i < 10; i++) b.beReparied(10);
  std::cout << std::endl;

  b.beReparied(10);
  std::cout << std::endl;

  b.takeDamage(10000);
  std::cout << std::endl;

  b.takeDamage(10);
  std::cout << std::endl;

  std::cout << "Name : " << a.getName() << std::endl;
  std::cout << "Health: " << a.getHealth() << std::endl;
  std::cout << "Energy: " << a.getEnergy() << std::endl;
  std::cout << "Damage: " << a.getDamage() << std::endl;
  std::cout << std::endl;
  return 0;
}