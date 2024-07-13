#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

class Dynamic {
 private:
  Dynamic(/* args */);
  Dynamic(const Dynamic& other);
  Dynamic& operator=(const Dynamic& other);
  ~Dynamic();

 public:
  static Base* generate(void);
  static void identify(Base* p);
  static void identify(Base& p);
};
