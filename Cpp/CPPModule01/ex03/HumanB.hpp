#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>

#include "Weapon.hpp"

class HumanB {
 private:
  std::string mName;
  Weapon* mWeaponType;

 public:
  HumanB(std::string name);
  ~HumanB(void);

  void setWeapon(Weapon& weaponType);
  void attack(void) const;
};
#endif