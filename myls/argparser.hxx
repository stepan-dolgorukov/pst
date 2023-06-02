#ifndef ARGPARSER_HXX
#define ARGPARSER_HXX

#include <string>
#include "mode.hxx"
#include "mode_mask.hxx"

namespace myls {
  class argparser;
}

class myls::argparser {
  std::string arg_format{"lrh"};
  myls::mode_mask mask{};

 public:
  argparser(int nargs, char* argv[]);
  myls::mode operator()(void);
};

#endif