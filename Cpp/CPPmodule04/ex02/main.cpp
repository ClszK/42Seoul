#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const Animal* j = new Dog();
  std::cout << std::endl;

  const Animal* i = new Cat();
  std::cout << std::endl;

  delete j;
  std::cout << std::endl;

  delete i;
  std::cout << std::endl;
  {
    const Animal* arr[10];
    const Dog dog;
    const Cat cat;
    std::cout << std::endl;

    for (int k = 0; k < 6; k += 2) {
      arr[k] = new Dog(dog);
      std::cout << std::endl;
      arr[k + 1] = new Cat(cat);
      std::cout << std::endl;
    }

    for (int k = 0; k < 6; k++) {
      delete arr[k];
      std::cout << std::endl;
    }
  }

  std::cout << std::endl;
  std::cout << std::endl;

  Dog a;
  Dog b;
  std::cout << std::endl;
  std::cout << std::endl;

  a = b;

  Cat aa;
  Cat bb;
  aa = bb;
  std::cout << std::endl;
  std::cout << std::endl;

  Animal a;

  return 0;
}
