#include "Point.hpp"

int main( void )
{
	Point a(0,0);
	Point b(10,0);
	Point c(0,5);
	Point p1(12,5);
	Point p2(3,2);

	std::cout << "a(0,0); b(10,0); c(0,5); p1(12,5); p2(3,2)" << std::endl;
	std::cout << "Is p1 in (a, b, c) ?" << boolToString(bsp(a, b, c, p1)) << std::endl;
	std::cout << "Is p2 in (a, b, c) ?" << boolToString(bsp(a, b, c, p2)) << std::endl;
	std::cout << "Is a in (a, b, c) ?" << boolToString(bsp(a, b, c, a)) << std::endl;

	return 0;
}
