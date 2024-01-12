#ifndef ARGPARSER_HXX
#define ARGPARSER_HXX

#include <string>
#include "options.hxx"
#include "options_storage.hxx"
#include "mode.hxx"
#include <vector>

namespace myls {
  class argparser;
}

class myls::argparser {
  std::string arg_format{"lrh"};
  myls::options_storage mask{};
  std::string directory{"."};

  struct {
    int amount;
    char** values;
  } raw_args;

  void parse_actions(void);
  void parse_directory(void);

 public:
  argparser(int nargs, char* argv[]);
  myls::mode operator()(void) const;

};

#endif