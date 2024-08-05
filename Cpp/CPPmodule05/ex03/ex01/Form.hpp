#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "MyException.hpp"

class Bureaucrat;

class Form {
 public:
  class GradeTooHighException : public ::GradeTooHighException {};
  class GradeTooLowException : public ::GradeTooLowException {};

  Form(const std::string* name, int requiredGrade, int executedGrade);
  Form(const std::string& name, int requiredGrade, int executedGrade);
  Form(const Form& other);
  ~Form();

  std::string getName() const;
  bool getBeSigned() const;
  int getRequiredGrade() const;
  int getExecutedGrade() const;
  void beSigned(const Bureaucrat& brc);

  void validateGradeForm(int requiredGrade, int executedGrade);

 private:
  const std::string mName;
  bool mBeSigned;
  const int mRequiredGrade;
  const int mExecutedGrade;

  /* Not use */
  Form();
  Form& operator=(const Form& other);
};

std::ostream& operator<<(std::ostream& os, const Form& form);
