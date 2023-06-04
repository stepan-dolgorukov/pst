#ifndef MODE_HXX
#define MODE_HXX

#include <cstdint>
#include "option_mask.hxx"
#include <string>

namespace myls {
  class mode;
}

class myls::mode {
  myls::option_mask mask{};
  std::string directory{"."};

  template<typename Output>
  friend Output& operator<<(Output& out, myls::mode mode) {
    out << "Long listing: " << mode.has_long_listing() << '\n' <<
      "Reverse: " << mode.has_reverse_listing() << '\n' <<
      "Human readable size: " << mode.has_human_size() << '\n' <<
      "Directory: " << mode.get_directory();

    return out;
  }

  public:
    mode(myls::option_mask mask, const std::string& directory);
    bool has_long_listing(void) const;
    bool has_reverse_listing(void) const;
    bool has_human_size(void) const;
    std::string get_directory(void) const;
};

#endif