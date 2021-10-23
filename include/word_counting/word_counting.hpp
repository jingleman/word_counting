#ifndef WORD_COUNTING_FOO_H_
#define WORD_COUNTING_FOO_H_


#include <string>


namespace word_counting {
  
  auto word_counting(int nCharsMin, int nCharsMax, std::string corpusPath, std::string queryPath) -> void;
  
}

#endif