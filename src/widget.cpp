
#include "widget.h"
#include <Eigen/Dense>
#include <iostream>

template<typename T>
void bar(T t) {
  std::cout << "base " << t << std::endl;
}

template<typename T, typename... Ts>
void bar(T t, Ts... ts) {
  std::cout << "bar " << t << std::endl;
  bar(ts...);
}

class widget::impl {
  int n;
public:
  void draw(const widget& w) const {
    if(w.shown()) // this call to public member function requires the back-reference
      std::cout << "drawing a const widget " << n << '\n';
  }
  void draw(const widget& w) {
    if(w.shown())
      std::cout << "drawing a non-const widget " << n << '\n';
    Eigen::MatrixX<double> m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m << std::endl;
  }
  impl(int n) : n(n) {}
};

void widget::draw() const { pImpl->draw(*this); }
void widget::draw()       { pImpl->draw(*this); }
template <typename T>
void widget::draws(T t)       { }//pImpl->draw(*this); }
template void widget::draws<int>(int);
  // chrome-extension://efaidnbmnnnibpcajpcglclefindmkaj/viewer
                       // .html?pdfurl=https%3A%2F%2Fwww.aristeia.com%2FTalkNotes%2FFacebook2012_PerfectForwarding.pdf&clen=353419&chunk=true
widget::widget(int n) : pImpl{std::make_unique<impl>(n)} {}
widget::widget(widget&&) = default;
widget::~widget()        = default;
widget& widget::operator=(widget&&) = default;
  // Don't think cp is possible.
