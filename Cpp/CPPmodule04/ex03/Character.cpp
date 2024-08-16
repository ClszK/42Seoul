#include "Character.hpp"

Character::Character() : s_node_(NULL) {
  for (int i = 0; i < 4; i++) mInventory[i] = NULL;
}

Character::Character(const std::string& name) : mName(name), s_node_(NULL) {
  for (int i = 0; i < 4; i++) mInventory[i] = NULL;
}

Character::Character(const Character& other)
    : mName(other.mName), s_node_(other.s_node_) {
  for (int i = 0; i < 4; i++) {
    if (other.mInventory[i]) {
      AMateria* tmp = other.mInventory[i]->clone();
      mInventory[i] = tmp;
    } else
      mInventory[i] = NULL;
  }
}

Character::~Character() {
  for (int i = 0; i < 4; i++)
    if (mInventory[i]) delete mInventory[i];

  SNode* current = s_node_;
  while (current != NULL) {
    SNode* next = current->next;
    delete next->material;
    delete current;
    current = next;
  }
}

Character& Character::operator=(const Character& other) {
  if (this != &other) {
    mName = other.mName;

    for (int i = 0; i < 4; i++) {
      AMateria* tmp = NULL;

      if (mInventory[i]) delete mInventory[i];

      if (other.mInventory[i]) tmp = other.mInventory[i]->clone();

      mInventory[i] = tmp;
    }
    SNode* current = s_node_;

    while (current != NULL) {
      SNode* next = current->next;
      delete next->material;
      delete current;
      current = next;
    }

    s_node_ = other.s_node_;
  }
  return *this;
}

std::string const& Character::getName() const { return mName; }

void Character::equip(AMateria* m) {
  if (!m) return;

  for (int i = 0; i < 4; i++) {
    if (mInventory[i] == NULL) {
      mInventory[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx < 0 || idx > 3) return;
  if (!mInventory[idx]) return;
  pushBack(mInventory[idx]);
  mInventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
  if (idx < 0 || idx > 3) return;
  if (!mInventory[idx]) return;
  mInventory[idx]->use(target);
}

void Character::pushBack(AMateria* m) {
  if (s_node_ == NULL) {
    s_node_ = new SNode;
    s_node_->material = m;
    s_node_->next = NULL;
  } else {
    SNode* tmp = s_node_;
    while (tmp->next != NULL) tmp = tmp->next;
    tmp->next = new SNode;
    tmp->next->material = m;
    tmp->next->next = NULL;
  }
}