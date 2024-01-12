#ifndef FILE_MODIF_TIME_HXX
#define FILE_MODIF_TIME_HXX

#include <ctime>
#include <string>
#include <sys/stat.h>

namespace myls {
  class file_modif_time;
}

class myls::file_modif_time {
  std::time_t time{};

  using sys_stat = struct stat;
  sys_stat stat{};

  void fill_time(void);

  template<typename Output>
  friend Output& operator<<(Output& out, const myls::file_modif_time& modif_time) {
    return out << static_cast<std::string>(modif_time);
  }

 public:
  file_modif_time(const std::string& name);
  decltype(time) operator()(void) const;
  operator std::string(void) const;
};

#endif