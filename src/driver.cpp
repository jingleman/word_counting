
#include "widget.h"
#include <iostream>


template<typename T>
void foo(T t) {
  std::cout << "base " << t << std::endl;
}

template<typename T, typename... Ts>
void foo(T t, Ts... ts) {
  std::cout << "foo " << t << std::endl;
  foo(ts...);
}



// user (main.cpp)
int main()
{
  foo<int, int, int>(5, 3, 2);
  widget w(7);
  
  const widget w2(8);
  w.draw();
  w2.draw();
  w.draws(1);//, 2.0, true);
  //w2.draws(1, 2.0, true);
}