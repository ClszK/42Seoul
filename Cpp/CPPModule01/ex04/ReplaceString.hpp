#pragma once

#include <string>

class ReplaceString {
 private:
  std::string original_s1_;
  std::string replace_s2_;
  /* data */
 public:
  ReplaceString(std::string s1, std::string s2);
  ~ReplaceString();
  void Replace(std::string& str);
};
