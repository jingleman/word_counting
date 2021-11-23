
#include <iostream>
#include <utility>
using namespace std;

struct S {
  S(int i) : i_(i) {}
  S & operator=(const S && s) {
    cout << "mv assn" << endl;
    //++s.i_;
    i_ = move(s.i_);
    return *this;
  }
  S(S && s) : i_(move(s.i_)) {
    cout << "mv ctor" << endl;
  }
  int i_ = 1;
};
int main() {
  S s2(2);
  S s3(2);
  s3 = move(s2);
  cout << s3.i_ << endl;
  return 0;
}
