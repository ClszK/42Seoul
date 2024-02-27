#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <sstream>

class Zombie
{
private:
	std::string mName;

public:
	Zombie(void);
	~Zombie(void);

	void	setName(std::string name);
	void	announce(void) const;
};

Zombie* zombieHorde( int N, std::string name );

#endif