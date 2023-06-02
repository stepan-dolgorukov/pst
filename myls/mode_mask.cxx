#include "mode_mask.hxx"

myls::option_mask::option_mask(void): mask{0b000u} {

}

void myls::option_mask::set(myls::arguments arg) {
  mask |= arg_mask.at(arg);
}

bool myls::option_mask::get(myls::arguments arg) {
  return 0u != (mask & arg_mask.at(arg));
}