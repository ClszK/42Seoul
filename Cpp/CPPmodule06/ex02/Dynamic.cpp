#include "Dynamic.hpp"

Base* Dynamic::generate(void) {
  std::srand(std::time(0));
  int random = std::rand() % 3;

  if (random == 0)
    return new A();
  else if (random == 1)
    return new B();
  else
    return new C();
}

void Dynamic::identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "A" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "B" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;
  else
    std::cout << "Unknown" << std::endl;
}

void Dynamic::identify(Base& p) {
  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "A" << std::endl;
  } catch (const std::exception& e) {
    try {
      (void)dynamic_cast<B&>(p);
      std::cout << "B" << std::endl;
    } catch (const std::exception& e) {
      try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
      } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
      }
    }
  }
}

Dynamic::Dynamic() {}

Dynamic::Dynamic(const Dynamic& other) { (void)other; }

Dynamic& Dynamic::operator=(const Dynamic& other) {
  (void)other;
  return *this;
}

Dynamic::~Dynamic() {}