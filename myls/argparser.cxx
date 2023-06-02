#include <unistd.h>
#include <string>
#include "argparser.hxx"
#include "args.hxx"
#include <iostream>

myls::argparser::argparser(int nargs, char* argv[]) {
  signed raw_arg{};

  while (-1 != (raw_arg = getopt(nargs, argv, arg_format.c_str()))) {
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

  if (1 != nargs) {
    int last{nargs - 1};

    if ('-' != argv[last][0]) {
      directory = argv[last];
    }
  }
};

myls::mode myls::argparser::operator()(void) {
  return myls::mode(mask, directory);
};