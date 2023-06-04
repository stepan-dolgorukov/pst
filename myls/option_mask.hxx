#ifndef MODE_MASK_HXX
#define MODE_MASK_HXX

#include <cstdint>
#include <unordered_map>

#include "options.hxx"

namespace myls {
  class option_mask;
}

class myls::option_mask {
  std::uint8_t mask: 3u;

  std::unordered_map<myls::options, std::uint8_t> arg_mask{
    {myls::options::long_listing, 0x4u},
    {myls::options::reverse_listing, 0x2u},
    {myls::options::human_readable_size, 0x1u}
  };

  public:
    option_mask(void);
    void set(myls::options arg);
    bool get(myls::options arg) const;
};

#endif