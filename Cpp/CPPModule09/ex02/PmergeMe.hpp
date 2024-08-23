#pragma once

#include <deque>
#include <iostream>

class PmergeMe {
 private:
  std::deque<int> deq;

  PmergeMe();
  PmergeMe(const PmergeMe& rhs);
  PmergeMe& operator=(const PmergeMe& other);

 public:
  PmergeMe(int argc, char* argv[]);
  ~PmergeMe();

  void mergePairDeque(size_t left, size_t right);
  void mergeMainChain(size_t left, size_t mid, size_t right);

  void printDeque() const;
};
