#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const& type) : mType(type) {}

AMateria::AMateria(const AMateria& other) : mType(other.mType) {}

AMateria::~AMateria() {}

AMateria& AMateria::operator=(const AMateria& other) {
  if (this != &other) mType = other.mType;

  return *this;
}

std::string const& AMateria::getType() const { return mType; }

void AMateria::use(ICharacter& target) {
  (void)target;
  std::cout << "AMateria::use(ICharacter& target) called" << std::endl;
}