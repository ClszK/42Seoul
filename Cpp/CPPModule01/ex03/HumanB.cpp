#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
  mName = name;
  mWeaponType = NULL;
}

HumanB::~HumanB(void) {}

void HumanB::setWeapon(Weapon& weaponType) { mWeaponType = &weaponType; }

void HumanB::attack(void) const {
  if (mWeaponType == NULL)
    std::cout << mName << " can't attack.(Don't have Weapon)" << std::endl;
  else
    std::cout << mName << " attacks with their " << mWeaponType->getType()
              << std::endl;
}