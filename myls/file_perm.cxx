#include "file_perm.hxx"
#include <sys/stat.h>
#include <iostream>
#include <utility>

myls::file_perm::file_perm(const std::string& name)
    : perms{0b000'000'000u}, name{name} {

  int error_status{::stat(name.c_str(), &stat)};
  fill_permissions();
}

void myls::file_perm::fill_permissions(void) {
  for (std::pair<myls::permissions, int> perm_protbits : protection_bits) {
    auto perm{perm_protbits.first};
    auto protbits{perm_protbits.second};

    if (protbits == (protbits & stat.st_mode)) {
      perms |= static_cast<decltype(perms)>(perm);
    }
  }
}

bool myls::file_perm::permission(myls::permissions perm) {
  using perms_type = decltype(perms);
  perms_type num_perm{static_cast<perms_type>(perm)};

  return num_perm == (perms & num_perm);
}

bool myls::file_perm::can_owner_read(void) {
  return permission(myls::permissions::owner_read);
}

bool myls::file_perm::can_owner_write(void) {
  return permission(myls::permissions::owner_write);
}

bool myls::file_perm::can_owner_execute(void) {
  return permission(myls::permissions::owner_execute);
}

bool myls::file_perm::can_group_read(void) {
  return permission(myls::permissions::group_read);
}

bool myls::file_perm::can_group_write(void) {
  return permission(myls::permissions::group_write);
}

bool myls::file_perm::can_group_execute(void) {
  return permission(myls::permissions::group_execute);
}

bool myls::file_perm::can_other_read(void) {
  return permission(myls::permissions::other_read);
}

bool myls::file_perm::can_other_write(void) {
  return permission(myls::permissions::other_write);
}

bool myls::file_perm::can_other_execute(void) {
  return permission(myls::permissions::other_execute);
}