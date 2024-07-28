#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(
    const std::string& target)
    : AForm("PresidentialPardon", 25, 5), mTarget(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& other)
    : AForm(other), mTarget(other.mTarget) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeFormAction() const {
  std::cout << mTarget
            << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}

/* private method area */
PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& other) {
  (void)other;
  return *this;
}
