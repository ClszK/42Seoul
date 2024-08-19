#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria {
 private:
  Cure(const Cure& other);
  Cure& operator=(const Cure& other);

 public:
  Cure(/* args */);
  ~Cure();

  virtual AMateria* clone() const;
  virtual void use(ICharacter& target);
};
