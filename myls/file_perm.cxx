#include "file_perm.hxx"
#include <sys/stat.h>
#include <iostream>
#include <utility>

myls::file_perm::file_perm(const std::string& name)
    : perms{0b000'000'000u}, name{name} {

  int error_status{::stat(name.c_str(), &stat)};
  fill_permissions();
  std::cout << std::hex << perms;
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