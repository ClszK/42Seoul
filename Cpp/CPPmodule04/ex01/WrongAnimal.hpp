#pragma once

#include <iostream>
#include <string>

class WrongAnimal {
 protected:
  std::string type_;

 public:
  WrongAnimal(/* args */);
  WrongAnimal(const std::string &type);
  WrongAnimal(const WrongAnimal &other);
  ~WrongAnimal();

  WrongAnimal &operator=(const WrongAnimal &other);

  void makeSound() const;

  const std::string &getType() const;
};