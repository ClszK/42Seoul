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

  /* 추가적인 테스트 */

  IMateriaSource* newSrc = new MateriaSource();

  newSrc->learnMateria(new Ice());
  newSrc->learnMateria(new Cure());
  newSrc->learnMateria(new Cure());
  newSrc->learnMateria(new Cure());
  newSrc->learnMateria(new Cure());
  newSrc->learnMateria(new Cure());

  ICharacter* alice = new Character("alice");
  AMateria* newTmp;

  newTmp = newSrc->createMateria("ice");
  alice->equip(newTmp);
  newTmp = newSrc->createMateria("cure");
  alice->equip(newTmp);
  alice->equip(newSrc->createMateria("ice"));
  alice->equip(newSrc->createMateria("ice"));
  alice->equip(newSrc->createMateria("ice"));
  alice->equip(newSrc->createMateria("ice"));

  alice->unequip(0);
  alice->unequip(0);
  alice->unequip(0);
  alice->unequip(0);
  alice->unequip(0);
  alice->unequip(1);
  alice->unequip(2);
  alice->unequip(3);
  alice->unequip(0);
  alice->equip(newSrc->createMateria("ice"));
  alice->unequip(0);
  alice->equip(newSrc->createMateria("ice"));
  alice->unequip(0);
  alice->equip(newSrc->createMateria("ice"));
  alice->unequip(0);
  alice->equip(newSrc->createMateria("ice"));

  // Materia 사용 테스트
  alice->use(0, *bob);
  alice->use(1, *bob);
  alice->use(-10, *bob);
  alice->use(3, *bob);
  alice->use(4, *bob);

  // 메모리 해제
  delete alice;
  delete newSrc;

  delete bob;
  delete me;
  delete src;

  return 0;
}