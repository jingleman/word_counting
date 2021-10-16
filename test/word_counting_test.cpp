#include <iostream>
#include "gtest/gtest.h"

#include "word_counting/word_counting.hpp"

TEST(word_counting, positive) {
  EXPECT_NO_THROW(word_counting::word_counting(1, 1));
}

