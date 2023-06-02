#ifndef ARGS_HXX
#define ARGS_HXX

namespace myls {
  enum class arguments : char;
}

enum class myls::arguments : char {
  long_listing = 'l',
  reverse_listing = 'r',
  human_readable_size = 'h',
};

#endif