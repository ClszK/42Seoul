#include "DiamondTrap.hpp"

int main() {
  ClapTrap clap("CLAP");
  std::cout << std::endl;

  DiamondTrap dia("DIA");
  std::cout << std::endl;

  dia.whoAmI();
  std::cout << std::endl;

  dia.attack("CLAP");
  clap.attack("CLAP");
  std::cout << std::endl;

  dia.takeDamage(dia.getDamage());
  clap.takeDamage(dia.getDamage());
  std::cout << std::endl;

  dia.beReparied(10);
  clap.beReparied(10);
  std::cout << std::endl;

  DiamondTrap a;
  std::cout << std::endl;

  DiamondTrap b(a);
  std::cout << std::endl;

  a = dia;
  std::cout << "Name : " << a.getName() << std::endl;
  std::cout << "Health: " << a.getHealth() << std::endl;
  std::cout << "Energy: " << a.getEnergy() << std::endl;
  std::cout << "Damage: " << a.getDamage() << std::endl;
  std::cout << std::endl;
  return 0;
}