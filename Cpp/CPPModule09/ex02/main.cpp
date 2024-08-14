#include <algorithm>
#include <deque>
#include <iostream>

void binarySearchInsertDeq(std::deque<int>& deq, std::deque<size_t>& mainChain,
                           size_t pairSize, size_t rangeStart) {
  size_t left = 0, right = mainChain.size() - 1;
  int mid;
  while (left <= right) {
    mid = (left + right) / 2;
    if (mainChain[mid] == deq[rangeStart]) {
      left = mid;
      break;
    } else if (mainChain[mid] < deq[rangeStart])
      left = mid + 1;
    else
      right = mid - 1;
  }
  deq.insert(deq.begin() + mainChain[left], deq.begin() + rangeStart,
             deq.begin() + rangeStart + pairSize);
  deq.erase(deq.begin() + rangeStart, deq.begin() + rangeStart + pairSize);
  mainChain.insert(mainChain.begin() + mid, deq[rangeStart]);
}

void insertionPair(std::deque<int>& deq, std::deque<size_t>& mainChain,
                   size_t pairSize) {
  int jacobsthal[] = {1,     3,     5,     11,     21,    43,   85,
                      171,   341,   683,   1365,   2731,  5461, 10923,
                      21845, 43691, 87381, 174763, 349525};

  if (pairSize * 2 >= deq.size()) {
    mainChain.push_front(deq[0]);
    return;
  }

  std::swap_ranges(deq.begin(), deq.begin() + pairSize, deq.begin() + pairSize);
  mainChain.push_front(deq[0]);

  size_t idx = 1;
  size_t pendingSize = deq.size() / pairSize / 2;
  size_t jacobsthalSize = 0;
  size_t pendingPos =
      (pendingSize < jacobsthal[idx] ? pendingSize : jacobsthal[idx]);
  int cnt = pendingSize - 1;

  std::cout << "DEQ\n";
  for (auto a : deq) {
    std::cout << a << " ";
  }
  std::cout << "\n";
  while (cnt--) {
    std::deque<size_t>::iterator pos = std::lower_bound(
        mainChain.begin(), mainChain.end(), deq[(pendingPos + 1) * pairSize]);
    mainChain.insert(pos, deq[(pendingPos + 1) * pairSize]);
    deq.insert(deq.begin() + (pos - mainChain.begin() - 1) * pairSize,
               deq.begin() + (pendingPos + 1) * pairSize,
               deq.begin() + (pendingPos + 1) * pairSize + pairSize);
    deq.erase(deq.begin() + (pendingPos + 2) * pairSize,
              deq.begin() + (pendingPos + 2) * pairSize + pairSize);
    if (pendingPos == jacobsthal[idx - 1]) {
      pendingPos =
          (pendingPos < jacobsthal[++idx] ? pendingSize : jacobsthal[idx]);
    } else {
      pendingPos--;
    }
    std::cout << "PAIR SIZE : " << pairSize << std::endl;
    std::cout << "DEQ\n";
    for (auto a : deq) {
      std::cout << a << " ";
    }
    std::cout << "\n";
    std::cout << "MAIN CHAIN\n";
    for (auto a : mainChain) {
      std::cout << a << " ";
    }
    std::cout << "\n\n";
  }

  // while () {
  // deq.insert(deq.begin() + )
  // }

  // binarySearchInsertDeq(deq, mainChain, pairSize, 3 * pairSize - 1);
}

void mergePair(std::deque<int>& deq, std::deque<size_t>& mainChain,
               size_t pairSize) {
  if (pairSize == 16) return;

  for (size_t i = 0; i < deq.size() - pairSize; i += pairSize * 2) {
    if (deq[i] < deq[i + pairSize]) {
      std::swap_ranges(deq.begin() + i, deq.begin() + i + pairSize,
                       deq.begin() + i + pairSize);
    }
  }
  mergePair(deq, mainChain, pairSize * 2);
  insertionPair(deq, mainChain, pairSize);
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
// 		    2 - 4 - 5 - 8
// 		   /   /   /   /
// 		  0   1   3   6

//    0   1   3   5   7
// 		0 - 2 - 4 - 5 - 8
// 		      /   /   /
// 		     1   3   6

// 		0 - 1 - 2 - 3 - 4 - 5 - 8
// 		       		  	       /
// 		      	              6

// 		0 - 1 - 2 - 3 - 4 - 5 - 6 - 8 / 7

int main(int argc, char* argv[]) {
  std::deque<int> deq(argc - 1);
  std::deque<size_t> mainChain;

  for (int i = 0; i < argc - 1; ++i) {
    deq[i] = std::atol(argv[i + 1]);
  }

  mergePair(deq, mainChain, 1);

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

  // mergePair(deq, pairSize * 2);
  // insertionPair(deq, pairSize / 2);
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