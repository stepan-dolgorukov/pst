#include "file_hlinks_amnt.hxx"

myls::file_hlinks_amnt::file_hlinks_amnt(const std::string& name) {
  int error_status{::stat(name.c_str(), &stat)};
  fill_amount();
}

void myls::file_hlinks_amnt::fill_amount(void) {
  amount = stat.st_nlink;
}

std::size_t myls::file_hlinks_amnt::operator()(void) const {
  return amount;
}