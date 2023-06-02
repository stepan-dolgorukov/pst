#include "mode_mask.hxx"

myls::mode_mask::mode_mask(void): mask{0b000u} {

}

void myls::mode_mask::set(myls::arguments arg) {
  mask |= arg_mask.at(arg);
}

bool myls::mode_mask::get(myls::arguments arg) {
  return 0u != (mask & arg_mask.at(arg));
}