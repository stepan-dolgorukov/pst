#include "file_size.hxx"
#include <iostream>
#include <sys/stat.h>
#include <cstdint>
#include <system_error>

myls::file_size::file_size(const std::string &name) {
  int error_status{::stat(name.c_str(), &stat)};
  fill_size();
}

void myls::file_size::fill_size(void) {
  size = stat.st_size;
}

std::size_t myls::file_size::operator()(void) const {
  return size;
}

std::string myls::file_size::operator()(bool human_readable) const {
  if (!human_readable) {
    return std::to_string(operator()());
  }

  size_t div_size{size}, prev_div_size{0u};
  const char suffixes[]{'K', 'M', 'G', 'T'};
  std::int8_t suffix{-1};

  while (0u != div_size) {
    prev_div_size = div_size;
    div_size /= 1024u;
    ++suffix;
  }

  if (0 == suffix || -1 == suffix) {
    return std::to_string(size);
  }

  return std::to_string(prev_div_size) + suffixes[suffix - 1];
}