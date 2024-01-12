#ifndef FILE_PERM_HXX
#define FILE_PERM_HXX

#include <cstdint>
#include <string>
#include <sys/stat.h>
#include <unordered_map>

namespace myls {
  class file_perm;
  enum class permissions : std::uint16_t;
}

enum class myls::permissions : std::uint16_t {
  owner_read = 0x100u,
  owner_write = 0x80u,
  owner_execute = 0x40u,

  group_read = 0x20u,
  group_write = 0x10u,
  group_execute = 0x8u,

  other_read = 0x4u,
  other_write = 0x2u,
  other_execute = 0x1u
};


class myls::file_perm {
  std::uint16_t perms : 9u;
  std::string name{};

  std::unordered_map<myls::permissions, unsigned> protection_bits{
    {myls::permissions::owner_read, S_IRUSR},
    {myls::permissions::owner_write, S_IWUSR},
    {myls::permissions::owner_execute, S_IXUSR},

    {myls::permissions::group_read, S_IRGRP},
    {myls::permissions::group_write, S_IWGRP},
    {myls::permissions::group_execute, S_IXGRP},

    {myls::permissions::other_read, S_IROTH},
    {myls::permissions::other_write, S_IWOTH},
    {myls::permissions::other_execute, S_IXOTH}
  };

  using sys_stat = struct stat;
  sys_stat stat{};

  void fill_permissions(void);
  bool permission(myls::permissions perm) const;

  template<typename Output>
  friend Output& operator<<(Output& out, const myls::file_perm& fp);

 public:
  file_perm(const std::string& name);

  bool can_owner_read(void) const;
  bool can_owner_write(void) const;
  bool can_owner_execute(void) const;

  bool can_group_read(void) const;
  bool can_group_write(void) const;
  bool can_group_execute(void) const;

  bool can_other_read(void) const;
  bool can_other_write(void) const;
  bool can_other_execute(void) const;

  operator std::string() const;
  std::string operator()() const;
};

template<typename Output>
Output& myls::operator<<(Output& out, const myls::file_perm& fp) {
  return out << fp();
}

#endif