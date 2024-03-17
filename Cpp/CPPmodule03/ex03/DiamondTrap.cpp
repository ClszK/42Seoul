#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap(), ScavTrap(), FragTrap(), name_("DEFAULT") {
  std::cout << "DiamondTrap Default Constructor called" << std::endl;
  ClapTrap::name_ = name_ + "_clap_name";
  energy_ = 50;
  std::cout << "Health : " << health_ << std::endl;
  std::cout << "Energy : " << energy_ << std::endl;
  std::cout << "damage : " << damage_ << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name),
      FragTrap(name),
      name_(name) {
  std::cout << "DiamondTrap Constructor called." << std::endl;
  energy_ = 50;
  std::cout << "Health : " << health_ << std::endl;
  std::cout << "Energy : " << energy_ << std::endl;
  std::cout << "damage : " << damage_ << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name_(other.name_) {
  std::cout << "DiamondTrap Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap " << name_ << " call destructor" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "DiamondTrap assignment operator called" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
    name_ = other.name_;
  }

  return *this;
}

void DiamondTrap::attack(const std::string &target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  if (health_ == 0)
    std::cout << "DiamondTrap " << name_ << "is die." << std::endl;
  else if (energy_ == 0)
    std::cout << "DiamondTrap " << name_ << "don't have energy" << std::endl;
  else {
    std::cout << "DiamondTrap Name's " << name_ << std::endl;
    std::cout << "ClapTrap Name's    " << ClapTrap::name_ << std::endl;
  }
}