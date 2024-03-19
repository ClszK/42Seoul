#pragma once

#include <iostream>
#include <string>

class Brain {
 private:
  std::string ideas_[100];

 public:
  Brain(/* args */);
  Brain(const Brain &other);
  ~Brain();

  Brain &operator=(const Brain &other);
};