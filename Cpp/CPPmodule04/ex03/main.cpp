#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main() {
  IMateriaSource* src = new MateriaSource();

  src->learnMateria(new Ice());
  src->learnMateria(new Cure());

  ICharacter* me = new Character("me");
  AMateria* tmp;

  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);

  ICharacter* bob = new Character("bob");

  me->use(0, *bob);
  me->use(1, *bob);
  std::cout << "Testing additional scenarios..." << std::endl;

  IMateriaSource* newSrc = new MateriaSource();
  newSrc->learnMateria(new Ice());
  newSrc->learnMateria(new Cure());

  ICharacter* alice = new Character("alice");
  AMateria* newTmp;

  newTmp = newSrc->createMateria("ice");
  alice->equip(newTmp);
  newTmp = newSrc->createMateria("cure");
  alice->equip(newTmp);

  // Materia 사용 테스트
  alice->use(0, *bob);
  alice->use(1, *bob);

  // 메모리 해제
  delete alice;
  delete newSrc;

  delete bob;
  delete me;
  delete src;

  return 0;
}