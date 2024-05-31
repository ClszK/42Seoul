#include "Character.hpp"

Character::Character() {
  for (int i = 0; i < 4; i++) inventory_[i] = NULL;
}

Character::Character(const std::string& name) : name_(name) {
  for (int i = 0; i < 4; i++) inventory_[i] = NULL;
}

Character::Character(const Character& other) : name_(other.name_) {
  for (int i = 0; i < 4; i++) {
    if (other.inventory_[i]) {
      AMateria* tmp = other.inventory_[i]->clone();
      inventory_[i] = tmp;
    } else
      inventory_[i] = NULL;
  }
}

Character::~Character() {
  for (int i = 0; i < 4; i++)
    if (inventory_[i]) delete inventory_[i];
}

Character& Character::operator=(const Character& other) {
  if (this != &other) {
    name_ = other.name_;

    for (int i = 0; i < 4; i++) {
      AMateria* tmp = NULL;

      if (inventory_[i]) delete inventory_[i];

      if (other.inventory_[i]) tmp = other.inventory_[i]->clone();

      inventory_[i] = tmp;
    }
  }
  return *this;
}

std::string const& Character::getName() const { return name_; }

void Character::equip(AMateria* m) {
  if (!m) return;

  for (int i = 0; i < 4; i++) {
    if (inventory_[i] == NULL) {
      inventory_[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 3) return;
  if (!inventory_[idx]) return;
  inventory_[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx > 3) return;
  if (!inventory_[idx]) return;
  inventory_[idx]->use(target);
}