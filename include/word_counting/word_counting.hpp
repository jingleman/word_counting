#ifndef WORD_COUNTING_FOO_H_
#define WORD_COUNTING_FOO_H_


#include <string>


namespace word_counting {
  
  auto word_counting(const std::string& corpusPath, const std::string& queryPath) -> void;
  
}

#endif