#include <cstdlib>
#include <iostream>
#include "argparser.hxx"
#include "formatter.hxx"
#include "former.hxx"
#include <vector>

int main(int nargs, char* args[]) {

  try {
    myls::argparser parser{nargs, args};
    myls::mode mode{parser()};

    myls::former former{mode};

    if (mode.has_long_listing()) {
      myls::formatter formatter{
          static_cast<std::vector<myls::file_info>>(former),
          mode};

      for (const std::string& infostr : formatter()) {
        std::cout << infostr << '\n';
      }
    }

    else {
      for (const std::string& name :
           static_cast<std::vector<std::string>>(former)) {
        std::cout << name << '\n';
      }
    }

  } catch(const std::exception& ex) {
    std::cerr << ex.what() << '\n';
    return EXIT_FAILURE;

  } catch(const std::string& ex) {
    std::cerr << ex << '\n';
    return EXIT_FAILURE;
  }
}