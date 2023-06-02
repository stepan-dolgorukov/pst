#include "mode.hxx"

myls::mode::mode(std::uint8_t mode_mask) : mask{mode_mask} {
}

bool myls::mode::has_long_listing() {
  return 0b100u & mask;
}

bool myls::mode::has_reverse_listing() {
  return 0b010u & mask;
}

bool myls::mode::has_human_size() {
  return 0b001u & mask;
}