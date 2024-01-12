#include "file_type.hxx"
#include <sys/types.h>

myls::file_type::file_type(const std::string& name) : type{myls::file_types::regular} {
  int error{::stat(name.c_str(), &stat)};
  fill_type();
};

void myls::file_type::fill_type(void) {
  if (0 != S_ISDIR(stat.st_mode)) {
    type = myls::file_types::directory;
    return;
  }

  if (0 != S_ISCHR(stat.st_mode)) {
    type = myls::file_types::character;
    return;
  }

  if (0 != S_ISBLK(stat.st_mode)) {
    type = myls::file_types::block;
    return;
  }

  if (0 != S_ISREG(stat.st_mode)) {
    type = myls::file_types::regular;
    return;
  }

  if (0 != S_ISFIFO(stat.st_mode)) {
    type = myls::file_types::fifo;
    return;
  }

  if (0 != S_ISLNK(stat.st_mode)) {
    type = myls::file_types::symbolic_link;
    return;
  }

  if (0 != S_ISSOCK(stat.st_mode)) {
    type = myls::file_types::socket;
    return;
  }
}


char myls::file_type::operator()(void) const {
  switch (type) {
    case myls::file_types::directory:
      return 'd';

    case myls::file_types::character:
      return 'c';

    case myls::file_types::block:
      return 'b';

    case myls::file_types::regular:
      return '-';

    case myls::file_types::fifo:
      return 'p';

    case myls::file_types::symbolic_link:
      return 'l';

    case myls::file_types::socket:
      return 's';
  }

  return '\0';
}