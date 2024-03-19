#include "Brain.hpp"

Brain::Brain(/* args */) {
  std::cout << "Brain Default Constructor called." << std::endl;
}

Brain::Brain(const std::string name) {
  std::cout << "Brain Constructor called." << std::endl;
  ideas_[0] = name;
}

Brain::Brain(const Brain &other) {
  std::cout << "Brain Copy Constructor called." << std::endl;
  *this = other;
}

Brain::~Brain() { std::cout << "Brain Destructor called." << std::endl; }

Brain &Brain::operator=(const Brain &other) {
  std::cout << "Brain Assignment Operator called." << std::endl;

  if (this != &other)
    for (int i = 0; i < 100; i++) ideas_[i] = other.ideas_[i];

  return *this;
}

const std::string *Brain::getIdea() const { return ideas_; }

void Brain::setIdea(const std::string type, size_t index) {
  ideas_[index] = type;
}