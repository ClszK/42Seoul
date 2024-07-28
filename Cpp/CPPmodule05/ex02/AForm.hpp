#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "MyException.hpp"

class Bureaucrat;

class AForm {
 public:
  class GradeTooHighException : public ::GradeTooHighException {
  };
  class GradeTooLowException : public ::GradeTooLowException {};

  AForm();
  AForm(const std::string* name, int requiredGrade,
        int executedGrade);
  AForm(const std::string& name, int requiredGrade,
        int executedGrade);
  AForm(const AForm& other);
  virtual ~AForm();

  std::string getName() const;
  bool getBeSigned() const;
  int getRequiredGrade() const;
  int getExecutedGrade() const;
  void beSigned(const Bureaucrat& brc);

  void validateGradeAForm(int requiredGrade, int executedGrade);
  void execute(Bureaucrat const& executor) const;

 private:
  const std::string mName;
  bool mBeSigned;
  const int mRequiredGrade;
  const int mExecutedGrade;

  AForm& operator=(const AForm& other);

 protected:
  virtual void executeFormAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);
