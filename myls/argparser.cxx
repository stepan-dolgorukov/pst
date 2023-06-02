#include <unistd.h>
#include <string>
#include "argparser.hxx"
#include "args.hxx"

myls::argparser::argparser(int nargs, char* argv[]) {
  signed raw_arg{};

  while (-1 != (raw_arg = getopt(nargs, argv, arg_format.c_str()))) {
    myls::arguments arg{static_cast<myls::arguments>(raw_arg)};

    switch (arg) {
      case myls::arguments::long_listing:
        mask.set(myls::arguments::long_listing);
        break;

      case myls::arguments::reverse_listing:
        mask.set(myls::arguments::reverse_listing);
        break;

      case myls::arguments::human_readable_size:
        mask.set(myls::arguments::human_readable_size);
        break;

      default:
        // THINK
        break;
    };
  }
};

myls::mode myls::argparser::operator()(void) {
  return myls::mode(mask);
};