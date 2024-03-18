#include "Animal.hpp"

// Constructors
Animal::Animal() {
  type_ = "";
  std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(const Animal &copy) {
  type_ = copy.type_;
  std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
}

Animal::Animal(std::string type_) {
  type_ = type_;
  std::cout << "\e[0;33mFields Constructor called of Animal\e[0m" << std::endl;
}

// Destructor
Animal::~Animal() {
  std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}

// Operators
Animal &Animal::operator=(const Animal &assign) {
  type_ = assign.type_;
  return *this;
}

// Getters / Setters
