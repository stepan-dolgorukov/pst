#ifndef FORMATTER_HXX
#define FORMATTER_HXX

#include "file_info.hxx"
#include <vector>
#include <pwd.h>
#include <grp.h>
#include "mode.hxx"

namespace myls {
  class formatter;
}

class myls::formatter {
  std::size_t size_max_length{};
  std::size_t nlinks_max_length{};
  bool name_with_space{};
  bool has_human_size{};

  std::vector<myls::file_info> info;

  std::string get_format_string(void);
  std::string format(myls::file_info& fi);
  std::string prepare(const std::string& name);

  public:
  formatter(const std::vector<myls::file_info>& info, bool has_human_size);
  std::vector<std::string> operator()(void);
};

#endif