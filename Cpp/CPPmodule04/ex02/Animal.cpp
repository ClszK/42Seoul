#include "Animal.hpp"

Animal::Animal(/* args */) : type_("") {
  std::cout << "Animal Default Constructor called." << std::endl;
}

Animal::Animal(const std::string &type) : type_(type) {
  std::cout << "Animal Constructor called." << std::endl;
}

Animal::Animal(const Animal &other) : type_(other.type_) {
  std::cout << "Animal Copy Constructor called." << std::endl;
}

Animal::~Animal() { std::cout << "Animal Destructor called." << std::endl; }

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal Assignment Operator called." << std::endl;
  if (this != &other) type_ = other.type_;

  return *this;
}

const std::string &Animal::getType() const { return type_; }