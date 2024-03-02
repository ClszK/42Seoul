#pragma once

#include <fstream>
#include <iostream>
#include <string>

class FileManager {
 private:
  std::ofstream out_file_;
  std::ifstream in_file_;
  std::ios_base::iostate in_state_;
  std::string original_filename_;
  std::string new_filename_;
  /* data */
 public:
  FileManager(std::string origin_filename);
  ~FileManager();
  bool OpenAndCreateFile();
  bool GetlineInFile(std::string& line);
  bool WriteLineInFile(const std::string& line);
};