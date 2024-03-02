#include "FileManager.hpp"

FileManager::FileManager(std::string origin_filename)
    : in_state_(std::ios_base::goodbit), original_filename_(origin_filename) {
  new_filename_ = original_filename_ + ".replace";
}

FileManager::~FileManager() {
  if (out_file_.is_open()) out_file_.close();
  if (in_file_.is_open()) in_file_.close();
}

bool FileManager::OpenAndCreateFile() {
  in_file_.open(original_filename_);
  out_file_.open(new_filename_);
  if (!in_file_.is_open() || !out_file_.is_open()) return false;
  return true;
}

bool FileManager::GetlineInFile(std::string& line) {
  std::getline(in_file_, line);

  in_state_ = in_file_.rdstate();
  if (in_state_)
    return false;
  else
    return true;
}

bool FileManager::WriteLineInFile(const std::string& line) {
  out_file_ << line << std::endl;
  if (out_file_.fail())
    return false;
  else
    return true;
}