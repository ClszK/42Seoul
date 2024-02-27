#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB
{
private:
	std::string	mName;
	Weapon*		mWeaponType;

public:
	HumanB(void);
	HumanB(std::string name);
	~HumanB(void);

	void	setWeapon(Weapon& weaponType);
	void	attack(void) const;
};
#endif