#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point{
	private:
		Fixed const _x;
		Fixed const _y;
	public:
		Point();
		Point(const Point &copy);
		Point &operator = (const Point &src);
		~Point();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
