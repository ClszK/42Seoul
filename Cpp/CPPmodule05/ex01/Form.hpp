#pragma once

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
#include "MyException.hpp"

class Bureaucrat;

class Form {
 public:
  class GradeTooHighException
      : public ::GradeTooHighException {};
  class GradeTooLowException
      : public ::GradeTooLowException {};

  Form();
  Form(const std::string* name, int requiredGrade,
       int executedGrade);
  Form(const std::string& name, int requiredGrade,
       int executedGrade);
  Form(const Form& other);
  ~Form();

  std::string getName() const;
  bool getBeSigned() const;
  int getRequiredGrade() const;
  int getExecutedGrade() const;
  void beSigned(const Bureaucrat& brc);

  void validateGradeForm(int requiredGrade,
                         int executedGrade);

 private:
  const std::string mName;
  bool mBeSigned;
  const int mRequiredGrade;
  const int mExecutedGrade;

  Form& operator=(const Form& other);
};

std::ostream& operator<<(std::ostream& os,
                         const Form& form);

/**
 *  해야 할 것. 복사 연산자를 어떻게 처리할 것인가.
 * 	1. private으로 이동.
 * 	2. const_cast로 변환.
 *
 * 	내일 1.번으로 진행해야겠다.
 * 	빠이!!
 * */