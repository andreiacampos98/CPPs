#include "Point.hpp"

std::string	boolToString(bool b)
{
	if (b)
		return ("true");
	return ("false");
}

int main( void )
{
	Point a(0,0);
	Point b(10,0);
	Point c(0,5);
	Point p1(12,5);
	Point p2(3,2);
	Point p3(1,1);

	std::cout << "a(0,0); b(10,0); c(0,5); p1(12,5); p2(3,2); p3(1,1)" << std::endl;
	std::cout << "Is p1 in (a, b, c) ? " << boolToString(bsp(Point(0,0), Point(10,0), Point(0,5), Point(12,5))) << std::endl;
	std::cout << "Is p3 in (a, b, c) ? " << boolToString(bsp(Point(0,0), Point(10,0), Point(0,5), Point(1,1))) << std::endl;

	return 0;
}
