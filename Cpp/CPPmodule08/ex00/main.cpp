#include <deque>
#include <list>
#include <vector>

#include "easyfind.hpp"

int main() {
  std::vector<int> vec;
  std::list<int> lst;
  std::deque<int> deq;

  for (int i = 1; i <= 5; ++i) {
    vec.push_back(i);
    lst.push_back(i);
    deq.push_back(i);
  }

  // Vector test
  {
    std::vector<int>::iterator it = easyfind(vec, 3);

    if (it != vec.end())
      std::cout << "Found in vector: " << *it << std::endl;
    else
      std::cout << "Not found in vector" << std::endl;

    it = easyfind(vec, 6);

    if (it != vec.end())
      std::cout << "Found in vector: " << *it << std::endl;
    else
      std::cout << "Not found in vector" << std::endl;
  }

  // List test
  {
    std::list<int>::iterator it = easyfind(lst, 4);

    if (it != lst.end())
      std::cout << "Found in list: " << *it << std::endl;
    else
      std::cout << "Not found in list" << std::endl;

    it = easyfind(lst, 7);

    if (it != lst.end())
      std::cout << "Found in list: " << *it << std::endl;
    else
      std::cout << "Not found in list" << std::endl;
  }

  // Deque test
  {
    std::deque<int>::iterator it = easyfind(deq, 5);

    if (it != deq.end())
      std::cout << "Found in deque: " << *it << std::endl;
    else
      std::cout << "Not found in deque" << std::endl;

    it = easyfind(deq, 8);

    if (it != deq.end())
      std::cout << "Found in deque: " << *it << std::endl;
    else
      std::cout << "Not found in deque" << std::endl;
  }

  return 0;
}
