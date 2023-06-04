#include "file_perm.hxx"
#include <sys/stat.h>
#include <iostream>
#include <utility>

myls::file_perm::file_perm(const std::string& name)
    : perms{0b000000000u}, name{name} {

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

bool myls::file_perm::permission(myls::permissions perm) const {
  using perms_type = decltype(perms);
  perms_type num_perm{static_cast<perms_type>(perm)};

  return num_perm == (perms & num_perm);
}

bool myls::file_perm::can_owner_read(void) const {
  return permission(myls::permissions::owner_read);
}

bool myls::file_perm::can_owner_write(void) const {
  return permission(myls::permissions::owner_write);
}

bool myls::file_perm::can_owner_execute(void) const {
  return permission(myls::permissions::owner_execute);
}

bool myls::file_perm::can_group_read(void) const {
  return permission(myls::permissions::group_read);
}

bool myls::file_perm::can_group_write(void) const {
  return permission(myls::permissions::group_write);
}

bool myls::file_perm::can_group_execute(void) const {
  return permission(myls::permissions::group_execute);
}

bool myls::file_perm::can_other_read(void) const {
  return permission(myls::permissions::other_read);
}

bool myls::file_perm::can_other_write(void) const {
  return permission(myls::permissions::other_write);
}

bool myls::file_perm::can_other_execute(void) const {
  return permission(myls::permissions::other_execute);
}

myls::file_perm::operator std::string(void) const {
  std::string perms{"---------"};

  if (can_owner_read()) {
    perms.at(0) = 'r';
  }

  if (can_owner_write()) {
    perms.at(1) = 'w';
  }

  if (can_owner_execute()) {
    perms.at(2) = 'x';
  }

  if (can_group_read()) {
    perms.at(3) = 'r';
  }

  if (can_group_write()) {
    perms.at(4) = 'w';
  }

  if (can_group_execute()) {
    perms.at(5) = 'x';
  }

  if (can_other_read()) {
    perms.at(6) = 'r';
  }

  if (can_other_write()) {
    perms.at(7) = 'w';
  }

  if (can_other_execute()) {
    perms.at(8) = 'x';
  }

  return perms;
};

std::string myls::file_perm::operator()(void) const {
  return static_cast<std::string>(*this);
}