#ifndef MODE_HXX
#define MODE_HXX

#include <cstdint>

namespace myls {
  class mode;
}

class myls::mode {
  std::uint8_t mask: 3u;

  template<typename Output>
  friend Output& operator<<(Output& out, myls::mode mode) {
    out << "Long listing: " << mode.has_long_listing() << '\n' <<
      "Reverse: " << mode.has_reverse_listing() << '\n' <<
      "Human readable size: " << mode.has_human_size();

    return out;
  }

  public:
    mode(std::uint8_t mode_mask);
    bool has_long_listing(void);
    bool has_reverse_listing(void);
    bool has_human_size(void);
};

#endif