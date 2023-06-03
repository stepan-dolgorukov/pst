#include "file_info.hxx"
#include "file_perm.hxx"

myls::file_info::file_info(const std::string& directory_name,
                           const std::string& file_name,
                           bool human_readable_size)
    : human_readable_size{human_readable_size},
      info{directory_name, file_name} {
}

auto myls::file_info::operator()(void) -> decltype(info) {
  return info;
}