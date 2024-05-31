#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
 public:
  Ice(/* args */);
  Ice(const Ice& other);
  ~Ice();
  Ice& operator=(const Ice& other);

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};
