
//#include <bits/stdc++.h>
#include <iostream>
#include <chrono>
#include <map>
#include <random>
#include <thread>

using namespace std;
using namespace std::chrono_literals;
#include <random>

template <class T>                    auto get_sum(T t) -> auto {return t;}
template <class T, class ... Rest>      // before
auto get_sum(T t, Rest ... rest)        // betweeen
//->decltype(t + rest )
// parameter packs not expanded
//->decltype(auto)
{return t + get_sum(rest...);}

static_assert(
    is_same_v<
        decltype(get_sum(1.0, 1.0f, 1, size_t(1))),
        decltype(get_sum(1.0))
        >
);
static constexpr bool are_same() {
  return
      is_same_v<
          decltype(get_sum(size_t(0))),
          decltype(get_sum(size_t(0)))
          >;
}

static_assert(are_same());
static_assert(
    is_same_v<
        decltype(get_sum(size_t(0))),
        decltype(get_sum(size_t(0)))
        >
);

int main() {
  for (size_t i = 0; i < 100; ++i) {std::cout << std::endl;}
  
  double sum = get_sum(1.1, 1.1f, 1, size_t(1));
  //size_t(1), int(1), 1.1, 1.1f);
  cout << "sum= " << sum << endl;
  return 0;
  
  vector<chrono::time_point<
      chrono::steady_clock>> ts;
  ts.emplace_back(chrono::steady_clock::now());
  this_thread::sleep_for(1s);
  ts.emplace_back(chrono::steady_clock::now());
  
  map<int, int> m;
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution dis(0, 9);
  for (int i = 0; i < 10; ++i) {
    int r = dis(gen);
    cout << r << endl;
    m[i] = r;
  }
  for (const auto & [k, v] : m) {
    cout << k << " " << v << endl;
  }
  
  for (auto t : ts) {
    cout << "t= " << chrono::duration<double>(t-ts.front()).count() << endl;
  }
  return 0;
}
