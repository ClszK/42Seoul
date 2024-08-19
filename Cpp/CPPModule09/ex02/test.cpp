#include <algorithm>
#include <iostream>
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
            std::vector<int>& pendingChain) {
  std::vector<int> jacobsthal = jacobsthalVec(pendingChain.size());
  int prevIdx = 0, pendingSize = mainChain.size() * 2;
  bool existOdd = mainChain.size() != pendingChain.size();

  for (int mainIdx = 0; mainIdx < mainChain.size(); ++mainIdx) {
    if (mainChain[mainIdx].second != mainIdx) {
      for (int pendingPos = mainIdx; pendingPos < pendingChain.size();
           pendingPos += mainChain.size())
        std::swap(pendingChain[pendingPos],
                  pendingChain[mainChain[pendingPos].second]);
    }
  }

  // mainChain.insert(mainChain.begin(), std::make_pair(pendingChain[0], 0));
  // for (int i = 1; i < mainChain.size(); ++i)
  //   ++mainChain[i].second;

  for (int i = 0; i < jacobsthal.size(); ++i) {
    int index =
        (pendingSize <= jacobsthal[i] ? pendingSize - existOdd : jacobsthal[i]);

    for (int j = index - 1; j >= prevIdx; --j) {
      std::vector<std::pair<int, int> >::iterator it =
          std::find_if(mainChain.begin(), mainChain.end(), IsEqual(j));
      std::cout << "it : " << it->first << std::endl;
      it = (it == mainChain.begin() ? it : it - 1);
      std::pair<int, int> temp =
          std::make_pair(pendingChain[j], it - mainChain.begin());
      for (; it != mainChain.end(); ++it) ++it->second;

      mainChain.insert(
          std::lower_bound(mainChain.begin(), it, temp, comparePairs) + 1,
          temp);
    }
    prevIdx = index + 1;
    testPrint(mainChain, pendingChain);
  }
  if (existOdd) {
    std::vector<std::pair<int, int> >::iterator it =
        std::lower_bound(mainChain.begin(), mainChain.end(),
                         std::make_pair(pendingChain.back(), -1), comparePairs);
    mainChain.insert(it,
                     std::make_pair(pendingChain.back(), pendingChain.size()));
  }
}

void merge(std::vector<std::pair<int, int> >& vec, int size) {
  if (vec.size() < 2) return;

  std::vector<std::pair<int, int> > mainChain(vec.size() / 2);
  std::vector<int> pendingChain(vec.size() / 2);
  int maxValPos, mainChainPos = 0, pendingChainPos = 0;

  for (size_t i = 0; i < vec.size() / 2; ++i) {
    maxValPos = (vec[i * 2].first > vec[i * 2 + 1].first ? i * 2 : i * 2 + 1);
    mainChain[mainChainPos++] =
        std::make_pair(vec[maxValPos].first, pendingChainPos);
    pendingChain[pendingChainPos++] =
        std::min(vec[i * 2].first, vec[i * 2 + 1].first);
  }
  if (vec.size() % 2) {
    pendingChain.push_back(vec.back().first);
  }

  // vec.erase(vec.begin() + vec.size() / 2, vec.end());

  testPrint(mainChain, pendingChain);
  merge(mainChain, size);
  insert(mainChain, pendingChain);
  vec = mainChain;
}

void sort(std::vector<int>& vec) {
  std::vector<std::pair<int, int> > mainChain(vec.size());
  for (int i = 0; i < vec.size(); ++i) {
    mainChain[i] = std::make_pair(vec[i], i);
  }
  merge(mainChain, vec.size());

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

//    0 1 2 3   /   4 5 6 7  8	   => 4
//   {8 6 4 1}     {5 3 2 0} 7

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
