#pragma once

#include <fstream>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm(const std::string& target);
  PresidentialPardonForm(const PresidentialPardonForm& other);
  ~PresidentialPardonForm();

  virtual void executeFormAction() const;

 private:
  std::string mTarget;

  /* Not use method */
  PresidentialPardonForm();
  PresidentialPardonForm& operator=(
      const PresidentialPardonForm& other);
};
