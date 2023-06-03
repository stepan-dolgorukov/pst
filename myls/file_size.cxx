#include "file_size.hxx"
#include <sys/stat.h>

myls::file_size::file_size(const std::string &name) {
  int error_status{::stat(name.c_str(), &stat)};
  fill_size();
}

void myls::file_size::fill_size(void) {
  size = stat.st_size;
}

std::size_t myls::file_size::operator()(void) {
  return size;
}