#ifndef FILE_INFO_HXX
#define FILE_INFO_HXX

#include "file_hlinks_amnt.hxx"
#include "file_modif_time.hxx"
#include "file_owner.hxx"
#include "file_perm.hxx"
#include "file_size.hxx"
#include "file_type.hxx"

namespace myls {
  class file_info;
}

class myls::file_info {
  struct info {
    myls::file_type type;
    myls::file_perm permissions;
    myls::file_hlinks_amnt nhlinks;
    myls::file_owner owners;
    myls::file_size size;
    myls::file_modif_time mod_time;
    std::string name;

    info(const std::string& name)
      : type{name},
        permissions{name},
        nhlinks{name},
        owners{name},
        size{name},
        mod_time{name},
        name{name} {
    }
  } info;

  template<typename Output>
  friend Output& operator<<(Output& out, myls::file_info fi) {
    return out <<
      fi.info.type <<
      fi.info.permissions <<
      ' ' <<
      fi.info.nhlinks <<
      ' ' <<
      fi.info.owners <<
      ' ' <<
      fi.info.size <<
      ' ' <<
      fi.info.mod_time <<
      ' ' <<
      fi.info.name;
  }

  public:
  file_info(const std::string& name);
  decltype(info) operator()(void);
};

#endif