#include "formatter.hxx"
#include <array>
#include <cstddef>

myls::formatter::formatter(const std::vector<myls::file_info>& info, const myls::mode& mode)
    : info{info}, mode{mode} {
}

std::vector<std::string> myls::formatter::operator()(void) {
  std::vector<std::string> formatted{};

  for (auto& fi : info) {
    size_max_length = std::max(size_max_length,
      fi().size(mode.has_human_size()).length());

    nlinks_max_length = std::max(nlinks_max_length,
      std::to_string(fi().nhlinks()).length());

    if (std::string::npos != fi().name.find(' ')) {
      name_with_space = true;
    }
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
    info.size(mode.has_human_size()).c_str(),
    static_cast<std::string>(info.mod_time).c_str(),
    prepare(info.name).c_str());

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

std::string myls::formatter::prepare(const std::string& name) {
  if (std::string::npos != name.find(' ')) {
    return '\'' + name + '\'';
  }

  if (name_with_space) {
    return ' ' + name;
  }

  return name;
}