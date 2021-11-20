
#include "word_counting/load_query.hpp"
#include "word_counting/database.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace word_counting {

auto load_query(const std::string &path) -> std::vector<std::string> {
  std::ifstream ifs(path);
  if (!ifs) {
    throw std::invalid_argument("Invalid path " + path);
  }

  std::vector<std::string> results;
  std::string word;
  while (ifs >> word) {
    if (word.empty()) {
      continue;
    }
    results.push_back(word);
  }

  return results;
}
} // namespace word_counting
