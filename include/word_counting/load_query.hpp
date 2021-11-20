#ifndef WORD_COUNTING__LOAD_QUERY_H_
#define WORD_COUNTING__LOAD_QUERY_H_

#include <string>
#include <vector>

namespace word_counting {

auto load_query(const std::string &path) -> std::vector<std::string>;

} // namespace word_counting

#endif