#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
  for (int i = 0; i < 4; i++) mBackup[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
  for (int i = 0; i < 4; i++) {
    if (other.mBackup[i]) {
      AMateria* tmp = other.mBackup[i]->clone();
      mBackup[i] = tmp;
    } else
      mBackup[i] = NULL;
  }
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++)
    if (mBackup[i]) delete mBackup[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
  if (this != &other) {
    for (int i = 0; i < 4; i++) {
      AMateria* tmp = NULL;

      if (mBackup[i]) delete mBackup[i];

      if (other.mBackup[i]) tmp = other.mBackup[i]->clone();

      mBackup[i] = tmp;
    }
  }
  return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
  if (m == NULL) return;
  for (int i = 0; i < 4; i++) {
    if (mBackup[i] == NULL) {
      mBackup[i] = m->clone();
      break;
    }
  }
}

AMateria* MateriaSource::createMateria(std::string const& type) {
  for (int i = 0; i < 4; i++) {
    if (mBackup[i] && mBackup[i]->getType() == type) {
      return mBackup[i]->clone();
    }
  }
  return NULL;
}