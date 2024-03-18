#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
 public:
  // Constructors
  Animal();
  Animal(const Animal &copy);
  Animal(std::string type_);

  // Destructor
  virtual ~Animal();

  // Operators
  Animal &operator=(const Animal &assign);

  virtual void makeSound();

  // Getters / Setters
 protected:
  std::string type_;
};

#endif