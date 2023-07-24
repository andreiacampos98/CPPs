#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
	//std::cout << "Point Default constructor called" << std::endl;
	return ;
}

Point::Point(const float &valuex, const float &valuey): _x(Fixed(valuex)), _y(Fixed(valuey))
{
	//std::cout << "Point Default constructor called" << std::endl;
	return ;
}

Point::Point(const Point &copy): _x(copy._x), _y(copy._y)
{
	//std::cout << "Point Copy constructor called" << std::endl;
	return ;
}
Point &Point::operator=(const Point &src)
{
	(void)src;
	//std::cout << "Point Copy assignment operator called" << std::endl;
	return (*this);
}

Point::~Point()
{
	//std::cout << "Point Destructor called" << std::endl;
	return ;
}

float Point::getX( void ) const
{
	return(this->_x.toFloat());
}

float Point::getY( void ) const
{
	return(this->_y.toFloat());
}

float Point::area(const Point &a, const Point &b, const Point &c)
{
    Fixed _area;

	//_area = ((a._x*(b._y - c._y) + b._x*(c._y - a._y) + c._x*(a._y - b._y))/2);
	_area = (a._x - c._x) * (b._y - c._y) - (b._x - c._x) * (a._y - c._y);
    return (_area.toFloat());
}
