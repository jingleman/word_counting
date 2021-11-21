

#include <algorithm>
#include <deque>
//#include <execution>  // requires c++20 with this compiler? no, worse...
// see below.
#include <iomanip>
#include <iostream>
#include <list>
#include <cmath>
#include <ostream>
#include <sstream>
#include <vector>
using namespace std;
using namespace literals;

// transform, generate, next_permutation, & attempt a "zip" operation
  // (since apparently it's not in c++ 20 ranges views)
// tgamma(n+1) (factorial), do while
// ExecutionPolicy? ... doesn't exist! see dynalist.
// (operator<<... or rather to_stream w/ variadic template & perfect forwarding)
// (back_inserter, in place, plus<>{}, crbegin(), etc.

//template <template <class...> class ContT, class... ContArgsT>
  // This will work too, but it doesn't add anything for the true container
  // cases and it introduces ambiguity into the operator<< overload for strings.
  // Template specialization doesn't help.
//ostream &to_stream(ostream &os, const ContT<ContArgsT...> &cont) {
  // Gave up on this. It works with everything except the << beforehand.
template <class ContT> string to_string(const ContT &cont) {
  ostringstream oss;
  for (const auto &elem : cont) {
    oss << setw(5) << elem << " ";
  }
  return oss.str();   // Probably not efficient.
}

int main(int argc, char** argv) {
  try {
    vector<int> a(3);
    list<int> b(2);   // n < 2 noexcept, but makes element-wise
        // xform even more complicated to follow.
    deque<int> c;
    generate(a.begin(), a.end(), [n=-10]() mutable {return n--;});
    generate(b.begin(), b.end(), [m= 10]() mutable {return m++;});
    transform(a.crbegin(), a.crend(), b.cbegin(),
                               front_inserter(c),
              std::plus<>{});   // mix-and-match element-wise.
    cout << "a= " << to_string(a) << endl;
    cout << "b= " << to_string(b) << endl;
    cout << "c= " << to_string(c) << endl;
    
    auto p = c;
    size_t nPerms = 0;
    sort(p.begin(), p.end());
    do {
      cout << "p[" << nPerms++ << "]=" << to_string(p) << endl;
    } while (next_permutation(p.begin(), p.end()));
    assert(nPerms == tgamma(p.size() + 1));
    
    vector<int> vi1 {1, 2, 3};
    vector<int> vi2 {-1, -2, -3, -4};
    for (auto it1 = vi1.begin(),
              it2 = vi2.begin(); it1 != vi1.end() &&
                                 it2 != vi2.end(); ++it1, ++it2) {
      cout << *it1 << " " << *it2 << endl;  // note comma at end.
    } // generate can only handle one container, & transform has to modify
      // something. No structured binding.
    
    cout << "main done" << endl;
  } catch (const exception & e) {
    cerr << "Caught " << e.what() << endl;
    return 1;
  }
  return 0;
}
