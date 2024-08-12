#include <algorithm>
#include <deque>
#include <iostream>

void insertionPair(std::deque<int>& deq, size_t pairSize) {
  int jacobsthal[] = {3,     5,     11,    21,    43,     85,
                      171,   341,   683,   1365,  2731,   5461,
                      10923, 21845, 43691, 87381, 174763, 349525};
  if (pairSize < 2) return;
  if (pairSize == deq.size() / 2) return;

  std::swap(deq[0], deq[1]);
  size_t pendingChainSize = deq.size() / pairSize;
  size_t pendingChain, prevPos = 2, idx = 0,
                       finishSortCnt = pendingChainSize - 1;

  // 1은 무조건 맨 앞에 삽입되기때문에 무시, 결국 b_2부터 계산해야함.
  while (true) {
    pendingChain = (pendingChainSize < jacobsthal[idx] ? pendingChainSize
                                                       : jacobsthal[idx]);
    for (int i = pendingChain; i >= prevPos; --i) {
      std::deque<int>::iterator pos = std::lower_bound(
          deq.begin(), deq.begin() + (i - 1) * 2 - 1, deq[i * 2 - 1]);
      deq.insert(pos, deq[i * 2 - 1]);
      deq.erase(deq.begin() + i * 2 - 1);
      for (auto& elem : deq) {
        std::cout << elem << " ";
      }
      std::cout << std::endl;
      std::cout << std::endl;
      if (!(--finishSortCnt)) return;
    }
    prevPos = jacobsthal[idx++];
  }
}

void mergePair(std::deque<int>& deq, size_t pairSize) {
  if (pairSize == 16) return;

  for (size_t i = 0; i < deq.size() - pairSize; i += pairSize * 2) {
    if (deq[i] < deq[i + pairSize]) {
      std::swap_ranges(deq.begin() + i, deq.begin() + i + pairSize,
                       deq.begin() + i + pairSize);
    }
  }
  mergePair(deq, pairSize * 2);
  insertionPair(deq, pairSize / 2);
}

// 0 1 2 3 4 5 6 7 8
// 4 1 8 6 2 0 3 5 7

//  0 1 2 3 4 5 6 7    /   8	   => 2
// {4 1} {8 6} {2 0} {5 3} 7

//    0 1 2 3   /   4 5 6 7  8	   => 4
//   {8 6 4 1}     {5 3 2 0} 7

//  (0 1)/(2 3) | (4 5)/(6 7)  8  => 8
//      {8 6 4 1 5 3 2 0}      7

// -----------------------------
//  (0 1)/(2 3) | (4 5)/(6 7)  8  => 4
// 	{5 3 2 0} {8 6 4 1}  7

//  (0 1 2 3) | (4 5 6 7) 8 	   => 2
//  	{5 3} {2 0} {8 6} {4 1}  7
// ->  {2 0} {5 3} {8 6} {4 1} 7
// ->  {2 0} {4 1} {5 3} {8 6}  7
//		 1     2	 3	   4

// 여기서부터 야콥스탈 수열이 필요할듯?

//  (0 1 2 3 4 5 6 7) / 8		   => 1
// 		0 - 2 - 4 - 5 - 8
// 		       /   /   /
// 		      1   3   6

// 		0 - 2 - 3 - 4 - 5 - 8
// 		       		/      /
// 		      	   1      6

// 		0 - 1 - 2 - 3 - 4 - 5 - 8
// 		       		  	       /
// 		      	              6

// 		0 - 1 - 2 - 3 - 4 - 5 - 6 - 8 / 7

int main(int argc, char* argv[]) {
  std::deque<int> deq(argc - 1);

  for (int i = 0; i < argc - 1; ++i) {
    deq[i] = std::atol(argv[i + 1]);
  }

  mergePair(deq, 1);

  for (auto& elem : deq) {
    std::cout << elem << " ";
  }

  return 0;
}

void mergePair_backup(std::deque<int>& deq, size_t pairSize) {
  if (pairSize == 16) return;

  for (size_t i = 0; i < deq.size() - pairSize; i += pairSize * 2) {
    std::cout << "i: " << i << " | " << deq[i] << " " << deq[i + pairSize]
              << std::endl;
    if (deq[i] < deq[i + pairSize]) {
      std::swap_ranges(deq.begin() + i, deq.begin() + i + pairSize,
                       deq.begin() + i + pairSize);
    }
  }
  std::cout << std::endl;

  mergePair(deq, pairSize * 2);
  insertionPair(deq, pairSize / 2);
}

void insertionPair_backup(std::deque<int>& deq, size_t pairSize) {
  int jacobsthal[] = {3,     5,     11,    21,    43,     85,
                      171,   341,   683,   1365,  2731,   5461,
                      10923, 21845, 43691, 87381, 174763, 349525};
  if (pairSize < 2) return;
  size_t maxIdx = pairSize * 2;

  std::cout << "pairSize : " << pairSize << std::endl;
  std::swap_ranges(deq.begin(), deq.begin() + pairSize, deq.begin() + pairSize);
  if (pairSize == deq.size() / 2) {
    for (auto& elem : deq) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    return;
  }
  std::swap(deq[0], deq[1]);
  for (auto& elem : deq) {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
  std::cout << std::endl;
}