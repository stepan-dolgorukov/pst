#ifndef FILE_TYPE_HXX
#define FILE_TYPE_HXX

#include <cstdint>
#include <string>
#include <sys/stat.h>
#include <unordered_map>

namespace myls {
  class file_type;

  enum class file_types : std::uint8_t {
    directory = 0b0000001u,
    character = 0b0000010u,
    block = 0b0000100u,
    regular = 0b0001000u,
    fifo = 0b0010000u,
    symbolic_link = 0b0100000u,
    socket = 0b1000000u
  };
}

class myls::file_type {
  file_types type: 7u;

  using sys_stat = struct stat;
  sys_stat stat{};

  void fill_type(void);

  template<typename Output>
  friend Output& operator<<(Output& out, myls::file_type type);

 public:
  file_type(const std::string& name);

  char operator()(void) const;
};

template<typename Output>
Output& myls::operator<<(Output& out, myls::file_type type) {
  return out << type();
}

#endif