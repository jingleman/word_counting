
#include "word_counting/word_counting.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>


namespace word_counting {
  
  auto word_counting(const std::string& corpusPath, const std::string& queryPath) -> void {
    auto corpus = Database(corpusPath);
    std::vector<std::string> queryKeys = load_query(queryPath);
    auto queryResults = Database(corpus, queryKeys);
    for (const auto& pr : queryResults.wordCounts()) {
      std::cout << "block: " << pr.first << " " << pr.second << std::endl;
    }
  }
}

