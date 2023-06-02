#include <unistd.h>
#include <string>
#include "argparser.hxx"
#include "args.hxx"

myls::argparser::argparser(int nargs, char* argv[]): mode_mask{0b000u} {
  signed raw_arg{};

  while (-1 != (raw_arg = getopt(nargs, argv, arg_format.c_str()))) {
    myls::arguments arg{static_cast<myls::arguments>(raw_arg)};

    switch (arg) {
      case myls::arguments::long_listing:
        mode_mask |= arg_mask.at(myls::arguments::long_listing);
        break;

      case myls::arguments::reverse_listing:
        mode_mask |= arg_mask.at(myls::arguments::reverse_listing);
        break;

      case myls::arguments::human_readable_size:
        mode_mask |= arg_mask.at(myls::arguments::human_readable_size);
        break;

      default:
        // THINK
        break;
    };
  }
};

myls::mode myls::argparser::operator()(void) {
  return myls::mode(mode_mask);
};