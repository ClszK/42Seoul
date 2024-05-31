#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "ReplaceString.hpp"

class FileManager {
 private:
  std::ofstream out_file_;
  std::ifstream in_file_;
  std::ios_base::iostate io_state_;
  std::string original_filename_;
  std::string new_filename_;
  ReplaceString replace_obj_;
  /* data */
 public:
  FileManager(std::string origin_filename, std::string s1, std::string s2);
  ~FileManager();

  std::ios_base::iostate ioState() const;
  bool OpenAndCreateFile();
  void GetlineInFile(std::string& line);
  void WriteLineInFile(std::string& line);
};