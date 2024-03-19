#include "WrongCat.hpp"

WrongCat::WrongCat(/* args */) : WrongAnimal("WrongCat") {
  std::cout << "WrongCat Default Constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "WrongCat Copy Constructor called." << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat Destructor called." << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "WrongCat Assignment Operator called." << std::endl;
  if (this != &other) WrongAnimal::operator=(other);

  return *this;
}

void WrongCat::makeSound() const { std::cout << "Meow Meow!!" << std::endl; }
