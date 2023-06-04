#include <stdexcept>
#include <unistd.h>
#include <string>
#include "argparser.hxx"
#include <iostream>

myls::argparser::argparser(int nargs, char* argv[])
  : raw_args{nargs, argv} {

  parse_actions();
  parse_directory();
};

myls::mode myls::argparser::operator()(void) const {
  return myls::mode(mask, directory);
};

void myls::argparser::parse_actions(void) {
  signed raw_arg{};

  // Выключение стандартных сообщений при парсинге
  opterr = 0;

  while (-1 != (raw_arg = getopt(raw_args.amount, raw_args.values, arg_format.c_str()))) {

    switch (raw_arg) {
      case static_cast<signed>(myls::options::long_listing):
      case static_cast<signed>(myls::options::reverse_listing):
      case static_cast<signed>(myls::options::human_readable_size):
        mask.set(static_cast<myls::options>(raw_arg));
        break;

      case '?':
        std::string message{"Неизвестный ключ "};
        message += '"';
        message += optopt;
        message += '"';

        throw std::invalid_argument{message};
    };
  }
}

void myls::argparser::parse_directory(void) {
  if (1 != raw_args.amount) {
    int last{raw_args.amount- 1};

    if ('-' != raw_args.values[last][0]) {
      directory = raw_args.values[last];
    }
  }
}