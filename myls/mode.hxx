#ifndef MODE_HXX
#define MODE_HXX

#include <cstdint>
#include "mode_mask.hxx"
#include <string>

namespace myls {
  class mode;
}

class myls::mode {
  myls::mode_mask mask{};
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
    mode(myls::mode_mask mask, const std::string& directory);
    bool has_long_listing(void);
    bool has_reverse_listing(void);
    bool has_human_size(void);
    std::string get_directory(void);
};

#endif