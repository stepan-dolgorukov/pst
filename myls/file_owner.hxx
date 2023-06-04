#ifndef FILE_OWNER_HXX
#define FILE_OWNER_HXX

#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
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

  template<typename Output>
  friend Output& operator<<(Output& out, myls::file_owner fo) {
    const std::string
      user_name{getpwuid(fo.owners.user)->pw_name},
      group_name{getgrgid(fo.owners.group)->gr_name};

    return out << user_name << ' ' << group_name;
  }

 public:
  file_owner(const std::string& name);
  decltype(owners) operator()(void) const;
};

#endif