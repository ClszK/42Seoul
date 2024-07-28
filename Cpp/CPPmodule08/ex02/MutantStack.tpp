#pragma once

#include "MutantStack.hpp"

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack()
    : std::stack<T, Container>() {}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& rhs)
    : std::stack<T, Container>(rhs) {}

template <typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(
    const MutantStack& other) {
  if (this != &other) {
    std::stack<T, Container>::operator=(other);
  }
  return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::begin() {
  return this->c.begin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::iterator
MutantStack<T, Container>::end() {
  return this->c.end();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::cbegin() const {
  return this->c.cbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator
MutantStack<T, Container>::cend() const {
  return this->c.cend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rbegin() {
  return this->c.rbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator
MutantStack<T, Container>::rend() {
  return this->c.rend();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::crbegin() const {
  return this->c.crbegin();
}

template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator
MutantStack<T, Container>::crend() const {
  return this->c.crend();
}