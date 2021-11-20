
#include "word_counting/database.hpp"
#include "word_counting/load_query.hpp"
#include <algorithm>
#include <exception>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

auto main(int argc, char **argv) -> int {
  try {
    if (argc != 3) {
      std::stringstream ss;
      ss << "usage: " << argv[0] << " "
         << "<corpus_path>"
         << " "
         << "<query_path>";
      throw std::invalid_argument(ss.str());
    } // Also check values?

    auto corpus = word_counting::Database(std::string(argv[1]));
    std::vector<std::string> queryKeys =
        word_counting::load_query(std::string(argv[2]));
    auto queryResults = word_counting::Database(corpus, queryKeys);
    auto wordCounts = queryResults.wordCounts();
    auto increasingCount = [](const std::pair<std::string, size_t> &a,
                              const std::pair<std::string, size_t> &b) {
      return a.second < b.second;
    };
    std::sort(wordCounts.begin(), wordCounts.end(), increasingCount);
    for (const auto &pr : wordCounts) {
      std::cout << "block: " << pr.first << " " << pr.second << std::endl;
    }
  } catch (const std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}
