#pragma once

#include <iostream>
#include <string>

class Brain {
 private:
  std::string ideas_[100];

 public:
  Brain(/* args */);
  Brain(const std::string name);
  Brain(const Brain &other);
  ~Brain();

  Brain &operator=(const Brain &other);

  const std::string *getIdea() const;
  void setIdea(const std::string type, size_t index = 0);
};