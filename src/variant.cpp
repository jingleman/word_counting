
#include <cassert>
#include <exception>
#include <iostream>
#include <string>
#include <variant>
using namespace std;

// variant, get, index, visit, holds_alternative

int main() {
  try {
    static constexpr  // Only way for index() to be available at compile time.
    variant<int, float> w {42.1f};
    variant<int, float> v = 42;
    variant<int, float> z = get<w.index()>(w);
    cout << "v= " << get<int>(v) << endl;
    cout << "w= " << get<float>(w) << endl;
    cout << "z= " << visit([](const auto &x) {return to_string(x);}, z) << endl;
    
    variant<string, void const *> y("abc");
    decltype(y) a = "abcd"s;
    assert(holds_alternative<void const *>(y));
    assert(holds_alternative<string>(a));
    cout << "main done" << endl;
  } catch (const exception & e) {
    cerr << "Caught " << e.what() << endl;
    return 1;
  }
  return 0;
}
