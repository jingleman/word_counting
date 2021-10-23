
#include "word_counting/word_counting.hpp"

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


bool wanted(char &c) {
  if (c >= 97 && c <= 122) return true;   // lower case.
  if (c >= 65 && c <= 90) {c += 32; return true;}  // upper. Could change.
  if (c == 39 || c == 45)  return true;   // ', -
  return false;
}

namespace word_counting {
  
  std::vector<std::string> load_query(const std::string &path) {
    
    std::ifstream ifs(path);
    if (!ifs) { throw std::invalid_argument("Invalid path " + path); }
  
    std::vector<std::string> results;
    string word;
    while (ifs >> word) {
      if (word.empty()) { continue; }
      results.push_back(word);
    }
    
    return results;
  }
  
  struct Database {
    Database(const Database &other, const std::vector<std::string> &queryKeys) {
      for (const auto& key : queryKeys) {
        auto it = other.wc.find(key);
        if (it == other.wc.end()) {
          wc[key] = 0;
        } else {
          wc[key] = it->second;
        }
      }
    }
    explicit Database(const std::string& path) {
      ifstream ifs(path);
      if (!ifs) {throw std::invalid_argument("Invalid path " + path);}
      std::string word;
      while (ifs >> word) {
        if (word.empty()) continue;
        auto cKept = word.begin();
        for (auto c: word) {
          if (wanted(c)) {
            *cKept++ = c;
          }
        }
        word.erase(cKept, word.end());
        ++wc[word];
      }
    }
    unordered_map<string, size_t> wc;
  };
  auto word_counting(const std::string& corpusPath, const std::string& queryPath) -> void {
    auto corpus = Database(corpusPath);
    std::vector<std::string> queryKeys = load_query(queryPath);
    auto queryResults = Database(corpus, queryKeys);
    for (const auto& q : queryResults.wc) {
      cout << "block: " << q.first << " " << q.second << endl;
    }
  }
}

