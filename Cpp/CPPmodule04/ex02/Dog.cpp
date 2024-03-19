#include "Dog.hpp"

Dog::Dog(/* args */) : Animal("Dog"), brain_(new Brain(type_)) {
  std::cout << "Dog Default Constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other), brain_(new Brain(*other.brain_)) {
  std::cout << "Dog Copy Constructor called." << std::endl;

  std::cout << "This  Brain's PTR : " << brain_ << std::endl;
  std::cout << "Other Brain's PTR : " << other.brain_ << std::endl;
  std::cout << "This  Brain's Idea: " << (brain_->getIdea())[0] << std::endl;
  std::cout << "Other Brain's Idea: " << other.brain_->getIdea()[0]
            << std::endl;
}

Dog::~Dog() {
  std::cout << "Dog Destructor called." << std::endl;
  if (brain_) delete brain_;
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog Assignment Operator called." << std::endl;
  if (this != &other) {
    Animal::operator=(other);

    Brain *newBrain = new Brain(*other.brain_);
    if (brain_) delete brain_;
    brain_ = newBrain;

    std::cout << "This  Brain's PTR : " << brain_ << std::endl;
    std::cout << "Other Brain's PTR : " << other.brain_ << std::endl;
    std::cout << "This  Brain's Idea: " << (brain_->getIdea())[0] << std::endl;
    std::cout << "Other Brain's Idea: " << other.brain_->getIdea()[0]
              << std::endl;
  }

  return *this;
}

void Dog::makeSound() const { std::cout << "bowwow bowwow !!" << std::endl; }
