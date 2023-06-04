#include "former.hxx"
#include "file_info.hxx"
#include <algorithm>
#include <bits/types/FILE.h>
#include <dirent.h>
#include <exception>
#include <system_error>

myls::former::former(const myls::mode& mode) : mode{mode} {
}

myls::former::operator std::vector<myls::file_info>(void) {
  std::vector<myls::file_info> info{};

  for (auto& name : file_names()) {
    info.emplace_back(mode.get_directory(), name, mode.has_human_size());
  }

  return info;
}

std::vector<std::string> myls::former::file_names(void) {
  DIR* directory{opendir(mode.get_directory().c_str())};
  struct dirent* directory_entry{};

  if (nullptr == directory) {
    throw "Не удалось открыть каталог " + mode.get_directory();
  }

  std::vector<std::string> file_names{};

  while (nullptr != (directory_entry = readdir(directory))) {
    const std::string name{directory_entry->d_name};

    if ("." != name && ".." != name) {
      file_names.emplace_back(name);
    }
  }

  if (mode.has_reverse_listing()) {
    std::sort(file_names.begin(), file_names.end(),
      std::greater_equal<std::string>{});
  }

  else {
    std::sort(file_names.begin(), file_names.end(),
      std::less_equal<std::string>{});
  }

  return file_names;
}

myls::former::operator std::vector<std::string>() {
  return file_names();
}