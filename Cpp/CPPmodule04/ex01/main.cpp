#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal* j = new Dog();
  std::cout << std::endl;

  const Animal* i = new Cat();
  std::cout << std::endl;

  delete j;  // should not create a leak
  std::cout << std::endl;

  delete i;
  std::cout << std::endl;

  const Animal* arr[10];

  for (int k = 0; k < 10; k += 2) {
    arr[k] = new Dog();
    arr[k + 1] = new Cat();
  }

  for (int k = 0; k < 10; k++) {
    delete arr[k];
    std::cout << std::endl;
  }

  return 0;
}
