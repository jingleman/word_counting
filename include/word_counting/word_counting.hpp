#ifndef WORD_COUNTING__WORD_COUNTING_H_
#define WORD_COUNTING__WORD_COUNTING_H_


#include <string>
#include <vector>


namespace word_counting {



auto word_counting(const std::string &corpusPath, const std::string &queryPath)
    -> void;

auto load_query(const std::string &path) -> std::vector<std::string>;

} // namespace word_counting

#endif