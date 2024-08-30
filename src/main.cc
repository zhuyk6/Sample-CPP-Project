#include "foo.h"
// #include <format>
#include <iostream>

int main() {
  Foo foo;
  int x = 2;
  int y = 3;
  // auto ret = std::format("Hello, {} + {} = {}", x, y, foo.add(x, y));
  // std::cout << ret << std::endl;
  std::cout << "Hello, " << x << " + " << y << " = " << foo.add(x, y)
            << std::endl;

  return 0;
}