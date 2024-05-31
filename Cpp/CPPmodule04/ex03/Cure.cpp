#include "Cure.hpp"

Cure::Cure(/* args */) : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& other) {
  if (this != &other) AMateria::operator=(other);

  return *this;
}

AMateria* Cure::clone() const { return new Cure(); }

void Cure::use(ICharacter& target) {
  std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}