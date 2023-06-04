#include "file_modif_time.hxx"

myls::file_modif_time::file_modif_time(const std::string& name) {
  int error_status{::stat(name.c_str(), &stat)};
  fill_time();
}

void myls::file_modif_time::fill_time(void) {
  time = stat.st_mtime;
}

auto myls::file_modif_time::operator()(void) -> decltype(time) {
  return time;
}

myls::file_modif_time::operator std::string() {
  auto time{operator()()};
  char output_mod_time[64u]{'\0'};

  std::strftime(std::data(output_mod_time), std::size(output_mod_time),
                "%b %e %H:%M", std::localtime(&time));
  return output_mod_time;
}