#ifndef FILE_TYPE_HXX
#define FILE_TYPE_HXX

#include <cstdint>
#include <string>
#include <sys/stat.h>

namespace myls {
  class file_type;

  enum class file_types : std::uint8_t {
    directory = 0x1u,
    character = 0x2u,
    block = 0x4u,
    regular = 0x8u,
    fifo = 0x10u,
    symbolic_link = 0x20u,
    socket = 0x40u
  };
}

class myls::file_type {
  file_types type: 7u;

  using sys_stat = struct stat;
  sys_stat stat{};

  void fill_type(void);

  template<typename Output>
  friend Output& operator<<(Output& out, const myls::file_type& type);

 public:
  file_type(const std::string& name);

  char operator()(void) const;
};

template<typename Output>
Output& myls::operator<<(Output& out, const myls::file_type& type) {
  return out << type();
}

#endif