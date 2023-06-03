#include "file_owner.hxx"

myls::file_owner::file_owner(const std::string& name) {
  int error_status{::stat(name.c_str(), &stat)};

  fill_user_owner();
  fill_group_owner();
}

void myls::file_owner::fill_user_owner(void) {
  owners.user = stat.st_uid;
}

void myls::file_owner::fill_group_owner(void) {
  owners.group = stat.st_gid;
}

auto myls::file_owner::operator()(void) -> decltype(owners) {
  return owners;
}