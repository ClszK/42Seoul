#pragma once

#include <iostream>
#include <string>

class ClapTrap {
 protected:
  std::string name_;
  unsigned int health_;
  unsigned int energy_;
  unsigned int damage_;
  /* data */
 public:
  ClapTrap();
  ClapTrap(const std::string& name);
  ClapTrap(const ClapTrap& other);
  ClapTrap& operator=(const ClapTrap& other);
  ~ClapTrap();

  const std::string& getName(void) const;
  unsigned int getHealth(void) const;
  unsigned int getEnergy(void) const;
  unsigned int getDamage(void) const;

  void attack(const std::string& target);
  void takeDamage(unsigned int amount);
  void beReparied(unsigned int amount);
};
