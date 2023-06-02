#ifndef ARGPARSER_HXX
#define ARGPARSER_HXX

#include "args.hxx"
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>
#include "mode.hxx"

namespace myls {
  class argparser;
}

class myls::argparser {
  std::string arg_format{"lrh"};
  std::uint8_t mode_mask: 3u;

  std::unordered_map<myls::arguments, std::uint8_t> arg_mask{
    {myls::arguments::long_listing, 0b100u},
    {myls::arguments::reverse_listing, 0b010u},
    {myls::arguments::human_readable_size, 0b001u}
  };

 public:
  argparser(int nargs, char* argv[]);
  myls::mode operator()(void);
};

#endif