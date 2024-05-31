#include "Zombie.hpp"

Zombie::Zombie(void) { }

Zombie::~Zombie(void) { std::cout << mName << "'s Dead!" << std::endl; }

void Zombie::announce(void) const { std::cout << mName << ": BraiiiiiiinnnzzzZ..." << std::endl; }

void Zombie::setName(std::string name) { mName = name; }