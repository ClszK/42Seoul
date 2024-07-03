#include <iostream>

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  Intern intern;

  // 테스트 케이스 1: 유효한 폼 생성
  std::cout << "------------------------------------------" << std::endl;
  std::cout << "Test Case 1: Valid Form Creation" << std::endl;
  AForm* form1 = intern.makeForm("shrubbery creation", "Garden");
  if (form1) {
    std::cout << "Form created: " << form1->getName() << std::endl;
    delete form1;  // 생성된 폼 삭제
  }

  // 테스트 케이스 2: 유효한 폼 생성
  std::cout << "------------------------------------------" << std::endl;
  std::cout << "Test Case 2: Valid Form Creation" << std::endl;
  AForm* form2 = intern.makeForm("robotomy request", "RoboTarget");
  if (form2) {
    std::cout << "Form created: " << form2->getName() << std::endl;
    delete form2;  // 생성된 폼 삭제
  }

  // 테스트 케이스 3: 유효한 폼 생성
  std::cout << "------------------------------------------" << std::endl;
  std::cout << "Test Case 3: Valid Form Creation" << std::endl;
  AForm* form3 = intern.makeForm("presidential pardon", "Marvin");
  if (form3) {
    std::cout << "Form created: " << form3->getName() << std::endl;
    delete form3;  // 생성된 폼 삭제
  }

  // 테스트 케이스 4: 잘못된 폼 이름
  std::cout << "------------------------------------------" << std::endl;
  std::cout << "Test Case 4: Invalid Form Name" << std::endl;
  AForm* form4 = intern.makeForm("invalid form name", "Target");
  if (!form4) {
    std::cout << "No form created for invalid form name." << std::endl;
  }
  std::cout << "------------------------------------------" << std::endl;

  return 0;
}