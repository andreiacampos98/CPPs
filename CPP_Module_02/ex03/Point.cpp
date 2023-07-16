#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
	std::cout << "Point Default constructor called" << std::endl;
}
Point::Point(const Point &copy)
{
	std::cout << "Point Copy constructor called" << std::endl;
}
Point Point::&operator = (const Point &src)
{
	std::cout << "Point Copy assignment operator called" << std::endl;
}

Point::~Point()
{
	std::cout << "Point Destructor called" << std::endl;
}
