#include "Zombie.hpp"

Zombie::Zombie(std::string name) { mName = name; }

Zombie::~Zombie(void) { std::cout << mName << "'s Dead!" << std::endl; }

void Zombie::announce(void) const { std::cout << mName << ": BraiiiiiiinnnzzzZ..." << std::endl; }
