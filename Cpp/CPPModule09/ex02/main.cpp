#include <cmath>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

int cnt = 0;

bool compareVec(const std::list<int>& a, const std::list<int>& b) {
  ++cnt;
  return a.front() < b.front();
}

void testPrint(std::vector<std::list<int> >& vec) {
  std::cout << "main" << std::endl;
  int k = 0;
  for (auto& i : vec) {
    std::cout << k++ << "\t: ";
    for (auto& j : i) std::cout << j << " ";
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void insert(std::vector<std::list<int> >& mainChain, std::list<int>& odd) {
  int moveIdx = 1, listSize = mainChain[0].size();
  int mainChainMaxSize = mainChain.size() * 2;

  std::list<int>::iterator nodeIt = mainChain[0].begin();
  std::advance(nodeIt, listSize / 2);

  std::list<int> node;
  node.splice(node.end(), mainChain[0], nodeIt, mainChain[0].end());
  mainChain.insert(mainChain.begin(), node);
  if (mainChain.size() == mainChainMaxSize && odd.empty()) return;

  int n = 2, prevIdx = 1, idx = 0;
  while (mainChainMaxSize != mainChain.size()) {
    n = n << 1;
    idx = n - 1;
    int insertCnt = 1;
    if (idx > mainChain.size() - 1) idx = mainChain.size() - 1;

    for (int i = idx; i >= prevIdx;) {
      if (mainChain[i].size() == listSize) {
        std::list<int>::iterator nodeIt = mainChain[i].begin();

        std::advance(nodeIt, listSize / 2);
        std::list<int> node;
        node.splice(node.end(), mainChain[i], nodeIt, mainChain[i].end());
        std::vector<std::list<int> >::iterator pos = std::lower_bound(
            mainChain.begin(), mainChain.begin() + i, node, compareVec);
        mainChain.insert(pos, node);
        ++insertCnt;
        continue;
      }
      --i;
    }
    prevIdx = idx + insertCnt;
  }

  if (!odd.empty()) {
    std::vector<std::list<int> >::iterator pos =
        std::lower_bound(mainChain.begin(), mainChain.end(), odd, compareVec);
    mainChain.insert(pos, odd);
  }
}

void merge(std::vector<std::list<int> >& mainChain) {
  if (mainChain.size() < 2) return;

  int mainChainSize = mainChain.size();

  std::list<int> node;

  if (mainChainSize != 1 && mainChainSize % 2) {
    node.splice(node.end(), mainChain.back());
    mainChain.pop_back();
  }

  for (int i = 0; i < mainChainSize / 2; ++i) {
    int minPos = i, maxPos = i + 1;

    cnt++;
    if (mainChain[maxPos].front() < mainChain[minPos].front())
      minPos = i + 1, maxPos = i;
    mainChain[maxPos].splice(mainChain[maxPos].end(), mainChain[minPos]);
    mainChain.erase(mainChain.begin() + minPos);
  }

  merge(mainChain);

  insert(mainChain, node);
}

void sort(std::vector<int>& vec) {
  std::vector<std::list<int> > mainChain;

  for (int i = 0; i < vec.size(); ++i) {
    std::list<int> node;

    node.push_back(vec[i]);
    mainChain.push_back(node);
  }

  merge(mainChain);
  for (int i = 0; i < mainChain.size(); ++i) {
    vec[i] = mainChain[i].front();
  }
}

int sortCnt = 0;
bool compareVec2(int a, int b) {
  ++sortCnt;
  return a < b;
}

int main(int argc, char* argv[]) {
  std::vector<int> vec(argc - 1);

  int num = 0;

  for (int i = 1; i < argc; ++i) vec[i - 1] = std::stoi(argv[i]);
  std::vector<int> vec2 = vec;

  clock_t start = clock();
  sort(vec);
  clock_t end = clock();
  std::cout << "Time to process a range of " << argc - 1
            << " elements with std::deque : "
            << static_cast<double>(end - start) * 1000.0 / CLOCKS_PER_SEC
            << " ms" << std::endl;
  std::cout << "\t\tcnt: " << cnt << std::endl;

  std::sort(vec2.begin(), vec2.end(), compareVec2);
  if (vec == vec2) {
    std::cout << "Vectvr is sorted." << std::endl;
  }
  std::cout << "\t\tstd::sort cnt: " << sortCnt << std::endl;

  return 0;
}