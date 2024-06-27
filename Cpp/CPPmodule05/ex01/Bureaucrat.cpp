#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : mName("default"), mGrade(50) {
  std::cout << mName << " Constructor call." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string* name, int grade)
    : mName("default"), mGrade(grade) {
  if (name == NULL) throw std::invalid_argument("Name is NULL.");
  throw std::invalid_argument("Name Invalid!");
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : mName(name), mGrade(grade) {
  std::cout << mName << "'s Constructor call." << std::endl;

  validateGrade(mGrade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : mName(other.mName), mGrade(other.mGrade) {
  std::cout << mName << "'s Copy Constructor call." << std::endl;

  validateGrade(mGrade);
}

Bureaucrat::~Bureaucrat() {
  std::cout << mName << "'s Destructor call." << std::endl;
}

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& brc) {
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

void Bureaucrat::signForm(Form& form) const {
  try {
    form.beSigned(*this);
    std::cout << mName << " signed " << form.getName() << std::endl;
  } catch (const std::exception& e) {
    std::cout << mName << " couldn't sign " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  std::cout << other.mName << "'s Copy Assignment Constructor call."
            << std::endl;
  return *this;
}