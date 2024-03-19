#include "Cat.hpp"

Cat::Cat(/* args */) : Animal("Cat") {
  std::cout << "Cat Default Constructor called." << std::endl;
  brain_ = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat Copy Constructor called." << std::endl;
  brain_ = other.brain_;
}

Cat::~Cat() {
  std::cout << "Cat Destructor called." << std::endl;
  delete brain_;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat Assignment Operator called." << std::endl;
  if (this != &other) {
    Animal::operator=(other);
    brain_ = other.brain_;
  }

  return *this;
}

void Cat::makeSound() const { std::cout << "Meow Meow!!" << std::endl; }
