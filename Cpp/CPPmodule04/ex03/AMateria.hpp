#pragma once

#include <iostream>

class AMateria {
 protected:
 public:
  AMateria();
  AMateria(std::string const& type);
  AMateria(const std::string& other);

  std::string const& getType() const;  // Returns the materia type

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};
