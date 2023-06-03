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
  owner_read = 0b100'000'000u,
  owner_write = 0b010'000'000u,
  owner_execute = 0b001'000'000u,

  group_read = 0b000'100'000u,
  group_write = 0b000'010'000u,
  group_execute = 0b000'001'000u,

  other_read = 0b000'000'100u,
  other_write = 0b000'000'010u,
  other_execute = 0b000'000'001u
};


class myls::file_perm {
  std::uint16_t perms : 9u;
  std::string name{};

  std::unordered_map<myls::permissions, int> protection_bits{
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

 public:
  file_perm(const std::string& name);
};

#endif