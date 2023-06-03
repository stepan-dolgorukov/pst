#ifndef FILE_OWNER_HXX
#define FILE_OWNER_HXX

#include <sys/stat.h>
#include <string>

namespace myls {
  class file_owner;
}

class myls::file_owner {
  struct {
    uid_t user{};
    gid_t group{};
  } owners;

  using sys_stat = struct stat;
  sys_stat stat{};

  void fill_user_owner(void);
  void fill_group_owner(void);

 public:
  file_owner(const std::string& name);
  decltype(owners) operator()(void);
};

#endif