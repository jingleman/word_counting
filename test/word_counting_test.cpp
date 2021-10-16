#include <iostream>
#include "gtest/gtest.h"

#include "word_counting/word_counting.hpp"

TEST(word_counting, positive) {
  EXPECT_EQ(2, word_counting::word_counting(1, 1));
}

