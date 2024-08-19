#pragma once

#include <iostream>
#include <string>

class Animal {
 protected:
  std::string type_;

  /* data */
 public:
  Animal(/* args */);
  Animal(const std::string &type);
  Animal(const Animal &other);
  virtual ~Animal();

  Animal &operator=(const Animal &other);

  virtual void makeSound() const;
  const std::string &getType() const;
};
