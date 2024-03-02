#include "ReplaceString.hpp"

ReplaceString::ReplaceString(std::string s1, std::string s2)
    : original_s1_(s1), replace_s2_(s2) {}

ReplaceString::~ReplaceString() {}

void ReplaceString::Replace(std::string& str) {
  std::string::size_type original_idx = 0;

  while (true) {
    original_idx = str.find(original_s1_, original_idx);
    if (original_idx == std::string::npos) break;

    str.erase(original_idx, original_s1_.length());
    str.insert(original_idx, replace_s2_);
    original_idx += replace_s2_.length();
  }
}