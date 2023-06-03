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