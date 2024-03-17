#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default", 100, 50, 20), is_guard_gate_(false) {
  std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name)
    : ClapTrap(name, 100, 50, 20), is_guard_gate_(false) {
  std::cout << "ScavTrap Constructor called with " << name << "." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other)
    : ClapTrap(other), is_guard_gate_(false) {
  std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  if (this != &other) {
    ClapTrap::operator=(other);
    is_guard_gate_ = other.is_guard_gate_;
  }

  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << name_ << " call destructor" << std::endl;
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
    std::cout << "ScavTrap " << name_ << "don't have energy." << std::endl;
  else {
    is_guard_gate_ = !is_guard_gate_;
    std::cout << "ScavTrap " << name_ << " change Guard Gate Mode "
              << (is_guard_gate_ ? "On" : "OFF") << std::endl;
    --energy_;
  }
}