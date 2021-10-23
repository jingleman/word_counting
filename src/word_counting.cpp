
#include "word_counting/word_counting.hpp"

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <sstream>
#include <string>
#include <unordered_map>

using namespace std;


bool wanted(char &c) {
  if (c >= 97 && c <= 122) return true;   // lower case.
  if (c >= 65 && c <= 90) {c += 32; return true;}  // upper. Could change.
  if (c == 39 || c == 45)  return true;   // ', -
  return false;
}

bool vowel(char c) {  // lower
  return c == 97 || c == 101 || c == 105 || c == 111 || c == 117;
}

namespace word_counting {
  auto word_counting::word_counting(int nCharsMin, int nCharsMax, std::string corpusPath, std::string queryPath) -> void {
    unordered_map<string, size_t> wc;
    ifstream ifs(corpusPath);
    if (!ifs) {throw std::invalid_argument("Invalid corpus: " + corpusPath);}
    string word;
    size_t nWords = 0;
    while (ifs >> word) {
      if (word.size() < nCharsMin) continue;
      if (word.empty()) continue;
      auto cKept = word.begin();
      for (auto c : word) {
        if (wanted(c)) {
          *cKept++ = c;
        }
      }
      word.erase(cKept, word.end());
      ++nWords;
      if (word.size() >= nCharsMin &&
          word.size() <= nCharsMax) {
        ++wc[word];
      }
    }
    for (auto w : wc) {
      //cout << w.first << " " << w.second << endl;
    }
    
    
    {
      map<string, size_t> query;
      ifstream blocks(queryPath);
      if (!blocks) {
        std::stringstream ss;
        ss << "Invalid query path " << queryPath;
        throw invalid_argument(ss.str());
      }
      string word;
      
      while (blocks >> word) {
        query[word] = wc[word]; // non const
      }
      
      for (auto q : query) {
        cout << "block: " << q.first << " " << q.second << endl;
      }
    }
  }
}

