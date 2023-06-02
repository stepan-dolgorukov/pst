#include <unistd.h>
#include <string>
#include "argparser.hxx"
#include "args.hxx"
#include <iostream>

myls::argparser::argparser(int nargs, char* argv[])
  : raw_args{nargs, argv} {

  parse_actions();
  parse_directory();
};

myls::mode myls::argparser::operator()(void) {
  return myls::mode(mask, directory);
};

void myls::argparser::parse_actions(void) {
  signed raw_arg{};

  while (-1 != (raw_arg = getopt(raw_args.amount, raw_args.values, arg_format.c_str()))) {
    myls::arguments arg{static_cast<myls::arguments>(raw_arg)};

    switch (arg) {
      case myls::arguments::long_listing:
      case myls::arguments::reverse_listing:
      case myls::arguments::human_readable_size:
        mask.set(arg);
        break;

      default:
        // THINK
        break;
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