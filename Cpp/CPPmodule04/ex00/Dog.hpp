#pragma once

#include "Animal.hpp"

class Dog : public Animal {
 public:
  Dog(/* args */);
  Dog(const Dog &other);
  virtual ~Dog();

  Dog &operator=(const Dog &other);

  virtual void makeSound() const;
};