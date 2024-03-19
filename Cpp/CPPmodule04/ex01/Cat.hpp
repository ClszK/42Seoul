#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
 private:
  Brain *brain_;

 public:
  Cat(/* args */);
  Cat(const Cat &other);
  virtual ~Cat();

  Cat &operator=(const Cat &other);

  virtual void makeSound() const;
};