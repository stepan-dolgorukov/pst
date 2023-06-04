#include "options.hxx"
#include "option_mask.hxx"
#include "mode.hxx"

myls::mode::mode(const myls::option_mask mask, const std::string& directory) :
  mask{mask},
  directory{directory} {
}

bool myls::mode::has_long_listing() const {
  return mask.get(myls::options::long_listing);
}

bool myls::mode::has_reverse_listing() const {
  return mask.get(myls::options::reverse_listing);
}

bool myls::mode::has_human_size() const {
  return mask.get(myls::options::human_readable_size);
}

std::string myls::mode::get_directory(void) const {
  return directory;
}