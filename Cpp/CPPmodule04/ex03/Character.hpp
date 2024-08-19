#pragma once

#include "ICharacter.hpp"

struct SNode {
  AMateria* material;
  SNode* next;
};

class Character : public ICharacter {
 private:
  std::string mName;
  AMateria* mInventory[4];
  SNode* s_node_;

  Character(const Character& other);
  Character& operator=(const Character& other);

 public:
  Character(/* args */);
  Character(const std::string& name);
  ~Character();

  virtual std::string const& getName() const;
  virtual void equip(AMateria* m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter& target);

  void pushBack(AMateria* m);
};
