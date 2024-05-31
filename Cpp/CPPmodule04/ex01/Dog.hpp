#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
 private:
  Brain *brain_;

 public:
  Dog(/* args */);
  Dog(const Dog &other);
  virtual ~Dog();

  Dog &operator=(const Dog &other);

  virtual void makeSound() const;
};