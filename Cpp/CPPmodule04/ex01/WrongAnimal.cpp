#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(/* args */) : type_("") {
  std::cout << "WrongAnimal Default Constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : type_(type) {
  std::cout << "WrongAnimal Constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type_(other.type_) {
  std::cout << "WrongAnimal Copy Constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal Destructor called." << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "WrongAnimal Assignment Operator called." << std::endl;
  if (this != &other) type_ = other.type_;

  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << "Don't have Animal Type" << std::endl;
}

const std::string &WrongAnimal::getType() const { return type_; }