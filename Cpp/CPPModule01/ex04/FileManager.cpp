#include "FileManager.hpp"

FileManager::FileManager(std::string origin_filename, std::string s1,
                         std::string s2)
    : io_state_(std::ios_base::goodbit),
      original_filename_(origin_filename),
      replace_obj_(s1, s2) {
  new_filename_ = original_filename_ + ".replace";
}

FileManager::~FileManager() {
  if (out_file_.is_open()) out_file_.close();
  if (in_file_.is_open()) in_file_.close();
}

std::ios_base::iostate FileManager::ioState() const { return io_state_; }

bool FileManager::OpenAndCreateFile() {
  in_file_.open(original_filename_.c_str());
  if (!in_file_.is_open()) return false;
  out_file_.open(new_filename_.c_str());
  if (!out_file_.is_open()) return false;
  return true;
}

void FileManager::GetlineInFile(std::string& line) {
  std::getline(in_file_, line);
  if (in_file_.rdstate()) io_state_ = in_file_.rdstate();
}

void FileManager::WriteLineInFile(std::string& line) {
  replace_obj_.Replace(line);
  out_file_ << line;
  if (in_file_.eof()) return;
  out_file_ << std::endl;
  io_state_ = out_file_.rdstate();
}