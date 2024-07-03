#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(
    const std::string& target)
    : AForm("ShrubberyCreation", 72, 45), mTarget(target) {}

RobotomyRequestForm::RobotomyRequestForm(
    const RobotomyRequestForm& other)
    : AForm(other), mTarget(other.mTarget) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeFormAction() const {
  std::srand(std::time(0));

  if (std::rand() % 2)
    std::cout << mTarget << " has been robotomized successfully!"
              << std::endl;
  else
    std::cout << "the robotomy failed." << std::endl;
}

/* private method area */
RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& other) {
  (void)other;
  return *this;
}
