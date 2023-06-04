#ifndef FILE_HLINKS_AMNT_HXX
#define FILE_HLINKS_AMNT_HXX

#include <cstddef>
#include <string>
#include <sys/stat.h>

namespace myls {
  class file_hlinks_amnt;
}

class myls::file_hlinks_amnt {
  std::size_t amount{0u};

  using sys_stat = struct stat;
  sys_stat stat{};

  void fill_amount(void);

  template<typename Output>
  friend Output& operator<<(Output& out, const myls::file_hlinks_amnt& fha) {
    return out << fha();
  }

 public:
  file_hlinks_amnt(const std::string& name);
  std::size_t operator()(void) const;
};

#endif