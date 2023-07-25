#include "Point.hpp"

Point::Point(): _x(0), _y(0) {}

Point::Point(const float &valuex, const float &valuey): _x(valuex), _y(valuey) {}

Point::Point(const Point &copy): _x(copy._x), _y(copy._y) {}

Point &Point::operator=(const Point &src)
{
	if (this != &src) {
    (Fixed)this->_x = src.getX();
    (Fixed)this->_y = src.getY();
  	}
	return (*this);
}

Point::~Point() {}

float Point::getX( void ) const
{
	return(this->_x.toFloat());
}

float Point::getY( void ) const
{
	return(this->_y.toFloat());
}

Fixed Point::area(const Point &a, const Point &b, const Point &c)
{
    Fixed _area;

	_area = ((a._x*(b._y - c._y) + b._x*(c._y - a._y) + c._x*(a._y - b._y))/2);
	if (_area < 0)
		_area = Fixed(-_area.toFloat());
    return (_area);
}
