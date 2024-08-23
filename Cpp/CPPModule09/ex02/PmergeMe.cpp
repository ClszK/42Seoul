#include "PmergeMe.hpp"

bool PmergeMe::compare(const std::list<int> &a, const std::list<int> &b) {
  return a.front() < b.front();
}

void PmergeMe::testPrint(const std::vector<std::list<int> > &mainChain) {
  for (size_t i = 0; i < mainChain.size(); ++i) {
    for (std::list<int>::const_iterator it = mainChain[i].begin();
         it != mainChain[i].end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }
}

PmergeMe::PmergeMe(int size)
    : mNotSortedVec(size), mVector(size), mDeque(size) {}

bool PmergeMe::createNotSortedVec(int argc, char *argv[]) {
  int num;

  for (int i = 1; i < argc; ++i) {
    std::istringstream iss(argv[i]);

    if (!(iss >> num) || !iss.eof() || num <= 0) return false;
    mNotSortedVec[i - 1] = num;
  }
  createContainer();
  return true;
}

const std::vector<int> &PmergeMe::getNotSortedVec() const {
  return mNotSortedVec;
}

void PmergeMe::createContainer() {
  for (size_t i = 0; i < mNotSortedVec.size(); ++i) {
    mVector[i] = mNotSortedVec[i];
    mDeque[i] = mNotSortedVec[i];
  }
}

clock_t PmergeMe::sortVec() {
  std::vector<std::list<int> > mainChain(mVector.size());

  clock_t start = clock();
  for (size_t i = 0; i < mVector.size(); ++i) {
    std::list<int> node;

    node.push_back(mVector[i]);
    mainChain[i] = node;
  }

  mergeVec(mainChain);
  for (size_t i = 0; i < mVector.size(); ++i) {
    mVector[i] = mainChain[i].front();
  }
  clock_t end = clock();

  return end - start;
}

clock_t PmergeMe::sortDeque() {
  std::deque<std::list<int> > mainChain(mDeque.size());

  clock_t start = clock();
  for (size_t i = 0; i < mDeque.size(); ++i) {
    std::list<int> node;

    node.push_back(mDeque[i]);
    mainChain[i] = node;
  }

  mergeDeq(mainChain);
  for (size_t i = 0; i < mDeque.size(); ++i) {
    mDeque[i] = mainChain[i].front();
  }

  clock_t end = clock();
  return end - start;
}

void PmergeMe::mergeVec(std::vector<std::list<int> > &mainChain) {
  if (mainChain.size() < 2) return;

  int mainChainSize = mainChain.size();

  std::list<int> node;

  if (mainChainSize != 1 && mainChainSize % 2) {
    node.splice(node.end(), mainChain.back());
    mainChain.pop_back();
  }

  for (int i = 0; i < mainChainSize / 2; ++i) {
    int minPos = i, maxPos = i + 1;

    if (mainChain[maxPos].front() < mainChain[minPos].front())
      minPos = i + 1, maxPos = i;
    mainChain[maxPos].splice(mainChain[maxPos].end(), mainChain[minPos]);
    mainChain.erase(mainChain.begin() + minPos);
  }

  mergeVec(mainChain);

  insertVec(mainChain, node);
}

void PmergeMe::mergeDeq(std::deque<std::list<int> > &mainChain) {
  if (mainChain.size() < 2) return;

  int mainChainSize = mainChain.size();

  std::list<int> node;

  if (mainChainSize != 1 && mainChainSize % 2) {
    node.splice(node.end(), mainChain.back());
    mainChain.pop_back();
  }

  for (int i = 0; i < mainChainSize / 2; ++i) {
    int minPos = i, maxPos = i + 1;

    if (mainChain[maxPos].front() < mainChain[minPos].front())
      minPos = i + 1, maxPos = i;
    mainChain[maxPos].splice(mainChain[maxPos].end(), mainChain[minPos]);
    mainChain.erase(mainChain.begin() + minPos);
  }

  mergeDeq(mainChain);

  insertDeq(mainChain, node);
}

void PmergeMe::insertVec(std::vector<std::list<int> > &mainChain,
                         std::list<int> &odd) {
  size_t mainChainMaxSize = mainChain.size() * 2,
         listSize = mainChain[0].size();
  std::list<int>::iterator nodeIt = mainChain[0].begin();
  std::list<int> node;

  std::advance(nodeIt, listSize / 2);
  node.splice(node.end(), mainChain[0], nodeIt, mainChain[0].end());
  mainChain.insert(mainChain.begin(), node);
  if (mainChain.size() == mainChainMaxSize && odd.empty()) return;

  int jacob = 1, prevJacob = 1, tmp, insertCnt;
  size_t idx = 2;
  std::vector<std::list<int> >::iterator pos;
  while (mainChainMaxSize != mainChain.size()) {
    tmp = jacob;
    jacob = jacob + 2 * prevJacob;
    prevJacob = tmp;

    insertCnt = jacob - prevJacob;
    idx <<= 1;
    if (idx > mainChain.size()) {
      idx = mainChain.size();
      insertCnt = mainChainMaxSize - mainChain.size();
    }

    for (int i = idx - 1; insertCnt > 0;) {
      if (mainChain[i].size() == listSize) {
        nodeIt = mainChain[i].begin();

        std::advance(nodeIt, listSize / 2);
        node.clear();
        node.splice(node.end(), mainChain[i], nodeIt, mainChain[i].end());
        pos = std::lower_bound(mainChain.begin(), mainChain.begin() + i, node,
                               compare);
        mainChain.insert(pos, node);
        --insertCnt;
        continue;
      }
      --i;
    }
  }

  if (!odd.empty()) {
    pos = std::lower_bound(mainChain.begin(), mainChain.end(), odd, compare);
    mainChain.insert(pos, odd);
  }
}

void PmergeMe::insertDeq(std::deque<std::list<int> > &mainChain,
                         std::list<int> &odd) {
  size_t mainChainMaxSize = mainChain.size() * 2,
         listSize = mainChain[0].size();
  std::list<int>::iterator nodeIt = mainChain[0].begin();
  std::list<int> node;

  std::advance(nodeIt, listSize / 2);
  node.splice(node.end(), mainChain[0], nodeIt, mainChain[0].end());
  mainChain.push_front(node);
  if (mainChain.size() == mainChainMaxSize && odd.empty()) return;

  int jacob = 1, prevJacob = 1, tmp, insertCnt;
  size_t idx = 2;
  std::deque<std::list<int> >::iterator pos;
  while (mainChainMaxSize != mainChain.size()) {
    tmp = jacob;
    jacob = jacob + 2 * prevJacob;
    prevJacob = tmp;

    insertCnt = jacob - prevJacob;
    idx <<= 1;
    if (idx > mainChain.size()) {
      idx = mainChain.size();
      insertCnt = mainChainMaxSize - mainChain.size();
    }

    for (int i = idx - 1; insertCnt > 0;) {
      if (mainChain[i].size() == listSize) {
        nodeIt = mainChain[i].begin();

        std::advance(nodeIt, listSize / 2);
        node.clear();
        node.splice(node.end(), mainChain[i], nodeIt, mainChain[i].end());
        pos = std::lower_bound(mainChain.begin(), mainChain.begin() + i, node,
                               compare);
        mainChain.insert(pos, node);
        --insertCnt;
        continue;
      }
      --i;
    }
  }

  if (!odd.empty()) {
    pos = std::lower_bound(mainChain.begin(), mainChain.end(), odd, compare);
    mainChain.insert(pos, odd);
  }
}

const std::vector<int> &PmergeMe::getVector() const { return mVector; }

const std::deque<int> &PmergeMe::getDeque() const { return mDeque; }

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { (void)other; }

PmergeMe PmergeMe::operator=(const PmergeMe &other) {
  (void)other;
  return *this;
}