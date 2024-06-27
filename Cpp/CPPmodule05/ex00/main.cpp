#include "Bureaucrat.hpp"

int main() {
  Bureaucrat a("test", 1);
  Bureaucrat b(a);
  Bureaucrat c;

  std::cout << "---------------------" << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << c << std::endl;

  std::cout << "---------------------" << std::endl;
  try {
    a.incrementGrade();
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl << std::endl;
  }
  std::cout << "---------------------" << std::endl;
  a.decrementGrade();
  a.decrementGrade();
  a.decrementGrade();
  std::cout << a << std::endl << std::endl;

  a.incrementGrade();
  a.incrementGrade();
  std::cout << a << std::endl << std::endl;

  std::cout << "---------------------" << std::endl;
  Bureaucrat d("test1", 150);

  try {
    d.decrementGrade();
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl << std::endl;
  }

  try {
    Bureaucrat e("Test2", 0);
    std::cout << e << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl << std::endl;
  }

  try {
    Bureaucrat e("Test2", 151);
    std::cout << e << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl << std::endl;
  }

  try {
    Bureaucrat nullValid(NULL, 10);
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl << std::endl;
  }
  std::cout << "---------------------" << std::endl;
  return 0;
}