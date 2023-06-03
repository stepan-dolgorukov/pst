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
  friend Output& operator<<(Output& out, myls::file_modif_time modif_time) {
    decltype(modif_time()) time{modif_time()};
    char output_mod_time[64u]{'\0'};

    std::strftime(std::data(output_mod_time), std::size(output_mod_time),
                  "%b %e %H:%M", std::localtime(&time));
    return out << output_mod_time;
  }

 public:
  file_modif_time(const std::string& name);
  decltype(time) operator()(void);
};

#endif