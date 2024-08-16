#include <deque>
#include <iostream>

void testPrint(std::deque<size_t>& deq) {
  std::cout << "main" << std::endl;
  for (auto& i : deq) std::cout << i << " ";
  std::cout << std::endl;
}

std::deque<size_t> jacobsthalDeq(size_t size) {
  std::deque<size_t> jacobsthal(size);

  jacobsthal[0] = 1;
  if (size > 1) jacobsthal[1] = 3;

  for (size_t i = 2; i < size; i++)
    jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];

  return jacobsthal;
}

size_t binarySearch(std::deque<size_t>& deq,
                    std::deque<std::pair<size_t, bool> >& mainChainIdx,
                    std::deque<size_t>& subChainIdx, size_t pairSize,
                    size_t subChainPos) {
  int left = 0, i = 0;
  for (; i < mainChainIdx.size(); ++i) {
    if (mainChainIdx[i].first == subChainIdx[subChainPos] - pairSize / 2) break;
  }
  mainChainIdx[i].second = false;
  int right = i - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (deq[mainChainIdx[mid].first] < deq[subChainIdx[subChainPos]]) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  size_t insertPos = 0;

  for (int m = 0; m < left; ++m) {
    if (mainChainIdx[m].second)
      insertPos += pairSize;
    else
      insertPos += pairSize / 2;
  }
  mainChainIdx.insert(mainChainIdx.begin() + left,
                      std::make_pair(insertPos, false));

  deq.insert(deq.begin() + insertPos, deq.begin() + subChainIdx[subChainPos],
             deq.begin() + subChainIdx[subChainPos] + pairSize / 2);
  deq.erase(deq.begin() + subChainIdx[subChainPos] + pairSize / 2,
            deq.begin() + subChainIdx[subChainPos] + pairSize);
  for (size_t k = left; k < i + 1; ++k) {
    mainChainIdx[k + 1].first += pairSize / 2;
  }
  for (int k = 0; k < subChainPos; ++k) {
    if (subChainIdx[k] >= mainChainIdx[left].first)
      subChainIdx[k] += pairSize / 2;
  }

  std::cout << "i : " << i << std::endl;
  std::cout << "left : " << left << std::endl;
  std::cout << "deq" << std::endl;
  for (auto a : deq) std::cout << a << " ";
  std::cout << std::endl;
  std::cout << "MainChainIdx" << std::endl;
  for (auto a : mainChainIdx) std::cout << deq[a.first] << " ";
  std::cout << std::endl;
  std::cout << "SubChainIdx" << std::endl;
  for (auto a : subChainIdx) std::cout << deq[a] << " ";
  std::cout << std::endl;
  return left;
}

void insert(std::deque<size_t>& deq, size_t pairSize) {
  std::deque<std::pair<size_t, bool> > mainChainIdx(deq.size() / pairSize);
  std::deque<size_t> subChainIdx(deq.size() / pairSize),
      jacobsthal = jacobsthalDeq(deq.size() / pairSize);

  size_t idx = 0, i = 0;

  for (; i < deq.size() / pairSize; ++i) {
    mainChainIdx[idx] = std::make_pair(i * pairSize, true);
    subChainIdx[idx] = i * pairSize + pairSize / 2;
    ++idx;
  }
  std::cout << "MainChainIdx before" << std::endl;
  for (auto a : mainChainIdx) std::cout << deq[a.first] << " ";
  std::cout << std::endl;
  std::cout << "SubChainIdx before" << std::endl;
  for (auto a : subChainIdx) std::cout << deq[a] << " ";
  std::cout << std::endl;

  int prevIdx = 0;
  for (size_t i = 0; i < jacobsthal.size(); ++i) {
    size_t index = (jacobsthal[i] >= subChainIdx.size() ? subChainIdx.size()
                                                        : jacobsthal[i]);

    for (int j = index - 1; j >= prevIdx; --j) {
      size_t insertMainChainPos =
          binarySearch(deq, mainChainIdx, subChainIdx, pairSize, j);
      size_t mainIdx = 0, subIdx = 0;
    }
    prevIdx = index;
    std::cout << std::endl;
  }
}

void mergePair(std::deque<size_t>& deq, size_t pairSize) {
  if (pairSize > deq.size()) {
    return;
  };

  for (size_t i = 0; i < deq.size() / pairSize; ++i) {
    size_t pairSizeIdx = i * pairSize;

    if (deq[pairSizeIdx] < deq[pairSizeIdx + pairSize / 2]) {
      std::swap_ranges(deq.begin() + pairSizeIdx,
                       deq.begin() + pairSizeIdx + pairSize / 2,
                       deq.begin() + pairSizeIdx + pairSize / 2);
    }
  }

  mergePair(deq, pairSize * 2);
  if (pairSize >= 2) insert(deq, pairSize);
}

int main(int argc, char* argv[]) {
  std::deque<size_t> deq(argc - 1);

  for (int i = 1; i < argc; ++i) deq[i - 1] = std::stoi(argv[i]);

  mergePair(deq, 2);
  for (auto a : deq) std::cout << a << " ";
  return 0;
}
