#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

std::vector<int> jacobsthalVec(int size) {
  std::vector<int> jacobsthal(size);

  jacobsthal[0] = 1;
  if (size > 1) jacobsthal[1] = 3;

  for (int i = 2; i < size; i++)
    jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];

  return jacobsthal;
}

void testPrint(std::vector<std::pair<int, int> >& vec,
               std::vector<int>& pendingChain) {
  std::cout << "main" << std::endl;
  for (auto& i : vec) std::cout << i.first << " " << i.second << std::endl;
  std::cout << std::endl;
  std::cout << "pending" << std::endl;
  for (auto& i : pendingChain) std::cout << i << " ";
  std::cout << std::endl;
}

class IsEqual {
 public:
  int value;

  IsEqual(int v) : value(v) {}
  bool operator()(const std::pair<int, int>& p) const {
    return p.second == value;
  }
};

bool comparePairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
  return a.first < b.first;
}

void insert(std::vector<std::pair<int, int> >& mainChain,
            std::vector<int>& pendingChain, int pendingSize) {
  std::vector<int> jacobsthal = jacobsthalVec(pendingSize);
  int prevIdx = 0, inOrder = mainChain.size();
  int existOdd = pendingSize != 1 && pendingSize % 2;
  std::cout << "Insert start\n";
  testPrint(mainChain, pendingChain);

  std::cout << "PendingSize : " << pendingSize << std::endl;
  for (int mainIdx = 0; mainIdx < mainChain.size(); ++mainIdx) {
    if (mainChain[mainIdx].second != mainIdx) {
      std::vector<std::pair<int, int> >::iterator it = std::find_if(
          mainChain.begin() + mainIdx, mainChain.end(), IsEqual(mainIdx));
      std::swap(mainChain[mainIdx].second, it->second);
      int distance = std::distance(mainChain.begin() + mainIdx, it);
      for (int pendingPos = mainIdx;
           pendingPos < pendingChain.size() - distance;
           pendingPos += mainChain.size())
        // std::swap(pendingChain[pendingPos],
        //           pendingChain[pendingPos + distance]);
        std::swap_ranges(
            pendingChain.begin() + pendingPos,
            pendingChain.begin() + pendingPos + pendingSize,
            pendingChain.begin() + pendingPos + pendingSize + distance);
    }
  }
  std::cout << "After\n";
  testPrint(mainChain, pendingChain);

  for (int i = 0; i < jacobsthal.size(); ++i) {
    int index =
        (pendingSize <= jacobsthal[i] ? pendingSize - existOdd : jacobsthal[i]);

    for (int j = index - 1; j >= prevIdx; --j) {
      std::vector<std::pair<int, int> >::iterator it =
          std::find_if(mainChain.begin(), mainChain.end(), IsEqual(j));
      it = (it == mainChain.begin() ? it : it - 1);
      std::pair<int, int> temp = std::make_pair(
          pendingChain[pendingChain.size() - pendingSize + j], inOrder++);

      mainChain.insert(
          std::lower_bound(mainChain.begin(), it, temp, comparePairs), temp);
    }
    prevIdx = index;
  }

  if (existOdd) {
    std::vector<std::pair<int, int> >::iterator it = std::lower_bound(
        mainChain.begin(), mainChain.end(),
        std::make_pair(pendingChain.back(), pendingSize - 1), comparePairs);
    mainChain.insert(it,
                     std::make_pair(pendingChain.back(), pendingChain.size()));
  }

  pendingChain.erase(pendingChain.end() - pendingSize, pendingChain.end());
}

// void merge(std::vector<std::pair<int, int> >& vec,
//            std::vector<int>& pendingChain) {
//   if (vec.size() < 2) return;

//   std::vector<std::pair<int, int> > mainChain(vec.size() / 2);

//   int pendingSize = vec.size() / 2;

//   for (size_t i = 0; i < vec.size() / 2; ++i) {
//     int minPos = i * 2 + 1, maxPos = i * 2;

//     if (vec[maxPos].first < vec[minPos].first) {
//       for (size_t j = i; j < pendingChain.size(); j += pendingSize) {
//         std::swap(pendingChain[j * 2], pendingChain[j * 2 + 1]);
//       }
//       minPos = i * 2, maxPos = i * 2 + 1;
//     }
//     mainChain[i] = std::make_pair(vec[maxPos].first, i);
//     pendingChain.push_back(vec[minPos].first);
//   }

//   if (vec.size() % 2) pendingChain.push_back(vec.back().first);

//   // testPrint(mainChain, pendingChain);
//   merge(mainChain, pendingChain);
//   insert(mainChain, pendingChain,
//          static_cast<int>(std::round(static_cast<double>(vec.size()) / 2)));
//   vec = mainChain;
// }

void merge(std::vector<std::pair<int, int> >& vec,
           std::vector<int>& pendingChain) {
  if (vec.size() < 2) return;

  std::vector<std::pair<int, int> > mainChain(vec.size() / 2);

  int pendingSize = vec.size() / 2;

  for (size_t i = 0; i < vec.size() / 2; ++i) {
    int minPos = i * 2 + 1, maxPos = i * 2;

    if (vec[maxPos].first < vec[minPos].first) {
      for (size_t j = i; j < pendingChain.size() - i; j += pendingSize) {
        // std::swap(pendingChain[j * 2], pendingChain[j * 2 + 1]);
        std::swap_ranges(pendingChain.begin() + j * 2,
                         pendingChain.begin() + j * 2 + pendingSize / 2,
                         pendingChain.begin() + j * 2 + pendingSize / 2);
      }
      minPos = i * 2, maxPos = i * 2 + 1;
    }
    mainChain[i] = std::make_pair(vec[maxPos].first, i);
    pendingChain.push_back(vec[minPos].first);
  }

  if (vec.size() % 2) pendingChain.push_back(vec.back().first);

  testPrint(mainChain, pendingChain);
  merge(mainChain, pendingChain);
  // insert(mainChain, pendingChain,
  //        static_cast<int>(std::round(static_cast<double>(vec.size()) / 2)));
  vec = mainChain;
}

void sort(std::vector<int>& vec) {
  std::vector<std::pair<int, int> > mainChain(vec.size());
  std::vector<int> pendingChain;
  for (int i = 0; i < vec.size(); ++i) {
    mainChain[i] = std::make_pair(vec[i], i);
  }
  merge(mainChain, pendingChain);

  for (auto& a : mainChain) std::cout << a.first << " ";
}

int main(int argc, char* argv[]) {
  std::vector<int> vec(argc - 1);

  for (int i = 1; i < argc; ++i) vec[i - 1] = std::stoi(argv[i]);

  sort(vec);

  return 0;
}

// 0 1 2 3 4 5 6 7 8
// 4 1 8 6 2 0 3 5 7

//  0 1 2 3 4 5 6 7    /   8	   => 2
// {4 1} {8 6} {2 0} {5 3} 7
// [4 8 2 5]
// [1 6 0 3]

//    0 1 2 3   /   4 5 6 7  8	   => 4
//       {5 3 2 0} {8 6 4 1}
// [8 5]
// [6 3]
// [4 2]
// [1 0]
/*
8
6
4
1
5
3
2
0
*/

//  (0 1)/(2 3) | (4 5)/(6 7)  8  => 8
//      {8 6 4 1 5 3 2 0}      7

// -----------------------------
//  (0 1)/(2 3) | (4 5)/(6 7)  8  => 4
// 	{5 3 2 0} {8 6 4 1}  7

//      (0 1   2 3) (4 5   6 7)  8 	   => 2
//  	{5 3} {2 0} {8 6} {4 1}  7
// ->  {2 0} {5 3} {8 6} {4 1} 7
// ->  {2 0} {4 1} {5 3} {8 6}  7
//		 1     2	 3	   4

// 여기서부터 야콥스탈 수열이 필요할듯?

//  (0 1 2 3 4 5 6 7) / 8		   => 1

// 		    2 - 4 - 5 - 8
// 		   /   /   /   /
// 		  0   1   3   6

//      0   1   3   5   7
// 		0 - 2 - 3 - 5 - 8
// 		       /   /   /
// 		      1   4   6

// {8 7} {6 5} {4 3} {2 1}