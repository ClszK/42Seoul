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

  void pushBack(AMateria* m);
};
