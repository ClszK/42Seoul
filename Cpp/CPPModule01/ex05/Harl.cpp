#include "Harl.hpp"

Harl::Harl() {
  func_arr_[0] = "DEBUG";
  func_arr_[1] = "INFO";
  func_arr_[2] = "WARNING";
  func_arr_[3] = "ERROR";

  func_arr_ptr_[0] = &Harl::debug;
  func_arr_ptr_[1] = &Harl::info;
  func_arr_ptr_[2] = &Harl::warning;
  func_arr_ptr_[3] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug(void) {
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!"
      << std::endl;
}

void Harl::info(void) {
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning(void) {
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years whereas you started working here since last month."
      << std::endl;
}

void Harl::error(void) {
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Harl::complain(std::string level) {
  for (int i = 0; i < 4; i++) {
    if (func_arr_[i] == level) {
      (this->*func_arr_ptr_[i])();
      return;
    }
  }
}
