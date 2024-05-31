#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
 public:
  Cure(/* args */);
  Cure(const Cure& other);
  ~Cure();
  Cure& operator=(const Cure& other);

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};
