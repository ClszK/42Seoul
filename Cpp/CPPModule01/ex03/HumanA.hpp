#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanA {
 private:
  std::string mName;
  Weapon &mWeaponType;

 public:
  HumanA(std::string name, Weapon &weaponType);
  ~HumanA(void);

  void attack(void) const;
};

#endif