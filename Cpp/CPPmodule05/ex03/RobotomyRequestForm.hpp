#pragma once

#include <cstdlib>
#include <ctime>
#include <fstream>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
  RobotomyRequestForm(const std::string& target);
  RobotomyRequestForm(const RobotomyRequestForm& other);
  ~RobotomyRequestForm();

  virtual void executeFormAction() const;

 private:
  std::string mTarget;

  /* Not use method */
  RobotomyRequestForm();
  RobotomyRequestForm& operator=(
      const RobotomyRequestForm& other);
};
