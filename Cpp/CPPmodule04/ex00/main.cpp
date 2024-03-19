#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  std::cout << std::endl;

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  j->makeSound();  // meta->makeSound(); ...
  i->makeSound();  // will output the cat sound!
  meta->makeSound();
  std::cout << std::endl;

  const WrongAnimal* wrong_meta = new WrongAnimal();
  const WrongAnimal* wrong_i = new WrongCat();

  std::cout << wrong_meta->getType() << " " << std::endl;
  std::cout << wrong_i->getType() << " " << std::endl;
  wrong_meta->makeSound();
  wrong_i->makeSound();
  std::cout << std::endl;

  delete meta;
  delete j;
  delete i;
  std::cout << std::endl;
  delete wrong_meta;
  delete wrong_i;
  return 0;
}
