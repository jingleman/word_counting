
#include "word_counting/word_counting.hpp"
#include "word_counting/database.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace word_counting {


auto word_counting(const std::string &corpusPath, const std::string &queryPath)
    -> void {
  auto corpus = Database(corpusPath);
  std::vector<std::string> queryKeys = load_query(queryPath);
  auto queryResults = Database(corpus, queryKeys);
  for (const auto &pr : queryResults.wordCounts()) {
    std::cout << "block: " << pr.first << " " << pr.second << std::endl;
  }
}

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
