#include<iostream>
#include "argparser.hxx"

int main(int nargs, char* args[]) {
  myls::argparser parser{nargs, args};
  std::cout << parser() << '\n';
}