#ifndef ARGS_HXX
#define ARGS_HXX

namespace myls {
  enum class options : char;
}

enum class myls::options : char {
  long_listing = 'l',
  reverse_listing = 'r',
  human_readable_size = 'h',
};

#endif