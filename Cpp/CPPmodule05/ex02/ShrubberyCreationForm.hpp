#pragma once

#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
  ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ~ShrubberyCreationForm();

  virtual void executeFormAction() const;

 private:
  std::string mTarget;

  /* Not use method */
  ShrubberyCreationForm();
  ShrubberyCreationForm& operator=(
      const ShrubberyCreationForm& other);
};
