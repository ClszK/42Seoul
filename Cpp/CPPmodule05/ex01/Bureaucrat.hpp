#pragma once

#include <iostream>
#include <string>

#include "Form.hpp"
#include "MyException.hpp"

class Form;

class Bureaucrat {
 public:
  class GradeTooHighException : public ::GradeTooHighException {};
  class GradeTooLowException : public ::GradeTooLowException {};

  Bureaucrat(const std::string* name, int grade);
  Bureaucrat(const std::string& name, int grade);
  Bureaucrat(const Bureaucrat& other);
  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
  void validateGrade(int grade);

  void signForm(Form& form) const;

 private:
  const std::string mName;
  int mGrade;

  /* Not use */
  Bureaucrat();
  Bureaucrat& operator=(const Bureaucrat& other);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& brc);