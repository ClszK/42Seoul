#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string* name, int grade)
    : mName("default"), mGrade(grade) {
  if (name == NULL) throw std::invalid_argument("Name is NULL.");
  throw std::invalid_argument("Name Invalid!");
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : mName(name), mGrade(grade) {
  validateGrade(mGrade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : mName(other.mName), mGrade(other.mGrade) {
  validateGrade(mGrade);
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return mName; }

int Bureaucrat::getGrade() const { return mGrade; }

void Bureaucrat::incrementGrade() {
  if (mGrade <= 1) {
    std::cerr << mName << "'s ";
    throw GradeTooHighException();
  }
  mGrade--;
}

void Bureaucrat::decrementGrade() {
  if (mGrade >= 150) {
    std::cerr << mName << "'s ";
    throw GradeTooLowException();
  }
  mGrade++;
}

std::ostream& operator<<(std::ostream& os,
                         const Bureaucrat& brc) {
  os << brc.getName() << ", bureaucrat grade " << brc.getGrade();
  return os;
}

void Bureaucrat::validateGrade(int grade) {
  if (grade < 1) {
    std::cerr << mName << "'s ";
    throw GradeTooHighException();
  }
  if (grade > 150) {
    std::cerr << mName << "'s ";
    throw GradeTooLowException();
  }
}

void Bureaucrat::signForm(AForm& form) const {
  try {
    form.beSigned(*this);
    std::cout << mName << " signed " << form.getName()
              << std::endl;
  } catch (const std::exception& e) {
    std::cout << mName << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(const AForm& form) {
  try {
    form.execute(*this);
    std::cout << mName << " executed " << form.getName()
              << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }
}

/* private method */

Bureaucrat::Bureaucrat() : mName("default"), mGrade(50) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  std::cout << other.mName
            << "'s Copy Assignment Constructor call."
            << std::endl;
  return *this;
}