#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
 private:
  AMateria* backup_[4];

 public:
  MateriaSource();
  MateriaSource(const MateriaSource& other);
  ~MateriaSource();
  MateriaSource& operator=(const MateriaSource& other);

  virtual void learnMateria(AMateria*);
  virtual AMateria* createMateria(std::string const& type);
};