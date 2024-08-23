#pragma once

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

class PmergeMe {
 public:
  PmergeMe(int size);
  ~PmergeMe();

  bool createNotSortedVec(int argc, char *argv[]);

  const std::vector<int> &getNotSortedVec() const;
  const std::vector<int> &getVector() const;
  const std::deque<int> &getDeque() const;

  clock_t sortVec();
  clock_t sortDeque();

 private:
  std::vector<int> mNotSortedVec;
  std::vector<int> mVector;
  std::deque<int> mDeque;

  void createContainer();

  void mergeVec(std::vector<std::list<int> > &mainChain);
  void mergeDeq(std::deque<std::list<int> > &mainChain);

  void insertVec(std::vector<std::list<int> > &mainChain, std::list<int> &odd);
  void insertDeq(std::deque<std::list<int> > &mainChain, std::list<int> &odd);

  static bool compare(const std::list<int> &a, const std::list<int> &b);
  static void testPrint(const std::vector<std::list<int> > &mainChain);

  PmergeMe(const PmergeMe &other);
  PmergeMe();
  PmergeMe operator=(const PmergeMe &other);
};
