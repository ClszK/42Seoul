#include "Span.hpp"

template <typename T>
void Span::addNumberWithContainer(const T& container) {
  if (container.size() > mIntVec.capacity() - mIntVec.size())
    throw std::out_of_range("Over Capacity.");

  mIntVec.insert(mIntVec.end(), container.begin(), container.end());
}