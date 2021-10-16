#include "benchmark/benchmark.h"
#include "word_counting/word_counting.hpp"

static void BM_WordCounting(benchmark::State& state) {
  while (state.KeepRunning()) {
    word_counting::word_counting(1, state.range(0));
  }
}
BENCHMARK(BM_WordCounting)
    ->Args({100})
    ->Args({1000})
    ->Args({10000})
    ->Args({100000});

BENCHMARK_MAIN();
