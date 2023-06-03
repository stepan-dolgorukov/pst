#include <cstdlib>
#include <iostream>
#include "argparser.hxx"
#include "former.hxx"

int main(int nargs, char* args[]) {

  try {
    myls::argparser parser{nargs, args};
    myls::former former{parser()};

    auto info{former()};

    for (auto file_info : former()) {
      std::cout << file_info << '\n';
    }

  } catch(std::exception& ex) {
    std::cerr << ex.what() << '\n';
    return EXIT_FAILURE;

  } catch(std::string& ex) {
    std::cerr << ex << '\n';
    return EXIT_FAILURE;
  }
}