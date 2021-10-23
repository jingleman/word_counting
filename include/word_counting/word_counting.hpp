#ifndef WORD_COUNTING_FOO_H_
#define WORD_COUNTING_FOO_H_


#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <sstream>
#include <unordered_map>
#include <utility>
#include <vector>
#include "word_counting/word_counting.hpp"


namespace word_counting {
  
  auto word_counting(const std::string& corpusPath, const std::string& queryPath) -> void;
  
  std::__1::vector<std::string> load_query(const std::string &path) {
    
    std::ifstream ifs(path);
    if (!ifs) { throw std::invalid_argument("Invalid path " + path); }
  
    std::__1::vector<std::string> results;
    std::string word;
    while (ifs >> word) {
      if (word.empty()) { continue; }
      results.push_back(word);
    }
    
    return results;
  }
  
  struct Database {
    Database(const Database &other, const std::__1::vector<std::string> &queryKeys) {
      for (const auto& key : queryKeys) {
        auto it = other.wc.find(key);
        if (it == other.wc.end()) {
          wc[key] = 0;
        } else {
          wc[key] = it->second;
        }
      }
    }
    bool wanted(char &c) {
      if (c >= 97 && c <= 122) return true;   // lower case.
      if (c >= 65 && c <= 90) {c += 32; return true;}  // upper. Could change.
      if (c == 39 || c == 45)  return true;   // ', -
      return false;
    }
    explicit Database(const std::string& path) {
      std::ifstream ifs(path);
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
    std::__1::vector<std::__1::pair<std::string, size_t>> wordCounts() const {
      std::__1::vector<std::__1::pair<std::string, size_t>> results;
      for (auto pr: wc) results.emplace_back(pr);
      std::sort(results.begin(), results.end());
      return results;
    }
  private:
    std::__1::unordered_map<std::string, size_t> wc;
  };
}

#endif