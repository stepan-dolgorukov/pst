#ifndef FORMATTER_HXX
#define FORMATTER_HXX

#include "file_info.hxx"
#include <vector>
#include <pwd.h>
#include <grp.h>
#include "mode.hxx"
#include <array>

namespace myls {
  class formatter;
}

class myls::formatter {
  std::size_t size_max_length{};
  std::size_t nlinks_max_length{};
  bool name_with_space{};
  bool has_human_size{};

  std::vector<myls::file_info> info;

  std::string get_format_string(void) const;
  std::string format(const myls::file_info& fi);
  std::string prepare(const std::string& name) const;

  template<typename Array>
  std::string to_string(const Array& chars);

  public:
  formatter(const std::vector<myls::file_info>& info, bool has_human_size);
  std::vector<std::string> operator()(void);
};

#endif