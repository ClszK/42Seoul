#pragma once

#include <iostream>
#include <string>

#define DEBUG 0
#define INFO 1
#define WARNING 2
#define ERROR 3

class Harl {
 private:
  typedef void (Harl::*MemberFunc)(void);

  MemberFunc func_arr_ptr_[4];
  std::string func_arr_[4];
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  /* data */
 public:
  Harl();
  ~Harl();
  void complain(std::string level);
};
