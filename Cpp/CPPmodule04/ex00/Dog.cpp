#include "Dog.hpp"

Dog::Dog(/* args */) : Animal("Dog") {
  std::cout << "Dog Default Constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog Copy Constructor called." << std::endl;
}

Dog::~Dog() { std::cout << "Dog Destructor called." << std::endl; }

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog Assignment Operator called." << std::endl;
  if (this != &other) Animal::operator=(other);

  return *this;
}

void Dog::makeSound() const { std::cout << "bowwow bowwow !!" << std::endl; }
