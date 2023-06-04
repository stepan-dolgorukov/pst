#include <cstdlib>
#include <iostream>
#include "argparser.hxx"
#include "formatter.hxx"
#include "former.hxx"

int main(int nargs, char* args[]) {

  try {
    myls::argparser parser{nargs, args};
    myls::former former{parser()};

    auto info{former()};
    myls::formatter formatter{info, parser()};

    for (const auto& infostr : formatter()) {
      std::cout << infostr << '\n';
    }

  } catch(const std::exception& ex) {
    std::cerr << ex.what() << '\n';
    return EXIT_FAILURE;

  } catch(const std::string& ex) {
    std::cerr << ex << '\n';
    return EXIT_FAILURE;
  }
}