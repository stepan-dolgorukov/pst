#include "mode.hxx"
#include "args.hxx"

myls::mode::mode(myls::mode_mask mask) : mask{mask} {
}

bool myls::mode::has_long_listing() {
  return mask.get(myls::arguments::long_listing);
}

bool myls::mode::has_reverse_listing() {
  return mask.get(myls::arguments::reverse_listing);
}

bool myls::mode::has_human_size() {
  return mask.get(myls::arguments::human_readable_size);
}