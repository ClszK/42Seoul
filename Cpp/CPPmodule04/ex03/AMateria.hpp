#pragma once

#include <iostream>

class ICharacter;

class AMateria {
 protected:
  std::string type_;

 public:
  AMateria();
  AMateria(std::string const& type);
  AMateria(const AMateria& other);
  virtual ~AMateria();

  AMateria& operator=(const AMateria& other);

  std::string const& getType() const;  // Returns the materia type

  virtual AMateria* clone() const = 0;
  virtual void use(ICharacter& target);
};
