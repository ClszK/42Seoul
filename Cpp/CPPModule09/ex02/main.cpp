#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
  PmergeMe pmerge(argc - 1);
  clock_t vecTime, deqTime;

  if (argc == 1 || !pmerge.createNotSortedVec(argc, argv)) {
    std::cerr << "Invalid input" << std::endl;
    return 1;
  }

  deqTime = pmerge.sortDeque();
  vecTime = pmerge.sortVec();

  const std::vector<int> notSorted(pmerge.getNotSortedVec()),
      sorted(pmerge.getVector());

  std::cout << "Before:\t";
  for (size_t i = 0; i < notSorted.size(); ++i) {
    std::cout << notSorted[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "After:\t";
  for (size_t i = 0; i < sorted.size(); ++i) {
    std::cout << sorted[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Time to process a range of\t" << pmerge.getVector().size()
            << " elements with  std::vector : \t"
            << (vecTime * 1000000.0) / CLOCKS_PER_SEC << " us" << std::endl;
  std::cout << "Time to process a range of\t" << pmerge.getVector().size()
            << " elements with  std::deque : \t"
            << (deqTime * 1000000.0) / CLOCKS_PER_SEC << " us" << std::endl;

  //   std::vector<int> testVec = pmerge.getNotSortedVec();
  //   std::deque<int> testDeq;

  //   for (size_t i = 0; i < testVec.size(); ++i) {
  //     testDeq.push_back(testVec[i]);
  //   }
  //   std::sort(testVec.begin(), testVec.end());
  //   std::sort(testDeq.begin(), testDeq.end());

  //   if (testVec == pmerge.getVector() && testDeq == pmerge.getDeque()) {
  //     std::cout << "sorted" << std::endl;
  //   } else {
  //     std::cout << "not sorted" << std::endl;
  //   }

  return 0;
}
