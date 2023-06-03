#include "file_perm.hxx"
#include <sys/stat.h>
#include <iostream>

myls::file_perm::file_perm(const std::string& name)
    : perms{0b000'000'000u}, name{name} {

  int error_status{::stat(name.c_str(), &stat)};

  fill_owner_mask();
  fill_group_mask();
  fill_other_mask();
}

void myls::file_perm::fill_owner_mask(void) {
  if (S_IRUSR == (S_IRUSR & stat.st_mode)) {
    perms |= static_cast<std::uint16_t>(myls::permissions::owner_read);
  }

  if (S_IWUSR == (S_IWUSR & stat.st_mode)) {
    perms |= static_cast<std::uint16_t>(myls::permissions::owner_write);
  }

  if (S_IXUSR == (S_IXUSR & stat.st_mode)) {
    perms |= static_cast<std::uint16_t>(myls::permissions::owner_execute);
  }
}

void myls::file_perm::fill_group_mask(void) {

}

void myls::file_perm::fill_other_mask(void) {

}