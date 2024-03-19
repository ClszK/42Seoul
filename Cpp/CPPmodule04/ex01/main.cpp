#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
  const Animal* j = new Dog();
  std::cout << std::endl;

  const Animal* i = new Cat();
  std::cout << std::endl;

  delete j;  // should not create a leak
  std::cout << std::endl;

  delete i;
  std::cout << std::endl;
  {
    const Animal* arr[10];
    const Dog dog;
    std::cout << std::endl;

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
  {
    Dog a;
    std::cout << std::endl;

    Dog b = a;
    std::cout << std::endl;
  }
  {
    std::cout << std::endl;
    std::cout << std::endl;

    Cat aa;
    std::cout << std::endl;

    Cat bb;
    std::cout << std::endl;

    aa = bb;
    std::cout << std::endl;
    std::cout << std::endl;
  }

  return 0;
}
