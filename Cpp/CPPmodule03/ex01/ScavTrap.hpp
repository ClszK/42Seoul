#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
 private:
  bool is_guard_gate_;

 public:
  ScavTrap();
  ScavTrap(const std::string &name);
  ScavTrap(const ScavTrap &other);
  ScavTrap &operator=(const ScavTrap &other);
  virtual ~ScavTrap();

  virtual void attack(const std::string &target);
  void guardGate();
};
