#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : mName("default"), mGrade(50) {
  std::cout << mName << " Constructor call." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string* name, int grade) {
  (void)name;
  (void)grade;
  throw std::invalid_argument("Invalid name!");
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : mName(name) {
  std::cout << mName << "'s Constructor call." << std::endl;

  validateGrade(grade);
  mGrade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : mName(other.getName()) {
  std::cout << mName << "'s Copy Constructor call." << std::endl;

  int grade = other.getGrade();

  validateGrade(grade);
  mGrade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  std::cout << other.getName() << "'s Assign Constructor call." << std::endl;

  if (this == &other) return *this;

  Bureaucrat temp(other);

  const_cast<std::string&>(mName) = temp.getName();
  mGrade = temp.getGrade();
  return *this;
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