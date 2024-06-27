#include "AForm.hpp"

AForm::AForm()
    : mName("Default"),
      mBeSigned(false),
      mRequiredGrade(50),
      mExecutedGrade(50) {}

AForm::AForm(const std::string* name, int requiredGrade,
             int executedGrade)
    : mName("Default"),
      mBeSigned(false),
      mRequiredGrade(requiredGrade),
      mExecutedGrade(executedGrade) {
  if (name == NULL) throw std::invalid_argument("Name is NULL.");
  throw std::invalid_argument("Invalid name!");
}

AForm::AForm(const std::string& name, int requiredGrade,
             int executedGrade)
    : mName(name),
      mBeSigned(false),
      mRequiredGrade(requiredGrade),
      mExecutedGrade(executedGrade) {
  validateGradeAForm(mRequiredGrade, mExecutedGrade);
}

AForm::AForm(const AForm& other)
    : mName(other.mName),
      mBeSigned(other.mBeSigned),
      mRequiredGrade(other.mRequiredGrade),
      mExecutedGrade(other.mExecutedGrade) {
  validateGradeAForm(mRequiredGrade, mExecutedGrade);
}

AForm::~AForm() {}

std::string AForm::getName() const { return mName; }

bool AForm::getBeSigned() const { return mBeSigned; }

int AForm::getRequiredGrade() const { return mRequiredGrade; }

int AForm::getExecutedGrade() const { return mExecutedGrade; }

void AForm::beSigned(const Bureaucrat& brc) {
  if (brc.getGrade() <= mRequiredGrade)
    mBeSigned = true;
  else
    throw GradeTooLowException();
}

void AForm::validateGradeAForm(int requiredGrade,
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

void AForm::execute(Bureaucrat const& executor) const {
  if (!mBeSigned) throw NotSigned();
  if (executor.getGrade() > mExecutedGrade)
    throw GradeTooLowException();

  executeFormAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
  os << form.getName() << ", form signed " << std::boolalpha
     << form.getBeSigned() << ", required grade "
     << form.getRequiredGrade() << ", executed grade "
     << form.getExecutedGrade();
  return os;
}

AForm& AForm::operator=(const AForm& other) {
  std::cout << other.mName
            << "'s Copy Assignment Constructor call."
            << std::endl;
  return *this;
}