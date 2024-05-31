#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter {
 private:
  std::string name_;
  AMateria* inventory_[4];

 public:
  Character(/* args */);
  Character(const std::string& name);
  Character(const Character& other);
  ~Character();
  Character& operator=(const Character& other);

  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);
};
