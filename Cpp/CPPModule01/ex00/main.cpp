#include "Zombie.hpp"

int main()
{
	Zombie	*zombieObj;
	Zombie	mainZombie("main_stack");

	mainZombie.announce();
	randomChump("stack");
	zombieObj = newZombie("heap");
	if (!zombieObj)
	{
		std::cerr << "Memory alloc fail!" << std::endl;
		return 1;
	}
	zombieObj->announce();
	delete zombieObj;

	return 0;
}