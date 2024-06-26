#include "Form.hpp"

Form::Form()
    : mName("default"),
      mBeSigned(false),
      mRequiredGrade(50),
      mExecutedGrade(50) {
  std::cout << mName << " Constructor call." << std::endl;
}

Form::Form(const std::string* name, bool beSigned, int requiredGrade,
           int executedGrade) {
  (void)name;
  (void)beSigned;
  (void)requiredGrade;
  (void)executedGrade;
  throw std::invalid_argument("Invalid name!");
}

Form::Form(const std::string& name, bool beSigned, int requiredGrade,
           int executedGrade)
    : mName(name), mBeSigned(beSigned) {
  std::cout << mName << "'s Constructor call." << std::endl;

  validateGradeForm(requiredGrade, executedGrade);
  mRequiredGrade = requiredGrade;
  mExecutedGrade = executedGrade;
}

Form::Form(const Form& other) : mName(other.getName()), mBeSigned(false) {
  std::cout << mName << "'s Constructor call." << std::endl;

  int requiredGrade = other.getRequiredGrade();
  int executedGrade = other.getExecutedGrade();

  validateGradeForm(requiredGrade, executedGrade);
  mRequiredGrade = requiredGrade;
  mExecutedGrade = executedGrade;
}

Form& Form::operator=(const Form& other) {
  std::cout << other.getName() << "'s Assign Constructor call." << std::endl;

  if (this == &other) return *this;

  Form temp(other);

  const_cast<std::string&>(mName) = temp.getName();
  mBeSigned = false;
  mRequiredGrade = temp.getRequiredGrade();
  mExecutedGrade = temp.getExecutedGrade();
  return *this;
}

Form::~Form() { std::cout << mName << "'s Destructor call." << std::endl; }

std::string Form::getName() const { return mName; }

bool Form::getBeSgined() const { return mBeSigned; }

int Form::getRequiredGrade() const { return mRequiredGrade; }

int Form::getExecutedGrade() const { return mExecutedGrade; }

void Form::validateGradeForm(int requiredGrade, int executedGrade) {
  if (requiredGrade < 1 || executedGrade < 1) {
    std::cerr << mName << "'s ";
    throw GradeTooHighException();
  }
  if (requiredGrade > 150 || executedGrade > 150) {
    std::cerr << mName << "'s ";
    throw GradeTooLowException();
  }
}

std::ostream& operator<<(std::ostream& os, const Form& form) {}
