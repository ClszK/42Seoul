#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie*	zombieArr = new(std::nothrow) Zombie[N];
	if (!zombieArr)
		return NULL;
	
	for (int i = 0; i < N; i++)
	{
		std::stringstream ss;
		ss << i + 1;
		zombieArr[i].setName(name + ss.str());
	}
	return zombieArr;
}