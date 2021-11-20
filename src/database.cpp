
#include "word_counting/database.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace word_counting {

Database::Database(const Database &other,
                   const std::vector<std::string> &queryKeys) {
  for (const auto &key : queryKeys) {
    auto it = other.wc.find(key);
    if (it == other.wc.end()) {
      wc[key] = 0;
    } else {
      wc[key] = it->second;
    }
  }
}

bool Database::wanted(char &c) {
  if (c >= 97 && c <= 122)
    return true; // lower case.
  if (c >= 65 && c <= 90) {
    c += 32;
    return true;
  } // upper. Could change.
  if (c == 39 || c == 45)
    return true; // ', -
  return false;
}

Database::Database(const std::string &path) {
  std::ifstream ifs(path);
  if (!ifs) {
    throw std::invalid_argument("Invalid path " + path);
  }
  std::string word;
  while (ifs >> word) {
    if (word.empty())
      continue;
    auto cKept = word.begin();
    for (auto c : word) {
      if (wanted(c)) {
        *cKept++ = c;
      }
    }
    word.erase(cKept, word.end());
    ++wc[word];
  }
}

std::vector<std::pair<std::string, size_t>> Database::wordCounts() const {
  std::vector<std::pair<std::string, size_t>> results;
  for (auto pr : wc)
    results.emplace_back(pr);
  std::sort(results.begin(), results.end());
  return results;
}

} // namespace word_counting
