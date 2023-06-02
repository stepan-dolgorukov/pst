#ifndef MODE_MASK_HXX
#define MODE_MASK_HXX

#include <cstdint>
#include <unordered_map>
#include "args.hxx"

namespace myls {
  class option_mask;
}

class myls::option_mask {
  std::uint8_t mask: 3u;

  std::unordered_map<myls::arguments, std::uint8_t> arg_mask{
    {myls::arguments::long_listing, 0b100u},
    {myls::arguments::reverse_listing, 0b010u},
    {myls::arguments::human_readable_size, 0b001u}
  };

  public:
    option_mask(void);
    void set(myls::arguments arg);
    bool get(myls::arguments arg);
};

#endif