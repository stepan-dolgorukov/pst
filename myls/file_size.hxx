#ifndef FILE_SIZE_HXX
#define FILE_SIZE_HXX

#include <cstddef>
#include <string>
#include <sys/stat.h>

namespace myls {
  class file_size;
}

class myls::file_size {
  std::size_t size{0u};

  using sys_stat = struct stat;
  sys_stat stat{};

  void fill_size(void);

  template<typename Output>
  friend Output& operator<<(Output& out, const myls::file_size& fs) {
    return out << fs();
  }

 public:
  file_size(const std::string& name);
  std::size_t operator()(void) const;
  std::string operator()(bool human_readable) const;
};

#endif