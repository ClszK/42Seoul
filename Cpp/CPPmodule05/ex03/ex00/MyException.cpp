#include "MyException.hpp"

const char* GradeTooHighException::what() const throw() {
  return "Grade is too High!";
}

const char* GradeTooLowException::what() const throw() {
  return "Grade is too Low!";
}