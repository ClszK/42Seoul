#include "Zombie.hpp"

int main()
{
	Zombie *zombieArr = zombieHorde(15, "Zombie");

	if (!zombieArr)
	{
		std::cerr << "Memory alloc fail" << std::endl;
		return 1;
	}
	for (int i = 0; i < 15; i++)
		zombieArr[i].announce();

	delete[] zombieArr;
	return 0;
}