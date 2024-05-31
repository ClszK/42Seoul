#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("DEFAULT") {
  std::cout << "FragTrap DEFAULT Constructor called" << std::endl;
  health_ = 100;
  energy_ = 100;
  damage_ = 30;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  std::cout << "FragTrap Constructor called." << std::endl;
  health_ = 100;
  energy_ = 100;
  damage_ = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "FragTrap Copy constructor called." << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FrapTrap " << name_ << " call destructor" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  std::cout << "FragTrap assignment operator called" << std::endl;
  if (this != &other) ClapTrap::operator=(other);

  return *this;
}

void FragTrap::highFivesGuys(void) {
  if (health_ == 0)
    std::cout << "FragTrap " << name_ << "is die." << std::endl;
  else if (energy_ == 0)
    std::cout << "FragTrap " << name_ << "don't have energy" << std::endl;
  else
    std::cout << "Positive high fives request!" << std::endl;
}