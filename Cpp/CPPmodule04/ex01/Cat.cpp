#include "Cat.hpp"

Cat::Cat(/* args */) : Animal("Cat"), brain_(new Brain(type_)) {
  std::cout << "Cat Default Constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain_(new Brain(*other.brain_)) {
  std::cout << "Cat Copy Constructor called." << std::endl;

  std::cout << "This  Brain's PTR : " << brain_ << std::endl;
  std::cout << "Other Brain's PTR : " << other.brain_ << std::endl;
  std::cout << "This  Brain's Idea: " << (brain_->getIdea())[0] << std::endl;
  std::cout << "Other Brain's Idea: " << other.brain_->getIdea()[0]
            << std::endl;
}

Cat::~Cat() {
  std::cout << "Cat Destructor called." << std::endl;
  if (brain_) delete brain_;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat Assignment Operator called." << std::endl;
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

void Cat::makeSound() const { std::cout << "Meow Meow!!" << std::endl; }
