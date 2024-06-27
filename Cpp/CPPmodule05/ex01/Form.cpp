#include "Form.hpp"

Form::Form()
    : mName("Default"),
      mBeSigned(false),
      mRequiredGrade(50),
      mExecutedGrade(50) {
  std::cout << mName << " Constructor call." << std::endl;
}

Form::Form(const std::string* name, int requiredGrade,
           int executedGrade)
    : mName("Default"),
      mBeSigned(false),
      mRequiredGrade(requiredGrade),
      mExecutedGrade(executedGrade) {
  if (name == NULL)
    throw std::invalid_argument("Name is NULL.");
  throw std::invalid_argument("Invalid name!");
}

Form::Form(const std::string& name, int requiredGrade,
           int executedGrade)
    : mName(name),
      mBeSigned(false),
      mRequiredGrade(requiredGrade),
      mExecutedGrade(executedGrade) {
  std::cout << mName << "'s Constructor call." << std::endl;

  validateGradeForm(mRequiredGrade, mExecutedGrade);
}

Form::Form(const Form& other)
    : mName(other.mName),
      mBeSigned(other.mBeSigned),
      mRequiredGrade(other.mRequiredGrade),
      mExecutedGrade(other.mExecutedGrade) {
  std::cout << mName << "'s Constructor call." << std::endl;

  validateGradeForm(mRequiredGrade, mExecutedGrade);
}

Form::~Form() {
  std::cout << mName << "'s Destructor call." << std::endl;
}

std::string Form::getName() const { return mName; }

bool Form::getBeSigned() const { return mBeSigned; }

int Form::getRequiredGrade() const {
  return mRequiredGrade;
}

int Form::getExecutedGrade() const {
  return mExecutedGrade;
}

void Form::beSigned(const Bureaucrat& brc) {
  if (brc.getGrade() <= mRequiredGrade)
    mBeSigned = true;
  else
    throw GradeTooLowException();
}

void Form::validateGradeForm(int requiredGrade,
                             int executedGrade) {
  if (requiredGrade < 1 || executedGrade < 1) {
    std::cerr << mName << "'s ";
    throw GradeTooHighException();
  }
  if (requiredGrade > 150 || executedGrade > 150) {
    std::cerr << mName << "'s ";
    throw GradeTooLowException();
  }
}

std::ostream& operator<<(std::ostream& os,
                         const Form& form) {
  os << form.getName() << ", form signed " << std::boolalpha
     << form.getBeSigned() << ", required grade "
     << form.getRequiredGrade() << ", executed grade "
     << form.getExecutedGrade();
  return os;
}

Form& Form::operator=(const Form& other) {
  std::cout << other.mName
            << "'s Copy Assignment Constructor call."
            << std::endl;
  return *this;
}