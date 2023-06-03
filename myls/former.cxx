#include "former.hxx"
#include "file_info.hxx"
#include <algorithm>
#include <dirent.h>
#include <exception>
#include <system_error>

myls::former::former(const myls::mode& mode) : mode{mode} {
}

std::vector<myls::file_info> myls::former::operator()(void) {
  DIR* directory{opendir(mode.get_directory().c_str())};
  struct dirent* directory_entry{};

  if (nullptr == directory) {
    throw "Не удалось открыть каталог " + mode.get_directory();
  }

  std::vector<myls::file_info> info{};
  std::vector<std::string> file_names{};

  while (nullptr != (directory_entry = readdir(directory))) {
    file_names.emplace_back(directory_entry->d_name);
  }

  if (mode.has_reverse_listing()) {
    std::sort(file_names.begin(), file_names.end(),
      std::greater_equal<std::string>{});
  }

  else {
    std::sort(file_names.begin(), file_names.end(),
      std::less_equal<std::string>{});
  }

  for (auto& name : file_names) {
    info.emplace_back(mode.get_directory(), name, mode.has_human_size());
  }

  return info;
}