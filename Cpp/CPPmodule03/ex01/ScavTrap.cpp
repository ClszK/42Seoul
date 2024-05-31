#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default") {
  std::cout << "ScavTrap Default Constructor called" << std::endl;
  health_ = 100;
  energy_ = 50;
  damage_ = 20;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  std::cout << "ScavTrap Constructor called." << std::endl;
  health_ = 100;
  energy_ = 50;
  damage_ = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "ScavTrap Copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << name_ << " call destructor" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "ScavTrap assignment operator called" << std::endl;
  if (this != &other) ClapTrap::operator=(other);

  return *this;
}

void ScavTrap::attack(const std::string &target) {
  if (energy_ > 0 && health_ > 0) {
    std::cout << "ScavTrap " << name_ << " attacks " << target << ", causing "
              << damage_ << " points of damage!" << std::endl;
    --energy_;
  } else
    std::cout << "ScavTrap " << name_ << " don't have energy or health."
              << std::endl;
}

void ScavTrap::guardGate() {
  if (health_ == 0)
    std::cout << "ScavTrap " << name_ << "is die." << std::endl;
  else if (energy_ == 0)
    std::cout << "ScavTrap " << name_ << "don't have energy" << std::endl;
  else
    std::cout << "ScavTrap " << name_ << " is now in Gate keeper mode."
              << std::endl;
}