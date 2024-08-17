#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {
 private:
  Ice(const Ice& other);
  Ice& operator=(const Ice& other);

 public:
  Ice(/* args */);
  ~Ice();

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};
