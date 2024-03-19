#include "Ice.hpp"

Ice::Ice(/* args */) : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice::~Ice() {}

Ice& Ice::operator=(const Ice& other) {
  if (this != &other) AMateria::operator=(other);

  return *this;
}

AMateria* Ice::clone() const { return new Ice(); }

void Ice::use(ICharacter& target) {
  std::cout << "* shoots an ice bolt at " << target.getName() << " *"
            << std::endl;
}