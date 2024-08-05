#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    // Bureaucrats
    Bureaucrat highRanker("Alice", 1);
    Bureaucrat lowRanker("Bob", 150);

    // Forms
    ShrubberyCreationForm shrubbery("home");
    RobotomyRequestForm robotomy("RoboTarget");
    PresidentialPardonForm pardon("Marvin");

    // Sign and execute forms
    std::cout << "-------------------------------------------"
              << std::endl;
    std::cout << "High ranker tries to sign and execute forms."
              << std::endl;
    std::cout << "-------------------------------------------"
              << std::endl;
    highRanker.signForm(shrubbery);
    highRanker.executeForm(shrubbery);
    std::cout << std::endl;

    highRanker.signForm(robotomy);
    highRanker.executeForm(robotomy);
    std::cout << std::endl;

    highRanker.signForm(pardon);
    highRanker.executeForm(pardon);
    std::cout << std::endl;

    std::cout << "-------------------------------------------"
              << std::endl;
    std::cout << "Low ranker tries to sign and execute forms."
              << std::endl;
    std::cout << "-------------------------------------------"
              << std::endl;
    lowRanker.signForm(shrubbery);
    lowRanker.executeForm(shrubbery);
    std::cout << std::endl;

    lowRanker.signForm(robotomy);
    lowRanker.executeForm(robotomy);
    std::cout << std::endl;

    lowRanker.signForm(pardon);
    lowRanker.executeForm(pardon);
    std::cout << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
