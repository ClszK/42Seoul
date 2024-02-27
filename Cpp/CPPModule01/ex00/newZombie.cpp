#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
	Zombie	*newZombieObj = new(std::nothrow) Zombie(name);
	return newZombieObj;
}