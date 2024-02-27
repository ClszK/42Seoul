#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
private:
	std::string mType;

public:
	Weapon(std::string type);
	~Weapon(void);
	
	std::string	getType(void) const;
	void		setType(std::string type);	
};

#endif