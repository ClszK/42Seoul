#pragma once

#include <iostream>
#include <string>

#include "MyException.hpp"

class Bureaucrat {
 public:
  class GradeTooHighException : public ::GradeTooHighException {};
  class GradeTooLowException : public ::GradeTooLowException {};

  Bureaucrat();
  Bureaucrat(const std::string* name, int grade);
  Bureaucrat(const std::string& name, int grade);
  Bureaucrat(const Bureaucrat& other);
  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
  void validateGrade(int grade);

 private:
  const std::string mName;
  int mGrade;

  Bureaucrat& operator=(const Bureaucrat& other);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& brc);