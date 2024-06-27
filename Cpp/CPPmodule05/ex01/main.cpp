#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
  try {
    Form invalidFormHigh("InvalidFormHigh", 0, 50);
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  std::cout << "---------------------" << std::endl;

  try {
    Form invalidFormLow("InvalidFormLow", 151, 50);
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << "---------------------" << std::endl;
  try {
    Bureaucrat highGradeBureaucrat("HighGradeBureaucrat",
                                   0);
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  std::cout << "---------------------" << std::endl;
  try {
    Bureaucrat lowGradeBureaucrat("LowGradeBureaucrat",
                                  151);
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  try {
    Bureaucrat bob("Bob", 20);
    Bureaucrat alice("Alice", 1);

    Form taxForm("Tax Form", 30, 50);
    Form contract("Contract", 1, 10);

    std::cout << bob << std::endl;
    std::cout << alice << std::endl;
    std::cout << taxForm << std::endl;
    std::cout << contract << std::endl;

    std::cout << "---------------------" << std::endl;
    bob.signForm(taxForm);
    alice.signForm(contract);

    std::cout << taxForm << std::endl;
    std::cout << contract << std::endl;

    bob.signForm(contract);

    std::cout << "---------------------" << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
