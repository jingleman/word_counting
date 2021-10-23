
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "word_counting/word_counting.hpp"

auto main(int argc, char **argv) -> int {
  try {
    if (argc != 5) {
      std::stringstream ss;
      ss << "usage: " << argv[0] << " " << "<min_length>" << " " << "<max_length>" << " " << "<input_txt>";
      throw std::invalid_argument(ss.str());
    }   // Also check values?
    word_counting::word_counting(std::atoi(argv[1]), std::atoi(argv[2]), std::string(argv[3]), std::string(argv[4]));
  } catch (const std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}

