#include "formatter.hxx"
#include <array>

myls::formatter::formatter(const std::vector<myls::file_info>& info, bool has_human_size)
    : has_human_size{has_human_size}, info{info}  {
}

std::vector<std::string> myls::formatter::operator()(void) {
  std::vector<std::string> formatted{};

  for (auto& fi : info) {
    size_max_length = std::max(size_max_length,
      fi().size(has_human_size).length());

    nlinks_max_length = std::max(nlinks_max_length,
      std::to_string(fi().nhlinks()).length());

    if (!name_with_space && std::string::npos != fi().name.find(' ')) {
      name_with_space = true;
    }
  }

  for (auto& fi : info) {
    formatted.push_back(format(fi));
  }

  return formatted;
}

std::string myls::formatter::format(const myls::file_info& fi) {
  std::array<char, 512u> arr_formatted{};
  const std::string format{get_format_string()};

  const auto info{fi()};
  const auto owners{info.owners()};

  const std::string
    user_name{getpwuid(owners.user)->pw_name},
    group_name{getgrgid(owners.group)->gr_name};

  std::sprintf(arr_formatted.data(), format.c_str(),
    info.type(),
    info.permissions().c_str(),
    info.nhlinks(),
    user_name.c_str(),
    group_name.c_str(),
    info.size(has_human_size).c_str(),
    static_cast<std::string>(info.mod_time).c_str(),
    prepare(info.name).c_str());

  return to_string(arr_formatted);
}

std::string myls::formatter::get_format_string(void) const {
  const std::string format{
     // Тип
    "%c"

    // Права доступа
    "%s"

    // Пробел
    " "

    // Количество hard-ссылок
    "%" + std::to_string(nlinks_max_length) + "lu" +

    // Пробел
    " "

    // Пользователь-владелец
    "%s"

    // Пробел
    " "

    // Группа владелец
    "%s"

    // Пробел
    " "

    // Размер
    "%" + std::to_string(size_max_length) + "s"

    // Пробел
    " "

    // Время изменения
    "%s"

    // Пробел
    " "

    // Имя
    "%s"
  };

  return format;
}

std::string myls::formatter::prepare(const std::string& name) const {
  if (std::string::npos != name.find(' ')) {
    return '\'' + name + '\'';
  }

  if (name_with_space) {
    return ' ' + name;
  }

  return name;
}

template<typename Array>
std::string myls::formatter::to_string(const Array& chars) {
  std::string str{};

  for (auto ch: chars) {
    if ('\0' == ch) {
      break;
    }

    str += ch;
  }

  return str;
}