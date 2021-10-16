
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include "word_counting/word_counting.hpp"

auto main(int argc, char **argv) -> int {
  std::cout << "main" << std::endl;
  try {
    if (argc != 3) {
      throw std::runtime_error("Invalid arguments.");
    }   // Also check values?
    word_counting::word_counting(std::atoi(argv[1]), std::atoi(argv[2]));
  } catch (const std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
    return 1;
  }
  std::cout << "main done" << std::endl;
  return 0;
}

