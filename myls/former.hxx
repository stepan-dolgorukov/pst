#ifndef FORMER_HXX
#define FORMER_HXX

#include "file_info.hxx"
#include "mode.hxx"

#include <vector>

namespace myls {
  class former;
}

class myls::former {
  myls::mode mode;

  std::vector<std::string> file_names(void);

 public:
  former(const myls::mode& mode);

  operator std::vector<myls::file_info>(void);
  operator std::vector<std::string>(void);
};

#endif