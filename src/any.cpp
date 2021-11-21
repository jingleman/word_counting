
#include <any>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;
using namespace literals;

// any, any_cast, has_value, reset, type().name(), namespace literals
// (see cppreference for bad_cast exception)

int main() {
  try {
    any i;
    assert(!i.has_value());
    i = -3;
    cout << "i= " << i.type().name() << " " << any_cast<int>(i) << endl;
    i = 4ul;
    cout << "i= " << i.type().name() << " " << any_cast<size_t>(i) << endl;
    i.reset();
    assert(!i.has_value());
    cout << "main done" << endl;
  } catch (const exception & e) {
    cerr << "Caught " << e.what() << endl;
    return 1;
  }
  return 0;
}
