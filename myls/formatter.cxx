#include "formatter.hxx"
#include <array>
#include <cstddef>

myls::formatter::formatter(const std::vector<myls::file_info>& info, bool human_readable_size)
    : info{info}, human_readable_size{human_readable_size} {
}

std::vector<std::string> myls::formatter::operator()(void) {
  std::vector<std::string> formatted{};

  for (auto& fi : info) {
    size_max_length = std::max(size_max_length,
      fi().size(human_readable_size).length());

    nlinks_max_length = std::max(nlinks_max_length,
      std::to_string(fi().nhlinks()).length());
  }

  for (auto& fi : info) {
    formatted.push_back(format(fi));
  }

  return formatted;
}

std::string myls::formatter::format(myls::file_info& fi) {
  std::string formatted(512u, '\0'), format{get_format_string()};

  auto info{fi()};
  auto owners{info.owners()};

  const std::string
    user_name{getpwuid(owners.user)->pw_name},
    group_name{getgrgid(owners.group)->gr_name};

  std::sprintf(formatted.data(), format.c_str(),
    info.type(),
    info.permissions().c_str(),
    info.nhlinks(),
    user_name.c_str(),
    group_name.c_str(),
    info.size(human_readable_size).c_str(),
    static_cast<std::string>(info.mod_time).c_str(),
    info.name.c_str());

  return formatted;
}

std::string myls::formatter::get_format_string(void) {
  std::string format{
    "%c%s %" +
    std::to_string(nlinks_max_length) +
    "lu " +
    "%s %s %" +
    std::to_string(size_max_length) +
    "s %s %s"
  };

  return format;
}