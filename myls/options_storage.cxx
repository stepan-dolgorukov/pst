#include "options_storage.hxx"

myls::options_storage::options_storage(void): storage{0u} {

}

void myls::options_storage::set(myls::options arg) {
  storage |= arg_mask.at(arg);
}

bool myls::options_storage::get(myls::options arg) const {
  return arg_mask.at(arg) == (storage & arg_mask.at(arg));
}