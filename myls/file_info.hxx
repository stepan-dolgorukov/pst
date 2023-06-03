#ifndef FILE_INFO_HXX
#define FILE_INFO_HXX

#include "file_hlinks_amnt.hxx"
#include "file_modif_time.hxx"
#include "file_owner.hxx"
#include "file_perm.hxx"
#include "file_size.hxx"
#include "file_type.hxx"
#include <iomanip>
#include <iostream>

namespace myls {
  class file_info;
}

class myls::file_info {
  bool human_readable_size{};
  struct info {
    myls::file_type type;
    myls::file_perm permissions;
    myls::file_hlinks_amnt nhlinks;
    myls::file_owner owners;
    myls::file_size size;
    myls::file_modif_time mod_time;
    std::string name;

    info(const std::string& directory_name, const std::string& file_name)
      : type{directory_name + '/' + file_name},
        permissions{directory_name + '/' + file_name},
        nhlinks{directory_name + '/' + file_name},
        owners{directory_name + '/' + file_name},
        size{directory_name + '/' + file_name},
        mod_time{directory_name + '/' + file_name},
        name{file_name} {
    }
  } info;

  template<typename Output>
  friend Output& operator<<(Output& out, myls::file_info fi) {
    auto quot_if_has_spaces{[](const std::string& name){
      if (name.npos != name.find(' ')) {
        return '\'' + name + '\'';
      }

      return name;
    }};

    return out <<
      fi.info.type <<
      fi.info.permissions <<
      ' ' <<
      fi.info.nhlinks <<
      ' ' <<
      fi.info.owners <<
      ' ' <<
      fi.info.size(fi.human_readable_size) <<
      ' ' <<
      fi.info.mod_time <<
      ' ' <<
      quot_if_has_spaces(fi.info.name);
  }

  public:
   file_info(const std::string& directory_name,
              const std::string& file_name,
              bool human_readable_size);

   decltype(info)
   operator()(void);
};

#endif