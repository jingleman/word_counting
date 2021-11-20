#include <iostream>
#include "gtest/gtest.h"

#include "word_counting/load_query.hpp"

TEST(word_counting, positive) {
  EXPECT_NO_THROW(word_counting::word_counting(std::string(), std::string()));
}

