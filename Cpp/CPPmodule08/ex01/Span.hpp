#pragma once

#include <algorithm>
#include <exception>
#include <iostream>
#include <numeric>
#include <vector>

class Span {
 private:
  std::vector<int> mIntVec;

  Span();

 public:
  Span(unsigned int N);
  Span(const Span& rhs);
  Span& operator=(const Span& other);
  ~Span();

  void addNumber(unsigned int num);
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;
  template <typename T>
  void addNumberWithContainer(const T& container);

  std::vector<int> getIntVec() const;
};

#include "Span.tpp"
