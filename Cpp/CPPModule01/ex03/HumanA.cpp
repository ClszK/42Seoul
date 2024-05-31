#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weaponType)
	: mName(name), mWeaponType(weaponType) { }

HumanA::~HumanA(void) { }

void HumanA::attack(void) const
{
	std::cout << mName << " attacks with their " << mWeaponType.getType() << std::endl;
}