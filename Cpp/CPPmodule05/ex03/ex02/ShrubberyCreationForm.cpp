#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(
    const std::string& target)
    : AForm("ShrubberyCreation", 145, 137), mTarget(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm& other)
    : AForm(other), mTarget(other.mTarget) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeFormAction() const {
  std::ofstream ofs;
  std::string fileName = mTarget + "_shrubbery";

  ofs.open(fileName.c_str());
  if (!ofs.is_open())
    throw std::ios_base::failure("Failed File Create.");

  ofs << "       _-_\n";
  ofs << "    /~~   ~~\\\n";
  ofs << " /~~         ~~\\\n";
  ofs << "{               }\n";
  ofs << " \\  _-     -_  /\n";
  ofs << "   ~  \\ //  ~\n";
  ofs << "_- -   | | _- _\n";
  ofs << "  _ -  | |   -_\n";
  ofs << "      // \\\n";

  ofs.close();
}

/* private method area */
ShrubberyCreationForm::ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other) {
  (void)other;
  return *this;
}
