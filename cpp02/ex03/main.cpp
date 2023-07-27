#include <iostream>
#include "Point.h"

void verify(bool result) {
  if (result) {
    std::cout << "The point is in the triangle." << std::endl;
  } else {
    std::cout << "The point is not in the triangle." << std::endl;
  }
}

int main( void ) {
  Point a(1, 1);
  Point b(2, 2);
  Point c(3, 3);

  verify(bsp(a, b, c, Point(0, 0))); // inside
  verify(bsp(a, b, c, Point(2, 0))); // outside
  verify(bsp(a, b, c, Point(3, 0))); // outside

  return 0;
}
