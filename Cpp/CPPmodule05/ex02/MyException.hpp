#pragma once

#include <stdexcept>

class GradeTooHighException : public std::exception {
 public:
  const char* what() const throw();
};

class GradeTooLowException : public std::exception {
 public:
  const char* what() const throw();
};

class NotSigned : public std::exception {
 public:
  const char* what() const throw();
};