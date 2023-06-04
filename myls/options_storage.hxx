#ifndef OPTIONS_STORAGE_HXX
#define OPTIONS_STORAGE_HXX

#include <cstdint>
#include <unordered_map>

#include "options.hxx"

namespace myls {
  class options_storage;
}

class myls::options_storage {
  std::uint8_t storage: 3u;

  std::unordered_map<myls::options, std::uint8_t> arg_mask{
    {myls::options::long_listing, 0x4u},
    {myls::options::reverse_listing, 0x2u},
    {myls::options::human_readable_size, 0x1u}
  };

  public:
    options_storage(void);
    void set(myls::options arg);
    bool get(myls::options arg) const;
};

#endif