#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { *this = other; }

Intern& Intern::operator=(const Intern& other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string& formName,
                        const std::string& formTarget) {
  std::string formNames[] = {"shrubbery creation", "robotomy request",
                             "presidential pardon"};
  AForm* forms[3] = {NULL, NULL, NULL};

  try {
    forms[0] = new ShrubberyCreationForm(formTarget);
    forms[1] = new RobotomyRequestForm(formTarget);
    forms[2] = new PresidentialPardonForm(formTarget);
  } catch (const std::bad_alloc& e) {
    for (int i = 0; i < 3; ++i) delete forms[i];

    std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    return NULL;
  }

  AForm* result = NULL;

  for (int i = 0; i < 3; ++i) {
    if (formName == formNames[i]) {
      std::cout << "Intern creates " << formName << std::endl;
      result = forms[i];
    } else
      delete forms[i];
  }

  if (!result) {
    std::cout << "Error: Form name " << formName << " does not exist."
              << std::endl;
  }

  return result;
}