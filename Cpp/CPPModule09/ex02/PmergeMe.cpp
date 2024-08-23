#include "PmergeMe.hpp"

void PmergeMe::mergePairDeque(size_t left, size_t right) {
  if (right - left <= 1) {
    if (deq[left] < deq[right]) {
      std::iter_swap(deq.begin() + left, deq.begin() + right);
    }
    return;
  }

  size_t mid = (left + right - 1) / 2;
  mergePairDeque(left, mid);
  mergePairDeque(mid + 1, right);
  mergeMainChain(left, mid, right);
}

void PmergeMe::mergeMainChain(size_t left, size_t mid, size_t right) {
  if (deq[left] > deq[mid + 1]) {
    std::rotate(deq.begin() + left, deq.begin() + mid + 1,
                deq.begin() + right + 1);
  }
}

void PmergeMe::printDeque() const {
  for (size_t i = 0; i < deq.size(); ++i) {
    std::cout << deq[i] << " ";
  }
  std::cout << std::endl;
}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int argc, char* argv[]) : deq(argc - 1) {
  for (int i = 0; i < argc - 1; ++i) deq[i] = std::atol(argv[i + 1]);
}

PmergeMe::PmergeMe(const PmergeMe& rhs) { (void)rhs; }

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  (void)other;
  return *this;
}

PmergeMe::~PmergeMe() {}

// 이해가 안가는게 mainchain과 subchain이 있을 때 따로 공간을 둬야하나?

// 0 1 2 3 4 5 / 6 7 8 9
// 0 1 2 3 / 4 5 / 6 7 8 9

// 6 5 4 3 / 2 1
// 4 3 6 5 / 2 1