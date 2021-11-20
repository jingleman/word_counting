#ifndef WORD_COUNTING__DATABASE_H_
#define WORD_COUNTING__DATABASE_H_

#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace word_counting {

struct Database {
  Database(const Database &other, const std::vector<std::string> &queryKeys);
  bool wanted(char &c);
  explicit Database(const std::string &path);
  std::vector<std::pair<std::string, size_t>> wordCounts() const;

private:
  std::unordered_map<std::string, size_t> wc;
};

} // namespace word_counting

#endif