#include "file_info.hxx"
#include "file_perm.hxx"

myls::file_info::file_info(const std::string& name) : info{name} {
}

auto myls::file_info::operator()(void) -> decltype(info) {
  return info;
}