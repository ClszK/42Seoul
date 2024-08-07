#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : mIntVec(N) { mIntVec.resize(0); }

Span::Span(const Span& rhs) : mIntVec(rhs.mIntVec) { mIntVec.resize(0); }

Span& Span::operator=(const Span& other) {
  if (this != &other) {
    mIntVec = other.mIntVec;
  }
  return *this;
}

Span::~Span() {}

void Span::addNumber(unsigned int num) {
  if (mIntVec.size() >= mIntVec.capacity())
    throw std::out_of_range("Full Integer");
  mIntVec.push_back(num);
}

unsigned int Span::shortestSpan() const {
  if (mIntVec.size() < 2) throw std::out_of_range("Not enough elements.");
  std::vector<int> sortedVec(mIntVec);
  std::vector<int> result(sortedVec.size());

  std::sort(sortedVec.begin(), sortedVec.end());

  std::adjacent_difference(sortedVec.begin(), sortedVec.end(), result.begin());

  return *std::min_element(result.begin() + 1, result.end());
}

unsigned int Span::longestSpan() const {
  if (mIntVec.size() < 2) throw std::out_of_range("Not enough elements.");
  std::vector<int> sortedVec(mIntVec);

  std::sort(sortedVec.begin(), sortedVec.end());

  return (sortedVec.back() - sortedVec.front());
}
std::vector<int> Span::getIntVec() const { return mIntVec; }
